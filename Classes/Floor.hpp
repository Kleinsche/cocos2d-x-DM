//
//  Floor.hpp
//  DM
//
//  Created by Kleinsche on 2017/7/14.
//
//

#ifndef Floor_hpp
#define Floor_hpp

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class Floor:public Sprite {
protected:
    
public:
    virtual bool init();
    CREATE_FUNC(Floor);
};

#endif /* Floor_hpp */
