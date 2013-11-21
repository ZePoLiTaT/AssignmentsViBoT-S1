clc; clear; 

N = 5;
row = [1 1 zeros(1,N-2)];
B = toeplitz(row, row);
I = eye(N);
Z = zeros(N);

ATmp = [repmat(Z, 1, N-2) I B I repmat(Z, 1, N-2)];
A = [];

for i=N-1: -1: 0,
    iidx = N*i + 1;
    fidx = N*i + N*N;
    A = [A; ATmp(:,iidx:fidx)];
end

r = rank(A)
m = N*N
dimNA = m - r

b = [0 1 0 1 1 0 0 1 1];
b = [0 1 0 0 0 0 0 1 0 0 0 1 0 1 0 0 1 1 0 1 1 0 0 0 0]
AI = [A eye(m,m)];
RE = rref(AI);
E = RE(:, m+1:end);
E = mod(E*33,2);
