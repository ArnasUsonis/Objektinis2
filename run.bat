cmake CMakeLists.txt
cmake --install .
cmake --build .
copy src\studentai.txt Debug\studentai.txt
cd Debug\
Work_with_Files.exe
pause