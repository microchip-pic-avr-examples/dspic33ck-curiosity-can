![image](images/microchip.jpg)

## dsPIC33CK Curiosity Development Board - CAN-2.0 Demo

![Board](images/board.jpg)

## Summary

This project demonstrates the CAN 2.0 communication on dsPIC33CK Curiosity board using MCC- Melody driver code.

Demo code will loopback the CAN data messages if received message ID is 100 (0x64) or 101 (0x65), it responds with IDs to 120 (0x78) and 121 (0x79) respectively. Green LED will blink if data is received and transmitted back successfully.

CAN is configured in such a way that it ignores any messages other than above mentioned IDs on the bus.

## Related Documentation

[dsPIC33CK256MP508 datasheet](https://www.microchip.com/dsPIC33CK256MP508) for more information or specifications.

## Software Used

- [MPLAB® X IDE v6.00](https://www.microchip.com/mplabx) or newer
- [MPLAB® XC16 v2.00](https://www.microchip.com/xc16) or newer
- Device Family Pack : dsPIC33CK-MP_DFP v1.7.208
- [MPLAB® Code Configurator (MCC) 5.1.0](https://www.microchip.com/mcc) or newer
- [MPLAB® Data Visualizer v1.3.1136](https://www.microchip.com/en-us/tools-resources/debug/mplab-data-visualizer) or any other serial terminal
- [OptoLyzer® Studio Lite v1.8.1.1](https://www.microchip.com/en-us/tools-resources/develop/k2l-automotive-tools/optolyzer-studio) or any CAN analyzer tool

## Hardware Used

- [dsPIC33CK Curiosity Board](https://www.microchip.com/dm330030)

- [MCP2542 Click Board](https://www.mikroe.com/mcp2542-click)

- CAN Analyzer with DB9 Serial port

## Setup

**Hardware Setup**

- Plug the [MCP2542 Click Board](https://www.mikroe.com/mcp2542-click) to **mikroBUS B** of Curiosity board
- Connect CAN analyzer to [MCP2542 Click Board](https://www.mikroe.com/mcp2542-click) via DB9 serial connector
- Connect micro-USB cable to port `J7` of Curiosity board to PC for viewing debug messages.
- [Click here](images/hardware_setup.jpg) to view the hardware setup.

**MPLAB® X IDE Setup**

- Open the `dspic33ck-curiosity-can.X` project in MPLAB® X IDE
- Build and program the device

**CAN Analyzer Tool Setup**

- Configure CAN analyzer clock to 1 Mbps nominal bit-rate
- Create CAN data frame with message ID 101(0x64) with valid data length as per CAN 2.0 protocol (Eg. 0,1,2,3,4,5,6,7,8)
- Similarly create CAN frames with ID 102(0x65), 103(0x66) with above mentioned valid data length
- Start the analyzer log and send the frames

## Operation

- Demo code responds with the CAN message ID 0x78, 0x79 upon recieving the CAN message ID 0x64, 0x65 respectively.
- CAN acceptance mask configured in the demo code rejects any CAN message ID other than 0x64, 0x65.
- Green LED Blink indicates successful receive and transmit of the CAN message ID 0x64/0x65 and 0x78/0x79.
- Red LED On indicates CAN node is in Error state or there is Recieve Overflow error or CAN Transmit failed.

Received and transmitted frames from CAN peripheral can also be viewed from the serial terminal for debug purposes

![CAN Analyzer log](images/analyzer_log.jpg)

**Summary of the above log:**

| Message Index in the log | Description                                                                                                                                   | Transmitter         | Type           | Message ID in HEX | Data Length in decimal | Data in HEX             |
| ------------------------ | --------------------------------------------------------------------------------------------------------------------------------------------- | ------------------- | -------------- | ----------------- | ---------------------- | ----------------------- |
| 0                        | Standard data frame sent from the analyzer with message ID 100 (0x64)                                                                         | CAN Analyzer        | CAN Data Frame | 0x64 (Standard)   | 12                     | 41 42 43 44 45 46 47 48 |
| 1                        | Loopback of the data frame with message ID 120 (0x78)                                                                                         | dsPIC33CK Curiosity | CAN Data Frame | 0x78 (Standard)   | 12                     | 41 42 43 44 45 46 47 48 |
| 2                        | Extended data frame sent from the analyzer with message ID 101 (0x65)                                                                         | CAN Analyzer        | CAN Data Frame | 0x65 (Extended)   | 64                     | 43 41 4E 2D 44 45 4D 4F |
| 3                        | Loopback of the data frame with message ID 121 (0x79)                                                                                         | dsPIC33CK Curiosity | CAN Data Frame | 0x79 (Extended)   | 64                     | 43 41 4E 2D 44 45 4D 4F |
| 4                        | Extended data frame sent from the analyzer with message ID 103. This message will be ignored from the curiosity board as per filter settings. | CAN Analyzer        | CAN Data Frame | 103 (Extended)    | 12                     | 41 42 43 44 45 46 47 48 |

## MCC settings for reference

This Project uses the driver code generated by **MCC-Melody**.

**CAN Configuration**

- CAN Configuration done in MCC Melody User Interface for this demo code. <br>
- Custom name to `CAN_Driver` <br>
  ![custom name](images/can_custom_name.jpg)
- Clock and Nominal Bit-Rate Settings: Set CAN clock to 20 MHz, nominal bit rate to 1Mbps and sample point to 80%<br>
  ![step1-step2](images/step1_step2.jpg)
- General Settings: Enable ISO CRC and enable error interrupt <br>
  ![step3](images/step3.jpg)
- FIFO Configuration: Enable TXQ, set depth as 32, payload bytes as 64. Enable FIFO1, set depth as 32, payload bytes as 64 and operation to RX<br>
  ![step4](images/step4.jpg)
- Receive Filter Configuration: Enable Filter0 and type message IDs `0x64, 0x65, 0x64x,0x65x`. This will filter all messages allowing only standard and extended messages with ID 0x64 and 0x65<br>
  ![step5](images/filter.jpg)

**UART Configuration**

- UART Configuration done in MCC Melody User Interface for this demo code. <br>
  ![uart settings](images/uart.jpg)

**PIN Configuration**

- CAN pins: RD9 for CAN1TX and RD12 for CAN1RX
- UART Pins: RD4 as U1TX and RD3 as U1RX<br>
  ![pin selection](images/pin_selection.jpg)
- LED Pins: RE14 and RE15 as GPIO Output<br>
  ![rgb pin selection](images/rgb_pins.jpg)
- Custom name of RE14 to `LED_GREEN` and RE15 to `LED_RED`<br>
  ![rgb custom name](images/rgb_custom_name.jpg)

## OptoLyzer Studio Activity File

If the CAN analyzer uses `OptoLyzer® Studio`, then activity file can be found in the [optolyzerActivityFile](optolyzerActivityFile/) folder
