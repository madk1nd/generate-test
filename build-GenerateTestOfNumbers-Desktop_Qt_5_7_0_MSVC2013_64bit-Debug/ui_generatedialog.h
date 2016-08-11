/********************************************************************************
** Form generated from reading UI file 'generatedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERATEDIALOG_H
#define UI_GENERATEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_generatedialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QGroupBox *rangeGroupBox;
    QHBoxLayout *horizontalLayout_5;
    QGridLayout *gridLayout_2;
    QCheckBox *easyRangeCheckBox;
    QCheckBox *normalRangeCheckBox;
    QCheckBox *hardRangeCheckBox;
    QGroupBox *radixGroupBox;
    QHBoxLayout *horizontalLayout_4;
    QGridLayout *gridLayout;
    QCheckBox *radix10And2CheckBox;
    QCheckBox *radix2And8CheckBox;
    QCheckBox *radix10AndRandomCheckBox;
    QCheckBox *radix10And8CheckBox;
    QCheckBox *radix2And16CheckBox;
    QCheckBox *radixRandomAnd10CheckBox;
    QCheckBox *radix10And16CheckBox;
    QCheckBox *radix8And16CheckBox;
    QCheckBox *radixRandomAndRandomCheckBox;
    QGroupBox *formulationGroupBox;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout;
    QCheckBox *formulationHowCheckBox;
    QCheckBox *formulationWhatCheckBox;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *variantLabel;
    QSpinBox *variantSpinBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *questionLabel;
    QSpinBox *questionSpinBox;
    QHBoxLayout *horizontalLayout_8;
    QLineEdit *lineEdit;
    QPushButton *browseButton;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *createButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *cancelButton;

    void setupUi(QWidget *generatedialog)
    {
        if (generatedialog->objectName().isEmpty())
            generatedialog->setObjectName(QStringLiteral("generatedialog"));
        generatedialog->resize(470, 293);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(generatedialog->sizePolicy().hasHeightForWidth());
        generatedialog->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(generatedialog);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        rangeGroupBox = new QGroupBox(generatedialog);
        rangeGroupBox->setObjectName(QStringLiteral("rangeGroupBox"));
        horizontalLayout_5 = new QHBoxLayout(rangeGroupBox);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        easyRangeCheckBox = new QCheckBox(rangeGroupBox);
        easyRangeCheckBox->setObjectName(QStringLiteral("easyRangeCheckBox"));
        easyRangeCheckBox->setChecked(true);

        gridLayout_2->addWidget(easyRangeCheckBox, 0, 0, 1, 1);

        normalRangeCheckBox = new QCheckBox(rangeGroupBox);
        normalRangeCheckBox->setObjectName(QStringLiteral("normalRangeCheckBox"));

        gridLayout_2->addWidget(normalRangeCheckBox, 1, 0, 1, 1);

        hardRangeCheckBox = new QCheckBox(rangeGroupBox);
        hardRangeCheckBox->setObjectName(QStringLiteral("hardRangeCheckBox"));

        gridLayout_2->addWidget(hardRangeCheckBox, 2, 0, 1, 1);


        horizontalLayout_5->addLayout(gridLayout_2);


        horizontalLayout_7->addWidget(rangeGroupBox);

        radixGroupBox = new QGroupBox(generatedialog);
        radixGroupBox->setObjectName(QStringLiteral("radixGroupBox"));
        horizontalLayout_4 = new QHBoxLayout(radixGroupBox);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        radix10And2CheckBox = new QCheckBox(radixGroupBox);
        radix10And2CheckBox->setObjectName(QStringLiteral("radix10And2CheckBox"));
        radix10And2CheckBox->setChecked(true);

        gridLayout->addWidget(radix10And2CheckBox, 0, 0, 1, 1);

        radix2And8CheckBox = new QCheckBox(radixGroupBox);
        radix2And8CheckBox->setObjectName(QStringLiteral("radix2And8CheckBox"));

        gridLayout->addWidget(radix2And8CheckBox, 0, 1, 1, 1);

        radix10AndRandomCheckBox = new QCheckBox(radixGroupBox);
        radix10AndRandomCheckBox->setObjectName(QStringLiteral("radix10AndRandomCheckBox"));

        gridLayout->addWidget(radix10AndRandomCheckBox, 0, 2, 1, 1);

        radix10And8CheckBox = new QCheckBox(radixGroupBox);
        radix10And8CheckBox->setObjectName(QStringLiteral("radix10And8CheckBox"));

        gridLayout->addWidget(radix10And8CheckBox, 1, 0, 1, 1);

        radix2And16CheckBox = new QCheckBox(radixGroupBox);
        radix2And16CheckBox->setObjectName(QStringLiteral("radix2And16CheckBox"));

        gridLayout->addWidget(radix2And16CheckBox, 1, 1, 1, 1);

        radixRandomAnd10CheckBox = new QCheckBox(radixGroupBox);
        radixRandomAnd10CheckBox->setObjectName(QStringLiteral("radixRandomAnd10CheckBox"));

        gridLayout->addWidget(radixRandomAnd10CheckBox, 1, 2, 1, 1);

        radix10And16CheckBox = new QCheckBox(radixGroupBox);
        radix10And16CheckBox->setObjectName(QStringLiteral("radix10And16CheckBox"));

        gridLayout->addWidget(radix10And16CheckBox, 2, 0, 1, 1);

        radix8And16CheckBox = new QCheckBox(radixGroupBox);
        radix8And16CheckBox->setObjectName(QStringLiteral("radix8And16CheckBox"));

        gridLayout->addWidget(radix8And16CheckBox, 2, 1, 1, 1);

        radixRandomAndRandomCheckBox = new QCheckBox(radixGroupBox);
        radixRandomAndRandomCheckBox->setObjectName(QStringLiteral("radixRandomAndRandomCheckBox"));

        gridLayout->addWidget(radixRandomAndRandomCheckBox, 2, 2, 1, 1);


        horizontalLayout_4->addLayout(gridLayout);


        horizontalLayout_7->addWidget(radixGroupBox);


        verticalLayout_2->addLayout(horizontalLayout_7);

        formulationGroupBox = new QGroupBox(generatedialog);
        formulationGroupBox->setObjectName(QStringLiteral("formulationGroupBox"));
        horizontalLayout_6 = new QHBoxLayout(formulationGroupBox);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formulationHowCheckBox = new QCheckBox(formulationGroupBox);
        formulationHowCheckBox->setObjectName(QStringLiteral("formulationHowCheckBox"));
        formulationHowCheckBox->setChecked(true);

        verticalLayout->addWidget(formulationHowCheckBox);

        formulationWhatCheckBox = new QCheckBox(formulationGroupBox);
        formulationWhatCheckBox->setObjectName(QStringLiteral("formulationWhatCheckBox"));

        verticalLayout->addWidget(formulationWhatCheckBox);


        horizontalLayout_6->addLayout(verticalLayout);


        verticalLayout_2->addWidget(formulationGroupBox);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        variantLabel = new QLabel(generatedialog);
        variantLabel->setObjectName(QStringLiteral("variantLabel"));

        horizontalLayout->addWidget(variantLabel);

        variantSpinBox = new QSpinBox(generatedialog);
        variantSpinBox->setObjectName(QStringLiteral("variantSpinBox"));
        variantSpinBox->setMinimum(1);
        variantSpinBox->setMaximum(20);
        variantSpinBox->setValue(3);

        horizontalLayout->addWidget(variantSpinBox);


        horizontalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        questionLabel = new QLabel(generatedialog);
        questionLabel->setObjectName(QStringLiteral("questionLabel"));

        horizontalLayout_2->addWidget(questionLabel);

        questionSpinBox = new QSpinBox(generatedialog);
        questionSpinBox->setObjectName(QStringLiteral("questionSpinBox"));
        questionSpinBox->setMinimum(1);
        questionSpinBox->setMaximum(50);
        questionSpinBox->setValue(10);

        horizontalLayout_2->addWidget(questionSpinBox);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        lineEdit = new QLineEdit(generatedialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setEnabled(true);
        lineEdit->setReadOnly(true);

        horizontalLayout_8->addWidget(lineEdit);

        browseButton = new QPushButton(generatedialog);
        browseButton->setObjectName(QStringLiteral("browseButton"));

        horizontalLayout_8->addWidget(browseButton);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        createButton = new QPushButton(generatedialog);
        createButton->setObjectName(QStringLiteral("createButton"));

        horizontalLayout_9->addWidget(createButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_2);

        cancelButton = new QPushButton(generatedialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout_9->addWidget(cancelButton);


        verticalLayout_2->addLayout(horizontalLayout_9);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(generatedialog);

        QMetaObject::connectSlotsByName(generatedialog);
    } // setupUi

    void retranslateUi(QWidget *generatedialog)
    {
        generatedialog->setWindowTitle(QApplication::translate("generatedialog", "\320\223\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\202\320\265\321\201\321\202", 0));
        rangeGroupBox->setTitle(QApplication::translate("generatedialog", "\320\224\320\270\320\260\320\277\320\260\320\267\320\276\320\275 \321\207\320\270\321\201\320\265\320\273", 0));
        easyRangeCheckBox->setText(QApplication::translate("generatedialog", "0-256", 0));
        normalRangeCheckBox->setText(QApplication::translate("generatedialog", "256-1024", 0));
        hardRangeCheckBox->setText(QApplication::translate("generatedialog", "1024-4096", 0));
        radixGroupBox->setTitle(QApplication::translate("generatedialog", "\320\241\320\270\321\201\321\202\320\265\320\274\321\213 \321\201\321\207\320\270\321\201\320\273\320\265\320\275\320\270\321\217", 0));
        radix10And2CheckBox->setText(QApplication::translate("generatedialog", "10 \320\270 2", 0));
        radix2And8CheckBox->setText(QApplication::translate("generatedialog", "2 \320\270 8", 0));
        radix10AndRandomCheckBox->setText(QApplication::translate("generatedialog", "10 \320\270 ?", 0));
        radix10And8CheckBox->setText(QApplication::translate("generatedialog", "10 \320\270 8", 0));
        radix2And16CheckBox->setText(QApplication::translate("generatedialog", "2 \320\270 16", 0));
        radixRandomAnd10CheckBox->setText(QApplication::translate("generatedialog", "? \320\270 10", 0));
        radix10And16CheckBox->setText(QApplication::translate("generatedialog", "10 \320\270 16", 0));
        radix8And16CheckBox->setText(QApplication::translate("generatedialog", "8 \320\270 16", 0));
        radixRandomAndRandomCheckBox->setText(QApplication::translate("generatedialog", "? \320\270 ?", 0));
        formulationGroupBox->setTitle(QApplication::translate("generatedialog", "\320\244\320\276\321\200\320\274\321\203\320\273\320\270\321\200\320\276\320\262\320\272\320\260 \320\262\320\276\320\277\321\200\320\276\321\201\320\276\320\262", 0));
        formulationHowCheckBox->setText(QApplication::translate("generatedialog", "\320\232\320\260\320\272 \320\277\321\200\320\265\320\264\321\201\321\202\320\260\320\262\320\273\320\265\320\275\320\276 \321\207\320\270\321\201\320\273\320\276 X \321\201 \320\276\321\201\320\275\320\276\320\262\320\260\320\275\320\270\320\265\320\274 Y \320\262 \321\201\320\270\321\201\321\202\320\265\320\274\320\265 \321\201\321\207\320\270\321\201\320\273\320\265\320\275\320\270\321\217 \321\201 \320\276\321\201\320\275\320\276\320\262\320\260\320\275\320\270\320\265\320\274 Z?", 0));
        formulationWhatCheckBox->setText(QApplication::translate("generatedialog", "\320\247\320\265\320\274\321\203 \321\200\320\260\320\262\320\275\320\276 \321\207\320\270\321\201\320\273\320\276 X \321\201 \320\276\321\201\320\275\320\276\320\262\320\260\320\275\320\270\320\265\320\274 Y \320\262 \321\201\320\270\321\201\321\202\320\265\320\274\320\265 \321\201\321\207\320\270\321\201\320\273\320\265\320\275\320\270\321\217 \321\201 \320\276\321\201\320\275\320\276\320\262\320\260\320\275\320\270\320\265\320\274 Z?", 0));
        variantLabel->setText(QApplication::translate("generatedialog", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\262\320\260\321\200\320\270\320\260\320\275\321\202\320\276\320\262", 0));
        questionLabel->setText(QApplication::translate("generatedialog", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\262\320\276\320\277\321\200\320\276\321\201\320\276\320\262", 0));
        browseButton->setText(QApplication::translate("generatedialog", "\320\236\320\261\320\267\320\276\321\200", 0));
        createButton->setText(QApplication::translate("generatedialog", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", 0));
        cancelButton->setText(QApplication::translate("generatedialog", "\320\222\321\213\321\205\320\276\320\264", 0));
    } // retranslateUi

};

namespace Ui {
    class generatedialog: public Ui_generatedialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERATEDIALOG_H
