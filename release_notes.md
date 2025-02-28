---
title: Release notes
nav_order: 99
---

![Microchip logo](https://raw.githubusercontent.com/wiki/Microchip-MPLAB-Harmony/Microchip-MPLAB-Harmony.github.io/images/microchip_logo.png)
![Harmony logo small](https://raw.githubusercontent.com/wiki/Microchip-MPLAB-Harmony/Microchip-MPLAB-Harmony.github.io/images/microchip_mplab_harmony_logo_small.png)

# Microchip MPLABÂ® Harmony 3 Release Notes

## Harmony 3 Wireless BLE, Zigbee, and IEEE 802.15.4 MAC Application example for PIC32CXBZ family  **v2.0.0**

### Development kit and demo application support

Following table provides number of Wireless examples available for different development kits.

| Development Kits           | MPLABx applications |
|:--------------------------:|:-------------------:|
| WBZ451 Curiosity Board 	 |       12            |

### New Features
- WBZ451 BLE Central Transparent UART based code PHY for Long range BLE Application.
- WBZ451 BLE Peripheral HID Profile support BLE Keyboard Application.
- WBZ451 BLE Peripheral ANCS(Apple Notification Center Service client) profile for Notification Provider (NP) such as iPhone application.
- WBZ451 BLE Peripheral Pathloss threshold RSSI based Application.
- WBZ451 BLE Peripheral Transparent UART based code PHY for Long range BLE Application.
- WBZ451 BLE Peripheral Multiple Advertising Sets (Two Set Advertising) Application.
- WBZ451 Zigbee Custom Device type Application.
- WBZ451 Zigbee Custom Cluster Server Application.
- WBZ451 Zigbee Custom Cluster Client Application.
- WBZ451 Zigbee Custom Occupancy Light Clinet Application.
- WBZ451 Zigbee Multisensor DeepSleep Application.
- WBZ451 IEEE 802.15.4 MAC Harmony compoenent based application.

### Bug fixes and Improvements
- New applications release.

### Known Issues
- False Positive MISRA C deviations - 12 (MISRA C-2012 Rule 8.6 & MISRA C-2012 Rule 17.7)

### Limitations
- None

### Development Tools

- [MPLABÂ® X IDE v6.15](https://www.microchip.com/mplab/mplab-x-ide)
- MPLABÂ® X IDE plug-ins:
  - MPLABÂ® Code Configurator (MCC) `v5.3.7`
- [MPLABÂ® XC32 C/C++ Compiler v4.35](https://www.microchip.com/mplab/compilers)
- **PIC32CXBZ Family - DFP 1.1.230 or above version**


--------------------------------------------------------------------------------------------------------------------
# Microchip MPLABÂ® Harmony 3 Release Notes

## Harmony 3 Wireless IEEE 802.15.4 P2P Phy Application example for PIC32CXBZ family  **v1.2.0**

### Development kit and demo application support

Following table provides number of Wireless examples available for different development kits.

| Development Kits           | MPLABx applications |
|:--------------------------:|:-------------------:|
| WBZ451 Curiosity Board |       1            |

### New Features
- WBZ451 IEEE 802.15.4 Standalone PHY Harmony compoenent based P2P Phy application.

### Bug fixes and Improvements
- New applications release.

### Known Issues
- False Positive MISRA C deviations - 12 (MISRA C-2012 Rule 8.6 & MISRA C-2012 Rule 17.7)

### Limitations
- In IEEE 802.15.4 Standalone PHY based P2P Phy application, while using Data Mode, max data bytes/payload limit is 232 bytes (due to SYS CONSOLE Component limitation).

### Development Tools

- [MPLABÂ® X IDE v6.05](https://www.microchip.com/mplab/mplab-x-ide)
- MPLABÂ® X IDE plug-ins:
  - MPLABÂ® Code Configurator (MCC) `v5.2.2`
- [MPLABÂ® XC32 C/C++ Compiler v4.20](https://www.microchip.com/mplab/compilers)
- **DFP 1.1.218 or above version**


--------------------------------------------------------------------------------------------------------------------
# Microchip MPLABÂ® Harmony 3 Release Notes

## Harmony 3 Wireless Zigbee application examples for PIC32CXBZ family  **v1.1.0**

### Development kit and demo application support

Following table provides number of Wireless examples available for different development kits.

| Development Kits           | MPLABx applications |
|:--------------------------:|:-------------------:|
| WBZ451 Curiosity Board |       6            |

### New Features
- WBZ451 ZigBee applications.
- WBZ451 BLE and ZigBee Combo applications.
- WBZ451 IEEE 802.15.4 Standalone PHY Harmony compoenent based P2P Phy application.

### Bug fixes and Improvements
- New applications release.


### Known Issues
- In the Zigbee Multisensor application, System sleep Implementation source(device_sleep.c) and header(device_sleep.h) files are may not be included sometimes when regenerating the project through MCC. Work Around is remove and add the Zigbee multisensor component again in the MCC configuration.

### Development Tools

- [MPLABÂ® X IDE v6.00](https://www.microchip.com/mplab/mplab-x-ide)
- MPLABÂ® X IDE plug-ins:
  - MPLABÂ® Code Configurator (MCC) `v5.1.9`
- [MPLABÂ® XC32 C/C++ Compiler v4.10](https://www.microchip.com/mplab/compilers)
- **DFP 1.0.107 or above version**


--------------------------------------------------------------------------------------------------------------------
# Microchip MPLABÂ® Harmony 3 Release Notes

## Harmony 3 Wireless BLE application examples for PIC32CXBZ family  **v1.0.0**

### Development kit and demo application support

Following table provides number of Wireless examples available for different development kits.

| Development Kits           | MPLABx applications |
|:--------------------------:|:-------------------:|
| WBZ451 Curiosity Board |       16            |

### New Features
- WBZ451 BLE advanced applications.
- WBZ451 BLE building block applications.

### Bug fixes and Improvements
- New applications release.


### Known Issues
- In the DeepSleep application, System sleep Implementation source(device_sleep.c) and header(device_sleep.h) files are may not be included sometimes when regenerating the project through MCC. Work Around is provided in the DeepSleep application document.

### Development Tools

- [MPLABÂ® X IDE v6.00](https://www.microchip.com/mplab/mplab-x-ide)
- MPLABÂ® X IDE plug-ins:
  - MPLABÂ® Code Configurator (MCC) `v5.1.9`
- [MPLABÂ® XC32 C/C++ Compiler v4.10](https://www.microchip.com/mplab/compilers)
- **DFP 1.0.107 or above version**
