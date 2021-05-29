//ENCRYPTION DECRYPTION ALGORITHM
// MADE BY WAHAJ JAVED(20K-0208) AND IMAMA AWAIS(20K-0125)

//Inlude libraries
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//Declare prototypes
void loadingBar();
int vigenereEnc(char string[100]);
int RSAEnc(int RSAEnc);
int vigenereDec(char decString[100]);
int RSADec(int RSADec);

int main() {
	loadingBar();
	//7-grey background
	//0-black foreground
	system("color 70");
	
	//Main Menu
	printf("********************************************* \n");
	printf("WELCOME TO ENCRYPTION DECRYPTION ALGORITHM\n");
	printf("********************************************* \n");
	int value,i,*decNum,*encNum,n,temp;
	char choice,string[100],decString[100];
	
	//label
	start:
		printf("What task would you list to perform: \n");
		printf("1.Text Encryption\n");
		printf("2.Number Encryption\n");
		printf("3.Text Decryption \n");
		printf("4.Number Decryption \n");
		printf("5.Exit \n");
		printf("Enter your choice: ");
		scanf(" %c",&choice);	
		switch(choice){
			case '1':
				
				// VIGENERE ENCRYPTION
				system("cls");
				printf("************************* \n");
				printf("     TEXT ENCRYPTION \n");
				printf("************************* \n");
				printf("Enter the string: ");
				fflush(stdin);
				gets(string);
				vigenereEnc(string);
				printf("\n \n \n \n");
				break;
				
			case '2':
				system("cls");
				printf("************************* \n");
				printf("    NUMBER ENCRYPTION \n");
				printf("************************* \n");
				
				// RSA ENCRYPTION
				printf("How many digits does the number of your choice have: ");
				scanf("%d",&n);
				encNum = (int *)calloc(n,n*sizeof(int));
				printf("Enter the number: ");
				scanf("%d",&value);
				for(i=0;i<n;i++){
					temp = value %10;
					value=value/10;
					encNum[i] =RSAEnc(temp);
				}
				printf("Encrypted Numbers: ");
				for(i=0;i<n;i++){
				printf("%d ",encNum[i]);
				}
				free(encNum);
				printf("\n \n \n \n");
				break;
				
			case '3':
				system("cls");
				printf("************************* \n");
				printf("     TEXT DECRYPTION \n");
				printf("************************* \n");
				
				// VIGENERE DECRYPTION
				fflush(stdin);
				printf("Enter the string to be decrypted: ");
				scanf("%s",&decString);
				vigenereDec(decString);
				printf("\n \n \n \n");
				break;
				
			case '4':
				system("cls");
				printf("************************* \n");
				printf("    NUMBER DECRYPTION \n");
				printf("************************* \n");
				
				// RSA DECRYPTION
				printf("How many digits does the number of your choice have: ");
				scanf("%d",&n);
				decNum = (int *)calloc(n,n*sizeof(int));
				printf("Enter the number: ");
				scanf("%d",&value);
				for(i=0;i<n;i++){
					temp = value %10;
					value=value/10;
					decNum[i] =RSADec(temp);
				}
				printf("Original Number: ");
				for(i=0;i<n;i++){
				printf("%d",decNum[i]);
				}
				free(decNum);
				printf("\n \n \n \n");
				break;
				
			case '5':
				system("cls");
				printf("Thank You! ");
				printf("\n \n \n \n");
				printf("MADE BY: \n WAHAJ JAVED(20K-0208) \n IMAMA AWAIS(20K-0125)\n");
				printf("Press any key to exit.");
				getch();
				exit(0);
				break;
				
			default:
				printf("Select a value from the given list: \n");
				printf("\n \n \n \n");
				break;
				
		}
		goto start;
		return 0;
}
void loadingBar() { 
 int i;
    // 7 - white background, 
    // 0 - black Foreground 
    system("color 70"); 
  
    // Initialize char for printing 
    // loading bar 
    char a = 177, b = 219; 
  
    printf("\n\n\n\n");
	printf("\n\n\n\n\t\t\t\t      Encryption Decryption Algorithm"); 
    printf("\n\n\n\n\t\t\t\t\tLoading Database...\n\n"); 
    printf("\t\t\t\t\t"); 
  
    // Print initial loading bar 
    for (i = 0; i < 26; i++) 
        printf("%c", a); 
  
    // Set the cursor again at the starting 
    // point of loading bar 
    printf("\r"); 
    printf("\t\t\t\t\t"); 
  
    // Print loading bar progress 
    for (i = 0; i < 26; i++) { 
        printf("%c", b); 
  
        // Sleep for 0.12 second 
        Sleep(100); 
    }
	system("cls"); 
} 
int vigenereEnc(char *string){
	FILE *eptr;
	int i,j;
	char key[100],newKey[100],Encryption[100] ;
	int stringNum[100],keyNum[100],cipherNum[100];
	
	//Capitalize and remove puctuations from the the string
	j=0;
	for(i=0;i<strlen(string);i++){
		if(!ispunct(string[i])&& string[i]!=' '){
			string[j]=toupper(string[i]);
			j++;
		}
	}
	string[j]='\0';
	
	//convert string into numerical form
	for(i=0;i<strlen(string);i++){
		stringNum[i]= string[i]-'A';
	}
	
	//Get the key
	printf("Enter the key without spaces: ");
	gets(key);
	
	//generate a repititive key
	for(i=0,j=0;i<strlen(string);i++,j++){
		if(j==strlen(key)){
			j=0;
		}
		newKey[i]=key[j];
	}
	newKey[i]='\0';
	
	//Capitalize the key
	j=0;
	for(i=0;i<strlen(newKey);i++){
		newKey[j]=toupper(newKey[i]);
		j++;
	}
	newKey[j]='\0';
	
	//convert key into numerical form
	for(i=0;i<strlen(newKey);i++){
		keyNum[i]=newKey[i]-'A';
	}
	
	//calculate Cipher number
	for(i=0;i<strlen(string);i++){
		cipherNum[i]=stringNum[i]+keyNum[i];
	}
	
	//Encryption of the message
	for(i=0;i<strlen(string);i++){
		Encryption[i]= (cipherNum[i] % 26) + 'A';
	}
	Encryption[i]='\0';
	printf("Secret Message: ");
	puts(Encryption);
	
	//put the key and the secret message in a file
	eptr = fopen("Encrypted data.txt","w");
	if(eptr == NULL){
		printf("File could not be created.");
		exit(1);
	}
	fprintf(eptr,"Key: %s\n",key);
	fprintf(eptr,"Secret Message: %s",Encryption);
	fclose(eptr);
}

int vigenereDec(char *decString){
	FILE *dptr;
	int i,j;
	char decKey[100],decNewKey[100],Decryption[100];
	int decStringNum[100],decKeyNum[100],decryptNum[100];
	
	//capitalize and remove spaces from string
	j=0;
	for(i=0;i<strlen(decString);i++){
		if(!ispunct(decString[i])&& decString[i]!=' '){
			decString[j]=toupper(decString[i]);
			j++;
		}
	}
	decString[j]='\0';
	
	//convert string to numerical form
	for(i=0;i<strlen(decString);i++){
		decStringNum[i]= decString[i]-'A';
	}
	decStringNum[i]='\0';
	
	//Get the key
	printf("Enter the key without spaces: ");
	scanf("%s",&decKey);
	
	//generate a repititive key
	for(i=0,j=0;i<strlen(decString);i++,j++){
		if(j==strlen(decKey)){
			j=0;
		}
		decNewKey[i]=decKey[j];
	}
	decNewKey[i]='\0';
	
	//Capitalize the key
	j=0;
	for(i=0;i<strlen(decNewKey);i++){
		decNewKey[j]=toupper(decNewKey[i]);
		j++;
	}
	decNewKey[j]='\0';
	
	//convert key into numerical form
	for(i=0;i<strlen(decNewKey);i++){
		decKeyNum[i]=decNewKey[i]-'A';
	}
	
	//Decryption number
	for(i=0;i<strlen(decString);i++) {
		decryptNum[i] = (decStringNum[i] - decKeyNum[i] + 26) % 26;
	}
	for(i=0;i<strlen(decString);i++) {
		Decryption[i] = decryptNum[i]+ 'A';
	}
	Decryption[i]='\0';
	printf("Original text: ");
	printf("%s",Decryption);
	
	// put the key and decrypted text into a separate file
	dptr = fopen("Decrypted data.txt","w");
	if(dptr == NULL){
		printf("File could not be created.");
		exit(1);
	}
	fprintf(dptr,"Key: %s \n",decKey);
	fprintf(dptr,"Original text: %s",Decryption);
	fclose(dptr);
}

int RSAEnc(int RSAenc){
	
	//initialize variables
	int encryptionExp = 5,modulus = 14,encryptedCipher;
	long long int encProduct = 1;
	int modedEnCipher,i,j;
	
	//Raise the number to the power according to the key
	//Public Key=(5,14)
	for (i=1;i<=encryptionExp;i++) {
		encProduct = encProduct * RSAenc;
	}
	
	//The remainder by the key is the encrypted number
	encryptedCipher = (encProduct % modulus);
	
	//return encrypted number
	return encryptedCipher;
}
int RSADec(int RSAdec){
	
	//Initialize variables
	int decryptionExp = 11,modulus = 14;
	int decryptedCipher,i,j;
	long long int decProduct = 1;
	
	//raise the encrypted number to a speific power
	//Private key = (11,14)
	for(j=1;j<=decryptionExp;j++) {
		decProduct = decProduct * RSAdec;
	}
	
	//The remainder by the key is the Original number
		decryptedCipher = (decProduct % modulus);
		
	//return the original number
	return decryptedCipher;		
}
