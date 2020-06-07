/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT = 258,
     CHAR = 259,
     IDENTIFIER = 260,
     NUMBER = 261,
     EQUAL = 262,
     END_COMMA = 263,
     OPEN_ROUND = 264,
     CLOSED_ROUND = 265,
     OPEN_SQUARED = 266,
     CLOSED_SQUARED = 267,
     OPEN_BRACKET = 268,
     CLOSED_BRACKET = 269,
     RETURN = 270,
     STRING = 271,
     CH = 272,
     IF = 273,
     ELSE = 274,
     WHILE = 275,
     INC = 276,
     DEC = 277,
     AMP = 278,
     COMMA = 279,
     DF = 280,
     ET = 281,
     LT = 282,
     GT = 283,
     OR = 284,
     AND = 285,
     MINUS = 286,
     PLUS = 287,
     MODULO = 288,
     DIVIDE = 289,
     STAR = 290
   };
#endif
/* Tokens.  */
#define INT 258
#define CHAR 259
#define IDENTIFIER 260
#define NUMBER 261
#define EQUAL 262
#define END_COMMA 263
#define OPEN_ROUND 264
#define CLOSED_ROUND 265
#define OPEN_SQUARED 266
#define CLOSED_SQUARED 267
#define OPEN_BRACKET 268
#define CLOSED_BRACKET 269
#define RETURN 270
#define STRING 271
#define CH 272
#define IF 273
#define ELSE 274
#define WHILE 275
#define INC 276
#define DEC 277
#define AMP 278
#define COMMA 279
#define DF 280
#define ET 281
#define LT 282
#define GT 283
#define OR 284
#define AND 285
#define MINUS 286
#define PLUS 287
#define MODULO 288
#define DIVIDE 289
#define STAR 290




/* Copy the first part of user declarations.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "lexer.h"
#include "Tree.h"
#include "parser.h"
#include "exec.h"

#define RED     "\x1b[31m"
#define RESET   "\x1b[0m"

enum exprType;

int L_DEBUGGING = 0;
int P_DEBUGGING = 0;
int TREE_DEBUGGING = 0;

char * error_string = "";

int yylineno;
ProgramNode * MainNode;
struct ErrorList * Errors;
struct TreeNode * NullTreeNode;
struct TreeNode * return_node;
FILE *yyin;



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 33 "parser.y"
{
    long intValue;
    char * string;
    char charValue;
    struct TreeNode *node;
}
/* Line 193 of yacc.c.  */
#line 203 "parser.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 216 "parser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   688

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNRULES -- Number of states.  */
#define YYNSTATES  183

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    11,    14,    17,    20,
      23,    26,    28,    30,    33,    36,    40,    43,    47,    49,
      53,    56,    58,    62,    66,    69,    71,    73,    76,    78,
      80,    83,    85,    88,    91,    93,    96,    99,   101,   103,
     105,   107,   112,   116,   118,   121,   126,   130,   133,   139,
     144,   148,   150,   152,   158,   163,   167,   171,   175,   177,
     181,   185,   188,   192,   196,   200,   204,   208,   212,   216,
     220,   223,   227,   231,   235,   237,   241,   245,   247,   249,
     252,   255,   257,   259,   261,   263,   265,   267,   269,   272,
     275,   278,   281,   284,   288,   292,   296,   300,   304,   308,
     312,   316,   320,   324,   328,   332,   334,   336,   338,   343
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      37,     0,    -1,    -1,    38,    40,    -1,    40,    -1,    39,
      -1,    38,    39,    -1,    64,     8,    -1,    63,     8,    -1,
      62,     8,    -1,     1,     8,    -1,     1,    -1,    41,    -1,
      40,    41,    -1,    40,     1,    -1,    42,    48,    14,    -1,
      42,    14,    -1,    43,    44,    13,    -1,    64,    -1,     9,
      45,    10,    -1,     9,    10,    -1,    64,    -1,    45,    24,
      64,    -1,    47,    48,    14,    -1,    47,    14,    -1,    13,
      -1,    49,    -1,    48,    49,    -1,    50,    -1,    46,    -1,
      69,     8,    -1,    68,    -1,    64,     8,    -1,    65,     8,
      -1,    61,    -1,    60,     8,    -1,    63,     8,    -1,    52,
      -1,    57,    -1,     8,    -1,     1,    -1,     5,     9,    67,
      10,    -1,     5,     9,    10,    -1,    54,    -1,    54,    53,
      -1,    55,    13,    48,    14,    -1,    55,    13,    14,    -1,
      55,    50,    -1,    56,    58,    13,    48,    14,    -1,    56,
      58,    13,    14,    -1,    56,    58,    50,    -1,    19,    -1,
      18,    -1,    59,    58,    13,    48,    14,    -1,    59,    58,
      13,    14,    -1,    59,    58,    50,    -1,     9,    69,    10,
      -1,     9,    65,    10,    -1,    20,    -1,    65,    24,    65,
      -1,    60,    24,    65,    -1,    62,     8,    -1,    64,    24,
      75,    -1,    63,    24,    75,    -1,    62,    24,    75,    -1,
      62,     7,    69,    -1,    62,     7,    66,    -1,    64,     7,
      69,    -1,    64,     7,    66,    -1,    63,     7,    69,    -1,
      74,    75,    -1,    69,     7,    69,    -1,    65,     7,    69,
      -1,    13,    67,    14,    -1,    69,    -1,    67,    24,    69,
      -1,    15,    69,     8,    -1,    73,    -1,     6,    -1,    32,
       6,    -1,    31,     6,    -1,    75,    -1,    16,    -1,    17,
      -1,    51,    -1,    72,    -1,    70,    -1,    71,    -1,    23,
      75,    -1,    21,    75,    -1,    22,    75,    -1,    75,    21,
      -1,    75,    22,    -1,    69,    32,    69,    -1,    69,    31,
      69,    -1,    69,    35,    69,    -1,    69,    34,    69,    -1,
      69,    33,    69,    -1,     9,    69,    10,    -1,    69,    30,
      69,    -1,    69,    29,    69,    -1,    69,    28,    69,    -1,
      69,    27,    69,    -1,    69,    26,    69,    -1,    69,    25,
      69,    -1,     3,    -1,     4,    -1,     5,    -1,     5,    11,
      69,    12,    -1,     5,    11,    12,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   102,   102,   104,   105,   109,   110,   114,   115,   116,
     117,   118,   122,   123,   124,   128,   129,   133,   137,   141,
     142,   146,   147,   151,   152,   156,   160,   161,   165,   166,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   188,   189,   193,   194,   198,   199,   200,   204,   205,
     206,   210,   214,   218,   219,   220,   224,   225,   229,   233,
     234,   238,   242,   243,   244,   245,   246,   250,   251,   252,
     256,   260,   261,   265,   269,   270,   274,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   293,
     294,   298,   299,   303,   304,   305,   306,   307,   308,   312,
     313,   314,   315,   316,   317,   321,   322,   326,   327,   328
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "CHAR", "IDENTIFIER", "NUMBER",
  "EQUAL", "END_COMMA", "OPEN_ROUND", "CLOSED_ROUND", "OPEN_SQUARED",
  "CLOSED_SQUARED", "OPEN_BRACKET", "CLOSED_BRACKET", "RETURN", "STRING",
  "CH", "IF", "ELSE", "WHILE", "INC", "DEC", "AMP", "COMMA", "DF", "ET",
  "LT", "GT", "OR", "AND", "MINUS", "PLUS", "MODULO", "DIVIDE", "STAR",
  "$accept", "program", "global_scope", "global_statements",
  "function_list", "function", "function_parameters_declaration",
  "function_declaration", "arguments_declaration",
  "arguments_declaration_list", "scope", "start_scope", "statement_list",
  "statement_scope", "statement", "function_call", "if_else_statement",
  "else_statement", "if_statement", "else_declaration", "if_declaration",
  "while_statement", "condition", "while_declaration", "multi_asgn",
  "multi_dec_statement", "multi_dec", "declaration_and_assignment",
  "declaration", "assignment", "array_inizializer", "expr_list",
  "return_statement", "expr", "pre_incdec", "post_incdec", "operation",
  "comparison", "type", "variable", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    37,    37,    37,    38,    38,    39,    39,    39,
      39,    39,    40,    40,    40,    41,    41,    42,    43,    44,
      44,    45,    45,    46,    46,    47,    48,    48,    49,    49,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    51,    51,    52,    52,    53,    53,    53,    54,    54,
      54,    55,    56,    57,    57,    57,    58,    58,    59,    60,
      60,    61,    62,    62,    62,    62,    62,    63,    63,    63,
      64,    65,    65,    66,    67,    67,    68,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    70,
      70,    71,    71,    72,    72,    72,    72,    72,    72,    73,
      73,    73,    73,    73,    73,    74,    74,    75,    75,    75
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     2,     2,     2,     2,
       2,     1,     1,     2,     2,     3,     2,     3,     1,     3,
       2,     1,     3,     3,     2,     1,     1,     2,     1,     1,
       2,     1,     2,     2,     1,     2,     2,     1,     1,     1,
       1,     4,     3,     1,     2,     4,     3,     2,     5,     4,
       3,     1,     1,     5,     4,     3,     3,     3,     1,     3,
       3,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     3,     3,     3,     1,     3,     3,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     1,     4,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    11,   105,   106,     0,     0,     5,     0,    12,     0,
       0,     0,     0,    18,     0,    10,     1,     6,     0,    14,
      13,    18,    40,   107,    78,    39,     0,    25,    16,     0,
      82,    83,    52,    58,     0,     0,     0,     0,     0,    29,
       0,     0,    26,    28,    84,    37,    43,     0,    38,     0,
       0,    34,     0,     0,     0,     0,    31,     0,    86,    87,
      85,    77,    81,     0,     0,     0,     9,     0,     0,     8,
       0,     0,     7,     0,   107,    70,     0,     0,     0,     0,
      89,    90,    88,    80,    79,    24,     0,    15,    27,    51,
      44,     0,     0,     0,     0,    35,     0,    61,    36,    32,
       0,    33,     0,     0,    30,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    91,    92,    20,     0,
      21,    17,     0,    66,    65,    64,    69,    63,    68,    67,
      62,    42,     0,    74,   109,     0,    98,    76,    23,     0,
      47,     0,     0,     0,    50,     0,    55,    60,     0,    72,
      59,    71,   104,   103,   102,   101,   100,    99,    94,    93,
      97,    96,    95,    19,     0,     0,    41,     0,   108,    46,
       0,    57,    56,    49,     0,    54,     0,    22,    73,    75,
      45,    48,    53
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,     9,    10,    64,   119,
      39,    40,    41,    42,    43,    44,    45,    90,    46,    91,
      47,    48,    93,    49,    50,    51,    52,    53,    54,    55,
     123,   132,    56,    57,    58,    59,    60,    61,    14,    62
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -80
static const yytype_int16 yypact[] =
{
     255,    16,   -80,   -80,    20,    97,   -80,   287,   -80,   135,
      60,     1,    34,    37,    52,   -80,   -80,   -80,   319,   -80,
     -80,   -80,   -80,   150,   -80,   -80,   621,   -80,   -80,   621,
     -80,   -80,   -80,   -80,    52,    52,    52,    70,    86,   -80,
     167,   199,   -80,   -80,   -80,   -80,    85,    98,   -80,    98,
      40,   -80,    42,    46,    48,   138,   -80,     4,   -80,   -80,
     -80,   -80,   156,    12,   134,   562,   -80,    52,   621,   -80,
      52,   562,   -80,    52,   143,   -80,   581,   602,   629,    95,
     -80,   -80,   -80,   -80,   -80,   -80,   231,   -80,   -80,   -80,
     -80,   455,   621,   487,   519,   -80,   621,   -80,   -80,   -80,
     621,   -80,   621,   621,   -80,   621,   621,   621,   621,   621,
     621,   621,   621,   621,   621,   621,   -80,   -80,   -80,    50,
     -80,   -80,   621,   -80,   641,   -80,   641,   -80,   -80,   641,
     -80,   -80,    69,   641,   -80,   653,   -80,   -80,   -80,   263,
     -80,    89,    84,   295,   -80,   327,   -80,   153,   531,   641,
     153,   641,   162,   162,   162,   162,   192,   192,    99,    99,
     -80,   -80,   -80,   -80,   206,    81,   -80,   621,   -80,   -80,
     359,   -80,   -80,   -80,   391,   -80,   423,   -80,   -80,   641,
     -80,   -80,   -80
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -80,   -80,   -80,   158,   160,     3,   -80,   -80,   -80,   -80,
     -80,   -80,   -37,   -39,   260,   -80,   -80,   -80,   -80,   -80,
     -80,   -80,   120,   -80,   -80,   -80,    14,    68,     0,   -79,
     103,    57,   -80,   -25,   -80,   -80,   -80,   -80,   -80,    -8
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -5
static const yytype_int16 yytable[] =
{
      13,    78,    88,    86,    79,    13,    75,    21,    65,    66,
      20,   103,   104,   141,    11,     2,     3,   147,    21,    11,
      16,    20,   118,   150,    15,    67,    80,    81,    82,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     124,    68,    69,   126,    71,    72,   129,    88,    95,    65,
      97,   133,   135,    68,    98,    71,    99,    74,    70,   125,
     163,    73,   127,   120,    96,   130,    67,   142,    12,    63,
      70,   148,    73,    12,   164,   149,    83,   148,   151,   166,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   103,    84,   167,   172,   178,   100,   133,     1,   171,
       2,     3,   170,   137,    89,   167,   174,    92,   176,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,    88,   113,   114,   115,    88,    22,    88,     2,     3,
      23,    24,   179,    25,    26,   100,   101,   121,    27,    28,
      29,    30,    31,    32,    77,    33,    34,    35,    36,    76,
     100,    77,   102,    17,   177,    18,    37,    38,    22,    94,
       2,     3,    23,    24,   128,    25,    26,   116,   117,   165,
      27,    85,    29,    30,    31,    32,     0,    33,    34,    35,
      36,   109,   110,   111,   112,   113,   114,   115,    37,    38,
      22,     0,     2,     3,    23,    24,     0,    25,    26,     2,
       3,     0,    27,    87,    29,    30,    31,    32,     0,    33,
      34,    35,    36,   111,   112,   113,   114,   115,     0,     0,
      37,    38,    22,     0,     2,     3,    23,    24,     0,    25,
      26,     0,     0,     0,    27,   138,    29,    30,    31,    32,
       0,    33,    34,    35,    36,    -2,     1,     0,     2,     3,
       0,     0,    37,    38,    22,     0,     2,     3,    23,    24,
       0,    25,    26,     0,     0,     0,    27,   169,    29,    30,
      31,    32,     0,    33,    34,    35,    36,    -4,    19,     0,
       2,     3,     0,     0,    37,    38,    22,     0,     2,     3,
      23,    24,     0,    25,    26,     0,     0,     0,    27,   173,
      29,    30,    31,    32,     0,    33,    34,    35,    36,    -3,
      19,     0,     2,     3,     0,     0,    37,    38,    22,     0,
       2,     3,    23,    24,     0,    25,    26,     0,     0,     0,
      27,   175,    29,    30,    31,    32,     0,    33,    34,    35,
      36,   140,     0,   144,   146,     0,     0,     0,    37,    38,
      22,     0,     2,     3,    23,    24,     0,    25,    26,     0,
       0,     0,    27,   180,    29,    30,    31,    32,     0,    33,
      34,    35,    36,     0,     0,     0,     0,     0,     0,     0,
      37,    38,    22,     0,     2,     3,    23,    24,     0,    25,
      26,     0,     0,     0,    27,   181,    29,    30,    31,    32,
       0,    33,    34,    35,    36,     0,     0,     0,     0,     0,
       0,     0,    37,    38,    22,     0,     2,     3,    23,    24,
       0,    25,    26,     0,     0,     0,    27,   182,    29,    30,
      31,    32,     0,    33,    34,    35,    36,     0,     0,     0,
       0,     0,     0,     0,    37,    38,    22,     0,     2,     3,
      23,    24,     0,    25,    26,     0,     0,     0,   139,     0,
      29,    30,    31,    32,     0,    33,    34,    35,    36,     0,
       0,     0,     0,     0,     0,     0,    37,    38,    22,     0,
       2,     3,    23,    24,     0,    25,    26,     0,     0,     0,
     143,     0,    29,    30,    31,    32,     0,    33,    34,    35,
      36,     0,     0,     0,     0,     0,     0,     0,    37,    38,
      22,     0,     2,     3,    23,    24,     0,    25,    26,     0,
       0,     0,   145,     0,    29,    30,    31,    32,   103,    33,
      34,    35,    36,     0,     0,     0,     0,     0,     0,     0,
      37,    38,     0,     0,     0,     0,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,    23,    24,     0,
       0,    26,     0,     0,     0,   122,     0,     0,    30,    31,
       0,     0,     0,    34,    35,    36,    23,    24,     0,     0,
      26,   131,     0,    37,    38,     0,     0,    30,    31,     0,
       0,     0,    34,    35,    36,     0,     0,    23,    24,     0,
       0,    26,    37,    38,   134,     0,     0,     0,    30,    31,
       0,     0,     0,    34,    35,    36,    23,    24,     0,     0,
      26,     0,     0,    37,    38,     0,     0,    30,    31,   136,
       0,     0,    34,    35,    36,     0,     0,     0,     0,     0,
       0,     0,    37,    38,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   168,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,     0,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115
};

static const yytype_int16 yycheck[] =
{
       0,    26,    41,    40,    29,     5,    14,     7,     7,     8,
       7,     7,     8,    92,     0,     3,     4,    96,    18,     5,
       0,    18,    10,   102,     8,    24,    34,    35,    36,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      65,     7,     8,    68,     7,     8,    71,    86,     8,     7,
       8,    76,    77,     7,     8,     7,     8,     5,    24,    67,
      10,    24,    70,    63,    24,    73,    24,    92,     0,     9,
      24,    96,    24,     5,    24,   100,     6,   102,   103,    10,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,     7,     6,    24,    10,    14,     7,   122,     1,    10,
       3,     4,   139,     8,    19,    24,   143,     9,   145,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,   170,    33,    34,    35,   174,     1,   176,     3,     4,
       5,     6,   167,     8,     9,     7,     8,    13,    13,    14,
      15,    16,    17,    18,    11,    20,    21,    22,    23,     9,
       7,    11,    24,     5,   164,     5,    31,    32,     1,    49,
       3,     4,     5,     6,    71,     8,     9,    21,    22,   122,
      13,    14,    15,    16,    17,    18,    -1,    20,    21,    22,
      23,    29,    30,    31,    32,    33,    34,    35,    31,    32,
       1,    -1,     3,     4,     5,     6,    -1,     8,     9,     3,
       4,    -1,    13,    14,    15,    16,    17,    18,    -1,    20,
      21,    22,    23,    31,    32,    33,    34,    35,    -1,    -1,
      31,    32,     1,    -1,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    -1,    13,    14,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,     0,     1,    -1,     3,     4,
      -1,    -1,    31,    32,     1,    -1,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    -1,    13,    14,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,     0,     1,    -1,
       3,     4,    -1,    -1,    31,    32,     1,    -1,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    -1,    13,    14,
      15,    16,    17,    18,    -1,    20,    21,    22,    23,     0,
       1,    -1,     3,     4,    -1,    -1,    31,    32,     1,    -1,
       3,     4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,
      13,    14,    15,    16,    17,    18,    -1,    20,    21,    22,
      23,    91,    -1,    93,    94,    -1,    -1,    -1,    31,    32,
       1,    -1,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    -1,    13,    14,    15,    16,    17,    18,    -1,    20,
      21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    32,     1,    -1,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    -1,    13,    14,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,     1,    -1,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    -1,    13,    14,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    32,     1,    -1,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    -1,    13,    -1,
      15,    16,    17,    18,    -1,    20,    21,    22,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,     1,    -1,
       3,     4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,
      13,    -1,    15,    16,    17,    18,    -1,    20,    21,    22,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,
       1,    -1,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    -1,    13,    -1,    15,    16,    17,    18,     7,    20,
      21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    32,    -1,    -1,    -1,    -1,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,     5,     6,    -1,
      -1,     9,    -1,    -1,    -1,    13,    -1,    -1,    16,    17,
      -1,    -1,    -1,    21,    22,    23,     5,     6,    -1,    -1,
       9,    10,    -1,    31,    32,    -1,    -1,    16,    17,    -1,
      -1,    -1,    21,    22,    23,    -1,    -1,     5,     6,    -1,
      -1,     9,    31,    32,    12,    -1,    -1,    -1,    16,    17,
      -1,    -1,    -1,    21,    22,    23,     5,     6,    -1,    -1,
       9,    -1,    -1,    31,    32,    -1,    -1,    16,    17,    10,
      -1,    -1,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    12,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,    37,    38,    39,    40,    41,    42,
      43,    62,    63,    64,    74,     8,     0,    39,    40,     1,
      41,    64,     1,     5,     6,     8,     9,    13,    14,    15,
      16,    17,    18,    20,    21,    22,    23,    31,    32,    46,
      47,    48,    49,    50,    51,    52,    54,    56,    57,    59,
      60,    61,    62,    63,    64,    65,    68,    69,    70,    71,
      72,    73,    75,     9,    44,     7,     8,    24,     7,     8,
      24,     7,     8,    24,     5,    75,     9,    11,    69,    69,
      75,    75,    75,     6,     6,    14,    48,    14,    49,    19,
      53,    55,     9,    58,    58,     8,    24,     8,     8,     8,
       7,     8,    24,     7,     8,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    21,    22,    10,    45,
      64,    13,    13,    66,    69,    75,    69,    75,    66,    69,
      75,    10,    67,    69,    12,    69,    10,     8,    14,    13,
      50,    65,    69,    13,    50,    13,    50,    65,    69,    69,
      65,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    10,    24,    67,    10,    24,    12,    14,
      48,    10,    10,    14,    48,    14,    48,    64,    14,    69,
      14,    14,    14
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 5:
#line 109 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Global_scope_body found\n");;}
    break;

  case 6:
#line 110 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Global_scope_body found\n");;}
    break;

  case 7:
#line 114 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Global declaration statement found\n");                 Add_Node_Tree((yyvsp[(1) - (2)].node));  exec_DclN((yyvsp[(1) - (2)].node));}
    break;

  case 8:
#line 115 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Global declaration and assignment statement found\n");  Add_Node_Tree((yyvsp[(1) - (2)].node));  exec_DclN_Asgn((yyvsp[(1) - (2)].node));;}
    break;

  case 9:
#line 116 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Global multi declaration statement found\n");           Add_Node_Tree((yyvsp[(1) - (2)].node));  exec_Multi_DclN((yyvsp[(1) - (2)].node));;}
    break;

  case 10:
#line 117 "parser.y"
    {printf("%s global stmt error %s : \'%s\'\n", RED, RESET, error_string); yyerrok; yyclearin;;}
    break;

  case 11:
#line 118 "parser.y"
    {yyerrok; yyclearin;;}
    break;

  case 12:
#line 122 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Function list1 found\n");;}
    break;

  case 13:
#line 123 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Function list2 found\n");;}
    break;

  case 14:
#line 124 "parser.y"
    {yyerrok; yyclearin;;}
    break;

  case 15:
#line 128 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Function found\n"); if(Function_End())YYACCEPT;;}
    break;

  case 16:
#line 129 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Function found\n"); if(Function_End())YYACCEPT;;}
    break;

  case 17:
#line 133 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Function parameters declaration found\n");  create_FunctionNode((yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node));    if(TREE_DEBUGGING) printf("TREE: Function node created\n");;}
    break;

  case 18:
#line 137 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Function declaration found\n");  FunNodeList_Add ((yyvsp[(1) - (1)].node)); (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 19:
#line 141 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: arguments_declaration1 found\n");        (yyval.node) = (yyvsp[(2) - (3)].node);;}
    break;

  case 20:
#line 142 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: arguments_declaration2 found\n");        (yyval.node) = create_Arg_ListNode(NULL, NULL);;}
    break;

  case 21:
#line 146 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: arguments_declaration_list1 found\n");   (yyval.node) = create_Arg_ListNode(NULL, (yyvsp[(1) - (1)].node));;}
    break;

  case 22:
#line 147 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: arguments_declaration_list2 found\n");   (yyval.node) = create_Arg_ListNode((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));;}
    break;

  case 23:
#line 151 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: End of the scope found\n");              Propagate_return_flag(); ScopeStack_Pop(MainNode -> actual_stack);;}
    break;

  case 24:
#line 152 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: New empty scope found\n");               Propagate_return_flag(); ScopeStack_Pop(MainNode -> actual_stack);;}
    break;

  case 25:
#line 156 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Start of the scope found\n");            {(yyval.node) = create_ScopeNode(); Add_Node_Tree((yyval.node)); SetAs_ActualScope((yyval.node), Check_activation());} if(TREE_DEBUGGING) printf("TREE: Scope node created\n");;}
    break;

  case 30:
#line 172 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Expr statement found\n");                                        Add_Node_Tree((yyvsp[(1) - (2)].node)); Warning_Unused((yyvsp[(1) - (2)].node)); if(Check_activation()) exec_Expression((yyvsp[(1) - (2)].node));;}
    break;

  case 31:
#line 173 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Return statement found\n");                                      Add_Node_Tree((yyvsp[(1) - (1)].node)); Update_return_flag(); if(Check_activation()) {return_node = exec_return((yyvsp[(1) - (1)].node)); Return_main(return_node); YYACCEPT;};}
    break;

  case 32:
#line 174 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Declaration statement found\n");                                 Add_Node_Tree((yyvsp[(1) - (2)].node)); exec_DclN((yyvsp[(1) - (2)].node));;}
    break;

  case 33:
#line 175 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Assignment statement found\n");                                  Add_Node_Tree((yyvsp[(1) - (2)].node)); if(Check_activation()) exec_Asgn((yyvsp[(1) - (2)].node));;}
    break;

  case 34:
#line 176 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Multi declaration statement found\n");                           Add_Node_Tree((yyvsp[(1) - (1)].node)); if(Check_activation()) exec_Multi_DclN((yyvsp[(1) - (1)].node));;}
    break;

  case 35:
#line 177 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Multi assignment statement found\n");                            Add_Node_Tree((yyvsp[(1) - (2)].node)); if(Check_activation()) exec_Multi_Asgn((yyvsp[(1) - (2)].node));;}
    break;

  case 36:
#line 178 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Declaration and assignment statement found\n");                  Add_Node_Tree((yyvsp[(1) - (2)].node)); if(Check_activation()) exec_DclN_Asgn((yyvsp[(1) - (2)].node));;}
    break;

  case 37:
#line 179 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: IF statement statement found\n");                                Add_Node_Tree((yyvsp[(1) - (1)].node)); if(Check_activation()) {return_node = exec_ifElse((yyvsp[(1) - (1)].node), 0); if(Return_main(return_node)) YYACCEPT;};}
    break;

  case 38:
#line 180 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: WHILE statement statement found\n");                             Add_Node_Tree((yyvsp[(1) - (1)].node)); if(Check_activation()) {return_node = exec_while((yyvsp[(1) - (1)].node), 0);  if(Return_main(return_node)) YYACCEPT;};}
    break;

  case 39:
#line 181 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Empty statement found\n");;}
    break;

  case 40:
#line 182 "parser.y"
    {printf("STATEMENT ERRATO\n"); yyerrok; yyclearin;;}
    break;

  case 41:
#line 188 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Function call1 found\n");                (yyval.node) = create_Function_CallNode((yyvsp[(1) - (4)].string), (yyvsp[(3) - (4)].node));                   if(TREE_DEBUGGING) printf("TREE: Function call statement node created\n");;}
    break;

  case 42:
#line 189 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Function call2 found\n");                (yyval.node) = create_Function_CallNode((yyvsp[(1) - (3)].string), NULL);                 if(TREE_DEBUGGING) printf("TREE: Function call statement node created\n");;}
    break;

  case 43:
#line 193 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: If-else statement1 found\n");            (yyval.node) = create_IfElseNode((yyvsp[(1) - (1)].node), NULL);                        if(TREE_DEBUGGING) printf("TREE: If-else statement node created\n");;}
    break;

  case 44:
#line 194 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: If-else statement1 found\n");            (yyval.node) = create_IfElseNode((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));                          if(TREE_DEBUGGING) printf("TREE: If-else statement node created\n");;}
    break;

  case 45:
#line 198 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Else statement1 found\n");               (yyval.node) = create_ElseNode((yyvsp[(1) - (4)].node));                                if(TREE_DEBUGGING) printf("TREE: Else statement node created\n");;}
    break;

  case 46:
#line 199 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Else statement1 found\n");               (yyval.node) = create_ElseNode((yyvsp[(1) - (3)].node));                                if(TREE_DEBUGGING) printf("TREE: Else statement node created\n");;}
    break;

  case 47:
#line 200 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Else statement2 found\n");               (yyval.node) = create_ElseNode((yyvsp[(1) - (2)].node));                                if(TREE_DEBUGGING) printf("TREE: Else statement node created\n");;}
    break;

  case 48:
#line 204 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: If statement1 found\n");                 (yyval.node) = create_IfNode((yyvsp[(1) - (5)].node),(yyvsp[(2) - (5)].node));                               if(TREE_DEBUGGING) printf("TREE: If statement node created\n");;}
    break;

  case 49:
#line 205 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: If statement2 found\n");                 (yyval.node) = create_IfNode((yyvsp[(1) - (4)].node),(yyvsp[(2) - (4)].node));                               if(TREE_DEBUGGING) printf("TREE: If statement node created\n");;}
    break;

  case 50:
#line 206 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: If statement3 found\n");                 (yyval.node) = create_IfNode((yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node));                               if(TREE_DEBUGGING) printf("TREE: If statement node created\n");;}
    break;

  case 51:
#line 210 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Else declaration found\n");              (yyval.node) = create_ElseDeclaration();                           if(TREE_DEBUGGING) printf("TREE: Else node created\n");;}
    break;

  case 52:
#line 214 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: If declaration found\n");                (yyval.node) = create_IfDeclaration();                             if(TREE_DEBUGGING) printf("TREE: If node created\n");;}
    break;

  case 53:
#line 218 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: While statement1 found\n");              (yyval.node) = create_WhileNode((yyvsp[(1) - (5)].node),(yyvsp[(2) - (5)].node));                            if(TREE_DEBUGGING) printf("TREE: While statement node created\n");;}
    break;

  case 54:
#line 219 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: While statement2 found\n");              (yyval.node) = create_WhileNode((yyvsp[(1) - (4)].node),(yyvsp[(2) - (4)].node));                            if(TREE_DEBUGGING) printf("TREE: While statement node created\n");;}
    break;

  case 55:
#line 220 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: While statement3 found\n");              (yyval.node) = create_WhileNode((yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node));                            if(TREE_DEBUGGING) printf("TREE: While statement node created\n");;}
    break;

  case 56:
#line 224 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: While condition1 found\n");               (yyval.node) = create_Condition((yyvsp[(2) - (3)].node));                              if(TREE_DEBUGGING) printf("TREE: Condition node created\n");;}
    break;

  case 57:
#line 225 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: While condition2 found\n");               (yyval.node) = create_Condition((yyvsp[(2) - (3)].node));                              if(TREE_DEBUGGING) printf("TREE: Condition node created\n");;}
    break;

  case 58:
#line 229 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: While declaration found\n");             (yyval.node) = create_WhileDeclaration();                          if(TREE_DEBUGGING) printf("TREE: While node created\n");;}
    break;

  case 59:
#line 233 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Multi assignment1 found\n");             (yyval.node) = create_MultiAssignment((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));                     if(TREE_DEBUGGING) printf("TREE: Multi assignment node created\n");;}
    break;

  case 60:
#line 234 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Multi assignment2 found\n");             (yyval.node) = create_MultiAssignment((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));                     if(TREE_DEBUGGING) printf("TREE: Multi assignment node created\n");;}
    break;

  case 61:
#line 238 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Multi declaration statement found\n");   (yyval.node) = create_MultiDeclarationStatement((yyvsp[(1) - (2)].node));               if(TREE_DEBUGGING) printf("TREE: Multi declaration node created\n");;}
    break;

  case 62:
#line 242 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Multi declaration1 found\n");            (yyval.node) = create_MultiDeclaration((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), 1);                 if(TREE_DEBUGGING) printf("TREE: Multi declaration node created\n");;}
    break;

  case 63:
#line 243 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Multi declaration2 found\n");            (yyval.node) = create_MultiDeclaration((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), 1);                 if(TREE_DEBUGGING) printf("TREE: Multi declaration node created\n");;}
    break;

  case 64:
#line 244 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Multi declaration3 found\n");            (yyval.node) = create_MultiDeclaration((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), 1);                 if(TREE_DEBUGGING) printf("TREE: Multi declaration node created\n");;}
    break;

  case 65:
#line 245 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Multi declaration4 found\n");            (yyval.node) = create_MultiDeclaration((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), 0);                 if(TREE_DEBUGGING) printf("TREE: Multi declaration node created\n");;}
    break;

  case 66:
#line 246 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Multi declaration5 found\n");            (yyval.node) = create_MultiDeclaration((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), 0);                 if(TREE_DEBUGGING) printf("TREE: Multi declaration node created\n");;}
    break;

  case 67:
#line 250 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: declaration and assignment 1 found\n");  (yyval.node) = create_Declaration_AssignmentNode ((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));         if(TREE_DEBUGGING) printf("TREE: Declaration and Assignment node created\n");;}
    break;

  case 68:
#line 251 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: declaration and assignment 2 found\n");  (yyval.node) = create_Declaration_AssignmentNode ((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));         if(TREE_DEBUGGING) printf("TREE: Declaration and Assignment node created\n");;}
    break;

  case 69:
#line 252 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: declaration and assignment 3 found\n");  (yyval.node) = create_Declaration_AssignmentNode ((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));         if(TREE_DEBUGGING) printf("TREE: Declaration and Assignment node created\n");;}
    break;

  case 70:
#line 256 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: declaration found\n");                   (yyval.node) = create_DeclarationNode((yyvsp[(1) - (2)].intValue), (yyvsp[(2) - (2)].node));                     if(TREE_DEBUGGING) printf("TREE: Declaration node created\n");;}
    break;

  case 71:
#line 260 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: assignment1 found\n");                   (yyval.node) = create_AssignmentNode(MainNode, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));            if(TREE_DEBUGGING) printf("TREE: Assignment node created\n");;}
    break;

  case 72:
#line 261 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: assignment2 found\n");                   (yyval.node) = create_AssignmentNode(MainNode, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));            if(TREE_DEBUGGING) printf("TREE: Assignment node created\n");;}
    break;

  case 73:
#line 265 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: array initializer found\n");             (yyval.node)=(yyvsp[(2) - (3)].node);;}
    break;

  case 74:
#line 269 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: expression1 list found\n");              (yyval.node) = create_Expr_ListNode(NULL, (yyvsp[(1) - (1)].node));                     if(TREE_DEBUGGING) printf("TREE: Expression list node created\n");;}
    break;

  case 75:
#line 270 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: expression2 list found\n");              (yyval.node) = create_Expr_ListNode((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));                       if(TREE_DEBUGGING) printf("TREE: Expression list node created\n");;}
    break;

  case 76:
#line 274 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: return statement1 found\n");             (yyval.node) = create_ReturnNode((yyvsp[(2) - (3)].node));                              if(TREE_DEBUGGING) printf("TREE: Return node created\n");;}
    break;

  case 77:
#line 278 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: comparison -> expr\n");                  (yyval.node) = (yyvsp[(1) - (1)].node);                                                 if(TREE_DEBUGGING) printf("TREE: Expr node compare type created\n");;}
    break;

  case 78:
#line 279 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: integer -> expr\n");                     (yyval.node) = create_ExprNode(NUM, (yyvsp[(1) - (1)].intValue), NULL, NULL, NULL, 0);      if(TREE_DEBUGGING) printf("TREE: Expr node integer type created\n");;}
    break;

  case 79:
#line 280 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: positive integer -> expr\n");            (yyval.node) = create_ExprNode(NUM, (yyvsp[(2) - (2)].intValue), NULL, NULL, NULL, 0);      if(TREE_DEBUGGING) printf("TREE: Expr node integer type created\n");;}
    break;

  case 80:
#line 281 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: negative integer -> expr\n");            (yyval.node) = create_ExprNode(NUM, -(yyvsp[(2) - (2)].intValue), NULL, NULL, NULL, 0);     if(TREE_DEBUGGING) printf("TREE: Expr node integer type created\n");;}
    break;

  case 81:
#line 282 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: variable -> expr\n");                    Check_VariableConcistency((yyvsp[(1) - (1)].node)); (yyval.node) = (yyvsp[(1) - (1)].node);                  if(TREE_DEBUGGING) printf("TREE: Expr node variable type created\n");;}
    break;

  case 82:
#line 283 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: expr STRING -> expr\n");                 (yyval.node) = create_ExprNode(STR, 0, (yyvsp[(1) - (1)].string), NULL, NULL, 0);         if(TREE_DEBUGGING) printf("TREE: Expr node string type created\n");;}
    break;

  case 83:
#line 284 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: expr character -> expr\n");              (yyval.node) = create_ExprNode(C, 0, &(yyvsp[(1) - (1)].charValue), NULL, NULL, 0);          if(TREE_DEBUGGING) printf("TREE: Expr node char type created\n");;}
    break;

  case 84:
#line 285 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: expr function_call -> expr\n");          (yyval.node) = (yyvsp[(1) - (1)].node);                                                 if(TREE_DEBUGGING) printf("TREE: Expr node function call type created\n");;}
    break;

  case 85:
#line 286 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: expr PLUS expr -> expr\n");              (yyval.node) = (yyvsp[(1) - (1)].node);                                                 if(TREE_DEBUGGING) printf("TREE: Expr node operation type created\n");;}
    break;

  case 86:
#line 287 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: pre increment_decrement -> expr\n");     (yyval.node) = (yyvsp[(1) - (1)].node);                                                 if(TREE_DEBUGGING) printf("TREE: Expr node pre-increment/decrement type created\n");;}
    break;

  case 87:
#line 288 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: post increment_decrement -> expr\n");    (yyval.node) = (yyvsp[(1) - (1)].node);                                                 if(TREE_DEBUGGING) printf("TREE: Expr node post-increment/decrement type created\n");;}
    break;

  case 88:
#line 289 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: variable address -> expr\n");            (yyval.node) = create_ExprNode(ADD, 0, NULL, (yyvsp[(2) - (2)].node), NULL, 0);         if(TREE_DEBUGGING) printf("TREE: Expr node variable address type created\n");;}
    break;

  case 89:
#line 293 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: pre increment ++ found\n");              (yyval.node) = create_IncDecNode(PI, (yyvsp[(2) - (2)].node));                          if(TREE_DEBUGGING) printf("TREE: Expr node post increment type created\n");;}
    break;

  case 90:
#line 294 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: pre decrement -- found\n");              (yyval.node) = create_IncDecNode(PD, (yyvsp[(2) - (2)].node));                          if(TREE_DEBUGGING) printf("TREE: Expr node post decrement type created\n");;}
    break;

  case 91:
#line 298 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: post increment ++ found\n");             (yyval.node) = create_IncDecNode(IP, (yyvsp[(1) - (2)].node));                          if(TREE_DEBUGGING) printf("TREE: Expr node post increment type created\n");;}
    break;

  case 92:
#line 299 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: post decrement -- found\n");             (yyval.node) = create_IncDecNode(DP, (yyvsp[(1) - (2)].node));                          if(TREE_DEBUGGING) printf("TREE: Expr node post decrement type created\n");;}
    break;

  case 93:
#line 303 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: expr PLUS expr -> operation\n");         (yyval.node) = create_OperationNode((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), SUM);                if(TREE_DEBUGGING) printf("TREE: Expr node plus type created\n");;}
    break;

  case 94:
#line 304 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: expr MINUS expr -> operation\n");        (yyval.node) = create_OperationNode((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), DIF);                if(TREE_DEBUGGING) printf("TREE: Expr node difference type created\n");;}
    break;

  case 95:
#line 305 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: expr STAR expr -> operation\n");         (yyval.node) = create_OperationNode((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), TIM);                if(TREE_DEBUGGING) printf("TREE: Expr node times type created\n");;}
    break;

  case 96:
#line 306 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: expr DIVIDE expr -> operation\n");       (yyval.node) = create_OperationNode((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), DIV);                if(TREE_DEBUGGING) printf("TREE: Expr node divide type created\n");;}
    break;

  case 97:
#line 307 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: expr MODULO expr -> operation\n");       (yyval.node) = create_OperationNode((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), MOD);                if(TREE_DEBUGGING) printf("TREE: Expr node modulo type created\n");;}
    break;

  case 98:
#line 308 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: ( expr ) -> operation\n");               (yyval.node) = create_OperationNode((yyvsp[(2) - (3)].node), (yyvsp[(2) - (3)].node), RND);                if(TREE_DEBUGGING) printf("TREE: Expr node round brackets type created\n");;}
    break;

  case 99:
#line 312 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: AND -> comparison\n");                   (yyval.node) = create_ComparisonNode((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), AND_);              if(TREE_DEBUGGING) printf("TREE: Expr node and type created\n");;}
    break;

  case 100:
#line 313 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: OR -> comparison\n");                    (yyval.node) = create_ComparisonNode((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), OR_);               if(TREE_DEBUGGING) printf("TREE: Expr node or type created\n");;}
    break;

  case 101:
#line 314 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: GT -> comparison\n");                    (yyval.node) = create_ComparisonNode((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), GREAT_);            if(TREE_DEBUGGING) printf("TREE: Expr node greater than type created\n");;}
    break;

  case 102:
#line 315 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: LT -> comparison\n");                    (yyval.node) = create_ComparisonNode((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), LESS_);             if(TREE_DEBUGGING) printf("TREE: Expr node less then type created\n");;}
    break;

  case 103:
#line 316 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: ET -> comparison\n");                    (yyval.node) = create_ComparisonNode((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), EQUAL_);            if(TREE_DEBUGGING) printf("TREE: Expr node equal to type created\n");;}
    break;

  case 104:
#line 317 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: DF -> comparison\n");                    (yyval.node) = create_ComparisonNode((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), DIFF_);             if(TREE_DEBUGGING) printf("TREE: Expr node different from type created\n");;}
    break;

  case 105:
#line 321 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: INT -> type\n");                         (yyval.intValue) = INT_; ;}
    break;

  case 106:
#line 322 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: CHAR -> type\n");                        (yyval.intValue) = CHAR_;;}
    break;

  case 107:
#line 326 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: identifier -> variable\n");              (yyval.node) = create_ExprNode(ID, 0, (yyvsp[(1) - (1)].string), NULL, NULL, 0);        if(TREE_DEBUGGING) printf("TREE: Variable node identifier type created\n");;}
    break;

  case 108:
#line 327 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: array -> variable\n");                   (yyval.node) = create_ExprNode(VEC, 0, (yyvsp[(1) - (4)].string), (yyvsp[(3) - (4)].node), NULL, 0);         if(TREE_DEBUGGING) printf("TREE: Variable node array type created\n");;}
    break;

  case 109:
#line 328 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: array [] -> variable\n");                (yyval.node) = create_ExprNode(VEC, 0, (yyvsp[(1) - (3)].string), NULL, NULL, 0);       if(TREE_DEBUGGING) printf("TREE: Variable node array type created\n");;}
    break;


/* Line 1267 of yacc.c.  */
#line 2191 "parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 331 "parser.y"


/* EPILOGO */



  int yyerror (const char * error) {
    printf ("%s syntax error found -> \'%s\'.\n", ErrorMsg(), yytext);
    /*int size = strlen(error_string) + strlen(yytext);
    char * str = (char*)malloc(sizeof(char) * size);
    strcpy(str, error_string);
    strcat(str, yytext);
    if (strlen(yytext) != 1) free(error_string);
    error_string = str;*/
  }


////////////////////  arguments_declaration_list PRODUCTION  ///////////////////
struct TreeNode * create_Arg_ListNode(struct TreeNode * arg_list, struct TreeNode * arg){

  // first element of the list
  if (arg_list == NULL){

    struct TreeNode * newTreeNode = TreeNodeInitialization (); // generic Tree Node memory space allocation
    // Linking specific node to generic Tree Node
    newTreeNode -> nodeType = ArgLst;

    if (arg != NULL){

      if (arg -> node.DclN -> arrayDim != NULL){ if (!IsCostant(arg -> node.DclN -> arrayDim)) arg -> node.DclN -> ignore = 1;}
      else if (arg -> node.DclN -> arrayDim == NULL && (arg -> node.DclN -> type == INT_V_ || arg -> node.DclN -> type == CHAR_V_)){
        arg -> node.DclN -> arrayDim = create_ExprNode(NUM, 0, NULL, NULL, NULL, 0);
        arg -> node.DclN -> ignore = 1;
      }

      exec_DclN(arg);

      TreeNodeList_Add(newTreeNode -> child_list, arg);
      return newTreeNode;
    }
    // in case of 0 arguments
    else return newTreeNode;
  }
  else{

    if (arg -> node.DclN -> arrayDim != NULL){ if (!IsCostant(arg -> node.DclN -> arrayDim)) arg -> node.DclN -> ignore = 1;}
    else if (arg -> node.DclN -> arrayDim == NULL && (arg -> node.DclN -> type == INT_V_ || arg -> node.DclN -> type == CHAR_V_)){
      arg -> node.DclN -> arrayDim = create_ExprNode(NUM, 0, NULL, NULL, NULL, 0);
      arg -> node.DclN -> ignore = 1;
    }

    exec_DclN(arg);

    TreeNodeList_Add(arg_list->child_list, arg);
    return arg_list;
  }
}

////////////////////  SCOPE PRODUCTION /////////////////////////////////////////

struct TreeNode * create_ScopeNode(){

  struct TreeNode * newTreeNode = TreeNodeInitialization (); // generic Tree Node memory space allocation

  // Linking specific node to generic Tree Node
  newTreeNode -> nodeType = Scope;
  newTreeNode -> node.ST = SymbolTable_Set();

  return newTreeNode;
}

////////////////////  expr_list PRODUCTION  ////////////////////////////////////

struct TreeNode * create_Expr_ListNode(struct TreeNode * expr_list, struct TreeNode * expr){

  if (expr -> nodeType == Expr){
    // first expression of the list
    if (expr_list == NULL){ // first element of the list

      struct TreeNode * newTreeNode = TreeNodeInitialization (); // generic Tree Node memory space allocation
      // Linking specific node to generic Tree Node
      newTreeNode -> nodeType = ExprLst;
      TreeNodeList_Add(newTreeNode -> child_list, expr);
      return newTreeNode;
    }
    // subsequent expression of the list
    else{
      if( expr_list -> nodeType == ExprLst){
        TreeNodeList_Add(expr_list -> child_list, expr);
        return expr_list;
      }
      else{
        printf("%s create_Expr_ListNode - unexpected Tree Node type. Expected ExprLst, found %s.\n", ErrorMsg(), NodeTypeString(expr_list));
        exit(EXIT_FAILURE);
      }
    }
  }
  else{
    printf("%s create_Expr_ListNode - unexpected Tree Node type. Expected Expr, found %s.\n", ErrorMsg(), NodeTypeString(expr));
    exit(EXIT_FAILURE);
  }
}

////////////////////  function_call PRODUCTION  ////////////////////////////////

struct TreeNode * create_Function_CallNode(char * function_id, struct TreeNode * expr_list){

  if (expr_list != NULL) Check_NodeType(ExprLst, expr_list, "create_Function_CallNode");

  if (!strcmp(function_id, "printf")){
    struct TreeNode * node = create_ExprNode(FC, 0, "printf", expr_list, NULL, 0);
    Check_PrintfCallConcistency(node);
    return node;
  }
  else if(!strcmp(function_id, "scanf")){
    struct TreeNode * node = create_ExprNode(FC, 0, "scanf", expr_list, NULL, 0);
    Check_ScanfCallConcistency(node);
    return node;
  }
  else{
    struct TreeNode * node = create_ExprNode(FC, 0, function_id, expr_list, NULL, 0);
    Check_FunctionCallConcistency(node);
    return node;
  }
}

////////////////////  comparison PRODUCTION  ///////////////////////////////////

struct TreeNode * create_ComparisonNode(struct TreeNode * first, struct TreeNode * second, enum cmpType cmptype){

  if (first == NULL || second == NULL) {
      printf("%s create_ComparisonNode - comparison missing one or two expressions\n", ErrorMsg());
      exit(EXIT_FAILURE);
    }
    else{

      struct TreeNode * node = create_ExprNode(CMP, 0, NULL, first, second, cmptype);
      Check_ComparisonConcistency(node);

      return node;
    }
}

////////////////////  function node PRODUCTION  ////////////////////////////////

void create_FunctionNode(struct TreeNode * declaration, struct TreeNode * parameters){

  // check parameters
  Check_NodeType(DclN, declaration, "create_functionNode");
  Check_NodeType(ArgLst, parameters, "create_functionNode");

  Add_Node_Tree(parameters);

  char * fun_identifier = TreeNode_Identifier(declaration);

  if (!strcmp("main", fun_identifier)){
    // main arguments warning
    if (parameters -> child_list -> elements != 0) printf("%s this interpreter does not support main function arguments. \nArguments will be ignored.\n", WarnMsg());
    // main function scope must be active
    Scope_Activation();
    // there's a main function in the file
    MainNode -> main_flag = 1;
  }
}

////////////////////  if PRODUCTION  ///////////////////////////////////////////

struct TreeNode * create_IfElseNode(struct TreeNode * if_node, struct TreeNode * else_node){

  Check_NodeType(If, if_node, "create_IfElseNode");

  // creating a generic Tree Node with memory allocation
  struct TreeNode * newIfElseNode = TreeNodeInitialization();
  // Tree Node Type
  newIfElseNode -> nodeType = IfElse;
  // linking if node to if-else node
  TreeNodeList_Add(newIfElseNode -> child_list, if_node);

  // if there's an else condition
  if (else_node != NULL){
    // else_node must be an Else node
    Check_NodeType(Else, else_node, "create_IfElseNode");
    // linking else node to the if-else node
    TreeNodeList_Add(newIfElseNode -> child_list, else_node);
  }

  // return flag check
  char if_return_flag = Check_return_statement(if_node -> child_list -> first);
  char else_return_flag;
  if (else_node != NULL) else_return_flag = Check_return_statement(else_node -> child_list -> first);


  if (if_return_flag == 1 && else_return_flag == 1)
    MainNode -> actual_stack -> top -> return_flag = 1;

  return newIfElseNode;
}

struct TreeNode * create_ElseNode (struct TreeNode * else_node){

  Check_NodeType(Else, else_node, "create_ElseNode");
  // else scope is ended
  ScopeStack_Pop(MainNode -> actual_stack);

  return else_node;
}

struct TreeNode * create_ElseDeclaration(){

  // creating a generic Tree Node with memory allocation
  struct TreeNode * newElseNode = TreeNodeInitialization();
  // Tree Node Type
  newElseNode -> nodeType = Else;

  // creating else scope
  struct TreeNode * ElseScope = create_ScopeNode();
  // linking else scope to the while node
  TreeNodeList_Add(newElseNode -> child_list, ElseScope);
  // setting else scope as new actual scope
  // else scope is inactive by default
  SetAs_ActualScope(ElseScope, 0);

  return newElseNode;
}

struct TreeNode * create_IfNode (struct TreeNode * if_node, struct TreeNode * condition){

  Check_NodeType(If, if_node, "create_IfNode");
  Check_NodeType(Expr, condition, "create_IfNode");

  // linking condition to the if node
  TreeNodeList_Add(if_node -> child_list, condition);
  // if-scope is ended
  ScopeStack_Pop(MainNode -> actual_stack);

  return if_node;
}

struct TreeNode * create_IfDeclaration(){

  // creating a generic Tree Node with memory allocation
  struct TreeNode * newIfNode = TreeNodeInitialization();
  // Tree Node Type
  newIfNode -> nodeType = If;

  // creating if scope
  struct TreeNode * ifScope = create_ScopeNode();
  // linking if scope to the if node
  TreeNodeList_Add(newIfNode -> child_list, ifScope);
  // setting if scope as new actual scope
  // if scope is inactive by default
  SetAs_ActualScope(ifScope, 0);
  // by default if condition is not satisfied
  newIfNode -> node.flag = 0;

  return newIfNode;
}

////////////////////  while PRODUCTION  ////////////////////////////////////////

struct TreeNode * create_WhileNode(struct TreeNode * while_node, struct TreeNode * condition){

  Check_NodeType(While, while_node, "create_WhileNode");
  Check_NodeType(Expr, condition, "create_WhileNode");

  TreeNodeList_Add(while_node -> child_list, condition);
  ScopeStack_Pop(MainNode -> actual_stack);

  return while_node;
}

struct TreeNode * create_Condition(struct TreeNode * expr){

  struct TreeNode * condition;

  if ( expr -> nodeType == Expr){

    enum exprType type = expr -> node.Expr -> exprType;

    if (type == STR) printf("%s address of string will always evaluate to \'true\'.\n", WarnMsg());
    else if (type == ADD){

      if (expr -> child_list -> first -> node.Expr -> exprType == ID)
        printf("%s address of \'%s\' will always evaluate to \'true\'.\n", WarnMsg(), TreeNode_Identifier(expr));
      else if (expr -> child_list -> first -> node.Expr -> exprType == VEC)
        printf("%s address of \'%s[%d]\' will always evaluate to \'true\'.\n", WarnMsg(), TreeNode_Identifier(expr), Retrieve_ArrayIndex(expr -> child_list -> first));

    }
    else if (isArrayPointer(expr))
      printf("%s address of array \'%s\' will always evaluate to \'true\'.\n", WarnMsg(), TreeNode_Identifier(expr));
    else if(IsCostant(expr)){

      char value = CMP_node_logicValue(expr);
      if (value == 1){
        printf("%s condition is always true.\n", WarnMsg());
      }
      else if(value == 0){
        printf("%s condition is always false.\n", WarnMsg());
      }
    }

    condition = expr;
  }
  else{
    printf("%s create_Condition - unexpected Tree Node type. Expected Expr, found %s.\n", ErrorMsg(), NodeTypeString(expr));
    exit(EXIT_FAILURE);
  }

  return condition;
}

struct TreeNode * create_WhileDeclaration(){

  // creating a generic Tree Node with memory allocation
  struct TreeNode * newWhileNode = TreeNodeInitialization();
  // Tree Node Type
  newWhileNode -> nodeType = While;

  // creating while scope
  struct TreeNode * whileScope = create_ScopeNode();
  // linking while scope to the while node
  TreeNodeList_Add(newWhileNode -> child_list, whileScope);
  // setting while scope as new actual scope
  // while scope is inactive by default
  SetAs_ActualScope(whileScope, 0);

  return newWhileNode;
}

////////////////////  multi assignment PRODUCTION  /////////////////////////////

struct TreeNode * create_MultiAssignment(struct TreeNode * first, struct TreeNode * second){

  struct TreeNode * multiAssignment;

  if (first -> nodeType == Asgn){
    if (second -> nodeType == Asgn){
      // creating multi assignment node
      multiAssignment = TreeNodeInitialization();
      // setting node type
      multiAssignment -> nodeType = MultiAs;
      // linking first and second assignment to the multi assgniment node
      TreeNodeList_Add(multiAssignment -> child_list, first);
      TreeNodeList_Add(multiAssignment -> child_list, second);
    }
    else{
      printf("%s create_MultiAssignment - unexpected Tree node type. Expected Asgn, found %s.\n", ErrorMsg(), NodeTypeString(second));
      exit(EXIT_FAILURE);
    }
  }
  else if (first -> nodeType == MultiAs){
    if (second -> nodeType == Asgn){
      // adding the new assignement to the existing multi assignment node
      TreeNodeList_Add(multiAssignment -> child_list, second);
      multiAssignment = first;
    }
    else{
      printf("%s create_MultiAssignment - unexpected Tree node type. Expected Asgn, found %s.\n", ErrorMsg(), NodeTypeString(second));
      exit(EXIT_FAILURE);
    }
  }
  else{
    printf("%s create_MultiAssignment - unexpected Tree node type. Expected Asgn / MultiAs found %s.\n", ErrorMsg(), NodeTypeString(first));
    exit(EXIT_FAILURE);
  }

  return multiAssignment;
}

////////////////////  multi declaration PRODUCTION  ////////////////////////////

struct TreeNode * create_MultiDeclaration(struct TreeNode * declaration, struct TreeNode * expr, char flag){

  if (declaration -> nodeType == DclN){

    // Multi declaration node
    struct TreeNode * newTreeNode = TreeNodeInitialization();
    // setting node type
    newTreeNode -> nodeType = MultiDc;
    /*
    * linking the declaration node to the multi declaration node as first node
    * of the child list.
    */
    TreeNodeList_Add(newTreeNode -> child_list, declaration);

    // declaration must be executed in order to add the declared variable to the Symbol Table
    exec_DclN(declaration);

    enum Type declarationType = declaration -> node.DclN -> type;
    if (declarationType == INT_V_) declarationType = INT_;
    else if (declarationType == CHAR_V_) declarationType = CHAR_;

    if (expr -> node.Expr -> exprType == ID || expr -> node.Expr -> exprType == VEC){
      struct TreeNode * newDeclaration = create_DeclarationNode(declarationType, expr);
      TreeNodeList_Add(newTreeNode -> child_list, newDeclaration);
    }
    else{
      printf("%s create_MultiDeclaration - unexpected variable. Type found %u.\n", ErrorMsg(), expr -> node.Expr -> exprType);
      exit(EXIT_FAILURE);
    }

    return newTreeNode;
  }
  else if(declaration -> nodeType == DclAsgn){

    // Multi declaration node
    struct TreeNode * newTreeNode = TreeNodeInitialization();
    // setting node type
    newTreeNode -> nodeType = MultiDc;
    /*
    * linking the declaration node to the multi declaration node as first node
    * of the child list.
    */
    TreeNodeList_Add(newTreeNode -> child_list, declaration);

    enum Type declarationType = declaration -> child_list -> first -> node.DclN -> type;
    if (declarationType == INT_V_) declarationType = INT_;
    else if (declarationType == CHAR_V_) declarationType = CHAR_;

    if (expr -> node.Expr -> exprType == ID || expr -> node.Expr -> exprType == VEC){
      struct TreeNode * newDeclaration = create_DeclarationNode(declarationType, expr);
      TreeNodeList_Add(newTreeNode -> child_list, newDeclaration);
    }
    else{
      printf("%s create_MultiDeclaration - unexpected variable. Type found %u.\n", ErrorMsg(), expr -> node.Expr -> exprType);
      exit(EXIT_FAILURE);
    }

    return newTreeNode;
  }
  else if(declaration -> nodeType == MultiDc){
    /*
    *   flag value its used to recognize a new declaration (flag = 1)
    */
    if (flag == 1){
      // a new declaration node

      // if the previous element was a simple declaration I have to execute it
      if (declaration -> child_list  -> last -> nodeType == DclN){
        exec_DclN(declaration -> child_list  -> last);
      }

      // declaration type derives from the first declaration
      enum Type declarationType;
      struct TreeNode * firstDeclaration = declaration -> child_list -> first;
      if (firstDeclaration -> nodeType == DclN){
        declarationType = firstDeclaration -> node.DclN -> type;
      }
      else if (firstDeclaration -> nodeType == DclAsgn){
        declarationType = firstDeclaration -> child_list -> first -> node.DclN -> type;
      }

      if (declarationType == INT_V_) declarationType = INT_;
      else if (declarationType == CHAR_V_) declarationType = CHAR_;

      if (expr -> node.Expr -> exprType == ID || expr -> node.Expr -> exprType == VEC){
        struct TreeNode * newDeclaration = create_DeclarationNode(declarationType, expr);
        TreeNodeList_Add(declaration -> child_list, newDeclaration);
      }
      else{
        printf("%s create_MultiDeclaration - unexpected variable. Type found %u.\n", ErrorMsg(), expr -> node.Expr -> exprType);
        exit(EXIT_FAILURE);
      }
    }
    /*
    *   a new assignemnt linked to the previous declaration
    */
    else{
      if(expr -> nodeType == Expr){
        if (expr -> node.Expr -> exprType == ID){
        }
      }
      struct TreeNode * lastDeclaration = declaration -> child_list -> last;
      struct TreeNode * newDeclarationAssignment = create_Declaration_AssignmentNode(lastDeclaration, expr);
      TreeNodeList_Rem(declaration -> child_list);
      TreeNodeList_Add(declaration -> child_list, newDeclarationAssignment);
    }
    return declaration;
  }
  else{
    printf("%s create_MultiDeclaration - incorrect call. Unexpected %s type node.\n", ErrorMsg(), NodeTypeString(declaration));
    exit(EXIT_FAILURE);
  }
}

struct TreeNode * create_MultiDeclarationStatement(struct TreeNode * multi_dec){

  Check_NodeType(MultiDc, multi_dec, "create_MultiDeclarationStatement");

  struct TreeNode * last_declaration = multi_dec -> child_list -> last;
  if ( last_declaration -> nodeType == DclN ){
    exec_DclN(last_declaration);
  }
  else if ( !last_declaration -> nodeType == DclAsgn ){
    printf("%s unexpected expression.\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }
  return multi_dec;
}

////////////////////  declaration_and_assignment PRODUCTION  ///////////////////

struct TreeNode * create_Declaration_AssignmentNode(struct TreeNode * declaration, struct TreeNode * expr){

  if (declaration -> nodeType == DclN){
    // Declaration and Assignment node
    struct TreeNode * newTreeNode;

    // one expression to assign
    if (expr -> nodeType == Expr){

      // declaring variable identifier
      char * identifier = TreeNode_Identifier(declaration);
      struct TreeNode * identifierNode;

      enum Type decl_type = declaration -> node.DclN -> type;

      if (decl_type == INT_ || decl_type == CHAR_){

        identifierNode = create_ExprNode(ID, 0, identifier, NULL, NULL, 0);

        // declaration must be always executed, in order to add variables to the symbol table
        exec_DclN(declaration);

        // creating the assignment node
        struct TreeNode * assignmentNode = create_AssignmentNode(MainNode, identifierNode, expr);

        // Declaration and Assignment node memory allocation
        newTreeNode = TreeNodeInitialization (); // generic Tree Node memory space allocation
        // setting node type
        newTreeNode -> nodeType = DclAsgn;
        // linking declaration node
        TreeNodeList_Add(newTreeNode -> child_list, declaration);
        // linking assignment node
        TreeNodeList_Add(newTreeNode -> child_list, assignmentNode);
      }
      else if (decl_type == INT_V_ || decl_type == CHAR_V_){

        if (expr -> node.Expr -> exprType == STR){
          if (decl_type == CHAR_V_){

            char * string = expr -> node.Expr -> exprVal.stringExpr;

            struct TreeNode * character;
            // converting the string in a char expr list
            struct TreeNode * expr_list = NULL;
            for (int i = 0; i < strlen(string); i++){
              character = create_ExprNode(C, 0, &string[i], NULL, NULL, 0);
              expr_list = create_Expr_ListNode(expr_list, character);
            }

            char end_string = '\0';
            // adding end string character
            character = create_ExprNode(C, 0, &end_string, NULL, NULL, 0);
            expr_list = create_Expr_ListNode(expr_list, character);
            newTreeNode = create_Declaration_AssignmentNode(declaration, expr_list);
          }
          // error: int string
          else if(decl_type == INT_V_){
            printf("%s initializing int array \'%s\' with a string.\n", ErrorMsg(), identifier);
            exit(EXIT_FAILURE);
          }
        }
        // error: missing initializer
        else{
          printf("%s array initializer of \'%s\' must be an initializer list or wide string literal.\n", ErrorMsg(), identifier);
          exit(EXIT_FAILURE);
        }
      }
    }
    // array initializer to assign
    else if (expr -> nodeType == ExprLst){

      int var_dimension;
      int init_dimension;
      enum Type decl_type = declaration -> node.DclN -> type;

      // dimension of the initializer
      init_dimension = expr -> child_list -> elements;

      // an expr list with a single string is managed as a simple string
      if (init_dimension == 1 && expr -> child_list -> first -> node.Expr -> exprType == STR){
        newTreeNode = create_Declaration_AssignmentNode(declaration, expr -> child_list -> first);
      }
      else{

        if (decl_type == INT_ || decl_type == CHAR_){
          var_dimension = 1;
        }
        // array with unspecified dimension
        else if(declaration -> node.DclN -> arrayDim == NULL && (decl_type == INT_V_ || decl_type == CHAR_V_)){
          var_dimension = init_dimension;
          struct TreeNode * dimension = create_ExprNode(NUM, var_dimension, NULL, NULL, NULL, 0);
          declaration -> node.DclN -> arrayDim = dimension;
        }
        // array with specified dimension
        else{
          var_dimension = Expr_toInt(declaration -> node.DclN -> arrayDim);
        }

        // warning: excess elements in array initializer
        if(init_dimension > var_dimension){
          printf("%s excess elements in array initializer.\n", WarnMsg());
        }

        // single variable
        if (decl_type == INT_ || decl_type == CHAR_){
          // considers only the first expression in the expression list
          newTreeNode = create_Declaration_AssignmentNode(declaration, expr -> child_list -> first);
        }
        // array
        else if (decl_type == INT_V_ || decl_type == CHAR_V_){

          // declaration must be always executed, in order to add variables to the symbol table
          exec_DclN(declaration);

          // declaring variable identifier
          char * identifier = TreeNode_Identifier(declaration);

          // Declaration and Assignment node memory allocation
          newTreeNode = TreeNodeInitialization (); // generic Tree Node memory space allocation
          // setting node type
          newTreeNode -> nodeType = DclAsgn;
          // linking declaration node
          TreeNodeList_Add(newTreeNode -> child_list, declaration);

          // value to assign
          struct TreeNode * value = expr -> child_list -> first;

          int assignments;
          if (var_dimension < init_dimension) assignments = var_dimension;
          else assignments = init_dimension;

          // loop for craating the assignment statemets
          for (int i = 0; i < assignments; i++){

            // skipping to the next expression in the expression list
            if (i != 0) value = value -> next;

            // array index expr node
            struct TreeNode * index = create_ExprNode(NUM, i, NULL, NULL, NULL, 0);
            // array element expr node
            struct TreeNode * variable = create_ExprNode(VEC, 0, identifier, index, NULL, 0);

            // creating the assignment node
            struct TreeNode * assignmentNode = create_AssignmentNode(MainNode, variable, value);
            // linking assignment node
            TreeNodeList_Add(newTreeNode -> child_list, assignmentNode);
          }

        }
        else{
          printf("%s create_Declaration_AssignmentNode - unexpected dimension: %d\n", ErrorMsg(), var_dimension);
          exit(EXIT_FAILURE);
        }
      }
    }
    else{
          printf("%s create_Declaration_AssignmentNode - incorrect call. Expr TreeNode type expected. Type found: %u.\n", ErrorMsg(), expr -> nodeType);
          exit(EXIT_FAILURE);
        }

    return newTreeNode;
  }
  // subsequent assignment
  else if (declaration -> nodeType == DclAsgn){

    // previous assignment
    struct TreeNode * prev_assignment = declaration -> child_list -> first -> next;

    prev_assignment = create_AssignmentNode(MainNode, prev_assignment, expr);

    return declaration;
  }
  else{
    printf("%s create_Declaration_AssignmentNode - incorrect call. Declaration TreeNode type expected. Type found: %s.\n", ErrorMsg(), NodeTypeString(declaration));
    exit(EXIT_FAILURE);
  }
}

////////////////////  assignment PRODUCTION  ///////////////////////////////////

struct TreeNode * create_AssignmentNode(struct ProgramNode * prog, struct TreeNode * leftOp, struct TreeNode * rightOp){

  if (leftOp -> nodeType == Expr && rightOp -> nodeType == Expr){

    // generic Tree Node memory space allocation
    struct TreeNode * newTreeNode = TreeNodeInitialization ();
    // setting node type
    newTreeNode -> nodeType = Asgn;
    // Checking if the assignment is consistent
    Check_AsgnConcistency(leftOp, rightOp);
    // Storing left operator
    TreeNodeList_Add(newTreeNode -> child_list, leftOp);
    // Storing right operator
    TreeNodeList_Add(newTreeNode -> child_list, rightOp);

    return newTreeNode;
  }
  // multiple assignment
  else if (leftOp -> nodeType == Asgn && rightOp -> nodeType == Expr){

    struct TreeNode * leftOp_node = leftOp -> child_list -> last;

    // Checking if the assignment is consistent
    Check_AsgnConcistency(leftOp_node, rightOp);

    // Storing right operator
    TreeNodeList_Add(leftOp -> child_list, rightOp);

    return leftOp;
  }
  // incorrect call
  else{
    printf("%s - create_AssignmentNode: incorrect call.\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }

  exit(EXIT_FAILURE);
}

////////////////////  declaration PRODUCTION  //////////////////////////////////

struct TreeNode * create_DeclarationNode(enum Type type, struct TreeNode * var){

  Check_NodeType(Expr, var, "create_DeclarationNode");
  // generic Tree Node memory space allocation
  struct TreeNode * newTreeNode = TreeNodeInitialization ();
  // setting node type
  newTreeNode -> nodeType = DclN;
  // checking if the declaration is consistent
  Check_DeclConcistency(var);
  // memory space allocation for specific Declaration node
  struct DeclarationNode * newDeclaration;
  newDeclaration = (struct DeclarationNode *)malloc(sizeof(struct DeclarationNode));
  // variable identifier
  newDeclaration -> identifier = TreeNode_Identifier(var);
  // setting var type and array dimension
  if (var -> node.Expr -> exprType == ID){
    // variable type
    newDeclaration -> type = type;
    // array dimension
    newDeclaration -> arrayDim = NULL;
  }
  else if (var -> node.Expr -> exprType == VEC){
    if(type == INT_){
      // variable type
      newDeclaration -> type = INT_V_;
      // array dimension
      newDeclaration -> arrayDim = var -> child_list -> first;
    }
    else if(type == CHAR_){
      // variable type
      newDeclaration -> type = CHAR_V_;
      // array dimension
      newDeclaration -> arrayDim = var -> child_list -> first;
    }
    else{
      printf("%s create_DeclarationNode - unexpected variable type.\n", ErrorMsg());
      exit(EXIT_FAILURE);
    }
  }
  // setting ignore flag, 0 by default
  newDeclaration -> ignore = 0;

  // linking declaration struct to tree node
  newTreeNode -> node.DclN = newDeclaration;
  // freeing memory
  free(var -> node.Expr);
  free(var);

  return newTreeNode;
}

////////////////////  return PRODUCTION  ///////////////////////////////////////

struct TreeNode * create_ReturnNode(struct TreeNode * expr){

  struct TreeNode * newTreeNode = TreeNodeInitialization (); // generic Tree Node memory space allocation

  // Linking specific node to generic Tree Node
  newTreeNode -> nodeType = Return;
  // Linking returned expression to the return node
  TreeNodeList_Add(newTreeNode -> child_list, expr);

  int value;
  if (IsCostant(expr)){
    value = Expr_toInt(expr);

    FunNode * function_node = MainNode -> function_list -> last;
    enum Type function_type = function_node -> funType;

    if (function_type == CHAR_) Check_CharConcistency(value);
  }

  return newTreeNode;
}

////////////////////  pre_incdec_statement PRODUCTION  //////////////////////////

struct TreeNode * create_IncDecNode(enum exprType type, struct TreeNode * var){

  Check_NodeType(Expr, var, "create_IncDecNode");

  if (isAssignable(var)){
    Check_VariableConcistency(var);
    return create_ExprNode(type, 0, NULL, var, NULL, 0);
  }
  else{
    printf("%s expression is not assignable.\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }
}

////////////////////  operation PRODUCTION  ////////////////////////////////////

struct TreeNode * create_OperationNode(struct TreeNode * first, struct TreeNode * second, enum exprType type){

  Check_NodeType(Expr, first, "create_OperationNode");
  Check_NodeType(Expr, second, "create_OperationNode");

  if (first == NULL || second == NULL) {
      printf("%s create_OperationNode - comparison missing one or two expressions\n", ErrorMsg());
      exit(EXIT_FAILURE);
    }
  else{
    struct TreeNode * node = create_ExprNode(type, 0, NULL, first, second, 0);
    Check_OperationConcistency(node);

    return node;
  }

}

////////////////////  expr PRODUCTION  /////////////////////////////////////////

struct TreeNode * create_ExprNode(enum exprType type, long intExpr, char * charExpr, struct TreeNode * first, struct TreeNode * second, enum cmpType cmptype){

    struct TreeNode * newTreeNode = TreeNodeInitialization (); // generic Tree Node memory space allocation


    struct exprNode * NewExprNode;
    NewExprNode = (struct exprNode *)malloc(sizeof(struct exprNode)); // memory space allocation for specific Expr node

    NewExprNode -> exprType = type;

    switch (type) {
      case NUM: if(intExpr > -2147483649 && intExpr < 2147483648){
                  NewExprNode -> exprVal.intExpr = (int)intExpr;
                }
                else{
                 printf("%s out of integer range. This interpreter works with integer numbers only.\n",ErrorMsg());
                 exit(EXIT_FAILURE);
               }
                break;
      case ID:  NewExprNode -> exprVal.stringExpr = charExpr;
                break;
      case VEC: NewExprNode -> exprVal.stringExpr = charExpr;
                // check if vec has a dimension
                if(first != NULL){
                  enum Type dimension_type = expressionType(first);

                  // check if array dimension index is not a pointer
                  if (dimension_type == INT_ || dimension_type == CHAR_){

                    // adding the array dimension index as tree node child
                    TreeNodeList_Add(newTreeNode -> child_list, first);
                  }
                  // display error message if the dimension index is a string
                  else{
                    printf("%s size of array has non-integer type. Type found \'%s\'.\n", ErrorMsg(), IdentifierTypeString(dimension_type));
                    exit(EXIT_FAILURE);
                  }
                  // check if dimension is a variable
                }
                break;
      case STR: NewExprNode -> exprVal.stringExpr = (char *)malloc (sizeof(char) *strlen(charExpr)-1);
                // skipping the first and last apex
                for (int i =1; i<strlen(charExpr)-1; i++){
                  NewExprNode -> exprVal.stringExpr[i-1]=charExpr[i];
                }
                // adding end string symbol
                NewExprNode -> exprVal.stringExpr[strlen(charExpr)] = '\0';
                break;
      case C:   NewExprNode -> exprVal.charExpr = *charExpr;
                break;
      case FC:  NewExprNode -> exprVal.stringExpr = charExpr;
                // function parameters
                if (first != NULL) TreeNodeList_Add(newTreeNode -> child_list, first);
                break;
      case SUM: TreeNodeList_Add(newTreeNode -> child_list, first);
                TreeNodeList_Add(newTreeNode -> child_list, second);
                break;
      case DIF: TreeNodeList_Add(newTreeNode -> child_list, first);
                TreeNodeList_Add(newTreeNode -> child_list, second);
                break;
      case TIM: TreeNodeList_Add(newTreeNode -> child_list, first);
                TreeNodeList_Add(newTreeNode -> child_list, second);
                break;
      case DIV: TreeNodeList_Add(newTreeNode -> child_list, first);
                TreeNodeList_Add(newTreeNode -> child_list, second);
                break;
      case MOD: TreeNodeList_Add(newTreeNode -> child_list, first);
                TreeNodeList_Add(newTreeNode -> child_list, second);
                break;
      case RND: TreeNodeList_Add(newTreeNode -> child_list, first);
                break;
      case CMP: TreeNodeList_Add(newTreeNode -> child_list, first);
                TreeNodeList_Add(newTreeNode -> child_list, second);
                NewExprNode -> exprVal.cmpExpr = cmptype;
                break;
      case PI:  TreeNodeList_Add(newTreeNode -> child_list, first);
                break;
      case PD:  TreeNodeList_Add(newTreeNode -> child_list, first);
                break;
      case IP:  TreeNodeList_Add(newTreeNode -> child_list, first);
                break;
      case DP:  TreeNodeList_Add(newTreeNode -> child_list, first);
                break;
      case ADD: Check_VariableAddress(first);
                TreeNodeList_Add(newTreeNode -> child_list, first);
                break;
      }

    // Linking specific node to generic Tree Node
    newTreeNode -> nodeType = Expr;
    newTreeNode -> node.Expr = NewExprNode;

    return newTreeNode;
  }

////////////////////////////////////////////////////////////////////////////////

struct TreeNode * TreeNodeInitialization (){

    struct TreeNode * newTreeNode;
    newTreeNode = (struct TreeNode *)malloc(sizeof(struct TreeNode)); // memory space allocation for generic tree node
    newTreeNode -> child_list = TreeNodeList_Set();  // memory space allocation for tree node child list
    newTreeNode -> next = NULL;
    return newTreeNode;
  }

//////////////////  concistency FUNCTIONS  /////////////////////////////////////

void Check_CharConcistency(int value){
  if (value < -128 || value > 127){
    printf("%s implicit conversion from 'int' to 'char' changes value from %d to %d\n", WarnMsg(), value, (char)value);
  }
}

void Check_IdentifierConcistency(struct TreeNode * identifier_node){

  Check_NodeType(Expr, identifier_node, "Check_IdentifierConcistency");
  Check_ExprType(ID, identifier_node, "Check_IdentifierConcistency");

  char * identifier = identifier_node -> node.Expr -> exprVal.stringExpr;
  // check declaration
  if (!Check_VarWasDeclared(identifier, 1)){
    printf("%s use of undeclared identifier \'%s\'.\n", ErrorMsg(), identifier);
    exit(EXIT_FAILURE);
  }
}

void Check_ArrayConcistency(struct TreeNode * array){

  Check_NodeType(Expr, array, "Check_ArrayConcistency");
  Check_ExprType(VEC, array, "Check_ArrayConcistency");

  char * array_id = array -> node.Expr -> exprVal.stringExpr;
  // check declaration
  if (!Check_VarWasDeclared(array_id, 1)){

    printf("%s use of undeclared identifier \'%s\'.\n", ErrorMsg(), array_id);
    exit(EXIT_FAILURE);
  }
  else{
    // array dimension index missing
    if (array -> child_list -> elements == 0){
      printf("%s expexted expression.\n", ErrorMsg());
      exit(EXIT_FAILURE);
    }
    // check array index
    int index = Retrieve_ArrayIndex(array);
    int array_dim = Retrieve_ArrayDim(array_id);

    // out of bounds array error
    if (index > array_dim - 1 && !IgnoreFlag(array_id)){
      printf("%s array index %d is past the end of the array. Array contains %d elements.\n",ErrorMsg(),index, array_dim);
      exit(EXIT_FAILURE);
    }
    else if (index < 0){
      printf("%s array index %d is before the beginning of the array. Array contains %d elements.\n", ErrorMsg(),index, array_dim);
      exit(EXIT_FAILURE);
    }
  }
}

void Check_VariableConcistency(struct TreeNode * node){

  Check_NodeType(Expr, node, "Check_VariableConcistency");
  char * identifier = TreeNode_Identifier(node);

  if (node -> node.Expr -> exprType == ID) Check_IdentifierConcistency(node);
  else if (node -> node.Expr -> exprType == VEC) Check_ArrayConcistency(node);
  else {
    printf("%s Check_VariableConcistency unexpected expression type. Type found %s.\n", ErrorMsg(), ExprTypeString(node));
    exit(EXIT_FAILURE);
  }
}

void Check_OperationConcistency (struct TreeNode * operation_node){

  Check_NodeType(Expr, operation_node, "Check_OperationConcistency");
  if (operation_node -> nodeType == Expr){
    if(isOperation(operation_node)){

      if (operation_node -> node.Expr -> exprType != RND){
        // left operand type check
        struct TreeNode * leftOp = operation_node -> child_list -> first;
        enum Type leftOp_type = expressionType(leftOp);

        // right operand type check
        struct TreeNode * rightOp = operation_node -> child_list -> first -> next;
        enum Type rightOp_type = expressionType(rightOp);

        // left operand must not be a pointer
        if (leftOp_type != INT_ && leftOp_type != CHAR_){
          printf("%s Invalid operands. Operations with pointers are not allowed.\n", ErrorMsg());
          exit(EXIT_FAILURE);
        }
        // right operand must not be a pointer
        if (rightOp_type != INT_ && rightOp_type != CHAR_){
          printf("%s Invalid operands. Operations with pointers are not allowed.\n", ErrorMsg());
          exit(EXIT_FAILURE);
        }

        // Raise a warning if there's a division by 0
        if(operation_node -> node.Expr -> exprType == DIV || operation_node -> node.Expr -> exprType == MOD){
          // If the second operand is costant
          if(IsCostant(operation_node -> child_list -> first -> next)){
            // If the second operand value is 0
            if(Expr_toInt(operation_node -> child_list -> first -> next) == 0){
              printf("%s division by zero is undefined.\n", WarnMsg());
            }
          }
        }
        // Node value pre-calculus if it is not a division by 0
        else if(IsCostant(operation_node)){

            int value = Expr_toInt(operation_node);
            operation_node -> node.Expr -> exprVal.intExpr = value;
            operation_node -> node.Expr -> known = 1;
        }
      }
    }
    else{
      printf("%s Check_OperationConcistency - incorrect call. SUM/DIF/TIM/DIV/MOD/RND Expr TreeNode expected.\n", ErrorMsg());
      exit(EXIT_FAILURE);
    }
  }
}

void Check_ComparisonConcistency (struct TreeNode * comparison_node){

  Check_NodeType(Expr, comparison_node, "Check_ComparisonConcistency");
  Check_ExprType(CMP, comparison_node, "Check_ComparisonConcistency");

  enum cmpType type = comparison_node -> node.Expr -> exprVal.cmpExpr;

  // comparison is a binary logic operation with two operands: leftOp and rightOp
  struct TreeNode * leftOp = comparison_node -> child_list -> first;
  struct TreeNode * rightOp = comparison_node -> child_list -> first -> next;

  // comparison is a binary logic operation with two operands: leftOp and rightOp
  enum exprType leftOp_type = leftOp -> node.Expr -> exprType;
  enum exprType rightOp_type = rightOp -> node.Expr -> exprType;

  enum Type left_type = expressionType(leftOp);
  enum Type right_type = expressionType(rightOp);

  // operands must not be
  if ((left_type != INT_ && left_type != CHAR_) || ((right_type != INT_ && right_type != CHAR_))){
    printf("%s Invalid operands. Operations with pointers are not allowed.\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }

  if (type == AND_ || type == OR_){

    // Raise a warning if the operand is a costant and is different from 0 or 1
    if (IsCostant(leftOp)){
      int value = Expr_toInt(leftOp);
      if (value != 0 && value != 1){
        printf("%s logical operation with costant first operand.\n", WarnMsg());
      }

    }
    if (IsCostant(rightOp)){
      int value = Expr_toInt(rightOp);
      if (value != 0 && value != 1){
        printf("%s logical operation with costant second operand.\n", WarnMsg());
      }
    }

  }
  else if(type == GREAT_ || type == LESS_ || type == EQUAL_ || type == DIFF_ ){

    // Print a warning if the comparison with a char is always true or always false
    if (IsCostant(leftOp)){
      if (rightOp_type == ID || rightOp_type == VEC){
        char * identifier = TreeNode_Identifier(rightOp);
        enum Type varType = Retrieve_VarType(identifier);

        if (varType == CHAR_ || varType == CHAR_V_){
          if (type == GREAT_){
            if (Expr_toInt(leftOp) > 127){
              printf("%s result of comparison of constant %d with expression of type char is always true.\n", WarnMsg(), Expr_toInt(leftOp));
            }
            else if (Expr_toInt(leftOp) < -128){
              printf("%s result of comparison of constant %d with expression of type char is always false.\n", WarnMsg(), Expr_toInt(leftOp));
            }
          }
          if (type == LESS_){
            if (Expr_toInt(leftOp) > 127){
              printf("%s result of comparison of constant %d with expression of type char is always false.\n", WarnMsg(), Expr_toInt(leftOp));
            }
            else if (Expr_toInt(leftOp) < -128){
              printf("%s result of comparison of constant %d with expression of type char is always true.\n", WarnMsg(), Expr_toInt(leftOp));
            }
          }
          if (type == EQUAL_){
            if (Expr_toInt(leftOp) > 127){
              printf("%s result of comparison of constant %d with expression of type char is always false.\n", WarnMsg(), Expr_toInt(leftOp));
            }
            else if (Expr_toInt(leftOp) < -128){
              printf("%s result of comparison of constant %d with expression of type char is always false.\n", WarnMsg(), Expr_toInt(leftOp));
            }
          }
          if (type == DIFF_){
            if (Expr_toInt(leftOp) > 127){
              printf("%s result of comparison of constant %d with expression of type char is always true.\n", WarnMsg(), Expr_toInt(leftOp));
            }
            else if (Expr_toInt(leftOp) < -128){
              printf("%s result of comparison of constant %d with expression of type char is always true.\n", WarnMsg(), Expr_toInt(leftOp));
            }
          }
        }
      }
    }
    if (IsCostant(rightOp)){
      if (leftOp_type == ID || leftOp_type == VEC){
        char * identifier = TreeNode_Identifier(leftOp);
        enum Type varType = Retrieve_VarType(identifier);

        if (varType == CHAR_ || varType == CHAR_V_){
          if (type == GREAT_){
            if (Expr_toInt(rightOp) > 127){
              printf("%s result of comparison of constant %d with expression of type char is always false.\n", WarnMsg(), Expr_toInt(rightOp));
            }
            else if (Expr_toInt(rightOp) < -128){
              printf("%s result of comparison of constant %d with expression of type char is always true.\n", WarnMsg(), Expr_toInt(rightOp));
            }
          }
          if (type == LESS_){
            if (Expr_toInt(rightOp) > 127){
              printf("%s result of comparison of constant %d with expression of type char is always true.\n", WarnMsg(), rightOp -> node.Expr -> exprVal.intExpr);
            }
            else if (Expr_toInt(rightOp) < -128){
              printf("%s result of comparison of constant %d with expression of type char is always false.\n", WarnMsg(), rightOp -> node.Expr -> exprVal.intExpr);
            }
          }
          if (type == EQUAL_){
            if (Expr_toInt(rightOp) > 127){
              printf("%s result of comparison of constant %d with expression of type char is always false.\n", WarnMsg(), Expr_toInt(rightOp));
            }
            else if (Expr_toInt(rightOp) < -128){
              printf("%s result of comparison of constant %d with expression of type char is always false.\n", WarnMsg(), Expr_toInt(rightOp));
            }
          }
          if (type == DIFF_){
            if (Expr_toInt(rightOp) > 127){
              printf("%s result of comparison of constant %d with expression of type char is always true.\n", WarnMsg(), rightOp -> node.Expr -> exprVal.intExpr);
            }
            else if (Expr_toInt(rightOp) < -128){
              printf("%s result of comparison of constant %d with expression of type char is always true.\n", WarnMsg(), rightOp -> node.Expr -> exprVal.intExpr);
            }
          }
        }
      }
    }

    // Print a warning if the comparison with an other comparison is always true or always false
    if (leftOp_type == CMP && IsCostant(rightOp)){
      if (type == GREAT_){
        if (Expr_toInt(rightOp) < 0){
            printf("%s result of comparison of constant %d with boolean expression is always true.\n", WarnMsg(), Expr_toInt(rightOp));
        }
        if (Expr_toInt(rightOp) > 0){
            printf("%s result of comparison of constant %d with boolean expression is always false.\n", WarnMsg(), Expr_toInt(rightOp));
        }
      }
      if (type == LESS_){
        if (Expr_toInt(rightOp) > 1){
            printf("%s result of comparison of constant %d with boolean expression is always true.\n", WarnMsg(), Expr_toInt(rightOp));
        }
        if (Expr_toInt(rightOp) < 1){
            printf("%s result of comparison of constant %d with boolean expression is always false.\n", WarnMsg(), Expr_toInt(rightOp));
        }
      }
      if (type == EQUAL_){
        if (Expr_toInt(rightOp) != 0 &&  Expr_toInt(rightOp) != 1){
              printf("%s result of comparison of constant %d with boolean expression is always false.\n", WarnMsg(), Expr_toInt(rightOp));
          }
      }
      if (type == DIFF_){
        if (Expr_toInt(rightOp) != 0 &&  rightOp -> node.Expr -> exprVal.intExpr != 1){
            printf("%s result of comparison of constant %d with boolean expression is always true.\n", WarnMsg(), Expr_toInt(rightOp));
        }
      }
    }
    if (IsCostant(leftOp) && rightOp_type == CMP){
      if (type == GREAT_){
        if (Expr_toInt(leftOp) > 1){
            printf("%s result of comparison of constant %d with boolean expression is always true.\n", WarnMsg(), Expr_toInt(leftOp));
        }
        if (Expr_toInt(leftOp) < 1){
            printf("%s result of comparison of constant %d with boolean expression is always false.\n", WarnMsg(), Expr_toInt(leftOp));
        }
      }
      if (type == LESS_){
        if (Expr_toInt(leftOp) < 0){
            printf("%s result of comparison of constant %d with boolean expression is always true.\n", WarnMsg(), Expr_toInt(leftOp));
        }
        if (Expr_toInt(leftOp) > 0){
            printf("%s result of comparison of constant %d with boolean expression is always false.\n", WarnMsg(), Expr_toInt(leftOp));
        }
      }
      if (type == EQUAL_){
        if (Expr_toInt(leftOp) != 0 &&  Expr_toInt(leftOp) != 1){
              printf("%s result of comparison of constant %d with boolean expression is always false.\n", WarnMsg(), Expr_toInt(leftOp));
          }
      }
      if (type == DIFF_){
        if (Expr_toInt(leftOp) != 0 &&  Expr_toInt(leftOp) != 1){
            printf("%s result of comparison of constant %d with boolean expression is always true.\n", WarnMsg(), Expr_toInt(leftOp));
        }
      }
    }

    // Print a warning if the comparison is between a variable and itself
    if ((leftOp_type == ID) && (rightOp_type == ID)){

      char * left_identifier = TreeNode_Identifier(leftOp);
      char * right_identifier = TreeNode_Identifier(rightOp);

      if (!strcmp(left_identifier, right_identifier)){
        if (type == GREAT_ || type == LESS_ || type == DIFF_){
          printf("%s self-comparison always evaluates to false.\n", WarnMsg());
        }
        else if (type == EQUAL_){
          printf("%s self-comparison always evaluates to true.\n", WarnMsg());
        }
      }
    }
    if ((leftOp_type == VEC) && (rightOp_type == VEC)){

      char * left_identifier = TreeNode_Identifier(leftOp);
      char * right_identifier = TreeNode_Identifier(rightOp);
      // arrays must have the same index
      if ((IsCostant(leftOp -> child_list -> first))&&(IsCostant(rightOp -> child_list -> first))){
        if (Retrieve_ArrayIndex(leftOp) == Retrieve_ArrayIndex(leftOp)){

          if (!strcmp(left_identifier, right_identifier)){
            if (type == GREAT_ || type == LESS_ || type == DIFF_){
              printf("%s self-comparison always evaluates to false.\n", WarnMsg());
            }
            else if (type == EQUAL_){
              printf("%s self-comparison always evaluates to true.\n", WarnMsg());
            }
          }
        }
      }
    }
  }
}

void Check_AsgnConcistency(struct TreeNode * leftOp, struct TreeNode * rightOp){

  Check_NodeType(Expr, leftOp,  "Check_AsgnConcistency");
  Check_NodeType(Expr, rightOp, "Check_AsgnConcistency");


  enum exprType leftOp_type = leftOp -> node.Expr -> exprType;
  enum exprType rightOp_type = rightOp -> node.Expr -> exprType;

  // Only valid variables and array elements are assignable
  if (isAssignable(leftOp)){

    enum Type variable_type = expressionType(leftOp);
    enum Type value_type = expressionType(rightOp);

    // check if the value is an integer
    if (value_type != INT_ && value_type != CHAR_)
      printf("%s incompatible pointer to integer conversion assigning to '%s' from '%s'.\n", WarnMsg(), IdentifierTypeString(variable_type), IdentifierTypeString(value_type));

    char * leftOp_identifier = TreeNode_Identifier(leftOp);

    // Char assignment concistency
    if (IsCostant(rightOp)){

      enum Type varType = Retrieve_VarType(leftOp_identifier);
      if (varType == CHAR_ || varType == CHAR_V_){

        int value = Expr_toInt(rightOp);
        Check_CharConcistency(value);
      }
    }

    if(Multiple_Modifications(rightOp, leftOp_identifier)){
      printf("%s multiple unsequenced modifications to '%s'\n", WarnMsg(), leftOp_identifier);
    }
  }
  else{

    printf("%s: expression is not assignable\n",ErrorMsg());
    exit(EXIT_FAILURE);
  }
}
/*
*   flag parameter: 1 for declaration, 0 for declaration and assignment
*/
void Check_DeclConcistency(struct TreeNode * variable){

  Check_NodeType(Expr, variable, "Check_DeclConcistency");

  if (variable -> node.Expr -> exprType == ID || variable -> node.Expr -> exprType == VEC){

    char * identifier = TreeNode_Identifier(variable);
    // check if variable was previously declared
    if(Check_VarWasDeclared(identifier, 0)){
      printf("%s redefinition of %s.\n", ErrorMsg(), identifier);
      exit(EXIT_FAILURE);
    }

  }
  else{
    printf("%s Check_DeclConcistency - unexpected Expr type. Type found: %u.\n", ErrorMsg(), variable -> node.Expr -> exprType);
    exit(EXIT_FAILURE);
  }
}

int Check_ArrayDimension(struct TreeNode * node){

  if (node -> nodeType == Expr){
    if (node -> node.Expr -> exprType == VEC && node -> child_list -> elements == 0){
      printf("%s array '%s' dimension expression missing.\n", ErrorMsg(), TreeNode_Identifier(node));
      exit(EXIT_FAILURE);
      return 0;
    }
    else return 1;
  }
  else if (node -> nodeType == DclN){
    // array with no dimension specified
    if ((node -> node.DclN -> arrayDim == NULL) && (node -> node.DclN -> type == INT_V_ || node -> node.DclN -> type == CHAR_V_)){
      if (node -> node.DclN -> ignore) return 1;
      else{
        printf("%s definition of '%s' variable with array type needs an explicit size or an initializer.\n", ErrorMsg(), TreeNode_Identifier(node));
        exit(EXIT_FAILURE);
      }
    }
    else return 1;
  }
  else{
    printf("%s Check_ArrayDimension - unexpected tree node type. Expected 'expression' or 'declaration' found %s.\n", ErrorMsg(), NodeTypeString(node));
    exit(EXIT_FAILURE);
  }
}

void Check_NodeType(enum nodeType type, struct TreeNode * node, char * function_id){
  if( node -> nodeType != type){
    printf("%s %s - unexpected tree node type. Expected \'%s\', found \'%s\'.\n", ErrorMsg(), function_id, PrintNodeType(type), NodeTypeString(node));
    exit(EXIT_FAILURE);
  }
}

void Check_ExprType (enum exprType type, struct TreeNode * node, char * function_id){

  Check_NodeType(Expr, node, "Check_ExprType");

  if( node -> node.Expr -> exprType != type){
    printf("%s %s - unexpected expression tree node type. Expected \'%s\', found \'%s\'.\n", ErrorMsg(), function_id, PrintExpressionType(type), ExprTypeString(node));
    exit(EXIT_FAILURE);
  }
}

void Check_FunctionCallConcistency (struct TreeNode * function_call){

  Check_NodeType(Expr, function_call, "Check_FunctionCallConcistency");
  Check_ExprType(FC, function_call, "Check_FunctionCallConcistency");

  char * function_id = function_call -> node.Expr -> exprVal.stringExpr;

  // check if function was declared
  if(CheckFunAlreadyExist(function_id)) Check_FunctionParameters(function_call);
  // undeclared function error
  else{
    printf("%s call of undeclared function \'%s\'\n", ErrorMsg(), function_id);
    exit(EXIT_FAILURE);
  }

}
/*
*   comparing function call node with the function declaration
*/
void Check_FunctionParameters(struct TreeNode * function_call){

  char * identifier = function_call -> node.Expr -> exprVal.stringExpr;
  int index = FunNodeList_Search(identifier);
  struct FunNode * functionNode = FunNodeList_Get(index);

  struct TreeNode * call_parameters;
  struct TreeNode * decl_parameters = functionNode -> function_scope -> child_list -> first;

  int call_parameters_No;
  int decl_parameters_No = decl_parameters -> child_list -> elements;

  // if function call has parameters
  if (function_call -> child_list -> elements > 0){

    call_parameters = function_call -> child_list -> first;
    call_parameters_No = call_parameters -> child_list -> elements;
  }
  // if function call has not parameters
  else call_parameters_No = 0;

  // error: too many arguments
  if (call_parameters_No > decl_parameters_No){
    printf("%s too many arguments to function call '%s', expected %d, have %d.\n", ErrorMsg(), identifier, decl_parameters_No, call_parameters_No);
    exit(EXIT_FAILURE);
  }
  // error: too few arguments
  else if(call_parameters_No < decl_parameters_No){
    printf("%s too few arguments to function call '%s', expected %d, have %d.\n", ErrorMsg(), identifier, decl_parameters_No, call_parameters_No);
    exit(EXIT_FAILURE);
  }
  // no error: right number of parameters
  else{
    struct TreeNode * declaration;
    struct TreeNode * argument;
    for (int i = 0; i < decl_parameters_No; i++){

      if (i == 0) declaration = decl_parameters -> child_list -> first;
      else declaration = declaration -> next;

      if (i == 0) argument = call_parameters -> child_list -> first;
      else argument = argument -> next;

      CheckParameterAssignment(declaration, argument);
    }
  }
}

void CheckParameterAssignment(struct TreeNode * declaration, struct TreeNode * expression){

  Check_NodeType(DclN, declaration, "CheckParameterAssignment");
  Check_NodeType(Expr, expression, "CheckParameterAssignment");

  enum Type declaration_type = declaration -> node.DclN -> type;
  enum Type expression_type = expressionType(expression);

  if ((declaration_type == INT_V_ || declaration_type == CHAR_V_) && (expression_type == INT_ || expression_type == CHAR_)){
    printf("%s incompatible integer to pointer conversion passing \'%s\' to parameter of type \'%s\'.\n", ErrorMsg(), IdentifierTypeString(expression_type), IdentifierTypeString(declaration_type));
    exit(EXIT_FAILURE);
  }
  if ((declaration_type == INT_ || declaration_type == CHAR_) && (expression_type == INT_V_ || expression_type == CHAR_V_ || expression_type == INT_P_ || expression_type == CHAR_P_)){
    printf("%s incompatible pointer to integer conversion passing \'%s\' to parameter of type \'%s\'.\n", ErrorMsg(), IdentifierTypeString(expression_type), IdentifierTypeString(declaration_type));
    exit(EXIT_FAILURE);
  }

  if (declaration_type == CHAR_){
    if( expression -> node.Expr -> known){
      if (expression -> node.Expr -> exprVal.intExpr < -128 || expression -> node.Expr -> exprVal.intExpr > 127 ){
        printf("%s  implicit conversion from 'int' to 'char' changes value from %d to %d.\n", ErrorMsg(), expression -> node.Expr -> exprVal.intExpr, (char)expression -> node.Expr -> exprVal.intExpr);
      }
    }
  }

  if (declaration_type == INT_V_ || declaration_type == CHAR_V_){
    // pointer error
    if (declaration_type != expression_type){
      printf("%s incompatible pointer types passing \'%s\' to parameter of type \'%s\'.\n", ErrorMsg(),IdentifierTypeString(expression_type),IdentifierTypeString(declaration_type));
      exit(EXIT_FAILURE);
    }
  }
}

void Check_PrintfCallConcistency(struct TreeNode * function_call){

  Check_NodeType(Expr, function_call, "Check_PrintfCallConcistency");
  Check_ExprType(FC, function_call, "Check_PrintfCallConcistency");

  // check number of parameters
  if (function_call -> child_list -> elements == 0){
    printf("%s too few arguments to function call, expected at least 1, have 0.\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }
  else{

    // first argument must be a string
    struct TreeNode * arguments = function_call -> child_list -> first;
    struct TreeNode * firstArgument = arguments -> child_list -> first;

    if (firstArgument -> node.Expr -> exprType != STR){

      enum Type expression_type = expressionType(firstArgument);

      if (expression_type == INT_ || expression_type == CHAR_){
        printf("%s incompatible integer to pointer conversion passing \'%s\' to parameter of type \'char pointer\'.\n", ErrorMsg(), IdentifierTypeString(expression_type));
        exit(EXIT_FAILURE);
      }
      else if (expression_type == INT_V_){
        printf("%s incompatible pointer types passing \'%s\' to parameter of type \'char pointer\'.\n", ErrorMsg(), IdentifierTypeString(expression_type));
        exit(EXIT_FAILURE);
      }
      else if (expression_type == CHAR_V_)  printf("%s format string is not a string literal (potentially insecure).\n", WarnMsg());
    }
    // if is a string, check format strings
    else{
        char * string = firstArgument -> node.Expr -> exprVal.stringExpr;
        Check_Printf_String(string, arguments);
    }
  }
}

void Check_Printf_String(char * string, struct TreeNode * arguments){

  Check_NodeType(ExprLst, arguments, "Check_Printf_String");

  int string_lenght = strlen(string);

  // check format strings
   int string_format_no = 0;
   enum Type string_format_type;

  for (int i = 0; i < string_lenght; i++){
    // string format check
    if (string[i] == '%'){
      char string_format = string[i+1];
      if (isStringFormat(string_format)){

        if (string_format != '%') string_format_no++;

        if ( string_format_no + 1 > arguments -> child_list -> elements) printf("%s: more \'%%\' conversions than data arguments.\n", WarnMsg());
        else Check_Printf_FormatString_argument(string_format, ExprList_Expression (arguments, string_format_no+1));

        i++;
      }
      else printf("%s invalid conversion specifier '%c'.\n", WarnMsg(), string_format);
    }
  }

  // warning data argument not used
  if (string_format_no + 1 < arguments -> child_list -> elements)
    printf("%s data argument not used by format string.\n", WarnMsg());
}

void Check_ScanfCallConcistency(struct TreeNode * function_call){

  Check_NodeType(Expr, function_call, "Check_ScanfCallConcistency");
  Check_ExprType(FC, function_call, "Check_ScanfCallConcistency");

  // check number of parameters
  if (function_call -> child_list -> elements == 0){
    printf("%s too few arguments to function call, expected at least 1, have 0.\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }
  else{

    // first argument must be a string
    struct TreeNode * arguments = function_call -> child_list -> first;
    struct TreeNode * firstArgument = arguments -> child_list -> first;

    if (firstArgument -> node.Expr -> exprType != STR){

      enum Type expression_type = expressionType(firstArgument);

      if (expression_type != CHAR_V_){
        printf("%s incompatible integer to pointer conversion passing \'%s\' to parameter of type \'char pointer\'.\n", ErrorMsg(), IdentifierTypeString(expression_type));
        exit(EXIT_FAILURE);
      }
    }
    // if is a string, check format strings
    else{
        char * string = firstArgument -> node.Expr -> exprVal.stringExpr;
        Check_Scanf_String(string, arguments);
    }
  }
}

void Check_Scanf_String (char * string, struct TreeNode * arguments){

  Check_NodeType(ExprLst, arguments, "Check_Scanf_String");

  int string_lenght = strlen(string);

  // check format strings
   int string_format_no = 0;
   enum Type string_format_type;

   for (int i = 0; i < string_lenght; i++){
     // string format check
     if (string[i] == '%'){

       char string_format = string[i+1];
       if (isStringFormat(string_format) && string_format != '%'){

         string_format_no++;

         if ( string_format_no + 1 > arguments -> child_list -> elements) printf("%s: more \'%%\' conversions than data arguments.\n", WarnMsg());
         else Check_Scanf_FormatString_argument(string_format, ExprList_Expression (arguments, string_format_no+1));

         i++;
       }
       else printf("%s invalid conversion specifier '%c'.\n", WarnMsg(), string_format);
     }
     else if (string[i] != ' ') printf("%s invalid conversion specifier '%c'.\n", WarnMsg(), string[i]);
   }
}

void Check_Printf_FormatString_argument(char string_form, struct TreeNode * expression){

  enum Type expr_type = expressionType(expression);

  if (string_form == 'd' || string_form == 'i'){
    if (expr_type != INT_ && expr_type != CHAR_){
      printf("%s format specifies type 'int' but the argument has type '%s'.\n", WarnMsg(), IdentifierTypeString(expr_type));
    }
  }
  else if (string_form == 'c'){
    if (expr_type != INT_ && expr_type != CHAR_){
      printf("%s format specifies type 'char' but the argument has type '%s'.\n", WarnMsg(), IdentifierTypeString(expr_type));
    }
  }
  else if (string_form == 'o' || string_form == 'u'){
    if (expr_type != INT_ && expr_type != CHAR_){
      printf("%s format specifies type 'unsigned int' but the argument has type '%s'.\n", WarnMsg(), IdentifierTypeString(expr_type));
    }
  }
  else if (string_form == 's'){
    if (expr_type != CHAR_V_){
      if (expr_type == INT_V_ || expr_type == INT_P_ || expr_type == CHAR_P_) printf("%s format specifies type 'char pointer' but the argument has type '%s'.\n", WarnMsg(), IdentifierTypeString(expr_type));
      else{
        printf("%s format specifies type 'char pointer' but the argument has type '%s'.\n", ErrorMsg(), IdentifierTypeString(expr_type));
        exit(EXIT_FAILURE);
      }
    }
  }
  else if (string_form == 'x' || string_form == 'X'){
    if (expr_type != INT_ && expr_type != CHAR_){
      printf("%s format specifies type 'unsigned int' but the argument has type '%s'.\n", WarnMsg(), IdentifierTypeString(expr_type));
    }
  }
}

void Check_Scanf_FormatString_argument (char string_form, struct TreeNode * expression){

  enum Type expr_type = expressionType(expression);

  if (expression -> node.Expr -> exprType == STR){
    printf("%s a 'costant string' is not assignable.\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }
  if (string_form == 'd' || string_form == 'i'){
    if (expr_type == INT_ || expr_type == CHAR_){
      printf("%s format specifies type 'int pointer' but the argument has type '%s'.\n", ErrorMsg(), IdentifierTypeString(expr_type));
      exit(EXIT_FAILURE);
    }
    else if (expr_type == INT_V_ || expr_type == CHAR_V_ || expr_type == CHAR_P_)
      printf("%s format specifies type 'int pointer' but the argument has type '%s'.\n", WarnMsg(), IdentifierTypeString(expr_type));
  }
  else if (string_form == 'c'){
    if (expr_type == INT_ || expr_type == CHAR_){
      printf("%s format specifies type 'char pointer' but the argument has type '%s'.\n", ErrorMsg(), IdentifierTypeString(expr_type));
      exit(EXIT_FAILURE);
    }
    else if (expr_type == INT_V_ || expr_type == CHAR_V_ || expr_type == INT_P_)
      printf("%s format specifies type 'char pointer' but the argument has type '%s'.\n", WarnMsg(), IdentifierTypeString(expr_type));
  }
  else if (string_form == 'o' || string_form == 'u'){
    if (expr_type == INT_ || expr_type == CHAR_){
      printf("%s format specifies type 'unsigned int' but the argument has type '%s'.\n", ErrorMsg(), IdentifierTypeString(expr_type));
      exit(EXIT_FAILURE);
    }
    else if (expr_type == INT_V_ || expr_type == CHAR_V_ || expr_type == CHAR_P_)
      printf("%s format specifies type 'unsigned int' but the argument has type '%s'.\n", WarnMsg(), IdentifierTypeString(expr_type));
  }
  else if (string_form == 's'){
    if (expr_type == INT_ || expr_type == CHAR_){
      printf("%s format specifies type 'char pointer' but the argument has type '%s'.\n", ErrorMsg(), IdentifierTypeString(expr_type));
      exit(EXIT_FAILURE);
    }
    else if (expr_type == INT_V_ || expr_type == CHAR_V_ || expr_type == INT_P_)
      printf("%s format specifies type 'char pointer' but the argument has type '%s'.\n", WarnMsg(), IdentifierTypeString(expr_type));
  }
  if (string_form == 'x' || string_form == 'X'){
    if (expr_type == INT_ || expr_type == CHAR_){
      printf("%s format specifies type 'unsigned int' but the argument has type '%s'.\n", ErrorMsg(), IdentifierTypeString(expr_type));
      exit(EXIT_FAILURE);
    }
    else if (expr_type == INT_V_ || expr_type == CHAR_V_ || expr_type == CHAR_P_)
      printf("%s format specifies type 'unsigned int' but the argument has type '%s'.\n", WarnMsg(), IdentifierTypeString(expr_type));
  }

}

struct TreeNode * ExprList_Expression(struct TreeNode * exprList, int index){

  Check_NodeType(ExprLst, exprList, "ExprList_Expression");

  if (index > exprList -> child_list -> elements){
    printf("%s ExprList_Expression - index after expression list end.\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }
  else if (index < 1){
    printf("%s ExprList_Expression - index before expression list beginning.\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }
  else{
    struct TreeNode * expression;

    for (int i = 0; i < index; i++){

      if (i == 0) expression = exprList -> child_list -> first;
      else expression = expression -> next;
    }
    return expression;
  }
}

void Check_VariableAddress(struct TreeNode * variable){

  if (variable != NULL){

    // check if the variable is an array without expressed dimension
    if (variable -> node.Expr -> exprType == VEC && variable -> child_list -> elements == 0){
      printf("%s expected expression.\n", ErrorMsg());
      exit(EXIT_FAILURE);
    }
    // check if the variable was declared
    if (variable -> node.Expr -> exprType == ID) Check_IdentifierConcistency(variable);
    if (variable -> node.Expr -> exprType == VEC) Check_ArrayConcistency(variable);

  }
  else{
    printf("%s variable not found.\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }
}

void Warning_Unused(struct TreeNode * node){

  Check_NodeType(Expr, node, "Warning_Unused");

  enum exprType type = node -> node.Expr -> exprType;

  switch (type) {

    case NUM: printf("%s expression result unused.\n", WarnMsg());
              break;
    case ID:  printf("%s expression result unused.\n", WarnMsg());
              break;
    case VEC: printf("%s expression result unused.\n", WarnMsg());
              break;
    case STR: printf("%s expression result unused.\n", WarnMsg());
              break;
    case C:   printf("%s expression result unused.\n", WarnMsg());
              break;
    case FC:  break;
    case SUM: printf("%s expression result unused.\n", WarnMsg());
              break;
    case DIF: printf("%s expression result unused.\n", WarnMsg());
              break;
    case TIM: printf("%s expression result unused.\n", WarnMsg());
              break;
    case DIV: printf("%s expression result unused.\n", WarnMsg());
              break;
    case MOD: printf("%s expression result unused.\n", WarnMsg());
              break;
    case RND: printf("%s expression result unused.\n", WarnMsg());
              break;
    case CMP: printf("%s expression result unused.\n", WarnMsg());
              break;
    case PI:  break;
    case PD:  break;
    case IP:  break;
    case DP:  break;
    case ADD: printf("%s expression result unused.\n", WarnMsg());
              break;
    default:  break;

  }
}

//////////////////  execution CONTROL  /////////////////////////////////////////

int Check_Main(){

  struct FunNode * actualFunction =  MainNode -> function_list -> last;
  if (!strcmp("main", actualFunction -> funName)) return 1;
  else return 0;
}

char Check_activation(){
  struct Scope * actualScope = MainNode -> actual_stack -> top;
  // activation value is by default inherited by previous scope
  return actualScope -> active;
}

void Scope_Activation(){

  struct Scope * actualScope = MainNode -> actual_stack -> top;
  // check if previous scope is active
  if (actualScope -> prevScope -> active){
    actualScope -> active = 1;
  }
}

int Function_End(){

  // Return warning
  if (MainNode -> actual_stack -> top -> return_flag == 0)
    printf("%s control may reach end of non-void function.\n", WarnMsg());

  // Resetting global scope as actual scope
  MainNode -> actual_stack = MainNode -> global_scope_stack;

  if (!strcmp("main", MainNode -> function_list -> last -> funName)) return 1;
  else return 0;
}

void Update_return_flag(){

  MainNode -> actual_stack -> top -> return_flag = 1;
}

void Propagate_return_flag(){

  if (MainNode -> actual_stack -> top -> return_flag == 1)
    MainNode -> actual_stack -> top -> prevScope -> return_flag = 1;
}

int Check_return_statement(struct TreeNode * scope){

  Check_NodeType(Scope, scope, "Check_return_statement");
  struct TreeNode * statement;

  for (int i = 0; i < scope -> child_list -> elements; i++){
    if (i == 0) statement = scope -> child_list -> first;
    else statement = statement -> next;

    if (statement -> nodeType == Return) return 1;
  }

  return 0;
}

int Return_main (struct TreeNode * node){

  if (node != NULL) {

    Check_NodeType(Expr, node, "Return");

    MainNode -> return_value = Expr_toInt(node);
    return 1;
  }
  else return 0;
}

