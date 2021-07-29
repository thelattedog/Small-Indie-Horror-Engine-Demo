#pragma once
class Renderable
{
public:
	Renderable();
	virtual ~Renderable();
	virtual void Render() = 0;

};

