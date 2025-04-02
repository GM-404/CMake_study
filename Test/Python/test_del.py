import sys
import os
# 添加生成的模块路径
sys.path.append(os.path.abspath(r"C:\\Users\\19513\\Desktop\\cmake\build\\PythonWrapper"))
#print(sys.path)  # 打印 sys.path 内容，检查路径是否添加正确


import del_ctest

a = del_ctest.subdel(3, 2)
print(a)
