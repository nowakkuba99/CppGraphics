#ifndef CD913670_9C20_47A3_80C3_5B3D9F4B76C9
#define CD913670_9C20_47A3_80C3_5B3D9F4B76C9
/*
    Layer class used in layer stack
*/
#include "../../pch/pchBarrel.hpp"
#include "../events/Event.hpp"

namespace Barrel
{
    class Layer
    {
    public:
        // Constructor
        Layer(const std::string& name = "Layer") : m_DebugName(name) {}
        // Destructor - virtual since the class will be derived
        virtual ~Layer() = default;

        // Virtual member functions
        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate() {}
        virtual void OnImGuiRender() {}
        virtual void OnEvent(Event& event) {}

        // Other functions
        inline const std::string& GetName() const { return m_DebugName; }
    protected:
        // Member declaration
        std::string m_DebugName;
    };
}

#endif /* CD913670_9C20_47A3_80C3_5B3D9F4B76C9 */
