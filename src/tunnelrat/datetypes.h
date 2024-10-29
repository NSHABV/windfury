#ifndef DATETYPES_H
#define DATETYPES_H

#include <QtGlobal>

namespace TunnelRat::Date
{

using DateIndex = quint16; // Maximum is 65,535 - there are 365 days per year. Enough indexes for 2000-2150 est.

struct EventTime
{
    quint8 hours;
    quint8 minutes;
    quint8 seconds; // May be separately enabled later.
};

};

#endif // DATETYPES_H
