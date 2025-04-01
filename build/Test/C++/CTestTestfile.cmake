# CMake generated Testfile for 
# Source directory: C:/Users/19513/Desktop/cmake/Test/C++
# Build directory: C:/Users/19513/Desktop/cmake/build/Test/C++
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_add "C:/Users/19513/Desktop/cmake/build/Test/C++/test_add.exe")
set_tests_properties(test_add PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/19513/Desktop/cmake/Test/C++/CMakeLists.txt;32;add_test;C:/Users/19513/Desktop/cmake/Test/C++/CMakeLists.txt;0;")
add_test(test_del "C:/Users/19513/Desktop/cmake/build/Test/C++/test_del.exe")
set_tests_properties(test_del PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/19513/Desktop/cmake/Test/C++/CMakeLists.txt;33;add_test;C:/Users/19513/Desktop/cmake/Test/C++/CMakeLists.txt;0;")
subdirs("../../thirdpart/googletest")
