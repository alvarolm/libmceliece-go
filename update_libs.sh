#!/usr/bin/env bash
set -euo pipefail

MIRROR="http://ftp.debian.org/debian"
mkdir -p libs_src lib/amd64 lib/arm64 lib/include

declare -A POOL=(
    [libmceliece-dev]="pool/main/libm/libmceliece"
    [librandombytes-dev]="pool/main/libr/librandombytes"
)

HEADERS_DONE=0
for PKG in libmceliece-dev librandombytes-dev; do
    POOL_PATH="${POOL[$PKG]}"
    for ARCH in amd64 arm64; do
        FILENAME=$(curl -s "$MIRROR/$POOL_PATH/" \
            | grep -oP "href=\"\K[^\"]*_${ARCH}\.deb" \
            | grep "$PKG" | sort -V | tail -1)
        [ -z "$FILENAME" ] && { echo "Could not find $PKG for $ARCH"; exit 1; }

        DEB="libs_src/${FILENAME}"
        echo "Downloading $FILENAME..."
        curl -fL -o "$DEB" "$MIRROR/$POOL_PATH/$FILENAME"

        EXTRACT="libs_src/extract_${PKG}_${ARCH}"
        rm -rf "$EXTRACT" && mkdir -p "$EXTRACT"
        dpkg-deb --extract "$DEB" "$EXTRACT"

        find "$EXTRACT" -name '*.a' -exec cp {} "lib/$ARCH/" \;

        if [ "$PKG" = "libmceliece-dev" ] && [ "$HEADERS_DONE" -eq 0 ]; then
            find "$EXTRACT" -name '*.h' -exec cp {} lib/include/ \;
            HEADERS_DONE=1
        fi
    done
done

echo "Done."
