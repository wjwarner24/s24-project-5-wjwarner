/**
 * This file contains implementations for methods in the Process class.
 *
 * You'll need to add code here to make the corresponding tests pass.
 */

#include "process/process.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

Process *Process::read_from_input(std::istream &in)
{
    std::vector<Page*> pages;
    string line;
    char c;

    while (in.get(c)) {
        line += c;
        if (line.size() >= Page::PAGE_SIZE) {
            std::istringstream iss(line.substr(0, Page::PAGE_SIZE));
            pages.push_back(Page::read_from_input(iss));
            line = line.substr(Page::PAGE_SIZE);
        }
    }

    if (!line.empty()) {
        std::istringstream iss(line);
        pages.push_back(Page::read_from_input(iss));
    }

    return new Process(static_cast<int>(pages.size() * Page::PAGE_SIZE), pages);
}

size_t Process::size() const
{
    int total_size = 0;
    for (Page *const page : pages)
    {
        total_size += page->size();
    }
    return (size_t)total_size;
}

bool Process::is_valid_page(size_t index) const
{
    if (index < this->page_table.rows.size())
    {
        return true;
    }
    return false;
}

size_t Process::get_rss() const
{
    int rss_size = 0;
    int total = 0;
    for (auto row : page_table.rows) {
        if (row.present) {
            rss_size++;
        }
        total++;
    }
    return rss_size;
}

double Process::get_fault_percent() const
{
    if (memory_accesses == 0) {
        return 0;
    }
    return ((double) page_faults / (double) memory_accesses) * 100;
}
