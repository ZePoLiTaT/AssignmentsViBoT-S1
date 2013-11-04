function dellipse(s,n)
%Draw ellipse

[I, rho, varphi, delta]=stokes2physics(s);
w=2*pi;
t=0:0.01:1;

x = I*rho*cos(w*t)*cos(varphi);
y = I*rho*cos(w*t+delta)* sin(varphi);

figure(n)
clf(n)
plot(x,y,'-x')