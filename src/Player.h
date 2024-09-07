#pragma once

#include <iostream>
#include <SDL2/SDL.h>

#include "Entity.h"

class Player : public Entity {
public:
    Player();
    ~Player();

    // Methods to access and modify attributes
    int getMana() const;
    void setMana(int mana);
    std::u32string getName() const;
    void setName(const std::u32string& name);

private:
    int mana;
    double radius;
    std::u32string name;
};
