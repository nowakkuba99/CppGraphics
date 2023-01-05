#ifndef FF5E1331_88AF_4C2B_BA17_7C2305C430C9
#define FF5E1331_88AF_4C2B_BA17_7C2305C430C9
// Includes
#include <glad/glad.h>
#include <GLFW/glfw3.h>
// User files
#include "../window/Window.hpp"
#include "../events/Event.hpp"
#include "../events/ApplicationEvent.hpp"
#include "../layers/LayerStack.hpp"
// Application class
namespace Barrel
{
    class Application
    {
    public:
        //Constructors
        Application();
        // Destructors
        virtual ~Application();
        // Custom functions
        void Run();
        // Event Realted
        void OnEvent(Event& event);
        // Layer related
        void PushLayer(Layer* layer);
        void PopLayer(Layer* layer);

        void PushOverlay(Layer* overlay);

        // Static application get
        inline static Application& Get() { return *s_Instance; }
        Window& GetWindow() { return *m_Window; }
    private:
        // Functions
        bool OnWindowClose(WindowCloseEvent& event);

        // Member variables
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        LayerStack m_LayerStack;

        static Application* s_Instance;
    };
    /* Function used to create application by dependent application */
    Application* CreateApplication();
}
#endif /* FF5E1331_88AF_4C2B_BA17_7C2305C430C9 */
