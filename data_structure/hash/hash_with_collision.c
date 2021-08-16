int add(const char* key, int value, size_t (*hash_func)(const char*, size_t))
{
    size_t i;
    size_t start_index;
    size_t hash_id;

    hash_id = hash_func(key, strlen(key));
    start_index = hash_id % BUCKET_SIZE;
    i = start_index;

    do {
        if (s_keys[i] == NULL) {
            /*새 key-value pair 추가*/
            return TRUE;
        }

        if (strcmp(s_keys[i], key) == 0) {
            return TRUE;  
        }

        i = (i + 1) % BUCKET_SIZE;

    } while (i != start_index);

    return FALSE;
}