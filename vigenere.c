//libraries to include
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

//get a single command line argument of a non-negaitive integer, this will be used as the key to change the plaintext to ciphertext
int main(int argc, string argv[])
{
//define variables
string p_txt; //defined here becasue I use them in both the first if loop and the second set of loops.
string key;

    // if there is a single command line argument ask for plaintext input, if not, error
    if (argc != 2)//**why argc of 2 and not 1 if we index from 0 shouldn't the file name be 0 and the input that we want be 1?**
       
        //error message if there is no command line argument
        {
        printf("***error error will robinson***\n");
        return 1;
        }

    int keylen=strlen(argv[1]);//find and define the length of the key from the command line argument
    
    for (int k=0; (k<keylen-1);k++) //iterate over the key
    {
        if (isalpha(argv[1][k])==0)//check to make sure it is a letter
        {
            printf("***error error not alpha***\n");
            return 1;
        }
    }

    //ask user for the plaintext to be encoded.
    printf("plaintext:");
    p_txt=get_string ();
    key= (argv[1]);

    printf("ciphertext: ");
    
    for (int i = 0, j=0; i< strlen(p_txt); i++)//iterate over the plaintext
    {
        if (p_txt[i]>='a' && p_txt[i]<='z')  //if the char of plaintext is lowercase
        {    
            printf("%c",((p_txt[i] -'a' + (toupper(key [j])-'A'))%26 + 97)); //print the encoded letter. For the letter of the ptext, subtract lowercase "a"; add that to the lerrer of the key that we are using, changed to upper and subtract "A", use the remainder of that and subtract "A". 
            j++; //increment the key by 1
            if (j >= keylen){j=0;}// wrap the key when you run out of letters
        }
        else if (p_txt[i]>='A' && p_txt[i]<='Z')//if the char of plaintext is uppercase
        {
            printf("%c",((p_txt[i] -'A' + (tolower(key [j])-'a'))%26 + 65)); //use the remainder of key/26 and add the remainder to char of p_txt in position i 
            j++;
            if (j >= keylen){j=0;}
        }
        else
        {
            printf("%c",p_txt[i]); //else return the character as it was entered into plaintext
        }
    }
printf("\n");
return 0;
}
