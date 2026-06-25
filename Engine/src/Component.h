#pragma once

class IComponent{
public:
    virtual ~IComponent() = default;

protected:
    static int nextIndex;

};


class Component:public IComponent
{
public:
    virtual void Awake()=0;
    virtual  void Start()=0;
    virtual void Update()=0;
    virtual void LateUpdate()=0;
    virtual void Render()=0;
    virtual void Destroy()=0;

};


