//Author: Zbigniew Smaza

#include <iostream>
#include <cstring>
using namespace std;

void encryption(string text){ //function encryption and decryption
	for(int i=0; i< text.size(); i++){ 
		if(text[i] >= 65 & text[i] <= 90){ 
			char variable = 90 - (text[i] - 65); 
			text[i] = variable; 
		}	
		if(text[i] >= 97 & text[i] <= 122){
			char variable = 122 - (text[i] - 97); 
			text[i] = variable;
		}	
	}
	cout<< "After encryption: " << text << endl;
}
void interface(){
	std::string text;		
	char choice;
	std::cout<<"\n-------------\nChoose option:\n1 -> Encryption text\n2 -> Decryption text\n3 -> Exit\nYour choice: "; 
	std::cin>>choice;
		std::cin.ignore();
	
	if(choice =='1'){	
		std::cout<<"\n-----\nEnter text: ";
		getline(std::cin, text);
		encryption(text);	
		interface();	
	}
	else if(choice =='2'){	
		std::cout<<"\n-----\nEnter text: ";
		getline(std::cin, text);	
		encryption(text); 
		interface();
	}
	else if(choice =='3');		
	else {
		std::cout<<"No such option. Please choose again.";
		interface();	
	}
}

int main(int argc, char** argv) {
	cout<< "AthBash\n"<< endl;
	interface();
	
	return 0;
}
