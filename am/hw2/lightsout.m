function [Sol] = lightsout(b)

%At first, we are going to build the 25×25 matrix A which will represent... 
%what each button does to the rest of the lights on the grid.

Sol = [];

%Matrix A is defined by repeating B I O... 
%[reference paper: 'Turning lights out with linear algebra; Anderson and Feil']

%Now we want an elementary matrix of size 25 that produces the row... 
%operations that row-reduce matrix A in modulo 2.
%Matrix E is the transformation matrix to get the row reduced matrix A...
%[reference paper: 'Lights out; Adrienne F. Olson ']
[ A, E ] = getAE(5);

%b is the initial confifiguration (INPUT)
%b=[1 0 1 1 1  0 0 0 0 1  1 0 0 1 1  0 1 1 0 1  1 0 0 0 1]'; % sample of a solvable initialization
%b=[0 0 0 1 0  1 1 0 0 1  1 0 0 1 1  0 1 1 0 1  1 0 0 0 1]'; % sample of a solvable initialization
%b=[1 1 0 1 0  0 0 1 0 0  0 1 1 0 1  0 1 0 0 0  1 0 0 0 1]'; % sample of an unsolvable initialization
%b=[1 0 0 1 0  0 0 1 0 0  0 1 1 0 1  0 1 0 0 0  1 0 0 1 1]'; % sample of an unsolvable initialization

U=mod(rref(A),2);
%U is the row reduced echelon form of A in modulo 2, directly using matlab function 'rref'
%U=EA

N1=U(:,24);
N2=U(:,25);
N1(24,1)=1;
N2(25,1)=1;
%U has rank 23 and 2 free variables. Extracting the last two columns and putting 1 into 24 and 25th 
%free variable's position respectively give N1,N2; making them the vectors for orthogonal basis for N(U)

a=mod(dot(b,N1),2);
c=mod(dot(b,N2),2);
%Checking if given initial configuration is solvable or unsolvable; a,c=0 gives solvable solution

%If the configuration is solvable find all solutions
if (a==0 && c==0)   
    Sol1=mod((E*b),2);
    Sol2=mod((Sol1+N1),2);
    Sol3=mod((Sol1+N2),2);
    Sol4=mod((Sol1+N1+N2),2);

%Check the number of 0 in the solutions     
    d1=length(find(Sol1==0));
    d2=length(find(Sol2==0));
    d3=length(find(Sol3==0));
    d4=length(find(Sol4==0));
    
%To show the solution with minimum 1's (checking higher number of 0's)in command window... 
%and in a pseudo figure of Solution Strategy Matrix
    if (d1>d2&&d1>d3&&d1>d4)
        Sol=Sol1';
        %Sol=[Sol(1:5);Sol(6:10);Sol(11:15);Sol(16:20);Sol(21:25)]
        %figure(2)
        %imagesc(Sol)
    elseif (d2>d3&&d2>d4)
        Sol=Sol2';
        
        %Sol=[Sol(1:5);Sol(6:10);Sol(11:15);Sol(16:20);Sol(21:25)]
        %figure(2)
        %imagesc(Sol)
    elseif (d3>d4)
        Sol=Sol3';
        
        %Sol=[Sol(1:5);Sol(6:10);Sol(11:15);Sol(16:20);Sol(21:25)]
        %figure(2)
        %imagesc(Sol)
    else
        Sol=Sol4';
        
        %Sol=[Sol(1:5);Sol(6:10);Sol(11:15);Sol(16:20);Sol(21:25)]
        %figure(2)
        %imagesc(Sol)
    end
        
    
else
    'Initial configuration is unsolvable' %as game is not solvable
end

