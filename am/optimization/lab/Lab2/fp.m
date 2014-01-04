function [ fp, fp2 ] = fp(f, x)
%FP Returns the first and second order derivatives of f
%   Calculates the first and second order derivatives of f at the point
%   x by using the 5 points stencil method

h = 1;
fp =  ( -f(x+2*h) + 8*f(x+h) - 8*f(x-h) + f(x-2*h) ) / (12*h);
fp2 = ( -f(x+2*h) + 16*f(x+h) - 30*f(x) + 16*f(x-h) - f(x-2*h) ) / (12*(h.^2));

end

