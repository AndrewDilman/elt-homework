list main
list IsPassOk

b main.c: 21
r
# Смотрим на инструкции main
disassemble main
# подхожит 0x00005555555551eb <+66>:    lea    0xe30(%rip),%rax        # 0x555555556022

# узнаём размер переменной
print sizeof Pass

