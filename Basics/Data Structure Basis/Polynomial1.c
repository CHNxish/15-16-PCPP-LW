/*
ADT Polynomial
    数据对象：px = a1x^e1 + ... + anx^en; 有序二元组集合<ei,ai>
            ai ∈ Coefficients, ei ∈ Exponents, ei≥0 是整数
    成员函数：
        以下poly, poly1, poly2 ∈ Polynomial,
           coef ∈ Coefficients, expon ∈ Exponents
        Polynomilal Zero()              ::= return 多项式 p(x) = 0
        Boolean IsZero(poly)            ::= if (poly) return FALSE
                                            else return TRUE
        Coefficient Coef(poly, expon)   ::= if (expon∈poly)
                                               return 该项系数 coef
                                            else return 0
        Exponent LeadExp(poly)          ::= if (expon∈poly) 在poly
                                               中删除指数为expon的项，
                                               return poly
        Polynomial
        SingleMult(poly, coef, expon)   ::= return poly*coef*x^Exponent
        Polynomial Add(poly1, poly2)    ::= return poly1 + poly2
        Polynomial Mult(poly1, poly2)   ::= return poly1 * poly2
        Polynomial ReadPoly(poly)       ::= 读取 p(x)
        Interge PrintPoly(poly)         ::= 输出 p(x)
        void SortPoly(poly)             ::= 递增排序 p(x)
end Polynomial



*/
