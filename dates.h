//dates.h

/***********************************************************************************/
/* Program Defines */


# include <stdio.h>
# include <stdlib.h>        
# include <string.h>
# include <limits.h>
# include <math.h>


# define MONTHS 12
# define PASS 1
# define FAIL 0 
# define LINE 80
# define VALID_SCAN 3
# define VALID_DATES 1
# define M_LENGTH 10
# define NO 'n'
# define YES 'y'
# define FEB 2
# define VALID_ARGS 2

const int days[13] = { 0 ,31 ,28 ,31 ,30 ,31 ,30 ,31 ,31 ,30 ,31 ,30 ,31 };

const char *monthAbbreviations[] = { "BLANK" , "JAN" , "FEB" , "MAR" , "APR" , "MAY" ,
    "JUN" , "JUL" , "AUG" , "SEP" , "OCT" , "NOV" , "DEC" };

const char *months[] = { "Blank" , "January" , "February" , "March" , "April" , "May" , "June" ,
    "July" , "August" , "September" , "October" , "November" , "December" };

/***********************************************************************************/
/* Function Prototypes */

int validateNumericDate();
int validateMonth();
int determineLeapYear();
int validateYear();
int validateDayOfMonth();
int validateArgs();
void determineResult(char);





