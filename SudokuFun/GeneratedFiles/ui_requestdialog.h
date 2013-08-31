/********************************************************************************
** Form generated from reading UI file 'requestdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REQUESTDIALOG_H
#define UI_REQUESTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RequestDialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *requestQuestion;
    QLineEdit *requestLine;
    QHBoxLayout *horizontalLayout;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *RequestDialog)
    {
        if (RequestDialog->objectName().isEmpty())
            RequestDialog->setObjectName(QStringLiteral("RequestDialog"));
        RequestDialog->resize(449, 135);
        gridLayout = new QGridLayout(RequestDialog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        requestQuestion = new QLabel(RequestDialog);
        requestQuestion->setObjectName(QStringLiteral("requestQuestion"));
        QFont font;
        font.setPointSize(12);
        requestQuestion->setFont(font);
        requestQuestion->setWordWrap(true);

        verticalLayout->addWidget(requestQuestion);

        requestLine = new QLineEdit(RequestDialog);
        requestLine->setObjectName(QStringLiteral("requestLine"));

        verticalLayout->addWidget(requestLine);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        okButton = new QPushButton(RequestDialog);
        okButton->setObjectName(QStringLiteral("okButton"));

        horizontalLayout->addWidget(okButton);

        cancelButton = new QPushButton(RequestDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout->addWidget(cancelButton);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(RequestDialog);
        QObject::connect(okButton, SIGNAL(clicked()), RequestDialog, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), RequestDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(RequestDialog);
    } // setupUi

    void retranslateUi(QDialog *RequestDialog)
    {
        RequestDialog->setWindowTitle(QApplication::translate("RequestDialog", "RequestDialog", 0));
        requestQuestion->setText(QApplication::translate("RequestDialog", "What grid type (nxn) would you like? Please enter an integer.", 0));
        okButton->setText(QApplication::translate("RequestDialog", "Confirm", 0));
        cancelButton->setText(QApplication::translate("RequestDialog", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class RequestDialog: public Ui_RequestDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REQUESTDIALOG_H
