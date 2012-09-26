class BaseClass {
	// sub class and any other object can access public member directly
	public: 
		int _varOne; // public member field
		BaseClass()
		{
			_varOne = 0;
			_varTwo = 0;
			_varThree = 0;       
		}
		// where _varOne(varOne) denotes assign varOne to _varOne
		BaseClass (int varOne, int varTwo, int varThree) : _varOne(varOne),
				_varTwo(varTwo), _varThree(varThree)
		{
		}
		int getVarOne ()
		{
			return _varOne;
		}
		int getVarTwo ()
		{
			return _varTwo;
		}
		int getVarThree ()
		{
			return _varThree;
		}
	// sub class can access protected member directly
	// any other object cannot access protected member directly
	protected:
		int _varTwo; // protected member field
	// sub class and any other object cannot access private member directly
	private:
		int _varThree; // private member field
}; 
