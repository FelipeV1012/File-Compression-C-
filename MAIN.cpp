#include <iostream>

#include <fstream>

#include <string>

using namespace std;

void compressFile(const string & inputFile,
    const string & outputFile) {
    ifstream in (inputFile, ios::binary);
    ofstream out(outputFile, ios::binary);

    if (!in.is_open() || !out.is_open()) {
        cout << "Error opening files!" << endl;
        return;
    }

    char currentChar, prevChar = '\0';
    int count = 1;

    while (in.get(currentChar)) {
        if (currentChar == prevChar) {
            count++;
        } else {
            if (prevChar != '\0') {
                out.write(reinterpret_cast <
                    const char * > ( & count), sizeof(count));
                out.put(prevChar);
            }
            prevChar = currentChar;
            count = 1;
        }
    }

    if (prevChar != '\0') {
        out.write(reinterpret_cast <
            const char * > ( & count), sizeof(count));
        out.put(prevChar);
    }

    in.close();
    out.close();
    cout << "File compressed successfully." << endl;
}

void decompressFile(const string & inputFile,
    const string & outputFile) {
    ifstream in (inputFile, ios::binary);
    ofstream out(outputFile, ios::binary);

    if (!in.is_open() || !out.is_open()) {
        cout << "Error opening files!" << endl;
        return;
    }

    int count;
    char ch;

    while (in.read(reinterpret_cast < char * > ( & count), sizeof(count))) {
        in.get(ch);
        for (int i = 0; i < count; ++i) {
            out.put(ch);
        }
    }

    in.close();
    out.close();
    cout << "File decompressed successfully." << endl;
}

int main() {
    string inputFile, outputFile;
    int choice;

    cout << "1. Compress File\n2. Decompress File\nEnter your choice: ";
    cin >> choice;
    cin.ignore();

    cout << "Enter input file name: ";
    getline(cin, inputFile);
    cout << "Enter output file name: ";
    getline(cin, outputFile);

    if (choice == 1) {
        compressFile(inputFile, outputFile);
    } else if (choice == 2) {
        decompressFile(inputFile, outputFile);
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}