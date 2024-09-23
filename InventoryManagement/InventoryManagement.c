#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} InventoryItem;

InventoryItem inventory[MAX_ITEMS];
int itemCount = 0;

void addItem();
void viewItems();
void updateItem();
void deleteItem();
int findItemById(int id);

int main() {
    int choice;
    
    while (1) {
        printf("\nInventory Management System\n");
        printf("1. Add Item\n");
        printf("2. View Items\n");
        printf("3. Update Item\n");
        printf("4. Delete Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            // Clear the input buffer
            while (getchar() != '\n');
            continue;
        }
        
        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                viewItems();
                break;
            case 3:
                updateItem();
                break;
            case 4:
                deleteItem();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Inventory is full!\n");
        return;
    }
    
    InventoryItem item;
    
    printf("Enter item ID: ");
    if (scanf("%d", &item.id) != 1) {
        printf("Invalid input! Please enter a number.\n");
        // Clear the input buffer
        while (getchar() != '\n');
        return;
    }
    printf("Enter item name: ");
    if (scanf("%49s", item.name) != 1) {
        printf("Invalid input! Please enter a string.\n");
        // Clear the input buffer
        while (getchar() != '\n');
        return;
    }
    printf("Enter item quantity: ");
    if (scanf("%d", &item.quantity) != 1) {
        printf("Invalid input! Please enter a number.\n");
        // Clear the input buffer
        while (getchar() != '\n');
        return;
    }
    printf("Enter item price: ");
    if (scanf("%f", &item.price) != 1) {
        printf("Invalid input! Please enter a number.\n");
        // Clear the input buffer
        while (getchar() != '\n');
        return;
    }
    
    inventory[itemCount++] = item;
    printf("Item added successfully!\n");
}

void viewItems() {
    if (itemCount == 0) {
        printf("No items in the inventory.\n");
        return;
    
    }
    
    printf("\nInventory Items:\n");
    for (int i = 0; i < itemCount; i++) {

        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", 
               inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
      while (getchar() != '\n');
    printf("Hi");
    getchar();
}

void updateItem() {
    int id, quantity;
    float price;
    
    printf("Enter item ID to update: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid input! Please enter a number.\n");
        // Clear the input buffer
        while (getchar() != '\n');
        return;
    }
    
    int index = findItemById(id);
    if (index == -1) {
        printf("Item not found!\n");
        return;
    }
    
    printf("Enter new quantity: ");
    if (scanf("%d", &quantity) != 1) {
        printf("Invalid input! Please enter a number.\n");
        // Clear the input buffer
        while (getchar() != '\n');
        return;
    }
    printf("Enter new price: ");
    if (scanf("%f", &price) != 1) {
        printf("Invalid input! Please enter a number.\n");
        // Clear the input buffer
        while (getchar() != '\n');
        return;
    }
    
    inventory[index].quantity = quantity;
    inventory[index].price = price;
    printf("Item updated successfully!\n");
}

void deleteItem() {
    int id;
    
    printf("Enter item ID to delete: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid input! Please enter a number.\n");
        // Clear the input buffer
        while (getchar() != '\n');
        return;
    }
    
    int index = findItemById(id);
    if (index == -1) {
        printf("Item not found!\n");
        return;
    }
    
    for (int i = index; i < itemCount - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    
    itemCount--;
    printf("Item deleted successfully!\n");
}

int findItemById(int id) {
    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == id) {
            return i;
        }
    }
    return -1;
}
 