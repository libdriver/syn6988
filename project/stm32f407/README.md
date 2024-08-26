### 1. Chip

#### 1.1 Chip Info

Chip Name: STM32F407ZGT6.

Extern Oscillator: 8MHz.

UART Pin: TX/RX PA9/PA10.

UART2 Pin: TX/RX PA2/PA3.

SPI Pin: SCK/MISO/MOSI/CS  PA5/PA6/PA7/PA4.

READY Pin: PA8.

### 2. Development and Debugging

#### 2.1 Integrated Development Environment

LibDriver provides both Keil and IAR integrated development environment projects.

MDK is the Keil ARM project and your Keil version must be 5 or higher.Keil ARM project needs STMicroelectronics STM32F4 Series Device Family Pack and you can download from https://www.keil.com/dd2/stmicroelectronics/stm32f407zgtx.

EW is the IAR ARM project and your IAR version must be 9 or higher.

#### 2.2 Serial Port Parameter

Baud Rate: 115200.

Data Bits : 8.

Stop Bits: 1.

Parity: None.

Flow Control: None.

#### 2.3 Serial Port Assistant

We use '\n' to wrap lines.If your serial port assistant displays exceptions (e.g. the displayed content does not divide lines), please modify the configuration of your serial port assistant or replace one that supports '\n' parsing.

### 3. SYN6988

#### 3.1 Command Instruction

1. Show syn6988 chip and driver information.

   ```shell
   syn6988 (-i | --information)
   ```

2. Show syn6988 help.

   ```shell
   syn6988 (-h | --help)
   ```

3. Show syn6988 pin connections of the current board.

   ```shell
   syn6988 (-p | --port)
   ```

5. Run syn6988 synthesis test.

   ```shell
   syn6988 (-t syn | --test=syn) --interface=<uart | spi> 
   ```

5. Run syn6988 synthesis text function, gb2312 format is gb2312.

   ```shell
   syn6988 (-e syn | --example=syn) --interface=<uart | spi> --text=<gb2312>
   ```

#### 3.2 Command Example

```shell
syn6988 -i

syn6988: chip is Voicetx SYN6988.
syn6988: manufacturer is Voicetx.
syn6988: interface is UART SPI.
syn6988: driver version is 1.0.
syn6988: min supply voltage is 3.1V.
syn6988: max supply voltage is 4.5V.
syn6988: max current is 53.00mA.
syn6988: max temperature is 85.0C.
syn6988: min temperature is -40.0C.
```

```shell
syn6988 -p

syn6988: TX connected to GPIOA PIN3.
syn6988: RX connected to GPIOA PIN2.
syn6988: SCK connected to GPIOA PIN5.
syn6988: MISO connected to GPIOA PIN6.
syn6988: MOSI connected to GPIOA PIN7.
syn6988: CS connected to GPIOA PIN4.
syn6988: READY connected to GPIOA PIN8.
```

```shell
syn6988 -t syn --interface=uart

syn6988: chip is Voicetx SYN6988.
syn6988: manufacturer is Voicetx.
syn6988: interface is UART SPI.
syn6988: driver version is 1.0.
syn6988: min supply voltage is 3.1V.
syn6988: max supply voltage is 4.5V.
syn6988: max current is 53.00mA.
syn6988: max temperature is 85.0C.
syn6988: min temperature is -40.0C.
syn6988: synthesis text test.
syn6988: gb2312 synthesis text.
syn6988: gbk synthesis text.
syn6988: big5 synthesis text.
syn6988: unicode little endian synthesis text.
syn6988: unicode big endian synthesis text.
syn6988: sound synthesis text.
syn6988: synthesis control test.
syn6988: synthesis control pause.
syn6988: synthesis control resume.
syn6988: synthesis control stop.
syn6988: synthesis volume test.
syn6988: set synthesis volume 5.
syn6988: synthesis speed test.
syn6988: set synthesis speed 10.
syn6988: synthesis language test.
syn6988: set synthesis language english.
syn6988: set synthesis language chinese.
syn6988: set synthesis language auto.
syn6988: command test.
syn6988: set command 0.
syn6988: set command 1.
syn6988: syn6988 standby test.
syn6988: standby ok.
syn6988: syn6988 wake up test.
syn6988: wake up ok.
syn6988: finish synthesis test.
```

```shell
syn6988 -e syn --interface=uart --text=你好

syn6988: synthesis 你好.
```

```shell
syn6988 -h

Usage:
  syn6988 (-i | --information)
  syn6988 (-h | --help)
  syn6988 (-p | --port)
  syn6988 (-t syn | --test=syn) --interface=<uart | spi>
  syn6988 (-e syn | --example=syn) --interface=<uart | spi> --text=<gb2312>

Options:
  -e <syn>, --example=<syn>
                          Run the driver example.
  -h, --help              Show the help.
  -i, --information       Show the chip information.
      --interface=<uart | spi>
                          Set the chip interface.([default: uart])
  -p, --port              Display the pin connections of the current board.
  -t <syn>, --test=<syn>  Run the driver test.
      --text=<gb2312>     Set the synthesis text and it's format is GB2312.
```

