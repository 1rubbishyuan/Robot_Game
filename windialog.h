#ifndef WINDIALOG_H
#define WINDIALOG_H

#include <QDialog>

namespace Ui {
class WinDialog;
}

class WinDialog : public QDialog
{
    Q_OBJECT
public:
    explicit WinDialog(QString contents,QWidget *parent = nullptr);
    ~WinDialog();
    void mwrite(QString s);
signals:
    void gopressed();
    void cutpressed();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::WinDialog *ui;
};

#endif // WINDIALOG_H
