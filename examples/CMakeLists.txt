link_libraries(gl3w glfw bu_glw)

add_executable(minimal_triangle minimal_triangle.cpp)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/basic_vertex_shader.glsl basic_vertex_shader.glsl COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/basic_fragment_shader.glsl basic_fragment_shader.glsl COPYONLY)

add_executable(uniform_api uniform_api.cpp)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/uniform_vertex_shader.glsl uniform_vertex_shader.glsl COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/uniform_fragment_shader.glsl uniform_fragment_shader.glsl COPYONLY)
