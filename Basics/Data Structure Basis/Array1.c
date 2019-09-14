/*
ADT Array
    数据对象：二元组<index, value>的集合，对每个index，都有一个相应的取自集合
        Item中的value与之对应，Index是有限的一维或多维有序集合，例如，一维Index
        可以是{0,1,...,n-1}，二维Index可以是{{0,0},{0,1},...{n-1,m-1}}等
    成员函数
        以下 A ∈ Array, i ∈ Index, x ∈ Item, j,size ∈ integer
        Array Create(j, list)   ::= return 维数为j的数组，list是j元组，它的
                                    第i个元素是第i维的维数，数组元素的值未定义。
        Item Retriev(A, i)      ::= if (i∈Index) return 数组A中i对应的值
                                    else return 出错信息
        Array Store(A, i, x)    ::= if (i∈Index) 在A中更新二元组<i,x>并返回A
                                    else return 出错消息
end Array
*/
