# libzelda64
Libzelda64 is highly tested and highly modular header-only library for writing code for zelda64 games.

This is an alternative to z64ovl, z64poevl, z64hdr, and glankk's environment, which has high compatability with [zeldaret/oot](https://github.com/zeldaret/oot) and [zeldaret/mm*](https://github.com/zeldaret/mm).

**\*=** oot decomp names are used over mm decomp names when possible.

## What is this?
Imagine [z64ovl](https://github.com/CrookedPoe/z64ovl/) and [zeldaret/oot](https://github.com/zeldaret/oot) having a baby. This lets you compile code in the context of the zelda64 games; generally used for actor overlays.

The overall purpose of this repository is to make it easier to write cross-game overlays, while also being easy to understand through ludicrously modular self-documentation.

## Version Support
Currently, this repository supports OOT 1.0, and MM US

## How do I use this?

### Get your hands on mips64-gcc
On *nix systems, you can usually install this through your package manager, or compile it yourself from source.
For example, on debian-based distros, you can run:

```
apt update
sudo apt install gcc-mips-linux-gnu
```

On Windows systems, you can install mips64-gcc through msys2/mingw, WSL, or you can cross-compile it from source.
CAT, or **C**ustom **A**ctor **T**oolkit (CAT), which can be found [here](https://hylianmodding.com/?p=217), and ships with a pre-compiled version of mips64-gcc.

### Set up your paths
You can either make sure that [the include folder](include) is in the system include path, or set up an environment variable which points to the correct include directory.

Consider how we use libzelda64 in our [examples](examples), where we use the environment variable `LIBZ64_PATH`.

To use this with CAT, you can replace the contents of `./gcc/mips64/include` with [the include folder](include).

### Libultra
Some of the contents of the repository relies on headers from [libreultra](https://github.com/n64decomp/libreultra). To use this in your projects, you can just put this in your system include path, or manually include it with `-I`

### Building, and overlays
If you want to build overlays, you will need to install [nOVL](https://github.com/z64me/nOVL).
As for building code, you can see various examples of both overlay, and standard code in our [examples](examples). Check out the Makefiles to learn more.

If you would like to include everything, include the header `libzelda64.h`. Additionally, if you would only like to include type definitions, or function symbols from the header, you can define `LIBZELDA64_DONT_AUTOINCLUDE_FUNCS` or `LIBZELDA64_DONT_AUTOINCLUDE_TYPES`
```c
#include <libzelda64.h>

...
```

## Why should I use this over the other options?
It is entirely subjective for what you decide to use. However, that is not to say that each option doesn't have it's advantages and disadvantages. With that in mind, here are some of libzelda64's advantages:
- Highly organized and easy-to-follow (self-documenting)
- Extremely modular with minimal dependencies
- Overwhelmingly tested with many examples, some of which are used in zelda64-online
- Small and extremely bloat-free
- High compatability with [zeldaret/oot](https://github.com/zeldaret/oot) symbols

And disadvantages:
- Incomplete, and updated as needed
    - We are developing automation, which will soon be introduced
- Not in-sync with [zeldaret/mm](https://github.com/zeldaret/mm) (We use oot names)
- No debug support (yet)

#### I need to struct everywhere?
No. This is only required if you do not include the relevant headers. The ports of the structure definitions were written to be modular enough so that they have bare-minimum requirements.

#### Does this contain Gigaleak content?
No. This repository was created sourcing (in order,) oot decomp, our own reverse engineering, mm decomp, z64ovl, cloud-modding, and the knowledge of others.

## Examples
You can find example projects [here](examples). If you would like to submit your own example project, just open a PR.

## Contributing
If you would like to contribute, there are two major things that need to be done.
Firstly, the porting of structures from [zeldaret/oot](https://github.com/zeldaret/oot) and [zeldaret/mm](https://github.com/zeldaret/mm), while most of these are the same, some of them have more data than 1.0, and this must be accounted for.
Secondly, the porting of functions (as externs) from [zeldaret/oot](https://github.com/zeldaret/oot) and [zeldaret/mm](https://github.com/zeldaret/mm).

### Structures
Structure type-definitions should be placed [here](gcc/mips64/include/libzelda64/lib/types), with a safety gate that reads `[FILENAME]_TYPE_H`
So for example, for the Actor type, it looks like this:

```c
#ifndef ACTOR_TYPE_H
#define ACTOR_TYPE_H
...
#endif
```

Each structure type-definition should have its own file, with the exception of structures built from a union, which should be paired with those unions, and furthermore structures which are extremely similar in data and purpose.
Additionally, enums, defines, and constants that are relevant to a particular structure should be placed in their type file.

Another thing to keep in mind when porting structures is that _each structure should be able to stand on its' own_, or in other words, before including it in a source file, you should not have to include any other structure, and it should include a _bare minimum_ amount of headers.
This means that each type should include everything that it needs, and nothing more. With this in mind, do not include headers solely for structured pointer-types. Instead, prepend these with `struct` to reduce the amount of prerequisites.
For example:

```c
typedef struct Foo {
    /* 0x00 */ struct Actor* parent;
    /* 0x04 */ int32_t bar;
} Foo; /* sizeof = 0x08 */
```

If we had this structure, we prepended the member `parent` whose type is a `pointer-to Actor` with `struct`, and then do not include the actor type.

Something else to consider when contributing: unlike [zeldaret/oot](https://github.com/zeldaret/oot), we use wider, more explicit integer types, and standard float/double types. This means `u32` from [zeldaret/oot](https://github.com/zeldaret/oot) is `uint32_t` here, and similarly `f32` is simply `float`.

A final thing to keep in mind is that when contributing structures, you should have the offsets of each member variable, and the size of the structure written as seen in the example above. This is mostly similar to [zeldaret/oot](https://github.com/zeldaret/oot), however we use `/* sizeof = X */` instead of `//size = X` at the end, and also pad to a minimum of two digits (meaning that a structure of size 8 would read `/* sizeof 0x08 */`); be sure to make sure that the offsets line up with the relevant game version.

### Functions
Function externals should be placed [here](include/libzelda64/lib), with a safety gate that reads `[FILENAME]_FUNC_H`
So for example, for t he Actor functions, it looks like this:

```c
#ifndef ACTOR_FUNC_H
#define ACTOR_FUNC_H
...
#endif
```

Since functions are more broad, and likely more ambiguos, it is alright to use the function headers in the context of the general purpose for functions.
For example, instead of having a `Math.h` and `cmath.h` to write the functions for `Math_FAtan2F` and `sqrtf` respectively, they can just be placed in `Math.h`
Furthermore, the function headers should include relevant types, so the Actor function header would include the Actor type header.

