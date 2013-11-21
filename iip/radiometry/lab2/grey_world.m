function [ oimg ] = grey_world( iim )
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here

r = iim(:,:,1);
g = iim(:,:,2);
b = iim(:,:,3);

ravg = mean(r(:));
gavg = mean(g(:));
bavg = mean(b(:));

iavg = mean([ravg, gavg, bavg]);

Kr = iavg/ravg;
Kg = iavg/gavg;
Kb = iavg/bavg;

oimg = iim;
oimg(:,:,1) = r*Kr;
oimg(:,:,2) = g*Kg;
oimg(:,:,3) = b*Kb;
    
end

