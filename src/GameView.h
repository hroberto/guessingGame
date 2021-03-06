
/**
 * @file GameView.h
 *
 * @brief Classe responsavel por construir a intera��o com o usu�ria e a camada de controle do sistema
 *
 *  Created on: 26/06/2021
 *  @author: Henrique Martins Roberto
 */


#ifndef __HMR_GAMEVIEW__
#define __HMR_GAMEVIEW__

#include "GameModel.h"

namespace HMR {

class GameView {
public:
    GameView(HMR::GameModel & model);
    virtual ~GameView();

    void say_hello();

    void sendWarningThinkAnimal();
    const bool askTraitFound(const stNode* current );
    const bool askAnimalFound(const stNode* current );
    const bool askGameAgain();

    const std::string readAnimalThink();
    const std::string readTraitAnimalThink(const std::string& animalNovo, const std::string& animalAntigo);

private:
    HMR::GameModel*  ptrModel_;
};

} // HMR

#endif  // __HMR_GAMEVIEW__
