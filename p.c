#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum file name size
#define MAX_FILENAME 100

// Block structure representing a memory block
typedef struct Block {
    int data;              // Simulated data
    struct Block *next;    // Pointer to the next block in the file
} Block;

// File structure representing a file with a linked list of blocks
typedef struct File {
    char name[MAX_FILENAME]; // File name
    Block *head;             // Pointer to the first block of the file
    struct File *nextFile;   // Pointer to the next file
} File;

// Head pointer to keep track of files
File *fileSystem = NULL;
Block* createBlock(int data) {
    Block *newBlock = (Block*) malloc(sizeof(Block));
    newBlock->data = data;
    newBlock->next = NULL;
    return newBlock;
}
void addFile(char *fileName, int numBlocks) {
    // Check if file already exists
    File *temp = fileSystem;
    while (temp != NULL) {
        if (strcmp(temp->name, fileName) == 0) {
            printf("File with the same name already exists!\n");
            return;
        }
        temp = temp->nextFile;
    }

    // Create the new file
    File *newFile = (File*) malloc(sizeof(File));
    strcpy(newFile->name, fileName);
    newFile->head = NULL;
    newFile->nextFile = fileSystem; // Insert at the beginning
    fileSystem = newFile;

    // Add blocks to the file
    Block *lastBlock = NULL;
    for (int i = 1; i <= numBlocks; i++) {
        Block *newBlock = createBlock(i * 10); // Simulate data in block
        if (newFile->head == NULL)
            newFile->head = newBlock; // First block
        else
            lastBlock->next = newBlock; // Link the new block
        lastBlock = newBlock;
    }
    printf("File '%s' added with %d blocks.\n", fileName, numBlocks);
}
void deleteFile(char *fileName) {
    File *current = fileSystem, *prev = NULL;

    while (current != NULL && strcmp(current->name, fileName) != 0) {
        prev = current;
        current = current->nextFile;
    }

    if (current == NULL) {
        printf("File not found.\n");
        return;
    }

    if (prev == NULL)
        fileSystem = current->nextFile; // File is at head
    else
        prev->nextFile = current->nextFile;

    // Free blocks of the file
    Block *block = current->head;
    while (block != NULL) {
        Block *temp = block;
        block = block->next;
        free(temp);
    }
    free(current);
    printf("File '%s' deleted successfully.\n", fileName);
}
void displayFiles() {
    if (fileSystem == NULL) {
        printf("No files in the system.\n");
        return;
    }

    File *tempFile = fileSystem;
    while (tempFile != NULL) {
        printf("File: %s\n", tempFile->name);
        Block *tempBlock = tempFile->head;
        int blockNum = 1;
        while (tempBlock != NULL) {
            printf("  Block %d: Data = %d\n", blockNum++, tempBlock->data);
            tempBlock = tempBlock->next;
        }
        tempFile = tempFile->nextFile;
    }
}
void menu() {
    int choice, numBlocks;
    char fileName[MAX_FILENAME];

    while (1) {
        printf("\n--- File Allocation System ---\n");
        printf("1. Add File\n");
        printf("2. Delete File\n");
        printf("3. Display Files\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter file name: ");
                scanf("%s", fileName);
                printf("Enter number of blocks: ");
                scanf("%d", &numBlocks);
                addFile(fileName, numBlocks);
                break;
            case 2:
                printf("Enter file name to delete: ");
                scanf("%s", fileName);
                deleteFile(fileName);
                break;
            case 3:
                displayFiles();
                break;
            case 4:
                printf("Exiting...\n");
                return;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}
