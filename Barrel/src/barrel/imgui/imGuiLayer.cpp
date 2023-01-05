#include "../../pch/pchBarrel.hpp"
#include "ImGuiLayer.hpp"

#include <imgui.h>
#include <backends/imgui_impl_opengl3.h>
#include <backends/imgui_impl_glfw.h>


#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../core/application.hpp"


/* ---------- MACROS ------------ */
#define BR_BIND_EVENT_FN(fn) std::bind(&fn,this,std::placeholders::_1)

namespace Barrel
{
// Constructor
ImGuiLayer::ImGuiLayer()
    : Layer("ImGuiLayer") {}
// On attach function
void ImGuiLayer::OnAttach()
{
    // Setup ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();   (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

    // Setup ImGui style
    ImGui::StyleColorsDark();

    SetDarkThemeColors();

    Application& app = Application::Get();
    GLFWwindow* window = static_cast<GLFWwindow*>(app.GetWindow().GetNativeWindow());

    // Setup Platform/Renderer bindings
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 410");
}

void ImGuiLayer::OnUpdate()
{
    ImGuiIO& io = ImGui::GetIO();
    Application& app = Application::Get();
    io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

    float time = (float)glfwGetTime();
    io.DeltaTime = m_Time > 0.0f ? (time - m_Time) : (1.0f / 60.0f);
    m_Time = time;

    ImGui_ImplOpenGL3_NewFrame();
    ImGui::NewFrame();

    static bool show = true;
    ImGui::ShowDemoWindow(&show);

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
/* Temporary */

void ImGuiLayer::OnEvent(Event& event)
{
    EventDispatcher dispatcher{event};
    dispatcher.dispatch<MouseButtonPressedEvent>(BR_BIND_EVENT_FN(ImGuiLayer::OnMouseButtonPressedEvent));
    dispatcher.dispatch<MouseButtonReleasedEvent>(BR_BIND_EVENT_FN(ImGuiLayer::OnMouseButtonReleasedEvent));
    dispatcher.dispatch<MouseMovedEvent>(BR_BIND_EVENT_FN(ImGuiLayer::OnMouseMovedEvent));
    dispatcher.dispatch<MouseScrolledEvent>(BR_BIND_EVENT_FN(ImGuiLayer::OnMouseScrolledEvent));
    dispatcher.dispatch<KeyPressedEvent>(BR_BIND_EVENT_FN(ImGuiLayer::OnKeyPressedEvent));
    dispatcher.dispatch<KeyTypedEvent>(BR_BIND_EVENT_FN(ImGuiLayer::OnKeyTypedEvent));
    dispatcher.dispatch<KeyReleasedEvent>(BR_BIND_EVENT_FN(ImGuiLayer::OnKeyReleasedEvent));
    dispatcher.dispatch<WindowResizeEvent>(BR_BIND_EVENT_FN(ImGuiLayer::OnWindowResizeEvent));
}

bool ImGuiLayer::OnMouseButtonPressedEvent(MouseButtonPressedEvent& e)
{
    ImGuiIO& io = ImGui::GetIO();
    io.MouseDown[e.GetMouseButton()] = true;

    return false;
}

bool ImGuiLayer::OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e)
{
    ImGuiIO& io = ImGui::GetIO();
    io.MouseDown[e.GetMouseButton()] = false;

    return false;
}

bool ImGuiLayer::OnMouseMovedEvent(MouseMovedEvent& e)
{
    ImGuiIO& io = ImGui::GetIO();
    io.MousePos = ImVec2(e.getX(), e.getY());

    return false;
}

bool ImGuiLayer::OnMouseScrolledEvent(MouseScrolledEvent& e)
{
    ImGuiIO& io = ImGui::GetIO();
    io.MouseWheelH += e.GetXOffset();
    io.MouseWheel += e.GetYOffset();

    return false;
}

bool ImGuiLayer::OnKeyPressedEvent(KeyPressedEvent& e)
{
    ImGuiIO& io = ImGui::GetIO();
    io.KeysDown[e.GetKeyCode()] = true;

    io.KeyCtrl = io.KeysDown[GLFW_KEY_LEFT_CONTROL] || io.KeysDown[GLFW_KEY_RIGHT_CONTROL];
    io.KeyShift = io.KeysDown[GLFW_KEY_LEFT_SHIFT] || io.KeysDown[GLFW_KEY_RIGHT_SHIFT];
    io.KeyAlt = io.KeysDown[GLFW_KEY_LEFT_ALT] || io.KeysDown[GLFW_KEY_RIGHT_ALT];
    io.KeySuper = io.KeysDown[GLFW_KEY_LEFT_SUPER] || io.KeysDown[GLFW_KEY_RIGHT_SUPER];
    return false;
}

bool ImGuiLayer::OnKeyReleasedEvent(KeyReleasedEvent& e)
{
    ImGuiIO& io = ImGui::GetIO();
    io.KeysDown[e.GetKeyCode()] = false;

    return false;
}

//bool ImGuiLayer::OnKeyTypedEvent(KeyTypedEvent& e)
//{
//    ImGuiIO& io = ImGui::GetIO();
//    int keycode = e.GetKeyCode();
//    if (keycode > 0 && keycode < 0x10000)
//        io.AddInputCharacter((unsigned short)keycode);
//
//    return false;
//}

bool ImGuiLayer::OnWindowResizeEvent(WindowResizeEvent& e)
{
    ImGuiIO& io = ImGui::GetIO();
    io.DisplaySize = ImVec2(e.getWidth(), e.getHeight());
    io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
    glViewport(0, 0, e.getWidth(), e.getHeight());

    return false;
}

};
