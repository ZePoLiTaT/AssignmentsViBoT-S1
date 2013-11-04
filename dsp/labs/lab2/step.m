function [ signal ] = step(n, N)
%STEP Returns the step function shifted at position n
%   Shifted step function

signal = zeros(1,N);

if(n<1 || n>N)
    warning('n should be in the range [1..N]');
    return;
end

signal = zeros(1,N);
signal(n:N) = ones(1,N-n+1);

end

