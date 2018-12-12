#include <iostream>
#include <string>

int main()
{
	
	return 0;
}

// Converts text to lowercase and removes spaces and any characters that are not alphabetic
public static String convertText()
{
	
}

// Prepares the text to be sent into cipher()
public static String cipherShell(String toCipher, String initVector, String keyword)
{
	//declare and initialize variables
    String finishedCipher = "";
    String block = "";
    String cipheredBlock = "";
    int blockLength = initVector.length();
        
    //convert initVector into char array
    char [] prevBlock = new char[blockLength]; //prev block starts out as IV, then updates
    for(int i = 0; i < blockLength; i++)
    {
        prevBlock[i] = initVector.charAt(i);
    }
    //calculate number of blocks in plaintext and send each to cipher()
        
    //calculate number of characters in plaintext
    int numChars = toCipher.length();
        
    //calculate number of blocks in plaintext
    int numBlocks = numChars/blockLength;
    if((numChars/blockLength)%6 > 0)
    {
        numBlocks++;
    }
        
    //send each block through cipher
    for(int i = 0; i < numBlocks; i++)
    {
        //get next block
        if(toCipher.length() >= blockLength)
        {
            block = toCipher.substring(0, blockLength);
        }
        else
        {
            block = toCipher;
            
            //calculate how many padded characters to add
            int numPads = blockLength - toCipher.length();
            //add on each x pad
            for(int j = 0; j < numPads; j++)
            {
                block += "x";
            }
        }
        //remove previous block from plaintext
        if(i != numBlocks - 1)
        {
            toCipher = toCipher.substring(blockLength);
        }
        //cipher removed block and store in cipheredBlock
        cipheredBlock = cipher(block, keyword, prevBlock);
        //add cipheredBlock to finishedCipher
        finishedCipher += cipheredBlock;
    }
    
    return finishedCipher;	
}

// Applies the cipher to the text, block by block
public static String cipher(String block, String keyword, char[] prevBlock)
{
	//declare and initialize variables
    char letter = 'a';
    int xorNum = 0;
    int vigNum = 0;
    String finishedBlock = "";
    for(int i = 0; i < block.length(); i++)
    {
        //take single char from block
        letter = block.charAt(i);
        //convert to numeric value
        int numberBlock = letter - 'a';
        int numberPrev = prevBlock[i] - 'a';
        int numberKey = keyword.charAt(i) - 'a';
        //apply XOR
        xorNum = (numberBlock + numberPrev)%26;
        //apply Vigenere
        vigNum = (numberKey + xorNum)%26;
        //convert back to letter
        letter = (char)(vigNum + 'a');
        //add to finishedBlock
        finishedBlock += letter;
        //add that letter to the updated prevBlock
        prevBlock[i] = letter;
    }
    
    return finishedBlock;
}

//prints output
public static void printOutput(String toPrint)
{
	
}