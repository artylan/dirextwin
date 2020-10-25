#ifndef STATS_H
#define STATS_H

#include <cstdint>
#include <string>

class stats {
private:
    std::wstring ext;
    uintmax_t count;
    uintmax_t size;
public:
    void set_ext(std::wstring ext) { this->ext = ext; }
    void incCount(uintmax_t  inc) { count += inc; }
    void incSize(uintmax_t inc) { size += inc; }
    std::wstring get_ext() const { return ext; }
    uintmax_t get_count() const { return count; }
    uintmax_t get_size() const { return size; }
};

#endif // STATS_H
