function [ oimg ] = progressive( iim, h1, h2 )
%UNTITLED6 Summary of this function goes here
%   Detailed explanation goes here

r = iim(:,:,1);
g = iim(:,:,2);
b = iim(:,:,3);

I = (r + g + b)/3;

% I >= h1: white patch

I_h1 = I(:) >= h1;

rmean = double(mean(r(I_h1)));
gmean = double(mean(g(I_h1)));
bmean = double(mean(b(I_h1)));

Kr_w = 255/rmean;
Kg_w = 255/gmean;
Kb_w = 255/bmean;

% I <= h2: grey world

I_h2 = I(:) <= h2;

rmean = double(mean(r(:)));
gmean = double(mean(g(:)));
bmean = double(mean(b(:)));

irmean = mean(r(:));
igmean = mean(g(:));
ibmean = mean(b(:));
imean = (irmean + igmean + ibmean)/3;

Kr_g = imean/rmean;
Kg_g = imean/gmean;
Kb_g = imean/bmean;

% h2 < I < h1

I_h1h2 = ( I(:) < h1) && ( I(:) > h2);

delta = (1 / (h1 - h2) ) * I - ( h2 / (h1-h2) );

Kr_wg = 255/rmax;
Kg_wg = 255/gmax;
Kb_wg = 255/bmax;

oimg = iim;
oimg(:,:,1) = r*Kr;
oimg(:,:,2) = g*Kg;
oimg(:,:,3) = b*Kb;

end

