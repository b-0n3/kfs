

#ifndef KFS_GLOBAL_DESCRIPTOR_TABLE_H
#define KFS_GLOBAL_DESCRIPTOR_TABLE_H
/**
             *  @See: https://wiki.osdev.org/Global_Descriptor_Table#GDTR
             *  @Description:
             *      this class  is used to describe a GDT entry
             *      |base | limit| access | flags
             *
             *      BASE: is a pointer to segment
             *
             *      limit: is the max offset of the segment
             *
             *
             *      access: define the type of segment and access rules
             *         7	6	5	4	3	2	1	0
             *         P	 DPL   S   E   DC  RW  A
             *
             *          P  : Present bit. Allows an entry to refer to a valid segment.
             *                Must be set (1) for any valid segment.
             *          DPL: Descriptor privilege level field.
             *              Contains the CPU Privilege level of the segment.
             *              0 = highest privilege (kernel), 3 = lowest privilege (user applications).
             *          S: Descriptor type bit.
             *            If clear (0) the descriptor defines a system segment (eg. a Task State Segment).
             *            If set (1) it defines a code or data segment.
             *          E: Executable bit. If clear (0) the descriptor defines a data segment.
             *              If set (1) it defines a code segment which can be executed from.
             *          DC: Direction bit/Conforming bit.
             *          For data selectors: Direction bit. If clear (0) the segment grows up.
             *              If set (1) the segment grows down, ie. the Offset has to be greater than the Limit.
             *              For code selectors: Conforming bit.
             *              If clear (0) code in this segment can only be executed from the ring set in DPL.
             *              If set (1) code in this segment can be executed from an equal or lower privilege level.
             *              For example, code in ring 3 can far-jump to conforming code in a ring 2 segment.
             *              The DPL field represent the highest privilege level that is allowed to execute the segment.
             *              For example, code in ring 0 cannot far-jump to a conforming code segment where DPL is 2,
             *              while code in ring 2 and 3 can. Note that the privilege level remains the same,
             *              ie. a far-jump from ring 3 to a segment with a DPL of 2 remains in ring 3 after the jump.
             *          RW: Readable bit/Writable bit.
             *              For code segments: Readable bit. If clear (0),
             *              read access for this segment is not allowed.
             *              If set (1) read access is allowed. Write access is never allowed for code segments.
             *              For data segments: Writeable bit. If clear (0),
             *              write access for this segment is not allowed. If set (1) write access is allowed.
             *              Read access is always allowed for data segments.
             *              A: Accessed bit. Best left clear (0),
             *              the CPU will set it when the segment is accessed.
             *
             *      flags:
             *       3	2	1	0
             *       G	DB	L	Reserved
             *         G: Granularity flag, indicates the size the Limit value is scaled by.
             *                 If clear (0), the Limit is in 1 Byte blocks (byte granularity).
             *                 If set (1), the Limit is in 4 KiB blocks (page granularity).
             *        DB: Size flag. If clear (0), the descriptor defines a 16-bit protected mode segment.
             *                 If set (1) it defines a 32-bit protected mode segment.
             *                 A GDT can have both 16-bit and 32-bit selectors at once.
             *         L: Long-mode code flag. If set (1), the descriptor defines a 64-bit code segment.
             *                 When set, DB should always be clear.
             *                 For any other type of segment (other code types or any data segment), it should be clear (0).
             *
             *      the segment Descriptor is quite complex, so we will use a struct to represent it
             *       the size is 8 bytes
             *       the first two bytes are the limit_lo
             *       the next three bytes are the base_lo
             *       the next byte is the type
             *       the next byte is the flags_limit_hi
             *       the last byte is the base_vhi
             *       the structure is like this
             *            1        2       3        4           5         6              7               8
             *       | 8 bits| 8 bits | 8 bits | 8 bits | 8 bits    | 8 bits |  4bits    | 4 bits   | 8 bits   |
             *       \               /\                /\          /\       /\          /\         /\          \
             *       |  limit_lo    | |  base_lo      | | base_hi | | type | |limit_hi | |  flags | | base_vhi |
             *
             *      @author B-one
             *      @version 1.0
             */

#include <common/types.h>



using namespace Common;


namespace Kernel::GDT {

        class GlobalDescriptorTable {
        public:

            class GDTEntry {
                private:
                    uint16_t limit_lo; // 2 first bytes of the limit
                    uint16_t base_lo;  // 2 first bytes of the base
                    uint8_t base_hi;   // 3rd byte of the base
                    uint8_t type;     // 4 bits type, 2 bits privilege, 1 bit present, 1 bit reserved
                    uint8_t flags_limit_hi; // 4 bits flags, 4 bits limit_hi which is the 4th byte of the limit but multiplied by 16
                    uint8_t base_vhi;  // 4th byte of the base
                public:
                    GDTEntry(uint32_t base,
                             uint32_t limit,
                             uint8_t type,
                             uint8_t flags);
                    uint32_t base();
                    uint32_t limit();
            } __attribute__((packed));
            GDTEntry nullSegmentSelector;
            GDTEntry unusedSegmentSelector;
            GDTEntry codeSegmentSelector;
            GDTEntry dataSegmentSelector;
        public:
            GlobalDescriptorTable();
            ~GlobalDescriptorTable();
            uint16_t getCodeSegmentSelector();
            uint16_t getDataSegmentSelector();

        } __attribute__((packed));
    }

#endif