#include <iostream>
#include <memory>
#include <vector>
#include <cassert>
#include "Pokemon.h"
#include "FatPokemon.h"
#include "StrongPokemon.h"

int main() {
    // запись
    std::vector<Pokemon*> pokemons;

    {
        auto pk = new Pokemon("petya");
        pk->setAttack(22);
        pk->setDefense(12);
        pk->setHealth(84);
        pk->setSpeed(17);
        pokemons.push_back(pk);
    }

    {
        auto pk = new StrongPokemon("vanya");
        pk->setSpecialAttack(13);
        pk->setAttack(14);
        pk->setDefense(42);
        pk->setHealth(33);
        pk->setSpeed(56);
        pokemons.push_back(pk);
    }

    {
        auto pk = new FatPokemon("zhora");
        pk->setSpecialDefense(13);
        pk->setAttack(14);
        pk->setDefense(42);
        pk->setHealth(33);
        pk->setSpeed(56);
        pokemons.push_back(pk);
    }

    // запись
    {
        std::ofstream fos("test.yaml");
        YamlWriter yaml(fos);

        for (auto& p : pokemons) {
            yaml.beginListObject(p->getPokemonType());
            p->serialize(yaml);
            yaml.endListObject();
        }

        for (auto& p : pokemons)
            delete p;
        pokemons.clear();
    }

    // считывание
    {
        std::ifstream fis("test.yaml");

        fis.seekg(2, std::ios::cur);
        std::string type;

        while (fis.good()) {
            // зачитается знак двоеточия на конце, уберём его
            fis >> type;
            type.resize(type.length() - 1);

            Pokemon* pokemon;
            if (type == "basic_pokemon") {
                pokemon = new Pokemon("unknown");
            } else if (type == "fat_pokemon") {
                pokemon = new FatPokemon("unknown");
            } else if (type == "strong_pokemon") {
                pokemon = new StrongPokemon("unknown");
            }

            std::string attribute;
            while (fis.good()) {
                fis >> attribute;
                if (attribute == "-" || !fis.good())
                    break;

                // зачитается знак двоеточия на конце, уберём его
                attribute.resize(attribute.length() - 1);

                std::string value;
                fis >> value;
                if (value[0] == '"') {
                    // строка
                    pokemon->dispatchAttribute(attribute, value.substr(1, value.length() - 2));
                } else if (isalnum(value[0])) {
                    // число
                    pokemon->dispatchAttribute(attribute, std::stoi(value));
                } else {
                    // какая-то ерунда, которую мы не осилим
                    assert(0);
                }
            }
            pokemons.push_back(pokemon);
        }
    }


    return 0;
}
