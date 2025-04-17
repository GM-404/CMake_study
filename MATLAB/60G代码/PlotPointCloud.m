function [] = PlotPointCloud(point)
    point_display = [];
    frame_up = 300;  %上限
    frame_down = 00;  %下限
    %可以结合距离图判断哪些帧的点可能会更多：运动明显更多
    Index = point(:, 9) <= frame_up;
    point_display = point(Index, :);
    Index = point_display(:, 9) >= frame_down;
    point_display = point(Index, :);
    %仅仅保留部分点，根据上限和下限调节，这样方便直接查看点相对多的帧
    frame = point_display(:, 9);
    frame_add=5;
    %%根据frame_add调节展示的点云当中每一帧点云实际包括了雷达点云多少帧的点
    frame_section=frame_up-frame_down;
    %%要展示的点云总帧数
    section=[];
    num_intervals = ceil(frame_section / frame_add);  % 计算总的区间数
    for i = 1:num_intervals
        section(frame > (i-1)*frame_add+frame_down & frame <= i*frame_add+frame_down) = i;  % 每一个区间的划分
    end
    
    % 获取坐标
    x = point_display(:, 1);
    y = point_display(:, 2);
    z = point_display(:, 3);

    fig = figure();
    pause_time = 0.1;  % 暂停时间，展示的点云每一帧停留多久，这里暂停pause_time秒
    % 无限循环展示各个区间的点云
    while true
        for i = 1:num_intervals
            % 获取当前区间对应的点
            current_section_points = point_display(section == i, :);
            % 获取当前颜色区间的 X, Y, Z 坐标
            x = current_section_points(:, 1);
            y = current_section_points(:, 2);
            z = current_section_points(:, 3);
            clf(fig);  % 清除当前展示的点云图

            % 绘制当前颜色区间的点云
            scatter3(x, y, z, 50, 'filled');
            title(['实际帧数为 ' num2str((i-1)*frame_add+1+frame_down) ' 到 ' num2str(i*frame_add+frame_down) ' 的点云']);
            xlabel('X');
            ylabel('Y');
            zlabel('Z');
            
            % 显示网格
            grid on;
            
            % 调整视角
            view(-80, 10); 
            xlim([-0 5]);
            ylim([-5 5]);
            zlim([-4 4]);

          
            pause(pause_time);    % 暂停一段时间展示该区间的点云
        end
    end
end

 