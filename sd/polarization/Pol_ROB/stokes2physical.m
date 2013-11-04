function physical = stokes2physical(s_in)

physical = zeros(4,1);

dop = sqrt(s_in(2)^2 + s_in(3)^2 + s_in(4)^2)/s_in(1);
d = atan2(s_in(3)/s_in(2));
phi = (1/2)*(atan2(s_in(2)/(s_in(1)*cos(d))));

physical(1) = s_in(1);
physical(2) = dop;
physical(3) = phi;
physical(4) = d;


end