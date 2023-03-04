#include <stdio.h> 
#include <stdlib.h> //memory allocation functions // system("cls") for clear function
#include <conio.h> //getch()

struct product {
    int productId;
    char name[100];
    int quantity;
};
void addInventory(struct product *productList, int *numOfProducts) {
    // Creates A struct product with different memory
    struct product *tempProduct;
    tempProduct = malloc(sizeof(struct product));
    // productID is automatic
    printf("Adding Product Form:\n");
    printf("product ID: %d\n",*numOfProducts + 1);
    tempProduct->productId = *numOfProducts + 1;

    printf("product Name: ");
    scanf(" %[^\n]s",&tempProduct->name);
    printf("Quantity: ");
    scanf(" %d",&tempProduct->quantity);
    productList[*numOfProducts] = *tempProduct;
    // numOfProducts is passed by reference so it can be reused on other functions
    *numOfProducts = *numOfProducts + 1;
}
void printInventory(struct product *productList, int numOfProducts) {
    // Printing is Table Driven Format
    int i;
    printf("%20s%20s%20s\n","Product ID","Name","Quantity");
    for (i = 0 ; i < numOfProducts;i++) {
        printf("%20d%20s%20d\n",productList[i].productId,productList[i].name,productList[i].quantity);
    }

}
//Create a  simple inventory program that small business
//Add a product list with product ID, name and quantity (5pts);
int main(void) {
    struct product productList[100];
    int numOfProducts = 0;
    int option;
    while(1) {
        printf("Simple Inventory Program\n");
        printf("1. Add a product in the Inventory\n");
        printf("2. Display all product and its information\n");
        printf("0. To exit\n");
        printf("Option: ");
        scanf("%d",&option);
        switch(option) {
            case 1:
                system("cls"); // to clear terminal
                addInventory(productList,&numOfProducts);
                getch();
                system("cls");
                break;
            case 2:
                system("cls");
                printInventory(productList,numOfProducts);
                getch();
                system("cls");
                break;
            case 0:
                printf("Exiting....");
                getch();
                exit(0);
            default:
                printf("Invalid Input\n");
                getch();
                system("cls");
                break;
        }
    }
    return 0;
}

