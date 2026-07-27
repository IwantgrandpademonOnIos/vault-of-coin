#include "ClockVaultLayer.hpp"
using namespace geode::prelude;

ClockVaultLayer* ClockVaultLayer::create() {
    auto ret = new ClockVaultLayer();
    if (ret && ret->init()) {
        ret->autorelease();
        return ret;
    }
    delete ret;
    return nullptr;
}

bool ClockVaultLayer::init() {
    if (!CCLayer::init()) return false;

    auto winSize = CCDirector::sharedDirector()->getWinSize();

    auto bg = CCSprite::create("clock_vault_bg.png");
    bg->setPosition(winSize / 2);
    this->addChild(bg);

    auto title = CCLabelBMFont::create("???", "bigFont.fnt");
    title->setPosition({ winSize.width / 2, winSize.height - 60 });
    this->addChild(title);

    auto prompt = CCLabelBMFont::create("TAP TO INSERT A NUMBER", "goldFont.fnt");
    prompt->setPosition({ winSize.width / 2, winSize.height - 120 });
    this->addChild(prompt);

    auto inputBox = CCSprite::create("ui/input_box.png");
    inputBox->setPosition({ winSize.width / 2, winSize.height - 180 });
    this->addChild(inputBox);

    auto face = CCSprite::create("clock_vault_face.png");
    face->setPosition({ winSize.width / 2, 80 });
    this->addChild(face);

    return true;
}
