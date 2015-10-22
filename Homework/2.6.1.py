# Equivalent python solutino of Excercise 2.6.1 in FDSC
def count(string):
    chars = set(list(string))
    freq = {key: 0 for key in chars}
    for ch in string:
        if ch in freq:
            freq[ch] += 1
    print(len(freq))
    return freq

