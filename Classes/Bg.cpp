//
//  Bg.cpp
//  DM
//
//  Created by Kleinsche on 2017/7/14.
//
//

#include "Bg.hpp"
#include "Floor.hpp"

bool Bg::init(){
    if (!Layer::init()) {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    
    auto button = Sprite::create("buttonbg.png");
    auto top = Sprite::create("topbg.png");
    
    
    button->setAnchorPoint(Vec2(0, 0));
    button->setScale(visibleSize.width /button->getContentSize().width, visibleSize.height /3 /button->getContentSize().height);
    addChild(button);
    

    top->setAnchorPoint(Vec2(0, 0));
    top->setPosition(Vec2(0, visibleSize.height /3));
    top->setScale(visibleSize.width /top->getContentSize().width, visibleSize.height *2/3 /top->getContentSize().height);
    addChild(top);
    
    auto floor = Floor::create();
    addChild(floor);
    
    return true;
}
