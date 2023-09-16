build-cvm-dll:$(cvm-dir)cvm.cpp $(cvm-req)
	g++ $(cvm-dir)/cvm.cpp --shared -o $(BUILD_DIR)/cvm$(DLL_OUT_TYPE)
