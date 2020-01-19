from nltk.tokenize import sent_tokenize


def lines(a, b):
    """Return lines in both a and b"""

    # split string into list then into a set
    lines_a = set([line for line in a.split('\n')])
    lines_b = set([line for line in b.split('\n')])

    return list(lines_a & lines_b)


def sentences(a, b):
    """Return sentences in both a and b"""

    sentences_a = set(sent_tokenize(a))
    sentences_b = set(sent_tokenize(b))

    return list(sentences_a & sentences_b)


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""

    substrings_a = set([a[i:i+n] for i in range(len(a) - n + 1)])
    substrings_b = set([b[i:i+n] for i in range(len(b) - n + 1)])

    return list(substrings_a & substrings_b)

