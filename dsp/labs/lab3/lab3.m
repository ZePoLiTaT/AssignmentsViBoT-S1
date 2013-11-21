clc; clear; close all;

x = [9 2 1 0 5]
h = [0 1 0]

%% Without zero padding
y = convN(h,x)
