#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>

#define MAXLEN 100

extern FILE *input_file;
extern FILE *customer_file;
extern FILE *supplier_file;
extern FILE *product_file;
extern FILE *sales_file;

extern int make_sales(void);
extern int get_product_data(void);
extern int get_supplier_data(void);
extern int get_customer_data(void);
extern int read_data(int selection);
extern void open_files(void);
extern int get_supplier_record(void);

struct customer
{
    int cid;
    char lname[MAXLEN];
    char fname[MAXLEN];
    char bname[MAXLEN];
    char sadd[MAXLEN];
    char town[MAXLEN];
    char province [3];
    char postalcode[10];
    char phonenumber [16];
};

struct supplier
{
    int sid;
    char mname[MAXLEN];
    char name[MAXLEN];
    char cname[MAXLEN];
    char sadd[100];
    char phonenumber [16];
    char email[100];
};

struct products
{
    int pid;
    char name[MAXLEN];
    char classification[MAXLEN];
    char mname[MAXLEN];
    char uc[20];
    char mc[30];
    char is[16];
};

struct sales
{
    int said;
    char fname[MAXLEN];
    char lname[MAXLEN];
    char pname[MAXLEN];
    int num;
    char tc[MAXLEN];
    char sname[MAXLEN];
    char scompany[MAXLEN];
    char cphonenumber[16];
    int customerid;
};

struct products newPRODUCTS;

struct supplier newSUPPLIER;

struct customer newCUSTOMER;

struct sales newSALES;
