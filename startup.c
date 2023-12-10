/* startup.c */

extern unsigned int _sidata, _sdata, _edata, _sbss, _ebss;

void Reset_Handler(void);

void Default_Handler(void) {
    while (1);
}

void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void) __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void) __attribute__((weak, alias("Default_Handler")));

void SVC_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DebugMon_Handler(void) __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void) __attribute__((weak, alias("Default_Handler")));

/* Vector Table */
void (*const vector_table[]) __attribute__((section(".vector_table"))) = {
    (void (*)(void))& _sidata, /* Initial stack pointer value */
    Reset_Handler,             /* Reset handler */
    NMI_Handler,               /* NMI handler */
    HardFault_Handler,         /* HardFault handler */
    MemManage_Handler,         /* Memory Manage handler */
    BusFault_Handler,          /* Bus Fault handler */
    UsageFault_Handler,        /* Usage Fault handler */
    0, 0, 0, 0,               /* Reserved */
    SVC_Handler,               /* SVC handler */
    DebugMon_Handler,          /* Debug Monitor handler */
    0,                         /* Reserved */
    PendSV_Handler,            /* PendSV handler */
    SysTick_Handler            /* SysTick handler */
};

/* Default Reset Handler */
void Reset_Handler(void) {
    unsigned int *src, *dst;

    /* Copy data section from flash to RAM */
    src = &_sidata;
    dst = &_sdata;
    while (dst < &_edata) {
        *(dst++) = *(src++);
    }

    /* Initialize bss section to zero in RAM */
    dst = &_sbss;
    while (dst < &_ebss) {
        *(dst++) = 0;
    }

    /* Call main() */
    main();

    /* Infinite loop in case main() returns */
    while (1);
}
