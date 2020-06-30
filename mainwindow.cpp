#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    QGroupBox *echoGroup = new QGroupBox(tr("Echo"));

    QLabel *echoLable = new QLabel(tr("Mode"));
    QComboBox *echoComboBox = new QComboBox;
    echoComboBox->addItem(tr("Normal"));
    echoComboBox->addItem(tr("Password"));
    echoComboBox->addItem(tr("PasswordEchoOnEdit"));
    echoComboBox->addItem(tr("No Echo"));

    echoLineEdit = new QLineEdit;
    echoLineEdit->setPlaceholderText("Placeholder Text");
    echoLineEdit->setFocus();

    QGroupBox *validatorGroup = new QGroupBox(tr("Validator"));

    QLabel *validatorLabel = new QLabel(tr("Type:"));
    QComboBox *validatorComboBox = new QComboBox;
    validatorComboBox->addItem(tr("No Validator"));
    validatorComboBox->addItem(tr("Integer validator"));
    validatorComboBox->addItem(tr("Double Validator"));

    validatorLineEdit = new QLineEdit;
    validatorLineEdit->setPlaceholderText("Placeholder Text");

    QGroupBox *alignmentGroup = new QGroupBox(tr("Alignment"));

    QLabel *alignmentLabel = new QLabel(tr("Type: "));
    QComboBox *alignmentComboBox = new QComboBox;
    alignmentComboBox->addItem(tr("Left"));
    alignmentComboBox->addItem(tr("Centered"));
    alignmentComboBox->addItem(tr("Right"));

    alignmentLineEdit = new QLineEdit;
    alignmentLineEdit->setPlaceholderText("Placeholder Text");

    QGroupBox *inputMaskGroup = new QGroupBox(tr("Input Mask"));

    QLabel *inputMaskLabel = new QLabel(tr("Type: "));
    QComboBox *inputMaskComboBox = new QComboBox;
    inputMaskComboBox->addItem(tr("No Mask"));
    inputMaskComboBox->addItem(tr("Phone Number"));
    inputMaskComboBox->addItem(tr("ISO Date"));
    inputMaskComboBox->addItem(tr("License Key"));

    inputMaskLineEdit = new QLineEdit;
    inputMaskLineEdit->setPlaceholderText("Placeholder Text");

    QGroupBox *accessGroup = new QGroupBox(tr("Access"));

    QLabel *accessLabel = new QLabel(tr("Read-only:"));
    QComboBox *accessComboBox = new QComboBox;
    accessComboBox->addItem(tr("False"));
    accessComboBox->addItem(tr("True"));

    accessLineEdit = new QLineEdit;
    accessLineEdit->setPlaceholderText("Placeholder Text");

    QGroupBox *scatterGroupBox = new QGroupBox(tr("Scatter Plot"));

    connect(echoComboBox, QOverload<int>::of(&QComboBox::activated),
            this, &MainWindow::echoChanged);
    connect(validatorComboBox, QOverload<int>::of(&QComboBox::activated),
            this, &MainWindow::validatorChanged);
    connect(alignmentComboBox, QOverload<int>::of(&QComboBox::activated),
            this, &MainWindow::alignmentChanged);
    connect(inputMaskComboBox, QOverload<int>::of(&QComboBox::activated),
            this, &MainWindow::inputMaskChanged);
    connect(accessComboBox, QOverload<int>::of(&QComboBox::activated),
            this, &MainWindow::accessChanged);

    QGridLayout *echoLayout = new QGridLayout;
    echoLayout->addWidget(echoLable, 0,0);
    echoLayout->addWidget(echoComboBox, 0, 1);
    echoLayout->addWidget(echoLineEdit, 1, 0, 1, 2);
    echoGroup->setLayout(echoLayout);

    QGridLayout *validatorLayout = new QGridLayout;
    validatorLayout->addWidget(validatorLabel, 0, 0);
    validatorLayout->addWidget(validatorComboBox, 0, 1);
    validatorLayout->addWidget(validatorLineEdit, 1, 0, 1, 2);
    validatorGroup->setLayout(validatorLayout);

    QGridLayout *alignmentLayout = new QGridLayout;
    alignmentLayout->addWidget(alignmentLabel, 0, 0);
    alignmentLayout->addWidget(alignmentComboBox, 0, 1);
    alignmentLayout->addWidget(alignmentLineEdit, 1, 0, 1, 2);
    alignmentGroup->setLayout(alignmentLayout);

    QGridLayout *inputMaskLayout = new QGridLayout;
    inputMaskLayout->addWidget(inputMaskLabel, 0, 0);
    inputMaskLayout->addWidget(inputMaskComboBox, 0, 1);
    inputMaskLayout->addWidget(inputMaskLineEdit, 1, 0, 1, 2);
    inputMaskGroup->setLayout(inputMaskLayout);

    QGridLayout *accessLayout = new QGridLayout;
    accessLayout->addWidget(accessLabel, 0, 0);
    accessLayout->addWidget(accessComboBox, 0, 1);
    accessLayout->addWidget(accessLineEdit, 1, 0, 1, 2);
    accessGroup->setLayout(accessLayout);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(echoGroup, 0, 0);
    layout->addWidget(validatorGroup, 1, 0);
    layout->addWidget(alignmentGroup, 2, 0);
    layout->addWidget(inputMaskGroup, 0, 1);
    layout->addWidget(accessGroup, 1, 1);
    layout->addWidget(scatterGroupBox, 2,1);
    setLayout(layout);

    setWindowTitle(tr("Line Edits"));

//    ui->setupUi(this);
}

void MainWindow::echoChanged(int index)
{
    switch (index)
    {
    case 0:
        echoLineEdit->setEchoMode(QLineEdit::Normal);
        break;
    case 1:
        echoLineEdit->setEchoMode(QLineEdit::Password);
        break;
    case 2:
        echoLineEdit->setEchoMode(QLineEdit::PasswordEchoOnEdit);
        break;
    case 3:
        echoLineEdit->setEchoMode(QLineEdit::NoEcho);
        break;
    }
}

void MainWindow::validatorChanged(int index)
{
    switch (index)
    {
    case 0:
        validatorLineEdit->setValidator(nullptr);
        break;
    case 1:
        validatorLineEdit->setValidator(new QIntValidator(validatorLineEdit));
        break;
    case 2:
        validatorLineEdit->setValidator(new QDoubleValidator(-999.0, 999.0, 2, validatorLineEdit));
        break;
    }

    validatorLineEdit->clear();
}

void MainWindow::alignmentChanged(int index)
{
    switch (index)
    {
    case 0:
        alignmentLineEdit->setAlignment(Qt::AlignLeft);
        break;
    case 1:
        alignmentLineEdit->setAlignment(Qt::AlignCenter);
        break;
    case 2:
        alignmentLineEdit->setAlignment(Qt::AlignRight);
        break;
    }
}

void MainWindow::inputMaskChanged(int index)
{
    switch (index)
    {
    case 0:
        inputMaskLineEdit->setInputMask("");
        break;
    case 1:
        inputMaskLineEdit->setInputMask("+1 999-999-9999;_");
        break;
    case 2:
        inputMaskLineEdit->setInputMask("0000-00-00");
        inputMaskLineEdit->setText("00000000");
        inputMaskLineEdit->setCursorPosition(0);
        break;
    case 3:
        inputMaskLineEdit->setInputMask("AAAAA-AAAAA-AAAAA-AAAAA-AAAAA;#");
        break;
    }
}

void MainWindow::accessChanged(int index)
{
    switch (index)
    {
    case 0:
        accessLineEdit->setReadOnly(false);
        break;
    case 1:
        accessLineEdit->setReadOnly(true);
        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

