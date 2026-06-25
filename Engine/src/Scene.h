#pragma once
#include "Entity.h"
#include "Component.h"
#include <vector>

class Scene
{
private:
    Scene()=default;
    ~Scene()=default;
    std::vector<Entity*> entities;

public:
    static Scene& GetInstance()
    {
        static Scene instance;
        return instance;
    }

public:
    template<typename TComponent>
    Component* GetEntityComponent(Entity* entity) const;

    template<typename TComponent>
    Entity* GetEntityHasType()const;
    Entity* GetEntityWithName(const std::string& name)const;
    Entity* GetEntityWithTag(const std::string& tag)const;

public:
    virtual void Awake() ;
    virtual void Start() ;
    virtual void Update() ;
    virtual void LateUpdate() ;
    virtual void Render() ;
    virtual void Destroy() ;
};
