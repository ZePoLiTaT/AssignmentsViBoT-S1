clear all; 
figure(30);
ax=[-5 5 0 0.1];
N = 1000000;
s = randn(1,N); %white noise, gaussian distribution
%s = rand(1,N); %white noise, uniform distribution
s = s - mean(s);

h=0;
[h, xh] = hist(s,50);
h = h/sum(h);
subplot(4,2,1); plot(xh,h,'*-');
axis(ax);
title('pdf histogram');
fs = 1000;
f = fftshift(fft(s)); %we can apply the fft on outcomes
fprintf('Length of fft: %d\n', length(f));
df = fs/N;
figure(30); subplot(4,2,2); plot(-fs/2:df:fs/2-df, abs(f));

sb = 0;
sb = s(1:2:end);
Nb = length(sb);
h=0;
[h, xh] = hist(s,50);
h = h/sum(h);
subplot(4,2,3); plot(xh,h,'*-');
axis(ax);
title('pdf histogram');

fsb = fs / 2;
f = fftshift(fft(sb)); %we can apply the fft on outcomes
df = fsb/Nb;
figure(30); subplot(4,2,4); plot(-fsb/2:df:fsb/2-df, abs(f));
%the frecuency distribution is modified range is divided by 2
% the spatial distribution is unchanged

sc = 0;
sc = sin(s);
Ns = length(sc);
h=0;
[h, xh] = hist(sc,50);
h = h/sum(h);
subplot(4,2,5); plot(xh,h,'*-');
axis(ax);
title('pdf histogram');

fss = fs;
f = fftshift(fft(sc)); %we can apply the fft on outcomes
df = fss/Ns;
figure(30); subplot(4,2,6); plot(-fss/2:df:fss/2-df, abs(f));
%the frecuency distribution is modified range is divided by 2
% the spatial distribution is unchanged