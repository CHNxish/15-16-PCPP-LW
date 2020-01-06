#include "SalesItem.h"

double SalesItem::avg_price() const {
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}