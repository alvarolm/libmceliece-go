#!/bin/bash

# Exit immediately if a command exits with a non-zero status
# -e: exit on error
# -u: treat unset variables as an error
set -eu

mkdir -p ./libs_src

cd ./libs_src

add_arm64_compiler_config() {
  local dir="$1"
  echo "aarch64-linux-gnu-gcc -Wall -fPIC -fwrapv -O2" > "$dir/compilers/arm64"
}

# ensure global dependencies are installed
# for debian:
sudo apt install -y valgrind python3-capstone gcc-aarch64-linux-gnu


# dependency:
# librandombytes
# https://randombytes.cr.yp.to/
wget -m https://randombytes.cr.yp.to/librandombytes-latest-version.txt
version=$(cat randombytes.cr.yp.to/librandombytes-latest-version.txt)
wget -m https://randombytes.cr.yp.to/librandombytes-$version.tar.gz
tar -xzf randombytes.cr.yp.to/librandombytes-$version.tar.gz

# dependency:
# libcpucycles
# https://cpucycles.cr.yp.to/
wget -m https://cpucycles.cr.yp.to/libcpucycles-latest-version.txt
version=$(cat cpucycles.cr.yp.to/libcpucycles-latest-version.txt)
wget -m https://cpucycles.cr.yp.to/libcpucycles-$version.tar.gz
tar -xzf cpucycles.cr.yp.to/libcpucycles-$version.tar.gz

# library
# libmceliece
# https://lib.mceliece.org/
wget -m https://lib.mceliece.org/libmceliece-latest-version.txt
version=$(cat lib.mceliece.org/libmceliece-latest-version.txt)
wget -m https://lib.mceliece.org/libmceliece-$version.tar.gz
tar -xzf lib.mceliece.org/libmceliece-$version.tar.gz

# Find directories dynamically (pick highest version when multiple exist)
LIBCPUCYCLES_DIR=$(find "$PWD" -maxdepth 1 -type d -name "libcpucycles-*" | sort -V | tail -n1)
LIBRANDOMBYTES_DIR=$(find "$PWD" -maxdepth 1 -type d -name "librandombytes-*" | sort -V | tail -n1)
LIBMCELIECE_DIR=$(find "$PWD" -maxdepth 1 -type d -name "libmceliece-*" | sort -V | tail -n1)

# Check if directories were found
if [[ -z "$LIBCPUCYCLES_DIR" ]]; then
    echo "Error: libcpucycles directory not found"
    exit 1
fi

if [[ -z "$LIBRANDOMBYTES_DIR" ]]; then
    echo "Error: librandombytes directory not found"
    exit 1
fi

if [[ -z "$LIBMCELIECE_DIR" ]]; then
    echo "Error: libmceliece directory not found"
    exit 1
fi

echo "Using directories:"
echo "  libcpucycles: $LIBCPUCYCLES_DIR"
echo "  librandombytes: $LIBRANDOMBYTES_DIR"
echo "  libmceliece: $LIBMCELIECE_DIR"

# compile librandombytes (amd64 + arm64)
add_arm64_compiler_config "$LIBRANDOMBYTES_DIR"
cd "$LIBRANDOMBYTES_DIR"
./configure --prefix=/usr && make -j"$(nproc)"
./configure --host=arm64 && make -j"$(nproc)"
cd "$OLDPWD"

# compile libcpucycles (amd64 + arm64)
add_arm64_compiler_config "$LIBCPUCYCLES_DIR"
cd "$LIBCPUCYCLES_DIR"
./configure --prefix=/usr && make -j"$(nproc)"
./configure --host=arm64 && make -j"$(nproc)"
cd "$OLDPWD"

# compile libmceliece (amd64 + arm64)
add_arm64_compiler_config "$LIBMCELIECE_DIR"
cd "$LIBMCELIECE_DIR"

# amd64 build
export CPATH="$LIBCPUCYCLES_DIR/build/amd64/package/include:$LIBRANDOMBYTES_DIR/build/amd64/package/include"
export LIBRARY_PATH="$LIBCPUCYCLES_DIR/build/amd64/package/lib:$LIBRANDOMBYTES_DIR/build/amd64/package/lib"
export LD_LIBRARY_PATH="$LIBRARY_PATH"
./configure && make -j"$(nproc)"

# arm64 build
export CPATH="$LIBCPUCYCLES_DIR/build/arm64/package/include:$LIBRANDOMBYTES_DIR/build/arm64/package/include"
export LIBRARY_PATH="$LIBCPUCYCLES_DIR/build/arm64/package/lib:$LIBRANDOMBYTES_DIR/build/arm64/package/lib"
export LD_LIBRARY_PATH="$LIBRARY_PATH"
./configure --host=arm64 && make -j"$(nproc)"

cd "$OLDPWD"
