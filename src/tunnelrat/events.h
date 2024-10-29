#ifndef EVENTS_H
#define EVENTS_H
#include <QString>

#include "datetypes.h"
#include "mathtypes.h"

using namespace TunnelRat::Date;
using namespace TunnelRat::Math;

namespace TunnelRat::Calendar
{
struct Meal
{
    QMap<NutritionType, WeightVal> nutritionalContents;
    MealType type;
    QString name;
};

class Event
{
public:
    Event(const EventTime &eventTime, const QString &name);

    void const setRepeatable(bool set);
    bool isRepeatable(bool set);
    EventTime getRepeatTime();
    void const setRepeatTime(const EventTime &repeatTime);

    void const setTime(const EventTime &eventTime);
    EventTime getTime();
protected:
    EventTime mTime;

    bool mRepeatable;
    EventTime mRepeatTime;

    QString name;
};

class TransactionEvent : public Event
{
public:
    TransactionEvent(const EventTime &eventTime, TransactionVal mVal);

    virtual TransactionVal getValue();
    void const setValue(TransactionVal mVal);

    virtual TransactionEvent operator+(const TransactionEvent &other) const;
protected:
    TransactionVal mVal;
    TransactionPriority mPriority;
};

class ConsumptionEvent : public TransactionEvent
{
    ConsumptionEvent(const EventTime &eventTime, const Meal &meal);

    virtual TransactionEvent operator+(const TransactionEvent &other) const override;

    void const setMeal(const Meal &meal);
    virtual Meal getMeal();
protected:
    Meal mCaloricVal;
};
};
#endif // EVENTS_H
