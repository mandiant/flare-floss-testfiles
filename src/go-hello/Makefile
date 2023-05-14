NAME=go-hello

BUILDDIR=bin
SRC=$(NAME).go
LINUX=$(NAME)
WINDOWS=$(NAME).exe
WINDOWS64=$(NAME)64.exe

dir=@mkdir -p $(@D)

$(BUILDDIR)/$(LINUX): $(SRC)
	$(dir)
	go build -o $@ $(SRC)


$(BUILDDIR)/$(WINDOWS): $(SRC)
	$(dir)
	GOOS=windows GOARCH=386 go build -o $@ $(SRC)


$(BUILDDIR)/$(WINDOWS64): $(SRC)
	$(dir)
	GOOS=windows GOARCH=amd64 go build -o $@ $(SRC)



clean:
	rm -rf $(BUILDDIR)/*~ $(BUILDDIR)/*.bak $(BUILDDIR)/*.exe $(BUILDDIR)/*.viv $(BUILDDIR)/*.swp $(BUILDDIR)/$(LINUX)


all: $(BUILDDIR)/$(LINUX) $(BUILDDIR)/$(WINDOWS) $(BUILDDIR)/$(WINDOWS64)
