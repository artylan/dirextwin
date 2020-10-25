#include <map>
#include "dirext.h"

std::wstring dirext::get_extension(const fs::directory_entry& entry) {
    std::wstring file_name{ entry.path().filename().wstring() };
    size_t pos = file_name.find_last_of(L".");
    if (pos == 0 || pos == std::wstring::npos) {
        return L"<noext>";
    }
    return file_name.substr(pos);
}

std::vector<stats> dirext::create_ext_map(std::wstring dir, QApplication &app, ProgressDialog &dlg) {
    std::map<std::wstring, stats> ext_map{};
    auto iter = fs::recursive_directory_iterator(fs::path(dir), fs::directory_options::skip_permission_denied);
    bool error = false;
    for (auto i = begin(iter); i != end(iter);) {
        try {
            auto& e = *i;
            if (!error && !e.is_directory()) {
                std::wstring ext = get_extension(e);
                stats& stats = ext_map[ext];
                stats.set_ext(ext);
                stats.incCount(1);
                stats.incSize(e.file_size());

                ++progress;
                if (progress % 1000 == 0) {
                    dlg.setProgress(progress);
                    app.processEvents();
                    if (dlg.isCanceled()) {
                        break;
                    }
                }
            }
        } catch (...) {
        }
        error = false;
        try { ++i;
        } catch (...) {
            error = true;
        }
    }
    std::vector<stats> vec;
    for (auto entry : ext_map) {
        vec.push_back(entry.second);
    }
    dlg.setProgress(progress);
    return vec;
}


