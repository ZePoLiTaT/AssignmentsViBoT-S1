clear; clc; close all;

im1 = imread('lena.tif');
%im = rgb2gray(im);
im2 = imread('bar.png');
im2 = rgb2gray(im2);


figure; imagesc(im1); colormap(gray);
[imMag1, imPhase1] = playFourier(im1);

figure; imagesc(im2); colormap(gray);
[imMag2, imPhase2] = playFourier(im2);


%%Mixing plots
imMix1 = imMag1 .* exp(i.*imPhase2);
imMix2 = imMag2 .* exp(i.*imPhase1);

imMix1 = ifft2(imMix1);
imMix2 = ifft2(imMix2);

figure;
subplot(1,2,1); imagesc(abs(imMix1)); colormap(gray);
subplot(1,2,2); imagesc(abs(imMix2)); colormap(gray);
title('Mixing info');