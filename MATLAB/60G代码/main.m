clc;
clear;
close all;
%60G雷达
 data = data60G();
 sig=fftExtract(data);
 sig=MTImean(sig);%MEAN
 PlotRange(sig);
 [point,frame_max]= DataExtract(data);
 point=DBSCAN(point,frame_max);
 PlotPointCloud(point);
 