#include "framework.h";
#include "cObjectManager.h"

void cObjectManager::AddObject(cObject* pObject)
{
	m_setObject.insert(pObject);
}

void cObjectManager::RemoveObject(cObject* pObject)
{
	m_setObject.erase(pObject);
}

void cObjectManager::Destroy()
{
	m_setObject.clear();
	assert(m_setObject.empty());
}
