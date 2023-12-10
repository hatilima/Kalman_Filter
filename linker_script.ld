/* linker_script.ld */

MEMORY
{
  FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 128K
  RAM (rwx) : ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS
{
  .text :
  {
    KEEP(*(.vector_table))
    *(.text*)
    *(.rodata*)
  } > FLASH

  .data :
  {
    _sidata = LOADADDR(.data);
    _sdata = ADDR(.data);
    _edata = ADDR(.data) + SIZEOF(.data);
    *(.data*)
  } > RAM AT > FLASH

  .bss :
  {
    _sbss = ADDR(.bss);
    _ebss = ADDR(.bss) + SIZEOF(.bss);
    *(.bss*)
  } > RAM
}
