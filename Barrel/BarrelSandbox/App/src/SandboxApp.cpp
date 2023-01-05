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
    }

    void OnEvent(Barrel::Event& event) override
    {
        BR_TRACE("{0}",event);
    }
};




/* Sandbox application that is a sub class of Barrel Application */
class Sandbox : public Barrel::Application
{
    public:
        Sandbox()
        {
            PushLayer(new ExampleLayer{});
            PushOverlay(new Barrel::ImGuiLayer{});
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
