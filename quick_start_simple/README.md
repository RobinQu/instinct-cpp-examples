# Quick start for instinct-cpp

A deadly simple setup for instinct.cpp using conan.

## Build and run

To bootstrap project using conan:

```shell
conan install conanfile.py --build=missing
```

`conan` will prepare dependencies and configure project. You can learn more about consuming packages using conan from [conan's official docs](https://docs.conan.io/2/tutorial/consuming_packages.html). 

Now you can open project using your favorite IDEs or use command line to build:

```shell
conan build .
```

And execute the `main` program:

```shell
./build/main
```

## What's next?

Back to [library documentations](https://github.com/RobinQu/instinct.cpp/blob/main/docs/library.md).
