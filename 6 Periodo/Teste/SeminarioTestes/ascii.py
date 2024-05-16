# "aasdjjjjdddasvva"
# [2, 97, 1, 115, 1, 100, 4, 106, 3, 100, 1, 97, 1, 115, 2, 118, 1, 97]

def ascii_encoding(string):
    if not string:
        return []
    ascii_list = []
    for char in string:
        ascii_list.append(ord(char))
    encoded = []
    prev = ascii_list[0]
    count = 1
    for char in ascii_list[1:]:
        if char != prev:
            encoded.append(count)
            encoded.append(prev)
            count = 1
        else:
            count += 1
        prev = char
    encoded.append(count)
    encoded.append(prev)
    return encoded

def ascii_decoding(encoded):
    decoded = []
    for i in range(0, len(encoded), 2):
        count = encoded[i]
        char = encoded[i + 1]
        for _ in range(count):
            decoded.append(char)
    return ''.join(chr(char) for char in decoded)