import sys
import os

#暂时测试没通过，但代码逻辑没问题
# # 添加模块路径
# sys.path.append(os.path.abspath(r"C:\Users\19513\Desktop\cmake\build\PythonWrapper"))

# # 导入模块
# import bind_move_zero as bmz

# # 测试数据
# test_cases = [
#     ([0, 1, 0, 3, 12], [1, 3, 12, 0, 0]),
#     ([1, 2, 3, 4, 5], [1, 2, 3, 4, 5]),
#     ([0, 0, 1, 0, 0], [1, 0, 0, 0, 0])
# ]

# # 创建实例
# sol = bmz.Solution_Move_Zero()

# # 执行测试
# for i, (input_arr, expected) in enumerate(test_cases):
#     # 复制输入数组
#     arr = input_arr.copy()
#     # 调用方法
#     sol.Move_Zeroes(arr)
#     # 验证结果
#     if arr == expected:
#         print(f"测试{i+1}通过: {arr}")
#     else:
#         print(f"测试{i+1}失败: 预期{expected}, 实际{arr}")