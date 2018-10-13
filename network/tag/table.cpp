#include "table.h"

QString Table::name()
{
    return "table";
}

bool Table::isSelfClosing() {
    return false;
}
