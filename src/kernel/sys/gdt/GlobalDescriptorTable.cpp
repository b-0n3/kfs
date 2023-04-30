//
// Created by b1 on 4/29/23.
//

#include <sys/gdt/GlobalDescriptorTable.h>

Kernel::GDT::GlobalDescriptorTable::GDTEntry::GDTEntry(uint32_t base,
                                                       uint32_t limit,
                                                       uint8_t type,
                                                       uint8_t flags)
                                                       {


}

uint32_t Kernel::GDT::GlobalDescriptorTable::GDTEntry::base() {
    return 0;
}

uint32_t Kernel::GDT::GlobalDescriptorTable::GDTEntry::limit() {
    return 0;
}

Kernel::GDT::GlobalDescriptorTable::GlobalDescriptorTable():
nullSegmentSelector(0,0,0,0),
unusedSegmentSelector(0,0,0,0),
codeSegmentSelector(0,0,0,0), // @Todo change values
dataSegmentSelector(0,0,0,0) // @Todo: change values
{

}

Kernel::GDT::GlobalDescriptorTable::~GlobalDescriptorTable() {

}

uint16_t Kernel::GDT::GlobalDescriptorTable::getCodeSegmentSelector() {
    return 0;
}

uint16_t Kernel::GDT::GlobalDescriptorTable::getDataSegmentSelector() {
    return 0;
}
