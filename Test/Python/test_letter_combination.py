import sys
import os
# 添加生成的模块路径
sys.path.append(os.path.abspath(r"C:\\Users\\19513\\Desktop\\cmake\build\\PythonWrapper"))
#print(sys.path)  # 打印 sys.path 内容，检查路径是否添加正确


import bind_letter


# 创建 letter_combination 类的实例
lc = bind_letter.letter_combination()

# 准备测试数据
strs = ["eat", "tea", "tan", "ate", "nat", "bat"]

# 调用 groupAnagrams 方法
result = lc.groupAnagrams(strs)
print(result)

# 调用 groupAnagrams1 方法
result1 = lc.groupAnagrams1(strs)
print(result1)