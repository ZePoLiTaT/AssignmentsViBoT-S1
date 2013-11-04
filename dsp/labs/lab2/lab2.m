N = 10;
n = 1:N;

figure
f1 = step(4,N)
pf = primf(f1, N)
subplot(2,1,1); plot(n,f1);
subplot(2,1,2); plot(n,pf);

figure
f2 = Dirac(4,N)
pf = primf(f2, N)
subplot(2,1,1); plot(n,f2);
subplot(2,1,2); plot(n,pf);