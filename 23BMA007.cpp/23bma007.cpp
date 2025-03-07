
// NAMES AND ROLLNO. OF STUDENTS:
// ANISH - 23BMA007
// ANSHI JAIN - 23BMA008
// ARCHISMAN - 23BMA009
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Define a single block in the file
struct FileBlock {
    int blockNum;
    string data;
    FileBlock* next;
    
    FileBlock(int num, string content) : blockNum(num), data(content), next(nullptr) {}
};

// Define a file structure with a linked list of blocks
struct File {
    string fileName;
    FileBlock* head;
    
    File(string name) : fileName(name), head(nullptr) {}
};

// File system class
class FileSystem {
private:
    unordered_map<string, File*> files;  // Map to store files by name
    int blockCounter = 0;  // Unique identifier for each block
    
public:
    // Function to create a file and allocate blocks
    void createFile(string fileName, string content, int blockSize) {
        if (files.find(fileName) != files.end()) {
            cout << "File already exists.\n";
            return;
        }
        
        File* newFile = new File(fileName);
        FileBlock* current = nullptr;
        
        // Split content into blocks
        for (size_t i = 0; i < content.size(); i += blockSize) {
            string blockData = content.substr(i, blockSize);
            FileBlock* block = new FileBlock(blockCounter++, blockData);
            
            if (newFile->head == nullptr) {
                newFile->head = block;
            } else {
                current->next = block;
            }
            current = block;
        }
        
        files[fileName] = newFile;
        cout << "File created successfully.\n";
    }
    
    // Function to read a file by traversing through its blocks
    void readFile(string fileName) {
        if (files.find(fileName) == files.end()) {
            cout << "File not found.\n";
            return;
        }
        
        FileBlock* current = files[fileName]->head;
        cout << "Reading file '" << fileName << "':\n";
        
        while (current) {
            cout << "Block " << current->blockNum << ": " << current->data << endl;
            current = current->next;
        }
    }
    
    // Function to delete a file and release its blocks
    void deleteFile(string fileName) {
        if (files.find(fileName) == files.end()) {
            cout << "File not found.\n";
            return;
        }
        
        FileBlock* current = files[fileName]->head;
        while (current) {
            FileBlock* temp = current;
            current = current->next;
            delete temp;
        }
        
        delete files[fileName];
        files.erase(fileName);
        cout << "File deleted successfully.\n";
    }
    
    // User menu
    void menu() {
        int choice;
        do {
            cout << "\nFile Allocation System Menu:\n";
            cout << "1. Create File\n";
            cout << "2. Read File\n";
            cout << "3. Delete File\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;
            
            switch (choice) {
                case 1: {
                    string fileName, content;
                    int blockSize;
                    cout << "Enter file name: ";
                    cin >> fileName;
                    cout << "Enter file content: ";
                    cin.ignore();
                    getline(cin, content);
                    cout << "Enter block size: ";
                    cin >> blockSize;
                    createFile(fileName, content, blockSize);
                    break;
                }
                case 2: {
                    string fileName;
                    cout << "Enter file name to read: ";
                    cin >> fileName;
                    readFile(fileName);
                    break;
                }
                case 3: {
                    string fileName;
                    cout << "Enter file name to delete: ";
                    cin >> fileName;
                    deleteFile(fileName);
                    break;
                }
                case 4:
                    cout << "Exiting system.\n";
                    break;
                default:
                    cout << "Invalid choice. Try again.\n";
            }
        } while (choice != 4);
    }
};

// Main function
int main() {
    FileSystem fs;
    fs.menu();
    return 0;
}
