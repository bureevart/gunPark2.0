#include <iostream>
using namespace std;

class Weapon
{
public:
    
    int damage;
    Weapon() 
    {
        damage = 1;
    }
    virtual void shoot() = 0;
};
class Knife : public Weapon
{
public:
    Knife()
    {
        damage = 100;
    }
    void shoot()
    {
        cout << "Тыкаю" << endl;
    }
};
class  Gun : public Weapon
{
public:
    Gun()
    {
        damage = 30;
    }
    void shoot()
    {
        cout << "Стреляю!" << endl;
    }
};
class AutoGun : public  Gun
{
public:
    AutoGun()
    {
        damage = 40;
    }
    void shoot()
    {
        cout << "Стреляю! стреляю! стреляю!" << endl;
    }
};
class Bazuka : public AutoGun
{
public:
    Bazuka()
    {
        damage = 80;
    }
    void shoot()//также переопределяем, ключевое слово писать необязательно
    {
        cout << "BOOOOO" << endl;
    }
};

class Player
{
public:
    int hp = 100;
    void shoot(Weapon* weapon, Player* player)//передаем ссылку на объект
    {
        weapon->shoot();
        (*player).hp -= weapon->damage;

        if ((*player).hp < 0) {
            (*player).hp = 0;
        }
    }

    void showState() {
        cout <<"Осталось хп: " << hp << endl;
    }

};

enum WeaponTypes{
    knife = 1,
    gun,
    autoGun,
    bazuka
};
int main()
{
    setlocale(LC_ALL, "RUS");

    Player p1 = Player();
    Player p2 = Player();
    Weapon* weapon;

    Knife k;
    Gun g;
    AutoGun ag;
    Bazuka b;

    int gunType;


    while (true) {
        cout << "Введите номер оружия (порядок в енаме, выводить не хочу): ";
        cin >> gunType;

        switch (gunType) {
        case knife:
            weapon = &k;
            break;
        case gun:
            weapon = &g;
            break;
        case autoGun:
            weapon = &ag;
            break;
        case bazuka:
            weapon = &b;
            break;
        default:
            cout << "Пока! ";
            return 0;
        }

        p1.shoot(weapon, &p2);
        p2.showState();
    }

    return 0;
}

