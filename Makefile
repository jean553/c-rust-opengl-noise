CC=gcc
CFLAGS=-std=c99
SOURCEDIR=src
LIBS=-lm -ldl -lpthread -lGL -lGLU -lglut libs/simple-noise-rs/simple-noise-rs/target/debug/libsimplenoise.a

all: simple_noise_rs c_rust_opengl_noise

c_rust_opengl_noise:
	$(CC) $(SOURCEDIR)/main.c -o c_rust_opengl_noise $(LIBS)

simple_noise_rs:
	cargo build --manifest-path libs/simple-noise-rs/simple-noise-rs/Cargo.toml

clean:
	rm -rf libs/simple-noise-rs/simple-noise-rs/target
	rm c_rust_opengl_noise
