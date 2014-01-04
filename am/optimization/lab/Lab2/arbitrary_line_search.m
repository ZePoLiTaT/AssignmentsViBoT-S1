function [ zcur, minx, miny, iter ] = arbitrary_line_search( f3d, pini )
%STEEPEST_DESCENT Summary of this function goes here
%   Detailed explanation goes here

%Number of dimensions
N = 2;

% u = [u1, u2]
ubase = [0.45 1; -0.89 0];


plot(pini(1), pini(2),'or');
text(pini(1)+0.03, pini(2)+0.03, 'it 0');

p0 = pini;
err = inf;
zcur = inf;
pcur = p0;
iter = 0;

while(err > 1e-1)
  
    
    iter = iter + 1;
    z0 = zcur;
    
    for j=1:2
        
        % Update the direction 
        d = ubase(:,j);
        
        %Just to see the 2d cut in 3d space
        f = @(t) f_td(t, d, pcur, f3d);

        %Find the minimum in the line of the parametric f(t,d)
        [~,tmin] = Golden_search(f, -1000, 1000);

        [zcur, minx, miny] = f_td(tmin, d, pcur, f3d);

        %Update the point
        pcur = [minx, miny]';

        %Plot the point
        plot(pcur(1), pcur(2),'ok');
        text(pcur(1)+0.03, pcur(2)+0.03, strcat('it ',int2str(iter)));
       
    end
    
    err = norm([z0 zcur],2);
end
    
end

