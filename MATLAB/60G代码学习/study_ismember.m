% 生成示例数据
data = '66BB 1234567890 BB66     66BB ABCDABCD BB66       66BB 0987654321 BB66';

data = strrep(data, ' ', ''); % 去除空格
% 检查字符串长度是否为奇数，如果是则在前面补零
if mod(length(data), 2) ~= 0
    data = ['0' data];
end


% 确定帧头帧尾
head_position = strfind(data, '66BB');
tail_position = strfind(data, 'BB66');

% 记录有效数据块数量。
fftnum = 0;

% 每个有效数据块的长度为 10
head_test = head_position + 14;
tf = ismember(head_test, tail_position); % 判断每个帧头后移14个单位后的位置是否在帧尾位置中


% 预分配 fftsig 矩阵，最大可能的行数为 length(head_position)
fftsig = zeros(length(head_position), 10); % 这里假设每个数据块长度为 10

% 遍历每个帧头位置
for i = 1:length(head_position)
    if(tf(i) == 1)
        fftnum = fftnum + 1;
        % 提取该有效数据块中从第 5 个元素到第 14 个元素的数据，并存储在 fftsig 矩阵的第 fftnum 行。
        fftsig(fftnum, :) = data(head_position(i)+4 : head_position(i)+13);
    end
end
% 裁剪掉未使用的行
fftsig = fftsig(1:fftnum, :);

% 输出结果
disp('帧头位置:');
disp(head_position);
disp('帧尾位置:');
disp(tail_position);
disp('帧头后移2404个单位后的位置:');
disp(head_test);
disp('判断结果:');
disp(tf);
disp('有效数据块数量:');
disp(fftnum);
disp('提取的有效数据块:');
disp(fftsig);