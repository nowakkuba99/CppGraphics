// Include libraries
#include <iostream>
#include "Barrel.hpp"

// Include user files

/* Example Layer */
class ExampleLayer : public Barrel::Layer
{
public:
    ExampleLayer() : Layer("Example layer") {}

    void OnUpdate() override
    {
        //BR_INFO("ExampleLayer::Update");
        //if(Barrel::Input::IsKeyPressed(Barrel::Key::Tab))
          //  BR_INFO("TAB Key pressed ...");
    }

    void OnEvent(Barrel::Event& event) override
    {
        //BR_TRACE("{0}",event);
        if(event.GetEventType() == Barrel::EventType::KeyPressed)
        {
            Barrel::KeyPressedEvent casted = static_cast<Barrel::KeyPressedEvent&>(event);
            BR_INFO("Key: {0} pressed ...",static_cast<char>(casted.GetKeyCode()));
        }
    }
};




/* Sandbox application that is a sub class of Barrel Application */
class Sandbox : public Barrel::Application
{
    public:
        Sandbox()
        {
            PushLayer(new ExampleLayer{});
        };
        ~Sandbox()
        {

        };
};


/* Create application and pass to the barrel engine */
Barrel::Application* Barrel::CreateApplication()
{
    return new Sandbox();
}
