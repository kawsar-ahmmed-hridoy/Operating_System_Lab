#include<bits/stdc++.h>
#include<fstream>
#include<filesystem>

using namespace std;

void copyFile(string src, string dst){

    string line;
    ifstream in {src};
    ofstream out {dst};

    if(in && out){
        while(getline(in, line)){
            out << line << "\n";
        }

        cout << "Successfully copied!" << endl;
    }
    else {
        cout << "Failed to copy file!" << endl;
    }
}

int main(){
    string src, dst;
    cout<<"Enter source file name: "; cin>>src;
    cout<<"Enter destination file name: "; cin>>dst;
    copyFile(src, dst);
}

