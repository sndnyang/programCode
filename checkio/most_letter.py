def checkio(text):

    #replace this for solution
    import string
    table = string.maketrans(string.ascii_uppercase, string.ascii_lowercase)
    new_text = string.translate(text, table)
    char = ''
    maxest = 0
    for x in string.ascii_lowercase:
        xcount = new_text.count(x)
        if xcount > maxest:
            char = x
            maxest = xcount
    return char

if __name__ == '__main__':
    #These "asserts" using only for self-checking and not necessary for auto-testing
    assert checkio("Hello World!") == "l", "Hello test"
    assert checkio("How do you do?") == "o", "O is most wanted"
    assert checkio("One") == "e", "All letter only once."
    assert checkio("Oops!") == "o", "Don't forget about lower case."
    assert checkio("AAaooo!!!!") == "a", "Only letters."
    assert checkio("abe") == "a", "The First."
    print("Start the long test")
    assert checkio('a' * 9000 + 'b' * 1000) == "a", "Long."
    print("The local tests are done.")
