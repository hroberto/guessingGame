

#include "GameController.h"


namespace HMR {

/**
 * \brief Construtor da classe GameController
 */
GameController::GameController(GameModel & model, GameView & view)
: ptrModel_(&model), ptrView_(&view)
{
}

/**
 * \brief Destrutor da classe GameController
 */
GameController::~GameController() {
}


/**
 * \brief Executa o Jogo, com base  nos Modelo de dados( Utilizado ) e a View para apresentacao ao usuario.
 */
void GameController::run()
{
    // Inicializa com a informacoes BASE conhecidas
    ptrModel_->initialize();

    bool isGameAgain = true;

    while ( isGameAgain ) {
        ptrView_->sendWarningThinkAnimal();

        HMR::stNode* ptrNoParent = NULL;
        bool bLastTraitFoundCorrect = false;

        bool restart = false;
        ptrModel_->moveFirst();

        while( ! restart )
        {

            if ( ptrModel_->getCurrent()->value.isTypeTrait() ) {
                bLastTraitFoundCorrect = ptrView_->askTraitFound( ptrModel_->getCurrent() );

                ptrNoParent = ptrModel_->getCurrent();

                if ( bLastTraitFoundCorrect ) {
                    ptrModel_->moveRight();
                }
                else {
                    ptrModel_->moveLeft();
                }
            }
            else {
                // FOUND animal
                const bool bAnimalFoundCorrect = ptrView_->askAnimalFound( ptrModel_->getCurrent() );

                if ( ! bAnimalFoundCorrect ) {
                    // faz a leitura das informacoes com o usuario para
                    // realizar o aprendizado para alimentar o conhecimento do sistema
                    std::string strAnimal = ptrView_->readAnimalThink();
                    std::string strTrait = ptrView_->readTraitAnimalThink(strAnimal, ptrModel_->getCurrent()->value.getDescription());

                    // envia a informacao coletada para registro pelo Modelo
                    if ( bLastTraitFoundCorrect ) {
                        ptrModel_->addKnowledgeRight(strTrait , strAnimal, ptrNoParent );
                    }
                    else {
                        ptrModel_->addKnowledgeLeft(strTrait , strAnimal, ptrNoParent );
                    }

                }
                restart = true;
            }
        }
        isGameAgain = ptrView_->askGameAgain();
    }
}

} // HMR
