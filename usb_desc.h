/* Modifications
 * Copyright (c) 2015-2019, CryptoTrust LLC.
 * All rights reserved.
 * 
 * Author : Tim Steiner <t@crp.to>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials provided
 *    with the distribution.
 *
 * 3. All advertising materials mentioning features or use of this
 *    software must display the following acknowledgment:
 *    "This product includes software developed by CryptoTrust LLC. for
 *    the OnlyKey Project (https://www.crp.to/ok)"
 *
 * 4. The names "OnlyKey" and "CryptoTrust" must not be used to
 *    endorse or promote products derived from this software without
 *    prior written permission. For written permission, please contact
 *    admin@crp.to.
 *
 * 5. Products derived from this software may not be called "OnlyKey"
 *    nor may "OnlyKey" or "CryptoTrust" appear in their names without
 *    specific prior written permission. For written permission, please
 *    contact admin@crp.to.
 *
 * 6. Redistributions of any form whatsoever must retain the following
 *    acknowledgment:
 *    "This product includes software developed by CryptoTrust LLC. for
 *    the OnlyKey Project (https://www.crp.to/ok)"
 *
 * 7. Redistributions in any form must be accompanied by information on
 *    how to obtain complete source code for this software and any
 *    accompanying software that uses this software. The source code
 *    must either be included in the distribution or be available for
 *    no more than the cost of distribution plus a nominal fee, and must
 *    be freely redistributable under reasonable conditions. For a
 *    binary file, complete source code means the source code for all
 *    modules it contains.
 *
 * NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS
 * ARE GRANTED BY THIS LICENSE. IF SOFTWARE RECIPIENT INSTITUTES PATENT
 * LITIGATION AGAINST ANY ENTITY (INCLUDING A CROSS-CLAIM OR COUNTERCLAIM
 * IN A LAWSUIT) ALLEGING THAT THIS SOFTWARE (INCLUDING COMBINATIONS OF THE
 * SOFTWARE WITH OTHER SOFTWARE OR HARDWARE) INFRINGES SUCH SOFTWARE
 * RECIPIENT'S PATENT(S), THEN SUCH SOFTWARE RECIPIENT'S RIGHTS GRANTED BY
 * THIS LICENSE SHALL TERMINATE AS OF THE DATE SUCH LITIGATION IS FILED. IF
 * ANY PROVISION OF THIS AGREEMENT IS INVALID OR UNENFORCEABLE UNDER
 * APPLICABLE LAW, IT SHALL NOT AFFECT THE VALIDITY OR ENFORCEABILITY OF THE
 * REMAINDER OF THE TERMS OF THIS AGREEMENT, AND WITHOUT FURTHER ACTION
 * BY THE PARTIES HERETO, SUCH PROVISION SHALL BE REFORMED TO THE MINIMUM
 * EXTENT NECESSARY TO MAKE SUCH PROVISION VALID AND ENFORCEABLE. ALL
 * SOFTWARE RECIPIENT'S RIGHTS UNDER THIS AGREEMENT SHALL TERMINATE IF IT
 * FAILS TO COMPLY WITH ANY OF THE MATERIAL TERMS OR CONDITIONS OF THIS
 * AGREEMENT AND DOES NOT CURE SUCH FAILURE IN A REASONABLE PERIOD OF
 * TIME AFTER BECOMING AWARE OF SUCH NONCOMPLIANCE. THIS SOFTWARE IS
 * PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* Original Teensyduino Core Library
 * http://www.pjrc.com/teensy/
 * Copyright (c) 2013 PJRC.COM, LLC.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * 1. The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * 2. If the Software is incorporated into a build system that allows
 * selection among a list of target devices, then similar target
 * devices manufactured by PJRC.COM must be included in the list of
 * target devices and selectable in the same manner.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef _usb_desc_h_
#define _usb_desc_h_

// This header is NOT meant to be included when compiling
// user sketches in Arduino.  The low-level functions
// provided by usb_dev.c are meant to be called only by
// code which provides higher-level interfaces to the user.

#include <stdint.h>
#include <stddef.h>

#define ENDPOINT_UNUSED			0x00
#define ENDPOINT_TRANSIMIT_ONLY		0x15
#define ENDPOINT_RECEIVE_ONLY		0x19
#define ENDPOINT_TRANSMIT_AND_RECEIVE	0x1D

/*
Each group of #define lines below corresponds to one of the
settings in the Tools > USB Type menu.  This file defines what
type of USB device is actually created for each of those menu
options.
Each "interface" is a set of functionality your PC or Mac will
use and treat as if it is a unique device.  Within each interface,
the "endpoints" are the actual communication channels.  Most
interfaces use 1, 2 or 3 endpoints.  By editing only this file,
you can customize the USB Types to be any collection of interfaces.
To modify a USB Type, delete the XYZ_INTERFACE lines for any
interfaces you wish to remove, and copy them from another USB Type
for any you want to add.
Give each interface a unique number, and edit NUM_INTERFACE to
reflect the total number of interfaces.
Next, assign unique endpoint numbers to all the endpoints across
all the interfaces your device has.  You can reuse an endpoint
number for transmit and receive, but the same endpoint number must
not be used twice to transmit, or twice to receive.
Most endpoints also require their maximum size, and some also
need an interval specification (the number of milliseconds the
PC will check for data from that endpoint).  For existing
interfaces, usually these other settings should not be changed.
Edit NUM_ENDPOINTS to be at least the largest endpoint number used.
Edit NUM_USB_BUFFERS to control how much memory the USB stack will
allocate.  At least 2 should be used for each endpoint.  More
memory will allow higher throughput for user programs that have
high latency (eg, spending time doing things other than interacting
with the USB).
Edit the ENDPOINT*_CONFIG lines so each endpoint is configured
the proper way (transmit, receive, or both).
If you are using existing interfaces (making your own device with
a different set of interfaces) the code in all other files should
automatically adapt to the new endpoints you specify here.
If you need to create a new type of interface, you'll need to write
the code which sends and receives packets, and presents an API to
the user.  Usually, a pair of files are added for the actual code,
and code is also added in usb_dev.c for any control transfers,
interrupt-level code, or other very low-level stuff not possible
from the packet send/receive functons.  Code also is added in
usb_inst.c to create an instance of your C++ object.
You may edit the Vendor and Product ID numbers, and strings.  If
the numbers are changed, Teensyduino may not be able to automatically
find and reboot your board when you click the Upload button in
the Arduino IDE.  You will need to press the Program button on
Teensy to initiate programming.
Some operating systems, especially Windows, may cache USB device
info.  Changes to the device name may not update on the same
computer unless the vendor or product ID numbers change, or the
"bcdDevice" revision code is increased.
If these instructions are missing steps or could be improved, please
let me know?  http://forum.pjrc.com/forums/4-Suggestions-amp-Bug-Reports
*/


#if defined(USB_SERIAL)
  #define VENDOR_ID		0x16C0
  #define PRODUCT_ID		0x0483
  #define DEVICE_CLASS		2	// 2 = Communication Class
  #define MANUFACTURER_NAME	{'T','e','e','n','s','y','d','u','i','n','o'}
  #define MANUFACTURER_NAME_LEN	11
  #define PRODUCT_NAME		{'U','S','B',' ','S','e','r','i','a','l'}
  #define PRODUCT_NAME_LEN	10
  #define EP0_SIZE		64
  #define NUM_ENDPOINTS		4
  #define NUM_USB_BUFFERS	12
  #define NUM_INTERFACE		2
  #define CDC_STATUS_INTERFACE	0
  #define CDC_DATA_INTERFACE	1
  #define CDC_ACM_ENDPOINT	2
  #define CDC_RX_ENDPOINT       3
  #define CDC_TX_ENDPOINT       4
  #define CDC_ACM_SIZE          16
  #define CDC_RX_SIZE           64
  #define CDC_TX_SIZE           64
  #define ENDPOINT2_CONFIG	ENDPOINT_TRANSIMIT_ONLY
  #define ENDPOINT3_CONFIG	ENDPOINT_RECEIVE_ONLY
  #define ENDPOINT4_CONFIG	ENDPOINT_TRANSIMIT_ONLY

#elif defined(USB_HID)
  #define VENDOR_ID		0x16C0
  #define PRODUCT_ID		0x0482
  #define MANUFACTURER_NAME	{'T','e','e','n','s','y','d','u','i','n','o'}
  #define MANUFACTURER_NAME_LEN	11
  #define PRODUCT_NAME		{'K','e','y','b','o','a','r','d','/','M','o','u','s','e','/','J','o','y','s','t','i','c','k'}
  #define PRODUCT_NAME_LEN	23
  #define EP0_SIZE		64
  #define NUM_ENDPOINTS         5
  #define NUM_USB_BUFFERS	24
  #define NUM_INTERFACE		4
  #define SEREMU_INTERFACE      2	// Serial emulation
  #define SEREMU_TX_ENDPOINT    1
  #define SEREMU_TX_SIZE        64
  #define SEREMU_TX_INTERVAL    1
  #define SEREMU_RX_ENDPOINT    2
  #define SEREMU_RX_SIZE        32
  #define SEREMU_RX_INTERVAL    2
  #define KEYBOARD_INTERFACE    0	// Keyboard
  #define KEYBOARD_ENDPOINT     3
  #define KEYBOARD_SIZE         8
  #define KEYBOARD_INTERVAL     1
  #define MOUSE_INTERFACE       1	// Mouse
  #define MOUSE_ENDPOINT        5
  #define MOUSE_SIZE            8
  #define MOUSE_INTERVAL        1
  #define JOYSTICK_INTERFACE    3	// Joystick
  #define JOYSTICK_ENDPOINT     4
  #define JOYSTICK_SIZE         16
  #define JOYSTICK_INTERVAL     2
  #define ENDPOINT1_CONFIG	ENDPOINT_TRANSIMIT_ONLY
  #define ENDPOINT2_CONFIG	ENDPOINT_RECEIVE_ONLY
  #define ENDPOINT3_CONFIG	ENDPOINT_TRANSIMIT_ONLY
  #define ENDPOINT4_CONFIG	ENDPOINT_TRANSIMIT_ONLY
  #define ENDPOINT5_CONFIG	ENDPOINT_TRANSIMIT_ONLY

#elif defined(USB_SERIAL_HID)
  #define VENDOR_ID		0x16C0
  #define PRODUCT_ID		0x0487
  #define DEVICE_CLASS		0xEF
  #define DEVICE_SUBCLASS	0x02
  #define DEVICE_PROTOCOL	0x01
  #define MANUFACTURER_NAME	{'T','e','e','n','s','y','d','u','i','n','o'}
  #define MANUFACTURER_NAME_LEN	11
  #define PRODUCT_NAME		{'S','e','r','i','a','l','/','K','e','y','b','o','a','r','d','/','M','o','u','s','e','/','J','o','y','s','t','i','c','k'}
  #define PRODUCT_NAME_LEN	30
  #define EP0_SIZE		64
  #define NUM_ENDPOINTS		6
  #define NUM_USB_BUFFERS	30
  #define NUM_INTERFACE		5
  #define CDC_IAD_DESCRIPTOR	1
  #define CDC_STATUS_INTERFACE	0
  #define CDC_DATA_INTERFACE	1	// Serial
  #define CDC_ACM_ENDPOINT	2
  #define CDC_RX_ENDPOINT       3
  #define CDC_TX_ENDPOINT       4
  #define CDC_ACM_SIZE          16
  #define CDC_RX_SIZE           64
  #define CDC_TX_SIZE           64
  #define KEYBOARD_INTERFACE    2	// Keyboard
  #define KEYBOARD_ENDPOINT     1
  #define KEYBOARD_SIZE         8
  #define KEYBOARD_INTERVAL     1
  #define MOUSE_INTERFACE       3	// Mouse
  #define MOUSE_ENDPOINT        5
  #define MOUSE_SIZE            8
  #define MOUSE_INTERVAL        2
  #define JOYSTICK_INTERFACE    4	// Joystick
  #define JOYSTICK_ENDPOINT     6
  #define JOYSTICK_SIZE         16
  #define JOYSTICK_INTERVAL     1
  #define ENDPOINT1_CONFIG	ENDPOINT_TRANSIMIT_ONLY
  #define ENDPOINT2_CONFIG	ENDPOINT_TRANSIMIT_ONLY
  #define ENDPOINT3_CONFIG	ENDPOINT_RECEIVE_ONLY
  #define ENDPOINT4_CONFIG	ENDPOINT_TRANSIMIT_ONLY
  #define ENDPOINT5_CONFIG	ENDPOINT_TRANSIMIT_ONLY
  #define ENDPOINT6_CONFIG	ENDPOINT_TRANSIMIT_ONLY

#elif defined(USB_MIDI)
  #define VENDOR_ID		0x16C0
  #define PRODUCT_ID		0x0485
  #define MANUFACTURER_NAME	{'T','e','e','n','s','y','d','u','i','n','o'}
  #define MANUFACTURER_NAME_LEN	11
  #define PRODUCT_NAME		{'T','e','e','n','s','y',' ','M','I','D','I'}
  #define PRODUCT_NAME_LEN	11
  #define EP0_SIZE		64
  #define NUM_ENDPOINTS         4
  #define NUM_USB_BUFFERS	16
  #define NUM_INTERFACE		2
  #define SEREMU_INTERFACE      1	// Serial emulation
  #define SEREMU_TX_ENDPOINT    1
  #define SEREMU_TX_SIZE        64
  #define SEREMU_TX_INTERVAL    1
  #define SEREMU_RX_ENDPOINT    2
  #define SEREMU_RX_SIZE        32
  #define SEREMU_RX_INTERVAL    2
  #define MIDI_INTERFACE        0	// MIDI
  #define MIDI_TX_ENDPOINT      3
  #define MIDI_TX_SIZE          64
  #define MIDI_RX_ENDPOINT      4
  #define MIDI_RX_SIZE          64
  #define ENDPOINT1_CONFIG	ENDPOINT_TRANSIMIT_ONLY
  #define ENDPOINT2_CONFIG	ENDPOINT_RECEIVE_ONLY
  #define ENDPOINT3_CONFIG	ENDPOINT_TRANSIMIT_ONLY
  #define ENDPOINT4_CONFIG	ENDPOINT_RECEIVE_ONLY
  

  
  #elif defined(USB_RAWHID)
  #define VENDOR_ID             0x1d50
  #define PRODUCT_ID            0x60fc
  #define RAWHID_USAGE_PAGE	0xf1d0  // Changed for FIDO support
  #define RAWHID_USAGE		0x01  // Changed for FIDO support
  #define MANUFACTURER_NAME     {'C','R','Y','P','T','O','T','R','U','S','T'}
  #define MANUFACTURER_NAME_LEN	11
  #define PRODUCT_NAME          {'O','N','L','Y','K','E','Y'}
  #define PRODUCT_NAME_LEN	    7  
  #define EP0_SIZE		        64
  #define NUM_ENDPOINTS         5
  #define NUM_USB_BUFFERS	    30
  #define NUM_INTERFACE		    3
  #define RAWHID_INTERFACE      0	// RawHID
  #define RAWHID_TX_ENDPOINT    3
  #define RAWHID_TX_SIZE        64
  #define RAWHID_TX_INTERVAL    1
  #define RAWHID_RX_ENDPOINT    4
  #define RAWHID_RX_SIZE        64
  #define RAWHID_RX_INTERVAL    1
  #define SEREMU_INTERFACE      1	// Serial emulation
  #define SEREMU_TX_ENDPOINT    1
  #define SEREMU_TX_SIZE        64
  #define SEREMU_TX_INTERVAL    1
  #define SEREMU_RX_ENDPOINT    2
  #define SEREMU_RX_SIZE        32
  #define SEREMU_RX_INTERVAL    2
  #define KEYBOARD_INTERFACE    2	// Keyboard
  #define KEYBOARD_ENDPOINT     5
  #define KEYBOARD_SIZE         8
  #define KEYBOARD_INTERVAL     1
  #define ENDPOINT1_CONFIG	ENDPOINT_TRANSIMIT_ONLY
  #define ENDPOINT2_CONFIG	ENDPOINT_RECEIVE_ONLY
  #define ENDPOINT3_CONFIG	ENDPOINT_TRANSIMIT_ONLY
  #define ENDPOINT4_CONFIG	ENDPOINT_RECEIVE_ONLY
  #define ENDPOINT5_CONFIG	ENDPOINT_TRANSIMIT_ONLY

  //#define VENDOR_ID             0x1d50
  //#define PRODUCT_ID            0x60fc
  //#define RAWHID_USAGE_PAGE	0xf1d0  // Changed for FIDO support
  //#define RAWHID_USAGE		0x01  // Changed for FIDO support
  //#define MANUFACTURER_NAME     {'C','R','Y','P','T','O','T','R','U','S','T'}
  //#define MANUFACTURER_NAME_LEN	11
  //#define PRODUCT_NAME          {'O','N','L','Y','K','E','Y'}
  //#define PRODUCT_NAME_LEN	    7
  //#define EP0_SIZE		        64
  //#define NUM_ENDPOINTS         3
  //#define NUM_USB_BUFFERS	    30
  //#define NUM_INTERFACE		    2
  //#define RAWHID_INTERFACE      0	// RawHID
  //#define RAWHID_TX_ENDPOINT    1
  //#define RAWHID_TX_SIZE        64
  //#define RAWHID_TX_INTERVAL    1
  //#define RAWHID_RX_ENDPOINT    2
  //#define RAWHID_RX_SIZE        64
  //#define RAWHID_RX_INTERVAL    1
  //#define KEYBOARD_INTERFACE    1	// Keyboard
  //#define KEYBOARD_ENDPOINT     3
  //#define KEYBOARD_SIZE         8
  //#define KEYBOARD_INTERVAL     1
  //#define ENDPOINT1_CONFIG	ENDPOINT_TRANSIMIT_ONLY
  //#define ENDPOINT2_CONFIG	ENDPOINT_RECEIVE_ONLY
  //#define ENDPOINT3_CONFIG	ENDPOINT_TRANSIMIT_ONLY
  

#elif defined(USB_FLIGHTSIM)
  #define VENDOR_ID		0x16C0
  #define PRODUCT_ID		0x0488
  #define MANUFACTURER_NAME	{'T','e','e','n','s','y','d','u','i','n','o'}
  #define MANUFACTURER_NAME_LEN	11
  #define PRODUCT_NAME		{'T','e','e','n','s','y',' ','F','l','i','g','h','t',' ','S','i','m',' ','C','o','n','t','r','o','l','s'}
  #define PRODUCT_NAME_LEN	26
  #define EP0_SIZE		64
  #define NUM_ENDPOINTS         4
  #define NUM_USB_BUFFERS	20
  #define NUM_INTERFACE		2
  #define FLIGHTSIM_INTERFACE	0	// Flight Sim Control
  #define FLIGHTSIM_TX_ENDPOINT	3
  #define FLIGHTSIM_TX_SIZE	64
  #define FLIGHTSIM_TX_INTERVAL	1
  #define FLIGHTSIM_RX_ENDPOINT	4
  #define FLIGHTSIM_RX_SIZE	64
  #define FLIGHTSIM_RX_INTERVAL	1
  #define SEREMU_INTERFACE      1	// Serial emulation
  #define SEREMU_TX_ENDPOINT    1
  #define SEREMU_TX_SIZE        64
  #define SEREMU_TX_INTERVAL    1
  #define SEREMU_RX_ENDPOINT    2
  #define SEREMU_RX_SIZE        32
  #define SEREMU_RX_INTERVAL    2
  #define ENDPOINT1_CONFIG	ENDPOINT_TRANSIMIT_ONLY
  #define ENDPOINT2_CONFIG	ENDPOINT_RECEIVE_ONLY
  #define ENDPOINT3_CONFIG	ENDPOINT_TRANSIMIT_ONLY
  #define ENDPOINT4_CONFIG	ENDPOINT_RECEIVE_ONLY

#elif defined(USB_MTPDISK)
  #define VENDOR_ID		0x16C0
  #define PRODUCT_ID		0x0489
  #define MANUFACTURER_NAME	{'T','e','e','n','s','y','d','u','i','n','o'}
  #define MANUFACTURER_NAME_LEN	11
  #define PRODUCT_NAME		{'T','e','e','n','s','y',' ','M','T','P',' ','D','i','s','k'}
  #define PRODUCT_NAME_LEN	15
  #define EP0_SIZE		64
  #define NUM_ENDPOINTS         4
  #define NUM_USB_BUFFERS	20
  #define NUM_INTERFACE		2
  #define MTP_INTERFACE		0	// MTP Disk
  #define MTP_TX_ENDPOINT	3
  #define MTP_TX_SIZE		64
  #define MTP_RX_ENDPOINT	3
  #define MTP_RX_SIZE		64
  #define MTP_EVENT_ENDPOINT	4
  #define MTP_EVENT_SIZE	16
  #define MTP_EVENT_INTERVAL	10
  #define SEREMU_INTERFACE      1	// Serial emulation
  #define SEREMU_TX_ENDPOINT    1
  #define SEREMU_TX_SIZE        64
  #define SEREMU_TX_INTERVAL    1
  #define SEREMU_RX_ENDPOINT    2
  #define SEREMU_RX_SIZE        32
  #define SEREMU_RX_INTERVAL    2
  #define ENDPOINT1_CONFIG	ENDPOINT_TRANSIMIT_ONLY
  #define ENDPOINT2_CONFIG	ENDPOINT_RECEIVE_ONLY
  #define ENDPOINT3_CONFIG	ENDPOINT_TRANSMIT_AND_RECEIVE
  #define ENDPOINT4_CONFIG	ENDPOINT_RECEIVE_ONLY

#endif

#ifdef USB_DESC_LIST_DEFINE
#if defined(NUM_ENDPOINTS) && NUM_ENDPOINTS > 0
// NUM_ENDPOINTS = number of non-zero endpoints (0 to 15)
extern const uint8_t usb_endpoint_config_table[NUM_ENDPOINTS];

typedef struct {
	uint16_t	wValue;
	uint16_t	wIndex;
	const uint8_t	*addr;
	uint16_t	length;
} usb_descriptor_list_t;

extern const usb_descriptor_list_t usb_descriptor_list[];
#endif // NUM_ENDPOINTS
#endif // USB_DESC_LIST_DEFINE

#endif
