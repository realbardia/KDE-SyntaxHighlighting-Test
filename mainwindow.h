#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <SyntaxHighlighter>
#include <Theme>
#include <Repository>
#include <Definition>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    static QStringList themes();
    static QStringList definitions();

protected:
    void reloadTheme();
    void reloadDefinition();

private:
    Ui::MainWindow *ui;

    KSyntaxHighlighting::SyntaxHighlighter *mHighlighter;
    KSyntaxHighlighting::Repository mRepo;
};
#endif // MAINWINDOW_H
