list main
list IsPassOk

b main.c: 21
r
# узнаём размер переменной
print sizeof Pass

# Берём текущй дар функции
info frame
# saved rip = 0x5555555551c9 - адрес возврата
# 0x5555555551eb - if

b main.c: 23
c
info frame