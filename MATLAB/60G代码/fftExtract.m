function sig = fftExtract(data)
%从60G雷达当中提取1维FFT数据
data = reshape(data', 1, []);
%确定帧头帧尾
head_position = strfind(data, '66BB');
tail_position = strfind(data, 'BB66');

 %记录有效数据块数量。
fftnum=0;
%初始化fft之后数据
%sig=false[];

%每个有效数据块的长度为 2404
head_test=head_position+2404;

%判断是否为有效帧
tf = ismember(head_test, tail_position);


for i=1:length(head_position)
  if(tf(i)==1)
      fftnum=fftnum+1;
      %提取该有效数据块中从第 5 个元素到第 2404 个元素的数据，并存储在 fftsig 矩阵的第 fftnum 行
      fftsig(fftnum,:)=(data(head_position(i)+4:head_position(i)+2403));%2403，2410
  end
end


real_sig=fftsig(:,1:1200);
imag_sig=fftsig(:,1201:2400);

%小端开头
for j = 1:fftnum
    for i=1:150
        
    result1(j,i,1)=real_sig(j,7+(i-1)*8);
    result2(j,i,1)=imag_sig(j,7+(i-1)*8);
    
    result1(j,i,2)=real_sig(j,8+(i-1)*8);
    result2(j,i,2)=imag_sig(j,8+(i-1)*8);

    result1(j,i,3)=real_sig(j,5+(i-1)*8);
    result2(j,i,3)=imag_sig(j,5+(i-1)*8);

    result1(j,i,4)=real_sig(j,6+(i-1)*8);
    result2(j,i,4)=imag_sig(j,6+(i-1)*8);

    result1(j,i,5)=real_sig(j,3+(i-1)*8);
    result2(j,i,5)=imag_sig(j,3+(i-1)*8);

    result1(j,i,6)=real_sig(j,4+(i-1)*8);
    result2(j,i,6)=imag_sig(j,4+(i-1)*8);

    result1(j,i,7)=real_sig(j,1+(i-1)*8);
    result2(j,i,7)=imag_sig(j,1+(i-1)*8);

    result1(j,i,8)=real_sig(j,2+(i-1)*8);
    result2(j,i,8)=imag_sig(j,2+(i-1)*8);
    
    end
end
%三维矩阵，帧数*150*4（四个字节）
  %把三维矩阵 result1 的第 2 维和第 3 维进行交换。
  result1 = string( permute(result1, [1, 3, 2]));
  result2 =string( permute(result2, [1, 3, 2]));

  %十六进制转十进制,方便bit_positions直接按照2的几次方赋值
  result1=hex2dec(result1);
  result2=hex2dec(result2);

%十进制转二进制,得到一个三维矩阵，帧数*150*32二进制数
result_3d = zeros(fftnum, 150, 32);
bit_positions = uint32(2.^(31:-1:0));

for i = 1:fftnum
    for j = 1:150
        % 使用位运算提取每一位
        result_3d(i, j, :) = bitand(uint32(result1(i, j)), bit_positions) ~= 0;
    end
end
result1=result_3d;

for i = 1:fftnum
    for j = 1:150
        % 使用位运算提取每一位
        result_3d(i, j, :) = bitand(uint32(result2(i, j)), bit_positions) ~= 0;
    end
end
result2=result_3d;

%%计算实部的值
%提取符号位、指数位和尾数位
signal = result1(:,:,1);         %从 result1 矩阵中提取第 1 个维度的数据作为符号位。
exponent = result1(:,:,2:9);     %从 result1 矩阵中提取第 2 个到第 9 个维度的数据作为指数位。
fraction = result1(:,:,10:32);   %从 result1 矩阵中提取第 10 个到第 32 个维度的数据作为尾数位。


% 预分配结果数组
fftnum = size(result1, 1);
e1 = zeros(fftnum, 150);
f=ones(fftnum,150);
    for i=1:fftnum
       for j=1:150
           e_string= sprintf('%d', exponent(i,j,:));  %将指数位的二进制数据转换为字符串。
           e1(i,j)=bin2dec(e_string)-127;  %将二进制字符串转换为十进制数，并减去 127 得到实际的指数值。
    
           for m = 1:23
               if fraction(i,j,m) == 1
                   f(i,j) = f(i,j) + 2^(-m);  %初始为1，后面累加
               end
           end
       end
    end
real_sig= (-1).^signal .* f .* 2.^e1;  %根据符号位、尾数和指数计算实部数值。

%计算虚部的值
signal = result2(:,:,1);
exponent = result2(:,:,2:9);
fraction = result2(:,:,10:end);
% 预分配结果数组
fftnum = size(result1, 1);
e2 = zeros(fftnum, 150);
f=ones(fftnum,150);
    for i=1:fftnum
        for j=1:150
            e_string= sprintf('%d', exponent(i,j,:));
            e2(i,j)=bin2dec(e_string)-127;

            for m = 1:23
                if fraction(i,j,m) == 1
                f(i,j) = f(i,j) + 2^(-m);  
                end
            end
        end
    end
imag_sig= (-1).^signal .* f .* 2.^e2;

sig=real_sig+1i.*imag_sig;
end
