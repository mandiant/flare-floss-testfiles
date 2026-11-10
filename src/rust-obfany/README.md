# test-rust-obfany

Strings encrypted with the obfany crate's obfstr! and obfwide! (UTF-16) macros: xor with a XorShift keystream.

Adapted from [rust-deobf](https://github.com/VAHPEM/rust-deobf) (`bench_src/obfany`), by Ve (VAHPEM),
licensed under the Apache License 2.0.

Built with rustc 1.97.0, release profile (stripped), for i686-pc-windows-gnu, x86_64-pc-windows-gnu
(with mingw-w64), and x86_64-unknown-linux-gnu: `make all`.
