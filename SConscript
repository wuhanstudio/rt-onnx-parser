from building import *
import rtconfig

# get current directory
cwd     = GetCurrentDir()
# The set of source files associated with this SConscript file.
src     = Glob('src/*.c')

if GetDepend('ONNX_PARSER_USING_EXAMPLE'):
	src    += Glob('examples/onnx_parser_example.c')

if GetDepend('ONNX_PARSER_USING_RAM_EXAMPLE'):
	src    += Glob('examples/mnist_onnx.c')
	src    += Glob('examples/onnx_parser_ram_example.c')

path   =  [cwd + '/src']
path   += [cwd + '/examples']

LOCAL_CCFLAGS = ''

group = DefineGroup('onnx-parser', src, depend = ['PKG_USING_ONNX_PARSER'], CPPPATH = path, LOCAL_CCFLAGS = LOCAL_CCFLAGS)

Return('group')
