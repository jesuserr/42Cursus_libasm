section .note.GNU-stack
    db 0

section .data
    hello_msg db 'Hello, World!', 0x0A  ; Define the string with a newline character

section .text
    global hello

hello:
    ; Write syscall
    mov rax, 1          ; syscall number for sys_write
    mov rdi, 1          ; file descriptor 1 is stdout
    lea rsi, [rel hello_msg]  ; address of the string to output
    mov rdx, 14         ; number of bytes to write (length of "Hello, World!\n")
    syscall             ; make the syscall

    ; Exit syscall
    mov rax, 60         ; syscall number for sys_exit
    xor rdi, rdi        ; exit code 0
    syscall             ; make the syscall