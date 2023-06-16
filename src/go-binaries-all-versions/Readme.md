# Test Files for Go Binary Versions

This repository contains two ZIP archives, each containing compiled Go binaries for minor versions 1.11 to 1.20, specifically for the 386 and amd64 architectures, along with their corresponding source code.

## Contents

Each ZIP archive corresponds to a specific architecture and contains the following files:

- `bin/versions_32.zip`: Zip file containing the compiled Go binaries for the 386 architecture.
- `bin/versions_64.zip`: Zip file containing the compiled Go binaries for the amd64 architecture.
- `main32.go`: Source code for the 386 architecture binaries.
- `main64.go`: Source code for the amd64 architecture binaries.

## Generating Go Binaries using Docker

To automate the process of generating Go binaries for all versions from 1.11 to 1.20 using Docker, you can use the provided Python script. Follow the steps below:

- Make sure Docker is installed and properly configured on your system.
- Run the script using the following command: `python3 go_binary_generator.py`.

The script will handle the setup, compilation, and generation of Go binaries for the specified minor versions. The resulting binaries will be saved in the `bin/` directory.