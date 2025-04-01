import sys
import os

# 添加生成的模块路径
sys.path.append(os.path.abspath(r"C:\\Users\\19513\\Desktop\\cmake\build\\PythonWrapper"))
print(sys.path)  # 打印 sys.path 内容，检查路径是否添加正确

try:
	import add
except ModuleNotFoundError:
	print("The 'lesson' module could not be found. Ensure it is built and located in the specified path.")
	sys.exit(1)

a = 0
a = add.add(3, 2)
print(a)


