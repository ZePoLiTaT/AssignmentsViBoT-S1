function [ signal ] = geo( a, n, N )
%GEO Returns a shifted discrete geometric series function
%   Returns a shifted discrete geometric series function

signal = zeros(1,N);

if(n<1 || n>N)
    warning('n should be in the range [1..N]');
    return;
end

f = @(k) a.^k;
signal = zeros(1,N);
signal(n:N) = f([0:N-n]);

end

