#include <iostream>
#include <string>
using namespace std;

class Monster
{
public:
    enum MonsterType
    {
        Dragon,
        Goblin,
        Ogrem,
        Orc,
        Skeleton,
        Troll,
        Vampire,
        Zombie,
        MAX_MONSTER
    };
private:
    MonsterType m_type;
    string m_name;
    int m_health;
public:
    Monster(MonsterType type, string name, int health): m_type(type), m_name(name), m_health(health) {}

    string getTypeString()
    {
        switch(m_type)
        {
            case Dragon: return "Dragon";
            case Goblin: return "Goblin"; 
            case Ogrem: return "Ogrem"; 
            case Orc: return "Orc"; 
            case Skeleton: return "Skeleton";
            case Troll: return "Troll";
            case Vampire: return "Vampire";
            case Zombie: return "Zombie";
        }
        return "Error";
    }
    void print()
    {
        cout << m_name << "is the " << getTypeString() << " that has " << m_health << " health points" << endl;
    }

};

class MonsterGenerator
{
public:
    static int getRandomNumber(int min, int max)
	{
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); // используем static, так как это значение нужно вычислить единожды
		// Равномерно распределяем вычисление значения из нашего диапазона
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}
    static Monster generateMonster()
    {
        Monster::MonsterType type = static_cast<Monster::MonsterType>(getRandomNumber(0, Monster::MAX_MONSTER));
        int health = getRandomNumber(0, 100);
        static string s_name[6] = {"John", "Brad", "Alex", "Thor", "Hulk", "Asnee"};
        return Monster(type, s_name[getRandomNumber(0, 5)], health);
    }
};

int main()
{
    srand(static_cast<unsigned int>(time(0))); // используем системные часы в качестве стартового значения
	rand(); // пользователям Visual Studio: делаем сброс первого случайного числа
    // // Monster jack(Monster::Orc, "Jack", 90);
    // // jack.print();
 
	Monster m = MonsterGenerator::generateMonster();
	m.print();
    return 0;
}