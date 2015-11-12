/********************************************************************************
** Form generated from reading UI file 'qchesspiece.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QCHESSPIECE_H
#define UI_QCHESSPIECE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QChessPiece
{
public:

    void setupUi(QWidget *QChessPiece)
    {
        if (QChessPiece->objectName().isEmpty())
            QChessPiece->setObjectName(QStringLiteral("QChessPiece"));
        QChessPiece->resize(46, 42);

        retranslateUi(QChessPiece);

        QMetaObject::connectSlotsByName(QChessPiece);
    } // setupUi

    void retranslateUi(QWidget *QChessPiece)
    {
        QChessPiece->setWindowTitle(QApplication::translate("QChessPiece", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class QChessPiece: public Ui_QChessPiece {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QCHESSPIECE_H
