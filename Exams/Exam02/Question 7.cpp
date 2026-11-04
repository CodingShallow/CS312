hash():

size_t hash(const string& str, size_t i)
{
    if (i >= str.length())
        return 0;

    char letter = tolower(str[str.length() - 1 - i]);

    return letter - 'a' + 1;
}


RadixSort Trace:

1. ["grade", "testing", "session", "assign", "monitor", "classes", "quiz"]

2. ["grade", "classes", "assign", "quiz", "testing", "session", "monitor"]

3. ["grade", "assign", "testing", "session", "classes", "monitor", "quiz"]

4. ["monitor", "quiz", "grade", "assign", "session", "classes", "testing"]

5. ["quiz", "classes", "grade", "monitor", "assign", "session", "testing"]

6. ["quiz", "grade", "assign", "session", "testing", "classes", "monitor"]

7. ["quiz", "grade", "assign", "classes", "monitor", "session", "testing"]