#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// Declarations of the two functions you will implement
// Feel free to declare any helper functions
void printPuzzle(char** arr, int n);
void searchPuzzle(char** arr, int n, char** list, int listSize);
void searchWord(int j, int k, int gridsize, char** arr, char** list, int listPos);

// Main function, DO NOT MODIFY (except line 52 if your output is not as expected -- see the comment there)!!!	
int main(int argc, char **argv) {
    int bSize = 15;
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <puzzle file name>\n", argv[0]);
		return 2;
	}
    int i, j;
    FILE *fptr;
    char **block = (char**)malloc(bSize * sizeof(char*));
	char **words = (char**)malloc(50 * sizeof(char*));

    // Open file for reading puzzle
    fptr = fopen(argv[1], "r");
    if (fptr == NULL) {
        printf("Cannot Open Puzzle File!\n");
        return 0;
    }

	// Read puzzle block into 2D arrays
    for(i = 0; i < bSize; i++) {
        *(block+i) = (char*)malloc(bSize * sizeof(char));

        fscanf(fptr, "%c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n", *(block+i), *(block+i)+1, *(block+i)+2, *(block+i)+3, *(block+i)+4, *(block+i)+5, *(block+i)+6, *(block+i)+7, *(block+i)+8, *(block+i)+9, *(block+i)+10, *(block+i)+11, *(block+i)+12, *(block+i)+13, *(block+i)+14 );
    }
	fclose(fptr);

	// Open file for reading word list
	fptr = fopen("states.txt", "r");
	if (fptr == NULL) {
        printf("Cannot Open Words File!\n");
        return 0;
    }
	
	// Save words into arrays
	for(i = 0; i < 50; i++) {
		*(words+i) = (char*)malloc(20 * sizeof(char));
		fgets(*(words+i), 20, fptr);		
	}
	
	// Remove newline characters from each word (except for the last word)
	for(i = 0; i < 49; i++) {
		*(*(words+i) + strlen(*(words+i))-2) = '\0'; // Change -2 to -1 if line 58 outputs words with the last character missing
	}
	
	// Print out word list
	printf("Printing list of words:\n");
	for(i = 0; i < 50; i++) {
		printf("%s\n", *(words + i));		
	}
	printf("\n");
	
	// Print out original puzzle grid
    printf("Printing puzzle before search:\n");
    printPuzzle(block, bSize);
	printf("\n");

	// Call searchPuzzle to find all words in the puzzle
	searchPuzzle(block, bSize, words, 50);
	printf("\n");
	
	// Print out final puzzle grid with found words in lower case
    printf("Printing puzzle after search:\n");
    printPuzzle(block, bSize);
	printf("\n");
	
    return 0;
}

void printPuzzle(char** arr, int n) {
	// This function will print out the complete puzzle grid (arr). It must produce the output in the SAME format as the samples in the instructions.
	// Your implementation here
for(int i = 0; i < n; i++){
        printf("\n");
        for(int j = 0; j < n; j++){
            printf("%c ", *(*(arr+i)+j)); //arr[i]+[j]
		}
}

}

void searchPuzzle(char** arr, int n, char** list, int listSize) {
	// This function checks if arr contains words from list. If a word appears in arr, it will print out that word and then convert that word entry in arr into lower case.
	// Your implementation here
	for(int i = 0; i < listSize; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                    searchWord(j, k, n, arr, list, i);
                }
            }

        }

}


void searchWord(int j, int k, int gridsize, char** arr, char** list, int listPos){
    int wordlength = strlen(*(list+listPos));
    if(j+wordlength <= gridsize){ //Horizontal
        int i = 0;
        while(i < wordlength && *(*(arr+(j+i))+k) == *(*(list+listPos)+i)){
            i++;
        }
        if(i == wordlength){
            while(i > 0 && *(*(arr+(j+i))+k) == *(*(list+listPos)+i)){
            putchar(tolower(*(*(arr+(j+i))+k)));
            i--;
            }
            for(i = 0; i < wordlength; i++)
                printf("%c", *(*(list+listPos)+i));
        }
    }

    if(k+wordlength <= gridsize){ //Vertical
        int i = 0;
        while(i < wordlength && *(*(arr+j)+(k+i)) == *(*(list+listPos)+i)){
            i++;
        }
        if(i == wordlength){
            while(i > 0 && *(*(arr+j)+(k+i)) == *(*(list+listPos)+i)){
             putchar(tolower(*(*(arr+(j+i))+k)));
            i--;
            }
            for(i = 0; i < wordlength; i++){
                printf("%c", *(*(list+listPos)+i));
            }
        }
    }

    if(j+wordlength <= gridsize && k+wordlength <= gridsize){ //Diagonal
        int i = 0;
        while(i < wordlength && *(*(arr+(j+i))+k) == *(*(list+listPos)+i)){
            i++;
        }
        if(i == wordlength){
            while(i > 0 && *(*(arr+(j+i))+(k+i)) == *(*(list+listPos)+i)){
             putchar(tolower(*(*(arr+(j+i))+(k+i))));
            i--;
            }
            for(i = 0; i < wordlength; i++)
                printf("%c", *(*(list+listPos)+i));
        }
    }


}
