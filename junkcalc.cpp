#include <iostream>
#include <windows.h>
#include <fstream>
#include <sstream>

using namespace std;

int space(string dir) {
    string command = "dir "+ dir +" /a /s | find \"bytes\" > temp";
    const char *comm = command.c_str();
    system(comm);
    ifstream tempfile("temp");
    string spacetext;
    int spacelines = 0;
    while (getline (tempfile, spacetext)) {
        spacelines += 1;
    }
    tempfile.close();
    int spaceline = spacelines - 1;
    spacelines = 0;
    ifstream newtempfile("temp");
    string impspacetext;
    while (getline (newtempfile, spacetext)) {
        spacelines += 1;
        if (spaceline == spacelines) {
            impspacetext = spacetext;
            break;
        }
    }
    newtempfile.close();
    system("del temp");
    string finaltext;
    for (int i=0; i< impspacetext.length(); i++) {
        if (impspacetext.at(i) == ' ' && impspacetext.at(i+1) == ' ')
            continue;
        else
            finaltext += impspacetext.at(i);
    }
    finaltext.erase(0, 1);
    string bytes;
    int count = 0;
    for (int i=0; i< finaltext.length(); i++) {
        if (count == 2) {
            bytes += finaltext.at(i);
        }
        if (finaltext.at(i) == ' ') {
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
    stringstream convert(proper_bytes);
    convert >> final_mega_bytes;
    return final_mega_bytes/1000000;
}

int main() {
    cout << "%temp% : " << space("%temp%") << " MB" <<  endl;
    cout << "prefetch : " << space("C:\\Windows\\Prefetch") << " MB" << endl;
    cout << "temp : " << space("C:\\Windows\\Temp") << " MB" << endl;
    string pause;
    cin >> pause;
}
