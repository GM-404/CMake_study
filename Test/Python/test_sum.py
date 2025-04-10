import sys
import os
# 添加生成的模块路径
sys.path.append(os.path.abspath(r"C:\\Users\\19513\\Desktop\\cmake\build\\PythonWrapper"))
#print(sys.path)  # 打印 sys.path 内容，检查路径是否添加正确

import bind_sum as solution_module

# 创建 Solution 对象
sol = solution_module.Solution()

# 测试 twoSum 方法
nums = [1, 2, 4, 10, 15, 7]
target = 11
result = sol.twoSum(nums, target)
print(result)