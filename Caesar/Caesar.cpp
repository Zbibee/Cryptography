//Author: Zbigniew Smaza
#include <iostream>
#include <cstring>

void encryption(std::string text, int key){ 
	char x,y;
	std::cout<< "Encryption text: " <<text<<std::endl;

	for(int i=0; i<text.size() ; i++){
		if(text[i]>=65 && text[i]<=90){			 
			x=65; y=90;
		}
		else if(text[i]>=96 && text[i]<=122){   
			x=97; y=122;
		}
				
		if(text[i] != 32){
			if(key>=0){
				if(text[i]+key<=y) //jezeli przesuniecie miesci sie w zakresie 
					text[i]+=key;  // to zamien znak z jego pozycji w tablicy ascii na znak o nr wiekszym o podany klucz
				else
					text[i]=text[i] + key - 26; // jezeli nr znaku po przesunieciu przekroczy zakres to bedzie kontynuowal po poczatku
			}
			else if(key<0){
					if(text[i]+key>=x) // jezeli klucz jest ujemny to przesuniecie dokonuje sie w lewo
						text[i]+=key; // 
					else
						text[i]=text[i]+key+26;
			}	
		}
		else
			text[i] = 32;
	}
	std::cout<<"After encryption: " << text <<std::endl;
}

void interface(){
	std::string text;		
	char choice;
	std::cout<<"\n-------------\nChoose option:\n1 -> Encryption text\n2 -> Decryption text\n3 -> Exit\nYour choice: "; 
	std::cin>>choice;
		std::cin.ignore();
	
	if(choice =='1'){
		int key;		
		std::cout<<"\n-----\nEnter text: ";
		getline(std::cin, text);
		
		std::cout<<"\nChoose a key from -26 to 26: ";
		std::cin>> key; //padany klucz przedestawia nam o ile pozycji dokona sie przesuniecie w prawo, a minusowa wartosc daje nam mozliwosc przesuwania w lewo
			std::cin.ignore();
		encryption(text, key);	
		interface();	
	}
	else if(choice =='2'){	
		int key;
		std::cout<<"\n-----\nEnter text: ";
		getline(std::cin, text);
		
		std::cout<<"\nChoose a key from -26 to 26: ";
		std::cin>> key;
			std::cin.ignore();
		encryption(text, -key); 
		interface();
	}
	else if(choice =='3');		
	else {
		std::cout<<"No such option. Please choose again.";
		interface();	
	}
}

int main(int argc, char** argv) {
	std::cout<<"Caesar's code"<<std::endl;
	interface();
	return 0;
}
