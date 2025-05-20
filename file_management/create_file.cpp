#include<bits/stdc++.h>
#include<fstream>
#include<filesystem>

using namespace std;

void createFile(string fileName)
{
    ofstream file;
    file.open(fileName);

    if(file){
        cout << "File created successfully!" << endl;
        file.close();
    }
    else{
        cout << "Failed to create file!" << endl;
    }
}
int main(){

    string s;
    cin>>s;
    createFile(s);

}
