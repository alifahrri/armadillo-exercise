#!/bin/bash

docker run --rm \
	-v $(pwd)/include:/app/include \
	-v $(pwd)/src:/app/src \
	-v $(pwd)/CMakeLists.txt:/app/CMakeLists.txt \
	-it --name armadillo-demo armadillo:demo bash
