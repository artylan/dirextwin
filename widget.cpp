#include "widget.h"
#include "ui_widget.h"
#include "customtablemodel.h"
#include "mynumberformatdelegate.h"
#include "myproxymodel.h"
#include <QSettings>

constexpr char COMPANY[] = "WAS";
constexpr char PROG[] = "DirExtWin";
constexpr char WINDOW[] = "mainwindow";
constexpr char GEOMETRY[] = "geometry";
constexpr char MAXIMIZED[] = "maximized";
constexpr char POS[] = "pos";
constexpr char SIZE[] = "size";

Widget::Widget(std::vector<stats> stats_list, int progress, QString dir_path, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    stats_list(stats_list),
    progress(progress),
    dir_path(dir_path)
{
    ui->setupUi(this);

    ui->labelDir->setText("Verzeichnis: " + dir_path);
    ui->labelProgress->setText("Besuchte Dateien: " + QString::number(progress));

    CustomTableModel * model = new CustomTableModel(this, stats_list);
    MyProxyModel * proxyModel = new MyProxyModel(this);
    proxyModel->setSourceModel(model);
    ui->tableView->setStyleSheet("QHeaderView::section { background-color:lightgray } QTableCornerButton::section {background-color: lightgray }");
    ui->tableView->setItemDelegateForColumn(1, new MyNumberFormatDelegate(this));
    ui->tableView->setItemDelegateForColumn(2, new MyNumberFormatDelegate(this));
    ui->tableView->setModel(proxyModel );
    ui->tableView->sortByColumn(0, Qt::AscendingOrder);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    QHeaderView *verticalHeader = ui->tableView->verticalHeader();
    verticalHeader->setSectionResizeMode(QHeaderView::Fixed);
    verticalHeader->setDefaultSectionSize(12);

    loadSettings();
}

void Widget::closeEvent(QCloseEvent *event)
{
    saveSettings();
    QWidget::closeEvent(event);
}

void Widget::saveSettings()
{
    QSettings qsettings(COMPANY, PROG);
    qsettings.beginGroup(WINDOW);
    qsettings.setValue(GEOMETRY, saveGeometry());
    qsettings.setValue(MAXIMIZED, isMaximized());
    if ( !isMaximized()) {
        qsettings.setValue(POS, pos());
        qsettings.setValue(SIZE, size());
    }
    qsettings.endGroup();
}

void Widget::loadSettings()
{
    QSettings qsettings(COMPANY, PROG);
    qsettings.beginGroup(WINDOW);
    restoreGeometry(qsettings.value(GEOMETRY, saveGeometry()).toByteArray());
    move(qsettings.value(POS, pos()).toPoint());
    resize(qsettings.value(SIZE, size()).toSize());
    if ( qsettings.value(MAXIMIZED, isMaximized() ).toBool())
        showMaximized();
    qsettings.endGroup();
}

Widget::~Widget()
{
    delete ui;
}
