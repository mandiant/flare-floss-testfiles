NAME=test-rust-cryptify

BUILDDIR=bin
LINUX=$(NAME)
WINDOWS=$(NAME).exe
WINDOWS64=$(NAME)64.exe

dir=@mkdir -p $(@D)

# needs: rustup target add i686-pc-windows-gnu x86_64-pc-windows-gnu, and mingw-w64.
$(BUILDDIR)/$(LINUX): src/main.rs Cargo.toml
	$(dir)
	cargo build --release --locked --target x86_64-unknown-linux-gnu
	cp target/x86_64-unknown-linux-gnu/release/$(NAME) $@


$(BUILDDIR)/$(WINDOWS): src/main.rs Cargo.toml
	$(dir)
	cargo build --release --locked --target i686-pc-windows-gnu
	cp target/i686-pc-windows-gnu/release/$(NAME).exe $@


$(BUILDDIR)/$(WINDOWS64): src/main.rs Cargo.toml
	$(dir)
	cargo build --release --locked --target x86_64-pc-windows-gnu
	cp target/x86_64-pc-windows-gnu/release/$(NAME).exe $@


clean:
	rm -rf target $(BUILDDIR)/*.exe $(BUILDDIR)/$(LINUX)


all: $(BUILDDIR)/$(LINUX) $(BUILDDIR)/$(WINDOWS) $(BUILDDIR)/$(WINDOWS64)
