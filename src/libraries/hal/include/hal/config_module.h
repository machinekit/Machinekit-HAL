/********************************************************************
 *  Description: config_module.h
 *  Provides functions for selecting between actual kernel mode build
 *  of loadable module code, or hooks to user space code that allows
 *  for compiling kernel module code to run in user space
 *
 *  Author(s): Charles Steinkuehler
 *  License: GNU LGPL Version 2.1 or (at your option) any later version.
 *
 *  Last change:
 *  2012-Dec-17 Charles Steinkuehler
 *              Initial version
 ********************************************************************/

/********************************************************************
 *  This file is part of Machinekit RTAPI / HAL
 *
 *  Copyright (C) 2012  Charles Steinkuehler
 *                      <charles AT steinkuehler DOT net>
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 *  THE AUTHORS OF THIS LIBRARY ACCEPT ABSOLUTELY NO LIABILITY FOR
 *  ANY HARM OR LOSS RESULTING FROM ITS USE.  IT IS _EXTREMELY_ UNWISE
 *  TO RELY ON SOFTWARE ALONE FOR SAFETY.  Any machinery capable of
 *  harming persons must have provisions for completely removing power
 *  from all motors, etc, before persons enter any danger area.  All
 *  machinery must be designed to comply with local and national safety
 *  codes, and the authors of this software can not, and do not, take
 *  any responsibility for such compliance.
 *
 * This code is part of the Machinekit HAL project.  For more
 * information, go to https://github.com/machinekit.
 *******************************************************************/

#ifndef CONFIG_MODULE_H
#define CONFIG_MODULE_H

/***********************************************************************
*                      USERMODE KERNEL DEFINES                         *
************************************************************************/

/*  When building kernel modules as userspace drivers, the code may be
    making use of linux kernel specific functionality (such as kmalloc
    or <linux/list.h>).  Thish is where these functions get rempapped
    to equivelent usermode functions or alternate code written to
    replace the kernel mode functionality.

    Mostly, this is done by replacing the standard linux kernel include
    files with alternates from the userpci directory, which requires
    place of something like <linux/list.h>
*/

/* Usermode PCI builds */

#define RTAPI_INC_CTYPE_H       <ctype.h>
#define RTAPI_INC_DEVICE_H      "user_pci/device.h"
#define RTAPI_INC_FIRMWARE_H    "user_pci/firmware.h"
#define RTAPI_INC_GFP_H         "user_pci/gfp.h"
#define RTAPI_INC_LIST_H        "user_pci/list.h"
#define RTAPI_INC_SLAB_H        "user_pci/slab.h"
#define RTAPI_INC_STRING_H      "user_pci/string.h"

#endif /* CONFIG_MODULE_H */
