#pragma once
#include "cCharacter.h"
class cCubeMan :
    public cCharacter
{
public:
    cCubeMan();
    virtual ~cCubeMan();

protected:
    cCubeNode* m_pRoot;
    D3DMATERIAL9    m_stMt1;

public:
    virtual void Setup() override;
    virtual void Update() override;
    virtual void Render() override;
};

