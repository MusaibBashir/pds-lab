/*Name= Musaib Bin Bashir
Roll No.= 24IM10047
Group No.= 1
PC No= 81
Description= "PDS Lab Section 04, Assignment 10"*/

#include<stdio.h>
#include <string.h>

struct Product  //Create the structure for our products
{
    int ID;
    char name[20];
    float price;
    int quantity;
};

struct Inventory  //This acts like a structure of array with a count variable, it contains all the different products
{
    struct Product prod[10];
    int count;
};

void addProduct(struct Inventory *invt)
{
    if(invt->count>=10) //equality because count starts from 0, so count=9 means 10 elements
    {
        printf("Inventory full, Product can't be added"); //as specified in question, we limit inventory size to 10 products(each product can have much higher quantity).
        return;
    }
    struct Product *newProd=&invt->prod[invt->count];//I have created a new pointer so that I don't have to write this much long address again and again for multiple scanfs;

    printf("Enter Product ID: ");//taking input
    scanf("%d", &newProd->ID);
    printf("Enter name: ");
    scanf("%s", newProd->name);
    printf("Enter price: ");
    scanf("%f", &newProd->price);
    printf("Enter quantity: ");
    scanf("%d", &newProd->quantity);

    invt->count++;//we also increase the count, so that next element adds in array accordingly
    printf("Product added successfully!\n");
};

void updateProduct(struct Inventory *invt, int target)
{
    int ch,ns;
    float np;
    for(int i=0; i<invt->count; i++)
    {
        if(invt->prod[i].ID==target)
        {
            struct Product *updprod=&invt->prod[i];//same reason as before, to shorten the lines.
            do
            {
                printf("1.Update Price of Product\n");//menu is provided so that price and product can be changed accordingly, and a do-while loop is implemented so that it can be updated until the user wants
                printf("2.Update Quantity of Product\n");
                printf("3.Back to Main Menu\n");
                scanf("%d",&ch);
                switch(ch) //switch-case for menu
                {
                case 1:
                    printf("Enter New Price: ");
                    scanf("%f",&np);
                    updprod->price=np;//updating price
                    break;

                case 2:
                    printf("Enter New Quantity: ");
                    scanf("%d",&ns);
                    updprod->quantity=ns;//updating quantity
                    break;
                case 3:
                    return;
                default:
                    printf("Invalid Option, Try again ");
                }
            }
            while(ch!=3);

        }
    }
    printf("Product with %d ID could not be found\n",target);//We've not used any condition here because we've used a return above, if element has been found, this piece of code will not be reached.
}

void deleteProduct(struct Inventory *invt, int target)
{
    for(int i=0; i<invt->count; i++)
    {
        if(invt->prod[i].ID==target) //search for the product using ID
        {
            for(int j=i; j<(invt->count)-1; j++) //shift the products next to the element to be deleted leftwards
            {
                invt->prod[j].ID=invt->prod[j+1].ID;
                strcpy(invt->prod[j].name,invt->prod[j+1].name);
                invt->prod[j].price=invt->prod[j+1].price;
                invt->prod[j].quantity=invt->prod[j+1].quantity;
            }
            invt->count--;//decrease the count of products in inventory
            printf("Product Removed Successfully");
            return;

        }
    }
    printf("Product with %d ID could not be found\n",target);//in case element is not found. here also we've used return above so no condition is needed for this printf
}

void displayProducts(struct Inventory *invt)
{
    if(invt->count==0)
    {
        printf("Inventory is empty\n");//in case our inventory doesn't have any element(either no element has been added, or elements have been deleted, or everything sold out)
        return;
    }
    printf("\nList of all items in inventory:\n");
    for(int i=0; i<invt->count; i++) //iterate over all items in inventory
    {
        printf("\nProduct %d:\n",i+1);
        printf("ID: %d\n", invt->prod[i].ID);
        printf("Name: %s\n", invt->prod[i].name);
        printf("Price: %f\n", invt->prod[i].price);
        printf("Quantity: %d\n", invt->prod[i].quantity);
    }
}

void generateBill(struct Inventory *invt)
{
    int no_of_prod,id,quant,found,quant_found;
    float total;
    printf("\nEnter total products for billing (<10): ");//ask for the no. of products
    scanf("%d",&no_of_prod);
    for(; no_of_prod>0; no_of_prod--) //since no_of_prod has already been initialised , we leave the first part of for statement empty
    {
        found=0;
        printf("Enter ID of product: ");//taking ID
        scanf("%d",&id);
        for(int i=0; i<invt->count; i++)
        {
            if(invt->prod[i].ID==id) //search for ID
            {
                found=1;//update the flag
                do //a do-while loop has been implemented for the case when entered quantity is more then quantity in inventory, user can decrease quantity
                {
                    printf("Enter quantity of product needed: ");
                    scanf("%d",&quant);//taking quantity
                    if(quant>invt->prod[i].quantity) //in case entered quantity is more then quantity of product available in inventory
                    {
                        quant_found=0;//quantity flag changed to 0
                        printf("Entered Quantity is more then Inventory stock\n");
                    }
                    else //if entered quantity is available in inventory
                    {
                        quant_found=1;//update the quantity flag
                        total+=(invt->prod[i].price)*quant;//add the price*quantity to total
                        invt->prod[i].quantity-=quant;//decrease the quantity of the product in inventory
                    }
                }
                while(quant_found==0);
                break;//if product ID has been found, then don't look ahead, skip to next product ID
            }
            if(!found)//here since we haven't used return above(because here we've to run this loop multiple times), we have to use flag
                printf("Product with %d ID not found\n",id);
        }
    }
    if(total>0)//if total=0, means no product has been bought(the case when no ID matches)
        printf("Total Bill for selected items= Rs.%f\n", total);
}

int main()
{
    struct Inventory inventory= {.count=0}; // initialising the inventory(which itself initialises the product structure) and keeping count=0;
    int choice,target;

    do // a do-while loop to make the menu
    {
        printf("-----------MAIN MENU-----------\n");
        printf("\nStore Management System\n");
        printf("1.Add a new product \n");
        printf("2.Update an existing product \n");
        printf("3.Delete a product \n");
        printf("4.Display all products \n");
        printf("5.Generate a bill \n");
        printf("6.Exit the program \n");
        printf("-------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            addProduct(&inventory);
            break;
        case 2:
            printf("Enter ID of the product to be updated: ");
            scanf("%d",&target);
            updateProduct(&inventory, target);
            break;
        case 3:
            printf("Enter ID of the product to be deleted: ");
            scanf("%d",&target);
            deleteProduct(&inventory, target);
            break;
        case 4:
            displayProducts(&inventory);
            break;
        case 5:
            generateBill(&inventory);
            break;
        case 6:
            break;
        default:
            printf("Invalid choice, Try again\n");
        }
    }
    while(choice!=6);

    return 0;
}
