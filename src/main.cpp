#include <Geode/Geode.hpp>
#include <Geode/modify/OptionsLayer.hpp>
#include "ClockVaultLayer.hpp"

using namespace geode::prelude;

class $modify(OptionsLayer) {
    bool init() {
        if (!OptionsLayer::init()) return false;

        auto winSize = CCDirector::sharedDirector()->getWinSize();

        // Create the Clock Vault button
        auto btn = CCMenuItemSpriteExtra::create(
            CCSprite::create("clock_vault_face.png"),
            this,
            menu_selector(OptionsLayer::onClockVault)
        );

        // Position it in the top-right corner of the Options page
        btn->setPosition({ winSize.width - 40, winSize.height - 40 });

        // Add it to the existing menu
        auto menu = this->getChildByID("options-menu");
        if (menu) menu->addChild(btn);

        return true;
    }

    void onClockVault(CCObject*) {
        auto scene = CCScene::create();
        scene->addChild(ClockVaultLayer::create());
        CCDirector::sharedDirector()->pushScene(scene);
    }
};
