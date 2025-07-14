#include <iostream>
#include <vector>
#include <string>
#include <functional> // std::function
#include <algorithm>  // std::sort

/*这三句代码的核心作用是消除组间顺序对结果比较的影响，确保两个 “字符串分组集合” 在逻辑上相等时能被判定为相等*/
int main()
{
    // 1. 定义一个二维向量（多个字符串组）
    std::vector<std::vector<std::string>> groups = {
        {"tan", "nat"},        // 组1
        {"eat", "tea", "ate"}, // 组2
        {"bat"}                // 组3
    };

    // 2. 定义比较函数（不使用auto，显式声明类型）
    std::function<bool(const std::vector<std::string> &, const std::vector<std::string> &)> compareGroups =
        [](const std::vector<std::string> &a, const std::vector<std::string> &b)
    {
        return a < b; // 利用vector的默认字典序比较
    };

    // 3. 对二维向量中的所有组进行排序
    std::sort(groups.begin(), groups.end(), compareGroups);

    // 4. 打印排序后的结果
    std::cout << "排序后的组（按字典序）：" << std::endl;
    for (const std::vector<std::string> &group : groups)
    {
        for (const std::string &str : group)
        {
            std::cout << str << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}