#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <iomanip>
using namespace std;

const int LINE_WIDTH = 50;

struct Weapon
{
    string name;
    int damageModifier;
};

struct Stats
{
   ///TODO (0): declare agility, toughness, hitpoints
   ///done
    int agility;
    int toughness;
    int hitpoints;
};

struct Monster
{
   ///TODO(1): declare name, stats, and weapon
   ///done
    string name;
    Stats stats;
    Weapon weapon;
} ;

///TODO (2):  declare Hero struct
///done
struct Hero
{
    string name;
    Stats stats;
    Weapon weapon;
};
void displayStats(const Stats& s);
void displayWeapon(const Weapon& w);
void displayMonster(const Monster& m);
void displayHero(const Hero& h);
int d6Roll(int numDice);
void attackMonster(const Hero& h, Monster& m);
void attackHero(Hero& h, const Monster& m);
void displayMonsters(const vector<Monster>& lair);
void monstersTurn(Hero& h, const vector<Monster>& lair);
void heroTurn(const Hero& h, vector<Monster>& lair);
bool lairCleared(vector<Monster>& lair);
void enterLair(Hero& h, vector<Monster>& lair);

int main()
{
    srand(1337);  //don't change me!

    Weapon teeth = {"teeth/claws", -6};
    Weapon axe = {"sharp axe", +1};
    Weapon dagger = {"steel dagger", +2};

    vector<Monster> lair;
    lair.push_back({"Rat", Stats{3, 4, 2}, teeth});
    lair.push_back({"Goblin", Stats{2, 7, 9}, axe});

    Hero hero = {"Darwin", Stats{5, 9, 20}, dagger};

    enterLair(hero, lair);

    if(lairCleared(lair)) cout << "You win!" << endl;
    else cout << "Game over" << endl;

    return 0;
}


///TODO (3):   displayStats, NO newline
///done
void displayStats(const Stats& s){
    cout << "[a:" << s.agility <<", t:" <<s.toughness << ", hp:" <<s.hitpoints << "]";
}
///TODO (4):   displayWeapon.  If damageModifier >= 0 prepend a "+". NO newline at the end.
///done
void displayWeapon(const Weapon& w){
    cout << "<" << w.name << ", ";
    if (w.damageModifier >= 0) {
        cout << "+";
    }
    cout << w.damageModifier << ">";

}
///TODO (5):   displayMonster
///done
void displayMonster(const Monster& m) {
if (m.stats.hitpoints > 0) {
    cout << "--------"<< endl;
    cout << m.name << ' ';
    displayStats(m.stats);
    cout <<' ';
    displayWeapon(m.weapon);
    cout << endl;
    cout << "--------"<< endl;
    }
}
///TODO (6):   displayHero
///done
void displayHero(const Hero& h){
    cout <<"--------" <<endl;
    cout <<"Our Hero..." <<endl;
    cout <<h.name << " ";
    displayStats(h.stats);
    cout << " ";
    displayWeapon(h.weapon);
    cout <<endl;
    cout <<"--------" <<endl;

}
///TODO (7):   d6Roll.  Don't forget to add each roll if numDice is greater than 1.
///done
int d6Roll(int numDice){
    int i, dice = 0;
    for (i = 0; i < numDice; ++i){
        dice += (rand() % 6) + 1;
    }
    return dice;
}

///TODO (8):   attackMonster.  See rules above.
///            You will have to use multiple dots here to access members within members.
///            eg h.weapon.name, m.stats.agility, etc
void attackMonster(const Hero& h, Monster& m){
    int oneDie = 1;
    int twoDie = 2;
    int resultRoll =0;

    cout << h.name << " attacks " << m.name << " with " << h.weapon.name << "..." <<endl;
    resultRoll = d6Roll(oneDie);
    cout << "Hit? " << resultRoll<<" vs. "<<m.stats.agility<<" : ";

    if(resultRoll >= m.stats.agility ){
        cout<< "yes" <<endl;
        cout << h.name << " hits " << m.name<<"..." <<endl;
        resultRoll = d6Roll(twoDie);
        cout<<"Inflict? "<< resultRoll<<"vs."<<m.stats.toughness<<" : ";

            if(resultRoll > m.stats.toughness){
                cout<<"yes"<<endl;
                cout<<h.name<<"inflicts "<< resultRoll + h.weapon.damageModifier<<" points of damage..." <<endl;
                m.stats.hitpoints -= resultRoll + h.weapon.damageModifier;
                if (m.stats.hitpoints < 0){
                    cout << m.name << " is slain!" <<endl;
                }
                return;
            }
         cout<<"no"<<endl;
         cout<<m.name<< "'s toughness prevents damage." <<endl;
         return;
    }
    else{
        cout<<"no"<<endl;
        cout<<h.name<<" misses."<<endl;
        return;
    }

}
///TODO (9):   attackHero.  Same rules.
void attackHero(Hero& h, const Monster& m){
    int oneDie = 1;
    int twoDie = 2;
    int resultRoll =0;

    cout << m.name << " attacks " << h.name << " with " << m.weapon.name << "...";
    resultRoll = d6Roll(oneDie);
    cout << "Hit? " << resultRoll<<" vs. "<<h.stats.agility<<" : ";

    if(resultRoll >= h.stats.agility ){
        cout<< "yes" <<endl;
        cout << m.name << " hits " << h.name<<"..."<<endl;
        resultRoll = d6Roll(twoDie);
        cout<<"Inflict? "<< resultRoll<<"vs."<<h.stats.toughness<<" : ";

            if(resultRoll > h.stats.toughness){
                cout<<"yes"<<endl;
                cout<<m.name<<"inflicts "<< resultRoll + m.weapon.damageModifier<<" points of damage..."<<endl;
                h.stats.hitpoints -= resultRoll + m.weapon.damageModifier;
                if (m.stats.hitpoints < 0){
                    cout << m.name << " is slain!" <<endl;
                }
                return;
            }
         cout<<"no"<<endl;
         cout<<h.name<< "'s toughness prevents damage." <<endl;
         return;
    }
    else{
        cout<<"no"<<endl;
        cout<<m.name<<" misses."<<endl;
        return;
    }
}
///TODO (10):  displayMonsters.  Loop through the vector and call displayMonster for each Monster
///not working
void displayMonsters(const vector<Monster>& lair){
    cout << "Monster lair..." <<endl;
    for (size_t i = 0; i < lair.size(); i++){
        displayMonster(lair.at(i));
    }
}
///TODO (11):  monstersTurn.  Loop through the vector and call displayMonster and then attackHero for each Monster if their hitpoints > 0.  If the hero's hitpoints drop below zero, break
///done
void monstersTurn(Hero& h, const vector<Monster>& lair){
    for(size_t i=0; i<lair.size()&& h.stats.hitpoints>0; i++){
        displayMonster(lair.at(i));
        if(lair.at(i).stats.hitpoints>0){
            attackHero(h, lair.at(i));
        }
    }
}
///TODO (12):  heroTurn.  Loop through the vector and call attackMonster for each Monster whose hitpoints > 0
void heroTurn(const Hero& h, vector<Monster>& lair){
    for (size_t i = 0; i< lair.size(); i++){
        if (lair.at(i).stats.hitpoints > 0){
            attackMonster(h, lair.at(i));
        }
    }
}
///TODO (13):  lairCleared.  Loop through the vector.  If there is a monster whose hitpoints > 0, return false.
///            if the loop completes then return true
        ///done
bool lairCleared(vector<Monster>& lair){
    for(size_t i=0; i<lair.size(); i++) {
        if(lair.at(i).stats.hitpoints>0) {
            return false;
        }
    }
    return true;
}

void enterLair(Hero& h, vector<Monster>& lair)
{
   ///TODO (14):  Call functions to display Hero and Monsters
    ///done
    displayHero(h);
    displayMonsters(lair);
    cout << "The battle begins..." << endl;

   ///TODO (15):  Loop while the hero is alive and the lair is not cleared
        ///call heroTurn
        ///if the lair is not cleared, call monstersTurn
        ///done
    while (h.stats.hitpoints > 0 && !lairCleared(lair) > 0){
        displayHero(h);
        heroTurn(h,lair);
        if (!lairCleared(lair)){
            monstersTurn(h, lair);
        }
    }
}
