//
// Created by alex2772 on 11/16/20.
//

#include "FatPokemon.h"

void FatPokemon::serialize(YamlWriter& fos) {
    Pokemon::serialize(fos);
    fos.writeAttribute("special_defense", mSpecialDefense);
}

std::string FatPokemon::getPokemonType() {
    return "fat_pokemon";
}

void FatPokemon::dispatchAttribute(const std::string& key, int value) {
    if (key == "special_defense") {
        mSpecialDefense = value;
    } else {
        Pokemon::dispatchAttribute(key, value);
    }
}
