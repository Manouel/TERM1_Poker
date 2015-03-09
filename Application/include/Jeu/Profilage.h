/*========================================================================
Nom: Profilage.h       Auteur: Manuel CHATAIGNER
Maj: 04/03/2015          Creation: 04/03/2015
Projet: Profilage par essais et erreurs au poker
--------------------------------------------------------------------------
Specification: Classe contenant l'écriture et la lecture
               des données de profilage.
=========================================================================*/


#ifndef PROFILAGE_H
#define PROFILAGE_H

#include <string>
#include <QString>

class Profilage
{
    public:

        // Etapes de jeu
        enum { PREFLOP, FLOP, TURN, RIVER, NB_ETAPES };

        static const QString etapes[4];

    private:

        std::string nomJoueur;

        struct Profil
        {
            bool couche;                    // vrai si le joueur s'est couché

            double probaGainAdversaire;     // % de chance de gagner du joueur (-1 si cartes inconnues)
            double pot;                     // % du pot par rapport à la cave du joueur

            /* Type du joueur (somme des taux = 100%) */
            double tauxAgressivite;         // Agressivité du joueur (mise la plus haute, mise totale, nb checks)
            double tauxRationnalite;        // Rationnalite du joueur (mise totale, s'est couché ?)
            double tauxBluff;               // Bluff du joueur (mise totale, s'est couché ?)
            double tauxPassivite;           // Passivite du joueur (suivis, checks)

            /* Taux en % des différentes actions effectuées par le joueur (les relances sont incluses dans les mises) */
            double tauxSuivis;
            double tauxChecks;
            double tauxMises;

            int misePlusHaute;
            int miseTotaleJoueur;

            double miseTotaleIA;            // Mise de l'IA en fonction des jetons du joueur
        };

        bool partieGagnee;              // vrai si l'IA a gagné la partie

        Profil profil[NB_ETAPES];

    public:

        Profilage(std::string joueur);
        ~Profilage();

        /**
         * @action Ajoute les données de profilage de la partie dans le fichier correspondant au joueur
         */
        void sauvegarder() const;

};

#endif // PROFILAGE_H