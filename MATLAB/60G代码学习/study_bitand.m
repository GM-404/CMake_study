% 定义 result1 矩阵
result1 = [10 20; 30 40];

% 定义 bit_positions 向量
bit_positions = uint32([1, 2, 4, 8, 16]);

% 初始化 result_3d 三维矩阵
result_3d = false(size(result1, 1), size(result1, 2), length(bit_positions));

% 遍历 result1 矩阵的每个元素
for i = 1:size(result1, 1)
    for j = 1:size(result1, 2)
        result_3d(i, j, :) = bitand(uint32(result1(i, j)), bit_positions) ~= 0;
    end
end

% 输出结果
disp('result1 矩阵:');
disp(result1);
disp('bit_positions 向量:');
disp(bit_positions);
disp('result_3d 三维矩阵:');
disp(result_3d);
% 这些结果展示了 result1 矩阵中每个元素与 bit_positions 进行按位与操作的结果。
% 例如，result1(1, 1) = 10 的二进制表示为 1010，与 bit_positions 进行按位与操作后，得到的逻辑数组为 [0 1 0 1 0]，存储在 result_3d(1, 1, :) 中。