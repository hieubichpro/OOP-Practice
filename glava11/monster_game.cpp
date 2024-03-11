#include <iostream>
#include <string>

using namespace std;

class Creature
{
private:
    string m_name;
    char m_symbol;
    int m_health;
    int m_golds;
protected:
    int m_damage;
public:
    Creature(string name = "", char symbol = 'a', int health = 0, int damage = 0, int golds = 0) : m_name(name), m_symbol(symbol), m_health(health), m_damage(damage), m_golds(golds) {}
    string getName() const {return m_name;}
    char getSymbol() const {return m_symbol;}
    int getHealth() const {return m_health;}
    int getdamage() const {return m_damage;}
    int getGold() const {return m_golds;}
    void reduceHealth(int value) {m_health -= value;}
    bool isDead() {return m_health <= 0;}
    void addGold(int value) {m_golds += value;}
};

class Player : public Creature
{
private:
    int m_level;
public:
    Player(string name) : Creature(name, '@', 10, 1, 0) {}
    // using Creature::m_damage;
    void levelUp()
    {
        m_level++;
        m_damage++;
    }
    int getLevel() {return m_level;}
    bool hasWon() {return m_level >= 20;}
};

class Monster : public Creature
{
public:
    enum Type
    {
        DRAGON,
        ORC,
        SMILE,
        MAX_TYPES
    };
};

int main()
{
	// Creature o("orc", 'o', 4, 2, 10);
	// o.addGold(5);
	// o.reduceHealth(1);
	// std::cout << "The " << o.getName() << " has " << o.getHealth() << " health and is carrying " << o.getGold() << " gold.";
 
	// return 0;
	cout << "Enter your name: ";
	string playerName;
	cin >> playerName;
 
	Player p(playerName);
	cout << "Welcome, " << p.getName() << ".\n";
 
	cout << "You have " << p.getHealth() << " health and are carrying " << p.getGold() << " gold.";
 
	return 0;
}