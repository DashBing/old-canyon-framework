ifeq ($(OS), Windows_NT)
	FILE_OUT_TYPE := .exe
else
	FILE_OUT_TYPE :=
endif

BUILD_DIR := build

build:
	make build-cvm-runner

build-cvm-runner:
	g++ cvm-runner/main.cpp -o __build__/cvm-runner$(FILE_OUT_TYPE)
