#include<iostream>
#include<conio.h>
#include<string.h>
#include<cctype>
#include<cmath>
#include<fstream>
using namespace std;
//global file name variable
char fileName[20];
//function prototypes
void textEnc(string encrypt);
void textDec(string decrypt);
int numEnc(int number);
int numDec(int number);
int main() {
	int choice,count,value,encNum[100],decNum[100];
	char filing;
	string encrypt,decrypt;
	start:
		cout <<"Encryption-Decryption Algorithm"<< endl;
		cout <<"1. Text Encryption"<< endl;
		cout <<"2. Text Decryption"<< endl;
		cout <<"3. Number Encryption"<< endl;
		cout <<"4. Number Decryption"<< endl;
		cout <<"5. Exit"<< endl;
		cin >>choice;
		switch(choice){
			case 1:
				system("cls");
				cout<<"Text Encryption: "<<endl;
				fflush(stdin);
				cout<< "Do you want to read the text from file?(Y/N): ";
				cin>> filing;
				if(filing == 'Y' || filing == 'y'){
					fflush(stdin);
					cout<<"Please enter the name of text file along with extension: ";
					cin>>fileName;
					ifstream fptr;
					fptr.open(fileName);
					if(fptr == NULL){
						cout<<"File not found";
						break;
					}
					getline(fptr,encrypt);
					textEnc(encrypt);
					fptr.close();
				}else {
					fflush(stdin);
					cout<<"Enter the string: ";
					getline(cin,encrypt);
					textEnc(encrypt);	
				}
				goto start;
				break;
			case 2:
				system("cls");
				cout<<"Text Decryption: "<<endl;
				fflush(stdin);
				cout<< "Do you want to read the text from file?(Y/N): ";
				cin>> filing;
				if(filing == 'Y' || filing == 'y'){
					fflush(stdin);
					cout<<"Please enter the name of text file along with extension: ";
					cin>>fileName;
					ifstream fptr;
					fptr.open(fileName);
					if(fptr == NULL){
						cout<<"File not found";
						break;
					}
					getline(fptr,decrypt);
					textDec(decrypt);
					fptr.close();
				}else {
					fflush(stdin);
					cout<<"Enter the string: ";
					getline(cin,decrypt);
					textDec(decrypt);	
				}
				goto start;
				break;
			case 3:
				system("cls");
				cout<<"Number Encryption: "<<endl;
				fflush(stdin);
				cout<< "Enter the number of digits you want to enter: ";
				cin>> count;
				fflush(stdin);
				cout<< "Enter the number: ";
				cin>> value;
				for(int i=0;i<count;i++){
					int temp = value %10;
					value /= 10;
					encNum[i] = numEnc(temp); 
				}
				cout<<"Secret Message: "<< endl;
				for(int i=0;i<count;i++){
					cout<<encNum[i]<<"\t"<<endl;
				}
				goto start;
				break;
			case 4:
				system("cls");
				cout<<"Number Decryption: "<<endl;
				fflush(stdin);
				cout<< "Enter the number of digits you want to enter: ";
				cin>> count;
				fflush(stdin);
				cout<< "Enter the number: ";
				cin>> value;
				for(int i=0;i<count;i++){
					int temp = value %10;
					value /= 10;
					decNum[i] = numDec(temp); 
				}
				cout<<"Original Message: "<<endl;
				for(int i=0;i<count;i++){
					cout<<decNum[i]<<"\t"<<endl;
				}
				goto start;
				break;
			case 5:
				system("cls");
				exit(0);
				break;
			default:
				cout<<"Invalid input"<<endl;
				goto start;
				break;
		}
}
void textEnc(string encrypt){
	string key;
	cout<< "Enter the key: ";
	fflush(stdin);
	getline(cin,key);
	char newKey[100],encryption[100];
	int j=0;
	//remove punctuations from string and capitalize
	for(int i=0;i<encrypt.size();i++){
		if(!ispunct(encrypt[i]) && encrypt[i]!=' '){
			encrypt[j] = toupper(encrypt[i]);
			j++;
		}
	}
	encrypt[j]='\0';
	int stringLen = j;
	int encryptNum[stringLen],stringNum[stringLen],keyNum[stringLen];
	//convert into numbers
	for(int i=0;i<stringLen;i++){
		stringNum[i] = encrypt[i]-'A';
	}
	//remove punctuations from key and capitalize
	for(int i=0,j=0;i<key.size();i++){
		if(!ispunct(key[i]) && key[i]!=' '){
			key[j] = toupper(key[i]);
			j++;
		}
	}
	key[j]='\0';
	int keyLen = key.size();
	//repititions of key
	int k=0;
	for(int i=0,j=0;i<stringLen;i++){
		if(j == keyLen){
			j=0;
		}
		newKey[i] = key[j];
		j++;
		k++;
	}
	newKey[k]='\0';
	//convert key into numbers
	for(int i =0;i<stringLen;i++){
		keyNum[i]= newKey[i] - 'A';
	}
	//comparison
	for(int i=0;i<stringLen;i++){
		encryptNum[i] = (stringNum[i] + keyNum[i]); 
	}
	//encryption
	for(int i=0,k=0;i<stringLen;i++){
		encryption[i] = (encryptNum[i] %26) + 'A';
		k++;
	}
	encryption[k]='\0';
	cout<<"Encrypted Message: "<< encryption << endl;
	//if file name exists ,replace the contents of the file
	ofstream fptr;
	fptr.open(fileName);
	fptr<<encryption;
	fptr.close();
}
void textDec(string decrypt){
	string key;
	cout<< "Enter the key: ";
	fflush(stdin);
	getline(cin,key);
	char newKey[100],decryption[100];
	int j=0;
	//remove punctuations and capitalize
	for(int i=0;i<decrypt.size();i++){
		if(!ispunct(decrypt[i]) && decrypt[i]!=' '){
			decrypt[j] = toupper(decrypt[i]);
			j++;
		}
	}
	decrypt[j] = '\0';
	int stringLen = j;
	int decryptNum[stringLen],stringNum[stringLen],keyNum[stringLen];
	//conversion into numbers
	for(int i=0;i<stringLen;i++){
		stringNum[i] = decrypt[i] - 'A';
	}
	//remove punctuations and capitalize key
	for(int i=0,j=0;i<key.size();i++){
		if(!ispunct(decrypt[i]) && decrypt[i] != ' '){
			key[j] = toupper(key[i]);
			j++;
		}
	}
	key[j] = '\0';
	//generate a repititive key
	int k=0;
	for(int i=0,j=0;i<stringLen;i++){
		if(j==key.size()){
			j=0;
		}
		newKey[i] = key[j];
		j++;
		k++;
	}
	newKey[k] = '\0';
	//convert key into numbers
	for(int i=0;i<stringLen;i++){
		keyNum[i] = newKey[i] - 'A';
	}
	//comparison
	for(int i=0;i<stringLen;i++){
		decryptNum[i] = stringNum[i] - keyNum[i] + 26;
	}
	//Decryption
	for(int i=0,j=0;i<stringLen;i++){
		decryption[i] = (decryptNum[i] % 26) + 'A';
		j++;
	}
	decryption[j] = '\0';
	cout<<"Original Message: "<<decryption << endl;
	//if file name exists ,replace the contents of the file
	ofstream fptr;
	fptr.open(fileName);
	fptr<<decryption;
	fptr.close();
}
int numEnc(int number){
	int modulus = 14,exponent = 5;
	long long int product = 1;
	//public key= (5,14)
	//raise number to the exponent
	product = pow(number,exponent);
	//take remainder from 14
	int result = product % 14;
	return result;
}
int numDec(int number){
	int modulus = 14, exponent = 11;
	long long int product = 1;
	//private key=(11,14)
	//raise number to exponent
	product = pow(number,exponent);
	//take exponent by 14
	int result = product % 14;
	return result;
}
