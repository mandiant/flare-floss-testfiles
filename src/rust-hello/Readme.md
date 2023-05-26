## Hello World Rust Binary


### Prerequisites

Before proceeding, ensure that you have the following prerequisites installed:
- Rust: The Rust programming language and its package manager, Cargo. You can install Rust by following the instructions provided on the [official Rust website].

### Building the binary
Build the binary using Cargo:

To build the "Hello World" Rust binary, follow these steps:

1) Clone the repository to your local machine:
```git clone https://github.com/your-username/hello-world-rust.git```

2) Navigate to the project directory:
```cd hello-world-rust```
3) Build the binary using Cargo:
For Debug profile:

- 32-bit Windows machine:
```cargo build --target i686-pc-windows-gnu```

- 64-bit Windows machine:
```cargo build --target x86_64-pc-windows-gnu```

- 64-bit Linux machine:
```cargo build --target x86_64-unknown-linux-gnu```

For Release profile, replace build with build --release in the above commands.

The above commands will compile the Rust code and generate the binary based on the selected profile and target platform.


### Running the Binary

Once the binary is built, you can run it using the following command:

For Debug profile:
```cargo run```

For Release profile:
```cargo run --release```

### Version and Platform Information

The version of Rust used to build these binaries is 1.69.0, and the profile used was DEBUG. The binaries were compiled on Linux using LLVM.

The above commands will execute the binary and display the "Hello World" message in your terminal.

