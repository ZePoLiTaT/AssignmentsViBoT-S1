function [minY,minX] = Newton(f, iniX, h)
%NEWTON Finds the minimum of a 1D function using the Newton's 
%method.
%   Newton?s Method starts with the initial guess given by the
%   input parameter x and performs a series of incremental
%   steps towards the point were f' is 0. 
%   This means
%   that depending on the initial condition, the method will
%   reach either the minimum or the maximum of the function.
%   Each step is approximated by $x_{n+1} = x_{n} - \frac{f'(x_n)}{f''(x_n)}$
%   which comes from the 2nd order Taylor expansion. Here it is assumed
%   that the function behaves like a quadratic function around the optimum

eps = 10^-3;
it = 1;

fp1 = inf;
minX = iniX;

while abs(fp1) > eps
    
    % minY = f(minX)
    % hold on
    % plot(minX,minY,'og')
    % hold off
    
    [fp1, fp2] = Five_point_stencil(f, minX, h)
    minX = minX - fp1/fp2
    
    
    it = it + 1;
    
end

minY = f(minX)
hold on
plot(minX,minY,'og')
hold off

