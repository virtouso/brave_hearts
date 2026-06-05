find_package(SDL2 CONFIG REQUIRED)

add_executable(Game)

file(GLOB_RECURSE GAME_SOURCES
    src/*.cpp
)

target_sources(Game PRIVATE ${GAME_SOURCES})


target_link_libraries(Game PRIVATE
    Engine
    SDL2::SDL2
    SDL2::SDL2main
)