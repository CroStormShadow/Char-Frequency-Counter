#include <iostream>
#include <fstream>
#include <sstream>
#include <ctype.h>
#include <iomanip>
#include <math.h>
using namespace std;

int lista[27] = {0};
string novi;
int counter;
int ostali = 0;
void citanje(){
	fstream dat;
	stringstream buffer;
	dat.open("Podaci.txt");
	
	buffer << dat.rdbuf();
	novi = buffer.str();
	
	dat.close(); dat.clear();	
}
void analiza(){
	char znak;
	cout << endl;
	
	for(int i = 0; i < counter; i++){
		znak = tolower(novi[i]);
		if(znak == 32){
			lista[27]++;
		}
		else if(znak < 97){
			ostali++;
		}
		else{
			lista[int(znak)-97] ++;
		}
	}
	cout << endl;
}
int main(){
    citanje(); 
	counter = novi.length();
	cout << counter << " znakova" << endl;                      
	analiza();
	
	cout << "Rezultati" << endl;
	for(int i = 0; i < 26; i++){
		cout << char(i+97) << " " << setw(6) << lista[i] << setw(7) << (round((float(lista[i])/counter*100)*100))/100 << "%" << endl;
	}
	cout << "Razmak " << lista[27]  << setw(6) << (round((float(lista[27])/counter*100)*100))/100 << "%" << endl;
	cout << "Ostali " << ostali << setw(6) << (round((float(ostali)/counter*100)*100))/100 << "%" << endl;
	
	cin.get();    
    system("PAUSE");    
    return 0;
}
