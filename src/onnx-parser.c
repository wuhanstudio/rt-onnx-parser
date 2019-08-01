#include "onnx-parser.h"

const char* onnx_tensor_proto_data_type[] = {
    "Undefined", 
    "FLOAT",
    "UINT8",
    "INT8",
    "UINT16",
    "INT16",
    "INT32",
    "INT64",
    "STRING",
    "BOOL",
    "FLOAT16",
    "DOUBLE",
    "UINT32",
    "UINT64",
    "COMPLEX64",
    "COMPLEX128"
};

Onnx__ModelProto* onnx_load_model(const char* onnx_file_name)
{
    rt_kprintf("Load model %s\n", onnx_file_name);
    // Get file size first
    int ret;
    struct stat buf;
    ret = stat(onnx_file_name, &buf);
    if(ret == 0)
    {
        rt_kprintf("%s file size = %d\n", onnx_file_name, buf.st_size);
    }
    else
    {
        rt_kprintf("%s file not fonud\n", onnx_file_name);
        return RT_NULL;
    }

    // Read protobuf file
    size_t msg_len = buf.st_size;
    rt_uint8_t* buffer = (rt_uint8_t*) rt_malloc(sizeof(rt_uint8_t) * msg_len);
    if(buffer == RT_NULL)
    {
        rt_kprintf("Failed to malloc memory for %s\n", onnx_file_name);
        return RT_NULL;
    }

    int fd = open(onnx_file_name, O_RDONLY);
    if (fd>= 0)
    {
        int size = read(fd, buffer, msg_len);
        close(fd);
        if (size < 0)
        {
			rt_kprintf("Read file %s failed \n", onnx_file_name);
            return RT_NULL;
        }
		rt_kprintf("Sucessfully read file %s\n", onnx_file_name);
    }

    Onnx__ModelProto* model = onnx__model_proto__unpack(NULL, msg_len, buffer);
	rt_kprintf("Free memory %s\n", onnx_file_name);
	rt_free(buffer);

    return model;
}

void onnx_model_info(Onnx__ModelProto model)
{
    rt_kprintf("---- Model info ----\n");
    rt_kprintf("IR Version is %ld\n", model.ir_version);
    rt_kprintf("Produceer name is %s\n", model.producer_name);
    rt_kprintf("Produceer version is %s\n", model.producer_version);
    rt_kprintf("Produceer version is %s\n", model.domain);
}

void onnx_graph_info(Onnx__GraphProto graph)
{
    rt_kprintf("---- Graph Info ----\n");
    
    // Input
    rt_kprintf("---- Graph Input Info ----\n");
    rt_kprintf("Graph inputs number: %ld\n", graph.n_input);
    for(int i = 0; i < graph.n_input; i++)
    {
        onnx_graph_input_info(*graph.input[i]);
    }

    // Output
    rt_kprintf("---- Graph Output Info ----\n");
    rt_kprintf("Graph outputs number: %ld\n", graph.n_output);
    for(int i = 0; i < graph.n_output; i++)
    {
        onnx_graph_output_info(*graph.output[i]);
    }

    // Nodes
    rt_kprintf("---- Graph Node Info ----\n");
    rt_kprintf("Graph nodes number: %ld\n", graph.n_node);
    for(int i = 0; i < graph.n_node; i++)
    {
        onnx_graph_node_info(*graph.node[i]);
    }
}

void onnx_graph_info_sorted(Onnx__GraphProto graph)
{
    rt_kprintf("---- Graph Info ----\n");
    
    // Input
    rt_kprintf("---- Graph Input Info ----\n");
    rt_kprintf("Graph inputs number: %ld\n", graph.n_input);
    for(int i = 0; i < graph.n_input; i++)
    {
        onnx_graph_input_info(*graph.input[i]);
    }

    // Output
    rt_kprintf("---- Graph Output Info ----\n");
    rt_kprintf("Graph outputs number: %ld\n", graph.n_output);
    for(int i = 0; i < graph.n_output; i++)
    {
        onnx_graph_output_info(*graph.output[i]);
    }

    // Nodes
    rt_kprintf("---- Graph Node Info ----\n");
    rt_kprintf("Graph nodes number: %ld\n", graph.n_node);
    Onnx__NodeProto* node = onnx_graph_get_node_by_input(graph, graph.input[0]->name);

    while(node != NULL)
    {
        onnx_graph_node_info(*node);
        node = onnx_graph_get_node_by_input(graph, node->output[0]);
    }

}

void onnx_graph_input_info(Onnx__ValueInfoProto input)
{
    rt_kprintf("Input name %s\n", input.name);

    Onnx__TypeProto type = *(input.type);
    Onnx__TypeProto__Tensor tensor_type = *(type.tensor_type);
    Onnx__TensorShapeProto shape = *(tensor_type.shape);

    rt_kprintf("Input type %s\n", onnx_tensor_proto_data_type[tensor_type.elem_type]);
    rt_kprintf("Input dimension %ld\n", shape.n_dim);
    
    for(int i = 0; i < shape.n_dim; i++)
    {
        onnx_graph_value_tensor_shape_dimension_info(*(shape.dim[i]));
        if( i != shape.n_dim - 1)
        {
            rt_kprintf(" x ");
        }
    }
    rt_kprintf("\n");
}

void onnx_graph_value_tensor_shape_dimension_info(Onnx__TensorShapeProto__Dimension dim)
{
    
    switch (dim.value_case)
    {
        case ONNX__TENSOR_SHAPE_PROTO__DIMENSION__VALUE__NOT_SET:
            rt_kprintf("?");
            break;
        case ONNX__TENSOR_SHAPE_PROTO__DIMENSION__VALUE_DIM_VALUE:
            rt_kprintf("%ld",dim.dim_value);
            break;
        case ONNX__TENSOR_SHAPE_PROTO__DIMENSION__VALUE_DIM_PARAM:
            rt_kprintf("%s",dim.dim_param);
            break;
        default:
            rt_kprintf("?");
            break;
    }
}

void onnx_graph_output_info(Onnx__ValueInfoProto output)
{
    rt_kprintf("Output name %s\n", output.name);

    Onnx__TypeProto type = *(output.type);
    Onnx__TypeProto__Tensor tensor_type = *(type.tensor_type);
    Onnx__TensorShapeProto shape = *(tensor_type.shape);

    rt_kprintf("Output type %s\n", onnx_tensor_proto_data_type[tensor_type.elem_type]);
    rt_kprintf("Output dimension %ld\n", shape.n_dim);
    
    for(int i = 0; i < shape.n_dim; i++)
    {
        onnx_graph_value_tensor_shape_dimension_info(*(shape.dim[i]));
        if( i != shape.n_dim - 1)
        {
            rt_kprintf(" x ");
        }
    }
    rt_kprintf("\n");
}

Onnx__NodeProto* onnx_graph_get_node_by_input(Onnx__GraphProto graph, const char* node_name)
{
    for(int i = 0; i < graph.n_node; i++)
    {
        Onnx__NodeProto* node = graph.node[i];
        for(int j = 0; j < node->n_input; j++)
        {
            if( strcmp(node->input[j], node_name) == 0)
            {
                return node;
            }
        }
    }

    return NULL;
}

void onnx_graph_node_info(Onnx__NodeProto node)
{
    rt_kprintf("%-12s: %-30s ->    %-30s [%s]\n", node.op_type, node.input[0], node.output[0], node.name);
}
