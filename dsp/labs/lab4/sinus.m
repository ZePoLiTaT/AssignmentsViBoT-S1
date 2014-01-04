function [ s ] = sinus( f, phase_rd, nbPeriod, varargin ) %fs or N
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here

    Ttotal = nbPeriod/f;
    if(strcmp(varargin{1}, 'N'))
        N = varargin{2};
        Fs = 1/(Ttotal/N);
    else
        Fs = varargin{2}
        N = round(TTotal*Fs); %ne tombe pas forcément sur un ent
        disp('Warning: the length of the signal can be different from');
    end
    Ts = 1/Fs;
    s = sin(2*pi*f*(0:N-1)*Ts+ phase_rd);
end

