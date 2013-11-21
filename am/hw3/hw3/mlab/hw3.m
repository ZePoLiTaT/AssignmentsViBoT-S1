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

P = [0 0 1 0 0
     1 0 0 0 0
     0 0 0 0 0
     1 1 1 0 1 
     0 0 0 1 0] 
 
 %{
P = [0 0 0 1 0 0 0 0 0 0
     0 0 1 1 1 1 1 1 1 1
     0 1 0 0 0 0 0 0 0 0
     0 0 0 0 1 0 0 0 0 0
     0 0 0 0 0 1 1 1 1 1
     0 0 0 0 1 0 0 0 0 0
     0 0 0 0 0 0 0 0 0 0
     0 0 0 0 0 0 0 0 0 0
     0 0 0 0 0 0 0 0 0 0
     0 0 0 0 0 0 0 0 0 0
    ]; 
%}
 
[rank, P, T, Q, Qw] = pagerank(P, zeps, r)  

%% Validation:
% We obtain the eigenvector of the eigenvalue=1 to verify
% that is indeed the approximation obtained in the previous state
[V,D] = eigs(Q);
V = V(:,1);
V = V / sum(V)


%% Plot the results
% Show the relative sizes of the ranked web sites
% The pages are ordered from left to right and the y position is random
x = 80 * [1:size(P,1)];
y = 80 * randn(size(x));
c = randi(80, size(x));
%c=[1 .5 0; 1 .5 0; 0 1 0; 1 0 0; 0 0 1];
scatter(x, y, V*10000, c, 'filled', 'MarkerEdgeColor', 'k')
axis off;

