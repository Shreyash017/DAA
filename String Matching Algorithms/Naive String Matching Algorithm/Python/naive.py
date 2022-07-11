def search(pat, txt):
    m = len(pat)
    n = len(txt)

    # A loop to slide window pattern
    for i in range(n - m + 1):
        j = 0

        # To match pattern
        while (j < m):
            if (txt[i + j] != pat[j]):
                break
            j += 1

        if (j == m):
            print("Pattern found at index ", i)


if __name__ == '__main__':
    txt = input("\nEnter the String: ")
    pat = input("\nEnter the Pattern: ")
    print()
    search(pat, txt)


"""
Eg:- 
txt = "AABAACAADAABAAABAA"
pat = "AABA"
"""
