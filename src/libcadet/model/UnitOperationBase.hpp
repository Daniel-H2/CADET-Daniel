// =============================================================================
//  CADET - The Chromatography Analysis and Design Toolkit
//  
//  Copyright © 2008-2018: The CADET Authors
//            Please see the AUTHORS and CONTRIBUTORS file.
//  
//  All rights reserved. This program and the accompanying materials
//  are made available under the terms of the GNU Public License v3.0 (or, at
//  your option, any later version) which accompanies this distribution, and
//  is available at http://www.gnu.org/licenses/gpl.html
// =============================================================================

/**
 * @file 
 * Provides a base class for unit operation models.
 */

#ifndef LIBCADET_UNITOPERATIONBASE_HPP_
#define LIBCADET_UNITOPERATIONBASE_HPP_

#include "UnitOperation.hpp"
#include "AutoDiff.hpp"
#include "ParamIdUtil.hpp"

#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace cadet
{

namespace model
{

class IBindingModel;

/**
 * @brief Base class for unit operation models
 * @details Provides parameter handling.
 */
class UnitOperationBase : public IUnitOperation
{
public:

	UnitOperationBase(UnitOpIdx unitOpIdx);
	virtual ~UnitOperationBase() CADET_NOEXCEPT;

	virtual UnitOpIdx unitOperationId() const CADET_NOEXCEPT { return _unitOpIdx; }

	virtual std::unordered_map<ParameterId, double> getAllParameterValues() const;
	virtual double getParameterDouble(const ParameterId& pId) const;
	virtual bool hasParameter(const ParameterId& pId) const;

	virtual bool setParameter(const ParameterId& pId, int value);
	virtual bool setParameter(const ParameterId& pId, double value);
	virtual bool setParameter(const ParameterId& pId, bool value);

	virtual bool setSensitiveParameter(const ParameterId& pId, unsigned int adDirection, double adValue);
	virtual void setSensitiveParameterValue(const ParameterId& id, double value);

	virtual void clearSensParams();
	virtual unsigned int numSensParams() const;

	virtual int residualSensFwdCombine(const active& t, unsigned int secIdx, const active& timeFactor, double const* const y, double const* const yDot, 
		const std::vector<const double*>& yS, const std::vector<const double*>& ySdot, const std::vector<double*>& resS, active const* adRes, 
		double* const tmp1, double* const tmp2, double* const tmp3);

protected:

	UnitOpIdx _unitOpIdx; //!< Unit operation index
	IBindingModel* _binding; //!<  Binding model

	typedef std::unordered_map<ParameterId, active*> paramMap_t;
	paramMap_t _parameters; //!< Provides access to all parameters
	std::unordered_set<active*> _sensParams; //!< Holds all parameters with activated AD directions
};

} // namespace model
} // namespace cadet

#endif  // LIBCADET_UNITOPERATIONBASE_HPP_
