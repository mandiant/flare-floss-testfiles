# test-rust-obfuse-xor

Strings encrypted with the obfuse crate's xor mode: xor computed through mixed boolean-arithmetic expressions.

Adapted from [rust-deobf](https://github.com/VAHPEM/rust-deobf) (`bench_src/obfuse_xor`), by Ve (VAHPEM),
licensed under the Apache License 2.0.

Built with rustc 1.97.0, release profile (stripped), for i686-pc-windows-gnu, x86_64-pc-windows-gnu
(with mingw-w64), and x86_64-unknown-linux-gnu: `make all`.
obfuse picks new random keys on each build, so a rebuild doesn't give the same bytes.
