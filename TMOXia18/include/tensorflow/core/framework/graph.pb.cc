// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: graph.proto

#include "graph.pb.h"

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
extern PROTOBUF_INTERNAL_EXPORT_tensorflow_2fcore_2fframework_2ffunction_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<3> scc_info_FunctionDefLibrary_tensorflow_2fcore_2fframework_2ffunction_2eproto;
extern PROTOBUF_INTERNAL_EXPORT_tensorflow_2fcore_2fframework_2fnode_5fdef_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<3> scc_info_NodeDef_tensorflow_2fcore_2fframework_2fnode_5fdef_2eproto;
extern PROTOBUF_INTERNAL_EXPORT_tensorflow_2fcore_2fframework_2fversions_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_VersionDef_tensorflow_2fcore_2fframework_2fversions_2eproto;
namespace tensorflow {
class GraphDefDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<GraphDef> _instance;
} _GraphDef_default_instance_;
}  // namespace tensorflow
static void InitDefaultsscc_info_GraphDef_graph_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::tensorflow::_GraphDef_default_instance_;
    new (ptr) ::tensorflow::GraphDef();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::tensorflow::GraphDef::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<3> scc_info_GraphDef_graph_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 3, InitDefaultsscc_info_GraphDef_graph_2eproto}, {
      &scc_info_NodeDef_tensorflow_2fcore_2fframework_2fnode_5fdef_2eproto.base,
      &scc_info_VersionDef_tensorflow_2fcore_2fframework_2fversions_2eproto.base,
      &scc_info_FunctionDefLibrary_tensorflow_2fcore_2fframework_2ffunction_2eproto.base,}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_graph_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_graph_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_graph_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_graph_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::tensorflow::GraphDef, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::tensorflow::GraphDef, node_),
  PROTOBUF_FIELD_OFFSET(::tensorflow::GraphDef, versions_),
  PROTOBUF_FIELD_OFFSET(::tensorflow::GraphDef, version_),
  PROTOBUF_FIELD_OFFSET(::tensorflow::GraphDef, library_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::tensorflow::GraphDef)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::tensorflow::_GraphDef_default_instance_),
};

const char descriptor_table_protodef_graph_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\013graph.proto\022\ntensorflow\032(tensorflow/co"
  "re/framework/function.proto\032(tensorflow/"
  "core/framework/node_def.proto\032(tensorflo"
  "w/core/framework/versions.proto\"\235\001\n\010Grap"
  "hDef\022!\n\004node\030\001 \003(\0132\023.tensorflow.NodeDef\022"
  "(\n\010versions\030\004 \001(\0132\026.tensorflow.VersionDe"
  "f\022\023\n\007version\030\003 \001(\005B\002\030\001\022/\n\007library\030\002 \001(\0132"
  "\036.tensorflow.FunctionDefLibraryBz\n\030org.t"
  "ensorflow.frameworkB\013GraphProtosP\001ZLgith"
  "ub.com/tensorflow/tensorflow/tensorflow/"
  "go/core/framework/graph_go_proto\370\001\001b\006pro"
  "to3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_graph_2eproto_deps[3] = {
  &::descriptor_table_tensorflow_2fcore_2fframework_2ffunction_2eproto,
  &::descriptor_table_tensorflow_2fcore_2fframework_2fnode_5fdef_2eproto,
  &::descriptor_table_tensorflow_2fcore_2fframework_2fversions_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_graph_2eproto_sccs[1] = {
  &scc_info_GraphDef_graph_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_graph_2eproto_once;
static bool descriptor_table_graph_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_graph_2eproto = {
  &descriptor_table_graph_2eproto_initialized, descriptor_table_protodef_graph_2eproto, "graph.proto", 443,
  &descriptor_table_graph_2eproto_once, descriptor_table_graph_2eproto_sccs, descriptor_table_graph_2eproto_deps, 1, 3,
  schemas, file_default_instances, TableStruct_graph_2eproto::offsets,
  file_level_metadata_graph_2eproto, 1, file_level_enum_descriptors_graph_2eproto, file_level_service_descriptors_graph_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_graph_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_graph_2eproto), true);
namespace tensorflow {

// ===================================================================

void GraphDef::InitAsDefaultInstance() {
  ::tensorflow::_GraphDef_default_instance_._instance.get_mutable()->versions_ = const_cast< ::tensorflow::VersionDef*>(
      ::tensorflow::VersionDef::internal_default_instance());
  ::tensorflow::_GraphDef_default_instance_._instance.get_mutable()->library_ = const_cast< ::tensorflow::FunctionDefLibrary*>(
      ::tensorflow::FunctionDefLibrary::internal_default_instance());
}
class GraphDef::_Internal {
 public:
  static const ::tensorflow::VersionDef& versions(const GraphDef* msg);
  static const ::tensorflow::FunctionDefLibrary& library(const GraphDef* msg);
};

const ::tensorflow::VersionDef&
GraphDef::_Internal::versions(const GraphDef* msg) {
  return *msg->versions_;
}
const ::tensorflow::FunctionDefLibrary&
GraphDef::_Internal::library(const GraphDef* msg) {
  return *msg->library_;
}
void GraphDef::clear_node() {
  node_.Clear();
}
void GraphDef::unsafe_arena_set_allocated_versions(
    ::tensorflow::VersionDef* versions) {
  if (GetArenaNoVirtual() == nullptr) {
    delete versions_;
  }
  versions_ = versions;
  if (versions) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:tensorflow.GraphDef.versions)
}
void GraphDef::clear_versions() {
  if (GetArenaNoVirtual() == nullptr && versions_ != nullptr) {
    delete versions_;
  }
  versions_ = nullptr;
}
void GraphDef::unsafe_arena_set_allocated_library(
    ::tensorflow::FunctionDefLibrary* library) {
  if (GetArenaNoVirtual() == nullptr) {
    delete library_;
  }
  library_ = library;
  if (library) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:tensorflow.GraphDef.library)
}
void GraphDef::clear_library() {
  if (GetArenaNoVirtual() == nullptr && library_ != nullptr) {
    delete library_;
  }
  library_ = nullptr;
}
GraphDef::GraphDef()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:tensorflow.GraphDef)
}
GraphDef::GraphDef(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
  _internal_metadata_(arena),
  node_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:tensorflow.GraphDef)
}
GraphDef::GraphDef(const GraphDef& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      node_(from.node_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  if (from.has_library()) {
    library_ = new ::tensorflow::FunctionDefLibrary(*from.library_);
  } else {
    library_ = nullptr;
  }
  if (from.has_versions()) {
    versions_ = new ::tensorflow::VersionDef(*from.versions_);
  } else {
    versions_ = nullptr;
  }
  version_ = from.version_;
  // @@protoc_insertion_point(copy_constructor:tensorflow.GraphDef)
}

void GraphDef::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_GraphDef_graph_2eproto.base);
  ::memset(&library_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&version_) -
      reinterpret_cast<char*>(&library_)) + sizeof(version_));
}

GraphDef::~GraphDef() {
  // @@protoc_insertion_point(destructor:tensorflow.GraphDef)
  SharedDtor();
}

void GraphDef::SharedDtor() {
  GOOGLE_DCHECK(GetArenaNoVirtual() == nullptr);
  if (this != internal_default_instance()) delete library_;
  if (this != internal_default_instance()) delete versions_;
}

void GraphDef::ArenaDtor(void* object) {
  GraphDef* _this = reinterpret_cast< GraphDef* >(object);
  (void)_this;
}
void GraphDef::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void GraphDef::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const GraphDef& GraphDef::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_GraphDef_graph_2eproto.base);
  return *internal_default_instance();
}


void GraphDef::Clear() {
// @@protoc_insertion_point(message_clear_start:tensorflow.GraphDef)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  node_.Clear();
  if (GetArenaNoVirtual() == nullptr && library_ != nullptr) {
    delete library_;
  }
  library_ = nullptr;
  if (GetArenaNoVirtual() == nullptr && versions_ != nullptr) {
    delete versions_;
  }
  versions_ = nullptr;
  version_ = 0;
  _internal_metadata_.Clear();
}

#if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
const char* GraphDef::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArenaNoVirtual(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // repeated .tensorflow.NodeDef node = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(add_node(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<::PROTOBUF_NAMESPACE_ID::uint8>(ptr) == 10);
        } else goto handle_unusual;
        continue;
      // .tensorflow.FunctionDefLibrary library = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr = ctx->ParseMessage(mutable_library(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // int32 version = 3 [deprecated = true];
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          version_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // .tensorflow.VersionDef versions = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 34)) {
          ptr = ctx->ParseMessage(mutable_versions(), ptr);
          CHK_(ptr);
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
bool GraphDef::MergePartialFromCodedStream(
    ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!PROTOBUF_PREDICT_TRUE(EXPRESSION)) goto failure
  ::PROTOBUF_NAMESPACE_ID::uint32 tag;
  // @@protoc_insertion_point(parse_start:tensorflow.GraphDef)
  for (;;) {
    ::std::pair<::PROTOBUF_NAMESPACE_ID::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .tensorflow.NodeDef node = 1;
      case 1: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (10 & 0xFF)) {
          DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadMessage(
                input, add_node()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // .tensorflow.FunctionDefLibrary library = 2;
      case 2: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (18 & 0xFF)) {
          DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadMessage(
               input, mutable_library()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // int32 version = 3 [deprecated = true];
      case 3: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (24 & 0xFF)) {

          DO_((::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadPrimitive<
                   ::PROTOBUF_NAMESPACE_ID::int32, ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_INT32>(
                 input, &version_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // .tensorflow.VersionDef versions = 4;
      case 4: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (34 & 0xFF)) {
          DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadMessage(
               input, mutable_versions()));
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
  // @@protoc_insertion_point(parse_success:tensorflow.GraphDef)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:tensorflow.GraphDef)
  return false;
#undef DO_
}
#endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER

void GraphDef::SerializeWithCachedSizes(
    ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:tensorflow.GraphDef)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .tensorflow.NodeDef node = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->node_size()); i < n; i++) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteMessageMaybeToArray(
      1,
      this->node(static_cast<int>(i)),
      output);
  }

  // .tensorflow.FunctionDefLibrary library = 2;
  if (this->has_library()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, _Internal::library(this), output);
  }

  // int32 version = 3 [deprecated = true];
  if (this->version() != 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32(3, this->version(), output);
  }

  // .tensorflow.VersionDef versions = 4;
  if (this->has_versions()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteMessageMaybeToArray(
      4, _Internal::versions(this), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:tensorflow.GraphDef)
}

::PROTOBUF_NAMESPACE_ID::uint8* GraphDef::InternalSerializeWithCachedSizesToArray(
    ::PROTOBUF_NAMESPACE_ID::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:tensorflow.GraphDef)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .tensorflow.NodeDef node = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->node_size()); i < n; i++) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessageToArray(
        1, this->node(static_cast<int>(i)), target);
  }

  // .tensorflow.FunctionDefLibrary library = 2;
  if (this->has_library()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessageToArray(
        2, _Internal::library(this), target);
  }

  // int32 version = 3 [deprecated = true];
  if (this->version() != 0) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(3, this->version(), target);
  }

  // .tensorflow.VersionDef versions = 4;
  if (this->has_versions()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessageToArray(
        4, _Internal::versions(this), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:tensorflow.GraphDef)
  return target;
}

size_t GraphDef::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:tensorflow.GraphDef)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .tensorflow.NodeDef node = 1;
  {
    unsigned int count = static_cast<unsigned int>(this->node_size());
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
          this->node(static_cast<int>(i)));
    }
  }

  // .tensorflow.FunctionDefLibrary library = 2;
  if (this->has_library()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *library_);
  }

  // .tensorflow.VersionDef versions = 4;
  if (this->has_versions()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *versions_);
  }

  // int32 version = 3 [deprecated = true];
  if (this->version() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->version());
  }

  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void GraphDef::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:tensorflow.GraphDef)
  GOOGLE_DCHECK_NE(&from, this);
  const GraphDef* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<GraphDef>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:tensorflow.GraphDef)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:tensorflow.GraphDef)
    MergeFrom(*source);
  }
}

void GraphDef::MergeFrom(const GraphDef& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:tensorflow.GraphDef)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  node_.MergeFrom(from.node_);
  if (from.has_library()) {
    mutable_library()->::tensorflow::FunctionDefLibrary::MergeFrom(from.library());
  }
  if (from.has_versions()) {
    mutable_versions()->::tensorflow::VersionDef::MergeFrom(from.versions());
  }
  if (from.version() != 0) {
    set_version(from.version());
  }
}

void GraphDef::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:tensorflow.GraphDef)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GraphDef::CopyFrom(const GraphDef& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:tensorflow.GraphDef)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GraphDef::IsInitialized() const {
  return true;
}

void GraphDef::InternalSwap(GraphDef* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  CastToBase(&node_)->InternalSwap(CastToBase(&other->node_));
  swap(library_, other->library_);
  swap(versions_, other->versions_);
  swap(version_, other->version_);
}

::PROTOBUF_NAMESPACE_ID::Metadata GraphDef::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace tensorflow
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::tensorflow::GraphDef* Arena::CreateMaybeMessage< ::tensorflow::GraphDef >(Arena* arena) {
  return Arena::CreateMessageInternal< ::tensorflow::GraphDef >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
