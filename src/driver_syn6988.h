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
 * @file      driver_syn6988.h
 * @brief     driver syn6988 header file
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

#ifndef DRIVER_SYN6988_H
#define DRIVER_SYN6988_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @defgroup syn6988_driver syn6988 driver function
 * @brief    syn6988 driver modules
 * @{
 */

/**
 * @addtogroup syn6988_base_driver
 * @{
 */

/**
 * @brief syn6988 timeout definition
 */
#ifndef SYN6988_BUSY_TIMEOUT
    #define SYN6988_BUSY_TIMEOUT        1000        /**< 1000ms */
#endif

/**
 * @brief syn6988 sound enumeration definition
 */
#define SYN6988_SOUND_101        "sound101"        /**< sound101 */
#define SYN6988_SOUND_102        "sound102"        /**< sound102 */
#define SYN6988_SOUND_103        "sound103"        /**< sound103 */
#define SYN6988_SOUND_104        "sound104"        /**< sound104 */
#define SYN6988_SOUND_105        "sound105"        /**< sound105 */
#define SYN6988_SOUND_106        "sound106"        /**< sound106 */
#define SYN6988_SOUND_107        "sound107"        /**< sound107 */
#define SYN6988_SOUND_108        "sound108"        /**< sound108 */
#define SYN6988_SOUND_109        "sound109"        /**< sound109 */
#define SYN6988_SOUND_110        "sound110"        /**< sound110 */
#define SYN6988_SOUND_111        "sound111"        /**< sound111 */
#define SYN6988_SOUND_112        "sound112"        /**< sound112 */
#define SYN6988_SOUND_113        "sound113"        /**< sound113 */
#define SYN6988_SOUND_114        "sound114"        /**< sound114 */
#define SYN6988_SOUND_115        "sound115"        /**< sound115 */
#define SYN6988_SOUND_116        "sound116"        /**< sound116 */
#define SYN6988_SOUND_117        "sound117"        /**< sound117 */
#define SYN6988_SOUND_118        "sound118"        /**< sound118 */
#define SYN6988_SOUND_119        "sound119"        /**< sound119 */
#define SYN6988_SOUND_120        "sound120"        /**< sound120 */
#define SYN6988_SOUND_121        "sound121"        /**< sound121 */
#define SYN6988_SOUND_122        "sound122"        /**< sound122 */
#define SYN6988_SOUND_123        "sound123"        /**< sound123 */
#define SYN6988_SOUND_124        "sound124"        /**< sound124 */
#define SYN6988_SOUND_201        "sound201"        /**< sound201 */
#define SYN6988_SOUND_202        "sound202"        /**< sound202 */
#define SYN6988_SOUND_203        "sound203"        /**< sound203 */
#define SYN6988_SOUND_204        "sound204"        /**< sound204 */
#define SYN6988_SOUND_205        "sound205"        /**< sound205 */
#define SYN6988_SOUND_206        "sound206"        /**< sound206 */
#define SYN6988_SOUND_207        "sound207"        /**< sound207 */
#define SYN6988_SOUND_208        "sound208"        /**< sound208 */
#define SYN6988_SOUND_209        "sound209"        /**< sound209 */
#define SYN6988_SOUND_301        "sound301"        /**< sound301 */
#define SYN6988_SOUND_302        "sound302"        /**< sound302 */
#define SYN6988_SOUND_303        "sound303"        /**< sound303 */
#define SYN6988_SOUND_304        "sound304"        /**< sound304 */
#define SYN6988_SOUND_305        "sound305"        /**< sound305 */
#define SYN6988_SOUND_306        "sound306"        /**< sound306 */
#define SYN6988_SOUND_307        "sound307"        /**< sound307 */
#define SYN6988_SOUND_308        "sound308"        /**< sound308 */
#define SYN6988_SOUND_309        "sound309"        /**< sound309 */
#define SYN6988_SOUND_310        "sound310"        /**< sound310 */
#define SYN6988_SOUND_311        "sound311"        /**< sound311 */
#define SYN6988_SOUND_312        "sound312"        /**< sound312 */
#define SYN6988_SOUND_313        "sound313"        /**< sound313 */
#define SYN6988_SOUND_314        "sound314"        /**< sound314 */
#define SYN6988_SOUND_315        "sound315"        /**< sound315 */
#define SYN6988_SOUND_316        "sound316"        /**< sound316 */
#define SYN6988_SOUND_317        "sound317"        /**< sound317 */
#define SYN6988_SOUND_318        "sound318"        /**< sound318 */
#define SYN6988_SOUND_401        "sound401"        /**< sound401 */
#define SYN6988_SOUND_402        "sound402"        /**< sound402 */
#define SYN6988_SOUND_403        "sound403"        /**< sound403 */
#define SYN6988_SOUND_404        "sound404"        /**< sound404 */
#define SYN6988_SOUND_405        "sound405"        /**< sound405 */
#define SYN6988_SOUND_406        "sound406"        /**< sound406 */
#define SYN6988_SOUND_407        "sound407"        /**< sound407 */
#define SYN6988_SOUND_408        "sound408"        /**< sound408 */

/**
 * @brief syn6988 interface enumeration definition
 */
typedef enum
{
    SYN6988_INTERFACE_UART = 0x00,        /**< uart interface function */
    SYN6988_INTERFACE_SPI  = 0x01,        /**< spi interface function */
} syn6988_interface_t;

/**
 * @brief syn6988 type enumeration definition
 */
typedef enum
{
    SYN6988_TYPE_GB2312         = 0x00,         /**< gb2312 type */
    SYN6988_TYPE_GBK            = 0x01,         /**< gbk type */
    SYN6988_TYPE_BIG5           = 0x02,         /**< big5 type */
    SYN6988_TYPE_UNICODE_LITTLE = 0x03,         /**< unicode little endian type */
    SYN6988_TYPE_UNICODE_BIG    = 0x04,         /**< unicode big endian type */
} syn6988_type_t;

/**
 * @brief syn6988 status enumeration definition
 */
typedef enum
{
    SYN6988_STATUS_OK   = 0x00,         /**< ok status */
    SYN6988_STATUS_BUSY = 0x01,         /**< busy status */
} syn6988_status_t;

/**
 * @brief syn6988 language enumeration definition
 */
typedef enum
{
    SYN6988_LANGUAGE_AUTO    = 0,        /**< auto */
    SYN6988_LANGUAGE_CHINESE = 1,        /**< chinese */
    SYN6988_LANGUAGE_ENGLISH = 2,        /**< english */
} syn6988_language_t;

/**
 * @brief syn6988 handle structure definition
 */
typedef struct syn6988_handle_s
{
    uint8_t (*gpio_ready_init)(void);                                       /**< point to a gpio_ready_init function address */
    uint8_t (*gpio_ready_deinit)(void);                                     /**< point to a gpio_ready_deinit function address */
    uint8_t (*gpio_ready_read)(uint8_t *value);                             /**< point to a gpio_ready_read function address */
    uint8_t (*uart_init)(void);                                             /**< point to a uart_init function address */
    uint8_t (*uart_deinit)(void);                                           /**< point to a uart_deinit function address */
    uint16_t (*uart_read)(uint8_t *buf, uint16_t len);                      /**< point to a uart_read function address */
    uint8_t (*uart_flush)(void);                                            /**< point to a uart_flush function address */
    uint8_t (*uart_write)(uint8_t *buf, uint16_t len);                      /**< point to a uart_write function address */
    uint8_t (*spi_init)(void);                                              /**< point to an spi_init function address */
    uint8_t (*spi_deinit)(void);                                            /**< point to an spi_deinit function address */
    uint8_t (*spi_transmit)(uint8_t *tx, uint8_t *rx, uint16_t len);        /**< point to an spi_transmit function address */
    void (*delay_ms)(uint32_t ms);                                          /**< point to a delay_ms function address */
    void (*debug_print)(const char *const fmt, ...);                        /**< point to a debug_print function address */
    uint8_t inited;                                                         /**< inited flag */
    uint8_t uart_spi;                                                       /**< uart_spi flag */
    uint8_t type;                                                           /**< type */
    uint8_t buf[4096];                                                      /**< frame buf */
} syn6988_handle_t;

/**
 * @brief syn6988 information structure definition
 */
typedef struct syn6988_info_s
{
    char chip_name[32];                /**< chip name */
    char manufacturer_name[32];        /**< manufacturer name */
    char interface[16];                /**< chip interface name */
    float supply_voltage_min_v;        /**< chip min supply voltage */
    float supply_voltage_max_v;        /**< chip max supply voltage */
    float max_current_ma;              /**< chip max current */
    float temperature_min;             /**< chip min operating temperature */
    float temperature_max;             /**< chip max operating temperature */
    uint32_t driver_version;           /**< driver version */
} syn6988_info_t;

/**
 * @}
 */

/**
 * @defgroup syn6988_link_driver syn6988 link driver function
 * @brief    syn6988 link driver modules
 * @ingroup  syn6988_driver
 * @{
 */

/**
 * @brief     initialize syn6988_handle_t structure
 * @param[in] HANDLE points to a syn6988 handle structure
 * @param[in] STRUCTURE is syn6988_handle_t
 * @note      none
 */
#define DRIVER_SYN6988_LINK_INIT(HANDLE, STRUCTURE)               memset(HANDLE, 0, sizeof(STRUCTURE))

/**
 * @brief     link uart_init function
 * @param[in] HANDLE points to a syn6988 handle structure
 * @param[in] FUC points to a uart_init function address
 * @note      none
 */
#define DRIVER_SYN6988_LINK_UART_INIT(HANDLE, FUC)               (HANDLE)->uart_init = FUC

/**
 * @brief     link uart_deinit function
 * @param[in] HANDLE points to a syn6988 handle structure
 * @param[in] FUC points to a uart_deinit function address
 * @note      none
 */
#define DRIVER_SYN6988_LINK_UART_DEINIT(HANDLE, FUC)             (HANDLE)->uart_deinit = FUC

/**
 * @brief     link uart_read function
 * @param[in] HANDLE points to a syn6988 handle structure
 * @param[in] FUC points to a uart_read function address
 * @note      none
 */
#define DRIVER_SYN6988_LINK_UART_READ(HANDLE, FUC)               (HANDLE)->uart_read = FUC

/**
 * @brief     link uart_write function
 * @param[in] HANDLE points to a syn6988 handle structure
 * @param[in] FUC points to a uart_write function address
 * @note      none
 */
#define DRIVER_SYN6988_LINK_UART_WRITE(HANDLE, FUC)              (HANDLE)->uart_write = FUC

/**
 * @brief     link uart_flush function
 * @param[in] HANDLE points to a syn6988 handle structure
 * @param[in] FUC points to a uart_flush function address
 * @note      none
 */
#define DRIVER_SYN6988_LINK_UART_FLUSH(HANDLE, FUC)              (HANDLE)->uart_flush = FUC

/**
 * @brief     link spi_init function
 * @param[in] HANDLE points to a syn6988 handle structure
 * @param[in] FUC points to a spi_init function address
 * @note      none
 */
#define DRIVER_SYN6988_LINK_SPI_INIT(HANDLE, FUC)                (HANDLE)->spi_init = FUC

/**
 * @brief     link spi_deinit function
 * @param[in] HANDLE points to a syn6988 handle structure
 * @param[in] FUC points to a spi_deinit function address
 * @note      none
 */
#define DRIVER_SYN6988_LINK_SPI_DEINIT(HANDLE, FUC)              (HANDLE)->spi_deinit = FUC

/**
 * @brief     link spi_transmit function
 * @param[in] HANDLE points to a syn6988 handle structure
 * @param[in] FUC points to a spi_transmit function address
 * @note      none
 */
#define DRIVER_SYN6988_LINK_SPI_TRANSMIT(HANDLE, FUC)            (HANDLE)->spi_transmit = FUC

/**
 * @brief     link gpio_ready_init function
 * @param[in] HANDLE points to a syn6988 handle structure
 * @param[in] FUC points to a gpio_ready_init function address
 * @note      none
 */
#define DRIVER_SYN6988_LINK_GPIO_READY_INIT(HANDLE, FUC)         (HANDLE)->gpio_ready_init = FUC

/**
 * @brief     link gpio_ready_deinit function
 * @param[in] HANDLE points to a syn6988 handle structure
 * @param[in] FUC points to a gpio_ready_deinit function address
 * @note      none
 */
#define DRIVER_SYN6988_LINK_GPIO_READY_DEINIT(HANDLE, FUC)       (HANDLE)->gpio_ready_deinit = FUC

/**
 * @brief     link gpio_ready_read function
 * @param[in] HANDLE points to a syn6988 handle structure
 * @param[in] FUC points to a gpio_ready_read function address
 * @note      none
 */
#define DRIVER_SYN6988_LINK_GPIO_READY_READ(HANDLE, FUC)         (HANDLE)->gpio_ready_read = FUC

/**
 * @brief     link delay_ms function
 * @param[in] HANDLE points to a syn6988 handle structure
 * @param[in] FUC points to a delay_ms function address
 * @note      none
 */
#define DRIVER_SYN6988_LINK_DELAY_MS(HANDLE, FUC)                (HANDLE)->delay_ms = FUC

/**
 * @brief     link debug_print function
 * @param[in] HANDLE points to a syn6988 handle structure
 * @param[in] FUC points to a debug_print function address
 * @note      none
 */
#define DRIVER_SYN6988_LINK_DEBUG_PRINT(HANDLE, FUC)             (HANDLE)->debug_print = FUC

/**
 * @}
 */

/**
 * @defgroup syn6988_base_driver syn6988 base driver function
 * @brief    syn6988 base driver modules
 * @ingroup  syn6988_driver
 * @{
 */

/**
 * @brief      get chip's information
 * @param[out] *info points to a syn6988 info structure
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 * @note       none
 */
uint8_t syn6988_info(syn6988_info_t *info);

/**
 * @brief     set the chip interface
 * @param[in] *handle points to a syn6988 handle structure
 * @param[in] interface is the chip interface
 * @return    status code
 *            - 0 success
 *            - 2 handle is NULL
 * @note      none
 */
uint8_t syn6988_set_interface(syn6988_handle_t *handle, syn6988_interface_t interface);

/**
 * @brief      get the chip interface
 * @param[in]  *handle points to a syn6988 handle structure
 * @param[out] *interface points to a chip interface buffer
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 * @note       none
 */
uint8_t syn6988_get_interface(syn6988_handle_t *handle, syn6988_interface_t *interface);

/**
 * @brief     initialize the chip
 * @param[in] *handle points to a syn6988 handle structure
 * @return    status code
 *            - 0 success
 *            - 1 uart or spi initialization failed
 *            - 2 handle is NULL
 *            - 3 linked functions is NULL
 *            - 4 gpio ready init failed
 * @note      none
 */
uint8_t syn6988_init(syn6988_handle_t *handle);

/**
 * @brief     close the chip
 * @param[in] *handle points to a syn6988 handle structure
 * @return    status code
 *            - 0 success
 *            - 1 uart or spi deinit failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 gpio ready deinit failed
 * @note      none
 */
uint8_t syn6988_deinit(syn6988_handle_t *handle);

/**
 * @brief     set the chip text type
 * @param[in] *handle points to a syn6988 handle structure
 * @param[in] type is the chip text type
 * @return    status code
 *            - 0 success
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t syn6988_set_text_type(syn6988_handle_t *handle, syn6988_type_t type);

/**
 * @brief      get the chip text type
 * @param[in]  *handle points to a syn6988 handle structure
 * @param[out] *type points to a chip text type
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t syn6988_get_text_type(syn6988_handle_t *handle, syn6988_type_t *type);

/**
 * @brief     synthesis the test
 * @param[in] *handle points to a syn6988 handle structure
 * @param[in] fmt is the format data
 * @return    status code
 *            - 0 success
 *            - 1 synthesis text failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 chip is busy
 *            - 5 uart read failed
 * @note      none
 */
uint8_t syn6988_synthesis_text(syn6988_handle_t *handle, const char *const fmt, ...);

/**
 * @brief      get the current status
 * @param[in]  *handle points to a syn6988 handle structure
 * @param[out] *status points to a status buffer
 * @return     status code
 *             - 0 success
 *             - 1 get status failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t syn6988_get_status(syn6988_handle_t *handle, syn6988_status_t *status);

/**
 * @brief     stop the chip
 * @param[in] *handle points to a syn6988 handle structure
 * @return    status code
 *            - 0 success
 *            - 1 stop failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 spi interface can't use this function
 * @note      none
 */
uint8_t syn6988_stop(syn6988_handle_t *handle);

/**
 * @brief     pause the chip
 * @param[in] *handle points to a syn6988 handle structure
 * @return    status code
 *            - 0 success
 *            - 1 pause failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 spi interface can't use this function
 * @note      none
 */
uint8_t syn6988_pause(syn6988_handle_t *handle);

/**
 * @brief     resume the chip
 * @param[in] *handle points to a syn6988 handle structure
 * @return    status code
 *            - 0 success
 *            - 1 resume failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 spi interface can't use this function
 * @note      none
 */
uint8_t syn6988_resume(syn6988_handle_t *handle);

/**
 * @brief     set the chip to standby mode
 * @param[in] *handle points to a syn6988 handle structure
 * @return    status code
 *            - 0 success
 *            - 1 standby failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 spi interface can't use this function
 * @note      none
 */
uint8_t syn6988_standby(syn6988_handle_t *handle);

/**
 * @brief     wake up the chip
 * @param[in] *handle points to a syn6988 handle structure
 * @return    status code
 *            - 0 success
 *            - 1 wake up failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 spi interface can't use this function
 * @note      none
 */
uint8_t syn6988_wake_up(syn6988_handle_t *handle);

/**
 * @brief     set the chip synthesis volume
 * @param[in] *handle points to a syn6988 handle structure
 * @param[in] volume is the synthesis volume
 * @return    status code
 *            - 0 success
 *            - 1 set synthesis volume failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 volume is invalid
 * @note      0 <= volume <= 10
 */
uint8_t syn6988_set_synthesis_volume(syn6988_handle_t *handle, uint8_t volume);

/**
 * @brief     set the synthesis speed
 * @param[in] *handle points to a syn6988 handle structure
 * @param[in] speed is the synthesis speed
 * @return    status code
 *            - 0 success
 *            - 1 set synthesis speed failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 speed is invalid
 * @note      0 <= speed <= 10
 */
uint8_t syn6988_set_synthesis_speed(syn6988_handle_t *handle, uint8_t speed);

/**
 * @brief     set synthesis language
 * @param[in] *handle points to a syn6988 handle structure
 * @param[in] language is the set synthesis language
 * @return    status code
 *            - 0 success
 *            - 1 set synthesis language failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t syn6988_set_synthesis_language(syn6988_handle_t *handle, syn6988_language_t language);

/**
 * @}
 */

/**
 * @defgroup syn6988_extend_driver syn6988 extend driver function
 * @brief    syn6988 extend driver modules
 * @ingroup  syn6988_driver
 * @{
 */

/**
 * @brief     send the command to the chip
 * @param[in] *handle points to a syn6988 handle structure
 * @param[in] command is the set command
 * @param[in] timeout is the timeout in ms
 * @return    status code
 *            - 0 success
 *            - 1 write failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 chip is busy
 *            - 5 uart read failed
 * @note      none
 */
uint8_t syn6988_set_command(syn6988_handle_t *handle, uint8_t command, uint32_t timeout);

/**
 * @brief     send the command with arg to the chip
 * @param[in] *handle points to a syn6988 handle structure
 * @param[in] command is the set command
 * @param[in] param is the set param
 * @param[in] *txt points to a txt buffer
 * @param[in] timeout is the timeout in ms
 * @return    status code
 *            - 0 success
 *            - 1 write failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 txt is too long
 *            - 5 chip is busy
 *            - 6 uart read failed
 * @note      none
 */
uint8_t syn6988_set_command_with_arg(syn6988_handle_t *handle, uint8_t command, uint8_t param, char *txt, uint32_t timeout);

/**
 * @}
 */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif
