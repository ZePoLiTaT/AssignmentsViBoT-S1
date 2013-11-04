N=10;
n = 1:N;
x = step(4,N);
y = x(1:N-1) + x(2:N);
plot(n(1:N-1),y)