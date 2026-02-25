package mceliece

import (
	"bytes"
	"testing"
)

var allVariants = []struct {
	name    string
	variant Variant
}{
	{"348864", Variant348864},
	{"348864f", Variant348864f},
	{"348864pc", Variant348864pc},
	{"348864pcf", Variant348864pcf},
	{"460896", Variant460896},
	{"460896f", Variant460896f},
	{"460896pc", Variant460896pc},
	{"460896pcf", Variant460896pcf},
	{"6688128", Variant6688128},
	{"6688128f", Variant6688128f},
	{"6688128pc", Variant6688128pc},
	{"6688128pcf", Variant6688128pcf},
	{"6960119", Variant6960119},
	{"6960119f", Variant6960119f},
	{"6960119pc", Variant6960119pc},
	{"6960119pcf", Variant6960119pcf},
	{"8192128", Variant8192128},
	{"8192128f", Variant8192128f},
	{"8192128pc", Variant8192128pc},
	{"8192128pcf", Variant8192128pcf},
}

func TestRoundTrip(t *testing.T) {
	for _, tc := range allVariants {
		tc := tc
		t.Run(tc.name, func(t *testing.T) {
			kem := New(tc.variant)

			pk, sk, err := kem.GenerateKeyPair()
			if err != nil {
				t.Fatalf("GenerateKeyPair: %v", err)
			}
			if len(pk) != kem.PublicKeySize() {
				t.Errorf("pk length = %d, want %d", len(pk), kem.PublicKeySize())
			}
			if len(sk) != kem.SecretKeySize() {
				t.Errorf("sk length = %d, want %d", len(sk), kem.SecretKeySize())
			}

			ct, ss1, err := kem.Encapsulate(pk)
			if err != nil {
				t.Fatalf("Encapsulate: %v", err)
			}
			if len(ct) != kem.CiphertextSize() {
				t.Errorf("ct length = %d, want %d", len(ct), kem.CiphertextSize())
			}
			if len(ss1) != kem.SharedSecretSize() {
				t.Errorf("ss1 length = %d, want %d", len(ss1), kem.SharedSecretSize())
			}

			ss2, err := kem.Decapsulate(ct, sk)
			if err != nil {
				t.Fatalf("Decapsulate: %v", err)
			}
			if len(ss2) != kem.SharedSecretSize() {
				t.Errorf("ss2 length = %d, want %d", len(ss2), kem.SharedSecretSize())
			}

			if !bytes.Equal(ss1, ss2) {
				t.Error("shared secrets do not match")
			}
		})
	}
}

func TestInvalidInputs(t *testing.T) {
	kem := New(Variant348864)

	pk, sk, err := kem.GenerateKeyPair()
	if err != nil {
		t.Fatalf("GenerateKeyPair: %v", err)
	}

	// Wrong public key size for Encapsulate
	_, _, err = kem.Encapsulate(pk[:10])
	if err == nil {
		t.Error("Encapsulate with short pk: expected error, got nil")
	}

	ct, _, err := kem.Encapsulate(pk)
	if err != nil {
		t.Fatalf("Encapsulate: %v", err)
	}

	// Wrong ciphertext size for Decapsulate
	_, err = kem.Decapsulate(ct[:10], sk)
	if err == nil {
		t.Error("Decapsulate with short ct: expected error, got nil")
	}

	// Wrong secret key size for Decapsulate
	_, err = kem.Decapsulate(ct, sk[:10])
	if err == nil {
		t.Error("Decapsulate with short sk: expected error, got nil")
	}
}
