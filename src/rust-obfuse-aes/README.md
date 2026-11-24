# test-rust-obfuse-aes

Strings encrypted with the obfuse crate's aes-256-gcm mode: AES-256-GCM, with AES-NI where the CPU has it.

Adapted from [rust-deobf](https://github.com/VAHPEM/rust-deobf) (`bench_src/obfuse_aes`), by Ve (VAHPEM),
licensed under the Apache License 2.0.

Built with rustc 1.97.0, release profile (stripped), for i686-pc-windows-gnu, x86_64-pc-windows-gnu
(with mingw-w64), and x86_64-unknown-linux-gnu: `make all`.
obfuse picks new random keys on each build, so a rebuild doesn't give the same bytes.
