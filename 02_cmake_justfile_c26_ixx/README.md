# link

<hr />

# cmake 최신판 설치[|🔝|](#link)

- https://cmake.org/download/
- 압축 풀고 cmake폴더 들어가서

```bash
./bootstrap && make && sudo make install

# 병렬 실행
make -j `nproc`
```

- https://tttsss77.tistory.com/77


# Cmake업데이트 하기[[🔝]](#link)
- https://somjang.tistory.com/entry/Ubuntu-CMake-%EC%97%85%EB%8D%B0%EC%9D%B4%ED%8A%B8-%ED%95%98%EB%8A%94-%EB%B0%A9%EB%B2%95

- https://askubuntu.com/questions/829310/how-to-upgrade-cmake-in-ubuntu

# Cmake option옵션 설정[[🔝]](#link)
- https://tttsss77.tistory.com/193?category=827570

# (외부240919) Don’t Get Left in the Dark – Master C++20 Modules NOW! | LearnQtGuide]
- [(외부240919) Don’t Get Left in the Dark – Master C++20 Modules NOW! | LearnQtGuide](https://youtu.be/oT3IUopRa5g?si=SpzR_UnhHU-1Gv1W)

# How to use c++20 modules with CMake?
- https://stackoverflow.com/questions/57300495/how-to-use-c20-modules-with-cmake
- [관련 유튜브 영상(외부영상) 230726 The Challenges of Implementing C++ Header Units: C++ Modules - Daniel Ruoso - CppNow 2023 | CppNow](https://youtu.be/_LGR0U5Opdg?si=e0fA8FcAz_VE1ZwM)
- [(외부250507)C++ Modules Myth Busting | Microsoft Visual Studio](https://youtu.be/F-sXXKeNuio?si=kG-GAZVouAE52_4m)
- [(외부240919) Don’t Get Left in the Dark – Master C++20 Modules NOW! | LearnQtGuide](https://youtu.be/oT3IUopRa5g?si=SpzR_UnhHU-1Gv1W)



# Agenda
- • Background on the work on C++ Modules
- • Review of the Named Modules tooling
- • The challenges of implementing header units
- • Where do we go from here?
  - 안건
    - • C++ 모듈 작업의 배경
    - • 명명된 모듈 도구 검토
    - • 헤더 유닛 구현의 어려움
    - • 여기서부터 어디로 가야 할까요?

# Background
- • Initial work in modules was focused in highly-regulated environments (i.e., mono-repos)
- • Bloomberg has a more open-ended package management approach, closer to what GNU/Linux distributions do
- • In July 2021, Bloomberg got more involved in the ISO C++ Tooling Study Group with the focus of making C++ Modules work in our environment

- Papers:
  - • [P2409RO](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2021/p2409r0.pdf): Requirements for Usage of C++ Modules at Bloomberg

- 배경
- • 모듈의 초기 작업은 고도로 규제된 환경(즉, 모노 레포)에 집중되었습니다
- • 블룸버그는 GNU/리눅스 배포판에 더 가까운 보다 개방적인 패키지 관리 접근 방식을 가지고 있습니다
- • 2021년 7월, 블룸버그는 환경에서 C++ 모듈을 작동시키는 데 중점을 두고 ISO C++ 툴링 연구 그룹에 더 많이 참여했습니다
- 논문:
  - • P2409RO: 블룸버그에서 C++ 모듈 사용 요건

- (영상230726기준)Over the past two years, there has been significant progress in figuring out Named Modules
- • Bloomberg has been working with Kitware; CMake now has experimental support for them
- • There's still significant work to be done for Named Modules to be usable in production environments
  - 지난 2년 동안 명명된 모듈을 파악하는 데 상당한 진전이 있었습니다
  - • 블룸버그는 키트웨어와 협력해 왔으며, 이제 CMake는 키트웨어에 대한 실험적 지원을 제공하고 있습니다
  - • 명명된 모듈이 운영 환경에서 사용되기 위해서는 아직 상당한 작업이 필요합니다
