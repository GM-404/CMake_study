import sys
import os

# 老版本，可移植性较差

# # 添加生成的模块路径
# sys.path.append(os.path.abspath(r"C:\\Users\\19513\\Desktop\\cmake\build\\PythonWrapper"))
# #print(sys.path)  # 打印 sys.path 内容，检查路径是否添加正确

# import bind_sum as solution_module

# # 创建 Solution 对象
# sol = solution_module.Solution()

# # 测试 twoSum 方法
# nums = [1, 2, 4, 10, 15, 7]
# target = 11
# result = sol.twoSum(nums, target)
# print(result)

#优化版本
def main():
    # 定义模块所在目录（使用相对路径思想，避免硬编码绝对路径）
    module_dir = os.path.join(
        os.path.dirname(os.path.abspath(__file__)),  # 当前脚本所在目录
        "..", "..", "build", "PythonWrapper"         # 相对当前目录的模块路径
    )
    # 转换为绝对路径并标准化（处理../等相对路径符号）
    module_dir = os.path.abspath(module_dir)
    
    # 检查路径是否存在，避免导入失败无提示
    if not os.path.isdir(module_dir):
        print(f"错误：模块目录不存在 - {module_dir}", file=sys.stderr)
        sys.exit(1)
    
    # 添加模块路径（仅在路径不在sys.path中时添加，避免重复）
    if module_dir not in sys.path:
        sys.path.append(module_dir)
    
    try:
        # 导入模块（使用别名更简洁）
        import bind_sum as bs
    except ImportError as e:
        print(f"错误：导入模块失败 - {e}", file=sys.stderr)
        sys.exit(1)
    
    try:
        # 创建实例并调用方法（添加类型提示注释，增强可读性）
        sol = bs.Solution()
        nums: list[int] = [1, 2, 4, 10, 15, 7]
        target: int = 11
        result: list[int] = sol.twoSum(nums, target)
        
        # 输出结果（添加上下文说明，避免纯数字输出）
        print(f"数组 {nums} 中，和为 {target} 的元素索引为：{result}")
        
    except Exception as e:
        # 捕获调用C++方法时可能出现的异常（如参数类型错误）
        print(f"调用twoSum失败：{e}", file=sys.stderr)
        sys.exit(1)

if __name__ == "__main__":
    main()