#pragma once

template <typename T>
class Singleton
{
public:
	static T* Instance() {
		static T* instance = new T();
		return instance;
	}
};

