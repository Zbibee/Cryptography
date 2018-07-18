// Zbigniew Smaza szyfru Polibiusza z keyem
#include <iostream>
#include<cstring>
using namespace std;

int char_on_int(char variable_char){ // funkcja zmieniaj¹ca variable char na int
	int variable_int;
	variable_int = variable_char - 48;
	return variable_int;
}

char int_on_char(int variable_int){ // funkcja zmieniajaca zmianna int na char
	char variable_char;
	variable_char = variable_int + 48;
}

void decryption(string text, char tab[5][5]){ // argumentami jest zaszyfrowany text i key
	int length = (text.size()/2); //length odszyfrowanej wiadomosci
	char tab_char[length];	 // odszyfrowana wiadomosc bedzie tablica znakowa
	char letter;
	int  x, y;
	
	for(int i=0, j=0; i<text.size(); i+=2, j++){ //i to licznik do chodzenia po tekscie zaszyfrowanym wiec chodzimy po 2 znaki, a j to licznik po talicy ktora bedzie odsyfrowana wiadomoscia
		x = char_on_int(text[i]); 				  //piewrwsza z 2 zmiennych jest odpowiedzialna za kolumne 
		y = char_on_int(text[i+1]);			  // druga odpowiedzialna za wiersz
		letter = tab[x][y];						// przypisanie litery z tablicy na podstawie powyzszych zmiennych
												//PS. powyzej jest wykorzystywana funkcja char_on_int poniewaz text jest stringiem wiec variable text[i] jest variable char	
		tab_char[j]= letter;					//zapisanie litery do tablicy
		}
	cout << "\nODencryption\n" << text << "\t->\t" << tab_char << endl; // wyswietl text odszyfrowany
	}

void encryption(string text, char tab[5][5]){ // funkcja encryptionaca argumenty to text jawny do zaszyfrowania i tablica dwuwymiarowa jako key
	string encrypted;
	char letter;
	
	for(int k=0, z=0; k<text.size(); k++, z+=2 ){ // k sluzy  do chodzenia po tabli
		letter = text[k];
		for(int i=0;i<5;i++){ // do przeszukiwania tablicy ktora jest keyem
			for(int j=0; j<5; j++){ 
				if(letter == tab[i][j]){ //jezeli letter znajduje sie w tablicy
				encrypted += int_on_char(i); //przypisujemy parami gdzie pierwsza jest nr kolumny a druga nr wiersza
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
// w funkcji main znajduje sie generowanie wlasnego keya, ta funkcjonalnosc jest tak obszarna poniewaz sa tutaj operacje na tablicach znakowyc
// key1 to alfabet, key2 to bedzie odpowiednio przeksztalcony key jako tablica jednowymiarowa, key3 to alfabet bez liter ktor moga pojawic sie w slowie key
	char key1[25]={'a', 'b', 'c', 'd', 'e','f', 'g', 'h', 'i', 'k','l', 'm', 'n', 'o', 'p','q', 'r', 's', 't', 'u','w', 'v', 'x', 'y', 'z'};
	char key2[25];
	char key3[25];
	char tab_key[5][5]; // to jest tablica 2 wymiarowa ktora ostatecznia bedzie naszym readym keyem
	
	string inscription, d;
	cout<< "Enter word key"<< endl;
		getline(cin, inscription);
		
	cout << inscription <<endl;
	int length_inscription = inscription.size();	
	char inscription_key[25];
	
// jezeli letter w slowie key powtarza sie to wstawiamy '1' w kazde jej nastepne powtorzenie np anakonda -> an11ko1d1
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
//w nastepujacej petli jest tworzony inscription_key to talbica znakowa w ktorej jest slowo bez powtarzajacych sie liter
// na poprzednim przykladzie anakonda -> ankod
// tu bardzo wazne poniewaz w kolejnych krokach programu wazne jest by tablica inscription_key nie mial rozmiaru 25 tylko rozmiar dopasowany do lengthi inscriptionu bez powtarzajacych sie znakow
int ile;
	for(int i=0, z=0; i<length_inscription; i++){ 
		if(inscription[i] != '1'){
			inscription_key[z] = inscription[i];
			z++;
			ile = z;
			
		}
}
// tu wlanie powstaje tablica inscription_key1 w ktora ma odpowiednia length
char inscription_key1[ile];
for(int i=0; i< ile; i++){
	inscription_key1[i] = inscription_key[i];	
}
//jezeli letter juz znajduje sie w tablicy inscription_key1 to w tablicy key1 zmienia sie na '1'
	for(int i=0; i<25; i++){
		for(int j=0; j< ile; j++){
			if(key1[i]==inscription_key1[j])
				key1[i] = '1';
		}
	}
//pozbywamy sie jedynek z key 1 i otrzymujemy key3 czyli teblice zawierajaca litery alfabetu ktore nie znajduja sie w inscription_key1  	
	for(int i=0, z=0; i<25; i++){
		if(key1[i] != '1'){
			key3[z] = key1[i];
			z++;
		}
	}
// do tablicy key2 najpierw przypisujemy inscription_key1 nastepnie reszte alfabeu
	for(int i=0; i<25; i++){
		if(i<ile){
			key2[i] = inscription_key1[i]; 
		}
		else
			key2[i] = key3[i-ile];
	}
//te petle zmieniaja liste jedowymiarowa key2 na dwuwymiarowa tab_key	
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			int z;
			tab_key[i][j] = key2[z];
			z++;
		}
	}		
//drukowanie keya		
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
