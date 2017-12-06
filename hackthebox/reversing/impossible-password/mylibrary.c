/*****************************************************************************
 * File:    mylibrary.c
 * Purpose: our own library to intercept the strcmp() library function to
 *          one that always returns true!
 * Date:    December 6, 2017
 * Author:  fortyfunbobby
 *****************************************************************************/

#include <stdio.h>
int strcmp(const char *s1, const char *s2) {
  /* always return 0 */
  return 0;
}
