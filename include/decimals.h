//
// Created by timob on 31.01.2025.
//

#ifndef bardow_DECIMALS_H
#define bardow_DECIMALS_H

#ifdef bardow_DISABLE_DECIMALS
typedef float decimal32 ;
typedef double decimal64 ;
typedef long double decimal128;
#else

#ifndef __STDC_IEC_60559_DFP__
#define __STDC_IEC_60559_DFP__
#endif

typedef _Decimal32 decimal32;
typedef _Decimal64 decimal64;
typedef _Decimal128 decimal128;

#endif //bardow_DISABLE_DECIMALS
#endif //bardow_DECIMALS_H
