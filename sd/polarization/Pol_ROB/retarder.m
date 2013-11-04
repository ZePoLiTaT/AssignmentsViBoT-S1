function s_out= retarder(s_in,d,phi)

%
%s_in -> should be a row vector
%d ->
%phi ->
%

c=cos(2*phi);
s=sin(2*phi);

M_ret = [1           0                  0                  0
         0     c^2 + (s^2)*cos(d)  s*c*(1-cos(d))        -s*sin(d)
         0     s*c*(1-cos(d))       s^2 + (c^2)*cos(d)    c*sin(d)
         0     s*sin(d)            -c*sin(d)             cos(d)  ];
     
s_out = M_ret*s_in';% s_in' because s_in should be inputed as a row vector
     
end