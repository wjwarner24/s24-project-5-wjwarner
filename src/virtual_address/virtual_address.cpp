/**
 * This file contains implementations for methods in the VirtualAddress class.
 *
 * You'll need to add code here to make the corresponding tests pass.
 */

#include "virtual_address/virtual_address.h"

using namespace std;

VirtualAddress VirtualAddress::from_string(int process_id, string address) {
    string page_str = address.substr(0, 10);
    string offset_str = address.substr(10, 6);
    int page = stoi(page_str, nullptr, 2);
    int offset = stoi(offset_str, nullptr, 2);
    return VirtualAddress(process_id, page, offset);
}


string VirtualAddress::to_string() const {
    std::bitset<32> binary_frame(page);
    std::bitset<32> binary_offset(offset);

    std::string frame_string = binary_frame.to_string();
    std::string offset_string = binary_offset.to_string();

    std::string frame_bits = frame_string.substr(frame_string.length() - 10, frame_string.length());
    std::string offset_bits = offset_string.substr(offset_string.length() - 6, offset_string.length());

    return frame_bits + "" + offset_bits;
}


ostream& operator <<(ostream& out, const VirtualAddress& address) {
    out << boost::format("PID %1% @ %2% [page: %3%; offset: %4%]") % address.process_id % address.to_string() % address.page % address.offset;
    return out;
}
