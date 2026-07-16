cmake_minimum_required(VERSION 3.14) # 推荐使用 3.14 以上以完美支持 CONFIGURE_DEPENDS
project(CodingExercises C CXX)

# 设置 C++17 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ==================== 【新增：解决中文乱码问题】 ====================
# 强制编译器（MSVC 或 GCC/Clang）统一使用 UTF-8 编码处理源文件和输出的可执行文件
if(MSVC)
    # 给 MSVC 编译器添加 /utf-8 选项
    add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
    add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
else()
    # 给 GCC/Clang 编译器指定输入和输出字符集为 UTF-8
    add_compile_options(-finput-charset=UTF-8 -fexec-charset=UTF-8)
endif()
# ====================================================================

# 启用 compile_commands.json（用于 clangd 等代码提示工具）
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 统一输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 【核心】递归查找当前源码目录下的所有 .cpp 文件
# CONFIGURE_DEPENDS 会在每次编译前检查文件系统，如果有新增 .cpp 会自动重新 cmake
file(GLOB_RECURSE ALL_SOURCE_FILES
        LIST_DIRECTORIES false
        CONFIGURE_DEPENDS
        "${CMAKE_SOURCE_DIR}/*.cpp"
)

# 过滤掉不需要编译的文件或目录（如 build, .vscode, 隐藏文件夹等）
list(FILTER ALL_SOURCE_FILES EXCLUDE REGEX "/build/|/\\.vscode/|/\\..*")

# 为每个独立的 .cpp 创建可执行文件
foreach(SRC_FILE IN LISTS ALL_SOURCE_FILES)
    # 获取相对路径并计算 MD5，避免不同目录下同名文件冲突
    string(MD5 FILE_HASH "${SRC_FILE}")
    string(SUBSTRING "${FILE_HASH}" 0 8 FILE_HASH_SHORT)
    set(UNIQUE_TARGET_NAME "exe_${FILE_HASH_SHORT}")

    add_executable("${UNIQUE_TARGET_NAME}" "${SRC_FILE}")
endforeach()

# 打印调试信息
list(LENGTH ALL_SOURCE_FILES TOTAL_COUNT)
message(STATUS "🚀 Total targets created: ${TOTAL_COUNT}")