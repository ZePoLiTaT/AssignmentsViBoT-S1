function [ A, E ] = getAE(N)
%GETAE Returns the A and E function for the configuration

%At first, we are going to build the 25×25 matrix A which will represent... 
%what each button does to the rest of the lights on the grid.
I=[1 0 0 0 0;0 1 0 0 0;0 0 1 0 0;0 0 0 1 0;0 0 0 0 1];
B=[1 1 0 0 0;1 1 1 0 0;0 1 1 1 0;0 0 1 1 1;0 0 0 1 1];
O=[0 0 0 0 0;0 0 0 0 0;0 0 0 0 0;0 0 0 0 0;0 0 0 0 0];
A=[B I O O O;I B I O O;O I B I O;O O I B I;O O O I B];

%Matrix A is defined by repeating B I O... 
%[reference paper: 'Turning lights out with linear algebra; Anderson and Feil']

%Now we want an elementary matrix of size 25 that produces the row... 
%operations that row-reduce matrix A in modulo 2.
E=[0 1 1 1 0 0 0 1 0 1 0 0 0 1 1 0 0 0 0 1 0 0 0 0 0; 1 1 0 1 1 0 1 0 0 0 0 0 1 1 1 0 0 0 1 0 0 0 0 0 0; 1 0 1 1 1 1 0 1 1 0 0 0 1 1 0 1 1 1 1 1 0 1 0 0 0;
   1 1 1 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 1 1 1 0 0; 0 1 1 0 1 1 0 0 0 0 1 0 1 0 1 0 0 1 0 1 1 1 0 0 0; 0 0 1 0 1 0 1 1 0 1 0 0 1 0 0 0 0 0 1 1 0 0 0 0 0; 
   0 1 0 1 0 1 1 0 1 1 0 0 0 1 0 1 1 1 0 0 0 1 0 0 0; 1 0 1 0 0 1 0 1 1 0 0 0 0 0 1 1 0 1 0 1 1 0 1 0 0; 0 0 1 0 0 0 1 1 1 0 1 0 0 1 1 1 0 0 1 0 0 1 1 0 0; 
   1 0 0 0 0 1 1 0 0 0 1 0 1 0 1 0 1 1 0 1 0 0 1 0 0; 0 0 0 0 1 0 0 0 1 1 0 0 1 0 1 1 1 1 1 0 0 1 0 0 0; 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 1 1 0 0;    
   0 1 1 0 1 1 0 0 0 1 1 0 1 1 0 0 0 1 0 0 1 1 0 0 0; 1 1 1 0 0 0 1 0 1 0 0 0 1 1 1 0 0 0 1 0 0 0 0 0 0; 1 1 0 0 1 0 0 1 1 1 1 0 0 1 1 1 1 0 1 0 1 0 0 0 0; 
   0 0 1 0 0 0 1 1 1 0 1 0 0 0 1 1 0 1 0 1 1 0 1 0 0; 0 0 1 1 0 0 1 0 0 1 1 1 0 0 1 0 1 1 1 0 0 0 1 0 0; 0 0 1 0 1 0 1 1 0 1 1 0 1 0 0 1 1 0 1 1 1 0 0 0 0; 
   0 1 1 0 0 1 0 0 1 0 1 0 0 1 1 0 1 1 1 0 0 0 1 0 0; 1 0 1 0 1 1 0 1 0 1 0 0 0 0 0 1 0 1 0 1 1 0 1 0 0; 0 0 0 1 1 0 0 1 0 0 0 1 1 0 1 1 0 1 0 1 1 1 0 0 0; 
   0 0 1 1 1 0 1 0 1 0 1 1 1 0 0 0 0 0 0 0 1 1 1 0 0; 0 0 0 1 0 0 0 1 1 1 0 1 0 0 0 1 1 0 1 1 0 1 0 0 0; 0 1 1 1 0 1 0 1 0 1 1 1 0 1 1 1 0 1 0 1 0 1 1 1 0; 
   1 0 1 0 1 1 0 1 0 1 0 0 0 0 0 1 0 1 0 1 1 0 1 0 1];
%Matrix E is the transformation matrix to get the row reduced matrix A...
%[reference paper: 'Lights out; Adrienne F. Olson']

end

