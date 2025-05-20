#include<bits/stdc++.h>
#include<fstream>
#include<filesystem>

using namespace std;

void readFile(string fileName){

    ifstream file(fileName);

    if(file){

        string line;
        cout << "Reading file content:\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();

    } else {
        cout << "File not found!" << endl;
    }
}

int main(){
    string name;
    cout<<"To read insert file name: ";cin>>name;

    readFile(name);
}