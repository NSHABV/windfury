#ifndef TUNNELEVENTITEM_H
#define TUNNELEVENTITEM_H
#include <QListWidgetItem>

#include "tunnelrat/events.h"

using namespace TunnelRat::Date;
using namespace TunnelRat::Math;
using namespace TunnelRat::Calendar

class TunnelEventItem : public QListWidgetItem
{
public:
    TunnelEventItem();
};
#endif // TUNNELEVENTITEM_H
