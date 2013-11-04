function [I, rho, varphi, delta]=stokes2physics(s)
% function [I, rho, varphi, delta]=stokes2physics(s)

s0=s(1);
s1=s(2);
s2=s(3);
s3=s(4);

I=s0;
rho=sqrt(s1*s1+s2*s2+s3*s3)/s0;
delta=atan(s3/(s2+0.0000000001));
%varphi=0.5*atan2(s2/cos(delta),s1);
%varphi=0.5*atan2(s3/sin(delta),s1);
%varphi=0.5*acos(s1/sqrt(s1*s1+s2*s2+s3*s3));
varphi=0.5*atan2(s2,s1*cos(delta));

