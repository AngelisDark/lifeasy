#include <iostream>
#include <windows.h>
#include <fstream>
#include <sstream>

using namespace std;

int space(string dir) {
    string command = "dir "+ dir +" /a /s | find \"bytes\" > fuck";
    const char *comm = command.c_str();
    system(comm);
    ifstream fuckfile("fuck");
    string fucktext;
    int fucklines = 0;
    while (getline (fuckfile, fucktext)) {
        fucklines += 1;
    }
    //string fuckarray[fucklines];
    fuckfile.close();
    //cout << fucklines << endl;
    int fuckline = fucklines - 1;
    fucklines = 0;
    ifstream newfuckfile("fuck");
    string impfucktext;
    while (getline (newfuckfile, fucktext)) {
        fucklines += 1;
        //cout << fuckline << " " << fucklines << endl;
        if (fuckline == fucklines) {
            impfucktext = fucktext;
            break;
        }
    }
    newfuckfile.close();
    system("del fuck");
    //cout << impfucktext;
    string yotext;
    for (int i=0; i< impfucktext.length(); i++) {
        if (impfucktext.at(i) == ' ' && impfucktext.at(i+1) == ' ')
            continue;
        else
            yotext += impfucktext.at(i);
    }
    yotext.erase(0, 1);
    string bytes;
    int count = 0;
    for (int i=0; i< yotext.length(); i++) {
        if (count == 2) {
            bytes += yotext.at(i);
        }
        if (yotext.at(i) == ' ') {
            count += 1;
        }
        if (count == 3) {
            break;
        }
    }
    string proper_bytes;
    int final_mega_bytes;
    for (int i=0; i < bytes.length(); i++) {
        if (bytes.at(i) != ',') {
            proper_bytes += bytes.at(i);
        }
    }
    //cout << proper_bytes;
    stringstream convert(proper_bytes);
    convert >> final_mega_bytes;
    //cout << final_mega_bytes/1000000 << " MB";
    return final_mega_bytes/1000000;
}

int main() {
    cout << "%temp% : " << space("%temp%") << " MB" <<  endl;
    cout << "prefetch : " << space("C:\\Windows\\Prefetch") << " MB" << endl;
    cout << "temp : " << space("C:\\Windows\\Temp") << " MB" << endl;
    string pause;
    cin >> pause;
}