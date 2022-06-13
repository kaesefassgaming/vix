#pragma once
#include "stdio.h"

#define outb(port, value) \
    asm volatile("outb %%al, %%dx" ::"d"(port), "a"(value));


#define outbp(port, value) \
    asm volatile("outb %%al, %%dx; jmp 1f; 1:" ::"d"(port), "a"(value));


#define inb(port) ({              \
    unsigned char _v;             \
    asm volatile("inb %%dx, %%al" \
                 : "=a"(_v)       \
                 : "d"(port));    \
    _v;                           \
})

#define inw(port) ({              \
    unsigned short _v;             \
    asm volatile("inw %%dx, %%ax" \
                 : "=a"(_v)       \
                 : "d"(port));    \
    _v;                           \
})

namespace hdd {
    namespace generic {
        typedef struct __genericDrive_t {
            bool alive;
            enum __drivetype {
                GENERIC_DRIVE_ATAPIO = 0,
                GENERIC_DRIVE_USBFLASH = 1,
                GENERIC_DRIVE_SATA = 2,
            } drivetype;
            uint64_t devinfo1;
            uint64_t devinfo2;
        } genericDrive_t;
    }

    namespace ata_pio {
        typedef struct __atadevice_t {
            bool dev_okay;
	        char name[41];
        } atadevice_t;
        enum controller {
            ATA_CONTROLLER_PRIMARY = 0x1F0,
            ATA_CONTROLLER_SECONDARY = 0x170,
        };
        enum drive {
            ATA_DRIVE_MASTER = 0xA0,
            ATA_DRIVE_SLAVE = 0xB0,
        };
        void idk();
        int generic_get_drives(int occupied, int max, hdd::generic::genericDrive_t* drivearr);
        void generic_read(void* buf, uint64_t lba, uint16_t sectors, hdd::generic::genericDrive_t drive);
    }
}