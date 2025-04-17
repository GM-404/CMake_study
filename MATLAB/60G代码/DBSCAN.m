function [point_dbscan] = DBSCAN(point,frame_max)
%问题？目前不是针对逐帧进行DBSCAN，而是全部帧的点一起DBSCAN
%针对每一帧（实际）的点进行DBSCAN处理
    eps = 0.165; % 聚类半径   EPS
    minpoints = 4; % 最小数据量 minPoints
    %聚类半径范围内少于最小数据量，认为是噪声点
    ini_point=point;
    point_4d = ini_point;
  point_dbscan=[];
  frame_add=5;%做5帧的积累
    for j=1:frame_max
    
    Index = point_4d(:, 9) <= frame_add*j;
    point = point_4d(Index, :);
    Index = point(:, 9) >= frame_add*(j-1)+1;
    point = point(Index, :);
    % 数据是否已经被聚类
    point_type    = zeros(size(point, 1), 1);% 每个点的聚类类型，0 表示未分类
    cluster_points  = [];   %每个聚类点数，其实是个中间量
    cluster_index   = 1;    %初始的聚类编号，该值的最终值代表着聚类总数
    for i = 1:size(point, 1)
        %依次对每个点单独进行处理
        if point_type(i) == 0 % 该点未被分类
            point_type(i)    = cluster_index;     % 将点标记为当前聚类
            num          = 1;   % 当前聚类的点数初始化为1
            cluster_index       = cluster_index + 1; % 类别标号增加:便于建立下一个聚类
        else
            num           = cluster_points(point_type(i)); % 否则，提取已有聚类的点数
        end
        for iii = 1:size(point, 1) 
            %逐帧处理各个点
            % 被聚过类了 或者是 就是它自己
            if i == iii, continue, end  % 跳过自身
            if point_type(iii), continue, end % 跳过已分类的点
            if norm(point(iii, 1:3) - point(i, 1:3)) < eps  % 如果点在 eps 范围内
                point_type(iii)    = point_type(i);  % 归类到当前点所处的类别
                num            = num  + 1;     % 当前聚类点数加1
            end
        end
        cluster_points(point_type(i)) = num;    % 更新当前聚类的点数 
        
    end
   %上面完成对所有点进行聚类
   %下面剔除掉噪声点
    index              = find(cluster_points < minpoints);
    %将聚类总点数不达要求的种类索引存入index
    array  = [];
    for i = 1:length(index)
        array = [array find(point_type == index(i))'];
        %%%得到噪声点在point的索引，存入array
    end
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % 对数据进行擦除
    point(array,:)        = [];
    %从point把噪声点去除
    point_type(array,:)   = [];
    %不满足要求的聚类种类被去除
    cluster_points(index)   = [];
    %不满足要求的聚类内的点数信息被去除
    % 重新对数据进行编号 
    re_index = 1;
    for i = 1:length(cluster_points) - 1
        %遍历所有聚类种类
        index = find(point_type == i);
        if ~isempty(index)
            %如果该聚类没有被删去
            point_type(index) = re_index;
            %该聚类的所有点重新赋予一个聚类种类编号
            re_index = re_index + 1;
            %聚类种类编号递增
        end
    end
  
    re_index = re_index - 1;
    %新的聚类总数
    %data_cluster = [point point_type]; % 被聚类的数据
    %在点云数据的基础上附带其聚类种类信息

point_dbscan=[point_dbscan;point];
    end
  
end

