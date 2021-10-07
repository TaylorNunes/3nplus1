#include <iostream>
#include <vector>

// this divides the number by 2 
void calcEven(std::vector<int> &vect){
   // std::cout << "even\n";
   // std::cout << "Vect size: " << vect.size() << "\n";
    int startingSize = vect.size();
    for(int i = 0; i < startingSize; i++){
       // std::cout << vect.at(i) << "\n";
        if (vect.at(i) == 0) continue;
        if (vect.at(i)%2 != 0) vect.at(i-1)+=5;
        vect.at(i) /= 2;
    }
    
    if (vect.at(vect.size()-1) == 0) vect.pop_back();
    
    return; 
}

void calcOdd(std::vector<int> &vect){
    //std::cout << "odd\n";
    //std::cout << "Vect size: " << vect.size() << "\n";
    int startingSize = vect.size();
    int carryOver = 0;
    for(int i = 0; i < startingSize; i++){
        //std::cout << vect.at(i) << "\n";
        //if (vect.at(i) == 0) continue;
        int newTemp =  vect.at(i)*3;
        if (i == 0) newTemp++;
        else newTemp+=carryOver;
        vect.at(i) = newTemp%10;
        //if (newTemp/10 == 0) continue;
        if (i+1<startingSize) carryOver= newTemp/10;
        else vect.push_back(newTemp/10);
    }
    
    if (vect.at(vect.size()-1) == 0) vect.pop_back();
    
    return;
}

int main(int argc, char **argv){

    if(argc!=2){
        std::cout << "Invalid arg. You entered " << argc << " args\n";
        return 0;
    }
    
    std::vector<int> theNumberArray;
    std::string theNumberString = argv[1];
    
    //std::cout << "Enter a number: ";
    //std::cin >> theNumberString;
    //std::cout << "\n";
    
    int theStringSize = theNumberString.size();
    //std::cout << "str size: " << theStringSize << "\n";
    for(int i=0; i<theStringSize; i++){
        if (std::isdigit(theNumberString[theStringSize - i - 1]) == 0) return 0;
        theNumberArray.push_back(theNumberString[theStringSize - i - 1]-'0');
    }
    //std::cout << "Orig num array size: " << theNumberArray.size() << "\n";
        //std::cout << "Starting num: ";
    for(int i = 0; i < theNumberArray.size(); i++){
        std::cout << theNumberArray.at(theNumberArray.size() - i - 1);
    }
    std::cout << "\n";
   
    unsigned long long stoppingTime = 0;
    while (true){
        stoppingTime++;
        if (theNumberArray.at(0) % 2 == 0) calcEven(theNumberArray); 
        else calcOdd(theNumberArray);

        //std::cout << "Printing num: ";
        for(int i = 0; i < theNumberArray.size(); i++){
            std::cout << theNumberArray.at(theNumberArray.size() - i - 1) << "";
        }
        std::cout << "\n";
        
        //std::cout << "Array size: " << theNumberArray.size() << "\n";
        if (theNumberArray.size() == 1 && theNumberArray.at(0) == 1) break;
    }
    
    std::cout << "\nStopping time: " << stoppingTime << "\n";
    return 0;
}
