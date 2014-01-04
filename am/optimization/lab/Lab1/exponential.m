function y = exponential(x)
%EXPONENTIAL Test function
%   y = -e(-x^2) + e(-(x+1)^2)

    y = -exp(-x.^2) + exp(-(x+1).^2);

end
