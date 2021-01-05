

template <class Elem> class List {
public:
  virtual void clear() = 0;
  virtual bool insert(const Elem&) = 0;
  virtual bool append(const Elem&) = 0;
  virtual bool remove(Elem&) = 0;
  virtual void setStart() = 0;
  virtual void setEnd() = 0;
  virtual void prev() = 0;
  virtual void next() = 0;
  virtual int leftLength() const = 0;
  virtual int rightLength() const = 0;
  virtual bool setPos(int pos) = 0;
  virtual bool getValue(Elem&) const = 0;
  virtual void print() const = 0;
};


