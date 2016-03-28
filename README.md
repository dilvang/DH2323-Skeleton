SDL2 skeleton for lab assignments 1–3 of the KTH course DH2323,
Computer Graphics and Interaction (and also SU DA3001, Datalogi II).

Requires a compiler handling C++11.


Build with
    $ cmake .
    $ make

If successful, you should be able to run
    $ ./DgiLab
and see a window with blue background.


### Notes
Under OS X, I think running
    $ brew install sdl2 sdl2_gfx glm cmake
should be enough to get you going but I'm not sure since I'm also
running llvm/clang:
    $ brew install --with-clang llvm

Markus Lidström reported that he had to switch out `GLM` for `OpenGL`
in `CMakeLists.txt` in order to make it run on his distribution of
Linux.
