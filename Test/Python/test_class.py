#调用类的方法
import sys
import os

# 添加生成的模块路径
sys.path.append(os.path.abspath(r"C:\\Users\\19513\\Desktop\\cmake\\build\\PythonWrapper"))
print(sys.path)  # 打印 sys.path 内容，检查路径是否添加正确
try:
	import bind_class as bc
except ModuleNotFoundError:
	raise ModuleNotFoundError("The 'bind_class' module could not be found. Ensure it exists in the specified directory.")

# 创建 ExampleClass 的实例
obj = bc.ExampleClass(42)

# 调用 getData 方法
print(obj.getData())

# 调用 setData 方法
obj.setData(100)

# 再次调用 getData 方法
print(obj.getData())
