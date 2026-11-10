# test-rust-tightstring

A stack buffer xor-decoded in place by a tight loop, with the key hidden from the optimizer by std::hint::black_box.

Adapted from [rust-deobf](https://github.com/VAHPEM/rust-deobf) (`bench_src/tight_xor`), by Ve (VAHPEM),
licensed under the Apache License 2.0.

Built with rustc 1.97.0, release profile (stripped), for i686-pc-windows-gnu, x86_64-pc-windows-gnu
(with mingw-w64), and x86_64-unknown-linux-gnu: `make all`.
