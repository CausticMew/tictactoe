
#include <iostream> //preprocessor directive is 
#include <string>
#include <vector>
#include <cstdlib>

//#define MAX 3

const int MAX = 3;

//STRUCTURE
struct Point{ //point represents an object, encapsulation is taking all the elements of a specific object in the objects definition
    int x;
    int y;
    char symbol;
    bool isEmpty;
};

struct Player{
    bool hasWon;
    char playerSymbol;
    std::string name;
    //constructor
    Player() {
        this->hasWon = false;
        this->playerSymbol = playerSymbol;
        this->name = "";
    }
};

void populateGridWithXandYandFalse();
void game();
bool isOver();
int placement(int x, char symbol);
char getSymbol();
void display();
//void winner();
int horizontal(int x, int y, char symbol);
int vertical(int x, int y, char symbol);
int negDiagonal(int x, int y, char symbol);
int posDiagonal(int x, int y, char symbol);

Point grid[MAX][MAX]; //populated with for loop

Player player1;
Player player2;





//LOGIC
int main()
{
    game();

    int i = 0;
    
    while(i < MAX)
    {
        int j = 0;
        while(j < MAX)
        {
            std::cout << "#";
            j++;
        }
        std::cout << "\n";
        i++;
    }

    return 0;
}


void populateGridWithXandYandFalse() { 

    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            grid[i][j].x = i; // "." member access operator
            grid[i][j].y = j;
            grid[i][j].isEmpty = true;
        }
    }
}

void playerMove(Player p)
{
    int p1;
    int count = 0;
    
    std::cout << "Enter placement for symbol: ";
    std::cin >> p1;
    
    count = placement(p1, p.playerSymbol);
    display();

    if (count == 3)
    {
        std::cout << "Player" << p.name << "has won\n";
        std::exit(0);
    }
    
    if (isOver() == true)
    {
        std::cout << "Tie!\n";
        std::exit(0);
    }
}

void game(){ //player 1 always goes 1st

    int i = 0;
    player1.name = " 1 ";
    player2.name = " 2 ";

    populateGridWithXandYandFalse();
    player1.playerSymbol = 'X'; //getSymbol();
    player2.playerSymbol = 'O'; //getSymbol();

    while(player1.hasWon == false && player2.hasWon == false)
    {
        playerMove(player1);
        playerMove(player2);

    }
}

bool isOver(){
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            if (grid[i][j].isEmpty == true)
            {
                return false;
            }
            
        }
    }
    return true;
}

int placement(int x, char symbol) {
    int vcount = 0;
    int hcount = 0;
    int ndcount = 0;
    int pdcount = 0;

    switch(x) {
         case 1:
            grid[0][0].symbol = symbol;
            grid[0][0].isEmpty = false;
            hcount = horizontal(0, 0, symbol);
            vcount = vertical(0, 0, symbol);
            ndcount = negDiagonal(0, 0, symbol);
            break;
         case 2:
            grid[0][1].symbol = symbol;
            grid[0][1].isEmpty = false;
            hcount = horizontal(0, 0, symbol);
            vcount = vertical(0, 1, symbol);
            break;
         case 3:
            grid[0][2].symbol = symbol;
            grid[0][2].isEmpty = false;
            hcount = horizontal(0, 0, symbol);
            vcount = vertical(0, 2, symbol);
            pdcount = posDiagonal(0, 2, symbol);
            break;
         case 4:
            grid[1][0].symbol = symbol;
            grid[1][0].isEmpty = false;
            hcount = horizontal(1, 0, symbol);
            vcount = vertical(0, 0, symbol);
            break;
         case 5:
            grid[1][1].symbol = symbol;
            grid[1][1].isEmpty = false;
            hcount = horizontal(1, 0, symbol);
            vcount = vertical(0, 1, symbol);
            ndcount = negDiagonal(0, 0, symbol);
            pdcount = posDiagonal(0, 2, symbol);
            break;
         case 6:
            grid[1][2].symbol = symbol;
            grid[1][2].isEmpty = false;
            hcount = horizontal(1, 0, symbol);
            vcount = vertical(0, 2, symbol);
            break;
         case 7:
            grid[2][0].symbol = symbol;
            grid[2][0].isEmpty = false;
            hcount = horizontal(2, 0, symbol);
            vcount = vertical(0, 0, symbol);
            pdcount = posDiagonal(0, 2, symbol);
            break;
         case 8:
            grid[2][1].symbol = symbol;
            grid[2][1].isEmpty = false;
            hcount = horizontal(2, 0, symbol);
            vcount = vertical(0, 1, symbol);
            break;
         case 9:
            grid[2][2].symbol = symbol;
            grid[2][2].isEmpty = false;
            hcount = horizontal(2, 0, symbol);
            vcount = vertical(0, 2, symbol);
            ndcount = negDiagonal(0, 0, symbol);
            break;
        default:
            std::cout << "Invalid!\n";
    }

    std::vector < int > arr1; //cpp array
    arr1.push_back(hcount);
    arr1.push_back(vcount);
    arr1.push_back(ndcount);
    arr1.push_back(pdcount);

    int max = arr1[0];

    for(int i = 0; i < arr1.size(); i++) 
    {
        if(max < arr1[i])
        {
            max = arr1[i];
        }
    }
    return max;
    // if (hcount == 3 || vcount == 3 || ndcount == 3 || pdcount == 3)
    // {
    //     std::cout << "Player: " << symbol << " has won!" << std::endl;
    //     if (symbol == player1.playerSymbol)
    //     {
    //         player1.hasWon = true;
    //     }
    //     else if (symbol == player2.playerSymbol)
    //     {
    //         player2.hasWon = true;
    //     }
    // }
    
}

int horizontal(int x, int y, char symbol) {

    int counter = 0;

    for (y = 0; y < MAX; y++)
    {
        if (grid[x][y].symbol == symbol)
        {
            counter++;
        }
    }

    return counter;
}


int vertical(int x, int y, char symbol) {

    int counter = 0;
    for (x = 0; x < MAX; x++)
    {
        if (grid[x][y].symbol == symbol)
        {
            counter++;
        }
    }

    return counter;
}

int negDiagonal(int x, int y, char symbol) {

    int counter = 0;
    for (x = 0, y = 0; x < MAX; x++, y++)
    {
        if (grid[x][y].symbol == symbol)
        {
            counter++;
        }
    }

    return counter;
}

int posDiagonal(int x, int y, char symbol) {

    int counter = 0;
    for (x = 0, y = 2; x < MAX; x++, y--)
    {
        if (grid[x][y].symbol == symbol)
        {
            counter++;
        }
    }

    return counter;
}

char getSymbol() {

    char symbol;
    std::cout << "Enter your symbol: ";
    std::cin >> symbol;
    
    return symbol;
}

void display() {
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++) //(0,0)

        {
            if (grid[i][j].isEmpty == true){
                std::cout << '-';
            } else {
                std::cout << grid[i][j].symbol;
            }
            //std::cout << "[" << grid[i][j].x << ',' << grid[i][j].y << "] ";
        }
        std::cout << '\n';
    }
    std::cout << '\n';
    std::cout << '\n';
}

