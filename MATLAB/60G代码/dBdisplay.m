function out = dBdisplay(FFT)
   %%%该函数是将输入数据进行归一化和转换成分贝形式
FFT = FFT/max(abs(FFT),[],'all');
   %%%对输入的数据进行归一化，使得其取值范围在0和1之间
out = 20*log10(abs(FFT));
   %%%对归一化之后的数据转化成分贝形式
end

