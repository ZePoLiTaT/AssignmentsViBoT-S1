% I = [0 0 0 0 0 0;
%      0 0 0 0 0 0;
%      0 0 255 255 0 0;
%      0 0 255 255 0 0;
%      0 0 255 255 0 0;
%      0 0 0 0 0 0;
%      0 0 0 0 0 0];
I = imread('eli.png');
subplot(2,2,1);
subimage(I);
title('Image');

% 2D Fourier Transform

G = rgb2gray(I);
% fourier transform:
FT = fft2(G); 
% Discrete Fourier Transform: without shift
subplot(2,2,2);
imagesc(abs(FT));
colormap(gray);
title('DFT');
% put the origin of the spectrum in the center of the plot:
FT_shift = fftshift(FT);
% compute the magnitude
M = abs(FT_shift);
subplot(2,2,3);
imagesc(M);
colormap(gray);
title('Centred Magnitude Spectrum');
% logarithm
L = log(M);
subplot(2,2,4);
imagesc(L);
colormap(gray);
title('Centred Magnitude Spectrum applying Log');

%inverse fourier transform
% IFT = ifft(FT);
% figure();
% subplot(2,2,1);
% imagesc(IFT);

