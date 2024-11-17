g++ backend/*.cpp -o executables/main     # Base Compile
diskus executables                        # Print Executable Original Size
strip --strip-unneeded executables/main   # Strip Executable of Non-Needed Libraries
diskus executables                        # Print Executable New Size
./executables/main                        # Run

