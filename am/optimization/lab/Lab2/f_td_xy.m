function [ x, y ] = f_td_xy( t, d, p0 )
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here

    pxy = d*t;
    pxy = bsxfun(@plus, pxy, p0);
    x = pxy(1,:);
    y = pxy(2,:);
end

