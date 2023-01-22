//
//  MacInput.cpp
//  Barrel
//
//  Created by Jakub Nowak on 06/01/2023.
//
#include "../../pch/pchBarrel.hpp"
#include "MacInput.hpp"
#include "Application.hpp"


namespace Barrel
{
// Initialize Input object
Input* Input::s_Instance = new MacInput();
// Keyboard
bool MacInput::IsKeyPressedImpl(int keycode)
{
    auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
    auto state = glfwGetKey(window, keycode);
    return state == GLFW_PRESS || state == GLFW_REPEAT;
}
// Mouse
bool MacInput::IsMouseButtonPressedImpl(int button)
{
    auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
    auto state = glfwGetMouseButton(window, button);
    return state == GLFW_PRESS;
}

float MacInput::GetMouseXImpl()
{
    auto [x,y] = GetMouseImpl();
    return x;
}

float MacInput::GetMouseYImpl()
{
    auto [x,y] = GetMouseImpl();
    return y;
}

std::pair<float, float> MacInput::GetMouseImpl()
{
    auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    return {(float)xpos,(float)ypos};
}



};
