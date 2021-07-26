
/**
 * @file GameModel.h
 *
 * @brief Classe responsavel por ...*
 *
 *  Created on: 26/06/2021
 *  @author: Henrique Martins Roberto
 */


#ifndef __PSAFE_GAMEMODEL__
#define __PSAFE_GAMEMODEL__


#include "Knowledge.h"

namespace psafe {

/**
 * GameModel model

 * stNode* newNo1 = model.addKnowledge( "lives in water", "shark" , "monkey" );
 * stNode* newNo2 = model.addKnowledgeLeft( "lives in home", "dog", newNo1 );
 * stNode* newNo3 = model.addKnowledgeRigth( "lives in the river", "carp", newNo1 );
 * stNode* newNo4 = model.addKnowledgeLeft( "lives in room", "cat", newNo2 );
 */

class GameModel {
public:

    GameModel();
    virtual ~GameModel();

    void initialize();

    stNode* moveFirst();
    stNode* moveLeft();  // response NO
    stNode* moveRight(); // response YES

    stNode* getCurrent() const { return ptrNodeCurrent; }

    stNode* setKnowledge(const std::string __trait, const std::string __animalRight, const std::string __animalLeft );
    stNode* addKnowledgeLeft(const std::string& __trait, const std::string & __animalRight, stNode* _nodeParent );
    stNode* addKnowledgeRight(const std::string& __trait, const std::string & __animalRight, stNode* _nodeParent );

protected:
private:
    std::unique_ptr< stNode > rootData;
    stNode* ptrNodeCurrent;
};

} // psafe

#endif  // __PSAFE_GAMEMODEL__
