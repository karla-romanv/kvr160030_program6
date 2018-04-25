//Karla Roman
//kvr160030@utdallas.edu
//cs3377.002

//declare header files for cdk usage 
//and to read in binary files
#include <stdint.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "cdk.h"
#include <fstream>
#include <sstream>
#define MATRIX_WIDTH 3
#define MATRIX_HEIGHT 5
#define BOX_WIDTH 18
#define MATRIX_NAME_STRING "Binary File Contents"
const int maxStrLength = 25;

using namespace std;

//this class will out put the output onto the matrix
//the magic number, its version of the file,and the records contained
class BinaryFile
{
public:
  uint32_t magicNumber;
  uint32_t versionNumber;
  uint64_t numberRecords;
};

//this class witholds the structure of the matrix
class BinaryFileRecord
{
public:
  uint8_t strLength;
  char stringBuffer[maxStrLength];
};

//main will construct the matrix through the cdk
//and the binary file will be read to be converted into 
//a readable output
int main()
{
  //create the window through the CDK toolkit
  WINDOW        *window;
  CDKSCREEN     *cdkscreen;
  CDKMATRIX     *myMatrix;

  //name the rows and columns of the matrix
  const char *rowTitles[] = {"","a", "b", "c", "d", "e"};
  const char *columnTitles[] = {"","a","b","c"};

  //set the matrix widths and create through the cdk
  int boxWidths[] = {BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH,BOX_WIDTH};
  int boxTypes[] = {vMIXED, vMIXED, vMIXED, vMIXED,  vMIXED,  vMIXED};
  
  //display the created matrix through the cdk toolkit
  window = initscr();
  cdkscreen = initCDKScreen(window);

  initCDKColor();

  //create the matrix within the box
  myMatrix = newCDKMatrix(cdkscreen, CENTER, CENTER, MATRIX_HEIGHT, MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_WIDTH,MATRIX_NAME_STRING, (char **) rowTitles, (char **) columnTitles, boxWidths,boxTypes, 1, 1, ' ', ROW, true, true, false);


  //output an error if matrix could not be created
  if (myMatrix == NULL)
    {
      printf("Error creating Matrix\n");
      _exit(1);
    }


  //draw the matrix onto the console
  drawCDKMatrix(myMatrix, true);


  //using ifstream to read in a specified binary file
  ifstream binInfile("cs3377.bin", ios::in | ios::binary);

  //create an instnce of the classes to be used
  //to read the binary file
  BinaryFile *binaryHeader = new BinaryFile();
  BinaryFileRecord *binaryRecord = new BinaryFileRecord();

  //read in the file as strings
  binInfile.read((char *) binaryHeader, sizeof(BinaryFile));
  binInfile.read((char *) binaryRecord, sizeof(BinaryFileRecord));

  //delcare strings to hold in the values of the contents
  string MagicNumber, version, NumberOfRecords, stringlengthb,stringlengthB, stringlengthc, stringlengthC, stringlengthd, stringlengthD, stringlengthe,
   stringlengthE, SeedMoney, Leadership, Entrepreneurship, Skillz;
 
  //output onto the matrix headers for what will be printed
  MagicNumber = "Magic: 0x";
  version = "Version: ";
  NumberOfRecords = "NumRecords: "; 
  stringlengthB = "strlen: ";  
  stringlengthC = "strlen: "; 
  stringlengthD = "strlen: "; 
  stringlengthE = "strlen: "; 

  //covert the binary to printable characters
  stringstream convert;

  //convert the magic number
  convert << hex << uppercase << binaryHeader->magicNumber; 
  MagicNumber += convert.str();
  //use this code of line to reset after each read 
  convert.str("");
  
  //comvert the version number
  convert << dec << binaryHeader->versionNumber; 
  version += convert.str();
  convert.str("");

  //convert the number of records
  convert << binaryHeader->numberRecords;
  NumberOfRecords += convert.str();
  convert.str("");


  //convert the records on rows b-d
  convert << binaryRecord->stringBuffer; 
  stringlengthb = convert.str();
  convert.str("");
  convert << stringlengthb.length();
  stringlengthB += convert.str();
  convert.str("");

  //read in the information convert then output onto the matrix
  binInfile.read((char *) binaryRecord, sizeof(BinaryFileRecord));
  convert << binaryRecord->stringBuffer; 
  stringlengthc = convert.str();
  convert.str("");
  convert << stringlengthc.length();
  stringlengthC += convert.str();
  convert.str("");
  

  //after reset read in the information convert the
  //output and the output onto the matrix
  binInfile.read((char *) binaryRecord, sizeof(BinaryFileRecord));
  convert << binaryRecord->stringBuffer; 
  stringlengthd = convert.str();
  convert.str("");
  convert << stringlengthd.length();
  stringlengthD += convert.str();
  convert.str("");


  //after reset read in the information convert the 
  //output and send the output onto the matrix
  binInfile.read((char *) binaryRecord, sizeof(BinaryFileRecord));
  convert << binaryRecord->stringBuffer; 
  stringlengthe = convert.str();
  convert.str("");
  convert << stringlengthe.length();
  stringlengthE += convert.str();
  convert.str("");


  //set the output onto the indicated cells 
  //based on the desired spot to set the information at

  //first row will contain the magic number, version, and amount of records
  setCDKMatrixCell(myMatrix, 1, 1, MagicNumber.c_str());    
  setCDKMatrixCell(myMatrix, 1, 2, version.c_str());      
  setCDKMatrixCell(myMatrix, 1, 3, NumberOfRecords.c_str());   

  //the rest of the rows (b-d) will have the informartion contained
  //and the length of that information
  setCDKMatrixCell(myMatrix, 2, 1, stringlengthB.c_str());     
  setCDKMatrixCell(myMatrix, 2, 2, stringlengthb.c_str());     
  setCDKMatrixCell(myMatrix, 3, 1, stringlengthC.c_str());   
  setCDKMatrixCell(myMatrix, 3, 2, stringlengthc.c_str());     
  setCDKMatrixCell(myMatrix, 4, 1, stringlengthD.c_str());     
  setCDKMatrixCell(myMatrix, 4, 2, stringlengthd.c_str());     
  setCDKMatrixCell(myMatrix, 5, 1, stringlengthE.c_str());     
  setCDKMatrixCell(myMatrix, 5, 2, stringlengthe.c_str());    
  drawCDKMatrix(myMatrix, true);      

  //continue reading file
  unsigned char readVal;
  cin >> readVal;
  
  //when done close file
  endCDK();
}

