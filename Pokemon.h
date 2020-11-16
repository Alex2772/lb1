#pragma once

#include "YamlWriter.h"


class Pokemon {
private:
    std::string mName;
    int mHealth = 0;
    int mAttack = 0;
    int mDefense = 0;
    int mSpeed = 0;

public:
    Pokemon(const std::string& name);

    virtual ~Pokemon() {}

    int getHealth() const {
        return mHealth;
    }

    void setHealth(int health) {
        mHealth = health;
    }

    int getAttack() const {
        return mAttack;
    }

    void setAttack(int attack) {
        mAttack = attack;
    }

    int getDefense() const {
        return mDefense;
    }

    void setDefense(int defense) {
        mDefense = defense;
    }

    int getSpeed() const {
        return mSpeed;
    }

    void setSpeed(int speed) {
        mSpeed = speed;
    }

    const std::string& getName() const {
        return mName;
    }

    void setName(const std::string& name) {
        mName = name;
    }

    virtual void serialize(YamlWriter& fos);
    virtual std::string getPokemonType();

    virtual void dispatchAttribute(const std::string& key, const std::string& value);
    virtual void dispatchAttribute(const std::string& key, int value);
};

