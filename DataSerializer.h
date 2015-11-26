#pragma once

#include "tinyxml2.h"

using namespace std;

class DataSerializer
{
public:
	DataSerializer();
	~DataSerializer();

	template <typename T>
	static T* LoadData(const wchar_t* dataAsset);
};

template <typename T>
T* DataSerializer::LoadData(const wchar_t* dataAsset)
{
	// Create an instance of the XmlSerializer specifying type and namespace.
	XmlSerializer* serializer = gcnew XmlSerializer(OrderedItem::typeid);

	// A FileStream is needed to read the XML document.
	FileStream* fs = gcnew FileStream(filename, FileMode::Open);
	XmlReader* reader = gcnew XmlTextReader(fs);

	// Declare an object variable of the type to be deserialized.
	T* i;

	// Use the Deserialize method to restore the object's state.
	i = dynamic_cast<T*>(serializer->Deserialize(reader));

	assert(i);

	return i;
}

