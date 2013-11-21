clear; clc; close all;

ipar = imread('CPM/Difuse/2.png');
iorth = imread('CPM/Difuse/2a.png');

figure; colormap(gray);
subplot(1,2,1); imagesc(ipar);
subplot(1,2,2); imagesc(iorth);

itotalint = double(ipar) + double(iorth);
ipolcontr = double(ipar) - double(iorth);
ipolcontrdisp = ipar - iorth;
ipolcontrratio = ipolcontr./itotalint;


figure; colormap(gray);
subplot(2,2,1); imagesc(itotalint);  title('Total Intensity (scaling)');
subplot(2,2,2); imagesc(ipolcontrratio); title('Pol. Contrast Ratio (scaling)');
subplot(2,2,3); imagesc(ipolcontr); title('Pol. Contrast (scaling)');
subplot(2,2,4); imagesc(255-ipolcontrdisp); title('Pol. Contrast (negative)');