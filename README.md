# libmceliece-go

Go wrapper for [libmceliece](https://libmceliece.cr.yp.to/), which implements Classic McEliece, a post-quantum key encapsulation mechanism (KEM) thats been around since 1978 and is now a NIST standard. The underlying C library is highly optimized and very fast. Pre-built C libraries for amd64 and arm64 are included, so you don't need to compile anything to get started.

## Usage

```go
package main

import (
	"fmt"
	"github.com/alvarolm/libmceliece-go"
)

func main() {
	kem := mceliece.New(mceliece.Variant348864)

	pk, sk, err := kem.GenerateKeyPair()
	if err != nil {
		panic(err)
	}

	ct, ss1, err := kem.Encapsulate(pk)
	if err != nil {
		panic(err)
	}

	ss2, err := kem.Decapsulate(ct, sk)
	if err != nil {
		panic(err)
	}

	fmt.Println("shared secrets match:", string(ss1) == string(ss2))
}
```

## Install

```
go get github.com/alvarolm/libmceliece-go
```

Requires CGO (`CGO_ENABLED=1`). Pre-built static libraries are bundled for linux/amd64 and linux/arm64

## Variants

All 20 Classic McEliece parameter sets are supported:

| Variant            | Public key | Secret key | Ciphertext |
|--------------------|------------|------------|------------|
| `Variant348864`    | 261 KB     | 6.5 KB     | 96 B       |
| `Variant348864f`   | 261 KB     | 6.5 KB     | 96 B       |
| `Variant348864pc`  | 261 KB     | 6.5 KB     | 128 B      |
| `Variant348864pcf` | 261 KB     | 6.5 KB     | 128 B      |
| `Variant460896`    | 524 KB     | 13.3 KB    | 156 B      |
| `Variant460896f`   | 524 KB     | 13.3 KB    | 156 B      |
| `Variant460896pc`  | 524 KB     | 13.3 KB    | 188 B      |
| `Variant460896pcf` | 524 KB     | 13.3 KB    | 188 B      |
| `Variant6688128`   | 1020 KB    | 13.6 KB    | 208 B      |
| `Variant6688128f`  | 1020 KB    | 13.6 KB    | 208 B      |
| `Variant6688128pc` | 1020 KB    | 13.6 KB    | 240 B      |
| `Variant6688128pcf`| 1020 KB    | 13.6 KB    | 240 B      |
| `Variant6960119`   | 1023 KB    | 13.6 KB    | 194 B      |
| `Variant6960119f`  | 1023 KB    | 13.6 KB    | 194 B      |
| `Variant6960119pc` | 1023 KB    | 13.6 KB    | 226 B      |
| `Variant6960119pcf`| 1023 KB    | 13.6 KB    | 226 B      |
| `Variant8192128`   | 1326 KB    | 13.8 KB    | 208 B      |
| `Variant8192128f`  | 1326 KB    | 13.8 KB    | 208 B      |
| `Variant8192128pc` | 1326 KB    | 13.8 KB    | 240 B      |
| `Variant8192128pcf`| 1326 KB    | 13.8 KB    | 240 B      |

The `f` suffix uses a faster key generation algorithm. The `pc` suffix enables plaintext confirmation.

The shared secret is always 32 bytes regardless of variant.

## Rebuilding the C libraries

If you want to recompile from source (or target a different architecture), run:

```
./update_libs.sh
```
