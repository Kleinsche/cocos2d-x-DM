//
//  Dog.hpp
//  jump
//
//  Created by Kleinsche on 2017/7/13.
//
//

#ifndef Dog_hpp
#define Dog_hpp

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class Dog:public Sprite {
protected:
    
public:
    Dog();
    virtual ~Dog();
    virtual bool init();
    CREATE_FUNC(Dog);
    
};

#endif /* Dog_hpp */
