#include "Type.h"

template<class T>
Type ConstructType<T>(T& In) {
	Type T;
	T.Value = In;
	//T.T = T;
	return T;
}

template<class T>
T& Get(Type& In) {
	return In.Value;
}

VariadicArguments ConstructVariadicArguments(Vector<Type>& In) {
	VariadicArguments V;
	V.T = In;

	return V;
}
Type* Get(VariadicArguments& In,size_t I) {
	return Index(In.T, I);
}

template<size_t N>
FixedArguments<N> ConstructFixedArguments<N>(FixedVector<Type,N>& In){
	FixedArguments F:
	F.T = In;

	return F;
}
template<size_t N>
Type* Get(FixedArguments<N>& In,size_t I) {
	return Index(In.T, I);
}