#ifndef C8C03D6F_F08B_4D6F_9257_8992747E277A
#define C8C03D6F_F08B_4D6F_9257_8992747E277A
/*
    Layer stack class - used to mange layers in application
*/

#include "../../pch/pchBarrel.hpp"

#include "Layer.hpp"

namespace Barrel
{
    class LayerStack
    {
    public:
        // Constructor
        LayerStack() = default;
        // Destructor
        ~LayerStack();

        // Member functions
        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);
        void PopLayer(Layer* layer);
        void PopOverlay(Layer* overlay);

        //Functions to return iterators
        inline std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
        inline std::vector<Layer*>::iterator end() { return m_Layers.end(); }

    private:
        // Member definition
        std::vector<Layer*> m_Layers;
        unsigned int m_LayerInsertIndex = 0;
    };
}
#endif /* C8C03D6F_F08B_4D6F_9257_8992747E277A */
