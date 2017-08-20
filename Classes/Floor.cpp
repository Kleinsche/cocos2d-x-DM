//
//  Floor.cpp
//  DM
//
//  Created by Kleinsche on 2017/7/14.
//
//

#include "Floor.hpp"

bool Floor::init(){
    
    if (!Sprite::init()) {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    
    setTextureRect(Rect(0, 0, visibleSize.width, 10));
    setColor(Color3B(136, 17, 0));
    setPosition(visibleSize.width /2, visibleSize.height /3 +39);
    
    
    
    
    return true;
}
