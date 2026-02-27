# libmceliece-go

Go wrapper for [libmceliece](https://lib.mceliece.org/) which implements Classic McEliece, a post-quantum key encapsulation mechanism (KEM) thats been around since 1978 and is now a NIST standard.

- prebuilt libraries for `linux/amd64` and `linux/arm64` included; run `./update_libs.sh` to refresh them from Debian packages (requires `curl` and `dpkg-deb`)

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

Requires CGO (`CGO_ENABLED=1`). 

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

## Updating the C libraries

`update_libs.sh` downloads the latest prebuilt `.deb` packages for `libmceliece-dev` and `librandombytes-dev` from Debian forky and copies the static libraries and headers into `lib/`:

```
./update_libs.sh
```

Requirements: `curl`, `dpkg-deb` (available on any Debian/Ubuntu system).

After running, `lib/` will contain:

```
lib/
  amd64/  libmceliece.a  librandombytes.a  librandombytes-kernel.a
  arm64/  libmceliece.a  librandombytes.a  librandombytes-kernel.a
  include/ mceliece.h
```

## Benchmark results

 ```bash
 goos: linux
goarch: amd64
pkg: github.com/alvarolm/libmceliece-go
cpu: 11th Gen Intel(R) Core(TM) i5-1135G7 @ 2.40GHz
BenchmarkGenerateKeyPair/348864-8         	      93	  12176580 ns/op	  268673 B/op	       2 allocs/op
BenchmarkGenerateKeyPair/348864f-8        	     176	   6806130 ns/op	  268673 B/op	       2 allocs/op
BenchmarkGenerateKeyPair/348864pc-8       	     100	  12478288 ns/op	  268672 B/op	       2 allocs/op
BenchmarkGenerateKeyPair/348864pcf-8      	     170	   6769099 ns/op	  268672 B/op	       2 allocs/op
BenchmarkGenerateKeyPair/460896-8         	      32	  39965043 ns/op	  538624 B/op	       2 allocs/op
BenchmarkGenerateKeyPair/460896f-8        	      48	  23506215 ns/op	  538626 B/op	       2 allocs/op
BenchmarkGenerateKeyPair/460896pc-8       	      26	  43822002 ns/op	  538624 B/op	       2 allocs/op
BenchmarkGenerateKeyPair/460896pcf-8      	      52	  22484362 ns/op	  538625 B/op	       2 allocs/op
BenchmarkGenerateKeyPair/6688128-8        	      22	  81162917 ns/op	 1062912 B/op	       2 allocs/op
BenchmarkGenerateKeyPair/6688128f-8       	      22	  51066976 ns/op	 1062920 B/op	       2 allocs/op
BenchmarkGenerateKeyPair/6688128pc-8      	      13	 109550062 ns/op	 1062912 B/op	       2 allocs/op
BenchmarkGenerateKeyPair/6688128pcf-8     	      21	  52197947 ns/op	 1062912 B/op	       2 allocs/op
BenchmarkGenerateKeyPair/6960119-8        	      28	  72089851 ns/op	 1062915 B/op	       2 allocs/op
BenchmarkGenerateKeyPair/6960119f-8       	      28	  40732858 ns/op	 1062915 B/op	       2 allocs/op
BenchmarkGenerateKeyPair/6960119pc-8      	      16	  90241067 ns/op	 1062912 B/op	       2 allocs/op
BenchmarkGenerateKeyPair/6960119pcf-8     	      27	  42887002 ns/op	 1062915 B/op	       2 allocs/op
BenchmarkGenerateKeyPair/8192128-8        	      18	 100475568 ns/op	 1374213 B/op	       2 allocs/op
BenchmarkGenerateKeyPair/8192128f-8       	      22	  50191968 ns/op	 1374212 B/op	       2 allocs/op
BenchmarkGenerateKeyPair/8192128pc-8      	      16	  93846186 ns/op	 1374214 B/op	       2 allocs/op
BenchmarkGenerateKeyPair/8192128pcf-8     	      21	  51003914 ns/op	 1374212 B/op	       2 allocs/op
BenchmarkEncapsulate/348864-8             	  147676	      8622 ns/op	     128 B/op	       2 allocs/op
BenchmarkEncapsulate/348864f-8            	  141252	      8339 ns/op	     128 B/op	       2 allocs/op
BenchmarkEncapsulate/348864pc-8           	  118848	     10189 ns/op	     160 B/op	       2 allocs/op
BenchmarkEncapsulate/348864pcf-8          	  114228	     10209 ns/op	     160 B/op	       2 allocs/op
BenchmarkEncapsulate/460896-8             	   68546	     17685 ns/op	     192 B/op	       2 allocs/op
BenchmarkEncapsulate/460896f-8            	   66234	     17561 ns/op	     192 B/op	       2 allocs/op
BenchmarkEncapsulate/460896pc-8           	   60807	     19176 ns/op	     224 B/op	       2 allocs/op
BenchmarkEncapsulate/460896pcf-8          	   62060	     19186 ns/op	     224 B/op	       2 allocs/op
BenchmarkEncapsulate/6688128-8            	   43240	     28237 ns/op	     240 B/op	       2 allocs/op
BenchmarkEncapsulate/6688128f-8           	   43110	     27648 ns/op	     240 B/op	       2 allocs/op
BenchmarkEncapsulate/6688128pc-8          	   38628	     31316 ns/op	     272 B/op	       2 allocs/op
BenchmarkEncapsulate/6688128pcf-8         	   38240	     30695 ns/op	     272 B/op	       2 allocs/op
BenchmarkEncapsulate/6960119-8            	   43016	     27572 ns/op	     240 B/op	       2 allocs/op
BenchmarkEncapsulate/6960119f-8           	   44558	     27598 ns/op	     240 B/op	       2 allocs/op
BenchmarkEncapsulate/6960119pc-8          	   38373	     30286 ns/op	     272 B/op	       2 allocs/op
BenchmarkEncapsulate/6960119pcf-8         	   39642	     30545 ns/op	     272 B/op	       2 allocs/op
BenchmarkEncapsulate/8192128-8            	   39162	     30688 ns/op	     240 B/op	       2 allocs/op
BenchmarkEncapsulate/8192128f-8           	   40713	     30256 ns/op	     240 B/op	       2 allocs/op
BenchmarkEncapsulate/8192128pc-8          	   36350	     32975 ns/op	     272 B/op	       2 allocs/op
BenchmarkEncapsulate/8192128pcf-8         	   36024	     32996 ns/op	     272 B/op	       2 allocs/op
BenchmarkDecapsulate/348864-8             	   40624	     29708 ns/op	      32 B/op	       1 allocs/op
BenchmarkDecapsulate/348864f-8            	   40581	     30115 ns/op	      32 B/op	       1 allocs/op
BenchmarkDecapsulate/348864pc-8           	   39066	     31645 ns/op	      32 B/op	       1 allocs/op
BenchmarkDecapsulate/348864pcf-8          	   38629	     31267 ns/op	      32 B/op	       1 allocs/op
BenchmarkDecapsulate/460896-8             	   19645	     59572 ns/op	      32 B/op	       1 allocs/op
BenchmarkDecapsulate/460896f-8            	   19862	     60849 ns/op	      32 B/op	       1 allocs/op
BenchmarkDecapsulate/460896pc-8           	   19555	     61291 ns/op	      32 B/op	       1 allocs/op
BenchmarkDecapsulate/460896pcf-8          	   19196	     62043 ns/op	      32 B/op	       1 allocs/op
BenchmarkDecapsulate/6688128-8            	   16971	     71095 ns/op	      32 B/op	       1 allocs/op
BenchmarkDecapsulate/6688128f-8           	   17301	     71197 ns/op	      32 B/op	       1 allocs/op
BenchmarkDecapsulate/6688128pc-8          	   16252	     72932 ns/op	      32 B/op	       1 allocs/op
BenchmarkDecapsulate/6688128pcf-8         	   16180	     74648 ns/op	      32 B/op	       1 allocs/op
BenchmarkDecapsulate/6960119-8            	   17912	     65572 ns/op	      32 B/op	       1 allocs/op
BenchmarkDecapsulate/6960119f-8           	   18310	     65439 ns/op	      32 B/op	       1 allocs/op
BenchmarkDecapsulate/6960119pc-8          	   17192	     68869 ns/op	      32 B/op	       1 allocs/op
BenchmarkDecapsulate/6960119pcf-8         	   17108	     70091 ns/op	      32 B/op	       1 allocs/op
BenchmarkDecapsulate/8192128-8            	   16969	     71775 ns/op	      32 B/op	       1 allocs/op
BenchmarkDecapsulate/8192128f-8           	   17293	     71457 ns/op	      32 B/op	       1 allocs/op
BenchmarkDecapsulate/8192128pc-8          	   15475	     75567 ns/op	      32 B/op	       1 allocs/op
BenchmarkDecapsulate/8192128pcf-8         	   15982	     79006 ns/op	      32 B/op	       1 allocs/op
```
