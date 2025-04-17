function sig_clear = MTImean(sig)
%根据需要改，1：MEAN，0：MTI
mean_or_mti_flag =10;

sig=abs(sig);
sig_clear=sig;
[row,col ]=size(sig);
if mean_or_mti_flag == 1
%MEAN：减去同一距离上的均值，以滤除静态噪声
    sig_clear = sig - mean(sig,1);
elseif mean_or_mti_flag == 0
% MTI：动目标检测
    data_range_filtout = zeros( row,col);
    for i=1:row-1 
        data_range_filtout(i,:) = sig(i+1,:) - sig(i,: );
    end   
    sig_clear = data_range_filtout(:, :);
else
end
end


