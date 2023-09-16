cvm-runner.exe:$(cvm-req)
	g++ cvm-runner/main.cpp -o $(BUILD_DIR)/cvm-runner$(FILE_OUT_TYPE)

.PHONY:build-cvm-runner
build-cvm-runner:
	$(make) make-build-dir
	$(make) cvm-runner.exe

.PHONY:clean-cvm-runner
clean-cvm-runner:
	rmdir $(BUILD_DIR)
