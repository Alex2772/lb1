//
// Created by alex2772 on 11/16/20.
//

#include "StrongPokemon.h"

void StrongPokemon::serialize(YamlWriter& fos) {
    Pokemon::serialize(fos);
    fos.writeAttribute("special_attack", mSpecialAttack);
}

std::string StrongPokemon::getPokemonType() {
    return "strong_pokemon";
}

void StrongPokemon::dispatchAttribute(const std::string& key, int value) {
    if (key == "special_attack") {
        mSpecialAttack = value;
    } else {
        Pokemon::dispatchAttribute(key, value);
    }
}

