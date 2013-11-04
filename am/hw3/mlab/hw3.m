%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Subject : Applied Mathematics
% Homework: 3
% Author  : Tatiana Lopez G
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

clc; clear; close all;

%Google 'loaded coin' r constant
r = 0.85;
zeps = 1e-4;


%% Section 1: 
% Initial reference-count matrix P

P = [1    1    0    0    0
     0    0    1    0    1
     0    0    1    0    0
     1    0    0    1    0
     1    1    0    0    1];

%Number of pages in our little world
N = size(P,1);

%% Section 2: 
% Now we take into account the weight of each reference

%Find the count of all references per site
n_j = sum(P);

%If the node is a dead end, set the maximum value
dead_ends = find(n_j==0)
n_j(dead_ends) = N;

%Normalize the matrix
P = bsxfun(@rdivide, P, n_j) 


%% Section 4: 
% Q Markov Matrix with Teleportation

%Matrix of random access to any website
%this means each page has the same probability to be chosen
T = ones(N,N)/N

%New Markov matrix with guaranteed non zero entries
%and therefore unique eigval=1 and unique stable state solution
Q = r*P + (1-r)*T

%% Section 5: 
% Steady state approximation

% Choose an arbitrary initial state
w = rand(N, 1);

%Make it valid. This means make all entries add up to 1
%which is achieved by normalizing it
w = w / sum(w);

% Create an unitary vector for multiplication purposes
u = ones(N, 1);
% Calculate the teleport term only once because its independent of w
teleport_term = (1-r)/N * u;

%First iteration
Qw_prev = r*P * w  +  teleport_term;


err = inf;
iterations = 0;
while(err > zeps)
   Qw = r*P * Qw_prev  +  teleport_term;
   
   err = sum(abs(Qw - Qw_prev));
   iterations = iterations + 1;
   
   Qw_prev = Qw;
end

Qw
iterations

%% Validation:
% We obtain the eigenvector of the eigenvalue=1 to verify
% that is indeed the approximation obtained in the previous state
[V,D] = eigs(Q);
V = V(:,1);
V = V / sum(V)