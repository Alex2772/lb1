//
// Created by alex2772 on 11/16/20.
//

#include <cassert>
#include "Pokemon.h"

Pokemon::Pokemon(const std::string& name) : mName(name) {}

void Pokemon::serialize(YamlWriter& fos) {
    fos.writeAttribute("name", getName());
    fos.writeAttribute("health", mHealth);
    fos.writeAttribute("attack", mAttack);
    fos.writeAttribute("defense", mDefense);
    fos.writeAttribute("speed", mSpeed);
}

std::string Pokemon::getPokemonType() {
    return "basic_pokemon";
}

void Pokemon::dispatchAttribute(const std::string& key, const std::string& value) {
    if (key == "name") {
        mName = value;
    } else {
        assert(0);
    }
}

void Pokemon::dispatchAttribute(const std::string& key, int value) {
    if (key == "health") {
        mHealth = value;
    } else if (key == "attack") {
        mAttack = value;
    } else if (key == "defense") {
        mDefense = value;
    } else if (key == "speed") {
        mSpeed = value;
    } else {
        assert(0);
    }
}
