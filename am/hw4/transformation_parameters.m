function [ X ] = transformation_parameters( F, b )
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here

    M = create_matrix(F);
    [U,S,V] = svd(M);
    Apinv = V*pinv(S)*U';
    X = Apinv*b;

end

