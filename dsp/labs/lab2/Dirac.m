function [ signal ] = Dirac(n, N)
%DIRAC Returns the dirac function
%   Dirac function

signal = zeros(1,N);

if(n<1 || n>N)
    warning('n should be in the range [1..N]');
    return;
end

signal = zeros(1,N);
signal(n) = 1;

end

