function [ signal ] = ramp( n, N )
%RAMP Returns a discrete shifted ramp function
%   Returns a discrete shifted ramp function

if(n<1 || n>N)
    warning('n should be in the range [1..N]');
    return;
end

signal = zeros(1,N);
signal(n:N) = [0:N-n];

end

