add_executable(${PROJECT_NAME}
    mainwindow.cpp
    main.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE 
    Qt6::Widgets
    ads::qtadvanceddocking-qt6
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)