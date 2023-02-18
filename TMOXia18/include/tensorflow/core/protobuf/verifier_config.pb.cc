// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: verifier_config.proto

#include "verifier_config.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
namespace tensorflow {
class VerifierConfigDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<VerifierConfig> _instance;
} _VerifierConfig_default_instance_;
}  // namespace tensorflow
static void InitDefaultsscc_info_VerifierConfig_verifier_5fconfig_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::tensorflow::_VerifierConfig_default_instance_;
    new (ptr) ::tensorflow::VerifierConfig();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::tensorflow::VerifierConfig::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_VerifierConfig_verifier_5fconfig_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsscc_info_VerifierConfig_verifier_5fconfig_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_verifier_5fconfig_2eproto[1];
static const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* file_level_enum_descriptors_verifier_5fconfig_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_verifier_5fconfig_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_verifier_5fconfig_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::tensorflow::VerifierConfig, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::tensorflow::VerifierConfig, verification_timeout_in_ms_),
  PROTOBUF_FIELD_OFFSET(::tensorflow::VerifierConfig, structure_verifier_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::tensorflow::VerifierConfig)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::tensorflow::_VerifierConfig_default_instance_),
};

const char descriptor_table_protodef_verifier_5fconfig_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\025verifier_config.proto\022\ntensorflow\"\233\001\n\016"
  "VerifierConfig\022\"\n\032verification_timeout_i"
  "n_ms\030\001 \001(\003\022=\n\022structure_verifier\030\002 \001(\0162!"
  ".tensorflow.VerifierConfig.Toggle\"&\n\006Tog"
  "gle\022\013\n\007DEFAULT\020\000\022\006\n\002ON\020\001\022\007\n\003OFF\020\002B\214\001\n\030or"
  "g.tensorflow.frameworkB\024VerifierConfigPr"
  "otosP\001ZUgithub.com/tensorflow/tensorflow"
  "/tensorflow/go/core/protobuf/for_core_pr"
  "otos_go_proto\370\001\001b\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_verifier_5fconfig_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_verifier_5fconfig_2eproto_sccs[1] = {
  &scc_info_VerifierConfig_verifier_5fconfig_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_verifier_5fconfig_2eproto_once;
static bool descriptor_table_verifier_5fconfig_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_verifier_5fconfig_2eproto = {
  &descriptor_table_verifier_5fconfig_2eproto_initialized, descriptor_table_protodef_verifier_5fconfig_2eproto, "verifier_config.proto", 344,
  &descriptor_table_verifier_5fconfig_2eproto_once, descriptor_table_verifier_5fconfig_2eproto_sccs, descriptor_table_verifier_5fconfig_2eproto_deps, 1, 0,
  schemas, file_default_instances, TableStruct_verifier_5fconfig_2eproto::offsets,
  file_level_metadata_verifier_5fconfig_2eproto, 1, file_level_enum_descriptors_verifier_5fconfig_2eproto, file_level_service_descriptors_verifier_5fconfig_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_verifier_5fconfig_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_verifier_5fconfig_2eproto), true);
namespace tensorflow {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* VerifierConfig_Toggle_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_verifier_5fconfig_2eproto);
  return file_level_enum_descriptors_verifier_5fconfig_2eproto[0];
}
bool VerifierConfig_Toggle_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}

#if (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)
constexpr VerifierConfig_Toggle VerifierConfig::DEFAULT;
constexpr VerifierConfig_Toggle VerifierConfig::ON;
constexpr VerifierConfig_Toggle VerifierConfig::OFF;
constexpr VerifierConfig_Toggle VerifierConfig::Toggle_MIN;
constexpr VerifierConfig_Toggle VerifierConfig::Toggle_MAX;
constexpr int VerifierConfig::Toggle_ARRAYSIZE;
#endif  // (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)

// ===================================================================

void VerifierConfig::InitAsDefaultInstance() {
}
class VerifierConfig::_Internal {
 public:
};

VerifierConfig::VerifierConfig()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:tensorflow.VerifierConfig)
}
VerifierConfig::VerifierConfig(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
  _internal_metadata_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:tensorflow.VerifierConfig)
}
VerifierConfig::VerifierConfig(const VerifierConfig& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::memcpy(&verification_timeout_in_ms_, &from.verification_timeout_in_ms_,
    static_cast<size_t>(reinterpret_cast<char*>(&structure_verifier_) -
    reinterpret_cast<char*>(&verification_timeout_in_ms_)) + sizeof(structure_verifier_));
  // @@protoc_insertion_point(copy_constructor:tensorflow.VerifierConfig)
}

void VerifierConfig::SharedCtor() {
  ::memset(&verification_timeout_in_ms_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&structure_verifier_) -
      reinterpret_cast<char*>(&verification_timeout_in_ms_)) + sizeof(structure_verifier_));
}

VerifierConfig::~VerifierConfig() {
  // @@protoc_insertion_point(destructor:tensorflow.VerifierConfig)
  SharedDtor();
}

void VerifierConfig::SharedDtor() {
  GOOGLE_DCHECK(GetArenaNoVirtual() == nullptr);
}

void VerifierConfig::ArenaDtor(void* object) {
  VerifierConfig* _this = reinterpret_cast< VerifierConfig* >(object);
  (void)_this;
}
void VerifierConfig::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void VerifierConfig::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const VerifierConfig& VerifierConfig::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_VerifierConfig_verifier_5fconfig_2eproto.base);
  return *internal_default_instance();
}


void VerifierConfig::Clear() {
// @@protoc_insertion_point(message_clear_start:tensorflow.VerifierConfig)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&verification_timeout_in_ms_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&structure_verifier_) -
      reinterpret_cast<char*>(&verification_timeout_in_ms_)) + sizeof(structure_verifier_));
  _internal_metadata_.Clear();
}

#if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
const char* VerifierConfig::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArenaNoVirtual(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // int64 verification_timeout_in_ms = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          verification_timeout_in_ms_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // .tensorflow.VerifierConfig.Toggle structure_verifier = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
          set_structure_verifier(static_cast<::tensorflow::VerifierConfig_Toggle>(val));
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}
#else  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
bool VerifierConfig::MergePartialFromCodedStream(
    ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!PROTOBUF_PREDICT_TRUE(EXPRESSION)) goto failure
  ::PROTOBUF_NAMESPACE_ID::uint32 tag;
  // @@protoc_insertion_point(parse_start:tensorflow.VerifierConfig)
  for (;;) {
    ::std::pair<::PROTOBUF_NAMESPACE_ID::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // int64 verification_timeout_in_ms = 1;
      case 1: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (8 & 0xFF)) {

          DO_((::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadPrimitive<
                   ::PROTOBUF_NAMESPACE_ID::int64, ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_INT64>(
                 input, &verification_timeout_in_ms_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // .tensorflow.VerifierConfig.Toggle structure_verifier = 2;
      case 2: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (16 & 0xFF)) {
          int value = 0;
          DO_((::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadPrimitive<
                   int, ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          set_structure_verifier(static_cast< ::tensorflow::VerifierConfig_Toggle >(value));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:tensorflow.VerifierConfig)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:tensorflow.VerifierConfig)
  return false;
#undef DO_
}
#endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER

void VerifierConfig::SerializeWithCachedSizes(
    ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:tensorflow.VerifierConfig)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int64 verification_timeout_in_ms = 1;
  if (this->verification_timeout_in_ms() != 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt64(1, this->verification_timeout_in_ms(), output);
  }

  // .tensorflow.VerifierConfig.Toggle structure_verifier = 2;
  if (this->structure_verifier() != 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnum(
      2, this->structure_verifier(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:tensorflow.VerifierConfig)
}

::PROTOBUF_NAMESPACE_ID::uint8* VerifierConfig::InternalSerializeWithCachedSizesToArray(
    ::PROTOBUF_NAMESPACE_ID::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:tensorflow.VerifierConfig)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int64 verification_timeout_in_ms = 1;
  if (this->verification_timeout_in_ms() != 0) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt64ToArray(1, this->verification_timeout_in_ms(), target);
  }

  // .tensorflow.VerifierConfig.Toggle structure_verifier = 2;
  if (this->structure_verifier() != 0) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      2, this->structure_verifier(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:tensorflow.VerifierConfig)
  return target;
}

size_t VerifierConfig::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:tensorflow.VerifierConfig)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // int64 verification_timeout_in_ms = 1;
  if (this->verification_timeout_in_ms() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int64Size(
        this->verification_timeout_in_ms());
  }

  // .tensorflow.VerifierConfig.Toggle structure_verifier = 2;
  if (this->structure_verifier() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->structure_verifier());
  }

  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void VerifierConfig::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:tensorflow.VerifierConfig)
  GOOGLE_DCHECK_NE(&from, this);
  const VerifierConfig* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<VerifierConfig>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:tensorflow.VerifierConfig)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:tensorflow.VerifierConfig)
    MergeFrom(*source);
  }
}

void VerifierConfig::MergeFrom(const VerifierConfig& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:tensorflow.VerifierConfig)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.verification_timeout_in_ms() != 0) {
    set_verification_timeout_in_ms(from.verification_timeout_in_ms());
  }
  if (from.structure_verifier() != 0) {
    set_structure_verifier(from.structure_verifier());
  }
}

void VerifierConfig::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:tensorflow.VerifierConfig)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void VerifierConfig::CopyFrom(const VerifierConfig& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:tensorflow.VerifierConfig)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool VerifierConfig::IsInitialized() const {
  return true;
}

void VerifierConfig::InternalSwap(VerifierConfig* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(verification_timeout_in_ms_, other->verification_timeout_in_ms_);
  swap(structure_verifier_, other->structure_verifier_);
}

::PROTOBUF_NAMESPACE_ID::Metadata VerifierConfig::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace tensorflow
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::tensorflow::VerifierConfig* Arena::CreateMaybeMessage< ::tensorflow::VerifierConfig >(Arena* arena) {
  return Arena::CreateMessageInternal< ::tensorflow::VerifierConfig >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
