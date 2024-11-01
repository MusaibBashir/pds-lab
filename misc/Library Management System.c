#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOKS 100


struct Book {
    char title[100];
    char author[100];
    char ISBN[20];
    float price;
};

struct Library {
    struct Book books[MAX_BOOKS];
    int count;
};

int compareString(const char *str1, const char *str2) {
    while (*str1 && *str2) {
        if (*str1 != *str2)
            return 0; 
        str1++;
        str2++;
    }
    return *str1 == '\0' && *str2 == '\0';
}

void addBook(struct Library *lib) {
    if (lib->count >= MAX_BOOKS) {
        printf("Library is full. Cannot add more books.\n");
        return;
    }

    struct Book *newBook = &lib->books[lib->count];

    printf("Enter title: ");
    scanf(" %[^\n]", newBook->title);

    printf("Enter author: ");
    scanf(" %[^\n]", newBook->author);

    printf("Enter ISBN: ");
    scanf(" %[^\n]", newBook->ISBN);

    printf("Enter price: ");
    scanf("%f", &newBook->price);

    lib->count++;
    printf("Book added successfully!\n");
}


void search_ISBN(struct Library *lib) {
    char isbn[20];
    printf("Enter ISBN to search: ");
    scanf(" %[^\n]", isbn);

    for (int i = 0; i < lib->count; i++) {
        if (compareString(lib->books[i].ISBN, isbn)) {
            printf("Book found:\n");
            printf("Title: %s\n", lib->books[i].title);
            printf("Author: %s\n", lib->books[i].author);
            printf("ISBN: %s\n", lib->books[i].ISBN);
            printf("Price: $%.2f\n", lib->books[i].price);
            return;
        }
    }
    printf("Book with ISBN %s not found.\n", isbn);
}


void displayAllBooks(struct Library *lib) {
    if (lib->count == 0) {
        printf("Library is empty.\n");
        return;
    }

    printf("List of all books in the library:\n");
    for (int i = 0; i < lib->count; i++) {
        printf("\nBook %d:\n", i + 1);
        printf("Title: %s\n", lib->books[i].title);
        printf("Author: %s\n", lib->books[i].author);
        printf("ISBN: %s\n", lib->books[i].ISBN);
        printf("Price: $%.2f\n", lib->books[i].price);
    }
}

int main() {
    struct Library library = { .count = 0 };
    int choice;

    do {
        printf("\nLibrary System\n");
        printf("1. Add a new book\n");
        printf("2. Search for a book by ISBN\n");
        printf("3. Display all books\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(&library);
                break;
            case 2:
                search_ISBN(&library);
                break;
            case 3:
                displayAllBooks(&library);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
