#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QElapsedTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void pushMenu();
    void timeHit();
private:
    Ui::MainWindow *ui;
    enum class Menu {
        ABOUT = 0,
        NEW_WINDOW,
        SAVE_ALL_WINDOW,
        SAVE,
        WRAP_WINDOW,
        COPY,
        DELETE,
        EXIT,
        INSERT,
        NETWORK,
        NEW_DOCUMENT,
        INSERT_NEW_FILE,
        NEW_FOLDER,
        PRINT,
        OPEN_FILE,
        COPY_ALL,
        SAVE_WINDOW,
        OPEN_FOLDER
    };
    bool m_is_printed = false;
    QTimer* m_timer;
    QElapsedTimer *m_elapsed;
    int index = 1;
};
#endif // MAINWINDOW_H
