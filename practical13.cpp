#include <iostream>
#include <fstream>

using namespace std;

struct Record {
    int id;
    string name;
};

const char* FILE_NAME = "records.dat";

void insertRecord(Record record) {
    fstream file(FILE_NAME, ios::out | ios::binary | ios::app);

    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    file.write(reinterpret_cast<char*>(&record), sizeof(Record));
    file.close();

    cout << "Record inserted successfully." << endl;
}

void deleteRecord(int id) {
    fstream file(FILE_NAME, ios::in | ios::binary);

    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    fstream tempFile("temp.dat", ios::out | ios::binary);

    Record record;
    bool found = false;

    while (file.read(reinterpret_cast<char*>(&record), sizeof(Record))) {
        if (record.id != id) {
            tempFile.write(reinterpret_cast<char*>(&record), sizeof(Record));
        } else {
            found = true;
        }
    }

    file.close();
    tempFile.close();

    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);

    if (found) {
        cout << "Record deleted successfully." << endl;
    } else {
        cout << "Record not found." << endl;
    }
}

int main() {
    Record record;

    // Insertion
    record.id = 1;
    record.name = "ABC";
    insertRecord(record);

    record.id = 2;
    record.name = "XYZ";
    insertRecord(record);

    // Deletion
    int recordId;
    cout << "Enter the record ID to delete: ";
    cin >> recordId;

    deleteRecord(recordId);

    return 0;
}

