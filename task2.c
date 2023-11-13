#include <stdio.h>
#include <string.h>

#define MAX_USERS 100

struct User {
    char username[20];
    char password[20];
    int isActive;
};

struct User users[MAX_USERS];
int userCount = 0;

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("Registration limit reached. Cannot register new users.\n");
        return;
    }
    
    struct User newUser;
    printf("Enter username: ");
    scanf("%s", newUser.username);
    
    printf("Enter password: ");
    scanf("%s", newUser.password);
    
    newUser.isActive = 1;

    users[userCount] = newUser;
    userCount++;
    
    printf("Registration successful. Please login to continue.\n");
}

int loginUser() {
    char username[20];
    char password[20];
    
    printf("Enter username: ");
    scanf("%s", username);
    
    printf("Enter password: ");
    scanf("%s", password);
    
    for (int i = 0; i < userCount; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            if (users[i].isActive) {
                printf("Login successful. Welcome, %s!\n", users[i].username);
                return 1;
            } else {
                printf("Your account has been deactivated. Please contact support for assistance.\n");
                return 0;
            }
        }
    }
    
    printf("Invalid username or password. Please try again.\n");
    return 0;
}

int main() {
    int choice;
    int loggedIn = 0;
    
    do {
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                if (!loggedIn) {
                    loggedIn = loginUser();
                } else {
                    printf("You are already logged in. Please log out first.\n");
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);
    
    return 0;
}