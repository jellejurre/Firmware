// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_SERVERTODEVICEMESSAGE_OPENSHOCK_SERIALIZATION_H_
#define FLATBUFFERS_GENERATED_SERVERTODEVICEMESSAGE_OPENSHOCK_SERIALIZATION_H_

#include "flatbuffers/flatbuffers.h"

// Ensure the included flatbuffers.h is the same version as when this file was
// generated, otherwise it may not be compatible.
static_assert(FLATBUFFERS_VERSION_MAJOR == 23 &&
              FLATBUFFERS_VERSION_MINOR == 5 &&
              FLATBUFFERS_VERSION_REVISION == 26,
             "Non-compatible flatbuffers version included");

#include "ShockerCommandType_generated.h"
#include "ShockerModelType_generated.h"

namespace OpenShock {
namespace Serialization {

struct ShockerCommand;

struct ShockerCommandList;
struct ShockerCommandListBuilder;

struct CaptivePortalConfig;

struct ServerToDeviceMessage;
struct ServerToDeviceMessageBuilder;

enum class ServerToDeviceMessagePayload : uint8_t {
  NONE = 0,
  ShockerCommandList = 1,
  CaptivePortalConfig = 2,
  MIN = NONE,
  MAX = CaptivePortalConfig
};

inline const ServerToDeviceMessagePayload (&EnumValuesServerToDeviceMessagePayload())[3] {
  static const ServerToDeviceMessagePayload values[] = {
    ServerToDeviceMessagePayload::NONE,
    ServerToDeviceMessagePayload::ShockerCommandList,
    ServerToDeviceMessagePayload::CaptivePortalConfig
  };
  return values;
}

inline const char * const *EnumNamesServerToDeviceMessagePayload() {
  static const char * const names[4] = {
    "NONE",
    "ShockerCommandList",
    "CaptivePortalConfig",
    nullptr
  };
  return names;
}

inline const char *EnumNameServerToDeviceMessagePayload(ServerToDeviceMessagePayload e) {
  if (::flatbuffers::IsOutRange(e, ServerToDeviceMessagePayload::NONE, ServerToDeviceMessagePayload::CaptivePortalConfig)) return "";
  const size_t index = static_cast<size_t>(e);
  return EnumNamesServerToDeviceMessagePayload()[index];
}

template<typename T> struct ServerToDeviceMessagePayloadTraits {
  static const ServerToDeviceMessagePayload enum_value = ServerToDeviceMessagePayload::NONE;
};

template<> struct ServerToDeviceMessagePayloadTraits<OpenShock::Serialization::ShockerCommandList> {
  static const ServerToDeviceMessagePayload enum_value = ServerToDeviceMessagePayload::ShockerCommandList;
};

template<> struct ServerToDeviceMessagePayloadTraits<OpenShock::Serialization::CaptivePortalConfig> {
  static const ServerToDeviceMessagePayload enum_value = ServerToDeviceMessagePayload::CaptivePortalConfig;
};

bool VerifyServerToDeviceMessagePayload(::flatbuffers::Verifier &verifier, const void *obj, ServerToDeviceMessagePayload type);
bool VerifyServerToDeviceMessagePayloadVector(::flatbuffers::Verifier &verifier, const ::flatbuffers::Vector<::flatbuffers::Offset<void>> *values, const ::flatbuffers::Vector<ServerToDeviceMessagePayload> *types);

FLATBUFFERS_MANUALLY_ALIGNED_STRUCT(2) ShockerCommand FLATBUFFERS_FINAL_CLASS {
 private:
  uint8_t model_;
  int8_t padding0__;
  uint16_t id_;
  uint8_t type_;
  uint8_t intensity_;
  uint16_t duration_ms_;

 public:
  struct Traits;
  static FLATBUFFERS_CONSTEXPR_CPP11 const char *GetFullyQualifiedName() {
    return "OpenShock.Serialization.ShockerCommand";
  }
  ShockerCommand()
      : model_(0),
        padding0__(0),
        id_(0),
        type_(0),
        intensity_(0),
        duration_ms_(0) {
    (void)padding0__;
  }
  ShockerCommand(OpenShock::Serialization::Types::ShockerModelType _model, uint16_t _id, OpenShock::Serialization::Types::ShockerCommandType _type, uint8_t _intensity, uint16_t _duration_ms)
      : model_(::flatbuffers::EndianScalar(static_cast<uint8_t>(_model))),
        padding0__(0),
        id_(::flatbuffers::EndianScalar(_id)),
        type_(::flatbuffers::EndianScalar(static_cast<uint8_t>(_type))),
        intensity_(::flatbuffers::EndianScalar(_intensity)),
        duration_ms_(::flatbuffers::EndianScalar(_duration_ms)) {
    (void)padding0__;
  }
  OpenShock::Serialization::Types::ShockerModelType model() const {
    return static_cast<OpenShock::Serialization::Types::ShockerModelType>(::flatbuffers::EndianScalar(model_));
  }
  uint16_t id() const {
    return ::flatbuffers::EndianScalar(id_);
  }
  OpenShock::Serialization::Types::ShockerCommandType type() const {
    return static_cast<OpenShock::Serialization::Types::ShockerCommandType>(::flatbuffers::EndianScalar(type_));
  }
  uint8_t intensity() const {
    return ::flatbuffers::EndianScalar(intensity_);
  }
  uint16_t duration_ms() const {
    return ::flatbuffers::EndianScalar(duration_ms_);
  }
};
FLATBUFFERS_STRUCT_END(ShockerCommand, 8);

struct ShockerCommand::Traits {
  using type = ShockerCommand;
};

FLATBUFFERS_MANUALLY_ALIGNED_STRUCT(1) CaptivePortalConfig FLATBUFFERS_FINAL_CLASS {
 private:
  uint8_t enabled_;

 public:
  struct Traits;
  static FLATBUFFERS_CONSTEXPR_CPP11 const char *GetFullyQualifiedName() {
    return "OpenShock.Serialization.CaptivePortalConfig";
  }
  CaptivePortalConfig()
      : enabled_(0) {
  }
  CaptivePortalConfig(bool _enabled)
      : enabled_(::flatbuffers::EndianScalar(static_cast<uint8_t>(_enabled))) {
  }
  bool enabled() const {
    return ::flatbuffers::EndianScalar(enabled_) != 0;
  }
};
FLATBUFFERS_STRUCT_END(CaptivePortalConfig, 1);

struct CaptivePortalConfig::Traits {
  using type = CaptivePortalConfig;
};

struct ShockerCommandList FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef ShockerCommandListBuilder Builder;
  struct Traits;
  static FLATBUFFERS_CONSTEXPR_CPP11 const char *GetFullyQualifiedName() {
    return "OpenShock.Serialization.ShockerCommandList";
  }
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_COMMANDS = 4
  };
  const ::flatbuffers::Vector<const OpenShock::Serialization::ShockerCommand *> *commands() const {
    return GetPointer<const ::flatbuffers::Vector<const OpenShock::Serialization::ShockerCommand *> *>(VT_COMMANDS);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffsetRequired(verifier, VT_COMMANDS) &&
           verifier.VerifyVector(commands()) &&
           verifier.EndTable();
  }
};

struct ShockerCommandListBuilder {
  typedef ShockerCommandList Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_commands(::flatbuffers::Offset<::flatbuffers::Vector<const OpenShock::Serialization::ShockerCommand *>> commands) {
    fbb_.AddOffset(ShockerCommandList::VT_COMMANDS, commands);
  }
  explicit ShockerCommandListBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<ShockerCommandList> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<ShockerCommandList>(end);
    fbb_.Required(o, ShockerCommandList::VT_COMMANDS);
    return o;
  }
};

inline ::flatbuffers::Offset<ShockerCommandList> CreateShockerCommandList(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    ::flatbuffers::Offset<::flatbuffers::Vector<const OpenShock::Serialization::ShockerCommand *>> commands = 0) {
  ShockerCommandListBuilder builder_(_fbb);
  builder_.add_commands(commands);
  return builder_.Finish();
}

struct ShockerCommandList::Traits {
  using type = ShockerCommandList;
  static auto constexpr Create = CreateShockerCommandList;
};

inline ::flatbuffers::Offset<ShockerCommandList> CreateShockerCommandListDirect(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<OpenShock::Serialization::ShockerCommand> *commands = nullptr) {
  auto commands__ = commands ? _fbb.CreateVectorOfStructs<OpenShock::Serialization::ShockerCommand>(*commands) : 0;
  return OpenShock::Serialization::CreateShockerCommandList(
      _fbb,
      commands__);
}

struct ServerToDeviceMessage FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef ServerToDeviceMessageBuilder Builder;
  struct Traits;
  static FLATBUFFERS_CONSTEXPR_CPP11 const char *GetFullyQualifiedName() {
    return "OpenShock.Serialization.ServerToDeviceMessage";
  }
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_PAYLOAD_TYPE = 4,
    VT_PAYLOAD = 6
  };
  OpenShock::Serialization::ServerToDeviceMessagePayload payload_type() const {
    return static_cast<OpenShock::Serialization::ServerToDeviceMessagePayload>(GetField<uint8_t>(VT_PAYLOAD_TYPE, 0));
  }
  const void *payload() const {
    return GetPointer<const void *>(VT_PAYLOAD);
  }
  template<typename T> const T *payload_as() const;
  const OpenShock::Serialization::ShockerCommandList *payload_as_ShockerCommandList() const {
    return payload_type() == OpenShock::Serialization::ServerToDeviceMessagePayload::ShockerCommandList ? static_cast<const OpenShock::Serialization::ShockerCommandList *>(payload()) : nullptr;
  }
  const OpenShock::Serialization::CaptivePortalConfig *payload_as_CaptivePortalConfig() const {
    return payload_type() == OpenShock::Serialization::ServerToDeviceMessagePayload::CaptivePortalConfig ? static_cast<const OpenShock::Serialization::CaptivePortalConfig *>(payload()) : nullptr;
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint8_t>(verifier, VT_PAYLOAD_TYPE, 1) &&
           VerifyOffset(verifier, VT_PAYLOAD) &&
           VerifyServerToDeviceMessagePayload(verifier, payload(), payload_type()) &&
           verifier.EndTable();
  }
};

template<> inline const OpenShock::Serialization::ShockerCommandList *ServerToDeviceMessage::payload_as<OpenShock::Serialization::ShockerCommandList>() const {
  return payload_as_ShockerCommandList();
}

template<> inline const OpenShock::Serialization::CaptivePortalConfig *ServerToDeviceMessage::payload_as<OpenShock::Serialization::CaptivePortalConfig>() const {
  return payload_as_CaptivePortalConfig();
}

struct ServerToDeviceMessageBuilder {
  typedef ServerToDeviceMessage Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_payload_type(OpenShock::Serialization::ServerToDeviceMessagePayload payload_type) {
    fbb_.AddElement<uint8_t>(ServerToDeviceMessage::VT_PAYLOAD_TYPE, static_cast<uint8_t>(payload_type), 0);
  }
  void add_payload(::flatbuffers::Offset<void> payload) {
    fbb_.AddOffset(ServerToDeviceMessage::VT_PAYLOAD, payload);
  }
  explicit ServerToDeviceMessageBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<ServerToDeviceMessage> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<ServerToDeviceMessage>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<ServerToDeviceMessage> CreateServerToDeviceMessage(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    OpenShock::Serialization::ServerToDeviceMessagePayload payload_type = OpenShock::Serialization::ServerToDeviceMessagePayload::NONE,
    ::flatbuffers::Offset<void> payload = 0) {
  ServerToDeviceMessageBuilder builder_(_fbb);
  builder_.add_payload(payload);
  builder_.add_payload_type(payload_type);
  return builder_.Finish();
}

struct ServerToDeviceMessage::Traits {
  using type = ServerToDeviceMessage;
  static auto constexpr Create = CreateServerToDeviceMessage;
};

inline bool VerifyServerToDeviceMessagePayload(::flatbuffers::Verifier &verifier, const void *obj, ServerToDeviceMessagePayload type) {
  switch (type) {
    case ServerToDeviceMessagePayload::NONE: {
      return true;
    }
    case ServerToDeviceMessagePayload::ShockerCommandList: {
      auto ptr = reinterpret_cast<const OpenShock::Serialization::ShockerCommandList *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case ServerToDeviceMessagePayload::CaptivePortalConfig: {
      return verifier.VerifyField<OpenShock::Serialization::CaptivePortalConfig>(static_cast<const uint8_t *>(obj), 0, 1);
    }
    default: return true;
  }
}

inline bool VerifyServerToDeviceMessagePayloadVector(::flatbuffers::Verifier &verifier, const ::flatbuffers::Vector<::flatbuffers::Offset<void>> *values, const ::flatbuffers::Vector<ServerToDeviceMessagePayload> *types) {
  if (!values || !types) return !values && !types;
  if (values->size() != types->size()) return false;
  for (::flatbuffers::uoffset_t i = 0; i < values->size(); ++i) {
    if (!VerifyServerToDeviceMessagePayload(
        verifier,  values->Get(i), types->GetEnum<ServerToDeviceMessagePayload>(i))) {
      return false;
    }
  }
  return true;
}

inline const OpenShock::Serialization::ServerToDeviceMessage *GetServerToDeviceMessage(const void *buf) {
  return ::flatbuffers::GetRoot<OpenShock::Serialization::ServerToDeviceMessage>(buf);
}

inline const OpenShock::Serialization::ServerToDeviceMessage *GetSizePrefixedServerToDeviceMessage(const void *buf) {
  return ::flatbuffers::GetSizePrefixedRoot<OpenShock::Serialization::ServerToDeviceMessage>(buf);
}

inline bool VerifyServerToDeviceMessageBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<OpenShock::Serialization::ServerToDeviceMessage>(nullptr);
}

inline bool VerifySizePrefixedServerToDeviceMessageBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<OpenShock::Serialization::ServerToDeviceMessage>(nullptr);
}

inline void FinishServerToDeviceMessageBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<OpenShock::Serialization::ServerToDeviceMessage> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedServerToDeviceMessageBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<OpenShock::Serialization::ServerToDeviceMessage> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace Serialization
}  // namespace OpenShock

#endif  // FLATBUFFERS_GENERATED_SERVERTODEVICEMESSAGE_OPENSHOCK_SERIALIZATION_H_
