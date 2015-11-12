/********************************************************************************
** Form generated from reading UI file 'aboutdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AboutDialog
{
public:
    QLabel *label;
    QLabel *labelMovie;
    QPushButton *okButton;

    void setupUi(QDialog *AboutDialog)
    {
        if (AboutDialog->objectName().isEmpty())
            AboutDialog->setObjectName(QStringLiteral("AboutDialog"));
        AboutDialog->resize(480, 372);
        label = new QLabel(AboutDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 30, 291, 51));
        labelMovie = new QLabel(AboutDialog);
        labelMovie->setObjectName(QStringLiteral("labelMovie"));
        labelMovie->setGeometry(QRect(90, 100, 301, 201));
        okButton = new QPushButton(AboutDialog);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(180, 320, 115, 32));

        retranslateUi(AboutDialog);

        QMetaObject::connectSlotsByName(AboutDialog);
    } // setupUi

    void retranslateUi(QDialog *AboutDialog)
    {
        AboutDialog->setWindowTitle(QApplication::translate("AboutDialog", "Dialog", 0));
        label->setText(QApplication::translate("AboutDialog", "<html><head/><body><p><span style=\" font-size:24pt; font-weight:600; color:#4500ff;\">\351\276\231\345\223\245\345\210\266\344\275\234\357\274\2142015\345\271\2647\346\234\21014\346\227\245</span></p></body></html>", 0));
        labelMovie->setText(QString());
        okButton->setText(QApplication::translate("AboutDialog", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class AboutDialog: public Ui_AboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
