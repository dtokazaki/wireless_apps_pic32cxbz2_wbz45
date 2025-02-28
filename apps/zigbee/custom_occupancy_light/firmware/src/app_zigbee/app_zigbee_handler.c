/*******************************************************************************
  Application Zigbee Handler Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_zigbee_handler.c

  Summary:
    This file contains the Application Zigbee functions for this project.

  Description:
    This file contains the Application Zigbee functions for this project.
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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include <app_zigbee/app_zigbee_handler.h>
#include <app_zigbee/zigbee_console/console.h>
#include <zcl/include/zclZllIdentifyCluster.h>
#include <zcl/include/zclZllGroupsCluster.h>
#include <zcl/include/zclZllOnOffCluster.h>
#include <zcl/include/zclZllLevelControlCluster.h>
#include <zcl/include/zclZllColorControlCluster.h>
#include <zcl/include/zclZllScenesCluster.h>
#include <zcl/include/zcloccupancysensingcluster.h>
#include <z3device/custom/include/customOnOffCluster.h>
#include <z3device/custom/include/customOccupancySensingCluster.h>
#include <z3device/custom/include/customLevelControlCluster.h>
#include <z3device/custom/include/customColorControlCluster.h>
#include <rgb_led.h>
// *****************************************************************************
// *****************************************************************************
// *****************************************************************************
// Section: Macros
// *****************************************************************************
// *****************************************************************************

void BSP_Event_Handler(APP_Zigbee_Event_t event);
void Cluster_Event_Handler(APP_Zigbee_Event_t event);
void Zigbee_Event_Handler(APP_Zigbee_Event_t event);

#define MIN_COLOR_LEVEL           0
#define MAX_COLOR_LEVEL           0xfeff

#define MIN_SATURATION_LEVEL      0
#define MAX_SATURATION_LEVEL      0xfe
// *****************************************************************************
// *****************************************************************************
// Section: Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Zigbee_Handler(APP_Zigbee_Event_t event)

  Remarks:
    See prototype in app_zigbee_handler.h.
******************************************************************************/

void APP_Zigbee_Handler(APP_Zigbee_Event_t event)
{
    switch(event.eventGroup)
    {
        case EVENT_BSP:
        {
            /* BSP Events Dispatcher */
            BSP_Event_Handler(event);
        }
        break;

        case EVENT_ZIGBEE:
        {
            /* Zigbee Events Dispatcher */
            Zigbee_Event_Handler(event);
        }
        break;

        case EVENT_CLUSTER:
        {
            /* Cluster Events Dispatcher */
            Cluster_Event_Handler(event);
        }
        break;

        default:
        break;
    }
}

/*******************************************************************************
  Function:
    void BSP_Event_Handler(APP_Zigbee_Event_t event)

  Remarks:
    See prototype in app_zigbee_handler.h.
******************************************************************************/

void BSP_Event_Handler(APP_Zigbee_Event_t event)
{
    // User to handle  board Support package events
    switch(event.eventId)
    {
        case CMD_LED_OPEN:
        {
            /* Init/Open LEDs */
            //appSnprintf("Init /Open LEDs\r\n");
        }
        break;

        case CMD_LED_ON:
        {
            /* Turn on the LED */
            //Access - > event.eventData.value;
            //appSnprintf("On\r\n");
        }
        break;

        case CMD_LED_OFF:
        {
            /* Turn off the LED */
            //Access - > event.eventData.value;
            //appSnprintf("Off\r\n");
        }
        break;

        case CMD_LED_TOGGLE:
        {
            /* Toggle the LED */
            //Access - > event.eventData.value;
            //appSnprintf("Toggle\r\n");
        }
        break;
        case CMD_LED_BRIGHTNESS:
        {
            /* Set the given LED brightness */
            //Access - > event.eventData.value;
            //appSnprintf("Led Brightness \r\n");
            RGB_LED_SetBrightnessLevel(event.eventData.value);            
        }
        break;

        case CMD_LED_COLOR_HS:
        {
            /* LED Hue , Saturation */
            //Access - > event.eventData.colorHS.hue;
            //Access - > event.eventData.colorHS.saturation;
            //appSnprintf("LED Hue , Saturation \r\n");
           RGB_LED_SetLedColorHS(event.eventData.colorHS.hue, event.eventData.colorHS.saturation);            
        }
        break;

        case CMD_LED_COLOR_XY:
        {
            /* Set the LED Color X Y */
            //Access - > event.eventData.colorXY.x;
            //Access - > event.eventData.colorXY.y;
            //appSnprintf("LED X,Y Color \r\n");
            RGB_LED_SetLedColorXY(event.eventData.colorXY.x, event.eventData.colorXY.y);            
        }
        break;

        case CMD_BUTTON_OPEN:
        {
            /* Button Init */
            //appSnprintf("Button Init/Open \r\n");
        }
        break;

        case CMD_BUTTON_READ:
        {
            /* Button Press */
            //Access - > event.eventData.state;
            //appSnprintf("Button Read \r\n");
        }
        break;

        case CMD_SENSOR_OPEN:
        {
            /* Sensor Data */
            //appSnprintf("Sensor Open /Init Event \r\n");
        }        
        break;

        case CMD_SENSOR_READ:
        {
            /* Sensor Data */
            //Access - > event.eventData.data;
            //appSnprintf("Sensor Read Event \r\n");
        }        
        break;
		
		case CMD_BUTTON_LONG_PRESS:
        {
            /* Button long press */
        }
		break;

        default:
        break;
    }
}

/*******************************************************************************
  Function:
    void Zigbee_Event_Handler(APP_Zigbee_Event_t event)

  Remarks:
    See prototype in app_zigbee_handler.h.
******************************************************************************/

void Zigbee_Event_Handler(APP_Zigbee_Event_t event)
{
    // User to handle all zigbee stack events  
    switch(event.eventId)
    {
        case EVENT_NETWORK_ESTABLISHED:
        {
            appSnprintf("Network Established\r\n");
        }
        break;
        case EVENT_DISCONNECTED:
        {
            appSnprintf("Disconnected from the Network\r\n");
        }
        break;
        case EVENT_COMMISSIONING_STARTED:
        {
            appSnprintf("Commissioning Procedure Started - 180 Seconds \r\n");
            appSnprintf("Commissioning Sequence: ");
            appSnprintf("Formation->");
            appSnprintf("Steering->");
            appSnprintf("Find & Bind->");
            appSnprintf("\r\n");
        }
        break;

        case EVENT_COMMISSIONING_COMPLETE:
        {
            appSnprintf("Commissioning Procedure Complete \r\n");
        }
        break;
        case EVENT_COMMISSIONING_FORMATION_COMPLETE:
        {
            appSnprintf("Nwk Formation: ");
            if(event.eventData.value == BDB_COMMISSIONING_SUCCESS)
                appSnprintf("Success\r\n");
            else //BDB_COMMISSIONING_FORMATION_FAILURE
                appSnprintf("Failed\r\n");
        }
        break;
        case EVENT_COMMISSIONING_STEERING_COMPLETE:
        {
            appSnprintf("Steering: ");
            if(event.eventData.value == BDB_COMMISSIONING_NO_NETWORK)
                appSnprintf("No networks found to join\r\n");
            else if(event.eventData.value == BDB_COMMISSIONING_SUCCESS)
                appSnprintf("Success\r\n");
            else
                appSnprintf("Failed\r\n");
        }
        break;
        case EVENT_COMMISSIONING_TOUCHLINK_COMPLETE:
        {
            appSnprintf("Touchlink: Attempt: ");
            if(event.eventData.value == BDB_COMMISSIONING_NO_SCAN_RESPONSE)
                appSnprintf("No scan response\r\n");
            else if(event.eventData.value == BDB_COMMISSIONING_SUCCESS)
                appSnprintf("Success\r\n");
            else
                appSnprintf("Failed\r\n");
        }
        break;
        case EVENT_COMMISSIONING_FINDBIND_COMPLETE:
        {
            appSnprintf("Finding & Binding: ");
            if(event.eventData.value == BDB_COMMISSIONING_NO_IDENTIFY_QUERY_RESPONSE)
              appSnprintf("No identify Query Response\r\n");
            else if(event.eventData.value == BDB_COMMISSIONING_BINDING_TABLE_FULL)
              appSnprintf("Binding table full\r\n");
            else if(event.eventData.value == BDB_COMMISSIONING_SUCCESS)
              appSnprintf("Success\r\n");
            else
              appSnprintf("Failed\r\n");
        }
        break;
        case EVENT_COMMISSIONING_FAILURE:
        {
          switch(event.eventData.value)
          {
              case BDB_COMMISSIONING_NO_NETWORK:
              {
                  //appSnprintf("No network found in search\r\n");
              }
              break;
              case BDB_COMMISSIONING_NOT_SUPPORTED:
              {
                  appSnprintf("Commissioning: One of the BDB commissioning procedure not supported\r\n");
              }
              break;
              case BDB_COMMISSIONING_NO_SCAN_RESPONSE:
              break;
              case BDB_COMMISSIONING_NO_IDENTIFY_QUERY_RESPONSE:
              break;
              default:
              break;
          }
        }
        break;

        case EVENT_STARTED_CENTRALIZED_NETWORK:
        {
            appSnprintf("Started Centralized Network\r\n");
        }
        break;
        case EVENT_STARTED_DISTRIBUTED_NETWORK:
        {
            appSnprintf("Started Distributed Network\r\n");
        }
        break;
        case EVENT_JOINED_TO_AN_EXISTING_NETWORK:
        {
            appSnprintf("Network Search: Complete: Joined to a Network \r\n");
            appSnprintf("Joined to: Address 0x%04x  MACID 0x%08x%08x ExtendedPANID 0x%08x%08x\r\n", event.eventData.ParentChildInfo.shortAddress, (uint32_t)(event.eventData.ParentChildInfo.extendedAddress >> 32), (uint32_t)(event.eventData.ParentChildInfo.extendedAddress & 0xFFFFFFFF), (uint32_t)(event.eventData.ParentChildInfo.extendedPanId >> 32), (uint32_t)(event.eventData.ParentChildInfo.extendedPanId & 0xFFFFFFFF));
        }
        break;

        case EVENT_WAKEUP:
        {
            //appSnprintf("Wake up Indication \r\n");
        }
        break;

        case EVENT_LEFT_FROM_NETWORK:
        {
            //appSnprintf("Left from the Network \r\n");
        }
        break;

        case EVENT_CHILD_JOINED:
        {
            appSnprintf("Device joined: Address 0x%04x  MACID 0x%08x%08x ExtendedPANID 0x%08x%08x\r\n", event.eventData.ParentChildInfo.shortAddress, (uint32_t)(event.eventData.ParentChildInfo.extendedAddress >> 32), (uint32_t)(event.eventData.ParentChildInfo.extendedAddress & 0xFFFFFFFF), (uint32_t)(event.eventData.ParentChildInfo.extendedPanId >> 32), (uint32_t)(event.eventData.ParentChildInfo.extendedPanId & 0xFFFFFFFF));
        }
        break;

        case EVENT_CHILD_REMOVED:
        {
            appSnprintf("Child Left\r\n");
        }
        break;

        case EVENT_NWK_UPDATE:
        {
            //appSnprintf("Network Information updated \r\n");
        }
        break;

        case EVENT_RESET_TO_FACTORY_DEFAULTS:
        {
            //appSnprintf("Reset To Factory New\r\n");
        }
        break;

        case EVENT_NWK_ADDRESS_RESPONSE:
        {
            if(event.eventData.ParentChildInfo.status == ZCL_SUCCESS_STATUS)
                appSnprintf( "->NwkAddrResponse, status = %d, address = %04x\r\n" ,event.eventData.ParentChildInfo.status, event.eventData.ParentChildInfo.shortAddress);
            else
                appSnprintf( "->NwkAddrResponse, status = %d \r\n" ,event.eventData.ParentChildInfo.status);
        }
        break;

        case EVENT_IEEE_ADDRESS_RESPONSE:
        {
            if(event.eventData.ParentChildInfo.status == ZCL_SUCCESS_STATUS)
                appSnprintf("->IeeeAddrResponse, status = %d, address = 0x%016x \r\n", event.eventData.ParentChildInfo.status,(event.eventData.ParentChildInfo.extendedAddress));
            else
                appSnprintf( "->IeeeAddrResponse, status = %d, address = 0x%016x \r\n", event.eventData.ParentChildInfo.status);
        }
        break;

        case EVENT_SIMPLE_DESCRIPTOR_RESPONSE:
        {
            appSnprintf( "->SimpleDescResponse, status = %d \r\n" ,event.eventData.ParentChildInfo.status);
        }
        break;

        case EVENT_MATCH_DESCRIPTOR_RESPONSE:
        {
            if(event.eventData.ParentChildInfo.status == ZCL_SUCCESS_STATUS)
                appSnprintf( "->MatchDescResponse, status = %d, MatchedEpCount = %d\r\n" ,event.eventData.ParentChildInfo.status, event.eventData.ParentChildInfo.ep);
            else
                appSnprintf( "->MatchDescResponse, status = %d \r\n" ,event.eventData.ParentChildInfo.status);
        }
        break;

        case EVENT_ACTIVE_EP_RESPONSE:
        {
            if(event.eventData.ParentChildInfo.status == ZCL_SUCCESS_STATUS)
                appSnprintf( "->ActiveEpResponse, status = %d, EpCount = %d\r\n" ,event.eventData.ParentChildInfo.status, event.eventData.ParentChildInfo.ep);
            else
                appSnprintf( "->ActiveEpResponse, status = %d \r\n" ,event.eventData.ParentChildInfo.status);
        }
        break;

        case EVENT_NODE_DESCRIPTOR_RESPONSE:
        {
            appSnprintf( "->NodeDescResponse, status = %d \r\n" ,event.eventData.ParentChildInfo.status);
        }
        break;

        case EVENT_LEAVE_RESPONSE:
        {
            appSnprintf( "->LeaveRsp, status = %d \r\n" ,event.eventData.ParentChildInfo.status);
        }
        break;

        case EVENT_MANAGEMENT_BIND_RESPONSE:
        {
            appSnprintf( "MgmtBindRsp %d\r\n", event.eventData.ParentChildInfo.status); 
        }
        break;

        case EVENT_LQI_RESPONSE:
        {
            appSnprintf( "->MgmtLqiRsp, status = %d \r\n" ,event.eventData.ParentChildInfo.status);
        }
        break;

        case EVENT_BIND_RESPONSE:
        {
            appSnprintf( "->BindRsp, status = %d \r\n" ,event.eventData.ParentChildInfo.status);
        }
        break;

        case EVENT_UNBIND_RESPONSE:
        {
            appSnprintf( "->UnBindRsp, status = %d \r\n" ,event.eventData.ParentChildInfo.status);
        }
        break;

        default:
        break;
    }
}

/*******************************************************************************
  Function:
    void Cluster_Event_Handler(APP_Zigbee_Event_t event)

  Remarks:
    See prototype in app_zigbee_handler.h.
******************************************************************************/

void Cluster_Event_Handler(APP_Zigbee_Event_t event)
{
    switch(event.eventId)
    {
        case CMD_ZCL_ON:
        {
            /* ZCL Command ON received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            appSnprintf("On\r\n");
        }
        break;
        case CMD_ZCL_OFF:
        {
            /* ZCL Command Off received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            appSnprintf("Off\r\n");
        }
        break;
        case CMD_ZCL_TOGGLE:
        {
            /* ZCL Command Toggle received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            appSnprintf("Toggle\r\n");
        }
        break;
        case CMD_ZCL_OFF_WITH_EFFECT:
        {
            /* ZCL Command Off with effect received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_OffWithEffect_t *payload = (ZCL_OffWithEffect_t *)event.eventData.zclEventData.payload;
            appSnprintf("OffWithEffect %d 0x%x\r\n", payload->effectIdentifier, payload->effectVariant);
        }
        break;
        case CMD_ZCL_ON_WITH_RECALL_GLOBALSCENE:
        {
            /* ZCL Command on with recall globalscene received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            appSnprintf("OnWithRecallGlobalScene\r\n");
        }
        break;
        case CMD_ZCL_ON_WITH_TIMED_OFF:
        {
            /* ZCL Command on with timed off received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_OnWithTimedOff_t *payload = (ZCL_OnWithTimedOff_t *)event.eventData.zclEventData.payload;
            appSnprintf("OnWithTimedOff %d %d 0x%x\r\n", payload->onOffControl, payload->onTime, payload->offWaitTime);
        }
        break;
        case CMD_ZCL_MOVE_TO_HUE:
        {
            /* ZCL Command Move to Hue received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            appSnprintf("moveToHueInd()\r\n");
        }
        break;
        case CMD_ZCL_MOVE_HUE:
        {
            /* ZCL Command Move Hue received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
           appSnprintf("moveHueInd()\r\n");
        }
        break;
        case CMD_ZCL_STEP_HUE:
        {
            /* ZCL Command Step Hue received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            appSnprintf("stepHueInd()\r\n");
        }
        break;
        case CMD_ZCL_MOVE_TO_SATURATION:
        {
            /* ZCL Command Move to Saturation received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            appSnprintf("moveToSaturationInd()\r\n");
        }
        break;
        case CMD_ZCL_MOVE_SATURATION:
        {
            /* ZCL Command Move Saturation received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            appSnprintf("moveSaturationInd()\r\n");
        }
        break;
        case CMD_ZCL_STEP_SATURATION:
        {
            /* ZCL Command Step Saturation received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            appSnprintf("stepSaturationInd()\r\n");
        }
        break;
        case CMD_ZCL_MOVE_TO_HUE_SATURATION:
        {
            /* ZCL Command Move to Hue Saturation received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            appSnprintf("moveToHueAndSaturationInd()\r\n");
        }
        break;
        case CMD_ZCL_MOVE_TO_COLOR:
        {
            /* ZCL Command Move to Color received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            uint16_t x, y;
            ZCL_ZllMoveToColorCommand_t *payload = (ZCL_ZllMoveToColorCommand_t*)event.eventData.zclEventData.payload;
            x = (MAX_COLOR_LEVEL < payload->colorX) ? MAX_COLOR_LEVEL : payload->colorX;
            y = (MAX_COLOR_LEVEL < payload->colorY) ? MAX_COLOR_LEVEL : payload->colorY;
            appSnprintf("moveToColorInd() X=%d Y=%d\r\n", x,y);
        }
        break;
        case CMD_ZCL_MOVE_COLOR:
        {
            /* ZCL Command Move Color received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            appSnprintf("moveColorInd()\r\n");
        }
        break;
        case CMD_ZCL_STEP_COLOR:
        {
            /* ZCL Command Step Color received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            appSnprintf("stepColorInd()\r\n");
        }
        break;
        case CMD_ZCL_MOVE_TO_COLOR_TEMPERATURE:
        {
            /* ZCL Command Move to Color Temerature received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            appSnprintf("moveToColorTemperatureInd()\r\n");
        }
        break;
        case CMD_ZCL_ENHANCED_MOVE_TO_HUE:
        {
            /* ZCL Command Enhanced Move to Hue received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            appSnprintf("enhancedMoveToHueInd()\r\n");
        }
        break;
        case CMD_ZCL_ENHANCED_MOVE_HUE:
        {
            /* ZCL Command Move Hue received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            appSnprintf("enhancedMoveHueInd()\r\n");
        }
        break;
        case CMD_ZCL_ENHANCED_STEP_HUE:
        {
            /* ZCL Command Step Hue received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            appSnprintf("enhancedStepHueInd()\r\n");
        }
        break;
        case CMD_ZCL_ENHANCED_MOVED_TO_HUE_SATURATION:
        {
            /* ZCL Command Move to Hue Saturation received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            uint16_t saturation;
            ZCL_ZllEnhancedMoveToHueAndSaturationCommand_t *payload = (ZCL_ZllEnhancedMoveToHueAndSaturationCommand_t*)event.eventData.zclEventData.payload;
            saturation = (MAX_SATURATION_LEVEL < payload->saturation) ? MAX_SATURATION_LEVEL : payload->saturation;
            appSnprintf("enhancedMoveToHueAndSaturationInd() Hue=%d Saturation=%d\r\n", payload->enhancedHue,saturation);
        }
        break;
        case CMD_ZCL_COLOR_LOOP_SET:
        {
            /* ZCL Command Color loop Set received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            appSnprintf("colorLoopSetInd()\r\n");
        }
        break;
       case CMD_ZCL_STOP_MOVE_STEP:
        {
            /* ZCL Command ZCL STOP MOVE SET received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
             appSnprintf("stopMoveStepInd()\r\n");
        }
        break;
        case CMD_ZCL_MOVE_COLOR_TEMPERATURE:
        {
            /* ZCL Command Move to Color Temperature received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            appSnprintf("moveColorTemperatureInd()\r\n");
        }
        break;
        case CMD_ZCL_STEP_COLOR_TEMPERATURE:
        {
            /* ZCL Command Step Color Temperature received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            appSnprintf("stepColorTemperatureInd()\r\n");
        }
        break;
        case CMD_ZCL_RESET_TO_FACTORY_DEFAULTS:
        {
            /* Command ZCL ResetToFactoryDefaults */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            //appSnprintf("ZCL ResetToFactoryDefaults\r\n");
        }
        break;
        case CMD_ZCL_IDENTIFY:
        {
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            appSnprintf( "->Identify\r\n");
        }
        break;
        case CMD_ZCL_IDENTIFY_QUERY:
        {
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            //appSnprintf("->IdentifyQuery\r\n");
        }
        break;
        case CMD_ZCL_TRIGGER_EFFECT:
        {
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_TriggerEffect_t *payload = (ZCL_TriggerEffect_t *)event.eventData.zclEventData.payload;
            appSnprintf("->TriggerEffect 0x%x\r\n",  payload->effectIdentifier);
        }
        break;
        case CMD_ZCL_IDENTIFY_QUERY_RESPONSE:
        {
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            //appSnprintf("->IdentifyQueryResponse, addr = 0x%04x, timeout = 0x%04x\r\n", addressing->addr.shortAddress, payload->timeout);
        }
        break;
        case CMD_ZCL_ADD_GROUP:
        {
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_AddGroup_t *payload = (ZCL_AddGroup_t *)event.eventData.zclEventData.payload;
            appSnprintf("addGroupInd(): 0x%04x\r\n", payload->groupId);
        }
        break;
        case CMD_ZCL_VIEW_GROUP:
        {
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_ViewGroup_t *payload = (ZCL_ViewGroup_t *)event.eventData.zclEventData.payload;
            appSnprintf("viewGroupInd(): 0x%04x\r\n", payload->groupId);
        }
        break;
        case CMD_ZCL_GET_GROUP_MEMBERSHIP:
        {
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload; 
            appSnprintf("getGroupMembershipInd()\r\n");
        }
        break;
        case CMD_ZCL_REMOVE_GROUP:
        {
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_RemoveGroup_t *payload = (ZCL_RemoveGroup_t *)event.eventData.zclEventData.payload;
            appSnprintf("removeGroupInd(): 0x%04x\r\n", payload->groupId);
        }
        break;
        case CMD_ZCL_REMOVE_ALL_GROUP:
        {
            //Access - > event.eventData.zclAttributeData.addressing;
            //Access - > event.eventData.zclAttributeData.attributeId;
            //Access - > event.eventData.zclAttributeData.event;
            appSnprintf( "removeAllGroupsInd()\r\n");
        }
        break;
        case CMD_ZCL_ADD_GROUP_IF_IDENTIFYING:
        {
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_AddGroupIfIdentifying_t *payload = (ZCL_AddGroupIfIdentifying_t *)event.eventData.zclEventData.payload;
            appSnprintf("addGroupIfIdentifyingInd(): 0x%04x\r\n", payload->groupId);
        }
        break;
        case CMD_ZCL_ADD_GROUP_RESPONSE:
        {
            //Access - > event.eventData.zclAttributeData.addressing;
            //Access - > event.eventData.zclAttributeData.attributeId;
            //Access - > event.eventData.zclAttributeData.event;
            appSnprintf("addGroupResponseInd()\r\n");
        }
        break;
        case CMD_ZCL_VIEW_GROUP_RESPONSE:
        {
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_ViewGroupResponse_t *payload = (ZCL_ViewGroupResponse_t *)event.eventData.zclEventData.payload;
            appSnprintf("viewGroupResponse(): status = 0x%02x\r\n", payload->status);
            appSnprintf("groupId = 0x%04x\r\n", payload->groupId);
        }
        break;
        case CMD_ZCL_GET_GROUP_MEMBERSHIP_RESPONSE:
        {
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_GetGroupMembershipResponse_t *payload = (ZCL_GetGroupMembershipResponse_t *)event.eventData.zclEventData.payload;
            appSnprintf("getGroupMembershipResponse()\r\n");
            appSnprintf("groupCount = %d\r\n", payload->groupCount);
            for (uint8_t i = 0; i < payload->groupCount; i++)
              appSnprintf("groupId = 0x%04x\r\n", payload->groupList[i]);
        }
        break;
        case CMD_ZCL_REMOVE_GROUP_RESPONSE:
        {
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_RemoveGroupResponse_t *payload = (ZCL_RemoveGroupResponse_t *)event.eventData.zclEventData.payload;
            appSnprintf("removeGroupResponseInd()\r\n");
            appSnprintf("groupId = 0x%04x\r\n", payload->groupId);

        }
        break;
        case CMD_ZCL_MOVE_TO_LEVEL:
        {
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_MoveToLevel_t *payload = (ZCL_MoveToLevel_t *)event.eventData.zclEventData.payload;
            appSnprintf("->MoveToLevel: lvl=0x%x trTime=%u\r\n", ((ZCL_MoveToLevel_t *)payload)->level, ((ZCL_MoveToLevel_t *)payload)->transitionTime);
        }
        break;
        case CMD_ZCL_MOVE:
        {
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_Move_t *payload = (ZCL_Move_t *)event.eventData.zclEventData.payload;
            appSnprintf("->Move: mode=0x%x rate=0x%x\r\n", ((ZCL_Move_t*)payload)->moveMode, ((ZCL_Move_t*)payload)->rate);
        }
        break;
        case CMD_ZCL_STEP:
        {
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_Step_t *payload = (ZCL_Step_t *)event.eventData.zclEventData.payload;
            appSnprintf( "->Step: mode=0x%x stepSize=0x%x trTime=%u\r\n", ((ZCL_Step_t *)payload)->stepMode, ((ZCL_Step_t *)payload)->stepSize, ((ZCL_Step_t *)payload)->transitionTime);
        }
        break;
        case CMD_ZCL_STOP:
        {
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            appSnprintf("->Stop\r\n");
        }
        break;
        case CMD_ZCL_MOVE_TO_LEVEL_WITH_ONOFF:
        {
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_MoveToLevelWithOnOff_t *payload = (ZCL_MoveToLevelWithOnOff_t *)event.eventData.zclEventData.payload;
            appSnprintf("->MoveToLevelWithOnOff: lvl=0x%x trTime=%u\r\n", ((ZCL_MoveToLevelWithOnOff_t*)payload)->level, ((ZCL_MoveToLevelWithOnOff_t*)payload)->transitionTime);
        }
        break;
        case CMD_ZCL_MOVE_WITH_ONOFF:
        {
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_MoveWithOnOff_t *payload = (ZCL_MoveWithOnOff_t *)event.eventData.zclEventData.payload;
            appSnprintf("->Move with on/off: mode=0x%x rate=0x%x\r\n", ((ZCL_MoveWithOnOff_t*)payload)->moveMode, ((ZCL_MoveWithOnOff_t*)payload)->rate);
        }
        break;
        case CMD_ZCL_STEP_WITH_ONOFF:
        {
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_StepWithOnOff_t *payload = (ZCL_StepWithOnOff_t *)event.eventData.zclEventData.payload;
            appSnprintf("->Step with on/off: mode=0x%x stepSize=0x%x trTime=%u\r\n", ((ZCL_StepWithOnOff_t*)payload)->stepMode, ((ZCL_StepWithOnOff_t*)payload)->stepSize, ((ZCL_StepWithOnOff_t*)payload)->transitionTime);
        }
        break;
        case CMD_ZCL_STOP_WITH_ONOFF:
        {
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            appSnprintf("->Stop with on/off\r\n");
        }
        break;
        case CMD_ZCL_ADD_SCENE:
        {
            /* ZCL Command add scene received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_AddScene_t *cmd =((ZCL_AddScene_t*)event.eventData.zclEventData.payload);
            appSnprintf("addSceneInd(): 0x%04x, 0x%02x\r\n", cmd->groupId, cmd->sceneId);
        }
        break;
        case CMD_ZCL_VIEW_SCENE:
        {
            /* ZCL Command view scene received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_ViewScene_t *cmd = ((ZCL_ViewScene_t*)event.eventData.zclEventData.payload);
            appSnprintf("viewSceneInd(): 0x%04x, 0x%02x\r\n", cmd->groupId, cmd->sceneId);
        }
        break;
        case CMD_ZCL_ENHANCED_ADD_SCENE:
        {
            /* ZCL Command enhanced add scene received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_EnhancedAddScene_t *cmd = ((ZCL_EnhancedAddScene_t*)event.eventData.zclEventData.payload);
            appSnprintf("enhancedAddSceneInd(): 0x%04x, 0x%02x\r\n", cmd->groupId, cmd->sceneId);
        }
        break;
        case CMD_ZCL_ENHANCED_VIEW_SCENE:
        {
            /* ZCL Command enhanced view scene received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_EnhancedViewScene_t *cmd = ((ZCL_EnhancedViewScene_t*)event.eventData.zclEventData.payload);
            appSnprintf("enhancedViewSceneInd(): 0x%04x, 0x%02x\r\n", cmd->groupId, cmd->sceneId);
        }
        break;
        case CMD_ZCL_REMOVE_SCENE:
        {
            /* ZCL Command remove scene received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_RemoveScene_t *cmd = ((ZCL_RemoveScene_t*)event.eventData.zclEventData.payload);
            appSnprintf("removeSceneInd(): 0x%04x, 0x%02x\r\n", cmd->groupId, cmd->sceneId);
        }
        break;
        case CMD_ZCL_REMOVE_ALL_SCENES:
        {
            /* ZCL Command remove all scenes received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_RemoveAllScenes_t *cmd = ((ZCL_RemoveAllScenes_t*)event.eventData.zclEventData.payload);
            appSnprintf("removeAllScenesInd(): 0x%04x\r\n", cmd->groupId);
        }
        break;
        case CMD_ZCL_STORE_SCENE:
        {
            /* ZCL Command store scene received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_StoreScene_t *cmd = ((ZCL_StoreScene_t*)event.eventData.zclEventData.payload);
            appSnprintf("storeSceneInd(): 0x%04x, 0x%x\r\n", cmd->groupId, cmd->sceneId);
        }
        break;
        case CMD_ZCL_RECALL_SCENE:
        {
            /* ZCL Command recall scene received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_RecallScene_t *cmd = ((ZCL_RecallScene_t *)event.eventData.zclEventData.payload);
            appSnprintf("recallSceneInd(): 0x%04x, 0x%x\r\n", cmd->groupId, cmd->sceneId);
        }
        break;
        case CMD_ZCL_GET_SCENE_MEMBERSHIP:
        {
            /* ZCL Command get scene membership received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_GetSceneMembership_t *cmd = ((ZCL_GetSceneMembership_t *)event.eventData.zclEventData.payload);
            appSnprintf("getSceneMembershipInd(): 0x%04x\r\n", cmd->groupId);
        }
        break;
        case CMD_ZCL_COPY_SCENE:
        {
            /* ZCL Command get scene membership received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_GetSceneMembership_t *cmd = ((ZCL_GetSceneMembership_t *)event.eventData.zclEventData.payload);
            appSnprintf("copySceneInd()\r\n");
        }
        break;
        case CMD_ZCL_ADD_SCENE_RESP:
        {
            /* ZCL Command Add scene response received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_AddSceneResponse_t *resp = ((ZCL_AddSceneResponse_t*)event.eventData.zclEventData.payload);
            appSnprintf("Add scene response: status = 0x%02x\r\n", resp->status);
            appSnprintf("groupId = 0x%04x\r\n", resp->groupId);
            appSnprintf("sceneId = 0x%02x\r\n", resp->sceneId);
        }
        break;
        case CMD_ZCL_VIEW_SCENE_RESP:
        {
            /* ZCL Command View scene response received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_ViewSceneResponse_t *resp = ((ZCL_ViewSceneResponse_t*)event.eventData.zclEventData.payload);
            appSnprintf("View scene response: status = 0x%02x\r\n", resp->status);
            appSnprintf( "groupId = 0x%04x\r\n", resp->groupId);
            appSnprintf("sceneId = 0x%02x\r\n", resp->sceneId);
            appSnprintf("transitionTime = 0x%04x\r\n", resp->transitionTime);
        }
        break;
        case CMD_ZCL_REMOVE_SCENE_RESP:
        {
            /* ZCL Command remove scene response received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_RemoveSceneResponse_t *resp = ((ZCL_RemoveSceneResponse_t*)event.eventData.zclEventData.payload);
            appSnprintf("Remove scene response: status = 0x%02x\r\n",resp->status);
            appSnprintf("groupId = 0x%04x\r\n", resp->groupId);
            appSnprintf("sceneId = 0x%02x\r\n", resp->sceneId);
        }
        break;
        case CMD_ZCL_REMOVE_ALL_SCENES_RESP:
        {
            /* ZCL Command remove all scenes response received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_RemoveAllScenesResponse_t *resp = ((ZCL_RemoveAllScenesResponse_t*)event.eventData.zclEventData.payload);
            appSnprintf("Remove all scenes response: status = 0x%02x\r\n", resp->status);
            appSnprintf("groupId = 0x%04x\r\n", resp->groupId);
        }
        break;
        case CMD_ZCL_STORE_SCENE_RESP:
        {
            /* ZCL Command store scene response received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_StoreSceneResponse_t *resp = ((ZCL_StoreSceneResponse_t*)event.eventData.zclEventData.payload);
            appSnprintf("Store scene response: status = 0x%02x\r\n",resp->status);
            appSnprintf("groupId = 0x%04x\r\n", resp->groupId);
            appSnprintf("sceneId = 0x%02x\r\n", resp->sceneId);
        }
        break;
        case CMD_ZCL_GET_SCENE_MEMBERSHIP_RESP:
        {
            /* ZCL Command get scene membership response received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_GetSceneMembershipResponse_t *resp = ((ZCL_GetSceneMembershipResponse_t*)event.eventData.zclEventData.payload);
            appSnprintf("Get scene membership response: status = 0x%02x\r\n", resp->status);
            appSnprintf("groupId = 0x%04x\r\n", resp->groupId);
            appSnprintf("sceneCount = 0x%02x\r\n", resp->sceneCount);
            for (uint8_t i = 0; i < resp->sceneCount; i++)
              appSnprintf("sceneId = 0x%02x\r\n", resp->sceneList[i]);
        }
        break;
        case CMD_ZCL_ENHANCED_ADD_SCENE_RESP:
        {
            /* ZCL Command enhanced Add scene response received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_EnhancedAddSceneResponse_t *resp = (ZCL_EnhancedAddSceneResponse_t *)(event.eventData.zclEventData.payload);
            appSnprintf("Enhanced add scene response: status = 0x%02x\r\n", resp->status);
            appSnprintf("groupId = 0x%04x\r\n", resp->groupId);
            appSnprintf("sceneId = 0x%02x\r\n", resp->sceneId);
        }
        break;
        case CMD_ZCL_ENHANCED_VIEW_SCENE_RESP:
        {
            /* ZCL Command enhanced view scene response received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_EnhancedViewSceneResponse_t *resp = ((ZCL_EnhancedViewSceneResponse_t *)(event.eventData.zclEventData.payload));
            appSnprintf("Enhanced view scene response: status = 0x%02x\r\n", resp->status);
            appSnprintf("groupId = 0x%04x\r\n", resp->groupId);
            appSnprintf("sceneId = 0x%02x\r\n", resp->sceneId);
            appSnprintf("transitionTime = 0x%04x\r\n", resp->transitionTime);
        }
        break;
        case CMD_ZCL_COPY_SCENE_RESP:
        {
            /* ZCL Command copy scene response received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_CopySceneResponse_t *resp = ((ZCL_CopySceneResponse_t*)event.eventData.zclEventData.payload);
            appSnprintf("Copy scene response: status = 0x%02x\r\n", resp->status);
        }
        break;
        case CMD_ZCL_ATTR_COLOR_CONTROL:
        {
            /* Command ZCL ColorControlAttributeEventInd */
            //Access - > event.eventData.zclAttributeData.addressing;
            //Access - > event.eventData.zclAttributeData.attributeId;
            //Access - > event.eventData.zclAttributeData.event;
            //appSnprintf("ZCL ColorControlAttributeEventInd\r\n");
           if(ZCL_CONFIGURE_DEFAULT_ATTRIBUTE_REPORTING_EVENT == event.eventData.zclAttributeData.event)
           {
            switch(event.eventData.zclAttributeData.attributeId)
            {
            case ZCL_ZLL_CLUSTER_CURRENT_HUE_SERVER_ATTRIBUTE_ID:
                customColorControlClusterServerAttributes.currentHue.minReportInterval = COLOR_CONTROL_CUURENT_HUE_MIN_REPORT_PERIOD;
                customColorControlClusterServerAttributes.currentHue.maxReportInterval = COLOR_CONTROL_CUURENT_HUE_MAX_REPORT_PERIOD;
                customColorControlClusterServerAttributes.currentHue.reportableChange  = 0;
            break;

            case ZCL_ZLL_CLUSTER_CURRENT_SATURATION_SERVER_ATTRIBUTE_ID:
                customColorControlClusterServerAttributes.currentSaturation.minReportInterval = COLOR_CONTROL_CURRENT_SAT_MIN_REPORT_PERIOD;
                customColorControlClusterServerAttributes.currentSaturation.maxReportInterval = COLOR_CONTROL_CURRENT_SAT_MAX_REPORT_PERIOD;
                customColorControlClusterServerAttributes.currentSaturation.reportableChange  = 0;
            break;

            case ZCL_ZLL_CLUSTER_CURRENT_X_SERVER_ATTRIBUTE_ID:
                customColorControlClusterServerAttributes.currentX.minReportInterval = COLOR_CONTROL_CURR_X_MIN_REPORT_PERIOD;
                customColorControlClusterServerAttributes.currentX.maxReportInterval = COLOR_CONTROL_CURR_X_MAX_REPORT_PERIOD;
                customColorControlClusterServerAttributes.currentX.reportableChange  = 0;
            break;

            case ZCL_ZLL_CLUSTER_CURRENT_Y_SERVER_ATTRIBUTE_ID:
                customColorControlClusterServerAttributes.currentY.minReportInterval = COLOR_CONTROL_CURR_Y_MIN_REPORT_PERIOD;
                customColorControlClusterServerAttributes.currentY.maxReportInterval = COLOR_CONTROL_CURR_Y_MAX_REPORT_PERIOD;
                customColorControlClusterServerAttributes.currentY.reportableChange  = 0;
            break;

            case ZCL_ZLL_CLUSTER_COLOR_TEMPERATURE_SERVER_ATTRIBUTE_ID:
                customColorControlClusterServerAttributes.colorTemperature.minReportInterval = COLOR_CONTROL_COLOR_TEMP_MIN_REPORT_PERIOD;
                customColorControlClusterServerAttributes.colorTemperature.maxReportInterval = COLOR_CONTROL_COLOR_TEMP_MAX_REPORT_PERIOD;
                customColorControlClusterServerAttributes.colorTemperature.reportableChange  = 0;
            break;
            default:
              break;
        }
           }
        }
        break;
        case CMD_ZCL_ATTR_IDENTIFY:
        {
            /* Command ZCL IdentifyAttributeEventInd */ 
            //Access - > event.eventData.zclAttributeData.addressing;
            //Access - > event.eventData.zclAttributeData.attributeId;
            //Access - > event.eventData.zclAttributeData.event;
            //appSnprintf("ZCL IdentifyAttributeEventInd\r\n");
        }
        break;
        case CMD_ZCL_ATTR_LEVEL_CONTROL:
        {
            /* Command ZCL LevelControlAttributeEventInd */
            //Access - > event.eventData.zclAttributeData.addressing;
            //Access - > event.eventData.zclAttributeData.attributeId;
            //Access - > event.eventData.zclAttributeData.event;
            ZCL_AttributeEvent_t eventzcl = event.eventData.zclAttributeData.event;
            ZCL_AttributeId_t attributeId = event.eventData.zclAttributeData.attributeId;    
            if((ZCL_CONFIGURE_DEFAULT_ATTRIBUTE_REPORTING_EVENT == eventzcl) && \
                (ZCL_LEVEL_CONTROL_CLUSTER_CURRENT_LEVEL_ATTRIBUTE_ID == attributeId))
            {
                customLevelControlClusterServerAttributes.currentLevel.minReportInterval = LEVEL_CONTROL_VAL_MIN_REPORT_PERIOD;
                customLevelControlClusterServerAttributes.currentLevel.maxReportInterval = LEVEL_CONTROL_VAL_MAX_REPORT_PERIOD;
                customLevelControlClusterServerAttributes.currentLevel.reportableChange  = 0;
            }
        }
        break;
        case CMD_ZCL_ATTR_ONOFF:
        {
            /* Command ZCL OnOffAttributeEventInd */
            //Access - > event.eventData.zclAttributeData.addressing;
            //Access - > event.eventData.zclAttributeData.attributeId;
            //Access - > event.eventData.zclAttributeData.event; 
            ZCL_AttributeEvent_t eventzcl = event.eventData.zclAttributeData.event;
            ZCL_AttributeId_t attributeId = event.eventData.zclAttributeData.attributeId;  
            if((ZCL_CONFIGURE_DEFAULT_ATTRIBUTE_REPORTING_EVENT == eventzcl) && \
                (ZCL_ONOFF_CLUSTER_ONOFF_SERVER_ATTRIBUTE_ID == attributeId))
            {
                customOnOffClusterServerAttributes.onOff.minReportInterval = ONOFF_VAL_MIN_REPORT_PERIOD;
                customOnOffClusterServerAttributes.onOff.maxReportInterval = ONOFF_VAL_MAX_REPORT_PERIOD;
                customOnOffClusterServerAttributes.onOff.reportableChange  = 0;
            }
        }
        break;
        case CMD_ZCL_ATTR_OCCUPANCY:
        {
            /* Command ZCL OccupancyAttributeEventInd */
            //Access - > event.eventData.zclAttributeData.addressing;
            //Access - > event.eventData.zclAttributeData.attributeId;
            //Access - > event.eventData.zclAttributeData.event;
            ZCL_AttributeEvent_t eventzcl = event.eventData.zclAttributeData.event;
            ZCL_AttributeId_t attributeId = event.eventData.zclAttributeData.attributeId;
            if ((ZCL_CONFIGURE_DEFAULT_ATTRIBUTE_REPORTING_EVENT == eventzcl) && \
                (ZCL_OCCUPANCY_SENSING_CLUSTER_OCCUPANCY_SERVER_ATTRIBUTE_ID == attributeId))
            {
                appSnprintf("<-Occupancy Sensor Attr Value Changed: Value = 0x%x\r\n", (int)customOccupancySensingClusterServerAttributes.occupancy.value); //test occupancy value
                customOccupancySensingClusterServerAttributes.occupancy.minReportInterval = OCCUPANCY_SENSING_VAL_MIN_REPORT_PERIOD;
                customOccupancySensingClusterServerAttributes.occupancy.maxReportInterval = OCCUPANCY_SENSING_VAL_MAX_REPORT_PERIOD;
                customOccupancySensingClusterServerAttributes.occupancy.reportableChange = 0;     
            }
        }
        break;
        case CMD_ZCL_REPORTING_ONOFF:
        {
            /* Command ZCL OnOffReportInd */
            //Access - > event.eventData.zclAttributeData.addressing;
            //Access - > event.eventData.zclAttributeData.payloadLength;
            //Access - > event.eventData.zclAttributeData.payload;
            ZCL_Report_t *rep = (ZCL_Report_t *)event.eventData.zclEventData.payload;
            appSnprintf("<-On/Off Attr Report: Value = 0x%x\r\n", (int)rep->value[0]);
        }
        break;
        case CMD_ZCL_REPORTING_LEVEL:
        {
            /* Command ZCL LevelReportInd( */
            //Access - > event.eventData.zclAttributeData.addressing;
            //Access - > event.eventData.zclAttributeData.payloadLength;
            //Access - > event.eventData.zclAttributeData.payload;
            ZCL_Report_t *rep = (ZCL_Report_t *)event.eventData.zclEventData.payload;
            appSnprintf("<-Level Control Attr Report: Value = 0x%x\r\n", (int)rep->value[0]);
        }
        break;
        case CMD_ZCL_REPORTING_COLOR_CONTROL:
        {
            /* ZCL Command ZCL STOP MOVE SET received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            do  //Possibilities of getting more than one report at a time.
            {
                ZCL_Report_t *rep = (ZCL_Report_t *)(event.eventData.zclEventData.payload);
                uint16_t reportValue = 0;
                if(rep->type == ZCL_U8BIT_DATA_TYPE_ID)
                {
                    memcpy(&reportValue, (event.eventData.zclEventData.payload+ sizeof(ZCL_AttributeId_t)+ sizeof(rep->type)), sizeof(uint8_t));
                }
                else
                {
                    memcpy(&reportValue, (event.eventData.zclEventData.payload+ sizeof(ZCL_AttributeId_t)+ sizeof(rep->type)), sizeof(uint16_t));
                }
                appSnprintf("<-Color Control Attr (0x%x) Report: Value = 0x%x\r\n", (unsigned)rep->id, reportValue);
                
                if((event.eventData.zclEventData.payloadLength >= 4))
                {
                    if(rep->type == ZCL_U8BIT_DATA_TYPE_ID)//Attribute data is of 1 byte
                    {
                        event.eventData.zclEventData.payloadLength = event.eventData.zclEventData.payloadLength - sizeof(uint32_t);  // Skip the first report 
                        event.eventData.zclEventData.payload = (event.eventData.zclEventData.payload)+ sizeof(uint32_t);             // Align the pointer to read next        
                    }
                    else // Attribute data is of 2 byte
                    {
                        event.eventData.zclEventData.payloadLength = event.eventData.zclEventData.payloadLength - sizeof(uint32_t) - sizeof(uint8_t); // Skip the first report 
                        event.eventData.zclEventData.payload = (event.eventData.zclEventData.payload) + sizeof(uint32_t) + sizeof(uint8_t);          // Align the pointer to read next            
                    }
               }
            }while(event.eventData.zclEventData.payloadLength);   
        }
        break;
        case CMD_ZCL_REPORTING_OCCUPANCY:
        {
            /* Command ZCL LevelReportInd( */
            //Access - > event.eventData.zclAttributeData.addressing;
            //Access - > event.eventData.zclAttributeData.payloadLength;
            //Access - > event.eventData.zclAttributeData.payload;
            ZCL_Report_t *rep = (ZCL_Report_t *)event.eventData.zclEventData.payload;
            appSnprintf("<-Occupancy Sensor Attr Report: Value = 0x%x\r\n", (int)rep->value[0]);
        }
        break;
        
        //Custom Clusters       



        default:
        break;
    }
}