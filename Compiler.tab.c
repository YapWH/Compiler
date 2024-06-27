
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "Compiler.y"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>
#include "data_struct.h"
#include "state.h"

    /* Declaration of function*/
    // 1. Function to print out the expression
    void print_expr(nodeType* );

    // 2. Function to store the constant, matrix and 'arguments number for each IDENTIFIER'
    nodeType *con(double value);
    nodeType *store_matrix();  
    void saved_arguments_num();
    
    // 3. Function to perform function operation [IDENTIFIER '(' arguments ')']
    nodeType *func_operation();
    
    // 3.1 Function to perform arithmetric and U-arithmetric (E.g. U-MINUS) operation
    nodeType *arithmetric(nodeType *a, nodeType *b, char opr1);
    nodeType *U_arithmetric(nodeType *a, char opr1);
    double calculate(double a, double b, char opr1);
    double U_calculate(double a, char opr1);

    // 3.2 Function to perform basic function operation. E.g. sin(), cos(), mod(),...
    double apply_function(int num, ...);

    // 3.3 Function to perform matrix and vector operation
    nodeType* create_array(nodeType* rowNode, nodeType* colNode, double value);
    nodeType* reshape_array(nodeType* a, nodeType* new_row, nodeType* new_col);
    nodeType* horzat_array(nodeType* matrix1, nodeType* matrix2);
    nodeType* verzat_array(nodeType* matrix1, nodeType* matrix2);
    nodeType* linspace(double start, double stop, double num);
    nodeType* logspace(double start, double stop, double num);
    nodeType* transpose_array(nodeType* input);
    nodeType* cross_product(nodeType* matrix1, nodeType* matrix2);
    nodeType* scalar_mul_mat(nodeType *scalar, nodeType* matrix1);
    nodeType* mat_mul_scalar(nodeType* matrix1, nodeType* scalar);
    nodeType* determinant(nodeType* matrix1);
    nodeType* eigen(nodeType* matrix1);
    nodeType* trace(nodeType* matrix1);
    nodeType* inverse_matrix(nodeType* input);

    // 4. Function needed in .lex file
    int yylex(void);
    void yyerror(char *s);
    
    /* Declare of variables */
    int MAX_NUM_SYMBOL = 500;       // 500 = Total number of identifier available for the program
    int MAX_NUM_ARGS   = 10;        // 10  = Total number of arguments available for the program
    nodeType **symbols;             // a pointer to store list of variables
    nodeType **arguments;           // a pointer to store list of arguments
    int symbols_id[500];            // To indicate whether the data have been assigned value before 
    double matrix_buffer[50][50];   // Matrix maximum size
    int func_arg[100];              // Array to store number of argument that a function should have
    int error_flag = 0;             // A flag to indicate whether the programmer type some syntax wrongly
    int row=0, col=0;               // Variable to store row and col of a matrix
    int count_arg;                  // Variable to count the number of arguments for a function
    int temp_Identifier = 0;        // Variable to store temperary identifier for a variable
    nodeType* ans;                  // Variable to store latest display answer in screen
    


/* Line 189 of yacc.c  */
#line 141 "Compiler.tab.c"

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     DOUBLE = 259,
     UPLUS = 260,
     UMINUS = 261
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 68 "Compiler.y"
                        
    int id;                 /* Integer value */
    double dValue;          /* Double value*/
    nodeType* nPtr;



/* Line 214 of yacc.c  */
#line 191 "Compiler.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 203 "Compiler.tab.c"

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
# if YYENABLE_NLS
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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   59

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  21
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  7
/* YYNRULES -- Number of rules.  */
#define YYNRULES  25
/* YYNRULES -- Number of states.  */
#define YYNSTATES  46

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   261

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      16,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    18,     2,     2,
      14,    15,     9,     7,     6,     8,     2,    10,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     5,
       2,    17,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    19,     2,    20,    11,     2,     2,     2,     2,     2,
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
      12,    13
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     7,     8,    12,    14,    18,    22,    26,
      30,    34,    38,    41,    44,    48,    53,    55,    57,    61,
      65,    67,    71,    73,    76,    80
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      22,     0,    -1,    22,    23,    16,    -1,    -1,     3,    17,
      24,    -1,    24,    -1,    24,     7,    24,    -1,    24,     8,
      24,    -1,    24,     9,    24,    -1,    24,    10,    24,    -1,
      24,    11,    24,    -1,    24,    18,    24,    -1,     8,    24,
      -1,     7,    24,    -1,    14,    24,    15,    -1,     3,    14,
      25,    15,    -1,     4,    -1,     3,    -1,    19,    26,    20,
      -1,    25,     6,    24,    -1,    24,    -1,    26,     5,    26,
      -1,    27,    -1,    27,     4,    -1,    27,     6,     4,    -1,
       4,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    89,    89,    90,    92,    96,   102,   105,   108,   111,
     114,   117,   120,   123,   126,   128,   141,   142,   151,   156,
     162,   168,   169,   171,   172,   173
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "DOUBLE", "';'", "','",
  "'+'", "'-'", "'*'", "'/'", "'^'", "UPLUS", "UMINUS", "'('", "')'",
  "'\\n'", "'='", "'%'", "'['", "']'", "$accept", "program", "stmt",
  "expr", "argument", "matrix", "vector", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,    59,    44,    43,    45,    42,
      47,    94,   260,   261,    40,    41,    10,    61,    37,    91,
      93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    21,    22,    22,    23,    23,    24,    24,    24,    24,
      24,    24,    24,    24,    24,    24,    24,    24,    24,    25,
      25,    26,    26,    27,    27,    27
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     0,     3,     1,     3,     3,     3,     3,
       3,     3,     2,     2,     3,     4,     1,     1,     3,     3,
       1,     3,     1,     2,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     1,    17,    16,     0,     0,     0,     0,     0,
       5,     0,     0,    17,    13,    12,     0,    25,     0,    22,
       2,     0,     0,     0,     0,     0,     0,    20,     0,     4,
      14,     0,    18,    23,     0,     6,     7,     8,     9,    10,
      11,     0,    15,    21,    24,    19
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     9,    10,    28,    18,    19
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -10
static const yytype_int8 yypact[] =
{
     -10,    23,   -10,    -9,   -10,    21,    21,    21,     0,    -7,
       4,    21,    21,    19,    20,    20,    41,   -10,    27,    51,
     -10,    21,    21,    21,    21,    21,    21,     4,    28,     4,
     -10,     0,   -10,   -10,    37,    35,    35,    -8,    -8,    20,
       4,    21,   -10,   -10,   -10,     4
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -10,   -10,   -10,    -5,   -10,     8,   -10
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      14,    15,    16,    25,    17,    11,    27,    29,    12,    20,
      26,    21,    22,    23,    24,    25,    35,    36,    37,    38,
      39,    40,    26,     2,    13,     4,     3,     4,     5,     6,
       5,     6,    31,    11,    41,     7,    45,     7,    26,    43,
       8,    44,     8,    42,    23,    24,    25,    32,    21,    22,
      23,    24,    25,    26,     0,    33,    30,    34,     0,    26
};

static const yytype_int8 yycheck[] =
{
       5,     6,     7,    11,     4,    14,    11,    12,    17,    16,
      18,     7,     8,     9,    10,    11,    21,    22,    23,    24,
      25,    26,    18,     0,     3,     4,     3,     4,     7,     8,
       7,     8,     5,    14,     6,    14,    41,    14,    18,    31,
      19,     4,    19,    15,     9,    10,    11,    20,     7,     8,
       9,    10,    11,    18,    -1,     4,    15,     6,    -1,    18
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    22,     0,     3,     4,     7,     8,    14,    19,    23,
      24,    14,    17,     3,    24,    24,    24,     4,    26,    27,
      16,     7,     8,     9,    10,    11,    18,    24,    25,    24,
      15,     5,    20,     4,     6,    24,    24,    24,    24,    24,
      24,     6,    15,    26,     4,    24
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
# if YYLTYPE_IS_TRIVIAL
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
  if (yyn == YYPACT_NINF)
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
        case 4:

/* Line 1455 of yacc.c  */
#line 92 "Compiler.y"
    { symbols[(yyvsp[(1) - (3)].id)] = malloc(sizeof(nodeType));
                                    symbols[(yyvsp[(1) - (3)].id)] = (yyvsp[(3) - (3)].nPtr);
                                    symbols_id[(yyvsp[(1) - (3)].id)] = 1;
                                    ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 96 "Compiler.y"
    { if (!(temp_Identifier == 40|| temp_Identifier == 41|| temp_Identifier == 42 || temp_Identifier == 43)){
                                        print_expr((yyvsp[(1) - (1)].nPtr));
                                        ans = (yyvsp[(1) - (1)].nPtr);
                                    }
                                  ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 102 "Compiler.y"
    { (yyval.nPtr) = arithmetric((yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr), '+');
                                        if (error_flag) return 1;
                                      ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 105 "Compiler.y"
    { (yyval.nPtr) = arithmetric((yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr), '-');
                                        if (error_flag) return 1;
                                      ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 108 "Compiler.y"
    { (yyval.nPtr) = arithmetric((yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr), '*');
                                        if (error_flag) return 1;
                                      ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 111 "Compiler.y"
    { (yyval.nPtr) = arithmetric((yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr), '/');
                                        if (error_flag) return 1;
                                      ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 114 "Compiler.y"
    { (yyval.nPtr) = arithmetric((yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr), '^');
                                        if (error_flag) return 1;
                                      ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 117 "Compiler.y"
    { (yyval.nPtr) = arithmetric((yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr), '%');
                                        if (error_flag) return 1;
                                      ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 120 "Compiler.y"
    { (yyval.nPtr) = U_arithmetric((yyvsp[(2) - (2)].nPtr), '-');
                                        if (error_flag) return 1;
                                      ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 123 "Compiler.y"
    { (yyval.nPtr) = U_arithmetric((yyvsp[(2) - (2)].nPtr), '+');
                                        if (error_flag) return 1;
                                      ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 126 "Compiler.y"
    { (yyval.nPtr) = (yyvsp[(2) - (3)].nPtr); ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 128 "Compiler.y"
    {
                                            if ((yyvsp[(1) - (4)].id) >= 100){
                                                yyerror("The identifier is not a function");
                                                return 1;
                                            }
                                            temp_Identifier = (yyvsp[(1) - (4)].id);
                                            if (count_arg > func_arg[temp_Identifier]) {
                                                printf("The arguments number exceed the argument allowed. Current: %d, Correct: %d.\n", count_arg, func_arg[temp_Identifier]);
                                                return 1;
                                            }
                                            (yyval.nPtr) = func_operation();
                                            if (error_flag) return 1;
                                        ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 141 "Compiler.y"
    { (yyval.nPtr) = con((yyvsp[(1) - (1)].dValue));   ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 142 "Compiler.y"
    { temp_Identifier = (yyvsp[(1) - (1)].id);
                                          if (symbols_id[(yyvsp[(1) - (1)].id)] == 1) { (yyval.nPtr) = symbols[(yyvsp[(1) - (1)].id)]; }
                                          else if((yyvsp[(1) - (1)].id) == 40) { printf("\e[1;1H\e[2J"); }
                                          else if((yyvsp[(1) - (1)].id) == 41) { print_expr(ans); }
                                          else{
                                            yyerror("Undeclared Identifier!");
                                            return 1;
                                          }
                                        ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 151 "Compiler.y"
    { temp_Identifier = 0;
                                          (yyval.nPtr) = store_matrix();
                                          row=0;  col=0; // Reset the row and column
                                        ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 156 "Compiler.y"
    {
                                          arguments[count_arg] = malloc(sizeof(nodeType));
                                          arguments[count_arg] = (yyvsp[(3) - (3)].nPtr);
                                          count_arg++;
                                        ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 162 "Compiler.y"
    { count_arg = 0;
                                          arguments[count_arg] = malloc(sizeof(nodeType));
                                          arguments[count_arg] = (yyvsp[(1) - (1)].nPtr);
                                          count_arg++;
                                        ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 168 "Compiler.y"
    { ; ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 169 "Compiler.y"
    {row ++;;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 171 "Compiler.y"
    {matrix_buffer[row][col++] = (yyvsp[(2) - (2)].dValue); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 172 "Compiler.y"
    {matrix_buffer[row][col++] = (yyvsp[(3) - (3)].dValue);;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 173 "Compiler.y"
    { col = 0;  
                                          matrix_buffer[row][col++] = (yyvsp[(1) - (1)].dValue);;}
    break;



/* Line 1455 of yacc.c  */
#line 1632 "Compiler.tab.c"
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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



/* Line 1675 of yacc.c  */
#line 175 "Compiler.y"


void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}

int main(void) {
    ans       = malloc(sizeof(nodeType));
    symbols   = malloc(MAX_NUM_SYMBOL*sizeof(nodeType));
    arguments = malloc(MAX_NUM_ARGS*sizeof(nodeType));
    saved_arguments_num();
    yyparse();
    return 0;
}

void print_expr(nodeType* p){
    printf("out: ");
    if (p->type == typeConstant)
    {
        printf("%.4lf\n",p->cons);
    }
    else if (p->type == typeVector){
        printf("[ ");
        for (int i=0; i<p->vec.length; i++)
            printf("%.4lf ",p->vec.vector[i]);
        printf("]\n");
    }
    else if (p->type == typeMatrix){
        printf("[ ");
        for (int i=0; i< p->mat.row; i++){
            for (int j=0; j<p->mat.col; j++)
                printf("%lf ",p->mat.matrix[i][j]);
            if (i < p->mat.row-1)
                printf("\n      ");
        }
        printf("]\n");
    }
}

nodeType *con(double value) {
    nodeType *p;      // Declare a pointer of node

    /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeConstant;
    p->cons = value;

    return p;
}

nodeType* store_matrix(){
    nodeType *node = malloc(sizeof(nodeType));

    if (row == 1){ // It is a vector
        node->type = typeVector;
        node->vec.length = col;
        node->vec.vector = malloc(sizeof(double) * col);

        for (int i=0; i< col; i++)
            node->vec.vector[i] = matrix_buffer[row-1][i];
    }
    else {    //It is a matrix
        
        node->type = typeMatrix;
        node->mat.row = row;
        node->mat.col = col;
        node->mat.matrix = malloc(sizeof(double) * row * col);   
        for (int i=0; i< row; i++){
            node->mat.matrix[i] = malloc(sizeof(double) * col);
            for (int j =0; j< col; j++)
                node->mat.matrix[i][j] = matrix_buffer[i][j];
        }
    }

    return node;
}

void saved_arguments_num(){
    for (int i=0; i<20; i++)        // Function that have 1 argument
        func_arg[i] = 1;
    for (int i=20; i<30; i++)       // Function that have 2 arguments
        func_arg[i] = 2;
    for (int i =30; i<40; i++)      // Function that have 3 arguments
        func_arg[i] = 3;
}

nodeType *func_operation(){
    nodeType *p = malloc(sizeof(nodeType));

    switch (count_arg){
        case 1:
        {
            if (temp_Identifier < 25)
            {
                if (arguments[0]->type == typeConstant){
                    p->type = typeConstant;
                    p->cons = apply_function(count_arg, arguments[0]->cons);
                }
                else if (arguments[0]->type == typeVector){
                    if (temp_Identifier >=0 && temp_Identifier <=12){
                        p->type = typeVector;
                        p->vec.length = arguments[0]->vec.length;
                        p->vec.vector = malloc(sizeof(arguments[0]->vec.vector));
                        
                        for (int i=0; i<p->vec.length; i++)
                            p->vec.vector[i] = apply_function(count_arg, arguments[0]->vec.vector[i]); 
                    }
                    else if (temp_Identifier == 13){
                        p->type = typeConstant;
                        p->cons = arguments[0]->vec.length;
                    }
                    else if (temp_Identifier == 14){
                        p->type = typeVector;
                        p->vec.vector = malloc(sizeof(double) * 1);
                        p->vec.length = 1;
                        p->vec.vector[0] = arguments[0]->vec.length;
                    }
                    else if (temp_Identifier == 15){
                        p->type = typeConstant;
                        p->cons = 1;
                    }
                    else if (temp_Identifier == 16){
                        p->type = typeConstant;
                        p->cons = arguments[0]->vec.length;
                    }
                    else if (temp_Identifier == 17){
                            return transpose_array(arguments[0]);
                    }
                }
                else if (arguments[0]->type == typeMatrix){
                    if (temp_Identifier >=0 && temp_Identifier <=12){
                        p->type = typeMatrix;
                        p->mat.row    = arguments[0]->mat.row;
                        p->mat.col    = arguments[0]->mat.col;
                        p->mat.matrix = malloc(sizeof(double) * p->mat.row * p->mat.col);
                        
                        for (int i=0; i< p->mat.row; i++){
                            p->mat.matrix[i] =  malloc(sizeof(double) * p->mat.col);
                            for (int j =0; j< p->mat.col; j++){
                                p->mat.matrix[i][j] = apply_function(count_arg, arguments[0]->mat.matrix[i][j]);
                            }
                        }
                    }
                    else if (temp_Identifier == 13){
                        p->type = typeConstant;
                        p->cons = arguments[0]->mat.row > arguments[0]->mat.col ? arguments[0]->mat.row : arguments[0]->mat.col;
                    }
                    else if (temp_Identifier == 14){
                        p->type = typeVector;
                        p->vec.vector = malloc(sizeof(double) * 2);
                        p->vec.length = 2;
                        p->vec.vector[0] = arguments[0]->mat.row;
                        p->vec.vector[1] = arguments[0]->mat.col;
                    }
                    else if (temp_Identifier == 15){
                        p->type = typeConstant;
                        p->cons = 2;
                    }
                    else if (temp_Identifier == 16){
                        p->type = typeConstant;
                        p->cons = arguments[0]->mat.row * arguments[0]->mat.col;
                    }
                    else if (temp_Identifier == 17){
                            return transpose_array(arguments[0]);
                    }
                    else if (temp_Identifier == 18){
                        return determinant(arguments[0]);
                    }
                    else if (temp_Identifier == 19){
                        return eigen(arguments[0]);
                    }
                    else if (temp_Identifier == 20){
                        return trace(arguments[0]);
                    }
                    else if (temp_Identifier == 21){
                        return inverse_matrix(arguments[0]);
                    }
                } 
            }
            else
            {
                printf("The arguments number are too few, %d. Use %d arguments.\n", count_arg, func_arg[temp_Identifier]);
                error_flag = 1;
                return NULL;
            }
            break;
        }
        case 2:
        {
            if (temp_Identifier >= 25 && temp_Identifier < 35)
            {
                if (arguments[0]->type == typeConstant && arguments[1]->type == typeConstant){
                    if (temp_Identifier == 28){
                        return create_array(arguments[0], arguments[1], 0.0);
                    } 
                    else if (temp_Identifier == 29){
                        return create_array(arguments[0], arguments[1], 1.0);
                    }
                    else if (temp_Identifier == 25){
                        p->type = typeConstant;
                        p->cons = apply_function(count_arg, arguments[0]->cons, arguments[1]->cons);
                    }
                    else{
                        printf("Incorrect format of arguments.\n");
                        error_flag = 1;
                        return NULL;
                    }
                }
                else if (arguments[0]->type == typeVector && arguments[1]->type == typeConstant){
                    if (temp_Identifier == 25){
                        p->type = typeVector;
                        p->vec.length = arguments[0]->vec.length;
                        p->vec.vector = malloc(sizeof(arguments[0]->vec.vector));
                        
                        for (int i=0; i<p->vec.length; i++)
                            p->vec.vector[i] = apply_function(count_arg, arguments[0]->vec.vector[i], arguments[1]->cons); 
                    }
                    else{
                        printf("Incorrect format of arguments.\n");
                        error_flag = 1;
                        return NULL;
                    }
                }
                else if (arguments[0]->type == typeMatrix && arguments[1]->type == typeConstant){
                    if (temp_Identifier == 25){
                        p->type = typeMatrix;
                        p->mat.row    = arguments[0]->mat.row;
                        p->mat.col    = arguments[0]->mat.col;
                        p->mat.matrix = malloc(sizeof(double) * p->mat.row * p->mat.col);
                        
                        for (int i=0; i< p->mat.row; i++){
                            p->mat.matrix[i] =  malloc(sizeof(double) * p->mat.col);
                            for (int j =0; j< p->mat.col; j++){
                                p->mat.matrix[i][j] = apply_function(count_arg, arguments[0]->mat.matrix[i][j], arguments[1]->cons);
                            }
                        }
                    }
                    else if (temp_Identifier == 32){
                        p = mat_mul_scalar(arguments[0], arguments[1]);
                    }
                    else{
                        printf("Incorrect format of arguments.\n");
                        error_flag = 1;
                        return NULL;
                    }
                }
                else if (arguments[0]->type == typeConstant && arguments[1]->type == typeMatrix){
                    if (temp_Identifier == 31){
                        p = scalar_mul_mat(arguments[0], arguments[1]);
                    }
                    else{
                        printf("Incorrect format of arguments.\n");
                        error_flag = 1;
                        return NULL;
                    }
                }
                else if (arguments[0]->type == typeMatrix && arguments[1]->type == typeMatrix ){
                    if (temp_Identifier == 26)
                        return horzat_array(arguments[0], arguments[1]);
                    else if (temp_Identifier == 27)
                        return verzat_array(arguments[0], arguments[1]);
                    else if (temp_Identifier == 30)
                        return cross_product(arguments[0], arguments[1]);
                    else{
                        printf("Incorrect format of arguments.\n");
                        error_flag = 1;
                        return NULL;
                    }
                }
                else{
                    printf("Incorrect format of arguments.\n");
                    error_flag = 1;
                    return NULL;
                }
            }
            else
            {
                printf("The arguments number are too few, %d. Use %d arguments.\n", count_arg, func_arg[temp_Identifier]);
                error_flag = 1;
                return NULL;
            }
            break;
        }
        case 3:
        {
            if (temp_Identifier >= 35 && temp_Identifier < 40)
            {
                if ((arguments[0]->type == typeMatrix || arguments[0]->type == typeVector) && arguments[1]->type == typeConstant && arguments[2]->type == typeConstant){ 
                    if (temp_Identifier == 35){
                        return reshape_array(arguments[0], arguments[1], arguments[2]);
                    }
                    else{
                        printf("Incorrect format of arguments.\n");
                        error_flag = 1;
                        return NULL;
                    }
                }
                else if (arguments[0]->type == typeConstant && arguments[1]->type == typeConstant && arguments[2]->type == typeConstant){
                    if (temp_Identifier == 36)
                        return linspace(arguments[0]->cons, arguments[1]->cons, arguments[2]->cons);
                    else if (temp_Identifier == 37)
                        return logspace(arguments[0]->cons, arguments[1]->cons, arguments[2]->cons);
                    else{
                        printf("Incorrect format of arguments.\n");
                        error_flag = 1;
                        return NULL;
                    }
                }
                else{
                    printf("Incorrect format of arguments.\n");
                    error_flag = 1;
                    return NULL;
                }
                
            }
            else
            {
                printf("The arguments number are too few, %d. Use %d arguments.\n", count_arg, func_arg[temp_Identifier]);
                error_flag = 1;
                return NULL;
            }
            break;
        }
        default:
            error_flag = 1;
            return NULL;
    }

    return p;
}

nodeType *arithmetric(nodeType *a, nodeType *b, char opr1){
    nodeType *p = malloc(sizeof(nodeType));
    if (a->type == typeConstant && b->type == typeConstant){
        p->type = typeConstant;
        p->cons = calculate(a->cons, b->cons, opr1);
    }
    else if (a->type == typeVector && b->type == typeVector){
        if (a->vec.length == b->vec.length){
            p->type = typeVector;
            p->vec.length = a->vec.length;
            p->vec.vector = malloc(sizeof(a->vec.vector));
            for (int i=0; i<p->vec.length; i++)
                p->vec.vector[i] = calculate(a->vec.vector[i], b->vec.vector[i], opr1);
        }
        else{
            error_flag = 1;
            printf("The vector have difference length a: %d, b:%d\n",a->vec.length, b->vec.length);
        }
    }
    else if (a->type == typeMatrix && b->type == typeMatrix){
        if (a->mat.row == b->mat.row && a->mat.col == b->mat.col ){
            p->type = typeMatrix;
            p->mat.row   = a->mat.row;
            p->mat.col   = a->mat.col;
            p->mat.matrix = malloc(sizeof(double) * p->mat.row * p->mat.col);
            for (int i=0; i< p->mat.row; i++){
                p->mat.matrix[i] =  malloc(sizeof(double) * p->mat.col);
                for (int j =0; j< p->mat.col; j++){
                    p->mat.matrix[i][j] = calculate(a->mat.matrix[i][j], b->mat.matrix[i][j], opr1);
                }
            }
        }
        else{
            error_flag = 1;
            printf("The matrix have difference shape a: (%d,%d), b:(%d,%d)\n",a->mat.row, a->mat.col, b->mat.row, b->mat.col);
        }
    }
    else{
        error_flag = 1;
    }
    return p;
}

nodeType *U_arithmetric(nodeType *a, char opr1){
    nodeType *p = malloc(sizeof(nodeType));
    if (a->type == typeConstant ){
        p->type = typeConstant;
        p->cons = U_calculate(a->cons, opr1);
    }
    else if (a->type == typeVector){
        p->type = typeVector;
        p->vec.length = a->vec.length;
        p->vec.vector = malloc(sizeof(a->vec.vector));
        for (int i=0; i<p->vec.length; i++)
            p->vec.vector[i] = U_calculate(a->vec.vector[i], opr1); 
    }
    else if (a->type == typeMatrix){
        p->type = typeMatrix;
        p->mat.row   = a->mat.row;
        p->mat.col   = a->mat.col;
        p->mat.matrix = malloc(sizeof(double) * p->mat.row * p->mat.col);
        for (int i=0; i< p->mat.row; i++){
            p->mat.matrix[i] =  malloc(sizeof(double) * p->mat.col);
            for (int j =0; j< p->mat.col; j++){
                p->mat.matrix[i][j] = U_calculate(a->mat.matrix[i][j], opr1);
            }
        }
    }

    return p;
}

double calculate(double a, double b, char opr1){
    if (opr1 == '+')      return a+b;
    else if (opr1 == '-') return a-b;
    else if (opr1 == '*' )return a*b;
    else if (opr1 == '/') return a/b;
    else if (opr1 == '^') return pow(a,b);
}

double U_calculate(double a, char opr1){
    if (opr1 == '+')      return a;
    else if (opr1 == '-') return -a;
}

double apply_function(int num, ...){
    double result;
    double temp_arr[MAX_NUM_ARGS];
    va_list valist;
    va_start(valist, num);          // Initialize valist for num of number of arguments

    switch(temp_Identifier){
        /* Functions with 1 argument */
        case 0:  result = sin(va_arg(valist, double));   break;        // access all the arguments assigned to valist
        case 1:  result = cos(va_arg(valist, double));   break;
        case 2:  result = tan(va_arg(valist, double));   break;
        case 3:  result = asin(va_arg(valist, double));  break;
        case 4:  result = acos(va_arg(valist, double));  break;
        case 5:  result = atan(va_arg(valist, double));  break;
        case 6:  result = round(va_arg(valist, double)); break;
        case 7:  result = ceil(va_arg(valist, double));  break;
        case 8:  result = floor(va_arg(valist, double)); break;
        case 9:  result = exp(va_arg(valist, double));   break;
        case 10: result = log(va_arg(valist, double));   break;
        case 11: result = log10(va_arg(valist, double)); break;
        case 12: result = sqrt(va_arg(valist, double));  break;

        /* Functions with 2 arguments */
        case 20: temp_arr[0] = va_arg(valist, double); 
                 result = fmod(temp_arr[0], va_arg(valist, double)); break;
        
        /* Functions with 3 arguments */

    }

    va_end(valist);    // clean memory reserved for valist
    return result;
}

nodeType* create_array(nodeType* rowNode, nodeType* colNode,  double value) {
    nodeType* p = malloc(sizeof(nodeType));
    
    if (rowNode->type == typeConstant && colNode->type == typeConstant) {
        p->type = typeMatrix;
        p->mat.row = rowNode->cons;
        p->mat.col = colNode->cons;
        p->mat.matrix = malloc(sizeof(nodeType) * p->mat.row );

        for (int i = 0; i < p->mat.row ; i++) {
            p->mat.matrix[i] = malloc(sizeof(double) * p->mat.col);
            for (int j = 0; j < p->mat.col; j++) {
                p->mat.matrix[i][j] = value;
            }
        }
        return p;
    } 
    else{
        error_flag = 1;
        printf("Invalid input. Rows and columns should be an constant value.\n");
        return NULL;
    }
}

// Reshape matrix or vector  -- temp_Identifier = 30
nodeType* reshape_array(nodeType* a, nodeType* new_row, nodeType* new_col){
    nodeType* p = malloc(sizeof(nodeType));
    int new_row_value = new_row->cons;
    int new_col_value = new_col->cons;

    if (new_row->type == typeConstant && new_col->type == typeConstant){

        if (a->type == typeVector){
            p->type = typeMatrix;
            int length = a->vec.length;
            int total_elements = new_row_value * new_col_value;

            if (length == total_elements){
                p->mat.row = new_row_value;
                p->mat.col = new_col_value;
                p->mat.matrix = malloc(sizeof(double*) * new_row_value);

                int k = 0;
                for (int i = 0; i < new_row_value; i++) {
                    p->mat.matrix[i] = malloc(sizeof(double) * new_col_value);
                    for (int j = 0; j < new_col_value; j++) {
                        p->mat.matrix[i][j] = a->vec.vector[k++];
                    }
                }

                return p;
            } else{
                error_flag = 1;
                printf("Invalid reshape dimensions. The total number of elements must remain the same. Given %d, reshape ele: %d\n", length, total_elements);
            } 
        } else if (a->type == typeMatrix){
            p->type = typeMatrix;
            int row = a->mat.row;
            int col = a->mat.col;
            int total_elements = row * col;

            if (total_elements == new_row_value * new_col_value){
                p->mat.row = new_row_value;
                p->mat.col = new_col_value;
                p->mat.matrix = malloc(sizeof(double*) * new_row_value);

                for (int i = 0; i < new_row_value; i++) {
                    p->mat.matrix[i] = malloc(sizeof(double) * new_col_value);
                    for (int j = 0; j < new_col_value; j++) {
                        int old_i = (i * new_col_value + j) / col;
                        int old_j = (i * new_col_value + j) % col;
                        p->mat.matrix[i][j] = a->mat.matrix[old_i][old_j];
                    }
                }

            return p;
            } else{
                error_flag = 1;
                printf("Invalid reshape dimensions. The total number of elements must remain the same. Given %d, reshape ele: %d\n", total_elements, new_row_value * new_col_value);
            }
        } else {
            error_flag = 1;
            printf("Unsupported type for reshape operation.\n");
        }
    } else{
        error_flag = 1;
        printf("Invalid input. Row and Colummns should be integer.\n");
    }
}

// Concatenate matrix horizontally -- temp_Identifier = 21
nodeType* horzat_array(nodeType* matrix1, nodeType* matrix2) {
    if (matrix1->type != typeMatrix || matrix2->type != typeMatrix) {
        error_flag = 1;
        printf("Invalid input types. Only matrices can be concatenated.\n");
    }

    int row1 = matrix1->mat.row;
    int col1 = matrix1->mat.col;
    int row2 = matrix2->mat.row;
    int col2 = matrix2->mat.col;

    // Concatenate horizontally
    if (row1 == row2) {
        nodeType* p = malloc(sizeof(nodeType));
        p->type = typeMatrix;
        p->mat.row = row1;
        p->mat.col = col1 + col2;
        p->mat.matrix = malloc(sizeof(double*) * row1);

        for (int i = 0; i < row1; i++) {
            p->mat.matrix[i] = malloc(sizeof(double) * (col1 + col2));

            for (int j = 0; j < col1; j++) {
                p->mat.matrix[i][j] = matrix1->mat.matrix[i][j];
            }

            for (int j = 0; j < col2; j++) {
                p->mat.matrix[i][col1 + j] = matrix2->mat.matrix[i][j];
            }
        }
        return p;

    } else{
        error_flag = 1;
        printf("Invalid matrices for horizontal concatenation. The number of rows must match a:%d, b:%d.\n",row1,row2);
    }
}

// Concatenate matrix vertically   -- temp_Identifier = 22
nodeType* verzat_array(nodeType* matrix1, nodeType* matrix2) {

    if (matrix1->type != typeMatrix || matrix2->type != typeMatrix) {
        error_flag = 1;
        printf("Invalid input types. Only matrices can be concatenated.\n");
    }

    int row1 = matrix1->mat.row;
    int col1 = matrix1->mat.col;
    int row2 = matrix2->mat.row;
    int col2 = matrix2->mat.col;

    // Concatenate vertically
    if (col1 == col2) {
        nodeType* p = malloc(sizeof(nodeType));
        p->type = typeMatrix;
        p->mat.row = row1 + row2;
        p->mat.col = col1;
        p->mat.matrix = malloc(sizeof(double*) * (row1 + row2));

        for (int i = 0; i < row1; i++) {
            p->mat.matrix[i] = malloc(sizeof(double) * col1);

            for (int j = 0; j < col1; j++) {
                p->mat.matrix[i][j] = matrix1->mat.matrix[i][j];
            }
        }

        for (int i = 0; i < row2; i++) {
            p->mat.matrix[row1 + i] = malloc(sizeof(double) * col1);

            for (int j = 0; j < col1; j++) {
                p->mat.matrix[row1 + i][j] = matrix2->mat.matrix[i][j];
            }
        }

        return p;
    } else{
        error_flag = 1;
        printf("Invalid matrices for vertical concatenation. The number of columns must match a:%d, b:%d.\n",col1,col2);
    }
}

// Cross product of two matrix -- temp_Identifier = 25
nodeType* cross_array(nodeType* matrix1, nodeType* matrix2) {
    if (matrix1->type != typeVector || matrix2->type != typeVector) {
        error_flag = 1;
        printf("Invalid input types. Only vectors can be cross multiplied.\n");
    }

    if (matrix1->mat.col != matrix2->mat.row){
        error_flag = 1;
        printf("Invalid matrices for cross product. The number of columns of the first matrix must match the number of rows of the second matrix.\n");
    }

    nodeType* p = malloc(sizeof(nodeType));
    p->type = typeMatrix;
    p->mat.row = matrix1->mat.row;
    p->mat.col = matrix2->mat.col;
    p->mat.matrix = malloc(sizeof(double*) * p->mat.row);

    for (int i=0; i < p->mat.row; i++) {
        p->mat.matrix[i] = malloc(sizeof(double) * p->mat.col);
    }

    for (int i = 0; i < p->mat.row; i++) {
        for (int j = 0; j < p->mat.col; j++) {
            p->mat.matrix[i][j] = 0;
            for (int k = 0; k < matrix1->mat.col; k++) {
                p->mat.matrix[i][j] += matrix1->mat.matrix[i][k] * matrix2->mat.matrix[k][j];
            }
        }
    }

    return p;
}

nodeType* linspace(double start, double stop, double num){
    nodeType* p = malloc(sizeof(nodeType));
    p->type = typeVector;
    p->vec.length = num;
    p->vec.vector = malloc(sizeof(double) * num);

    for (int i=0; i< num; i++)
        p->vec.vector[i] = start + (stop-start)/(num-1) * i;

    return p;
}

nodeType* logspace(double start, double stop, double num){
    nodeType* p = malloc(sizeof(nodeType));
    p = linspace(start, stop, num);

    for (int i=0; i< num; i++){
        p->vec.vector[i] = pow(10, p->vec.vector[i]);
    }
    return p;
}

nodeType* transpose_array(nodeType* input){
    nodeType* p = malloc(sizeof(nodeType));
    p->type = typeMatrix;
    
    if (input->type == typeMatrix)  {
        p->mat.row = input->mat.col;
        p->mat.col = input->mat.row;
        p->mat.matrix = malloc(p->mat.row * sizeof(nodeType));
        
        for (int i = 0; i < p->mat.row; i++) {
            p->mat.matrix[i] = malloc(p->mat.col * sizeof(nodeType));
            for(int j=0; j < p->mat.col;j++) {
                p->mat.matrix[i][j] = input->mat.matrix[j][i];
            }
        }
    }
    else if (input->type == typeVector) {
        p->mat.row=input->vec.length;
        p->mat.col=1;
        p->mat.matrix = malloc(p->mat.row * sizeof(nodeType));
        for (int i = 0; i < p->mat.row; i++) {
            p->mat.matrix[i] = malloc(p->mat.col * sizeof(nodeType));
            for(int j=0; j < p->mat.col;j++) {
                p->mat.matrix[i][j] = input->vec.vector[i];
            }
        }
    }
    else {
        error_flag = 1;
        printf("Invalid variable type for transpose function.\n");
    }
    
    return p;
}

// Multiply a acalar with a matrix
nodeType* scalar_mul_mat(nodeType *scalar, nodeType *matrix1) {
    int rows = matrix1->mat.row;
    int cols = matrix1->mat.col;

    // Allocate memory for the resulting matrix
    nodeType* p = malloc(sizeof(nodeType));
    p->type = typeMatrix;
    p->mat.row = rows;
    p->mat.col = cols;
    p->mat.matrix = malloc(sizeof(double*) * rows);

    // Perform scalar multiplication
    for (int i = 0; i < rows; i++) {
        p->mat.matrix[i] = malloc(sizeof(double) * cols);
        for (int j = 0; j < cols; j++) {
            p->mat.matrix[i][j] = scalar->cons * matrix1->mat.matrix[i][j];
        }
    }

    return p;
}

// Multiply a matrix with a scalar
nodeType* mat_mul_scalar(nodeType *matrix1, nodeType *scalar) {
    int rows = matrix1->mat.row;
    int cols = matrix1->mat.col;

    // Allocate memory for the resulting matrix
    nodeType* p = malloc(sizeof(nodeType));
    p->type = typeMatrix;
    p->mat.row = rows;
    p->mat.col = cols;
    p->mat.matrix = malloc(sizeof(double*) * rows);

    // Perform scalar multiplication
    for (int i = 0; i < rows; i++) {
        p->mat.matrix[i] = malloc(sizeof(double) * cols);
        for (int j = 0; j < cols; j++) {
            p->mat.matrix[i][j] = matrix1->mat.matrix[i][j] * scalar->cons;
        }
    }

    return p;
}

// Find the Determinant of a matrix
double determinant_recursive(double **matrix, int n) {
    double det = 0;
    if (n == 1) {
        return matrix[0][0];
    }
    if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    double **submatrix = (double **)malloc((n - 1) * sizeof(double *));
    for (int i = 0; i < n - 1; i++) {
        submatrix[i] = (double *)malloc((n - 1) * sizeof(double));
    }
    for (int x = 0; x < n; x++) {
        int subi = 0;
        for (int i = 1; i < n; i++) {
            int subj = 0;
            for (int j = 0; j < n; j++) {
                if (j == x) continue;
                submatrix[subi][subj] = matrix[i][j];
                subj++;
            }
            subi++;
        }
        det += (x % 2 == 0 ? 1 : -1) * matrix[0][x] * determinant_recursive(submatrix, n - 1);
    }
    for (int i = 0; i < n - 1; i++) {
        free(submatrix[i]);
    }
    free(submatrix);
    return det;
}

nodeType* determinant(nodeType *matrix1) {
    if (matrix1->mat.row != matrix1->mat.col) {
        fprintf(stderr, "Matrix must be square to compute determinant.\n");
        exit(EXIT_FAILURE);
    }
    nodeType* p = malloc(sizeof(nodeType));
    p->type = typeMatrix;
    p->mat.row = 1;
    p->mat.col = 1;

    p->mat.matrix = (double **)malloc(sizeof(double *));
    p->mat.matrix[0] = (double *)malloc(sizeof(double));
    p->mat.matrix[0][0] = determinant_recursive(matrix1->mat.matrix, matrix1->mat.row);
    return p;
}

// Find the Eigenvalues and corresponding eigenvectors of a matrix

// Find the Trace of a matrix
nodeType* trace(nodeType *matrix1) {
    if (matrix1->mat.row != matrix1->mat.col) {
        fprintf(stderr, "Matrix must be square to compute trace.\n");
        exit(EXIT_FAILURE);
    }
    double trace = 0;
    for (int i = 0; i < matrix1->mat.row; i++) {
        trace += matrix1->mat.matrix[i][i];
    }
    nodeType *result = (nodeType *)malloc(sizeof(nodeType));
    result->mat.row = 1;
    result->mat.col = 1;
    result->mat.matrix = (double **)malloc(sizeof(double *));
    result->mat.matrix[0] = (double *)malloc(sizeof(double));
    result->mat.matrix[0][0] = trace;
    return result;
}

// Function to compute the inverse of a matrix
nodeType* inverse_matrix(nodeType* input) {
    if (input->type != typeMatrix) {
        error_flag = 1;
        printf("Invalid input type. Only matrices can be inverted.\n");
        return NULL;
    }

    int n = input->mat.row;
    if (n != input->mat.col) {
        error_flag = 1;
        printf("Matrix must be square to find its inverse. Rows: %d, Cols: %d\n", n, input->mat.col);
        return NULL;
    }

    // Allocate memory for the resulting matrix
    nodeType* p = malloc(sizeof(nodeType));
    p->type = typeMatrix;
    p->mat.row = n;
    p->mat.col = n;
    p->mat.matrix = malloc(sizeof(double*) * n);

    for (int i = 0; i < n; i++) {
        p->mat.matrix[i] = malloc(sizeof(double) * n);
    }

    // Create augmented matrix with the identity matrix
    double** aug = malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        aug[i] = malloc(2 * n * sizeof(double));
        for (int j = 0; j < n; j++) {
            aug[i][j] = input->mat.matrix[i][j];
        }
        for (int j = n; j < 2 * n; j++) {
            aug[i][j] = (i == j - n) ? 1 : 0;
        }
    }

    // Perform Gaussian elimination
    for (int i = 0; i < n; i++) {
        if (aug[i][i] == 0) {
            error_flag = 1;
            printf("Matrix is singular and cannot be inverted.\n");
            return NULL;
        }
        for (int j = 0; j < n; j++) {
            if (i != j) {
                double ratio = aug[j][i] / aug[i][i];
                for (int k = 0; k < 2 * n; k++) {
                    aug[j][k] -= ratio * aug[i][k];
                }
            }
        }
    }

    // Normalize the diagonal
    for (int i = 0; i < n; i++) {
        double diag = aug[i][i];
        for (int j = 0; j < 2 * n; j++) {
            aug[i][j] /= diag;
        }
    }

    // Extract the inverse matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            p->mat.matrix[i][j] = aug[i][j + n];
        }
    }

    // Free the augmented matrix
    for (int i = 0; i < n; i++) {
        free(aug[i]);
    }
    free(aug);

    return p;
}

