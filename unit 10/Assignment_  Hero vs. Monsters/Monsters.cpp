// -----------------------------------------------------------------------
// monsters.cpp
// -----------------------------------------------------------------------
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
};

struct Monster
{
   ///TODO(1): declare name, stats, and weapon
} ;

///TODO (2):  declare Hero struct

//output agility, toughness, and hitpoints, NO newline
void displayStats(const Stats& s);

//output Weapon name and damageModifier, NO newline
void displayWeapon(const Weapon& w);

//output name, stats, and weapon
void displayMonster(const Monster& m);

//output name, stats, and weapon
void displayHero(const Hero& h);

//roll a d6 numDice times (nd6)
int d6Roll(int numDice);

//Hero attacks a Monster
void attackMonster(const Hero& h, Monster& m);

//Monster attacks the Hero
void attackHero(Hero& h, const Monster& m);

//Display each monster in the vector
void displayMonsters(const vector<Monster>& lair);

//Each Monster whose hitpoints > 0 attacks the Hero
//If the hero's hitpoints drop below zero, break
void monstersTurn(Hero& h, const vector<Monster>& lair);

//The Hero attacks each Monster whose hitpoints > 0
void heroTurn(const Hero& h, vector<Monster>& lair);

//returns true if there is no Monster whose hitpoints > 0
bool lairCleared(vector<Monster>& lair);

//begin an epic battle!  displayHero, displayMonsters
//loop as long as the hero is alive and the lair is not clear
void enterLair(Hero& h, vector<Monster>& lair);
//*******

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
///TODO (4):   displayWeapon.  If damageModifier >= 0 prepend a "+". NO newline at the end.
///TODO (5):   displayMonster
///TODO (6):   displayHero
///TODO (7):   d6Roll.  Don't forget to add each roll if numDice is greater than 1.
///TODO (8):   attackMonster.  See rules above.  
///            You will have to use multiple dots here to access members within members.
///            eg h.weapon.name, m.stats.agility, etc

///TODO (9):   attackHero.  Same rules.
///TODO (10):  displayMonsters.  Loop through the vector and call displayMonster for each Monster
///TODO (11):  monstersTurn.  Loop through the vector and call displayMonster and then attackHero for each Monster if their hitpoints > 0.  If the hero's hitpoints drop below zero, break
///TODO (12):  heroTurn.  Loop through the vector and call attackMonster for each Monster whose hitpoints > 0
///TODO (13):  lairCleared.  Loop through the vector.  If there is a monster whose hitpoints > 0, return false.
///            if the loop completes then return true

void enterLair(Hero& h, vector<Monster>& lair)
{
   ///TODO (14):  Call functions to display Hero and Monsters

    cout << "The battle begins..." << endl;

   ///TODO (15):  Loop while the hero is alive and the lair is not cleared
        ///call heroTurn
        ///if the lair is not cleared, call monstersTurn
}
