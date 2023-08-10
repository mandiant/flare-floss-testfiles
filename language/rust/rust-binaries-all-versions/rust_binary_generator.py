# Copyright (C) 2023 Mandiant, Inc. All Rights Reserved.
"""
This Python script automates the process of generating Rust binaries for versions 1.56.0 to 1.70.0 using Docker. By leveraging Docker containers, it ensures a consistent and reproducible environment for compiling the Rust source code across different platforms.

Please note that Docker must be installed and properly configured on your system for the script to execute successfully.

Usage:
    python rust_binary_generator.py

The resulting binaries will be saved in the `bin/` directory.
"""

import subprocess

rust_versions = """
1.70.0
1.68.0
1.66.0
1.64.0
1.62.0
1.60.0
1.58.0
1.56.0
"""

f = open("docker-compose.yml", "w")

f.write(
    """services:
  app:
    build: ."""
)

f.close()

subprocess.call(["docker", "compose", "up"])
print("Compose is UP")

architecture = {"386": "i686-pc-windows-gnu", "amd64": "x86_64-pc-windows-gnu"}

for arch in architecture.keys():
    for version in rust_versions.split():
        print("version: ", version)

        f = open("Dockerfile", "w")

        target = architecture[arch]

        f.write(
            """# syntax=docker/dockerfile:1
FROM rust:{}
ENV USER root
RUN cargo new known_binary
WORKDIR known_binary
COPY ./src/main.rs ./src/main.rs
RUN apt update && apt install mingw-w64 -y
RUN rustup target add {}
RUN rustup update
RUN cargo build --release --target {}

""".format(
                version, target, target
            )
        )
        f.close()

        subprocess.call(["docker", "build", "--tag", "rust-test", "."])
        subprocess.call(
            [
                "docker",
                "run",
                "-v",
                ".:/var/opt",
                "rust-test",
                "mv",
                "./target/{}/release/known_binary.exe".format(target),
                "/var/opt/bin/rust_{}_{}.exe".format(arch, version),
            ]
        )

subprocess.call(["docker", "compose", "down"])
print("Compose is DOWN")

# Free up disk space
subprocess.call(["docker", "system", "prune", "-a", "-f"])
