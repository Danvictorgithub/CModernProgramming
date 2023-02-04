#include <stdio.h>
#include <string.h>
#define BUFFERSIZE 100
struct query {
	int CustomerID;
	char Items_Bought[100];
	float total;
}querylist[7];

struct Product {
	char ProductID[BUFFERSIZE];
	char ProductDescription[100];
	float price;
	int times_bought;
	int CustomerIDs[10];
	int noCustomer;
}Productlist[13];
void split(char *string) {

}
int main(void) {
	char key[BUFFERSIZE];
	int i = 0;
	FILE *RegularCustomerDatabase = fopen("RegularCustomer.txt","r");
	FILE *ProductDatabase = fopen("Prod_list.txt","r");
	FILE *LogDatabase = fopen("Invoice_Logs_011622.txt","r");
	FILE *result = fopen("product_report_011622.txt","w");
	// fscanf(ProductDatabase,"%s %s %s",key, key,key);
	while(fscanf(ProductDatabase,"%s %s %f",Productlist[i].ProductID, Productlist[i].ProductDescription, &Productlist[i].price)!= EOF) {
		Productlist[i].times_bought = 0;
		Productlist[i].noCustomer = 0;
		// Productlist[i].CustomerIDs[0] = 1;
		// Productlist[i].CustomerIDs[1] = 1;
		// Productlist[i].noCustomer += 1;
		i++;
	}
	i=0;
	while(fscanf(LogDatabase,"%d %s %f",&querylist[i].CustomerID,querylist[i].Items_Bought,&querylist[i].total)!= EOF) {
		i++;
	}
	for (i = 0; i < 7;i++) {
		for (int j = 0; j < 13;j++) {
			if (strcmp(querylist[i].Items_Bought,Productlist[j].ProductID) == 0) {
				Productlist[j].times_bought++;
				Productlist[j].CustomerIDs[Productlist[j].noCustomer++] = querylist[i].CustomerID;
			}
		}
	}
	printf("%s\t\t%s\t%s\t%s\t","Prod_ID", "Prod_Desc", "#_of_times_bought","Cust_ID");
	for (i =0; i < 12;i++) {
		printf("\n%s\t\t",Productlist[i].ProductID);
		printf("%.15s\t\t\t",Productlist[i].ProductDescription);
		printf("%d\t",Productlist[i].times_bought);
		for (int j = 0;j < Productlist[i].noCustomer;j++) {
				printf("%d",Productlist[i].CustomerIDs[j]);
		}
	}

	// Saving
	fprintf(result,"%s\t\t%s\t%s\t%s\t","Prod_ID", "Prod_Desc", "#_of_times_bought","Cust_ID");
	for (i =0; i < 12;i++) {
		fprintf(result,"\n%s\t\t",Productlist[i].ProductID);
		fprintf(result,"%.15s\t\t\t",Productlist[i].ProductDescription);
		fprintf(result,"%d\t",Productlist[i].times_bought);
		for (int j = 0;j < Productlist[i].noCustomer;j++) {
				fprintf(result,"%d",Productlist[i].CustomerIDs[j]);
		}
	}
	// fscanf(LogDatabase,"%d %s %f",&querylist[0].CustomerID,querylist[0].Items_Bought,&querylist[0].total);
	// fscanf(LogDatabase,"%d",querylist[0].CustomerID);

	// printf("%d",Productlist[0].times_bought);


	return 0;
}