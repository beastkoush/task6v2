#ifndef Read_Data
#define Read_Data

#include "header.h"

int read_data(int selection)
{
    int option;
    int rec_no = 0,j=0;
    printf("\nSelect one of the following: \n");
    printf("1: Read a singular record from file\n");
    printf("2: Read all the records from file\n");
    printf("3: Read a range of records from file\n");
    printf("Enter 0 for exit\n");
    printf("Option #: ");
    scanf("%d",&option);
    switch (option)
    {
        case 1:
            printf("Enter record number to read: ");
            scanf("%d", &rec_no);
            printf("\n");
            j = rec_no+1;
            break;
        case 2:
            if(selection==3)
            rec_no=1;
            else if(selection==1||selection==2)
            rec_no=1000;
            break;
        case 3:
            printf("Enter the range of data to read (start end): ");
            scanf("%d %d", &rec_no, &j);
            printf("\n");
            j++;
            break;
        case 0:
            return 0;
        default:
            printf("Invalid Entry\n");
    }


    if(rec_no!=0)
	{
    switch (selection)
    {
        case 1:
            if(option==2)
            {
            while((fread(&newCUSTOMER, sizeof(newCUSTOMER), 1, customer_file))>0)
            {
            	j++;	
			}	
			}
            
            for(rec_no;rec_no<j;rec_no++)
            {
            fseek(customer_file, rec_no * sizeof(newCUSTOMER), SEEK_SET);
            fread(&newCUSTOMER, sizeof(newCUSTOMER), 1, customer_file);
			   
            printf("Customer ID: %d\n Customer Name: %s %s\n Business Name: %s\n Street Address: %s\n Town: %s\n Province:%s\n Postal Code: %s\n Telephone Number: %s\n\n",newCUSTOMER.cid,newCUSTOMER.fname,
            newCUSTOMER.lname, newCUSTOMER.bname, newCUSTOMER.sadd, newCUSTOMER.town,
            newCUSTOMER.province, newCUSTOMER.postalcode, newCUSTOMER.phonenumber);
            }
            break;
        case 2:
            if(option==2)
            {
            while((fread(&newSUPPLIER, sizeof(newSUPPLIER), 1, supplier_file))>0)
            {
            	j++;
			}  	
			}
                
            for(rec_no;rec_no<j;rec_no++)
            {
            fseek(supplier_file, rec_no * sizeof(newSUPPLIER), SEEK_SET);
            fread(&newSUPPLIER, sizeof(newSUPPLIER), 1, supplier_file);
            printf(" Supplier ID: %d\n Manufacturer: %s\n Supplier Name: %s\n Company Name: %s\n Supplier Address: %s\n Supplier Telephone No: %s\n Supplier Email: %s \n\n",newSUPPLIER.sid,newSUPPLIER.mname, newSUPPLIER.name,newSUPPLIER.cname,newSUPPLIER.sadd,newSUPPLIER.phonenumber,newSUPPLIER.email);
            }
            break;
        case 3:
            if(option==2)
            {
            while((fread(&newPRODUCTS, sizeof(newPRODUCTS), 1, product_file))>0)
            {
                j++;	
			}  	
			}
                
            for(rec_no;rec_no<j;rec_no++)
            {
            fseek(product_file, rec_no * sizeof(newPRODUCTS), SEEK_SET);
            fread(&newPRODUCTS, sizeof(newPRODUCTS), 1, product_file);

            printf(" Product ID: %d\n Product Name: %s\n Product Classification: %s\n Product Manufacturer: %s\n Unit Cost: %s\n Manufacturer Code: %s\n Products in stock: %s\n\n",newPRODUCTS.pid,newPRODUCTS.name, newPRODUCTS.classification,newPRODUCTS.mname,newPRODUCTS.uc,newPRODUCTS.mc,newPRODUCTS.is);
            }
            break;
        case 4:
            if(option==2)
            {
            while((fread(&newSALES, sizeof(newSALES), 1, sales_file))>0)
            {
                j++;	
			} 
			}
                  
            for(rec_no;rec_no<j;rec_no++)
            {
            fseek(sales_file, rec_no * sizeof(newSALES), SEEK_SET);
            fread(&newSALES, sizeof(newSALES), 1, sales_file);
            
            printf(" Customer Name (FN LN): %s %s\n Customer ID: %d\n Product Name: %s\n Quantity: %d\n Cost per unit: %s\n Supplier Name: %s\n Company Name: %s\n\n",newSALES.fname, newSALES.lname,newSALES.customerid, newSALES.pname,newSALES.num,newSALES.tc,newSALES.sname,newSALES.scompany);
            }
            break;
        default:
            printf("Invalid Entry\n\n");
            break;
    }
    }
    return 0;
}

#endif
