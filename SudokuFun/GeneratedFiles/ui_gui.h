/********************************************************************************
** Form generated from reading UI file 'gui.ui'
**
** Created by: Qt User Interface Compiler version 5.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_guiClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QTableView *sudokuArea;
    QVBoxLayout *verticalLayout;
    QPushButton *regenerateButton;
    QPushButton *autoButton;
    QPushButton *resetButton;
    QSpacerItem *verticalSpacer;
    QLCDNumber *timer;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *guiClass)
    {
        if (guiClass->objectName().isEmpty())
            guiClass->setObjectName(QStringLiteral("guiClass"));
        guiClass->resize(937, 708);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(guiClass->sizePolicy().hasHeightForWidth());
        guiClass->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(guiClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        sudokuArea = new QTableView(centralWidget);
        sudokuArea->setObjectName(QStringLiteral("sudokuArea"));

        horizontalLayout->addWidget(sudokuArea);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        regenerateButton = new QPushButton(centralWidget);
        regenerateButton->setObjectName(QStringLiteral("regenerateButton"));

        verticalLayout->addWidget(regenerateButton);

        autoButton = new QPushButton(centralWidget);
        autoButton->setObjectName(QStringLiteral("autoButton"));

        verticalLayout->addWidget(autoButton);

        resetButton = new QPushButton(centralWidget);
        resetButton->setObjectName(QStringLiteral("resetButton"));

        verticalLayout->addWidget(resetButton);

        verticalSpacer = new QSpacerItem(107, 485, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        timer = new QLCDNumber(centralWidget);
        timer->setObjectName(QStringLiteral("timer"));

        verticalLayout->addWidget(timer);


        horizontalLayout->addLayout(verticalLayout);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        guiClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(guiClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        guiClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(guiClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        guiClass->setStatusBar(statusBar);

        mainToolBar->addSeparator();

        retranslateUi(guiClass);

        QMetaObject::connectSlotsByName(guiClass);
    } // setupUi

    void retranslateUi(QMainWindow *guiClass)
    {
        guiClass->setWindowTitle(QApplication::translate("guiClass", "gui", 0));
        regenerateButton->setText(QApplication::translate("guiClass", "Generate New Puzzle", 0));
        autoButton->setText(QApplication::translate("guiClass", "Auto Complete", 0));
        resetButton->setText(QApplication::translate("guiClass", "Reset Puzzle", 0));
    } // retranslateUi

};

namespace Ui {
    class guiClass: public Ui_guiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
