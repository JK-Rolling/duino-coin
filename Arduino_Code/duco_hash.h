#pragma once

#include <Arduino.h>

#define SHA1_BLOCK_LEN 64
#define SHA1_HASH_LEN 20

struct duco_hash_state_t {
	uint8_t buffer[SHA1_BLOCK_LEN];
	uint8_t result[SHA1_HASH_LEN];
	uint32_t tempState[5];

	uint8_t block_offset;
	uint8_t total_bytes;
};

#ifdef __cplusplus
extern "C" {
#endif
// Declare external assembly functions
extern uint32_t sha1_rotl5(uint32_t val);
extern uint32_t sha1_rotl30(uint32_t val);
#ifdef __cplusplus
}
#endif

void duco_hash_init(duco_hash_state_t * hasher, char const * prevHash);

uint8_t const * duco_hash_try_nonce(duco_hash_state_t * hasher, char const * nonce);
