/**
 * UART1 Generated Driver Header File
 * 
 * @file      uart1.h
 *            
 * @ingroup   uartdriver
 *            
 * @brief     This is the generated driver header file for the UART1 driver
 *            
 * @version   Driver Version 1.1.0
 *            
 * @skipline  Device : dsPIC33CK256MP508
*/

/*
© [2022] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#ifndef UART1_H
#define UART1_H

// Section: Included Files

#include <stdbool.h>
#include <stdint.h>
#include "uart_interface.h"

// Section: Data Type Definitions

/**
 @ingroup  uartdriver
 @brief    Structure object of type UART_INTERFACE with the 
           custom name given by the user in the Melody Driver User interface. 
           The default name e.g. UART1 can be changed by the 
           user in the UART user interface. 
           This allows defining a structure with application specific name 
           using the 'Custom Name' field. Application specific name allows the 
           API Portability.
*/
extern const struct UART_INTERFACE UART1_Drv;

/**
 * @ingroup  uartdriver
 * @brief    This macro defines the Custom Name for \ref UART1_Initialize API
 */
#define UART1_Drv_Initialize UART1_Initialize
/**
 * @ingroup  uartdriver
 * @brief    This macro defines the Custom Name for \ref UART1_Deinitialize API
 */
#define UART1_Drv_Deinitialize UART1_Deinitialize
/**
 * @ingroup  uartdriver
 * @brief    This macro defines the Custom Name for \ref UART1_Read API
 */
#define UART1_Drv_Read UART1_Read
/**
 * @ingroup  uartdriver
 * @brief    This macro defines the Custom Name for \ref UART1_Write API
 */
#define UART1_Drv_Write UART1_Write
/**
 * @ingroup  uartdriver
 * @brief    This macro defines the Custom Name for \ref UART1_IsRxReady API
 */
#define UART1_Drv_IsRxReady UART1_IsRxReady
/**
 * @ingroup  uartdriver
 * @brief    This macro defines the Custom Name for \ref UART1_IsTxReady API
 */
#define UART1_Drv_IsTxReady UART1_IsTxReady
/**
 * @ingroup  uartdriver
 * @brief    This macro defines the Custom Name for \ref UART1_IsTxDone API
 */
#define UART1_Drv_IsTxDone UART1_IsTxDone

// Section: UART1 APIs

/**
 * @ingroup  uartdriver
 * @brief    Initializes the UART module
 * @return   none
 */
void UART1_Initialize(void);

/**
 * @ingroup  uartdriver
 * @brief    Deinitializes the UART to POR values
 * @return   none
 */
void UART1_Deinitialize(void);

/**
 * @ingroup  uartdriver
 * @brief    Reads a byte of data from the UART1
 * @pre      UART1_Initialize function should have been called
 *           before calling this function. The transfer status should be checked
 *           to see  if the receiver is not empty before calling this function.
 * @return   A data byte received by the driver
 */
uint8_t UART1_Read(void);

/**
 * @ingroup    uartdriver
 * @brief      Writes a byte of data to the UART1
 * @pre        UART1_Initialize function should have been called
 *             before calling this function. The transfer status should be checked
 *             to see if transmitter is not full before calling this function.
 * @param[in]  data - Data byte to write to the UART1
 * @return     none
 */
void UART1_Write(uint8_t data);

/**
 * @ingroup  uartdriver
 * @brief    Returns a boolean value if data is available to read
 * @return   true    - Data available to read
 * @return   false   - Data not available to read
 */
bool UART1_IsRxReady(void);

/**
 * @ingroup  uartdriver
 * @brief    Returns a boolean value if data can be written
 * @return   true    - Data can be written
 * @return   false   - Data can not be written
 */
bool UART1_IsTxReady(void);

/**
 * @ingroup  uartdriver
 * @brief    Indicates if all bytes have been transferred
 * @return   true    - All bytes transferred
 * @return   false   - Data transfer is pending
 */
bool UART1_IsTxDone(void);

#endif  // UART1_H

