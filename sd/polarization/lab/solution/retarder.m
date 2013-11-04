function s_out=retarder(s_in,delta,psi)
% Mueller function for a retarder
%   delta: phase shift 
%   psi: angle in degree of the retarder
d=delta;
p=psi/180*pi;

c=cos(2*p);
s=sin(2*p);

M=	[1, 0,0,0;
	0,c*c+s*s*cos(d),s*c*(1-cos(d)),-s*sin(d);
	0,c*s*(1-cos(d)),s*s+c*c*cos(d),c*sin(d);
	0,s*sin(d),-c*sin(d),cos(d)];

s_out=M*s_in;

