import sys
import os

#老版本
# # 添加生成的模块路径
# sys.path.append(os.path.abspath(r"C:\\Users\\19513\\Desktop\\cmake\build\\PythonWrapper"))
# #print(sys.path)  # 打印 sys.path 内容，检查路径是否添加正确


# import bind_letter


# # 创建 letter_combination 类的实例
# lc = bind_letter.letter_combination()

# # 准备测试数据
# strs = ["eat", "tea", "tan", "ate", "nat", "bat"]

# # 调用 groupAnagrams 方法
# result = lc.groupAnagrams(strs)
# print(result)

# # 调用 groupAnagrams1 方法
# result1 = lc.groupAnagrams1(strs)
# print(result1)

## 新版本
import traceback
from typing import List, Any

def setup_module_path() -> bool:
    """设置模块路径并验证是否有效"""
    try:
        # 构建模块路径（跨平台兼容）
        current_dir = os.path.dirname(os.path.abspath(__file__))
        module_path = os.path.abspath(os.path.join(
            current_dir, "..", "..", "build", "PythonWrapper"
        ))
        
        # 仅添加不存在的路径
        if module_path not in sys.path:
            sys.path.append(module_path)
        
        # 验证路径存在
        if not os.path.isdir(module_path):
            print(f"错误：模块路径不存在 - {module_path}", file=sys.stderr)
            return False
        return True
    except Exception as e:
        print(f"路径设置失败：{str(e)}", file=sys.stderr)
        return False

def import_module() -> Any:
    """导入绑定模块并返回，失败则返回None"""
    try:
        import bind_letter
        return bind_letter
    except ImportError:
        print("错误：无法导入 bind_letter 模块，请检查编译是否成功", file=sys.stderr)
        print("可能的原因：模块未编译或路径错误", file=sys.stderr)
        return None
    except Exception as e:
        print(f"模块导入异常：{str(e)}", file=sys.stderr)
        traceback.print_exc()
        return None

def test_case(
    lc: Any, 
    test_name: str, 
    input_strs: List[str], 
    method_name: str = "groupAnagrams"
) -> None:
    """执行单个测试用例并格式化输出结果"""
    print(f"\n=== 测试用例：{test_name} ===")
    print(f"输入: {input_strs}")
    
    try:
        # 调用指定方法
        method = getattr(lc, method_name, None)
        if not method:
            print(f"错误：未找到方法 {method_name}", file=sys.stderr)
            return
        
        result = method(input_strs)
        
        # 格式化输出结果
        print(f"输出 ({method_name}):")
        if not result:
            print("  空结果")
        else:
            for i, group in enumerate(result, 1):
                print(f"  组 {i}: {group}")
                
    except Exception as e:
        print(f"执行失败：{str(e)}", file=sys.stderr)
        traceback.print_exc()

def main():
    # 1. 初始化模块路径
    if not setup_module_path():
        return
    
    # 2. 导入模块
    bind_module = import_module()
    if not bind_module:
        return
    
    # 3. 创建实例
    try:
        lc = bind_module.letter_combination()
    except Exception as e:
        print(f"创建实例失败：{str(e)}", file=sys.stderr)
        return
    
    # 4. 定义测试用例集（覆盖多种场景）
    test_cases = [
        {
            "name": "基本异位词分组",
            "input": ["eat", "tea", "tan", "ate", "nat", "bat"],
        },
        {
            "name": "空输入",
            "input": [],
        },
        {
            "name": "单个字符串",
            "input": ["hello"],
        },
        {
            "name": "全部相同字符串",
            "input": ["a", "a", "a", "a"],
        },
        {
            "name": "无异位词",
            "input": ["a", "b", "c", "d"],
        },
        {
            "name": "包含空字符串",
            "input": ["", "", "a", "b", ""],
        },
        {
            "name": "大小写敏感测试",
            "input": ["Eat", "tea", "TEA", "bat", "Bat"],
        },
        {
            "name": "长字符串组合",
            "input": ["listen", "silent", "enlist", "google", "goo"],
        }
    ]
    
    # 5. 执行两种方法的测试
    for case in test_cases:
        # 测试 groupAnagrams 方法
        test_case(lc, case["name"], case["input"], "groupAnagrams")
        # 测试 groupAnagrams1 方法
        test_case(lc, case["name"], case["input"], "groupAnagrams1")

if __name__ == "__main__":
    main()