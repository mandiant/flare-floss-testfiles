# Copyright (C) 2023 Mandiant, Inc. All Rights Reserved.
"""
This Python script automates the process of generating Go binaries for versions 1.11 to 1.20 using Docker. By leveraging Docker containers, it ensures a consistent and reproducible environment for compiling the Go source code across different platforms.

Please note that Docker must be installed and properly configured on your system for the script to execute successfully.

Usage:
    python go_binary_generator.py

The resulting binaries will be saved in the `bin/` directory.
"""

import subprocess

go_versions = """
1.11
1.12
1.13
1.14
1.15
1.16
1.17
1.18
1.19
1.20
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

architecture = {"386": 32, "amd64": 64}

for arch in architecture.keys():
    for version in go_versions.split():
        print("version: ", version)

        f = open("Dockerfile", "w")

        f.write(
            """# syntax=docker/dockerfile:1
FROM golang:{}

WORKDIR /app
COPY go.mod ./
RUN go mod download
COPY *.go ./
RUN GOOS=windows GOARCH={} go install main{}.go""".format(
                version, arch, architecture[arch]
            )
        )
        f.close()

        f = open("go.mod", "w")

        f.write(
            """module go-test

go {}
        """.format(
                version
            )
        )

        f.close()

        subprocess.call(["docker", "build", "--tag", "go-test", "."])
        subprocess.call(
            [
                "docker",
                "run",
                "-v",
                ".:/var/opt",
                "go-test",
                "mv",
                "/go/bin/main{}.exe".format(architecture[arch]),
                "/var/opt/bin/main_{}_{}.exe".format(architecture[arch], version),
            ]
        )

subprocess.call(["docker", "compose", "down"])
print("Compose is DOWN")
