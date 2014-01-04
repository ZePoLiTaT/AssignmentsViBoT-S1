

syms x real
y = f(x)
yh = matlabFunction(y)
ydiff = matlabFunction( diff(y) )
ydiffdiff = matlabFunction( diff( diff(y) ) )
taylorapprox = @(x,stp) yh(x) + stp*ydiff(x) + (stp.^2)/2 * ydiffdiff(x)

tmpx=[0:0.01:125];
hold on; plot(tmpx, taylorapprox(tmpx, h), 'r'); hold off;