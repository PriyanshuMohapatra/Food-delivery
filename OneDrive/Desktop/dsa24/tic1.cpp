#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<string> board={"1","2","3","4","5","6","7","8","9"};
void print(){
    cout<<board[0]<<" | "<<board[1]<<" | "<<board[2]<<endl;
    cout<<board[3]<<" | "<<board[4]<<" | "<<board[5]<<endl;
    cout<<board[6]<<" | "<<board[7]<<" | "<<board[8]<<endl;
}

void turn(string player){
    cout << player << "'s turn." << endl;
    cout << "Choose a position from 1-9: ";
    int position;
    cin>>position;
    position-=1;
    while((position<0 || position > 8) || (board[position]=="X" || board[position]=="O")){
        cout<<"Invalid pos"<<endl;
        cout<<"Enter again: ";
        cin>>position;
        position-=1;
    }
    board[position]=player;
    print();
}

bool check(){
    int comb[8][3]={{0,1,2},{3,4,5},{6,7,8},
    {0,3,6},{1,4,7},{2,5,8},
    {0,4,8},{2,4,6}
    };
    for(int i=0;i<8;i++){
    if (board[comb[i][0]] == board[comb[i][1]] && 
            board[comb[i][1]] == board[comb[i][2]] && 
            (board[comb[i][0]] == "X" ||  board[comb[i][0]] == "O")) {
            return true; 
        }
    }
    return false;
}

string checkgame(){
    if(check())
    return "win";
    if(count(board.begin(),board.end(),"X")==0 && count(board.begin(),board.end(),"O")==0)
    return "Tie";
    else
    return "play";
}
int main(){
    print();
    
    string cp="X";
    
    while(true){
        turn(cp);
        if(check()){
        cout<<cp<<" wins";
        break;
        }
        if(checkgame()=="Tie"){
        cout<<"Tie";
        break;
        }
        else{
            cp=(cp=="X")?"O":"X";
        }
    }
    return 0;
}