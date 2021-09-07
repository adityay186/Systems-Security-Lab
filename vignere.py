def decrypt(ciphertext, key):
    key_length = len(key)
    key_as_int = [ord(i) for i in key]
    ciphertext_int = [ord(i) for i in ciphertext]
    plaintext = ''
    for i in range(len(ciphertext_int)):
        value = (ciphertext_int[i] - key_as_int[i % key_length]) % 26
        plaintext += chr(value + 65)
    return plaintext

print("Ciphertext : ", "HHWKSWXSLGNTCG")
print("Key : ", "PASCAL")
print()
print(decrypt("HHWKSWXSLGNTCG", "PASCAL"))
