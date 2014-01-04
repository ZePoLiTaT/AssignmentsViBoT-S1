function [ fp, fp2 ] = Five_point_stencil(f, x, h)
%FP Returns the first and second order derivatives of f
%   Calculates the first and second order derivatives of f at the point
%   x by using the 5 points stencil method

fp =  ( -f(x+2*h) + 8*f(x+h) - 8*f(x-h) + f(x-2*h) ) / (12*h);
fp2 = ( -f(x+2*h) + 16*f(x+h) - 30*f(x) + 16*f(x-h) - f(x-2*h) ) / (12*(h.^2));

end

