set(CHAPTER ch01)

# 自动为本目录下的每个 cpp 文件生成一个可执行文件
file(GLOB CH01_SOURCES CONFIGURE_DEPENDS *.cpp)

foreach(src ${CH01_SOURCES})
    # 从文件名中提取可执行文件名
    get_filename_component(exe_name ${src} NAME_WE)

    add_executable(${CHAPTER}_${exe_name} ${src})

    target_include_directories(${CHAPTER}_${exe_name}
        PRIVATE
            ${PROJECT_SOURCE_DIR}/include
    )
endforeach()
