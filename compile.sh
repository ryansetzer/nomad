g++ backend/*.cpp -o executables/main                # Base Compile
g++ io/testing/*.cpp -o executables/display-test     # Base Compile
diskus executables                                   # Print Executable Original Size
strip --strip-unneeded executables/main              # Strip Executable of Non-Needed Libraries
strip --strip-unneeded executables/display-test      # Strip Executable of Non-Needed Libraries
diskus executables                                   # Print Executable New Size

