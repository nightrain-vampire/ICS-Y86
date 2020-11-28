CCH_QH.dll:
	gcc -shared -fPIC R.cpp TOP.cpp FETCH.cpp DECODE.cpp EXECUTE.cpp MEMORY.cpp WBACK.cpp main.cpp -o CCH_QH.dll -lstdc++