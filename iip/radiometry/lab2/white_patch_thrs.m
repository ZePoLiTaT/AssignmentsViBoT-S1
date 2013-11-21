function [ oimg ] = white_patch_thrs( iim, h )
%UNTITLED5 Summary of this function goes here
%   Detailed explanation goes here

r = iim(:,:,1);
g = iim(:,:,2);
b = iim(:,:,3);

rmax = double( mean( r(r(:) > h) ));
gmax = double( mean( g(g(:) > h) ));
bmax = double( mean( b(b(:) > h) ));

Kr = 255/rmax;
Kg = 255/gmax;
Kb = 255/bmax;

oimg = iim;
oimg(:,:,1) = r*Kr;
oimg(:,:,2) = g*Kg;
oimg(:,:,3) = b*Kb;

end
