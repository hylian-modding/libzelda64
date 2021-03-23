# libzelda64
Poe was taking too long with [z64poevl](https://github.com/CrookedPoe/z64ovl/) and we kept missing each other when we agreed to work on it.
This is an alternative to Poe's fork of z64ovl, with high compatability with [zeldaret/oot](https://github.com/zeldaret/oot).

## What is this?
Imagine [z64ovl](https://github.com/CrookedPoe/z64ovl/) and [zeldaret/oot](https://github.com/zeldaret/oot) having a baby. This lets you compile code in the context of the zelda64 games (particularly oot 1.0 at the moment); generally used for actor overlays.

### Why?
I wanted to get the new z64 puppet written, and felt like we should sync up with Decomp's structure and function names, since it will be _the way_.
The overall purpose of this is to make it easier to write cross-game overlays, while also being easy to understand through self-documentation.

### How do I use this?
Get your hands on mips64-gcc, and make sure that [this folder](gcc/mips64/include) is in the system include path.
If you want to build overlays, you will additionally need [nOVL](https://github.com/AriaHiro64/novl).

If you are coming from **C**ustom **A**ctor **T**oolkit (CAT), which can be found [here](https://hylianmodding.com/?p=217), you can replace the contents of `./gcc/mips64/include` with [this folder](gcc/mips64/include), and then use this with CAT.

### Examples
You can find example projects [here](examples). If you would like to submit your own example project, just open a PR.

### Contributing
If you would like to contribute, there are two major things that need to be done.
Firstly, the porting of structures from [zeldaret/oot](https://github.com/zeldaret/oot), while most of these are the same, some of them have more data than 1.0, and this must be accounted for.
Secondly, the porting of functions (as externs) from [zeldaret/oot](https://github.com/zeldaret/oot).

#### Structures
Structure type-definitions should be placed [here](gcc/mips64/include/libzelda64/lib/types), with a safety gate that reads `[FILENAME]_TYPE_H`
So for example, for the Actor type, it looks like this:

```c
#ifndef ACTOR_TYPE_H
#define ACTOR_TYPE_H
...
#endif
```

Each structure typedefinition should have its own file, with the exception of structures built from a union, which should be paired with those unions.
Additionally, enums, defines, and constants that are relevant to a particular structure should be placed in their type file.

Another thing to keep in mind when porting structures is that _each structure should be able to stand on its' own_, or in other words, before including it in a source file, you should not have to include any other structure.
This means that each type should include everything that it needs, and nothing more. With this in mind, do not include headers for structured pointer-types. Instead, prepend these with `struct`.
For example:

```c
typedef struct Foo {
    /* 0x00 */ struct Actor* parent;
    /* 0x04 */ int32_t bar;
} Foo; /* sizeof = 0x08 */
```

If we had this structure, we prepended the member `parent` whose type is a `pointer-to Actor` with `struct`, and then do not include the actor type.

Something else to consider when contributing: unlike [zeldaret/oot](https://github.com/zeldaret/oot), we use wider integer types, and standard float/double types. This means `u32` from [zeldaret/oot](https://github.com/zeldaret/oot) is `uint32_t` here, and similarly `f32` is simply `float`.

A final thing to keep in mind is that when contributing structures, you should have the offsets of each member variable, and the size of the structure written as seen in the example above. This is mostly similar to [zeldaret/oot](https://github.com/zeldaret/oot), however we use `/* sizeof = X */` instead of `//size = X` at the end, and also pad to a minimum of two digits (meaning that a structure of size 8 would read `/* sizeof 0x08 */`); be sure to make sure that the offsets line up with oot 1.0.

#### Functions
Function externals should be placed [here](gcc/mips64/include/libzelda64/lib), with a safety gate that reads `[FILENAME]_FUNC_H`
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

