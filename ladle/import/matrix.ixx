//export module ladle.matrix;
//
//
//namespace ladle {
//	using dim_t = int;
//
//	enum class MatrixType {
//		DenseMatrix,
//		DiagoModule.ixxnalMatrix,
//		UpperTriangularMatrix,
//		LowerTriangularMatrix,
//		StrictUpperTriangularMatrix,
//		StrictLowerTriangularMatrix
//	};
//
//	enum class MatrixLayout {
//		ColumnMajor,
//		RowMajor
//	};
//
//	template<typename T, dim_t Height, dim_t Width, MatrixType MT, MatrixLayout ML> requires (Height > 0) && (Width > 0)
//	class Matrix : MatrixBase<T, Height, Width, MT, ML>
//	{
//
//	};
//
//} // namespace ladle