#include "events.h"

using namespace TunnelRat::Date;
using namespace TunnelRat::Math;

namespace TunnelRat::Calendar
{

Event::Event(const EventTime &eventTime, const QString &name)
{
    mTime = eventTime;
    bool mRepeatable = false;

    mName = name;
}

void Event::setRepeatable(bool set)
{
    mRepeatable = set;
}

bool Event::isRepeatable(bool set)
{
    return mRepeatable;
}

EventTime Event::getRepeatTime()
{
    if (mRepeatable)
        return EventTime{0, 0, 0};

    return mRepeatTime;
}

void Event::setRepeatTime(const EventTime &repeatTime)
{
    if (!mRepeatable)
        mRepeatTime = repeatTime;
}

void Event::setTime(const EventTime &eventTime)
{
    mTime = eventTime;
}

EventTime Event::getTime()
{
    return mTime;
}

void Event::setName(const QString& name)
{
    mName = name;
}

QString Event::getName() const
{
    return mName;
}

TransactionEvent::TransactionEvent(const EventTime &eventTime, const QString &name, TransactionVal mVal) : Event(eventTime, name)
{
    mVal = mVal;
    mPriority = TransactionPriority::Default;
}

TransactionVal TransactionEvent::getValue() const
{
    return mVal;
}

void TransactionEvent::setValue(TransactionVal mVal)
{
    mVal = mVal;
}

TransactionEvent TransactionEvent::operator+(const TransactionEvent &other)
{
    TransactionVal newVal;
    newVal = this->mVal + other.mVal;
    return TransactionEvent(this->mTime, this->mName, newVal);
}


ConsumptionEvent::ConsumptionEvent(const EventTime &eventTime, const QString &name, const Meal &meal) : TransactionEvent(eventTime, name, 0)
{
    mCaloricVal = meal;
}

ConsumptionEvent::ConsumptionEvent(const EventTime &eventTime, const QString &name, const Meal &meal, TransactionVal val) 
    : TransactionEvent(eventTime, name, val)
{
    mCaloricVal = meal;
}

ConsumptionEvent ConsumptionEvent::operator+(const ConsumptionEvent &other)
{
    auto mealPass = this->getMeal();
    auto otherMeal = other.getMeal().nutritionalContents;
    for (auto key : otherMeal.keys())
    {
        if (this->mCaloricVal.nutritionalContents.contains(key))
        {
            qint16 val = this->mCaloricVal.nutritionalContents.value(key) + otherMeal.value(key);
            mealPass.nutritionalContents.insert(key, val);
        }
    }

    return ConsumptionEvent(this->getTime(), this->getName(), mealPass, this->getValue() + other.getValue());
}

void ConsumptionEvent::setMeal(const Meal &meal)
{
    mCaloricVal = meal;
}

Meal ConsumptionEvent::getMeal() const
{
    return mCaloricVal;
}
};
