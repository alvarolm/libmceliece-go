package mceliece

import "testing"

func BenchmarkDecapsulate(b *testing.B) {
	for _, tc := range allVariants {
		tc := tc
		b.Run(tc.name, func(b *testing.B) {
			kem := New(tc.variant)
			pk, sk, err := kem.GenerateKeyPair()
			if err != nil {
				b.Fatal(err)
			}
			ct, _, err := kem.Encapsulate(pk)
			if err != nil {
				b.Fatal(err)
			}
			b.ResetTimer()
			for i := 0; i < b.N; i++ {
				kem.Decapsulate(ct, sk)
			}
		})
	}
}
