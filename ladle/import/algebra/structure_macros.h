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
#ifndef LADLE_STRUCTURE_MACROS_H
#define LADLE_STRUCTURE_MACROS_H


#define LADLE_ASSOCIATIVE(TYPE, OP)										\
template<>																\
struct ladle::is_associative<TYPE, OP> : std::true_type {};

#define LADLE_COMMUTATIVE(TYPE, OP)										\
template<>																\
struct ladle::is_commutative<TYPE, OP> : std::true_type {};

#define LADLE_SET_IDENTITY(TYPE, OP, IDENTITY_VALUE)					\
template<>																\
struct ladle::has_identity<TYPE, OP> : std::true_type {};				\
namespace ladle {														\
	template<>															\
	inline const constexpr TYPE identity<TYPE, ::OP> = IDENTITY_VALUE;	\
} // namespace ladle

#define LADLE_INVERTIBLE(TYPE, OP, IDENTITY_VALUE)						\
LADLE_SET_IDENTITY(TYPE, OP, IDENTITY_VALUE)							\
template<>																\
struct ladle::is_invertible<TYPE, OP> : std::true_type {};		

#define LADLE_LEFT_DISTRIBUTIVE(TYPE)									\
template<>																\
struct ladle::is_left_distributive<TYPE> : std::true_type {};

#define LADLE_RIGHT_DISTRIBUTIVE(TYPE)									\
template<>																\
struct ladle::is_right_distributive<TYPE> : std::true_type {};

#define LADLE_DISTRIBUTIVE(TYPE)										\
LADLE_LEFT_DISTRIBUTIVE(TYPE)											\
LADLE_RIGHT_DISTRIBUTIVE(TYPE)

#define LADLE_MONOID(TYPE, OP, IDENTITY_VALUE)							\
LADLE_ASSOCIATIVE(TYPE, OP)												\
LADLE_SET_IDENTITY(TYPE, OP, IDENTITY_VALUE)

#define LADLE_GROUP(TYPE, OP, IDENTITY_VALUE)							\
LADLE_ASSOCIATIVE(TYPE, OP)												\
LADLE_INVERTIBLE(TYPE, OP, IDENTITY_VALUE)

#define LADLE_ABELIAN_GROUP(TYPE, OP, IDENTITY_VALUE)					\
LADLE_GROUP(TYPE, OP, IDENTITY_VALUE)									\
LADLE_COMMUTATIVE(TYPE, OP)

#define LADLE_FIELD(TYPE, IDENTITY_PLUS, IDENTITY_MULTIPY)				\
LADLE_ABELIAN_GROUP(TYPE, ladle::plus<TYPE>, IDENTITY_PLUS)				\
LADLE_ABELIAN_GROUP(TYPE, ladle::multiplies<TYPE>, IDENTITY_MULTIPY)	\
LADLE_DISTRIBUTIVE(TYPE)

#endif // LADLE_STRUCTURE_MACROS_H