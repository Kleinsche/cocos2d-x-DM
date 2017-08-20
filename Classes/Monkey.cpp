//
//  Monkey.cpp
//  dog
//
//  Created by Kleinsche on 2017/7/13.
//
//

#include "Monkey.hpp"
#include "StartScene.hpp"

Monkey::Monkey(){
    
}

Monkey::~Monkey(){
    
}

bool Monkey::init(){
    
    if (!Sprite::init()) {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    
    auto cache = SpriteFrameCache::getInstance();
    cache->addSpriteFramesWithFile("DM.plist");
    
    Vector<SpriteFrame*> vect;
    char szName[100] = {0};
    
    for (int i = 1; i<=9; i++) {
        sprintf(szName, "monkey－%d.tiff", i);
        auto push = cache->getSpriteFrameByName(szName);
        vect.pushBack(push);
    }
    
    Animation* animation = Animation::createWithSpriteFrames(vect,0.2f);
    Animate* animate = Animate::create(animation);
    
    runAction(RepeatForever::create(animate));
    
    
    setContentSize(Size(50, 50));
    auto physics = PhysicsBody::createCircle(25);
    physics->setRotationEnable(false);
    setPhysicsBody(physics);
    getPhysicsBody()->setRotationEnable(false);
    setPosition(Vec2(visibleSize.width, visibleSize.height /3 +90));
    
    getPhysicsBody()->setContactTestBitmask(2);
    setScale(2);
    
    
    scheduleUpdate();
    
    return true;
}

void Monkey::update(float dt) {
    this->setPositionX(getPositionX()-5);
    
    if (this->getPosition().x <= 50) {
        unscheduleUpdate();
        this->removeFromParent();
    }
}
