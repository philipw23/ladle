// =======================================================================
// Ladle Library
// -----------------------------------------------------------------------
// Copyright 2021 Philip Weyer
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http ://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissionsand
// limitations under the License.
// =======================================================================

module;

#include "structure_macros.h"

export module ladle.algebra.real;

import "config.h";
import ladle.algebra.axioms;
import ladle.algebra.structures;


export {
	LADLE_FIELD(float, 0.0f, 1.0f)
}

export namespace ladle {

	using real = default_fp_t;

} // namespace ladle