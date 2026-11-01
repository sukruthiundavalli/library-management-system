
#include <stdio.h>

struct Book {
    int id;
    char name[50];
    int issued;
};

int main() {
    struct Book books[100];
    int count = 0;
    int choice, id, i, found;

    do {
        printf("\n===== LIBRARY MANAGEMENT SYSTEM =====\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter Book ID: ");
                scanf("%d", &books[count].id);

                printf("Enter Book Name: ");
                scanf(" %49[^\n]", books[count].name);

                books[count].issued = 0;
                count++;

                printf("Book added successfully!\n");
                break;

            case 2:
                if (count == 0) {
                    printf("No books available.\n");
                } else {
                    for (i = 0; i < count; i++) {
                        printf("\nID: %d", books[i].id);
                        printf("\nName: %s", books[i].name);
                        printf("\nStatus: %s\n",
                            books[i].issued ? "Issued" : "Available");
                    }
                }
                break;

            case 3:
                printf("Enter Book ID to search: ");
                scanf("%d", &id);

                found = 0;

                for (i = 0; i < count; i++) {
                    if (books[i].id == id) {
                        printf("Book Found: %s\n", books[i].name);
                        found = 1;
                        break;
                    }
                }

                if (!found)
                    printf("Book not found.\n");
                break;

            case 4:
                printf("Enter Book ID to issue: ");
                scanf("%d", &id);

                found = 0;

                for (i = 0; i < count; i++) {
                    if (books[i].id == id) {
                        found = 1;

                        if (books[i].issued == 0) {
                            books[i].issued = 1;
                            printf("Book issued successfully!\n");
                        } else {
                            printf("Book is already issued.\n");
                        }
                        break;
                    }
                }

                if (!found)
                    printf("Book not found.\n");
                break;

            case 5:
                printf("Enter Book ID to return: ");
                scanf("%d", &id);

                found = 0;

                for (i = 0; i < count; i++) {
                    if (books[i].id == id) {
                        found = 1;

                        if (books[i].issued == 1) {
                            books[i].issued = 0;
                            printf("Book returned successfully!\n");
                        } else {
                            printf("Book was not issued.\n");
                        }
                        break;
                    }
                }

                if (!found)
                    printf("Book not found.\n");
                break;

            case 6:
                printf("Thank you!\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}
