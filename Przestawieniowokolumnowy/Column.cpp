//Author:  Zbigniew Smaza
#include <iostream>
#include <cstring>
#include <cctype>
#include <cmath>
using namespace std;

int char_on_int(char variable_char){ // funkcja zmieniaj¹ca variable char na int
	int variable_int;
	variable_int = variable_char - 48;
	return variable_int;
}

char int_on_char(int variable_int){ // funkcja zmieniajaca zmianna int na char
	char variable_char;
	variable_char = variable_int + 48;
	return variable_char;
}

int up(int x, int y){ // funkcja zaokragla do gory
	if(x%y == 0)
		return x/y;
	if(x%y != 0)
		return (x/y + 1);
}

void generate_word_key(string text, char* tab_counter){ // ta funkcja zmienia teskt do slowa klucz w tablice znakowa w ktorej sa cyfry ktore beda nadawac priorytet
	for(int i=0; i<text.size(); i++){
		tab_counter[i] = text[i];
		}
	
	for(int i=0; i<text.size(); i++){
		tab_counter[i] = int_on_char(text.size()); 
		for(int j=0; j< text.size(); j++){
			if(text[i] < text[j]){
				tab_counter[i] -= 1;
			}
			if(text[i] == text[j] & i < j){
				tab_counter[i] -= 1;			
			}
		}
	}	
	
}

void encryption(string text, string text2, char *tab_counter, int length_tab, char *tab){
for(int i=0;i<text2.size();i++){
	if(text2[i]>=65 && text2[i]<=90)
		text2[i] += 32;
	if(text2[i] == ' ')
		text2[i] = '_';
	
}

for(int i=0;i<length_tab;i++){
	if(i<text2.size())
		tab[i] = text2[i];	
}

char tab_szyf[up(text2.size(), text.size())][text.size()];
int z =0;
for(int i=0; i< up(text2.size(), text.size()); i++){
	for(int j=0; j<text.size(); j++){
		tab_szyf[i][j] = tab[z];
		z++;
	}
}
for(int i=0;i<text.size();i++){
	cout << tab_counter[i] << ' ';
}
for(int i=0; i< up(text2.size(), text.size()); i++){
	cout<<endl;
	for(int j=0; j<text.size(); j++){
		cout<< tab_szyf[i][j] << ' ';
	}
}
//---------------------------------------------------------------------------------
z=0;
char tab_przest[length_tab];
	for(int i=0; i<text.size(); i++){
		for(int j=0; j< up(text2.size(), text.size()); j++){
				tab_przest[z] = tab_szyf[j][i];	
				z++;
	}
}
//----------------------------------------------------------------------------
string zaszyfrowane;
z = 0;
for(int n=0; n<text.size()+1; n++){
	for(int i=0; i<text.size(); i++){
		if(char_on_int(tab_counter[i]) == n){
			for(int j=0; j< up(text2.size(), text.size()); j++){
				zaszyfrowane += tab_szyf[j][i];
			}
		}
	}
}
cout<< "\nEncrypted text: " <<zaszyfrowane<<endl;
}

void decryption(int length_tab_counter, char *tab_counter, int length_tab, char *tab){
	int z=0;
	int ile_liter = length_tab/length_tab_counter;// ile liter -> ma ciag liter ktore chcemy sklejac
	char tab_odszyf[length_tab_counter][ile_liter];
		for(int i=0; i<length_tab_counter; i++){
			//cout<<endl;
			for(int j=0; j<ile_liter;j++){
			//	cout<< tab[z] << ' ';
				tab_odszyf[i][j] = tab[z];
				z++;
			}
		}
	
	z=0;	
	for(int n=0; n<length_tab_counter+1; n++){
		for(int i=0; i<length_tab_counter; i++){
			if((char_on_int(tab_counter[n])-1) == i){
				//cout<<endl;
				for(int j=0; j<ile_liter; j++){
					tab[z] = tab_odszyf[i][j];
					z++;
				}
			}
		}
	}	
	z=0;
	for(int i=0; i<length_tab_counter; i++){
		for(int j=0;j<ile_liter;j++){
			tab_odszyf[i][j] = tab[z];
			z++;
		}
	}
	string odszyfrowane;
	z=0;
	for(int i=0; i<ile_liter; i++){
		for(int j=0; j<length_tab_counter; j++){
			odszyfrowane += tab_odszyf[j][i];
		}
	}
	
	for(int i=0; i<odszyfrowane.size(); i++){
		if(odszyfrowane[i] == '_')
			odszyfrowane[i] = ' ';
		}
		
		cout<< "Decrypted text: " << odszyfrowane <<endl;
}

int main(int argc, char** argv) {	
	string text;	
	string text2;
	string text3;
	cout<< "\nEnter word key"<< endl;
		getline(cin, text);

		for(int i=0;i<text.size();i++){
			if(text[i]>=65 && text[i]<=90){
				text[i] += 32;
			}
		}

		char tab_counter[text.length()];
		generate_word_key(text, tab_counter);
//--------------------------------------------------------- 

cout<< "\nEnter text to the encryption"<< endl;
		getline(cin, text2);

			int length_tab = up(text2.size(), text.size()) * text.size();
			char tab[length_tab];
			int length_tab_counter = text.size();
		
		encryption(text, text2, tab_counter, length_tab, tab);
		
cout<< "\n" <<endl;

cout<< "\nEnter text to the decryption"<< endl;
			getline(cin, text3);

			char tab_od[text3.size()];
			for(int i=0; i<=text3.size(); i++){
				tab_od[i]=text3[i];
			}
			
			decryption(length_tab_counter,tab_counter, text3.size(), tab_od);

	return 0;
}
