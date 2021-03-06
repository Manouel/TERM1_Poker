/*========================================================================
Nom: CalibrageIdeal.cpp       Auteur: Manuel CHATAIGNER
Maj: 07/05/2015            Creation: 07/05/2015
Projet: Profilage par essais et erreurs au poker
--------------------------------------------------------------------------
Specification: Fichier contenant les définitions de la classe CalibrageIdeal.
=========================================================================*/


#include "../../include/AI/IdealCalibration.h"
#include "../../include/Constants.h"

#include <QFile>
#include <QTextStream>

namespace ai {

    IdealCalibration::IdealCalibration(game::Game *game, profiling::Profile *profilingAI, profiling::Profile *profiledAI, int nbParts)
        : m_game(game), m_profilingAICalibration(profilingAI), m_profiledAICalibration(profiledAI), m_partsNumber(nbParts),
          m_numberPartsWon(0), m_totalTokensWon(0)
    {
        m_profilingAIRates << 15 << 30 << 45 << 60 << 75 << 90 << 100;
    }

    IdealCalibration::~IdealCalibration()
    {

    }

    void IdealCalibration::writeTotalPartsResult() const
    {
        QString filename = QString::number(m_profiledAICalibration->getAggressiveness()) + "_"
                                + QString::number(m_profiledAICalibration->getRationality()) + "_testsCalibrageIdeal.csv";
        QFile file(QString::fromStdString(STATIC_PROFILING_FOLDER) + filename);

        if (!file.open(QIODevice::Append | QIODevice::Text)) {
            std::cerr << "Erreur lors de l'ouverture du fichier de calibrage ideal" << std::endl;
            return;
        }

        QTextStream out(&file);

        // Si le fichier est vide, on ajoute l'en-tête
        if (file.size() == 0) {
            out << "Calibrage teste,Parties gagnees,Argent gagne" << endl;
        }

        double partsWon = (static_cast<double>(m_numberPartsWon) * 100.0) / m_partsNumber;

        out << m_profilingAICalibration->getAggressiveness() << "-" << m_profilingAICalibration->getRationality()
            << "," << partsWon << "," << m_totalTokensWon << endl;

        file.close();
    }

    void IdealCalibration::launchParts()
    {
        std::cout << m_profiledAICalibration->getAggressiveness() << " - " << m_profiledAICalibration->getRationality() << std::endl;

        for (int i = 0; i < m_profilingAIRates.size(); i++) {
            for (int j = 0; j < m_profilingAIRates.size(); j++) {

                m_profilingAICalibration->setAggressiveness(m_profilingAIRates[i]);
                m_profilingAICalibration->setRationality(m_profilingAIRates[j]);

                m_numberPartsWon = 0;
                m_totalTokensWon = 0;

                std::cout << "Calibrage " << m_profilingAICalibration->getAggressiveness() << "-" << m_profilingAICalibration->getRationality() << std::endl;

                for (int n = 0; n < m_partsNumber; n++) {
                    std::cout << "\tPartie " << n+1 << std::endl;

                    m_game->newGame();

                    m_game->launchPart();

                    // Si c'est l'IA qui a gagné
                    if (m_game->getGameResult() == LOOSE) {
                        ++m_numberPartsWon;
                    }

                    m_totalTokensWon += m_game->getPlayer(1)->getCave() - m_game->getPlayer(1)->getStartingCave();

                    m_game->newHand();
                }

                writeTotalPartsResult();
            }
        }
    }
}
