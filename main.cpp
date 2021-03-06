#include <iostream>
#include <fstream>

using namespace std;
fstream file;
short pin = 0;


class Crypt{
private:
    char arr[200] = {'.','\\','|','[',']','{','E','}','\"','\'','=','h','i','+',':',';','"','?',',','~','O',' ','!','@','#','%','^','&','a','*','(',')','3','4','5','6','7','8','9','0','b','c','d','f','g','j','k','l','m','n','o','p','q','r',
                    's','t','u','v','w','x','y','z','A','B','C','D','F','G','H','I','J','K','L','1','2','M','N','P','Q','R','S','T','U','V','W','X','Y','e','Z'};
    int size;


public:
    Crypt(){
        size = 0;

    };

    int matchCharacter(char character){

        int i = 0;
        while(true){
            if(character == arr[i]) {
                return i;
            }
            else{

                i++;
            }


        }



    }

    void writeToAFile(char buffer[], long int length, string fileName){
        file.open(fileName);
        for(int i = 0; i < length; i++){

            file << buffer[i];


        }

        file.close();


    }

    void writeDate(string fileName){

        file.open(fileName);

        file.close();

    }

    void readFromFile(char buffer[], long int length, string fileName){
        file.open(fileName);
        for(int i = 0; i < length; i++){

            file << buffer[i];


        }

        file.close();


    }



    char encryptFile(char c[], long int length){
        //pin = pin+5;
        for(int i = 0; i < length; i++){
            c[i] = arr[matchCharacter((char) (c[i] + pin))];

        }

    }

    char decryptFile(char c[], long int length){

        //pin = pin-5;
        for(int i = 0; i < length; i++){
            c[i] = arr[matchCharacter((char) (c[i] - pin))];

        }

    }



};





int main() {
    Crypt crypt;
    string inputFileName;
    char storage[30000];



    cout << "Enter File Name: ";
    cin >>  inputFileName;
    cout << "Whats the password?: ";
    short *pinptr = &pin;
    cin >> *pinptr;


    cout << "to encrypt file press 1" << endl;
    cout << "to decrypt file press 2" << endl;
    int number;
    cin >> number;
    switch (number){

        case 1:
            //cout << "type file name to open: ";
            //cin >> inputFileName;
            file.open(inputFileName);
            if(file.is_open()){
                // get length of file:
                file.seekg (0, file.end);
                long int length = file.tellg();
                file.seekg (0, file.beg);


                // allocate memory:
                //char * buffer = new char [length];

                cout << "file is open" << endl;
                // read data as a block:
                file.read (storage,length);

                file.close();

                // print content:
                pinptr= &pin+3;
                crypt.writeDate(inputFileName);
                crypt.encryptFile(storage, length);

                //cout.write(storage, length);
                //cout << endl;

                crypt.writeToAFile(storage, length, inputFileName);
                cout << "DONE" << endl;


            }
            break;

        case 2:
            //cout << "type file name to open: ";
            //cin >> inputFileName;
            file.open(inputFileName);
            if(file.is_open()){
                // get length of file:
                file.seekg (0, file.end);
                long int length = file.tellg();
                file.seekg (0, file.beg);

                // allocate memory:
                //char * buffer = new char [length];

                cout << "file is open" << endl;
                // read data as a block:
                file.read (storage,length);

                file.close();

                // print content:
                pinptr= &pin-3;
                crypt.decryptFile(storage, length);

                //cout.write(storage, length);
                //cout << endl;

                crypt.writeToAFile(storage, length, inputFileName);
                cout << "DONE" << endl;



            }



        break;
    }



    return 0;
}