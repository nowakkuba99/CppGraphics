//
//  Static Input Manager
//  Barrel
//
//  Created by Jakub Nowak on 06/01/2023.
//
#include "../../pch/pchBarrel.hpp"

#ifndef Input_hpp
#define Input_hpp
namespace Barrel
{
class Input //Singelton
{
public:
    inline static bool IsKeyPressed(int keycode) { return s_Instance->IsKeyPressedImpl(keycode); }
    inline static bool IsMouseButtonPressed(int button) {return s_Instance->IsMouseButtonPressedImpl(button); }
    inline static float GetMouseX() {return s_Instance->GetMouseXImpl(); }
    inline static float GetMouseY() {return s_Instance->GetMouseYImpl(); }
    inline static std::pair<float, float> GetMouse() {return s_Instance->GetMouseImpl(); }
    
    // Delete clone constructor and assign operator
    Input() = default;
    Input(const Input& copy) = delete;
    void operator=(const Input&) = delete;
protected:
    virtual bool IsKeyPressedImpl(int keycode) = 0; //Full abstract
    virtual bool IsMouseButtonPressedImpl(int button) = 0; //Full abstract
    virtual float GetMouseXImpl() = 0; //Full abstract
    virtual float GetMouseYImpl() = 0; //Full abstract
    virtual std::pair<float, float> GetMouseImpl() = 0;   //Full abstract
    
private:
    static Input* s_Instance;
    
};
}

#endif /* Input_hpp */
