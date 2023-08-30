#include <stdio.h> //input and output
#include <stdlib.h> //memory allocation functions
#include <conio.h> //getch()
struct product {
    int productId;
    char name[100];
    int quantity;
};
// The Product node
struct node {
	struct product *value;
	struct node *next;
};
void insertToList(struct node **productList, struct product *productInfo) {
    struct node *newNode = malloc(sizeof(struct node));
    struct node *current = *productList;
    newNode->value = productInfo;
    if (*productList == NULL) {
        newNode->next = *productList;
        *productList = newNode;
    }
    else {
        if (current->next == NULL) {
            if (current->value->productId > newNode->value->productId) {
                newNode->next = current;
                current = newNode;
                *productList = current;
            }
            else {
                current->next = newNode;
                newNode->next = NULL;
            }
        }
        else {
            if (current->value->productId > newNode->value->productId) {
                newNode->next = current;
                *productList = newNode;
                return;
            }
            for (;
                current->next != NULL && current->next->value->productId < newNode->value->productId;
                current = current->next){}
            newNode->next = current->next;
            current->next = newNode;
        }
    }
}
void addInventoryList(struct node **productList, char *type) {
    struct product *tempProduct;
    tempProduct = malloc(sizeof(struct product));
    printf("%s Product Form:\n",type);
    printf("product ID: ");
    scanf("%d",&tempProduct->productId);
    printf("product Name: ");
    scanf(" %[^\n]s",&tempProduct->name);
    printf("Quantity: ");
    scanf(" %d",&tempProduct->quantity);
    insertToList(productList,tempProduct); 
    // *numOfProducts = *numOfProducts + 1;
}
void printInventoryList(struct node *productList) {
	if (productList != NULL) {
		printf("%20d%20s%20d\n",productList->value->productId,productList->value->name,productList->value->quantity);
		printInventoryList(productList->next);
	}
}
//Traverse by Linear
struct node *searchNode(struct node *list, int productIdS) {
    for (;list != NULL && list->value->productId != productIdS;list = list->next);
    return list;
}
struct node *deleteNode(struct node **list, int productIdS) {
    struct node *current, *previous;
    for (
        current = *list,previous = NULL;
        current != NULL;
        previous = current, current= current->next
        )
        {
            if (current->value->productId == productIdS) {
                if (previous == NULL) {
                    *list = (*list)->next;
                    return current;
                }
                else {
                    previous->next = current->next;
                    return current;
                }
            }
        }
    return NULL;
}
int main(void) {
    // struct product productList[100];
    struct node *productListNode = NULL;
    // int numOfProducts = 0; //indicator for productID
    int option; //storage for
    int search;
    struct node *productFound = NULL; //flag ifFound Product
    while(1) {
        printf("Simple Inventory Program\n");
        printf("1. Add a product in the Inventory\n");
        printf("2. Display all product and its information\n");
        printf("3. Search By ProductID\n");
        printf("4. Delete by ProductID\n");
        printf("5. Update by ProductID\n");
        printf("Option: ");
        scanf("%d",&option);
        switch(option) {
            case 1:
                printf("Selected Option 1\n");
                system("cls");
                // addInventory(productList,&numOfProducts);
                addInventoryList(&productListNode,"Adding");
                //sortList(productListNode);
                getch();
                system("cls");
                break;
            case 2:
                printf("Selected Option 2\n");
                system("cls");
                // printInventory(productList,numOfProducts);
                printf("%20s%20s%20s\n","Product ID","Name","Quantity");
                printInventoryList(productListNode);
                getch();
                system("cls");
                break;
            case 3:
               	printf("Selected Option 3\n");
               	system("cls");
               	printf("Enter productId: ");
               	scanf("%d",&search);
               	productFound = searchNode(productListNode,search);
               	if (productFound != NULL) {
               		printf("Product Found:\n");
               		printf("%20s%20s%20s\n","Product ID","Name","Quantity");
               		printf("%20d%20s%20d\n",productFound->value->productId,productFound->value->name,productFound->value->quantity);
               	}
               	else {
               		printf("ProductID doesn't exist");
               	}
               	getch();
               	system("cls");
               	break;
            case 4:
                printf("Selected Option 4\n");
                system("cls");
                printf("Enter productId to delete: ");
                scanf("%d",&search);
                productFound = deleteNode(&productListNode,search);
                if (productFound != NULL) {
                    printf("Product Found:\n");
                    printf("%20s%20s%20s\n","Product ID","Name","Quantity");
                    printf("%20d%20s%20d\n",productFound->value->productId,productFound->value->name,productFound->value->quantity);
                    printf("----Deleted!");
                    free(productFound);
                }
                else {
                    printf("ProductID doesn't exist");
                }
                getch();
                system("cls");
                break;
            case 5:
                system("cls");
                printf("Enter productId to update: ");
                scanf("%d",&search);
                productFound = deleteNode(&productListNode,search);
                if (productFound != NULL) {
                    printf("Product Found:\n");
                    printf("%20s%20s%20s\n","Product ID","Name","Quantity");
                    printf("%20d%20s%20d\n",productFound->value->productId,productFound->value->name,productFound->value->quantity);
                    addInventoryList(&productListNode,"Updating");
                }
                else {
                    printf("ProductID doesn't exist");
                }
                getch();
                system("cls");
                break;
            default:
                printf("Invalid Input\n");
                getch();
                system("cls");
                break;
        }
    }
    return 0;
}
