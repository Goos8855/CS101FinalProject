#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct point{ //Organize our points into a vector list of points
    int x;
    int y;
    char txt;
};

int main(){
    cout << "Started" << endl;
    ifstream file("data.txt");
    if(!file){ //Check if the file actually opens first
        cout << "File couldn't open" << endl;
        return -1;
    }

    vector<point> points; //Initializing all our variables and lists
    int x;
    int y;
    char txt;
    string line;
    int i = 0;
    point temp;
    cout << "Init" << endl;

    while(getline(file, line)){
        if(line.empty()) continue;
        stringstream ss(line);
        point p{};
        string mid;

        ss>>p.x;
        ss>>mid;
        ss>>p.y;

        p.txt = mid.empty() ? ' ' : mid[0];
        
        points.push_back(p);
    }    

    cout << "Fetched" << endl;
    cout << points.size() << endl;

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

    
    cout << "Max-x: " << maxx << ", Max-y: " << maxy << endl;

    vector<vector<char>> print(maxy+1, vector<char>(maxx+1, ' '));

    for(int i=0; i<points.size(); i++){ //Moving all the values from the struct into a 2d array
        print[points[i].y][points[i].x] = points[i].txt;
    }

    for(int y=0; y<=maxy; y++){
        for(int x=0; x<=maxx; x++){
            cout << print[y][x];
        }
        cout << endl;
        
    }

    cout << "Printed" << endl;
    return 0;
}