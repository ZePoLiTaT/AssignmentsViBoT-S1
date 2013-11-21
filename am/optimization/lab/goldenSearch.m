function [ idxMin ] = goldenSearch( f, a, c, zeps )
%GOLDENSEARCH Summary of this function goes here
%   Detailed explanation goes here

% TODO: Generate rand b validating initial condition
b = 1;

thrs = inf;
xev = b - 0.38*(b-a);
z = 1 - 2*0.38;

%while (thrs > zeps)
for i = 1:2
    
    if( f(xev) < f(b) )
        a = b;
        b = xev;
        
    else
        if ( f(xev) > f(b) )
            c = xev;
        end
    end
    
    %
    xev = (c-a)*z + b
    
    %TODO: change this
    thrs = abs(f(b) - f(xev))
end

end

