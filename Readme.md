



Pseudo code pour deux joueurs:

tant que n =! 9

si (i == pair)
    Joueur B joue
        entre chiffre entre 1 et 9
                checkAnswer, si false => recommence entre
                    fonction affiche
                        fonction wingame

sinon (i == impaire)
    Joueur A joue
        entre chiffre entre 1 et 9
            fonction checkAnswer, si false => recommence entre
                fonction affiche
                    fonction wingame


tant que n =! 3
    si chaque ligne = vrai 
        retourne vrai
    si chaque colonne = vrai 
        retourne vrai
    fonction affiche

checkAnswer 
fonction qui retourne une erreur
si l'entree n'est pas une valeur entre 1 et 9
ou que la case est déjà cochée

affiche
affiche les cases actuelles de la grille de jeu

wingame 
retourne true si un des joueurs a gagne