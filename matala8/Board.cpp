#include "Board.h"
#include "ObjBoard.hpp"

////////// constructors and destructor ////////

Board::Board(int size){
    makeBoard(size);
   // bildBoard();
}


Board::Board(const Board& bo){
    makeBoard(bo.sizeOfBoard);
    if(bo.sizeOfBoard != 0)
    this->free();

    for(int i = 0; i < bo.sizeOfBoard; i++)
        for(int j = 0; j < bo.sizeOfBoard; j++)
            this->matBoard[i][j] = bo.matBoard[i][j];
}

Board::Board()
{
	this->sizeOfBoard=0;
	this->matBoard=NULL;
}


Board::~Board(){
	free();
}
//this code from: https://github.com/GeekCSA/Cpp-assignment/blob/master/Board.cpp
void Board::free(){
    for(int i = 0; i < this->sizeOfBoard; i++){
        delete[] this->matBoard[i];
    }
    delete[] this->matBoard;
}

//////// Bild Matrix ////////

void Board::makeBoard(int size){
    this->sizeOfBoard = size;
    matBoard = new ObjBoard*[sizeOfBoard];
    for(int i = 0; i < sizeOfBoard; i++)
        matBoard[i] = new ObjBoard[sizeOfBoard];

            bildBoard();

}

void Board::bildBoard(){
    for(int i = 0; i<sizeOfBoard; i++){
        for(int j = 0; j < sizeOfBoard; j++){
            matBoard[i][j] = ObjBoard(i,j);
        }
        cout << endl;
    }
}

///////// operators in and out //////////

ostream& operator<<(ostream& os, const Board& Board) {
    	for(int i = 0; i < Board.sizeOfBoard; i++){
		    for(int j = 0; j < Board.sizeOfBoard; j++)
                  os << Board.matBoard[i][j];
		
        os << "" << endl;
	}
    return os;
    }

std::istream& operator>>(std::istream& in, Board& board){


    uint i=0,j=0;
    char token;
    vector <char> vec;

    bool flag = true;
    int sizeOfBoard;
    int counter =0;
    while (cin.get(token)) {
        if(flag&&token=='\n'){
            flag =false;
            sizeOfBoard=counter;
        }
        counter ++;
        vec.push_back(token);
    }
    Board temp{sizeOfBoard};
    int index = 0;
    for(int i=0; i<sizeOfBoard; i++){
        for(int j=0; j<sizeOfBoard; j++){
            if(vec.at(index)!='\n'){
                temp.matBoard[i][j] = vec.at(index);
            }
            else{
                temp.matBoard[i][j] = vec.at(++index);
            }
            index++;
        }
    }
    board = temp;
    return in;
}

///////////// operators [] ///////////

char Board::operator[](const ObjBoard& obj) const{
    int x = obj.getX();
    int y = obj.getY();
    if(x >= this->sizeOfBoard || y >= this->sizeOfBoard){
          IllegalCoordinateException ex;
              ex.setA(x); ex.setB(y);
                throw ex;
    }
    else
    return matBoard[x][y].getAT();
}

ObjBoard& Board::operator[](const ObjBoard& obj){
    int x = obj.getX();
    int y = obj.getY();
    if(x >= this->sizeOfBoard || y >= this->sizeOfBoard){
          IllegalCoordinateException ex;
              ex.setA(x); ex.setB(y);
                throw ex;
    }
    else 
    return this->matBoard[x][y];
}

/////////// operators = ///////////

Board& Board::operator=(const char c){
if(c=='X'||c=='O'||c=='.') {
		for (int i = 0; i < sizeOfBoard; i++) {
			for (int j = 0; j < sizeOfBoard; j++) {
				this->matBoard[i][j] = c;
			}
            		}
	}    else{
        IllegalCharException ex;
        ex.setC(c);
        throw ex;
    }
    
    return *this;
}

Board& Board::operator=(const Board & bo){
    if(bo.sizeOfBoard != this->sizeOfBoard){
        free();
        makeBoard(bo.sizeOfBoard);
    }

    for(int i = 0; i < bo.sizeOfBoard; i++)
        for( int j = 0; j < bo.sizeOfBoard; j++)
            this->matBoard[i][j] = bo.matBoard[i][j];

            return *this;
}

char Board::operator=(const ObjBoard& ob){
    int x = ob.getX();
    int y = ob.getY();
    char a = this->matBoard[x][y].getAT();
    return a;
}

//////draw function//////

string Board::draw(int n){
	int num = 0;
	std::string fileName = "board"+to_string(num)+".ppm";

	while(true){
		ifstream f("board"+to_string(num)+".ppm");
		if(!f.good())
			break;
		else{
			num++;
		}
	}
	fileName = "board"+to_string(num)+".ppm";
	const int dimx = n, dimy = n;
    int sizeBoard = this->sizeOfBoard;
    if(sizeBoard ==0)
    sizeBoard =1;
    
    int cellSize = dimx/sizeBoard;
	ofstream imageFile(fileName, ios::out | ios::binary);
	imageFile << "P6" << endl << dimx <<" " << dimy << endl << 255 << endl;
	RGB image[dimx*dimy];
  
  for (int j = 0; j < dimy; ++j)  {  // row
    for (int i = 0; i < dimx; ++i) { // column
      image[dimx*j+i].red = (150);
      image[dimx*j+i].green = (180);
      image[dimx*j+i].blue = (190);
    }
  }

    //Bild columns
  	for (int i = 0; i < this->sizeOfBoard; ++i) {
		int Xfrom = i * (dimx/this->sizeOfBoard);

		for (int r = 10; r < dimy - 10 ; ++r) {
			image[dimy * (r) + Xfrom].red = (0);
			image[dimy * (r) + Xfrom].green = (0);
			image[dimy * (r) + Xfrom].blue = (0);
		}
      }

    //Bild rows
  	for (int i = 0; i < this->sizeOfBoard; ++i) {
		int Yfrom = i * (dimx/this->sizeOfBoard);

		for (int r = 10; r < dimy - 10 ; ++r) {
			image[(r) +(dimy * Yfrom)].red = (0);
			image[(r) +(dimy * Yfrom)].green = (0);
			image[(r) +(dimy * Yfrom)].blue = (0);
		}
      }

     for(int i=0; i<sizeBoard; i++){
         for(int j=0; j<sizeBoard; j++){

        int pixelrow = i*cellSize;
        int pixelcol = j*cellSize;
        //darw X
        if(matBoard[i][j]=='X'){
        for(int x=0; x<cellSize; x++){
           pixelcol = j*cellSize;
            for(int y=0; y<cellSize; y++){
                if(x==y || x+y == cellSize-1){
                image[pixelrow*dimx+pixelcol].red = 0;
                image[pixelrow*dimx+pixelcol].green = 0;
                image[pixelrow*dimx+pixelcol].blue = 0;       
                }     
                    pixelcol++;   
        }
        pixelrow++;
        }    
       }

       //Drae O
       if( matBoard[i][j] == 'O'){

    int dx, dy;
    int r = cellSize/2 -10;
    int x2_center = cellSize/2;
    int y2_center = cellSize/2;
    int pixrow = i*cellSize;
    int pixcol = j*cellSize;

    for (int x = 0; x < dimx; x++) {
        pixrow = i * cellSize;
        for (int y = 0; y < dimx; y++) {
            dx = x2_center - x;
            dy = y2_center - y;
            double distance = sqrt((dx * dx) + (dy * dy));
            if ((distance >= (r) - 1) && (distance <= (r) + 1)) {
                image[pixrow * dimx + pixcol].red = 0;
                image[pixrow * dimx + pixcol].green = 0;
                image[pixrow * dimx + pixcol].blue = 0;

            }
            pixcol++;
        }
        pixrow++;

    }
       }

      }
     }


  ///
  ///image processing
  ///
  imageFile.write(reinterpret_cast<char*>(&image), 3*dimx*dimy);
  imageFile.close();
    return fileName;
}






// istream& operator>>(std::istream& in, Board& board){
//     char c;
// 	string line;
//     getline(in,line); //Moves the input to string line
//     ifstream file(line);//Moves the data from the path to the string line

//     int k = 0;
// 	vector<ObjBoard> allString;//Vector that hold all the data

//     while(file.get(c)){//Passes a character in a string
//         if (c == 'X' || c == 'O' || c == '.')
//         allString.push_back(c);
//     }

//     board.free();
//     int s = sqrt(allString.size());
//     //Board temp(s);
//     board.makeBoard(s);

//     for(int i = 0; i < s; i++){
//         for(int j = 0; j < s; j++){
//             board[{i , j}] =  allString.at(k);
//             k++;
//         }
//     }

// 	        allString.clear();

//     return in;
// }