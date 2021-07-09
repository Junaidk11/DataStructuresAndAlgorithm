//
//  main.c
//  Strings
//
//  Created by jjkhan on 7/9/21.
//

#include <stdio.h>

// String operations
void print_string(char *str);
int str_len(char *str);
void change_to_upper(char *str);


// Programs
void get_string_length(void);
void upper_to_lower(void);

int main(int argc, const char * argv[]) {
    // insert code here...
    upper_to_lower();
    
    return 0;
}

void upper_to_lower(void){
    char str[] = "HELLO WORLD";
    change_to_upper(str);
    print_string(str);
}

void get_string_length(void){
    // By initializing a string like this,
    // the compiler automatically allocates
    // the character array with'\0' in the heap memory.
    // But, the string is "HELLO" is not modifiable
    // I.e. declaring and initializing a string using char*
    // will move the string to read-only-memory!
    // *str is created in stack activation record of main func.
    char *str="Hello";
    printf("Length of string: %d \n", str_len(str));
}

void print_string(char *str){
    printf("String: %s\n",str);
}

// Returns length of given string
int str_len(char *str){
    int i;
    for(i=0;str[i]!='\0';i++);
    return i;
}

/*
    This function will change the given string's contents
    from lower case to upper case.
    
    ASCII of 'A' = 65 -> 'Z' = 90
    ASCII of 'a' = 97 -> 'z' = 122
    
    Difference between 'a' and 'A' -> 97-65 = 32
                        'b' and 'B' -> 98-66 = 32
 
    The difference between upper and lower case letters is 32.
    
    To go from lower to upper -> subtract 32 from ASCII of char
    To go from upper to lower -> add 32 to ASCII of char

 */
void change_to_upper(char *str){
    int i;
    
    for(i=0; str[i]!='\0';i++){
        
        if(str[i]>='A' && str[i]<='Z'){
            // Add 32 to convert to lower case
            str[i] = (str[i])+32;
            
        }
    }
}
