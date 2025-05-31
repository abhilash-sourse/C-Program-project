#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct {
    int id;
    char title[100];
    char author[50];
    int year;
    int is_issued;  // 0 = available, 1 = issued
} Book;

Book library[MAX_BOOKS];
int book_count = 0;

void initialize_library() {
    library[0] = (Book){1, "1984", "George Orwell", 1949, 0};
    library[1] = (Book){2, "To Kill a Mockingbird", "Harper Lee", 1960, 0};
    library[2] = (Book){3, "The Great Gatsby", "F. Scott Fitzgerald", 1925, 0};
    book_count = 3;
}

void display_books() {
    if (book_count == 0) {
        printf("No books in the library currently.\n");
        return;
    }
    printf("List of Books:\n");
    for (int i = 0; i < book_count; i++) {
        printf("ID: %d | Title: %s | Author: %s | Year: %d | Status: %s\n",
            library[i].id, library[i].title, library[i].author, library[i].year,
            library[i].is_issued ? "Issued" : "Available");
    }
}

void add_book() {
    if (book_count >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }
    Book new_book;
    new_book.id = book_count + 1;

    printf("Enter Title: ");
    getchar();  // consume leftover newline
    fgets(new_book.title, sizeof(new_book.title), stdin);
    new_book.title[strcspn(new_book.title, "\n")] = 0;

    printf("Enter Author: ");
    fgets(new_book.author, sizeof(new_book.author), stdin);
    new_book.author[strcspn(new_book.author, "\n")] = 0;

    printf("Enter Year of Publication: ");
    scanf("%d", &new_book.year);

    new_book.is_issued = 0;

    library[book_count] = new_book;
    book_count++;
    printf("Book added successfully with ID %d.\n", new_book.id);
}

void view_book_details() {
    int id;
    printf("Enter Book ID to view details: ");
    scanf("%d", &id);

    for (int i = 0; i < book_count; i++) {
        if (library[i].id == id) {
            printf("Book Details:\n");
            printf("ID: %d\n", library[i].id);
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("Year: %d\n", library[i].year);
            printf("Status: %s\n", library[i].is_issued ? "Issued" : "Available");
            return;
        }
    }
    printf("Book with ID %d not found.\n", id);
}

void issue_book() {
    int id;
    printf("Enter Book ID to issue: ");
    scanf("%d", &id);

    for (int i = 0; i < book_count; i++) {
        if (library[i].id == id) {
            if (library[i].is_issued) {
                printf("Book ID %d is already issued.\n", id);
            } else {
                library[i].is_issued = 1;
                printf("Book ID %d issued successfully.\n", id);
            }
            return;
        }
    }
    printf("Book with ID %d not found.\n", id);
}

void return_book() {
    int id;
    printf("Enter Book ID to return: ");
    scanf("%d", &id);

    for (int i = 0; i < book_count; i++) {
        if (library[i].id == id) {
            if (!library[i].is_issued) {
                printf("Book ID %d is not issued.\n", id);
            } else {
                library[i].is_issued = 0;
                printf("Book ID %d returned successfully.\n", id);
            }
            return;
        }
    }
    printf("Book with ID %d not found.\n", id);
}

int main() {
    int choice;
    initialize_library();

    do {
        printf("\nLibrary Management System\n");
        printf("1. Display All Books\n");
        printf("2. Add New Book\n");
        printf("3. View Book Details\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                display_books();
                break;
            case 2:
                add_book();
                break;
            case 3:
                view_book_details();
                break;
            case 4:
                issue_book();
                break;
            case 5:
                return_book();
                break;
            case 6:
                printf("Exiting Library Management System.\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while(choice != 6);

    return 0;
}