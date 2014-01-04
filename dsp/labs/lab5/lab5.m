clear all; close all; clc;

N = 64;
Ts = 1/N; Fs = N; df = Fs/N
Im(N/8:N/4, N/4+1:N/2) = 1;
Im(1:N/4, N/2+1:N) = Im;
Im(N/4+1:N/2, :) = Im;
Im(N/2+1:3*N/4, :) = Im(1:N/4, :);
Im(3*N/4+1:N, :) = Im(1:N/4, :);

figure(10), imagesc(Im); colormap(gray);

tf = fft2(Im)/N/N;
tfs = fftshift( tf );  %Normalization
moyenne = mean2(Im);

figure(11); imagesc( abs(tfs) ); set(gca, 'XTickLabel',{-N/2:df:N/2-1});
figure(12); imagesc( angle(tfs)/pi*180 ); colormap(gray);



%Horizontal frequency axis
hfs = tfs(N/2+1, :);
%Vertical frequencies
vfs = tfs(:, N/2+1);

figure;
subplot(2,1, 1), plot(-Fs/2 :Fs/2-df, abs(hfs)); title('Freq horizontales'); 
subplot(2,1, 2), plot(-Fs/2 :Fs/2-df, abs(vfs)); title('Freq verticales');


