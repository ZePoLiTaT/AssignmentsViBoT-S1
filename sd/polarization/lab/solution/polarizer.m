function s_out=polarizer(s_in,alpha)
% Mueller function for a polarizer
%   alpha in degree

a=alpha*pi/180;
c=cos(2*a);
s=sin(2*a);

M=0.5*[1, c,s,0;
	c,c*c,c*s,0;
	s,c*s,s*s,0;
	0,0,0,0];

s_out=M*s_in;

