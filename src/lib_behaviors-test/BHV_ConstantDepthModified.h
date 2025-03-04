/*****************************************************************/
/*    NAME: Matthew McMurray                                   */
/*    FILE: BHV_ConstantDepthModified.h                                  */
/*                                                               */
/* This file is part of MOOS-IvP                                 */
/*                                                               */
/* MOOS-IvP is free software: you can redistribute it and/or     */
/* modify it under the terms of the GNU General Public License   */
/* as published by the Free Software Foundation, either version  */
/* 3 of the License, or (at your option) any later version.      */
/*                                                               */
/* MOOS-IvP is distributed in the hope that it will be useful,   */
/* but WITHOUT ANY WARRANTY; without even the implied warranty   */
/* of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See  */
/* the GNU General Public License for more details.              */
/*                                                               */
/* You should have received a copy of the GNU General Public     */
/* License along with MOOS-IvP.  If not, see                     */
/* <http://www.gnu.org/licenses/>.                               */
/*****************************************************************/
 


#ifndef BHV_CONSTANT_DEPTH_MODIFIED_HEADER
#define BHV_CONSTANT_DEPTH_MODIFIED_HEADER

#include "IvPBehavior.h"

class BHV_ConstantDepthModified : public IvPBehavior {
public:
  BHV_ConstantDepthModified(IvPDomain);
  ~BHV_ConstantDepthModified() {}
  
  void         onIdleState() {updateInfoIn();}
  IvPFunction* onRunState();
  bool         setParam(std::string, std::string);
  std::string    expandMacros(std::string);

 protected:
  bool         updateInfoIn();

 protected: // Configuration variables
  double      m_desired_depth;
  double      m_peakwidth;
  double      m_basewidth;
  double      m_summitdelta;
  std::string m_depth_mismatch_var;

 protected: // State variables
  double      m_osd;
};

#define IVP_EXPORT_FUNCTION

extern "C" {
  IVP_EXPORT_FUNCTION IvPBehavior * createBehavior(std::string name, IvPDomain domain)
  {return new BHV_ConstantDepthModified(domain);}
}

#endif










