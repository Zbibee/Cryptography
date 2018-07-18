//Zbigniew Smaza szyfr Homofoniczny
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <time.h>
using namespace std;

void encryption(int tab_key[28][100], int tab[100], string text){
	
	int variable;
	for(int i=0; i<28; i++){
		variable = 0;
		for(int j=0; j< text.size(); j++){ 
			if(text[j]-97 == i ){ 
				tab[j] = tab_key[i][variable];
				variable++; 
			}
			if(i == 27 and text[j] == ' '){
				tab[j] = tab_key[i][variable];
				variable++;
			}
		}
	}
	cout<< "\nEncrypted text: ";
	for(int i=0; i<text.size(); i++){
		cout << tab[i] << " | ";
	}
}

void decryption(int tab_key[28][100], int tab[100], int length){
	string decrypted;
		for(int z=0; z<length; z++){
			for(int i=0;i<28;i++){
				for(int j=0;j<100;j++){
					if(tab[z] == tab_key[i][j] && i == 27){
						decrypted += ' '; 
					}
						
					
					if(tab[z] == tab_key[i][j] && i != 27){
						decrypted += char(i + 97); 
					}
				}
			}
		}
	cout<< "\nDecrypted text: " << decrypted;
}

int main(int argc, char** argv) {
	string text, cryptogram, jawny;
	cout<< "Szyfr Homofoniczny" <<endl;
	cout<< "\n***Encryption***\n" << endl;
	cout<< "Enter text to encryption: \n\t";
	getline(cin, text);

	for(int i = 0; i<text.size(); i++){
		if (text[i] >=65 && text[i] <=90 )
			text[i] = text[i] + 32;
	}
			

	int how_many_letters = 0; 
	int most_popular = 0; 
	int how_many_spaces = 0;
	for(int j=0; j<26; j++){	
		int how_many_found = 0; 	
			how_many_spaces = 0;
			for(int i=0; i<text.size(); i++){
				if(char(j+97) == text[i]){	
					how_many_found++;
					if(most_popular < how_many_found)
						most_popular = how_many_found;
				}
				if(text[i] == ' ')
					how_many_spaces++;
			}
			if(how_many_found > 0){ 
				cout<< char(j+97) << " found: " << how_many_found << " times." <<endl;
				how_many_letters += 1;
			}			
		}
		if(most_popular < how_many_spaces)
			most_popular = how_many_spaces;
		if(how_many_spaces>0){
			cout<< "Space" << " found: " << how_many_spaces << " times." <<endl;
			how_many_letters += 1;
		}
	cout << "\nIlosc wszystkich liter wraz ze spacja " << how_many_letters <<endl;
	cout << "Ilosc najczesciej wystepujacej litery " << most_popular <<endl;
	//---------------------------------------------------------------------------------------------------------
	cout << "\nArray key" << endl;
	srand (time(NULL)); 
	int tab_key[27][most_popular];
	for(int i=0; i<28; i++){
		for(int j=0; j<most_popular; j++){
			tab_key[i][j] = 0;
		}
	}
	
	for(int j=0; j<26; j++){	
		int how_many_found = 0; 	
			how_many_spaces = 0;
			for(int i=0; i<text.size(); i++){
				if(char(j+97) == text[i]){
					how_many_found++;
				}
				if(text[i] == ' ')
					how_many_spaces++;
			}
			if(how_many_found > 0){ 
				cout<< "\n" << char(j+97) << ": ";
				for(int a=0; a<how_many_found; a++){
					tab_key[j][a] = rand();
					cout<< tab_key[j][a] << " | ";
				}
			}			
		}
	if(how_many_spaces > 0){
		cout<< "\nSpace : ";
		for(int a=0; a<how_many_spaces; a++){
			tab_key[27][a] = rand();
			cout<< tab_key[27][a] << " | ";
		}
	}
	
	int tab_function_key[28][100];
	for(int i=0; i<28; i++){
		for(int j=0; j<100; j++){
			tab_function_key[i][j] = 0;
		}
	}
	
	
	int tab_function[100];
	for(int i=0; i<28; i++){
		for(int j=0; j<most_popular; j++){
			tab_function_key[i][j] = tab_key[i][j];
		}
	}
	encryption(tab_function_key, tab_function, text); 

	cout << "\n\n***Decryption***\n" << endl;
	int length_crypto;
	cout<< "Enter cryptograms length  to decryption: "; 
	cin>> length_crypto;
	

	int tab_crypto[100]; 
	cout<< "Enter cryptogram: " <<endl;
	int variable;
	for(int i=0; i<length_crypto; i++){
		cout<< "Enter number k[" << i <<"] = ";
		cin>> variable;
		cin.ignore();
		tab_crypto[i] = variable; 
	}
	decryption(tab_function_key, tab_crypto, length_crypto);

	return 0;
}
