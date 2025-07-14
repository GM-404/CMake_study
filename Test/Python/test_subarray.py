import unittest
import sys
import os

# 设置模块路径（根据实际情况调整）
module_path = os.path.abspath(
    os.path.join(
        os.path.dirname(os.path.abspath(__file__)),
        "..", "..", "build", "PythonWrapper"
    )
)
sys.path.append(module_path)

try:
    import bind_subarray  # 导入C++绑定模块
except ImportError:
    print(f"无法导入模块，请检查路径: {module_path}")
    sys.exit(1)

class TestSolutionSubarray(unittest.TestCase):
    def setUp(self):
        self.sol = bind_subarray.Solution_subarray()
    
    def test_empty_array(self):
        """测试空数组"""
        nums = []
        target = 5
        self.assertEqual(self.sol.maxSubArray(nums, target), 0)
    
    def test_single_element(self):
        """测试单元素数组"""
        nums = [5]
        target = 5
        self.assertEqual(self.sol.maxSubArray(nums, target), 1)
        
        target = 3
        self.assertEqual(self.sol.maxSubArray(nums, target), 0)
    
    def test_basic_case(self):
        """测试基本场景"""
        nums = [1, 2, 3]
        target = 3
        self.assertEqual(self.sol.maxSubArray(nums, target), 2)  # [1,2], [3]
    
    def test_with_negatives(self):
        """测试包含负数的数组"""
        nums = [1, -1, 2, -2]
        target = 0
        self.assertEqual(self.sol.maxSubArray(nums, target), 3)  # [1,-1], [1,-1,2,-2], [2,-2]
    
    def test_multiple_non_contiguous(self):
        """测试多个不连续子数组"""
        nums = [0, 0, 0]
        target = 0
        self.assertEqual(self.sol.maxSubArray(nums, target), 6)  # [0], [0], [0], [0,0], [0,0], [0,0,0]
    
    def test_no_match(self):
        """测试无匹配子数组"""
        nums = [1, 2, 3]
        target = 10
        self.assertEqual(self.sol.maxSubArray(nums, target), 0)
    
    def test_multiple_tails(self):
        """测试需要断尾多次的场景"""
        nums = [3, 4, 7, 2, -3, 1, 4, 2]
        target = 7
        self.assertEqual(self.sol.maxSubArray(nums, target), 4)  # [7], [3,4], [7,2,-3,1], [1,4,2]
    
    def test_negative_target(self):
        """测试负数目标"""
        nums = [2, -3, 1]
        target = -1
        self.assertEqual(self.sol.maxSubArray(nums, target), 1)  # [2,-3], 
    
    def test_single_element_multiple_times(self):
        """测试单元素多次出现"""
        nums = [1, 1, 1, 1]
        target = 2
        self.assertEqual(self.sol.maxSubArray(nums, target), 3)  # [1,1], [1,1], [1,1]
    
    def test_complex_with_zero(self):
        """测试包含零的复杂场景"""
        nums = [0, 1, 0, -1, 0]
        target = 0
        self.assertEqual(self.sol.maxSubArray(nums, target), 7)  # [0], [0], [0], [0,1,0,-1], [1,0,-1], [0,-1,0], [-1,0]
# 在 Jupyter 中运行的关键：不使用 unittest.main()，而是手动加载并运行测试
if __name__ == "__main__":
    # 创建测试套件
    suite = unittest.TestLoader().loadTestsFromTestCase(TestSolutionSubarray)
    # 运行测试
    unittest.TextTestRunner().run(suite)