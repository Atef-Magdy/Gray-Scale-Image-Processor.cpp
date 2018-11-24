#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"
#include<vector>

using namespace std;

    unsigned char image[SIZE][SIZE];
    unsigned char Merge[SIZE][SIZE];
    unsigned char Rot[SIZE][SIZE];
    unsigned char enlarge[SIZE][SIZE];
    unsigned char shrank[SIZE][SIZE];

    void loadImage();
    void SaveImage();
    void BlackWite();
    void Invert();
    void Mrge();
    void Flip();
    void Rotate();
    void Dark_light();
    void DetectingEdge();
    void Enlarge();
    void Shrank();
    void Miror();

    int in , choice;
    char f;

    int main()
    {
        cout << "Ahlan ya user ya habibi." << endl << endl;
        loadImage();
        while(true){
                cout << "\n1- Black & White Filter \n2- Invert Filter \n3- Merge Filter \n4- Flip Image" << endl;
                cout << "5- Darken and Lighten Image \n6- Rotate Image \n7- Detect Image Edges \n8- Enlarge Image" << endl;
                cout << "9- Shrink Image \n10- Save the image to a file \n11-Mirror 1/2 Image \n0- Exit" << endl << endl;
                cout << "Please select a filter to apply or 0 to exit :";
                cin >> choice;
                while(choice>11 || choice<0){
                    cout << "Enter a correct number : ";
                    cin >> choice;
                }
                if(choice==1) BlackWite();
                else if(choice==2) Invert();
                else if(choice==3) Mrge();
                else if(choice==4) Flip();
                else if(choice==5) Dark_light();
                else if(choice==6) Rotate();
                else if(choice==7) DetectingEdge();
                else if(choice==8) Enlarge();
                else if(choice==9) Shrank();
                else if(choice==10) SaveImage();
                else if(choice==11) Miror();
                else if(choice==0) break;
        }

        return 0;
    }
    void loadImage () {
       char imageFileName[100];
       cout << "Enter the source image file name: ";
       cin >> imageFileName;
       strcat (imageFileName, ".bmp");
       readGSBMP(imageFileName, image);
    }
    void BlackWite(){
        int total=0 , average;
        for(int i=0 ; i<SIZE ; ++i){
            for(int j=0 ; j<SIZE ; ++j){
                    total+=image[i][j];

            }}
        average=total/pow(SIZE,2);
        for(int i=0 ; i<SIZE ; ++i){
            for(int j=0 ; j<SIZE ; ++j){
                    if(image[i][j] > average) image[i][j]=255;
                    else image[i][j]=0;

            }}
    }
    void SaveImage() {
       char imageFileName[100];
       cout << "Enter the target image file name: ";
       cin >> imageFileName;
       strcat (imageFileName, ".bmp");
       writeGSBMP(imageFileName, image);
    }
    void Invert(){
        for(int i=0 ; i<SIZE ; ++i){
            for(int j=0 ; j<SIZE ; ++j){
                    image[i][j]=255-image[i][j];
            }}
    }
    void Mrge(){
        char imageFileName[100];
        cout << "Please enter name of image file to merge with: ";
        cin >> imageFileName;
        strcat(imageFileName , ".bmp");
        readGSBMP(imageFileName,Merge);
        for(int i=0 ; i<SIZE ; ++i){
            for(int j=0 ; j<SIZE ; ++j){
                    image[i][j]=(Merge[i][j]+image[i][j])/2;
            }}
    }
    void Flip(){
        cout << "Flip (h)orizontally or (v)ertically ?";
        cin >> f;
        while(f!='v' && f!='h'){
                cout << "Enter v or h : ";
                cin >> f;
            }
        if(f=='v'){
                unsigned char half[SIZE][SIZE/2+1];
                for(int i=0 ; i<SIZE ; ++i){
                    for(int j=0 ; j<SIZE/2+1 ; ++j){
                            half[i][j]=image[i][j];
                            image[i][j]=image[i][255-j];
                    }}
                for(int i=0 ; i<SIZE ; ++i){
                    for(int j=SIZE/2+2; j<SIZE ; ++j){
                            image[i][j]=half[i][255-j];

            }}}

        else if(f=='h'){
                unsigned char half[SIZE/2+1][SIZE];
                for(int i=0 ; i<SIZE/2+1 ; ++i){
                    for(int j=0 ; j<SIZE ; ++j){
                            half[i][j]=image[i][j];
                            image[i][j]=image[255-i][j];
                    }}
                for(int i=SIZE/2+2 ; i<SIZE ; ++i){
                    for(int j=0 ; j<SIZE ; ++j){
                            image[i][j]=half[255-i][j];

            }}}
    }
    void Rotate(){
        cout << "Rotate (90), (180) or (270) degrees? ";
        cin >> in;
        while(in!=90 && in!=180 && in!=270){
                cout << "Enter a correct degree : ";
                cin >> in;
            }

        if(in==90){
                for(int i=0 ; i<SIZE ; ++i){
                    for(int j=0 ; j<SIZE ; ++j){
                        Rot[j][255-i]=image[i][j];
            }}
                for(int i=0 ; i<SIZE ; ++i){
                    for(int j=0 ; j<SIZE ; ++j){
                        image[i][j]=Rot[i][j];
            }}}

        else if(in==180){
                for(int i=0 ; i<SIZE ; ++i){
                    for(int j=0 ; j<SIZE ; ++j){
                        Rot[255-i][255-j]=image[i][j];
                    }}
                for(int i=0 ; i<SIZE ; ++i){
                    for(int j=0 ; j<SIZE ; ++j){
                            image[i][j]=Rot[i][j];
            }}}

        else if(in==270){
                for(int i=0 ; i<SIZE ; ++i){
                    for(int j=0 ; j<SIZE ; ++j){
                        Rot[255-j][i]=image[i][j];
                    }}
                for(int i=0 ; i<SIZE ; ++i){
                    for(int j=0 ; j<SIZE ; ++j){
                            image[i][j]=Rot[i][j];
            }}}
    }
    void Dark_light(){
        cout << "Do you want to (d)arken or (l)ighten? ";
        cin >> f;
        while(f!='d' && f!='l'){
                    cout << "Enter d or l : ";
                    cin >> f;
            }
        if(f=='d'){
                for(int i=0 ; i<SIZE ; ++i){
            for(int j=0 ; j<SIZE ; ++j){
                image[i][j]-=image[i][j]/2;
        }}}

        else if(f=='l'){
                 for(int i=0 ; i<SIZE ; ++i){
            for(int j=0 ; j<SIZE ; ++j){
                image[i][j]+=50;
        }}}
    }
    void DetectingEdge(){
        for(int i=0 ; i<SIZE ; ++i){
            for(int j=0 ; j<SIZE ; ++j){
                    if((image[i+1][j]-image[i][j]>=40) || (image[i][j+1]-image[i][j]>=40) || image[i][j]-image[i+1][j]>=40 || image[i][j]-image[i][j+1]>=40) image[i][j]=0;
                    else image[i][j]=255;
    }}}
    void Enlarge(){
        cout << "Which quarter to enlarge 1, 2, 3 or 4? ";
        cin >> in;
        while(in<1 && in>4){
                cout << "Enter a correct number : ";
                cin >> in;
            }
        if(in==1){
                int r=0 , c=0;
                for(int i=0 ; i<SIZE/2 ; ++i){
                    for(int j=0 ; j<SIZE/2 ; ++j){
                            enlarge[r][c]  =image[i][j];
                            enlarge[r][c+1]=image[i][j];
                            enlarge[r+1][c]=image[i][j];
                            enlarge[r+1][c+1]=image[i][j];
                            c+=2;

                    }
                    c=0;
                    r+=2;
                    }
                for(int i=0 ; i<SIZE ; ++i){
                    for(int j=0 ; j<SIZE ; ++j){
                            image[i][j]=enlarge[i][j];
            }}}

        else if(in==2){
                int r=0 , c=0;
                for(int i=0 ; i<SIZE/2 ; ++i){
                    for(int j=SIZE/2 ; j<SIZE ; ++j){
                            enlarge[r][c]  =image[i][j];
                            enlarge[r][c+1]=image[i][j];
                            enlarge[r+1][c]=image[i][j];
                            enlarge[r+1][c+1]=image[i][j];
                            c+=2;

                    }
                    c=0;
                    r+=2;
                    }
                for(int i=0 ; i<SIZE ; ++i){
                    for(int j=0 ; j<SIZE ; ++j){
                            image[i][j]=enlarge[i][j];
            }}}

        else if(in==3){
                int r=0 , c=0;
                for(int i=SIZE/2 ; i<SIZE ; ++i){
                    for(int j=0 ; j<SIZE/2 ; ++j){
                            enlarge[r][c]  =image[i][j];
                            enlarge[r][c+1]=image[i][j];
                            enlarge[r+1][c]=image[i][j];
                            enlarge[r+1][c+1]=image[i][j];
                            c+=2;

                    }
                    c=0;
                    r+=2;
                    }
                for(int i=0 ; i<SIZE ; ++i){
                    for(int j=0 ; j<SIZE ; ++j){
                            image[i][j]=enlarge[i][j];
            }}}

        else if(in==4){
                int r=0 , c=0;
                for(int i=SIZE/2 ; i<SIZE ; ++i){
                    for(int j=SIZE/2 ; j<SIZE ; ++j){
                            enlarge[r][c]  =image[i][j];
                            enlarge[r][c+1]=image[i][j];
                            enlarge[r+1][c]=image[i][j];
                            enlarge[r+1][c+1]=image[i][j];
                            c+=2;

                    }
                    c=0;
                    r+=2;
                    }
                for(int i=0 ; i<SIZE ; ++i){
                    for(int j=0 ; j<SIZE ; ++j){
                            image[i][j]=enlarge[i][j];
            }}}
    }
    void Shrank(){
        int choise;
        cout << "Shrink to (1/2), (1/3) or (1/4)? ";
        cin >> choise;
        while(choise<2 || choise>4){
                cout << "Enter 2 or 3 or 4 : ";
                cin >> choise;
            }

        if(choise==2){
                int r=0 , c=0 , raw1 , raw2;
                for(int i=0 ; i<SIZE ; i+=2){
                    for(int j=0 ; j<SIZE ; j+=2){

                            raw1=image[i][j]+image[i][j+1];
                            raw2=image[i+1][j]+image[i+1][j+1];

                          shrank[r][c]= (raw1+raw2)/4.0;
                          c+=1;
                    }
                    c=0;
                    r+=1;
                    }
                for(int i=0 ; i<SIZE ; ++i){
                    for(int j=0 ; j<SIZE ; ++j){
                            image[i][j]=shrank[i][j];
            }}}

        else if(choise==3){
                int r=0 , c=0 , raw1 , raw2 ,raw3;
                for(int i=0 ; i<SIZE ; i+=3){
                    for(int j=0 ; j<SIZE ; j+=3){

                        raw1=image[i][j]  +image[i][j+1]  +image[i][j+2];
                        raw2=image[i+1][j]+image[i+1][j+1]+image[i+1][j+2];
                        raw3=image[i+2][j]+image[i+2][j+1]+image[i+2][j+2];

                          shrank[r][c]= (raw1+raw2+raw3)/9.0;
                          c+=1;
                    }
                    c=0;
                    r+=1;
                    }
                for(int i=0 ; i<SIZE ; ++i){
                    for(int j=0 ; j<SIZE ; ++j){
                            image[i][j]=shrank[i][j];
            }}}

        else if (choise==4){
                int r=0 , c=0 , raw1 , raw2 , raw3 ,raw4 ;
                for(int i=0 ; i<SIZE ; i+=4){
                    for(int j=0 ; j<SIZE ; j+=4){

                        raw1=image[i][j]+image[i][j+1]+image[i][j+2]+image[i][j+3];
                        raw2=image[i+1][j]+image[i+1][j+1]+image[i+1][j+2]+image[i+1][j+3];
                        raw3=image[i+2][j]+image[i+2][j+1]+image[i+2][j+2]+image[i+2][j+3];
                        raw4=image[i+3][j]+image[i+3][j+1]+image[i+3][j+2]+image[i+3][j+3];

                        shrank[r][c]= (raw1+raw2+raw3+raw4)/16.0;
                        c+=1;
                    }
                    c=0;
                    r+=1;
                    }
                for(int i=0 ; i<SIZE ; ++i){
                    for(int j=0 ; j<SIZE ; ++j){
                            image[i][j]=shrank[i][j];
            }}}
    }
    void Miror(){
        char choise;
        cout << "Mirror (l)eft, (r)ight, (u)pper, (d)own side? ";
        cin >> choise;
        while(choise!='l' && choise!='r' && choise!='u' && choise!='d'){
            cout << "Enter 'l' or 'r' or 'u' or 'd' : ";
            cin >> choise;
        }
        if(choise=='l'){
            for(int i=0 ; i<SIZE ; ++i){
                for(int j=0 ; j<SIZE/2 ; ++j){
                    image[i][255-j]=image[i][j];
                }}}

        else if(choise=='r'){
            for(int i=0 ; i<SIZE ; ++i){
                for(int j=0 ; j<SIZE/2 ; ++j){
                    image[i][j]=image[i][255-j];
                }}}

        else if(choise=='u'){
            for(int i=0 ; i<SIZE/2 ; ++i){
                for(int j=0 ; j<SIZE ; ++j){
                    image[255-i][j]=image[i][j];
                }}}

        else if(choise=='d'){
            for(int i=0 ; i<SIZE/2 ; ++i){
                for(int j=0 ; j<SIZE ; ++j){
                    image[i][j]=image[255-i][j];
                }}}
    }
