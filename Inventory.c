//This is a simple Inventory Management System Program
//Functionalities include: 1. Adding Products, 2. Deleting Products, 3. Searching Product
                        // 4. Viewing the inventory, 5. Exiting the Program
//Author: Ali Ahmad

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
struct product {
    int productid;
    char name[50];
    int quantity;
    float price;
} p[50];

void addProduct(struct product p[], int *numProducts) {
    struct product newProduct;

    printf("Enter product ID: ");
    scanf("%d", &newProduct.productid);
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter price: ");
    scanf("%f", &newProduct.price);

    p[*numProducts] = newProduct;
    (*numProducts)++;
}
void display(struct product p[], int numProduct){
    printf(" ***** INVENTORY *****\n");
    printf("------------------------------------------------------------------\n");
    printf("S.N.| NAME | ID | QUANTITY | PRICE \n");
    printf("------------------------------------------------------------------\n");
    for(int i=0;i<numProduct;i++)
        printf("%d %s %d %d %f\n",i+1,p[i].name,p[i].productid,p[i].quantity,p[i].price);
    printf("------------------------------------------------------------------\n");
}
void deleteProduct(int pid) {
    int i, found = 0, numProducts=5;
    for (i = 0; i < numProducts; i++){
        if (p[i].productid == pid) {
            found = 1;
            // Shift elements to fill the gap
            for (int j = i; j <= numProducts - 1; j++) {
                p[j] = p[j + 1];
            }
            numProducts--;
            printf("Product deleted successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Product with ID %d not found.\n", pid);
    }
}

// Function to search for a product by name
void searchProductByName(struct product p[], int numProducts) {
    int i, found = 0;
    char Name[50];
    printf("Enter the name of the product to search: ");
    scanf("%s", Name);
    for (i = 0; i < numProducts; i++) {
        if (strcmp(p[i].name, Name) == 0) {
            found = 1;
            printf("Product found - ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", p[i].productid, p[i].name, p[i].quantity, p[i].price);
        }
    }
    if (!found) {
        printf("Product with name '%s' not found.\n", Name);
    }
}
int main() {
    int i;
    int numProducts=0;


    int ch;
    while(1){printf("<== Inventory Management System ==>\n");
        printf("1.Add Product\n");
        printf("2.Delete Product\n");
        printf("3.Search Product by Name\n");
        printf("4.Display Inventory\n");
        printf("0.Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        if(ch==1){
            addProduct(p, &numProducts);
        }
        else if(ch==2){
            int pid;
            printf("Enter the ID of the product you want to delete: ");
            scanf("%d",&pid);
            deleteProduct(pid);
        }
        else if(ch==3){

            searchProductByName(p,numProducts);
        }
        else if(ch ==4){
            display(p,numProducts);
        }
        else if(ch==0){
            exit(0);
        }
        else{
            printf("Invalid choice entered. Sorry.");
        }
        printf("Press Any Key To Continue...");
        getch();
    }
    return 0;
}