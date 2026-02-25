// Package mceliece provides a Go wrapper for the libmceliece Classic McEliece
// post-quantum key encapsulation mechanism (KEM).
package mceliece

// #cgo CFLAGS: -I${SRCDIR}/lib/include
// #cgo LDFLAGS: -L${SRCDIR}/lib/amd64 -lmceliece -lrandombytes-kernel
// #include <mceliece.h>
import "C"
import (
	"errors"
	"unsafe"
)

// Variant identifies one of the 20 Classic McEliece parameter sets.
type Variant int

const (
	Variant348864    Variant = iota
	Variant348864f
	Variant348864pc
	Variant348864pcf
	Variant460896
	Variant460896f
	Variant460896pc
	Variant460896pcf
	Variant6688128
	Variant6688128f
	Variant6688128pc
	Variant6688128pcf
	Variant6960119
	Variant6960119f
	Variant6960119pc
	Variant6960119pcf
	Variant8192128
	Variant8192128f
	Variant8192128pc
	Variant8192128pcf
)

// KEM holds the chosen parameter set and exposes the KEM operations.
type KEM struct {
	variant Variant
}

// New returns a KEM instance for the given variant.
func New(v Variant) *KEM {
	return &KEM{variant: v}
}

// PublicKeySize returns the public key size in bytes for this variant.
func (k *KEM) PublicKeySize() int {
	switch k.variant {
	case Variant348864, Variant348864f, Variant348864pc, Variant348864pcf:
		return 261120
	case Variant460896, Variant460896f, Variant460896pc, Variant460896pcf:
		return 524160
	case Variant6688128, Variant6688128f, Variant6688128pc, Variant6688128pcf:
		return 1044992
	case Variant6960119, Variant6960119f, Variant6960119pc, Variant6960119pcf:
		return 1047319
	case Variant8192128, Variant8192128f, Variant8192128pc, Variant8192128pcf:
		return 1357824
	default:
		panic("mceliece: unknown variant")
	}
}

// SecretKeySize returns the secret key size in bytes for this variant.
func (k *KEM) SecretKeySize() int {
	switch k.variant {
	case Variant348864, Variant348864f, Variant348864pc, Variant348864pcf:
		return 6492
	case Variant460896, Variant460896f, Variant460896pc, Variant460896pcf:
		return 13608
	case Variant6688128, Variant6688128f, Variant6688128pc, Variant6688128pcf:
		return 13932
	case Variant6960119, Variant6960119f, Variant6960119pc, Variant6960119pcf:
		return 13948
	case Variant8192128, Variant8192128f, Variant8192128pc, Variant8192128pcf:
		return 14120
	default:
		panic("mceliece: unknown variant")
	}
}

// CiphertextSize returns the ciphertext size in bytes for this variant.
func (k *KEM) CiphertextSize() int {
	switch k.variant {
	case Variant348864, Variant348864f:
		return 96
	case Variant348864pc, Variant348864pcf:
		return 128
	case Variant460896, Variant460896f:
		return 156
	case Variant460896pc, Variant460896pcf:
		return 188
	case Variant6688128, Variant6688128f:
		return 208
	case Variant6688128pc, Variant6688128pcf:
		return 240
	case Variant6960119, Variant6960119f:
		return 194
	case Variant6960119pc, Variant6960119pcf:
		return 226
	case Variant8192128, Variant8192128f:
		return 208
	case Variant8192128pc, Variant8192128pcf:
		return 240
	default:
		panic("mceliece: unknown variant")
	}
}

// SharedSecretSize returns 32 for all variants.
func (k *KEM) SharedSecretSize() int {
	return 32
}

// GenerateKeyPair generates a new key pair.
func (k *KEM) GenerateKeyPair() (publicKey, secretKey []byte, err error) {
	pk := make([]byte, k.PublicKeySize())
	sk := make([]byte, k.SecretKeySize())
	pkPtr := (*C.uchar)(unsafe.Pointer(&pk[0]))
	skPtr := (*C.uchar)(unsafe.Pointer(&sk[0]))

	switch k.variant {
	case Variant348864:
		C.mceliece348864_keypair(pkPtr, skPtr)
	case Variant348864f:
		C.mceliece348864f_keypair(pkPtr, skPtr)
	case Variant348864pc:
		C.mceliece348864pc_keypair(pkPtr, skPtr)
	case Variant348864pcf:
		C.mceliece348864pcf_keypair(pkPtr, skPtr)
	case Variant460896:
		C.mceliece460896_keypair(pkPtr, skPtr)
	case Variant460896f:
		C.mceliece460896f_keypair(pkPtr, skPtr)
	case Variant460896pc:
		C.mceliece460896pc_keypair(pkPtr, skPtr)
	case Variant460896pcf:
		C.mceliece460896pcf_keypair(pkPtr, skPtr)
	case Variant6688128:
		C.mceliece6688128_keypair(pkPtr, skPtr)
	case Variant6688128f:
		C.mceliece6688128f_keypair(pkPtr, skPtr)
	case Variant6688128pc:
		C.mceliece6688128pc_keypair(pkPtr, skPtr)
	case Variant6688128pcf:
		C.mceliece6688128pcf_keypair(pkPtr, skPtr)
	case Variant6960119:
		C.mceliece6960119_keypair(pkPtr, skPtr)
	case Variant6960119f:
		C.mceliece6960119f_keypair(pkPtr, skPtr)
	case Variant6960119pc:
		C.mceliece6960119pc_keypair(pkPtr, skPtr)
	case Variant6960119pcf:
		C.mceliece6960119pcf_keypair(pkPtr, skPtr)
	case Variant8192128:
		C.mceliece8192128_keypair(pkPtr, skPtr)
	case Variant8192128f:
		C.mceliece8192128f_keypair(pkPtr, skPtr)
	case Variant8192128pc:
		C.mceliece8192128pc_keypair(pkPtr, skPtr)
	case Variant8192128pcf:
		C.mceliece8192128pcf_keypair(pkPtr, skPtr)
	default:
		return nil, nil, errors.New("mceliece: unknown variant")
	}
	return pk, sk, nil
}

// Encapsulate generates a ciphertext and shared secret using the public key.
func (k *KEM) Encapsulate(publicKey []byte) (ciphertext, sharedSecret []byte, err error) {
	if len(publicKey) != k.PublicKeySize() {
		return nil, nil, errors.New("mceliece: invalid public key size")
	}
	ct := make([]byte, k.CiphertextSize())
	ss := make([]byte, k.SharedSecretSize())
	pkPtr := (*C.uchar)(unsafe.Pointer(&publicKey[0]))
	ctPtr := (*C.uchar)(unsafe.Pointer(&ct[0]))
	ssPtr := (*C.uchar)(unsafe.Pointer(&ss[0]))

	var ret C.int
	switch k.variant {
	case Variant348864:
		ret = C.mceliece348864_enc(ctPtr, ssPtr, pkPtr)
	case Variant348864f:
		ret = C.mceliece348864f_enc(ctPtr, ssPtr, pkPtr)
	case Variant348864pc:
		ret = C.mceliece348864pc_enc(ctPtr, ssPtr, pkPtr)
	case Variant348864pcf:
		ret = C.mceliece348864pcf_enc(ctPtr, ssPtr, pkPtr)
	case Variant460896:
		ret = C.mceliece460896_enc(ctPtr, ssPtr, pkPtr)
	case Variant460896f:
		ret = C.mceliece460896f_enc(ctPtr, ssPtr, pkPtr)
	case Variant460896pc:
		ret = C.mceliece460896pc_enc(ctPtr, ssPtr, pkPtr)
	case Variant460896pcf:
		ret = C.mceliece460896pcf_enc(ctPtr, ssPtr, pkPtr)
	case Variant6688128:
		ret = C.mceliece6688128_enc(ctPtr, ssPtr, pkPtr)
	case Variant6688128f:
		ret = C.mceliece6688128f_enc(ctPtr, ssPtr, pkPtr)
	case Variant6688128pc:
		ret = C.mceliece6688128pc_enc(ctPtr, ssPtr, pkPtr)
	case Variant6688128pcf:
		ret = C.mceliece6688128pcf_enc(ctPtr, ssPtr, pkPtr)
	case Variant6960119:
		ret = C.mceliece6960119_enc(ctPtr, ssPtr, pkPtr)
	case Variant6960119f:
		ret = C.mceliece6960119f_enc(ctPtr, ssPtr, pkPtr)
	case Variant6960119pc:
		ret = C.mceliece6960119pc_enc(ctPtr, ssPtr, pkPtr)
	case Variant6960119pcf:
		ret = C.mceliece6960119pcf_enc(ctPtr, ssPtr, pkPtr)
	case Variant8192128:
		ret = C.mceliece8192128_enc(ctPtr, ssPtr, pkPtr)
	case Variant8192128f:
		ret = C.mceliece8192128f_enc(ctPtr, ssPtr, pkPtr)
	case Variant8192128pc:
		ret = C.mceliece8192128pc_enc(ctPtr, ssPtr, pkPtr)
	case Variant8192128pcf:
		ret = C.mceliece8192128pcf_enc(ctPtr, ssPtr, pkPtr)
	default:
		return nil, nil, errors.New("mceliece: unknown variant")
	}
	if ret != 0 {
		return nil, nil, errors.New("mceliece: encapsulation failed (public key not narrowly decodable)")
	}
	return ct, ss, nil
}

// Decapsulate recovers the shared secret from a ciphertext using the secret key.
func (k *KEM) Decapsulate(ciphertext, secretKey []byte) (sharedSecret []byte, err error) {
	if len(ciphertext) != k.CiphertextSize() {
		return nil, errors.New("mceliece: invalid ciphertext size")
	}
	if len(secretKey) != k.SecretKeySize() {
		return nil, errors.New("mceliece: invalid secret key size")
	}
	ss := make([]byte, k.SharedSecretSize())
	ctPtr := (*C.uchar)(unsafe.Pointer(&ciphertext[0]))
	skPtr := (*C.uchar)(unsafe.Pointer(&secretKey[0]))
	ssPtr := (*C.uchar)(unsafe.Pointer(&ss[0]))

	var ret C.int
	switch k.variant {
	case Variant348864:
		ret = C.mceliece348864_dec(ssPtr, ctPtr, skPtr)
	case Variant348864f:
		ret = C.mceliece348864f_dec(ssPtr, ctPtr, skPtr)
	case Variant348864pc:
		ret = C.mceliece348864pc_dec(ssPtr, ctPtr, skPtr)
	case Variant348864pcf:
		ret = C.mceliece348864pcf_dec(ssPtr, ctPtr, skPtr)
	case Variant460896:
		ret = C.mceliece460896_dec(ssPtr, ctPtr, skPtr)
	case Variant460896f:
		ret = C.mceliece460896f_dec(ssPtr, ctPtr, skPtr)
	case Variant460896pc:
		ret = C.mceliece460896pc_dec(ssPtr, ctPtr, skPtr)
	case Variant460896pcf:
		ret = C.mceliece460896pcf_dec(ssPtr, ctPtr, skPtr)
	case Variant6688128:
		ret = C.mceliece6688128_dec(ssPtr, ctPtr, skPtr)
	case Variant6688128f:
		ret = C.mceliece6688128f_dec(ssPtr, ctPtr, skPtr)
	case Variant6688128pc:
		ret = C.mceliece6688128pc_dec(ssPtr, ctPtr, skPtr)
	case Variant6688128pcf:
		ret = C.mceliece6688128pcf_dec(ssPtr, ctPtr, skPtr)
	case Variant6960119:
		ret = C.mceliece6960119_dec(ssPtr, ctPtr, skPtr)
	case Variant6960119f:
		ret = C.mceliece6960119f_dec(ssPtr, ctPtr, skPtr)
	case Variant6960119pc:
		ret = C.mceliece6960119pc_dec(ssPtr, ctPtr, skPtr)
	case Variant6960119pcf:
		ret = C.mceliece6960119pcf_dec(ssPtr, ctPtr, skPtr)
	case Variant8192128:
		ret = C.mceliece8192128_dec(ssPtr, ctPtr, skPtr)
	case Variant8192128f:
		ret = C.mceliece8192128f_dec(ssPtr, ctPtr, skPtr)
	case Variant8192128pc:
		ret = C.mceliece8192128pc_dec(ssPtr, ctPtr, skPtr)
	case Variant8192128pcf:
		ret = C.mceliece8192128pcf_dec(ssPtr, ctPtr, skPtr)
	default:
		return nil, errors.New("mceliece: unknown variant")
	}
	if ret != 0 {
		return nil, errors.New("mceliece: decapsulation failed")
	}
	return ss, nil
}
