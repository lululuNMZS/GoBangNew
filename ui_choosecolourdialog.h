/********************************************************************************
** Form generated from reading UI file 'choosecolourdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSECOLOURDIALOG_H
#define UI_CHOOSECOLOURDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChooseColourDialog
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QPushButton *blackButton;
    QPushButton *whiteButton;

    void setupUi(QDialog *ChooseColourDialog)
    {
        if (ChooseColourDialog->objectName().isEmpty())
            ChooseColourDialog->setObjectName(QStringLiteral("ChooseColourDialog"));
        ChooseColourDialog->resize(320, 240);
        widget = new QWidget(ChooseColourDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(50, 40, 221, 131));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        blackButton = new QPushButton(widget);
        blackButton->setObjectName(QStringLiteral("blackButton"));

        horizontalLayout->addWidget(blackButton);

        whiteButton = new QPushButton(widget);
        whiteButton->setObjectName(QStringLiteral("whiteButton"));

        horizontalLayout->addWidget(whiteButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ChooseColourDialog);

        QMetaObject::connectSlotsByName(ChooseColourDialog);
    } // setupUi

    void retranslateUi(QDialog *ChooseColourDialog)
    {
        ChooseColourDialog->setWindowTitle(QApplication::translate("ChooseColourDialog", "Dialog", 0));
        label->setText(QApplication::translate("ChooseColourDialog", "Choose the colour:", 0));
        blackButton->setText(QApplication::translate("ChooseColourDialog", "\351\273\221\345\255\220", 0));
        whiteButton->setText(QApplication::translate("ChooseColourDialog", "\347\231\275\345\255\220", 0));
    } // retranslateUi

};

namespace Ui {
    class ChooseColourDialog: public Ui_ChooseColourDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSECOLOURDIALOG_H
