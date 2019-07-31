/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: src/onnx.proto */

#ifndef PROTOBUF_C_src_2fonnx_2eproto__INCLUDED
#define PROTOBUF_C_src_2fonnx_2eproto__INCLUDED

#include <protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1000000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1002001 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif


typedef struct _Onnx__AttributeProto Onnx__AttributeProto;
typedef struct _Onnx__ValueInfoProto Onnx__ValueInfoProto;
typedef struct _Onnx__NodeProto Onnx__NodeProto;
typedef struct _Onnx__ModelProto Onnx__ModelProto;
typedef struct _Onnx__StringStringEntryProto Onnx__StringStringEntryProto;
typedef struct _Onnx__GraphProto Onnx__GraphProto;
typedef struct _Onnx__TensorProto Onnx__TensorProto;
typedef struct _Onnx__TensorProto__Segment Onnx__TensorProto__Segment;
typedef struct _Onnx__TensorShapeProto Onnx__TensorShapeProto;
typedef struct _Onnx__TensorShapeProto__Dimension Onnx__TensorShapeProto__Dimension;
typedef struct _Onnx__TypeProto Onnx__TypeProto;
typedef struct _Onnx__TypeProto__Tensor Onnx__TypeProto__Tensor;
typedef struct _Onnx__OperatorSetIdProto Onnx__OperatorSetIdProto;


/* --- enums --- */

/*
 * Note: this enum is structurally identical to the OpSchema::AttrType
 * enum defined in schema.h.  If you rev one, you likely need to rev the other.
 */
typedef enum _Onnx__AttributeProto__AttributeType {
  ONNX__ATTRIBUTE_PROTO__ATTRIBUTE_TYPE__UNDEFINED = 0,
  ONNX__ATTRIBUTE_PROTO__ATTRIBUTE_TYPE__FLOAT = 1,
  ONNX__ATTRIBUTE_PROTO__ATTRIBUTE_TYPE__INT = 2,
  ONNX__ATTRIBUTE_PROTO__ATTRIBUTE_TYPE__STRING = 3,
  ONNX__ATTRIBUTE_PROTO__ATTRIBUTE_TYPE__TENSOR = 4,
  ONNX__ATTRIBUTE_PROTO__ATTRIBUTE_TYPE__GRAPH = 5,
  ONNX__ATTRIBUTE_PROTO__ATTRIBUTE_TYPE__FLOATS = 6,
  ONNX__ATTRIBUTE_PROTO__ATTRIBUTE_TYPE__INTS = 7,
  ONNX__ATTRIBUTE_PROTO__ATTRIBUTE_TYPE__STRINGS = 8,
  ONNX__ATTRIBUTE_PROTO__ATTRIBUTE_TYPE__TENSORS = 9,
  ONNX__ATTRIBUTE_PROTO__ATTRIBUTE_TYPE__GRAPHS = 10
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(ONNX__ATTRIBUTE_PROTO__ATTRIBUTE_TYPE)
} Onnx__AttributeProto__AttributeType;
typedef enum _Onnx__TensorProto__DataType {
  ONNX__TENSOR_PROTO__DATA_TYPE__UNDEFINED = 0,
  /*
   * Basic types.
   */
  /*
   * float
   */
  ONNX__TENSOR_PROTO__DATA_TYPE__FLOAT = 1,
  /*
   * uint8_t
   */
  ONNX__TENSOR_PROTO__DATA_TYPE__UINT8 = 2,
  /*
   * int8_t
   */
  ONNX__TENSOR_PROTO__DATA_TYPE__INT8 = 3,
  /*
   * uint16_t
   */
  ONNX__TENSOR_PROTO__DATA_TYPE__UINT16 = 4,
  /*
   * int16_t
   */
  ONNX__TENSOR_PROTO__DATA_TYPE__INT16 = 5,
  /*
   * int32_t
   */
  ONNX__TENSOR_PROTO__DATA_TYPE__INT32 = 6,
  /*
   * int64_t
   */
  ONNX__TENSOR_PROTO__DATA_TYPE__INT64 = 7,
  /*
   * string
   */
  ONNX__TENSOR_PROTO__DATA_TYPE__STRING = 8,
  /*
   * bool
   */
  ONNX__TENSOR_PROTO__DATA_TYPE__BOOL = 9,
  /*
   * Advanced types
   */
  ONNX__TENSOR_PROTO__DATA_TYPE__FLOAT16 = 10,
  ONNX__TENSOR_PROTO__DATA_TYPE__DOUBLE = 11,
  ONNX__TENSOR_PROTO__DATA_TYPE__UINT32 = 12,
  ONNX__TENSOR_PROTO__DATA_TYPE__UINT64 = 13,
  /*
   * complex with float32 real and imaginary components
   */
  ONNX__TENSOR_PROTO__DATA_TYPE__COMPLEX64 = 14,
  /*
   * complex with float64 real and imaginary components
   */
  ONNX__TENSOR_PROTO__DATA_TYPE__COMPLEX128 = 15
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(ONNX__TENSOR_PROTO__DATA_TYPE)
} Onnx__TensorProto__DataType;
/*
 * Versioning
 * ONNX versioning is specified in docs/IR.md and elaborated on in docs/Versioning.md
 * To be compatible with both proto2 and proto3, we will use a version number
 * that is not defined by the default value but an explicit enum number.
 */
typedef enum _Onnx__Version {
  /*
   * proto3 requires the first enum value to be zero.
   * We add this just to appease the compiler.
   */
  ONNX__VERSION___START_VERSION = 0,
  /*
   * The version field is always serialized and we will use it to store the
   * version that the  graph is generated from. This helps us set up version
   * control. 
   * For the IR, we are using simple numbers starting with with 0x00000001, 
   * which was the version we published on Oct 10, 2017.
   */
  ONNX__VERSION__IR_VERSION_2017_10_10 = 1,
  /*
   * IR_VERSION 2 published on Oct 30, 2017
   * - Added type discriminator to AttributeProto to support proto3 users
   */
  ONNX__VERSION__IR_VERSION_2017_10_30 = 2,
  /*
   * IR VERSION 3 published on Nov 3, 2017
   * - For operator versioning:
   *    - Added new message OperatorSetIdProto
   *    - Added opset_import in ModelProto
   * - For vendor extensions, added domain in NodeProto
   */
  ONNX__VERSION__IR_VERSION = 3
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(ONNX__VERSION)
} Onnx__Version;

/* --- messages --- */

/*
 * Attributes
 * A named attribute containing either singular float, integer, string, graph,
 * and tensor values, or repeated float, integer, string, graph, and tensor values.
 * An AttributeProto MUST contain the name field, and *only one* of the
 * following content fields, effectively enforcing a C/C++ union equivalent.
 */
struct  _Onnx__AttributeProto
{
  ProtobufCMessage base;
  /*
   * The name field MUST be present for this version of the IR.
   */
  /*
   * namespace Attribute
   */
  char *name;
  /*
   * if ref_attr_name is not empty, ref_attr_name is the attribute name in parent function.
   * In this case, this AttributeProto does not contain data, and it's a reference of attribute
   * in parent scope.
   * NOTE: This should ONLY be used in function (sub-graph). It's invalid to be used in main graph.
   */
  char *ref_attr_name;
  /*
   * A human-readable documentation for this attribute. Markdown is allowed.
   */
  char *doc_string;
  /*
   * The type field MUST be present for this version of the IR.
   * For 0.0.1 versions of the IR, this field was not defined, and
   * implementations needed to use has_field hueristics to determine
   * which value field was in use.  For IR_VERSION 0.0.2 or later, this
   * field MUST be set and match the f|i|s|t|... field in use.  This
   * change was made to accomodate proto3 implementations.
   */
  /*
   * discriminator that indicates which field below is in use
   */
  protobuf_c_boolean has_type;
  Onnx__AttributeProto__AttributeType type;
  /*
   * Exactly ONE of the following fields must be present for this version of the IR
   */
  /*
   * float
   */
  protobuf_c_boolean has_f;
  float f;
  /*
   * int
   */
  protobuf_c_boolean has_i;
  int64_t i;
  /*
   * UTF-8 string
   */
  protobuf_c_boolean has_s;
  ProtobufCBinaryData s;
  /*
   * tensor value
   */
  Onnx__TensorProto *t;
  /*
   * graph
   */
  Onnx__GraphProto *g;
  /*
   * list of floats
   */
  size_t n_floats;
  float *floats;
  /*
   * list of ints
   */
  size_t n_ints;
  int64_t *ints;
  /*
   * list of UTF-8 strings
   */
  size_t n_strings;
  ProtobufCBinaryData *strings;
  /*
   * list of tensors
   */
  size_t n_tensors;
  Onnx__TensorProto **tensors;
  /*
   * list of graph
   */
  size_t n_graphs;
  Onnx__GraphProto **graphs;
};
#define ONNX__ATTRIBUTE_PROTO__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&onnx__attribute_proto__descriptor) \
    , NULL, NULL, NULL, 0,0, 0,0, 0,0, 0,{0,NULL}, NULL, NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL }


/*
 * Defines information on value, including the name, the type, and
 * the shape of the value.
 */
struct  _Onnx__ValueInfoProto
{
  ProtobufCMessage base;
  /*
   * This field MUST be present in this version of the IR.
   */
  /*
   * namespace Value
   */
  char *name;
  /*
   * This field MUST be present in this version of the IR.
   */
  Onnx__TypeProto *type;
  /*
   * A human-readable documentation for this value. Markdown is allowed.
   */
  char *doc_string;
};
#define ONNX__VALUE_INFO_PROTO__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&onnx__value_info_proto__descriptor) \
    , NULL, NULL, NULL }


/*
 * Nodes
 * Computation graphs are made up of a DAG of nodes, which represent what is
 * commonly called a "layer" or "pipeline stage" in machine learning frameworks.
 * For example, it can be a node of type "Conv" that takes in an image, a filter 
 * tensor and a bias tensor, and produces the convolved output.
 */
struct  _Onnx__NodeProto
{
  ProtobufCMessage base;
  /*
   * namespace Value
   */
  size_t n_input;
  char **input;
  /*
   * namespace Value
   */
  size_t n_output;
  char **output;
  /*
   * An optional identifier for this node in a graph.
   * This field MAY be absent in ths version of the IR.
   */
  /*
   * namespace Node
   */
  char *name;
  /*
   * The symbolic identifier of the Operator to execute.
   */
  /*
   * namespace Operator
   */
  char *op_type;
  /*
   * The domain of the OperatorSet that specifies the operator named by op_type.
   */
  /*
   * namespace Domain
   */
  char *domain;
  /*
   * Additional named attributes.
   */
  size_t n_attribute;
  Onnx__AttributeProto **attribute;
  /*
   * A human-readable documentation for this node. Markdown is allowed.
   */
  char *doc_string;
};
#define ONNX__NODE_PROTO__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&onnx__node_proto__descriptor) \
    , 0,NULL, 0,NULL, NULL, NULL, NULL, 0,NULL, NULL }


/*
 * Models
 * ModelProto is a top-level file/container format for bundling a ML model and
 * associating its computation graph with metadata.
 * The semantics of the model are described by the associated GraphProto.
 */
struct  _Onnx__ModelProto
{
  ProtobufCMessage base;
  /*
   * The version of the IR this model targets. See Version enum above.
   * This field MUST be present.
   */
  protobuf_c_boolean has_ir_version;
  int64_t ir_version;
  /*
   * The OperatorSets this model relies on.
   * All ModelProtos MUST have at least one entry that
   * specifies which version of the ONNX OperatorSet is
   * being imported.
   * All nodes in the ModelProto's graph will bind against the operator
   * with the same-domain/same-op_type operator with the HIGHEST version
   * in the referenced operator sets.
   */
  size_t n_opset_import;
  Onnx__OperatorSetIdProto **opset_import;
  /*
   * The name of the framework or tool used to generate this model.
   * This field SHOULD be present to indicate which implementation/tool/framework
   * emitted the model.
   */
  char *producer_name;
  /*
   * The version of the framework or tool used to generate this model.
   * This field SHOULD be present to indicate which implementation/tool/framework
   * emitted the model.
   */
  char *producer_version;
  /*
   * Domain name of the model.
   * We use reverse domain names as name space indicators. For example:
   * `com.facebook.fair` or `com.microsoft.cognitiveservices`
   * Together with `model_version` and GraphProto.name, this forms the unique identity of
   * the graph.
   */
  char *domain;
  /*
   * The version of the graph encoded. See Version enum below.
   */
  protobuf_c_boolean has_model_version;
  int64_t model_version;
  /*
   * A human-readable documentation for this model. Markdown is allowed.
   */
  char *doc_string;
  /*
   * The parameterized graph that is evaluated to execute the model.
   */
  Onnx__GraphProto *graph;
  /*
   * Named metadata values; keys should be distinct.
   */
  size_t n_metadata_props;
  Onnx__StringStringEntryProto **metadata_props;
};
#define ONNX__MODEL_PROTO__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&onnx__model_proto__descriptor) \
    , 0,0, 0,NULL, NULL, NULL, NULL, 0,0, NULL, NULL, 0,NULL }


/*
 * StringStringEntryProto follows the pattern for cross-proto-version maps.
 * See https://developers.google.com/protocol-buffers/docs/proto3#maps
 */
struct  _Onnx__StringStringEntryProto
{
  ProtobufCMessage base;
  char *key;
  char *value;
};
#define ONNX__STRING_STRING_ENTRY_PROTO__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&onnx__string_string_entry_proto__descriptor) \
    , NULL, NULL }


/*
 * Graphs
 * A graph defines the computational logic of a model and is comprised of a parameterized 
 * list of nodes that form a directed acyclic graph based on their inputs and outputs.
 * This is the equivalent of the "network" or "graph" in many deep learning
 * frameworks.
 */
struct  _Onnx__GraphProto
{
  ProtobufCMessage base;
  /*
   * The nodes in the graph, sorted topologically.
   */
  size_t n_node;
  Onnx__NodeProto **node;
  /*
   * The name of the graph.
   */
  /*
   * namespace Graph
   */
  char *name;
  /*
   * A list of named tensor values, used to specify constant inputs of the graph.
   * Each TensorProto entry must have a distinct name (within the list) that
   * also appears in the input list.
   */
  size_t n_initializer;
  Onnx__TensorProto **initializer;
  /*
   * A human-readable documentation for this graph. Markdown is allowed.
   */
  char *doc_string;
  /*
   * The inputs and outputs of the graph.
   */
  size_t n_input;
  Onnx__ValueInfoProto **input;
  size_t n_output;
  Onnx__ValueInfoProto **output;
  /*
   * Information for the values in the graph. The ValueInfoProto.name's
   * must be distinct. It is optional for a value to appear in value_info list.
   */
  size_t n_value_info;
  Onnx__ValueInfoProto **value_info;
};
#define ONNX__GRAPH_PROTO__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&onnx__graph_proto__descriptor) \
    , 0,NULL, NULL, 0,NULL, NULL, 0,NULL, 0,NULL, 0,NULL }


/*
 * For very large tensors, we may want to store them in chunks, in which
 * case the following fields will specify the segment that is stored in
 * the current TensorProto.
 */
struct  _Onnx__TensorProto__Segment
{
  ProtobufCMessage base;
  protobuf_c_boolean has_begin;
  int64_t begin;
  protobuf_c_boolean has_end;
  int64_t end;
};
#define ONNX__TENSOR_PROTO__SEGMENT__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&onnx__tensor_proto__segment__descriptor) \
    , 0,0, 0,0 }


/*
 * Tensors
 * A serialized tensor value.
 */
struct  _Onnx__TensorProto
{
  ProtobufCMessage base;
  /*
   * The shape of the tensor.
   */
  size_t n_dims;
  int64_t *dims;
  /*
   * The data type of the tensor.
   */
  protobuf_c_boolean has_data_type;
  Onnx__TensorProto__DataType data_type;
  Onnx__TensorProto__Segment *segment;
  /*
   * For float and complex64 values
   * Complex64 tensors are encoded as a single array of floats,
   * with the real components appearing in odd numbered positions,
   * and the corresponding imaginary component apparing in the
   * subsequent even numbered position. (e.g., [1.0 + 2.0i, 3.0 + 4.0i]
   * is encoded as [1.0, 2.0 ,3.0 ,4.0]
   * When this field is present, the data_type field MUST be FLOAT or COMPLEX64.
   */
  size_t n_float_data;
  float *float_data;
  /*
   * For int32, uint8, int8, uint16, int16, bool, and float16 values
   * float16 values must be bit-wise converted to an uint16_t prior
   * to writing to the buffer.
   * When this field is present, the data_type field MUST be
   * INT32, INT16, INT8, UINT16, INT8, BOOL, or FLOAT16
   */
  size_t n_int32_data;
  int32_t *int32_data;
  /*
   * For strings.
   * Each element of string_data is a UTF-8 encoded Unicode
   * string. No trailing null, no leading BOM. The protobuf "string"
   * scalar type is not used to match ML community conventions.
   * When this field is present, the data_type field MUST be STRING
   */
  size_t n_string_data;
  ProtobufCBinaryData *string_data;
  /*
   * For int64.
   * When this field is present, the data_type field MUST be INT64
   */
  size_t n_int64_data;
  int64_t *int64_data;
  /*
   * Optionally, a name for the tensor.
   */
  /*
   * namespace Value
   */
  char *name;
  /*
   * A human-readable documentation for this tensor. Markdown is allowed.
   */
  char *doc_string;
  /*
   * Serializations can either use one of the fields above, or use this
   * raw bytes field. The only exception is the string case, where one is
   * required to store the content in the repeated bytes string_data field.
   * When this raw_data field is used to store tensor value, elements MUST
   * be stored in as fixed-width, little-endian order.
   * Floating-point data types MUST be stored in IEEE 754 format.
   * Complex64 elements must be written as two consecutive FLOAT values, real component first.
   * Complex128 elements must be written as two consecutive DOUBLE values, real component first.
   * Boolean type MUST be written one byte per tensor element (00000001 for true, 00000000 for false).
   * Note: the advantage of specific field rather than the raw_data field is
   * that in some cases (e.g. int data), protobuf does a better packing via
   * variable length storage, and may lead to smaller binary footprint.
   * When this field is present, the data_type field MUST NOT be STRING or UNDEFINED
   */
  protobuf_c_boolean has_raw_data;
  ProtobufCBinaryData raw_data;
  /*
   * For double
   * Complex128 tensors are encoded as a single array of doubles,
   * with the real components appearing in odd numbered positions,
   * and the corresponding imaginary component apparing in the
   * subsequent even numbered position. (e.g., [1.0 + 2.0i, 3.0 + 4.0i]
   * is encoded as [1.0, 2.0 ,3.0 ,4.0]
   * When this field is present, the data_type field MUST be DOUBLE or COMPLEX128
   */
  size_t n_double_data;
  double *double_data;
  /*
   * For uint64 and uint32 values
   * When this field is present, the data_type field MUST be
   * UINT32 or UINT64
   */
  size_t n_uint64_data;
  uint64_t *uint64_data;
};
#define ONNX__TENSOR_PROTO__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&onnx__tensor_proto__descriptor) \
    , 0,NULL, 0,0, NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, NULL, NULL, 0,{0,NULL}, 0,NULL, 0,NULL }


typedef enum {
  ONNX__TENSOR_SHAPE_PROTO__DIMENSION__VALUE__NOT_SET = 0,
  ONNX__TENSOR_SHAPE_PROTO__DIMENSION__VALUE_DIM_VALUE = 1,
  ONNX__TENSOR_SHAPE_PROTO__DIMENSION__VALUE_DIM_PARAM = 2,
} Onnx__TensorShapeProto__Dimension__ValueCase;

struct  _Onnx__TensorShapeProto__Dimension
{
  ProtobufCMessage base;
  /*
   * Standard denotation can optionally be used to denote tensor
   * dimensions with standard semantic descriptions to ensure
   * that operations are applied to the correct axis of a tensor.
   * Refer to https://github.com/onnx/onnx/blob/master/docs/DimensionDenotation.md#denotation-definition
   * for pre-defined dimension denotations.
   */
  char *denotation;
  Onnx__TensorShapeProto__Dimension__ValueCase value_case;
  union {
    int64_t dim_value;
    /*
     * namespace Shape
     */
    char *dim_param;
  };
};
#define ONNX__TENSOR_SHAPE_PROTO__DIMENSION__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&onnx__tensor_shape_proto__dimension__descriptor) \
    , NULL, ONNX__TENSOR_SHAPE_PROTO__DIMENSION__VALUE__NOT_SET, {0} }


/*
 * Defines a tensor shape. A dimension can be either an integer value
 * or a symbolic variable. A symbolic variable represents an unknown
 * dimension.
 */
struct  _Onnx__TensorShapeProto
{
  ProtobufCMessage base;
  size_t n_dim;
  Onnx__TensorShapeProto__Dimension **dim;
};
#define ONNX__TENSOR_SHAPE_PROTO__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&onnx__tensor_shape_proto__descriptor) \
    , 0,NULL }


struct  _Onnx__TypeProto__Tensor
{
  ProtobufCMessage base;
  /*
   * This field MUST NOT have the value of UNDEFINED
   * This field MUST be present for this version of the IR.
   */
  protobuf_c_boolean has_elem_type;
  Onnx__TensorProto__DataType elem_type;
  Onnx__TensorShapeProto *shape;
};
#define ONNX__TYPE_PROTO__TENSOR__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&onnx__type_proto__tensor__descriptor) \
    , 0,0, NULL }


typedef enum {
  ONNX__TYPE_PROTO__VALUE__NOT_SET = 0,
  ONNX__TYPE_PROTO__VALUE_TENSOR_TYPE = 1,
} Onnx__TypeProto__ValueCase;

/*
 * Types
 * The standard ONNX data types.
 */
struct  _Onnx__TypeProto
{
  ProtobufCMessage base;
  /*
   * An optional denotation can be used to denote the whole 
   * type with a standard semantic description as to what is 
   * stored inside. Refer to https://github.com/onnx/onnx/blob/master/docs/TypeDenotation.md#type-denotation-definition
   * for pre-defined type denotations.
   */
  char *denotation;
  Onnx__TypeProto__ValueCase value_case;
  union {
    /*
     * The type of a tensor.
     */
    Onnx__TypeProto__Tensor *tensor_type;
  };
};
#define ONNX__TYPE_PROTO__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&onnx__type_proto__descriptor) \
    , NULL, ONNX__TYPE_PROTO__VALUE__NOT_SET, {0} }


/*
 * Operator Sets
 * OperatorSets are uniquely identified by a (domain, opset_version) pair.
 */
struct  _Onnx__OperatorSetIdProto
{
  ProtobufCMessage base;
  /*
   * The domain of the operator set being identified.
   * The empty string ("") or absence of this field implies the operator
   * set that is defined as part of the ONNX specification.
   * This field MUST be present in this version of the IR when referring to any other operator set.
   */
  char *domain;
  /*
   * The version of the operator set being identified.
   * This field MUST be present in this version of the IR.
   */
  protobuf_c_boolean has_version;
  int64_t version;
};
#define ONNX__OPERATOR_SET_ID_PROTO__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&onnx__operator_set_id_proto__descriptor) \
    , NULL, 0,0 }


/* Onnx__AttributeProto methods */
void   onnx__attribute_proto__init
                     (Onnx__AttributeProto         *message);
size_t onnx__attribute_proto__get_packed_size
                     (const Onnx__AttributeProto   *message);
size_t onnx__attribute_proto__pack
                     (const Onnx__AttributeProto   *message,
                      uint8_t             *out);
size_t onnx__attribute_proto__pack_to_buffer
                     (const Onnx__AttributeProto   *message,
                      ProtobufCBuffer     *buffer);
Onnx__AttributeProto *
       onnx__attribute_proto__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   onnx__attribute_proto__free_unpacked
                     (Onnx__AttributeProto *message,
                      ProtobufCAllocator *allocator);
/* Onnx__ValueInfoProto methods */
void   onnx__value_info_proto__init
                     (Onnx__ValueInfoProto         *message);
size_t onnx__value_info_proto__get_packed_size
                     (const Onnx__ValueInfoProto   *message);
size_t onnx__value_info_proto__pack
                     (const Onnx__ValueInfoProto   *message,
                      uint8_t             *out);
size_t onnx__value_info_proto__pack_to_buffer
                     (const Onnx__ValueInfoProto   *message,
                      ProtobufCBuffer     *buffer);
Onnx__ValueInfoProto *
       onnx__value_info_proto__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   onnx__value_info_proto__free_unpacked
                     (Onnx__ValueInfoProto *message,
                      ProtobufCAllocator *allocator);
/* Onnx__NodeProto methods */
void   onnx__node_proto__init
                     (Onnx__NodeProto         *message);
size_t onnx__node_proto__get_packed_size
                     (const Onnx__NodeProto   *message);
size_t onnx__node_proto__pack
                     (const Onnx__NodeProto   *message,
                      uint8_t             *out);
size_t onnx__node_proto__pack_to_buffer
                     (const Onnx__NodeProto   *message,
                      ProtobufCBuffer     *buffer);
Onnx__NodeProto *
       onnx__node_proto__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   onnx__node_proto__free_unpacked
                     (Onnx__NodeProto *message,
                      ProtobufCAllocator *allocator);
/* Onnx__ModelProto methods */
void   onnx__model_proto__init
                     (Onnx__ModelProto         *message);
size_t onnx__model_proto__get_packed_size
                     (const Onnx__ModelProto   *message);
size_t onnx__model_proto__pack
                     (const Onnx__ModelProto   *message,
                      uint8_t             *out);
size_t onnx__model_proto__pack_to_buffer
                     (const Onnx__ModelProto   *message,
                      ProtobufCBuffer     *buffer);
Onnx__ModelProto *
       onnx__model_proto__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   onnx__model_proto__free_unpacked
                     (Onnx__ModelProto *message,
                      ProtobufCAllocator *allocator);
/* Onnx__StringStringEntryProto methods */
void   onnx__string_string_entry_proto__init
                     (Onnx__StringStringEntryProto         *message);
size_t onnx__string_string_entry_proto__get_packed_size
                     (const Onnx__StringStringEntryProto   *message);
size_t onnx__string_string_entry_proto__pack
                     (const Onnx__StringStringEntryProto   *message,
                      uint8_t             *out);
size_t onnx__string_string_entry_proto__pack_to_buffer
                     (const Onnx__StringStringEntryProto   *message,
                      ProtobufCBuffer     *buffer);
Onnx__StringStringEntryProto *
       onnx__string_string_entry_proto__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   onnx__string_string_entry_proto__free_unpacked
                     (Onnx__StringStringEntryProto *message,
                      ProtobufCAllocator *allocator);
/* Onnx__GraphProto methods */
void   onnx__graph_proto__init
                     (Onnx__GraphProto         *message);
size_t onnx__graph_proto__get_packed_size
                     (const Onnx__GraphProto   *message);
size_t onnx__graph_proto__pack
                     (const Onnx__GraphProto   *message,
                      uint8_t             *out);
size_t onnx__graph_proto__pack_to_buffer
                     (const Onnx__GraphProto   *message,
                      ProtobufCBuffer     *buffer);
Onnx__GraphProto *
       onnx__graph_proto__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   onnx__graph_proto__free_unpacked
                     (Onnx__GraphProto *message,
                      ProtobufCAllocator *allocator);
/* Onnx__TensorProto__Segment methods */
void   onnx__tensor_proto__segment__init
                     (Onnx__TensorProto__Segment         *message);
/* Onnx__TensorProto methods */
void   onnx__tensor_proto__init
                     (Onnx__TensorProto         *message);
size_t onnx__tensor_proto__get_packed_size
                     (const Onnx__TensorProto   *message);
size_t onnx__tensor_proto__pack
                     (const Onnx__TensorProto   *message,
                      uint8_t             *out);
size_t onnx__tensor_proto__pack_to_buffer
                     (const Onnx__TensorProto   *message,
                      ProtobufCBuffer     *buffer);
Onnx__TensorProto *
       onnx__tensor_proto__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   onnx__tensor_proto__free_unpacked
                     (Onnx__TensorProto *message,
                      ProtobufCAllocator *allocator);
/* Onnx__TensorShapeProto__Dimension methods */
void   onnx__tensor_shape_proto__dimension__init
                     (Onnx__TensorShapeProto__Dimension         *message);
/* Onnx__TensorShapeProto methods */
void   onnx__tensor_shape_proto__init
                     (Onnx__TensorShapeProto         *message);
size_t onnx__tensor_shape_proto__get_packed_size
                     (const Onnx__TensorShapeProto   *message);
size_t onnx__tensor_shape_proto__pack
                     (const Onnx__TensorShapeProto   *message,
                      uint8_t             *out);
size_t onnx__tensor_shape_proto__pack_to_buffer
                     (const Onnx__TensorShapeProto   *message,
                      ProtobufCBuffer     *buffer);
Onnx__TensorShapeProto *
       onnx__tensor_shape_proto__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   onnx__tensor_shape_proto__free_unpacked
                     (Onnx__TensorShapeProto *message,
                      ProtobufCAllocator *allocator);
/* Onnx__TypeProto__Tensor methods */
void   onnx__type_proto__tensor__init
                     (Onnx__TypeProto__Tensor         *message);
/* Onnx__TypeProto methods */
void   onnx__type_proto__init
                     (Onnx__TypeProto         *message);
size_t onnx__type_proto__get_packed_size
                     (const Onnx__TypeProto   *message);
size_t onnx__type_proto__pack
                     (const Onnx__TypeProto   *message,
                      uint8_t             *out);
size_t onnx__type_proto__pack_to_buffer
                     (const Onnx__TypeProto   *message,
                      ProtobufCBuffer     *buffer);
Onnx__TypeProto *
       onnx__type_proto__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   onnx__type_proto__free_unpacked
                     (Onnx__TypeProto *message,
                      ProtobufCAllocator *allocator);
/* Onnx__OperatorSetIdProto methods */
void   onnx__operator_set_id_proto__init
                     (Onnx__OperatorSetIdProto         *message);
size_t onnx__operator_set_id_proto__get_packed_size
                     (const Onnx__OperatorSetIdProto   *message);
size_t onnx__operator_set_id_proto__pack
                     (const Onnx__OperatorSetIdProto   *message,
                      uint8_t             *out);
size_t onnx__operator_set_id_proto__pack_to_buffer
                     (const Onnx__OperatorSetIdProto   *message,
                      ProtobufCBuffer     *buffer);
Onnx__OperatorSetIdProto *
       onnx__operator_set_id_proto__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   onnx__operator_set_id_proto__free_unpacked
                     (Onnx__OperatorSetIdProto *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*Onnx__AttributeProto_Closure)
                 (const Onnx__AttributeProto *message,
                  void *closure_data);
typedef void (*Onnx__ValueInfoProto_Closure)
                 (const Onnx__ValueInfoProto *message,
                  void *closure_data);
typedef void (*Onnx__NodeProto_Closure)
                 (const Onnx__NodeProto *message,
                  void *closure_data);
typedef void (*Onnx__ModelProto_Closure)
                 (const Onnx__ModelProto *message,
                  void *closure_data);
typedef void (*Onnx__StringStringEntryProto_Closure)
                 (const Onnx__StringStringEntryProto *message,
                  void *closure_data);
typedef void (*Onnx__GraphProto_Closure)
                 (const Onnx__GraphProto *message,
                  void *closure_data);
typedef void (*Onnx__TensorProto__Segment_Closure)
                 (const Onnx__TensorProto__Segment *message,
                  void *closure_data);
typedef void (*Onnx__TensorProto_Closure)
                 (const Onnx__TensorProto *message,
                  void *closure_data);
typedef void (*Onnx__TensorShapeProto__Dimension_Closure)
                 (const Onnx__TensorShapeProto__Dimension *message,
                  void *closure_data);
typedef void (*Onnx__TensorShapeProto_Closure)
                 (const Onnx__TensorShapeProto *message,
                  void *closure_data);
typedef void (*Onnx__TypeProto__Tensor_Closure)
                 (const Onnx__TypeProto__Tensor *message,
                  void *closure_data);
typedef void (*Onnx__TypeProto_Closure)
                 (const Onnx__TypeProto *message,
                  void *closure_data);
typedef void (*Onnx__OperatorSetIdProto_Closure)
                 (const Onnx__OperatorSetIdProto *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCEnumDescriptor    onnx__version__descriptor;
extern const ProtobufCMessageDescriptor onnx__attribute_proto__descriptor;
extern const ProtobufCEnumDescriptor    onnx__attribute_proto__attribute_type__descriptor;
extern const ProtobufCMessageDescriptor onnx__value_info_proto__descriptor;
extern const ProtobufCMessageDescriptor onnx__node_proto__descriptor;
extern const ProtobufCMessageDescriptor onnx__model_proto__descriptor;
extern const ProtobufCMessageDescriptor onnx__string_string_entry_proto__descriptor;
extern const ProtobufCMessageDescriptor onnx__graph_proto__descriptor;
extern const ProtobufCMessageDescriptor onnx__tensor_proto__descriptor;
extern const ProtobufCMessageDescriptor onnx__tensor_proto__segment__descriptor;
extern const ProtobufCEnumDescriptor    onnx__tensor_proto__data_type__descriptor;
extern const ProtobufCMessageDescriptor onnx__tensor_shape_proto__descriptor;
extern const ProtobufCMessageDescriptor onnx__tensor_shape_proto__dimension__descriptor;
extern const ProtobufCMessageDescriptor onnx__type_proto__descriptor;
extern const ProtobufCMessageDescriptor onnx__type_proto__tensor__descriptor;
extern const ProtobufCMessageDescriptor onnx__operator_set_id_proto__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_src_2fonnx_2eproto__INCLUDED */
