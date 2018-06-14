#pragma once
#include <imgui.h>

// is window focused

namespace ofxImGuiLite {
	void initialize();
	void shutdown();

	void beginGui();
	void endGui();

	class ScopedImGui {
	public:
		ScopedImGui() { beginGui(); }
		~ScopedImGui() { endGui(); }

		ScopedImGui(const ScopedImGui&) = delete;
		void operator=(const ScopedImGui&) = delete;
	};
}