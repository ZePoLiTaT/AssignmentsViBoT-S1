clear; clc; close all;

P =[13 20  50 20 34 34 16 50 48 50]';

files_features = dir(fullfile('Data', '*.txt'));
files_images = dir(fullfile('Data', '*.JPG'));

Favg = normalize(files_features, P);
apply_transform(files_features, files_images, Favg, 5);
