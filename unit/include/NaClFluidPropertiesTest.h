//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#ifndef NACLFLUIDPROPERTIESTEST_H
#define NACLFLUIDPROPERTIESTEST_H

#include "MooseObjectUnitTest.h"
#include "NaClFluidProperties.h"

class NaClFluidPropertiesTest : public MooseObjectUnitTest
{
public:
  NaClFluidPropertiesTest() : MooseObjectUnitTest("MooseUnitApp")
  {
    registerObjects(_factory);
    buildObjects();
  }

protected:
  void registerObjects(Factory & factory) { registerUserObject(NaClFluidProperties); }

  void buildObjects()
  {
    InputParameters uo_pars = _factory.getValidParams("NaClFluidProperties");
    _fe_problem->addUserObject("NaClFluidProperties", "fp", uo_pars);
    _fp = &_fe_problem->getUserObject<NaClFluidProperties>("fp");
  }

  const NaClFluidProperties * _fp;
};

#endif // NACLFLUIDPROPERTIESTEST_H
