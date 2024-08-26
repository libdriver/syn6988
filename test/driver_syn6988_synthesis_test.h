/**
 * Copyright (c) 2015 - present LibDriver All rights reserved
 * 
 * The MIT License (MIT)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE. 
 *
 * @file      driver_syn6988_synthesis_test.h
 * @brief     driver syn6988 synthesis test header file
 * @version   1.0.0
 * @author    Shifeng Li
 * @date      2024-08-30
 *
 * <h3>history</h3>
 * <table>
 * <tr><th>Date        <th>Version  <th>Author      <th>Description
 * <tr><td>2024/08/30  <td>1.0      <td>Shifeng Li  <td>first upload
 * </table>
 */

#ifndef DRIVER_SYN6988_SYNTHESIS_TEST_H
#define DRIVER_SYN6988_SYNTHESIS_TEST_H

#include "driver_syn6988_interface.h"

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @defgroup syn6988_test_driver syn6988 test driver function
 * @brief    syn6988 test driver modules
 * @ingroup  syn6988_driver
 * @{
 */

/**
 * @brief     synthesis test
 * @param[in] interface is the chip interface
 * @return    status code
 *            - 0 success
 *            - 1 test failed
 * @note      none
 */
uint8_t syn6988_synthesis_test(syn6988_interface_t interface);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif
