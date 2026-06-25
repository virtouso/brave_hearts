#include "Entity.h"
#include <crossguid/guid.hpp>

Entity::Entity()
{
    id = xg::newGuid().str();
}

Entity::Entity(const std::string& name)
{
    id = xg::newGuid().str();
    this->name = name;
}

Entity::~Entity()
{
}

std::string Entity::get_id()
{
    return id;
}

std::string Entity::get_name()
{
    return name;
}

std::string Entity::get_tag()
{
    return tag;
}

std::vector<Component*> Entity::get_components()
{
    return components;
}

void Entity::Awake()
{
    for (const auto com : components)
    {
        com->Awake();
    }
}

void Entity::Start()
{
    for (const auto com : components)
    {
        com->Start();
    }
}

void Entity::Update()
{
    for (const auto com : components)
    {
        com->Update();
    }
}

void Entity::LateUpdate()
{
    for (const auto com : components)
    {
        com->LateUpdate();
    }
}

void Entity::Render()
{
    for (const auto com : components)
    {
        com->Render();
    }
}

void Entity::Destroy()
{
    for (const auto com : components)
    {
        com->Destroy();
    }
}
