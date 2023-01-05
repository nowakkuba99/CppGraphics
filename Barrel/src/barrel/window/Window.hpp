#ifndef D218ADBA_F2D2_4C63_B6C0_946515A0EA9A
#define D218ADBA_F2D2_4C63_B6C0_946515A0EA9A

/* 
    Abstract Window class
*/
// Pre-compiled headers
#include "../../pch/pchBarrel.hpp"
// Events
#include "../events/Event.hpp"

namespace Barrel
{
    // Window properties structure - used to create window object
    struct WindowProperties
    {
        // Mebmer variables
        std::string Title;
        uint32_t Width;
        uint32_t Height;

        // Constructor
        WindowProperties(const std::string& title = "Barrel Render Engine",
            uint32_t width = 1600,
            uint32_t height = 900)
            : Title(title), Width(width), Height(height) {}   
    };
    // Window abstract class - Interface for Mac window implementation
    class Window
    {
    public:
        // Set the window callback function as standard function - to be assinged later
        using EventCallbackFunction = std::function<void(Event&)>;  // Set the name EventCallbackFunction as void function that takes one Event reference parameter
        // No constructor - This is an interface
        
        // Virtual Destructor
        virtual ~Window() = default;
        
        // Pure virtual functions
        virtual void OnUpdate() = 0;

        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;

        // Window attributes modify functions
        virtual void SetEventCallback(const EventCallbackFunction& callback) = 0;   // Argument - function reference
        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;

        virtual void* GetNativeWindow() const = 0;

        // Function used to create the window
        static Window* Create(const WindowProperties& prop = WindowProperties());
    };
}



#endif /* D218ADBA_F2D2_4C63_B6C0_946515A0EA9A */
