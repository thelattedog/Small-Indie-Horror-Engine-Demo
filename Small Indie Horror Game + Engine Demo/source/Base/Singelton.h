#pragma once

// singelton template class
template<class T>
class Singelton
{
public:
	static T& Instantiate();
private:
	Singelton();
};

template<class T>
T& Singelton<T>::Instantiate()
{
	static T obj;
	return obj;
}

template<class T>
Singelton<T>::Singelton(){}