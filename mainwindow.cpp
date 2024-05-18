#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTableWidgetItem>
#include <QFont>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    m_timer(new QTimer(this)),
    m_elapsed(new QElapsedTimer)
{
    ui->setupUi(this);

    m_timer->setInterval(1000);
    m_timer->start();
    m_elapsed->start();

    QFont* font = new QFont;
    font->setPointSize(50);

    ui->line_edit->setReadOnly(true);
    ui->line_edit->setAlignment(Qt::AlignRight);
    ui->line_edit->setFont(*font);

    connect(m_timer, &QTimer::timeout, this, &MainWindow::timeHit);

    connect(ui->action_about, &QAction::triggered, this, &MainWindow::pushMenu);
    connect(ui->action_new_window, &QAction::triggered, this, &MainWindow::pushMenu);
    connect(ui->action_save_all_window, &QAction::triggered, this, &MainWindow::pushMenu);
    connect(ui->action_save, &QAction::triggered, this, &MainWindow::pushMenu);
    connect(ui->action_wrap_window, &QAction::triggered, this, &MainWindow::pushMenu);
    connect(ui->action_copy, &QAction::triggered, this, &MainWindow::pushMenu);
    connect(ui->action_delete, &QAction::triggered, this, &MainWindow::pushMenu);
    connect(ui->action_exit, &QAction::triggered, this, &MainWindow::pushMenu);
    connect(ui->action_insert, &QAction::triggered, this, &MainWindow::pushMenu);
    connect(ui->action_network, &QAction::triggered, this, &MainWindow::pushMenu);
    connect(ui->action_new_document, &QAction::triggered, this, &MainWindow::pushMenu);
    connect(ui->action_insert_new_file, &QAction::triggered, this, &MainWindow::pushMenu);
    connect(ui->action_new_folder, &QAction::triggered, this, &MainWindow::pushMenu);
    connect(ui->action_print, &QAction::triggered, this, &MainWindow::pushMenu);
    connect(ui->action_open_file, &QAction::triggered, this, &MainWindow::pushMenu);
    connect(ui->action_copy_all, &QAction::triggered, this, &MainWindow::pushMenu);
    connect(ui->action_save_window, &QAction::triggered, this, &MainWindow::pushMenu);
    connect(ui->action_open_folder, &QAction::triggered, this, &MainWindow::pushMenu);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pushMenu() {
    if(index > 20) {
        index = 1;
    }
    QTableWidgetItem* item1 = new QTableWidgetItem;
    int e = m_elapsed->elapsed();
    item1->setText(QString::number(e / 1000) + "." + QString::number(e % 1000));
    ui->table_widget->setItem(index, 0, item1);
    QTableWidgetItem* item2 = new QTableWidgetItem;
    int hick = qLn(19) / qLn(2);
    item2->setText(QString::number(hick));
    ui->table_widget->setItem(index, 1, item2);
    m_is_printed = false;
    ui->line_edit->clear();
    m_elapsed->restart();
}

void MainWindow::timeHit() {
    int time = 3000;
    int elapsed = m_elapsed->elapsed();
    int menu_bar = rand() % 18;
    if(elapsed > time && (!m_is_printed)) {
        switch(menu_bar) {
        case 0:
            ui->line_edit->setText(tr("About"));
            m_is_printed = true;
            break;
        case 2:
            ui->line_edit->setText(tr("New window"));
            m_is_printed = true;
            break;
        case 3:
            ui->line_edit->setText(tr("Save all window"));
            m_is_printed = true;
            break;
        case 4:
            ui->line_edit->setText(tr("Wrap window"));
            m_is_printed = true;
            break;
        case 5:
            ui->line_edit->setText(tr("Copy"));
            m_is_printed = true;
            break;
        case 6:
            ui->line_edit->setText(tr("Delete"));
            m_is_printed = true;
            break;
        case 7:
            ui->line_edit->setText(tr("Exit"));
            m_is_printed = true;
            break;
        case 8:
            ui->line_edit->setText(tr("Insert"));
            m_is_printed = true;
            break;
        case 9:
            ui->line_edit->setText(tr("Network"));
            m_is_printed = true;
            break;
        case 10:
            ui->line_edit->setText(tr("New document"));
            m_is_printed = true;
            break;
        case 11:
            ui->line_edit->setText(tr("Insert new file"));
            m_is_printed = true;
            break;
        case 12:
            ui->line_edit->setText(tr("New folder"));
            m_is_printed = true;
            break;
        case 13:
            ui->line_edit->setText(tr("Print"));
            m_is_printed = true;
            break;
        case 14:
            ui->line_edit->setText(tr("Open file"));
            m_is_printed = true;
            break;
        case 15:
            ui->line_edit->setText(tr("Copy all"));
            m_is_printed = true;
            break;
        case 16:
            ui->line_edit->setText(tr("Save window"));
            m_is_printed = true;
            break;
        case 17:
            ui->line_edit->setText(tr("Open folder"));
            m_is_printed = true;
            break;
        }
    }
}
