#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include "ClockVaultLayer.hpp"

using namespace geode::prelude;

class $modify(MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        auto winSize = CCDirector::sharedDirector()->getWinSize();

        auto btn = CCMenuItemSpriteExtra::create(
            CCSprite::create("clock_vault_face.png"),
            this,
            menu_selector(MenuLayer::onClockVault)
        );

        btn->setPosition({ winSize.width - 40, 40 });

        auto menu = this->getChildByID("bottom-menu");
        if (menu) menu->addChild(btn);

        return true;
    }

    void onClockVault(CCObject*) {
        auto scene = CCScene::create();
        scene->addChild(ClockVaultLayer::create());
        CCDirector::sharedDirector()->pushScene(scene);
    }
};
