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

export module ladle.algebra.axioms;

import <type_traits>;
import <concepts>;


export namespace ladle {

	// domain
	template<typename D>
	concept domain = std::copyable<D> && std::destructible<D> && std::equality_comparable<D>;

	// operators
	template<typename D>
	concept has_op_plus = domain<D> && requires(D a, D b) {
		{ a + b } -> std::convertible_to<D>;
	};
	template<typename D>
	concept has_op_minus = has_op_plus<D> && requires(D a, D b) {
		{ a - b } -> std::convertible_to<D>;
	};
	template<typename D>
	concept has_op_negate = has_op_plus<D> && requires(D a) {
		{ -a } -> std::convertible_to<D>;
	};
	template<typename D>
	concept has_op_multiply = domain<D> && requires(D a, D b) {
		{ a* b } -> std::convertible_to<D>;
	};
	template<typename D>
	concept has_op_divide = has_op_multiply<D> && requires(D a, D b) {
		{ a / b } -> std::convertible_to<D>;
	};

	// operations
	template<domain D>
	using plus = std::plus<D>;
	template<domain D>
	using multiplies = std::multiplies<D>;

	template<typename F, typename D>
	concept operation = (has_op_plus<D> && std::same_as<F, plus<D>>) || (has_op_multiply<D> && std::same_as<F, multiplies<D>>);


	// axioms
	template<domain D, operation<D> F>
	struct is_associative : std::false_type {};
	template<domain D, operation<D> F>
	inline constexpr bool is_associative_v = is_associative<D, F>::value;

	template<typename D, typename F>
	concept associative = domain<D> && operation<F, D> && is_associative_v<D, F>;


	template<domain D, operation<D> F>
	struct is_commutative : std::false_type {};
	template<domain D, operation<D> F>
	inline constexpr bool is_commutative_v = is_commutative<D, F>::value;

	template<typename D, typename F>
	concept commutative = domain<D> && operation <F, D> && is_commutative_v<D, F>;


	template<domain D, operation<D> F>
	struct is_invertible : std::false_type {};
	template<domain D, operation<D> F>
	inline constexpr bool is_invertible_v = is_invertible<D, F>::value;

	template<typename D, typename F>
	concept invertible = domain<D> && operation<F, D> && is_invertible_v<D, F> &&
		((std::same_as<F, plus<D>> && has_op_minus<D> && has_op_negate<D>) || (std::same_as<F, multiplies<D>> && has_op_divide<D>));


	template<domain D, operation<D> F>
	struct has_identity : std::false_type {};
	template<domain D, operation<D> F> requires invertible<D, F>
	struct has_identity<D, F> : std::true_type {};
	template<domain D, operation<D> F>
	inline constexpr bool has_identity_v = has_identity<D, F>::value;

	template<typename D, typename F>
	concept width_identity = domain<D> && operation <F, D> && has_identity_v<D, F>;

	template<domain D, operation<D> F>
	inline const constexpr D identity;


	template<domain D>
	struct is_left_distributive : std::false_type {};
	template<domain D>
	inline constexpr bool is_left_distributive_v = is_left_distributive<D>::value;

	template<typename D>
	concept left_distributive = domain<D> && is_left_distributive_v<D>;


	template<domain D>
	struct is_right_distributive : std::false_type {};
	template<domain D>
	inline constexpr bool is_right_distributive_v = is_right_distributive<D>::value;

	template<typename D>
	concept right_distributive = domain<D> && is_right_distributive_v<D>;


	template<typename D>
	concept distributive = is_left_distributive_v<D> && is_right_distributive_v<D>;

} // namespace ladle