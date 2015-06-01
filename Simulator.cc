#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct orb {
	int x; // from 0 to 6
        int y; // from 0 to 5
        string type; // from {red, blue, green, light, dark, heal, jammer, poison}
        bool enhanced;
} ;

orb board[5][6]; 

string gen_type() {
        string types[6] = {"R","B","G","L","D","H"};
	int buffer = rand() % 6;
        return types[buffer];
}        

void init_board() {
       for(int y = 0; y < 5; y++) {
	for(int x = 0; x < 6; x++) {
       	 string type = gen_type();
         bool xconflict = false;
         bool yconflict = false;
         if(x >= 2 && board[y][x-1].type==board[y][x-2].type)
           xconflict = true;
         if(y >= 2 && board[y-1][x].type==board[y-2][x].type)
           yconflict = true;
         if(xconflict && yconflict) {
           while(type == board[y][x-1].type || type==board[y-1][x].type) {
             type = gen_type();
           }
         }
         else if(xconflict) {
           while(type == board[y][x-1].type) {
             type = gen_type();
           }
         }
         else if(yconflict) {
           while(type == board[y-1][x].type) {
             type = gen_type();
           }
         }
         board[y][x].y = y;
         board[y][x].x = x;
         board[y][x].type = type;
         board[y][x].enhanced = false;    
	}}
}
 
void print_board() {
	for(int y = 0; y < 5; y++) {
          for(int x = 0; x < 6; x++) {
            cout << board[y][x].type;
          }
          cout << endl;
        }
}
bool possible(string lead) {
	bool isPossible = false;
        int R=0,B=0,G=0,L=0,D=0,H=0;
        for(int y = 0; y < 5; y++) {
	  for(int x = 0; x < 6; x++) {
            string type = board[y][x].type;
            if(type == "P" || type == "J") x++;
            else if(type == "R") R++;
            else if(type == "B") B++;
            else if(type == "G") G++;
            else if(type == "L") L++;
            else if(type == "D") D++;
            else if(type == "H") H++;
            else {
              cerr << "Error! Invalid Type " << type << " in (" << x << "," << y << ")" << endl;
            }
          }
        }
        if(R+B+G+L+D+H!=30) {
          cerr << "Error! # of orbs != 30" << endl;
        }
	if(lead == "Ra") {
          if((R>2)+(B>2)+(G>2)+(L>2)+(D>2)==5)
            isPossible = true;
        }
        else if(lead == "RaTPA") {
          if((R>2)+(B>2)+(G>2)+(L>3)+(D>2)==4)
            isPossible = true;
        }
        else if(lead == "LLRa16") {
          if((R>2)+(B>2)+(G>2)+(L>2)+(D>2)+(H>2)==5) 
            isPossible = true;
        }
        else if(lead == "LLRa49") {
          if((R>2)+(B>2)+(G>2)+(L>2)+(D>2)+(H>2)==6) 
            isPossible = true;
        }
	else if(lead == "DQXQ") {
          if((R>2)+(B>2)+(G>2)+(L>2)+(D>2)+(H>2)>=4)
            isPossible = true;
        }
        else if(lead == "Vegito") {
          if((R>3)+(B>2)+(G>2)+(L>2)+(D>2)+(H>2)>=4)
            isPossible = true;
        }
	else if(lead == "Durga") {
          if((R>2)+(B>2)+(G>2)+(D>2)+(H>2)>=4)
            isPossible = true;
        }
        else if(lead == "LKali") {
          if((R>2)+(B>2)+(L>2)+(D>2)==4)
            isPossible = true;
        }
        else if(lead == "LKaliTPA") {
          if((R>2)+(B>2)+(L>3)+(D>2)==4)
            isPossible = true;
        }
        else if(lead == "Juggler") {
          if((H>5)==1)
            isPossible = true;
        }
	else if (lead == "Haku") {
	  if((R>2)+(B>2)+(D>2)==3)
	    isPossible = true;
        }
        else if(lead == "Ilum9") {
          if((L>5)+(R>2)==2) {
            isPossible = true;
          }
          else if((L>2)+(R>5)==2) {
            isPossible = true;
          }
        }
        else if (lead == "gTPA") {
	  if((G>3)==1)
	    isPossible = true;
        }
	else if (lead == "g2TPA") {
	  if((G>7)==1)
	    isPossible = true;
	}
        else if (lead == "dTPA") {
          if((D>3)==1)
            isPossible = true;
        }
        else if (lead == "d2TPA") {
          if((D>7)==1)
            isPossible = true;
        }
	else if(lead == "Pandora5") {
          if((D==5)==1) {
            isPossible = true;
          }
        }
        else if(lead == "Pandora6") {
          if((D==6)==1) {
            isPossible = true;
          }
        }
        else if(lead == "Pandora7") {
          if((D==7)==1) {
            isPossible = true;
          }
        }
        else if(lead == "Pandora8") {
          if((D>=8)==1) {
            isPossible = true;
          }
        }
        else if(lead == "Ilum36") {
          if((L>5)+(R>5)==2) {
            isPossible = true;
          }
        }
        else {
          cerr << "Unsupported Lead " << lead << endl;
        }
        return isPossible;
} 

int possibleCombos() {
	int R=0,B=0,G=0,L=0,D=0,H=0;
        for(int y = 0; y < 5; y++) {
          for(int x = 0; x < 6; x++) {
            string type = board[y][x].type;
            if(type == "P" || type == "J") x++;
            else if(type == "R") R++;
            else if(type == "B") B++;
            else if(type == "G") G++;
            else if(type == "L") L++;
            else if(type == "D") D++;
            else if(type == "H") H++;
            else {
              cerr << "Error! Invalid Type " << type << " in (" << x << "," << y << ")" << endl;
            }
          }
        }
        return R/3+B/3+G/3+L/3+D/3+H/3;
}
//------------ CODE TO TEST ACTIVATION RATES ---------------
int main() {
        cout.precision(5);
        srand((unsigned)time(0));
        int runs = 100000;
/* 
        int RA = 0;
        int LLRA16 = 0;
        int LLRA49 = 0;
        int LKALI = 0;
        int LKALITPA = 0;
        for(int i = 0; i < runs; i++) {
          init_board();
          if(possible("Ra")) {
            RA++;
          }
          if(possible("LLRa16")) {
            LLRA16++;
          }
          if(possible("LLRa49")) {
            LLRA49++;
          }
          if(possible("LKali")) {
            LKALI++;
          }
          if(possible("LKaliTPA")) {
            LKALITPA++;
          }
        }
        double RArate = RA*100/(double)runs;
        double RA16rate = LLRA16*100/(double)runs;
        double RA49rate = LLRA49*100/(double)runs;
        double LKalirate = LKALI*100/(double)runs;
        double LKaliTPArate = LKALITPA*100/(double)runs;

        cout << "Ra Activation %: " << fixed << RArate << endl;
        cout << "LLRa 16x Activation %: " << fixed << RA16rate << endl;
        cout << "LLRa 49x Activation %: " << fixed << RA49rate << endl;
        cout << "LKali Activation %: " << fixed << LKalirate << endl;
        cout << "LKaliTPA Activation %: " << fixed << LKaliTPArate << endl;
*/
	int acombos = 0;
	int bcombos = 0;
	int ccombos = 0;
	int dcombos = 0;
        for(int i = 0; i < runs; i++) {
	  init_board();
          int buffer = possibleCombos();
          if(possible("Pandora6")) {acombos++;}
          if(possible("Pandora7")) {bcombos++;}
          if(possible("Pandora8")) {ccombos++;}
          if(possible("Haku")) {dcombos++;}
        }
        double acomborate = acombos*100/(double)runs;
        double bcomborate = bcombos*100/(double)runs;
        double ccomborate = ccombos*100/(double)runs;
        double dcomborate = dcombos*100/(double)runs;
	double total = acomborate + bcomborate + ccomborate;        

        cout << fixed << acomborate << endl;
        cout << fixed << bcomborate << endl;
        cout << fixed << ccomborate << endl;
        cout << fixed << total << endl;
        cout << fixed << dcomborate << endl;
}       
/*
int main() {
	srand((unsigned)time(0));
        init_board();
        print_board();
}G
*/
