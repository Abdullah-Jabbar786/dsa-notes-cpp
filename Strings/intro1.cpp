#include <iostream>
using namespace std;


// String is set of characters or an array of chars, concepts from C lang 
// '\0' is Null char and it is used to check end of the string

// a = 97 ---- z = 122
// A = 65 ---- Z = 90
// 48 = 0 ---- 57 = 9 (digits) 

// Declaring and initializing a string.
// char name1[10] = {'j','o','h','n','\0'}; // Method 1 (manual)

// char name2[] = "john"; // Method 2 (easiest)

// const char* name3 = "john"; // Method 3 (read-only), automatically includes '\0'.


// if C lang use printf("%s", name); and scanf("%s",name); to read.

void convert()
{
    char A[] = "WELCOME";
    // for lower case
    for(int i=0; A[i] != '\0'; i++)
    {
        A[i] += 32; // Subtract if vice versa.
    }
    cout<<A<<endl;
}

void count_vc()
{
    //Counting Vowels and Consonants
    int vcount = 0, ccount = 0;

    char B[] = "How are you";

    for(int i=0; B[i] != '\0'; i++)
    {
        if(B[i] == 'a' || B[i] == 'e' ||B[i] == 'i' || B[i] == 'o' || B[i] == 'u' || B[i] == 'A' || B[i] == 'E' || B[i] == 'I' || B[i] == 'O' || B[i] == 'U')
        {
            vcount++;
        }
        else if(B[i] >= 65 && B[i]<=90 || B[i] >= 97 && B[i]<=122 )
        {
            ccount++;
        }
    }
    cout<<"Number of Vowels: "<<vcount<<endl<<"Number of Consonants: "<<ccount;
}

//Counting Spaces and Number of Words.
void count_spaces()
{
    char C[] = "Believe in Yourself";
    
    int space_count = 0;
    // You will get number of words by adding + 1 to num of spaces

    for(int i=0; C[i] != '\0'; i++)
    {
        if(C[i] == ' ' && C[i-1] != ' ')// 2nd condition is for checking white spaces means 2 or more spaces which are together "I am  Abdullah" 2 spaces after am.
        {
            space_count++;
        }
    }
    cout<<"Number of Spaces: "<<space_count<<endl;
    cout<<"Number of Words: "<<space_count+1<<endl;
}


//Validate a string
int valid()
{
    char *name = "Abd!786"; // '!' is invalid.
    for(int i=0; name[i] != '\0'; i++)
    {
        if(!(name[i] >= 65 && name[i]<=90) && !(name[i] >= 97 && name[i]<=122) && !(name[i] >= 48 && name[i]<=57))
        {
            return false; // invalid letter
        }
    }
    return true;
}

//Comparing Strings
void Compare()
{
    char string1[] = "Painter";
    char string2[] = "Painting";
    
        int i = 0;

    while (string1[i] != '\0' && string2[i] != '\0')
    {
        if (string1[i] != string2[i])
        {
            if (string1[i] < string2[i])
                cout << "string1 is smaller" << endl;
            else
                cout << "string1 is greater" << endl;
            return;
        }
        i++;
    }

    // If one string ends earlier
    if (string1[i] == '\0' && string2[i] == '\0')
    {
        cout << "Both strings are equal" << endl;
    }
    else if (string1[i] == '\0')
    {
        cout << "string1 is smaller" << endl;
    }
    else
    {
        cout << "string1 is greater" << endl;
    } 
}

//Palindrome
//First Reverse then Compare.
void Palindrome_1()
{
    char str[] = "madam"; // you can change this to test
    char rev[100];        // enough space to store reversed string

    int i = 0, j = 0;

    // Find length
    while (str[i] != '\0')
    {
        i++;
    }
    int len = i;

    // Copy in reverse
    for (i = len - 1; i >= 0; i--, j++)
    {
        rev[j] = str[i];
    }
    rev[j] = '\0'; // null terminate reversed string

    // Compare original and reversed
    int k = 0;
    while (str[k] != '\0')
    {
        if (str[k] != rev[k])
        {
            cout << "Not a Palindrome" << endl;
            return;
        }
        k++;
    }

    cout << "It is a Palindrome" << endl;
}

//Palindrome Check without extra array.
//No need to actually reverse the string or do any swaps — just check if characters at symmetric positions match

void Palindrome_2()
{
    char str[] = "madam"; // change this string to test

    int i = 0;

    // Find length
    while (str[i] != '\0')
    {
        i++;
    }
    int len = i;

    // Compare from both ends
    int start = 0;
    int end = len - 1;

    while (start < end)
    {
        if (str[start] != str[end])
        {
            cout << "Not a Palindrome" << endl;
            return;
        }
        start++;
        end--;
    }

    cout << "It is a Palindrome" << endl;
}

//Finding Duplicates in a String.
// 1. Compare with other letters.               
// 2. Using Hash Table. (Similar to integers Arrays)     
// 3. Using Bits.               

// 2. Using Hash Table Concept

void HT_Duplicate() //O(n)
{
    char D[] = "abdullah";
    int H[26] = {0}; // We use H[26] to count lowercase letters (a–z). Each letter goes to index = letter - 'a'. As we scan the string, we increase count at that index. To support uppercase or digits, H[] must be larger.

    for(int i=0; D[i] != '\0'; i++)
    {
        H[D[i] - 97]++;
    }
    for(int i=0; i<26; i++)
    {
        if(H[i] > 1)
        {
            cout<<"Duplicate Element: "<<char(i+97)<<endl<<"Frequency: "<<H[i]<<endl;
        }
    }
}

// 3. Using Bitwise Operations: 
//      1. Left shift<<
//      2. Bits OR (Merging) // setting the bit as on / off in an array is merging and it is done by applying OR operation with another array at the same bit and then storing the reult at the same index in the array in which we have to set a bit as on.
//      3. Bits AND (Masking) // Checking whether a certain bit is on in an array is Masking and it is done by applying AND operation with another array having 1 on the same index as the first array where we have to check it on / off status.

// || Logical OR and | Bitwise OR. 

void Bit_Duplicate()
{
    char E[] = "finding";

    int H=0; // Bitwise hash tracker (all 0s initially)

    int x=0; // Will hold shifted bits to represent each letter
    
    for(int i=0; E[i] != '\0'; i++)
    {
        x=1;
        x=x<<E[i]-97; //OR operation, Shifts left by position of char in alphabet

        if((x&H) > 0) //AND operation, Checks if bit is already set in H
        {
            cout<<"Duplicate is: "<<E[i]<<endl;
        }
        else
        {
            H = x | H; // Sets the bit in H
        }
    }
}


// Check for Anagram.
// Anagram are words of same Alphabets like listen and silent, earth and heart etc

//1. Check simply using a nested for loop but time complexity will be O(n^2)
//2. Use Hash Table Mathod

// Function: Assuming There are no Duplicates in the Anagrams but you can use the same if the string contains Duplicates for exp : observe and verbose. We can use Bit sets also the concept is covered above but there should be no duplicate letters in the strings.

void Anagram()
{
    // Assuming all are lower case.
    char N[] = "decimal";
    char G[] = "medical";
    int i, H[26] = {0};
    
    // Find lengths
    int len1 = 0;
    while(N[len1] != '\0')len1++;
    
    int len2 = 0;
    while(G[len2] != '\0')len2++;
    
    // Step 2: If lengths differ, not anagram
    if(len1 != len2)
    {
        cout<<"Not Anagram, lengths mismatch"<<endl;
    }
    else
    {
        //First increment all the index in the hash table which are equal to Ascii values of the chars
        for(i=0; N[i]!='\0'; i++)
        {
            H[N[i] - 97]++;
        }
        
        // Then decrement every index in the hash table using a 2nd loop controlled by the other array containing another string so this will decrement the index which are equal to the Ascii values of chars in the other string
        for(i=0; G[i]!='\0'; i++)
        {
            H[G[i] - 97]--;
            if(H[G[i] - 97] < 0)
            {
                cout<<"Not Anagram."<<endl;
                break;
            }
        }
        if(G[i] == '\0')
        {
            cout<<"It's Anagram."<<endl;
        }
        
    }
}


//Permutation of a string.

// State Space Tree show routes for A,B,C and there 6 possible solutions like ABC, ACB, BAC, BCA, CAB, CBA
// Brute Force means finding out all possible permutations.
// Recursion can be use to achieve Back Tracking.

void permutation_1(char S[], int k)
{
    static int A[10] = {0};
    static char Res[10]; //Result Array
    int i;

    if(S[k] == '\0')
    {
        Res[k] = '\0';
        cout<<Res<<endl;
    }
    else
    {
        for(i=0; S[i] != '\0'; i++)
        {
            if(A[i] == 0)
            {
                Res[k] = S[i];
                A[i] = 1;
                permutation_1(S,k+1);
                A[i] = 0;
            }
        }
    }
}


//2nd Method for Permuations. This procedure will be using swapping.

void swap(char *a, char *b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

//Function for Permutation.
void permutation_2(char S[], int l, int h) // l = Low and h = High.
{
    int i;
    if(l==h)
    {
        cout<<S<<endl;
    }
    else
    {
        for(i=l; i<=h;i++)
        {
            swap(&S[l], &S[i]);
            permutation_2(S,l+1,h);
            swap(&S[l], &S[i]);
        }
    }
}

int main()
{
    
    // convert();
    // count_vc();
    // count_spaces();
    // Compare();
    // HT_Duplicate();
    // Bit_Duplicate();
    // Anagram();


    // Calling of Permutation Function.
    char S[] = "ABC";

    //Method 1
    // permutation_1(S,0);
    
    //Method 2
    // permutation_2(S,0,2);

    return 0;
}