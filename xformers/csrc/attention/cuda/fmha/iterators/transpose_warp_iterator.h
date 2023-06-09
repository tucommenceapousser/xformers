#pragma once

#include "warp_iterator_from_smem.h"

template <typename WarpIterator>
struct TransposeWarpIterator {
  using Iterator = char;
  static bool constexpr kSupportsTranspose = false;
};

template <
    /// Operand identity
    cutlass::gemm::Operand Operand,
    /// Data type of A elements
    typename Element,
    typename InstructionShape,
    bool kTranspose>
struct TransposeWarpIterator<
    cutlass::gemm::warp::
        WarpIteratorFromSmem<Operand, Element, InstructionShape, kTranspose>> {
  using Iterator = cutlass::gemm::warp::
      WarpIteratorFromSmem<Operand, Element, InstructionShape, !kTranspose>;
  static bool constexpr kSupportsTranspose = true;
};
