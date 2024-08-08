#include "event_handlers/impl/WSLocal.h"

#include "CaptivePortal.h"
#include "CommandHandler.h"
#include "Common.h"
#include "Logging.h"

#include <cstdint>

const char* const TAG = "LocalMessageHandlers";

void serializeSetRfTxPinResult(std::uint8_t socketId, std::uint8_t pin, OpenShock::Serialization::Local::SetRfPinResultCode result) {
  flatbuffers::FlatBufferBuilder builder(1024);

  auto responseOffset = builder.CreateStruct(OpenShock::Serialization::Local::SetRfTxPinCommandResult(pin, result));

  auto msgOffset = OpenShock::Serialization::Local::CreateHubToLocalMessage(builder, OpenShock::Serialization::Local::HubToLocalMessagePayload::SetRfTxPinCommandResult, responseOffset.Union());

  builder.Finish(msgOffset);

  const std::uint8_t* buffer = builder.GetBufferPointer();
  std::uint8_t size   = builder.GetSize();

  OpenShock::CaptivePortal::SendMessageBIN(socketId, buffer, size);
}

using namespace OpenShock::MessageHandlers::Local;

void _Private::HandleSetRfTxPinCommand(std::uint8_t socketId, const OpenShock::Serialization::Local::LocalToHubMessage* root) {
  auto msg = root->payload_as_SetRfTxPinCommand();
  if (msg == nullptr) {
    ESP_LOGE(TAG, "Payload cannot be parsed as SetRfTxPinCommand");
    return;
  }

  auto pin = msg->pin();

  auto result = OpenShock::CommandHandler::SetRfTxPin(pin);

  serializeSetRfTxPinResult(socketId, pin, result);
}

void _Private::HandleActionCommand(std::uint8_t socketId, const OpenShock::Serialization::Local::LocalToHubMessage* root) {
  auto msg = root->payload_as_ActionCommand();
  auto typeNum = msg->type();
  auto duration = msg->duration();
  auto intensity = msg->power();
  auto model = static_cast<OpenShock::Serialization::Types::ShockerModelType>(0);
  auto type = static_cast<OpenShock::Serialization::Types::ShockerCommandType>(typeNum);
  OpenShock::CommandHandler::HandleCommand(model, 42526, type, intensity, duration/256.0*15000.0);
}