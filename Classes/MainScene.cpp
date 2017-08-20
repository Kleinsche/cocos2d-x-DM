//
//  MainScene.cpp
//  DM
//
//  Created by Kleinsche on 2017/7/14.
//
//

#include "MainScene.hpp"
#include "Bg.hpp"
#include "Dog.hpp"
#include "StartScene.hpp"

#include <SimpleAudioEngine.h>
using namespace CocosDenshion;

Scene* MainScene::createScene(){
    auto scene = Scene::create();
    auto layer = MainScene::create();
    scene->addChild(layer);
    return scene;
}

bool MainScene::init(){
    
    if (!Layer::init()) {
        return false;
    }
    

    SimpleAudioEngine::getInstance()->preloadBackgroundMusic("music.mp3");
    SimpleAudioEngine::getInstance()->preloadEffect("tap.wav");
    
    
    SimpleAudioEngine::getInstance()->playBackgroundMusic("music.mp3",true);
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    
    auto bg = Bg::create();
    addChild(bg);
    
    auto dog = Dog::create();
    addChild(dog);
    
    
    auto label = Label::create();
    label->setSystemFontSize(200);
    label->setString("Start");
    label->setPosition(Vec2(visibleSize.width /2, visibleSize.height /4));
    addChild(label);
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [](Touch* t ,Event* e){
        if (e->getCurrentTarget()->getBoundingBox().containsPoint(t->getLocation())) {
            
            Director::getInstance()->replaceScene(StartScene::createScene());
        }
        
        return false;
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, label);
    
    return true;
}

