function [ y ] = convN( h, x, zeroh )
%CONVN Convolution function between x and h

% Flip the kernel
h = fliplr(h);
hN = length(h) - 1;
xN = length(x)

% Add zero padding
padding = zeros(1, length(h) - 1);
x = [padding x padding];

j = 1
for i = 1 : xN + hN
    tmp = x(i : i + hN) .* h;
    y(i) = sum(tmp);
end

end

