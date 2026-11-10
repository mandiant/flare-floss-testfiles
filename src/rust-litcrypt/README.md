# test-rust-litcrypt

Strings encrypted with the litcrypt crate's lc! macro: xor with a key embedded at build time, decoded by a shared function.

Adapted from [rust-deobf](https://github.com/VAHPEM/rust-deobf) (`bench_src/litcrypt`), by Ve (VAHPEM),
licensed under the Apache License 2.0.

Built with rustc 1.97.0, release profile (stripped), for i686-pc-windows-gnu, x86_64-pc-windows-gnu
(with mingw-w64), and x86_64-unknown-linux-gnu: `make all`.
litcrypt reads its key from the environment at build time: `LITCRYPT_ENCRYPT_KEY=benchmark-fixed-key-do-not-reuse`.
