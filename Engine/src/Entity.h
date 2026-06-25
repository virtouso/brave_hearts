#pragma once

#include "../../Game/src/framework/Game.h"
#include <vector>

#include "Component.h"

class Entity
{
private:
    std::string id;
    std::string name;
    std::string tag;
    Entity();
    explicit Entity(const std::string& name);
    ~Entity();
    std::vector<Component*> components;

public:
    std::string get_id();
    std::string get_name();
    std:: string get_tag();
std::vector<Component*> get_components();
public:
    virtual void Awake();
    virtual  void Start();
    virtual void Update();
    virtual void LateUpdate();
    virtual void Render();
    virtual void Destroy();

};


