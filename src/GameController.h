
/**
 * @file GameController.h
 *
 * @brief Classe responsavel por ...*
 *
 *  Created on: 26/06/2021
 *  @author: Henrique Martins Roberto
 */


#ifndef __PSAFE_GAMECONTROLLER__
#define __PSAFE_GAMECONTROLLER__

#include "GameModel.h"
#include "GameView.h"


namespace psafe {

class GameController {
public:
    GameController(GameModel & __model, GameView & __view);
    virtual ~GameController();

    void run();

private:
    GameModel * _ptrModel;
    GameView  * _ptrView;
};

} // psafe

#endif  // __PSAFE_GAMECONTROLLER__
