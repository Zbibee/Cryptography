//Affine code
// Author: Zbigniew Smaza

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int reverse_in_ring(int a){ // reverse number in the ring
	for(int i=0; i<26; i++){
		if((a*i)%26==1){
		   return i;
		}
	}
}

int function_encryption(int a, int b, int letter){ // encryption 1 letter
	int	result = (a * letter + b)%26;
	return result;	
}

int function_decryption(int a, int b, int letter){ //decryption 1 letter
	int result, reverse_value, function_de;
		reverse_value = reverse_in_ring(a); 
		function_de = reverse_value * (letter - b);
		if(function_de < 0){// modulo 26
			result = function_de%26 + 26;
		}
		else
			result = function_de%26;
	return result;
}

string encryption(string text, int x, int y){ // encryption string
	string cryptogram;
	int variable;
	for(int i=0; i<text.size(); i++){ 
		if(text[i]!= ' '){ 
			if(text[i] >= 65 && text[i] <= 90){  
				variable = function_encryption(x,y,text[i] - 65); 
				cryptogram += (variable+65);			
			}
			else if(text[i] >= 97 && text[i] <= 122){ 
				variable = function_encryption(x,y,text[i] - 97);
				cryptogram += (variable+97);
			}	
		}
		else cryptogram += ' ';
	}
	return cryptogram;
}

string decryption(string text, int x, int y){// decryption string
	string public_text;
	int variable;
	for(int i=0; i<text.size(); i++){ 
		if(text[i]!= ' '){
			if(text[i] >= 65 && text[i] <= 90){ 
				variable = function_decryption(x,y,text[i] - 65); 
				public_text += (variable+65);
			}
			else if(text[i] >= 97 && text[i] <= 122){
				variable = function_decryption(x,y,text[i] - 97);
				public_text += (variable+97);
			}	
	}
		else public_text += ' ';
	}
	return public_text;	
}

int main(int argc, char** argv) {
int key_x, key_y; 
	cout<<"Affine code\nEnter the values x, y to create the cryptographic equation\n\tf(x) = ax + b\n "<<endl; 
		cout<<"a= ";
			cin>>key_x;
			cin.ignore();
		
		cout<<"b= ";
			cin>>key_y;
			cin.ignore();
	cout<<endl;

	string text;
	cout<< "\nEnter the text to be encrypted: ";
		getline(cin, text);
		
		text = encryption(text, key_x, key_y);
		cout<< "Text after encryption: " << text<<endl;
	
	string encrytpted_text; 
	cout<< "\nEnter the text to be decrypted: ";
		getline(cin, encrytpted_text);
		
	text = decryption(encrytpted_text, key_x, key_y);
	cout<< "Text after decryption: " << text <<endl;

	return 0;
}
