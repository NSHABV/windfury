#ifndef MATHTYPES_H
#define MATHTYPES_H

#include <QtGlobal>
#include <QMap>

namespace TunnelRat::Math
{
enum TransactionPriority
{
    Low, Default, Medium, High, Critical
};

// TODO: Expand to include more types.
enum NutritionType
{
    Fat, Protein, Carbohydrates
};

enum MealType
{
    Breakfast, Lunch, Dinner, Other, Junkfood
};

using SumVal = quint64; // No idea what kind of money you're using, man. Hope it's dollars.
using TransactionVal = quint32;
using WeightVal = qint16;

}

#endif // MATHTYPES_H
