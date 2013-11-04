function s=physics2stokes(I, rho, varphi, delta)
% s=physics2stokes(I, rho, varphi, delta)

s=I*[1; rho*cos(2*varphi); rho*sin(2*varphi)*cos(delta); rho*sin(2*varphi)*sin(delta)];
