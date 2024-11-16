g++ backend/*.cpp -o executables/main
diskus executables
strip --strip-unneeded executables/main
diskus executables
./executables/main

