add_requires("raylib")

target("synth")
    set_kind("binary")
    set_languages("cxx11")
    add_files("src/*.cpp")
    add_packages("raylib")
