# test-rust-goldberg

Strings encrypted with the goldberg crate's goldberg_string! macro, next to its control-flow flattening (goldberg_stmts!).

Adapted from [rust-deobf](https://github.com/VAHPEM/rust-deobf) (`obf_src/goldberg_cff`), by Ve (VAHPEM),
licensed under the Apache License 2.0. Changed: the URL's host is under `.example`, rather than `.net`.

Built with rustc 1.97.0, release profile (stripped), for i686-pc-windows-gnu, x86_64-pc-windows-gnu
(with mingw-w64), and x86_64-unknown-linux-gnu: `make all`.
