#ifndef Make_Sales
#define Make_Sales

#include "header.h"

int make_sales(void){
	
	int customer_ID, Product_ID, quntity;
	
	printf("Enter customer ID: ");
    scanf("%d",&customer_ID);
    fseek(customer_file, customer_ID * sizeof(newCUSTOMER), SEEK_SET);
    
    if(fread(&newCUSTOMER, sizeof(newCUSTOMER), 1, customer_file)!=0)
    {
        strcpy(newSALES.fname,newCUSTOMER.fname);
        strcpy(newSALES.lname,newCUSTOMER.lname);
        strcpy(newSALES.cphonenumber,newCUSTOMER.phonenumber);
        newSALES.customerid=newCUSTOMER.cid;
    }
    else
    {
        printf("Customer does not exist in system. Please enter data manually.\n");
        return 0;
    }
	
	 
    printf("\nEnter the Product ID: ");
    scanf("%d",&Product_ID);
    fseek(product_file, Product_ID * sizeof(newPRODUCTS), SEEK_SET);
    
    if(fread(&newPRODUCTS, sizeof(newPRODUCTS), 1, product_file)==0)
    {
        printf("Product does not exist.");
        return 0;
    }
    
    printf("Enter the number of products ordered: ");
    scanf("%d",&newSALES.num);
    quntity = atoi(newPRODUCTS.is);
    
    if(quntity<newSALES.num)
    {
        printf("Sorry, only %d are available in stock.",quntity);
        return 0;
    }
    else
	{
    	printf("%d items in stock\n",quntity);
        strcpy(newSALES.pname,newPRODUCTS.name);
        strcpy(newSALES.tc,newPRODUCTS.uc);
	}
        
    if(get_supplier_record())
    {
        strcpy(newSALES.sname,newSUPPLIER.name);
        strcpy(newSALES.scompany,newSUPPLIER.cname);
    }
    else
    {
        printf("Supplier does not exist in system. Please enter data manually.\n");
        return 0;
    }
    
    fseek(sales_file,newSALES.said*sizeof(struct sales), SEEK_SET);
    fwrite(&newSALES,sizeof(struct sales),1,sales_file);
    printf("\nThe folloing Sale is made:");
    printf("\nCustomer Name (FN LN): %s %s\nCustomer ID: %d\nProduct Name: %s\nQuantity: %d\nCost per Unit: %s\nSupplier Name: %s\nCompany Name: %s\n\n",newSALES.fname, newSALES.lname,newSALES.customerid,newSALES.pname,newSALES.num, newSALES.tc,newSALES.sname,newSALES.scompany);
    return 0;
}

#endif
