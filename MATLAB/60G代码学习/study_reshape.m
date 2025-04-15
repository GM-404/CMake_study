% 创建一个3x2的矩阵
data = [1 2;
    3 4;
    5 6];

% 打印原始矩阵
disp('原始矩阵 data:');
disp(data);

% 对矩阵进行转置并重塑为一行
% 可以使用reshape(data', 1, [])，其中[]表示自动计算列数
% reshape函数的第二个参数是行数，第三个参数是列数
% 默认是按照列优先的顺序进行重塑
reshaped_data = reshape(data', 1, []);

% 打印重塑后的矩阵
disp('重塑后的矩阵 reshaped_data:');
disp(reshaped_data);