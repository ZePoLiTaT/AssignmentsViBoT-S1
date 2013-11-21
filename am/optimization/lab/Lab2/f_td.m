function [ z ] = f_td( t, d, p0 )
%UNTITLED6 Summary of this function goes here
%   Detailed explanation goes here

    pxy = d*t;
    bsxfun(@plus, pxy, p0);
    z = f_3d(pxy(1,:), pxy(2,:));
end

