function [ Favg ] = normalize( files , P)
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here

Favg = load(strcat('Data/',files(1).name))';
Favg = Favg(:);


iter = 1;
Favg_s = 0;
err = inf;
Ft = 0;

while(err >= .5) %sum(Ft-Favg) < 1e-3)
%for j=1:10

    Favg_s = 0;
    
    for i = 1:numel(files)
        
        Fi = load(strcat('Data/',files(i).name));
        %disp(files(i).name);
        if(iter==0 && i==1)
            T = transformation_parameters(Fi, P);
            Mfavg = create_matrix(reshape(Favg,2,5)');
            %Favg = Mfavg*X;
            %Favg_s = Favg_s + Favg;
            Favg = Mfavg*T
            Favg_s = Favg;
        else
            T = transformation_parameters(Fi, Favg);
            Mfi = create_matrix(Fi);
            Favg_s = Favg_s + Mfi*T;
            
        end
        
    end
    
    Ft = Favg
    Favg = Favg_s ./ numel(files)
    
    err = norm(Ft-Favg);
    fprintf('Iteración %d. Error[%f]\n', iter, err);
    iter = iter + 1;
    
end

Favg
end

