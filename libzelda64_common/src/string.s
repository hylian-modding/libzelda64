.set noreorder

.section .text

# Very fast memset
# A0 = dest, A1 = value, A2 = length
.global memset_fast_8
memset_fast_8:
1$:
    sb      $a1, 0x0($a0)
    addi    $a2, -1
    bnez    $a2, 1$
    addi    $a0, 1
2$:
    jr      $ra
    nop

# Very fast memset, length MUST be aligned to 2 bytes
# A0 = dest, A1 = value, A2 = length
.global memset_fast_16
memset_fast_16:
1$:
    sh      $a1, 0x0($a0)
    addi    $a2, -2
    bnez    $a2, 1$
    addi    $a0, 2
2$:
    jr      $ra
    nop

# Very fast memset, length MUST be aligned to 4 bytes
# A0 = dest, A1 = value, A2 = length
.global memset_fast_32
memset_fast_32:
1$:
    sw      $a1, 0x0($a0)
    addi    $a2, -4
    bnez    $a2, 1$
    addi    $a0, 4
2$:
    jr      $ra
    nop

# Very fast memset, length MUST be aligned to 8 bytes
# A0 = dest, A1 = value, A2 = length
.global memset_fast_64
memset_fast_64:
1$:
    sd      $a1, 0x0($a0)
    addi    $a2, -8
    bnez    $a2, 1$
    addi    $a0, 8
2$:
    jr      $ra
    nop

