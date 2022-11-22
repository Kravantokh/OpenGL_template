link_libraries(gl3w glfw bu_glw)

add_executable(minimal_triangle ${CMAKE_CURRENT_SOURCE_DIR}/minimal_triangle/minimal_triangle.cpp)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/minimal_triangle/basic_vertex_shader.glsl basic_vertex_shader.glsl COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/minimal_triangle/basic_fragment_shader.glsl basic_fragment_shader.glsl COPYONLY)

add_executable(uniform_api ${CMAKE_CURRENT_SOURCE_DIR}/uniform_api/uniform_api.cpp)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/uniform_api/uniform_vertex_shader.glsl uniform_vertex_shader.glsl COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/uniform_api/uniform_fragment_shader.glsl uniform_fragment_shader.glsl COPYONLY)

add_executable(cubic_bezier ${CMAKE_CURRENT_SOURCE_DIR}/cubic_bezier/cubic_bezier.cpp)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cubic_bezier/cubic_bezier_gs.glsl cubic_bezier_gs.glsl COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cubic_bezier/cubic_bezier_vs.glsl cubic_bezier_vs.glsl COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cubic_bezier/cubic_bezier_fs.glsl cubic_bezier_fs.glsl COPYONLY)
