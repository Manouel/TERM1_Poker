#ifndef Jeu_h
#define Jeu_h

#include <vector>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include "Carte.h"
#include "Joueur.h"
#include "IntelligenceArtificielle.h"

class Joueur;
class IntelligenceArtificielle;

namespace TYPES
{
    enum ACTION_LIST
    {
        MISER,
        RELANCER,
        SUIVRE,
        CHECKER,
        SE_COUCHER
    };
};


class Jeu{

	//Liste des attributs
	private :
		std::vector<Joueur> 			positionnement;
		std::vector<Carte>    			deck;
		std::vector<Carte> 			table;
		std::vector<TYPES::ACTION_LIST>		actions;
		int 					blind;
		int 					joueurCourant;
		int 					pot;
		int 					nombreDeCoup;
		int 					mise;
		
	//Constructeur et destructeur
	public:
		Jeu(int nbJoueur, int blindDepart, int cave, int typeIA);
		~Jeu();
		
	//Accesseur
		int 		getBlind() const;
		int 		getJoueurCourant() const;
		Joueur 		getJoueur(int i) const;
		void 		setJoueur(Joueur joueur);
		int		getPot() const;
		void		setPot(int jetons);
	
	//Methodes	
	//private:
		void distributionMain();
		void distributionFlop();
		void distributionTurn();
		void distributionRiver();
		void miseAJourBlind();
		void melange();
		void initialisationTable(int nbJoueur, int cave);
		std::vector<Carte> nouveauDeck();
		
		void miser(Joueur joueur, int jetons);
		void relancer(Joueur joueur, int jetons);
		void suivre(Joueur joueur);
		void checker(Joueur joueur);
		void seCoucher(Joueur joueur);
		
	
		
			
};

#endif
