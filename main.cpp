#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>

using namespace std;

int main()
{
    fstream main_file;
    fstream image;

    int i = 0;
    char id[5] { 0,0,0,0,0 };
    sprintf(id, "%d", i);
    char byte[1] = { 0x00 };
    char jpg[4] = { 0xFF, 0xD8, 0xFF, 0xE0 };
    char jpg0[1] = { 0xFF };
    char jpg1[1] = { 0xD8 };
    char jpg2[1] = { 0xFF };
    char memo1[1] = { 0x00 };
    char memo2[1] = { 0x00 };
    char memo3[1] = { 0x00 };

    main_file.open( "imgcache.0", ios::binary | ios::in );
    if( main_file.good() == true )
    {
        cout<<"Pr0ject_img 1.0"<<endl;
        cout<<"Author: MrStPL"<<endl;
        cout<<endl;
        cout<<"imgcache.0"<<"             OK!"<<endl;
        cout<<"Press ENTER to Start..."<<endl;
        getch();
    }
    else
    {
        cout<<"Pr0ject_img 1.0"<<endl;
        cout<<"Author: MrStPL"<<endl;
        cout<<endl;
        cout<<"ERROR! imgcache.0 not found!"<<endl;
        cout<<"Press ENTER to Exit..."<<endl;
        getch();
        return 0;
    }

    system( "md pict0r ");
    string name = "pict0r\/pic";
    name = id[0] + ".jpg";

    while(!main_file.eof())
    {
        main_file.read(byte, 1);

        if(byte[0] == jpg[0] )
        {
            memo1[0] = byte[0];
            main_file.read(byte, 1);
            if( byte[0] == jpg[1] )
            {
                memo2[0] = byte[0];
                main_file.read(byte, 1);
                if( byte[0] == jpg[2] )
                {
                    memo3[0] = byte[0];
                    main_file.read(byte, 1);
                    if( byte[0] == jpg[3])
                    {
                        if(i>0)
                            cout<<name<<endl;
                        image.close();
                        i++;
                        sprintf(id, "%d", i);
                        name = "pict0r\/pic";
                        if(i<10)
                             name = name + id[0] + ".jpg";
                        else if(i<100)
                            name = name + id[0] + id[1] +".jpg";
                        else if(i<1000)
                            name = name + id[0] + id[1] + id[2] + ".jpg";
                        else if(i<10000)
                            name = name + id[0] + id[1] + id[2] + id[3] + ".jpg";
                        else if(i<100000)
                            name = name + id[0] + id[1] + id[2] + id[3] + id[4] + ".jpg";
                        else
                            cout<<"ERROR!"<<endl;
                        image.open( name.c_str(), ios::binary | ios::out );
                        image.write(jpg, 4);
                    }
                    else
                    {
                        image.write(memo1, 1); memo1[1] = { 0x00 };
                        image.write(memo2, 1); memo2[1] = { 0x00 };
                        image.write(memo3, 1); memo3[1] = { 0x00 };
                        image.write(byte, 1);
                    }
                }
                else
                {
                    image.write(memo1, 1); memo1[1] = { 0x00 };
                    image.write(memo2, 1); memo2[1] = { 0x00 };
                    image.write(byte, 1);
                }
            }
            else
            {
                image.write(memo1, 1); memo1[1] = { 0x00 };
                image.write(byte, 1);
            }
        }
        else
        {
            image.write(byte, 1);
        }
    }
    cout<<"Done."<<endl;
    cout<<endl;
    cout<<"Author: MrStPL"<<endl;
    getch();
    return 0;
}
