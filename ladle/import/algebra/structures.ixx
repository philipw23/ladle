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

export module ladle.algebra.structures;

import <type_traits>;
import ladle.algebra.axioms;


export namespace ladle {

	template<domain D, operation<D> F>
	struct is_monoid : std::conjunction<is_associative<D, F>, has_identity<D, F>> {};
	template<domain D, operation<D> F>
	inline constexpr bool is_monoid_v = is_monoid<D, F>::value;

	template<typename D, typename F>
	concept monoid = domain<D> && operation<F, D> && is_monoid_v<D, F>;


	template<domain D, operation<D> F>
	struct is_group : std::conjunction<is_monoid<D, F>, is_invertible<D, F>> {};
	template<domain D, operation<D> F>
	inline constexpr bool is_group_v = is_group<D, F>::value;

	template<typename D, typename F>
	concept group = domain<D> && operation<F, D> && is_group_v<D, F>;


	template<domain D, operation<D> F>
	struct is_abelian_group : std::conjunction<is_group<D, F>, is_commutative<D, F>> {};
	template<domain D, operation<D> F>
	inline constexpr bool is_abelian_group_v = is_abelian_group<D, F>::value;

	template<typename D, typename F>
	concept abelian_group = domain<D> && operation<F, D> && is_abelian_group_v<D, F>;


	template<domain D>
	struct is_field : std::conjunction< is_abelian_group<D, plus<D>>, is_abelian_group<D, multiplies<D>> > {};
	template<domain D>
	inline constexpr bool is_field_v = is_field<D>::value;

	template<typename D>
	concept field = domain<D> && is_field_v<D>;

} // namespace ladle