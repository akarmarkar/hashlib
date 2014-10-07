
unsigned hash(const char *s)
{
    const unsigned char *p;
    unsigned hashval = 0;
    for (p = (const unsigned char *) s; *p; p++)
        hashval = *p + 31u * hashval;
    return hashval;
}