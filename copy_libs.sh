#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SRC_BASE="${SCRIPT_DIR}/libs_src"

MCELIECE_DIR=$(find "${SRC_BASE}" -maxdepth 1 -type d -name "libmceliece-*" | sort -V | tail -n1)
RANDOMBYTES_DIR=$(find "${SRC_BASE}" -maxdepth 1 -type d -name "librandombytes-*" | sort -V | tail -n1)

if [[ -z "${MCELIECE_DIR}" ]]; then
  echo "Error: no libmceliece-* directory found under ${SRC_BASE}" >&2
  exit 1
fi
if [[ -z "${RANDOMBYTES_DIR}" ]]; then
  echo "Error: no librandombytes-* directory found under ${SRC_BASE}" >&2
  exit 1
fi

echo "Using:"
echo "  mceliece:    ${MCELIECE_DIR}"
echo "  randombytes: ${RANDOMBYTES_DIR}"

MCELIECE_SRC="${MCELIECE_DIR}/build/amd64/package"
RANDOMBYTES_SRC="${RANDOMBYTES_DIR}/build/amd64/package"

DST_INCLUDE="${SCRIPT_DIR}/lib/include"
DST_LIB="${SCRIPT_DIR}/lib/amd64"

echo "Updating libmceliece wrapper libraries..."

cp -v "${MCELIECE_SRC}/include/mceliece.h"          "${DST_INCLUDE}/mceliece.h"
cp -v "${MCELIECE_SRC}/lib/libmceliece.a"            "${DST_LIB}/libmceliece.a"
cp -v "${RANDOMBYTES_SRC}/lib/librandombytes-kernel.a" "${DST_LIB}/librandombytes-kernel.a"

echo "Done."
