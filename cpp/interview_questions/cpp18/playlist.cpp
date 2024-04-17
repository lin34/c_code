#include <stdexcept>
#include <iostream>
//Same as Leetcode Linked List Cycle
class Song
{
public:
    Song(std::string name): name(name), nextSong(NULL) {}
    
    void next(Song* song)
    {
        this->nextSong = song;
    }
    Song* getNextSong(){
        return nextSong;
    }
    bool isInRepeatingPlaylist()
    {
        if (nextSong == NULL || nextSong->getNextSong() ==NULL){
            return false;
        }
        Song* fast = nextSong;
        Song* slow = nextSong;
        while(fast->getNextSong() != NULL){
            slow = slow->getNextSong();
            fast = fast->getNextSong();
            if(fast->getNextSong() == NULL){
                return false;
            }
            fast = fast->getNextSong();
            if (slow == fast){
                return true;
            }
        }
        return false;
    }

private:
    const std::string name;
    Song* nextSong;
};

#ifndef RunTests
int main()
{
    Song* first = new Song("Hello");
    Song* second = new Song("Eye of the tiger");
    
    first->next(second);
    second->next(first);

    std::cout << std::boolalpha << first->isInRepeatingPlaylist();
}
#endif