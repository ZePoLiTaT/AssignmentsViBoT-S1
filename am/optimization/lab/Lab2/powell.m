function [ zcur, minx, miny, iter ] = powell( f3d, pini )
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here

%Number of dimensions
N = 2;

% u = [u1, u2]
ubase = [1 0; 0 1];


plot(pini(1), pini(2),'or');
text(pini(1)+0.03, pini(2)+0.03, 'it 0');

p0 = pini;
err = inf;
zcur = inf;
pcur = p0;
iter = 0;

while(err > 1e-1)
  
    %Reset the base vectors after N iterations
    if (mod(iter,2)==0)
        %disp('Reseting directions u');
        u = ubase;        
    end
    
    iter = iter + 1;
    p0 = pcur;
    z0 = zcur;
    
    for j=1:3
        
        % Update the direction with the base vectors
        if j<3
            d = u(:,j);
        % In the last step of the iteration, update the base vector 
        else
            u = [u(:,2), (pcur - p0)];
            d = u(:,2);
        end
        
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

