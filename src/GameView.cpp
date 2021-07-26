

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



namespace HMR {

/**
 * \brief Construtor da classe GameView
 */
GameView::GameView(HMR::GameModel & model)
: ptrModel_( &model )
{
}

/**
 * \brief Destrutor da classe GameView
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
 * \brief Exibe a mensagem sobre o Animal elegivel
 */
void GameView::sendWarningThinkAnimal()
{
    std::cout << "> " << __MESSAGES.at(_IDX_MESSAGE_THINK) << std::endl;
    std::cin.get();
}


/**
 * \brief Exibe o questionamento se a caracteristica do animal está correta.
 * \param  current Node que identifica a caracteristica atual do animal.
 * \return Retorno booleano ( True/False ).
 */
const bool GameView::askTraitFound(const stNode* current )
{
    char option[30];

    printf( __MESSAGES.at(_IDX_MESSAGE_ASK_TRAIT).c_str(), current->value.getDescription().c_str() );
    std::cin >> option;

    return ( IS_OPTION_YES(option[0]) );
}


/**
 * \brief Exibe o questionamento se o animal esta correto.
 * \param current Node que identifica o animal atual.
 * \return Retorno booleano ( true/false )
 */
const bool GameView::askAnimalFound(const stNode* current )
{
    char option[30];

    printf( __MESSAGES.at(_IDX_MESSAGE_ASK_ANIMAL).c_str(), current->value.getDescription().c_str() );
    std::cin >> option;

    return ( IS_OPTION_YES(option[0]) );
}


/**
 * \brief  Exibe se o jogador quer continuar o jogo.
 * \return Retorno booleano ( true/false )
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
 * \brief Solicita a entrada do animal que o jogador pensou
 * \return  Retorna um texto indicando o animal
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
 * \brief Solicita a entrada da caracteristica do animal que o jogador pensou, que diferencia do ultimo animal
 * \param animalNovo Nome do novo animal
 * \param animalAntigo  Nome do antigo animal
 * \return Descricao da caracteristica do novo animal.
 */
const std::string GameView::readTraitAnimalThink(const std::string& animalNovo, const std::string& animalAntigo)
{
    std::string value;

    printf( __MESSAGES.at(_IDX_MESSAGE_READ_TRAIT).c_str(), animalNovo.c_str() , animalAntigo.c_str() );
    getline( std::cin, value);

    return ( value );
}

} // HMR
