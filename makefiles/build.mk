ifeq ($(OS),Windows_NT)
	RM := del /q
	RMDIR := rmdir
	RNM := ren
	DLL_OUT_TYPE := .dll
	FILE_OUT_TYPE := .exe
else
	RM := rm -f
	RMDIR := rm -rf
	RNM := mv
	DLL_OUT_TYPE := .so
	FILE_OUT_TYPE :=
endif

make := make
build-incdir := $(incdir)project-make/
BUILD_DIR := build

include $(incdir)requires.mk

build:
	$(make) make-build-dir
	$(make) build-cvm-dll
	$(make) build-cvm-runner

make-build-dir:
	mkdir $(BUILD_DIR)

.PHONY:clean
clean:
	@$(RM) $(BUILD_DIR)
	@$(RMDIR) $(BUILD_DIR)

include $(build-incdir)cvm-runner.mk
include $(build-incdir)cvm-dll.mk
