## onnx-parser

Open Neural Network Exchange model parser in C



Run:

```
./onnx-parser-example mnist.onnx
```

Output:

```
---- Model info ----
IR Version is 1073821696
Produceer name is keras2onnx
Produceer version is 1.5.1
Produceer version is onnx
---- Graph Info ----
---- Graph Input Info ----
Graph inputs number: 1
Input name conv2d_12_input
Input type FLOAT
Input dimension 4
N x 0 x 0 x 0
---- Graph Output Info ----
Graph outputs number: 1
Output name dense_14/Softmax:0
Output type FLOAT
Output dimension 2
? x 0
---- Graph Node Info ----
Graph nodes number: 15
Transpose   : conv2d_12_input                ->    adjusted_input1                [Transpose6]
Conv        : adjusted_input1                ->    convolution_output1            [conv2d_12]
Relu        : convolution_output1            ->    conv2d_12/Relu:0               [Relu1]
MaxPool     : conv2d_12/Relu:0               ->    pooling_output1                [max_pooling2d_12]
Conv        : pooling_output1                ->    convolution_output             [conv2d_13]
Relu        : convolution_output             ->    conv2d_13/Relu:0               [Relu]
MaxPool     : conv2d_13/Relu:0               ->    pooling_output                 [max_pooling2d_13]
Transpose   : pooling_output                 ->    max_pooling2d_13/MaxPool:0     [Transpose1]
Reshape     : max_pooling2d_13/MaxPool:0     ->    flatten_7/Reshape:0            [flatten_7]
MatMul      : flatten_7/Reshape:0            ->    transformed_tensor1            [dense_13]
Add         : transformed_tensor1            ->    biased_tensor_name1            [Add1]
MatMul      : biased_tensor_name1            ->    transformed_tensor             [dense_14]
Add         : transformed_tensor             ->    biased_tensor_name             [Add]
Softmax     : biased_tensor_name             ->    dense_14/Softmax:01            [Softmax]
Identity    : dense_14/Softmax:01            ->    dense_14/Softmax:0             [Identity1]

```
