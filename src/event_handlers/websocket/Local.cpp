#include "event_handlers/WebSocket.h"

#include "event_handlers/impl/WSLocal.h"
#include "Logging.h"

#include "serialization/_fbs/LocalToHubMessage_generated.h"

#include <WebSockets.h>

#include <array>
#include <cstdint>

static const char* TAG = "LocalMessageHandlers";

namespace Schemas  = OpenShock::Serialization::Local;
namespace Handlers = OpenShock::MessageHandlers::Local::_Private;
typedef Schemas::LocalToHubMessagePayload PayloadType;

using namespace OpenShock;

const std::size_t HANDLER_COUNT = static_cast<std::size_t>(PayloadType::MAX) + 1;

#define SET_HANDLER(payload, handler) handlers[static_cast<std::size_t>(payload)] = handler

static std::array<Handlers::HandlerType, HANDLER_COUNT> s_localHandlers = []() {
  std::array<Handlers::HandlerType, HANDLER_COUNT> handlers {};
  handlers.fill(Handlers::HandleInvalidMessage);

  SET_HANDLER(PayloadType::WifiScanCommand, Handlers::HandleWiFiScanCommand);
  SET_HANDLER(PayloadType::WifiNetworkSaveCommand, Handlers::HandleWiFiNetworkSaveCommand);
  SET_HANDLER(PayloadType::WifiNetworkForgetCommand, Handlers::HandleWiFiNetworkForgetCommand);
  SET_HANDLER(PayloadType::WifiNetworkConnectCommand, Handlers::HandleWiFiNetworkConnectCommand);
  SET_HANDLER(PayloadType::WifiNetworkDisconnectCommand, Handlers::HandleWiFiNetworkDisconnectCommand);
  SET_HANDLER(PayloadType::AccountLinkCommand, Handlers::HandleAccountLinkCommand);
  SET_HANDLER(PayloadType::AccountUnlinkCommand, Handlers::HandleAccountUnlinkCommand);
  SET_HANDLER(PayloadType::SetRfTxPinCommand, Handlers::HandleSetRfTxPinCommand);
  SET_HANDLER(PayloadType::ActionCommand, Handlers::HandleActionCommand);

  return handlers;
}();

void EventHandlers::WebSocket::HandleLocalBinary(std::uint8_t socketId, const std::uint8_t* data, std::size_t len) {
  // Deserialize
  auto msg = flatbuffers::GetRoot<Schemas::LocalToHubMessage>(data);
  if (msg == nullptr) {
    ESP_LOGE(TAG, "Failed to deserialize message");
    return;
  }

  // Validate buffer
  flatbuffers::Verifier::Options verifierOptions {
    .max_size = 4096,  // TODO: Profile this
  };
  flatbuffers::Verifier verifier(data, len, verifierOptions);
  if (!msg->Verify(verifier)) {
    ESP_LOGE(TAG, "Failed to verify message");
    return;
  }

  if (msg->payload_type() < PayloadType::MIN || msg->payload_type() > PayloadType::MAX) {
    Handlers::HandleInvalidMessage(socketId, msg);
    return;
  }

  s_localHandlers[static_cast<std::size_t>(msg->payload_type())](socketId, msg);
}
