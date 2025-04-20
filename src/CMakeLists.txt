set(SRC_FILES
    ssd1306.c
    RVgeneral.c
)

target_sources(${PROJECT_NAME} PRIVATE
    ${SRC_FILES}    
)