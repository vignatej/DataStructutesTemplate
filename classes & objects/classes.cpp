#include <iostream>
#include <string>
#include <vector>
class Player
{
public:
    std::string name = "starttt";
    int health = 20;
    int xp;

public:
    void talk(std::string)
    {
        std::cout << "my name: " << name << std::endl;
        std::cout << "my health: " << health << std::endl;
        std::cout << "my xp: " << xp << std::endl;
    };
    bool is_dead(std::string po);
    Player()
    {
        std::cout << "empty constructor calltd" << std::endl;
    };
    Player(std::string name)
        : name{name}
    {
        std::cout << "cons with 1 param called" << std::endl;
    }
    Player(std::string name, int hlth)
    {
        this->name = name;
        this->health = hlth;
        std::cout << "cons with 2 param called" << std::endl;
    }
    Player(std::string name, int hlth, int xp)
        :name{name}, health{hlth}, xp{xp}
    {
        std::cout << "cons with 3 param called" << std::endl;
    }
    ~Player(){
        std::cout<<"comp"<<std::endl;
    }
};

class BankAcc{
    private:
        std::string acc_holder_name;
        int amount;
    public:
        int get_amount();
        BankAcc();
        BankAcc(std::string);
        BankAcc(std::string, int amount);
        ~BankAcc();
        BankAcc(const BankAcc &src);
};

int bankAcc_amount(BankAcc na){
    return na.get_amount();
}

int main(int argc, char const *argv[])
{
    Player vigna;
    Player tej;
    Player *aass_nb{nullptr};
    aass_nb = new Player();

    // delete aass_nb;
    std::cout << "hello " << vigna.health << std::endl;
    vigna.health = 200;
    std::cout << "hello " << vigna.health << std::endl;

    Player players[]{vigna, tej};
    std::vector<Player> player_vec{vigna};
    player_vec.push_back(tej);
    for (auto i : player_vec)
    {
        i.talk("");
    }
    (*aass_nb).talk("asd");
    std::cout << (*aass_nb).name << std::endl;
    std::cout << aass_nb->name << std::endl;
    std::cout << aass_nb->is_dead("yes") << std::endl;

    {
        Player *last = new Player("hello", 20);
        Player pp;
        Player asq {"helllo", 120,150};
        asq.talk("");
    }
    {
        BankAcc b1;
        BankAcc *b2 = new BankAcc();
        delete b2;
        BankAcc *b3 = new BankAcc("sec");
        delete b3;
        BankAcc *b4 = new BankAcc("third", 200);
        delete b4;
        BankAcc b5 {"vigna", 500};
        std::cout<<"/n"<<bankAcc_amount(b5)<<std::endl;
        BankAcc *b6 = new BankAcc("tej", 1000);
        std::cout<<"/n"<<bankAcc_amount(*b6)<<std::endl;
        delete b6;
    }
    std::cout << "completed" << std::endl;
    return 0;
}
bool Player::is_dead(std::string a)
{
    if (a == "yes")
    {
        return true;
    }
    return false;
}

int BankAcc::get_amount(){
    return this->amount;
}
BankAcc::BankAcc()
    :BankAcc{"None", 0}{
        std::cout<<"no param bank acc cons"<<std::endl;
}

BankAcc::BankAcc(std::string name)
    :BankAcc{name, 0}{
        std::cout<< " 1 param bank acc cons" <<std::endl;
}

BankAcc::BankAcc(std::string name, int amount)
    :acc_holder_name{name}, amount{amount} {
        std::cout<<" 2 param bank acc constructor"<<std::endl;
}

BankAcc::~BankAcc(){
    std::cout<<"name: "<<acc_holder_name<<", amount: "<<amount<<" closed"<<std::endl;
}

BankAcc::BankAcc(const BankAcc &src)
    :acc_holder_name{src.acc_holder_name}, amount{src.amount}{
        std::cout<<"copy of src"<<std::endl;
}