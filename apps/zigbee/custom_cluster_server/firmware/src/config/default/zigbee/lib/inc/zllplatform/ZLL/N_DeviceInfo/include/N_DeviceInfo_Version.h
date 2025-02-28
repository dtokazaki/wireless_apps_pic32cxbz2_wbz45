/*******************************************************************************
  ZLL Device Version Header File

  Company:
    Microchip Technology Inc.

  File Name:
    N_Deviceinfo_Version.h

  Summary:
    This file contains the ZLL Device Version.

  Description:
    This file contains the ZLL Device Version.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
// DOM-IGNORE-END

#ifndef _N_DEVICEINFO_VERSION_H_
#define _N_DEVICEINFO_VERSION_H_

#define PRODUCT                 "ZB"
#define MAJOR_NUM               "5"
#define MINOR_NUM               "1"
#define MINOR_DERIVATIVE_NUM    "0"
#define BRANCH_ID               "3"
#define BRANCH_ITERATION_NUM    "1"
#define RELEASE_M               "P"

/* Release Version Information */
#define VER_PRODUCT_INFO    PRODUCT"_V"MAJOR_NUM"."MINOR_NUM"."MINOR_DERIVATIVE_NUM"_"BRANCH_ID"."BRANCH_ITERATION_NUM"_"RELEASE_M
#define N_DEVICE_INFO_PLATFORM_VERSION    VER_PRODUCT_INFO

#endif // _N_DEVICEINFO_VERSION_H_
