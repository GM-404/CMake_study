% 创建一个示例的三维矩阵 result1
result1 = zeros(2, 3, 4);
for i = 1:2
    for j = 1:3
        for k = 1:4
            result1(i, j, k) = (i - 1) * 12 + (j - 1) * 4 + k;
        end
    end
end

% 显示原始矩阵
disp('原始矩阵 result1:');
disp(result1);

% 使用 permute 函数交换第 2 维和第 3 维
result1_permuted = permute(result1, [1, 3, 2]);

% 显示维度重排后的矩阵
disp('维度重排后的矩阵 result1_permuted:');
disp(result1_permuted);