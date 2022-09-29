#include <iostream>
#include "string"
using namespace std;

void afficher(bool tabPlayerA[], bool tabPlayerB[]){

    cout << "_______" << endl;
    for(int i = 0; i < 9; ++i){
        if(i == 0 or i == 3 or i == 6){
            cout << "|";
        }
        if(tabPlayerA[i]){
            cout << "X" << "|";
        }else if(tabPlayerB[i]){
            cout << "O" << "|";
        }
        else {
            cout << (i+1) << "|";
        }
        if((i+1)%3 == 0){
            cout << endl;
            cout << "-------" << endl;
        }
    }

}

bool winGame(bool tab[]){
    for(int i = 0 ; i < 3 ; i++){ // boucle de 1 à 3
        if(tab[i*3] and tab[i*3+1] and tab[i*3+2]){ //win ligne
            return true;
        }
        if(tab[i] and tab[i+3] and tab[i+6]){ // win coll
            return true;
        }
    }
    if(tab[0] and tab[4] and tab[8] or tab[2] and tab[4] and tab[6]){ // win diago
        return true;
    }
    return false;

};

bool checkAnswer(string answerToCheck, bool tabPlayerA[9], bool tabPlayerB[9]){
    try {
        int answerCase = stoi(answerToCheck);
        for (int i = 1; i < 10; ++i) {
            if(answerCase == i){
                if(!tabPlayerA[i-1] and !tabPlayerB[i-1]){ // si la place est vide
                    return true;
                    }
            }
        }
    } catch (const std::exception& e) {
        return false;
        }


    return false;
}

int main() {

    bool tabPlayerA[9] = {0,0, 0,
                   0,0,0,
                   0, 0, 0 };
    bool tabPlayerB[9] = {0,0, 0,
                   0,0,0,
                   0, 0, 0 };

    afficher(tabPlayerA, tabPlayerB);
    string answerPlayer;
    for(int i = 1; i < 10; i++){

        if(i % 2 == 0){
            cout << "Joueur B : " << endl;
            cin >> answerPlayer;
            while(checkAnswer(answerPlayer, tabPlayerA, tabPlayerB) == false){ // Si la reponse donnee est fausse recomance
                cout << "CASE IMPOSSIBLE" << endl;
                cin >> answerPlayer;
            }
            tabPlayerB[stoi(answerPlayer)-1] = true;
            if( winGame(tabPlayerB)){
                afficher(tabPlayerA, tabPlayerB);
                cout << "Joueur B WIN" << endl;
                return 0;
            };
            }else{
            cout << "Joueur A : " << endl;
            cin >> answerPlayer;
            while(checkAnswer(answerPlayer, tabPlayerA, tabPlayerB) == false){ // Si la reponse donnee est fausse recomance
                cout << "CASE IMPOSSIBLE" << endl;
                cin >> answerPlayer;
            }
            tabPlayerA[stoi(answerPlayer)-1] = true;
            if( winGame(tabPlayerA)){
                afficher(tabPlayerA, tabPlayerB);
                cout << "Joueur A WIN" << endl;
                return 0;
            }
        }
        afficher(tabPlayerA, tabPlayerB);
    }
    return 0;
}
