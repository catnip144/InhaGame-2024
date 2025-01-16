#pragma once
class iMap
{
// interface
public:
	virtual bool GetHeight(IN float x, OUT float& y, IN float z) = 0;

	virtual void Render() = 0;
};
