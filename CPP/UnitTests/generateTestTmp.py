# This script must be called inside  G1/C_DataStructure_G1/CPP/UnitTests
import sys

test_name = sys.argv[1]

# -- GENERATE HEADER FILE
header_file = open(test_name+"_test.h", "w")
header_file.write("#ifndef __" + test_name + "_H_\n")
header_file.write("#define __" + test_name + "_H_\n")
header_file.write("TEST(" + test_name + ")\n")
header_file.write("#endif")

# -- GENERATE SOURCE FILE
src_file = open(test_name+"_test.cpp", "w")
src_file.write("#include <iostream>\n")
src_file.write("#include \"SonicTest.h\"\n")
src_file.write("// --- INCLUDE FILE THAT WILL BE TESTED !\n")
src_file.write("#include \"" + test_name + "_test.h\"\n")
src_file.write("// USE NAME SPACE\n")
src_file.write("TEST(" + test_name + ");\n")
src_file.write("{\n")
src_file.write("START_TEST(// test_case_name);\n")


define_test = "\tRUN_TEST(" + test_name + ");\n"
with open("./UnitTests.cpp", "r") as unit_test_file:
    contents = unit_test_file.read()

modified_contents = contents.replace("}", define_test + "}")

with open("./UnitTests.cpp", "w") as unit_test_file:
    unit_test_file.write(modified_contents)
