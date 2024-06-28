from conan import ConanFile
from conan.tools.build import check_min_cppstd
from conan.tools.cmake import cmake_layout


class CompressorRecipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"

    def validate(self):
        check_min_cppstd(self, 20)

    def layout(self):
        cmake_layout(self)

    def requirements(self):
        # toggle off all switches
        # you can turn on for further experiments
        self.requires("instinct-cpp/0.1.5", options={
            "with_pdfium": False,
            "with_duckx": False,
            "with_exprtk": False,
            "with_duckdb": False,
            "with_tests": False
        })

