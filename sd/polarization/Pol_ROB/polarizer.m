function s_out = polarizer(s_in,a)
%
%s_in -> should be a row vector
%a -> 
%

M_pola = [1            cos(2*a)          sin(2*a)            0
          cos(2*a)  (cos(2*a))^2       cos(2*a)*sin(2*a)     0
          sin(2*a)  cos(2*a)*sin(2*a)  (sin(2*a))^2          0
            0             0                   0              0];
M_pola = (1/2)*M_pola;

s_out=M_pola*s_in'; % s_in' because s_in should be inputed as a row vector

end