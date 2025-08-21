add_executable(${PROJECT_NAME}
    camerawidget.cpp
    mainwindow.cpp
    main.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE 
    Qt6::Widgets
    Qt6::Multimedia
    Qt6::MultimediaWidgets
    ads::qtadvanceddocking-qt6
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)