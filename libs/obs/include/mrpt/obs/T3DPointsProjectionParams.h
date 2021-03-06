/* +------------------------------------------------------------------------+
   |                     Mobile Robot Programming Toolkit (MRPT)            |
   |                          https://www.mrpt.org/                         |
   |                                                                        |
   | Copyright (c) 2005-2019, Individual contributors, see AUTHORS file     |
   | See: https://www.mrpt.org/Authors - All rights reserved.               |
   | Released under BSD License. See: https://www.mrpt.org/License          |
   +------------------------------------------------------------------------+ */
#pragma once

#include <mrpt/poses/CPose3D.h>
#include <cstdint>

namespace mrpt::obs
{
/** Used in CObservation3DRangeScan::unprojectInto()
 * \ingroup mrpt_obs_grp
 */
struct T3DPointsProjectionParams
{
	/** (Default: false) If false, local (sensor-centric) coordinates of points
	 * are generated. Otherwise, points are transformed with \a sensorPose.
	 * Furthermore, if provided, those coordinates are transformed with \a
	 * robotPoseInTheWorld */
	bool takeIntoAccountSensorPoseOnRobot{false};
	/** (Default: nullptr) Read takeIntoAccountSensorPoseOnRobot */
	const mrpt::poses::CPose3D* robotPoseInTheWorld{nullptr};

	/** (Default:true) If possible, use SSE2 optimized code. */
	bool USE_SSE2{true};
	/** (Default:false) set to true if you want an organized point cloud */
	bool MAKE_ORGANIZED{false};

	/** (Default:1) If !=1, split the range image in blocks of DxD
	 * (D=decimation), and only generates one point per block, with the minimum
	 * valid range. */
	uint8_t decimation{1};

	T3DPointsProjectionParams() = default;
};

}  // namespace mrpt::obs