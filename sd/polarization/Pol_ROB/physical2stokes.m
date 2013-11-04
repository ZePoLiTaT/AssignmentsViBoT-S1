function s = physical2stokes (phys)

s = zeros (4,1);

s(1) = phys(1);
s(2) = phys(1)*phys(2)*cos(2*phys(3));
s(3) = phys(1)*phys(2)*sin(2*phys(3))*cos(phys(4));
s(4) = phys(1)*phys(2)*sin(2*phys(3))*sin(phys(4));

end