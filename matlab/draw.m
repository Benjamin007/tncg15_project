function [ output ] = draw()

fileID = fopen('../rayCaster/screen_matrix.txt','r');
dimensionFileID = fopen('../rayCaster/screen_matrix_dim.txt','r');
formatSpec = '%d';
sizeDim = [1 2];
screenDimension = fscanf(dimensionFileID, formatSpec, sizeDim)


%formatSpec = ['%d' '%d' '%d'];
%sizeScreen = [screenDimension 3]

A = textscan(fileID, '%f')


screen = zeros(screenDimension(1), screenDimension(2),3);

%screen = zeros(2,2,3);


% OBSERVE!!! WARNING! Dimensions are twisted, to make coordinate system
% more like computer screen.
for x = 1:screenDimension(1)
    for y = 1:screenDimension(2)
        screen(x,y,1) = A{1}(((x-1) + (y-1)*screenDimension(2))*3+1);
        screen(x,y,2) = A{1}(((x-1) + (y-1)*screenDimension(2))*3+2);
        screen(x,y,3) = A{1}(((x-1) + (y-1)*screenDimension(2))*3+3);
        
        
    end
end


x = 2;
y = 1;

index = ((x-1) + (y-1)*screenDimension(2))*3+1
A{1}(index);


index = ((x-1) + (y-1)*screenDimension(2))*3+2
A{1}(index);


index = ((x-1) + (y-1)*screenDimension(2))*3+3
A{1}(index);

screen_max = max(max(screen))

image(screen)


% 
% screen = zeros(screenDimension(1),screenDimension(2),3);
% 
% for x = 1:screenDimension(1)
%     for y = 1:screenDimension(2)
%        screen(x,y,1) = A{1}((x-1)*screenDimension(1)+y);
%        screen(x,y,1) = A{2}((x-1)*screenDimension(1)+y);
%        screen(x,y,1) = A{3}((x-1)*screenDimension(1)+y);
%         
%     end
% end
% 
% screen
% image(screen)


%exit;
end

