# c-rust-opengl-noise

## Requirements

The following tools are required:
 * cargo (Rust nightly),
 * gcc
 * freeglut

### Install `freeglut` on Archlinux

```sh
pacman -S freeglut
```

## Install sub-module (Rust A-Star library)

```bash
git submodule init
git submodule update
```

## Compile

The following command compiles both
of the C program and the Rust library.

```sh
make
```

## Remove previous compilation data

```sh
make clean
```
