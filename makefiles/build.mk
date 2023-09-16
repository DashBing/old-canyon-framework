ifeq ($(OS), Windows_NT)
	FILE_OUT_TYPE := .exe
else
	FILE_OUT_TYPE :=
endif

BUILD_DIR := build

build:
	@make build-cvm-runner

.PHONY:make-build-dir
make-build-dir:
	mkdir $(BUILD_DIR)

build-cvm-runner:
	@make make-build-dir
	g++ cvm-runner/main.cpp -o $(BUILD_DIR)/cvm-runner$(FILE_OUT_TYPE)
