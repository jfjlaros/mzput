; RING0.ASM

; Assembler module containing the functions to be executed through a callgate.

.386
.model small

.code

public _asmclisti ; Disable / Re-enable all interrupts.
public _asmoutb   ; Do direct I/O output.
public _asminb    ; Do direct I/O input.

; Disable / Re-enable all interrupts.
_asmclisti proc
  ; Setup standard stack frame.
  push ebp
  mov ebp, esp

  ; Save the register we modify.
  push ax

  ; Get the parameter from the stack.
  mov ax, [ebp+0Ch]
  test ax, ax
  jnz dosti

  cli  ; Disable all interrupts.
  jmp endoffunc

dosti:
  sti  ; Re-enable all interrupts.

endoffunc:
  ; Restore the registers.
  pop ax

  pop ebp

  ; Make a far return and follow the _stdcall calling convention.
  retf 04h
_asmclisti endp

; Do direct I/O output.
_asmoutb proc
  ; Setup standard stack frame.
  push ebp
  mov ebp, esp

  ; Save the registers we modify.
  push ax
  push dx

  ; Get the parameters from the stack.
  mov ax, [ebp+0Ch] ; The port to send to.
  mov dx, ax
  mov ax, [ebp+10h] ; The value to be send.
  out dx, ax        ; Do the I/O.

  ; Restore the registers.
  pop dx
  pop ax

  pop ebp

  ; Make a far return and follow the _stdcall calling convention.
  retf 08h
_asmoutb endp

; Do direct I/O input.
_asminb proc
  ; Setup standard stack frame.
  push ebp
  mov ebp, esp

  ; Save the registers we modify.
  push esi
  push ax
  push dx

  ; Get the parameters from the stack.
  mov esi, [ebp+0Ch] ; The address of the return value.
  mov dx, [ebp+10h]  ; The port to read from.
  in ax, dx          ; Do the I/O.
  mov [esi], ax      ; Put the result where esi points to.

  ; Restore the registers.
  pop dx
  pop ax
  pop esi

  pop ebp

  ; Make a far return and follow the _stdcall calling convention.
  retf 08h
_asminb endp

END
