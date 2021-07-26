

#include "GameModel.h"



namespace psafe {

/**
 * Construtor da classe GameModel
 */
GameModel::GameModel() {
}

/**
 * Destrutor da classe GameModel
 */
GameModel::~GameModel() {
}

/**
 * Limpa a classe, deixando apenas os conhecimentos default
 **/
 void GameModel::initialize()
 {
     setKnowledge( "lives in water", "shark" , "monkey" );
 }


 /**
  * Direciona o ponteiro CURRENT para o inicio
  */
stNode* GameModel::moveFirst()
{
    return ( ptrNodeCurrent = rootData.get() );
}

/**
 * Move o ponteiro CURRENT para a informacao a esquerda, ou seja, a alterativa incorreta para a pergunta
 */
stNode* GameModel::moveLeft()
{
    return ( ptrNodeCurrent = ptrNodeCurrent->nodeLeft.get() );
}

/**
* Move o ponteiro CURRENT para a informacao a direita, ou seja, para a proxima opção da lista
*/
stNode* GameModel::moveRight()
{
    return ( ptrNodeCurrent = ptrNodeCurrent->nodeRight.get() );
}


/**
 * Define o valor base para as tomadas de decisão
 */
stNode* GameModel::setKnowledge(const std::string __trait, const std::string __animalRight, const std::string __animalLeft )
{
    const Knowledge know( Knowledge::KNOWLEDGE_TRAIT, __trait );
    rootData = std::unique_ptr< stNode > ( new stNode( know ) );

    // incluindo o valor correto para a caracteristica
    rootData->nodeRight = std::unique_ptr< stNode >(
        new stNode(Knowledge( Knowledge::KNOWLEDGE_ANIMAL, __animalRight )
    ));

    // incluindo o valor alternativo para a caracteristica
    rootData->nodeLeft = std::unique_ptr< stNode >(
        new stNode(Knowledge( Knowledge::KNOWLEDGE_ANIMAL, __animalLeft )
    ));


    return rootData.get();
}


/**
* Adiciona uma informação a ESQUERDA ( incorreta ) da tomada de decisao
*/
stNode* GameModel::addKnowledgeLeft(const std::string& __trait, const std::string & __animalRight, stNode* _nodeParent )
{
    std::unique_ptr< stNode > info ( new stNode(Knowledge( Knowledge::KNOWLEDGE_TRAIT, __trait )) );

    // incluindo o valor correto para a caracteristica
    info->nodeRight = std::unique_ptr< stNode >(
     new stNode(Knowledge( Knowledge::KNOWLEDGE_ANIMAL, __animalRight )
    ));

    // Inclui o animal atual na NEGACAO da nova caracteristica ( knowledge )
    info->nodeLeft = std::move(_nodeParent->nodeLeft );
    _nodeParent->nodeLeft = std::move(info);

    return info.get();
}



/**
* Adiciona uma informação a DIREITA ( correta ) para a tomada de decisao.
*/
stNode* GameModel::addKnowledgeRight(const std::string& __trait, const std::string & __animalRight, stNode* _nodeParent )
{
    std::unique_ptr< stNode > info ( new stNode( Knowledge( Knowledge::KNOWLEDGE_TRAIT, __trait ) ) );

    // incluindo o valor correto para a caracteristica
    info->nodeRight = std::unique_ptr< stNode >(
     new stNode(Knowledge( Knowledge::KNOWLEDGE_ANIMAL, __animalRight )
    ));

    // Inclui o animal atual na NEGACAO da nova caracteristica ( knowledge )
    info->nodeLeft = std::move(_nodeParent->nodeRight);
    _nodeParent->nodeRight = std::move(info);

    return info.get();
}


} // psafe
