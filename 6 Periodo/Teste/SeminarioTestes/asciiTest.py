from ascii import ascii_encoding, ascii_decoding
from hypothesis import given, strategies as st, example

@given(st.text())
@example("")
def test_ascii_encode_decode(text):
  assert text == ascii_decoding(ascii_encoding(text))