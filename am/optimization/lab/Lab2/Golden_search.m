function [minY, minX] = Golden_search(fun,a,c)

x = linspace(a,c,100);
y = fun(x);

interval = c-a;
eps = 10^-6;
flag = 1;

while (flag)
    b=rand()*(c-a)+a;
     %b = input('Input the initial guess:  ');   
    if ((fun(a) < fun(b)) || (fun(c) < fun(b)))
        disp('Invalid value, please try again')
    else
        flag =0;
    end
end

while (interval > eps)   % stop condition
    if ((b-a) > (c-b))
        xP = b - 0.38*(b-a);
        if ((fun(a) > fun(xP)) && (fun(b) > fun(xP))) 
       % if ( (fun(b) > fun(xP)))  why not?    
            c = b;
            b = xP;
        else
            a = xP;
        end
        
    else
        xP = b + 0.38*(c-b);
        if ((fun(c) > fun(xP)) && (fun(b) > fun(xP))) 
      %  if ( (fun(b) > fun(xP)))   why not?  
            a = b;
            b = xP;
        else
            c =xP;
        end
    end
    
    interval = c-a;
end

minY = fun(b);
minX = b;
% figure
% plot(x,y)
% hold on
% plot(minX,minY,'og')
% hold off

