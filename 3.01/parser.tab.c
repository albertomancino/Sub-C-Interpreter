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
     MAIN = 270,
     RETURN = 271,
     STRING = 272,
     CH = 273,
     IF = 274,
     ELSE = 275,
     WHILE = 276,
     INC = 277,
     DEC = 278,
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
#define MAIN 270
#define RETURN 271
#define STRING 272
#define CH 273
#define IF 274
#define ELSE 275
#define WHILE 276
#define INC 277
#define DEC 278
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

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"

enum exprType;

int L_DEBUGGING = 0;
int P_DEBUGGING = 0;
int TREE_DEBUGGING = 0;
int TREE_BUILDING = 1;
int ST_DEBUGGING = 0;
int EXEC = 1;
int ERR = 1;

int yylineno;
ProgramNode * MainNode;
struct ErrorList * Errors;
struct TreeNode * NullTreeNode;



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
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   519

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  107
/* YYNRULES -- Number of states.  */
#define YYNSTATES  184

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
       0,     0,     3,     4,     8,    11,    14,    16,    18,    20,
      23,    26,    29,    32,    34,    37,    40,    44,    47,    50,
      54,    57,    59,    63,    67,    70,    72,    74,    77,    79,
      81,    84,    86,    89,    92,    95,    98,   101,   103,   105,
     107,   112,   116,   118,   121,   126,   129,   135,   140,   144,
     146,   148,   154,   159,   163,   167,   171,   173,   177,   181,
     185,   189,   193,   197,   201,   205,   209,   213,   216,   220,
     224,   228,   230,   234,   238,   241,   243,   245,   248,   251,
     253,   255,   257,   259,   261,   263,   265,   269,   272,   275,
     278,   281,   285,   289,   293,   297,   301,   305,   309,   313,
     317,   321,   325,   329,   331,   333,   335,   340
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      37,     0,    -1,    -1,    38,    41,    42,    -1,    38,    42,
      -1,    41,    42,    -1,    42,    -1,    39,    -1,    40,    -1,
      38,    40,    -1,    65,     8,    -1,    64,     8,    -1,    63,
       8,    -1,    44,    -1,    41,    44,    -1,    43,    48,    -1,
       3,    15,    46,    -1,    45,    48,    -1,    65,    46,    -1,
       9,    47,    10,    -1,     9,    10,    -1,    65,    -1,    47,
      24,    65,    -1,    49,    50,    14,    -1,    49,    14,    -1,
      13,    -1,    51,    -1,    50,    51,    -1,    52,    -1,    48,
      -1,    70,     8,    -1,    69,    -1,    65,     8,    -1,    66,
       8,    -1,    63,     8,    -1,    62,     8,    -1,    64,     8,
      -1,    54,    -1,    59,    -1,     8,    -1,     5,     9,    68,
      10,    -1,     5,     9,    10,    -1,    56,    -1,    56,    55,
      -1,    57,    13,    50,    14,    -1,    57,    52,    -1,    58,
      60,    13,    50,    14,    -1,    58,    60,    13,    14,    -1,
      58,    60,    52,    -1,    20,    -1,    19,    -1,    61,    60,
      13,    50,    14,    -1,    61,    60,    13,    14,    -1,    61,
      60,    52,    -1,     9,    70,    10,    -1,     9,    66,    10,
      -1,    21,    -1,    66,    24,    66,    -1,    62,    24,    66,
      -1,    65,    24,    76,    -1,    64,    24,    76,    -1,    63,
       7,    70,    -1,    63,     7,    67,    -1,    63,    24,    76,
      -1,    65,     7,    70,    -1,    65,     7,    67,    -1,    64,
       7,    70,    -1,    75,    76,    -1,    70,     7,    70,    -1,
      66,     7,    70,    -1,    13,    68,    14,    -1,    70,    -1,
      68,    24,    70,    -1,    16,    70,     8,    -1,    16,     8,
      -1,    74,    -1,     6,    -1,    32,     6,    -1,    31,     6,
      -1,    76,    -1,    17,    -1,    18,    -1,    53,    -1,    73,
      -1,    71,    -1,    72,    -1,     9,    66,    10,    -1,    22,
      76,    -1,    23,    76,    -1,    76,    22,    -1,    76,    23,
      -1,    70,    32,    70,    -1,    70,    31,    70,    -1,    70,
      35,    70,    -1,    70,    34,    70,    -1,    70,    33,    70,
      -1,     9,    70,    10,    -1,    70,    30,    70,    -1,    70,
      29,    70,    -1,    70,    28,    70,    -1,    70,    27,    70,
      -1,    70,    26,    70,    -1,    70,    25,    70,    -1,     3,
      -1,     4,    -1,     5,    -1,     5,    11,    70,    12,    -1,
       5,    11,    12,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    99,    99,   101,   102,   103,   104,   108,   112,   113,
     117,   118,   119,   123,   124,   128,   132,   136,   141,   145,
     146,   150,   151,   155,   156,   160,   164,   165,   169,   170,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     194,   195,   202,   203,   207,   208,   212,   213,   214,   218,
     222,   226,   227,   228,   232,   233,   237,   241,   242,   246,
     247,   248,   249,   250,   254,   255,   256,   260,   264,   265,
     269,   273,   274,   278,   279,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   298,   299,   303,
     304,   308,   309,   310,   311,   312,   313,   317,   318,   319,
     320,   321,   322,   326,   327,   331,   332,   333
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "CHAR", "IDENTIFIER", "NUMBER",
  "EQUAL", "END_COMMA", "OPEN_ROUND", "CLOSED_ROUND", "OPEN_SQUARED",
  "CLOSED_SQUARED", "OPEN_BRACKET", "CLOSED_BRACKET", "MAIN", "RETURN",
  "STRING", "CH", "IF", "ELSE", "WHILE", "INC", "DEC", "COMMA", "DF", "ET",
  "LT", "GT", "OR", "AND", "MINUS", "PLUS", "MODULO", "DIVIDE", "STAR",
  "$accept", "program", "global_scope", "global_scope_body",
  "global_statements", "function_list", "main_function",
  "main_function_declaration", "function", "function_declaration",
  "arguments_declaration", "arguments_declaration_list", "scope",
  "start_scope", "statement_list", "statement_scope", "statement",
  "function_call", "if_else_statement", "else_statement", "if_statement",
  "else_declaration", "if_declaration", "while_statement", "condition",
  "while_declaration", "multi_asgn", "multi_dec",
  "declaration_and_assignment", "declaration", "assignment",
  "array_inizializer", "expr_list", "return_statement", "expr",
  "pre_incdec", "post_incdec", "operation", "comparison", "type",
  "variable", 0
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
       0,    36,    37,    37,    37,    37,    37,    38,    39,    39,
      40,    40,    40,    41,    41,    42,    43,    44,    45,    46,
      46,    47,    47,    48,    48,    49,    50,    50,    51,    51,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      53,    53,    54,    54,    55,    55,    56,    56,    56,    57,
      58,    59,    59,    59,    60,    60,    61,    62,    62,    63,
      63,    63,    63,    63,    64,    64,    64,    65,    66,    66,
      67,    68,    68,    69,    69,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    71,    71,    72,
      72,    73,    73,    73,    73,    73,    73,    74,    74,    74,
      74,    74,    74,    75,    75,    76,    76,    76
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     2,     2,     1,     1,     1,     2,
       2,     2,     2,     1,     2,     2,     3,     2,     2,     3,
       2,     1,     3,     3,     2,     1,     1,     2,     1,     1,
       2,     1,     2,     2,     2,     2,     2,     1,     1,     1,
       4,     3,     1,     2,     4,     2,     5,     4,     3,     1,
       1,     5,     4,     3,     3,     3,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     3,
       3,     1,     3,     3,     2,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     3,     2,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     1,     4,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,   103,   104,     0,     0,     7,     8,     0,     6,     0,
      13,     0,     0,     0,     0,     0,     0,     1,     9,     0,
       4,     5,    14,     0,    25,    15,     0,    17,     0,    12,
       0,     0,    11,     0,     0,    10,     0,     0,    18,   105,
      67,    16,     3,   103,   105,    76,    39,     0,    24,     0,
      80,    81,    50,    56,     0,     0,     0,     0,    29,     0,
      26,    28,    82,    37,    42,     0,    38,     0,     0,     0,
       0,     0,     0,    31,     0,    84,    85,    83,    75,    79,
       0,    62,    61,    63,    66,    60,    65,    64,    20,     0,
      21,    59,     0,     0,     0,     0,    74,     0,    87,    88,
      78,    77,    23,    27,    49,    43,     0,     0,     0,     0,
      35,     0,    34,    36,    32,     0,    33,     0,     0,    30,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    89,    90,     0,    71,    19,     0,   107,     0,    41,
       0,    86,    96,    73,     0,    45,     0,     0,     0,    48,
       0,    53,    58,     0,    69,    57,    68,   102,   101,   100,
      99,    98,    97,    92,    91,    95,    94,    93,    70,     0,
      22,   106,    40,     0,    55,    54,    47,     0,    52,     0,
      72,    44,    46,    51
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      38,    89,    58,    26,    59,    60,    61,    62,    63,   105,
      64,   106,    65,    66,   108,    67,    68,    69,    70,    71,
      72,    81,   133,    73,    74,    75,    76,    77,    78,    15,
      79
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -58
static const yytype_int16 yypact[] =
{
     114,    21,   -58,    57,   114,   -58,   -58,   114,   -58,    59,
     -58,    59,     8,    10,     4,    76,   119,   -58,   -58,   114,
     -58,   -58,   -58,   119,   -58,   -58,    37,   -58,   414,   -58,
      76,   465,   -58,    76,   414,   -58,   111,    76,   -58,   122,
     -58,   -58,   -58,   -58,   127,   -58,   -58,   465,   -58,   416,
     -58,   -58,   -58,   -58,    76,    76,   140,   148,   -58,   126,
     -58,   -58,   -58,   -58,   139,   153,   -58,   153,     2,    15,
      54,    67,   433,   -58,    78,   -58,   -58,   -58,   -58,   265,
     465,   -58,   355,   -58,   355,   -58,   -58,   355,   -58,    20,
     -58,   -58,   444,   463,    28,   332,   -58,   383,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,   -58,   252,   465,   273,   294,
     -58,   465,   -58,   -58,   -58,   465,   -58,   465,   465,   -58,
     465,   465,   465,   465,   465,   465,   465,   465,   465,   465,
     465,   -58,   -58,   -10,   355,   -58,   305,   -58,   477,   -58,
      23,   -58,   -58,   -58,   315,   -58,    56,   343,   147,   -58,
     168,   -58,   160,   372,   355,   160,   355,   484,   484,   484,
     484,   361,   361,   310,   310,   -58,   -58,   -58,   -58,   465,
     -58,   -58,   -58,   189,   -58,   -58,   -58,   210,   -58,   231,
     355,   -58,   -58,   -58
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -58,   -58,   -58,   -58,   171,   176,    69,   -58,    63,   -58,
     167,   -58,   255,   -58,   -25,   -57,    18,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,   121,   -58,   -58,    25,    80,     1,
     -40,   162,   108,   -58,   -28,   -58,   -58,   -58,   -58,   -58,
      -6
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      82,    14,   103,    84,   168,    14,    87,    94,    23,    40,
     110,    34,    35,    36,   169,    28,    29,    31,    32,    95,
      23,    97,    28,   112,    83,    12,   111,    85,    37,    12,
     135,    91,    30,   172,    33,   115,    16,    90,   141,    30,
      43,     2,    44,    45,   136,    46,    47,   169,    98,    99,
      24,    48,   134,    49,    50,    51,    52,    17,    53,    54,
      55,    31,   113,   115,   138,   134,   174,   146,    56,    57,
      22,   152,    24,    20,    34,   114,    21,   155,    33,   147,
      13,    39,    22,   153,    13,   118,   119,   154,    42,   153,
     156,    37,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,    43,     2,   103,     1,     2,   173,
     103,    88,   103,   177,   145,   179,   149,   151,    36,    43,
       2,    44,    45,    92,    46,    47,    93,   170,    92,    24,
     102,   180,    49,    50,    51,    52,   100,    53,    54,    55,
      43,     2,    44,    45,   101,    46,    47,    56,    57,   104,
      24,   176,   107,    49,    50,    51,    52,   115,    53,    54,
      55,    43,     2,    44,    45,    18,    46,    47,    56,    57,
      19,    24,   178,    41,    49,    50,    51,    52,   109,    53,
      54,    55,    43,     2,    44,    45,    86,    46,    47,    56,
      57,   140,    24,   181,     0,    49,    50,    51,    52,     0,
      53,    54,    55,    43,     2,    44,    45,     0,    46,    47,
      56,    57,     0,    24,   182,     0,    49,    50,    51,    52,
       0,    53,    54,    55,    43,     2,    44,    45,     0,    46,
      47,    56,    57,     0,    24,   183,     0,    49,    50,    51,
      52,     0,    53,    54,    55,    43,     2,    44,    45,     0,
      46,    47,    56,    57,    25,   144,    27,     0,    49,    50,
      51,    52,     0,    53,    54,    55,    43,     2,    44,    45,
       0,    46,    47,    56,    57,     0,   148,   131,   132,    49,
      50,    51,    52,     0,    53,    54,    55,    43,     2,    44,
      45,     0,    46,    47,    56,    57,     0,   150,    43,     2,
      49,    50,    51,    52,     0,    53,    54,    55,    43,     2,
      44,    45,     0,    46,    47,    56,    57,     0,    24,     0,
       0,    49,    50,    51,    52,     0,    53,    54,    55,   118,
       0,     0,   142,   128,   129,   130,    56,    57,     0,     0,
     118,     0,     0,   175,     0,     0,     0,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   118,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   143,   126,   127,   128,   129,   130,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,    44,
      45,    44,    45,    47,    96,    47,     0,    80,     0,     0,
       0,    50,    51,    50,    51,     0,    54,    55,    54,    55,
     115,   116,     0,     0,     0,    56,    57,    56,    57,    44,
      45,     0,     0,    47,     0,     0,   137,   117,     0,     0,
       0,    50,    51,     0,     0,     0,    54,    55,    44,    45,
      44,    45,    47,   139,    47,    56,    57,     0,     0,     0,
      50,    51,    50,    51,     0,    54,    55,    54,    55,   171,
       0,     0,     0,     0,    56,    57,    56,    57,     0,     0,
       0,     0,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   124,   125,   126,   127,   128,   129,   130
};

static const yytype_int16 yycheck[] =
{
      28,     0,    59,    31,    14,     4,    34,    47,     7,    15,
       8,     7,     8,     9,    24,     7,     8,     7,     8,    47,
      19,    49,     7,     8,    30,     0,    24,    33,    24,     4,
      10,    37,    24,    10,    24,     7,    15,    36,    10,    24,
       3,     4,     5,     6,    24,     8,     9,    24,    54,    55,
      13,    14,    80,    16,    17,    18,    19,     0,    21,    22,
      23,     7,     8,     7,    92,    93,    10,   107,    31,    32,
       7,   111,    13,     4,     7,     8,     7,   117,    24,   107,
       0,     5,    19,   111,     4,     7,     8,   115,    19,   117,
     118,    24,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     3,     4,   173,     3,     4,   144,
     177,    10,   179,   148,   106,   150,   108,   109,     9,     3,
       4,     5,     6,    11,     8,     9,     9,   136,    11,    13,
      14,   169,    16,    17,    18,    19,     6,    21,    22,    23,
       3,     4,     5,     6,     6,     8,     9,    31,    32,    20,
      13,    14,     9,    16,    17,    18,    19,     7,    21,    22,
      23,     3,     4,     5,     6,     4,     8,     9,    31,    32,
       4,    13,    14,    16,    16,    17,    18,    19,    67,    21,
      22,    23,     3,     4,     5,     6,    34,     8,     9,    31,
      32,    93,    13,    14,    -1,    16,    17,    18,    19,    -1,
      21,    22,    23,     3,     4,     5,     6,    -1,     8,     9,
      31,    32,    -1,    13,    14,    -1,    16,    17,    18,    19,
      -1,    21,    22,    23,     3,     4,     5,     6,    -1,     8,
       9,    31,    32,    -1,    13,    14,    -1,    16,    17,    18,
      19,    -1,    21,    22,    23,     3,     4,     5,     6,    -1,
       8,     9,    31,    32,     9,    13,    11,    -1,    16,    17,
      18,    19,    -1,    21,    22,    23,     3,     4,     5,     6,
      -1,     8,     9,    31,    32,    -1,    13,    22,    23,    16,
      17,    18,    19,    -1,    21,    22,    23,     3,     4,     5,
       6,    -1,     8,     9,    31,    32,    -1,    13,     3,     4,
      16,    17,    18,    19,    -1,    21,    22,    23,     3,     4,
       5,     6,    -1,     8,     9,    31,    32,    -1,    13,    -1,
      -1,    16,    17,    18,    19,    -1,    21,    22,    23,     7,
      -1,    -1,    10,    33,    34,    35,    31,    32,    -1,    -1,
       7,    -1,    -1,    10,    -1,    -1,    -1,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,     7,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,     8,    31,    32,    33,    34,    35,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,     5,
       6,     5,     6,     9,     8,     9,    -1,    13,    -1,    -1,
      -1,    17,    18,    17,    18,    -1,    22,    23,    22,    23,
       7,     8,    -1,    -1,    -1,    31,    32,    31,    32,     5,
       6,    -1,    -1,     9,    -1,    -1,    12,    24,    -1,    -1,
      -1,    17,    18,    -1,    -1,    -1,    22,    23,     5,     6,
       5,     6,     9,    10,     9,    31,    32,    -1,    -1,    -1,
      17,    18,    17,    18,    -1,    22,    23,    22,    23,    12,
      -1,    -1,    -1,    -1,    31,    32,    31,    32,    -1,    -1,
      -1,    -1,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    29,    30,    31,    32,    33,    34,    35
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    63,    64,    65,    75,    15,     0,    40,    41,
      42,    42,    44,    65,    13,    48,    49,    48,     7,     8,
      24,     7,     8,    24,     7,     8,     9,    24,    46,     5,
      76,    46,    42,     3,     5,     6,     8,     9,    14,    16,
      17,    18,    19,    21,    22,    23,    31,    32,    48,    50,
      51,    52,    53,    54,    56,    58,    59,    61,    62,    63,
      64,    65,    66,    69,    70,    71,    72,    73,    74,    76,
      13,    67,    70,    76,    70,    76,    67,    70,    10,    47,
      65,    76,    11,     9,    66,    70,     8,    70,    76,    76,
       6,     6,    14,    51,    20,    55,    57,     9,    60,    60,
       8,    24,     8,     8,     8,     7,     8,    24,     7,     8,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    22,    23,    68,    70,    10,    24,    12,    70,    10,
      68,    10,    10,     8,    13,    52,    66,    70,    13,    52,
      13,    52,    66,    70,    70,    66,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    14,    24,
      65,    12,    10,    50,    10,    10,    14,    50,    14,    50,
      70,    14,    14,    14
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
        case 7:
#line 108 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Global_scope found\n");;}
    break;

  case 8:
#line 112 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Global_scope_body found\n");;}
    break;

  case 9:
#line 113 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Global_scope_body found\n");;}
    break;

  case 10:
#line 117 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Global declaration statement found\n");                if(TREE_BUILDING) Add_Node_Tree(MainNode, (yyvsp[(1) - (2)].node));  if(EXEC) exec_DclN(MainNode, (yyvsp[(1) - (2)].node));}
    break;

  case 11:
#line 118 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Global declaration and assignment statement found\n"); if(TREE_BUILDING) Add_Node_Tree(MainNode, (yyvsp[(1) - (2)].node));;}
    break;

  case 13:
#line 123 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Function list found1\n");;}
    break;

  case 14:
#line 124 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Function list found2\n");;}
    break;

  case 15:
#line 128 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: MAIN function found\n"); /* Resetting global scope as acutal scope*/ MainNode -> actual_stack = MainNode -> global_scope_stack;;}
    break;

  case 16:
#line 132 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: MAIN function declaration found\n");    if(TREE_BUILDING) create_MainFunction(MainNode, (yyvsp[(3) - (3)].node));;}
    break;

  case 17:
#line 136 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Function found\n"); /* Resetting global scope as acutal scope*/ MainNode -> actual_stack = MainNode -> global_scope_stack;;}
    break;

  case 18:
#line 141 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Function declaration found\n");         create_FunctionNode((yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node)); if(TREE_BUILDING) {FunNodeList_Add (MainNode, (yyvsp[(1) - (2)].node)); Add_Node_Tree(MainNode, (yyvsp[(2) - (2)].node));};}
    break;

  case 19:
#line 145 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: arguments_declaration1 found\n");       if(TREE_BUILDING) (yyval.node) = (yyvsp[(2) - (3)].node);}
    break;

  case 20:
#line 146 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: arguments_declaration1 found\n");       if(TREE_BUILDING) (yyval.node) = create_Arg_ListNode(NULL, NULL);;}
    break;

  case 21:
#line 150 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: arguments_declaration_list1 found\n");  if(TREE_BUILDING) (yyval.node) = create_Arg_ListNode(NULL, (yyvsp[(1) - (1)].node));;}
    break;

  case 22:
#line 151 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: arguments_declaration_list2 found\n");  if(TREE_BUILDING) (yyval.node) = create_Arg_ListNode((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));;}
    break;

  case 23:
#line 155 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: End of the scope found\n");             if(TREE_BUILDING) ScopeStack_Pop(MainNode -> actual_stack);/*SymbolTable_Print(MainNode->ActualScope->last -> ThisScope.Tree -> node.ST); ScopeStack_Rem(MainNode->ActualScope);*/;}
    break;

  case 24:
#line 156 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: New empty scope found\n");              if(TREE_BUILDING) ScopeStack_Pop(MainNode -> actual_stack);/*ScopeStack_Rem(MainNode->ActualScope);*/;}
    break;

  case 25:
#line 160 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Start of the scope found\n");           if(TREE_BUILDING) { (yyval.node) = create_ScopeNode(); Add_Node_Tree(MainNode, (yyval.node)); SetAs_ActualScope(MainNode, (yyval.node), Check_activation());};}
    break;

  case 30:
#line 176 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Expr statement found\n");                                       if(TREE_BUILDING) Add_Node_Tree(MainNode, (yyvsp[(1) - (2)].node)); if(Check_activation()) exec_Expression((yyvsp[(1) - (2)].node));;}
    break;

  case 31:
#line 177 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Return statement found\n");                                     if(TREE_BUILDING) Add_Node_Tree(MainNode, (yyvsp[(1) - (1)].node));;}
    break;

  case 32:
#line 178 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Declaration statement found\n");   if(Check_ArrayDimension((yyvsp[(1) - (2)].node))) if(TREE_BUILDING) Add_Node_Tree(MainNode, (yyvsp[(1) - (2)].node)); exec_DclN(MainNode,(yyvsp[(1) - (2)].node));;}
    break;

  case 33:
#line 179 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Assignment statement found\n");                                 if(TREE_BUILDING) Add_Node_Tree(MainNode, (yyvsp[(1) - (2)].node)); if(Check_activation()) exec_Asgn(MainNode,(yyvsp[(1) - (2)].node));;}
    break;

  case 34:
#line 180 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Multi declaration statement found\n");                          if(TREE_BUILDING) Add_Node_Tree(MainNode, (yyvsp[(1) - (2)].node)); if(Check_activation()) exec_Multi_DclN((yyvsp[(1) - (2)].node));;}
    break;

  case 35:
#line 181 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Multi assignment statement found\n");                           if(TREE_BUILDING) Add_Node_Tree(MainNode, (yyvsp[(1) - (2)].node)); if(Check_activation()) exec_Multi_Asgn((yyvsp[(1) - (2)].node));;}
    break;

  case 36:
#line 182 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Declaration and assignment statement found\n");                 if(TREE_BUILDING) Add_Node_Tree(MainNode, (yyvsp[(1) - (2)].node)); if(Check_activation()) exec_DclN_Asgn((yyvsp[(1) - (2)].node));}
    break;

  case 37:
#line 183 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: IF statement statement found\n");                               if(TREE_BUILDING) Add_Node_Tree(MainNode, (yyvsp[(1) - (1)].node)); if(Check_activation()) exec_ifElse((yyvsp[(1) - (1)].node));}
    break;

  case 38:
#line 184 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: WHILE statement statement found\n");                            if(TREE_BUILDING) Add_Node_Tree(MainNode, (yyvsp[(1) - (1)].node)); if(Check_activation()) exec_while((yyvsp[(1) - (1)].node));}
    break;

  case 39:
#line 185 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Empty statement found\n");;}
    break;

  case 40:
#line 194 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Function call1 found\n");               if(TREE_BUILDING) (yyval.node) = create_Function_CallNode(MainNode, (yyvsp[(1) - (4)].string), (yyvsp[(3) - (4)].node));         if(TREE_DEBUGGING) printf("TREE: Function call statement node created\n");;}
    break;

  case 41:
#line 195 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Function call2 found\n");               if(TREE_BUILDING) (yyval.node) = create_Function_CallNode(MainNode, (yyvsp[(1) - (3)].string), NULL);       if(TREE_DEBUGGING) printf("TREE: Function call statement node created\n");;}
    break;

  case 42:
#line 202 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: If-else statement1 found\n");           if(TREE_BUILDING) (yyval.node) = create_IfElseNode((yyvsp[(1) - (1)].node), NULL);                        if(TREE_DEBUGGING) printf("TREE: If-else statement node created\n");;}
    break;

  case 43:
#line 203 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: If-else statement1 found\n");           if(TREE_BUILDING) (yyval.node) = create_IfElseNode((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));                          if(TREE_DEBUGGING) printf("TREE: If-else statement node created\n");;}
    break;

  case 44:
#line 207 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Else statement1 found\n");              if(TREE_BUILDING) (yyval.node) = create_ElseNode((yyvsp[(1) - (4)].node));                                if(TREE_DEBUGGING) printf("TREE: Else statement node created\n");;}
    break;

  case 45:
#line 208 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Else statement2 found\n");              if(TREE_BUILDING) (yyval.node) = create_ElseNode((yyvsp[(1) - (2)].node));                                if(TREE_DEBUGGING) printf("TREE: Else statement node created\n");;}
    break;

  case 46:
#line 212 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: If statement1 found\n");                if(TREE_BUILDING) (yyval.node) = create_IfNode((yyvsp[(1) - (5)].node),(yyvsp[(2) - (5)].node));                               if(TREE_DEBUGGING) printf("TREE: If statement node created\n");;}
    break;

  case 47:
#line 213 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: If statement2 found\n");                if(TREE_BUILDING) (yyval.node) = create_IfNode((yyvsp[(1) - (4)].node),(yyvsp[(2) - (4)].node));                               if(TREE_DEBUGGING) printf("TREE: If statement node created\n");;}
    break;

  case 48:
#line 214 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: If statement3 found\n");                if(TREE_BUILDING) (yyval.node) = create_IfNode((yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node));                               if(TREE_DEBUGGING) printf("TREE: If statement node created\n");;}
    break;

  case 49:
#line 218 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Else declaration found\n");             if(TREE_BUILDING) (yyval.node) = create_ElseDeclaration();                           if(TREE_DEBUGGING) printf("TREE: Else node created\n");;}
    break;

  case 50:
#line 222 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: If declaration found\n");               if(TREE_BUILDING) (yyval.node) = create_IfDeclaration();                             if(TREE_DEBUGGING) printf("TREE: If node created\n");;}
    break;

  case 51:
#line 226 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: While statement1 found\n");             if(TREE_BUILDING) (yyval.node) = create_WhileNode((yyvsp[(1) - (5)].node),(yyvsp[(2) - (5)].node));                            if(TREE_DEBUGGING) printf("TREE: While statement node created\n");;}
    break;

  case 52:
#line 227 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: While statement2 found\n");             if(TREE_BUILDING) (yyval.node) = create_WhileNode((yyvsp[(1) - (4)].node),(yyvsp[(2) - (4)].node));                            if(TREE_DEBUGGING) printf("TREE: While statement node created\n");;}
    break;

  case 53:
#line 228 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: While statement3 found\n");             if(TREE_BUILDING) (yyval.node) = create_WhileNode((yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node));                            if(TREE_DEBUGGING) printf("TREE: While statement node created\n");;}
    break;

  case 54:
#line 232 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: While condition1 found\n");             if(TREE_BUILDING)  (yyval.node) = create_Condition((yyvsp[(2) - (3)].node));                              if(TREE_DEBUGGING) printf("TREE: Condition node created\n");;}
    break;

  case 55:
#line 233 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: While condition2 found\n");             if(TREE_BUILDING)  (yyval.node) = create_Condition((yyvsp[(2) - (3)].node));                              if(TREE_DEBUGGING) printf("TREE: Condition node created\n");;}
    break;

  case 56:
#line 237 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: While declaration found\n");            if(TREE_BUILDING) (yyval.node) = create_WhileDeclaration();                          if(TREE_DEBUGGING) printf("TREE: While node created\n");;}
    break;

  case 57:
#line 241 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Multi assignment1 found\n");            if(TREE_BUILDING) (yyval.node) = create_MultiAssignment((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));                     if(TREE_DEBUGGING) printf("TREE: Multi assignment node created\n");;}
    break;

  case 58:
#line 242 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Multi assignment2 found\n");            if(TREE_BUILDING) (yyval.node) = create_MultiAssignment((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));                     if(TREE_DEBUGGING) printf("TREE: Multi assignment node created\n");;}
    break;

  case 59:
#line 246 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Multi declaration1 found\n");           if(TREE_BUILDING) (yyval.node) = create_MultiDeclaration((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), 1);                 if(TREE_DEBUGGING) printf("TREE: Multi declaration node created\n");;}
    break;

  case 60:
#line 247 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Multi declaration2 found\n");           if(TREE_BUILDING) (yyval.node) = create_MultiDeclaration((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), 1);                 if(TREE_DEBUGGING) printf("TREE: Multi declaration node created\n");;}
    break;

  case 61:
#line 248 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Multi declaration3 found\n");           if(TREE_BUILDING) (yyval.node) = create_MultiDeclaration((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), 0);                 if(TREE_DEBUGGING) printf("TREE: Multi declaration node created\n");;}
    break;

  case 62:
#line 249 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Multi declaration4 found\n");           if(TREE_BUILDING) (yyval.node) = create_MultiDeclaration((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), 0);                 if(TREE_DEBUGGING) printf("TREE: Multi declaration node created\n");;}
    break;

  case 63:
#line 250 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: Multi declaration5 found\n");           if(TREE_BUILDING) (yyval.node) = create_MultiDeclaration((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), 1);                  if(TREE_DEBUGGING) printf("TREE: Multi declaration node created\n");;}
    break;

  case 64:
#line 254 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: declaration and assignment 1 found\n"); if(TREE_BUILDING) (yyval.node) = create_Declaration_AssignmentNode ((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));         if(TREE_DEBUGGING) printf("TREE: Declaration and Assignment node created\n");;}
    break;

  case 65:
#line 255 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: declaration and assignment 2 found\n"); if(TREE_BUILDING) (yyval.node) = create_Declaration_AssignmentNode ((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));         if(TREE_DEBUGGING) printf("TREE: Declaration and Assignment node created\n");;}
    break;

  case 66:
#line 256 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: declaration and assignment 3 found\n"); if(TREE_BUILDING) (yyval.node) = create_Declaration_AssignmentNode ((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));         if(TREE_DEBUGGING) printf("TREE: Declaration and Assignment node created\n");;}
    break;

  case 67:
#line 260 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: declaration found\n");                  if(TREE_BUILDING) (yyval.node) = create_DeclarationNode((yyvsp[(1) - (2)].intValue), (yyvsp[(2) - (2)].node));                     if(TREE_DEBUGGING) printf("TREE: Declaration node created\n");;}
    break;

  case 68:
#line 264 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: assignment1 found\n");                  if(TREE_BUILDING) (yyval.node) = create_AssignmentNode(MainNode, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));            if(TREE_DEBUGGING) printf("TREE: Assignment node created\n");}
    break;

  case 69:
#line 265 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: assignment2 found\n");                  if(TREE_BUILDING) (yyval.node) = create_AssignmentNode(MainNode, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));            if(TREE_DEBUGGING) printf("TREE: Assignment node created\n");}
    break;

  case 70:
#line 269 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: array initializer found\n");            if(TREE_BUILDING) (yyval.node)=(yyvsp[(2) - (3)].node);;}
    break;

  case 71:
#line 273 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: expression1 list found\n");             if(TREE_BUILDING) (yyval.node) = create_Expr_ListNode(NULL, (yyvsp[(1) - (1)].node));                     if(TREE_DEBUGGING) printf("TREE: Expression list node created\n");;}
    break;

  case 72:
#line 274 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: expression2 list found\n");             if(TREE_BUILDING) (yyval.node) = create_Expr_ListNode((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));                       if(TREE_DEBUGGING) printf("TREE: Expression list node created\n");;}
    break;

  case 73:
#line 278 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: return statement1 found\n");            if(TREE_BUILDING) (yyval.node) = create_ReturnNode((yyvsp[(2) - (3)].node));                              if(TREE_DEBUGGING) printf("TREE: Return node created\n");;}
    break;

  case 74:
#line 279 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: return statement2 found\n");            if(TREE_BUILDING) (yyval.node) = create_ReturnNode(NULL);                            if(TREE_DEBUGGING) printf("TREE: Return node created\n");;}
    break;

  case 75:
#line 283 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: comparison -> expr\n");                 if(TREE_BUILDING) (yyval.node) = (yyvsp[(1) - (1)].node);                                                 if(TREE_DEBUGGING) printf("TREE: Expr node compare type created\n");;}
    break;

  case 76:
#line 284 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: integer -> expr\n");                    if(TREE_BUILDING) (yyval.node) = create_ExprNode(NUM, (yyvsp[(1) - (1)].intValue), NULL, NULL, NULL, 0);      if(TREE_DEBUGGING) printf("TREE: Expr node integer type created\n");;}
    break;

  case 77:
#line 285 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: positive integer -> expr\n");           if(TREE_BUILDING) (yyval.node) = create_ExprNode(NUM, (yyvsp[(2) - (2)].intValue), NULL, NULL, NULL, 0);      if(TREE_DEBUGGING) printf("TREE: Expr node integer type created\n");;}
    break;

  case 78:
#line 286 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: negative integer -> expr\n");           if(TREE_BUILDING) (yyval.node) = create_ExprNode(NUM, -(yyvsp[(2) - (2)].intValue), NULL, NULL, NULL, 0);     if(TREE_DEBUGGING) printf("TREE: Expr node integer type created\n");;}
    break;

  case 79:
#line 287 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: variable -> expr\n");                   if(TREE_BUILDING) if(Check_ArrayDimension((yyvsp[(1) - (1)].node))) (yyval.node) = (yyvsp[(1) - (1)].node);                    if(TREE_DEBUGGING) printf("TREE: Expr node variable type created\n");;}
    break;

  case 80:
#line 288 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: expr STRING -> expr\n");                if(TREE_BUILDING) (yyval.node) = create_ExprNode(STR, 0, (yyvsp[(1) - (1)].string), NULL, NULL, 0);         if(TREE_DEBUGGING) printf("TREE: Expr node string type created\n");;}
    break;

  case 81:
#line 289 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: expr character -> expr\n");             if(TREE_BUILDING) (yyval.node) = create_ExprNode(C, 0, &(yyvsp[(1) - (1)].charValue), NULL, NULL, 0);          if(TREE_DEBUGGING) printf("TREE: Expr node char type created\n");;}
    break;

  case 82:
#line 290 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: expr function_call -> expr\n");         if(TREE_BUILDING) (yyval.node) = (yyvsp[(1) - (1)].node);                                                 if(TREE_DEBUGGING) printf("TREE: Expr node function call type created\n");;}
    break;

  case 83:
#line 291 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: expr PLUS expr -> expr\n");             if(TREE_BUILDING) (yyval.node) = (yyvsp[(1) - (1)].node);                                                 if(TREE_DEBUGGING) printf("TREE: Expr node operation type created\n");;}
    break;

  case 84:
#line 292 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: pre increment_decrement -> expr\n");    if(TREE_BUILDING) (yyval.node) = (yyvsp[(1) - (1)].node);                                                 if(TREE_DEBUGGING) printf("TREE: Expr node pre-increment/decrement type created\n");;}
    break;

  case 85:
#line 293 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: post increment_decrement -> expr\n");   if(TREE_BUILDING) (yyval.node) = (yyvsp[(1) - (1)].node);                                                 if(TREE_DEBUGGING) printf("TREE: Expr node post-increment/decrement type created\n");;}
    break;

  case 86:
#line 294 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: parentheses assignment -> expr\n");     if(TREE_BUILDING) (yyval.node) = create_ExprNode(PA, 0, NULL, (yyvsp[(2) - (3)].node), NULL, 0);          if(TREE_DEBUGGING) printf("TREE: Expr node parentheses assignment type created\n");;}
    break;

  case 87:
#line 298 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: pre increment ++ found\n");             if(TREE_BUILDING) (yyval.node) = create_IncDecNode(PI, (yyvsp[(2) - (2)].node));                          if(TREE_DEBUGGING) printf("TREE: Expr node post increment type created\n");;}
    break;

  case 88:
#line 299 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: pre decrement -- found\n");             if(TREE_BUILDING) (yyval.node) = create_IncDecNode(PD, (yyvsp[(2) - (2)].node));                          if(TREE_DEBUGGING) printf("TREE: Expr node post decrement type created\n");;}
    break;

  case 89:
#line 303 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: post increment ++ found\n");            if(TREE_BUILDING) (yyval.node) = create_IncDecNode(IP, (yyvsp[(1) - (2)].node));                          if(TREE_DEBUGGING) printf("TREE: Expr node post increment type created\n");;}
    break;

  case 90:
#line 304 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: post decrement -- found\n");            if(TREE_BUILDING) (yyval.node) = create_IncDecNode(DP, (yyvsp[(1) - (2)].node));                          if(TREE_DEBUGGING) printf("TREE: Expr node post decrement type created\n");;}
    break;

  case 91:
#line 308 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: expr PLUS expr -> operation\n");        if(TREE_BUILDING) (yyval.node) = create_OperationNode(MainNode, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), SUM);        if(TREE_DEBUGGING) printf("TREE: Expr node plus type created\n");;}
    break;

  case 92:
#line 309 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: expr MINUS expr -> operation\n");       if(TREE_BUILDING) (yyval.node) = create_OperationNode(MainNode, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), DIF);        if(TREE_DEBUGGING) printf("TREE: Expr node difference type created\n");;}
    break;

  case 93:
#line 310 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: expr STAR expr -> operation\n");        if(TREE_BUILDING) (yyval.node) = create_OperationNode(MainNode, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), TIM);        if(TREE_DEBUGGING) printf("TREE: Expr node times type created\n");;}
    break;

  case 94:
#line 311 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: expr DIVIDE expr -> operation\n");      if(TREE_BUILDING) (yyval.node) = create_OperationNode(MainNode, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), DIV);        if(TREE_DEBUGGING) printf("TREE: Expr node divide type created\n");;}
    break;

  case 95:
#line 312 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: expr MODULO expr -> operation\n");      if(TREE_BUILDING) (yyval.node) = create_OperationNode(MainNode, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), MOD);        if(TREE_DEBUGGING) printf("TREE: Expr node modulo type created\n");;}
    break;

  case 96:
#line 313 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: ( expr ) -> operation\n");              if(TREE_BUILDING) (yyval.node) = create_OperationNode(MainNode, (yyvsp[(2) - (3)].node), (yyvsp[(2) - (3)].node), RND);        if(TREE_DEBUGGING) printf("TREE: Expr node round brackets type created\n");;}
    break;

  case 97:
#line 317 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: AND -> comparison\n");                  if(TREE_BUILDING) (yyval.node) = create_ComparisonNode(MainNode, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), AND_);      if(TREE_DEBUGGING) printf("TREE: Expr node and type created\n");;}
    break;

  case 98:
#line 318 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: OR -> comparison\n");                   if(TREE_BUILDING) (yyval.node) = create_ComparisonNode(MainNode, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), OR_);       if(TREE_DEBUGGING) printf("TREE: Expr node or type created\n");;}
    break;

  case 99:
#line 319 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: GT -> comparison\n");                   if(TREE_BUILDING) (yyval.node) = create_ComparisonNode(MainNode, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), GREAT_);    if(TREE_DEBUGGING) printf("TREE: Expr node greater than type created\n");;}
    break;

  case 100:
#line 320 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: LT -> comparison\n");                   if(TREE_BUILDING) (yyval.node) = create_ComparisonNode(MainNode, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), LESS_);     if(TREE_DEBUGGING) printf("TREE: Expr node less then type created\n");;}
    break;

  case 101:
#line 321 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: ET -> comparison\n");                   if(TREE_BUILDING) (yyval.node) = create_ComparisonNode(MainNode, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), EQUAL_);    if(TREE_DEBUGGING) printf("TREE: Expr node equal to type created\n");;}
    break;

  case 102:
#line 322 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: DF -> comparison\n");                   if(TREE_BUILDING) (yyval.node) = create_ComparisonNode(MainNode, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), DIFF_);     if(TREE_DEBUGGING) printf("TREE: Expr node different from type created\n");;}
    break;

  case 103:
#line 326 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: INT -> type\n");                        if(TREE_BUILDING) (yyval.intValue) = INT_ ;}
    break;

  case 104:
#line 327 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: CHAR -> type\n");                       if(TREE_BUILDING) (yyval.intValue) = CHAR_;}
    break;

  case 105:
#line 331 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: identifier -> variable\n");             if(TREE_BUILDING) (yyval.node) = create_ExprNode(ID, 0, (yyvsp[(1) - (1)].string), NULL, NULL, 0);          if(TREE_DEBUGGING) printf("TREE: Variable node identifier type created\n");;}
    break;

  case 106:
#line 332 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: array -> variable\n");                  if(TREE_BUILDING) (yyval.node) = create_ExprNode(VEC, 0, (yyvsp[(1) - (4)].string), (yyvsp[(3) - (4)].node), NULL, 0);           if(TREE_DEBUGGING) printf("TREE: Variable node vector type created\n");;}
    break;

  case 107:
#line 333 "parser.y"
    {if(P_DEBUGGING==1) printf("BISON: array [] -> variable\n");               if(TREE_BUILDING) (yyval.node) = create_ExprNode(VEC, 0, (yyvsp[(1) - (3)].string), NULL, NULL, 0);         if(TREE_DEBUGGING) printf("TREE: Variable node vector type created\n");;}
    break;


/* Line 1267 of yacc.c.  */
#line 2135 "parser.tab.c"
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


#line 336 "parser.y"


/* EPILOGO */



  int yyerror (const char *error) {
    printf ("%s unexpected expression.\n", ErrorMsg());
    exit(EXIT_FAILURE);
    return 0;
  }


////////////////////  arguments_declaration_list PRODUCTION  ///////////////////
struct TreeNode * create_Arg_ListNode(struct TreeNode *arg_list, struct TreeNode *arg){

  if (arg_list == NULL){
    struct TreeNode * newTreeNode = TreeNodeInitialization (); // generic Tree Node memory space allocation

    // Linking specific node to generic Tree Node
    newTreeNode -> nodeType = ArgLst;

    if (arg != NULL){       // first element of the list
      TreeNodeList_Add(newTreeNode -> child_list, arg);
      return newTreeNode;
    }
    else{
      return newTreeNode;  // in case of functions without arguments
    }
  }
  else{
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

struct TreeNode * create_Function_CallNode(ProgramNode * prog, char * function_id, struct TreeNode * expr_list){

  if (expr_list -> nodeType == ExprLst){

    struct TreeNode * node = create_ExprNode(FC, 0, function_id, expr_list, NULL, 0);
    Check_FunctionCallConcistency(prog, node);
    return node;

  }
  else{
    printf("%s create_Function_CallNode - unexpected Tree Node type. Expected ExprLst, found %s.\n", ErrorMsg(), NodeTypeString(expr_list));
    exit(EXIT_FAILURE);
  }
}

////////////////////  comparison PRODUCTION  ///////////////////////////////////

struct TreeNode * create_ComparisonNode(ProgramNode * prog, struct TreeNode * first, struct TreeNode * second, enum cmpType cmptype){

  if (first == NULL || second == NULL) {
      printf("%s create_ComparisonNode - comparison missing one or two expressions\n", ErrorMsg());
      exit(EXIT_FAILURE);
    }
    else{

      struct TreeNode * node = create_ExprNode(CMP, 0, NULL, first, second, cmptype);
      Check_ComparisonConcistency(prog, node);

      return node;
    }
}

////////////////////  main function PRODUCTION  ////////////////////////////////

void create_MainFunction(ProgramNode * prog, struct TreeNode * arguments){

  // arguments must be a ArgLst TreeNode
  if (arguments -> nodeType != ArgLst){
    printf("line %d: %serror:%s mainFunction - incorrect call. ArgLst TreeNode expected\n",yylineno,ANSI_COLOR_RED,ANSI_COLOR_RESET);
    exit(EXIT_FAILURE);
  }
  else{
    // main function must not have arguments. argc and argv arguments are not supported.
    if(arguments -> child_list -> elements != 0){
        printf("%s this interpreter does not support main function arguments.\n",ErrorMsg());
        exit(EXIT_FAILURE);
    }
    else{

      struct TreeNode * identifier = create_ExprNode(ID, 0, "main", NULL, NULL, 0);
      FunNodeList_Add (prog, create_DeclarationNode(INT_, identifier));
      // main scope is always an active scope
      Scope_Activation();
    }
  }
}


////////////////////  function node PRODUCTION  ////////////////////////////////

struct TreeNode * create_FunctionNode(struct TreeNode * declaration, struct TreeNode * parameters){

  // check parameters
  Check_NodeType(DclN, declaration, "create_functionNode");
  Check_NodeType(ArgD, parameters, "create_functionNode");

      //FunNodeList_Add (MainNode, $1);
      //Add_Node_Tree(MainNode, $2);
  return parameters;
}


////////////////////  if PRODUCTION  ///////////////////////////////////////////

struct TreeNode * create_IfElseNode(struct TreeNode * if_node, struct TreeNode * else_node){

  if (if_node -> nodeType == If){

    // creating a generic Tree Node with memory allocation
    struct TreeNode * newIfElseNode = TreeNodeInitialization();
    // Tree Node Type
    newIfElseNode -> nodeType = IfElse;

    TreeNodeList_Add(newIfElseNode -> child_list, if_node);

    printf("IF NODE HA %d FIGLI.\n", if_node -> child_list -> elements);
    // exec if statement
     if(Check_activation()) {exec_if(if_node);}

    // if there's an else condition
    if (else_node != NULL){
      if (else_node -> nodeType == Else){
        TreeNodeList_Add(newIfElseNode -> child_list, else_node);
      }
      else{
        printf("%s create_IfElseNode - unexpected Tree Node type. Expected Else, found %s.\n", ErrorMsg(), NodeTypeString(else_node));
        exit(EXIT_FAILURE);
      }
    }

    return newIfElseNode;
  }
  else{
    printf("%s create_IfElseNode - unexpected Tree Node type. Expected If, found %s.\n", ErrorMsg(), NodeTypeString(if_node));
    exit(EXIT_FAILURE);
  }



  return if_node;
}

struct TreeNode * create_ElseNode (struct TreeNode * else_node){

  if (else_node -> nodeType == Else){
    // else scope is ended
    ScopeStack_Pop(MainNode -> actual_stack);

    return else_node;
  }
  else{
    printf("%s create_ElseNode - unexpected Tree Node type. Expected Else, found %s.\n", ErrorMsg(), NodeTypeString(else_node));
    exit(EXIT_FAILURE);
  }

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
  SetAs_ActualScope(MainNode, ElseScope, 0);

  return newElseNode;
}

struct TreeNode * create_IfNode (struct TreeNode * if_node, struct TreeNode * condition){

  if (if_node -> nodeType == If){
    if (condition -> nodeType == Expr){

      // linking condition to the if node
      TreeNodeList_Add(if_node -> child_list, condition);
      // if scope is ended
      ScopeStack_Pop(MainNode -> actual_stack);

      return if_node;
    }
    else{
      printf("%s create_IfNode - unexpected Tree Node type. Expected Expr, found %s.\n", ErrorMsg(), NodeTypeString(condition));
      exit(EXIT_FAILURE);
    }
  }
  else{
    printf("%s create_IfNode - unexpected Tree Node type. Expected If, found %s.\n", ErrorMsg(), NodeTypeString(if_node));
    exit(EXIT_FAILURE);
  }
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
  SetAs_ActualScope(MainNode, ifScope, 0);
  // by default if condition is not satisfied
  newIfNode -> node.flag = 0;

  return newIfNode;
}

////////////////////  while PRODUCTION  ////////////////////////////////////////

struct TreeNode * create_WhileNode(struct TreeNode * while_node, struct TreeNode * condition){

  if (while_node -> nodeType == While){
    if (condition -> nodeType == Expr){

      TreeNodeList_Add(while_node -> child_list, condition);
      ScopeStack_Pop(MainNode -> actual_stack);

      return while_node;
    }
    else{
      printf("%s create_WhileNode - unexpected Tree Node type. Expected Expr, found %s.\n", ErrorMsg(), NodeTypeString(condition));
      exit(EXIT_FAILURE);
    }
  }
  else{
    printf("%s create_WhileNode - unexpected Tree Node type. Expected While, found %s.\n", ErrorMsg(), NodeTypeString(while_node));
    exit(EXIT_FAILURE);
  }
}

struct TreeNode * create_Condition(struct TreeNode * expr){

  struct TreeNode * condition;

  if ( expr -> nodeType == Expr){

    if (expr -> node.Expr -> exprType == STR){
      printf("%s this interpreter does not support pointer to integer conversion.\n", ErrorMsg());
      exit(EXIT_FAILURE);
    }
    if(IsCostant(expr)){
      char value = CMP_node_logicValue(MainNode, expr);
      if (value == 1){
        printf("%s condition is always true.\n", WarnMsg());
      }
      else if(value == 0){
        printf("%s condition is always false.\n", WarnMsg());
      }
    }

    condition = expr;
  }
  else if (expr -> nodeType == Asgn){

    // transforming assignment in a parathesis assignment node
    struct TreeNode * newExpr = create_ExprNode(PA, 0, NULL, expr, NULL, 0);
    condition = create_Condition(newExpr);
    // print warning
    printf("%s using the result of an assignment as a condition without parentheses\n", WarnMsg());
    printf("note: use '==' to turn this assignment into an equality comparison\n");
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
  SetAs_ActualScope(MainNode, whileScope, 0);

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
    exec_DclN(MainNode, declaration);

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
        exec_DclN(MainNode, declaration -> child_list  -> last);
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
        exec_DclN(MainNode, declaration);
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
          var_dimension = Expr_toInt(MainNode, declaration -> node.DclN -> arrayDim);
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
          exec_DclN(MainNode, declaration);

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
    printf("%s create_Declaration_AssignmentNode - incorrect call. Declaration TreeNode type expected. Type found: %u.\n", ErrorMsg(), declaration -> nodeType);
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
    Check_AsgnConcistency(prog, leftOp, rightOp);
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
    Check_AsgnConcistency(prog, leftOp_node, rightOp);

    // Storing right operator
    TreeNodeList_Add(leftOp -> child_list, rightOp);

    return leftOp;
  }
  // incorrect call
  else{
    printf("line:%d %serror%s - create_AssignmentNode: incorrect call\n",yylineno,ANSI_COLOR_RED,ANSI_COLOR_RESET);
    exit(EXIT_FAILURE);
  }

  exit(EXIT_FAILURE);
}

////////////////////  declaration PRODUCTION  //////////////////////////////////
/*
*   flag parameter: 1 for declaration, 0 for declaration and assignment
*/
struct TreeNode * create_DeclarationNode(enum Type type, struct TreeNode * var){

  if (var -> nodeType == Expr){

    // generic Tree Node memory space allocation
    struct TreeNode * newTreeNode = TreeNodeInitialization ();
    // setting node type
    newTreeNode -> nodeType = DclN;
    // checking if the declaration is consistent
    Check_DeclConcistency(var);
    // memory space allocation for specific Declaration node
    struct DeclarationNode * NewNodeType;
    NewNodeType = (struct DeclarationNode *)malloc(sizeof(struct DeclarationNode));
    // variable identifier
    NewNodeType -> identifier = TreeNode_Identifier(var);
    // setting var type and array dimension
    if (var -> node.Expr -> exprType == ID){
      // variable type
      NewNodeType -> type = type;
      // array dimension
      NewNodeType -> arrayDim = NULL;
    }
    else if (var -> node.Expr -> exprType == VEC){
      if(type == INT_){
        // variable type
        NewNodeType -> type = INT_V_;
        // array dimension
        NewNodeType -> arrayDim = var -> child_list -> first;
      }
      else if(type == CHAR_){
        // variable type
        NewNodeType -> type = CHAR_V_;
        // array dimension
        NewNodeType -> arrayDim = var -> child_list -> first;
      }
      else{
        printf("%s create_DeclarationNode - unexpected variable type.\n", ErrorMsg());
        exit(EXIT_FAILURE);
      }
    }

    // linking declaration struct to tree node
    newTreeNode -> node.DclN = NewNodeType;
    // freeing memory
    free(var -> node.Expr);
    free(var);

    return newTreeNode;


/*
    // generic Tree Node memory space allocation
    struct TreeNode * newTreeNode = TreeNodeInitialization ();
    // memory space allocation for specific Declaration node
    struct DeclarationNode * NewNodeType;
    NewNodeType = (struct DeclarationNode *)malloc(sizeof(struct DeclarationNode));

    // declaration node type is the declarated variable type
    NewNodeType -> type = type;

    // declaration node identifier is the declarated variable identifier
    strcpy(NewNodeType -> identifier, var -> node.Expr -> exprVal.stringExpr);

    // checks if the Tree Node is an array or an identifier (exprType = ID if IDENTIFIER, = VEC if ARRAY)
    if (var -> node.Expr -> exprType == VEC) {

      // check array lenght if costant, must be > 0
      if (IsCostant(var -> child_list -> first)){
        int lenght = Expr_toInt(MainNode, var -> child_list -> first);
        if (lenght < 1){
          printf("%s '%s' declared as an array with 0 or negative size\n", ErrorMsg(), NewNodeType -> identifier);
          exit(EXIT_FAILURE);
        }
      }

      NewNodeType -> arrayDim = var -> child_list -> first;
    }
    // otherwise the array dimension is null
    else NewNodeType -> arrayDim = NULL;

    // Tree Node Type
    newTreeNode -> nodeType = DclN;
    // Declaration Node inside the TreeNode
    newTreeNode -> node.DclN = NewNodeType;

    return newTreeNode;

    */

  }
  else{
    printf("%s create_DeclarationNode - incorrect call. Expr Tree Node expected. Type found: %u\n", ErrorMsg(), var -> nodeType);
    exit(EXIT_FAILURE);
  }
}

////////////////////  return PRODUCTION  ///////////////////////////////////////

struct TreeNode * create_ReturnNode(struct TreeNode *expr){

  struct TreeNode * newTreeNode = TreeNodeInitialization (); // generic Tree Node memory space allocation

  // Linking specific node to generic Tree Node
  newTreeNode -> nodeType = Return;

  if(expr != NULL){
    TreeNodeList_Add(newTreeNode -> child_list, expr);}

  return newTreeNode;
}

////////////////////  pre_incdec_statement PRODUCTION  //////////////////////////

struct TreeNode * create_IncDecNode(enum exprType type, struct TreeNode * var){
  if (var -> nodeType == Expr){
    if (isAssignable(var)){
      return create_ExprNode(type, 0, NULL, var, NULL, 0);
    }
    else{
      printf("%s expression is not assignable.\n", ErrorMsg());
      exit(EXIT_FAILURE);
    }
  }
  else{
    printf("%s create_IncDecNode - incorrect call. Expr TreeNode expected.\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }
}

////////////////////  operation PRODUCTION  ////////////////////////////////////

struct TreeNode * create_OperationNode(ProgramNode * prog, struct TreeNode * first, struct TreeNode * second, enum exprType type){

  if (first == NULL || second == NULL) {
      printf("%s create_OperationNode - comparison missing one or two expressions\n", ErrorMsg());
      exit(EXIT_FAILURE);
    }
  else{
    struct TreeNode * node = create_ExprNode(type, 0, NULL, first, second, 0);
    Check_OperationConcistency(prog, node);

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
      case NUM: NewExprNode -> exprVal.intExpr = (int)intExpr;
                break;
      case ID:  NewExprNode -> exprVal.stringExpr = (char *)malloc (sizeof(char) *strlen(charExpr)); // memory space allocation for storing string value.
                strcpy(NewExprNode -> exprVal.stringExpr, charExpr);
                break;
      case VEC: NewExprNode -> exprVal.stringExpr = (char *)malloc (sizeof(char) *strlen(charExpr)); // memory space allocation for storing string value.
                // copying variable identifier in the node
                strcpy(NewExprNode -> exprVal.stringExpr, charExpr);
                // check if vec as a dimension
                if(first != NULL){
                  // check if array dimension index is not a string
                  if (first -> node.Expr -> exprType != STR ){
                    // adding the array dimension index as tree node child
                    TreeNodeList_Add(newTreeNode -> child_list, first);
                  }
                  // display error message if the dimension index is a string
                  else{
                    printf("%s array index must not be a string.\n", ErrorMsg());
                    exit(EXIT_FAILURE);
                  }
                }
                break;
      case STR: NewExprNode -> exprVal.stringExpr = (char *)malloc (sizeof(char) *strlen(charExpr)-2); // sottraggo due alla dimensione per rimuovere gli apici
                for (int i =1; i<strlen(charExpr)-1; i++){
                NewExprNode -> exprVal.stringExpr[i-1]=charExpr[i];
                }
                break;
      case C:   NewExprNode -> exprVal.charExpr = *charExpr;
                break;
      case FC:  NewExprNode -> exprVal.stringExpr = (char *)malloc (sizeof(char) *strlen(charExpr)); // memory space allocation for storing string value.
                strcpy(NewExprNode -> exprVal.stringExpr, charExpr); // function identifier
                if (first != NULL){ // function parameters
                  TreeNodeList_Add(newTreeNode -> child_list, first);
                }
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
      case PA:  TreeNodeList_Add(newTreeNode -> child_list, first);
                break;
      }

    // Linking specific node to generic Tree Node
    newTreeNode -> nodeType = Expr;
    newTreeNode -> node.Expr = NewExprNode;

    return newTreeNode;
  }



struct TreeNode * TreeNodeInitialization (){

    struct TreeNode * newTreeNode;
    newTreeNode = (struct TreeNode *)malloc(sizeof(struct TreeNode)); // memory space allocation for generic tree node
    newTreeNode -> child_list = TreeNodeList_Set();  // memory space allocation for tree node child list
    newTreeNode -> next = NULL;
    return newTreeNode;
  }

/* todo rimuovere sta schifezza
////////////////////  global scope declaration PRODUCTION  /////////////////////

void create_GlobalDeclarationNode(ProgramNode * prog, struct TreeNode * declaration){

  if (declaration -> nodeType == DclN){

    // check array lenght declaration, must not be an identifier
    if (declaration -> node.DclN -> arrayDim != NULL){
      if (declaration -> node.DclN -> arrayDim -> nodeType == Expr){
        if (!IsCostant(declaration -> node.DclN -> arrayDim)){
          printf("%s variable lenght array not allowed in at global scope.\n", ErrorMsg());
          exit(EXIT_FAILURE);
        }
      }
      else{
        printf("%s create_GlobalDeclarationNode - array lenght Expr node expected. Type found %u.\n", ErrorMsg(), declaration -> node.DclN -> arrayDim -> nodeType);
        exit(EXIT_FAILURE);
      }
    }

    // adding node to the AST
    Add_Node_Tree(prog, declaration);
  }
  else{
    printf("%s create_GlobalDeclarationNode - incorrect call. DclN node expected. Type found %u.\n", ErrorMsg(), declaration -> nodeType);
    exit(EXIT_FAILURE);
  }
}*/

//////////////////  concistency FUNCTIONS  /////////////////////////////////////

void Check_CharConcistency(int value){
  if (value < -128 || value > 127){
    printf("%s implicit conversion from 'int' to 'char' changes value from %d to %d\n", WarnMsg(), value, (char)value);
  }
}

void Check_ExprConcistency(ProgramNode * prog, struct TreeNode * expr_node){

  enum exprType type = expr_node -> node.Expr -> exprType;
  // an Expr Tree Node is expected
  if ( expr_node -> nodeType == Expr){
    // todo da rivedere
    switch (type) {
      case NUM: break;
      case ID:  Check_IdentifierConcistency (prog, expr_node); break;
      case VEC: Check_ArrayConcistency (prog, expr_node); break;
      case STR: break;
      case C:   break;
      case FC:  Check_FunctionCallConcistency (prog, expr_node); break;
      case SUM: break;
      case DIF: break;
      case TIM: break;
      case DIV: break;
      case MOD: break;
      case RND: break;
      case CMP: Check_ComparisonConcistency (prog, expr_node); break;
      case PI:  break;
      case PD:  break;
      case IP:  break;
      case DP:  break;
      case PA:  break;
    }
  }
  // Error: unexpected TreeNode type
  else{
    printf("%s Check_ExprConcistency - incorrect call. Expr TreeNode expected.\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }

}

void Check_IdentifierConcistency(ProgramNode * prog, struct TreeNode * identifier_node){

  if (identifier_node -> nodeType == Expr){
    if (identifier_node -> node.Expr -> exprType == ID){

      char * identifier = identifier_node -> node.Expr -> exprVal.stringExpr;
      // check declaration
      if (!Check_VarWasDeclared(prog, identifier, 1)){

        printf("line %d: %serror:%s use of undeclared identifier \'%s\'.\n",yylineno,ANSI_COLOR_RED,ANSI_COLOR_RESET, identifier);
        exit(EXIT_FAILURE);
      }
    }
    else{
      printf("%s Check_ArrayConcistency - incorrect call. ID Expr TreeNode expected.\n",ErrorMsg());
      exit(EXIT_FAILURE);
    }
  }
  else{
    printf("%s Check_ArrayConcistency - incorrect call. Expr TreeNode expected.\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }
}

void Check_ArrayConcistency(ProgramNode * prog, struct TreeNode * array){

  if (array -> nodeType == Expr){
    if (array -> node.Expr -> exprType == VEC){

      char * array_id = array -> node.Expr -> exprVal.stringExpr;
      // check declaration
      if (!Check_VarWasDeclared(prog, array_id, 1)){

        printf("line %d: %serror:%s use of undeclared identifier \'%s\'.\n",yylineno,ANSI_COLOR_RED,ANSI_COLOR_RESET, array_id);
        exit(EXIT_FAILURE);
      }
      else{
        // check array index
        int index = Retrieve_ArrayIndex(prog, array);
        int array_dim = Retrieve_ArrayDim(prog, array_id);

        // out of bounds array error
        if (index > array_dim - 1){
          printf("line %d: %serror:%s array index %d is past the end of the array. Array contains %d elements.\n",yylineno,ANSI_COLOR_RED,ANSI_COLOR_RESET,index, array_dim);
          exit(EXIT_FAILURE);
        }
        else if (index < 0){
          printf("line %d: %serror:%s array index %d is before the beginning of the array. Array contains %d elements.\n",yylineno,ANSI_COLOR_RED,ANSI_COLOR_RESET,index, array_dim);
          exit(EXIT_FAILURE);
        }
      }
    }
    else{
      printf("line %d: %serror:%s Check_ArrayConcistency - incorrect call. VEC Expr TreeNode expected.\n",yylineno,ANSI_COLOR_RED,ANSI_COLOR_RESET);
      exit(EXIT_FAILURE);
    }
  }
  else{
    printf("line %d: %serror:%s Check_ArrayConcistency - incorrect call. Expr TreeNode expected.\n",yylineno,ANSI_COLOR_RED,ANSI_COLOR_RESET);
    exit(EXIT_FAILURE);
  }
}

void Check_FunctionCallConcistency (ProgramNode * prog, struct TreeNode * function_call){

  if(function_call -> nodeType == Expr){
    if(function_call -> node.Expr -> exprType == FC){

      char * function_id = function_call -> node.Expr -> exprVal.stringExpr;

      // check if function was declared
      if(CheckFunAlreadyExist(prog, function_id)){

        if (function_call -> child_list -> elements > 0){

          struct TreeNode * arguments = function_call -> child_list -> first;
          struct TreeNode * argument = arguments -> child_list -> first;
          // check arguments
          for (int i = 0; i < arguments -> child_list -> elements; i++){

            if (i!=0) argument = argument -> next;
            // pensaci un attimo: se è stato creato il nodo expr, non è di per se già controllato in fase di creazione?
            Check_ExprConcistency(prog, argument);
          }
        }

      }
      else{
        printf("%s call of undeclared function \'%s\'\n", ErrorMsg(), function_id);
        exit(EXIT_FAILURE);
      }

    }
    else{
      printf("line %d: %serror:%s Check_FunctionCallConcistency - incorrect call. FC Expr TreeNode expected.\n",yylineno,ANSI_COLOR_RED,ANSI_COLOR_RESET);
      exit(EXIT_FAILURE);
    }
  }
  else{
    printf("line %d: %serror:%s Check_FunctionCallConcistency - incorrect call. Expr TreeNode expected.\n",yylineno,ANSI_COLOR_RED,ANSI_COLOR_RESET);
    exit(EXIT_FAILURE);
  }

}

void Check_OperationConcistency (ProgramNode * prog, struct TreeNode * operation_node){

  if (operation_node -> nodeType == Expr){
    if(isOperation(operation_node)){

      struct TreeNode * leftOp = operation_node -> child_list -> first;
      struct TreeNode * rightOp;
      if (operation_node -> node.Expr -> exprType != RND) rightOp = operation_node -> child_list -> first -> next;

      enum exprType leftOp_type = leftOp -> node.Expr -> exprType;
      enum exprType rightOp_type;
      if (operation_node -> node.Expr -> exprType != RND) rightOp_type = rightOp -> node.Expr -> exprType;

      // Raise an error if one operand is an undeclared identifier
      if (leftOp_type == ID || leftOp_type == VEC){

        char * left_identifier = TreeNode_Identifier(leftOp);
        if (!Check_VarWasDeclared(prog, left_identifier, 1)){

          printf("%s use of undeclared identifier \'%s\'.\n",ErrorMsg(),left_identifier);
          exit(EXIT_FAILURE);
        }
      }
      if (rightOp_type == ID || rightOp_type == VEC){

        char * right_identifier = TreeNode_Identifier(rightOp);
        if (!Check_VarWasDeclared(prog, right_identifier, 1)){

          printf("%s use of undeclared identifier \'%s\'.\n",ErrorMsg(),right_identifier);
          exit(EXIT_FAILURE);
        }
      }

      // Raise a warning if one or two operands are array identifiers
      if (leftOp_type == ID){
        char * identifier = TreeNode_Identifier(leftOp);
        enum Type varType = Retrieve_VarType(prog, identifier);
        if (varType == INT_V_ || varType == CHAR_V_){

          printf("%s this interpreter does not support pointer to integer conversion.\n", ErrorMsg());
          exit(EXIT_FAILURE);
        }
      }
      if (rightOp_type == ID){
        char * identifier = TreeNode_Identifier(rightOp);
        enum Type varType = Retrieve_VarType(prog, identifier);
        if (varType == INT_V_ || varType == CHAR_V_){

          printf("%s this interpreter does not support pointer to integer conversion.\n", ErrorMsg());
          exit(EXIT_FAILURE);
        }
      }

      // Raise an error if one or two operands are strings
      if (leftOp_type == STR || rightOp_type == STR){
        printf("%s this interpreter does not support pointer to integer conversion.\n", ErrorMsg());
        exit(EXIT_FAILURE);
      }

      // Raise a warning if there's a division by 0
      if(operation_node -> node.Expr -> exprType == DIV){
        // If the second operand is costant
        if(IsCostant(operation_node -> child_list -> first -> next)){
          // If the second operand value is 0
          if(Expr_toInt(prog, operation_node -> child_list -> first -> next) == 0){
            printf("%s division by zero is undefined.\n", WarnMsg());
          }
        }
      }
      // Node value pre-calculus if it is not a division by 0
      else if(IsCostant(operation_node)){

          int value = Expr_toInt(prog, operation_node);
          operation_node -> node.Expr -> exprVal.intExpr = value;
          operation_node -> node.Expr -> known = 1;
      }
    }
    else{
      printf("%s Check_OperationConcistency - incorrect call. SUM/DIF/TIM/DIV/MOD/RND Expr TreeNode expected.\n", ErrorMsg());
      exit(EXIT_FAILURE);
    }
  }
  else{
    printf("%s Check_OperationConcistency - incorrect call. Expr TreeNode expected.\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }
}

void Check_ComparisonConcistency (ProgramNode * prog, struct TreeNode * comparison_node){

  if (comparison_node -> nodeType == Expr){
    if(comparison_node -> node.Expr -> exprType == CMP){

      enum cmpType type = comparison_node -> node.Expr -> exprVal.cmpExpr;
      // comparison is a binary logic operation with two operands: leftOp and rightOp
      struct TreeNode * leftOp = comparison_node -> child_list -> first;
      struct TreeNode * rightOp = comparison_node -> child_list -> first -> next;

      // comparison is a binary logic operation with two operands: leftOp and rightOp
      enum exprType leftOp_type = leftOp -> node.Expr -> exprType;
      enum exprType rightOp_type = rightOp -> node.Expr -> exprType;


      // Raise an error if one or two operands are strings
      if (leftOp_type == STR || rightOp_type == STR){
        printf("%s this interpreter does not support pointer to integer conversion.\n", ErrorMsg());
        exit(EXIT_FAILURE);
      }

      // Raise an error if one operand is an undeclared identifier
      if (leftOp_type == ID || leftOp_type == VEC){

        char * left_identifier = TreeNode_Identifier(leftOp);
        if (!Check_VarWasDeclared(prog, left_identifier, 1)){

          printf("%s use of undeclared identifier \'%s\'.\n",ErrorMsg(),left_identifier);
          exit(EXIT_FAILURE);
        }
      }
      if (rightOp_type == ID || rightOp_type == VEC){

        char * right_identifier = TreeNode_Identifier(rightOp);

        if (!Check_VarWasDeclared(prog, right_identifier, 1)){

          printf("%s use of undeclared identifier \'%s\'.\n",ErrorMsg(),right_identifier);
          exit(EXIT_FAILURE);
        }
      }

      // todo gestire ++ e --
      if (type == AND_ || type == OR_){

        // Raise a warning if the operand is a costant and is different from 0 or 1
        if (IsCostant(leftOp)){
          int value = Expr_toInt(prog, leftOp);
          if (value != 0 && value != 1){
            printf("%s logical operation with costant first operand.\n", WarnMsg());
          }

        }
        if (IsCostant(rightOp)){
          int value = Expr_toInt(prog, rightOp);
          if (value != 0 && value != 1){
            printf("%s logical operation with costant first operand.\n", WarnMsg());
          }

        }

        // Raise a warning if the operand is an array identifier
        if (leftOp_type == ID){
          char * identifier = TreeNode_Identifier(leftOp);
          enum Type varType = Retrieve_VarType(prog, identifier);
          if (varType == INT_V_ || varType == CHAR_V_){

          printf("%s array identifier will always evaluate to 'true'.\n", WarnMsg());
          }
        }
        if (rightOp_type == ID){
          char * identifier = TreeNode_Identifier(rightOp);
          enum Type varType = Retrieve_VarType(prog, identifier);
          if (varType == INT_V_ || varType == CHAR_V_){

          printf("%s array identifier will always evaluate to 'true'.\n", WarnMsg());
          }
        }

        // Raise a warning if the operand is a string
        if (leftOp_type == STR || rightOp_type == STR){
          printf("%s string identifier will always evaluate to 'true'.\n", WarnMsg());
        }

      }
      else if(type == GREAT_ || type == LESS_ || type == EQUAL_ || type == DIFF_ ){

        // Print an error if the operand is a string
        if (leftOp_type == STR || rightOp_type == STR){

          printf("%s this interpreter does not support comparison against pointers.\n", ErrorMsg());
          exit(EXIT_FAILURE);
        }

        // Print an error if the operand is an array identifier
        if (leftOp_type == ID){
          char * identifier = TreeNode_Identifier(leftOp);
          enum Type varType = Retrieve_VarType(prog, identifier);
          if (varType == INT_V_ || varType == CHAR_V_){

          printf("%s this interpreter does not support comparison against pointers.\n", ErrorMsg());
          exit(EXIT_FAILURE);
          }
        }
        if (rightOp_type == ID){
          char * identifier = TreeNode_Identifier(rightOp);
          enum Type varType = Retrieve_VarType(prog, identifier);
          if (varType == INT_V_ || varType == CHAR_V_){

          printf("%s this interpreter does not support comparison against pointers.\n", ErrorMsg());
          exit(EXIT_FAILURE);
          }
        }

        // Print a warning if the comparison with a char is always true or always false
        if (IsCostant(leftOp)){
          if (rightOp_type == ID || rightOp_type == VEC){
            char * identifier = TreeNode_Identifier(rightOp);
            enum Type varType = Retrieve_VarType(prog, identifier);

            if (varType == CHAR_ || varType == CHAR_V_){
              if (type == GREAT_){
                if (Expr_toInt(prog, leftOp) > 127){
                  printf("%s result of comparison of constant %d with expression of type char is always true.\n", WarnMsg(), Expr_toInt(prog, leftOp));
                }
                else if (Expr_toInt(prog, leftOp) < -128){
                  printf("%s result of comparison of constant %d with expression of type char is always false.\n", WarnMsg(), Expr_toInt(prog, leftOp));
                }
              }
              if (type == LESS_){
                if (Expr_toInt(prog, leftOp) > 127){
                  printf("%s result of comparison of constant %d with expression of type char is always false.\n", WarnMsg(), Expr_toInt(prog, leftOp));
                }
                else if (Expr_toInt(prog, leftOp) < -128){
                  printf("%s result of comparison of constant %d with expression of type char is always true.\n", WarnMsg(), Expr_toInt(prog, leftOp));
                }
              }
              if (type == EQUAL_){
                if (Expr_toInt(prog, leftOp) > 127){
                  printf("%s result of comparison of constant %d with expression of type char is always false.\n", WarnMsg(), Expr_toInt(prog, leftOp));
                }
                else if (Expr_toInt(prog, leftOp) < -128){
                  printf("%s result of comparison of constant %d with expression of type char is always false.\n", WarnMsg(), Expr_toInt(prog, leftOp));
                }
              }
              if (type == DIFF_){
                if (Expr_toInt(prog, leftOp) > 127){
                  printf("%s result of comparison of constant %d with expression of type char is always true.\n", WarnMsg(), Expr_toInt(prog, leftOp));
                }
                else if (Expr_toInt(prog, leftOp) < -128){
                  printf("%s result of comparison of constant %d with expression of type char is always true.\n", WarnMsg(), Expr_toInt(prog, leftOp));
                }
              }
            }
          }
        }
        if (IsCostant(rightOp)){
          if (leftOp_type == ID || leftOp_type == VEC){
            char * identifier = TreeNode_Identifier(leftOp);
            enum Type varType = Retrieve_VarType(prog, identifier);

            if (varType == CHAR_ || varType == CHAR_V_){
              if (type == GREAT_){
                if (Expr_toInt(prog, rightOp) > 127){
                  printf("%s result of comparison of constant %d with expression of type char is always false.\n", WarnMsg(), Expr_toInt(prog, rightOp));
                }
                else if (Expr_toInt(prog, rightOp) < -128){
                  printf("%s result of comparison of constant %d with expression of type char is always true.\n", WarnMsg(), Expr_toInt(prog, rightOp));
                }
              }
              if (type == LESS_){
                if (Expr_toInt(prog, rightOp) > 127){
                  printf("%s result of comparison of constant %d with expression of type char is always true.\n", WarnMsg(), rightOp -> node.Expr -> exprVal.intExpr);
                }
                else if (Expr_toInt(prog, rightOp) < -128){
                  printf("%s result of comparison of constant %d with expression of type char is always false.\n", WarnMsg(), rightOp -> node.Expr -> exprVal.intExpr);
                }
              }
              if (type == EQUAL_){
                if (Expr_toInt(prog, rightOp) > 127){
                  printf("%s result of comparison of constant %d with expression of type char is always false.\n", WarnMsg(), Expr_toInt(prog, rightOp));
                }
                else if (Expr_toInt(prog, rightOp) < -128){
                  printf("%s result of comparison of constant %d with expression of type char is always false.\n", WarnMsg(), Expr_toInt(prog, rightOp));
                }
              }
              if (type == DIFF_){
                if (Expr_toInt(prog, rightOp) > 127){
                  printf("%s result of comparison of constant %d with expression of type char is always true.\n", WarnMsg(), rightOp -> node.Expr -> exprVal.intExpr);
                }
                else if (Expr_toInt(prog, rightOp) < -128){
                  printf("%s result of comparison of constant %d with expression of type char is always true.\n", WarnMsg(), rightOp -> node.Expr -> exprVal.intExpr);
                }
              }
            }
          }
        }

        // Print a warning if the comparison with an other comparison is always true or always false
        if (leftOp_type == CMP && IsCostant(rightOp)){
          if (type == GREAT_){
            if (Expr_toInt(prog, rightOp) < 0){
                printf("%s result of comparison of constant %d with boolean expression is always true.\n", WarnMsg(), Expr_toInt(prog, rightOp));
            }
            if (Expr_toInt(prog, rightOp) > 0){
                printf("%s result of comparison of constant %d with boolean expression is always false.\n", WarnMsg(), Expr_toInt(prog, rightOp));
            }
          }
          if (type == LESS_){
            if (Expr_toInt(prog, rightOp) > 1){
                printf("%s result of comparison of constant %d with boolean expression is always true.\n", WarnMsg(), Expr_toInt(prog, rightOp));
            }
            if (Expr_toInt(prog, rightOp) < 1){
                printf("%s result of comparison of constant %d with boolean expression is always false.\n", WarnMsg(), Expr_toInt(prog, rightOp));
            }
          }
          if (type == EQUAL_){
            if (Expr_toInt(prog, rightOp) != 0 &&  Expr_toInt(prog, rightOp) != 1){
                  printf("%s result of comparison of constant %d with boolean expression is always false.\n", WarnMsg(), Expr_toInt(prog, rightOp));
              }
          }
          if (type == DIFF_){
            if (Expr_toInt(prog, rightOp) != 0 &&  rightOp -> node.Expr -> exprVal.intExpr != 1){
                printf("%s result of comparison of constant %d with boolean expression is always true.\n", WarnMsg(), Expr_toInt(prog, rightOp));
            }
          }
        }
        if (IsCostant(leftOp) && rightOp_type == CMP){
          if (type == GREAT_){
            if (Expr_toInt(prog, leftOp) > 1){
                printf("%s result of comparison of constant %d with boolean expression is always true.\n", WarnMsg(), Expr_toInt(prog, leftOp));
            }
            if (Expr_toInt(prog, leftOp) < 1){
                printf("%s result of comparison of constant %d with boolean expression is always false.\n", WarnMsg(), Expr_toInt(prog, leftOp));
            }
          }
          if (type == LESS_){
            if (Expr_toInt(prog, leftOp) < 0){
                printf("%s result of comparison of constant %d with boolean expression is always true.\n", WarnMsg(), Expr_toInt(prog, leftOp));
            }
            if (Expr_toInt(prog, leftOp) > 0){
                printf("%s result of comparison of constant %d with boolean expression is always false.\n", WarnMsg(), Expr_toInt(prog, leftOp));
            }
          }
          if (type == EQUAL_){
            if (Expr_toInt(prog, leftOp) != 0 &&  Expr_toInt(prog, leftOp) != 1){
                  printf("%s result of comparison of constant %d with boolean expression is always false.\n", WarnMsg(), Expr_toInt(prog, leftOp));
              }
          }
          if (type == DIFF_){
            if (Expr_toInt(prog, leftOp) != 0 &&  Expr_toInt(prog, leftOp) != 1){
                printf("%s result of comparison of constant %d with boolean expression is always true.\n", WarnMsg(), Expr_toInt(prog, leftOp));
            }
          }
        }

        // Print a warning if the comparison is between a variable and itself
        if (((leftOp_type == ID) && (rightOp_type == ID)) || ((leftOp_type == VEC) && (rightOp_type == VEC))){

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

      }
    }
    else{
      printf("%s Check_ComparisonConcistency - incorrect call. CMP Expr TreeNode expected.\n", ErrorMsg());
      exit(EXIT_FAILURE);
    }
  }
  else{
    printf("%s Check_ComparisonConcistency - incorrect call. Expr TreeNode expected.\n", ErrorMsg());
    exit(EXIT_FAILURE);
  }
}

void Check_AsgnConcistency(ProgramNode * prog, struct TreeNode * leftOp, struct TreeNode * rightOp){

  enum exprType leftOp_type = leftOp -> node.Expr -> exprType;
  enum exprType rightOp_type = rightOp -> node.Expr -> exprType;

  // Only valid variables and vectors elements are assignable
  if (isAssignable(leftOp)){

    char * leftOp_identifier = TreeNode_Identifier(leftOp);

    // todo se la chiamata di isAssignable funziona bene è da togliere dato che fanno la stessa cosa
    /*

    enum Type leftOp_varType = Retrieve_VarType(prog, leftOp_identifier);

    if (leftOp_type == ID){

      // check if left operator is not a vector identifier
      if (leftOp_varType == INT_V_ || leftOp_varType == CHAR_V_){

        int array_dim = Retrieve_ArrayDim(prog, leftOp_identifier);
        if (leftOp_varType == INT_V_) printf("line %d: %serror:%s array type \'int[%d]\' is not assignable\n",yylineno,ANSI_COLOR_RED,ANSI_COLOR_RESET,array_dim);
        if (leftOp_varType == CHAR_V_) printf("line %d: %serror:%s array type \'char[%d]\' is not assignable\n",yylineno,ANSI_COLOR_RED,ANSI_COLOR_RESET,array_dim);
        exit(EXIT_FAILURE);
      }
    }
    else if (leftOp_type == VEC){

      int index = Retrieve_ArrayIndex(prog, leftOp);
      int array_dim = Retrieve_ArrayDim(prog, leftOp_identifier);

      // out of bounds array error
      if (index > array_dim-1){
        printf("line %d: %serror:%s array index %d is past the end of the array. Array contains %d elements.\n",yylineno,ANSI_COLOR_RED,ANSI_COLOR_RESET,index, array_dim);
        exit(EXIT_FAILURE);
      }
      else if (index < 0){
        printf("line %d: %serror:%s array index %d is before the beginning of the array. Array contains %d elements.\n",yylineno,ANSI_COLOR_RED,ANSI_COLOR_RESET,index, array_dim);
        exit(EXIT_FAILURE);
      }
    }
    */
    if (rightOp_type == STR){
      printf("%s a string is not assignable\n", ErrorMsg());
      exit(EXIT_FAILURE);
    }
    else if (rightOp_type == ID){

      char * rightOp_identifier = rightOp -> node.Expr -> exprVal.stringExpr;
      enum Type rightOp_varType = Retrieve_VarType(prog, rightOp_identifier);

      // check if rigth operator is not a vector identifier
      if (rightOp_varType == INT_V_ || rightOp_varType == CHAR_V_){
        int array_dim = Retrieve_ArrayDim(prog, rightOp_identifier);
        if (rightOp_varType == INT_V_) printf("%s array type \'int[%d]\' is not assignable\n", ErrorMsg(), array_dim);
        if (rightOp_varType == CHAR_V_) printf("%s array type \'char[%d]\' is not assignable\n", ErrorMsg(), array_dim);
        exit(EXIT_FAILURE);
      }
    }
    else if (rightOp_type == VEC){

    char * rightOp_identifier = rightOp -> node.Expr -> exprVal.stringExpr;
    int index = Retrieve_ArrayIndex(prog, rightOp);
    int array_dim = Retrieve_ArrayDim(prog, rightOp_identifier);

    // out of bounds array error
    if (index > array_dim-1){
      printf("%s array index %d is past the end of the array. Array contains %d elements.\n", ErrorMsg(), index, array_dim);
      exit(EXIT_FAILURE);
    }
    else if (index < 0){
      printf("%s array index %d is before the beginning of the array. Array contains %d elements.\n", ErrorMsg(), index, array_dim);
      exit(EXIT_FAILURE);
    }
  }

    // Char assignment concistency
    if (IsCostant(rightOp)){

      enum Type varType = Retrieve_VarType(prog, leftOp_identifier);
      if (varType == CHAR_ || varType == CHAR_V_){

        int value = Expr_toInt(MainNode, rightOp);
        Check_CharConcistency(value);
      }
    }

    // todo: gestire il caso in cui il valore deriva dal contenuto di una espressione per esempio con parentesi
    // dovrebbe essere già gestito perchè con le stringhe non si possono fare operazioni, ma è da verificare

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

    if (variable -> nodeType == Expr){

      if (variable -> node.Expr -> exprType == ID || variable -> node.Expr -> exprType == VEC){

        char * identifier = TreeNode_Identifier(variable);
        // check if variable was previously declared
        if(Check_VarWasDeclared(MainNode, identifier, 0)){
          printf("%s redefinition of %s.\n", ErrorMsg(), identifier);
          exit(EXIT_FAILURE);
        }

        /* todo rimuovere
        if(variable -> node.Expr -> exprType == VEC){

          // array without dimension
          if(variable -> child_list -> elements == 0 && flag){
            printf("%s definition of variable %s with array type needs an explicit size or an initializer.\n", ErrorMsg(), identifier);
            exit(EXIT_FAILURE);
          }

        }
        */
      }
      else{
        printf("%s Check_DeclConcistency - unexpected Expr type. Type found: %u.\n", ErrorMsg(), variable -> node.Expr -> exprType);
        exit(EXIT_FAILURE);
      }
    }
    else{
      printf("%s Check_DeclConcistency - incorrect call. Expr Tree Node expected. Type found %u.\n", ErrorMsg(), variable -> nodeType == Expr);
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
    else{
      return 1;
    }
  }
  else if (node -> nodeType == DclN){
    // array with no dimension specified
    if (node -> node.DclN -> arrayDim == NULL && (node -> node.DclN -> type == INT_V_ || node -> node.DclN -> type == CHAR_V_)){
      printf("%s definition of '%s' variable with array type needs an explicit size or an initializer\n", ErrorMsg(), TreeNode_Identifier(node));
      exit(EXIT_FAILURE);
    }
    else{
      return 1;
    }
  }
  else{
    printf("%s Check_ArrayDimension - incorrect call. Expr or DclN node expected. Type found %u.\n", ErrorMsg(), node -> nodeType == Expr);
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

//////////////////  execution CONTROL  /////////////////////////////////////////

int Check_Main(){

  struct FunNode * actualFunction =  MainNode -> function_list -> last;
  if (!strcmp("main", actualFunction -> funName)){
    return 1;
  }
  else{
    return 0;
  }
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

