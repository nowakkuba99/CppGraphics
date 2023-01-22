//
//  MacInput.hpp
//  Barrel
//
//  Created by Jakub Nowak on 06/01/2023.
//

#ifndef MacInput_hpp
#define MacInput_hpp

#include "Input.hpp"

namespace Barrel
{
class MacInput : public Input
{
public:
    virtual bool IsKeyPressedImpl(int keycode) override;
    virtual bool IsMouseButtonPressedImpl(int button) override;
    virtual float GetMouseXImpl() override; //Full abstract
    virtual float GetMouseYImpl() override; //Full abstract
    virtual std::pair<float, float> GetMouseImpl() override;   //Full abstract
};
}

#endif /* MacInput_hpp */
