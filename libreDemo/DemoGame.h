#pragma once

#include "libre/libre.h"

#include <iostream>
#include <ctime>

using namespace std;
using namespace libre;

class DemoGame : public Game
{
protected:
    virtual void Initialize() override;
};