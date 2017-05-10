
// dateValidator.c

/***********************************************************************************/
/* Author: Christian Hidalgo. PID: 2103434                                         */

/* Description: program, when executed is to accept values from a file (dates.dat)
   and read the lines and validate if the date in the file is in the valid format
   of month/day/year and will send its valid output to the screen. Or, if 
   redirection is used, it will send its output to another process, which in this
   case is dateConverter.c . A number will also be read from the command line 
   which will be the number of valid dates to be outputed. a ZERO would mean that
   ALL valid dates are returned */

/* Command-line Input: a file called dates.dat ( **PLEASE MAKE SURE YOUR FILE NAME IS
    UPDATED IN THE MAKEFILE UNDER 'IN_FILE'** )*/

/* Output: valid dates in the format 'month/day/year' from the dates.dat file          */

/* Compilation: make                                       */
/* Execute with ./dateV.out < fileName.dat 'number' i.e. ( ./dateV.out < dates.dat 3 )
   or if its used a*/

/* I certify that this work is my own and none of it is work of any other person   */
/* or entity (with exception of the temperature conversion formulas                */


/***********************************************************************************/
/* Program Defines */

# include "dates.h"

/**********************************************************************************	*/

/**********************************************************************************	*/
/* main will receive a .dat file as input along with a number, which would mean the
   number of valid inputs to be outputed. a ZERO will indicate that all valid dates 
   are to be returned. Main will scan through the file and look for a date in the
   form of month/day/year and will output it as a valid date */
/**********************************************************************************	*/


int main( int argsc , char *argsv[ ] ){
    
    char done = NO;
    
    int validDates = atoi( argsv[ VALID_DATES ] );
    int result = validateArgs( argsc , validDates  );
    
    if( result != PASS){
        
        printf("%c\n" , done);
        return 0;
    
    }//this will exit if the input is not valid and it will indicate process 2 that an error was encountered
    
    if( validDates <= 0){
            
        validDates = INT_MAX;
        
    } /*This will make 'validateDates' large enough in order to read every date in the file
    unless a file has more than INT_MAX valid dates*/
    
    int month , day;
    int count = 1;
    int test;
    

    long int year;
    
   
    
    char monthName[ LINE ];
    char date[ LINE ];
    
        

    
    while( fgets(date, sizeof(date), stdin) != NULL && (validDates + 1) != count){

        if ( sscanf  ( date , "\n%d/%d/%ld" , &month ,&day ,&year)== VALID_SCAN ){
            
            test = validateNumericDate( month , day , year );
            
            if( test == PASS ){
                
                count++;
                printf("%d/%d/%ld\n" , month , day , year);

                
            }
            
        }
        
    }
    
    done = YES;
    printf("%c\n" , done);//this will be an idicator for process 2 to let it know this process is done

    return 0;
    
}// end of main


/**********************************************************************************	*/
/* validateNumericDate() received 2 ints and a long int. both ints are for month 
   and day, and long int is for the year. This function will validate if its a valid
   Month, Day, and Year by calling its respective validation functions. it will 
   return a 1 (PASS) if the validation passes or a 0 (FAIL) if the validation fails */
/**********************************************************************************	*/


int validateNumericDate( int month , int day , long year){
    
    int test = FAIL;
    
    test = validateMonth( month );
    
    if( test == FAIL ){
        
        return test;
        
    }//will exit if the number is not a valid month
    
    test = validateDayOfMonth( month , day , year);
    
    if( test == FAIL ){
        
        return test;
        
    }// will exit if the number is not a valid day of the month
    
    test = validateYear( year );
    
    return test;
}


/**********************************************************************************	*/
/* validateMonth() gets an int as a parameter. It will check if the int entered is
   in between 0 and 12 (MONTHS). returns a 1 if it passes and a 0 if it fails*/
/**********************************************************************************	*/


int validateMonth( int month){
    
    int test = FAIL;
    
    if ( month > 0 && month <= MONTHS){
        
        test = PASS;
        
    }
    
    return test;
    
}

/**********************************************************************************	*/
/* validateYear() validates if the year is within range */
/**********************************************************************************	*/


int validateYear( long int year ){
    
    int test = FAIL;
    
    if (  year  >= (-1 * INT_MAX) &&  year <= INT_MAX){
        
        test = PASS;
    }
    
    return test;
    
}

/**********************************************************************************	*/
/* determineLeapYear() validates if the year is a leap year */
/**********************************************************************************	*/


int determineLeapYear( int year){
    
    int leap = FAIL;
    
    if( (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ){
        
        leap = PASS;
        
    }//returns 1 if it is a leap year
    
    return leap;
    
}

/**********************************************************************************	*/
/* validateDayOfMonth() validates if the day of month is valid*/
/**********************************************************************************	*/

int validateDayOfMonth( int month , int day , int year){
    
    int testDay;
    int test = 0;
    int leap = 0;
    
    testDay = days[ month ];
    leap = determineLeapYear( year );
    
    if( leap == PASS && month == FEB ){
        testDay = days[ month ] + 1;
    }
    
    if ( day > 0 && day <= testDay){
        
        test = PASS;
        
    }
    
    return test;
    
}

/**********************************************************************************	*/
/* validateArgs() validates the argumtns inputed */
/**********************************************************************************	*/

int validateArgs( int args , int value ){
    
    int test = FAIL;
    
    if( args == VALID_ARGS && value >=0 ){
        
        test = PASS;
        
    }
    
    return test;
    
}


