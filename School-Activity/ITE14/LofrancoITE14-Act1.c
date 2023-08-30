#include <stdio.h>  // C standard input/output
#include <stdlib.h> //memory allocation functions // system("cls") for clear function // exit() for exiting
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
    scanf(" %[\n]s",&tempProduct->name);
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
void deleteProduct(struct product *productList,int *numOfProducts,int index) {
    for (; index < *numOfProducts-1;index++) {
        productList[index] = productList[index+1];
    }
    for (int i = 0; i < *numOfProducts;i++) {
        productList[i].productId = i+1;
    }
    *numOfProducts -= 1;
}
void updateProduct(struct product *product){
    printf("Update Product Form:\n");
    printf("Product ID: %d\n",product->productId);
    printf("product Name: ");
    scanf(" %[^\n]s",product->name);
    printf("Quantity: ");
    scanf("%d",&product->quantity);
    getch();
}

int binarySearch(int sortedArray[],int num, int size) {
    int h,l,m;
    h = size;
    l = 0;
    m = (l + h)/2;

    int flagFound = 0;
    // scanf("%d",&num);
    while (l <= h) {
        m = (l + h)/2;
        if (sortedArray[m] == num) {
            flagFound = 1;
            break;
        }
        else if (sortedArray[m] > num) {
            h = m-1;
            // printf("%d\n",sortedArray[m]);
        }
        else {
            l = m+1;
            // printf("%d\n",sortedArray[m]);
        }
    }
    if (flagFound) {
        // printf("found at index %d\n",m);
        return 1;
    }
    else {
        // printf("Doesn't exist in array\n");
        return -1;
    }
}

void searchByID(struct product *productList, int *numOfProducts) {
    int searchID;
    int foundFlag = 0;
    int i = 0;
    printf("Enter ID: ");
    scanf("%d",&searchID);
    for (;i < *numOfProducts;i++) {
        if (productList[i].productId == searchID) {
            foundFlag = 1;
            break;
        }
    }
    if (!foundFlag) {
        printf("Not Found\n");
        getch();
    }
    else {
        printf("Found!\n");
        printf("Product Info:\n");
        printf("%20s%20s%20s\n","Product ID","Name","Quantity");
        printf("%20d%20s%20d\n",productList[i].productId,productList[i].name,productList[i].quantity);
        getch();
        int option;
        while (option != 3) {
            system("cls");
            printf("1. Delete\n");
            printf("2. Update\n");
            printf("3. Return to Menu\n");
            printf("option: ");
            scanf("%d",&option);
            switch (option) {
            case 1:
                deleteProduct(productList,numOfProducts,i);
                printInventory(productList,*numOfProducts);
                option = 3;
                break;
            case 2:
                updateProduct(&productList[i]);
                printInventory(productList,*numOfProducts);
                option = 3;
                break;
            default:
                printf("Invalid option!\n");
            }
        }
        
    }
}
//Create a  simple inventory program that small business
//Add a product list with product ID, name and quantity (5pts);
int main(void) {
    struct product productList[100];
    int numOfProducts = 0;
    int option;
    // int Searchid;
    while(1) {
        system("cls");
        printf("Simple Inventory Program\n");
        printf("1. Add a product in the Inventory\n");
        printf("2. Display all product and its information\n");
        printf("3. Search Product by ID\n");
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
            case 3:
                system("cls");
                searchByID(productList,&numOfProducts);
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
