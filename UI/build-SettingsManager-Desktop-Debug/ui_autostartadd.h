/********************************************************************************
** Form generated from reading UI file 'autostartadd.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTOSTARTADD_H
#define UI_AUTOSTARTADD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AutoStartAdd
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *comboBoxApp;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AutoStartAdd)
    {
        if (AutoStartAdd->objectName().isEmpty())
            AutoStartAdd->setObjectName(QString::fromUtf8("AutoStartAdd"));
        AutoStartAdd->resize(400, 300);
        AutoStartAdd->setSizeGripEnabled(false);
        AutoStartAdd->setModal(false);
        verticalLayout_2 = new QVBoxLayout(AutoStartAdd);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(AutoStartAdd);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        comboBoxApp = new QComboBox(AutoStartAdd);
        comboBoxApp->setObjectName(QString::fromUtf8("comboBoxApp"));
        comboBoxApp->setEditable(true);

        verticalLayout->addWidget(comboBoxApp);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_2->addLayout(verticalLayout);

        buttonBox = new QDialogButtonBox(AutoStartAdd);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(AutoStartAdd);
        QObject::connect(buttonBox, SIGNAL(accepted()), AutoStartAdd, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AutoStartAdd, SLOT(reject()));

        QMetaObject::connectSlotsByName(AutoStartAdd);
    } // setupUi

    void retranslateUi(QDialog *AutoStartAdd)
    {
        AutoStartAdd->setWindowTitle(QCoreApplication::translate("AutoStartAdd", "Add an app", nullptr));
        label->setText(QCoreApplication::translate("AutoStartAdd", "App", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AutoStartAdd: public Ui_AutoStartAdd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTOSTARTADD_H
