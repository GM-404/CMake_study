import sys
import os

# 添加生成的模块路径
sys.path.append(os.path.abspath("C:\\Users\\19513\\Desktop\\cmake\\build\\PythonWrapper"))
import lesson

a = 0
a = lesson.add(3, 2)
print(a)
