#include <rtthread.h>
#include <string.h>
#include "onnx-parser.h"

#define THREAD_PRIORITY         8
#define THREAD_STACK_SIZE       5120
#define THREAD_TIMESLICE        5

static rt_thread_t tid1 = RT_NULL;
static char onnx_file_name[10];

static void onnx_parser_entry(void* parameter)
{
    // Load model
    Onnx__ModelProto* model = onnx_load_model(onnx_file_name);

    // Print Model Info
    if( model != NULL)
    {
        onnx_model_info(model);

        // Print Graph Info
        Onnx__GraphProto* graph = model->graph;
        if(graph != NULL)
        {
            onnx_graph_info_sorted(graph);
        }

        // Free Model
        onnx__model_proto__free_unpacked(model, NULL);
    }
    else
    {
        rt_kprintf("Decode model failed\n");
    }
}

static void onnx_parser_example(int argc, char *argv[])
{
    if (argc < 2) {
        rt_kprintf("Usage: %s onnx_file_name \n", argv[0]);
        rt_kprintf("Example: %s /mnist.onnx \n", argv[0]);
        return;
    }
    rt_kprintf("--- Reading from %s ---\n", argv[1]);
    strcpy (onnx_file_name, argv[1]);

    tid1 = rt_thread_create("tonnx",
                    onnx_parser_entry, RT_NULL,
                    THREAD_STACK_SIZE,
                    THREAD_PRIORITY, THREAD_TIMESLICE);

    if (tid1 != RT_NULL)
    {

        rt_thread_startup(tid1);
    }
    else
    {
        rt_kprintf("Failed to start onnx thread\n");
    }
}
MSH_CMD_EXPORT(onnx_parser_example, decode onnx model from file);
