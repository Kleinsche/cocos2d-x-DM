//
//  MainScene.hpp
//  DM
//
//  Created by Kleinsche on 2017/7/14.
//
//

#ifndef MainScene_hpp
#define MainScene_hpp

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class MainScene:public Layer {
protected:
    
public:
    static Scene* createScene();
    
    virtual bool init();
    
    CREATE_FUNC(MainScene);
    
//    virtual void playBackgroundMusic(const char* pszFilePath, bool bLoop = false);
};

#endif /* MainScene_hpp */
