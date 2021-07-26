

#include "GameView.h"


#include <iostream>
#include <vector>
#include <string>

#define IS_OPTION_YES(o) ( o == 'Y' || o == 'S' || o == 'y' || o == 's')

const int _IDX_MESSAGE_THINK = 0;
const int _IDX_MESSAGE_ASK_TRAIT = 1;
const int _IDX_MESSAGE_ASK_ANIMAL = 2;
const int _IDX_MESSAGE_READ_ANIMAL = 3;
const int _IDX_MESSAGE_READ_TRAIT = 4;
const int _IDX_MESSAGE_GAME_AGAIN = 5;

std::vector< std::string >  __MESSAGES = {
    "Think about a animal.  [Press any key to continue] ",
    "Does the animal that you thought about %s? ( Press [Yes/No] ) ",
    "Is the animal that you thought about %s? ( Press [Yes/No] ) ",
    "What animal did you think? ",
    "A %s _______ but a %s dows not (Fill it with an animal trait, like 'lives in water' ) ",
    "Will Again?  ( Press [Yes/No] ) "
};



namespace psafe {

/**
 * Construtor da classe GameView
 */
GameView::GameView(psafe::GameModel & __model)
: _ptrModel( &__model )
{
}

/**
 * Destrutor da classe GameView
 */
GameView::~GameView() {
}

/**
 * Realiza uma
 */
void GameView::say_hello() {
    std::cout  <<  ">> iniciando GUESSING GAME..." << std::endl;
}

/**
 *
 */
void GameView::sendWarningThinkAnimal()
{
    std::cout << "> " << __MESSAGES.at(_IDX_MESSAGE_THINK) << std::endl;
    std::cin.get();
}

/**
 *
 */
const bool GameView::askTraitFound(const stNode* __current )
{
    char option[30];

    printf( __MESSAGES.at(_IDX_MESSAGE_ASK_TRAIT).c_str(), __current->value.getDescription().c_str() );
    std::cin >> option;

    return ( IS_OPTION_YES(option[0]) );
}

/**
 *
 */
const bool GameView::askAnimalFound(const stNode* __current )
{
    char option[30];

    printf( __MESSAGES.at(_IDX_MESSAGE_ASK_ANIMAL).c_str(), __current->value.getDescription().c_str() );
    std::cin >> option;

    return ( IS_OPTION_YES(option[0]) );
}

/**
 *
 */
const bool GameView::askGameAgain()
{
    char option;

    std::cout << std::endl;
    std::cout << __MESSAGES.at( _IDX_MESSAGE_GAME_AGAIN ).c_str() ;
    std::cin >> option;

    std::cout << std::endl;

    return ( IS_OPTION_YES(option) );
}

/**
 *
 */
const std::string GameView::readAnimalThink()
{
    std::string value;

    std::cout << __MESSAGES.at(_IDX_MESSAGE_READ_ANIMAL).c_str();
    std::cin.ignore();
    getline( std::cin, value);

    return ( value );
}

/**
 *
 */
const std::string GameView::readTraitAnimalThink(const std::string& __animalNovo, const std::string& __animalAntigo)
{
    std::string value;

    printf( __MESSAGES.at(_IDX_MESSAGE_READ_TRAIT).c_str(), __animalNovo.c_str() , __animalAntigo.c_str() );
    getline( std::cin, value);

    return ( value );
}

} // psafe
