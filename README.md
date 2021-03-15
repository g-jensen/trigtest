![gif](trig.gif)

# trigtest

If you get an error that there was an ```Error loading font```, you need to change [this](https://github.com/g-jensen/trigtest/blob/6a0295a6bfd548431baade5ccad3baa4ea57a27f/trigtest.cpp#L104) line a file in the directory where your fonts are stored. 

SFML is a graphics library for c++

If you want to run this program you can install SFML:

```sudo apt-get install libsfml-dev```

or go to the website ```https://www.sfml-dev.org```

To compile this program, first do:

```g++ -c trigtest.cpp```

then:

```g++ trigtest.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system```

and to run it:

```./sfml-app```
