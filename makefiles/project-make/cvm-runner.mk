#cvm-runner.exe:$(cvm-req)

#.PHONY:build-cvm-runner
build-cvm-runner:$(cvm-req) $(BUILD_DIR)/cvm$(DLL_OUT_TYPE)
	g++ $(BUILD_DIR)/cvm$(DLL_OUT_TYPE) cvm-runner/main.cpp -o $(BUILD_DIR)/cvm-runner$(FILE_OUT_TYPE)
#$(make) cvm-runner.exe
