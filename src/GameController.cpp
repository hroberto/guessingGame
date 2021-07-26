

#include "GameController.h"


namespace psafe {

/**
 * Construtor da classe GameController
 */
GameController::GameController(GameModel & __model, GameView & __view)
: _ptrModel(&__model), _ptrView(&__view)
{
}

/**
 * Destrutor da classe GameController
 */
GameController::~GameController() {
}


/**
 * Executa o Jogo, com base  nos Modelo de dados( Utilizado ) e a View para apresentacao ao usuario.
 */
void GameController::run()
{
    // Inicializa com a informacoes BASE conhecidas
// #include <conio.h>
    _ptrModel->initialize();

    bool isGameAgain = true;

    while ( isGameAgain ) {
        _ptrView->sendWarningThinkAnimal();

        psafe::stNode* ptrNoParent = NULL;
        bool bLastTraitFoundCorrect = false;

        bool restart = false;
        _ptrModel->moveFirst();

        while( ! restart )
        {

            if ( _ptrModel->getCurrent()->value.isTypeTrait() ) {
                bLastTraitFoundCorrect = _ptrView->askTraitFound( _ptrModel->getCurrent() );

                ptrNoParent = _ptrModel->getCurrent();

                if ( bLastTraitFoundCorrect ) {
                    _ptrModel->moveRight();
                }
                else {
                    _ptrModel->moveLeft();
                }
            }
            else {
                // FOUND animal
                const bool bAnimalFoundCorrect = _ptrView->askAnimalFound( _ptrModel->getCurrent() );

                if ( ! bAnimalFoundCorrect ) {
                    // faz a leitura das informacoes com o usuario para
                    // realizar o aprendizado para alimentar o conhecimento do sistema
                    std::string strAnimal = _ptrView->readAnimalThink();
                    std::string strTrait = _ptrView->readTraitAnimalThink(strAnimal, _ptrModel->getCurrent()->value.getDescription());

                    // envia a informacao coletada para registro pelo Modelo
                    if ( bLastTraitFoundCorrect ) {
                        _ptrModel->addKnowledgeRight(strTrait , strAnimal, ptrNoParent );
                    }
                    else {
                        _ptrModel->addKnowledgeLeft(strTrait , strAnimal, ptrNoParent );
                    }

                }
                restart = true;
            }
        }
        isGameAgain = _ptrView->askGameAgain();
    }
}


    // GameModel * _ptrModel;
    // GameView  * _ptrView;}

} // psafe
