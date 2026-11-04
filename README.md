# First-semester coursework

Standalone C++ and Python exercises, including alternate approaches and drafts.

## C++ programs

| Source | Exercise | Input |
| --- | --- | --- |
| [byrokraticky_aparat.cpp](byrokraticky_aparat.cpp) | Cycle lengths and their least common multiple | `pravidla.in`; result on stdout |
| [misto_pro_zraz.cpp](misto_pro_zraz.cpp) | Weighted meeting-point selection | `R S N`, then weighted point triples |
| [pocet_inverzi_v_permutaci.cpp](pocet_inverzi_v_permutaci.cpp) | Count permutation inversions | Length, then permutation |
| [prunik_cest_ve_stromu.cpp](prunik_cest_ve_stromu.cpp) | Intersection of paths in a tree | Vertex/path counts, tree edges, path endpoints |
| [skladani_krabic.cpp](skladani_krabic.cpp) | Box-stacking experiment; computes a result without printing it | Box count and dimensions |
| [skladani_krabic2.cpp](skladani_krabic2.cpp) | Box-stacking DP variant | Box count and dimensions |
| [studentuv_rozvrh.cpp](studentuv_rozvrh.cpp) | Interval scheduling | Interval count, then start/end pairs |
| [theseus_a_minotauros.cpp](theseus_a_minotauros.cpp) | Maze-pursuit BFS | Width, height, then integer grid |
| [zasobovaci_strediska.cpp](zasobovaci_strediska.cpp) | Supply-center placement on a tree | Vertex/center counts, then tree edges |
| [zasobovaci_strediska2.cpp](zasobovaci_strediska2.cpp) | Alternative supply-center approach | Same input format |

Except for `byrokraticky_aparat`, these programs read stdin.

## Python programs

| Source | Exercise / usage |
| --- | --- |
| [bigramy.py](bigramy.py) | Letter-bigram counts; reads `vstup.txt`, writes `vystup.txt` |
| [bipartitni_graf.py](bipartitni_graf.py) | Bipartition; vertex and edge counts on separate lines, then edges |
| [directory.py](directory.py) | Importable `sort_people` helper for birth-date/name sorting |
| [kodovanie.py](kodovanie.py) | Recursive number encoding; one integer per stdin line |
| [nejvetsi_jeskyne.py](nejvetsi_jeskyne.py) | Cave-component analysis; text grid on stdin |
| [piskvorkova_remiza.py](piskvorkova_remiza.py) | Draw-pattern construction; row and column counts on stdin |
| [piskvorkova_remiza2.py](piskvorkova_remiza2.py) | Alternate draw pattern; same input format |
| [presmycky.py](presmycky.py) | Anagram queries; word count/list, then query count/list |
| [rect.py](rect.py) | Importable rectangle class with area, perimeter, containment, and intersection |
| [rezani_stromu.py](rezani_stromu.py) | Weighted tree-cut exercise; vertex count and weighted edges on stdin |
| [tst.py](tst.py) | Experimental 4D point generator; requires NumPy |
| [veze_na_sachovnici.py](veze_na_sachovnici.py) | Count nonattacking rook placements; board size and rows on stdin |

## Build C++

Requires GCC or Clang and CMake 3.16+. GNU C++17 extensions are enabled for the
original variable-length arrays.

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel 2
```

Each executable is placed in `build/`. To build a single exercise:

```sh
cmake --build build --target studentuv_rozvrh
```

For stdin-based programs, redirect an input file into the executable. File-based
examples can be run from the build folder:

```sh
cp pravidla.in vstup.txt build/
cd build
./byrokraticky_aparat
python3 ../bigramy.py
```

This keeps generated output in `build/`. The original samples and `code.png`
remain in the repository.

## Run Python

Requires Python 3.9+. All exercises use the standard library; only the `tst.py`
scratch script needs NumPy.

```sh
printf '0\n1\n2\n' | python3 kodovanie.py
printf '4 8\n' | python3 piskvorkova_remiza2.py
```

CI builds all ten C++ programs on Linux/macOS and checks Python syntax.
