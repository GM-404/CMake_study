import sys
import os


# 简略版本
# # 添加生成的模块路径
# sys.path.append(os.path.abspath(r"C:\\Users\\19513\\Desktop\\cmake\build\\PythonWrapper"))
# #print(sys.path)  # 打印 sys.path 内容，检查路径是否添加正确

# import bind_four_sum as solution_module

# # 创建 Solution 对象
# sol = solution_module.Solution_four_Sum()

# # 测试 fourSum 方法
# nums = [1, 0, -1, 0, -2, 2]
# target = 0
# result = sol.four_Sum(nums, target)
# print(result)  

# 优化版本
from typing import List

def test_four_sum():
    # 模块路径设置（保持之前的优化）
    module_dir = os.path.abspath(
        os.path.join(
            os.path.dirname(os.path.abspath(__file__)),
            "..", "..", "build", "PythonWrapper"
        )
    )
    if module_dir not in sys.path:
        sys.path.append(module_dir)
    
    try:
        import bind_four_sum as bfs
    except ImportError as e:
        print(f"模块导入失败: {e}", file=sys.stderr)
        return
    
    try:
        # 创建实例
        sol = bfs.Solution_four_Sum()
        
        # 测试数据
        nums: List[int] = [1, 0, -1, 0, -2, 2]
        target: int = 0
        
        # 调用方法
        result: List[List[int]] = sol.four_Sum(nums, target)
        
        # 优化打印格式：每个四元组单独一行
        print("四数之和为0的结果：")
        for i, quad in enumerate(result, 1):
            print(f"第{i}组: {quad}")  # 每组占一行，带序号更清晰
        
    except Exception as e:
        print(f"执行错误: {e}", file=sys.stderr)

if __name__ == "__main__":
    test_four_sum()