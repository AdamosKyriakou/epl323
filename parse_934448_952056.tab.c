/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 12 "parse_934448_952056.y"

 /* C declarations used in action */
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include "stack.h"
// #include "queue.h"
 extern char* yytext; /* using flex */
 extern int yylineno;
 #define YYDEBUG_LEXER_TEXT yytext
 
 char* errorStr = "", *parameters, *funName = NULL;
 STACK *s=NULL;
 int isCompound = 0, isNum = 0, isFloat = 0, isLeft=0; //Used to find blocks inside functions
 int isArray=0;
 int flag=1;
 int argsList[10], argsCounter = 0;
 QUEUENODE *f = NULL, *g=NULL;
 QUEUENODE **t;

 void myError (char *errorStr);
 void pushQueue();
 void pushQueue1();
 QUEUENODE * insertInQueue(char* ret, char* two, int isFunction, int isArray);

/* Line 371 of yacc.c  */
#line 94 "parse_934448_952056.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parse_934448_952056.tab.h".  */
#ifndef YY_YY_PARSE_934448_952056_TAB_H_INCLUDED
# define YY_YY_PARSE_934448_952056_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUM = 258,
     FLOAT_NUM = 259,
     ELSE = 260,
     IF = 261,
     INT = 262,
     VOID = 263,
     RETURN = 264,
     WHILE = 265,
     GTOE = 266,
     LTOE = 267,
     EQUAL = 268,
     NEQUAL = 269,
     PP = 270,
     PE = 271,
     MM = 272,
     ME = 273,
     ID = 274,
     NO_ELSE = 275,
     FOR = 276,
     FLOAT = 277
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 37 "parse_934448_952056.y"

	int a_number;
	char* str;
	float f_number;


/* Line 387 of yacc.c  */
#line 166 "parse_934448_952056.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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

#endif /* !YY_YY_PARSE_934448_952056_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 194 "parse_934448_952056.tab.c"

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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   264

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNRULES -- Number of states.  */
#define YYNSTATES  197

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   277

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      26,    27,    36,    35,    28,    32,     2,    37,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    23,
      33,    31,    34,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    24,     2,    25,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    29,     2,    30,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    18,    25,
      32,    36,    40,    42,    44,    46,    47,    55,    62,    70,
      77,    79,    81,    82,    86,    88,    92,    96,   100,   103,
     108,   113,   117,   120,   125,   130,   131,   134,   135,   138,
     140,   141,   144,   145,   148,   149,   152,   154,   157,   159,
     162,   168,   169,   178,   184,   192,   193,   200,   206,   207,
     218,   228,   238,   248,   252,   255,   259,   262,   266,   271,
     276,   278,   280,   285,   289,   291,   293,   295,   297,   299,
     301,   303,   307,   309,   312,   314,   316,   318,   321,   323,
     326,   330,   332,   334,   336,   340,   342,   344,   346,   348,
     353,   358,   360,   361,   365
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      39,     0,    -1,    40,    -1,    40,    41,    -1,    41,    -1,
      42,    -1,    44,    -1,    43,    19,    23,    -1,    43,    19,
      24,     3,    25,    23,    -1,     1,    19,    24,     3,    25,
      23,    -1,     1,    19,    23,    -1,    43,     1,    23,    -1,
       7,    -1,     8,    -1,    22,    -1,    -1,    43,    19,    26,
      45,    46,    27,    49,    -1,     1,    19,    26,    46,    27,
      49,    -1,     1,    43,    19,    26,    46,    27,    49,    -1,
      43,     1,    26,    46,    27,    49,    -1,    47,    -1,     8,
      -1,    -1,    47,    28,    48,    -1,    48,    -1,     1,    28,
       1,    -1,     1,    28,    48,    -1,    47,    28,     1,    -1,
      43,    19,    -1,    43,    19,    24,    25,    -1,     1,    19,
      24,    25,    -1,     1,    43,    19,    -1,    43,     1,    -1,
      29,    50,    51,    30,    -1,    29,    50,     1,    30,    -1,
      -1,    50,    42,    -1,    -1,    51,    52,    -1,    56,    -1,
      -1,    53,    49,    -1,    -1,    54,    57,    -1,    -1,    55,
      59,    -1,    62,    -1,    63,    23,    -1,    23,    -1,    63,
       1,    -1,     6,    26,    63,    27,    52,    -1,    -1,     6,
      26,    63,    27,    52,     5,    58,    52,    -1,     6,    26,
       1,    27,    52,    -1,     6,    26,     1,    27,    52,     5,
      52,    -1,    -1,    10,    26,    63,    27,    60,    52,    -1,
      10,    26,     1,    27,    52,    -1,    -1,    21,    26,    63,
      23,    63,    23,    63,    27,    61,    52,    -1,    21,    26,
       1,    23,    63,    23,    63,    27,    52,    -1,    21,    26,
      63,    23,     1,    23,    63,    27,    52,    -1,    21,    26,
      63,    23,    63,    23,     1,    27,    52,    -1,    21,    26,
      27,    -1,     9,    23,    -1,     9,    63,    23,    -1,     9,
       1,    -1,    64,    31,    63,    -1,    64,    31,    32,    63,
      -1,    64,    31,     1,    63,    -1,    65,    -1,    19,    -1,
      19,    24,    63,    25,    -1,    67,    66,    67,    -1,    67,
      -1,    11,    -1,    12,    -1,    13,    -1,    14,    -1,    33,
      -1,    34,    -1,    67,    68,    70,    -1,    70,    -1,    70,
      69,    -1,    35,    -1,    32,    -1,    15,    -1,    16,    70,
      -1,    17,    -1,    18,    70,    -1,    70,    71,    72,    -1,
      72,    -1,    36,    -1,    37,    -1,    26,    63,    27,    -1,
      64,    -1,    73,    -1,     3,    -1,     4,    -1,    19,    26,
      74,    27,    -1,    19,    26,     1,    27,    -1,    75,    -1,
      -1,    75,    28,    63,    -1,    63,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    53,    53,    55,    56,    58,    59,    61,    74,    88,
      89,    90,    92,    96,   100,   105,   105,   127,   128,   129,
     132,   189,   203,   205,   206,   207,   208,   209,   211,   216,
     223,   224,   225,   227,   228,   230,   231,   233,   234,   236,
     237,   237,   243,   243,   244,   244,   245,   247,   248,   249,
     251,   254,   254,   257,   258,   260,   260,   263,   264,   264,
     265,   266,   267,   268,   270,   271,   272,   274,   290,   306,
     307,   309,   329,   361,   370,   379,   380,   381,   382,   383,
     384,   386,   442,   445,   451,   452,   454,   455,   460,   461,
     467,   532,   536,   537,   539,   543,   571,   572,   579,   588,
     620,   622,   623,   625,   626
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "FLOAT_NUM", "ELSE", "IF", "INT",
  "VOID", "RETURN", "WHILE", "GTOE", "LTOE", "EQUAL", "NEQUAL", "PP", "PE",
  "MM", "ME", "ID", "NO_ELSE", "FOR", "FLOAT", "';'", "'['", "']'", "'('",
  "')'", "','", "'{'", "'}'", "'='", "'-'", "'<'", "'>'", "'+'", "'*'",
  "'/'", "$accept", "program", "declaration_list", "declaration",
  "var_declaration", "type_specifier", "fun_declaration", "$@1", "params",
  "param_list", "param", "compound_stmt", "local_declarations",
  "statement_list", "statement", "$@2", "$@3", "$@4", "expression_stmt",
  "selection_stmt", "$@5", "iteration_stmt", "$@6", "$@7", "return_stmt",
  "expression", "var", "simple_expression", "relop", "additive_expression",
  "addop", "doubleAddSub", "term", "mulop", "factor", "call", "args",
  "arg_list", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,    59,    91,    93,    40,    41,    44,   123,
     125,    61,    45,    60,    62,    43,    42,    47
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    38,    39,    40,    40,    41,    41,    42,    42,    42,
      42,    42,    43,    43,    43,    45,    44,    44,    44,    44,
      46,    46,    46,    47,    47,    47,    47,    47,    48,    48,
      48,    48,    48,    49,    49,    50,    50,    51,    51,    52,
      53,    52,    54,    52,    55,    52,    52,    56,    56,    56,
      57,    58,    57,    57,    57,    60,    59,    59,    61,    59,
      59,    59,    59,    59,    62,    62,    62,    63,    63,    63,
      63,    64,    64,    65,    65,    66,    66,    66,    66,    66,
      66,    67,    67,    67,    68,    68,    69,    69,    69,    69,
      70,    70,    71,    71,    72,    72,    72,    72,    72,    73,
      73,    74,    74,    75,    75
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     6,     6,
       3,     3,     1,     1,     1,     0,     7,     6,     7,     6,
       1,     1,     0,     3,     1,     3,     3,     3,     2,     4,
       4,     3,     2,     4,     4,     0,     2,     0,     2,     1,
       0,     2,     0,     2,     0,     2,     1,     2,     1,     2,
       5,     0,     8,     5,     7,     0,     6,     5,     0,    10,
       9,     9,     9,     3,     2,     3,     2,     3,     4,     4,
       1,     1,     4,     3,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     2,     1,     1,     1,     2,     1,     2,
       3,     1,     1,     1,     3,     1,     1,     1,     1,     4,
       4,     1,     0,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    12,    13,    14,     0,     0,     4,     5,     0,
       6,     0,     0,     1,     3,     0,     0,    10,     0,     0,
       0,    11,     0,     7,     0,    15,     0,     0,    13,     0,
       0,    20,    24,     0,     0,     0,     0,     0,     0,     0,
       0,    32,    28,     0,     0,     0,     0,     0,     0,     9,
       0,    25,    26,    31,     0,    35,    17,    27,    23,     0,
      19,     8,     0,    30,    29,     0,    18,    16,     0,    36,
       0,    44,     0,    34,     0,     0,    97,    98,     0,    71,
      48,     0,    33,    38,     0,     0,     0,    39,    46,     0,
      95,    70,    74,    82,    91,    96,    66,    64,     0,     0,
       0,     0,    41,     0,    43,     0,     0,    45,    49,    47,
       0,    75,    76,    77,    78,    85,    79,    80,    84,     0,
       0,    86,     0,    88,     0,    92,    93,    83,     0,    65,
       0,     0,   104,     0,   101,    94,     0,     0,     0,     0,
       0,    67,    95,    73,    81,    87,    89,    90,    72,   100,
      99,     0,     0,     0,     0,     0,     0,    63,     0,    69,
      68,   103,    44,    44,    44,    55,     0,     0,    53,    50,
      57,    44,     0,     0,     0,    44,    51,    56,     0,     0,
       0,    54,    44,     0,     0,     0,     0,    52,    44,    44,
      44,    58,    60,    61,    62,    44,    59
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,     8,    29,    10,    36,    30,    31,
      32,    56,    65,    71,    83,    84,    85,    86,    87,   104,
     182,   107,   171,   195,    88,    89,    90,    91,   119,    92,
     120,   127,    93,   128,    94,    95,   133,   134
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -145
static const yytype_int16 yypact[] =
{
     207,    72,  -145,  -145,  -145,    40,   185,  -145,  -145,     9,
    -145,   135,    24,  -145,  -145,    11,   139,  -145,    61,     8,
      51,  -145,     8,  -145,    80,  -145,    60,    59,    76,    10,
      78,    81,  -145,     8,   120,   110,     8,   118,   129,   209,
     149,  -145,   158,   162,   211,   169,   162,   153,   182,  -145,
     186,   176,  -145,  -145,   195,  -145,  -145,   176,  -145,   162,
    -145,  -145,   162,  -145,  -145,    89,  -145,  -145,    17,  -145,
      55,    46,   -19,  -145,   190,   114,  -145,  -145,   141,    44,
    -145,   171,  -145,  -145,   162,   215,    32,  -145,  -145,     1,
     191,  -145,   167,   188,  -145,  -145,  -145,  -145,   200,   171,
     103,   199,  -145,   208,  -145,   212,   213,  -145,  -145,  -145,
      22,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,   171,
     171,  -145,   171,  -145,   171,  -145,  -145,  -145,   171,  -145,
     210,   214,  -145,   216,   217,  -145,   113,   147,   130,   171,
     171,  -145,  -145,    93,   152,   152,   152,  -145,  -145,  -145,
    -145,   171,   219,   220,   221,   222,   227,  -145,   228,  -145,
    -145,  -145,   117,   117,   117,  -145,   171,   151,   232,   235,
    -145,   117,   229,   230,   231,   117,  -145,  -145,   171,   171,
     168,  -145,   117,   233,   234,   236,   237,  -145,   117,   117,
     117,  -145,  -145,  -145,  -145,   117,  -145
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -145,  -145,  -145,   238,   177,     6,  -145,  -145,    91,  -145,
     -31,   -45,  -145,  -145,  -144,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,  -145,   -78,   108,  -145,  -145,   136,
    -145,  -145,   -38,  -145,   128,  -145,  -145,  -145
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -103
static const yytype_int16 yytable[] =
{
      98,    60,   108,   101,    17,    18,     9,    12,    52,    27,
      15,    41,     9,    58,    66,     2,    28,    67,   168,   169,
     170,   130,   132,   139,   109,    76,    77,   177,    16,    42,
       4,   181,   141,    40,    21,   -22,    72,    22,   187,   102,
      13,    79,   105,    20,   192,   193,   194,    73,    81,    76,
      77,   196,   -42,   106,   140,    78,    74,    40,   153,   155,
     158,   159,   160,    40,    26,    79,     2,     3,    99,    80,
     100,    70,    81,   161,    75,   -40,    82,    33,    38,     2,
       3,     4,   144,    35,   145,    37,   146,    39,   172,   174,
      68,    11,   -37,   -37,     4,   -37,     2,     3,   -37,   -37,
     183,   184,   186,   -21,   131,    43,    76,    77,   -37,    44,
     -37,     4,   -37,    34,   152,   -37,    76,    77,   -37,   -37,
      76,    77,    79,   -42,    45,   115,    78,    48,   118,    81,
    -102,   156,    79,    76,    77,    47,    79,    23,    24,    81,
      80,    49,    96,    81,    76,    77,   -40,    46,   154,    79,
      76,    77,   173,    50,    76,    77,    81,   157,    17,    18,
      79,    19,    23,    24,    97,    25,    79,    81,    53,   185,
      79,    76,    77,    81,    76,    77,    61,    81,   111,   112,
     113,   114,    54,     2,     3,    -2,     1,    79,   125,   126,
      79,    55,     2,     3,    81,    38,    59,    81,     4,   115,
     116,   117,   118,   121,   122,   123,   124,     4,     1,    62,
      51,    63,    57,    21,     2,     3,     2,     3,     2,     3,
      64,   103,   110,   129,   125,   126,   135,   142,   142,     4,
     142,     4,   142,     4,   136,   148,   142,   175,   137,   138,
     176,   149,    69,   150,    14,   151,   162,   163,   164,   165,
     166,   167,   178,   179,   180,   143,   147,     0,     0,     0,
     188,   189,     0,   190,   191
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-145)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      78,    46,     1,    81,    23,    24,     0,     1,    39,     1,
       1,     1,     6,    44,    59,     7,     8,    62,   162,   163,
     164,    99,   100,     1,    23,     3,     4,   171,    19,    19,
      22,   175,   110,    27,    23,    27,    19,    26,   182,    84,
       0,    19,    10,    19,   188,   189,   190,    30,    26,     3,
       4,   195,     6,    21,    32,     9,     1,    51,   136,   137,
     138,   139,   140,    57,     3,    19,     7,     8,    24,    23,
      26,    65,    26,   151,    19,    29,    30,    26,    19,     7,
       8,    22,   120,     3,   122,    25,   124,    28,   166,   167,
       1,    19,     3,     4,    22,     6,     7,     8,     9,    10,
     178,   179,   180,    27,     1,    27,     3,     4,    19,    28,
      21,    22,    23,    22,     1,    26,     3,     4,    29,    30,
       3,     4,    19,     6,    33,    32,     9,    36,    35,    26,
      27,     1,    19,     3,     4,    25,    19,    23,    24,    26,
      23,    23,     1,    26,     3,     4,    29,    27,     1,    19,
       3,     4,     1,    24,     3,     4,    26,    27,    23,    24,
      19,    26,    23,    24,    23,    26,    19,    26,    19,     1,
      19,     3,     4,    26,     3,     4,    23,    26,    11,    12,
      13,    14,    24,     7,     8,     0,     1,    19,    36,    37,
      19,    29,     7,     8,    26,    19,    27,    26,    22,    32,
      33,    34,    35,    15,    16,    17,    18,    22,     1,    27,
       1,    25,     1,    23,     7,     8,     7,     8,     7,     8,
      25,     6,    31,    23,    36,    37,    27,   119,   120,    22,
     122,    22,   124,    22,    26,    25,   128,     5,    26,    26,
       5,    27,    65,    27,     6,    28,    27,    27,    27,    27,
      23,    23,    23,    23,    23,   119,   128,    -1,    -1,    -1,
      27,    27,    -1,    27,    27
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     7,     8,    22,    39,    40,    41,    42,    43,
      44,    19,    43,     0,    41,     1,    19,    23,    24,    26,
      19,    23,    26,    23,    24,    26,     3,     1,     8,    43,
      46,    47,    48,    26,    46,     3,    45,    25,    19,    28,
      43,     1,    19,    27,    28,    46,    27,    25,    46,    23,
      24,     1,    48,    19,    24,    29,    49,     1,    48,    27,
      49,    23,    27,    25,    25,    50,    49,    49,     1,    42,
      43,    51,    19,    30,     1,    19,     3,     4,     9,    19,
      23,    26,    30,    52,    53,    54,    55,    56,    62,    63,
      64,    65,    67,    70,    72,    73,     1,    23,    63,    24,
      26,    63,    49,     6,    57,    10,    21,    59,     1,    23,
      31,    11,    12,    13,    14,    32,    33,    34,    35,    66,
      68,    15,    16,    17,    18,    36,    37,    69,    71,    23,
      63,     1,    63,    74,    75,    27,    26,    26,    26,     1,
      32,    63,    64,    67,    70,    70,    70,    72,    25,    27,
      27,    28,     1,    63,     1,    63,     1,    27,    63,    63,
      63,    63,    27,    27,    27,    27,    23,    23,    52,    52,
      52,    60,    63,     1,    63,     5,     5,    52,    23,    23,
      23,    52,    58,    63,    63,     1,    63,    52,    27,    27,
      27,    27,    52,    52,    52,    61,    52
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
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




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 2:
/* Line 1792 of yacc.c  */
#line 53 "parse_934448_952056.y"
    {printf("Pop Final\n");pop(s); isCompound=0;}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 55 "parse_934448_952056.y"
    {/*printQueue(s->head->h);*/}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 56 "parse_934448_952056.y"
    {}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 58 "parse_934448_952056.y"
    {}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 59 "parse_934448_952056.y"
    {printf("Pop in Function \n");pop(s); isCompound=0;}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 61 "parse_934448_952056.y"
    {
										if (qLook(s->head->h,(yyvsp[(2) - (3)].str),0) == NULL)
											insertInQueue((yyval.str), (yyvsp[(2) - (3)].str), 0, 0);
										else{
											errorStr = (char*)malloc(strlen("Variable ")*sizeof(char));
											strcat(errorStr,"Variable ");
											strcat(errorStr,(yyvsp[(2) - (3)].str));
											strcat(errorStr," is already declared");
											myError(errorStr);
											errorStr=NULL;
										}
										
									}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 74 "parse_934448_952056.y"
    { 
										if (qLook(s->head->h,(yyvsp[(2) - (6)].str),1) == NULL)
											insertInQueue((yyval.str), (yyvsp[(2) - (6)].str), 0, (yyvsp[(4) - (6)].a_number));
										else{
											errorStr = (char*)malloc(strlen("Array ")*sizeof(char));
											strcat(errorStr,"Array ");
											strcat(errorStr,(yyvsp[(2) - (6)].str));
											strcat(errorStr," is already declared");
											myError(errorStr);
										}
										isNum=0;
										//TODO: create array to store the values
										//TODO: check for duplicate function opos to proigoumeno kodika
									}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 88 "parse_934448_952056.y"
    {yyerrok;}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 89 "parse_934448_952056.y"
    {yyerrok;}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 90 "parse_934448_952056.y"
    {yyerrok;}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 92 "parse_934448_952056.y"
    {
										(yyval.str) = (char*) malloc (strlen("int")*sizeof(char));
										strcpy((yyval.str), "int");
									}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 96 "parse_934448_952056.y"
    {
										(yyval.str) = (char*) malloc (strlen("void")*sizeof(char));
										strcpy((yyval.str), "void");
									}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 100 "parse_934448_952056.y"
    {
										(yyval.str) = (char*) malloc (strlen("float")*sizeof(char));
										strcpy((yyval.str), "float");
									}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 105 "parse_934448_952056.y"
    {
					funName = (char*)malloc(strlen((yyvsp[(2) - (3)].str)));
					strcpy(funName, (yyvsp[(2) - (3)].str));
					f=qLook(s->head->h,(yyvsp[(2) - (3)].str),2); 
					//printf("\nscope:%d\n",s->head->scope);
					/*flag = 1;	
					if ((f=qLook(s->head->h,$2,2)) != NULL){
						flag=1;
						switch (f->symbol->type){
							case 1: { flag=strcmp("int", $1); break;}
							case 2: { flag=strcmp("float", $1); break;}
							case 3: { flag=strcmp("void", $1); break;}						
						}
					} 
					printf("flag:%d",flag);*/
 					g=insertInQueue((yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), 1, 0); pushQueue(); printf("\nPush in Function\n");
					isCompound=1;
				//}
				       }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 123 "parse_934448_952056.y"
    {
										
								    }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 127 "parse_934448_952056.y"
    {yyerrok;}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 128 "parse_934448_952056.y"
    {yyerrok;}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 129 "parse_934448_952056.y"
    {yyerrok;}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 132 "parse_934448_952056.y"
    {
										(yyval.str)= (char*) malloc ((strlen((yyvsp[(1) - (1)].str)))*sizeof(char)); strcpy((yyval.str),(yyvsp[(1) - (1)].str)); printf("Params:%s\n",(yyval.str));
										char *temp = (char*) malloc (strlen((yyvsp[(1) - (1)].str))*sizeof(char)); strcpy(temp,(yyvsp[(1) - (1)].str));

										int insert = qLookAll(s->head->next->h,funName,2,temp);

										/*if (flag == 0){	
											int i=0;
											char *p = strtok(temp, ",");
											while (i<10 && f->symbol->paramTypes[i]!=0 && p!=NULL){
												if ((strstr(p, "int ") != NULL && f->symbol->paramTypes[i]!=1)||
												    (strstr(p, "float ") != NULL && f->symbol->paramTypes[i]!=2)||
												    (strstr(p, "void ") != NULL && f->symbol->paramTypes[i]!=3)){
													insert=1;
												}
												p = strtok(NULL, ",");
												i++;
											}
											
											if (insert==0 && f->symbol->paramTypes[i]==0 && p==NULL){
												errorStr = (char*)malloc(strlen("Function ")*sizeof(char));
												strcat(errorStr,"Function ");
												strcat(errorStr,f->symbol->name);
												strcat(errorStr," is already declared");
												myError(errorStr);
											} else{
												insert=0;
											}
											flag=2;
										}*/
		
										if (insert == 1){
											errorStr = (char*)malloc(strlen("Function ")*sizeof(char));
											strcat(errorStr,"Function ");
											strcat(errorStr,f->symbol->name);
											strcat(errorStr," is already declared");
											myError(errorStr);
										}

										strcpy(temp,(yyvsp[(1) - (1)].str));
										char *p = strtok(temp, ",");
										int i = 0;

										while (p!=NULL){
											if (strstr(p, "int ") != NULL) {g->symbol->paramTypes[i]=1;}
											else if (strstr(p, "float ") != NULL) {g->symbol->paramTypes[i]=2;}
											else if (strstr(p, "void ") != NULL) {g->symbol->paramTypes[i]=3;}
												
											p = strtok(NULL, ",");
											i++;
										}

										//int i = 0;
										/*for (i=0; i<10; i++)
											printf("G: %d\n",g->symbol->paramTypes[i]);*/

									}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 189 "parse_934448_952056.y"
    {
										if (flag==0 && (f->symbol->paramTypes[0])==0){
											errorStr = (char*)malloc(strlen("Function ")*sizeof(char));
											strcat(errorStr,"Function ");
											strcat(errorStr,f->symbol->name);
											strcat(errorStr," is already declared");
											myError(errorStr);
											flag=2;
										}
										else{
											(yyval.str) = (char*) malloc (strlen("void")*sizeof(char));
											strcpy((yyval.str), "void");
										}
									}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 203 "parse_934448_952056.y"
    {yyerror("No parameters given:");}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 205 "parse_934448_952056.y"
    {(yyval.str)= (char*) malloc ((strlen((yyvsp[(3) - (3)].str))+2+strlen((yyvsp[(1) - (3)].str)))*sizeof(char)); strcpy((yyval.str),(yyvsp[(1) - (3)].str));strcat((yyval.str),",");  strcat((yyval.str),(yyvsp[(3) - (3)].str)); }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 206 "parse_934448_952056.y"
    {(yyval.str)= (char*) malloc (strlen((yyvsp[(1) - (1)].str))*sizeof(char)); strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 207 "parse_934448_952056.y"
    {yyerrok;}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 208 "parse_934448_952056.y"
    {yyerrok;}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 209 "parse_934448_952056.y"
    {yyerrok;}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 211 "parse_934448_952056.y"
    {
										strcat((yyval.str)," ");
										strcat((yyval.str),(yyvsp[(2) - (2)].str));
										insertInQueue((yyvsp[(1) - (2)].str), (yyvsp[(2) - (2)].str), 0, 0); // Enqueue parameter
									}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 216 "parse_934448_952056.y"
    {
										strcat((yyval.str)," ");
										strcat((yyval.str),(yyvsp[(2) - (4)].str));
										strcat((yyval.str),"[]");
										//$$= (char*) malloc ((strlen($1)+strlen($2)+1)*sizeof(char)); strcpy($$,$1);strcat($$," ");strcat($$,$2);
										insertInQueue((yyvsp[(1) - (4)].str), (yyvsp[(2) - (4)].str), 0, 1); // Enqueue array parameter
									}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 223 "parse_934448_952056.y"
    {yyerrok;}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 224 "parse_934448_952056.y"
    {yyerrok;}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 225 "parse_934448_952056.y"
    {yyerrok;}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 227 "parse_934448_952056.y"
    {}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 228 "parse_934448_952056.y"
    {yyerrok;}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 230 "parse_934448_952056.y"
    {/*empty*/}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 231 "parse_934448_952056.y"
    {}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 233 "parse_934448_952056.y"
    {/*empty*/}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 234 "parse_934448_952056.y"
    {}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 236 "parse_934448_952056.y"
    {/*$$= (char*) malloc (strlen($1)*sizeof(char)); strcpy($$,$1);*/}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 237 "parse_934448_952056.y"
    { if (isCompound != 1){ pushQueue(); printf("Push in Compound\n"); isCompound=2;  }}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 237 "parse_934448_952056.y"
    {
														if (isCompound == 2){
															pop(s); printf("Pop in Compound\n"); 
															isCompound=2;
														} 
													}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 243 "parse_934448_952056.y"
    {pushQueue(); printf("Push in If/Else\n"); isCompound=1;}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 243 "parse_934448_952056.y"
    {pop(s); printf("Pop in If/Else\n");isCompound=0;}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 244 "parse_934448_952056.y"
    {pushQueue(); printf("Push in Iteration\n"); isCompound=1;}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 244 "parse_934448_952056.y"
    {pop(s); printf("Pop in Iteration\n");isCompound=0;}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 245 "parse_934448_952056.y"
    {}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 247 "parse_934448_952056.y"
    {/*$$= (char*) malloc (strlen($1)*sizeof(char)); strcpy($$,$1); strcat($$,";");*/}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 248 "parse_934448_952056.y"
    {/*$$= (char*) malloc (strlen(";")*sizeof(char)); strcpy($$,";");*/}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 249 "parse_934448_952056.y"
    {yyerrok;}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 251 "parse_934448_952056.y"
    {
												//pushQueue(); printf("Push in If\n");
									}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 254 "parse_934448_952056.y"
    {pop(s); printf("Pop in If\n"); pushQueue(); printf("Push in Else\n");}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 254 "parse_934448_952056.y"
    {
										//pushQueue(); printf("Push in If2\n");
									}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 257 "parse_934448_952056.y"
    {yyerrok;}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 258 "parse_934448_952056.y"
    {yyerrok;}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 260 "parse_934448_952056.y"
    {isCompound=1;}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 260 "parse_934448_952056.y"
    {	
										//pushQueue(); printf("Push in Iteration\n");
									}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 263 "parse_934448_952056.y"
    {yyerrok;}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 264 "parse_934448_952056.y"
    {isCompound=1;}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 264 "parse_934448_952056.y"
    {}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 265 "parse_934448_952056.y"
    {yyerrok;}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 266 "parse_934448_952056.y"
    {yyerrok;}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 267 "parse_934448_952056.y"
    {yyerrok;}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 268 "parse_934448_952056.y"
    {yyerrok;}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 270 "parse_934448_952056.y"
    {}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 271 "parse_934448_952056.y"
    {}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 272 "parse_934448_952056.y"
    {yyerrok;}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 274 "parse_934448_952056.y"
    { 
									  /*$$= (char*) malloc (strlen($1)*sizeof(char)); 
									  strcpy($$,$1);
									  strcat($$,"=");
									  strcat($$,$3);*/
									  QUEUENODE *temp = NULL;
									  if (isArray==0){
									  	searchStack(s,(yyvsp[(1) - (3)].str), &temp,0);
									  }
									  else{
										char *str = (char*)malloc(strlen((yyvsp[(1) - (3)].str))*sizeof(char));
										strcpy(str,(yyvsp[(1) - (3)].str));
									  	searchStack(s,strtok(str,"["), &temp,1);
										isArray=0;
									  }
									}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 290 "parse_934448_952056.y"
    {
									  /*$$= (char*) malloc (strlen($1)*sizeof(char)); 
									  strcpy($$,$1);
									  strcat($$,"=-");
									  strcat($$,$4);*/
									  QUEUENODE *temp = NULL;
									  searchStack(s,(yyvsp[(1) - (4)].str), &temp,0);
									  /*if (temp==NULL){
										errorStr = (char*)malloc(strlen("variable ")*sizeof(char));
										strcat(errorStr,"Variable ");
										strcat(errorStr,$1);
										strcat(errorStr," is not declared");
										myError(errorStr);
										errorStr=NULL;
									  }*/
									}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 306 "parse_934448_952056.y"
    {yyerrok;}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 307 "parse_934448_952056.y"
    {isNum = 0; isFloat=0;}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 309 "parse_934448_952056.y"
    {
										(yyval.str) = (char*) malloc (strlen((yyvsp[(1) - (1)].str))*sizeof(char));
										strcpy((yyval.str), (yyvsp[(1) - (1)].str));

										char *str = (char*)malloc(strlen((yyvsp[(1) - (1)].str)));
										strcpy(str,(yyvsp[(1) - (1)].str));
										QUEUENODE *temp = NULL;
									  	searchStack(s,str, &temp, 0);
										

										if (temp==NULL){
											errorStr = (char*)malloc(strlen("variable ")*sizeof(char));
											strcat(errorStr,"Variable ");
											strcat(errorStr,(yyval.str));
											strcat(errorStr," is not declared");
											myError(errorStr);
											errorStr=NULL;
									  	}

									}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 329 "parse_934448_952056.y"
    { 
										
										(yyval.str) = (char*) malloc (strlen((yyvsp[(1) - (4)].str))*sizeof(char));
										strcpy((yyval.str), (yyvsp[(1) - (4)].str));
										strcat((yyval.str),"[");
										/*if (isNum == 1){printf("IAM HERE %d\n",$3);										
											char *s = (char*)malloc(sizeof(char)*5);
											sprintf(s,"%d",$3);
											strcat($$,s);
											isNum=0;
										}
										else 
											strcat($$,$3);*/
										strcat((yyval.str),"]");
										char *str = (char*)malloc(strlen((yyvsp[(1) - (4)].str)));
										strcpy(str,(yyvsp[(1) - (4)].str));
										QUEUENODE *temp = NULL;
									  	searchStack(s,str, &temp, 1);
										
										isArray=1;

										if (temp==NULL){
											errorStr = (char*)malloc(strlen("array ")*sizeof(char));
											strcat(errorStr,"Array ");
											strcat(errorStr,(yyval.str));
											strcat(errorStr," is not declared");
											myError(errorStr);
											errorStr=NULL;
									  	}
											
									}
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 361 "parse_934448_952056.y"
    {
										astNodePtr exp = newExprNode(ADD_EXP,yylineno);
										exp->children[0]->type=(yyvsp[(1) - (3)].str); //malloc child
										exp->children[1]->type=(yyvsp[(3) - (3)].str);
										//print_node($$);
										printf("COMPARE: %d",strcmp((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)));
										printf("\n");
										//($1->value)=($$->value);	
									}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 370 "parse_934448_952056.y"
    {
										astNodePtr exp = newExprNode(ADD_EXP,yylineno);
										exp->children[0]->type=(yyvsp[(1) - (1)].str);
										//print_node($$);
										//printf("COMPARE: %d",strcmp($1,$3));
										printf("\n");
										//($1->value)=($$->value);
									}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 379 "parse_934448_952056.y"
    {/*$$ = (char*) malloc (strlen(">=")*sizeof(char)); strcpy($$, ">=");*/}
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 380 "parse_934448_952056.y"
    {/*$$ = (char*) malloc (strlen("<=")*sizeof(char)); strcpy($$, "<=");*/}
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 381 "parse_934448_952056.y"
    {/*$$ = (char*) malloc (strlen("==")*sizeof(char)); strcpy($$, "==");*/}
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 382 "parse_934448_952056.y"
    {/*$$ = (char*) malloc (strlen("!=")*sizeof(char)); strcpy($$, "!=");*/}
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 383 "parse_934448_952056.y"
    {/*$$ = (char*) malloc (strlen("<")*sizeof(char)); strcpy($$, "<");*/}
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 384 "parse_934448_952056.y"
    {/*$$ = (char*) malloc (strlen(">")*sizeof(char)); strcpy($$, ">");*/}
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 386 "parse_934448_952056.y"
    {
										printf("ADDITIVE:%s ADDOP:%s TERM:%s\n",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));
										printf("isNum=%d, isFloat=%d\n",isNum, isFloat);

										char* temp = (char*)malloc(strlen((yyvsp[(1) - (3)].str)));
										strcpy(temp,(yyvsp[(1) - (3)].str));

										f=NULL;
										searchStack(s, (yyvsp[(1) - (3)].str), &f, 0);
										if (f == NULL && strstr((yyvsp[(1) - (3)].str),"[") != NULL)
											searchStack(s, strtok(temp,"["), &f, 1);
										if (f == NULL)
											searchStack(s, (yyvsp[(1) - (3)].str), &f, 2);

										temp = (char*)malloc(strlen((yyvsp[(3) - (3)].str)));
										strcpy(temp,(yyvsp[(3) - (3)].str));

										g=NULL;
										searchStack(s, (yyvsp[(3) - (3)].str), &g, 0);
										if (g == NULL && strstr((yyvsp[(3) - (3)].str),"[") != NULL)
											searchStack(s, strtok(temp,"["), &g, 1);
										if (g == NULL)
											searchStack(s, (yyvsp[(3) - (3)].str), &g, 2);

										//printf("isNUM:%d\n",f->symbol->type,isNum);

										/*Check for type for var, array, function*/
										if (f!=NULL && g!= NULL && f->symbol->type != g->symbol->type){
											errorStr = (char*)malloc(strlen("Operation between different types ")*sizeof(char));
											strcat(errorStr,"Operation between different types ");
											myError(errorStr);
											errorStr=NULL;
										}

										/*Check for var, array, function and integer*/
										if ((f!=NULL && (f->symbol->type == 1) && (isNum != 1)) || (g!=NULL && (g->symbol->type == 1) && (isNum != 1))){
											errorStr = (char*)malloc(strlen("Operation between different types ")*sizeof(char));
											strcat(errorStr,"Operation between different types ");
											myError(errorStr);
											errorStr=NULL;
										}
										if ((f!=NULL && (f->symbol->type == 2) && (isFloat != 1)) || (g!=NULL && (g->symbol->type == 2) && (isFloat != 1))){
											errorStr = (char*)malloc(strlen("Operation between different types ")*sizeof(char));
											strcat(errorStr,"Operation between different types ");
											myError(errorStr);
											errorStr=NULL;
										}

										/*Check for var, array, function and integer*/

										/*astNode* exp = newExprNode(ADD_EXP,yylineno);
										exp->children[0]->type=$1;
										exp->children[1]->type=$3;
										printf("COMPARE: %d",strcmp($1,$3));
										printf("\n");*/
									}
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 442 "parse_934448_952056.y"
    {
										(yyval.str) = (char*) malloc (strlen((yyvsp[(1) - (1)].str))*sizeof(char)); strcpy((yyval.str), (yyvsp[(1) - (1)].str));
									}
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 445 "parse_934448_952056.y"
    {/*
										$$ = (char*) malloc (strlen($1)*sizeof(char));
										strcpy($$, $1);
										strcat($$, $2);
									*/}
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 451 "parse_934448_952056.y"
    {(yyval.str) = (char*) malloc (strlen("+")*sizeof(char)); strcpy((yyval.str), "+");}
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 452 "parse_934448_952056.y"
    {(yyval.str) = (char*) malloc (strlen("-")*sizeof(char)); strcpy((yyval.str), "-");}
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 454 "parse_934448_952056.y"
    {/*$$ = (char*) malloc (strlen("++")*sizeof(char)); strcpy($$, "++");*/}
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 455 "parse_934448_952056.y"
    {/*
										$$ = (char*) malloc (strlen("+=")*sizeof(char));
										strcpy($$, "+=");
										strcat($$, $2);
									*/}
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 460 "parse_934448_952056.y"
    {/*$$ = (char*) malloc (strlen("--")*sizeof(char)); strcpy($$, "--");*/}
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 461 "parse_934448_952056.y"
    {/*
										$$ = (char*) malloc (strlen("-=")*sizeof(char));
										strcpy($$, "-=");
										strcat($$, $2);
									*/}
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 467 "parse_934448_952056.y"
    {
										/*printf("TERM:%s MULOP:%s FACTOR:%s\n",$1,$2,$3);
										QUEUENODE *temp = NULL;
										int type=-1;
										if (strstr($1,"(")!=NULL){
									  		searchStack(s,$1, &temp, 2);
										}
										else if (strstr($1,"[")!=NULL){
									  		searchStack(s,$1, &temp, 1);
										}
										else{
									  		searchStack(s,$1, &temp, 0);
										}	
										if (temp!=NULL){
											type = temp->symbol->type;
										}*/

										printf("ADDITIVE:%s ADDOP:%s TERM:%s\n",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));
										printf("isNum=%d, isFloat=%d\n",isNum, isFloat);

										char* temp = (char*)malloc(strlen((yyvsp[(1) - (3)].str)));
										strcpy(temp,(yyvsp[(1) - (3)].str));

										f=NULL;
										searchStack(s, (yyvsp[(1) - (3)].str), &f, 0); 
										if (f == NULL && strstr(temp,"[") != NULL){
											searchStack(s, strtok(temp,"["), &f, 1);  printf("S: %p\n" ,f);}
										if (f == NULL)
											searchStack(s, (yyvsp[(1) - (3)].str), &f, 2);

										temp = (char*)malloc(strlen((yyvsp[(3) - (3)].str)));
										strcpy(temp,(yyvsp[(3) - (3)].str));

										g=NULL;
										searchStack(s, (yyvsp[(3) - (3)].str), &g, 0);
										if (g == NULL && strstr((yyvsp[(3) - (3)].str),"[") != NULL)
											searchStack(s, strtok(temp,"["), &g, 1);
										if (g == NULL)
											searchStack(s, (yyvsp[(3) - (3)].str), &g, 2);

										//printf("isNUM:%d\n",f->symbol->type,isNum);

										/*Check for type for var, array, function*/
										if (f!=NULL && g!= NULL && f->symbol->type != g->symbol->type){
											errorStr = (char*)malloc(strlen("Operation between different types ")*sizeof(char));
											strcat(errorStr,"Operation between different types ");
											myError(errorStr);
											errorStr=NULL;
										}

										printf("F: %p, type: %d, isNum=%d\n",f ,f->symbol->type, isNum);
										/*Check for var, array, function and integer*/
										if ((f!=NULL && (f->symbol->type == 1) && (isNum != 1)) || (g!=NULL && (g->symbol->type == 1) && (isNum != 1))){
											errorStr = (char*)malloc(strlen("Operation between different types ")*sizeof(char));
											strcat(errorStr,"Operation between different types ");
											myError(errorStr);
											errorStr=NULL;
										}
										if ((f!=NULL && (f->symbol->type == 2) && (isFloat != 1)) || (g!=NULL && (g->symbol->type == 2) && (isFloat != 1))){
											errorStr = (char*)malloc(strlen("Operation between different types ")*sizeof(char));
											strcat(errorStr,"Operation between different types ");
											myError(errorStr);
											errorStr=NULL;
										}
									}
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 532 "parse_934448_952056.y"
    {
										(yyval.str)=(yyvsp[(1) - (1)].str);	
									}
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 536 "parse_934448_952056.y"
    {(yyval.str) = (char*) malloc (strlen("*")*sizeof(char)); strcpy((yyval.str), "*");}
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 537 "parse_934448_952056.y"
    {(yyval.str) = (char*) malloc (strlen("/")*sizeof(char)); strcpy((yyval.str), "/");}
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 539 "parse_934448_952056.y"
    {
									  /*$$=(char*)malloc(strlen($2)*sizeof(char));
									  strcpy($$,$2);*/
									}
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 543 "parse_934448_952056.y"
    { 
										isNum = 0;
										(yyval.str)=(yyvsp[(1) - (1)].str);
										//printQueue(s->head->h);
										//printf("VAR: %s\n",$1);
										/*f=NULL;
										char *str = (char*)malloc(strlen($1));
										strcpy(str,$1);
										searchStack(s,strtok(str,"["),&f,0);
										searchStack(s,str,&g,1); 
										if (g==NULL){
											errorStr = (char*)malloc(strlen("Array ")*sizeof(char));
											strcat(errorStr,"Array ");
											strcat(errorStr,$1);
											strcat(errorStr," is not declared");
											myError(errorStr);
											errorStr=NULL;	
										}
										if (f==NULL){
											errorStr = (char*)malloc(strlen("Variable5 ")*sizeof(char));
											strcat(errorStr,"Variable5 ");
											strcat(errorStr,$1);
											strcat(errorStr," is not declared");
											myError(errorStr);
											errorStr=NULL;	
										}*/

									}
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 571 "parse_934448_952056.y"
    { (yyval.str)=(yyvsp[(1) - (1)].str); }
    break;

  case 97:
/* Line 1792 of yacc.c  */
#line 572 "parse_934448_952056.y"
    {
										isNum = 1;// printf("IS NUM\n");
										char *s = (char*)malloc(sizeof(char)*5);
										sprintf(s,"%d",(yyvsp[(1) - (1)].a_number));
										(yyval.str)=(char*)malloc(strlen(s)*sizeof(char)); 
										strcpy((yyval.str),s);
									}
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 579 "parse_934448_952056.y"
    {
										isFloat = 1; printf("HERE\n");
										char *s = (char*)malloc(sizeof(char)*10);
										sprintf(s,"%5.2f",(yyvsp[(1) - (1)].f_number));
										(yyval.str)=(char*)malloc(strlen(s)*sizeof(char)); 
printf("S: %s\n",s);
										strcpy((yyval.str),s);
									}
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 588 "parse_934448_952056.y"
    { //TODO: find the parameters in the stack and add their values(void**), *****function or array as argument in function****
										f=NULL;
										searchStack(s,(yyvsp[(1) - (4)].str),&f,2);
										
										if (f == NULL){
											errorStr = (char*)malloc(strlen("Function ")*sizeof(char));
											strcat(errorStr,"Function ");
											strcat(errorStr,(yyvsp[(1) - (4)].str));
											strcat(errorStr," is not declared");
											myError(errorStr);
											errorStr=NULL;
										}
										else {

											char *temp = (char*) malloc (strlen((yyvsp[(3) - (4)].str))*sizeof(char)); strcpy(temp,(yyvsp[(3) - (4)].str));
											int insert = qLookAndStackSearch(s->head->next->h,(yyvsp[(1) - (4)].str),2,temp,s);

											if (insert == 0){
												errorStr = (char*)malloc(strlen("Function ")*sizeof(char));
												strcat(errorStr,"Function ");
												strcat(errorStr,(yyvsp[(1) - (4)].str));
												strcat(errorStr," is not declared");
												myError(errorStr);
												errorStr=NULL;
											}
											else
												(yyval.str) = (void*)f->symbol;
										}
										(yyval.str)=(yyvsp[(1) - (4)].str);
										

									}
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 620 "parse_934448_952056.y"
    {yyerrok;}
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 622 "parse_934448_952056.y"
    {(yyval.str)= (char*) malloc (strlen((yyvsp[(1) - (1)].str))*sizeof(char)); strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 623 "parse_934448_952056.y"
    {(yyval.str)= (char*) malloc (strlen("")*sizeof(char)); strcpy((yyval.str),"");}
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 625 "parse_934448_952056.y"
    {(yyval.str)= (char*) malloc ((strlen((yyvsp[(1) - (3)].str))+strlen((yyvsp[(3) - (3)].str))+2)*sizeof(char)); strcpy((yyval.str),(yyvsp[(1) - (3)].str)); strcat((yyval.str),","); strcat((yyval.str),(yyvsp[(3) - (3)].str)); }
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 626 "parse_934448_952056.y"
    {(yyval.str)= (char*) malloc (strlen((yyvsp[(1) - (1)].str))*sizeof(char)); strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;


/* Line 1792 of yacc.c  */
#line 2640 "parse_934448_952056.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
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
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
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


/* Line 2055 of yacc.c  */
#line 628 "parse_934448_952056.y"

void pushQueue(){
   QUEUE *q=NULL; 
   if (initQueue(&q) == EXIT_FAILURE)
	exit(1);
   push(q, s);
}

void pushQueue1(){
   QUEUE *q=NULL; 
   if (initQueue(&q) == EXIT_FAILURE)
	exit(1);
   push(q, s);
}

QUEUENODE * insertInQueue(char* ret, char* two, int isFunction, int isArray){
   SYMTAB *symbol = (SYMTAB*) malloc (sizeof(symbol));
   symbol->name = (char*) malloc ((strlen(two))*sizeof(char));
   strcpy(symbol->name, two);

   int i = 0;
   for (i=0; i<10; i++)
	symbol->paramTypes[i] = 0;

   (symbol->name)[strlen(symbol->name)] = '\0';
   if(ret==NULL){
      /*do nothing*/
   }
   else if (strcmp(ret, "int")==0){
      symbol->type=1;
   }
   else if (strcmp(ret, "float")==0){
      symbol->type=2;
   }
   else if (strcmp(ret, "void")==0){
      symbol->type=3;
   }
   symbol->function=isFunction;
   symbol->array=isArray;
   /*if (isFunction==1){
	int i=0;
	for (i=0;i<sizeof(symbol->paramTypes)/4;i++){
		symbol->paramTypes[i]=0;
	}
   }*/
   QUEUENODE *p = enqueue(symbol, s->head->h);
   return p;
}

int main(void){
   s = initStack();
   QUEUE *q=NULL; 
   if (initQueue(&q) == EXIT_FAILURE)
	exit(1);
   push(q, s); printf("Push in Main\n");
   return yyparse();
}

void myError (char *errorStr){
	fprintf(stderr, "Line %d: %s \n", yylineno, errorStr);
}

yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  fprintf(stderr, "Line %d: %s (%s) %s \n", yylineno, s, yytext, errorStr); 
}
