function [ imMag, imPhase ] = playFourier( im )
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here


%FFT unshifted 
figure;
imf = fft2(double(im)); 
subplot(2,2,1); imagesc(abs(imf)); colormap(gray);
title('FFT2 without shift');

%Shifted
imfs = fftshift(imf);
subplot(2,2,2); imagesc(abs(imfs)); colormap(gray);
title('FFT2 shifted');

%Logarithmic scale
imgl = log(abs(imfs)+1);
subplot(2,2,3); imagesc(imgl); colormap(gray);
title('FFT2 with logarithmic scale');

%Angle
subplot(2,2,4); imagesc(angle(imfs)); colormap(gray);
title('FFT2 phase');

figure;

imi = ifft2(imf);
subplot(2,2,1); imagesc(abs(imi)); colormap(gray);
title('iFFT2 Directly from ifft [reference value]');

imMag = abs(imf);
imPhase = angle(imf);
irecon1 = imMag .* exp(i*imPhase );
irecon1 = ifft2(irecon1);
subplot(2,2,2); imagesc(abs(irecon1)); colormap(gray);
title('iFFT2 reconstructed by Mag*exp(jPhase)');

constMag = 100;
irecon2 = constMag .* exp(i*imPhase );
irecon2 = ifft2(irecon2);
subplot(2,2,3); imagesc(abs(irecon2)); colormap(gray);
title('iFFT2 reconstructed with const Magnitude ');


imMag = 100;
randPhase = (rand(size(imPhase))*2*pi) - pi;
irecon3 = imMag .* exp(i*randPhase );
irecon3 = ifft2(irecon3);
subplot(2,2,4); imagesc(abs(irecon3)); colormap(gray);
title('iFFT2 reconstructed with random Phase ');


end

