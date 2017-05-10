# include "dates.h"

int main ( ){

    int month, day;
    
    long int year;
    
    char date[ LINE ];
    char monthName[ M_LENGTH ];
    char buffer[ LINE ];
    
    char done = NO;
   
    FILE *inFile;
    FILE *outFile;

    inFile = fopen("dates.dat" , "r");
    outFile = fopen("outFile.txt" , "a");
    
    if(outFile == NULL || inFile == NULL){
        
        printf("Error opening file");
        
    }
    
    while(fgets(date, sizeof(date), stdin) != NULL && done != YES )
    {
        
        if ( sscanf  ( date , "\n%d/%d/%ld\n" , &month ,&day ,&year ) == VALID_SCAN ){
            
            printf("%d %s %ld\n" , day , monthAbbreviations[ month ], year);
        
        }
        else if( sscanf ( date , "\n%c" , &done) == PASS ){

            determineResult( done );
            done = YES;

        }// this will receive the indicator when datesValidator is finished.
        
    }
    
    fflush(stdout);
    
    while( fgets(buffer, sizeof(buffer), inFile) != NULL ){
        
        fprintf(outFile , "%s" , buffer);
        
    }


    fclose(outFile);
    fclose(inFile);

    return 0;
    
}

/* 
 determineResult() will detect if process 1 was done succesfully or erroneously, it will print out
 the outcome
 */

void determineResult( char indicator ){
    
    if( indicator == NO ){
        
        printf("-- Error in program 1 --\n\n");
        
    }else{
        
        printf("\n-- End of output --\n\n");
        
    }
}
