#include "hopch.h"
#include "Layer.h"

namespace Hello {
	Layer::Layer(const std::string& debugName): m_DebugName(debugName) {}
	Layer::~Layer() {}
}