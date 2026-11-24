# test-rust-decode-xor

A hand-written decoder function: static ciphertext xor a repeating 16-byte key, pushed into a heap Vec and returned as a String.

Adapted from [rust-deobf](https://github.com/VAHPEM/rust-deobf) (`bench_src/xor_custom`), by Ve (VAHPEM),
licensed under the Apache License 2.0.

Built with rustc 1.97.0, release profile (stripped), for i686-pc-windows-gnu, x86_64-pc-windows-gnu
(with mingw-w64), and x86_64-unknown-linux-gnu: `make all`.
