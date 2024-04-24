/**
 * This file contains implementations for methods in the PhysicalAddress class.
 *
 * You'll need to add code here to make the corresponding tests pass.
 */

#include "physical_address/physical_address.h"

using namespace std;

string PhysicalAddress::to_string() const {
    // TODO: implement me
    std::bitset<32> binary_frame(frame);
    std::bitset<32> binary_offset(offset);

    std::string frame_string = binary_frame.to_string();
    std::string offset_string = binary_offset.to_string();

    std::string frame_bits = frame_string.substr(frame_string.length() - 10, frame_string.length());
    std::string offset_bits = offset_string.substr(offset_string.length() - 6, offset_string.length());

    //return binary_frame.to_string() + binary_offset.to_string() + " [frame: " + std::to_string(frame) + "; offset: " + std::to_string(offset) + "]";
    return frame_bits + "" + offset_bits;
}


ostream& operator <<(ostream& out, const PhysicalAddress& address) {
    // TODO: implement me
    out << boost::format("%1% [frame: %2%; offset: %3%]") % address.to_string() % address.frame % address.offset;
    return out;
}
