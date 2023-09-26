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

char_set := -finput-charset=utf-8 -fexecl-charset=utf-8

include $(incdir)requires.mk

build:
	$(make) make-build-dir
	$(make) build-cvm-dll
	$(make) build-cyv

make-build-dir:
	mkdir $(BUILD_DIR)

.PHONY:clean
clean:
	@$(RM) $(BUILD_DIR)
	@$(RMDIR) $(BUILD_DIR)

include $(build-incdir)cyv.mk
include $(build-incdir)cvm-dll.mk
