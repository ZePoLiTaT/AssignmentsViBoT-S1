function [minY, minX] = Brent(fun,a,b)

x = linspace(a,b,100);
y = fun(x);

% for a=-4  and b=4 it doesnt work
% this method depends in the interval,
% it should be similar to a parabola
% it's not good

eps = 10^-3;
flag = 1;

while (flag)
     c = input('Input the initial guess:  ');   
    if ((fun(a) < fun(c)) || (fun(b) < fun(c)))
        disp('Invalid value, please try again')
    else
        flag =0;
    end
end

while( (abs(a-c)>eps) && (abs(b-c)>eps) )  % stop condition a=b=c
    num = (((b-a)^2)*(fun(b)-fun(c))) -  (((b-c)^2)*(fun(b)-fun(a)));
    den = (((b-a))*(fun(b)-fun(c))) -  (((b-c))*(fun(b)-fun(a)));
    xP = b - (1/2)*(num/den);
    
    if (max(fun(a),fun(b)) == fun(a))
        interv1 = xP-a;
        interv2 = c-a;
        diffInterv = interv1-interv2;
        if(diffInterv >  0)
            a = c;
            c = xP;
        else
            a = xP;
        end
        
    else
        interv1 = b-xP;
        interv2 = b-c;
        diffInterv = interv1-interv2;
        if(diffInterv >  0)
            b = c;
            c = xP;
        else
            b = xP;
        end
        
    end
    
end

minY = fun(c);
minX = c;

figure
plot(x,y)
hold on
plot(minX,minY,'*c')
hold off

