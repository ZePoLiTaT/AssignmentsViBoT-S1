function [ rank, P, T, Q, Qw ] = pagerank( P , zeps, r)
%PAGERANK Pagerank calculating function
%   Performs the steps explained in the paper and returns
%   the matrices P, T and Q and also the obtained eigenvector
%   after some iterations to achieve an error given by zeps
%   The loaded coin factor can also be provided. The default values is .85

if nargin < 3
    r =   0.85
end

%Number of pages in our little world
N = size(P,1);

%% Section 2: 
% Now we take into account the weight of each reference

%Find the count of all references per site
n_j = sum(P);

%Find indices of dead ends
dead_ends = find(n_j==0)
%Make it reference to all the web
P(:,dead_ends) = ones(N,length(dead_ends))
%Normalize by N
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

iterations


%% Ranked Pages:
% So the highest rank goes to the page with the higher value $$v_j$$
[tmp, rank] = sort(Qw, 'descend');

end

