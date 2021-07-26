

#include "GameModel.h"



namespace HMR {

/**
 * \brief Construtor da classe GameModel
 */
GameModel::GameModel() {
}

/**
 * \brief Destrutor da classe GameModel
 */
GameModel::~GameModel() {
}

/**
 * \brief Limpa a classe, deixando apenas os conhecimentos default
 **/
 void GameModel::initialize()
 {
     setKnowledge( "lives in water", "shark" , "monkey" );
 }


 /**
  * \brief Direciona o ponteiro CURRENT para o inicio
  */
stNode* GameModel::moveFirst()
{
    return ( ptrNodeCurrent_ = rootData_.get() );
}

/**
 * \brief Move o ponteiro CURRENT para a informacao a esquerda, ou seja, a alterativa incorreta para a pergunta
 */
stNode* GameModel::moveLeft()
{
    return ( ptrNodeCurrent_ = ptrNodeCurrent_->nodeLeft.get() );
}

/**
* \brief Move o ponteiro CURRENT para a informacao a direita, ou seja, para a proxima op��o da lista
*/
stNode* GameModel::moveRight()
{
    return ( ptrNodeCurrent_ = ptrNodeCurrent_->nodeRight.get() );
}


/**
 * \brief Define o valor base para as tomadas de decis�o
 */
stNode* GameModel::setKnowledge(const std::string __trait, const std::string __animalRight, const std::string __animalLeft )
{
    const Knowledge know( Knowledge::KNOWLEDGE_TRAIT, __trait );
    rootData_ = std::unique_ptr< stNode > ( new stNode( know ) );

    // incluindo o valor correto para a caracteristica
    rootData_->nodeRight = std::unique_ptr< stNode >(
        new stNode(Knowledge( Knowledge::KNOWLEDGE_ANIMAL, __animalRight )
    ));

    // incluindo o valor alternativo para a caracteristica
    rootData_->nodeLeft = std::unique_ptr< stNode >(
        new stNode(Knowledge( Knowledge::KNOWLEDGE_ANIMAL, __animalLeft )
    ));


    return rootData_.get();
}


/**
* \brief Adiciona uma informa��o a ESQUERDA ( incorreta ) da tomada de decisao
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
* \brief Adiciona uma informa��o a DIREITA ( correta ) para a tomada de decisao.
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


} // HMR
