function [ fgrad ] = gradient2D(f, point)
%FP Returns the first and second order derivatives of f
%   Calculates the first and second order derivatives of f at the point
%   x by using the 5 points stencil method

h = 1;
x = point(1);
y = point(2);

fx_h = @(tx) f(tx, y);
fy_h = @(ty) f(x, ty);

fpx = fp(fx_h, x);
fpy = fp(fy_h, y);
fgrad = [fpx, fpy];

end

