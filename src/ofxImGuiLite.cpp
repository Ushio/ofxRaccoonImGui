#include "ofxImguiLite.hpp"

#include "ofMain.h"
#include <GLFW/glfw3.h>
#include "imgui_impl_glfw_gl2.h"
#include "imgui_impl_glfw_gl3.h"

namespace {
	GLFWmousebuttonfun of_GLFWmousebuttonfun;
	void ofxImguiLite_MouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
		of_GLFWmousebuttonfun(window, button, action, mods);
		if (ofIsGLProgrammableRenderer()) {
			ImGui_ImplGlfw_MouseButtonCallback_GL3(window, button, action, mods);
		}
		else {
			ImGui_ImplGlfw_MouseButtonCallback(window, button, action, mods);
		}
	}

	GLFWscrollfun of_GLFWscrollfun;
	void ofxImguiLite_ScrollCallback(GLFWwindow* window, double xoffset, double yoffset) {
		of_GLFWscrollfun(window, xoffset, yoffset);
		if (ofIsGLProgrammableRenderer()) {
			ImGui_ImplGlfw_ScrollCallback_GL3(window, xoffset, yoffset);
		}
		else {
			ImGui_ImplGlfw_ScrollCallback(window, xoffset, yoffset);
		}
	}

	GLFWkeyfun of_GLFWkeyfun;
	void ofxImguiLite_KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
		of_GLFWkeyfun(window, key, scancode, action, mods);

		if (ofIsGLProgrammableRenderer()) {
			ImGui_ImplGlfw_KeyCallback_GL3(window, key, scancode, action, mods);
		}
		else {
			ImGui_ImplGlfw_KeyCallback(window, key, scancode, action, mods);
		}
	}

	GLFWcharfun of_GLFWcharfun;
	void ofxImguiLite_ImplGlfw_CharCallback(GLFWwindow* window, unsigned int c) {
		of_GLFWcharfun(window, c);
		if (ofIsGLProgrammableRenderer()) {
			ImGui_ImplGlfw_CharCallback_GL3(window, c);

		}
		else {
			ImGui_ImplGlfw_CharCallback(window, c);
		}
	}
}

namespace ofxImGuiLite {
	void initialize() {
		ImGui::CreateContext();

		ImGuiIO& io = ImGui::GetIO();
		io.IniFilename = nullptr;

		ofAppGLFWWindow *window = dynamic_cast<ofAppGLFWWindow *>(ofGetWindowPtr());
		GLFWwindow *glfwWindow = window->getGLFWWindow();

		if (ofIsGLProgrammableRenderer()) {
			ImGui_ImplGlfwGL3_Init(glfwWindow, false);
		}
		else {
			ImGui_ImplGlfwGL2_Init(glfwWindow, false);
		}

		of_GLFWmousebuttonfun = glfwSetMouseButtonCallback(glfwWindow, ofxImguiLite_MouseButtonCallback);
		of_GLFWscrollfun = glfwSetScrollCallback(glfwWindow, ofxImguiLite_ScrollCallback);
		of_GLFWkeyfun = glfwSetKeyCallback(glfwWindow, ofxImguiLite_KeyCallback);
		of_GLFWcharfun = glfwSetCharCallback(glfwWindow, ofxImguiLite_ImplGlfw_CharCallback);
	}
	void shutdown() {
		if (ofIsGLProgrammableRenderer()) {
			ImGui_ImplGlfwGL3_Shutdown();
		}
		else {
			ImGui_ImplGlfwGL2_Shutdown();
		}
		ImGui::DestroyContext();
	}
	void beginGui() {
		if (ofIsGLProgrammableRenderer()) {
			ImGui_ImplGlfwGL3_NewFrame();
		}
		else {
			ImGui_ImplGlfwGL2_NewFrame();
		}
	}
	void endGui() {
		ImGui::Render();
		if (ofIsGLProgrammableRenderer()) {
			ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());
		}
		else {
			ImGui_ImplGlfwGL2_RenderDrawData(ImGui::GetDrawData());
		}
	}
}