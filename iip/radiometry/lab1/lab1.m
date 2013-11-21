clc; clear; close all;

%% Intensity, luminance and color components

% Load the flower image
flowers = imread('RawImages/Flowers.tif');
figure;
imshow(flowers);

% Equal average of every channel
figure;
grayfavg = flowers(:,:,1)*(1/3) + flowers(:,:,2)*(1/3) + flowers(:,:,3)*(1/3);
subplot(1,3,1); imshow(grayfavg);
title('Normal Averaging');

% Weighted average to emulate the sensitivity of the eye
grayf = flowers(:,:,1)*0.299 + flowers(:,:,2)*0.587 + flowers(:,:,3)*0.114;
subplot(1,3,2); imshow(grayf);
title('Weighted Averaging');

% Comparison with the matlab function
grayrgb = rgb2gray(flowers);
subplot(1,3,3); imshow(grayrgb);
title('Matlab RGB2Gray');

% As we can see here, the weighted average gray image looks more
% natural and it is the same image obtained with the RGB2Gray Matlab
% function. This is because the HVS (Human Vision Systems) is more
% sensitive to the green and red light and thats why we put the
% 0.587, 9.299 respectively to these channels

%% Appropiate color spaces

% We want to have uncorrelated components with respect to
% the color. If we stay in the RGB space, the R, B and G 
% components are correlated because changing one of them
% affects the overall color obtained.
% 
% However, in HSV you have 3 uncorrelated components. By changing
% the saturation (S) and the value (V) will not change the color.
% Only changing the hue will change the color itself.

% Load the house image
house = imread('RawImages/house.tif');
figure;
imshow(house);

% Make it brighter in RGB means adding a constant to all of the channels
% In the cube representation is like moving diagonally from black to white
figure;
lum = 50;
house_brgb = house + lum;
imshow(house_brgb);

% Changing the brightness in HSV is simply augmenting the Value channel
househsv = rgb2hsv(house);
househsv_b = househsv;
househsv_b(:,:,3) = househsv_b(:,:,3) + 0.3;
subplot(1,3,1); imshow(hsv2rgb(househsv_b))

% Making the colors more pure can be done only by changing the
% Saturation channel
househsv_s = househsv;
househsv_s(:,:,2) = 1.0;
subplot(1,3,2); imshow(hsv2rgb(househsv_s))

% Changing the colors can be done only by changing the
% Hue channel
househsv_c = househsv;
househsv_c(:,:,1) = mod(househsv_c(:,:,1) + 0.5 ,1);
subplot(1,3,3); imshow(hsv2rgb(househsv_c))

figure;
subplot(1,3,1); imshow(househsv(:,:,1));
subplot(1,3,2); imshow(househsv(:,:,2));
subplot(1,3,3); imshow(househsv(:,:,3));