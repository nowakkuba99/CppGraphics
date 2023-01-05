// Pre-compiled headers
#include "../../pch/pchBarrel.hpp"
// MacOs window
#include "MacOsWindow.hpp"

#include "Window.hpp"
namespace Barrel
{
    // Function used to create the window
    Window* Window::Create(const WindowProperties& prop)
    {
        return MacOsWindow::Create();
    }
}
