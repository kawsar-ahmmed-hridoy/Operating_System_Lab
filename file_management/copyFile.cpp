#include<bits/stdc++.h>
#include<fstream>
#include<filesystem>

using namespace std;

void copyFile(string src, string dst){
    string line;
    ifstream in{src};
    ofstream out{dst};
    //ofstream out(dst,ios::app) to append

    if(in && out){
    // char ch;
    // int count = 0;
    // while (in.get(ch) && count < n) {  n=total characters
    //     out.put(ch);
    //     count++;
    // }

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

