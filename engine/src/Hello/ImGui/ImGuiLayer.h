#pragma once

#include "Hello/Layer.h"

#include "Hello/Events/MouseEvent.h"
#include "Hello/Events/KeyEvent.h"
#include "Hello/Events/ApplicationEvent.h"

namespace Hello {
	class HELLO_API ImGuiLayer : public Layer {
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

	private:
		float m_Time = 0.0f;
	};
}