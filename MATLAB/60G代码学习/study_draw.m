% 示例数据
data = 'ABCDEFGHIJ';
start_index = 1;
i = 1;

% 初始化元胞数组 len
len = cell(1, 1);

% 执行提取和存储操作
len{i} = ([data(start_index+2:start_index+3), data(start_index:start_index+1)]);

% 输出结果
disp('原始数据:');
disp(data);
disp('提取并组合后的结果:');
disp(len{i});