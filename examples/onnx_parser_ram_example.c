#include <rtthread.h>
#include "onnx-parser.h"

extern unsigned char mnist_onnx[];
extern unsigned int mnist_onnx_len;

#define THREAD_PRIORITY         8
#define THREAD_STACK_SIZE       1024
#define THREAD_TIMESLICE        5

static rt_thread_t tid1 = RT_NULL;

static void onnx_parser_entry(void* parameters)
{
    // Load Model
    Onnx__ModelProto* model = onnx__model_proto__unpack(NULL, mnist_onnx_len, mnist_onnx);

    // Print Model Info
    if( model != NULL)
    {
        rt_kprintf("Loaded model\n");
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

static void onnx_parser_ram_example(int argc, char *argv[])
{

    tid1 = rt_thread_create("tonnx_ram",
                    onnx_parser_entry, RT_NULL,
                    THREAD_STACK_SIZE,
                    THREAD_PRIORITY, THREAD_TIMESLICE);

    if (tid1 != RT_NULL)
    {
        rt_thread_startup(tid1);
    }
    else
    {
        rt_kprintf("Start failed\n");
    }
}
MSH_CMD_EXPORT(onnx_parser_ram_example, decode onnx model from file);
