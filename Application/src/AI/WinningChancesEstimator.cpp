#include "../../include/AI/WinningChancesEstimator.h"
#include "../../include/Game/Card.h"

#include <string>
#include <unordered_map>
#include <vector>

namespace ai {

    WinningChancesEstimator::WinningChancesEstimator(game::Game *game, game::Player *player, int testsNumber)
        : m_testsNumber(testsNumber), m_estimateResult(0), m_game(game), m_player(player) {

    }

    WinningChancesEstimator::~WinningChancesEstimator() {

    }

    double WinningChancesEstimator::getEstimateResult() const {
        return m_estimateResult;
    }

    void WinningChancesEstimator::setTestsNumber(int testsNumber) {
        m_testsNumber = testsNumber;
    }

    void WinningChancesEstimator::setGame(game::Game *game) {
        m_game = game;
    }

    void WinningChancesEstimator::setPlayer(game::Player *player) {
        m_player = player;
    }

    void WinningChancesEstimator::run() {
        estimateWinningChances();
    }

    void WinningChancesEstimator::estimateWinningChances() {

        double numberOfPartsWon = 0;
        int position;
        int tableSize;
        std::vector<game::Card> table;
        std::vector<game::Card> opponentsHand;
        std::vector<game::Card> deck;

        for (int t = 0; t < m_testsNumber; t++) {
            deck.clear();
            table.clear();
            opponentsHand.clear();

            deck = newDeck();
            WinningChancesEstimator::shuffle(deck);

            table = m_game->getTable();
            tableSize =  5 - (int) table.size();

            for (int i = 0; i < tableSize; i++) {
                position = rand() % deck.size();
                table.push_back(deck.at(position));
                deck.erase(deck.begin() + position);
            }

            for (int i = 0; i < 2; i++) {
                position = rand() % deck.size();
                opponentsHand.push_back(deck.at(position));
                deck.erase(deck.begin() + position);
            }

            GAME_RESULT compareHandsResult = assessor::Assessor::compareHands(table,m_player->getHand(), opponentsHand);

            if (compareHandsResult == WON) {
                ++numberOfPartsWon;

            }
        }

        m_estimateResult = numberOfPartsWon / m_testsNumber;
    }


    std::vector<game::Card> WinningChancesEstimator::newDeck() {
        std::vector<game::Card> deck;

        for (int i = CARD_COLOR::SPADES; i <= CARD_COLOR::DIAMONDS; i++) {
            for (int j = CARD_RANK::AS; j <= CARD_RANK::K; j++) {
                game::Card carte(j,i);
                deck.push_back(carte);
            }
        }

        deck.erase(deck.begin() + m_player->getHand().at(0).getId());
        deck.erase(deck.begin() + m_player->getHand().at(1).getId());

        return deck;
    }

    void WinningChancesEstimator::shuffle(std::vector<game::Card>& deck) {
        std::random_shuffle(deck.begin(),deck.end());
    }
}
