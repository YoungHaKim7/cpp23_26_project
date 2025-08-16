# 외국사람이 잘 정리함(C11부터 C26까지 예시 잘 정리됨)
- https://github.com/scivision/Cpp23-examples

# raylib
- https://www.raylib.com/
  - API https://www.raylib.com/cheatsheet/cheatsheet.html
  - raylib https://github.com/raysan5/raylib

- https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux#build-raylib-using-cmake

```
git clone https://github.com/raysan5/raylib.git raylib
cd raylib
mkdir build && cd build
cmake -DBUILD_SHARED_LIBS=ON ..
make
sudo make install
sudo ldconfig
```