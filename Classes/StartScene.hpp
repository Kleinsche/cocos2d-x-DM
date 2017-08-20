//
//  StartScene.hpp
//  jump
//
//  Created by Kleinsche on 2017/7/13.
//
//

#ifndef StartScene_hpp
#define StartScene_hpp

#include <stdio.h>
#include "cocos2d.h"
#include <SimpleAudioEngine.h>
using namespace CocosDenshion;

#include "Dog.hpp"
#include "Monkey.hpp"
#include "Floor.hpp"
#include "MainScene.hpp"
#include "Bg.hpp"

USING_NS_CC;

class StartScene:public Layer {
protected:
//    void createEdge();
    
protected:
    Vector<Monkey*> vect;
    Size visibleSize;
    int _current;
    int _next = 60;
    
    
public:
    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(StartScene);
    
public:
    void onEnter();
    void update(float dt);
    
    
    int scorl;
    Label* label;
};

#endif /* StartScene_hpp */
