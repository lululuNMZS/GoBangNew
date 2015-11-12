/********************************************************************************
** Form generated from reading UI file 'qshowboard.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QSHOWBOARD_H
#define UI_QSHOWBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QShowBoard
{
public:

    void setupUi(QWidget *QShowBoard)
    {
        if (QShowBoard->objectName().isEmpty())
            QShowBoard->setObjectName(QStringLiteral("QShowBoard"));
        QShowBoard->resize(293, 219);

        retranslateUi(QShowBoard);

        QMetaObject::connectSlotsByName(QShowBoard);
    } // setupUi

    void retranslateUi(QWidget *QShowBoard)
    {
        QShowBoard->setWindowTitle(QApplication::translate("QShowBoard", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class QShowBoard: public Ui_QShowBoard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QSHOWBOARD_H
