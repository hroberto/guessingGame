
/**
 * @file Knowledge.h
 *
 * @brief Classe responsavel por ...*
 *
 *  Created on: 26/06/2021
 *  @author: Henrique Martins Roberto
 */


#ifndef __HMR_KNOWLEDGE__
#define __HMR_KNOWLEDGE__

#include <string>
#include <memory>

namespace HMR {

class Knowledge {
public:
    typedef enum
    {
        KNOWLEDGE_TRAIT = 1,
        KNOWLEDGE_ANIMAL = 2
    } type;

    Knowledge(const Knowledge& __value) : _type(__value._type), _description(__value._description)
    {
    }
    Knowledge(const type& __type, const std::string & __description ) : _type(__type), _description(__description)
    {
    }

    virtual ~Knowledge()
    {
    }

    // GETs
    const std::string & getDescription() const { return (_description); }
    const type& getType() const { return (_type); }

    const bool isTypeTrait() const { return ( _type == KNOWLEDGE_TRAIT ); }
    const bool isTypeAnimal() const { return ( _type == KNOWLEDGE_ANIMAL ); }


private:
    Knowledge::type _type;
    std::string   _description;
};


struct stNode {
    // std::unique_ptr< Knowledge > value;
    Knowledge value;
    std::unique_ptr< stNode > nodeRight; // YES
    std::unique_ptr< stNode > nodeLeft;  // NO, others options

    // stNode() {}
    stNode(const Knowledge&  __value) : value(__value) {}

};


} // HMR

#endif  // __HMR_KNOWLEDGE__
