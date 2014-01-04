function [ z, x, y ] = f_td( t, d, p0, f3d )
%UNTITLED6 Summary of this function goes here
%   Detailed explanation goes here

    [x, y] = f_td_xy(t, d, p0);
    z = f3d(x, y);
end

