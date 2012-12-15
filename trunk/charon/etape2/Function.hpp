template <typename T>
class Function;

template <typename T, typename P1>
class Function<T(P1)>
{
  typedef Function<T(P1)>& ret;
  typedef T (*ptr)(P1);
 
  // interface
  class IFuncType
  {
  public:
    virtual T  operator()(P1 const&) = 0;
    virtual ~IFuncType(){};
  };
  
  // class templété
  template <typename C>
  class FuncTypeTemplated : public IFuncType
  {
    C*	_funcPtr;
 
  public:
    FuncTypeTemplated() : _funcPtr(0) {}
    FuncTypeTemplated(C const& p) : _funcPtr(new C(p)) {}
    FuncTypeTemplated(FuncTypeTemplated<C> const& f) : _funcPtr(f._funcPtr) {}
    FuncTypeTemplated(FuncTypeTemplated<T(P1)> const& f) : _funcPtr(f._funcPtr) {}
    virtual ~FuncTypeTemplated() { delete _funcPtr; }
 
    T                   operator()(P1 const& p)
    {
      if (_funcPtr)
	return _funcPtr->operator()(p);
      return T(p);
    }
  };

  // class templété spécialisé
  template <typename PTR, typename A1>
  class FuncTypeTemplated<PTR(A1)> : public IFuncType
  {
    ptr         _o;
 
  public:
    FuncTypeTemplated() : _o(0) {}
    FuncTypeTemplated(ptr p) : _o(p) {}
    FuncTypeTemplated(FuncTypeTemplated<T(P1)> const& f) : _o(f._o) {}
    T	operator()(P1 const& p) { return _o(p); }
    virtual ~FuncTypeTemplated() {}
  };
 
  // membre
  IFuncType*      _funcPtr;

public:
  Function() : _funcPtr(0) {}
  template <typename C>
  Function(C const& p) : _funcPtr(new FuncTypeTemplated<C>(p)) {}
  Function(ptr p) : _funcPtr(new FuncTypeTemplated<T(P1)>(p)) {}
  Function(Function<T(P1)> const& f) : _funcPtr(f._funcPtr){}
 
  T                     operator()(P1 const& p)
  {
    if (_funcPtr)
      return _funcPtr->operator()(p);
    return T();
  }

  ret	operator=(ptr p)
  {
    delete _funcPtr;
    _funcPtr = new FuncTypeTemplated<T(P1)>(p);
    return *this;
  }
 
  template <typename B>
  ret	operator=(B const&b)
  {
    delete _funcPtr;
    _funcPtr = new FuncTypeTemplated<B>(b);
    return *this;
  }
};
