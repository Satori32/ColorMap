#pragma once
#include <stdio.h>

#include "Vector.h"
#include "FixedVector.h"

struct VariadicArguments {
	Vector<Type> T;
};

template<size_t N>
struct FixedArguments {
	FixedVector<Type, N> T;
};

struct Type {
	//type T=NULL:
	typedef int T;
	T Value;
};

template<class T> Type ConstructType<T>(T& In);
template<class T> T& Get(Type& In);
VariadicArguments ConstructVariadicArguments(Vector<Type>& In);
Type* Get(VariadicArguments& In, size_t I);
