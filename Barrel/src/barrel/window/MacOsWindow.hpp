#ifndef BB233731_10BA_4EEF_91FF_1685C894CFD5
#define BB233731_10BA_4EEF_91FF_1685C894CFD5
/*
    Mac Os window class
*/
#include <GLFW/glfw3.h>

#include "Window.hpp"

namespace Barrel
{
    // MacOs specific window class
    class MacOsWindow : public Window
    {
    public:
        // Constructor
        MacOsWindow(const WindowProperties& properties);
        // Destructor
        virtual ~MacOsWindow();

        // Override functions
        void OnUpdate() override;

        unsigned int GetWidth() const override { return m_Data.Width; }
        unsigned int GetHeight() const override { return m_Data.Height; }

        // Window properties modify functions
        void SetEventCallback(const EventCallbackFunction& callback) override { m_Data.EventCallback = callback; }
        void SetVSync(bool enabled) override;
        bool IsVSync() const override;

        virtual void* GetNativeWindow() const override { return m_Window; }
    private:
        // Private window operating functions
        virtual void Init(const WindowProperties& prop);
        virtual void Shutdown();
    private:
        // Member data
        GLFWwindow* m_Window;   // Window pointer

        // Structore to hold window parameters
        struct WindowData
        {
            std::string Title;
            unsigned int Width, Height;
            bool VSync;

            EventCallbackFunction EventCallback;
        };

        WindowData m_Data;  // Window properties
    public:
        static Window* Create(const WindowProperties prop = WindowProperties());    // Function to create new window
    };
}

#endif /* BB233731_10BA_4EEF_91FF_1685C894CFD5 */
