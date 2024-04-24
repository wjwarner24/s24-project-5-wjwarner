/**
 * This file contains implementations for methods in the PageTable class.
 *
 * You'll need to add code here to make the corresponding tests pass.
 */

#include "page_table/page_table.h"
#include <limits>

using namespace std;


size_t PageTable::get_present_page_count() const {
    // TODO: implement me
    int length = 0;
    for (int i = 0; i < (int) rows.size(); i++) {
        if (rows.at(i).present) {
            length++;
        }
    }
    return (size_t) length;
}


size_t PageTable::get_oldest_page() const {
    // TODO: implement me
    int oldest_index = -1;
    int oldest_load_time = std::numeric_limits<int>::max();
    for (int i = 0; i < (int) rows.size(); i++) {
        if (rows.at(i).present && rows.at(i).loaded_at <= oldest_load_time) {
            oldest_index = i;
            oldest_load_time = rows.at(i).loaded_at;
        }
    }
    return (size_t) oldest_index;
}


size_t PageTable::get_least_recently_used_page() const {
    // TODO: implement me
    int oldest_index = 0;
    int oldest_load_time = rows.at(0).last_accessed_at;
    for (int i = 0; i < (int) rows.size(); i++) {
        if (rows.at(i).present && rows.at(i).last_accessed_at <= oldest_load_time) {
            oldest_index = i;
            oldest_load_time = rows.at(i).last_accessed_at;
        }
    }
    return (size_t) oldest_index;
}
