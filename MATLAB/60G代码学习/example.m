
%文件路径
file_path='C:\Users\19513\Desktop\rada_data\example.DAT';%可用,双人
% 检查文件是否存在,存在返回二
if exist(file_path, 'file') ~= 2
    fprintf('文件不存在: %s\n', file_path);
    hex_data = [];
    return;
end
%打开文件
fid = fopen(file_path, 'rb');
if fid ~= -1
    %读取所有数据
    data = fread(fid, Inf, 'uint8'); % 读取为无符号8位整数
    fclose(fid);
    % 将字节数据转换为十六进制字符串
    %hex_data = dec2hex (data);
    fprintf('十六进制数据:\n');
    disp(data);
    fprintf('打印完毕\n');
else
    fprintf('无法打开文件: %s\n', file_path);
end

