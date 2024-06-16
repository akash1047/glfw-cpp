#ifndef GLFW_CPP_GLFW_HPP
#define GLFW_CPP_GLFW_HPP

#include <memory>
#define GLFW_INCLUDE_NONE

#include <GLFW/glfw3.h>

namespace glfw {

void PRINT_ON_ERROR(int error, const char *description);

inline bool init() {
    return glfwInit();
}

inline bool init(GLFWerrorfun err) {
    glfwSetErrorCallback(err);
    return glfwInit();
}

inline void terminate() {
    glfwTerminate();
}

inline void poll_events() {
    glfwPollEvents();
}

class window
    : public std::unique_ptr<GLFWwindow, decltype(&glfwDestroyWindow)> {

    public:
    window(GLFWwindow *ptr)
        : std::unique_ptr<GLFWwindow, decltype(&glfwDestroyWindow)>(
              ptr, glfwDestroyWindow) {}

    window(int width, int height, const char *title, GLFWmonitor *monitor,
           GLFWwindow *share)
        : std::unique_ptr<GLFWwindow, decltype(&glfwDestroyWindow)>(
              glfwCreateWindow(width, height, title, monitor, share),
              glfwDestroyWindow) {}

    inline void swap_buffers() {
        glfwSwapBuffers(get());
    }

    inline void make_context_current() {
        glfwMakeContextCurrent(get());
    }

    inline bool should_close() {
        return glfwWindowShouldClose(get());
    }

    inline void set_should_close(bool value) {
        glfwSetWindowShouldClose(get(), value);
    }

    window(const window &) = delete;
    window &operator=(const window &) = delete;

    window(window &&) = default;
    window &operator=(window &&) = default;
};

enum class ClientApi {
    NoApi = GLFW_NO_API,
    OpenGl = GLFW_OPENGL_API,
    OpenGlEs = GLFW_OPENGL_ES_API
};

enum class OpenglVersion {
    v1_0 = 10,
    v1_1 = 11,
    v1_2 = 12,
    v1_3 = 13,
    v1_4 = 14,
    v1_5 = 15,
    v2_0 = 20,
    v2_1 = 21,
    v3_0 = 30,
    v3_1 = 31,
    v3_2 = 32,
    v3_3 = 33,
    v4_0 = 40,
    v4_1 = 41,
    v4_2 = 42,
    v4_3 = 43,
    v4_4 = 44,
    v4_5 = 45,
    v4_6 = 46
};

enum class OpenglEsVersion {
    v1_0 = 10,
    v1_1 = 11,
    v2_0 = 20,
    v3_0 = 30,
    v3_1 = 31,
    v3_2 = 32
};

namespace hint {

inline void client_api(ClientApi api) {
    glfwWindowHint(GLFW_CLIENT_API, static_cast<int>(api));
}

inline void context_version(OpenglVersion version) {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, static_cast<int>(version) / 10);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, static_cast<int>(version) % 10);
}

inline void context_version(OpenglEsVersion version) {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, static_cast<int>(version) / 10);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, static_cast<int>(version) % 10);
}

inline void resizable(bool value) {
    glfwWindowHint(GLFW_RESIZABLE, value);
}

inline void visible(bool value) {
    glfwWindowHint(GLFW_VISIBLE, value);
}

inline void decorated(bool value) {
    glfwWindowHint(GLFW_DECORATED, value);
}

inline void focused(bool value) {
    glfwWindowHint(GLFW_FOCUSED, value);
}

inline void auto_iconify(bool value) {
    glfwWindowHint(GLFW_AUTO_ICONIFY, value);
}

inline void floating(bool value) {
    glfwWindowHint(GLFW_FLOATING, value);
}

inline void maximized(bool value) {
    glfwWindowHint(GLFW_MAXIMIZED, value);
}

inline void center_cursor(bool value) {
    glfwWindowHint(GLFW_CENTER_CURSOR, value);
}

inline void transparent_framebuffer(bool value) {
    glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, value);
}

inline void focus_on_show(bool value) {
    glfwWindowHint(GLFW_FOCUS_ON_SHOW, value);
}

inline void scale_to_monitor(bool value) {
    glfwWindowHint(GLFW_SCALE_TO_MONITOR, value);
}

} // namespace hint

inline window create_window(int width, int height, const char *title) {
    return window(width, height, title, nullptr, nullptr);
}

} // namespace glfw

#endif // GLFW_CPP_GLFW_HPP
