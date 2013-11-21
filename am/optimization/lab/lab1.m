clc; clear; close all;

f = @(x) -exp(-x.*x) + exp(-(x+1).*(x+1))
N = 1000;
x = linspace(-3,3,N);

%% Sampling of the function
idx = intervalSearch(x,f);
sprintf('Minimum: x = %f, f(x)=%f \n',x(idx), f(x(idx)) )

plot(x,f(x));

goldenSearch(f, -3, 3, eps);