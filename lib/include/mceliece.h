/*

All of the stable libmceliece API functions have names beginning

    mceliece{6960119,6688128,8192128,460896,348864}

whereas functions beginning mceliece_ (e.g., functions used for internal
tests and benchmarks) may change.

*/

#ifndef mceliece_h
#define mceliece_h

#ifdef __cplusplus
extern "C" {
#endif

#define mceliece6960119_keypair mceliece_kem_6960119_keypair
#define mceliece6960119_enc mceliece_kem_6960119_enc
#define mceliece6960119_dec mceliece_kem_6960119_dec
#define mceliece6960119_SECRETKEYBYTES mceliece_kem_6960119_SECRETKEYBYTES
#define mceliece6960119_PUBLICKEYBYTES mceliece_kem_6960119_PUBLICKEYBYTES
#define mceliece6960119_CIPHERTEXTBYTES mceliece_kem_6960119_CIPHERTEXTBYTES
#define mceliece6960119_BYTES mceliece_kem_6960119_BYTES
#define mceliece6960119f_keypair mceliece_kem_6960119f_keypair
#define mceliece6960119f_enc mceliece_kem_6960119f_enc
#define mceliece6960119f_dec mceliece_kem_6960119f_dec
#define mceliece6960119f_SECRETKEYBYTES mceliece_kem_6960119f_SECRETKEYBYTES
#define mceliece6960119f_PUBLICKEYBYTES mceliece_kem_6960119f_PUBLICKEYBYTES
#define mceliece6960119f_CIPHERTEXTBYTES mceliece_kem_6960119f_CIPHERTEXTBYTES
#define mceliece6960119f_BYTES mceliece_kem_6960119f_BYTES
#define mceliece6960119pc_keypair mceliece_kem_6960119pc_keypair
#define mceliece6960119pc_enc mceliece_kem_6960119pc_enc
#define mceliece6960119pc_dec mceliece_kem_6960119pc_dec
#define mceliece6960119pc_SECRETKEYBYTES mceliece_kem_6960119pc_SECRETKEYBYTES
#define mceliece6960119pc_PUBLICKEYBYTES mceliece_kem_6960119pc_PUBLICKEYBYTES
#define mceliece6960119pc_CIPHERTEXTBYTES mceliece_kem_6960119pc_CIPHERTEXTBYTES
#define mceliece6960119pc_BYTES mceliece_kem_6960119pc_BYTES
#define mceliece6960119pcf_keypair mceliece_kem_6960119pcf_keypair
#define mceliece6960119pcf_enc mceliece_kem_6960119pcf_enc
#define mceliece6960119pcf_dec mceliece_kem_6960119pcf_dec
#define mceliece6960119pcf_SECRETKEYBYTES mceliece_kem_6960119pcf_SECRETKEYBYTES
#define mceliece6960119pcf_PUBLICKEYBYTES mceliece_kem_6960119pcf_PUBLICKEYBYTES
#define mceliece6960119pcf_CIPHERTEXTBYTES mceliece_kem_6960119pcf_CIPHERTEXTBYTES
#define mceliece6960119pcf_BYTES mceliece_kem_6960119pcf_BYTES

#define mceliece6688128_keypair mceliece_kem_6688128_keypair
#define mceliece6688128_enc mceliece_kem_6688128_enc
#define mceliece6688128_dec mceliece_kem_6688128_dec
#define mceliece6688128_SECRETKEYBYTES mceliece_kem_6688128_SECRETKEYBYTES
#define mceliece6688128_PUBLICKEYBYTES mceliece_kem_6688128_PUBLICKEYBYTES
#define mceliece6688128_CIPHERTEXTBYTES mceliece_kem_6688128_CIPHERTEXTBYTES
#define mceliece6688128_BYTES mceliece_kem_6688128_BYTES
#define mceliece6688128f_keypair mceliece_kem_6688128f_keypair
#define mceliece6688128f_enc mceliece_kem_6688128f_enc
#define mceliece6688128f_dec mceliece_kem_6688128f_dec
#define mceliece6688128f_SECRETKEYBYTES mceliece_kem_6688128f_SECRETKEYBYTES
#define mceliece6688128f_PUBLICKEYBYTES mceliece_kem_6688128f_PUBLICKEYBYTES
#define mceliece6688128f_CIPHERTEXTBYTES mceliece_kem_6688128f_CIPHERTEXTBYTES
#define mceliece6688128f_BYTES mceliece_kem_6688128f_BYTES
#define mceliece6688128pc_keypair mceliece_kem_6688128pc_keypair
#define mceliece6688128pc_enc mceliece_kem_6688128pc_enc
#define mceliece6688128pc_dec mceliece_kem_6688128pc_dec
#define mceliece6688128pc_SECRETKEYBYTES mceliece_kem_6688128pc_SECRETKEYBYTES
#define mceliece6688128pc_PUBLICKEYBYTES mceliece_kem_6688128pc_PUBLICKEYBYTES
#define mceliece6688128pc_CIPHERTEXTBYTES mceliece_kem_6688128pc_CIPHERTEXTBYTES
#define mceliece6688128pc_BYTES mceliece_kem_6688128pc_BYTES
#define mceliece6688128pcf_keypair mceliece_kem_6688128pcf_keypair
#define mceliece6688128pcf_enc mceliece_kem_6688128pcf_enc
#define mceliece6688128pcf_dec mceliece_kem_6688128pcf_dec
#define mceliece6688128pcf_SECRETKEYBYTES mceliece_kem_6688128pcf_SECRETKEYBYTES
#define mceliece6688128pcf_PUBLICKEYBYTES mceliece_kem_6688128pcf_PUBLICKEYBYTES
#define mceliece6688128pcf_CIPHERTEXTBYTES mceliece_kem_6688128pcf_CIPHERTEXTBYTES
#define mceliece6688128pcf_BYTES mceliece_kem_6688128pcf_BYTES

#define mceliece8192128_keypair mceliece_kem_8192128_keypair
#define mceliece8192128_enc mceliece_kem_8192128_enc
#define mceliece8192128_dec mceliece_kem_8192128_dec
#define mceliece8192128_SECRETKEYBYTES mceliece_kem_8192128_SECRETKEYBYTES
#define mceliece8192128_PUBLICKEYBYTES mceliece_kem_8192128_PUBLICKEYBYTES
#define mceliece8192128_CIPHERTEXTBYTES mceliece_kem_8192128_CIPHERTEXTBYTES
#define mceliece8192128_BYTES mceliece_kem_8192128_BYTES
#define mceliece8192128f_keypair mceliece_kem_8192128f_keypair
#define mceliece8192128f_enc mceliece_kem_8192128f_enc
#define mceliece8192128f_dec mceliece_kem_8192128f_dec
#define mceliece8192128f_SECRETKEYBYTES mceliece_kem_8192128f_SECRETKEYBYTES
#define mceliece8192128f_PUBLICKEYBYTES mceliece_kem_8192128f_PUBLICKEYBYTES
#define mceliece8192128f_CIPHERTEXTBYTES mceliece_kem_8192128f_CIPHERTEXTBYTES
#define mceliece8192128f_BYTES mceliece_kem_8192128f_BYTES
#define mceliece8192128pc_keypair mceliece_kem_8192128pc_keypair
#define mceliece8192128pc_enc mceliece_kem_8192128pc_enc
#define mceliece8192128pc_dec mceliece_kem_8192128pc_dec
#define mceliece8192128pc_SECRETKEYBYTES mceliece_kem_8192128pc_SECRETKEYBYTES
#define mceliece8192128pc_PUBLICKEYBYTES mceliece_kem_8192128pc_PUBLICKEYBYTES
#define mceliece8192128pc_CIPHERTEXTBYTES mceliece_kem_8192128pc_CIPHERTEXTBYTES
#define mceliece8192128pc_BYTES mceliece_kem_8192128pc_BYTES
#define mceliece8192128pcf_keypair mceliece_kem_8192128pcf_keypair
#define mceliece8192128pcf_enc mceliece_kem_8192128pcf_enc
#define mceliece8192128pcf_dec mceliece_kem_8192128pcf_dec
#define mceliece8192128pcf_SECRETKEYBYTES mceliece_kem_8192128pcf_SECRETKEYBYTES
#define mceliece8192128pcf_PUBLICKEYBYTES mceliece_kem_8192128pcf_PUBLICKEYBYTES
#define mceliece8192128pcf_CIPHERTEXTBYTES mceliece_kem_8192128pcf_CIPHERTEXTBYTES
#define mceliece8192128pcf_BYTES mceliece_kem_8192128pcf_BYTES

#define mceliece460896_keypair mceliece_kem_460896_keypair
#define mceliece460896_enc mceliece_kem_460896_enc
#define mceliece460896_dec mceliece_kem_460896_dec
#define mceliece460896_SECRETKEYBYTES mceliece_kem_460896_SECRETKEYBYTES
#define mceliece460896_PUBLICKEYBYTES mceliece_kem_460896_PUBLICKEYBYTES
#define mceliece460896_CIPHERTEXTBYTES mceliece_kem_460896_CIPHERTEXTBYTES
#define mceliece460896_BYTES mceliece_kem_460896_BYTES
#define mceliece460896f_keypair mceliece_kem_460896f_keypair
#define mceliece460896f_enc mceliece_kem_460896f_enc
#define mceliece460896f_dec mceliece_kem_460896f_dec
#define mceliece460896f_SECRETKEYBYTES mceliece_kem_460896f_SECRETKEYBYTES
#define mceliece460896f_PUBLICKEYBYTES mceliece_kem_460896f_PUBLICKEYBYTES
#define mceliece460896f_CIPHERTEXTBYTES mceliece_kem_460896f_CIPHERTEXTBYTES
#define mceliece460896f_BYTES mceliece_kem_460896f_BYTES
#define mceliece460896pc_keypair mceliece_kem_460896pc_keypair
#define mceliece460896pc_enc mceliece_kem_460896pc_enc
#define mceliece460896pc_dec mceliece_kem_460896pc_dec
#define mceliece460896pc_SECRETKEYBYTES mceliece_kem_460896pc_SECRETKEYBYTES
#define mceliece460896pc_PUBLICKEYBYTES mceliece_kem_460896pc_PUBLICKEYBYTES
#define mceliece460896pc_CIPHERTEXTBYTES mceliece_kem_460896pc_CIPHERTEXTBYTES
#define mceliece460896pc_BYTES mceliece_kem_460896pc_BYTES
#define mceliece460896pcf_keypair mceliece_kem_460896pcf_keypair
#define mceliece460896pcf_enc mceliece_kem_460896pcf_enc
#define mceliece460896pcf_dec mceliece_kem_460896pcf_dec
#define mceliece460896pcf_SECRETKEYBYTES mceliece_kem_460896pcf_SECRETKEYBYTES
#define mceliece460896pcf_PUBLICKEYBYTES mceliece_kem_460896pcf_PUBLICKEYBYTES
#define mceliece460896pcf_CIPHERTEXTBYTES mceliece_kem_460896pcf_CIPHERTEXTBYTES
#define mceliece460896pcf_BYTES mceliece_kem_460896pcf_BYTES

#define mceliece348864_keypair mceliece_kem_348864_keypair
#define mceliece348864_enc mceliece_kem_348864_enc
#define mceliece348864_dec mceliece_kem_348864_dec
#define mceliece348864_SECRETKEYBYTES mceliece_kem_348864_SECRETKEYBYTES
#define mceliece348864_PUBLICKEYBYTES mceliece_kem_348864_PUBLICKEYBYTES
#define mceliece348864_CIPHERTEXTBYTES mceliece_kem_348864_CIPHERTEXTBYTES
#define mceliece348864_BYTES mceliece_kem_348864_BYTES
#define mceliece348864f_keypair mceliece_kem_348864f_keypair
#define mceliece348864f_enc mceliece_kem_348864f_enc
#define mceliece348864f_dec mceliece_kem_348864f_dec
#define mceliece348864f_SECRETKEYBYTES mceliece_kem_348864f_SECRETKEYBYTES
#define mceliece348864f_PUBLICKEYBYTES mceliece_kem_348864f_PUBLICKEYBYTES
#define mceliece348864f_CIPHERTEXTBYTES mceliece_kem_348864f_CIPHERTEXTBYTES
#define mceliece348864f_BYTES mceliece_kem_348864f_BYTES
#define mceliece348864pc_keypair mceliece_kem_348864pc_keypair
#define mceliece348864pc_enc mceliece_kem_348864pc_enc
#define mceliece348864pc_dec mceliece_kem_348864pc_dec
#define mceliece348864pc_SECRETKEYBYTES mceliece_kem_348864pc_SECRETKEYBYTES
#define mceliece348864pc_PUBLICKEYBYTES mceliece_kem_348864pc_PUBLICKEYBYTES
#define mceliece348864pc_CIPHERTEXTBYTES mceliece_kem_348864pc_CIPHERTEXTBYTES
#define mceliece348864pc_BYTES mceliece_kem_348864pc_BYTES
#define mceliece348864pcf_keypair mceliece_kem_348864pcf_keypair
#define mceliece348864pcf_enc mceliece_kem_348864pcf_enc
#define mceliece348864pcf_dec mceliece_kem_348864pcf_dec
#define mceliece348864pcf_SECRETKEYBYTES mceliece_kem_348864pcf_SECRETKEYBYTES
#define mceliece348864pcf_PUBLICKEYBYTES mceliece_kem_348864pcf_PUBLICKEYBYTES
#define mceliece348864pcf_CIPHERTEXTBYTES mceliece_kem_348864pcf_CIPHERTEXTBYTES
#define mceliece348864pcf_BYTES mceliece_kem_348864pcf_BYTES

#define mceliece_version "20250507"
#define mceliece_arch "amd64"

extern void mceliece_cpuid(unsigned int *,long long);

#define mceliece_xof mceliece_xof_shake256
#define mceliece_dispatch_xof mceliece_dispatch_xof_shake256

extern void mceliece_xof_shake256(unsigned char *,long long,const unsigned char *,long long);
extern void (*mceliece_dispatch_xof_shake256(long long))(unsigned char *,long long,const unsigned char *,long long);

#define mceliece_xof_implementation mceliece_xof_shake256_implementation
#define mceliece_xof_compiler mceliece_xof_shake256_compiler
#define mceliece_dispatch_xof_implementation mceliece_dispatch_xof_shake256_implementation
#define mceliece_dispatch_xof_compiler mceliece_dispatch_xof_shake256_compiler
#define mceliece_numimpl_xof mceliece_numimpl_xof_shake256

extern const char *mceliece_xof_shake256_implementation(void);
extern const char *mceliece_xof_shake256_compiler(void);
extern const char *mceliece_dispatch_xof_shake256_implementation(long long);
extern const char *mceliece_dispatch_xof_shake256_compiler(long long);
extern long long mceliece_numimpl_xof_shake256(void);

extern void mceliece_xof_bitwrite16(unsigned char *,long long,const unsigned char *,long long);
extern void (*mceliece_dispatch_xof_bitwrite16(long long))(unsigned char *,long long,const unsigned char *,long long);

extern const char *mceliece_xof_bitwrite16_implementation(void);
extern const char *mceliece_xof_bitwrite16_compiler(void);
extern const char *mceliece_dispatch_xof_bitwrite16_implementation(long long);
extern const char *mceliece_dispatch_xof_bitwrite16_compiler(long long);
extern long long mceliece_numimpl_xof_bitwrite16(void);

#define mceliece_sort_BYTES 2

#define mceliece_sort_int16_BYTES 2

#define mceliece_sort mceliece_sort_int16
#define mceliece_dispatch_sort mceliece_dispatch_sort_int16

extern void mceliece_sort_int16(void *,long long);
extern void (*mceliece_dispatch_sort_int16(long long))(void *,long long);

#define mceliece_sort_implementation mceliece_sort_int16_implementation
#define mceliece_sort_compiler mceliece_sort_int16_compiler
#define mceliece_dispatch_sort_implementation mceliece_dispatch_sort_int16_implementation
#define mceliece_dispatch_sort_compiler mceliece_dispatch_sort_int16_compiler
#define mceliece_numimpl_sort mceliece_numimpl_sort_int16

extern const char *mceliece_sort_int16_implementation(void);
extern const char *mceliece_sort_int16_compiler(void);
extern const char *mceliece_dispatch_sort_int16_implementation(long long);
extern const char *mceliece_dispatch_sort_int16_compiler(long long);
extern long long mceliece_numimpl_sort_int16(void);

#define mceliece_sort_int32_BYTES 4

extern void mceliece_sort_int32(void *,long long);
extern void (*mceliece_dispatch_sort_int32(long long))(void *,long long);

extern const char *mceliece_sort_int32_implementation(void);
extern const char *mceliece_sort_int32_compiler(void);
extern const char *mceliece_dispatch_sort_int32_implementation(long long);
extern const char *mceliece_dispatch_sort_int32_compiler(long long);
extern long long mceliece_numimpl_sort_int32(void);

#define mceliece_sort_int64_BYTES 8

extern void mceliece_sort_int64(void *,long long);
extern void (*mceliece_dispatch_sort_int64(long long))(void *,long long);

extern const char *mceliece_sort_int64_implementation(void);
extern const char *mceliece_sort_int64_compiler(void);
extern const char *mceliece_dispatch_sort_int64_implementation(long long);
extern const char *mceliece_dispatch_sort_int64_compiler(long long);
extern long long mceliece_numimpl_sort_int64(void);

#define mceliece_kem_PUBLICKEYBYTES 1047319
#define mceliece_kem_SECRETKEYBYTES 13948
#define mceliece_kem_CIPHERTEXTBYTES 194
#define mceliece_kem_BYTES 32

#define mceliece_kem_6960119_PUBLICKEYBYTES 1047319
#define mceliece_kem_6960119_SECRETKEYBYTES 13948
#define mceliece_kem_6960119_CIPHERTEXTBYTES 194
#define mceliece_kem_6960119_BYTES 32

#define mceliece_kem_keypair mceliece_kem_6960119_keypair
#define mceliece_dispatch_kem_keypair mceliece_dispatch_kem_6960119_keypair

extern void mceliece_kem_6960119_keypair(unsigned char *,unsigned char *);
extern void (*mceliece_dispatch_kem_6960119_keypair(long long))(unsigned char *,unsigned char *);

#define mceliece_kem_enc mceliece_kem_6960119_enc
#define mceliece_dispatch_kem_enc mceliece_dispatch_kem_6960119_enc

extern int mceliece_kem_6960119_enc(unsigned char *,unsigned char *,const unsigned char *);
extern int (*mceliece_dispatch_kem_6960119_enc(long long))(unsigned char *,unsigned char *,const unsigned char *);

#define mceliece_kem_dec mceliece_kem_6960119_dec
#define mceliece_dispatch_kem_dec mceliece_dispatch_kem_6960119_dec

extern int mceliece_kem_6960119_dec(unsigned char *,const unsigned char *,const unsigned char *);
extern int (*mceliece_dispatch_kem_6960119_dec(long long))(unsigned char *,const unsigned char *,const unsigned char *);

#define mceliece_kem_implementation mceliece_kem_6960119_implementation
#define mceliece_kem_compiler mceliece_kem_6960119_compiler
#define mceliece_dispatch_kem_implementation mceliece_dispatch_kem_6960119_implementation
#define mceliece_dispatch_kem_compiler mceliece_dispatch_kem_6960119_compiler
#define mceliece_numimpl_kem mceliece_numimpl_kem_6960119

extern const char *mceliece_kem_6960119_implementation(void);
extern const char *mceliece_kem_6960119_compiler(void);
extern const char *mceliece_dispatch_kem_6960119_implementation(long long);
extern const char *mceliece_dispatch_kem_6960119_compiler(long long);
extern long long mceliece_numimpl_kem_6960119(void);

#define mceliece_kem_6960119f_PUBLICKEYBYTES 1047319
#define mceliece_kem_6960119f_SECRETKEYBYTES 13948
#define mceliece_kem_6960119f_CIPHERTEXTBYTES 194
#define mceliece_kem_6960119f_BYTES 32

extern void mceliece_kem_6960119f_keypair(unsigned char *,unsigned char *);
extern void (*mceliece_dispatch_kem_6960119f_keypair(long long))(unsigned char *,unsigned char *);

extern int mceliece_kem_6960119f_enc(unsigned char *,unsigned char *,const unsigned char *);
extern int (*mceliece_dispatch_kem_6960119f_enc(long long))(unsigned char *,unsigned char *,const unsigned char *);

extern int mceliece_kem_6960119f_dec(unsigned char *,const unsigned char *,const unsigned char *);
extern int (*mceliece_dispatch_kem_6960119f_dec(long long))(unsigned char *,const unsigned char *,const unsigned char *);

extern const char *mceliece_kem_6960119f_implementation(void);
extern const char *mceliece_kem_6960119f_compiler(void);
extern const char *mceliece_dispatch_kem_6960119f_implementation(long long);
extern const char *mceliece_dispatch_kem_6960119f_compiler(long long);
extern long long mceliece_numimpl_kem_6960119f(void);

#define mceliece_kem_6960119pc_PUBLICKEYBYTES 1047319
#define mceliece_kem_6960119pc_SECRETKEYBYTES 13948
#define mceliece_kem_6960119pc_CIPHERTEXTBYTES 226
#define mceliece_kem_6960119pc_BYTES 32

extern void mceliece_kem_6960119pc_keypair(unsigned char *,unsigned char *);
extern void (*mceliece_dispatch_kem_6960119pc_keypair(long long))(unsigned char *,unsigned char *);

extern int mceliece_kem_6960119pc_enc(unsigned char *,unsigned char *,const unsigned char *);
extern int (*mceliece_dispatch_kem_6960119pc_enc(long long))(unsigned char *,unsigned char *,const unsigned char *);

extern int mceliece_kem_6960119pc_dec(unsigned char *,const unsigned char *,const unsigned char *);
extern int (*mceliece_dispatch_kem_6960119pc_dec(long long))(unsigned char *,const unsigned char *,const unsigned char *);

extern const char *mceliece_kem_6960119pc_implementation(void);
extern const char *mceliece_kem_6960119pc_compiler(void);
extern const char *mceliece_dispatch_kem_6960119pc_implementation(long long);
extern const char *mceliece_dispatch_kem_6960119pc_compiler(long long);
extern long long mceliece_numimpl_kem_6960119pc(void);

#define mceliece_kem_6960119pcf_PUBLICKEYBYTES 1047319
#define mceliece_kem_6960119pcf_SECRETKEYBYTES 13948
#define mceliece_kem_6960119pcf_CIPHERTEXTBYTES 226
#define mceliece_kem_6960119pcf_BYTES 32

extern void mceliece_kem_6960119pcf_keypair(unsigned char *,unsigned char *);
extern void (*mceliece_dispatch_kem_6960119pcf_keypair(long long))(unsigned char *,unsigned char *);

extern int mceliece_kem_6960119pcf_enc(unsigned char *,unsigned char *,const unsigned char *);
extern int (*mceliece_dispatch_kem_6960119pcf_enc(long long))(unsigned char *,unsigned char *,const unsigned char *);

extern int mceliece_kem_6960119pcf_dec(unsigned char *,const unsigned char *,const unsigned char *);
extern int (*mceliece_dispatch_kem_6960119pcf_dec(long long))(unsigned char *,const unsigned char *,const unsigned char *);

extern const char *mceliece_kem_6960119pcf_implementation(void);
extern const char *mceliece_kem_6960119pcf_compiler(void);
extern const char *mceliece_dispatch_kem_6960119pcf_implementation(long long);
extern const char *mceliece_dispatch_kem_6960119pcf_compiler(long long);
extern long long mceliece_numimpl_kem_6960119pcf(void);

#define mceliece_kem_6688128_PUBLICKEYBYTES 1044992
#define mceliece_kem_6688128_SECRETKEYBYTES 13932
#define mceliece_kem_6688128_CIPHERTEXTBYTES 208
#define mceliece_kem_6688128_BYTES 32

extern void mceliece_kem_6688128_keypair(unsigned char *,unsigned char *);
extern void (*mceliece_dispatch_kem_6688128_keypair(long long))(unsigned char *,unsigned char *);

extern int mceliece_kem_6688128_enc(unsigned char *,unsigned char *,const unsigned char *);
extern int (*mceliece_dispatch_kem_6688128_enc(long long))(unsigned char *,unsigned char *,const unsigned char *);

extern int mceliece_kem_6688128_dec(unsigned char *,const unsigned char *,const unsigned char *);
extern int (*mceliece_dispatch_kem_6688128_dec(long long))(unsigned char *,const unsigned char *,const unsigned char *);

extern const char *mceliece_kem_6688128_implementation(void);
extern const char *mceliece_kem_6688128_compiler(void);
extern const char *mceliece_dispatch_kem_6688128_implementation(long long);
extern const char *mceliece_dispatch_kem_6688128_compiler(long long);
extern long long mceliece_numimpl_kem_6688128(void);

#define mceliece_kem_6688128f_PUBLICKEYBYTES 1044992
#define mceliece_kem_6688128f_SECRETKEYBYTES 13932
#define mceliece_kem_6688128f_CIPHERTEXTBYTES 208
#define mceliece_kem_6688128f_BYTES 32

extern void mceliece_kem_6688128f_keypair(unsigned char *,unsigned char *);
extern void (*mceliece_dispatch_kem_6688128f_keypair(long long))(unsigned char *,unsigned char *);

extern int mceliece_kem_6688128f_enc(unsigned char *,unsigned char *,const unsigned char *);
extern int (*mceliece_dispatch_kem_6688128f_enc(long long))(unsigned char *,unsigned char *,const unsigned char *);

extern int mceliece_kem_6688128f_dec(unsigned char *,const unsigned char *,const unsigned char *);
extern int (*mceliece_dispatch_kem_6688128f_dec(long long))(unsigned char *,const unsigned char *,const unsigned char *);

extern const char *mceliece_kem_6688128f_implementation(void);
extern const char *mceliece_kem_6688128f_compiler(void);
extern const char *mceliece_dispatch_kem_6688128f_implementation(long long);
extern const char *mceliece_dispatch_kem_6688128f_compiler(long long);
extern long long mceliece_numimpl_kem_6688128f(void);

#define mceliece_kem_6688128pc_PUBLICKEYBYTES 1044992
#define mceliece_kem_6688128pc_SECRETKEYBYTES 13932
#define mceliece_kem_6688128pc_CIPHERTEXTBYTES 240
#define mceliece_kem_6688128pc_BYTES 32

extern void mceliece_kem_6688128pc_keypair(unsigned char *,unsigned char *);
extern void (*mceliece_dispatch_kem_6688128pc_keypair(long long))(unsigned char *,unsigned char *);

extern int mceliece_kem_6688128pc_enc(unsigned char *,unsigned char *,const unsigned char *);
extern int (*mceliece_dispatch_kem_6688128pc_enc(long long))(unsigned char *,unsigned char *,const unsigned char *);

extern int mceliece_kem_6688128pc_dec(unsigned char *,const unsigned char *,const unsigned char *);
extern int (*mceliece_dispatch_kem_6688128pc_dec(long long))(unsigned char *,const unsigned char *,const unsigned char *);

extern const char *mceliece_kem_6688128pc_implementation(void);
extern const char *mceliece_kem_6688128pc_compiler(void);
extern const char *mceliece_dispatch_kem_6688128pc_implementation(long long);
extern const char *mceliece_dispatch_kem_6688128pc_compiler(long long);
extern long long mceliece_numimpl_kem_6688128pc(void);

#define mceliece_kem_6688128pcf_PUBLICKEYBYTES 1044992
#define mceliece_kem_6688128pcf_SECRETKEYBYTES 13932
#define mceliece_kem_6688128pcf_CIPHERTEXTBYTES 240
#define mceliece_kem_6688128pcf_BYTES 32

extern void mceliece_kem_6688128pcf_keypair(unsigned char *,unsigned char *);
extern void (*mceliece_dispatch_kem_6688128pcf_keypair(long long))(unsigned char *,unsigned char *);

extern int mceliece_kem_6688128pcf_enc(unsigned char *,unsigned char *,const unsigned char *);
extern int (*mceliece_dispatch_kem_6688128pcf_enc(long long))(unsigned char *,unsigned char *,const unsigned char *);

extern int mceliece_kem_6688128pcf_dec(unsigned char *,const unsigned char *,const unsigned char *);
extern int (*mceliece_dispatch_kem_6688128pcf_dec(long long))(unsigned char *,const unsigned char *,const unsigned char *);

extern const char *mceliece_kem_6688128pcf_implementation(void);
extern const char *mceliece_kem_6688128pcf_compiler(void);
extern const char *mceliece_dispatch_kem_6688128pcf_implementation(long long);
extern const char *mceliece_dispatch_kem_6688128pcf_compiler(long long);
extern long long mceliece_numimpl_kem_6688128pcf(void);

#define mceliece_kem_8192128_PUBLICKEYBYTES 1357824
#define mceliece_kem_8192128_SECRETKEYBYTES 14120
#define mceliece_kem_8192128_CIPHERTEXTBYTES 208
#define mceliece_kem_8192128_BYTES 32

extern void mceliece_kem_8192128_keypair(unsigned char *,unsigned char *);
extern void (*mceliece_dispatch_kem_8192128_keypair(long long))(unsigned char *,unsigned char *);

extern int mceliece_kem_8192128_enc(unsigned char *,unsigned char *,const unsigned char *);
extern int (*mceliece_dispatch_kem_8192128_enc(long long))(unsigned char *,unsigned char *,const unsigned char *);

extern int mceliece_kem_8192128_dec(unsigned char *,const unsigned char *,const unsigned char *);
extern int (*mceliece_dispatch_kem_8192128_dec(long long))(unsigned char *,const unsigned char *,const unsigned char *);

extern const char *mceliece_kem_8192128_implementation(void);
extern const char *mceliece_kem_8192128_compiler(void);
extern const char *mceliece_dispatch_kem_8192128_implementation(long long);
extern const char *mceliece_dispatch_kem_8192128_compiler(long long);
extern long long mceliece_numimpl_kem_8192128(void);

#define mceliece_kem_8192128f_PUBLICKEYBYTES 1357824
#define mceliece_kem_8192128f_SECRETKEYBYTES 14120
#define mceliece_kem_8192128f_CIPHERTEXTBYTES 208
#define mceliece_kem_8192128f_BYTES 32

extern void mceliece_kem_8192128f_keypair(unsigned char *,unsigned char *);
extern void (*mceliece_dispatch_kem_8192128f_keypair(long long))(unsigned char *,unsigned char *);

extern int mceliece_kem_8192128f_enc(unsigned char *,unsigned char *,const unsigned char *);
extern int (*mceliece_dispatch_kem_8192128f_enc(long long))(unsigned char *,unsigned char *,const unsigned char *);

extern int mceliece_kem_8192128f_dec(unsigned char *,const unsigned char *,const unsigned char *);
extern int (*mceliece_dispatch_kem_8192128f_dec(long long))(unsigned char *,const unsigned char *,const unsigned char *);

extern const char *mceliece_kem_8192128f_implementation(void);
extern const char *mceliece_kem_8192128f_compiler(void);
extern const char *mceliece_dispatch_kem_8192128f_implementation(long long);
extern const char *mceliece_dispatch_kem_8192128f_compiler(long long);
extern long long mceliece_numimpl_kem_8192128f(void);

#define mceliece_kem_8192128pc_PUBLICKEYBYTES 1357824
#define mceliece_kem_8192128pc_SECRETKEYBYTES 14120
#define mceliece_kem_8192128pc_CIPHERTEXTBYTES 240
#define mceliece_kem_8192128pc_BYTES 32

extern void mceliece_kem_8192128pc_keypair(unsigned char *,unsigned char *);
extern void (*mceliece_dispatch_kem_8192128pc_keypair(long long))(unsigned char *,unsigned char *);

extern int mceliece_kem_8192128pc_enc(unsigned char *,unsigned char *,const unsigned char *);
extern int (*mceliece_dispatch_kem_8192128pc_enc(long long))(unsigned char *,unsigned char *,const unsigned char *);

extern int mceliece_kem_8192128pc_dec(unsigned char *,const unsigned char *,const unsigned char *);
extern int (*mceliece_dispatch_kem_8192128pc_dec(long long))(unsigned char *,const unsigned char *,const unsigned char *);

extern const char *mceliece_kem_8192128pc_implementation(void);
extern const char *mceliece_kem_8192128pc_compiler(void);
extern const char *mceliece_dispatch_kem_8192128pc_implementation(long long);
extern const char *mceliece_dispatch_kem_8192128pc_compiler(long long);
extern long long mceliece_numimpl_kem_8192128pc(void);

#define mceliece_kem_8192128pcf_PUBLICKEYBYTES 1357824
#define mceliece_kem_8192128pcf_SECRETKEYBYTES 14120
#define mceliece_kem_8192128pcf_CIPHERTEXTBYTES 240
#define mceliece_kem_8192128pcf_BYTES 32

extern void mceliece_kem_8192128pcf_keypair(unsigned char *,unsigned char *);
extern void (*mceliece_dispatch_kem_8192128pcf_keypair(long long))(unsigned char *,unsigned char *);

extern int mceliece_kem_8192128pcf_enc(unsigned char *,unsigned char *,const unsigned char *);
extern int (*mceliece_dispatch_kem_8192128pcf_enc(long long))(unsigned char *,unsigned char *,const unsigned char *);

extern int mceliece_kem_8192128pcf_dec(unsigned char *,const unsigned char *,const unsigned char *);
extern int (*mceliece_dispatch_kem_8192128pcf_dec(long long))(unsigned char *,const unsigned char *,const unsigned char *);

extern const char *mceliece_kem_8192128pcf_implementation(void);
extern const char *mceliece_kem_8192128pcf_compiler(void);
extern const char *mceliece_dispatch_kem_8192128pcf_implementation(long long);
extern const char *mceliece_dispatch_kem_8192128pcf_compiler(long long);
extern long long mceliece_numimpl_kem_8192128pcf(void);

#define mceliece_kem_460896_PUBLICKEYBYTES 524160
#define mceliece_kem_460896_SECRETKEYBYTES 13608
#define mceliece_kem_460896_CIPHERTEXTBYTES 156
#define mceliece_kem_460896_BYTES 32

extern void mceliece_kem_460896_keypair(unsigned char *,unsigned char *);
extern void (*mceliece_dispatch_kem_460896_keypair(long long))(unsigned char *,unsigned char *);

extern int mceliece_kem_460896_enc(unsigned char *,unsigned char *,const unsigned char *);
extern int (*mceliece_dispatch_kem_460896_enc(long long))(unsigned char *,unsigned char *,const unsigned char *);

extern int mceliece_kem_460896_dec(unsigned char *,const unsigned char *,const unsigned char *);
extern int (*mceliece_dispatch_kem_460896_dec(long long))(unsigned char *,const unsigned char *,const unsigned char *);

extern const char *mceliece_kem_460896_implementation(void);
extern const char *mceliece_kem_460896_compiler(void);
extern const char *mceliece_dispatch_kem_460896_implementation(long long);
extern const char *mceliece_dispatch_kem_460896_compiler(long long);
extern long long mceliece_numimpl_kem_460896(void);

#define mceliece_kem_460896f_PUBLICKEYBYTES 524160
#define mceliece_kem_460896f_SECRETKEYBYTES 13608
#define mceliece_kem_460896f_CIPHERTEXTBYTES 156
#define mceliece_kem_460896f_BYTES 32

extern void mceliece_kem_460896f_keypair(unsigned char *,unsigned char *);
extern void (*mceliece_dispatch_kem_460896f_keypair(long long))(unsigned char *,unsigned char *);

extern int mceliece_kem_460896f_enc(unsigned char *,unsigned char *,const unsigned char *);
extern int (*mceliece_dispatch_kem_460896f_enc(long long))(unsigned char *,unsigned char *,const unsigned char *);

extern int mceliece_kem_460896f_dec(unsigned char *,const unsigned char *,const unsigned char *);
extern int (*mceliece_dispatch_kem_460896f_dec(long long))(unsigned char *,const unsigned char *,const unsigned char *);

extern const char *mceliece_kem_460896f_implementation(void);
extern const char *mceliece_kem_460896f_compiler(void);
extern const char *mceliece_dispatch_kem_460896f_implementation(long long);
extern const char *mceliece_dispatch_kem_460896f_compiler(long long);
extern long long mceliece_numimpl_kem_460896f(void);

#define mceliece_kem_460896pc_PUBLICKEYBYTES 524160
#define mceliece_kem_460896pc_SECRETKEYBYTES 13608
#define mceliece_kem_460896pc_CIPHERTEXTBYTES 188
#define mceliece_kem_460896pc_BYTES 32

extern void mceliece_kem_460896pc_keypair(unsigned char *,unsigned char *);
extern void (*mceliece_dispatch_kem_460896pc_keypair(long long))(unsigned char *,unsigned char *);

extern int mceliece_kem_460896pc_enc(unsigned char *,unsigned char *,const unsigned char *);
extern int (*mceliece_dispatch_kem_460896pc_enc(long long))(unsigned char *,unsigned char *,const unsigned char *);

extern int mceliece_kem_460896pc_dec(unsigned char *,const unsigned char *,const unsigned char *);
extern int (*mceliece_dispatch_kem_460896pc_dec(long long))(unsigned char *,const unsigned char *,const unsigned char *);

extern const char *mceliece_kem_460896pc_implementation(void);
extern const char *mceliece_kem_460896pc_compiler(void);
extern const char *mceliece_dispatch_kem_460896pc_implementation(long long);
extern const char *mceliece_dispatch_kem_460896pc_compiler(long long);
extern long long mceliece_numimpl_kem_460896pc(void);

#define mceliece_kem_460896pcf_PUBLICKEYBYTES 524160
#define mceliece_kem_460896pcf_SECRETKEYBYTES 13608
#define mceliece_kem_460896pcf_CIPHERTEXTBYTES 188
#define mceliece_kem_460896pcf_BYTES 32

extern void mceliece_kem_460896pcf_keypair(unsigned char *,unsigned char *);
extern void (*mceliece_dispatch_kem_460896pcf_keypair(long long))(unsigned char *,unsigned char *);

extern int mceliece_kem_460896pcf_enc(unsigned char *,unsigned char *,const unsigned char *);
extern int (*mceliece_dispatch_kem_460896pcf_enc(long long))(unsigned char *,unsigned char *,const unsigned char *);

extern int mceliece_kem_460896pcf_dec(unsigned char *,const unsigned char *,const unsigned char *);
extern int (*mceliece_dispatch_kem_460896pcf_dec(long long))(unsigned char *,const unsigned char *,const unsigned char *);

extern const char *mceliece_kem_460896pcf_implementation(void);
extern const char *mceliece_kem_460896pcf_compiler(void);
extern const char *mceliece_dispatch_kem_460896pcf_implementation(long long);
extern const char *mceliece_dispatch_kem_460896pcf_compiler(long long);
extern long long mceliece_numimpl_kem_460896pcf(void);

#define mceliece_kem_348864_PUBLICKEYBYTES 261120
#define mceliece_kem_348864_SECRETKEYBYTES 6492
#define mceliece_kem_348864_CIPHERTEXTBYTES 96
#define mceliece_kem_348864_BYTES 32

extern void mceliece_kem_348864_keypair(unsigned char *,unsigned char *);
extern void (*mceliece_dispatch_kem_348864_keypair(long long))(unsigned char *,unsigned char *);

extern int mceliece_kem_348864_enc(unsigned char *,unsigned char *,const unsigned char *);
extern int (*mceliece_dispatch_kem_348864_enc(long long))(unsigned char *,unsigned char *,const unsigned char *);

extern int mceliece_kem_348864_dec(unsigned char *,const unsigned char *,const unsigned char *);
extern int (*mceliece_dispatch_kem_348864_dec(long long))(unsigned char *,const unsigned char *,const unsigned char *);

extern const char *mceliece_kem_348864_implementation(void);
extern const char *mceliece_kem_348864_compiler(void);
extern const char *mceliece_dispatch_kem_348864_implementation(long long);
extern const char *mceliece_dispatch_kem_348864_compiler(long long);
extern long long mceliece_numimpl_kem_348864(void);

#define mceliece_kem_348864f_PUBLICKEYBYTES 261120
#define mceliece_kem_348864f_SECRETKEYBYTES 6492
#define mceliece_kem_348864f_CIPHERTEXTBYTES 96
#define mceliece_kem_348864f_BYTES 32

extern void mceliece_kem_348864f_keypair(unsigned char *,unsigned char *);
extern void (*mceliece_dispatch_kem_348864f_keypair(long long))(unsigned char *,unsigned char *);

extern int mceliece_kem_348864f_enc(unsigned char *,unsigned char *,const unsigned char *);
extern int (*mceliece_dispatch_kem_348864f_enc(long long))(unsigned char *,unsigned char *,const unsigned char *);

extern int mceliece_kem_348864f_dec(unsigned char *,const unsigned char *,const unsigned char *);
extern int (*mceliece_dispatch_kem_348864f_dec(long long))(unsigned char *,const unsigned char *,const unsigned char *);

extern const char *mceliece_kem_348864f_implementation(void);
extern const char *mceliece_kem_348864f_compiler(void);
extern const char *mceliece_dispatch_kem_348864f_implementation(long long);
extern const char *mceliece_dispatch_kem_348864f_compiler(long long);
extern long long mceliece_numimpl_kem_348864f(void);

#define mceliece_kem_348864pc_PUBLICKEYBYTES 261120
#define mceliece_kem_348864pc_SECRETKEYBYTES 6492
#define mceliece_kem_348864pc_CIPHERTEXTBYTES 128
#define mceliece_kem_348864pc_BYTES 32

extern void mceliece_kem_348864pc_keypair(unsigned char *,unsigned char *);
extern void (*mceliece_dispatch_kem_348864pc_keypair(long long))(unsigned char *,unsigned char *);

extern int mceliece_kem_348864pc_enc(unsigned char *,unsigned char *,const unsigned char *);
extern int (*mceliece_dispatch_kem_348864pc_enc(long long))(unsigned char *,unsigned char *,const unsigned char *);

extern int mceliece_kem_348864pc_dec(unsigned char *,const unsigned char *,const unsigned char *);
extern int (*mceliece_dispatch_kem_348864pc_dec(long long))(unsigned char *,const unsigned char *,const unsigned char *);

extern const char *mceliece_kem_348864pc_implementation(void);
extern const char *mceliece_kem_348864pc_compiler(void);
extern const char *mceliece_dispatch_kem_348864pc_implementation(long long);
extern const char *mceliece_dispatch_kem_348864pc_compiler(long long);
extern long long mceliece_numimpl_kem_348864pc(void);

#define mceliece_kem_348864pcf_PUBLICKEYBYTES 261120
#define mceliece_kem_348864pcf_SECRETKEYBYTES 6492
#define mceliece_kem_348864pcf_CIPHERTEXTBYTES 128
#define mceliece_kem_348864pcf_BYTES 32

extern void mceliece_kem_348864pcf_keypair(unsigned char *,unsigned char *);
extern void (*mceliece_dispatch_kem_348864pcf_keypair(long long))(unsigned char *,unsigned char *);

extern int mceliece_kem_348864pcf_enc(unsigned char *,unsigned char *,const unsigned char *);
extern int (*mceliece_dispatch_kem_348864pcf_enc(long long))(unsigned char *,unsigned char *,const unsigned char *);

extern int mceliece_kem_348864pcf_dec(unsigned char *,const unsigned char *,const unsigned char *);
extern int (*mceliece_dispatch_kem_348864pcf_dec(long long))(unsigned char *,const unsigned char *,const unsigned char *);

extern const char *mceliece_kem_348864pcf_implementation(void);
extern const char *mceliece_kem_348864pcf_compiler(void);
extern const char *mceliece_dispatch_kem_348864pcf_implementation(long long);
extern const char *mceliece_dispatch_kem_348864pcf_compiler(long long);
extern long long mceliece_numimpl_kem_348864pcf(void);

#ifdef __cplusplus
}
#endif

#endif
