#include <iostream>
using namespace std;

struct StudyRecord {
    string SubjectName;
    int minutes[5];
};

void clear(){
    for(int z=0; z<100; z++){
        cout << endl;
    }
}

int totalMinutes(const StudyRecord& r){
    int sum=0;
    for(int i=0; i<5; i++){
        sum += r.minutes[i];
    }
    return(sum);
}

double averageMinutes(const StudyRecord& r){
    return((totalMinutes(r))/5.00);
}

int totalAll(StudyRecord arr[], int size){
    int sum=0;
    for(int i=0;i<3;i++){
        for(int j=0; j<5; j++){
            sum += arr[i].minutes[j];
        }
    }
    return(sum);
}

int indexOfMax(StudyRecord arr[], int size){
    int indexOfMax = 0;
    int max = 0;
    for(int i=0; i<3; i++){
        if(totalMinutes(arr[i])>max){
            max = totalMinutes(arr[i]);
            indexOfMax = i;
        }
    }
    return(indexOfMax);
}
    
int main(){
    clear();
    int minutes;
    string subject;
    StudyRecord records[3];
    for(int i=0; i<3; i++){
        cout << "Please enter a subject:" << " (" << i+1 << "/3) " << endl;
        cin >> subject;
        records[i].SubjectName = subject;
        for(int j=0; j<5; j++){
            cout << "Please enter the amount of muinutes studied " << j+1 << " day(s) ago." << " (" << j+1 << "/5)" << endl;
            cin >> minutes;
            records[i].minutes[j] = minutes;
        }
        clear();
    }
    
    //output

    for(int i=0; i<3; i++){
        cout << records[i].SubjectName << ": ";
        for(int j=0; j<5; j++){
            cout << records[i].minutes[j] << ", ";
        }
        cout << "Total: " << totalMinutes(records[i]) << ", Avg: " << averageMinutes(records[i]) << endl;
    }
    cout << "The subject with the most minutes is " << records[indexOfMax(records,3)].SubjectName << "." << endl;
    cout << "The total time studied is " << totalAll(records,3) << " minutes." << endl;
    return(0);
}