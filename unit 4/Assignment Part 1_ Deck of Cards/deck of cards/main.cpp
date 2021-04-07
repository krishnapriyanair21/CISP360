#include <iostream>
using namespace std;
#include <string>



// TODO (1): #include directives and namespace statement here

int main() {
    const string LINE = "--------------------";

    // TODO (2): declare variables here
    string match;
    string suitName, rankName;

    // TODO (3): prompt user for matchword; read in the value
    cout << "Enter match word ('.' for match all): ";
    cin >> match;
    // TODO (4): consider declaring and initializing additional variables

    // TODO (5): start output with a line
    cout <<"--------------------" <<endl;

    // TODO (6): outer loop ..... ///[0...3] 0 => suitName = "Clubs", 1=> suitName = "Hearts", ...
if (match == "ace" || match == "Ace" || match == "Two" || match == "two" || match == "three" || match ==  "Three"){
        cout << match << " of Clubs" <<endl;
        cout << match << " of Hearts" <<endl;
        cout << match << " of Spades" <<endl;
        cout << match << " of Diamonds" <<endl;
}
else if (match == "four" || match == "Four" || match == "five" || match == "Five" || match == "six" || match ==  "Six"){
        cout << match << " of Clubs" <<endl;
        cout << match << " of Hearts" <<endl;
        cout << match << " of Spades" <<endl;
        cout << match << " of Diamonds" <<endl;
}
else if (match == "seven" || match == "Seven" || match == "eight" || match == "Eight" || match == "nine" || match ==  "Nine"){
        cout << match << " of Clubs" <<endl;
        cout << match << " of Hearts" <<endl;
        cout << match << " of Spades" <<endl;
        cout << match << " of Diamonds" <<endl;
}
else if (match == "ten" || match == "Ten" || match == "Jack" || match == "jack" || match == "queen" || match ==  "Queen"){
        cout << match << " of Clubs" <<endl;
        cout << match << " of Hearts" <<endl;
        cout << match << " of Spades" <<endl;
        cout << match << " of Diamonds" <<endl;
}
else if (match == "king" || match == "King"){
        cout << match << " of Clubs" <<endl;
        cout << match << " of Hearts" <<endl;
        cout << match << " of Spades" <<endl;
        cout << match << " of Diamonds" <<endl;
}
else if (match == "Spades") {
    cout << "Ace of Spades" <<endl;
    cout << "Two of Spades" <<endl;
    cout << "Three of Spades" <<endl;
    cout << "Four of Spades" <<endl;
    cout << "Five of Spades" <<endl;
    cout << "Six of Spades" <<endl;
    cout << "Seven of Spades" <<endl;
    cout << "Eight of Spades" <<endl;
    cout << "Nine of Spades" <<endl;
    cout << "Ten of Spades" <<endl;
    cout << "Jack of Spades" <<endl;
    cout << "Queen of Spades" <<endl;
    cout << "King of Spades" <<endl;

}
else if (match == "Hearts") {
    cout << "Ace of Hearts" <<endl;
    cout << "Two of Hearts" <<endl;
    cout << "Three of Hearts" <<endl;
    cout << "Four of Hearts" <<endl;
    cout << "Five of Hearts" <<endl;
    cout << "Six of Hearts" <<endl;
    cout << "Seven of Hearts" <<endl;
    cout << "Eight of Hearts" <<endl;
    cout << "Nine of Hearts" <<endl;
    cout << "Ten of Hearts" <<endl;
    cout << "Jack of Hearts" <<endl;
    cout << "Queen of Hearts" <<endl;
    cout << "King of Hearts" <<endl;
}
else if (match == "Clubs") {
    cout << "Ace of Clubs" <<endl;
    cout << "Two of Clubs" <<endl;
    cout << "Three of Clubs" <<endl;
    cout << "Four of Clubs" <<endl;
    cout << "Five of Clubs" <<endl;
    cout << "Six of Clubs" <<endl;
    cout << "Seven of Clubs" <<endl;
    cout << "Eight of Clubs" <<endl;
    cout << "Nine of Clubs" <<endl;
    cout << "Ten of Clubs" <<endl;
    cout << "Jack of Clubs" <<endl;
    cout << "Queen of Clubs" <<endl;
    cout << "King of Clubs" <<endl;
}
else if (match == "Diamonds") {
    cout << "Ace of Diamonds" <<endl;
    cout << "Two of Diamonds" <<endl;
    cout << "Three of Diamonds" <<endl;
    cout << "Four of Diamonds" <<endl;
    cout << "Five of Diamonds" <<endl;
    cout << "Six of Diamonds" <<endl;
    cout << "Seven of Diamonds" <<endl;
    cout << "Eight of Diamonds" <<endl;
    cout << "Nine of Diamonds" <<endl;
    cout << "Ten of Diamonds" <<endl;
    cout << "Jack of Diamonds" <<endl;
    cout << "Queen of Diamonds" <<endl;
    cout << "King of Diamonds" <<endl;
}
else if (match == ".") {
    cout << "Ace of Clubs" <<endl;
    cout << "Two of Clubs" <<endl;
    cout << "Three of Clubs" <<endl;
    cout << "Four of Clubs" <<endl;
    cout << "Five of Clubs" <<endl;
    cout << "Six of Clubs" <<endl;
    cout << "Seven of Clubs" <<endl;
    cout << "Eight of Clubs" <<endl;
    cout << "Nine of Clubs" <<endl;
    cout << "Ten of Clubs" <<endl;
    cout << "Jack of Clubs" <<endl;
    cout << "Queen of Clubs" <<endl;
    cout << "King of Clubs" <<endl;
     cout << "Ace of Hearts" <<endl;
    cout << "Two of Hearts" <<endl;
    cout << "Three of Hearts" <<endl;
    cout << "Four of Hearts" <<endl;
    cout << "Five of Hearts" <<endl;
    cout << "Six of Hearts" <<endl;
    cout << "Seven of Hearts" <<endl;
    cout << "Eight of Hearts" <<endl;
    cout << "Nine of Hearts" <<endl;
    cout << "Ten of Hearts" <<endl;
    cout << "Jack of Hearts" <<endl;
    cout << "Queen of Hearts" <<endl;
    cout << "King of Hearts" <<endl;
    cout << "Ace of Spades" <<endl;
    cout << "Two of Spades" <<endl;
    cout << "Three of Spades" <<endl;
    cout << "Four of Spades" <<endl;
    cout << "Five of Spades" <<endl;
    cout << "Six of Spades" <<endl;
    cout << "Seven of Spades" <<endl;
    cout << "Eight of Spades" <<endl;
    cout << "Nine of Spades" <<endl;
    cout << "Ten of Spades" <<endl;
    cout << "Jack of Spades" <<endl;
    cout << "Queen of Spades" <<endl;
    cout << "King of Spades" <<endl;
     cout << "Ace of Diamonds" <<endl;
    cout << "Two of Diamonds" <<endl;
    cout << "Three of Diamonds" <<endl;
    cout << "Four of Diamonds" <<endl;
    cout << "Five of Diamonds" <<endl;
    cout << "Six of Diamonds" <<endl;
    cout << "Seven of Diamonds" <<endl;
    cout << "Eight of Diamonds" <<endl;
    cout << "Nine of Diamonds" <<endl;
    cout << "Ten of Diamonds" <<endl;
    cout << "Jack of Diamonds" <<endl;
    cout << "Queen of Diamonds" <<endl;
    cout << "King of Diamonds" <<endl;
}
        // TODO (7): inner loop .....   ///[1...13]  1 => rankName = "Ace", 2 => rankName = "Two", ...

            // TODO (8): should we print the card name?  (Does the match word equal the suit name OR the rank name?)

        // }
    // }

    // TODO: (9) output (no matches) if nothing matched
else {
    cout <<" (no matches)" <<endl;
}
    // TODO: (10) finish output with a line
    cout <<"--------------------" <<endl;

    return 0;
}

