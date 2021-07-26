
/**
 * @file GameController.h
 *
 * @brief Classe responsavel por ...*
 *
 *  Created on: 26/06/2021
 *  @author: Henrique Martins Roberto
 */


#ifndef __HMR_GAMECONTROLLER__
#define __HMR_GAMECONTROLLER__

#include "GameModel.h"
#include "GameView.h"


namespace HMR {

class GameController {
public:
    GameController(GameModel & model, GameView & view);
    virtual ~GameController();

    void run();

private:
    GameModel * ptrModel_;
    GameView  * ptrView_;
};

} // HMR

#endif  // __HMR_GAMECONTROLLER__
