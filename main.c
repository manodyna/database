// all variable names are in camel case
// most of the required header files are included and the need to include other header files may not arise
// the file may be split later for enhanced code readability 
// all commits to the git repo be appropriately described
// it is preferable to branch the repo before making changes to it cause I ACCIDENTALLY DELETED ALL CODE
// all functions are to be defined below the main function and appropriate prototypes be added in the header for easy debugging
// a csv file is being used for data persistance

// including the header files
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <stdbool.h> 
#include <time.h>

// defining the time functionality
#define _XOPEN_SOURCE 
#define __USE_XOPEN

// defining database functionalities
#define DB "database.csv" 
// defining the readable and unreadable queries
#define TRY(a)  if (!(a)) {perror(#a);exit(1);}
#define TRY2(a) if((a)<0) {perror(#a);exit(1);}
#define FREE(a) if(a) {free(a);a=NULL;}
// defining a sort function using string compare(strcmp), pointers and a lambda expression
#define sort_by(sort) \
static int by_##sort (const void*p1, const void*p2) { \
    return strcmp ((*(const pdb_t*)p1)->sort, (*(const pdb_t*)p2)->sort); }

// build succesful

// defining a struct for the management system
typedef struct db
{
    char drug[56];
    char type[26];
    time_t dateOfExpiry;
    char manufacturer[56];
    int quantity;
    float price;
    bool isPrescription;
    struct db *next;
}
db_t,*pdb_t;

// typedef for sorting
typedef int (sort)(const void*, const void*);

// enum for commands
enum {ADD, DELETE, SORT, UPDATE, SELECT};

// function definitions
// data access object(DAO)
static pdb_t dao (int cmd, FILE *f, pdb_t db, sort sortby);
// static char *time2str (time_t *time);
// static time_t str2time (char *date);

// qsort comparator callbacks
sort_by(drug);
sort_by(quantity);
sort_by(manufacturer);
sort_by(type);
static int by_date(pdb_t *p1, pdb_t *p2);

// main method
int main(){
    
}  

static pdb_t dao (int cmd, FILE *f, pdb_t in_db, sort sortby) {

}

// build succesful

// // numeric to date string
// static char *timeToStr (time_t *time) {
//     static char buf[255];
//     struct tm *ptm;
//     ptm=localtime (time);
//     strftime(buf, 255, "-%m-%d-%Y", ptm);
//     return buf;
// }

// // date to numeric string
// static time_t strToTime (char *date) {
//     struct tm tm;
//     memset (&tm, 0, sizeof(struct tm));
//     strptime(date, "-%m-%d-%Y", &tm);
//     return mktime(&tm);
// }

// sort by date callback for qsort
static int by_date (pdb_t *p1, pdb_t *p2) {
    if ((*p1)->dateOfExpiry < (*p2)->dateOfExpiry) {
        return -1;
    }
    else return ((*p1)->dateOfExpiry > (*p2)->dateOfExpiry);
}    
// build succesful
