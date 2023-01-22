#ifndef AC0B7E66_0458_42D5_8EA2_686A16790D94
#define AC0B7E66_0458_42D5_8EA2_686A16790D94

#include "../layers/Layer.hpp"

#include "../events/ApplicationEvent.hpp"
#include "../events/KeyEvent.hpp"
#include "../events/MouseEvent.hpp"

#define GL_SILENCE_DEPRECATION

namespace Barrel
{
class ImGuiLayer : public Layer
{
public:
    // Constructor
    ImGuiLayer();
    //Destructor
    ~ImGuiLayer() = default;

    // Virtual functions
    virtual void OnAttach() override;
    virtual void OnDetach() override;
    virtual void OnEvent(Event& event) override;
    virtual void OnImGuiRender() override;

    // Other functions
    void Begin();
    void End();

    void BlockEvents(bool block) { m_BlockEvents = block; }

    void SetDarkThemeColors();
private:
    // Member variables
    bool m_BlockEvents;
};
}


#endif /* AC0B7E66_0458_42D5_8EA2_686A16790D94 */
