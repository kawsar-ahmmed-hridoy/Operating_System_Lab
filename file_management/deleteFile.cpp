#include<bits/stdc++.h>
#include<fstream>
#include<filesystem>

using namespace std;

void deleteFile(string fileName)
{
    if(remove(fileName.c_str()) == 0){
        cout << "File deleted Successfully!" << endl;
    }
    else{
        cout << "Failed to delete file!" << endl;
    }
}

int main(){
    string name;
    cout<<"Enter file name you want to delete: "; cin>>name;
    deleteFile(name);
}

