/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef _MAINBOARD_XMP_INFO_H_
#define _MAINBOARD_XMP_INFO_H_

#include <stdint.h>
#include <stdbool.h>

/* CBMEM ID for XMP detection information */
#define CBMEM_ID_XMP_INFO 0x584d5000  /* "XMP\0" */

/* Structure to store XMP detection results in CBMEM */
struct xmp_detection_info {
    uint32_t signature;        /* Magic signature for validation */
    bool profile1_available;   /* XMP Profile 1 available on all DIMMs */
    bool profile2_available;   /* XMP Profile 2 available on all DIMMs */
    bool profiles_match;       /* Profiles match between DIMMs */
    uint8_t profile_count;     /* Number of available profiles */
    uint8_t reserved[3];       /* Padding for alignment */
};

#define XMP_INFO_SIGNATURE 0x584D5031  /* "XMP1" */

#endif /* _MAINBOARD_XMP_INFO_H_ */