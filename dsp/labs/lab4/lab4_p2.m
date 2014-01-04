clear all;
f=1000;
NT = 6;
Np = 100;
s=0;
s = sinus(f,0,NT,'N',Np);
figure(32); subplot(2,1,1), plot(s,'*-');

N = length(s);
sf = fftshift(fft(s));
fs = 1/((1/f)*NT/N);
df = fs/N;
subplot(2,1,2), plot(-fs/2:df:fs/2-df,abs(sf), '*-');
ch = sprintf('sampling frecuency');
title(ch); 