#include<iostream>
using namespace std;


//----------------------------------------MAIN PROGRAM CODE---------------------------------------------------------------------
class Game {
private:
	int chances = 0; char arr[5] = { '-','-','-','-','-' }; char ans[5] = {'f','r','h','a','n'};
public:
	Game() {
		chances = 5;
		for(int i=0;i<5;i++)
			{
				arr[i]= '-';
			}
	}
	int getchances() {
		return chances;
	}
	~Game() {
		chances = 0;
		for (int i = 0; i < 5; i++)
			{
				arr[i] = '-';
			}
	}
	int display();
	void checkword( char c);
	bool checkwin();
	void resetchances();
};
int main() {
	int game = 1;
	Game obj;
	do {
		game =obj.display();
		if (game == 1) { obj.resetchances(); }
	} while (game==1);
}
//-------------------------------------FUNCTIONS ARE DEFINED------------------------------------------------------------------
int Game::display(){
	char tempch; int in = 0; int choice;
	
	
	do {
		

		system("cls");
		
		cout << "\t \t ";
	cout << "**  HANG MAN **" << endl;
	cout << "\t \t ";
	cout << "***************" << endl;
	cout << "\t \t ";
	cout << "- - - - - - - -" << endl;
	cout << "\t \t ";
	cout << arr[0] << "  " << arr[1] << "  " << arr[2] << "  " << arr[3] << "  " << arr[4] << endl;
	cout << "\t \t ";
	cout << "***************" << endl;
	cout << "\t \t ";
	cout << "- - - - - - - -" << endl;
	cout << "You have " << chances << " left" << endl;
	
		cout << "Enter a Char "; cin >> tempch;
		if (tempch >= 'a' && tempch <= 'z') {
			
			checkword(tempch);
		}
		else { cout << "Enter correct char a-z "; cout << "\n please enter again:" << endl; }
	}
		while (checkwin()==false && getchances()>0);
	if (checkwin() == true)
	{
		cout << "Congrats you have won " << endl;
		cout << " Wana Play Again YES(1)/NO(0) "; cin >> choice;

	}
	else if (getchances() == 0)
	{
		cout << "You are out of chances sorry Please Try Again Later: " << endl;
		cout << " Wana Play Again YES(1)/No(enter anyother digit/char "; cin >> choice;
	}

	 return choice; 
}
void Game::checkword(char c) {
	bool matched = false;
	for (int i = 0; i < 5; i++) {
		if(c==ans[i])
		{
			
			arr[i] = c;
			matched = true;
		}
	}
	if (matched == false) {
		chances--;
	}

}
bool Game::checkwin() {
	int count = 0;
	for (int i = 0; i < 5; i++) {
		if (arr[i] == ans[i])
		{count++; }
		else {break;}
	}
	if (count == 5) { return true; }
	else { return false; }
}
void Game::resetchances() {
	chances = 5;
}
 
