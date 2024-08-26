[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver SYN6988

[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/syn6988/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE)

SYN6988芯片是北京宇音天下科技有限公司于2021年最新推出的一款高端的中英文语音合成芯片。SYN6988通过UART接口或SPI接口通讯方式，接收待合成的文本数据，实现文本到语音（或TTS语音）的转换。公司最新推出的SYN6988中文语音合成芯片，继承了SY6658高端中文语音合成芯片的优秀特点：小尺寸贴片封装、硬件接口简单、低功耗、音色清亮圆润，接近人声、极高的性/价比；除此之外，SYN6988新增了英文文本解析和英文音库，是一款真正面向高端行业应用领域的中英文语音合成芯片。SYN6988芯片做到了硬件和通讯接口与SYN6988芯片完全兼容。

LibDriver SYN6988 是LibDriver推出的SYN6988 的全功能驱动，该驱动提供文本合成、声音合成等功能并且它符合MISRA标准。

### 目录

  - [说明](#说明)
  - [安装](#安装)
  - [使用](#使用)
    - [example basic](#example-basic)
  - [文档](#文档)
  - [贡献](#贡献)
  - [版权](#版权)
  - [联系我们](#联系我们)

### 说明

/src目录包含了LibDriver SYN6988的源文件。

/interface目录包含了LibDriver SYN6988与平台无关的UART, SPI模板。

/test目录包含了LibDriver SYN6988驱动测试程序，该程序可以简单的测试芯片必要功能。

/example目录包含了LibDriver SYN6988编程范例。

/doc目录包含了LibDriver SYN6988离线文档。

/datasheet目录包含了SYN6988数据手册。

/project目录包含了常用Linux与单片机开发板的工程样例。所有工程均采用shell脚本作为调试方法，详细内容可参考每个工程里面的README.md。

/misra目录包含了LibDriver MISRA代码扫描结果。

### 安装

参考/interface目录下与平台无关的UART, SPI模板，完成指定平台的UART, SPI驱动。

将/src目录，您使用平台的接口驱动和您开发的驱动加入工程，如果您想要使用默认的范例驱动，可以将/example目录加入您的工程。

### 使用

您可以参考/example目录下的编程范例完成适合您的驱动，如果您想要使用默认的编程范例，以下是它们的使用方法。

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

### 文档

在线文档: [https://www.libdriver.com/docs/syn6988/index.html](https://www.libdriver.com/docs/syn6988/index.html)。

离线文档: /doc/html/index.html。

### 贡献

请参考CONTRIBUTING.md。

### 版权

版权 (c) 2015 - 现在 LibDriver 版权所有

MIT 许可证（MIT）

特此免费授予任何获得本软件副本和相关文档文件（下称“软件”）的人不受限制地处置该软件的权利，包括不受限制地使用、复制、修改、合并、发布、分发、转授许可和/或出售该软件副本，以及再授权被配发了本软件的人如上的权利，须在下列条件下：

上述版权声明和本许可声明应包含在该软件的所有副本或实质成分中。

本软件是“如此”提供的，没有任何形式的明示或暗示的保证，包括但不限于对适销性、特定用途的适用性和不侵权的保证。在任何情况下，作者或版权持有人都不对任何索赔、损害或其他责任负责，无论这些追责来自合同、侵权或其它行为中，还是产生于、源于或有关于本软件以及本软件的使用或其它处置。

### 联系我们

请联系lishifenging@outlook.com。