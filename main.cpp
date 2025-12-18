#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct point{ //Organize our points into a vector list of points
    int x;
    int y;
    char txt;
};

int main(){
    ifstream file("data.txt");
    if(!file){ //Check if the file actually opens first
        cout << "File couldn't open" << endl;
        return 1;
    }

    vector<point> points; //Initializing all our variables and lists
    int x;
    int y;
    char txt;
    string line;
    int i = 0;
    point temp;

    getline(file, line); //Skip first 3 lines since it's just the instructions
    getline(file, line);
    getline(file, line);

    while(true){
        point p;
        if(!getline(file,line)){ //Filter out end of file and empty lines before reading x
            break;
        }
        if(line == ""){
            continue;
        }
        p.x = stoi(line); //stoi is the getline equivalent which converts the str in the txt file to int for our program

        if(!getline(file,line)){ //Filter out end of file and empty lines before reading x
            break;
        }
        if(line == ""){
            continue;
        }
        p.txt = line[0]; //No need to use stoi since we just need the character anyways

        if(!getline(file,line)){ //Filter out end of file and empty lines before reading x
            break;
        }
        if(line == ""){
            continue;
        }
        p.y = stoi(line); 

        points.push_back(p); //Adds the values to the vector

    }

    int maxx = 0;
    int maxy = 0;
    for(int i=0; i<points.size(); i++){ //Loop through the list and check for max x and y for the entire list
        if(points[i].x > maxx){
            maxx = points[i].x;
        }
        if(points[i].y > maxy){
            maxy = points[i].y;
        }

    }

    char print[maxx][maxy];

    for(int i=0; i<points.size(); i++){ //Moving all the values from the struct into a 2d array
        print[points[i].x][points[i].y] = points[i].txt;
    }

    for(int y=0; y<maxy; y++){
        for(int x=0; x<maxx; x++){
            cout << print[x][y];
        }
        cout << endl;
    }

}