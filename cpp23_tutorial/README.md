# link
- [C++23: An Overview of Almost All New and Updated Features - Marc Gregoire - CppCon 2023 | CppCon](https://youtu.be/Cttb8vMuq-Y?si=rJqfyv4sog3OHum9)
- [Elevating Precision in C++ - A Journey Below the Surface of Floating-Point - Tom Tesch - C++ on Sea  | cpponsea](https://youtu.be/Kftvt_l8wsQ?si=iCRSaADi1KbGm5Iv)

<hr />

# C++23 Deducing this And Functional Programming | IQ95 The Homo Dawkins

https://youtube.com/playlist?list=PLsIvhalfft1FYthrH9HtlS_v_mpUM5JPL&si=0JbsArZ9WZVP_8AB

# Compile(C++23)
- https://github.com/llvm/llvm-project/issues/57104

```bash
$ clang++ -std=c++2b -stdlib=libc++ -nostdinc++ -I /usr/include/c++/20 -I /usr/include/x86_64-unknown-linux-gnu/c++/20 -L /usr/lib -Wl,-rpath,/usr/lib
 src/main.cpp
```

<hr />



# justfile

```justfile
# which g++ 
gpp_which := `which g++`

# Source and target directories
src_dir := "./src"
target_dir := "./target"

# Files
source := src_dir+"/main.cpp"
target := target_dir+"/main"

# Common flags
ldflags_common := "-std=c++2b -pedantic -pthread -pedantic-errors -lm -Wall -Wextra -ggdb"
ldflags_debug := "-c -std=c++2b -pthread -lm -Wall -Wextra -ggdb"
ldflags_emit_llvm := "-S -emit-llvm"
ldflags_assembly := "-Wall -save-temps"
ldflags_fsanitize_address := "-O1 -g -fsanitize=address -fno-omit-frame-pointer -c"
ldflags_fsanitize_object := "-g -fsanitize=address"
ldflags_fsanitize_valgrind := "-fsanitize=address -g3 -std=c++2b"

# g++ compile
r:
	rm -rf target
	mkdir -p target
	g++ {{ldflags_common}} -o {{target}} {{source}}
	{{target}}

# zig c++ compile
zr:
	rm -rf target
	mkdir -p target
	zig c++ {{ldflags_common}} -o {{target}} {{source}}
	{{target}}

# g++ build
b:
	rm -rf target
	mkdir -p target
	g++ {{ldflags_debug}} -o {{target}} {{source}}

# clang++ LLVM emit-file
ll:
	rm -rf target
	mkdir -p target
	cp -rf {{src_dir}}/main.cpp ./
	clang++ {{ldflags_emit_llvm}} main.cpp
	mv *.ll {{target_dir}}
	clang++ {{ldflags_common}} -o {{target}} {{source}}
	mv *.cpp {{target_dir}}
	rm -rf *.out

# Assembly emit-file
as:
	rm -rf target
	mkdir -p target
	g++ {{ldflags_assembly}} -o {{target}} {{source}}
	mv *.ii {{target_dir}}
	mv *.o {{target_dir}}
	mv *.s {{target_dir}}
	mv *.bc {{target_dir}}

# clang++ fsanitize_address
fsan:
	rm -rf target
	mkdir -p target
	clang++ {{ldflags_fsanitize_address}} {{source}} -o {{target}}
	clang++ {{ldflags_fsanitize_object}} {{target}}
	mv *.out {{target_dir}}

# leak memory check(valgrind)
mem:
	rm -rf target
	mkdir -p target
	g++ {{ldflags_fsanitize_valgrind}} {{source}} -o {{target}}
	valgrind --leak-check=full {{target}}

# object file emit-file
obj:
	rm -rf target
	mkdir -p target
	g++ {{ldflags_assembly}} -o {{target}} {{source}}
	mv *.ii {{target_dir}}
	mv *.o {{target_dir}}
	mv *.s {{target_dir}}
	mv *.bc {{target_dir}}
	objdump --disassemble -S -C {{target_dir}}/main.o

# hex view
xx:
	rm -rf target
	mkdir -p target
	g++ {{ldflags_fsanitize_valgrind}} {{source}} -o {{target}}
	xxd -c 16 {{target}}

# clean files
clean:
	rm -rf {{target_dir}} *.out {{src_dir}}/*.out *.bc {{src_dir}}/target/ *.dSYM {{src_dir}}/*.dSYM *.i *.o *.s

# C++ init
init:
	mkdir -p src
	echo '#include <iostream>' > src/main.cpp
	echo '' >> src/main.cpp
	echo 'int main() {' >> src/main.cpp
	echo '    std::cout << "Hello C++" << std::endl;' >> src/main.cpp
	echo '    return 0;' >> src/main.cpp
	echo '}' >> src/main.cpp

# C++ init(int argc, char **argv)
init2:
	mkdir -p src
	echo '#include <iostream>' > src/main.cpp
	echo '' >> src/main.cpp
	echo 'int main(int argc, char **argv) {' >> src/main.cpp
	echo '    std::cout << "Hello C++" << std::endl;' >> src/main.cpp
	echo '    return 0;' >> src/main.cpp
	echo '}' >> src/main.cpp

# Debugging(VSCode)
vscode:
	rm -rf .vscode
	mkdir -p .vscode
	echo '{' > .vscode/launch.json
	echo '    "version": "0.2.0",' >> .vscode/launch.json
	echo '    "configurations": [' >> .vscode/launch.json
	echo '        {' >> .vscode/launch.json
	echo '            "type": "lldb",' >> .vscode/launch.json
	echo '            "request": "launch",' >> .vscode/launch.json
	echo '            "name": "Launch",' >> .vscode/launch.json
	echo '            "program": "${workspaceFolder}/target/${fileBasenameNoExtension}",' >> .vscode/launch.json
	echo '            "args": [],' >> .vscode/launch.json
	echo '            "cwd": "${workspaceFolder}",' >> .vscode/launch.json
	echo '            // "preLaunchTask": "C/C++: clang build active file"' >> .vscode/launch.json
	echo '        },' >> .vscode/launch.json
	echo '        {' >> .vscode/launch.json
	echo '            "name": "gcc - Build and debug active file",' >> .vscode/launch.json
	echo '            "type": "cppdbg",' >> .vscode/launch.json
	echo '            "request": "launch",' >> .vscode/launch.json
	echo '            "program": "${fileDirname}/target/${fileBasenameNoExtension}",' >> .vscode/launch.json
	echo '            "args": [],' >> .vscode/launch.json
	echo '            "stopAtEntry": false,' >> .vscode/launch.json
	echo '            "cwd": "${fileDirname}",' >> .vscode/launch.json
	echo '            "environment": [],' >> .vscode/launch.json
	echo '            "externalConsole": false,' >> .vscode/launch.json
	echo '            "MIMode": "lldb",' >> .vscode/launch.json
	echo '            // "tasks": "C/C++: clang build active file"' >> .vscode/launch.json
	echo '        }' >> .vscode/launch.json
	echo '    ]' >> .vscode/launch.json
	echo '}' >> .vscode/launch.json
	echo '{' > .vscode/tasks.json
	echo '    "tasks": [' >> .vscode/tasks.json
	echo '        {' >> .vscode/tasks.json
	echo '            "type": "cppbuild",' >> .vscode/tasks.json
	echo '            "label": "C/C++: clang build active file",' >> .vscode/tasks.json
	echo '            "command": "{{gpp_which}}",' >> .vscode/tasks.json
	echo '            "args": [' >> .vscode/tasks.json
	echo '                "-fcolor-diagnostics",' >> .vscode/tasks.json
	echo '                "-fansi-escape-codes",' >> .vscode/tasks.json
	echo '                "-g",' >> .vscode/tasks.json
	echo '                "${file}",' >> .vscode/tasks.json
	echo '                "-o",' >> .vscode/tasks.json
	echo '                "${fileDirname}/target/${fileBasenameNoExtension}"' >> .vscode/tasks.json
	echo '            ],' >> .vscode/tasks.json
	echo '            "options": {' >> .vscode/tasks.json
	echo '                "cwd": "${fileDirname}"' >> .vscode/tasks.json
	echo '            },' >> .vscode/tasks.json
	echo '            "problemMatcher": [' >> .vscode/tasks.json
	echo '                "$gcc"' >> .vscode/tasks.json
	echo '            ],' >> .vscode/tasks.json
	echo '            "group": {' >> .vscode/tasks.json
	echo '                "kind": "build",' >> .vscode/tasks.json
	echo '                "isDefault": true' >> .vscode/tasks.json
	echo '            },' >> .vscode/tasks.json
	echo '            "detail": "Task generated by Debugger."' >> .vscode/tasks.json
	echo '        }' >> .vscode/tasks.json
	echo '    ],' >> .vscode/tasks.json
	echo '    "version": "2.0.0"' >> .vscode/tasks.json
	echo '}' >> .vscode/tasks.json
```

# 250719_C++ FINALLY Improved Error Handling with std::expected! | The Cherno
- https://youtu.be/Vz40rDiWnN8?si=lTZlVwWuJ7l0mPtV

- https://godbolt.org/

```
x86-64 clang 20.1.0

-std=c++23
```

