#include <iostream>
#include <cstring>
using namespace std;
int map[11][15]=
{
    {1,1,1,1,1,1,1,1,1,1,1,1,1,2,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,1,1,0,0,1},
    {1,1,0,1,0,0,0,1,0,1,1,0,0,0,1},
    {1,0,0,1,1,1,0,1,0,1,0,0,1,0,1},
    {1,0,1,1,1,0,0,1,1,1,1,1,1,0,1},
    {1,0,1,0,0,0,1,1,0,1,0,0,0,0,1},
    {1,1,1,0,1,1,1,0,0,1,0,1,1,1,1},
    {1,0,1,0,1,0,1,1,0,0,0,1,0,0,1},
    {1,0,0,0,0,0,0,0,0,1,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};
int pozx=1,pozy=8, direction=180;
//Legend
//0 = walkable space
//1 = wall
//2 = exit

//Graphics
char hall[]="\t1#####1\n\t#1###1#\n\t##   ##\n\ti#   #i\n\t##   ##\n\t#1###1#\n\t1#####1\n";
char wall[]="\t#######\n\t#######\n\t#######\n\t#i###i#\n\t#######\n\t#######\n\t#######\n";

int main()
{
    char input[1];
    cout<<"Welcome to the dungeon! Try to escape!"<<endl;
    cout<<"Controals: W, A, S, D"<<endl;
    cout<<"W = Go forward"<<endl;
    cout<<"S = Go backwards"<<endl;
    cout<<"A = Turn to the left"<<endl;
    cout<<"D = Turn to the right"<<endl;
    while(1)
    {
        //Determine the direction the player is facing
        if(direction==0)
            if(map[pozy-1][pozx]==1)cout<<wall;
            else cout<<hall;
        else if(direction==90)
            if(map[pozy][pozx+1]==1)cout<<wall;
            else cout<<hall;
        else if(direction==180)
            if(map[pozy+1][pozx]==1)cout<<wall;
            else cout<<hall;
        else if(direction==-90)
            if(map[pozy][pozx-1]==1)cout<<wall;
            else cout<<hall;
        cout<<"What are you going to do? ";cin>>input;
        //Reading input and changing the position
        if(strcmp("w",input)==0 || strcmp("W",input)==0)
            {
                if(direction==0 && map[pozy-1][pozx]==0)
                {
                    pozy-=1;
                }
                else if(direction==90 && map[pozy][pozx+1]==0)
                {
                    pozx+=1;
                }
                else if(direction==-90 && map[pozy][pozx-1]==0)
                {
                    pozx-=1;
                }
                else if(direction==180 && map[pozy+1][pozx]==0)
                {
                    pozy+=1;
                }

                // Special case when close to exit
                if(direction==0 && map[pozy-1][pozx]==2)
                {
                    cout<<"Congratulations! You escaped!";
                    return 0;
                }
                else if(direction==90 && map[pozy][pozx+1]==2)
                {
                    cout<<"Congratulations! You escaped!";
                    return 0;
                }
                else if(direction==-90 && map[pozy][pozx-1]==2)
                {
                    cout<<"Congratulations! You escaped!";
                    return 0;
                }
                else if(direction==180 && map[pozy+1][pozx]==2)
                {
                    cout<<"Congratulations! You escaped!";
                    return 0;
                }
            }
        else if (strcmp("s",input)==0 || strcmp("S",input)==0)
            {
                if(direction==0 && map[pozy+1][pozx]==0)
                {
                    pozy+=1;
                }
                else if(direction==90 && map[pozy][pozx-1]==0)
                {
                    pozx-=1;
                }
                else if(direction==-90 && map[pozy][pozx+1]==0)
                {
                    pozx+=1;
                }
                else if(direction==180 && map[pozy-1][pozx]==0)
                {
                    pozy-=1;
                }

                // Special case when close to exit
                if(direction==0 && map[pozy+1][pozx]==2)
                {
                    cout<<"Congratulations! You escaped!";
                    return 0;
                }
                else if(direction==90 && map[pozy][pozx-1]==2)
                {
                    cout<<"Congratulations! You escaped!";
                    return 0;
                }
                else if(direction==-90 && map[pozy][pozx+1]==2)
                {
                    cout<<"Congratulations! You escaped!";
                    return 0;
                }
                else if(direction==180 && map[pozy-1][pozx]==2)
                {
                    cout<<"Congratulations! You escaped!";
                    return 0;
                }
            }
        else if (strcmp("a",input)==0 || strcmp("A",input)==0)
            direction-=90;
        else if (strcmp("d",input)==0 || strcmp("D",input)==0)
            direction+=90;
        else cout<<"Invalid command."<<endl;
        if(direction==-180)direction=180;
        if(direction==270)direction=-90;
        if(direction==360)direction=0;
    }
    return 0;
}