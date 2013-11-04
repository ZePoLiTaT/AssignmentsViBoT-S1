N = 5;
n = 3;

t = [1:N];
s1 = Dirac(n,N)
%stem(t,s1);

s2 = step(n,N)
%stairs(t,s2);

s3 = ramp(n, N)
%plot(t,s3);

a=2;
s4 = geo(a, n, N)

a=3;
s5 = box(a, 4, N)
