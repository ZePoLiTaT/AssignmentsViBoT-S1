#include <iostream>
#include "WingedEdge.h"
#include "Exercice.h"
#include <stdlib.h>

using namespace std;


/**
* <B>Excercice 1</B>
* The filled table is:
* <table>
* <tr>
*  <th>Edge#</th>
*  <th>StarPt</th>
*  <th>EndPt</th>
*  <th>Fccw</th>
*  <th>Fcw</th>
*  <th>Nccw</th>
*  <th>Pccw</th>
*  <th>Ncw</th>
*  <th>Pcw</th>
* </tr>
* <tr>
*  <td> 0</td>
*  <td> P0</td>
*  <td> P1</td>
*  <td>F1</td>
*  <td>F3</td>
*  <td>1</td>
*  <td>3</td>
*  <td>9</td>
*  <td>8</td>
* </tr>
* <tr>
*  <td> 1</td>
*  <td> P1</td>
*  <td>P2</td>
*  <td>F1</td>
*  <td>F4</td>
*  <td>2</td>
*  <td>0</td>
*  <td>10</td>
*  <td>9</td>
* </tr>
* <tr>
*  <td> 2</td>
*  <td>P2 </td>
*  <td>P3</td>
*  <td>F1</td>
*  <td>F5</td>
*  <td>3</td>
*  <td>1</td>
*  <td>11</td>
*  <td>10</td>
* </tr>
* <tr>
*  <td> 3</td>
*  <td>P3</td>
*  <td>P0</td>
*  <td>F1</td>
*  <td>F6</td>
*  <td>0</td>
*  <td>2</td>
*  <td>8</td>
*  <td>11</td>
* </tr>
* <tr>
*  <td> 4</td>
*  <td>P7</td>
*  <td>P6</td>
*  <td>F2</td>
*  <td>F5</td>
*  <td>5</td>
*  <td>7</td>
*  <td>10</td>
*  <td>11</td>
* </tr>
* <tr>
*  <td> 5</td>
*  <td>P6</td>
*  <td>P5</td>
*  <td>F2</td>
*  <td>F4</td>
*  <td>6</td>
*  <td>4</td>
*  <td>9</td>
*  <td>10</td>
* </tr>
* <tr>
*  <td> 6</td>
*  <td>P5</td>
*  <td>P4</td>
*  <td>F2</td>
*  <td>F3</td>
*  <td>7</td>
*  <td>5</td>
*  <td>8</td>
*  <td>9</td>
* </tr>
* <tr>
*  <td> 7</td>
*  <td>P4</td>
*  <td>P7</td>
*  <td>F2</td>
*  <td>F6</td>
*  <td>4</td>
*  <td>6</td>
*  <td>11</td>
*  <td>8</td>
* </tr>
* <tr>
*  <td> 8</td>
*  <td>P0</td>
*  <td>P4</td>
*  <td>F3</td>
*  <td>F6</td>
*  <td>6</td>
*  <td>0</td>
*  <td>7</td>
*  <td>3</td>
* </tr>
* <tr>
*  <td> 9</td>
*  <td>P1</td>
*  <td>P5</td>
*  <td>F4</td>
*  <td>F3</td>
*  <td>5</td>
*  <td>1</td>
*  <td>6</td>
*  <td>0</td>
* </tr>
* <tr>
*  <td> 10</td>
*  <td>P2</td>
*  <td>P6</td>
*  <td>F5</td>
*  <td>F4</td>
*  <td>4</td>
*  <td>2</td>
*  <td>5</td>
*  <td>1</td>
* </tr>
* <tr>
*  <td> 11</td>
*  <td>P3</td>
*  <td>P7</td>
*  <td>F6</td>
*  <td>F5</td>
*  <td>7</td>
*  <td>3</td>
*  <td>4</td>
*  <td>2</td>
* </tr>
</table>
* <B>Excercice 2</B>
* -# There are 3 classes for the objects that form the Winged Edge structure: Point, Edge and Face
*    and 3 Arrays for holding each one of them
*
* -# If the following section is commented
* <CODE>
*   #ifndef ...
*   #define ...
*   ...
*   #endif
* </CODE>
* in the WingedEdge.h file, then the following error is shown: "redefinition of ‘class Point’ ... previous definition of ‘class Point’ ..."
*
* -# The previous statement is a safeguard for the includes. It ensures that if a file was previously included, then it is not redeclared again.
*    For this specific case, the WingedEdge.h is included in the main.cpp file but also in the Exercice.h file, and if the validation
*    is removed, then the header will be appended twice, leading to a redefinition of the clases inside it.
*
* -# The main program shows a menu for handling the points, faces and edges of a WingedEdge structure.
*    The user can manually add each one of the objects mentioned, can display their individual information or
*    all the elements in the Array of points, faces or edges.
*
*    The options 14, 15 and 16 provide the functionality
*    to automatically create the vertices, edges and faces of a cube. And the options 7, 8 and 9, create all
*    the links between all the objects of these 3 clases necesary to make it a valid WingedEdge cube structure.
*
*    Finally, the option 13 provides a method to validate if all the faces of the automatically generated strcture (cube)
*    are valid, because as
*    we saw, this data structure is extremelly sensitive to errors. That is to say, if even 1 of the links is
*    wrong, then the whole structure is invalid.
*       - Individual edges can be added through the option 4 which internally does <CODE>Edge * E = new Edge(P1,P2); ArrayE.AddEdge(E);</CODE>
*       - Individual points can be added through the option 1 which internally does <CODE>ArrayP.AddPoint();</CODE>
*       - Individual faces can be added through the option 10 which internally does <CODE>Face*F = new Face;
                F->Start = ArrayE.GetAt( _usergivenindex_ );
                F->Start->Fccw = F;
                ArrayF.AddFace(F);</CODE>
*       - Display information about edges can be done through the option 5 which internally does <CODE>E->Info();</CODE> and 6
*         which internally does <CODE>ArrayE.Info();</CODE>
*       - Display information about points can be done through the option 2 which internally does <CODE>P->Info();</CODE> and 3
*         which internally does <CODE>ArrayP.Info();</CODE>
*       - Display information about faces can be done through the option 11 which internally does <CODE>F->Info();</CODE> and 12
*         which internally does <CODE>ArrayF.Info();</CODE>
*       - The purpose of the <CODE><type> **array;</CODE> is to handle an array of pointers of the type given by <CODE>type</CODE>
*         As mentioned before, there are 3 arrays (ArrayP, ArrayE, ArrayF) of pointers, that stores pointers to Points, Edges and Faces
*         respectively.
* -# My source code was included in the case 7, case 8, case 9 and case 13 of the main function.
*
* <B>Excercice 3</B>
* In order to create the cube, the code for the case 7, 8 and 9 was implemented.
* The user should select these options in the menu in the following order: (14, 15, 16, 7, 8, 9)
*
* <B>Excercice 4</B>
* The validation of all the faces was implemented in the case 13. Here iterate through all the faces
* stored in ArrayF and for each one, I extract the starting edge. The validity of each face is done by traversing all
* the edges in clockwise or counter clockwise order (depeding on if the face is Fcw or Fccw for the edge)
* and counting the number of edges until I reach again the starting point.
*
* A validation of the maximum number of edges that a face can have was added in order to prevent infinite loops in
* case the face is invalid.
*
* Also, since we are dealing with a cube, the number of edges that the face must have is 4.
*/
int main()
{
    ArrayPoint ArrayP;
    ArrayEdge  ArrayE;
    ArrayFace  ArrayF;

    int answer = 0;
    int end = -1;
    while(answer != end)
    {
        system("cls"); // kind of bad, but is enough to clear the console screen

        cout << "1 : Create point(s)" << endl;
        cout << "2 : Get Point info using index"<<endl;
        cout << "3 : Get Array Points info"<<endl<<endl;

        cout << "4 : Create segment(s)" << endl;
        cout << "5 : Get Segment info"<<endl;
        cout << "6 : Get Array Segments info"<<endl<<endl;

        cout << "7 : Link segment clockwise - prev and next - (student work here)"<<endl;
        cout << "8 : Link segment counterclockwise - prev and next - (student work here)"<<endl;
        cout << "9 : Link segment to faces (student work here)"<<endl<<endl;

        cout << "10 : Create face(s) by setting a start Edge" << endl;
        cout << "11 : Get Face info"<<endl;
        cout << "12 : Get Array Faces info"<<endl;
        cout << "13 : Check if face is closed (student work here)"<<endl<<endl;

        cout << "14 : automatic point generation"<<endl;
        cout << "15 : automatic edge generation"<<endl;
        cout << "16 : automatic first edge init for faces"<<endl;





        cout << endl<< end <<" : exit"<<endl<<endl;

        cout<<"entry: ";cin >>answer;
        system("cls"); // kind of bad, but is enough to clear the console screen

        switch (answer) {
            case 1 : {
                ArrayP.AddPoint();
            }break;

            case 2 : {

                cout <<"Enter point index:";
                int pindex; cin >> pindex;
                Point * P = ArrayP.GetAt(pindex);
                if (P) P->Info();
                else cout<<"Point not found"<<endl;

            }break;

            case 3 : {
                ArrayP.Info();
            }break;

            case 4 : {
                cout <<"Edge creation"<<endl;
                cout <<"Enter indexes of extremities"<<endl;
                int a, b;
                cin>> a>>b;

                Point*P1 = ArrayP.GetAt(a);
                Point*P2 = ArrayP.GetAt(b);

                if(P1 && P2) {
                    Edge * E = new Edge(P1,P2);
                    ArrayE.AddEdge(E);
                    }
                else{
                    cout <<"indexes invalid or points not created"<<endl;
                    }
            }break;

            case 5 : {

                cout <<"Enter Edge index:";
                int eindex; cin >> eindex;
                Edge * E = ArrayE.GetAt(eindex);
                if (E) E->Info();
                else cout<<"Edge not found"<<endl;

            }break;

            case 6 : {
                ArrayE.Info();
            }break;

//-------------------------
//student work here
//-------------------------

            case 7 : {
                //Manual setup of Next Clockwise and Prev Clockwise

                //Edge 0
                    ArrayE.GetAt(0)->Nextcw = ArrayE.GetAt(9);
                    ArrayE.GetAt(0)->Prevcw = ArrayE.GetAt(8);

                //Edge 1
                    ArrayE.GetAt(1)->Nextcw = ArrayE.GetAt(10);
                    ArrayE.GetAt(1)->Prevcw = ArrayE.GetAt(9);

                //Edge 2
                    ArrayE.GetAt(2)->Nextcw = ArrayE.GetAt(11);
                    ArrayE.GetAt(2)->Prevcw = ArrayE.GetAt(10);

                //Edge 3
                    ArrayE.GetAt(3)->Nextcw = ArrayE.GetAt(8);
                    ArrayE.GetAt(3)->Prevcw = ArrayE.GetAt(11);

                //Edge 4
                    ArrayE.GetAt(4)->Nextcw = ArrayE.GetAt(10);
                    ArrayE.GetAt(4)->Prevcw = ArrayE.GetAt(11);

                //Edge 5
                    ArrayE.GetAt(5)->Nextcw = ArrayE.GetAt(9);
                    ArrayE.GetAt(5)->Prevcw = ArrayE.GetAt(10);

                //Edge 6
                    ArrayE.GetAt(6)->Nextcw = ArrayE.GetAt(8);
                    ArrayE.GetAt(6)->Prevcw = ArrayE.GetAt(9);

                //Edge 7
                    ArrayE.GetAt(7)->Nextcw = ArrayE.GetAt(11);
                    ArrayE.GetAt(7)->Prevcw = ArrayE.GetAt(8);

                //Edge 8
                    ArrayE.GetAt(8)->Nextcw = ArrayE.GetAt(7);
                    ArrayE.GetAt(8)->Prevcw = ArrayE.GetAt(3);

                //Edge 9
                    ArrayE.GetAt(9)->Nextcw = ArrayE.GetAt(6);
                    ArrayE.GetAt(9)->Prevcw = ArrayE.GetAt(0);

                //Edge 10
                    ArrayE.GetAt(10)->Nextcw = ArrayE.GetAt(5);
                    ArrayE.GetAt(10)->Prevcw = ArrayE.GetAt(1);

                //Edge 11
                    ArrayE.GetAt(11)->Nextcw = ArrayE.GetAt(4);
                    ArrayE.GetAt(11)->Prevcw = ArrayE.GetAt(2);

                }break;

//-------------------------
//student work here
//-------------------------

            case 8 : {

                //Edge 0
                    ArrayE.GetAt(0)->Nextccw = ArrayE.GetAt(1);
                    ArrayE.GetAt(0)->Prevccw = ArrayE.GetAt(3);


                //Edge 1
                    ArrayE.GetAt(1)->Nextccw = ArrayE.GetAt(2);
                    ArrayE.GetAt(1)->Prevccw = ArrayE.GetAt(0);

                //Edge 2
                    ArrayE.GetAt(2)->Nextccw = ArrayE.GetAt(3);
                    ArrayE.GetAt(2)->Prevccw = ArrayE.GetAt(1);

                //Edge 3
                    ArrayE.GetAt(3)->Nextccw = ArrayE.GetAt(0);
                    ArrayE.GetAt(3)->Prevccw = ArrayE.GetAt(2);

                //Edge 4
                    ArrayE.GetAt(4)->Nextccw = ArrayE.GetAt(5);
                    ArrayE.GetAt(4)->Prevccw = ArrayE.GetAt(7);

                //Edge 5
                    ArrayE.GetAt(5)->Nextccw = ArrayE.GetAt(6);
                    ArrayE.GetAt(5)->Prevccw = ArrayE.GetAt(4);

                //Edge 6
                    ArrayE.GetAt(6)->Nextccw = ArrayE.GetAt(7);
                    ArrayE.GetAt(6)->Prevccw = ArrayE.GetAt(5);

                //Edge 7
                    ArrayE.GetAt(7)->Nextccw = ArrayE.GetAt(4);
                    ArrayE.GetAt(7)->Prevccw = ArrayE.GetAt(6);

                //Edge 8
                    ArrayE.GetAt(8)->Nextccw = ArrayE.GetAt(6);
                    ArrayE.GetAt(8)->Prevccw = ArrayE.GetAt(0);

                //Edge 9
                    ArrayE.GetAt(9)->Nextccw = ArrayE.GetAt(5);
                    ArrayE.GetAt(9)->Prevccw = ArrayE.GetAt(1);

                //Edge 10
                    ArrayE.GetAt(10)->Nextccw = ArrayE.GetAt(4);
                    ArrayE.GetAt(10)->Prevccw = ArrayE.GetAt(2);

                //Edge 11
                    ArrayE.GetAt(11)->Nextccw = ArrayE.GetAt(7);
                    ArrayE.GetAt(11)->Prevccw = ArrayE.GetAt(3);

                }break;


//-------------------------
//student work here
//-------------------------

            case 9 : {

                //Edge 0
                    ArrayE.GetAt(0)->Fccw = ArrayF.GetAt(0);
                    ArrayE.GetAt(0)->Fcw  = ArrayF.GetAt(2);

                //Edge 1
                    ArrayE.GetAt(1)->Fccw = ArrayF.GetAt(0);
                    ArrayE.GetAt(1)->Fcw  = ArrayF.GetAt(3);

                //Edge 2
                    ArrayE.GetAt(2)->Fccw = ArrayF.GetAt(0);
                    ArrayE.GetAt(2)->Fcw  = ArrayF.GetAt(4);

                //Edge 3
                    ArrayE.GetAt(3)->Fccw = ArrayF.GetAt(0);
                    ArrayE.GetAt(3)->Fcw  = ArrayF.GetAt(5);

                //Edge 4
                    ArrayE.GetAt(4)->Fccw = ArrayF.GetAt(1);
                    ArrayE.GetAt(4)->Fcw  = ArrayF.GetAt(4);

                //Edge 5
                    ArrayE.GetAt(5)->Fccw = ArrayF.GetAt(1);
                    ArrayE.GetAt(5)->Fcw  = ArrayF.GetAt(3);

                //Edge 6
                    ArrayE.GetAt(6)->Fccw = ArrayF.GetAt(1);
                    ArrayE.GetAt(6)->Fcw  = ArrayF.GetAt(2);

                //Edge 7
                    ArrayE.GetAt(7)->Fccw = ArrayF.GetAt(1);
                    ArrayE.GetAt(7)->Fcw  = ArrayF.GetAt(5);

                //Edge 8
                    ArrayE.GetAt(8)->Fccw = ArrayF.GetAt(2);
                    ArrayE.GetAt(8)->Fcw  = ArrayF.GetAt(5);

                //Edge 9
                    ArrayE.GetAt(9)->Fccw = ArrayF.GetAt(3);
                    ArrayE.GetAt(9)->Fcw  = ArrayF.GetAt(2);

                //Edge 10
                    ArrayE.GetAt(10)->Fccw = ArrayF.GetAt(4);
                    ArrayE.GetAt(10)->Fcw  = ArrayF.GetAt(3);

                //Edge 11
                    ArrayE.GetAt(11)->Fccw = ArrayF.GetAt(5);
                    ArrayE.GetAt(11)->Fcw  = ArrayF.GetAt(4);

                }break;

            case 10 : {

                Face*F = new Face;
                cout <<"enter index of starting edge for the face"<<endl;
                int eindex;
                cin >>eindex;
                F->Start = ArrayE.GetAt(eindex);
                F->Start->Fccw = F;
                ArrayF.AddFace(F);

            }break;

            case 11 : {

                cout <<"Enter Face index:";
                int findex; cin >> findex;
                Face * F = ArrayF.GetAt(findex);
                if (F) F->Info();
                else cout<<"Edge not found"<<endl;

            }break;

            case 12 : {
                ArrayF.Info();
                }break;

            case 13 : {

                int validFaces = 0;
                Face * F;
                cout<<"Number of faces to test: "<<ArrayF.n<<endl;
                cout<<"Maximum number of edges per face: "<<ArrayE.n<<endl;

                //Evaluate the validity of all the faces inside the cube
                for(unsigned int findex=0; findex<ArrayF.n; findex++)
                {
                    cout<<"-------------------  Testing Face "<<findex<<"-------------------------------"<<endl;
                    F = ArrayF.GetAt(findex);
                    F->Info();
                    cout<<"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;

                    if(F && F->Start)
                    {
                        Edge *it = F->Start;

                        if(it!=NULL)
                        {
                            int count = 0;
                            do
                            {
                                it->Info();

                                //If the face is counter-clockwise to the edge, then we follow
                                //the next edge that is also counter-clockwise
                                if(it->Fccw == F)
                                    it = it->Nextccw;
                                else
                                    it = it->Prevcw;

                                count++;
                            }while(it && it!=F->Start && count<ArrayE.n);

                            //If we return to the origin and we counted 4 edges, then is the face of the cube
                            if(it==F->Start && count==4)
                            {
                                cout<<"Closed Face!! .. Number of edges ["<<count<<"]"<<endl;
                                validFaces++;
                            }
                            else
                                cout<<"Open Face :( Number of edges ["<<count<<"]"<<endl;
                        }
                        else
                            cout<<"Open Face :( No Initial edge"<<endl;
                    }

                    cout<<"------------------------------------------------------------------"<<endl;

                }

                if(validFaces==ArrayF.n)
                        cout<<"**** ALL FACES ARE VALID! ****"<<endl;
                else
                    cout<<"**** SORRY, THERE ARE SOME INVALID FACES ****"<<endl;

                }break;

            case 14 : {

                ArrayP.AddPoint(new Point( 0,0,0) );
                ArrayP.AddPoint(new Point( 0,1,0) );
                ArrayP.AddPoint(new Point( 1,1,0) );
                ArrayP.AddPoint(new Point( 1,0,0) );
                ArrayP.AddPoint(new Point( 0,0,-1) );
                ArrayP.AddPoint(new Point( 0,1,-1) );
                ArrayP.AddPoint(new Point( 1,1,-1) );
                ArrayP.AddPoint(new Point( 1,0,-1) );

            }break;

            case 15 :{
                //edges of the front face
                ArrayE.AddEdge(new Edge(ArrayP.GetAt(0),ArrayP.GetAt(1))) ;
                ArrayE.AddEdge(new Edge(ArrayP.GetAt(1),ArrayP.GetAt(2))) ;
                ArrayE.AddEdge(new Edge(ArrayP.GetAt(2),ArrayP.GetAt(3))) ;
                ArrayE.AddEdge(new Edge(ArrayP.GetAt(3),ArrayP.GetAt(4))) ;

                //edges of the back face
                ArrayE.AddEdge(new Edge(ArrayP.GetAt(7),ArrayP.GetAt(6))) ;
                ArrayE.AddEdge(new Edge(ArrayP.GetAt(6),ArrayP.GetAt(5))) ;
                ArrayE.AddEdge(new Edge(ArrayP.GetAt(5),ArrayP.GetAt(4))) ;
                ArrayE.AddEdge(new Edge(ArrayP.GetAt(4),ArrayP.GetAt(7))) ;

                //edges to "link" front face and back face
                ArrayE.AddEdge(new Edge(ArrayP.GetAt(0),ArrayP.GetAt(4))) ;
                ArrayE.AddEdge(new Edge(ArrayP.GetAt(1),ArrayP.GetAt(5))) ;
                ArrayE.AddEdge(new Edge(ArrayP.GetAt(2),ArrayP.GetAt(6))) ;
                ArrayE.AddEdge(new Edge(ArrayP.GetAt(3),ArrayP.GetAt(7))) ;

            }break;

            case 16 :{

                Face *F1 = new Face;
                F1->Start = ArrayE.GetAt(0);
                F1->Start->Fccw = F1;
                ArrayF.AddFace(F1);

                Face *F2 = new Face;
                F2->Start = ArrayE.GetAt(4);
                F2->Start->Fccw = F2;
                ArrayF.AddFace(F2);

                Face *F3 = new Face;
                F3->Start = ArrayE.GetAt(8);
                F3->Start->Fccw = F3;
                ArrayF.AddFace(F3);

                Face *F4 = new Face;
                F4->Start = ArrayE.GetAt(9);
                F4->Start->Fccw = F4;
                ArrayF.AddFace(F4);

                Face *F5 = new Face;
                F5->Start = ArrayE.GetAt(10);
                F5->Start->Fccw = F5;
                ArrayF.AddFace(F5);

                Face *F6 = new Face;
                F6->Start = ArrayE.GetAt(11);
                F6->Start->Fccw = F6;
                ArrayF.AddFace(F6);
            }break;

        }//end switch

        system("pause"); //kind of bad too, but sufficient to pause until key pressed

    }//end while

    return 0;
}
