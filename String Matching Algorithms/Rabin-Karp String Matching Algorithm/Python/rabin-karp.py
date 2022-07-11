d = 256


def search(txt, pat, q):
    m = len(pat)
    n = len(txt)
    p = 0
    t = 0
    h = 1
    i = 0
    j = 0

    for i in range(m-1):
        h = (h*d) % q

    for i in range(m):
        p = ((d*p) + ord(pat[i])) % q
        t = ((d*t) + ord(txt[i])) % q

    for i in range(n - m + 1):
        if p == t:   # If the hash value is same then check each character to confirm
            for j in range(m):
                if txt[i + j] != pat[j]:
                    break
                j += 1

            if j == m:
                print("Pattern found at index", i)

        if i < n - m:
            # Rehashing:- Trailing Character Subtract, Leading Character Add
            t = (d * (t-ord(txt[i]) * h) + ord(txt[i + m])) % q

            if t < 0:
                # If negative then add the prime number
                t = t + q


if __name__ == '__main__':
    txt = input("\nEnter the String: ")
    pat = input("\nEnter the Pattern: ")
    q = int(input("\nEnter a Prime Number: "))
    print()
    search(txt, pat, q)


"""
Eg:- 
txt = "AABAACAADAABAAABAA"
pat = "AABA"
q = 13
"""
