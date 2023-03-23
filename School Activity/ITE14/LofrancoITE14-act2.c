#include <stdio.h>
#include <stdlib.h>
#include <conio.h> //getch
#include <string.h> // str functions
struct product {
    int productId;
    char name[100];
    int quantity;
};
void bubbleSort(struct product *productList,int arraysize) {
    int i, switched = 0;
    struct product temp;
    if (arraysize == 1) {
        return;
    }
    for (i = 0; i < arraysize-1; i++) {
        if (productList[i].productId > productList[i+1].productId) {
            temp = productList[i];
            productList[i] = productList[i+1];
            productList[i+1] = temp;
            switched = 1;
        }
    }
    if (switched) {
        bubbleSort(productList, arraysize);
    }
}

int binarySearch(struct product *productList,int num, int size) {
    int h,l,m;
    h = size;
    l = 0;
    m = (l + h)/2;

    int flagFound = 0;
    while (l <= h) {
        m = (l + h)/2;
        if (productList[m].productId == num) {
            flagFound = 1;
            break;
        }
        else if (productList[m].productId > num) {
            h = m-1;
        }
        else {
            l = m+1;
        }
    }
    if (flagFound) {
        return m;
    }
    else {
        return -1;
    }
}
void addInventory(struct product *productList, int *numOfProducts) {
    struct product *tempProduct;
    tempProduct = malloc(sizeof(struct product));
    printf("Adding Product Form:\n");
    printf("product ID: ");
    scanf("%d",&tempProduct->productId);
    printf("product Name: ");
    scanf(" %[^\n]s",&tempProduct->name);
    printf("Quantity: ");
    scanf(" %d",&tempProduct->quantity);
    productList[*numOfProducts] = *tempProduct;
    *numOfProducts = *numOfProducts + 1;
}
void printInventory(struct product *productList, int numOfProducts) {
    int i;
    printf("%20s%20s%20s\n","Product ID","Name","Quantity");
    for (i = 0 ; i < numOfProducts;i++) {
        printf("%20d%20s%20d\n",productList[i].productId,productList[i].name,productList[i].quantity);
    }
}
void updateOperation(struct product *productInfo) {
    system("cls");
    char nameTemp[100];
    printf("Enter new Product ID: ");
    scanf("%d",&productInfo->productId);
    printf("Enter new Product Name: ");
    scanf(" %[^\n]s",nameTemp);
    strcpy(productInfo->name,nameTemp);
    printf("Enter new Product Quantity: ");
    scanf("%d",&productInfo->quantity);
    getch();
}
// void insertOperation(struct product *productList, int *numOfProducts) {
//     int index;
//     printf("Enter an index to insert after the index: ");
//     scanf("%d", &index);
//     int searchIndex = index = binarySearch(productList,index,*numOfProducts-1);
// }
void searchById(struct product *productList, int *numOfProducts) {
    struct product *found = NULL;
    int searchId;
    int index;
    printf("Enter Product ID to Search: ");
    scanf("%d",&searchId);
    index = binarySearch(productList,searchId,*numOfProducts-1);

    if (index == -1) {
        printf("Product ID Doesn't Exist\n");
        getch();
    }
    else {
        printf("product found at index %d\n",index);
        found = &productList[index];
        printf("Product Information: \n");
        printf("Product ID: %d\n",found->productId);
        printf("Product Name: %s\n",found->name);
        printf("Product Quantity: %d\n",found->quantity);
        getch();
            // Found Logic
            int option;
            while (option != 3) {
                printf("\n");
                printf("1. Delete Product\n");
                printf("2. Update Product\n");
                printf("3. Return to Menu\n");
                printf("Enter Option: ");
                scanf("%d",&option);
                switch (option) {
                    case 1:
                        for (int i = index;i < *numOfProducts;i++) {
                            productList[i] = productList[i+1];
                        }
                        productList[*numOfProducts].productId = -1;
                        strcpy(productList[*numOfProducts].name,"");
                        productList[*numOfProducts].quantity = -1;
                        *numOfProducts = *numOfProducts-1;
                        // Updates ProductList - todo Change to sort
                        bubbleSort(productList,*numOfProducts); // sorting
                        break;
                    case 2:
                        updateOperation(found);
                        bubbleSort(productList,*numOfProducts); // sorting
                        break;
                    case 3:
                        break;
                    default:
                        printf("Invalid Input\n");
                        break;
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
    while(1) {
        system("cls");
        printf("Simple Inventory Program\n");
        printf("1. Insert a product in the Inventory\n");
        printf("2. Display all product and its information\n");
        printf("3. Search by ID\n");
        // printf("4. Insert Product\n");
        printf("Option: ");
        scanf("%d",&option);
        switch(option) {
            case 1:
                printf("Selected Option 1\n");
                system("cls");
                addInventory(productList,&numOfProducts);
                bubbleSort(productList,numOfProducts);
                getch();
                system("cls");
                break;
            case 2:
                printf("Selected Option 2\n");
                system("cls");
                printInventory(productList,numOfProducts);
                getch();
                system("cls");
                break;
            case 3:
                system("cls");
                searchById(productList, &numOfProducts);
                break;
            // case 4:
            //     break;
            case 0:
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