ifeq ($(OS), Windows_NT)
	FILE_OUT_TYPE := .exe
else
	FILE_OUT_TYPE :=
endif

make := make
build-incdir := $(incdir)project-make/
BUILD_DIR := build

include $(incdir)requires.mk

build:
	$(make) build-cvm-runner

make-build-dir:
	mkdir $(BUILD_DIR)

clean:
	$(make) clean-cvm-runner

include $(build-incdir)cvm-runner.mk
