set(SRC_FILES
    ssd1306.c
    RVgeneral.c
    RVsketches.c
)

target_sources(${PROJECT_NAME} PRIVATE
    ${SRC_FILES}    
)