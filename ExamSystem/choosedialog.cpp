#include "choosedialog.h"

class chooseDialogData : public QSharedData
{
public:

};

chooseDialog::chooseDialog() : data(new chooseDialogData)
{

}

chooseDialog::chooseDialog(const chooseDialog &rhs) : data(rhs.data)
{

}

chooseDialog &chooseDialog::operator=(const chooseDialog &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

chooseDialog::~chooseDialog()
{

}
