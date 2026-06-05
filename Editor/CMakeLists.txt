add_executable(Editor)

file(GLOB_RECURSE EDITOR_SOURCES
    src/*.cpp
)

target_sources(Editor PRIVATE ${EDITOR_SOURCES})


target_link_libraries(Editor PRIVATE Engine)