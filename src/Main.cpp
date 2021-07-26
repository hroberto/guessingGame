
/**
 * GUESSING GAME
 *
 * @brief Este jogo realiza a interacao com o usuario para gerar uma base de conhecimento simplificada
 * e conseguir responder de maneira assertiva.
 *
 *  Created on: 26/06/2021
 *  @author: Henrique Martins Roberto
 */

 // #include <cstdlib>
#include <iostream>

#include "GameModel.h"
#include "GameView.h"
#include "GameController.h"


int main(int argc, char** argv)
{
    psafe::GameModel model;
    psafe::GameView view(model);
    psafe::GameController controller(model, view);

    try {
        controller.run();
    }
    catch(const std::exception & e) {
        std::cerr << "Erro inesperado no sistema [" << e.what() << "]" << std::endl;
        return  EXIT_FAILURE;
    }
    catch(...) {
        std::cerr << "Erro inesperado no sistema." << std::endl;
        return  EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
