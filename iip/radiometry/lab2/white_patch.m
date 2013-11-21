function [ oimg ] = white_patch( iim )
%UNTITLED4 Summary of this function goes here
%   Detailed explanation goes here

r = iim(:,:,1);
g = iim(:,:,2);
b = iim(:,:,3);

rmax = double(max(r(:)));
gmax = double(max(g(:)));
bmax = double(max(b(:)));

Kr = 255/rmax;
Kg = 255/gmax;
Kb = 255/bmax;

oimg = iim;
oimg(:,:,1) = r*Kr;
oimg(:,:,2) = g*Kg;
oimg(:,:,3) = b*Kb;

end

