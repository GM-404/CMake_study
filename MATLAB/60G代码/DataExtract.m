function [point,frame_max] = DataExtract(data)
%从雷达数据当中提取出其中的点云部分
%60G雷达的点云：极坐标（距离，方位角，俯仰角），速度，功率的绝对值（反射强度）
data = reshape(data', 1, []);
head_position = strfind(data, '55AA');
len=[];
time=[];
numTLV=[];
type=[];
targetNum=[];
pointNum=0;%总的点数
test=[];
frame=[];
%%
%提取长度信息
for i = 1:length(head_position)
    start_index = head_position(i) + 4;  % 从第四个字符开始
    end_index = head_position(i) + 11;          % 到后续第11个字符
  %  test{i}=data(head_position(i):head_position(i)+80);
    % 确保索引不会超出data的长度
    if end_index <= length(data)
        len{i} = ([data(start_index+2:start_index+3), data(start_index:start_index+1)]);  % 将字符存入len
    end
end
%%
%提取时间信息
for i = 1:length(head_position)
    start_index = head_position(i) + 12;  % 从第12个字符开始
    end_index = head_position(i) + 15;          % 到第15个字符
    % 确保索引不会超出data的长度
    if end_index <= length(data)
        time{i} = [ data(start_index:end_index)];  % 将字符存入time
    end
end
%%
%numTLV：01：点云上传
for i = 1:length(head_position)
    start_index = head_position(i) + 16;  % 从第16个字符开始
    end_index = head_position(i) + 17;          % 到第17个字符
    
    % 确保索引不会超出data的长度
    if end_index <= length(data)
        numTLV{i} = [ data(start_index:end_index)];  % 将字符存入numTLV
    end
end
%%
%type：01代表点云协议：idx1到idx4+powABS
for i = 1:length(head_position)
    start_index = head_position(i) + 18;  % 从第18个字符开始
    end_index = head_position(i) + 19;          % 到第19个字符
    
    % 确保索引不会超出data的长度
    if end_index <= length(data)
        type{i} = [ data(start_index:end_index)];  % 将字符存入type
    end
end
%%
%获取点的数量信息targetNum
for i = 1:length(head_position)
    start_index = head_position(i) + 20;  % 从第20个字符开始
    end_index = head_position(i) + 23;          % 到第23个字符
    
    % 确保索引不会超出data的长度
    if end_index <= length(data)
        r{i}=  data(start_index:end_index);  
        target1 =  data(start_index:start_index+1);  
        target2 =  data(start_index+2:start_index+3);
      
        tar1=double(hex2dec(target1));
        tar2=double(hex2dec(target2));
 
       targetNum{i} =tar1+256*tar2;
    end
end
result = zeros(size(targetNum));
for i = 1:length(targetNum)
    result(i) = double(targetNum{i});
end
targetNum=result;
disp('帧数');
disp(length(targetNum));
frame_max=length(targetNum);
%%
%提取出每个目标点的idx1到idx4+powABS信息
for i = 1:length(head_position)
    for j=1:targetNum(i)
        if ~isempty(j)
    start_index = head_position(i) + 24+(j-1)*18;  
    end_index = head_position(i) + 27+(j-1)*18;  %两个字节      
    pointNum=pointNum+1;
    % 确保索引不会超出data的长度
    if end_index <= length(data)
        idx1{pointNum} =  [ data(start_index:start_index+1)]; 
      
    end
 frame(pointNum)=i;
     start_index = head_position(i) + 28+(j-1)*18;  
    end_index = head_position(i) + 29+(j-1)*18;         
   
    % 确保索引不会超出data的长度
    if end_index <= length(data)
        idx2{pointNum} =  [ data(start_index:end_index)]; 
       
    end

 start_index = head_position(i) + 30+(j-1)*18;  
    end_index = head_position(i) + 31+(j-1)*18;         
    
    % 确保索引不会超出data的长度
    if end_index <= length(data)
        idx3{pointNum} =   data(start_index:end_index); 
       
    end

     start_index = head_position(i) + 32+(j-1)*18;  
    end_index = head_position(i) + 33+(j-1)*18;         
    
    % 确保索引不会超出data的长度
    if end_index <= length(data)
        idx4{pointNum} =  data(start_index:end_index);    
    end
     start_index = head_position(i) + 34+(j-1)*18;  
    end_index = head_position(i) + 41+(j-1)*18;         
    % 确保索引不会超出data的长度
    if end_index <= length(data)
        powABS{pointNum} =[data(end_index:end_index-1),data(end_index-3:end_index-2),data(end_index-5:end_index-4),data(end_index-7:end_index-6)]; 
       
    end
        end
    end
end
%%
%转十进制
idx1 = cellfun(@hex2dec, idx1);
idx2 = cellfun(@hex2dec, idx2);
idx3 = cellfun(@hex2dec, idx3);
idx4 = cellfun(@hex2dec, idx4);
powABS = cellfun(@hex2dec, powABS);
%%
%提取距离信息
%range=idx1*0.05004;%带宽参数设为0
range=idx1*0.025;%带宽参数设为1
%%
%提取速度信息
for i=1:length(idx2)
    velocity(i)=idx2(i);
    if(velocity(i)>=32)
velocity(i)=-(velocity(i)-32)*0.104167;
    else 
        velocity(i)=(velocity(i)-32)*0.104167;
    end
end
%%
%提取出方位角信息
for i=1:length(idx3)
    azi(i)=idx3(i);
    if(idx3(i)>=64)
azi(i)=asin((idx3(i)-128)/64)*180/pi;
    else 
 azi(i)=asin(idx3(i)/64)*180/pi;
    end
end
%%
%提取出俯仰角信息
for i=1:length(idx4)
    ele(i)=idx4(i);
    if(ele(i)>=64)
ele(i)=asin((idx4(i)-128)/64)*180/pi;
    else 
 ele(i)=asin(idx4(i)/64)*180/pi;
    end
end
%%
range=transpose(range);
velocity=transpose(velocity);
ele=ele';
azi=azi';
powABS=powABS';
%%
%极坐标转换为直角坐标
% 计算直角坐标 (x, y, z)
frame=frame';
%方位角+-60，俯仰角=-45，超过的点不保真

x = range .* cosd(ele) .* cosd(azi); % x 坐标
y = range .* cosd(ele) .* sind(azi); % y 坐标
z = range .* sind(ele);            % z 坐标
point = [x y z velocity  powABS range azi ele frame];
return;