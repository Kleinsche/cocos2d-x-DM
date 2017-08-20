//
//  Monkey.hpp
//  dog
//
//  Created by Kleinsche on 2017/7/13.
//
//

#ifndef Monkey_hpp
#define Monkey_hpp

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class Monkey:public Sprite {
protected:
    
    
public:
    Monkey();
    virtual ~Monkey();
    virtual bool init();
    CREATE_FUNC(Monkey);
    
    void update(float dt);
    

};

#endif /* Monkey_hpp */
