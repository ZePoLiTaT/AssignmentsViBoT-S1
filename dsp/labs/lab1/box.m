function [ signal ] = box( a, n, N )
%BOX Returns the discrete box signal shifted by n
%   Returns the discrete box signal shifted by n
signal = []

if(n<(1+a) || n>(N-a))
    warning('n should be in the range [1+a..N-a]');
    return;
end

signal = zeros(1,N);
signal(n-a:n+a-1) = 1;

end

