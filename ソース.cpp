#include <stdio.h>

#include "SurfaceT.h"
#include "Vector.h"
#include "Any.h"
#include "Type.h"

struct LocalMap {
	//type T=RGB24;
	typedef RGB24 T;
	SurfaceT<T> Map;
	VariadicArguments Arg;
	Vector<Any> Secret;
};
LocalMap ConstructLocalMap(LocalMap& In) {
	LocalMap L;
	L.Arg = In.Arg;
	L.Map = In.Map;
	L.Secret = In.Secret;
	//L.T = In.T;

	return L;
}
bool Free(LocalMap& In) {
	Free(In.Map);
	Free(In.Arg);
	Free(In.Secret);

	return true;
}

struct ColorMap {
	//type T=RGB24;
	typedef RGB24 T;
	SurfaceT<T> Map;
	Vector<LocalMap> LocalMaps;
	VariadicArguments Arg;
	Vector<Any> Secret;
};

ColorMap ConstructColorMap(ColorMap& In) {
	ColorMap C;
	C.Map = In.Map;
	C.Arg = In.Arg;
	C.Secret = In.Secret;
	C.LocalMaps = In.LocalMaps;

	return C;
}


bool Free(ColorMap& In) {
	Free(In.Map);
	Free(In.Arg);
	Free(In.Secret);
	Free(In.LocalMaps);

	return true;
}