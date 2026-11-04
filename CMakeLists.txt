cmake_minimum_required(VERSION 3.16)
project(semester_one LANGUAGES CXX)

# Keep GNU extensions for the original variable-length arrays.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

foreach(program IN ITEMS
    byrokraticky_aparat
    misto_pro_zraz
    pocet_inverzi_v_permutaci
    prunik_cest_ve_stromu
    skladani_krabic
    skladani_krabic2
    studentuv_rozvrh
    theseus_a_minotauros
    zasobovaci_strediska
    zasobovaci_strediska2)
    add_executable(${program} ${program}.cpp)
endforeach()
