function varargout = gui(varargin)
% GUI MATLAB code for gui.fig
%      GUI, by itself, creates a new GUI or raises the existing
%      singleton*.
%
%      H = GUI returns the handle to a new GUI or the handle to
%      the existing singleton*.
%
%      GUI('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in GUI.M with the given input arguments.
%
%      GUI('Property','Value',...) creates a new GUI or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before gui_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to gui_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help gui

% Last Modified by GUIDE v2.5 16-Oct-2013 15:23:26

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @gui_OpeningFcn, ...
                   'gui_OutputFcn',  @gui_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT

function set_neighboors(handles, indx, gamemat, movmat)
    global imgon
    global imgoff
    
    %indx
    tomovemat = movmat(:,indx);
    tomovemat(indx) = 0; 
    moves = find(tomovemat);
    
     for i=1:length(moves)
          if(get(gamemat(moves(i)), 'Value'))
              set(gamemat(moves(i)),'cdata',imgoff );
              set(gamemat(moves(i)), 'Value', 0);
          else
              set(gamemat(moves(i)),'cdata',imgon );
              set(gamemat(moves(i)), 'Value', 1);
          end
     end
    

function togglebutton_callback(hObject, eventdata, handles, gamemat, indx)
    global imgon
    global imgoff
    global SETUPA
    global PLAYA
    
    playmode = get(handles.playsetup, 'Value');
    if get(hObject,'Value')
        set(hObject,'cdata',imgon );
    else
        set(hObject,'cdata',imgoff );
    end
    
    if(playmode)
        %If is the play mode,  the pressed button and its
        %4 neighboors are affected. The matrix of movements
        %is the matrix A given in the paper (PLAYA)
        set_neighboors(handles, indx, gamemat, PLAYA);
    else
        %If is the setup mode, only the pressed button
        %is affected, so the matrix of movements is the
        %identity matrix (SETUPA)
        set_neighboors(handles, indx, gamemat, SETUPA);
    end


%Creates a grid
function gamemat = create_grid(hObject, values, handles)
    %h = figure('ToolBar','none');
    global BTSIZE
    global N
    global imgoff

    gamemat = zeros(1, N*N);
    idx = 1;
    for i=1:N
        for j=1:N
            pbh = uicontrol(hObject,...
                    'Style','togglebutton',...
                    'String',' ',...
                    'Value', values(idx),...
                    'cdata', imgoff,...
                    'Position',[50+j*(BTSIZE+10) ...
                                380-i*(BTSIZE+10) ...
                                BTSIZE ...
                                BTSIZE]);
            
            gamemat(idx) = pbh;
            %set(pbh, 'Value', values(idx));
            idx = idx + 1;
        end
    end

    idx = 1;
    for i=1:N
        for j=1:N
            set(gamemat(idx), 'Callback',{@togglebutton_callback, handles, gamemat, idx});
            togglebutton_callback(gamemat(idx), [], handles, gamemat, idx);
            idx = idx + 1;
        end
    end
    

% --- Executes just before gui is made visible.
function gui_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to gui (see VARARGIN)

    global BTSIZE
    global N
    global b
    global imgon
    global imgoff
    global PLAYA
    global SETUPA
    
    global btnarr 

    % Choose default command line output for gui
    handles.output = hObject;

    % Update handles structure
    guidata(hObject, handles);

    %%%%%%%%%%%%%%%%%%%%%%%%%%
    %  INITIALIZE CONSTANTS
    %Button size
    BTSIZE = 50;

    %Grid size
    N=5;

    %Image
    imgon = imread('light_bulb.png');
    imgoff = imread('black.png');

    %User setup
    b = zeros(1,N*N);

    PLAYA = getAE(N);
    SETUPA = eye(N*N);
    
    %%%%%%%%%%%%%%%%%%%%%%%%
    %     Create the grid 
    btnarr = create_grid(hObject, b, handles);


% UIWAIT makes gui wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = gui_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
    varargout{1} = handles.output;


% --- Executes on button press in pushbutton1.
function pushbutton1_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

    global btnarr 
    global N
    global b
    global imgon

    idx = 1;
    for i=1:N
        for j=1:N
            b(idx) = get( btnarr(idx), 'Value' );
            idx = idx + 1;
        end
    end

    x = lightsout(b');
    if(length(x)>0)
        a = figure('name','Solution steps:');
        create_grid(a, x, handles);
    else
        warndlg('There is no solution!');
    end


% --- Executes on button press in playsetup.
function playsetup_Callback(hObject, eventdata, handles)
% hObject    handle to playsetup (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of playsetup
    if get(hObject,'Value')
            set(hObject,'String', 'Setup' );
    else
        set(hObject,'String', 'Play' );
    end
