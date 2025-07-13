import sys
import os

# # 老版本，可移植性较差

# # 添加生成的模块路径
# sys.path.append(os.path.abspath(r"C:\\Users\\19513\\Desktop\\cmake\build\\PythonWrapper"))
# #print(sys.path)  # 打印 sys.path 内容，检查路径是否添加正确

# import bind_three_sum as solution_module

# # 创建 Solution 对象
# sol = solution_module.Solution_three_sum()

# # 测试 twoSum 方法
# nums = [-1,1,0,1, 2, 4, 10, 15, 7]
# result = sol.three_sum(nums)
# print(result)

def load_and_test_three_sum():
    # 构建模块路径（使用os.path.join避免硬编码路径分隔符）
    module_dir = os.path.abspath(
        os.path.join(
            os.path.dirname(os.path.abspath(__file__)),  # 当前脚本所在目录
            "..", "..", "build", "PythonWrapper"  # 相对于当前脚本的模块路径
        )
    )
    
    # 仅在路径不存在时添加，避免重复
    if module_dir not in sys.path:
        sys.path.append(module_dir)
    
    try:
        # 导入模块
        import bind_three_sum as bs
    except ImportError as e:
        print(f"模块导入失败: {e}")
        print(f"请检查模块路径: {module_dir}")
        return
    
    try:
        # 创建实例并调用方法
        sol = bs.Solution_three_sum()
        
        # 测试用例
        test_cases = [
            [-1, 1, 0, 1, 2, 4, 10, 15, 7],
            [-1, -1, 2, 0],
            [0, 0, 0, 0]
        ]
        
        # 执行测试
        for nums in test_cases:
            print(f"\n测试数组: {nums}")
            
            # 调用C++方法
            result = sol.three_sum(nums)
            
            # 验证结果格式
            if not isinstance(result, list):
                print(f"错误: 返回类型不是列表 - {type(result)}")
                continue
                
            # 打印结果
            print(f"找到 {len(result)} 个三元组:")
            for triplet in result:
                if len(triplet) == 3 and sum(triplet) == 0:
                    print(f"  ✅ {triplet} (和为0)")
                else:
                    print(f"  ❌ 无效三元组: {triplet}")
                    
    except Exception as e:
        print(f"执行过程中出错: {e}")

if __name__ == "__main__":
    load_and_test_three_sum()