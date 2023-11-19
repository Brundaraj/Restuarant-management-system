#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct items{
    char item [20];
    float price;
    int qty;
};

struct orders{
    char costumer[50];
    char date[50];
    int numofitems;
    struct items itm[50];
};

//functions to generate bills
void generateBillHeader(char name[50],char date[30])
{
    printf("\n\n");
        printf("\t          B2A RESTURANT");
        printf("\n\t        ----------------- ");
        printf("\nDate:%s", date);
        printf("\nInvoice To:%s",name);
        printf("\n");
        printf("------------------------------------\n");
        printf("Items\t\t");
        printf("Qty\t\t");
        printf("Total\t\t");
        printf("\n------------------------------------");
        printf("\n\n");
}
void generateBillBody(char item[30],int qty, float price)
{
    printf("%s\t\t",item);
        printf("%d\t\t",qty);
        printf("%.2f\t\t",qty*price);
        printf("\n");
}

void generateBillFooter(float total)
{
    printf("\n");
    float dis = 0.1 *total;
    float netTotal=total-dis;
    float cgst=0.09*netTotal, grandTotal=netTotal + 2*cgst;
    printf("---------------------------------------------\n");
    printf("subTotal\t\t\t%.2f",total);
    printf("\nDiscount @10%s\t\t\t%.2f","%",dis);
    printf("\n\t\t\t\t----------------");
    printf("\nNet Total\t\t\t%.2f",netTotal);
    printf("\nCGST @9%s\t\t\t%.2f","%",cgst);
    printf("\nSGST @9%s\t\t\t%.2f","%",cgst);
    printf("\n--------------------------------------------");
    printf("\nGrand Total\t\t\t%.2f",grandTotal);
    printf("\n--------------------------------------------\n");
}
int main()
{ 
    float total;

    int opt,n;
    struct orders ord;
    struct orders order;
    char saveBill='y', contFlag="y";
    char name[50];
    FILE*fp;
    //dashboard

    while(contFlag=='y'){
    float total=0;
    int invoiceFound = 0;
    printf("\t=================B2A RESTUARANT===============");
    print("\n\npls select your prefered operation");
    printf("\n\n1.Genrate Invoice");
    printf("\n2.Show all Invoice");
    printf("\n3.search Invoice");
    printf("\n4.exit");

    printf("\n\n your choice:\t");
    scanf("%d",and opt);
    fgetc(stdin);
    
     switch (opt){
         case 1:
         system("clear");
         printf("\n  pls enter the name of costumer:\t");
         fgets(ord.customer,50,stdin);
         ord.customer[strlen(ord.customer)-1]=0;
         strcpy(ord.date,_DATE_);
         printf("\nPls enter the number of items:\t");
         scanf("%d",&n);
         ord.numofitems=n;

         for(int i=0;i<n;i++){
             fgetc(stdin);
             printf("\n\n");
             printf("pls enter the item %d:\t",i+1);
             fgets(ord.itm[i].item,20,stdin);
             ord.itm[i].item[strlen(ord.itm[i].item)-1]=0;
             printf("pls enter the quantity:\t");
             scanf("%d",&ord.itm[i].qty);
             printf("pls enter the unit price:\t");
             scanf("%f",&ord.itm[i].price);
             total +=ord.itm[i].qty*ord.itm[i].price;

         }
          generateBillHeader(ord.costumer,ord.date);
          for(int i=0;i<ord.numofitems;i++){
              generateBillBody(ord.itm[i].item,ord.itm[i].qty,ord.itm[i].price);
          }
          generateBillFooter(total);
          
          print("\n Do you want to save the invoice[y\n]:\t");
          scanf("%s",&saveBill);

          if(saveBill =='y'){
              fp =fopen("RestaurantBill.dat","a+");
              fwrite(&ord,sizeof(struct orders),1,fp);
              if(fwrite!=0)
              printf("\nSuccesfully saved");
              else 
              printf("\nError saving");
              fclose(fp)

          }
          break;

          case 2:
          system("clear");
          fp=fopen("RestaurantBill.dat","r");
          printf("\n *****Your previous invoices*****");
          while(fread(&order,sizeof(struct orders),1,fp)){
              float tot=0;
              generateBillHeader(order.customer,order.date);
              for(int i=0;i< order.numofitems;i++){
                  generateBillBody(order.itm[i].item,order.item[i].qty,order.itm[i].price)
                  tot+=order.itm[i].qty*order.iten[i].price;
              }
              generateBillFooter(tot);
            }
            fclose(fp);
            break;

            case 3:
            printf("\nEnter the name of the customer:\t");
           // fgetc(stdin);
            fgets(name,50,stdin);
            name[strlen(name)-1]=0;
            system("clear");
          fp=fopen("RestaurantBill.dat","r");
          printf("\t *****Invoices of %s*****",name);
          while(fread(&order,sizeof(struct orders),1,fp)){
              float tot=0;
              if(!strcmp(order.customer,name)){
              generateBillHeader(order.customer,order.date);
              for(int i=0;i< order.numofitems;i++){
                  generateBillBody(order.itm[i].item,order.item[i].qty,order.itm[i].price)
                  tot+=order.itm[i].qty*order.iten[i].price;
              }
              generateBillFooter(tot);
              invoiceFound = 1;
            }
            if(!invoiceFound){
                printf("sprry the invoice for %s does not exists",name)
            }
            fclose(fp);
            break;

            case 4:
            printf("\n\t\tTHANK YOU :)\n\n");
            exit(0);
            break;

            default:
            printf("SORRY INVALID OPTION");
            break;

     }
     printf("\n DO YOU WANT TO PERFORM ANOTHER OPERATION ?[y/n]:\t");
     scanf("%s",&contFlag);
     }

     printf("\n\n");
     return 0;
}
