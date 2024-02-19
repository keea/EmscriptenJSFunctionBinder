#!/bin/bash

docker run \
--rm \
-v $(pwd):/src \
-u $(id -u):$(id -g) \
emscripten/emsdk \
bash -c "emcmake cmake -B build-web && cmake --build build-web"