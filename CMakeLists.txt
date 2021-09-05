#Clip dependency
# Disable clip examples and tests
set(CLIP_EXAMPLES OFF CACHE BOOL "Compile clip examples")
set(CLIP_TESTS OFF CACHE BOOL "Compile clip tests")
#set(CLIP_X11_PNG_LIBRARY "${PNG_LIBRARY}")
add_subdirectory("third_party/clip")
target_link_libraries(clipboard-uploader clip)