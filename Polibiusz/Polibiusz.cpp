// Zbigniew Smaza szyfru Polibiusza z kluczem
#include <iostream>
#include<cstring>
using namespace std;

int char_on_int(char variable_char){ 
	int variable_int;
	variable_int = variable_char - 48;
	return variable_int;
}

char int_on_char(int variable_int){ 
	char variable_char;
	variable_char = variable_int + 48;
}

void decryption(string text, char tab[5][5]){ 
	int length = (text.size()/2); 
	char tab_char[length];	 
	char letter;
	int  x, y;
	
	for(int i=0, j=0; i<text.size(); i+=2, j++){
		x = char_on_int(text[i]); 				  
		y = char_on_int(text[i+1]);			  
		letter = tab[x][y];															
		tab_char[j]= letter;					
		}
	cout << "\nODencryption\n" << text << "\t->\t" << tab_char << endl; 
	}

void encryption(string text, char tab[5][5]){ 
	string encrypted;
	char letter;
	
	for(int k=0, z=0; k<text.size(); k++, z+=2 ){ 
		letter = text[k];
		for(int i=0;i<5;i++){ 
			for(int j=0; j<5; j++){ 
				if(letter == tab[i][j]){ 
				encrypted += int_on_char(i); 
				encrypted += int_on_char(j);
				}
			}
		}
	}
	cout<< "\nEncrypted\n" << text << "\t->\t" <<  encrypted <<endl;
}

string inscription(string text){
	string ready_inscription;
	for(int i=0; i<text.size();i++){
		if(text[i] != ' ')
			ready_inscription += text[i];
		}
	return ready_inscription;
}

int main(int argc, char** argv) {
	char key1[25]={'a', 'b', 'c', 'd', 'e','f', 'g', 'h', 'i', 'k','l', 'm', 'n', 'o', 'p','q', 'r', 's', 't', 'u','w', 'v', 'x', 'y', 'z'};
	char key2[25];
	char key3[25];
	char tab_key[5][5];
	
	string inscription, d;
	cout<< "Enter word key"<< endl;
		getline(cin, inscription);
		
	cout << inscription <<endl;
	int length_inscription = inscription.size();	
	char inscription_key[25];
	
	for(int i=0; i < length_inscription; i++){
		char x = inscription[i];
		for(int j=0, found = 0; j<length_inscription;j++){
			if(inscription[j]== x){
				found += 1;
				if(found>1){
					inscription[j] = '1';
				}
			}
		}
	}
	int ile;
	for(int i=0, z=0; i<length_inscription; i++){ 
		if(inscription[i] != '1'){
			inscription_key[z] = inscription[i];
			z++;
			ile = z;
			
		}
	}

	char inscription_key1[ile];
	for(int i=0; i< ile; i++){
		inscription_key1[i] = inscription_key[i];	
	}

	for(int i=0; i<25; i++){
		for(int j=0; j< ile; j++){
			if(key1[i]==inscription_key1[j])
				key1[i] = '1';
		}
	}

	for(int i=0, z=0; i<25; i++){
		if(key1[i] != '1'){
			key3[z] = key1[i];
			z++;
		}
	}

	for(int i=0; i<25; i++){
		if(i<ile){
			key2[i] = inscription_key1[i]; 
		}
		else
			key2[i] = key3[i-ile];
	}

	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			int z;
			tab_key[i][j] = key2[z];
			z++;
		}
	}		
	
	for(int i=0; i<5; i++){
		cout<< "\n";
		for(int j=0; j<5; j++){
			cout<< tab_key[i][j] << "  " ;;
		}
	}	

	string text;
	cout<< "\Enter text to encryption"<< endl;
			getline(cin, text);
				
	for(int i=0;i<text.size();i++){
		if('A'<=text[i] && text[i]<='Z'){
			text[i] += 'a' - 'A';
		} 
	}
			encryption(text,tab_key);
			
	cout<< "Enter text to decryption"<< endl;
			getline(cin, text);
			decryption(text, tab_key);
	return 0;
}
