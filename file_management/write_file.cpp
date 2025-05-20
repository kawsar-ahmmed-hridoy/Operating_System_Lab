#include<bits/stdc++.h>
#include<fstream>
#include<filesystem>

using namespace std;

void writeFile(string fileName, string data){

    ofstream file;
    file.open(fileName);
    if(file){
        file << data;
        cout << "Successfuly write!" << endl;
        file.close();
    }
    else{
        cout << "File not found!" << endl;
    }

}
int main(){
    string name,data;
    cout<<"File name: ";cin>>name;
    cout<<"Input data: ";cin>>data;
    writeFile(name, data);
}