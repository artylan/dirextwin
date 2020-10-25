#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <string>
#include <vector>
#include "stats.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(std::vector<stats> stats_list, int progress, QString dir_path, QWidget *parent = nullptr);
    ~Widget();

    std::vector<stats> get_stats_list();

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::Widget *ui;
    std::vector<stats> stats_list;
    int progress;
    QString dir_path;

    void saveSettings();
    void loadSettings();
};

#endif // WIDGET_H
