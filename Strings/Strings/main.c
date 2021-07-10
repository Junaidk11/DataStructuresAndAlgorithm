//
//  main.c
//  Strings
//
//  Created by jjkhan on 7/9/21.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// String operations
void print_string(char *str);
int str_len(char *str);
void change_to_upper(char *str);
void toggle_upper_to_lower(char *str);
int number_of_vowels(char *str);
int number_of_consonant(char *str);
int number_of_words(char *str);
bool isValid(char *str);
void reverse_using_additionalArray(char *str);
void reverse_not_using_additionalArray(char *str);

// Programs
void get_string_length(void);
void upper_to_lower(void);
void toggle_lower_to_upper(void);
void count_vowels_consanonts_words(void);
void validate_string(void);
void reverse_string(void);

int main(int argc, const char * argv[]) {
    // insert code here...
    reverse_string();
    
    return 0;
}

void reverse_string(void){
    char str[]="HELLOO SSNJFNCJ";
    char str2[]="HELLO \' \"";
    printf("Original string: %s\n",str2);
    reverse_using_additionalArray(str2);
    printf("Reverse String: %s\n",str2);
}
// Tests passed.
void validate_string(void){
    char str1[] ="JUnaidsjsne";
    char str2[] ="Kjhfcjc?sjcn";
    char str3[] ="123456789";
    char str4[] ="Jndujnd 345562";
    
    printf("Is \'%s\' a valid string?: %d\n",str1, isValid(str1));
    printf("Is \'%s\' a valid string?: %d\n",str2, isValid(str2));
    printf("Is \'%s\' a valid string?: %d\n",str3, isValid(str3));
    printf("Is \'%s\' a valid string?: %d\n",str4, isValid(str4));
}

// Tested with numbers & words.
void count_vowels_consanonts_words(void){
    
    char sen[] ="My name is Junaid Khan.";
    char sen2[]="aaaaaaaaaa";
    char sen3[]="123455456";
    printf("Number of vowels in %s : %d\n",sen2, number_of_vowels(sen3));
    printf("Number of consonants in %s : %d\n",sen3, number_of_consonant(sen3));
    printf("Number of words in %s: %d\n",sen, number_of_words(sen));
}
// Test passed: Only toggles characters, not affecting any symbols
void toggle_lower_to_upper(void){
    char str[] ="heLo worLd, What IT dO &^*&";
    print_string(str);
    toggle_upper_to_lower(str);
    print_string(str);
}

// Tests passed
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

/*
    An upper case letter gets switched to lower case
    A lower case letter gets switched to upper case.
 */
void toggle_upper_to_lower(char *str){
    
    int i;
    for(i=0;str[i]!='\0';i++){
        
        if(str[i]>='A' && str[i]<='Z'){
            // Add 32 to convert to lower case
            str[i]+=32;
        }else if(str[i]>='a' && str[i]<='z'){
            // Subtract 32 to convert to upper case
            str[i]-=32;
        }
    }
}
/*
        Counting how many vowels are in the given string.
        Vowels - a, e, i, o, u, A, E, I, O, U
 */
int number_of_vowels(char *str){
    
    int i, vcount=0;
    for(i=0;str[i]!='\0';i++){
        
        if(str[i]=='a' ||
           str[i]=='e' ||
           str[i]=='i' ||
           str[i]=='o' ||
           str[i]=='u' ||
           str[i]=='A' ||
           str[i]=='E' ||
           str[i]=='I' ||
           str[i]=='O' ||
           str[i]=='U' ){
            vcount++;
        }
    }
    return vcount;
}

bool linearSearch(char *str, char ch){
    int i;
    for(i=0;str[i]!='\0';i++){
        if(str[i]==ch){
            return true;
        }
    }
    return false; // ch not found in the string
}

bool isVowel(char ch){
    
    char vowels[] ="aeiouAEIOU";
    if(linearSearch(vowels,ch)){
        return true;
    }
    return false;
}
/*
        All the non-vowel alphabets.
        You first ensure the character is an alphabet, then you check
        if its not a vowel. If not a vowel then count incremented.
 */
int number_of_consonant(char *str){
    int i, consonant_count=0;
    for(i=0;str[i]!='\0';i++){
        if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')){
            // Character is an alphabet
            if(!isVowel(str[i])){
                consonant_count++;
            }
        }
    }
    return consonant_count;
}

/*
    You count spaces between words to indicate number of words
    in the given string.
    Make sure you don't count consecutive whitespaces as words.
        Only count a space if the previous character was not a space.
 */
int number_of_words(char *str){
    
    int i, words=0;
    for(i=0;str[i]!='\0';i++){
        if(str[i]==' ' && str[i-1]!=' '){
            words++;
        }
    }
    return words; // Because you're counting spaces
}

bool isAlphabet(char ch){
    if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')){
        return true;
    }
    return false;
}

bool isNumber(char ch){
    if(ch>='0' && ch<='9'){
        return true;
    }
    return false;
}
/*
        A string is valid if all its contents are either upper/lower alphabets or
        numbers, else it is invalid. I.e. if there is any special character in the
        string, the string is invalid.
 */
bool isValid(char *str){
    int i;
    for(i=0;str[i]!='\0';i++)
    {
        if(!(isAlphabet(str[i])) && !(isNumber(str[i]))){
            // The character is not an alphabet or a number, string not valid.
            return false;
        }
    }
    return true;
}

/*
    In this method, you create character array of same size as given string.
    Iterate to the last character of the given string, copy each character over
    to the character array and decrement iterator. Finally add NULL character to the
    character array to make it a string -> this is your reversed string
 */
void reverse_using_additionalArray(char *str){
    
    // Get size of the given string
    int i;
    for(i=0;str[i]!='\0';i++);
    // i is the size of the given string
    // i is at '\0'
    
    // Create a character array of same size as given string
    char *reverseString = (char*)malloc((i)*sizeof(char));
    
    i--; // i is at last character now
    
    // Copy the characters of given string over to
    // the memory allocated for reverseString
    // Copy stops when i>=0, i.e. copied all elements, when i=-1, stop
    int j; // For traversing the allocated block for reverseString
    for(j=0; i>=0;i--,j++){
        reverseString[j] = str[i];
    }
    
    // Add NULL character to the character array to make it a string
    reverseString[j] = '\0';
    
    //==================== NOTE ==================================
    // You can't simply say str = reverseString
    // because str is holding the memory address of the
    // the original string given to the function. The pointer str
    // only exist in this function, so if we assign it address
    // pointed to by reverseString, our changes won't be returned to the main program.
    // Because pointer to original string was passed by value.
    // Therefore, we need to explicitly copy the reversString to the address
    // pointed to by str
    //==================== NOTE ==================================
    
    // could use i aswell, no restrictions
    for(j=0;reverseString[j]!='\0';j++){
        str[j] = reverseString[j];
    }
    // NULL character already there in str
    // Now the address pointed to by str has the reversed string
    
    free(reverseString); // return memory to heap
    reverseString=NULL;
    
}
void reverse_not_using_additionalArray(char *str);
