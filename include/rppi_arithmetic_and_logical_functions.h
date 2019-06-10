#ifndef RPPI_ARITHMETIC_AND_LOGICAL_FUNCTIONS_H
#define RPPI_ARITHMETIC_AND_LOGICAL_FUNCTIONS_H
#include "rppdefs.h"

#include "rppdefs.h"
#ifdef __cplusplus
extern "C" {
#endif

// --------------------
// Bitwise AND
// --------------------

// Gpu function declarations

RppStatus
rppi_bitwise_AND_u8_pln1_gpu( RppPtr_t srcPtr1, RppPtr_t srcPtr2,
                              RppiSize srcSize, RppPtr_t dstPtr,
                              RppHandle_t rppHandle );

RppStatus
rppi_bitwise_AND_u8_pln3_gpu( RppPtr_t srcPtr1, RppPtr_t srcPtr2,
                              RppiSize srcSize, RppPtr_t dstPtr,
                              RppHandle_t rppHandle );

RppStatus
rppi_bitwise_AND_u8_pkd3_gpu( RppPtr_t srcPtr1, RppPtr_t srcPtr2,
                              RppiSize srcSize, RppPtr_t dstPtr,
                              RppHandle_t rppHandle );


// --------------------
// Bitwise NOT
// --------------------

// Gpu function declarations

RppStatus
rppi_bitwise_NOT_u8_pln1_gpu( RppPtr_t srcPtr1,
                              RppiSize srcSize, RppPtr_t dstPtr,
                              RppHandle_t rppHandle );

RppStatus
rppi_bitwise_NOT_u8_pln3_gpu( RppPtr_t srcPtr1,
                              RppiSize srcSize, RppPtr_t dstPtr,
                              RppHandle_t rppHandle );

RppStatus
rppi_bitwise_NOT_u8_pkd3_gpu( RppPtr_t srcPtr1,
                              RppiSize srcSize, RppPtr_t dstPtr,
                              RppHandle_t rppHandle );

// --------------------
// Exclusive OR
// --------------------

// Gpu function declarations

RppStatus
rppi_exclusive_OR_u8_pln1_gpu( RppPtr_t srcPtr1, RppPtr_t srcPtr2,
                              RppiSize srcSize, RppPtr_t dstPtr,
                              RppHandle_t rppHandle );

RppStatus
rppi_exclusive_OR_u8_pln3_gpu( RppPtr_t srcPtr1, RppPtr_t srcPtr2,
                              RppiSize srcSize, RppPtr_t dstPtr,
                              RppHandle_t rppHandle );

RppStatus
rppi_exclusive_OR_u8_pkd3_gpu( RppPtr_t srcPtr1, RppPtr_t srcPtr2,
                              RppiSize srcSize, RppPtr_t dstPtr,
                              RppHandle_t rppHandle );

// --------------------
// Inclusive OR
// --------------------

// Gpu function declarations

RppStatus
rppi_inclusive_OR_u8_pln1_gpu( RppPtr_t srcPtr1, RppPtr_t srcPtr2,
                              RppiSize srcSize, RppPtr_t dstPtr,
                              RppHandle_t rppHandle );

RppStatus
rppi_inclusive_OR_u8_pln3_gpu( RppPtr_t srcPtr1, RppPtr_t srcPtr2,
                              RppiSize srcSize, RppPtr_t dstPtr,
                              RppHandle_t rppHandle );

RppStatus
rppi_inclusive_OR_u8_pkd3_gpu( RppPtr_t srcPtr1, RppPtr_t srcPtr2,
                              RppiSize srcSize, RppPtr_t dstPtr,
                              RppHandle_t rppHandle );


// --------------------
// Addition
// --------------------

// Gpu function declarations

RppStatus
rppi_add_u8_pln1_gpu( RppPtr_t srcPtr1, RppPtr_t srcPtr2,
                              RppiSize srcSize, RppPtr_t dstPtr,
                              RppHandle_t rppHandle );

RppStatus
rppi_add_u8_pln3_gpu( RppPtr_t srcPtr1, RppPtr_t srcPtr2,
                              RppiSize srcSize, RppPtr_t dstPtr,
                              RppHandle_t rppHandle );

RppStatus
rppi_add_u8_pkd3_gpu( RppPtr_t srcPtr1, RppPtr_t srcPtr2,
                              RppiSize srcSize, RppPtr_t dstPtr,
                              RppHandle_t rppHandle );

// --------------------
// Subtraction
// --------------------

// Gpu function declarations

RppStatus
rppi_subtract_u8_pln1_gpu( RppPtr_t srcPtr1, RppPtr_t srcPtr2,
                              RppiSize srcSize, RppPtr_t dstPtr,
                              RppHandle_t rppHandle );

RppStatus
rppi_subtract_u8_pln3_gpu( RppPtr_t srcPtr1, RppPtr_t srcPtr2,
                              RppiSize srcSize, RppPtr_t dstPtr,
                              RppHandle_t rppHandle );

RppStatus
rppi_subtract_u8_pkd3_gpu( RppPtr_t srcPtr1, RppPtr_t srcPtr2,
                              RppiSize srcSize, RppPtr_t dstPtr,
                              RppHandle_t rppHandle );
// --------------------
// Absolute difference
// --------------------

// Gpu function declarations

RppStatus
rppi_absolute_difference_u8_pln1_gpu( RppPtr_t srcPtr1, RppPtr_t srcPtr2,
                              RppiSize srcSize, RppPtr_t dstPtr,
                              RppHandle_t rppHandle );

RppStatus
rppi_absolute_difference_u8_pln3_gpu( RppPtr_t srcPtr1, RppPtr_t srcPtr2,
                              RppiSize srcSize, RppPtr_t dstPtr,
                              RppHandle_t rppHandle );

RppStatus
rppi_absolute_difference_u8_pkd3_gpu( RppPtr_t srcPtr1, RppPtr_t srcPtr2,
                              RppiSize srcSize, RppPtr_t dstPtr,
                              RppHandle_t rppHandle );


// --------------------
// Bilateral filter
// --------------------

// Gpu function declarations

RppStatus
rppi_bilateral_filter_u8_pln1_gpu(RppPtr_t srcPtr, RppiSize srcSize,
                                  RppPtr_t dstPtr, Rpp32u filterSize,
                                  Rpp64f sigmaI, Rpp64f sigmaS,
                                  RppHandle_t rppHandle);

RppStatus
rppi_bilateral_filter_u8_pkd3_gpu(RppPtr_t srcPtr, RppiSize srcSize,
                                  RppPtr_t dstPtr, Rpp32u filterSize,
                                  Rpp64f sigmaI, Rpp64f sigmaS,
                                  RppHandle_t rppHandle);

RppStatus
rppi_bilateral_filter_u8_pln3_gpu(RppPtr_t srcPtr, RppiSize srcSize,
                                  RppPtr_t dstPtr, Rpp32u filterSize,
                                  Rpp64f sigmaI, Rpp64f sigmaS,
                                  RppHandle_t rppHandle);

// --------------------
// Accumulation
// --------------------

// Gpu function declarations

RppStatus
rppi_accumulate_u8_pln1_gpu( RppPtr_t srcPtr1, RppPtr_t srcPtr2,
                              RppiSize srcSize,
                              RppHandle_t rppHandle );

RppStatus
rppi_accumulate_u8_pln3_gpu( RppPtr_t srcPtr1, RppPtr_t srcPtr2,
                              RppiSize srcSize,
                              RppHandle_t rppHandle );

RppStatus
rppi_accumulate_u8_pkd3_gpu( RppPtr_t srcPtr1, RppPtr_t srcPtr2,
                              RppiSize srcSize,
                              RppHandle_t rppHandle );

// --------------------
// Accumulate Weighted
// --------------------

//Parameters : alpha should be [0 <= alpha <=1]
RppStatus
rppi_accumulate_weighted_u8_pln1_gpu( RppPtr_t srcPtr1, RppPtr_t srcPtr2,
                              RppiSize srcSize, double alpha,
                              RppHandle_t rppHandle );

RppStatus
rppi_accumulate_weighted_u8_pln3_gpu( RppPtr_t srcPtr1, RppPtr_t srcPtr2,
                              RppiSize srcSize, double alpha,
                              RppHandle_t rppHandle );

RppStatus
rppi_accumulate_weighted_u8_pkd3_gpu( RppPtr_t srcPtr1, RppPtr_t srcPtr2,
                              RppiSize srcSize, double alpha,
                              RppHandle_t rppHandle );


#ifdef __cplusplus
}
#endif
#endif /* RPPI_ARITHMATIC_AND_LOGICAL_FUNCTIONS_H */
