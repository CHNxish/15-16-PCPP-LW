#ifndef _SALES_ITEM_H_
#define _SALES_ITEM_H_

#include <iostream>
#include <string>

class SalesItem {
public:
    SalesItem(): units_sold(0), revenue(0.0) {}
    ~SalesItem() {}

    double avg_price() const;
    bool same_isbn(const SalesItem &rhs) const {
        return isbn == rhs.isbn;
    }

    friend std::istream &operator>>(std::istream &in, SalesItem &s) {
        in >> s.isbn >> s.units_sold >> s.revenue;
        return in;
    }
    friend std::ostream &operator<<(std::ostream &out, SalesItem &s) {
        out << s.isbn << " " << s.units_sold << " " << s.revenue << std::endl;
        return out;
    }

private:
    std::string isbn;
    unsigned units_sold;
    double revenue;
};

#endif
