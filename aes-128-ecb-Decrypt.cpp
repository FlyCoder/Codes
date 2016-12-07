const std::string DoDecrypt(const std::string& cipher, const std::string& key) {
  buffer[128] = {0};
  int len1 = 0, len2 = 0;
  EVP_CIPHER_CTX ctx;
  EVP_DecryptInit(&ctx,
                  EVP_aes_128_ecb(),
                  reinterpret_cast<const uint8_t*>(key.data()),
                  nullptr);
  EVP_DecryptUpdate(&ctx,
                    reinterpret_cast<uint8_t*>(buffer),
                    &len1,
                    reinterpret_cast<const uint8_t*>(cipher.data()),
                    cipher.length());
  EVP_DecryptFinal(&ctx,
                   reinterpret_cast<uint8_t*>(buffer) + len1,
                   &len2);

  EVP_CIPHER_CTX_cleanup(&ctx);

  return std::string(buffer, len1 + len2);
}
