#include "../../pch/pchBarrel.hpp"

#include "LayerStack.hpp"

namespace Barrel
{
    // Constructor - default
    // Destructor
    LayerStack::~LayerStack()
    {
        for(auto layer: m_Layers)
        {
            layer->OnDetach();
            delete layer;   //Delete all layers
        }
    }
    // Member functions
    void LayerStack::PushLayer(Layer* layer)
    {
        m_Layers.emplace(m_Layers.begin() + m_LayerInsertIndex, layer);
        m_LayerInsertIndex++;
    }

    void LayerStack::PushOverlay(Layer* overlay)
    {
        m_Layers.emplace_back(overlay);
    }

    void LayerStack::PopLayer(Layer* layer)
    {
        auto it = std::find(m_Layers.begin(),m_Layers.begin() + m_LayerInsertIndex,layer);
        if(it != m_Layers.begin() + m_LayerInsertIndex)
        {
            layer->OnDetach();
            m_Layers.erase(it);
            m_LayerInsertIndex--;
        }
    }

    void LayerStack::PopOverlay(Layer* overlay)
    {
        auto it = std::find(m_Layers.begin() + m_LayerInsertIndex,m_Layers.end(),overlay);
        if(it != m_Layers.end())
        {
            overlay->OnDetach();
            m_Layers.erase(it);
        }
    }

}