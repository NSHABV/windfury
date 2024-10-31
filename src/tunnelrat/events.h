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

    void setRepeatable(bool set);
    bool isRepeatable(bool set);
    EventTime getRepeatTime();
    void setRepeatTime(const EventTime &repeatTime);

    void setTime(const EventTime &eventTime);
    EventTime getTime();

    void setName(const QString& name);
    QString getName() const;
protected:
    EventTime mTime;

    bool mRepeatable;
    EventTime mRepeatTime;

    QString mName;
};

class TransactionEvent : public Event
{
public:
    TransactionEvent(const EventTime &eventTime, const QString &name, TransactionVal mVal);

    virtual TransactionVal getValue() const;
    void setValue(TransactionVal mVal);

    virtual TransactionEvent operator+(const TransactionEvent &other);
protected:
    TransactionVal mVal;
    TransactionPriority mPriority;
};

class ConsumptionEvent : public TransactionEvent
{
    friend class TransactionEvent;
    ConsumptionEvent(const EventTime &eventTime, const QString &name, const Meal &meal);
    ConsumptionEvent(const EventTime &eventTime, const QString &name, const Meal &meal, TransactionVal mVal);

    ConsumptionEvent operator+(const ConsumptionEvent &other);

    void setMeal(const Meal &meal);
    virtual Meal getMeal() const;
protected:
    Meal mCaloricVal;
};
};
#endif // EVENTS_H
