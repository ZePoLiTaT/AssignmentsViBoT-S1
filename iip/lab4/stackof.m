clear; clc; close all;

figure;
im = imread('lena.tif');

% Calculating fft2
fft2im = fft2(double(im));
% Taking the spectrum with log scaling
fft2im = log(1+(abs(fft2im)));
% Putting DC in the middle:
spectrum = fftshift(fft2im);
% finding maximum in spectrum:
maximum = max(max(spectrum));
% scaling maximum to 255 and minimum to 0:
spectrum = 255*spectrum/maximum;
% Casting to uint8 to be able to display:
spectrum =  uint8(spectrum);
imshow(spectrum);