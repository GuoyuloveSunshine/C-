template <class Elem> class BinNode{
public:
    virtual Elem & val()=0;
    virtual void setVal(const Elem&)=0;
    virtual BinNode*left() const=0;
    virtual BinNode*right() const=0;
    virtual void setLeft(BinNode*)=0;
    virtual void setRight(BinNode*)=0;
    virtual bool isLeaf()=0;
};