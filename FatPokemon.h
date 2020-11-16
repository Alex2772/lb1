#pragma once


#include "Pokemon.h"

class FatPokemon: public Pokemon {
private:
    int mSpecialDefense = 0;
public:
    FatPokemon(const std::string& name) : Pokemon(name) {}

    virtual ~FatPokemon() = default;

    void dispatchAttribute(const std::string& key, int value) override;

    void serialize(YamlWriter& fos) override;

    void setSpecialDefense(int specialDefense) {
        mSpecialDefense = specialDefense;
    }

    std::string getPokemonType() override;

    void specialDefense() { }

};

