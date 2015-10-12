# Equivalent python solutino of Excercise 2.6.1 in FDSC
def count(string):
    chars = set(list(string))
    freq = {key: 0 for key in chars}
    for ch in string:
        if ch in freq:
            freq[ch] += 1
    return freq

if __name__ == "__main__":
    s = "To be or not to be, it's a question."
    print(count(s))
