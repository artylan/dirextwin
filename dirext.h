#ifndef DIREXT_H
#define DIREXT_H

#include <QApplication>
#include "progressdialog.h"

#include <filesystem>
#include <string>
#include <vector>

#include "stats.h"

namespace fs = std::filesystem;

class dirext
{
public:
    std::vector<stats> create_ext_map(std::wstring dir, QApplication &app, ProgressDialog &dlg);
    int progress;
private:
    std::wstring get_extension(const fs::directory_entry& entry);
};

#endif // DIREXT_H
