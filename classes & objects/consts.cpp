#include <iostream>
#include <string>
class Player{
    private:
        std::string name = "uff";
        static int noOfPlayers;    
    public:
        void set_name(std::string name){
            this->name = name;
        }
        std::string getname() const{
            return this->name;
        }
        Player(){
            name = "hello ra";
            noOfPlayers++;
        }
        ~Player(){
            noOfPlayers--;
        }
        static int get_no_of_players(){
            return noOfPlayers;
        }
};
int Player::noOfPlayers = 0;
int main()
{
    
    const Player ravi;
    std::cout<<ravi.getname()<<std::endl;
    Player aqw;
    std::cout<<aqw.get_no_of_players()<<std::endl;
}
