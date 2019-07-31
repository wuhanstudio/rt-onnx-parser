#include "onnx-parser.h"

static void onnx_parser_example(int argc,char *argv[])
{
    if (argc < 2) {
        rt_kprintf("Usage: %s onnx_file_name \n", argv[0]);
        rt_kprintf("Example: %s /mnist.onnx \n", argv[0]);
        return;
    }
    rt_kprintf("--- Reading from %s ---\n", argv[1]);

    // Load Model
    Onnx__ModelProto* model = onnx_load_model(argv[1]);

    // Print Model Info
    if( model != NULL)
    {
        onnx_model_info(*model);
    }
    else
    {
        rt_kprintf("Decode model failed\n");
    }
    /*
    // Print Graph Info
    Onnx__GraphProto* graph = model->graph;
    if(graph != NULL)
    {
        onnx_graph_info_sorted(*graph);
    }
    */

    // Free Model
    if(model != RT_NULL)
    {
        onnx__model_proto__free_unpacked(model, NULL);
    }
}
MSH_CMD_EXPORT(onnx_parser_example, decode onnx model from file);
