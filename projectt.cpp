#include <iostream>
#include <unordered_map>

using namespace std;

// Block structure represents each block with a pointer to the next block.
struct Block {
    int blockNumber;
    Block* next;
    Block(int num) : blockNumber(num), next(nullptr) {}
};

// File structure to hold file information and the starting block.
struct File {
    string fileName;
    Block* startBlock;
    File(string name) : fileName(name), startBlock(nullptr) {}
};

class FileAllocationSystem {
    unordered_map<string, File*> fileTable; // Map to store files
    bool* freeBlocks; // Array to simulate physical storage blocks
    int totalBlocks;

public:
    // Constructor to initialize the total storage size
    FileAllocationSystem(int size) : totalBlocks(size) {
        freeBlocks = new bool[totalBlocks];
        for (int i = 0; i < totalBlocks; ++i) {
            freeBlocks[i] = true; // Initially, all blocks are free
        }
    }

    // Destructor to free allocated memory
    ~FileAllocationSystem() {
        delete[] freeBlocks;
        for (auto& entry : fileTable) {
            Block* current = entry.second->startBlock;
            while (current) {
                Block* toDelete = current;
                current = current->next;
                delete toDelete;
            }
            delete entry.second;
        }
    }

    // Function to allocate blocks and create a file
    void addFile(string fileName, int fileSize) {
        if (fileTable.find(fileName) != fileTable.end()) {
            cout << "File " << fileName << " already exists!\n";
            return;
        }

        int* allocatedBlocks = new int[fileSize];
        int allocatedCount = 0;

        for (int i = 0; i < totalBlocks && allocatedCount < fileSize; ++i) {
            if (freeBlocks[i]) {
                allocatedBlocks[allocatedCount++] = i;
                freeBlocks[i] = false;
            }
        }

        if (allocatedCount < fileSize) {
            cout << "Not enough free blocks to allocate file " << fileName << "!\n";
            for (int i = 0; i < allocatedCount; ++i) freeBlocks[allocatedBlocks[i]] = true;
            delete[] allocatedBlocks;
            return;
        }

        // Create the file and link blocks
        File* newFile = new File(fileName);
        fileTable[fileName] = newFile;

        Block* head = new Block(allocatedBlocks[0]);
        newFile->startBlock = head;
        Block* current = head;
        for (int i = 1; i < fileSize; ++i) {
            current->next = new Block(allocatedBlocks[i]);
            current = current->next;
        }

        delete[] allocatedBlocks;
        cout << "File " << fileName << " created with " << fileSize << " blocks.\n";
    }

    // Display the blocks of a specified file
    void displayFile(string fileName) {
        if (fileTable.find(fileName) == fileTable.end()) {
            cout << "File " << fileName << " does not exist!\n";
            return;
        }

        cout << "Displaying blocks for file " << fileName << ": ";
        Block* current = fileTable[fileName]->startBlock;
        while (current) {
            cout << current->blockNumber << " ";
            current = current->next;
        }
        cout << "\n";
    }

    // Function to delete a file and free up the blocks
    void deleteFile(string fileName) {
        if (fileTable.find(fileName) == fileTable.end()) {
            cout << "File " << fileName << " does not exist!\n";
            return;
        }

        // Free blocks associated with the file
        Block* current = fileTable[fileName]->startBlock;
        while (current) {
            freeBlocks[current->blockNumber] = true;
            Block* toDelete = current;
            current = current->next;
            delete toDelete;
        }

        delete fileTable[fileName];
        fileTable.erase(fileName);

        cout << "File " << fileName << " deleted successfully.\n";
    }

    // Function to display all files and their blocks
    void displayAllFiles() {
        if (fileTable.empty()) {
            cout << "No files available!\n";
            return;
        }

        for (auto& entry : fileTable) {
            displayFile(entry.first);
        }
    }
};

// Main function for the menu-driven file allocation system
int main() {
    int totalBlocks;
    cout << "Enter total number of blocks in storage: ";
    cin >> totalBlocks;

    FileAllocationSystem fas(totalBlocks);
    int choice;
    do {
        cout << "\nFile Allocation Menu:\n";
        cout << "1. Add File\n2. Display File\n3. Delete File\n4. Display All Files\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        string fileName;
        int fileSize;
        switch (choice) {
            case 1:
                cout << "Enter file name: ";
                cin >> fileName;
                cout << "Enter file size (in blocks): ";
                cin >> fileSize;
                fas.addFile(fileName, fileSize);
                break;
            case 2:
                cout << "Enter file name to display: ";
                cin >> fileName;
                fas.displayFile(fileName);
                break;
            case 3:
                cout << "Enter file name to delete: ";
                cin >> fileName;
                fas.deleteFile(fileName);
                break;
            case 4:
                fas.displayAllFiles();
                break;
            case 5:
                cout << "Exiting system.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}
