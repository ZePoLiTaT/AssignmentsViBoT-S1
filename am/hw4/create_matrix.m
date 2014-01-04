function [ M ] = create_matrix( F )
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here

    M = zeros(10,6);
    for j=1:5
        M(2*j-1,:) = [F(j,1) F(j,2)    0      0    1   0];
        M(2*j  ,:) = [   0      0   F(j,1) F(j,2)  0   1];
    end

end

