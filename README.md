[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver SYN6988

[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/syn6988/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE)

SYN6988 chip is a high-end Chinese English speech synthesis chip newly launched by Beijing Yuyin Tianxia Technology Co., Ltd. in 2021. SYN6988 receives text data to be synthesized through UART or SPI interface communication, achieving text to speech (or TTS speech) conversion. The latest SYN6988 Chinese speech synthesis chip launched by the company inherits the excellent features of SY6658 high-end Chinese speech synthesis chip: small-sized patch packaging, simple hardware interface, low power consumption, clear and round sound, close to human voice, and extremely high cost-effectiveness; In addition, SYN6988 has added English text parsing and English sound library, making it a truly high-end industry oriented Chinese English speech synthesis chip. The SYN6988 chip is fully compatible with the SYN6658 chip in terms of hardware and communication interfaces.

LibDriver SYN6988 is the full function driver of SYN6988 launched by LibDriver.It provides text synthesis, sound synthesis and other functions. LibDriver is MISRA compliant.

### Table of Contents

  - [Instruction](#Instruction)
  - [Install](#Install)
  - [Usage](#Usage)
    - [example basic](#example-basic)
  - [Document](#Document)
  - [Contributing](#Contributing)
  - [License](#License)
  - [Contact Us](#Contact-Us)

### Instruction

/src includes LibDriver SYN6988 source files.

/interface includes LibDriver SYN6988 UART, SPI platform independent template.

/test includes LibDriver SYN6988 driver test code and this code can test the chip necessary function simply.

/example includes LibDriver SYN6988 sample code.

/doc includes LibDriver SYN6988 offline document.

/datasheet includes SYN6988 datasheet.

/project includes the common Linux and MCU development board sample code. All projects use the shell script to debug the driver and the detail instruction can be found in each project's README.md.

/misra includes the LibDriver MISRA code scanning results.

### Install

Reference /interface UART, SPI platform independent template and finish your platform UART, SPI driver.

Add the /src directory, the interface driver for your platform, and your own drivers to your project, if you want to use the default example drivers, add the /example directory to your project.

### Usage

You can refer to the examples in the /example directory to complete your own driver. If you want to use the default programming examples, here's how to use them.

#### example basic

```C
#include "driver_syn6988_basic.h"

uint8_t res;
char text[129] = "你好";

/* basic init */
res = syn6988_basic_init(SYN6988_INTERFACE_UART);
if (res != 0)
{
    return 1;
}

...
    
/* delay 500ms */
syn6988_interface_delay_ms(500);

/* syn */
res = syn6988_basic_synthesis(text);
if (res != 0)
{
    (void)syn6988_basic_deinit();

    return 1;
}
(void)syn6988_basic_sync();

...

/* sound test */
res = syn6988_synthesis_text(&gs_handle, (char const *)SYN6988_SOUND_202);
if (res != 0)
{
    (void)syn6988_deinit(&gs_handle);

    return 1;
}
(void)syn6988_basic_sync();

...
    
/* basic deinit */
(void)syn6988_basic_deinit();
```

### Document

Online documents: [https://www.libdriver.com/docs/syn6988/index.html](https://www.libdriver.com/docs/syn6988/index.html).

Offline documents: /doc/html/index.html.

### Contributing

Please refer to CONTRIBUTING.md.

### License

Copyright (c) 2015 - present LibDriver All rights reserved



The MIT License (MIT) 



Permission is hereby granted, free of charge, to any person obtaining a copy

of this software and associated documentation files (the "Software"), to deal

in the Software without restriction, including without limitation the rights

to use, copy, modify, merge, publish, distribute, sublicense, and/or sell

copies of the Software, and to permit persons to whom the Software is

furnished to do so, subject to the following conditions: 



The above copyright notice and this permission notice shall be included in all

copies or substantial portions of the Software. 



THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR

IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,

FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE

AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER

LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,

OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE

SOFTWARE. 

### Contact Us

Please send an e-mail to lishifenging@outlook.com.