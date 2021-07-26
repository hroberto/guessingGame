
/**
 * @file GameView.h
 *
 * @brief Classe responsavel por construir a interação com o usuária e a camada de controle do sistema
 *
 *  Created on: 26/06/2021
 *  @author: Henrique Martins Roberto
 */


#ifndef __PSAFE_GAMEVIEW__
#define __PSAFE_GAMEVIEW__

#include "GameModel.h"

namespace psafe {

class GameView {
public:
    GameView(psafe::GameModel & __model);
    virtual ~GameView();

    void say_hello();

    void sendWarningThinkAnimal();
    const bool askTraitFound(const stNode* __current );
    const bool askAnimalFound(const stNode* __current );
    const bool askGameAgain();

    const std::string readAnimalThink();
    const std::string readTraitAnimalThink(const std::string& __animalNovo, const std::string& __animalAntigo);

private:
    psafe::GameModel*  _ptrModel;
};

} // psafe

#endif  // __PSAFE_GAMEVIEW__
