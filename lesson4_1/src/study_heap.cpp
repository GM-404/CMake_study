#include <iostream>
#include <vector>
#include <algorithm>  // 堆操作的核心头文件
#include <functional> // 包含greater<>等比较器

using namespace std;

// 自定义结构体：用于演示复杂类型的堆操作
struct Student
{
    string name;
    int score;

    // 构造函数
    Student(string n, int s) : name(n), score(s) {}

    // 用于输出
    friend ostream &operator<<(ostream &os, const Student &s)
    {
        os << "[" << s.name << ": " << s.score << "]";
        return os;
    }
};

// 打印容器元素（辅助函数）
template <typename T>
void printContainer(const T &container, const string &msg)
{
    cout << msg << ": ";
    for (const auto &elem : container)
    {
        cout << elem << " ";
    }
    cout << endl;
}

int main()
{
    // ========================== 1. 基础类型（int）的堆操作 ==========================
    cout << "===== 基础类型(int)的堆操作 =====" << endl;

    // 原始数组（vector作为堆的底层容器）
    vector<int> nums = {3, 1, 4, 1, 5, 9, 2, 6};
    printContainer(nums, "原始数组");

    // 1.1 建堆（默认是大顶堆，即最大元素在堆顶）
    make_heap(nums.begin(), nums.end());
    printContainer(nums, "大顶堆(make_heap后)"); // 堆顶为9

    // 1.2 插入元素（push_heap：先在容器末尾添加元素，再调整堆结构）
    nums.push_back(7);                          // 先添加元素到末尾
    push_heap(nums.begin(), nums.end());        // 调整为新的大顶堆
    printContainer(nums, "插入7后(push_heap)"); // 堆顶仍为9

    // 1.3 删除堆顶元素（pop_heap：先将堆顶移到末尾，再调整剩余元素为堆）
    pop_heap(nums.begin(), nums.end());           // 堆顶9被移到末尾，剩余元素重建堆
    printContainer(nums, "删除堆顶后(pop_heap)"); // 新堆顶为7，末尾是9
    nums.pop_back();                              // 从容器中真正删除末尾的9
    printContainer(nums, "删除末尾元素后");

    // 1.4 堆排序（反复pop_heap即可得到升序结果）
    vector<int> heapSortNums = nums; // 复制当前堆
    for (auto it = heapSortNums.end(); it != heapSortNums.begin(); --it)
    {
        pop_heap(heapSortNums.begin(), it); // 每次将堆顶移到当前末尾
    }
    printContainer(heapSortNums, "堆排序结果（升序）");

    // ========================== 2. 小顶堆的实现（使用greater<>比较器） ==========================
    cout << "\n===== 小顶堆的实现 =====" << endl;

    vector<int> minHeapNums = {3, 1, 4, 1, 5};
    // 建小顶堆（用greater<>指定比较器，堆顶为最小元素）
    make_heap(minHeapNums.begin(), minHeapNums.end(), greater<int>());
    printContainer(minHeapNums, "小顶堆(make_heap后)"); // 堆顶为1

    // 插入元素到小顶堆
    minHeapNums.push_back(0);
    push_heap(minHeapNums.begin(), minHeapNums.end(), greater<int>());
    printContainer(minHeapNums, "插入0后(小顶堆)"); // 新堆顶为0

    // 删除小顶堆的堆顶
    pop_heap(minHeapNums.begin(), minHeapNums.end(), greater<int>());
    minHeapNums.pop_back();
    printContainer(minHeapNums, "删除堆顶后（小顶堆）"); // 新堆顶为1

    // ========================== 3. 自定义类型（Student）的堆操作 ==========================
    cout << "\n===== 自定义类型的堆操作 =====" << endl;

    // 自定义比较器（按分数降序，即大顶堆；若分数相同，按姓名升序）
    auto scoreGreater = [](const Student &a, const Student &b)
    {
        if (a.score != b.score)
        {
            return a.score < b.score; // 分数高的优先级高（大顶堆）
        }
        else
        {
            return a.name > b.name; // 分数相同时，姓名字典序小的优先级高
        }
    };

    // 初始化自定义类型的容器
    vector<Student> students = {
        Student("Alice", 85),
        Student("Bob", 92),
        Student("Charlie", 85),
        Student("David", 95)};
    printContainer(students, "原始学生列表");

    // 用自定义比较器建堆
    make_heap(students.begin(), students.end(), scoreGreater);
    printContainer(students, "按分数的大顶堆（make_heap后）"); // 堆顶是David（95分）

    // 插入新学生到堆中
    students.push_back(Student("Eve", 90));
    push_heap(students.begin(), students.end(), scoreGreater);
    printContainer(students, "插入Eve后（push_heap）"); // 堆顶仍为David（95分）

    // 删除堆顶元素（David）
    pop_heap(students.begin(), students.end(), scoreGreater);
    students.pop_back();
    printContainer(students, "删除堆顶后（学生堆）"); // 新堆顶是Bob（92分）

    // ========================== 4. 堆的核心函数总结 ==========================
    cout << "\n===== 堆操作核心函数总结 =====" << endl;
    cout << "1. make_heap(begin, end)：将容器转换为大顶堆" << endl;
    cout << "2. make_heap(begin, end, comp)：用自定义比较器建堆（如小顶堆）" << endl;
    cout << "3. push_heap(begin, end):插入元素后调整堆(需先push_back:" << endl;
    cout << "4. pop_heap(begin, end):删除堆顶(移到末尾,需再pop_back:" << endl;
    cout << "5. is_heap(begin, end):判断容器是否为堆结构(返回bool:" << endl;

    return 0;
}