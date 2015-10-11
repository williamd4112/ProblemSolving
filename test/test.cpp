#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]){
    
    if(argc < 2){
        cout << "Usage:./a.out [FILENAME]" << endl;
        return 0;
    }
    
    ifstream ifs(argv[1], ios::in);
    string line;
    while(getline(ifs, line) != NULL){
        stringstream ss(line);
        
        int id;
        string name;
        float score;
        
        ss >> id >> name >> score;
        cout << id << "\t" << name << "\t" << score << endl;
        
    }
    
    ifs.close();
    
    return 0;
}