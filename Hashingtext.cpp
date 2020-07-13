#define HASH_LENGTH 16
char *hash(char *input){
    // Alphabet and length
    const char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    const int alphabetLen = sizeof(alphabet)/sizeof(char) - 1;

    // Randomization variables and length
    const char vars[] = {
        0xA6,
        0xC1,
        0x5E,
        0x31,
        0xF5,
        0x88,
        0xA1,
        0xE2
    };
    const int varsLen = sizeof(vars)/sizeof(char);

    // Digest (where the hash is made)
    char *digest = (char*)malloc(sizeof(char) * (HASH_LENGTH + 1));

    // Input length calculation
    int inputLen = 0;
    while(input[inputLen] != '\0') inputLen++;

    // Digest cleaning
    int i;
    for(i = 0; i < HASH_LENGTH; i++){
        digest[i] = 0;  
    }

    // Hashing process
    int j;
    for(i = 0; i < HASH_LENGTH; i++){
        // XORs digest[i] with vars[input[j]]
        for(j = 0; j < HASH_LENGTH; j++){
            digest[i] ^= vars[input[j % inputLen] % varsLen];
        }
        // XORs digest[i] with input[i] + vars[i]
        digest[i] ^= input[i % inputLen] + vars[i % varsLen];
    }

    // Translates digest to desired alphabet
    for(i = 0; i < HASH_LENGTH; i++){
        j = digest[i] > 0 ? 1 : -1;
        digest[i] = alphabet[digest[i] * j % alphabetLen];
    }
    // Finalizes digest string
    *(digest + HASH_LENGTH) = '\0';

    return digest;
}