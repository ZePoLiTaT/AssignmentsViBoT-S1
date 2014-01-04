function [ zcur, minx, miny, iter ] = steepest_descent( f3d, pini )
%STEEPEST_DESCENT Finds the minimum of a function using the gradient
%information
%   Searchs for the minimum of a function moving each step
%   in the direction of the negative gradient.
%   The function f is supposed to be diferentiable in order to
%   calculate the first order derivative

%Number of dimensions
N = 2;

plot(pini(1), pini(2),'or');
text(pini(1)+0.03, pini(2)+0.03, 'it 0');

p0 = pini;
err = inf;
zcur = inf;
pcur = p0;
iter = 0;

step = 0.01;

while(err > 1e-1)
    
    iter = iter + 1;
    zprev = zcur;
    
    for j=1:2
        
        % Update in the direction of the negative gradient
        d = - gradient2D( f3d, pcur )';
        
        %Find the 2D projection of the 3D function along the d direction
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
    
    err = norm([zprev zcur],2);
end
    
end

