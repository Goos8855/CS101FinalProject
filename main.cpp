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

    vector<point> points;
    int x;
    int y;
    char txt;

    
}