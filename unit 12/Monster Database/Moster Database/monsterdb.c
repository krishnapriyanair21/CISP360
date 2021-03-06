// -----------------------------------------------------------------------
// monsterdb.c
// -----------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// -----------------------------------------------------------------------
// Some defines
#define NAME_MAX 64
#define BUFFER_MAX 256

// User instructions
const char *info[] = {
  "Enter a command:",
  "",
  "  ?  - print this list of commands",
  "  r  - read monster database (binary file)",
  "  w  - write monster database (binary file)",
  "  d  - display monsters",
  "  n  - sort monsters by name (ascending)",
  "  h  - sort monsters by hitpoints (descending)",
  "  q  - quit",
};
const int N_INFO = 9;


// -----------------------------------------------------------------------
// Structs

typedef struct Weapon_struct {
    char name[NAME_MAX];
    int damageModifier;
} Weapon;

typedef struct Stats_struct {
    int agility;
    int toughness;
    int hitpoints;
} Stats;

typedef struct Monster_struct {
    char name[NAME_MAX];
    Stats stats;
    Weapon weapon;
} Monster;

typedef struct MonsterList_struct {
    int size;
    Monster *list;
} MonsterList;


// -----------------------------------------------------------------------
// Function prototypes

void printInfo();
void displayMonster(Monster *m);
void displayMonsters(MonsterList *monsters);
int swapNeededName(Monster *a, Monster *b);
int swapNeededHitPoints(Monster *a, Monster *b);
void sortMonsters(MonsterList *monsters, char sortType);
void readDb(MonsterList *monsters, char *fileName);
void writeDb(MonsterList *monsters, char *fileName);

// -----------------------------------------------------------------------
// Main Program

int main() {
    MonsterList monsters = {0, NULL};
    char fileName[BUFFER_MAX];
    char userIn[BUFFER_MAX];
    char cmd;

    printInfo();

    int done = 0;
    while (done == 0) {
        printf("\n> ");
        scanf("%s", userIn);
        cmd = userIn[0];

        switch (cmd) {
            case('?'):
                printInfo();
                break;

            case('r'):
                printf("DB file name (to read): ");
                scanf("%s", fileName);
                readDb(&monsters, fileName);
                break;

            case('w'):
                if(monsters.size == 0 || monsters.list == NULL){
                    printf("(no monsters loaded)");
                    break;
                }
                else {
                    printf("DB file name (to write): ");
                    writeDb(&monsters, fileName);
                    break;
                }

            case('d'):
                if(monsters.size == 0 && monsters.list == NULL){
                    printf("(no monsters loaded)");
                    break;
                }
                else{
                    displayMonsters(&monsters);
                    break;
                }

            case('n'):
                if(monsters.size == 0 && monsters.list == NULL){
                    printf("(no monsters loaded)");
                    break;
                }
                else {
                    sortMonsters(&monsters, cmd);
                    displayMonsters(&monsters);
                    break;
                }

            case('h'):
                if(monsters.size == 0 && monsters.list == NULL){
                    printf("(no monsters loaded)");
                    break;
                }
                else{
                    sortMonsters(&monsters, cmd);
                    displayMonsters(&monsters);
                    break;
                }

            case('q'):
                 done = 1;
                 break;
            default:
                printf("Unknown command `%c`", cmd);
                break;
                }
        }
    return 0;
}

// -----------------------------------------------------------------------
// Function implementations

// TODO (8): void printInfo();
void printInfo() {
    int i =0;
    printf("\n");
    while (info[i]!= NULL){
        printf("%s\n", info[i]);
        i++;
    }
    return;
}
// TODO (9): void displayMonster(Monster *m);
void displayMonster(Monster *m){
    printf("%10s [a:%d, t:%d, hp:%2d] <%-15s mod:%2d>\n", m->name, m->stats.agility, m->stats.toughness, m->stats.hitpoints,
           m->weapon.name, m->weapon.damageModifier);
}
// TODO (10): void displayMonsters(MonsterList *monsters);
void displayMonsters(MonsterList *monsters){
    for (int i =0; i < monsters->size; i++){
        displayMonster(&(monsters->list[i]));
    }
}
// TODO (11): int swapNeededName(Monster *a, Monster *b);
int swapNeededName(Monster *a, Monster *b){
    int x= strcmp(a->name, b->name);
    if (x < 0) {
        return 0;
    }
    else if (x > 0){
        return 1;
    }
    else if (x == '\0'){
        return 0;
    }
    else {
        return -1;
    }
}
// TODO (12): int swapNeededHitPoints(Monster *a, Monster *b);
int swapNeededHitPoints(Monster *a, Monster *b){
    int x = a->stats.hitpoints;
    int y = b->stats.hitpoints;
    if (x < y){
        return 1;
    }
    else {
        return 0;
    }
}
// TODO (13): void sortMonsters(MonsterList *monsters, char sortType);
void sortMonsters(MonsterList *monsters, char sortType){
    int i, j;
    Monster temp;
    for (i = 1; i < (monsters->size); ++i) {
        j = i;
        if (sortType=='n'){
            while (j > 0 && (swapNeededName(&monsters->list[j], &monsters->list[j - 1])==0)){
                temp = monsters->list[j];
                monsters->list[j] = monsters->list[j-1];
                monsters->list[j-1] = temp;
                --j;
            }
        }
        else if (sortType=='h') {
            while (j > 0 && swapNeededHitPoints(&monsters->list[j - 1], &monsters->list[j]) == 1) {
                temp = monsters->list[j];
                monsters->list[j] = monsters->list[j-1];
                monsters->list[j-1] = temp;
                --j;
            }
        }
    }
    return;
}
// TODO (14): void readDb(MonsterList *monsters, char *fileName);
void readDb(MonsterList *monsters, char *fileName){
    FILE* inFile = fopen(fileName, "rb");

    if (inFile == NULL) {
        printf("Failed to open '%s' for read\n", fileName);
        return;
    }
    fread(&monsters->size, sizeof(int), 1 , inFile);
    printf("1 items read from '%s' (size header)\n", fileName);
    printf("Allocating heap for %d Monsters...", monsters->size);

    free(monsters->list);
    monsters->list = (Monster*)malloc(sizeof(Monster) * monsters ->size);
    int i;
    for(i = 0; i < monsters->size; i++){
        fread(&(monsters->list[i]) , sizeof(Monster), monsters->size, inFile);
    }
    if (monsters->list != 0) {
        printf("memory allocated\n");
    }
    else {
        printf("failed to allocate memory!\n");
    }
    printf("%d items read from '%s' (monster array)\n", monsters->size, fileName);
    free(monsters->list);
    fclose(inFile);
    return;
}
// TODO (15): void writeDb(MonsterList *monsters, char *fileName);
void writeDb(MonsterList *monsters, char *fileName){
    FILE* outFile=fopen(fileName,"wb");
    if(outFile==NULL){
        printf("Failed to open '%s' for write",fileName);
        return;
    }
    fwrite(&(monsters->size), sizeof(int), 1, outFile);
    printf("1 item written to '%s'(size header)\n",fileName);
    int i;
    for (i = 0; i< (monsters->size); i++) {
        fwrite(&monsters->list[i], sizeof(Monster), 1, outFile);
    }
    printf("%d items writen to '%s' (monster array)\n", i, fileName);
    fclose(outFile);
    return;
}

// -----------------------------------------------------------------------
