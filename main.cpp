#include <iostream>
#include <list>
#include <stdlib.h>

using std::string;
using std::cout;
using std::cin;
using std::endl;



template < typename T >
class List {

     T * catalog; /**< ñïèñîê */
     int countOfFiles; /**< êîëè÷åñòâî ôàéëîâ */
 public:
     /** \brief Êîíñòðóòîð áåç ïàðàìåòðîâ
      *
      */

     List(){
        catalog =(T *)malloc(sizeof(T) * 1);
        countOfFiles = 0;
        }
    
     void add(T value){
        catalog[countOfFiles] = value;
        ++countOfFiles;
        catalog =(T *)realloc(catalog ,sizeof(T) * countOfFiles);

     }
   
      
      void printAll(){
         for(int i = 0; i < countOfFiles; i ++ ){
             cout<< catalog[i] << endl;
         }
     }
  

     ~List(){}
};




int main()
{
    int N = 0;
    cin>>N;
    char type = '1';
    for(int i = 0; i < N; i ++){
        cin>>type;
        if(type == 's'){
            List<string>* catalog = new List<string>();
            int count = 0;
            cin >> count;
            for(int i = 0; i < count; i ++){
                string str = "";
                cin >> str;
                catalog->add(str);
            }
            catalog->printAll();
            delete catalog;
        } else if (type == 'i') {
            List<int> * catalog = new List<int>();
            int count = 0;
            cin >> count;
            for(int i = 0; i < count; i ++){
                int number = 0;
                cin >> number;
                catalog->add(number);
            }
            catalog->printAll();
            delete catalog;
        }

    }
    return 0;
}
