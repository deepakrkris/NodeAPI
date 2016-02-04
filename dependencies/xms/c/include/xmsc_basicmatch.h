 /*********************************************************************/
 /*                                                                   */
 /*                  IBM Message Service Client for C/C++             */
 /*                                                                   */
 /*  FILE NAME:      xmsc_basicmatch.h                                */
 /*                                                                   */
 /*  DESCRIPTION:    Constants for the basicmatch plugin              */
 /*                                                                   */
 /*********************************************************************/
 /*  <START_COPYRIGHT>                                                */
 /*                                                                   */
 /*  Licensed Materials - Property of IBM                             */
 /*                                                                   */
 /*  5724-I13                                                         */
 /*                                                                   */
 /*  (c) Copyright IBM Corp. 2003, 2008                               */
 /*  All Rights Reserved                                              */
 /*                                                                   */
 /*  U.S. Government Users Restricted Rights - use,                   */
 /*  duplication or disclosure restricted by GSA                      */
 /*  ADP Schedule Contract with IBM Corp.                             */
 /*                                                                   */
 /*  Status: Version 2 Release 0                                      */
 /*  <END_COPYRIGHT>                                                  */
 /*                                                                   */
 /*********************************************************************/
 /*                                                                   */
 /*  FUNCTION:       Defines constants used by the basicmatch         */
 /*                  plugin.                                          */
 /*                                                                   */
 /*                                                                   */
 /*  PROCESSOR:      C                                                */
 /*                                                                   */
 /*********************************************************************/

#if !defined(__XMSC_BASICMATCH_H__)
#define __XMSC_BASICMATCH_H__


/*****************************************************************
 * name of shared object which contains gxisql functionality
 *******************************************************************/

#define XMSC_GXIBASICMATCH_PLUGIN_NAME  XMS_TEXT("gxibasicmatch")

/*****************************************************************
 * plugIn-specific connection factory properties
 *******************************************************************/

  /* none currently defined */

/*****************************************************************
 * plugIn-specific error codes, passed back as extended errors
 *******************************************************************/

#define XMS_E_GXIBASICMATCH_PLUGIN_START     XMS_E_PLUGIN_START+1000

#define XMS_E_GXIBASICMATCH_NULL_INPUT       XMS_E_GXIBASICMATCH_PLUGIN_START +0   /* input string/handle NULL, no info. */
#define XMS_E_GXIBASICMATCH_EMPTY_INPUT      XMS_E_GXIBASICMATCH_PLUGIN_START +1   /* input string/handle empty, no info. */
#define XMS_E_GXIBASICMATCH_INVALID          XMS_E_GXIBASICMATCH_PLUGIN_START +2   /* Selector didn't parse     */

#define XMS_E_GXIBASICMATCH_UNMATCHED_APOSTROPHE XMS_E_GXIBASICMATCH_PLUGIN_START +3 /* ' not matched,
                                                                      * info has %s
                                                                      * lineNumber columnNumber
                                                                      */

#define XMS_E_GXIBASICMATCH_UNMATCHED_QUOTE  XMS_E_GXIBASICMATCH_PLUGIN_START +4   /* " not matched in non-strict mode.
                                                                      * info has %s
                                                                      * lineNumber columnNumber
                                                                      */

#define XMS_E_GXIBASICMATCH_ILLEGAL_QUOTE_STRICT XMS_E_GXIBASICMATCH_PLUGIN_START +5 /* " illegal in strict mode.
                                                                      * info has %s
                                                                      * lineNumber columnNumber
                                                                      */

#define XMS_E_GXIBASICMATCH_ILLEGAL_CHARACTER XMS_E_GXIBASICMATCH_PLUGIN_START +6  /* illegal character.
                                                                      * info has %s
                                                                      * lineNumber columnNumber
                                                                      *  hex-value-of-char.
                                                                      */

#define XMS_E_GXIBASICMATCH_ILLEGAL_JAVA_START_CHR XMS_E_GXIBASICMATCH_PLUGIN_START +7  /* illegal character.
                                                                      * info has %s
                                                                      * lineNumber columnNumber
                                                                      *  hex-value.
                                                                      */

#define XMS_E_GXIBASICMATCH_ESCAPE_INCOMPLETE XMS_E_GXIBASICMATCH_PLUGIN_START +8  /* escape-seq cannot be completed.
                                                                      * info has %s
                                                                      * lineNumber columnNumber
                                                                      */

#define XMS_E_GXIBASICMATCH_ILLEGAL_ESCAPED_OCTAL_CHR XMS_E_GXIBASICMATCH_PLUGIN_START +9 /* illegal escaped octal char.
                                                                        * info has %s
                                                                        * lineNumber columnNumber
                                                                        *  hex-value.
                                                                        */

#define XMS_E_GXIBASICMATCH_ESCAPE_SEQ_OVERFLOW XMS_E_GXIBASICMATCH_PLUGIN_START +10 /* escape-seq > x'FFFF' or x'FFFFFFFF'
                                                                      * info has %s
                                                                      * lineNumber columnNumber
                                                                      */

#define XMS_E_GXIBASICMATCH_INT_FLOAT_PARSE_FAIL XMS_E_GXIBASICMATCH_PLUGIN_START +11  /* parse a float failed.
                                                                      * info has %s
                                                                      * lineNumber columnNumber
                                                                      */

#define XMS_E_GXIBASICMATCH_HEX_PARSE_FAIL   XMS_E_GXIBASICMATCH_PLUGIN_START +12  /* parse a hexadecimel failed.
                                                                      * info has %s
                                                                      * lineNumber columnNumber
                                                                      */

#define XMS_E_GXIBASICMATCH_OCTAL_PARSE_FAIL XMS_E_GXIBASICMATCH_PLUGIN_START +13  /* parse an octal failed.
                                                                      * info has %s
                                                                      * lineNumber columnNumber
                                                                      */

#define XMS_E_GXIBASICMATCH_DECIMAL_PARSE_FAIL XMS_E_GXIBASICMATCH_PLUGIN_START +14 /* parse a decimal failed.
                                                                      * info has %s
                                                                      * lineNumber columnNumber
                                                                      */

#define XMS_E_GXIBASICMATCH_SQL_SYNTAX_ERROR XMS_E_GXIBASICMATCH_PLUGIN_START +15  /* yacc error
                                                                      * info has %s
                                                                      * lineNumber columnNumber
                                                                      *  message.
                                                                      */

#define XMS_E_GXIBASICMATCH_NULL_LITERAL     XMS_E_GXIBASICMATCH_PLUGIN_START +16  /* Literal is NULL
                                                                      * info has %s
                                                                      * lineNumber columnNumber
                                                                      */

#define XMS_E_GXIBASICMATCH_EMPTY_LITERAL    XMS_E_GXIBASICMATCH_PLUGIN_START +17  /* Literal is empty
                                                                      * info has %s
                                                                      * lineNumber columnNumber
                                                                      */

#define XMS_E_GXIBASICMATCH_DIVIDE_BY_ZERO   XMS_E_GXIBASICMATCH_PLUGIN_START +18  /* Division by Zero error
                                                                      * info has %s
                                                                      * lineNumber columnNumber
                                                                      */

#define XMS_E_GXIBASICMATCH_ILLEGAL_STATE    XMS_E_GXIBASICMATCH_PLUGIN_START +19  /* internal error (switch(case))
                                                                      * info has %s
                                                                      * lineNumber columnNumber
                                                                      * filename fileline.
                                                                      */

#define XMS_E_GXIBASICMATCH_BAD_TOPIC        XMS_E_GXIBASICMATCH_PLUGIN_START +20  /* invalid topic name
                                                                      * info has %s
                                                                      * topicname
                                                                      */

#endif /* __XMSSQL_H__ */
