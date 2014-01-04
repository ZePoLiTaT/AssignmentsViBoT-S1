
function main

    N = 40;
    
    %% Exercice 1
    % Impulse response
    x = Dirac(20,N);
  
    filtering1D(x, @causalSmooth, @anticausalSmooth, true);
    
    % Unitary step
    x = step(10,N) - step(30,N);
    
    filtering1D(x, @causalDerivative, @anticausalDerivative, true);
    
    %% Exercice 2
    % Smooth derivative rows
    % I???
    im = imread('lena.png');
    Gx = filtering2D(im);
    
end


function filtering1D(x, causalFun, anticausalFun, youwanttoplot)
    yp = causalFun(x,1);
    yn = anticausalFun(x,1);
    y = yp + yn;
    
    if(youwanttoplot)
        figure;
        subplot(4,1,1); plot(x,'*-');
        subplot(4,1,2); plot(yp,'*-');
        subplot(4,1,3); plot(yn,'*-');
        subplot(4,1,4); plot(y,'*-');
    end
end

function Gx = filtering2D(x2D)
    [rows, cols] = size(x2D);
    
    for i=1:rows 
        x2DSmooth = filtering1D(x2D(i,:), @causalSmooth, @anticausalSmooth, false); 
    end
    
    for j=1:cols
                                                                                            
        Gx = filtering1D(x2DSmooth(:,j), @causalDerivative, @anticausalDerivative, false)'; 
    end
    
end

function y = causalSmooth(x, s)
    N = length(x);
    Ts = 1;
    
    alpha = s*Ts;
    a = exp(-alpha); 
    
    y=0;
    y(1:2) = 0;
    for k=3:N
        y(k) = x(k) + a*(alpha-1)*x(k-1) + 2*a*y(k-1) - a*a*y(k-2);
    end
end

function y = anticausalSmooth(x, s)
    N = length(x);
    Ts = 1;
    
    alpha = s*Ts;
    a = exp(-alpha); 
    
    y=0;
    y(N-1:N) = 0;
    for k= N-2: -1: 1
        y(k) = a*(alpha+1)*x(k+1) - a*a*x(k+2) + 2*a*y(k+1) - a*a*y(k+2);
    end
end

function y = causalDerivative(x, s)
    N = length(x);
    Ts = 1;
    
    alpha = s*Ts;
    a = exp(-alpha); 
    
    y=0;
    y(1:2) = 0;
    for k=3:N
        y(k) = -s*a*alpha*x(k-1) + 2*a*y(k-1) - a*a*y(k-2);
    end
end

function y = anticausalDerivative(x, s)
    N = length(x);
    Ts = 1;
    
    alpha = s*Ts;
    a = exp(-alpha); 
    
    y=0;
    y(N-1:N) = 0;
    for k= N-2: -1: 1
        y(k) = s*alpha*a*x(k+1) + 2*a*y(k+1) - a*a*y(k+2);
    end
end


