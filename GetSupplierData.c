#ifndef Get_Supplier_Data
#define Get_Supplier_Data

#include "header.h"

// Function to read supplier data from a text file and store it in a binary file
int get_supplier_data(void)
{
    // Declear files values
    int option,x;
    char file_name[30], input_buffer[1000];
    
    //Prompting user to select whether to input via a whole file or enter a singular data
    printf("\nSelect one of the following: \n");
    printf("1: Add by file\n");
    printf("2: Add manually\n");
    printf("0: Exit\n");
    printf("Option #: ");
    scanf("%d",&option);
    
    //If the user wants to enter from a file
    if(option==1)
    {
	    x=0;    
	    //Prompting user to type in a file name
	    printf("Enter name of file to read: ");
	    scanf("%s",file_name);
	             
	    //Opening input file
	    input_file=fopen(file_name,"r");
	                
	    //Reading data into buffer
	    while(fgets(input_buffer, 1000, input_file)>0)
	    {      
	    //Ignoring first line because its the title
	    if(x==0)
	    	x++;           
	    //Other lines except first
	    else
	    {            
		    //Storing data into supplier struct
		    sscanf(input_buffer,"%[^\t]%*c %[^\t]%*c %[^\t]%*c \"%100[^\"]\" %[^\t]%*c %[^\t]%*c",&newSUPPLIER.mname, &newSUPPLIER.name,&newSUPPLIER.cname,&newSUPPLIER.sadd,&newSUPPLIER.phonenumber,&newSUPPLIER.email);
		                   
		    //Store Supplier data into binary file
		    fseek(supplier_file,newSUPPLIER.sid*sizeof(struct supplier), SEEK_SET);
		    fwrite(&newSUPPLIER,sizeof(struct supplier),1,supplier_file);
		                    
		    //Incrementing ID counter
		    newSUPPLIER.sid++;
	    }
	    }
	}
    //If user wants to enter supplier data manually
    else if(option==2)
    {
                
	    //Promting user to enter supplier data
	    printf("\nEnter Supplier ID: ");
	    scanf("%d",&newSUPPLIER.sid);
	    printf("Enter Manufacturer Name: ");
	    scanf(" %[^\t\n]s",&newSUPPLIER.mname);
	    printf("Enter Contact Name: ");
	    scanf(" %[^\t\n]s",&newSUPPLIER.name);
	    printf("Enter Company Name: ");
	    scanf(" %[^\t\n]s",&newSUPPLIER.cname);
	    printf("Enter Address: ");
	    scanf(" %[^\t\n]s",&newSUPPLIER.sadd);
	    printf("Enter Phone Number: ");
	    scanf(" %[^\t\n]s",&newSUPPLIER.phonenumber);
	    printf("Enter Email address: ");
	    scanf(" %[^\t\n]s",&newSUPPLIER.email);
	                
	    //Store Supplier data into binary file
	    fseek(supplier_file,newSUPPLIER.sid*sizeof(struct supplier), SEEK_SET);
	    fwrite(&newSUPPLIER,sizeof(struct supplier),1,supplier_file);
    }
    
    //Hotkey to exit function
    else if(option==0)
    {
        return 0;
    }
    //When an unrecognized value is entered
    else
    {
    	printf("Invalid Entry.\n\n");
	}

    //Returning values
    return 0;
}

#endif
