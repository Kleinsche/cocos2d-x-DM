//
//  Dog.cpp
//  jump
//
//  Created by Kleinsche on 2017/7/13.
//
//

#include "Dog.hpp"

Dog::Dog(){
    
}

Dog::~Dog(){
    
}

bool Dog::init(){
    
    if (!Sprite::init()) {
        return false;
    }
    
    auto cache = SpriteFrameCache::getInstance();
    cache->addSpriteFramesWithFile("DM.plist");
    
    Vector<SpriteFrame*> vect;
    char szName[100] = {0};
    
    for (int i = 4; i<=9; i++) {
        sprintf(szName, "dog－%d.png", i);
        auto push = cache->getSpriteFrameByName(szName);
        vect.pushBack(push);
    }
    
    Animation* animation = Animation::createWithSpriteFrames(vect,0.2f);
    Animate* animate = Animate::create(animation);
    runAction(RepeatForever::create(animate));
    
    
    setContentSize(Size(240, 240));

    setPosition(Vec2(150, Director::getInstance()->getVisibleSize().height /3 +160));
    
    

    return true;
}
