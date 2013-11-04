% Exercise 1
% 1.3 Applications

%%%%%%
% Q1
%%%%%%
disp('Q1')
si=physics2stokes(1,1,0,0); % linearly polarized beam at 0°
[I, rho, varphi, delta]=stokes2physics(retarder(si,pi/2,45))
disp('Phase should be equal to 90°:')
delta*180/pi 
disp('Phase should be equal to 45°:')
varphi*180/pi



%%%%%%
% Q2
%%%%%%
disp('Q2')
alpha=30;
si=physics2stokes(1,1,alpha/180*pi,0); % linearly polarized beam at alpha°
[I, rho, varphi, delta]=stokes2physics(retarder(si,pi,0))
varphi*180/pi


%%%%%%
% Q3
%%%%%%
disp('Q3')
%1- Incident light is unpolarized
si0=[1;0;0;0];
%2- use a fixed polarizer oriented at 0°
si1=polarizer(si0,0)
%3- use a rotating analyzer with a degree

a=[0:10:350];
for k=1:length(a)
	si2=polarizer(si1,a(k));
	intensity(k)=si2(1);
end
figure(3)
clf(3)
hold on
plot(a,intensity,'x')
plot(a,cos(a*pi/180).^2/2,'r')
hold off

%%%%%%
% Q4
%%%%%%
disp('Q4')
dellipse(physics2stokes(1,0.9,0.7,2),4)

%%%%%%
% Q5
%%%%%%
disp('Q5')
%Partially linearly polarized light
splp=physics2stokes(1, 0.5, 37/180*pi,0);
%Use a rotating analyzer with a degree
clear a
clear intensity
a=[0:10:170];
for k=1:length(a)
	so=polarizer(splp,a(k));
	intensity(k)=so(1);
end
figure(5)
clf(5)
plot(a,intensity)

%%%%%%
% Q6
%%%%%%
disp('Q6')
%Use a variable retarder with l in degree
clear intensity
l=[0:10:170]*2;
for k=1:length(l)
	si1=retarder(splp,pi/2,0);
	si2=retarder(si1,l(k)*pi/180,45);
	si3=polarizer(si2,0);
	intensity(k)=si3(1);
end
figure(6)
clf(6)
plot(l,intensity,'gx-')


