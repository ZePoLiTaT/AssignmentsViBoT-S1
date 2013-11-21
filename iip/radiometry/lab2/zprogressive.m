function [ oimg ] = zprogressive( iim, h1, h2 )
%UNTITLED7 Summary of this function goes here
%   Detailed explanation goes here

r = iim(:,:,1);
g = iim(:,:,2);
b = iim(:,:,3);

I = (r + g + b)/3;

I_h1 = find(I(:) >= h1);


ravg = double( mean( r(I_h1) ));
gmax = double( mean( g(I_h1) ));
bmax = double( mean( b(I_h1) ));
av

Kr = 255/ravg;
Kg = 255/gmax;
Kb = 255/bmax;

oimg = iim;
oimg(:,:,1) = r*Kr;
oimg(:,:,2) = g*Kg;
oimg(:,:,3) = b*Kb;

end

