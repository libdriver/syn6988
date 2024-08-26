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
 * @file      driver_syn6988_synthesis_test.c
 * @brief     driver syn6988 synthesis test source file
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

#include "driver_syn6988_synthesis_test.h"

static syn6988_handle_t gs_handle;        /**< syn6988 handle */

/**
 * @brief     synthesis test
 * @param[in] interface is the chip interface
 * @return    status code
 *            - 0 success
 *            - 1 test failed
 * @note      none
 */
uint8_t syn6988_synthesis_test(syn6988_interface_t interface)
{
    uint8_t res;
    syn6988_info_t info;
    syn6988_status_t status;
    char s[32];
    uint8_t gb2312_text[] = {0xD3, 0xEE, 0xD2, 0xF4, 0xCC, 0xEC, 0xCF, 0xC2, 0x00};
    uint8_t gbk_text[] = {0xD3, 0xEE, 0xD2, 0xF4, 0xCC, 0xEC, 0xCF, 0xC2, 0x00};
    uint8_t big5_text[] = {0xA6, 0x74, 0xAD, 0xB5, 0xA4, 0xD1, 0xA4, 0x55, 0x00};
    uint8_t unicode_little_text[] = {0x87, 0x5B, 0xF3, 0x97, 0x29, 0x59, 0x0B, 0x4E, 0x00};
    uint8_t unicode_big_text[] = {0x5B, 0x87, 0x97, 0xF3, 0x59, 0x29, 0x4E, 0x0B, 0x00};
    char english_text[] = "welcome to use LibDriver.\n";
    
    /* link interface function */
    DRIVER_SYN6988_LINK_INIT(&gs_handle, syn6988_handle_t);
    DRIVER_SYN6988_LINK_UART_INIT(&gs_handle, syn6988_interface_uart_init);
    DRIVER_SYN6988_LINK_UART_DEINIT(&gs_handle, syn6988_interface_uart_deinit);
    DRIVER_SYN6988_LINK_UART_READ(&gs_handle, syn6988_interface_uart_read);
    DRIVER_SYN6988_LINK_UART_WRITE(&gs_handle, syn6988_interface_uart_write);
    DRIVER_SYN6988_LINK_UART_FLUSH(&gs_handle, syn6988_interface_uart_flush);
    DRIVER_SYN6988_LINK_SPI_INIT(&gs_handle, syn6988_interface_spi_init);
    DRIVER_SYN6988_LINK_SPI_DEINIT(&gs_handle, syn6988_interface_spi_deinit);
    DRIVER_SYN6988_LINK_SPI_TRANSMIT(&gs_handle, syn6988_interface_spi_transmit);
    DRIVER_SYN6988_LINK_GPIO_READY_INIT(&gs_handle, syn6988_interface_gpio_ready_init);
    DRIVER_SYN6988_LINK_GPIO_READY_DEINIT(&gs_handle, syn6988_interface_gpio_ready_deinit);
    DRIVER_SYN6988_LINK_GPIO_READY_READ(&gs_handle, syn6988_interface_gpio_ready_read);
    DRIVER_SYN6988_LINK_DELAY_MS(&gs_handle, syn6988_interface_delay_ms);
    DRIVER_SYN6988_LINK_DEBUG_PRINT(&gs_handle, syn6988_interface_debug_print);
    
    /* get syn6988 information */
    res = syn6988_info(&info);
    if (res != 0)
    {
        syn6988_interface_debug_print("syn6988: get info failed.\n");
       
        return 1;
    }
    else
    {
        /* print chip information */
        syn6988_interface_debug_print("syn6988: chip is %s.\n", info.chip_name);
        syn6988_interface_debug_print("syn6988: manufacturer is %s.\n", info.manufacturer_name);
        syn6988_interface_debug_print("syn6988: interface is %s.\n", info.interface);
        syn6988_interface_debug_print("syn6988: driver version is %d.%d.\n", info.driver_version / 1000, (info.driver_version % 1000) / 100);
        syn6988_interface_debug_print("syn6988: min supply voltage is %0.1fV.\n", info.supply_voltage_min_v);
        syn6988_interface_debug_print("syn6988: max supply voltage is %0.1fV.\n", info.supply_voltage_max_v);
        syn6988_interface_debug_print("syn6988: max current is %0.2fmA.\n", info.max_current_ma);
        syn6988_interface_debug_print("syn6988: max temperature is %0.1fC.\n", info.temperature_max);
        syn6988_interface_debug_print("syn6988: min temperature is %0.1fC.\n", info.temperature_min);
    }
    
    /* set interface */
    res = syn6988_set_interface(&gs_handle, interface);
    if (res != 0)
    {
        syn6988_interface_debug_print("syn6988: set interface failed.\n");
       
        return 1;
    }
    
    /* syn6988 init */
    res = syn6988_init(&gs_handle);
    if (res != 0)
    {
        syn6988_interface_debug_print("syn6988: init failed.\n");
       
        return 1;
    }
    
    /* set synthesis language auto */
    res = syn6988_set_synthesis_language(&gs_handle, SYN6988_LANGUAGE_AUTO);
    if (res != 0)
    {
        syn6988_interface_debug_print("syn6988: set synthesis language failed.\n");
        (void)syn6988_deinit(&gs_handle);
        
        return 1;
    }
    
    /* synthesis text test */
    syn6988_interface_debug_print("syn6988: synthesis text test.\n");
    
    /* gb2312 synthesis text */
    syn6988_interface_debug_print("syn6988: gb2312 synthesis text.\n");
    
    /* set text type gb2312 */
    res = syn6988_set_text_type(&gs_handle, SYN6988_TYPE_GB2312);
    if (res != 0)
    {
        syn6988_interface_debug_print("syn6988: set text type failed.\n");
        (void)syn6988_deinit(&gs_handle);
        
        return 1;
    }
    
    /* synthesis text */
    res = syn6988_synthesis_text(&gs_handle, (char const *)gb2312_text);
    if (res != 0)
    {
        syn6988_interface_debug_print("syn6988: synthesis text failed.\n");
        (void)syn6988_deinit(&gs_handle);
        
        return 1;
    }
    
    /* wait for finished */
    status = SYN6988_STATUS_BUSY;
    while (status == SYN6988_STATUS_BUSY)
    {
        syn6988_interface_delay_ms(500);
        res = syn6988_get_status(&gs_handle, &status);
        if (res != 0)
        {
            syn6988_interface_debug_print("syn6988: get status failed.\n");
            (void)syn6988_deinit(&gs_handle);
            
            return 1;
        }
    }
    
    /* gbk synthesis text */
    syn6988_interface_debug_print("syn6988: gbk synthesis text.\n");
    
    /* set text type gbk */
    res = syn6988_set_text_type(&gs_handle, SYN6988_TYPE_GBK);
    if (res != 0)
    {
        syn6988_interface_debug_print("syn6988: set text type failed.\n");
        (void)syn6988_deinit(&gs_handle);
        
        return 1;
    }
    
    /* synthesis text */
    res = syn6988_synthesis_text(&gs_handle, (char const *)gbk_text);
    if (res != 0)
    {
        syn6988_interface_debug_print("syn6988: synthesis text failed.\n");
        (void)syn6988_deinit(&gs_handle);
        
        return 1;
    }
    
    /* wait for finished */
    status = SYN6988_STATUS_BUSY;
    while (status == SYN6988_STATUS_BUSY)
    {
        syn6988_interface_delay_ms(500);
        res = syn6988_get_status(&gs_handle, &status);
        if (res != 0)
        {
            syn6988_interface_debug_print("syn6988: get status failed.\n");
            (void)syn6988_deinit(&gs_handle);
            
            return 1;
        }
    }
    
    /* big5 synthesis text */
    syn6988_interface_debug_print("syn6988: big5 synthesis text.\n");
    
    /* set text type big5 */
    res = syn6988_set_text_type(&gs_handle, SYN6988_TYPE_BIG5);
    if (res != 0)
    {
        syn6988_interface_debug_print("syn6988: set text type failed.\n");
        (void)syn6988_deinit(&gs_handle);
        
        return 1;
    }
    
    /* synthesis text */
    res = syn6988_synthesis_text(&gs_handle, (char const *)big5_text);
    if (res != 0)
    {
        syn6988_interface_debug_print("syn6988: synthesis text failed.\n");
        (void)syn6988_deinit(&gs_handle);
        
        return 1;
    }
    
    /* wait for finished */
    status = SYN6988_STATUS_BUSY;
    while (status == SYN6988_STATUS_BUSY)
    {
        syn6988_interface_delay_ms(500);
        res = syn6988_get_status(&gs_handle, &status);
        if (res != 0)
        {
            syn6988_interface_debug_print("syn6988: get status failed.\n");
            (void)syn6988_deinit(&gs_handle);
            
            return 1;
        }
    }
    
    /* unicode little endian synthesis text */
    syn6988_interface_debug_print("syn6988: unicode little endian synthesis text.\n");
    
    /* set text type unicode little endian */
    res = syn6988_set_text_type(&gs_handle, SYN6988_TYPE_UNICODE_LITTLE);
    if (res != 0)
    {
        syn6988_interface_debug_print("syn6988: set text type failed.\n");
        (void)syn6988_deinit(&gs_handle);
        
        return 1;
    }
    
    /* synthesis text */
    res = syn6988_synthesis_text(&gs_handle, (char const *)unicode_little_text);
    if (res != 0)
    {
        syn6988_interface_debug_print("syn6988: synthesis text failed.\n");
        (void)syn6988_deinit(&gs_handle);
        
        return 1;
    }
    
    /* wait for finished */
    status = SYN6988_STATUS_BUSY;
    while (status == SYN6988_STATUS_BUSY)
    {
        syn6988_interface_delay_ms(500);
        res = syn6988_get_status(&gs_handle, &status);
        if (res != 0)
        {
            syn6988_interface_debug_print("syn6988: get status failed.\n");
            (void)syn6988_deinit(&gs_handle);
            
            return 1;
        }
    }
    
    /* unicode big endian synthesis text */
    syn6988_interface_debug_print("syn6988: unicode big endian synthesis text.\n");
    
    /* set text type unicode big endian */
    res = syn6988_set_text_type(&gs_handle, SYN6988_TYPE_UNICODE_BIG);
    if (res != 0)
    {
        syn6988_interface_debug_print("syn6988: set text type failed.\n");
        (void)syn6988_deinit(&gs_handle);
        
        return 1;
    }
    
    /* synthesis text */
    res = syn6988_synthesis_text(&gs_handle, (char const *)unicode_big_text);
    if (res != 0)
    {
        syn6988_interface_debug_print("syn6988: synthesis text failed.\n");
        (void)syn6988_deinit(&gs_handle);
        
        return 1;
    }
    
    /* wait for finished */
    status = SYN6988_STATUS_BUSY;
    while (status == SYN6988_STATUS_BUSY)
    {
        syn6988_interface_delay_ms(500);
        res = syn6988_get_status(&gs_handle, &status);
        if (res != 0)
        {
            syn6988_interface_debug_print("syn6988: get status failed.\n");
            (void)syn6988_deinit(&gs_handle);
            
            return 1;
        }
    }
    
    /* sound synthesis text */
    syn6988_interface_debug_print("syn6988: sound synthesis text.\n");
    
    /* set text type gb2312 */
    res = syn6988_set_text_type(&gs_handle, SYN6988_TYPE_GB2312);
    if (res != 0)
    {
        syn6988_interface_debug_print("syn6988: set text type failed.\n");
        (void)syn6988_deinit(&gs_handle);
        
        return 1;
    }
    
    /* sound text */
    res = syn6988_synthesis_text(&gs_handle, (char const *)SYN6988_SOUND_202);
    if (res != 0)
    {
        syn6988_interface_debug_print("syn6988: synthesis text failed.\n");
        (void)syn6988_deinit(&gs_handle);
        
        return 1;
    }
    
    /* wait for finished */
    status = SYN6988_STATUS_BUSY;
    while (status == SYN6988_STATUS_BUSY)
    {
        syn6988_interface_delay_ms(500);
        res = syn6988_get_status(&gs_handle, &status);
        if (res != 0)
        {
            syn6988_interface_debug_print("syn6988: get status failed.\n");
            (void)syn6988_deinit(&gs_handle);
            
            return 1;
        }
    }
    
    if (interface == SYN6988_INTERFACE_UART)
    {
        /* synthesis control test */
        syn6988_interface_debug_print("syn6988: synthesis control test.\n");
        res = syn6988_synthesis_text(&gs_handle, (char *)gb2312_text);
        if (res != 0)
        {
            syn6988_interface_debug_print("syn6988: synthesis text failed.\n");
            (void)syn6988_deinit(&gs_handle);
            
            return 1;
        }
        syn6988_interface_delay_ms(500);
        res = syn6988_pause(&gs_handle);
        if (res != 0)
        {
            syn6988_interface_debug_print("syn6988: pause failed.\n");
            (void)syn6988_deinit(&gs_handle);
            
            return 1;
        }
        syn6988_interface_debug_print("syn6988: synthesis control pause.\n");
        syn6988_interface_delay_ms(5000);
        res = syn6988_resume(&gs_handle);
        if (res != 0)
        {
            syn6988_interface_debug_print("syn6988: resume failed.\n");
            (void)syn6988_deinit(&gs_handle);
            
            return 1;
        }
        syn6988_interface_debug_print("syn6988: synthesis control resume.\n");
        status = SYN6988_STATUS_BUSY;
        while (status == SYN6988_STATUS_BUSY)
        {
            syn6988_interface_delay_ms(500);
            res = syn6988_get_status(&gs_handle, &status);
            if (res != 0)
            {
                syn6988_interface_debug_print("syn6988: get status failed.\n");
                (void)syn6988_deinit(&gs_handle);
                
                return 1;
            }
        }
        res = syn6988_synthesis_text(&gs_handle, (char *)gb2312_text);
        if (res != 0)
        {
            syn6988_interface_debug_print("syn6988: synthesis text failed.\n");
            (void)syn6988_deinit(&gs_handle);
            
            return 1;
        }
        syn6988_interface_delay_ms(500);
        res = syn6988_stop(&gs_handle);
        if (res != 0)
        {
            syn6988_interface_debug_print("syn6988: stop failed.\n");
            (void)syn6988_deinit(&gs_handle);
            
            return 1;
        }
        syn6988_interface_debug_print("syn6988: synthesis control stop.\n");
        syn6988_interface_delay_ms(5000);
    }
    
    /* synthesis volume test */
    syn6988_interface_debug_print("syn6988: synthesis volume test.\n");
    res = syn6988_set_synthesis_volume(&gs_handle, 5);
    if (res != 0)
    {
        syn6988_interface_debug_print("syn6988: set synthesis volume failed.\n");
        (void)syn6988_deinit(&gs_handle);
        
        return 1;
    }
    syn6988_interface_debug_print("syn6988: set synthesis volume 5.\n");
    res = syn6988_synthesis_text(&gs_handle, (char *)gb2312_text);
    if (res != 0)
    {
        syn6988_interface_debug_print("syn6988: synthesis text failed.\n");
        (void)syn6988_deinit(&gs_handle);
        
        return 1;
    }
    status = SYN6988_STATUS_BUSY;
    while (status == SYN6988_STATUS_BUSY)
    {
        syn6988_interface_delay_ms(500);
        res = syn6988_get_status(&gs_handle, &status);
        if (res != 0)
        {
            syn6988_interface_debug_print("syn6988: get status failed.\n");
            (void)syn6988_deinit(&gs_handle);
            
            return 1;
        }
    }
    res = syn6988_set_synthesis_volume(&gs_handle, 10);
    if (res != 0)
    {
        syn6988_interface_debug_print("syn6988: set synthesis volume failed.\n");
        (void)syn6988_deinit(&gs_handle);
        
        return 1;
    }
    
    /* synthesis speed test */
    syn6988_interface_debug_print("syn6988: synthesis speed test.\n");
    res = syn6988_set_synthesis_speed(&gs_handle, 10);
    if (res != 0)
    {
        syn6988_interface_debug_print("syn6988: set synthesis speed failed.\n");
        (void)syn6988_deinit(&gs_handle);
        
        return 1;
    }
    syn6988_interface_debug_print("syn6988: set synthesis speed 10.\n");
    res = syn6988_synthesis_text(&gs_handle, (char *)gb2312_text);
    if (res != 0)
    {
        syn6988_interface_debug_print("syn6988: synthesis text failed.\n");
        (void)syn6988_deinit(&gs_handle);
        
        return 1;
    }
    status = SYN6988_STATUS_BUSY;
    while (status == SYN6988_STATUS_BUSY)
    {
        syn6988_interface_delay_ms(500);
        res = syn6988_get_status(&gs_handle, &status);
        if (res != 0)
        {
            syn6988_interface_debug_print("syn6988: get status failed.\n");
            (void)syn6988_deinit(&gs_handle);
            
            return 1;
        }
    }
    res = syn6988_set_synthesis_speed(&gs_handle, 5);
    if (res != 0)
    {
        syn6988_interface_debug_print("syn6988: set synthesis speed failed.\n");
        (void)syn6988_deinit(&gs_handle);
        
        return 1;
    }
    
    /* synthesis language test */
    syn6988_interface_debug_print("syn6988: synthesis language test.\n");
    res = syn6988_set_synthesis_language(&gs_handle, SYN6988_LANGUAGE_ENGLISH);
    if (res != 0)
    {
        syn6988_interface_debug_print("syn6988: set synthesis language failed.\n");
        (void)syn6988_deinit(&gs_handle);
        
        return 1;
    }
    syn6988_interface_debug_print("syn6988: set synthesis language english.\n");
    res = syn6988_synthesis_text(&gs_handle, (char *)english_text);
    if (res != 0)
    {
        syn6988_interface_debug_print("syn6988: synthesis text failed.\n");
        (void)syn6988_deinit(&gs_handle);
        
        return 1;
    }
    status = SYN6988_STATUS_BUSY;
    while (status == SYN6988_STATUS_BUSY)
    {
        syn6988_interface_delay_ms(500);
        res = syn6988_get_status(&gs_handle, &status);
        if (res != 0)
        {
            syn6988_interface_debug_print("syn6988: get status failed.\n");
            (void)syn6988_deinit(&gs_handle);
            
            return 1;
        }
    }
    
    /* set synthesis language chinese */
    res = syn6988_set_synthesis_language(&gs_handle, SYN6988_LANGUAGE_CHINESE);
    if (res != 0)
    {
        syn6988_interface_debug_print("syn6988: set synthesis language failed.\n");
        (void)syn6988_deinit(&gs_handle);
        
        return 1;
    }
    syn6988_interface_debug_print("syn6988: set synthesis language chinese.\n");
    res = syn6988_synthesis_text(&gs_handle, (char *)gb2312_text);
    if (res != 0)
    {
        syn6988_interface_debug_print("syn6988: synthesis text failed.\n");
        (void)syn6988_deinit(&gs_handle);
        
        return 1;
    }
    status = SYN6988_STATUS_BUSY;
    while (status == SYN6988_STATUS_BUSY)
    {
        syn6988_interface_delay_ms(500);
        res = syn6988_get_status(&gs_handle, &status);
        if (res != 0)
        {
            syn6988_interface_debug_print("syn6988: get status failed.\n");
            (void)syn6988_deinit(&gs_handle);
            
            return 1;
        }
    }
    
    /* set synthesis language auto */
    res = syn6988_set_synthesis_language(&gs_handle, SYN6988_LANGUAGE_AUTO);
    if (res != 0)
    {
        syn6988_interface_debug_print("syn6988: set synthesis language failed.\n");
        (void)syn6988_deinit(&gs_handle);
        
        return 1;
    }
    syn6988_interface_debug_print("syn6988: set synthesis language auto.\n");
    res = syn6988_synthesis_text(&gs_handle, (char *)english_text);
    if (res != 0)
    {
        syn6988_interface_debug_print("syn6988: synthesis text failed.\n");
        (void)syn6988_deinit(&gs_handle);
        
        return 1;
    }
    status = SYN6988_STATUS_BUSY;
    while (status == SYN6988_STATUS_BUSY)
    {
        syn6988_interface_delay_ms(500);
        res = syn6988_get_status(&gs_handle, &status);
        if (res != 0)
        {
            syn6988_interface_debug_print("syn6988: get status failed.\n");
            (void)syn6988_deinit(&gs_handle);
            
            return 1;
        }
    }
    
    /* command test */
    syn6988_interface_debug_print("syn6988: command test.\n");
    syn6988_interface_debug_print("syn6988: set command 0.\n");
    memset(s, 0, sizeof(char) * 32);
    strncpy(s, "[b0]", 32);
    res = syn6988_synthesis_text(&gs_handle, s);
    if (res != 0)
    {
        syn6988_interface_debug_print("syn6988: synthesis text failed.\n");
        (void)syn6988_deinit(&gs_handle);
        
        return 1;
    }
    memset(s, 0, sizeof(char) * 32);
    strncpy(s, "abc,def,ghi", 32);
    res = syn6988_synthesis_text(&gs_handle, s);
    if (res != 0)
    {
        syn6988_interface_debug_print("syn6988: synthesis text failed.\n");
        (void)syn6988_deinit(&gs_handle);
        
        return 1;
    }
    status = SYN6988_STATUS_BUSY;
    while (status == SYN6988_STATUS_BUSY)
    {
        syn6988_interface_delay_ms(500);
        res = syn6988_get_status(&gs_handle, &status);
        if (res != 0)
        {
            syn6988_interface_debug_print("syn6988: get status failed.\n");
            (void)syn6988_deinit(&gs_handle);
            
            return 1;
        }
    }
    syn6988_interface_debug_print("syn6988: set command 1.\n");
    memset(s, 0, sizeof(char) * 32);
    strncpy(s, "[b1]", 32);
    res = syn6988_synthesis_text(&gs_handle, s);
    if (res != 0)
    {
        syn6988_interface_debug_print("syn6988: synthesis text failed.\n");
        (void)syn6988_deinit(&gs_handle);
        
        return 1;
    }
    memset(s, 0, sizeof(char) * 32);
    strncpy(s, "abc,def,ghi", 32);
    res = syn6988_synthesis_text(&gs_handle, s);
    if (res != 0)
    {
        syn6988_interface_debug_print("syn6988: synthesis text failed.\n");
        (void)syn6988_deinit(&gs_handle);
        
        return 1;
    }
    status = SYN6988_STATUS_BUSY;
    while (status == SYN6988_STATUS_BUSY)
    {
        syn6988_interface_delay_ms(500);
        res = syn6988_get_status(&gs_handle, &status);
        if (res != 0)
        {
            syn6988_interface_debug_print("syn6988: get status failed.\n");
            (void)syn6988_deinit(&gs_handle);
            
            return 1;
        }
    }
    memset(s, 0, sizeof(char) * 32);
    strncpy(s, "[b0]", 32);
    res = syn6988_synthesis_text(&gs_handle, s);
    if (res != 0)
    {
        syn6988_interface_debug_print("syn6988: synthesis text failed.\n");
        (void)syn6988_deinit(&gs_handle);
        
        return 1;
    }
    
    if (interface == SYN6988_INTERFACE_UART)
    {
        /* syn6988 standby test */
        syn6988_interface_debug_print("syn6988: syn6988 standby test.\n");
        
        /* standby */
        res = syn6988_standby(&gs_handle);
        if (res != 0)
        {
            syn6988_interface_debug_print("syn6988: standby failed.\n");
            (void)syn6988_deinit(&gs_handle);
            
            return 1;
        }
        
        /* standby ok */
        syn6988_interface_debug_print("syn6988: standby ok.\n");
        
        /* syn6988 wake up test */
        syn6988_interface_debug_print("syn6988: syn6988 wake up test.\n");
        
        /* wake up */
        res = syn6988_wake_up(&gs_handle);
        if (res != 0)
        {
            syn6988_interface_debug_print("syn6988: wake up failed.\n");
            (void)syn6988_deinit(&gs_handle);
            
            return 1;
        }
        
        /* wake up ok */
        syn6988_interface_debug_print("syn6988: wake up ok.\n");
    }
    
    /* finish synthesis test */
    syn6988_interface_debug_print("syn6988: finish synthesis test.\n");
    (void)syn6988_deinit(&gs_handle);
    
    return 0;
}
