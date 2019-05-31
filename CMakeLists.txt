cmake_minimum_required(VERSION 2.6)

set(sources
   ${SOURCE}
   ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/Single_linked_list.cpp
)
set(headers
   ${HEADERS}
   ${CMAKE_CURRENT_SOURCE_DIR}/Single_linked_list.h
)
add_executable(Linked_list ${sources} ${headers})
