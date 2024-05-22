#include <iostream>
#include <string>
#include <unordered_map>

bool ransomNote(std::string mag, std::string note){
    std::unordered_map<char, int> map;
    for(char c : mag){
        if(map.find(c) != map.end()){
            map[c]++;
        }
        else{
            map[c] = 1;
        }
    }
    for(char c : note){
        if(map.find(c) != map.end()){
            if(map[c] > 0){
                map[c]--;
            }
            else{
                return false;
            }
        }else{
            return false;
        }
    }
    return true;
}


int main(){
    std::string mag1 = "Foxtrot";
    std::string note = "roxtz";
    bool res = ransomNote(mag1,note);
    std::cout << "magazine: " << mag1 << " note: " << note << "res "<< res << "\n";

}