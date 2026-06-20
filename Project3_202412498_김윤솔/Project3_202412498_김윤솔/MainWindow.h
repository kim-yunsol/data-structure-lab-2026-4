#pragma once

#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>

#include "Graph.h"

class MainWindow : public QMainWindow
{
public:
    MainWindow()
    {
        setWindowTitle("Subway Route Search");
        resize(500, 350);

        QWidget* central = new QWidget(this);
        setCentralWidget(central);

        QVBoxLayout* layout = new QVBoxLayout(central);

        QLabel* title = new QLabel("<h2>Subway Route Search</h2>");
        title->setAlignment(Qt::AlignCenter);
        layout->addWidget(title);

        layout->addWidget(new QLabel("Start Station"));

        startEdit = new QLineEdit();
        layout->addWidget(startEdit);

        layout->addWidget(new QLabel("End Station"));

        endEdit = new QLineEdit();
        layout->addWidget(endEdit);

        searchButton = new QPushButton("Search");
        layout->addWidget(searchButton);

        resultLabel = new QLabel("Result will appear here.");
        resultLabel->setAlignment(Qt::AlignCenter);
        layout->addWidget(resultLabel);

        QLabel* guide = new QLabel(
            "Available stations:\n"
            "Gangnam\n"
            "Seolleung\n"
            "Samseong\n"
            "Jamsil\n"
            "Gyodae\n"
            "Sadang");
        guide->setAlignment(Qt::AlignCenter);
        layout->addWidget(guide);

        connect(searchButton, &QPushButton::clicked,
            this,
            [this]()
            {
                QString start = startEdit->text().trimmed();
                QString end = endEdit->text().trimmed();

                QString path = graph.findPath(start, end);

                resultLabel->setText(path);
            });
    }

private:
    QLineEdit* startEdit;
    QLineEdit* endEdit;
    QPushButton* searchButton;
    QLabel* resultLabel;

    Graph graph;
};