#ifndef TOOLS_H
#define TOOLS_H
#include "../objects/gameobject.h"
#include <string>




namespace _2DEngine
{
    using namespace engine;
    void createObject(std::string name);
    void deleteObject(std::string name);
    void deleteObject(GameObject* object);
    GameObject* findObject(std::string name);

    template <typename ComponentType>
    void addComponent(std::string name)
    {
        GameObject* currentObj = findObject(name);
        //std::cout << currentObj->components.size() << std::endl;
        if (currentObj)
        {
            if (!currentObj->hasComponent<ComponentType>())
            {
                ComponentType* component = new ComponentType;
                component->parentObject = currentObj;
                currentObj->components.push_back(component);
                int last_elem = currentObj->components.size()-1;

                if (component->name == "BasicScript")
                {
                    currentObj->components[last_elem]->name = "BasicScript";
                    currentObj->registerObjComponent(component);
                }
                if (component->name == "Renderer")
                {
                    currentObj->components[last_elem]->name = "Renderer";
                    currentObj->registerObjComponent(component);

                }

                if (component->name == "RectCollider")
                {
                    currentObj->components[last_elem]->name = "RectCollider";
                    currentObj->registerObjComponent(component);

                }
                if (component->name == "PhysicalBody")
                {
                    currentObj->components[last_elem]->name = "PhysicalBody";
                    currentObj->registerObjComponent(component);

                }
                if (component->name == "Animation")
                {
                    currentObj->components[last_elem]->name = "Animation";
                }
                //std::cout << "component " << currentObj->components[last_elem]->name << " added" << std::endl;
            }
            else
            {
                std::cout << "Unable to add component: " << typeid(ComponentType).name() << std::endl;
            }
        }
        else
            std::cout << "Object not found: " << name << std::endl;
    }

    template <typename ComponentType>
    void addComponent(GameObject* currentObj)
    {
        if (currentObj)
        {
            if (!currentObj->hasComponent<ComponentType>())
            {
                ComponentType* component = new ComponentType;
                component->parentObject = currentObj;
                currentObj->components.push_back(component);
                int last_elem = currentObj->components.size()-1;

                if (component->name == "BasicScript")
                {
                    currentObj->registerObjComponent(component);
                    currentObj->components[last_elem]->name = "BasicScript";
                }
                if (component->name == "Renderer")
                {
                    currentObj->registerObjComponent(component);
                    currentObj->components[last_elem]->name = "Renderer";
                }

                if (component->name == "RectCollider")
                {
                    currentObj->registerObjComponent(component);
                    currentObj->components[last_elem]->name = "RectCollider";
                }
                if (component->name == "PhysicalBody")
                {
                    currentObj->registerObjComponent(component);
                    currentObj->components[last_elem]->name = "PhysicalBody";
                }
                if (component->name == "Animation")
                {
                    currentObj->components[last_elem]->name = "Animation";
                }
                //std::cout << "component " << currentObj->components[last_elem]->name << " added" << std::endl;
            }
            else
            {
                std::cout << "Unable to add component: " << typeid(ComponentType).name() << std::endl;
            }
        }
        else
            std::cout << "Object not found: " << currentObj << std::endl;
    }
}

#endif // TOOLS_H
