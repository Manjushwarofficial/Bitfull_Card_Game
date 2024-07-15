#include <iostream>
#include <algorithm> // For std::random_shuffle
#include <cstdlib>   // For std::rand, std::srand
#include <ctime>     // For std::time
#include <string>
#include <vector>
#include <chrono>    // To delay play
#include <thread>    // To delay play
#include <random>

using namespace std;

void shufflecards(string arr[], int n);

void showcards(string diamond[], string heart[], string spade[], string clubs[]);

void printcards(string array[], int len);

void bitfull(string diamond[], string heart[], string spade[], string clubs[]);

void printstuff();

void printrealdeck(string arr[13][4]);

void copycards(string cards1, string cards2, int size); // copies cards1 to cards2

void play(string player[13][4], string boarddeck[13][4], int n, int realplayer);

void playplayer(string player[13][4], string boarddeck[13][4], int n, int voice);

void freeplay(string player, string boarddeck[13][4], int n, int realplayer, int newly);

void calculatepoints(string player[13][4], int n);

void printSlowly(const vector<string>& bigLetter, int delayMs) {
    for (const string& line : bigLetter) {
        cout << line << endl;
        this_thread::sleep_for(chrono::milliseconds(delayMs));
    }
}

vector<string> getBigLetter(char c) {
    switch (toupper(c)) {
        case 'A':
            return {"  A  ",
                    " A A ",
                    "AAAAA",
                    "A   A",
                    "A   A"};
        case 'B':
            return {"BBBB ",
                    "B   B",
                    "BBBB ",
                    "B   B",
                    "BBBB "};
        case 'C':
            return {" CCC ",
                    "C   C",
                    "C    ",
                    "C   C",
                    " CCC "};
        case 'D':
            return {"DDDD ",
                    "D   D",
                    "D   D",
                    "D   D",
                    "DDDD "};
        case 'E':
            return {"EEEEE",
                    "E    ",
                    "EEE  ",
                    "E    ",
                    "EEEEE"};
        case 'F':
            return {"FFFFF",
                    "F    ",
                    "FFF  ",
                    "F    ",
                    "F    "};
        case 'G':
            return {" GGGG",
                    "G    ",
                    "G  GG",
                    "G   G",
                    " GGG "};
        case 'H':
            return {"H   H",
                    "H   H",
                    "HHHHH",
                    "H   H",
                    "H   H"};
        case 'I':
            return {"IIIII",
                    "  I  ",
                    "  I  ",
                    "  I  ",
                    "IIIII"};
        case 'J':
            return {"JJJJJ",
                    "    J",
                    "    J",
                    "J   J",
                    " JJJ "};
        case 'K':
            return {"K   K",
                    "K  K ",
                    "KKK  ",
                    "K  K ",
                    "K   K"};
        case 'L':
            return {"L    ",
                    "L    ",
                    "L    ",
                    "L    ",
                    "LLLLL"};
        case 'M':
            return {"M   M",
                    "MM MM",
                    "M M M",
                    "M   M",
                    "M   M"};
        case 'N':
            return {"N   N",
                    "NN  N",
                    "N N N",
                    "N  NN",
                    "N   N"};
        case 'O':
            return {" OOO ",
                    "O   O",
                    "O   O",
                    "O   O",
                    " OOO "};
        case 'P':
            return {"PPPP ",
                    "P   P",
                    "PPPP ",
                    "P    ",
                    "P    "};
        case 'Q':
            return {" QQQ ",
                    "Q   Q",
                    "Q   Q",
                    "Q  QQ",
                    " QQQQ"};
        case 'R':
            return {"RRRR ",
                    "R   R",
                    "RRRR ",
                    "R  R ",
                    "R   R"};
        case 'S':
            return {" SSS ",
                    "S    ",
                    " SSS ",
                    "    S",
                    " SSS "};
        case 'T':
            return {"TTTTT",
                    "  T  ",
                    "  T  ",
                    "  T  ",
                    "  T  "};
        case 'U':
            return {"U   U",
                    "U   U",
                    "U   U",
                    "U   U",
                    " UUU "};
        case 'V':
            return {"V   V",
                    "V   V",
                    "V   V",
                    " V V ",
                    "  V  "};
        case 'W':
            return {"W   W",
                    "W   W",
                    "W W W",
                    "WW WW",
                    "W   W"};
        case 'X':
            return {"X   X",
                    " X X ",
                    "  X  ",
                    " X X ",
                    "X   X"};
        case 'Y':
            return {"Y   Y",
                    " Y Y ",
                    "  Y  ",
                    "  Y  ",
                    "  Y  "};
        case 'Z':
            return {"ZZZZZ",
                    "   Z ",
                    "  Z  ",
                    " Z   ",
                    "ZZZZZ"};
        case ' ':
            return {"     ",
                    "     ",
                    "     ",
                    "     ",
                    "     "};
        default:
            return {"     ",
                    "     ",
                    "     ",
                    "     ",
                    "     "};
    }
}

void printMessageSlowly(const string& message, int delayMs) {
    vector<vector<string>> bigLetters;

    // Convert each character to its big letter representation
    for (char c : message) {
        bigLetters.push_back(getBigLetter(c));
    }

    // Print each line of the big letters with a delay
    for (int i = 0; i < 5; ++i) { // Assuming each big letter has 5 lines
        for (const auto& bigLetter : bigLetters) {
            cout << bigLetter[i] << "  ";
        }
        cout << endl;
        this_thread::sleep_for(chrono::milliseconds(delayMs));
    }
}

int main(){

    //cout << "You are playing cards today !!"<< endl ;
    
    string heart[13]={"H1","H2","H3","H4","H5","H6","H7","H8","H9","H10","HJ","HQ","HK"} ;

    string diamond[13]={"D1","D2","D3","D4","D5","D6","D7","D8","D9","D10","DJ","DQ","DK"} ;

    string spade[13]={"S1","S2","S3","S4","S5","S6","S7","S8","S9","S10","SJ","SQ","SK"} ;
    
    string clubs[13]={"C1","C2","C3","C4","C5","C6","C7","C8","C9","C10","CJ","CQ","CK"} ;

    string player[13], cpu1[13], cpu2[13], cpu[13];
    
    cout << "/////////////////////////////////////////////////////////" << endl;
    bitfull(diamond,heart,spade,clubs);

    return 0;
}

void Delay(const std::string &str) {
    for (char c : str) {
        if (c == '\n') {
            break;
        }
        std::cout << c;
        this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    //std::cout << std::endl; // Ensure the final output ends with a newline
}



void calculatepoints(string player[13][4], int n){

    cout << endl;

    cout <<"////////////////////////////////////////////////////////////////" << endl;
    /*
    string input = "The player's points is as follows as per the classical Bitfull rules : ";
    Delay(input);
    cout << endl;
    */
    int score[4]= {0,0,0,0};

    for (int i=0; i<4;i++){


        for (int j=0; j<13; j++){
            string card= player[i][j];
            if (card[1] == '1'){
                score[i] += 10;
            }
            if (card[1] == '2'){
                score[i] += 2;
            }
            if (card[1] == '3'){
                score[i] += 3;
            }
            if (card[1] == '4'){
                score[i] += 4;
            }
            if (card[1] == '5'){
                score[i] += 5;
            }
            if (card[1] == '6'){
                score[i] += 6;
            }
            if (card[1] == '7'){
                score[i] += 7;
            }
            if (card[1] == '8'){
                score[i] += 8;
            }
            if (card[1] == '9'){
                score[i] += 9;
            }
            if (card[1] == 'J'){
                score[i] += 11;
            }
            if (card[1] == 'Q'){
                score[i] += 12;
            }
            if (card[1] == 'K'){
                score[i] += 13;
            }

        }
        /*
        string s1 = "Player ";
        Delay(s1);
        cout << i+1;
        this_thread::sleep_for(std::chrono::milliseconds(100));
        cout << " ";
        this_thread::sleep_for(std::chrono::milliseconds(100));
        cout << ":";
        this_thread::sleep_for(std::chrono::milliseconds(100));
        cout << " "<< score[i]<< endl;
        */
        
        
    }

    cout << "Player no: Score : Remaining cards" << endl;

    for (int i=0; i<4;i++){

        string s1 = "Player ";
        Delay(s1);
        cout << i+1;
        this_thread::sleep_for(std::chrono::milliseconds(100));
        cout << " ";
        this_thread::sleep_for(std::chrono::milliseconds(100));
        cout << ":";
        this_thread::sleep_for(std::chrono::milliseconds(100));
        cout << "  ";
        this_thread::sleep_for(std::chrono::milliseconds(100));
        cout << " "<< score[i];
        this_thread::sleep_for(std::chrono::milliseconds(100));
        cout << "  "<< ":";
        this_thread::sleep_for(std::chrono::milliseconds(100));
        cout << " ";

        for (int j=0; j<13; j++){
            if (player[i][j] != " 0"){
                cout << player[i][j] << " ";
                this_thread::sleep_for(std::chrono::milliseconds(100));
            }
        }

        cout << endl;
    }

    cout << endl;

    string s3 = "The positions are :";
    Delay(s3);
    cout << endl;

    for (int i=0; i<4; i++){
        for (int j=i+1; j<4; j++){
            if (score[i]==score[j]){
                score [j]++;
            }
        
        }
    }
    

    int fir =0, sec, thi, fou, max;
    // first
    bool winner;

    if(score[0]>score[1] && score[0]>score[2] && score[0]>score[3]){
        max = score [0];
        fir = 1;
    }
    else if(score[1]>score[0] && score[1]>score[2] && score[1]>score[3]){
        max = score [1];
        fir = 2;
    }
    else if(score[2]>score[1] && score[2]>score[0] && score[2]>score[3]){
        max = score [2];
        fir = 3;
    }
    if(score[3]>score[1] && score[3]>score[2] && score[3]>score[0]){
        max = score [3];
        fir = 4;
    }

    // fourth
    int min=0;
    if(score[0]<score[1] && score[0]<score[2] && score[0]<score[3]){
        min = score [0];
        fou = 1;
    }
    else if(score[1]<score[0] && score[1]<score[2] && score[1]<score[3]){
        min = score [1];
        fou = 2;
    }
    else if(score[2]<score[1] && score[2]<score[0] && score[2]<score[3]){
        min = score [2];
        fou = 3;
    }
    if(score[3]<score[1] && score[3]<score[2] && score[3]<score[0]){
        min = score [3];
        fou= 4;
    }
    // second
    
    if (score [0]>min && score[0]<max){
        sec = 1;
    }
    else if (score [1]>min && score[1]<max){
        sec = 2;
    }
    else if (score [2]>min && score[2]<max){
        sec = 3;
    }
    else if (score [3]>min && score[3]<max){
        sec = 4;
    }

    //////////////////
    if (score [3]>min && score[3]<max){
        thi = 4;
    }
    else if (score [2]>min && score[2]<max){
        thi = 3;
    }
    else if (score [1]>min && score[1]<max){
        thi = 2;
    }
    else if (score [0]>min && score[0]<max){
        thi = 1;
    }

    int foo;
    if (score[sec-1]<score[thi-1]){
        foo = score[sec-1];
        score[sec-1]=score[thi-1];
        score[thi-1]=foo;
    }
    
    cout << "Toilet Cleaner : ";
    string k1 = "Player ";
    Delay(k1);
    cout << fir << endl;

    cout << "Peon : ";
    Delay(k1);
    cout << sec << endl;

    cout << "Queen : ";
    Delay(k1);
    cout << thi << endl;

    cout << "King : ";
    Delay(k1);
    cout << fou << endl;


    cout <<"////////////////////////////////////////////////////////////////" << endl;


}

void printcards(string array[], int len){
    for (int i=0; i<len; i++){
        cout << array[i] << " " ;
    }
    cout << endl;
}

void shufflecards(string arr[], int n) {
    std::srand(std::time(0));
    std::random_shuffle(arr, arr + n);
}

void printstuff(){
    cout << "/////////////////////////////////////////////////////////////////"<< endl;
    cout << "      Spade     " << "      Heart       " << "    Clubs    " << "      Diamond   " << endl;
}

void printrealdeck(string arr[13][4]){
    for (int i = 0; i <13; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << "       "<< arr[i][j] << "       ";
        }
        cout << endl;
    }
    cout << "/////////////////////////////////////////////////////////////////"<< endl;
}

void copycards(string cards1, string cards2, int size){
    for (int i=0; i<13; i++){
        cards2[i]=cards1[i];
    } 
}

bool isValidMove(string boarddeck[13][4], int row, int col, string card) {
    
    // Check up
    //cout << boarddeck[row-1][col][0]<< card[0]<< endl;
    //cout <<  (boarddeck[row-1][col][1]) << " " << card[1] << endl;

    if (row > 0 && boarddeck[row-1][col] != " 0") {
        
        if( ((boarddeck[row-1][col][0]==card[0]) && (boarddeck[row-1][col][1]+1==card[1]) && (boarddeck[row-1][col][1] != '1') && (card[1] != 'K'))){
            
            return true;
        }
    }
    // Check down
    if (row < 12 && boarddeck[row+1][col] != " 0") {
        if((boarddeck[row+1][col][0]==card[0]) && (boarddeck[row+1][col][1]-1==card[1]) && (card[2] != '0') ){
            return true;
        }
    }
    return false;

}

void play(string player[13][4], string boarddeck[13][4], int n, int realplayer) {
    
    for (int i = 0; i < 13; i++) {
        string card = player[i][n];
        
        // spade
        if (card=="S10"){
            if (boarddeck[8][0]=="S9"){
                boarddeck[9][0]="S10";
                player[i][n]=" 0";
                return;
            }
        }
        
        if (card=="SJ"){
            if (boarddeck[9][0]=="S10"){
                boarddeck[10][0]="SJ";
                player[i][n]=" 0";
                return;
            }
        }
        if (card=="SQ"){
            if (boarddeck[10][0]=="SJ"){
                boarddeck[11][0]="SQ";
                player[i][n]=" 0";
                return;
            }
        }
        if (card=="SK"){
            if (boarddeck[11][0]=="SQ"){
                boarddeck[12][0]="SK";
                player[i][n]=" 0";
                return;
                
            }
        }
        
        // Heart
        if (card=="H10"){
            if (boarddeck[8][1]=="H9"){
                boarddeck[9][1]="H10";
                player[i][n]=" 0";
                return;
            }
        }
        if (card=="HJ"){
            if (boarddeck[9][1]=="H10"){
                boarddeck[10][1]="HJ";
                player[i][n]=" 0";
                return;
            }
        }
        if (card=="HQ"){
            if (boarddeck[10][1]=="HJ"){
                boarddeck[11][1]="HQ";
                player[i][n]=" 0";
                return;
            }
        }
        if (card=="HK"){
            if (boarddeck[11][1]=="HQ"){
                boarddeck[12][1]="HK";
                player[i][n]=" 0";
                return;
            }
        }
        // Diamond
        if (card=="D10"){
            if (boarddeck[8][3]=="D9"){
                boarddeck[9][3]="D10";
                player[i][n]=" 0";
                return;
            }
        }
        if (card=="DJ"){
            if (boarddeck[9][3]=="D10"){
                boarddeck[10][3]="DJ";
                player[i][n]=" 0";
                return;
            }
        }
        if (card=="DQ"){
            if (boarddeck[10][3]=="DJ"){
                boarddeck[11][3]="DQ";
                player[i][n]=" 0";
                return;
            }
        }
        if (card=="DK"){
            if (boarddeck[11][3]=="DQ"){
                boarddeck[12][3]="DK";
                player[i][n]=" 0";
                return;
            }
        }
        // Clubs
        if (card=="C10"){
            if (boarddeck[8][2]=="C9"){
                boarddeck[9][2]="C10";
                player[i][n]=" 0";
                return;
            }
        }
        if (card=="CJ"){
            if (boarddeck[9][2]=="C10"){
                boarddeck[10][2]="CJ";
                player[i][n]=" 0";
                return;
            }
        }
        if (card=="CQ"){
            if (boarddeck[10][2]=="CJ"){
                boarddeck[11][2]="CQ";
                player[i][n]=" 0";
                return;
            }
        }
        if (card=="CK"){
            if (boarddeck[11][2]=="CQ"){
                boarddeck[12][2]="CK";
                player[i][n]=" 0";
                return;
            }
        }
        
       //cout << card << endl;
        // C1 Bug Fixing
        if (card=="C1"){
            if (boarddeck[1][2]=="C2"){
                boarddeck[0][2]="C1";
                player[i][n]=" 0";
                return;
            }
        }
        if (card=="S1"){
            if (boarddeck[1][0]=="S2"){
                boarddeck[0][0]="S1";
                player[i][n]=" 0";
                return;
            }
        }
        if (card=="H1"){
            if (boarddeck[1][1]=="H2"){
                boarddeck[0][1]="H1";
                player[i][n]=" 0";
                return;
            }
        }
        if (card=="D1"){
            if (boarddeck[1][3]=="D2"){
                boarddeck[0][3]="D1";
                player[i][n]=" 0";
                return;
            }
        }
        

        if (player[i][n] != " 0") {
            // Find a valid position on the board
            for (int row = 0; row < 13; row++) {
                for (int col = 0; col < 4; col++) {
                    if (boarddeck[row][col] == " 0") {
                        //cout << "working"<< endl;
                        if (isValidMove(boarddeck, row, col, player[i][n])) {//&& boarddeck[row][col][0]==player[i][n][0] ) {
                            //cout << "working"<< endl;
                            boarddeck[row][col] = player[i][n];
                            player[i][n] = " 0";
                            //printrealdeck(boarddeck);

                            return; // Card has been played, exit the function
                        }
                    }
                }
            }
        }
        // card greater than 9 (making the tree)
        
        // searching for classical 7
        if (card=="H7"){
            boarddeck[6][1]=card;
            player[i][n]= " 0";
            return;
        
        }
        if (card=="S7" && boarddeck[6][1]=="H7"){
            boarddeck[6][0]=card;
            player[i][n]= " 0";
            return;
            
        }
        if (card=="C7" && boarddeck[6][1]=="H7"){
            boarddeck[6][2]=card;
            player[i][n]= " 0";
            return;
            
        }
        if (card=="D7" && boarddeck[6][1]=="H7"){
            boarddeck[6][3]=card;
            player[i][n]= " 0";
            return;
            
        }

    }

    string comments[20] = {"HMM...    ","FOR GOD'S SAKE !    ", "BLODDY HELL      ", "GOT NONE TO PLAY      ", "WHY THIS GAME'S SO SLOW?       ", "I WAS WINNING :(      ", "WOW !       ","ILLEGAL IMMIGRRANT YOU.    ","WOW! THE CREATER OF THIS GAME IS BRILLIANT.         ","I KNOW YOU HAVE IT.         ","NO WAY !     ", "YOU WANNA PIECE OF ME?         ", "HERE WE GO AGAIN...      ", "NOICE ;)      ", "NOT PLAYING ANYMORE !!      ", "IS THIS WHAT YOU WANT?      ", "AHHHH NO !    ", "SHUT UP !    ","YOU CANNOT TEACH ME TO PLAY.   ","LET ME WIN I'M SO CLOSE.    "};

    // Seed with a real random value, if available
    std::random_device rd;

    // Initialize a random number generator
    std::mt19937 gen(rd());

    // Define a distribution in the range [0, 19]
    std::uniform_int_distribution<> distrib(0, 19);

    // Generate a random number
    int random_num = distrib(gen);
    cout << endl;
    cout << "PLAYER " << n+1 << ": ";
    string fool;
    fool=comments[random_num];
    Delay(fool);
    cout << endl;

    cout << "P";
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "l";
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "a";
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "y";
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "e";
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "r";
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << " ";
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << n+1;
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << " ";
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "h";
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "a";
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "s";
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << " ";
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "p";
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "a";
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "s";
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "s";
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "e";
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "d";
    this_thread::sleep_for(chrono::seconds(1));
    cout << ".";
    this_thread::sleep_for(chrono::seconds(1));
    cout << ".";
    this_thread::sleep_for(chrono::seconds(1));
    cout << "."<< endl;
    this_thread::sleep_for(chrono::seconds(1));
    
    cout << endl;  
    
                
}

void freeplay(string player[13][4], string boarddeck[13][4], int n, int realplayer, int newly) {
    
    
    for (int i = newly; i < newly+1; i++) {
        string card = player[i][n];
        
        // spade
        if (card=="S10"){
            if (boarddeck[8][0]=="S9"){
                boarddeck[9][0]="S10";
                player[i][n]=" 0";
                return;
            }
        }
        
        if (card=="SJ"){
            if (boarddeck[9][0]=="S10"){
                boarddeck[10][0]="SJ";
                player[i][n]=" 0";
                return;
            }
        }
        if (card=="SQ"){
            if (boarddeck[10][0]=="SJ"){
                boarddeck[11][0]="SQ";
                player[i][n]=" 0";
                return;
            }
        }
        if (card=="SK"){
            if (boarddeck[11][0]=="SQ"){
                boarddeck[12][0]="SK";
                player[i][n]=" 0";
                return;
                
            }
        }
        // Heart
        if (card=="H10"){
            if (boarddeck[8][1]=="H9"){
                boarddeck[9][1]="H10";
                player[i][n]=" 0";
                return;
            }
        }
        if (card=="HJ"){
            if (boarddeck[9][1]=="H10"){
                boarddeck[10][1]="HJ";
                player[i][n]=" 0";
                return;
            }
        }
        if (card=="HQ"){
            if (boarddeck[10][1]=="HJ"){
                boarddeck[11][1]="HQ";
                player[i][n]=" 0";
                return;
            }
        }
        if (card=="HK"){
            if (boarddeck[11][1]=="HQ"){
                boarddeck[12][1]="HK";
                player[i][n]=" 0";
                return;
            }
        }
        // Diamond
        if (card=="D10"){
            if (boarddeck[8][3]=="D9"){
                boarddeck[9][3]="D10";
                player[i][n]=" 0";
                return;
            }
        }
        if (card=="DJ"){
            if (boarddeck[9][3]=="D10"){
                boarddeck[10][3]="DJ";
                player[i][n]=" 0";
                return;
            }
        }
        if (card=="DQ"){
            if (boarddeck[10][3]=="DJ"){
                boarddeck[11][3]="DQ";
                player[i][n]=" 0";
                return;
            }
        }
        if (card=="DK"){
            if (boarddeck[11][3]=="DQ"){
                boarddeck[12][3]="DK";
                player[i][n]=" 0";
                return;
            }
        }
        // Clubs
        if (card=="C10"){
            if (boarddeck[8][2]=="C9"){
                boarddeck[9][2]="C10";
                player[i][n]=" 0";
                return;
            }
        }
        if (card=="CJ"){
            if (boarddeck[9][2]=="C10"){
                boarddeck[10][2]="CJ";
                player[i][n]=" 0";
                return;
            }
        }
        if (card=="CQ"){
            if (boarddeck[10][2]=="CJ"){
                boarddeck[11][2]="CQ";
                player[i][n]=" 0";
                return;
            }
        }
        if (card=="CK"){
            if (boarddeck[11][2]=="CQ"){
                boarddeck[12][2]="CK";
                player[i][n]=" 0";
                return;
            }
        }
        
       //cout << card << endl;
        // C1 Bug Fixing
        if (card=="C1"){
            if (boarddeck[1][2]=="C2"){
                boarddeck[0][2]="C1";
                player[i][n]=" 0";
                return;
            }
        }
        if (card=="S1"){
            if (boarddeck[1][0]=="S2"){
                boarddeck[0][0]="S1";
                player[i][n]=" 0";
                return;
            }
        }
        if (card=="H1"){
            if (boarddeck[1][1]=="H2"){
                boarddeck[0][1]="H1";
                player[i][n]=" 0";
                return;
            }
        }
        if (card=="D1"){
            if (boarddeck[1][3]=="D2"){
                boarddeck[0][3]="D1";
                player[i][n]=" 0";
                return;
            }
        }
        

        if (player[i][n] != " 0") {
            // Find a valid position on the board
            for (int row = 0; row < 13; row++) {
                for (int col = 0; col < 4; col++) {
                    if (boarddeck[row][col] == " 0") {
                        //cout << "working"<< endl;
                        if (isValidMove(boarddeck, row, col, player[i][n])) {//&& boarddeck[row][col][0]==player[i][n][0] ) {
                            //cout << "working"<< endl;
                            boarddeck[row][col] = player[i][n];
                            player[i][n] = " 0";
                            //printrealdeck(boarddeck);

                            return; // Card has been played, exit the function
                        }
                    }
                }
            }
        }
        // card greater than 9 (making the tree)
        
        // searching for classical 7
        if (card=="H7"){
            boarddeck[6][1]=card;
            player[i][n]= " 0";
            return;
        
        }
        if (card=="S7" && boarddeck[6][1]=="H7"){
            boarddeck[6][0]=card;
            player[i][n]= " 0";
            return;
            
        }
        if (card=="C7" && boarddeck[6][1]=="H7"){
            boarddeck[6][2]=card;
            player[i][n]= " 0";
            return;
            
        }
        if (card=="D7" && boarddeck[6][1]=="H7"){
            boarddeck[6][3]=card;
            player[i][n]= " 0";
            return;
            
        }

    }
}

void playplayer(string player[13][4], string boarddeck[13][4], int n, int voice){

    cout << "Your Cards : ";
    for(int i=0; i<13; i++){
        if(player[i][n] != " 0"){
            cout << player[i][n] << " ";
        }
    }
    cout << endl;

    string choice;
    int newly=0;
    
    cout << "Place your card : ";
    cin >> choice;

    bool validity = false;
    

    
    for(int i=0; i<13; i++){
        if(player[i][n] == choice ){
            validity = true; 
            newly=i;
            break;
        }
    }
    if (validity){
        cout << "You can play this card !"<< endl;
        freeplay(player, boarddeck, n, voice,newly) ;
    }
    else{
        cout << "You can't play it !"<< endl;
        string anotherchoice ;
        cout << "Do you want to pass : " ;
        cin >> anotherchoice ;
        if (anotherchoice[0]=='Y'){
            play(player, boarddeck, n, voice) ;
            
        }
        else {
            playplayer(player,boarddeck, n, voice);

        }
    
    }
    for(int i=0; i<13; i++){
        if(player[i][n] == choice ){
            validity = false; 
            newly=i;
            break;
        }
    }
    if (!validity){
        string s= "Sorry! You cannot play this card.";
        Delay(s);
        cout << endl;
        cout << "Another Valid Card has been played."<< endl;
        play(player,boarddeck, n, voice);
    }

    return;

}

void bitfull(string diamond[], string heart[], string spade[], string clubs[]){

    string message = "BITFULL";
    int delayMs = 500; // Delay in milliseconds (0.25 seconds)

    printMessageSlowly(message, delayMs);
    cout << "/////////////////////////////////////////////////////////" << endl;

    
    string deck[52]={
                        "H1","H2","H3","H4","H5","H6","H7","H8","H9","H10","HJ","HQ","HK",
                        "D1","D2","D3","D4","D5","D6","D7","D8","D9","D10","DJ","DQ","DK",
                        "S1","S2","S3","S4","S5","S6","S7","S8","S9","S10","SJ","SQ","SK",
                        "C1","C2","C3","C4","C5","C6","C7","C8","C9","C10","CJ","CQ","CK"
                        };

    shufflecards(deck,52);
    //printcards(deck,52);

    string player[13], cpu1[13], cpu2[13], cpu3[13];

    int niggu=0, tofu=0;

    for (int i=0; i<52; i++){

        if (niggu==0){
            player[tofu]=deck[i];
            niggu ++;
        }
        else if (niggu==1){
            cpu1[tofu]=deck[i];
            niggu ++;
        }
        else if (niggu==2){
            cpu2[tofu]=deck[i];
            niggu ++;
        }
        else {
            cpu3[tofu]=deck[i];
            niggu =0;
            tofu++;
        }
    }
    

    // boarddeck is collection of cards on board

    string boarddeck[13][4]={" 0",  " 0"  ,  " 0"  ,  " 0",  //1
                             " 0",  " 0"  ,  " 0"  ,  " 0",  //2
                             " 0",  " 0"  ,  " 0"  ,  " 0",  //3
                             " 0",  " 0"  ,  " 0"  ,  " 0",  //4
                             " 0",  " 0"  ,  " 0"  ,  " 0",  //5
                             " 0",  " 0"  ,  " 0"  ,  " 0",  //6
                             " 0",  " 0"  ,  " 0"  ,  " 0",  //7
                             " 0",  " 0"  ,  " 0"  ,  " 0",  //8
                             " 0",  " 0"  ,  " 0"  ,  " 0",  //9
                             " 0",  " 0"  ,  " 0"  ,  " 0",  //10
                             " 0",  " 0"  ,  " 0"  ,  " 0",  //11
                             " 0",  " 0"  ,  " 0"  ,  " 0",  //12
                             " 0",  " 0"  ,  " 0"  ,  " 0"}; //13
                            
    
    //printstuff();
    //printrealdeck(boarddeck);

    // Defining First Chance

    int chance=1;
    string first[13], second[13], third[13], fourth[13];
    int player1, player2, player3, player4;
    int realplayer;
    bool w1 = false, w2=false, w3=false,w4=false;

    // First player
    for (int i=0; i<13; i++){
        if (player[i]=="H7"){
            player1 = 1;
            w1 = true;
        }
    }
    if (w1 == false){
        chance ++;
        player1 = chance;
    }
    realplayer = chance;
    // Second player
    for (int i=0; i<13; i++){
        if (cpu1[i]=="H7"){
            player2 = 1;
            w2 = true;
        }
    }
    if (w2 == false){
        chance ++;
        player2 = chance;
    }
    // Third player
    for (int i=0; i<13; i++){
        if (cpu2[i]=="H7"){
            player3 = 1;
            w3 = true;
        }
    }
    if (w3 == false){
        chance ++;
        player3 = chance;
    }
    // Fourth player
    for (int i=0; i<13; i++){
        if (cpu3[i]=="H7"){
            player4 = 1;
            w4 = true;
        }
    }
    if (w4 == false){
        chance ++;
        player4 = chance;
    }
    /*
    cout << player1 << endl;
    cout << player2 << endl;
    cout << player3 << endl;
    cout << player4 << endl;
    */
    player1 -= 1;
    player2 -= 1;
    player3 -= 1;
    player4 -= 1;
    
    string fakedeck[13][4];
    //player 1
    for(int i=0; i<13; i++){
        fakedeck[i][player1]= player[i];
    }
    //player 2
    for(int i=0; i<13; i++){
        fakedeck[i][player2]= cpu1[i];
    }
    //player 3
    for(int i=0; i<13; i++){
        fakedeck[i][player3]= cpu2[i];
    }
    //player 4
    for(int i=0; i<13; i++){
        fakedeck[i][player4]= cpu3[i];
    }
    //printrealdeck(fakedeck);
    
    // to play chancewise
    //cout << realplayer << endl;
    //calculatepoints(fakedeck, 1);

    cout << "Your are Player "<< realplayer << " !" << endl;
    realplayer -=1 ;
    int count=1;
    while (true){

        bool polo = false;
       
        for (int i=0; i<4; i++){
            
            
            
            //cout << i<< endl;
            
            if (i!=realplayer){
                cout << "P";
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << "l";
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << "a";
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << "y";
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << "e";
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << "r";
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << " ";
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << i+1;
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << " ";
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << "i";
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << "s";
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << " ";
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << "p";
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << "l";
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << "a";
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << "y";
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << "i";
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << "n";
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << "g";
                this_thread::sleep_for(chrono::seconds(1));
                cout << ".";
                this_thread::sleep_for(chrono::seconds(1));
                cout << ".";
                this_thread::sleep_for(chrono::seconds(1));
                cout << '.' << endl;
            } 
            
            if (i==realplayer){
                cout << "I";
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << "t";
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << "'";
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << "s";
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << " ";
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << "y";
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << "o";
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << "u";
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << "r";
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << " ";
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << "c";
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << "h";
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << "a";
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << "n";
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << "c";
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << "e" ;
                this_thread::sleep_for(chrono::seconds(1));
                cout << '.';
                this_thread::sleep_for(chrono::seconds(1));
                cout << '.';
                this_thread::sleep_for(chrono::seconds(1));
                cout << '.' << endl;
                

                playplayer(fakedeck,boarddeck, i, realplayer);
                
            }
            
            else{
                play(fakedeck, boarddeck, i, realplayer);
            }   

            printstuff();
            printrealdeck(boarddeck);
            
            int cards = 0;
            for (int j=0; j<13; j++){
                if (fakedeck[j][i]==" 0"){
                    cards++;
                }
                
            }
            
            if (cards==12){
                polo = true;
                cout << endl;
                // Printing Winner 
                cout << "Here we go again";
                this_thread::sleep_for(chrono::seconds(1));
                cout << '.';
                this_thread::sleep_for(chrono::seconds(1));
                cout << '.';
                this_thread::sleep_for(chrono::seconds(1));
                cout << '.' << endl ;
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << "T";
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << "h";
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << "e";
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << " ";
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << "W";
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << "i";
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << "n";
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << "n";
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << "e";
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << "r";
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << " " ;
                this_thread::sleep_for(chrono::seconds(1));
                cout << 'i';
                this_thread::sleep_for(chrono::seconds(1));
                cout << 's';
                this_thread::sleep_for(chrono::seconds(1));
                cout << ' ' << endl;

                this_thread::sleep_for(chrono::milliseconds(100));
                cout << "P";
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << "l";
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << "a";
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << "y";
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << "e";
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << "r";
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << " ";
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << i+1 << endl;
                this_thread::sleep_for(chrono::milliseconds(1500));

                break;
                

                
            }
            
        }
        if (polo){
            break;
        }
        
        if (count == 200){
            break;
        }
        
    }
    calculatepoints(fakedeck, 1);
    /*
    printstuff();
    printrealdeck(boarddeck);
    printrealdeck(fakedeck);

    cout << endl;
    */

    //cout << boarddeck[6][1][0]<< " "<< ;


}






