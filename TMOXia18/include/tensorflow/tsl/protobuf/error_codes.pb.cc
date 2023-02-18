// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: error_codes.proto

#include "error_codes.pb.h"

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
namespace error {
}  // namespace error
}  // namespace tensorflow
static constexpr ::PROTOBUF_NAMESPACE_ID::Metadata* file_level_metadata_error_5fcodes_2eproto = nullptr;
static const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* file_level_enum_descriptors_error_5fcodes_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_error_5fcodes_2eproto = nullptr;
const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_error_5fcodes_2eproto::offsets[1] = {};
static constexpr ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema* schemas = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::Message* const* file_default_instances = nullptr;

const char descriptor_table_protodef_error_5fcodes_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\021error_codes.proto\022\020tensorflow.error*\204\003"
  "\n\004Code\022\006\n\002OK\020\000\022\r\n\tCANCELLED\020\001\022\013\n\007UNKNOWN"
  "\020\002\022\024\n\020INVALID_ARGUMENT\020\003\022\025\n\021DEADLINE_EXC"
  "EEDED\020\004\022\r\n\tNOT_FOUND\020\005\022\022\n\016ALREADY_EXISTS"
  "\020\006\022\025\n\021PERMISSION_DENIED\020\007\022\023\n\017UNAUTHENTIC"
  "ATED\020\020\022\026\n\022RESOURCE_EXHAUSTED\020\010\022\027\n\023FAILED"
  "_PRECONDITION\020\t\022\013\n\007ABORTED\020\n\022\020\n\014OUT_OF_R"
  "ANGE\020\013\022\021\n\rUNIMPLEMENTED\020\014\022\014\n\010INTERNAL\020\r\022"
  "\017\n\013UNAVAILABLE\020\016\022\r\n\tDATA_LOSS\020\017\022K\nGDO_NO"
  "T_USE_RESERVED_FOR_FUTURE_EXPANSION_USE_"
  "DEFAULT_IN_SWITCH_INSTEAD_\020\024Bq\n\030org.tens"
  "orflow.frameworkB\020ErrorCodesProtosP\001Z>gi"
  "thub.com/google/tsl/tsl/go/protobuf/for_"
  "core_protos_go_proto\370\001\001b\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_error_5fcodes_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_error_5fcodes_2eproto_sccs[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_error_5fcodes_2eproto_once;
static bool descriptor_table_error_5fcodes_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_error_5fcodes_2eproto = {
  &descriptor_table_error_5fcodes_2eproto_initialized, descriptor_table_protodef_error_5fcodes_2eproto, "error_codes.proto", 551,
  &descriptor_table_error_5fcodes_2eproto_once, descriptor_table_error_5fcodes_2eproto_sccs, descriptor_table_error_5fcodes_2eproto_deps, 0, 0,
  schemas, file_default_instances, TableStruct_error_5fcodes_2eproto::offsets,
  file_level_metadata_error_5fcodes_2eproto, 0, file_level_enum_descriptors_error_5fcodes_2eproto, file_level_service_descriptors_error_5fcodes_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_error_5fcodes_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_error_5fcodes_2eproto), true);
namespace tensorflow {
namespace error {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* Code_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_error_5fcodes_2eproto);
  return file_level_enum_descriptors_error_5fcodes_2eproto[0];
}
bool Code_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 20:
      return true;
    default:
      return false;
  }
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace error
}  // namespace tensorflow
PROTOBUF_NAMESPACE_OPEN
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
