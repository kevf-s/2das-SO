int comparar(const void *a, const void *b){
const char *cp1 = a, *cp2 = b;

    for (; toupper(*cp1) == toupper(*cp2); cp1++, cp2++)
        if (*cp1 == '\0')
            return 0;
    return ((toupper(*cp1) < toupper(*cp2)) ? -1 : +1);
	
} 