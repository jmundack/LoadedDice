file(GLOB SOURCES *.h *.cpp)

add_executable(LoadedDice ${SOURCES})
#target_link_libraries(UC${test} ${LIBRARIES})
install(TARGETS LoadedDice RUNTIME DESTINATION bin)
