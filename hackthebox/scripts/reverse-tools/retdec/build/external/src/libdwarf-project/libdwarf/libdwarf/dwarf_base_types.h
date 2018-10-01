/*

  Copyright (C) 2000,2005 Silicon Graphics, Inc.  All Rights Reserved.
  Portions Copyright (C) 2008-2012  David Anderson. All Rights Reserved.

  This program is free software; you can redistribute it and/or modify it
  under the terms of version 2.1 of the GNU Lesser General Public License
  as published by the Free Software Foundation.

  This program is distributed in the hope that it would be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

  Further, this software is distributed without any warranty that it is
  free of the rightful claim of any third person regarding infringement
  or the like.  Any license provided herein, whether implied or
  otherwise, applies only to this software file.  Patent licenses, if
  any, provided herein do not apply to combinations of this program with
  other software, or any other product whatsoever.

  You should have received a copy of the GNU Lesser General Public
  License along with this program; if not, write the Free Software
  Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston MA 02110-1301,
  USA.

*/



#include "libdwarfdefs.h"

#define true                    1
#define false                   0

/* .debug_addr new in DWARF5 */
#define DW_ADDR_VERSION5   5

/* To identify a cie. That is, for .debug_frame */
#define DW_CIE_ID 		~(0x0)
#define DW_CIE_VERSION		1 /* DWARF2 */
#define DW_CIE_VERSION3		3 /* DWARF3 */
#define DW_CIE_VERSION4		4 /* DWARF4 */
#define DW_CIE_VERSION5		5 /* DWARF5 */

/*  For .debug_info DWARF2,3,4,5.
    .debug_types in DWARF4 only,  and gets DW_CU_VERSION4.  */
#define DW_CU_VERSION2 2
#define DW_CU_VERSION3 3
#define DW_CU_VERSION4 4
#define DW_CU_VERSION5 5

/* DWARF2,3, 4  and 5.*/
#define DW_ARANGES_VERSION2 2

#define DW_LINE_VERSION2   2
#define DW_LINE_VERSION3   3
#define DW_LINE_VERSION4   4
#define DW_LINE_VERSION5   5

/* .debug_line_str (and .dwo) new in DWARF5. */
#define DW_LINE_STR_VERSION5   5
/* .debug_loc (and .dwo) First header version number is  DWARF5. */
#define DW_LOC_VERSION5   5



/* .debug_macro (and .dwo) new in DWARF5. */
#define DW_MACRO_VERSION5   5
/* .debug_names new in DWARF5. */
#define DW_NAMES_VERSION5   5

/* .debug_pubnames in DWARF2,3,4. */
#define DW_PUBNAMES_VERSION2 2
/* .debug_pubnames in DWARF3,4. */
#define DW_PUBTYPES_VERSION2 2

/* .debug_ranges gets a version number in header in DWARF5. */
#define DW_RANGES_VERSION5 5


/* .debug_str_offsets (and .dwo) new in DWARF5. */
#define DW_STR_OFFSETS_VERSION5   5

/* .debug_sup new in DWARF5. */
#define DW_SUP_VERSION5 5

/* .debug_cu_index new in DWARF5. */
#define DW_CU_INDEX_VERSION5 5
/* .debug_tu_index new in DWARF5. */
#define DW_TU_INDEX_VERSION5 5





/*  These are allocation type codes for structs that
    are internal to the Libdwarf Consumer library.  */
#define DW_DLA_ABBREV_LIST      0x1e
#define DW_DLA_CHAIN            0x1f
#define DW_DLA_CU_CONTEXT       0x20
#define DW_DLA_FRAME            0x21
#define DW_DLA_GLOBAL_CONTEXT   0x22
#define DW_DLA_FILE_ENTRY       0x23
#define DW_DLA_LINE_CONTEXT     0x24
#define DW_DLA_LOC_CHAIN        0x25
#define DW_DLA_HASH_TABLE       0x26
#define DW_DLA_FUNC_CONTEXT     0x27
#define DW_DLA_TYPENAME_CONTEXT 0x28
#define DW_DLA_VAR_CONTEXT      0x29
#define DW_DLA_WEAK_CONTEXT     0x2a
#define DW_DLA_PUBTYPES_CONTEXT 0x2b  /* DWARF3 */
#define DW_DLA_HASH_TABLE_ENTRY 0x2c
#define DW_DLA_FISSION_PERCU    0x2d
/* Thru 0x36 reserved for internal future use. */

/*  Maximum number of allocation types for allocation routines.
    Only used with malloc_check.c and that is basically obsolete. */
#define MAX_DW_DLA		0x38

/*Dwarf_Word  is unsigned word usable for index, count in memory */
/*Dwarf_Sword is   signed word usable for index, count in memory */
/*  They are 32 or 64 bits depending if 64 bit longs or not, which
    fits the  ILP32 and LP64 models
    These work equally well with ILP64.  */

typedef unsigned long Dwarf_Word;
typedef signed long Dwarf_Sword;

typedef signed char Dwarf_Sbyte;
typedef unsigned char Dwarf_Ubyte;
typedef signed short Dwarf_Shalf;
typedef Dwarf_Small *Dwarf_Byte_Ptr;

/*  These 2 are fixed sizes which must not vary with the
    ILP32/LP64 model. Between these two, stay at 32 bit.  */
typedef __uint32_t Dwarf_ufixed;
typedef Dwarf__int32_t Dwarf_sfixed;

/*  In various places the code mistakenly associates
    forms 8 bytes long with Dwarf_Signed or Dwarf_Unsigned
    This is not a very portable assumption.
    The following should be used instead for 64 bit integers.
*/
typedef Dwarf__uint64_t Dwarf_ufixed64;
typedef Dwarf__int64_t Dwarf_sfixed64;


typedef struct Dwarf_Abbrev_List_s *Dwarf_Abbrev_List;
typedef struct Dwarf_File_Entry_s *Dwarf_File_Entry;
typedef struct Dwarf_CU_Context_s *Dwarf_CU_Context;
typedef struct Dwarf_Hash_Table_s *Dwarf_Hash_Table;
typedef struct Dwarf_Hash_Table_Entry_s *Dwarf_Hash_Table_Entry;


typedef struct Dwarf_Alloc_Hdr_s *Dwarf_Alloc_Hdr;
