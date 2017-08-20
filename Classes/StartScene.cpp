//
//  StartScene.cpp
//  jump
//
//  Created by Kleinsche on 2017/7/13.
//
//

#include "StartScene.hpp"

Scene* StartScene::createScene(){
    auto scene = Scene::createWithPhysics();
    auto physics = scene->getPhysicsWorld();
//    physics->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    physics->setGravity(Vec2(0, -1000));
    
    auto layer = StartScene::create();
    scene->addChild(layer);
    
    return scene;
}

bool StartScene::init(){
    if (!Layer::init()) {
        return false;
    }
    
    visibleSize = Director::getInstance()->getVisibleSize();

        auto bg = Bg::create();
        addChild(bg);
    
    scorl = 0;

    
    return true;
}

void StartScene::onEnter(){
    Layer::onEnter();
//    this->createEdge();
    scheduleUpdate();
    
    
    auto floor = Floor::create();
    auto physicsF = PhysicsBody::createBox(floor->getContentSize());
    physicsF->setDynamic(false);
    physicsF->getShape(0)->setMaterial(PhysicsMaterial(0,0,0));
    floor->setPhysicsBody(physicsF);
    addChild(floor);
    
    auto dog = Dog::create();
    auto physicsD = PhysicsBody::createCircle(115);
    physicsD->setRotationEnable(false);
    physicsD->getShape(0)->setMaterial(PhysicsMaterial(0,0,0));
    dog->setPhysicsBody(physicsD);
    dog->getPhysicsBody()->setRotationEnable(false);
    dog->getPhysicsBody()->setContactTestBitmask(1);
    addChild(dog);
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [dog,this](Touch* t,Event* e){
        
        if (dog->getPositionY() <= visibleSize.height /3 +200) {
            SimpleAudioEngine::getInstance()->playEffect("tap.wav");
            dog->getPhysicsBody()->setVelocity(Vec2(0, 998));
            
            
            if (vect.size()) {
                auto it = vect.begin();

                    for (*it; it != vect.end(); it++) {
                        (*it)->getPhysicsBody()->setVelocity(Vec2(0, 900));
                    }

        }
        
        
            
        }
        
        return false;
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
    
    auto contentListener = EventListenerPhysicsContact::create();
    contentListener->onContactBegin = [this](PhysicsContact& contact){
        
        switch (contact.getShapeA()->getBody()->getContactTestBitmask() | contact.getShapeB()->getBody()->getContactTestBitmask()) {
            case 1 | 2:
                SimpleAudioEngine::getInstance()->stopBackgroundMusic();
                Director::getInstance()->replaceScene(MainScene::createScene());
                
                if (scorl > UserDefault::getInstance()->getIntegerForKey("scorl")) {
                    UserDefault::getInstance()->setIntegerForKey("scorl", scorl);
                }
                break;

            default:
                break;
        }
        
        return true;
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contentListener, this);
    
    
    label = Label::create();
    label->setSystemFontSize(50);
    label->setString(StringUtils::format("得分：0/%d",UserDefault::getInstance()->getIntegerForKey("scorl")));
    
    label->setPosition(Vec2(visibleSize.width/2, visibleSize.height -100));
    addChild(label);
    
    
}

//void StartScene::createEdge(){
//    auto physics = PhysicsBody::createEdgeBox(visibleSize,PHYSICSBODY_MATERIAL_DEFAULT,3);
//    auto edge = Node::create();
//    edge->setPosition(visibleSize/2);
//    edge->setPhysicsBody(physics);
//    addChild(edge);
//    edge->getPhysicsBody()->setContactTestBitmask(0);
//}


void StartScene::update(float dt){
    _current++;
    if (_current >= _next) {
        _current = 0;
        _next = rand()%120 +120;
        auto monkey = Monkey::create();
        addChild(monkey);
        vect.pushBack(monkey);
        
    }
    
    CCLOG("%zd",vect.size());
    if (vect.size()) {
        auto it = vect.begin();
        if ((*it)->getPosition().x <= 100) {
            vect.erase(it);
            scorl++;
//            CCLOG("%d",scorl);
            label->setString(StringUtils::format("得分：%d/%d",scorl,UserDefault::getInstance()->getIntegerForKey("scorl")));
        }
    }
    
    
}
