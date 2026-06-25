#include "Scene.h"


void Scene::Awake()
{
    for (const auto e : entities)
    {
        e->Awake();
    }
}

void Scene::Start()
{
    for (const auto e : entities)
    {
        e->Start();
    }
}

void Scene::Update()
{
    for (const auto e : entities)
    {
        e->Update();
    }
}

void Scene::LateUpdate()
{
    for (const auto e : entities)
    {
        e->LateUpdate();
    }
}

void Scene::Render()
{
    for (const auto e : entities)
    {
        e->Render();
    }
}

void Scene::Destroy()
{
    for (const auto e : entities)
    {
        e->Destroy();
    }
}


//


template <typename TComponent>
Component* Scene::GetEntityComponent(Entity* entity) const
{
    for (const auto& com : entity->get_components())
    {
        auto result = dynamic_cast<TComponent*>(com);
        if (result)
            return result;
    }
    return nullptr;
}

template <typename TComponent>
Entity* Scene::GetEntityHasType() const
{
    for (const auto& en : entities)
    {
        for (const auto& com : en->get_components())
        {
            auto result = dynamic_cast<TComponent*>(com);
            if (result)
                return en;
        }
    }
    return nullptr;
}


Entity* Scene::GetEntityWithName(const std::string& name) const
{
    for (const auto e : entities)
    {
        if (e->get_name() == name)
            return e;
    }
    return nullptr;
}


Entity* Scene::GetEntityWithTag(const std::string& tag) const
{
    for (const auto e : entities)
    {
        if (e->get_tag() == tag)
            return e;
    }
    return nullptr;
}
