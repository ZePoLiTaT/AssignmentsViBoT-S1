 close all
 clear all
 clc
%Brute_force(@sin,0.2,8)
%Golden_search(@sin,0.2,8)
%Brent(@sin,0,8)

fparabola = @(x) x.*x;



figure;

k = linspace(-4, 4, 100);
plot(k,exponential(k));
Newton(@exponential, 0, 0.01);


figure;

k = linspace(0, 140, 1000);
plot(k,sinusoidal(k));
Newton(@sinusoidal, 4, 0.01);
