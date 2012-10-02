class Base {
	public:
		int a;
		Base ()
		{
			a = 1;
		}
};
class Extended : public Base {
	public:
		float b;
		Extended ()
		{
			b = 2.2;
		}
};
class Unrelated {
	public:
		int c;
		float d;
		Unrelated ()
		{
			c = 3;
			d = 4.4;
		}
};
void testImplicitConversion(Base baseInstance, Extended extendedInstance);
void testExplicitConversion (Base baseInstance, Extended extendedInstance, Unrelated unrelatedInstance);
void testDynamicCast(Base baseInstance, Extended extendedInstance, Unrelated unrelatedInstance);
void testStaticCast(Base baseInstance, Extended extendedInstance, Unrelated unrelatedInstance);
void testReinterpretCast(Base baseInstance, Extended extendedInstance, Unrelated unrelatedInstance);
void testConstCast (char* strOne);