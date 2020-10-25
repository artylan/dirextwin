#include "widget.h"
#include "dirext.h"
#include "progressdialog.h"
#include "filesystem"
#include <iostream>
#include <QApplication>
#include <QFileDialog>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QString file_name;
    if (QCoreApplication::arguments().count() != 2) {
        file_name = QFileDialog::getExistingDirectory(Q_NULLPTR, "Besuche Verzeichnis",
                                                      "c:/",
                                                      QFileDialog::ShowDirsOnly
                                                      | QFileDialog::DontResolveSymlinks);
        if (file_name == Q_NULLPTR) {
            std::wcout << L"Sie haben kein Verzeichnis angegeben." << std::endl;
            return 1;
        }
    } else {
        file_name = QCoreApplication::arguments().at(1);
        auto path = std::filesystem::path(std::wstring((const wchar_t*)file_name.utf16()));
        std::error_code ec; // For using the non-throwing overloads of functions below.
        if (!std::filesystem::is_directory(path, ec))
        {
            std::wcout << path << L" ist kein Verzeichnis." << std::endl;
            return 1;
        }
    }

    ProgressDialog dlg(Q_NULLPTR);
    dlg.show();
    dlg.raise();
    dlg.activateWindow();
    app.processEvents();

    dirext dirext{};
    std::vector<stats> stats_list = dirext.create_ext_map(std::wstring((const wchar_t*)file_name.utf16()), app, dlg);

    dlg.hide();

    Widget w{stats_list, dlg.getProgress(), file_name};
    w.show();

    return app.exec();
}
