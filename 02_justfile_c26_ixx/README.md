# Result
- `just br`

```bash
$ just br

rm -rf target gcm.cache
mkdir -p target
/opt/gcc-15/bin/g++ -std=c++26 -pedantic -pthread -pedantic-errors -lm -Wall -Wextra -ggdb -fmodules-ts -c ./src/ixx_module/add_module.ixx -o target/add_module.o
/opt/gcc-15/bin/g++ -std=c++26 -pedantic -pthread -pedantic-errors -lm -Wall -Wextra -ggdb -fmodules-ts -c ./src/main.cpp -o target/main.o
/opt/gcc-15/bin/g++ -std=c++26 -pedantic -pthread -pedantic-errors -lm -Wall -Wextra -ggdb -fmodules-ts target/main.o target/add_module.o -o ./target/main
mv gcm.cache target/
./target/main


c26 hello world
2 + 5 = 7
c26 style : 2+ 5 = 7

```


# justfile(C++ & ixx include)

```justfile
# which g++ (c23 + 26)
gpp_which := "/opt/gcc-15/bin/g++"
clang_which := "/usr/bin/clang++-20"

# Source and target directories
src_dir := "./src"
target_dir := "target"

# Files
source := src_dir+"/main.cpp"
target := "./"+target_dir+"/main"
module_source := src_dir+"/ixx_module/add_module.ixx"
module_target := target_dir+"/add_module.o"
main_target := target_dir+"/main.o"


# Common flags
ldflags_common := "-std=c++26 -pedantic -pthread -pedantic-errors -lm -Wall -Wextra -ggdb"
ldflags_common_clang := "-std=c++23 -pedantic -pthread -pedantic-errors -lm -Wall -Wextra -ggdb"
ldflags_debug := "-c -std=c++2b -pthread -lm -Wall -Wextra -ggdb"
ldflags_emit_llvm := "-S -emit-llvm"
ldflags_assembly := "-Wall -save-temps"
ldflags_fsanitize_address := "-O1 -g -fsanitize=address -fno-omit-frame-pointer -c"
ldflags_fsanitize_object := "-g -fsanitize=address"
ldflags_fsanitize_valgrind := "-fsanitize=address -g3 -std=c++2b"

# fmt
fmt_flags := ". -regex '.*\\.\\(cpp\\|hpp\\|cc\\|cxx\\|c\\|h\\)' -exec clang-format -style=file -i {} \\;"

# g++ compile
r:
	rm -rf target
	mkdir -p target
	{{gpp_which}} {{ldflags_common}} -o {{target}} {{source}}
	{{target}}

# g++ compile with modules
br:
    rm -rf target gcm.cache
    mkdir -p target
    {{gpp_which}} {{ldflags_common}} -fmodules-ts -c {{module_source}} -o {{module_target}}
    {{gpp_which}} {{ldflags_common}} -fmodules-ts -c {{source}} -o {{main_target}}
    {{gpp_which}} {{ldflags_common}} -fmodules-ts {{main_target}} {{module_target}} -o {{target}}
    mv gcm.cache {{target_dir}}/
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
	{{gpp_which}} {{ldflags_debug}} -o {{target}} {{source}}

# .clang-format init
cl:
	rm -rf .clang-format
	clang-format -style=WebKit -dump-config > .clang-format

# .clang-format fmt
fmt:
	find {{fmt_flags}}

# clang++ LLVM emit-file
ll:
	rm -rf target
	mkdir -p target
	cp -rf {{src_dir}}/main.cpp ./
	{{clang_which}} {{ldflags_emit_llvm}} main.cpp
	mv *.ll {{target_dir}}
	{{clang_which}} {{ldflags_common}} -o {{target}} {{source}}
	mv *.cpp {{target_dir}}
	rm -rf *.out

# Assembly emit-file
as:
	rm -rf target
	mkdir -p target
	{{gpp_which}} {{ldflags_assembly}} -o {{target}} {{source}}
	mv *.ii {{target_dir}}
	mv *.o {{target_dir}}
	mv *.s {{target_dir}}
	mv *.bc {{target_dir}}

# clang++ fsanitize_address
fsan:
	rm -rf target
	mkdir -p target
	{{clang_which}} {{ldflags_fsanitize_address}} {{source}} -o {{target}}
	{{clang_which}} {{ldflags_fsanitize_object}} {{target}}
	mv *.out {{target_dir}}

# leak memory check(valgrind)
mem:
	rm -rf target
	mkdir -p target
	{{gpp_which}} {{ldflags_fsanitize_valgrind}} {{source}} -o {{target}}
	valgrind --leak-check=full {{target}}

# object file emit-file
obj:
	rm -rf target
	mkdir -p target
	{{gpp_which}} {{ldflags_assembly}} -o {{target}} {{source}}
	mv *.ii {{target_dir}}
	mv *.o {{target_dir}}
	mv *.s {{target_dir}}
	mv *.bc {{target_dir}}
	objdump --disassemble -S -C {{target_dir}}/main.o

# hex view
xx:
	rm -rf target
	mkdir -p target
	{{gpp_which}} {{ldflags_fsanitize_valgrind}} {{source}} -o {{target}}
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

	
 Debugging(VSCode)
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
	
```
