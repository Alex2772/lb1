#pragma once


#include "Pokemon.h"

class StrongPokemon: public Pokemon {
private:
    int mSpecialAttack = 0;
public:
    StrongPokemon(const std::string& name) : Pokemon(name) {}

    virtual ~StrongPokemon() = default;

    std::string getPokemonType() override;

    void setSpecialAttack(int specialAttack) {
        mSpecialAttack = specialAttack;
    }

    void dispatchAttribute(const std::string& key, int value) override;

    void serialize(YamlWriter& fos) override;
    void specialAttack() { }
};

