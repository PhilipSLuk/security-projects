/*

  Copyright (C) 2000-2005 Silicon Graphics, Inc.  All Rights Reserved.
  Portions Copyright (C) 2007-2013 David Anderson. All Rights Reserved.
  Portions Copyright (C) 2008-2010 Arxan Technologies, Inc. All Rights Reserved.

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
/*  Following the nomenclature of the DWARF standard
    Section Version Numbers (DWARF 5):
    * means not applicable.
    - means not defined in that version.
    The version numbers for .debug_info is the same as .debug_info.dwo
    (etc for the other dwo sections).
    The versions applicable by section are:
    .                  DWARF2 DWARF3 DWARF4 DWARF5
    .debug_abbrev           *      *      *      *
    .debug_addr             -      -      -      5
    .debug_aranges          2      2      2      2
    .debug_frame            1      3      4      4
    .debug_info             2      3      4      5
    .debug_line             2      3      4      5
    .debug_line_str         -      -      -      5
    .debug_loc              *      *      *      5
    .debug_macinfo          *      *      *      -
    .debug_macro            -      -      -      5
    .debug_pubnames         2      2      2      -
    .debug_pubtypes         -      2      2      -
    .debug_ranges           -      *      *      5
    .debug_str              *      *      *      *
    .debug_str_offsets      -      -      -      5
    .debug_sup              -      -      -      5
    .debug_types            -      -      4      -

    .debug_abbrev.dwo       -      -      -      *
    .debug_info.dwo         -      -      -      5
    .debug_line.dwo         -      -      -      5
    .debug_loc.dwo          -      -      -      5
    .debug_macro.dwo        -      -      -      5
    .debug_str.dwo          -      -      -      *
    .debug_str_offsets.dwo  -      -      -      5

    .debug_cu_index         -      -      -      5
    .debug_tu_index         -      -      -      5

*/

#include <stddef.h>

/*  The 'debug_info' names below are non-zero (non-NULL) only
    if we are processing a debug_info section. And vice versa
    for a debug_types section. */

struct Dwarf_Die_s {
    Dwarf_Byte_Ptr di_debug_ptr;
    Dwarf_Abbrev_List di_abbrev_list;
    Dwarf_CU_Context di_cu_context;
    int  di_abbrev_code;

    /* TRUE if part of debug_info. FALSE if part of .debug_types. */
    Dwarf_Bool di_is_info;
};

struct Dwarf_Attribute_s {
    Dwarf_Half ar_attribute;             /* Attribute Value. */
    Dwarf_Half ar_attribute_form;        /* Attribute Form. */
    Dwarf_Half ar_attribute_form_direct;
        /*  Identical to ar_attribute_form except that if
            the original form uleb was DW_FORM_indirect,
            ar_attribute_form_direct contains DW_FORM_indirect
            but ar_attribute_form contains the true form. */
    Dwarf_CU_Context ar_cu_context;
        /*  The following points to either debug_info or debug_types
            depending on if context is cc_is_info  or not. */
    Dwarf_Small *ar_debug_ptr;

    Dwarf_Die ar_die;/* Access to the DIE owning the attribute */
    Dwarf_Attribute ar_next;
};

/*
    This structure provides the context for a compilation unit.
    Thus, it contains the Dwarf_Debug, cc_dbg, that this cu
    belongs to.  It contains the information in the compilation
    unit header, cc_length, cc_version_stamp, cc_abbrev_offset,
    and cc_address_size, in the .debug_info section for that cu.
    In addition, it contains the count, cc_count_cu, of the cu
    number of that cu in the list of cu's in the .debug_info.
    The count starts at 1, ie cc_count_cu is 1 for the first cu,
    2 for the second and so on.  This struct also contains a
    pointer, cc_abbrev_table, to a list of pairs of abbrev code
    and a pointer to the start of that abbrev
    in the .debug_abbrev section.

    Each die will also contain a pointer to such a struct to
    record the context for that die.

    Notice that a pointer to the CU DIE itself is
    Dwarf_Off off2 = cu_context->cc_debug_info_offset;
    cu_die_info_ptr = dbg->de_debug_info.dss_data +
        off2 + _dwarf_length_of_cu_header(dbg, off2);
    Or similar for de_debug_types.

    **Updated by dwarf_next_cu_header in dwarf_die_deliv.c
*/
struct Dwarf_CU_Context_s {
    Dwarf_Debug cc_dbg;
    /*  The sum of cc_length, cc_length_size, and cc_extension_size
        is the total length of the CU including its header.

        cc_length is the length of the compilation unit excluding
        cc_length_size and cc_extension_size.  */
    Dwarf_Unsigned cc_length;

    /*  cc_length_size is the size in bytes of an offset.
        Should probably be renamed cc_offset_size.
        4 for 32bit dwarf, 8 for 64bit dwarf (whether MIPS/IRIX
        64bit dwarf or standard 64bit dwarf using the extension
        mechanism). */
    Dwarf_Small cc_length_size;

    /*  cc_extension_size is zero unless this is standard
        DWARF3 and later 64bit dwarf using the extension mechanism.
        64bit DWARF3 and later: cc_extension_size is 4.
        64bit DWARF2 MIPS/IRIX: cc_extension_size is zero.
        32bit DWARF:            cc_extension_size is zero.  */
    Dwarf_Small cc_extension_size;

    /*  cc_version_stamp is the DWARF version number applicable
        to the  DWARF in this compilation unit. 2,3,4,... */
    Dwarf_Half cc_version_stamp;
    /*  cc_abbrev_offset is the section-global offset
        of the .debug_abbrev section this CU uses.
        Data from CU header. Includes DWP adjustment made
        as soon as we create a cu_context. */
    Dwarf_Unsigned cc_abbrev_offset;

    /*  cc_address_size is the size of an address in this
        compilation unit. */
    Dwarf_Small cc_address_size;
    /*  cc_debug_offset is the global offset in the section
        of the CU header of this CU.
        That is, it is a section global offset.
        May be debug_info or debug_types
        but those are distinct.
        Even in DWP this is set to true global offset
        right away when cu_context created.
        See cc_is_info flag. */
    Dwarf_Unsigned cc_debug_offset;

    /*  cc_signature is in the TU header
        of a type unit of a TU DIE.
        Ignore this field if cc_signature_present is zero.

        If cc_unit_type == DW_UT_compile or DW_UT_partial
            the signature is a CU signature.
        If cc_unit_type == DW_UT_type
            the signature is a type signature. */
    Dwarf_Sig8  cc_type_signature;

    /*  cc_typeoffsets contains the
        section-local DIE offset of the type
        the signature applies to if the cc_unit_type
        is DW_UT_type.  */
    Dwarf_Unsigned cc_type_signature_offset;

    /*  For each CU and each TU
        in a dwp package file there is
        is a hash and
        a set of offsets indexed by DW_SECT_* id.
        Only one such set per CU or TU.
        The data on all that is in cc_dwp_offsets

        If it is a TU the signature in cc_dwp_offsets
        must match the signature in cc_type_signature.
        */
    struct Dwarf_Debug_Fission_Per_CU_s  cc_dwp_offsets;


    /*  If the attribute DW_AT_[GNU_]addr_base is present in the
        CU die, its value is in cc_addr_base.
        cc_addr_base_present TRUE means cc_addr_base is meaningful, which
        is a check on the correctness of the DWARF.
        This base field created in DWARF5 to reduce the
        number of address relocations a linker must do.


        DW_AT_str_offsets_base exists for a DW_FORM_strx,
        for GNU a base of zero is apparently fine.
        This base field created in DWARF5 to reduce the
        number of string offset relocations a linker must do.

        DW_AT_ranges_base similarly.
        Within the CU, this base means that DW_FORM_sec_offset
        values need not be realocated by the linker.

        Fields listed in this order for a tiny space saving
        as opposed to greatest clarity.
    */
    Dwarf_Bool cc_type_signature_present; /* Meaning type signature
        in TU header or, for CU header, signature in CU DIE. */
    Dwarf_Bool cc_addr_base_present;       /* Not TRUE in .dwo */
    Dwarf_Bool cc_str_ranges_base_present; /* Not TRUE in .dwo */
    Dwarf_Bool cc_str_offsets_base_present;

    /*  cc_cu_die_offset_present is non-zero if
        cc_cu_die_global_sec_offset is meaningful.  */
    Dwarf_Bool cc_cu_die_offset_present;

    /*  FIXME from DW_AT_addr_base in CU DIE */
    Dwarf_Unsigned cc_addr_base;     /* Zero in .dwo */
    /*  FIXME from DW_AT_ranges_base in CU DIE */
    Dwarf_Unsigned cc_ranges_base;   /* Zero in .dwo */
    /*  FIXME from DW_AT_str_offsets_base in CU DIE */
    Dwarf_Unsigned cc_str_offsets_base;

    /*  Global section offset to the bytes of the CU die for this CU.
        Set when the CU die is accessed by dwarf_siblingof(). */
    Dwarf_Unsigned cc_cu_die_global_sec_offset;

    Dwarf_Byte_Ptr cc_last_abbrev_ptr;
    Dwarf_Byte_Ptr cc_last_abbrev_endptr;
    Dwarf_Hash_Table cc_abbrev_hash_table;
    Dwarf_CU_Context cc_next;

    /*unsigned char cc_offset_length; */
    Dwarf_Bool cc_is_info; /* TRUE means context is
        in debug_info, FALSE means is in debug_types.
        FALSE only possible for DWARF4 .debug_types
        section CUs.
        For DWARF5 all DIEs are in .debug_info[.dwo]  */

    Dwarf_Half cc_unit_type; /* DW_UT_type or DW_UT_compile
        or DW_UT_partial (from the CU header in DWARF5).
        Zero until the value is known.
        For DWARF 2,3,4 this is filled in initially
        from the CU header and refined by inspecting the TAG
        of the CU DIE to detect DW_UT_partial is applicable.  */
};

/*  Consolidates section-specific data in one place.
    Section is an Elf specific term, intended as a general
    term (for non-Elf objects some code must synthesize the
    values somehow).  */
struct Dwarf_Section_s {
    Dwarf_Small *  dss_data;
    Dwarf_Unsigned dss_size;
    /*  Some Elf sections have a non-zero dss_entrysize which
        is the size in bytes of a table entry in the section.
        Relocations and symbols are both in tables, so have a
        non-zero entrysize.  Object formats which do not care
        about this should leave this field zero. */
    Dwarf_Unsigned dss_entrysize;
    /*  dss_index is the section index as things are numbered in
        an object file being read.   An Elf section number. */
    Dwarf_Word     dss_index;
    /*  dss_addr is the 'section address' which is only
        non-zero for a GNU eh section.
        Purpose: to handle DW_EH_PE_pcrel encoding. Leaving
        it zero is fine for non-elf.  */
    Dwarf_Addr     dss_addr;
    Dwarf_Small    dss_data_was_malloc;
    /*  is_in_use set during initial object reading to
        detect duplicates. Ignored after setup done. */
    Dwarf_Small    dss_is_in_use;

    /*  For non-elf, leaving the following fields zero
        will mean they are ignored. */
    /*  dss_link should be zero unless a section has a link
        to another (sh_link).  Used to access relocation data for
        a section (and for symtab section, access its strtab). */
    Dwarf_Word     dss_link;
    /*  The following is used when reading .rela sections
        (such sections appear in some .o files). */
    Dwarf_Half     dss_reloc_index; /* Zero means ignore the reloc fields. */
    Dwarf_Small *  dss_reloc_data;
    Dwarf_Unsigned dss_reloc_size;
    Dwarf_Unsigned dss_reloc_entrysize;
    Dwarf_Addr     dss_reloc_addr;
    /*  dss_reloc_symtab is the sh_link of a .rela to its .symtab, leave
        it 0 if non-meaningful. */
    Dwarf_Addr     dss_reloc_symtab;
    /*  dss_reloc_link should be zero unless a reloc section has a link
        to another (sh_link).  Used to access the symtab for relocations
        a section. */
    Dwarf_Word     dss_reloc_link;
    /*  Pointer to the elf symtab, used for elf .rela. Leave it 0
        if not relevant. */
    struct Dwarf_Section_s *dss_symtab;
    /*  dss_name must never be freed, it is a quoted string
        in libdwarf. */
    const char * dss_name;
};

/*  Overview: if next_to_use== first, no error slots are used.
    If next_to_use+1 (mod maxcount) == first the slots are all used
*/
struct Dwarf_Harmless_s {
  unsigned dh_maxcount;
  unsigned dh_next_to_use;
  unsigned dh_first;
  unsigned dh_errs_count;
  char **  dh_errors;
};

/* Data needed seperately for debug_info and debug_types
   as we may be reading both interspersed. */

struct Dwarf_Debug_InfoTypes_s {
    /*  Context for the compilation_unit just read by a call to
        dwarf_next_cu_header. **Updated by dwarf_next_cu_header in
        dwarf_die_deliv.c */
    Dwarf_CU_Context de_cu_context;
    /*  Points to linked list of CU Contexts for the CU's already read.
        These are only CU's read by dwarf_next_cu_header(). */
    Dwarf_CU_Context de_cu_context_list;
    /*  Points to the last CU Context added to the list by
        dwarf_next_cu_header(). */
    Dwarf_CU_Context de_cu_context_list_end;
    /*  This is the list of CU contexts read for dwarf_offdie().  These
        may read ahead of dwarf_next_cu_header(). */
    Dwarf_CU_Context de_offdie_cu_context;
    Dwarf_CU_Context de_offdie_cu_context_end;

    /*  Offset of last byte of last CU read.
        Actually one-past that last byte.  So
        use care and compare as offset >= de_last_offset
        to know if offset is too big. */
    Dwarf_Unsigned de_last_offset;
    /*  de_last_di_info_ptr and de_last_die are used with
        dwarf_siblingof, dwarf_child, and dwarf_validate_die_sibling.
        dwarf_validate_die_sibling will not give meaningful results
        if called inappropriately. */
    Dwarf_Byte_Ptr  de_last_di_ptr;
    Dwarf_Die  de_last_die;
};
typedef struct Dwarf_Debug_InfoTypes_s *Dwarf_Debug_InfoTypes;

/*  As the tasks performed on a debug related section is the same,
    in order to make the process of adding a new section (very unlikely) a
    little bit easy and to reduce the possibility of errors, a simple table
    build dynamically, will contain the relevant information.
*/

struct Dwarf_dbg_sect_s {
    /* Debug section name must not be freed, is quoted string. */
    const char *ds_name;
    /*   Debug section information, points to de_debug_*member
        (or the like) of the dbg struct.  */
    struct Dwarf_Section_s *ds_secdata;

    int ds_duperr;                     /* Error code for duplicated section */
    int ds_emptyerr;                   /* Error code for empty section */
    int ds_have_dwarf;                 /* Section contains DWARF */
};

/*  As the number of debug sections does not change very often, in the case a
    new section is added in 'enter_section_in_array()'
    the 'MAX_DEBUG_SECTIONS' must
    be updated accordingly.
    This does not yet allow for section-groups in object files,
    for which many .debug_info (and other) sections may exist.
*/
#define DWARF_MAX_DEBUG_SECTIONS 30



/*  These offsets and sizes (Dwarf_Fission*) are
    for the  DebugFission DWP sections
    .debug_cu_index and .debug_tu_index.
    Because the sections in the .dwp contain
    unrelocated .dwo sections. The offsets
    taken from the .dwo sections
    need the dfs_offset applied to
    find the applicable data correctly.

    When a .dwp is not involved (ie, when
    there is no .debug_cu_index or .debug_tu_index
    section) then the dfo_version field
    in  Dwarf_Fission_Offsets_s will be zero.
*/
struct Dwarf_Fission_Section_Offset_s {
    Dwarf_Unsigned dfs_offset;
    Dwarf_Unsigned dfs_size;
};

struct Dwarf_Fission_Per_CU_s {
    /*  dfp_index is the number of the compilation unit
        in the .debug_info.dwo or
        .debug_types.dwo(DWARF4 only) sections.
        Index starts at 0.
        May not match the location in
        dfo_per_cu array of Dwarf_Fission_Per_CU_s.  */
    unsigned       dfp_index;

    /* Called a signature in most places. */
    Dwarf_Sig8     dfp_hash;

    /* 0 unused, 1-8 are indexed by DW_SECT* */
    struct Dwarf_Fission_Section_Offset_s dfp_offsets[DW_FISSION_SECT_COUNT];
};


/*  If dfo_version is 0 the struct is empty/unused.
    and then all the other fields are 0.
    If dfo_version is zero this is not a
    DWP (.dwp) object file. */
struct Dwarf_Fission_Offsets_s {
    unsigned dfo_version; /* 2 is the only supported value.
        defaults to zero meaning 'none'. */

    /*  pointer to "cu" or "tu", never free
        the string.
        type refers to the index type
            'cu'referring to lookups of DW_AT_dwo_id
                .debug_cu_index
                which is an 8 byte hash.
                We use Dwarf_Sig8.
            'tu' referring to lookups of DW_FORM_ref_sig8 (type unit hash)
                .debug_tu_index
                We use Dwarf_Sig8 here too.
        tu does NOT refer to .debug_types in a DWARF5 object.
    */
    const char *   dfo_type;
    Dwarf_Bool     dfo_is_info; /* TRUE if the section is
        DWARF4 .debug_types for a "tu" . Else False. */
    Dwarf_Bool     dfo_is_type_unit; /* TRUE if this is
        a type unit. DW_TAG_type_unit. */

    Dwarf_Unsigned dfo_columns;
    Dwarf_Unsigned dfo_entries;
    Dwarf_Unsigned dfo_slots;

    /* Pointer to array of dfo_entries structs. */
    struct Dwarf_Fission_Per_CU_s *dfo_per_cu;

    /*  Hash table enables finding the index of
        into dfo_per_cu given a signature.
        Data for tsearch functions.
        Initially, just using sequential search.
        is tsearch needed here?
    void * dfo_hash_to_index; */
};


struct Dwarf_Debug_s {
    /*  All file access methods and support data
        are hidden in this structure.
        We get a pointer, callers control the lifetime of the
        structure and contents. */
    struct Dwarf_Obj_Access_Interface_s *de_obj_file;

    Dwarf_Handler de_errhand;
    Dwarf_Ptr de_errarg;

    struct Dwarf_Debug_InfoTypes_s de_info_reading;
    struct Dwarf_Debug_InfoTypes_s de_types_reading;

    /*  Number of bytes in the length, and offset field in various
        .debug_* sections.  It's not very meaningful, and is
        only used in one 'approximate' calculation.  */
    Dwarf_Small de_length_size;

    /*  number of bytes in a pointer of the target in various .debug_
        sections. 4 in 32bit, 8 in MIPS 64, ia64. */
    Dwarf_Small de_pointer_size;

    /*  set at creation of a Dwarf_Debug to say if form_string should be
        checked for valid length at every call. 0 means do the check.
        non-zero means do not do the check. */
    Dwarf_Small de_assume_string_in_bounds;

    /*  Keep track of allocations so a dwarf_finish call can clean up.
        Null till a tree is created */
    void * de_alloc_tree;

    /*  These fields are used to process debug_frame section.  **Updated
        by dwarf_get_fde_list in dwarf_frame.h */
    /*  Points to contiguous block of pointers to Dwarf_Cie_s structs. */
    Dwarf_Cie *de_cie_data;
    /*  Count of number of Dwarf_Cie_s structs. */
    Dwarf_Signed de_cie_count;
    /*  Keep eh (GNU) separate!. */
    Dwarf_Cie *de_cie_data_eh;
    Dwarf_Signed de_cie_count_eh;
    /*  Points to contiguous block of pointers to Dwarf_Fde_s structs. */
    Dwarf_Fde *de_fde_data;
    /*  Count of number of Dwarf_Fde_s structs. */
    Dwarf_Unsigned de_fde_count;
    /*  Keep eh (GNU) separate!. */
    Dwarf_Fde *de_fde_data_eh;
    Dwarf_Unsigned de_fde_count_eh;

    struct Dwarf_Section_s de_debug_info;
    struct Dwarf_Section_s de_debug_types;
    struct Dwarf_Section_s de_debug_abbrev;
    struct Dwarf_Section_s de_debug_line;
    struct Dwarf_Section_s de_debug_line_str; /* New in DWARF5 */
    struct Dwarf_Section_s de_debug_loc;
    struct Dwarf_Section_s de_debug_aranges;
    struct Dwarf_Section_s de_debug_macinfo;
    struct Dwarf_Section_s de_debug_macro; /* New in DWARF5 */
    struct Dwarf_Section_s de_debug_names; /* New in DWARF5 */
    struct Dwarf_Section_s de_debug_pubnames;
    struct Dwarf_Section_s de_debug_str;
    struct Dwarf_Section_s de_debug_sup;  /* New in DWARF5 */
    struct Dwarf_Section_s de_debug_frame;

    /* gnu: the g++ eh_frame section */
    struct Dwarf_Section_s de_debug_frame_eh_gnu;

    struct Dwarf_Section_s de_debug_pubtypes; /* DWARF3 .debug_pubtypes */

    struct Dwarf_Section_s de_debug_funcnames;

    /* SGI IRIX extension essentially
        identical to DWARF3 .debug_pubtypes. */
    struct Dwarf_Section_s de_debug_typenames;
    struct Dwarf_Section_s de_debug_varnames; /* SGI IRIX only. */
    struct Dwarf_Section_s de_debug_weaknames; /* SGI IRIX only. */

    struct Dwarf_Section_s de_debug_ranges;
    /*  Following two part of DebugFission. */
    struct Dwarf_Section_s de_debug_str_offsets;
    struct Dwarf_Section_s de_debug_addr;


    /* Following for the .gdb_index section.  */
    struct Dwarf_Section_s de_debug_gdbindex;

    /*  Types in DWARF5 are in .debug_info
        and in DWARF4 are in .debug_types.
        These indexes first standardized in DWARF5,
        DWARF4 can have them as an extension.
        The next to refer to the DWP index sections and the
        tu and cu indexes sections are distinct in DWARF4 & 5. */
    struct Dwarf_Section_s de_debug_cu_index;
    struct Dwarf_Section_s de_debug_tu_index;

    /*  For non-elf, simply leave the following two structs zeroed and
        they will be ignored. */
    struct Dwarf_Section_s de_elf_symtab;
    struct Dwarf_Section_s de_elf_strtab;

    /*  For a .dwp object file .
        For DWARF4, type units are in .debug_types
            (DWP is a GNU extension in DW4)..
        For DWARF5, type units are in .debug_info.
    */
    Dwarf_Xu_Index_Header  de_cu_hashindex_data;
    Dwarf_Xu_Index_Header  de_tu_hashindex_data;

    void *(*de_copy_word) (void *, const void *, size_t);
    unsigned char de_same_endian;
    unsigned char de_elf_must_close; /* If non-zero, then
        it was dwarf_init (not dwarf_elf_init)
        so must elf_end() */

    /* Default is DW_FRAME_INITIAL_VALUE from header. */
    Dwarf_Half de_frame_rule_initial_value;

    /* Default is   DW_FRAME_LAST_REG_NUM. */
    Dwarf_Half de_frame_reg_rules_entry_count;

    Dwarf_Half de_frame_cfa_col_number;
    Dwarf_Half de_frame_same_value_number;
    Dwarf_Half de_frame_undefined_value_number;

    unsigned char de_big_endian_object; /* Non-zero if big-endian
        object opened. */

    struct Dwarf_dbg_sect_s de_debug_sections[DWARF_MAX_DEBUG_SECTIONS];
    unsigned de_debug_sections_total_entries; /* Number actually used. */

    struct Dwarf_Harmless_s de_harmless_errors;

    struct Dwarf_Printf_Callback_Info_s  de_printf_callback;

};

int dwarf_printf(Dwarf_Debug dbg, const char * format, ...)
#ifdef __GNUC__ /* The following gets us printf-like arg checking. */
    __attribute__ ((format (__printf__, 2, 3)))
#endif
;

typedef struct Dwarf_Chain_s *Dwarf_Chain;
struct Dwarf_Chain_s {
    void *ch_item;
    Dwarf_Chain ch_next;
};

    /* Size of cu header version stamp field. */
#define CU_VERSION_STAMP_SIZE   sizeof(Dwarf_Half)

    /* Size of cu header address size field. */
#define CU_ADDRESS_SIZE_SIZE    sizeof(Dwarf_Small)

void *_dwarf_memcpy_swap_bytes(void *s1, const void *s2, size_t len);

#define ORIGINAL_DWARF_OFFSET_SIZE  4
#define DISTINGUISHED_VALUE  0xffffffff
#define DISTINGUISHED_VALUE_OFFSET_SIZE 8

/*  We don't load the sections until they are needed. This function is
    used to load the section.  */
int _dwarf_load_section(Dwarf_Debug,
    struct Dwarf_Section_s *,
    Dwarf_Error *);


int _dwarf_get_string_base_attr_value(Dwarf_Debug dbg,
    Dwarf_CU_Context context,
    Dwarf_Unsigned *sbase_out,
    Dwarf_Error *error);

int _dwarf_exract_string_offset_via_str_offsets(Dwarf_Debug dbg,
    Dwarf_Small *info_data_ptr,
    Dwarf_Half   attrnum,
    Dwarf_Half   attrform,
    Dwarf_CU_Context cu_context,
    Dwarf_Unsigned *str_sect_offset_out,
    Dwarf_Error *error);


int _dwarf_extract_address_from_debug_addr(Dwarf_Debug dbg,
    Dwarf_CU_Context context,
    Dwarf_Byte_Ptr info_ptr,
    Dwarf_Addr *addr_out,
    Dwarf_Error *error);

int _dwarf_extract_string_offset_via_str_offsets(Dwarf_Debug dbg,
    Dwarf_Small *info_data_ptr,
    Dwarf_Half   attrnum,
    Dwarf_Half   attrform,
    Dwarf_CU_Context cu_context,
    Dwarf_Unsigned *str_sect_offset_out,
    Dwarf_Error *error);

int _dwarf_get_base_and_size_given_signature(Dwarf_CU_Context *context,
    Dwarf_Sig8 *signature_in,
    /* xu_sect_index means DW_SECT_info etc. */
    Dwarf_Unsigned xu_sect_index,
    Dwarf_Unsigned *base_out,
    Dwarf_Unsigned *size_out,
    Dwarf_Error *err);

Dwarf_Bool _dwarf_file_has_debug_fission_cu_index(Dwarf_Debug dbg);
Dwarf_Bool _dwarf_file_has_debug_fission_tu_index(Dwarf_Debug dbg);
Dwarf_Bool _dwarf_file_has_debug_fission_index(Dwarf_Debug dbg);

/* This should only be called on a CU. Never a TU. */
int _dwarf_get_debugfission_for_offset(Dwarf_Debug dbg,
    Dwarf_Off   offset_wanted,
    Dwarf_Debug_Fission_Per_CU *  percu_out,
    Dwarf_Error *error);

/* whichone: must be a valid DW_SECT* macro value. */
Dwarf_Unsigned _dwarf_get_dwp_extra_offset(
    struct Dwarf_Debug_Fission_Per_CU_s* dwp,
    unsigned whichone, Dwarf_Unsigned * size);


int _dwarf_get_fission_addition_die(Dwarf_Die die, int dw_sect_index,
   Dwarf_Unsigned* offset, Dwarf_Unsigned*size,
   Dwarf_Error *error);

Dwarf_Byte_Ptr _dwarf_calculate_section_end_ptr(Dwarf_CU_Context context);

