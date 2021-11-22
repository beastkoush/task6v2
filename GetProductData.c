#ifndef Get_Product_Data
#define Get_Product_Data

#include "header.h"

int get_product_data(void)
{
	//initialize variables
	int option, x;
	char file_name[50], input_buffer[1000];
		
	//Prompt user for input between adding data from file or manually
    printf("\nSelect one of the following: \n");					
    printf("1: Add by file\n");
    printf("2: Add manually\n");
    printf("0: Exit\n");
    printf("Option #: ");
    scanf("%d",&option);
    
    //if statement for adding by file    
    if(option==1)													
    {
        x=0;
		//prompt user for input file name
        printf("Enter name of file to read: ");						
        scanf("%s",file_name);
		input_file=fopen(file_name,"r");
        
	//read data into the buffer
    while(fgets(input_buffer, 1000, input_file)>0)					
    {
    	//Ignoring first line because its the title
        if(x==0)
		{
			x++;												
		}														
        else {
		//stores data into the respective structs
        sscanf(input_buffer,"%[^\t]%*c %[^\t]%*c %[^\t]%*c %[^\t]%*c %[^\t]%*c %[^\t]%*c",&newPRODUCTS.name, &newPRODUCTS.classification,&newPRODUCTS.mname,&newPRODUCTS.uc,&newPRODUCTS.mc,&newPRODUCTS.is);    
        newPRODUCTS.pid++;	
		//store data into binary file	
        fseek(product_file,newPRODUCTS.pid*sizeof(struct products), SEEK_SET);		
        fwrite(&newPRODUCTS,sizeof(struct products),1,product_file);	
        }
    }
	}
    else if(option==2)											
    {	
		// Prompts user for input if data is added manually
	    printf("\nEnter Product ID: ");
	    scanf("%d",&newSUPPLIER.sid);
	    printf("Enter Product Name: ");
	    scanf(" %[^\t\n]s",&newPRODUCTS.name);
	    printf("Enter Classification: ");
	    scanf(" %[^\t\n]s",&newPRODUCTS.classification);
	    printf("Enter Manufacturer Name: ");
	    scanf(" %[^\t\n]s",&newPRODUCTS.mname);
	    printf("Enter Unit Cost: $");
	    scanf(" %[^\t\n]s",&newPRODUCTS.uc);
	    printf("Enter Manufacturer Code: ");
	    scanf(" %[^\t\n]s",&newPRODUCTS.mc);
	    printf("Enter no of items in stock: ");
	    scanf(" %[^\t\n]s",&newPRODUCTS.is);
	        
	    //Store product data into binary file
	    fseek(product_file,newPRODUCTS.pid*sizeof(struct products), SEEK_SET);
	    fwrite(&newPRODUCTS,sizeof(struct products),1,product_file);
    }
    //Hotkey to exit function
	else if (option == 0)
    {
    	return 0; 
	} 
	else
	{
		//unrecognized value will return invalid
        printf("Invalid Entry.\n\n");	
	}
																
	return 0;    
}
#endif
