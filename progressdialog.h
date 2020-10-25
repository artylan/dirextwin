#ifndef PROGRESSDIALOG_H
#define PROGRESSDIALOG_H

#include <QDialog>
#include <QLabel>

namespace Ui {
class ProgressDialog;
}

class ProgressDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProgressDialog(QWidget *parent = nullptr);
    ~ProgressDialog();

    void setProgress(int progress);
    bool isCanceled();
    int getProgress();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ProgressDialog *ui;
    bool canceled;
    int progress;
};

#endif // PROGRESSDIALOG_H
