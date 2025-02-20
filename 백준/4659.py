def isvowels(s):
    vowels =set(list('aeiou'))
    for c in s:
        if c in vowels:
            return 1
    return 0
def isthree(s):
    vowels =set(list('aeiou'))
    for i in range(len(s)-2):
        if s[i]==s[i+1] and s[i+1]==s[i+2]:
            return 0
        if s[i] in vowels and s[i+1] in vowels and s[i+2] in vowels:
            return 0
        if s[i] not in vowels and s[i+1] not in vowels and s[i+2] not in vowels:
            return 0
    return 1
def istwo(s):
    for i in range(len(s)-1):
        if s[i]==s[i+1] and not (s[i]=='e' or s[i]=='o'):
            return 0
    return 1

res = ["is not acceptable.","is acceptable."]    
while True:
    s = input()
    if s=="end":
        break
    print('<{}> {}'.format(s,res[isvowels(s)& isthree(s)&istwo(s)]))