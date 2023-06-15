# Copyright (C) 2023 Mandiant, Inc. All Rights Reserved.
'''
This Python script automates the process of generating Go binaries for versions 1.11 to 1.20 using Docker. By leveraging Docker containers, it ensures a consistent and reproducible environment for compiling the Go source code across different platforms.

Please note that Docker must be installed and properly configured on your system for the script to execute successfully.
'''

import subprocess
import sys

go_versions = """
go1.11
go1.12
go1.13
go1.14
go1.15
go1.16
go1.17
go1.18
go1.19
go1.20
"""

subprocess.call(["docker", "compose", "up"])
print("Compose is UP")

for version in go_versions.split():
    print("version: ", version[2:])
    f = open("Dockerfile", "w")

    f.write(
    """# syntax=docker/dockerfile:1
    FROM golang:{}

    WORKDIR /app
    COPY go.mod ./
    RUN go mod download
    COPY *.go ./
    RUN GOOS=windows GOARCH=386 go install main.go""".format(version[2:]))
    f.close()

    f = open("go.mod", "w")

    f.write(
    """
    module go-test

    go {}
    """.format(version[2:]))

    f.close()

    subprocess.call(["docker", "build", "--tag", "go-test", "."])
    subprocess.call(["docker", "run", "-v", "/home/ark/go-test/:/var/opt", "go-test", "mv", "/go/bin/main.exe", "/var/opt/binaries/main{}.exe".format(version[2:])])

subprocess.call(["docker", "compose", "down"])
print("Compose is DOWN")


