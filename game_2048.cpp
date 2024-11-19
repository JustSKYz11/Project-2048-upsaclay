#include<iostream>
#include<vector>
#include<iomanip>
#include<random>
#include<ctime>
#include<sstream>
using namespace std;
using Plateau = vector<vector<int>>;

/** génère aléatoirement un 2 ou un 4 avec des probabilités respectives de 9/10 et 1/10
 *  @return 2 ou 4
 **/

int tireDeuxOuQuatre(){
    srand(time(0));
    int a = 1 + rand() %10;
    if (a == 10) return 4;
    else return 2;
    
}

/** génère un plateau de dimensions 4*4 ne contenant que des 0
 *  @return un plateau vide
 **/

Plateau plateauVide(){
    Plateau tab(4); //declaration du plateau et allocation (taille 4)
    
    for (int i=0 ; i<tab.size() ; i++){
        tab[i] = vector<int>(4); //allocation des sous-tableaux
        
    }

    return tab;
    
}

/** fonction qui reinitialise un plateau a 0
  * @return un plateau 4x4 nul
**/

Plateau reinitialisePlateau(){
    return(vector<vector<int>>({{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}}));
}


/** génère deux nombres sur des cases aléatoires d'un plateau vide
 *  @return un plateau en début de jeu
 **/

Plateau plateauInitial(){
   
    Plateau game = plateauVide();
    
    srand(time(0));

    int m1,m2,n1,n2; // valeurs random qui vont designer une tuile au hasard pour lui allouer une valeur (2 ou 4)
    
    do{
        game = reinitialisePlateau();
        m1 = 0+rand()%3;
        n1 = 0+rand()%3;
        m2 = 0+rand()%3;
        n2 = 0+rand()%3;
        game[m1][n1] = tireDeuxOuQuatre(); // tirage aleatoire des tuiles auxquelles les valeurs 2 ou 4 seront donnees pas dans la meme case
        game[m2][n2] = tireDeuxOuQuatre(); // tirage aleatoire des tuiles auxquelles les valeurs 2 ou 4 seront donnees pas dans la meme case
        
    } while(m1 == m2 and n1 == n2);
    
    return game;
}

/** fonction qui affiche l'état de la partie
  * @param: un tableau d'entiers 4x4 qui represente la partie
**/

string plusGrandeCase(Plateau p){
    int plusGrand = 2; // la plus grande valeur de tuile dans la partie (minimum 2)
    for (auto ligne:p){
        for (auto tuile:ligne){
            if( tuile > plusGrand) plusGrand = tuile; // parcourt tous les elements du tableau pour trouver le plus grand
        }
    }
    
    return to_string(plusGrand); // fonction qui convertit le plus grand numero en chaine de caractere
}


/** affiche un plateau (NE MARCHE PAS POUR L'INSTANT)
 * @param p le plateau
 **/
string dessine(Plateau p){;

    ostringstream flux;

    string largest_number = plusGrandeCase(p); // la plus grande tuile dans le plateau
    
    int longueur_bordure = 4*(largest_number.size()+4) + 5;
                      
    for(int i=0; i<longueur_bordure ; i++) flux << "*";

    flux << endl;
                          
    for(auto ligne:p){
        for(auto tuile:ligne){
            if (tuile != 0){
                flux << "*" << setw(largest_number.size()+2)<< tuile << "  "; 
            }
            else{
                flux << "*" << setw(largest_number.size()+2); 
                for(int i=0 ; i< largest_number.size()+2 ; i++) flux << " "; // ici on a mis des espaces en considerant le nombre de caracteres de la plus                                                                                 grande tuile plus deux espaces (un a gauche et un a droite)
            }
        }
        
        flux << "*"<< endl;
    }

    for(int i=0; i<longueur_bordure ; i++) flux << "*";

    flux << endl;

    return flux.str();

}

int main(){
    Plateau partie = plateauInitial();
    cout << dessine(partie);

    return 0;
}














