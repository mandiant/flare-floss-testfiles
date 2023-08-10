# Test Files for Rust Binary Versions

This repository contains two ZIP archives, each containing compiled Rust binaries for minor versions 1.56.0 to 1.70.0, specifically for the 386 and amd64 architectures, along with their source code.

## Contents

Each ZIP archive corresponds to a specific architecture and contains the following files:

- `bin/versions_32.zip`: Zip file containing the compiled Rust binaries for the 386 architecture.
- `bin/versions_64.zip`: Zip file containing the compiled Rust binaries for the amd64 architecture.
- `src/main.rs`: Source code for the binaries.

## Generating Rust Binaries using Docker

To automate the process of generating Rust binaries for all versions from 1.56.0 to 1.70.0 using Docker, you can use the provided Python script. Follow the steps below:

- Make sure Docker is installed and properly configured on your system.
- Run the script using the following command: `python3 rust_binary_generator.py`.

The script will handle the setup, compilation, and generation of Rust binaries for the specified minor versions. The resulting binaries will be saved in the `bin/` directory.