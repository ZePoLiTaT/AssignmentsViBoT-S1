clear; clc; close all;

im = imread('Test1/Test1/fish.tif');

figure;
imshow(im);

imtest = white_patch_thrs(im, 150);
figure;
imshow(imtest);

juan = colorConstancy(im, 'grey world', 50, 200);
figure;
imshow(juan);