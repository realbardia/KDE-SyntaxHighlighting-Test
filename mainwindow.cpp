#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->themes->addItems(themes());
    ui->definitions->addItems(definitions());

    mHighlighter = new KSyntaxHighlighting::SyntaxHighlighter(ui->textEdit->document());

    connect(ui->themes, &QComboBox::currentTextChanged, this, &MainWindow::reloadTheme);
    connect(ui->definitions, &QComboBox::currentTextChanged, this, &MainWindow::reloadDefinition);

    ui->themes->setCurrentText("Breeze Light");
    ui->definitions->setCurrentText("C++");
}

QStringList MainWindow::themes()
{
    QStringList res;
    KSyntaxHighlighting::Repository repo;
    auto themes = repo.themes();
    for (const auto &t: themes)
        res << t.name();
    return res;
}

QStringList MainWindow::definitions()
{
    QStringList res;
    KSyntaxHighlighting::Repository repo;
    auto definitions = repo.definitions();
    for (const auto &d: definitions)
        res << d.name();

    res.sort();
    return res;
}

void MainWindow::reloadTheme()
{
    if (!mHighlighter)
        return;

    const auto themeName = ui->themes->currentText();
    const auto theme = mRepo.theme(themeName);

    mHighlighter->setTheme(theme);
    mHighlighter->rehighlight();

    auto plt = palette();
    plt.setColor(QPalette::Base, theme.editorColor(KSyntaxHighlighting::Theme::BackgroundColor));

    ui->textEdit->setPalette(plt);
}

void MainWindow::reloadDefinition()
{
    if (!mHighlighter)
        return;

    auto definitions = mRepo.definitions();
    for (const auto &d: definitions)
        if (d.name().toLower() == ui->definitions->currentText().toLower())
        {
            mHighlighter->setDefinition(d);
            break;
        }

    mHighlighter->rehighlight();
}

MainWindow::~MainWindow()
{
    delete ui;
}
