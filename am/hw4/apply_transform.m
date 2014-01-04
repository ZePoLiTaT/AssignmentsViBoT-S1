function apply_transform(files_features, files_images, Favg, dispView)
%UNTITLED4 Summary of this function goes here
%   Detailed explanation goes here

posDisp = 1;

for i = 1:numel(files_features)
    Ffeat = load(strcat('Data/',files_features(i).name));
    
    X = transformation_parameters(Ffeat, Favg);
    Mfeat = create_matrix(Ffeat);
    Mfeat*X;

    % Create the Affine transformation matrix
    Af = [X(1) X(2) X(5); 
          X(3) X(4) X(6);
           0     0   1];

    I = imread(strcat('Data/',files_images(i).name));
    tform = maketform('affine',Af');
    J = imtransform(I,tform,'bicubic','XData',[1 64], 'YData', [1 64]);
    
    if(mod(i,dispView)==0)
        figure(1), subplot(5,5,posDisp), imshow(J); 
        %figure(2), subplot(5,5,posDisp), imshow(I);
        posDisp = posDisp + 1;
    end
end

end

