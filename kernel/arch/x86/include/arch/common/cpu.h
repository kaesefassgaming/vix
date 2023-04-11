#pragma once
#include <config.h>
#include <types.h>

namespace arch {
#ifdef CONFIG_ENABLE_KERNEL_32
    struct cpu_ctx {
        uint32_t ebp;

        uint32_t edi;
        uint32_t esi;
        uint32_t edx;
        uint32_t ecx;
        uint32_t ebx;
        uint32_t eax;

        uint16_t gs, __gsh;
        uint16_t fs, __fsh;
        uint16_t es, __esh;
        uint16_t ds, __dsh;

        uint32_t interrupt;
        uint32_t error_code;

        // CPU pushes these (and iretd pops them)
        uint32_t eip;
        uint16_t cs, __csh;
        uint32_t eflags, esp;
        uint16_t ss, __ssh;
    };
#endif

#ifdef CONFIG_ENABLE_KERNEL_64
    struct cpu_ctx { // TODO: 64-bit context struct
        uint32_t ebp;

        uint32_t edi;
        uint32_t esi;
        uint32_t edx;
        uint32_t ecx;
        uint32_t ebx;
        uint32_t eax;

        uint16_t gs, __gsh;
        uint16_t fs, __fsh;
        uint16_t es, __esh;
        uint16_t ds, __dsh;

        uint32_t interrupt;
        uint32_t error_code;

        // CPU pushes these (and iretd pops them)
        uint32_t eip;
        uint16_t cs, __csh;
        uint32_t eflags, esp;
        uint16_t ss, __ssh;
    };
#endif
}