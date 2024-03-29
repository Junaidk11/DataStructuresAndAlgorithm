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
bool isPalindrome_using_additionalArray(char *str);
bool isPalindrome_not_using_additionalArray(char *str);

// Finding duplicates in a string - three possible methods
void find_duplicates_by_comparing(char *str);  // @TODO:
void find_lowercase_alphabet_duplicates_using_hastable_for_counting(char *str);
void find_uppercase_alphabet_duplicates_using_hastable_for_counting(char *str);
void find_upper_and_lowercase_alphabet_duplicates_using_hashtable_for_counting(char *str);
void find_duplicates_using_hashtable_with_bits(char *str); // @TODO:

// Anagram Checking
// Check if str2 is an anagram of str1
bool isAnagram(char *str1, char *str2);
bool isAnagram_using_search(char *str1, char *str2);


// Permutation of a give string
// level -> State-space representation of all permutations of given string
void permuation_of_given_string(char *str, int level);

// Sliding Window Problems
char* minWindowSubstring(char *searchString, char *chars);

// create substring
char* create_substring(char str[], int LowerIndex, int len);

// Programs
void get_string_length(void);
void upper_to_lower(void);
void toggle_lower_to_upper(void);
void count_vowels_consanonts_words(void);
void validate_string(void);
void reverse_string(void);
void check_palindrome(void);
void find_duplicates(void);
void check_anagram(void);
void print_permuations(void);
void slidingWindow_problems(void);


int main(int argc, const char * argv[]) {
    // insert code here...
    slidingWindow_problems();
    
     return 0;
}


void slidingWindow_problems(void){
    char str[] ="donutsandwafflemakemehungry";
    char target[]="flea";
    char str1[]="whoopiepiesmakemyscalegroan" ;
    char target1[]="roam";
    printf("Search String \'%s\' for minimum substring that contains all characters of \'%s\'.\n", str, target);
    printf("Minimum substring is: \'%s\' \n",minWindowSubstring(str, target));
    
    printf("Search String \'%s\' for minimum substring that contains all characters of \'%s\'.\n", str1, target1);
    printf("Minimum substring is: \'%s\' \n",minWindowSubstring(str1, target1));
    
}
void print_permuations(void){
    
    char str1[] = "ABC";
    char str2[] = "CAB1";
    char str3[] = "123";
    permuation_of_given_string(str1, 0);
    printf("\n");
    permuation_of_given_string(str2, 0);
    printf("\n");
    permuation_of_given_string(str3, 0);
    
}
// Tests passed: Tried lower case letters, mix and match with lower, upper and numbers, changed sizes.
void check_anagram(void){
        
    char str1[]="fried";
    char str2[]="FIRED";
    printf("Is \'%s\' an anagram of \'%s\'? %d\n",str2, str1, isAnagram(str1, str2));
    printf("Is \'%s\' an anagram of \'%s\'? %d\n",str2, str1, isAnagram_using_search(str1, str2));
    
}


// Tests: Only tested the hashtable method of finding duplicates-> Upper, lower, upper&&lower strings
void find_duplicates(void){
    
    char str1[]="abdjceedd";
    char str2[]="ASDCFVDDDRTVFFFF";
    char str3[]="asdCCf11cvggZZ ";
    printf("The string is: %s\n",str2);
    find_lowercase_alphabet_duplicates_using_hastable_for_counting(str2);
    printf("The string is: %s\n",str1);
    find_uppercase_alphabet_duplicates_using_hastable_for_counting(str1);
    
    // Counting upper and lower case duplicates
    printf("The string is: %s\n",str3);
    find_upper_and_lowercase_alphabet_duplicates_using_hashtable_for_counting(str3);
    
    
}
// Test all passed.
void check_palindrome(void){
    char str1[]="AYYA";
    char str2[]="Junaid";
    char str3[]="MAMA  ";
    printf("Is string \'%s\' a palindrome? %d\n", str1, isPalindrome_using_additionalArray(str1));
    printf("Is string \'%s\' a palindrome? %d\n", str2, isPalindrome_using_additionalArray(str2));
    printf("Is string \'%s\' a palindrome? %d\n", str3, isPalindrome_using_additionalArray(str3));
    printf("\n");
    printf("Is string \'%s\' a palindrome? %d\n", str1, isPalindrome_not_using_additionalArray(str1));
    printf("Is string \'%s\' a palindrome? %d\n", str2, isPalindrome_not_using_additionalArray(str2));
    printf("Is string \'%s\' a palindrome? %d\n", str3, isPalindrome_not_using_additionalArray(str3));
}

void reverse_string(void){
    char str[]="HELLOO SSNJFNCJ";
    char str2[]="HELLO \' \"";
    printf("Original string: %s\n",str2);
    reverse_using_additionalArray(str2);
    printf("Reverse String: %s\n",str2);
    printf("Original string: %s\n",str2);
    reverse_not_using_additionalArray(str2);
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

/*
    In this method of string reversal, you don't need an additional character array.
    You use the given string's character array, use two iterators.
    One starts at the last character of the string, and the other starts at the front.
    Each iteration, you swap the characters, this continues until front and back iterator cross each
    other.
    
 */
void reverse_not_using_additionalArray(char *str){
    
    // Get to the last character of given string
    int i;
    for(i=0;str[i]!='\0';i++);
    // i is at index of '\0'
    i--; // Now i is at last character
    
    int j; // for traversing from front of string
    char temp; // for swapping
    for(j=0;i>j;i--,j++){
        temp = str[j];
        str[j] = str[i];
        str[i] = temp;
    }
    
    // NULL character already in the right place.
}


char *create_copy(char *str){
    
    // Get size of the string
    int i;
    for(i=0;str[i]!='\0';i++);
    
    // Allocate memory from the heap for
    // a character array to store copy of str
    char *copy = (char*)malloc(i*sizeof(char));
    
    // copy contents
    for(i=0;str[i]!='\0';i++){
        copy[i]=str[i];
    }
    // i is at '\0' on str
    copy[i] = '\0'; // Now copy is a string
    
    return copy;
}
/*
    In this method of palindrome checking, you create an additional character array to
    store the reverse of the given string, then you compare the reverse with the given string.
    If they match, its a palindrome, else its not.
 */
bool isPalindrome_using_additionalArray(char *str){
    
    // Need to know the size of the given string
    int i;
    for(i=0;str[i]!='\0';i++);
    // i is at position of '\0'
    
    // Create a copy of the original string
    char *copy = create_copy(str);
    
    // Reverse the copy of the string
    reverse_not_using_additionalArray(copy);
    
    // copy is holding the revered string of the original string
    // Now we check if the reversed string matches the original string
    int j;
    for(j=0;str[j]!='\0';j++){
        if(str[j]!=copy[j]){
            // free the dynamically allocated memory for copy
            free(copy);
            copy = NULL;
            return false;
        }
    }
    
    // The reverse and original string are the same.
    // free the dynamically allocated memory for copy
    free(copy);
    copy = NULL;
    return true;
}
/*
    In this method of palindrome checking, you don't need an additional character array.
    You use two iterators, one starting from the front and the other from last character,
    each iteration you check the front and back character, if they don't match, this is not a palindrome.
    You repeat this process until front iterator crosses the back iterator or vice versa
 */
bool isPalindrome_not_using_additionalArray(char *str){
    
    // Get size of string
    int i;
    for(i=0;str[i]!='\0';i++);
    // i is at the position of '\0'
    i--; // i is now at last character
    
    int j; // for starting at the start of the string
    // Keep comparing the two index values until they cross each other
    for(j=0;j<i;j++,i--){
        if(str[j]!=str[i]){
            // not a palindrome, reverse not same as original
            return false;
        }
    }
    // Both original and its reverse are the same
    return true;
}


/*
        The idea here is to create a hashtable using arrays where each index
        is corresponding to an alphabet, and we keep count of the number of
        occurences of each alphabet in the given string.
 
        The hashtable size is based on the given range of values in the give string.
        i.e. if string is all lower case alphabets, then range of values is from 97-122 (ASCII code).
        The number of values from 97 to 122 is 26, so you create an array of size 26, where index 0
        corresponds to alphabet 'a', and index 1 corresponds to alphabet 'b' and so on.
            For each index, if you add 97 to it, you can get the character it corresponds to, i.e
            0+97 = 97 = 'a' and the value at index 0 corresponds to number of occurences of 'a'.
 
        To get the index value of the current character in given string, you simply subtract 97 from
        it. i.e. 'b'-97 = 1, because 'b' = 98 in ASCII code. When you have the index, use it to increment the count in the hashtable for the corresponding alphabet.
 
        All hashtable method of finding the duplicates has a linear time complexity,
        i.e. depending on your range of values expected in the given string, you create a hashtable
        of that size and populate with count of each alphabet.
 */
// We're assuming the string has only lower case alphabets
void find_lowercase_alphabet_duplicates_using_hastable_for_counting(char *str){
    
    // Create a hashtable of size 26, corresponding to ASCII of lower case alphabets (97-122)
    int counter[26] ={0}; // Initialize all the elements to 0
    
    int i;
    for(i=0;str[i]!='\0';i++){
        // str[i]-97 will calculate the index corresponding to the current character of the string
        counter[(str[i]-97)]++;
    }
    
    // Print all the duplicate characters in the string
    for(i=0;i<26;i++){
        if(counter[i]>1){
            // The character corresponding to the current index has duplicates
            printf("Character \'%c\' has occured %d times.\n", (char)(i+97), counter[i]);
        }
    }
}
/*
    The idea is same as above. The only difference is the range of values expected.
    Upper case alphabets range: 65-90 (A-Z)
    Therefore, hastable indexing -> (character_ASCII_code - 65)
    The hashtable size is still fix, 26 characters in the alphabets
 */
// We're assuming the input is all upper case alphabets.
void find_uppercase_alphabet_duplicates_using_hastable_for_counting(char *str){
    
    // Create a hashtable of size 26, corresponding to ASCII of lower case alphabets (97-122)
    int counter[26] ={0}; // Initialize all the elements to 0
    
    int i;
    for(i=0;str[i]!='\0';i++){
        // str[i]-65 will calculate the index corresponding to the current character of the string
        counter[(str[i]-65)]++;
    }
    
    // Print all the duplicate characters in the string
    for(i=0;i<26;i++){
        if(counter[i]>1){
            // The character corresponding to the current index has duplicates
            printf("Character \'%c\' has occured %d times.\n", (char)(i+65), counter[i]);
        }
    }
}

/*
    In this case, we have a total of 26+26= 52 character range, 'a'-'z' and 'A'-'Z'. Therefore,
    hashtable size is 52.
    Q: How do we index into the hashtable?
        upper case alphabet range: 'A' - 'Z' -> 65-90 -> (index 0 - index 25)
        lower case alphabet range: 'a' - 'z' -> 97-122 -> (index 26 - index 51)
 
    Accesing the upper case alphabets from hashtable is easy, just subtract 65 from the character ASCII.
    For lower case alphabets:
            ASCII_lower - (what) = (Index in hashtable)
            97 - x = 26 (for 'a') --> x = 97-26 = 71
            98 - x = 27 (for 'b') --> x = 98-27 = 71
            99 - x = 28 (for 'c') --> x = 99-28 = 71
        Lower case alphabets Hashtable indexing formula -> (char_ASCII_Code - 71 = Hashtable Index)
 */
void find_upper_and_lowercase_alphabet_duplicates_using_hashtable_for_counting(char *str){
    
    // Create hashtable of 52, indices 0-25 for Upper case alphabets, indices 26-51 for lower case alphabets
    int counter[52]={0}; // Initialize hashtable with 0
    
    int i;
    for(i=0;str[i]!='\0';i++){
        
        // Different Hashtable index formula depending on if upper or lower case character
        if(str[i]>='A' && str[i]<= 'Z'){
            // Hashtable indexing formula -> index = (str[i]-65)
            counter[(str[i]-65)]++;
        }else if(str[i]>='a' && str[i]<='z'){
            // Hashtable indexing formula -> index = (str[i]-71)
            counter[(str[i]-71)]++;
        }
    }
    
    // Printing all the duplicates in the given string
    for(i=0;i<52;i++){
        if(counter[i]>1){
            // Different Hashtable index formula depending on if the upper or lower case alphabet
            if(i<26){
                // Hashtable indexing formula for lower case alphabets -> index = (str[i]-65)
                printf("Character \'%c\' is repeated %d times.\n", (char)(i+65),counter[i]);
                
            }else if(i>=26){
                // Hashtable indexing formula for upper case alphabets -> index = (str[i]-71)
                printf("Character \'%c\' is repeated %d times.\n", (char)(i+71),counter[i]);
            }
        }
    }
}
int size_of_string(char *str){

    int i;
    for(i=0;str[i]!='\0';i++);
    return i;
}
/*
        Anagram Def: The string str2 is composed of all the characters in str1.
            
        Anagram can ONLY exist if the two strings are of same size, else they don't.
 
 
        The idea is to use a hashtable of size corresponding to range of ASCII codes
        possible in str1. For each character found in str1, you set the corresponding
        hashtable index to 1.
        
        After setting up the hashtable for str1 string content,
        you scan through str2 and check if corresponding hashtable index of the str1
        is set(or has a count value), if it is, you decrement it, which indicates the corresponding
        character was found in str2. You repeat this for the entire st2.
 
        At the end you check if the hashtable contents are 0, if they are, then str2
        contains all the characters of str1, i.e. its an anagram of str1.
        If any one of str1's hashtable index is not 0, then we can say str2 is not an anagram of
        str1.
 
        The time complexity of this is linear, because first you set up a hashtable for str1,
        then you scan through str2 (which is linear), and for each character, you check hashtable content corresponding to it(which is done in constant time), finally you scan hashtable
        to find the first non-zero index to indicate str2 is not an anagram of str1.
            Therefore, all these linear operations, sum to give you a linear complexity because
            highest degree is still 1.
 */
// Assume the strings contain all lower case alphabets, the idea is same, you can adapt code for
// any. If the string can contain both upper and lower case, you can convert both to same and do
// this operation -> depends on the setup
bool isAnagram(char *str1, char *str2){
    
    
    int i,j; // For sizes of str1 and str2
    
    i = size_of_string(str1);
    j = size_of_string(str2);
    
    if(i!=j){
        // sizes don't match, can't be an anagram
        return false;
    }else{
        // Sizes match, check if str2 is an anagram of str1
        
        // Lower case alphabets ASCII: 97-122
        // Total 26 alphabets, therefore, Hashtable size if 26.
        // Hashtable indexing:  character_ASCII_Code - 97 = index of hashtable
        
        int count[26] ={0}; // Initialize hashtable with 0
        
        // Scan through str1 and fill out hashtable
        for(i=0;str1[i]!='\0';i++){
            count[(str1[i]-97)]++;
        }
        
        // Scan str2 and decrement hashtable content
        for(i=0;str2[i]!='\0';i++){
            count[(str2[i]-97)]--;
        }
        
        // Find first non-zero entry of str1's hashtable,
        // to indicate str2 is not an anagram of str1
        for(i=0;i<26;i++){
            if(count[i]>0){
                // found an character of str1 not found in str2
                return false;
            }
        }
        
        // str2 is an anagram of str1
        return true;
    }
}


int linearSearch_withIndexReturn(char *str, char ch){
    
    int i;
    for(i=0;str[i]!='\0';i++){
        
        if(str[i]==ch){
            // Character found in string
            return i;
        }
    }
    
    // character not found in string
    return -1;
}
/*
    This is a simpler method, where for each character of str2 you check if it exists in str1.
    The idea is to search for the character in str1, if you find it, you replace it with something
    that is not in the range of ASCII codes you expect in str1, this way if you have multiple of
    same character, you will only count it once.
    
    In this method you don't need a hashtable.
 
    NOTE: Anagram can only exist, if the two strings are same size
 */
// We're expecting strings to only have lower case alphabets.
bool isAnagram_using_search(char *str1, char *str2){
    
    int i,j;
    i=size_of_string(str1);
    j=size_of_string(str2);
    
    if(i!=j){
        // The two strings are not same size,
        // str2 can't be an anagram of str1
        return false;
    }else{
        // Str1 and str2 are same size, anagram possible
        
        // Create a copy of str1, don't want to modify original
        char *copy = create_copy(str1);
        
        // Scan str2 and look for each character in str1
        // indexFound stores the index of the character found in str1
        int indexFound=-1;
        for(i=0;str2[i]!='\0';i++){
            
            indexFound = linearSearch_withIndexReturn(copy, str2[i]);
            if(indexFound>=0){
                // Set it to some special character because we're expecting all lower case
                copy[indexFound]='*';
            }
        }
        
        // Check if string 'copy' has all '*', which means str2 is an anagram of str1
        // because all of str1 characters found in str2
        for(i=0;copy[i]!='\0';i++){
            if(copy[i]!='*'){
                // found a character in str1, that was not found in str2
                // return memory allocate for copy first
                free(copy);
                copy=NULL;
                return false;
            }
        }
        
        // Str2 is an anagram of str1
        // return memory allocated for copy
        free(copy);
        copy=NULL;
        return true;
    }
    
}



/*
        Permutation is all possible strings using the characters of the given string.
            
        The permutations of all the characters in the given string can be represented using a
        state-space tree. The procedure used is called Brute Force, which looks at all the possible
        solutions. Brute force can be achieved in many ways, we will look at Backtracking method,
        where you explore one option and then you comeback and explore others in the level. Backtracking can be implemented recursively and iteratively.
        We will look at recursive implementation.
 
        You have two static arrays, one to store the leaf node result and the other
        is to store the flag corresponding to visited node (in this case the taken character from the given string).
        
        On each function call, you first check if the current character in the string is null, if it
        is then you print the result stored in the result array.Else, you scan through the visited node flag array to find character not taken yet. You can take the character and store it in the result array, set the flag corresponding to this character in the visited flag array and call the function again to jump to the next level of the state-space tree.
 
        The argument 'k' is the level of the state-space tree representing all possible permutations
        of the given character string. The last level of the state-space tree is equal to the size of the string, which is (number of characters in the string + null character). Therefore, you can use this 'k' to determine when you've found a possible permuation of the given string.
        
        Summary: You use a visited node flag array to keep track of the character taken in the previous recursive call, this helps you decide which character is available to taken. The result array is used to store the character taken at current call, before calling the function again. When you return from the function call, you have to clear the flag of character last taken, and continue scanning the visited flag array to find the next character available to take.
 
        The max number of possible characters in the given string is usually given, use
        that to create a static array.
            Number of permutations is factorial of number of characters in the string
            
 */
void permuation_of_given_string(char *str, int level){
    
    // Create two arrays, one for keeping track of character taken and one for result
    static int character_taken_flag[100]={0};
    static char permutation[100]; // Result array
    
    if(str[level]=='\0'){
        // You reached the leaf node, print the result
        // after you set the '\0' in the character array to make it string
        permutation[level]='\0';
        printf("Permuations: \'%s\'\n",permutation);
    }else{
        // Scan through the flag array and find the available character
        // copy it over the permutation char array, set flag in the flag array,
        // jump to next level of state-space tree representation of possible permutation
        int i;
        for(i=0;str[i]!='\0';i++){
            // Travelling through the given string
            
            if(character_taken_flag[i]!=1){
                // Character is available
                // Take it
                permutation[level] = str[i];
                // Set flag to indicate you took the character
                character_taken_flag[i]=1;
                // Jump to next level of state-space representation of possible permutation
                permuation_of_given_string(str, level+1);
                // When you return from the next level, after exploring that branch, clear the flag, before continuing scan
                character_taken_flag[i]=0;
            }
        }
    }
}

/*
     Creates a substring from str using the upper and lower indices given.
 */
char* create_substring(char str[], int LowerIndex, int len){
    
    // Allocate memory from the heap
    // +1 is added because indices start from 0, 1 extra space to convert char array to string
    char* substring = (char*)malloc((len+1)*sizeof(char));
    
    // Scan str and get the characters needed
    int i,k; // K needed scan through new string, and i needed to scan throught given string
    for(i=LowerIndex,k=0; k<len;i++,k++){
        // copy the characters from str to substring
        substring[k]=str[i];
    }
    // Add NULL to form a string
    // k is at 'NULL' position, add string terminator
    substring[k]='\0';
    
    // return substring
    return substring;
    
}
/*
    The Questions: Find the minimum substring of searchString that contains all the characters
    in second parameter.
 
    The best way to do it is using a sliding window with two iterators, left and right.
        The right iterator expands the window until you have a substring that contains all the chars
        of second parameter. The length of the substring found is compared to the previously found
        minimum length substring, if the current subtring (that contains all chars of second string)is shorter than previous, you update your variables to hold the start and end indices of the shorted substring indices.
            After finding a valid substring, you try to shrink the window size by moving the left iterator, and check if the resulting substring is still a valid substring (contains all chars of second parameter). You keep shrinking until you don't have a valid string or you've reached the end of the searchString. Once you don't have a valid substring anymore and you haven't reached the end of searchString, you expand your window again by moving the right iterator until you have valid substring or you've reached end of searchString. You repeat this process till left and right reach the end of searchString.
    
    Therefore, the idea of sliding window is simply moving the two pointers to shrink and expand
    window, analyze the string in the window, update your result holders, and try to better
    as you make your way by scanning the given searchString.
    
    In sliding window technique, you only process each char of searchString once (because you create
    a hashmap that gets updated as you shrink and expand your window), therefore the work done is linear, as it depends on the input size.

 
 */
// Assuming searchString has only lowercase alphabets -> ASCII: 97-122
// Hashmap -> simple int array of size 26 -> because indexing starts at 0
// Hash function: 97 -x = 0-> x=97
// For indexing into hashmap: ASCII_CODE -97
// For converting index to ASCII -> index+97
char* minWindowSubstring(char *searchString, char *searchingFor){
    
    
    // Create a hashmap for the frequency of characters in SearchingFor
    // We're assuming we only have lowercase alphabets in both strings
    int* hashmap = (int *)calloc(26,sizeof(int));
    
    // Populate the hashmap
    int i;
    for(i=0;searchingFor[i]!='\0';i++){
        hashmap[(searchingFor[i]-97)]++;
    }
    
    // Store number of unique chars in searchingFor string
    int count_unique_chars = i;
    

    // two iterators to scan the searchString
    // The two iterators start at the front of the string
    int left=0, right=0;
    
    // Result variables
    int minLeft=0,minRight=0, minWindowSize=1000;
    
    
    // scan through the given searchString
    // The left iterator is used to shrink the window size for improving size -> the outer loop
    // The right iterator is used to expand the window to get a valid substring -> Inner loop
    
    while(searchString[left]!='\0'){
        
        // Use left iterator, to find valid substrings that contain chars of
        // of searchingFor string
        // First check if the current character in searchingString is one of the
        // characters required
        if(hashmap[(searchString[left]-97)]>0){
            // found one of the required characters
            // decrement unique chars needed in a valid substring
            count_unique_chars--;
        }
        
        // Update hashmap of searchingFor string to account for current
        // character,
        hashmap[(searchString[left]-97)]--;
        
        // move left iterator forward
        left++;
        
        // check if we found a valid substring
        while(count_unique_chars==0){
            
            // Check if the minimum length of the string is better than our previous
            // minimum left we found
            // plus 1 because indexing starts at 0
            if((left-right)<minWindowSize){
                //found a shorter substring
                //Record the start and end indices of this shorter valid substring
                minRight = right;
                minLeft = left;
                minWindowSize = (left-right);
            }
            
            // We move the right iterator forward to see if we can do better
            // than our current minWindow
            // We need to update the hashtable of searchingFor string
            // before we shrink the window, because the character current
            // position of right could be one of the characters we're looking for
            hashmap[(searchString[right]-97)]++;
            
            // Check if you've lost one of the characters desired
            if(hashmap[(searchString[right]-97)]>0){
                // lost one of the characters needed
                count_unique_chars++;
            }
            // Now we shrink the window
            right++;
        }
            
    }
    
    // At this point, you scanned the entire search string
    // and found a substring of searchString that has all the
    // characters of string searchingFor
    if(minWindowSize==0){
        // Found no subtring in searchingString that has all chars of searchingFor
        return "";
    }
    
    // Return Subtring of searchingString found
    char *substring = create_substring(searchString, minRight, minWindowSize);
    return substring;
    
}
