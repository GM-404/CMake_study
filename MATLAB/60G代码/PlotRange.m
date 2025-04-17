function   PlotRange(sig)
%%距离-慢时间图
sig=abs(sig);
dist_vec=0:1:150;
dist_vec=dist_vec*0.05;
colormap('hot');
[row,~]=size(sig);
imagesc(1:row, dist_vec, dBdisplay(sig'),[-30, 0]);


xlabel('FrameIndex');
ylabel('Range(m)');  
title('Range—Time');
set(gca,'ydir','normal');
end

