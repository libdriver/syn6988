### 1. Board

#### 1.1 Board Info

Board Name: Raspberry Pi 4B.

UART Pin: TX/RX GPIO14/GPIO15.

SPI Pin: SCLK/MOSI/MISO/CS GPIO11/GPIO10/GPIO9/GPIO8.

READY Pin: GPIO17.

### 2. Install

#### 2.1 Dependencies

Install the necessary dependencies.

```shell
sudo apt-get install libgpiod-dev pkg-config cmake -y
```
#### 2.2 Configuration

Enable serial port.

Disable serial console.

#### 2.3 Makefile

Build the project.

```shell
make
```

Install the project and this is optional.

```shell
sudo make install
```

Uninstall the project and this is optional.

```shell
sudo make uninstall
```

#### 2.4 CMake

Build the project.

```shell
mkdir build && cd build 
cmake .. 
make
```

Install the project and this is optional.

```shell
sudo make install
```

Uninstall the project and this is optional.

```shell
sudo make uninstall
```

Test the project and this is optional.

```shell
make test
```

Find the compiled library in CMake. 

```cmake
find_package(syn6988 REQUIRED)
```

#### 2.5 Command Problem

Each command will sent a sleep command to the chip, but raspberry can't run wake up command, so you should power down and power on SYN6658 every time before your any new command.

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
./syn6988 -i

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
./syn6988 -p

syn6988: TX connected to GPIO15(BCM).
syn6988: RX connected to GPIO14(BCM).
syn6988: SCK connected to GPIO11(BCM).
syn6988: MISO connected to GPIO9(BCM).
syn6988: MOSI connected to GPIO10(BCM).
syn6988: CS connected to GPIO8(BCM).
syn6988: READY connected to GPIO17(BCM).
```

```shell
./syn6988 -t syn --interface=uart

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
./syn6988 -e syn --interface=uart --text=你好

syn6988: synthesis 你好.
```

```shell
./syn6988 -h

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

