#include "progressdialog.h"
#include "ui_progressdialog.h"

ProgressDialog::ProgressDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProgressDialog)
{
    ui->setupUi(this);
    canceled = false;
}

ProgressDialog::~ProgressDialog()
{
    delete ui;
}

void ProgressDialog::setProgress(int progress)
{
    this->progress = progress;
    ui->progressBar->setValue((progress / 1000) % 100);
    ui->progressLabel->setText("Besuchte Dateien: " + QString::number(progress));
}

bool ProgressDialog::isCanceled()
{
    return canceled;
}

int ProgressDialog::getProgress()
{
    return progress;
}

void ProgressDialog::on_pushButton_clicked()
{
    canceled = true;
}
