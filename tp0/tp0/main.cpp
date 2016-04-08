/* 
 * File:   main.cpp
 * Author: sajkiewl
 *
 * Created on 2 novembre 2015, 15:09
 */

#include <cstdlib>
#include <iostream>
#include <vector>


using namespace std;

int factorielleIter(int n) {
    // {n ≥ 0} => {résultat = n! (soit 1 × 2 × … × n − 1 × n}
    int r = 1;
    int i = 1;
    while (i <= n) {
        r = r * i;
        i = i + 1;

    }
    return r;
}


int factorielleRec(int n) {
    // {n ≥ 0} => {résultat = �! (soit 1 × 2 × … × � − 1 × �}
    if (n == 0) {
        return 1;
    } else {
        return factorielleRec(n - 1) * n;
    }
}

bool estPair(int n) {
    // {n ≥ 0} => {résultat = true si n est pair ; false sinon}
    if (n == 0) {
        return true;
    } else if (n == 1) {
        return false;
    } else
        return estPair(n - 2);
}

bool estPairQcq(int n) {
    if (n == 0) {
        return true;
    } else if (n == 1) {
        return false;
    } else if (n >= 2) {
        return estPairQcq(n - 2);
    } else {
        return estPairQcq(n + 2);
    }// {} => {résultat = true si n est pair ; false sinon}
}
bool estImpairCroisee(int n);

bool estPairCroisee(int n) {
    // {n ≥ 0} => {résultat = true si n est pair ; false sinon}
    if (n == 0) {
        return true;
    } else if (n == 1) {
        return false;
    } else
        return estImpairCroisee(n - 1);
}

bool estImpairCroisee(int n) {
    // {n ≥ 0} => {résultat = true si n est impair ; false sinon}
    if (n == 1) {
        return true;
    } else if (n == 0) {
        return false;
    } else
        return estPairCroisee(n - 1);
}

bool estImpairQcqCroisee(int n);

bool estPairQcqCroisee(int n) {
    // {} => {résultat = true si n est pair ; false sinon}
    if (n == 0) {
        return true;
    } else if (n == 1) {
        return false;
    } else if (n >= 2) {
        return estImpairQcqCroisee(n - 1);
    } else {
        return estImpairQcqCroisee(n + 1);
    }
}

bool estImpairQcqCroisee(int n) {
    // {} => {résultat = true si n est pair ; false sinon}
    if (n == 1) {
        return true;
    } else if (n == 0) {
        return false;
    } else if (n >= 2) {
        return estPairQcqCroisee(n - 1);
    } else {
        return estPairQcqCroisee(n + 1);
    }
}

int f91(int n) {
    if (n > 100) {
        return n - 10;
    } else {
        return f91(f91(n + 11));
    }
}

template<class T>
int dichoIter(vector<T> v, T val) {
    int sup = v.size() - 1;
    if (v[sup] < val) {
        return -(v.size() + 1);
    } else {
        int m;
        int inf = 0;
        while (inf <= sup) {
            m = (inf + sup) / 2;
            if (v[m] < val) {
                inf = m + 1;
            } else {
                sup = m - 1;
            }
        }
        if (v[inf] == val) {
            return inf + 1;
        } else {
            return -(inf + 1);
        }
    }
}


template<class T>
int dichoRecWorker(vector<T> v, int inf, int sup, T val) {
    if (inf > sup) {
        if (v[inf] == val) {
            return inf + 1;
        } else {
            return -(inf + 1);
        }
    } else {
        int m = (inf + sup) / 2;
        if (v[m] < val) {
            return dichoRecWorker(v, m + 1, sup, val);
        } else {
            return dichoRecWorker(v, inf, m - 1, val);
        }
    }
}

template<class T>
int dichoRec(vector<T> v, T val) {
    if (v[v.size() - 1] < val) {
        return -(v.size() + 1);
    } else {
        return dichoRecWorker(v, 0, v.size() - 1, val);
    }
}

void hanoi(int nbDisques, char depart, char intermediaire, char arrivee) {
    // {n ≥ 1} => {affiche les déplacement à effectuer pour résoudre le pb}
    if ( nbDisques==1){
        cout << "Deplacement de " << depart << "vers " << arrivee<<endl;
    }else {
        hanoi(nbDisques -1, depart,arrivee,intermediaire);
        cout << "Deplacement de disque 1 de "<< depart <<"vers "<< arrivee << endl;
        hanoi(nbDisques-1,intermediaire,depart,arrivee);
    }
}
double PuissanceNbMult(float x, int n, int& nbMult) {
    if (n==0){
        return 1;
    }else if (n==1) {
        return x;
    }else if (estPair(n)) {
        nbMult = nbMult +1;
        return PuissanceNbMult(x,(n /2),nbMult) * PuissanceNbMult(x,(n/2),nbMult);
    }else {
        nbMult = nbMult +2;
        return x*PuissanceNbMult(x,(n /2),nbMult) * PuissanceNbMult(x,(n/2),nbMult);
    }
}

/*
 * 
 */
int main(int argc, char** argv) {
    cout << "donnez un nombre n" << endl;
    int n;
    cin >> n;
    vector<int> v{19, 22, 94, 103, 210};
    cout << "1 Recherche du nombre n avec dichoIter"<< endl;
    cout << "2 Recherche du nombre n avec dichoRecc"<< endl;
    cout << "3 factorielle de n par iteration avec factorielleIter" << endl;
    cout << "4 factorielle de n par recursivité avec factorielleRec"<< endl;
    cout << "5 test de la parité de n avec estpair(1=pair,0= non pair)" << endl;
    cout << "6 test de la parité de n avec estpairQcq(1=pair,0= non pair)" << endl;
    cout << "7 test de la parité de n avec estpaircroisee(1=pair,0= non pair) " << endl;
    cout << "8 test de la parité de n avec estimpaircroisee(1=pair,0= non pair) " << endl;
    cout << "9 test de la parité de n avec estpairQcqcroisee(1=pair,0= non pair) " <<endl;
    cout << "10 test de la parité de n avec estimpairQcqcroisee(0=pair,1= non pair)" << endl;
    cout << "11 test de f91 de n" <<endl;
    cout << "12 test de hanoi" <<endl;
    cout << "13 test de puissanceNBMult" << endl;
    cout << "choisir l'action que vous voulez executer" << endl;
    int action;
    cin >> action;
    switch (action) {
        case(1): cout << "Recherche du nombre n :" << dichoIter(v, n) << endl;
        break;
        case(2):cout << "Recherche du nombre n :" << dichoRec(v, n) << endl;
        break;
        case(3):cout << "factorielle de n par iteration :" << factorielleIter(n) << endl;
        break;
        case(4):cout << "factorielle de n par recursivité :" << factorielleRec(n) << endl;
        break;
        case(5): cout << "test de la parité de n avec estpair(1=pair,0= non pair) :" << estPair(n) << endl;
        break;
        case(6):cout << "test de la parité de n avec estpairQcq(1=pair,0= non pair) :" << estPairQcq(n) << endl;
        break;
        case(7):cout << "test de la parité de n avec estpaircroisee(1=pair,0= non pair) :" << estPairCroisee(n) << endl;
        break;
        case(8):cout << "test de la parité de n avec estimpaircroisee(1=pair,0= non pair) :" << estImpairCroisee(n) << endl;
        break;
        case(9):cout << "test de la parité de n avec estpairQcqcroisee(1=pair,0= non pair) :" << estPairQcqCroisee(n) << endl;
        break;
        case(10):cout << "test de la parité de n avec estimpairQcqcroisee(0=pair,1= non pair) :" << estImpairQcqCroisee(n) << endl;
        break;
        case(11):cout << "test de f91 de n avec f91 :" << f91(n) <<endl;
        break;
        case(12): cout<< "test de hanoi :" << endl;
        hanoi(3,'d','i','a');
        break;
        case(13) : cout<< "test de puissanceNBMult"<< endl;
        float x;
        int nbmult;
        PuissanceNbMult(x,n,nbmult);
    }    
    return 0;
}

