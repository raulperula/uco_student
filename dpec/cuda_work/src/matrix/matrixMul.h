#ifndef _MATRIXMUL_H_
#define _MATRIXMUL_H_

/**
 * @file    matrixMul.h
 * @brief   Header file.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license  GPL v3
 * @version 1.0.0
 */

// Thread block size
#define BLOCK_SIZE 16

// Basic Matrix dimensions (can be amplified by command line switch)
// (chosen as multiples of the thread block size for simplicity)
#define WA (5  * BLOCK_SIZE) // Matrix A width
#define HA (10 * BLOCK_SIZE) // Matrix A height
#define WB (5  * BLOCK_SIZE) // Matrix B width
#define HB WA  // Matrix B height
#define WC WB  // Matrix C width 
#define HC HA  // Matrix C height

#endif // _MATRIXMUL_H_
