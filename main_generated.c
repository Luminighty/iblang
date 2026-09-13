#define NULL 0
/*  Common Includes */
#include <stdint.h>
#include <stdbool.h>
typedef uint8_t  u8;
typedef uint16_t  u16;
typedef uint32_t  u32;
typedef uint64_t  u64;
typedef int8_t   i8;
typedef int16_t  i16;
typedef int32_t  i32;
typedef int64_t  i64;
typedef float  f32;
typedef double f64;

/*  Extern Functions */
typedef enum s41_FileSeek s41_FileSeek;
typedef enum s83_HelpMode s83_HelpMode;
typedef enum s84_Mode s84_Mode;
typedef enum s155_Range s155_Range;
typedef enum s220_FlowTypeKind s220_FlowTypeKind;
typedef enum s221_TypeKind s221_TypeKind;
typedef enum s222_AtomicType s222_AtomicType;
typedef enum s226_ErrorKind s226_ErrorKind;
typedef enum s228_ErrorKind s228_ErrorKind;
typedef enum s403_Level s403_Level;
typedef enum s448_Status s448_Status;
typedef enum s449_NodeType s449_NodeType;
typedef enum s463_Method s463_Method;
typedef enum s472_Status s472_Status;
typedef enum s533_FlowTypeKind s533_FlowTypeKind;
typedef enum s534_TypeKind s534_TypeKind;
typedef enum s535_AtomicType s535_AtomicType;
typedef enum s543_SymbolStage s543_SymbolStage;
typedef enum s544_SymbolKind s544_SymbolKind;
typedef enum s557_PathResultKind s557_PathResultKind;
typedef enum s558_IdentResultKind s558_IdentResultKind;
typedef enum s589_NodeKind s589_NodeKind;
typedef enum s616_TokenKind s616_TokenKind;
typedef enum s703_TypeIdentContext s703_TypeIdentContext;
typedef enum s704_Declaration s704_Declaration;
typedef enum s781_ErrorKind s781_ErrorKind;
typedef enum s848_NodeKind s848_NodeKind;
typedef enum s849_ValueKind s849_ValueKind;
typedef enum s850_NodeFlow s850_NodeFlow;
typedef enum s859_LiteralKind s859_LiteralKind;
typedef enum s897_BinaryOp s897_BinaryOp;
typedef enum s898_UnaryOp s898_UnaryOp;
typedef enum s899_LiteralKind s899_LiteralKind;
typedef enum s950_RecoveryResult s950_RecoveryResult;
typedef enum s973_RHSKind s973_RHSKind;
typedef enum s1041_BinaryOp s1041_BinaryOp;
typedef enum s1042_AssignOp s1042_AssignOp;
typedef enum s1052_UnaryOp s1052_UnaryOp;
typedef enum s1115_CastMethod s1115_CastMethod;
#line 1 "./lib/stdlib.ib"
extern void putchar(int v1_c);
#line 2 "./lib/stdlib.ib"
extern int printf(char * v1_c, ...);
#line 3 "./lib/stdlib.ib"
extern void puts(char * v1_c);
#line 4 "./lib/stdlib.ib"
extern int getchar();
#line 5 "./lib/stdlib.ib"
extern int scanf(char * v1_format, ...);
#line 11 "./lib/stdlib.ib"
extern void * fopen(char * v1_path, char * v2_mode);
#line 12 "./lib/stdlib.ib"
extern int putc(int v1_c, void * v2_stream);
#line 13 "./lib/stdlib.ib"
extern int fputs(char * v1_data, void * v2_file);
#line 14 "./lib/stdlib.ib"
extern u64 fread(void * v1_ptr, u64 v2_size, u64 v3_nmemb, void * v4_stream);
#line 15 "./lib/stdlib.ib"
extern u64 fwrite(void * v1_ptr, u64 v2_size, u64 v3_nmemb, void * v4_stream);
#line 16 "./lib/stdlib.ib"
extern int fprintf(void * v1_stream, char * v2_c, ...);
#line 17 "./lib/stdlib.ib"
extern int fseek(void * v1_stream, u64 v2_offset, s41_FileSeek v3_whence);
#line 18 "./lib/stdlib.ib"
extern int fgetc(void * v1_stream);
#line 19 "./lib/stdlib.ib"
extern int ungetc(int v1_c, void * v2_stream);
#line 20 "./lib/stdlib.ib"
extern u64 ftell(void * v1_stream);
#line 21 "./lib/stdlib.ib"
extern int feof(void * v1_stream);
#line 22 "./lib/stdlib.ib"
extern int ferror(void * v1_stream);
#line 23 "./lib/stdlib.ib"
extern int fclose(void * v1_stream);
#line 24 "./lib/stdlib.ib"
extern int fscanf(void * v1_stream, char * v2_format, ...);
#line 25 "./lib/stdlib.ib"
extern int fflush(void * v1_stream);
#line 33 "./lib/stdlib.ib"
extern void * malloc(u64 v1_size);
#line 34 "./lib/stdlib.ib"
extern void * realloc(void * v1_ptr, u64 v2_size);
#line 35 "./lib/stdlib.ib"
extern void free(void * v1_ptr);
#line 36 "./lib/stdlib.ib"
extern void * memcpy(void * v1_dest, void * v2_src, u64 v3_size);
#line 37 "./lib/stdlib.ib"
extern void * memset(void * v1_ptr, int v2_value, u64 v3_size);
#line 38 "./lib/stdlib.ib"
extern int memcmp(void * v1_left, void * v2_right, u64 v3_size);
#line 40 "./lib/stdlib.ib"
extern int strcmp(char * v1_left, char * v2_right);
#line 41 "./lib/stdlib.ib"
extern int strncmp(char * v1_left, char * v2_right, u64 v3_len);
#line 42 "./lib/stdlib.ib"
extern u64 strlen(char * v1_s);
#line 43 "./lib/stdlib.ib"
extern int snprintf(char * v1_target, u64 v2_n, char * v3_format, ...);
#line 44 "./lib/stdlib.ib"
extern int sprintf(char * v1_target, char * v2_format, ...);
#line 46 "./lib/stdlib.ib"
extern void exit(int v1_status);
#line 47 "./lib/stdlib.ib"
extern void abort();
#line 66 "src/utils/fs.ib"
extern i64 remove(char * v1_file);
#line 7 "./lib/stdlib.ib"
extern void * stdout;
#line 8 "./lib/stdlib.ib"
extern void * stderr;
#line 9 "./lib/stdlib.ib"
extern void * stdin;
/*  Object Declarations */
typedef struct s82_Parser s82_Parser;
typedef struct s100_BuildResult s100_BuildResult;
typedef struct s101_ModuleParserMeta s101_ModuleParserMeta;
typedef struct s102_FileParseResult s102_FileParseResult;
typedef struct s129_StringArena s129_StringArena;
typedef struct s141_Entry s141_Entry;
typedef struct s142_IdentSet s142_IdentSet;
typedef struct s153_Span s153_Span;
typedef struct s154_PrintOptions s154_PrintOptions;
typedef struct s165_Position s165_Position;
typedef struct s166_FileMeta s166_FileMeta;
typedef struct s167_Key s167_Key;
typedef struct s201_UID s201_UID;
typedef struct s213_FlowType s213_FlowType;
typedef struct s214_TypeIdent s214_TypeIdent;
typedef struct s215_CompoundType s215_CompoundType;
typedef struct s216_ArrayType s216_ArrayType;
typedef struct s217_FunctionType s217_FunctionType;
typedef struct s218_TypeIdents s218_TypeIdents;
typedef struct s241_File s241_File;
typedef struct s257_Vec s257_Vec;
typedef struct s275_Path s275_Path;
typedef struct s299_StringBuilder s299_StringBuilder;
typedef struct s300_Node s300_Node;
typedef struct s307_LexerResult s307_LexerResult;
typedef struct s308_Tokens s308_Tokens;
typedef struct s334_Module s334_Module;
typedef struct s335_AstRunResult s335_AstRunResult;
typedef struct s336_IdentEntry s336_IdentEntry;
typedef struct s351_TypecheckContext s351_TypecheckContext;
typedef struct s366_CodegenContext s366_CodegenContext;
typedef struct s376_ModuleImport s376_ModuleImport;
typedef struct s377_ModuleMeta s377_ModuleMeta;
typedef struct s378_SymbolTable s378_SymbolTable;
typedef struct s401_Errors s401_Errors;
typedef struct s402_Error s402_Error;
typedef struct s439_Result s439_Result;
typedef struct s440_Node s440_Node;
typedef struct s441_StringData s441_StringData;
typedef struct s443_ObjectData s443_ObjectData;
typedef struct s444_ArrayData s444_ArrayData;
typedef struct s442_ObjectEntry s442_ObjectEntry;
typedef struct s445_Parser s445_Parser;
typedef struct s446_ParseStringResult s446_ParseStringResult;
typedef struct s461_Request s461_Request;
typedef struct s462_Parser s462_Parser;
typedef struct s466_Context s466_Context;
typedef struct s482_FileMap s482_FileMap;
typedef struct s481_File s481_File;
typedef struct s499_EntryMeta s499_EntryMeta;
typedef struct s500_HashMap s500_HashMap;
typedef struct s501_HashMapIter s501_HashMapIter;
typedef struct s531_TypeIdents s531_TypeIdents;
typedef struct s527_FlowType s527_FlowType;
typedef struct s528_TypeIdent s528_TypeIdent;
typedef struct s529_ArrayType s529_ArrayType;
typedef struct s530_FunctionType s530_FunctionType;
typedef struct s540_Symbol s540_Symbol;
typedef struct s554_PathResult s554_PathResult;
typedef struct s555_FindNextNodeResult s555_FindNextNodeResult;
typedef struct s556_IdentResult s556_IdentResult;
typedef struct s566_Arena s566_Arena;
typedef struct s567_ArenaNode s567_ArenaNode;
typedef struct s576_HashSet s576_HashSet;
typedef struct s575_EntryMeta s575_EntryMeta;
typedef struct s585_Nodes s585_Nodes;
typedef struct s586_TypeData s586_TypeData;
typedef struct s587_Node s587_Node;
typedef struct s603_StringView s603_StringView;
typedef struct s614_Token s614_Token;
typedef struct s647_Lexer s647_Lexer;
typedef struct s648_LexerResult s648_LexerResult;
typedef struct s649_EscapeResult s649_EscapeResult;
typedef struct s662_Declaration s662_Declaration;
typedef struct s663_Function s663_Function;
typedef struct s665_Prototype s665_Prototype;
typedef struct s664_ExternFn s664_ExternFn;
typedef struct s666_Arg s666_Arg;
typedef struct s667_Global s667_Global;
typedef struct s668_ExternGlobal s668_ExternGlobal;
typedef struct s669_Import s669_Import;
typedef struct s670_ObjectDef s670_ObjectDef;
typedef struct s671_ObjectField s671_ObjectField;
typedef struct s672_EnumDef s672_EnumDef;
typedef struct s673_EnumField s673_EnumField;
typedef struct s702_Ast s702_Ast;
typedef struct s712_WorkStack s712_WorkStack;
typedef struct s729_Module s729_Module;
typedef struct s739_Function s739_Function;
typedef struct s741_Prototype s741_Prototype;
typedef struct s740_ExternFn s740_ExternFn;
typedef struct s742_Arg s742_Arg;
typedef struct s743_FunctionContext s743_FunctionContext;
typedef struct s757_ObjectField s757_ObjectField;
typedef struct s758_ObjectDef s758_ObjectDef;
typedef struct s765_EnumField s765_EnumField;
typedef struct s766_EnumDef s766_EnumDef;
typedef struct s771_Global s771_Global;
typedef struct s772_ExternGlobal s772_ExternGlobal;
typedef struct s824_Builder s824_Builder;
typedef struct s846_Nodes s846_Nodes;
typedef struct s844_Node s844_Node;
typedef struct s845_NodeResult s845_NodeResult;
typedef struct s857_Literal s857_Literal;
typedef struct s864_ConstEvalResult s864_ConstEvalResult;
typedef struct s895_Literal s895_Literal;
typedef struct s894_Unary s894_Unary;
typedef struct s893_Binary s893_Binary;
typedef struct s890_Call s890_Call;
typedef struct s889_Array s889_Array;
typedef struct s891_ObjectInit s891_ObjectInit;
typedef struct s888_Cast s888_Cast;
typedef struct s892_ObjectFieldInit s892_ObjectFieldInit;
typedef struct s924_VarDeclaration s924_VarDeclaration;
typedef struct s923_BlockData s923_BlockData;
typedef struct s925_ReturnData s925_ReturnData;
typedef struct s922_IfData s922_IfData;
typedef struct s926_MatchData s926_MatchData;
typedef struct s921_LoopData s921_LoopData;
typedef struct s920_ForData s920_ForData;
typedef struct s927_MatchCase s927_MatchCase;
typedef struct s959_TypeIdentResult s959_TypeIdentResult;
typedef struct s972_InfixOpMap s972_InfixOpMap;
typedef struct s970_InfixPrecedence s970_InfixPrecedence;
typedef struct s971_PrefixOpMap s971_PrefixOpMap;
typedef struct s969_PrefixPrecedence s969_PrefixPrecedence;
typedef struct s984_VarBindings s984_VarBindings;
typedef struct s983_Variable s983_Variable;
typedef struct s985_VarResult s985_VarResult;
typedef struct s995_SizeAndAlign s995_SizeAndAlign;
typedef struct s1018_VarDeclaration s1018_VarDeclaration;
typedef struct s1017_BlockData s1017_BlockData;
typedef struct s1019_ReturnData s1019_ReturnData;
typedef struct s1016_IfData s1016_IfData;
typedef struct s1015_LoopData s1015_LoopData;
typedef struct s1014_ForData s1014_ForData;
typedef struct s1020_VarDeclResult s1020_VarDeclResult;
typedef struct s1028_FunctionContext s1028_FunctionContext;
typedef struct s1039_Binary s1039_Binary;
typedef struct s1040_Assign s1040_Assign;
typedef struct s1051_Unary s1051_Unary;
typedef struct s1065_Variable s1065_Variable;
typedef struct s1064_Call s1064_Call;
typedef struct s1066_EnumValue s1066_EnumValue;
typedef struct s1072_MatchData s1072_MatchData;
typedef struct s1073_MatchCase s1073_MatchCase;
typedef struct s1074_CondValue s1074_CondValue;
typedef struct s1075_MatchContext s1075_MatchContext;
typedef struct s1083_Array s1083_Array;
typedef struct s1084_Index s1084_Index;
typedef struct s1096_ObjectInit s1096_ObjectInit;
typedef struct s1098_FieldLookup s1098_FieldLookup;
typedef struct s1097_ObjectFieldInit s1097_ObjectFieldInit;
typedef struct s1113_Cast s1113_Cast;
typedef struct s1114_ImplicitResult s1114_ImplicitResult;
typedef struct s1153_PathStackResult s1153_PathStackResult;
typedef union s219_TypeData s219_TypeData;
typedef union s447_NodeData s447_NodeData;
typedef union s532_TypeData s532_TypeData;
typedef union s541_ShallowInfo s541_ShallowInfo;
typedef union s542_DeepInfo s542_DeepInfo;
typedef union s588_NodeData s588_NodeData;
typedef union s615_TokenData s615_TokenData;
typedef union s847_NodeData s847_NodeData;
typedef union s858_LiteralValue s858_LiteralValue;
typedef union s865_ConstExpr s865_ConstExpr;
typedef union s896_LiteralValue s896_LiteralValue;

/*  Functions Declarations */
#line 1 "./lib/stdlib.ib"
extern void putchar(int v1_c);
#line 2 "./lib/stdlib.ib"
extern int printf(char * v1_c, ...);
#line 3 "./lib/stdlib.ib"
extern void puts(char * v1_c);
#line 4 "./lib/stdlib.ib"
extern int getchar();
#line 5 "./lib/stdlib.ib"
extern int scanf(char * v1_format, ...);
#line 11 "./lib/stdlib.ib"
extern void * fopen(char * v1_path, char * v2_mode);
#line 12 "./lib/stdlib.ib"
extern int putc(int v1_c, void * v2_stream);
#line 13 "./lib/stdlib.ib"
extern int fputs(char * v1_data, void * v2_file);
#line 14 "./lib/stdlib.ib"
extern u64 fread(void * v1_ptr, u64 v2_size, u64 v3_nmemb, void * v4_stream);
#line 15 "./lib/stdlib.ib"
extern u64 fwrite(void * v1_ptr, u64 v2_size, u64 v3_nmemb, void * v4_stream);
#line 16 "./lib/stdlib.ib"
extern int fprintf(void * v1_stream, char * v2_c, ...);
#line 17 "./lib/stdlib.ib"
extern int fseek(void * v1_stream, u64 v2_offset, s41_FileSeek v3_whence);
#line 18 "./lib/stdlib.ib"
extern int fgetc(void * v1_stream);
#line 19 "./lib/stdlib.ib"
extern int ungetc(int v1_c, void * v2_stream);
#line 20 "./lib/stdlib.ib"
extern u64 ftell(void * v1_stream);
#line 21 "./lib/stdlib.ib"
extern int feof(void * v1_stream);
#line 22 "./lib/stdlib.ib"
extern int ferror(void * v1_stream);
#line 23 "./lib/stdlib.ib"
extern int fclose(void * v1_stream);
#line 24 "./lib/stdlib.ib"
extern int fscanf(void * v1_stream, char * v2_format, ...);
#line 25 "./lib/stdlib.ib"
extern int fflush(void * v1_stream);
#line 33 "./lib/stdlib.ib"
extern void * malloc(u64 v1_size);
#line 34 "./lib/stdlib.ib"
extern void * realloc(void * v1_ptr, u64 v2_size);
#line 35 "./lib/stdlib.ib"
extern void free(void * v1_ptr);
#line 36 "./lib/stdlib.ib"
extern void * memcpy(void * v1_dest, void * v2_src, u64 v3_size);
#line 37 "./lib/stdlib.ib"
extern void * memset(void * v1_ptr, int v2_value, u64 v3_size);
#line 38 "./lib/stdlib.ib"
extern int memcmp(void * v1_left, void * v2_right, u64 v3_size);
#line 40 "./lib/stdlib.ib"
extern int strcmp(char * v1_left, char * v2_right);
#line 41 "./lib/stdlib.ib"
extern int strncmp(char * v1_left, char * v2_right, u64 v3_len);
#line 42 "./lib/stdlib.ib"
extern u64 strlen(char * v1_s);
#line 43 "./lib/stdlib.ib"
extern int snprintf(char * v1_target, u64 v2_n, char * v3_format, ...);
#line 44 "./lib/stdlib.ib"
extern int sprintf(char * v1_target, char * v2_format, ...);
#line 46 "./lib/stdlib.ib"
extern void exit(int v1_status);
#line 47 "./lib/stdlib.ib"
extern void abort();
#line 66 "src/utils/fs.ib"
extern i64 remove(char * v1_file);
int main(int v1_argc, char * * v2_argv);
i64 s2_run();
void s40_assert(bool v1_value, char * v2_message);
void s42_init();
void s43_free();
void s63_parse(i64 v1_argc, char * * v2_argv);
void s64_parse_options(s82_Parser * v1_parser, bool (* v2_parse_fn)(char *));
bool s65_parse_build_arg(char * v1_arg);
bool s66_parse_common_args(char * v1_arg);
bool s67_match_flag(char * v1_arg, char * v2_short, char * v3_long);
bool s68_match_keyval(char * v1_arg, char * v2_key, char * * v3_out);
void s69_print_raw_args(i64 v1_argc, char * * v2_argv);
s83_HelpMode s70_parse_help_mode(s82_Parser * v1_parser);
s84_Mode s71_parse_mode(s82_Parser * v1_parser);
void s72_apply_defaults();
bool s73_has_next(s82_Parser * v1_parser);
char * s74_curr(s82_Parser * v1_parser);
void s75_step(s82_Parser * v1_parser);
void s76_print_args();
void s77_print_mode();
void s78_print_debug_flags();
void s79_print_flag(bool v1_condition, char * v2_label, i64 * v3_enabled_flag_count);
void s80_print_keyval(char * v1_label, char * v2_value);
void s81_print_forward_args();
i64 s86_run();
s100_BuildResult s87_new();
void s88_free(s100_BuildResult * v1_result);
void s89_clear(s100_BuildResult * v1_result);
s100_BuildResult s90_build();
void s91_parse_all(s100_BuildResult * v1_result, char * v2_entry);
void s92_insert_module_imports(s334_Module * v1_module, i64 v2_base_path_idx, s257_Vec * v3_modules_to_parse);
i64 s93_is_queued(s275_Path * v1_canonical_path, s257_Vec * v2_modules_to_parse);
s102_FileParseResult s94_parse_file(char * v1_filename, i64 v2_module, s100_BuildResult * v3_build_result);
s102_FileParseResult s95_parse_file_content(i64 v1_module, char * v2_filename, char * v3_content, i64 v4_length, s100_BuildResult * v5_build_result);
void s96_debug_ast(s334_Module * v1_module);
void s97_typecheck(s100_BuildResult * v1_result);
void s98_debug_typecheck(s729_Module * v1_module);
void s99_codegen(s100_BuildResult * v1_result);
i64 s103_run();
i64 s110_print();
void s111_section(char * v1_label);
void s112_command(char * v1_key, char * v2_desc);
void s113_flag(char * v1_short, char * v2_long, char * v3_desc);
void s114_keyval(char * v1_key, char * v2_val, char * v3_desc);
void s115_option(char * v1_key, char * v2_desc);
i64 s116_run();
void s117_parse_file(s466_Context * v1_context);
s129_StringArena * s123_create_node(i64 v1_capacity);
void s124_init();
char * s125_reserve(i64 v1_length);
char * s126_insert(char * v1_s, i64 v2_length);
void s127_free();
char * s128_debug_reserve(i64 v1_length);
i64 s132_count();
i64 s133_hash(char * v1_s, i64 v2_length);
char * s134_insert(char * v1_identifier, i64 v2_length);
char * s135_find(char * v1_identifier);
void s136_init();
void s137_free();
s141_Entry * s138_find_identifier_entry(char * v1_identifier, i64 v2_length, i64 v3_ident_hash);
void s139_expand();
s141_Entry * s140_find_next_empty_slot(s141_Entry * v1_entries, i64 v2_capacity, i64 v3_hash);
void s144_init();
void s145_free();
s153_Span * s146_get(i64 v1_span);
i64 s147_count();
i64 s148_new(char * v1_file, i64 v2_start, i64 v3_end);
i64 s149_merge(i64 v1_left, i64 v2_right);
void s150_write(s299_StringBuilder * v1_sb, i64 v2_span);
void s151_write_ex(s299_StringBuilder * v1_sb, i64 v2_span, s154_PrintOptions v3_options);
i64 s152_number_width(i64 v1_n);
void s157_init();
void s158_free();
s166_FileMeta * s159_create(char * v1_file, i64 v2_length);
s165_Position s160_find_position(char * v1_file, i64 v2_offset);
s166_FileMeta * s161_get(char * v1_file);
i64 s162_line_start(s166_FileMeta * v1_meta, i64 v2_line);
i64 s163_file_hash(s167_Key v1_key);
bool s164_file_eq(s167_Key v1_left, s167_Key v2_right);
bool s170_is_none(s201_UID v1_uid);
bool s171_eq(s201_UID v1_lhs, s201_UID v2_rhs);
void s172_assert_exists(s201_UID v1_symbol);
void s173_init();
void s174_free();
i64 s175_insert_module(char * v1_module);
s201_UID s176_insert(i64 v1_module, char * v2_name, bool v3_is_public, bool v4_is_extern, s544_SymbolKind v5_kind, i64 v6_span);
void s177_insert_imports(i64 v1_module, s257_Vec * v2_imports);
s201_UID s178_find_symbol(i64 v1_module_uid, char * v2_name);
s377_ModuleMeta * s179_get_module_meta(i64 v1_module);
s376_ModuleImport * s180_get_module_import(s377_ModuleMeta * v1_meta, i64 v2_index);
void s181_attach_shallow(s201_UID v1_symbol, s541_ShallowInfo v2_info);
void s182_attach_deep(s201_UID v1_symbol, s542_DeepInfo v2_info);
s542_DeepInfo s183_get_deep(s201_UID v1_symbol);
s541_ShallowInfo s184_get_shallow(s201_UID v1_symbol);
void s185_set_type(s201_UID v1_symbol, s528_TypeIdent * v2_type);
s528_TypeIdent * s186_get_type(s201_UID v1_symbol);
void s187_set_stage(s201_UID v1_symbol, s543_SymbolStage v2_stage);
bool s188_stage_eq(s201_UID v1_symbol, s543_SymbolStage v2_stage);
void s189_assert_kind(s201_UID v1_symbol, s544_SymbolKind v2_kind, char * v3_message);
s544_SymbolKind s190_kind(s201_UID v1_symbol);
bool s191_is_extern(s201_UID v1_symbol);
bool s192_is_public(s201_UID v1_symbol);
i64 s193_span(s201_UID v1_symbol);
char * s194_name(s201_UID v1_symbol);
void s195_preserve_name(s201_UID v1_symbol);
bool s196_is_preserve_name(s201_UID v1_symbol);
void s197_debug_all();
void s198_debug_all_head();
void s199_debug(s201_UID v1_symbol);
void s200_debug_head(s299_StringBuilder * v1_sb, s201_UID v2_symbol);
s218_TypeIdents s202_new(i64 v1_module_uid);
void s203_free(s218_TypeIdents * v1_type_idents);
s214_TypeIdent * s204_atomic(s218_TypeIdents * v1_type_idents, s222_AtomicType v2_atomic_ty);
s214_TypeIdent * s205_find_or_insert(s218_TypeIdents * v1_type_idents, s214_TypeIdent * v2_type);
bool s206_is_anyptr(s214_TypeIdent * v1_type);
s214_TypeIdent * s207_allocate_typeident(s218_TypeIdents * v1_typeidents, s214_TypeIdent * v2_type);
i64 s208_typeident_hash(s214_TypeIdent * * v1_ident);
bool s209_typeident_eq(s214_TypeIdent * * v1_lhs, s214_TypeIdent * * v2_rhs);
void s210_debug(s299_StringBuilder * v1_sb, s585_Nodes * v2_nodes, s214_TypeIdent * v3_type, i64 v4_depth);
void s211_debug_flowtype(s299_StringBuilder * v1_sb, s585_Nodes * v2_nodes, s213_FlowType * v3_flow_type, i64 v4_depth);
void s212_debug_atomic(s299_StringBuilder * v1_sb, s222_AtomicType v2_atomic);
void s223_append_message(s299_StringBuilder * v1_sb, s226_ErrorKind v2_error);
i64 s224_token_offset(s226_ErrorKind v1_err);
s155_Range s225_span_range(s226_ErrorKind v1_err);
void s227_append_message(s299_StringBuilder * v1_sb, s228_ErrorKind v2_error, char v3_curr);
s241_File s236_read_file(char * v1_file);
bool s237_write_file(char * v1_file, char * v2_content);
void s238_free(s241_File * v1_file);
bool s239_delete_file(char * v1_file);
bool s240_exists(char * v1_file);
bool s242_is_initialized(s257_Vec * v1_vec);
s257_Vec s243_new(i64 v1_item_size, i64 v2_capacity);
s257_Vec s244_new_frozen(i64 v1_item_size, i64 v2_capacity);
i64 s245_index(s257_Vec * v1_vec, i64 v2_i);
i64 s246_free(s257_Vec * v1_vec);
s257_Vec s247_clone(s257_Vec * v1_vec);
void s248_clear(s257_Vec * v1_vec);
void * s249_push(s257_Vec * v1_vec);
void * s250_pop(s257_Vec * v1_vec);
void * s251_get(s257_Vec * v1_vec, i64 v2_idx);
void * s252_last(s257_Vec * v1_vec);
void * s253_push_many(s257_Vec * v1_vec, i64 v2_count);
void s254_append(s257_Vec * v1_vec, s257_Vec * v2_other);
void s255_allocate(s257_Vec * v1_vec, i64 v2_count);
i64 s256_with_alignment(i64 v1_size);
s275_Path s261_new(char * v1_path);
void s262_free(s275_Path * v1_path);
s275_Path s263_join(s275_Path * v1_source, char * v2_relative);
void s264_assert_allocated_count(i64 v1_count);
void s265_print_debug(s275_Path * v1_path);
void s266_build(s275_Path * v1_path, s299_StringBuilder * v2_sb);
char * s267_to_str(s275_Path * v1_path);
s275_Path s268_relative_path(s275_Path * v1_source, char * v2_path);
s275_Path s269_library_path(s275_Path * v1__source, char * v2_path);
s275_Path s270_root_path(s275_Path * v1__source, char * v2_path);
s275_Path s271_build_path(s257_Vec v1_nodes, s603_StringView v2_path);
void s272_append(s257_Vec * v1_nodes, s603_StringView v2_path);
i64 s273_hash(s275_Path * v1_path);
bool s274_eq(s275_Path * v1_lhs, s275_Path * v2_rhs);
s299_StringBuilder s277_new();
void s278_free(s299_StringBuilder * v1_builder);
s299_StringBuilder s279_with_capacity(i64 v1_capacity);
bool s280_ends_with_char(s299_StringBuilder * v1_builder, char v2_c);
void s281_append_escaped_str(s299_StringBuilder * v1_builder, char * v2_content);
void s282_append_hex_escape(s299_StringBuilder * v1_builder, char v2_byte);
void s283_append(s299_StringBuilder * v1_builder, char * v2_content);
void s284_append_char(s299_StringBuilder * v1_builder, char v2_c);
void s285_append_debug(s299_StringBuilder * v1_builder, char * v2_content);
void s286_append_debug_char(s299_StringBuilder * v1_builder, char v2_c);
void s287_append_n(s299_StringBuilder * v1_builder, char * v2_content, i64 v3_length);
void s288_repeat(s299_StringBuilder * v1_builder, char * v2_content, i64 v3_count);
void s289_append_number(s299_StringBuilder * v1_builder, i64 v2_number);
f64 s290_absf(f64 v1_number);
void s291_append_float(s299_StringBuilder * v1_builder, f64 v2_number, i64 v3_precision);
char * s292_reserve(s299_StringBuilder * v1_builder, i64 v2_length);
char * s293_build(s299_StringBuilder * v1_builder);
char * s294_merge(s299_StringBuilder * v1_builder);
void s295_reset(s299_StringBuilder * v1_builder);
void s296_merge_into(s299_StringBuilder * v1_builder, char * v2_target);
s300_Node * s297_allocate_node(i64 v1_capacity);
i64 s298_number_width(i64 v1_n);
s307_LexerResult s301_run(char * v1_filename, char * v2_content, i64 v3_length, s401_Errors * v4_errors);
void s302_free(s308_Tokens * v1_tokens);
void s303_push(s308_Tokens * v1_tokens, s614_Token v2_token);
void s304_print_tokens(s308_Tokens * v1_tokens);
void s305_write_tokens(s299_StringBuilder * v1_sb, s308_Tokens * v2_tokens);
s307_LexerResult s306_fail();
s335_AstRunResult s310_run(char * v1_file, i64 v2_module_uid, s308_Tokens v3_tokens, s401_Errors * v4_errors);
s334_Module s311_new_module(i64 v1_uid);
void s312_free_modules(s257_Vec * v1_modules, bool v2__print_usage);
void s313_free_module(s334_Module * v1_module, bool v2_print_usage);
void s314_debug_declarations(s299_StringBuilder * v1_sb, s334_Module * v2_module, s257_Vec * v3_v, void (* v4_debug_fn)(s299_StringBuilder *, s334_Module *, void *));
void s315_debug_module(s299_StringBuilder * v1_sb, s334_Module * v2_module);
void s316_create_symbols_for_kind(i64 v1_module_uid, s257_Vec * v2_v, s662_Declaration * (* v3_decl_fn)(void *), s544_SymbolKind v4_kind, bool v5_is_extern);
s662_Declaration * s317_func_decl(s663_Function * v1_f);
s662_Declaration * s318_global_decl(s667_Global * v1_g);
s662_Declaration * s319_extfn_decl(s664_ExternFn * v1_e);
s662_Declaration * s320_extglobal_decl(s668_ExternGlobal * v1_e);
s662_Declaration * s321_objdef_decl(s670_ObjectDef * v1_o);
s662_Declaration * s322_enumdef_decl(s672_EnumDef * v1_e);
s662_Declaration * s323_import_decl(s669_Import * v1_i);
s257_Vec * s324_functions(s334_Module * v1_m);
s257_Vec * s325_globals(s334_Module * v1_m);
s257_Vec * s326_extern_fns(s334_Module * v1_m);
s257_Vec * s327_extern_globals(s334_Module * v1_m);
s257_Vec * s328_structs(s334_Module * v1_m);
s257_Vec * s329_unions(s334_Module * v1_m);
s257_Vec * s330_enums(s334_Module * v1_m);
void s331_create_symbols(s334_Module * v1_module);
bool s332_check_name_duplicates_for_kind(s401_Errors * v1_errors, s257_Vec * v2_idents, s257_Vec * v3_v, s662_Declaration * (* v4_decl_fn)(void *));
bool s333_check_name_duplicates(s334_Module * v1_module, s401_Errors * v2_errors);
s351_TypecheckContext s337_context(s401_Errors * v1_errors, s257_Vec * v2_ast_modules, s257_Vec * v3_modules);
void s338_context_free(s351_TypecheckContext * v1_context);
void s339_run(s351_TypecheckContext * v1_context);
void s340_typecheck_declaration_group(s351_TypecheckContext * v1_context, s257_Vec * (* v2_get_decl_vec)(s334_Module *), s662_Declaration * (* v3_decl_fn)(void *), void (* v4_typecheck_fn)(s351_TypecheckContext *, s201_UID));
s257_Vec s341_create_modules(s257_Vec * v1_ast_modules);
void s342_typecheck_symbol(s351_TypecheckContext * v1_context, s201_UID v2_symbol);
void s343_typecheck_symbol_body(s351_TypecheckContext * v1_context, s201_UID v2_symbol);
void s344_start_typechecking(s351_TypecheckContext * v1_context, s201_UID v2_symbol);
void s345_finish_typechecking(s351_TypecheckContext * v1_context, s201_UID v2_symbol);
s334_Module * s346_find_ast_module(s351_TypecheckContext * v1_context, i64 v2_uid);
s729_Module * s347_find_module(s351_TypecheckContext * v1_context, i64 v2_uid);
void s348_debug_declarations(s299_StringBuilder * v1_sb, s729_Module * v2_module, s257_Vec * v3_decls, void (* v4_debug_fn)(s299_StringBuilder *, s729_Module *, void *));
void s349_debug_module(s299_StringBuilder * v1_sb, s729_Module * v2_module);
void s350_free_modules(s257_Vec * v1_modules, bool v2_print_usage);
char * s353_generated_filename(char * v1_outfile);
s366_CodegenContext s354_context(s257_Vec * v1_modules, char * v2_outfile, bool v3_verbose);
void s355_free(s366_CodegenContext * v1_context);
void s356_run(s366_CodegenContext * v1_context);
void s357_codegen_symbol_implementation(s366_CodegenContext * v1_context, s201_UID v2_symbol);
void s358_codegen_group(s366_CodegenContext * v1_context, s257_Vec * (* v2_get_decl_vec)(s729_Module *), s201_UID (* v3_symbol_fn)(void *), void (* v4_codegen_fn)(s366_CodegenContext *, s729_Module *, s201_UID));
void s359_codegen_flush(s366_CodegenContext * v1_context);
void s360_define(s366_CodegenContext * v1_context, char * v2_name, char * v3_value);
void s361_include(s366_CodegenContext * v1_context, char * v2_message);
void s362_comment(s366_CodegenContext * v1_context, char * v2_message);
void s363_sourcemap(s366_CodegenContext * v1_context, i64 v2_span);
void s364_sourcemap_line(s366_CodegenContext * v1_context, i64 v2_span);
void s365_codegen_symbol(s299_StringBuilder * v1_sb, s201_UID v2_symbol);
s378_SymbolTable s367_new();
void s368_free(s378_SymbolTable * v1_table);
s201_UID s369_create_symbol(s378_SymbolTable * v1_table, i64 v2_module, char * v3_name, s544_SymbolKind v4_kind, i64 v5_span, bool v6_is_public, bool v7_is_extern);
s540_Symbol * s370_get_symbol(s378_SymbolTable * v1_table, s201_UID v2_uid);
i64 s371_insert_module(s378_SymbolTable * v1_table, char * v2_module);
void s372_insert_imports(s378_SymbolTable * v1_table, s257_Vec * v2_imports);
s201_UID s373_find_symbol(s378_SymbolTable * v1_table, i64 v2_module_id, char * v3_ident);
void s374_debug(s378_SymbolTable * v1_table);
void s375_debug_heads(s378_SymbolTable * v1_table);
s401_Errors s385_new();
void s386_free(s401_Errors * v1_errors);
void s387_reset(s401_Errors * v1_errors);
s402_Error * s388_push(s401_Errors * v1_errors, char * v2_header, s403_Level v3_level);
s402_Error * s389_lexer_error(s401_Errors * v1_errors);
s402_Error * s390_parser_error(s401_Errors * v1_errors);
s402_Error * s391_type_error(s401_Errors * v1_errors);
s402_Error * s392_type_warn(s401_Errors * v1_errors);
void s393_entry_not_found(s401_Errors * v1_errors);
void s394_file_not_found(s401_Errors * v1_errors, char * v2_file);
void s395_print_errors(s401_Errors * v1_errors);
void s396_write_errors(s299_StringBuilder * v1_sb, s401_Errors * v2_errors, bool v3_use_colors);
void s397_write_all(s299_StringBuilder * v1_sb, s401_Errors * v2_errors, bool v3_use_colors);
void s398_write_n(s299_StringBuilder * v1_sb, s401_Errors * v2_errors, bool v3_use_colors, i64 v4_max_errs);
void s399_write(s299_StringBuilder * v1_sb, s402_Error * v2_err, bool v3_use_colors);
void s400_level_color(s299_StringBuilder * v1_sb, s403_Level v2_level);
void s404_debug_str(char * v1_message);
void s405_debug_char(char v1_chr);
void s406_todo(char * v1_message);
s439_Result s407_parse(char * v1_content, i64 v2_len);
void s408_free(s440_Node * v1_node);
s440_Node * s409_get(s440_Node * v1_node, i64 v2_index);
s440_Node * s410_lookup(s440_Node * v1_node, char * v2_field);
bool s411_as_bool(s440_Node * v1_node);
i64 s412_as_number(s440_Node * v1_node);
char * s413_as_str(s440_Node * v1_node);
i64 s414_length(s440_Node * v1_node);
s448_Status s415_parse_value(s445_Parser * v1_parser, s440_Node * v2_node);
s448_Status s416_parse_number(s445_Parser * v1_parser, s440_Node * v2_node);
s448_Status s417_parse_string_node(s445_Parser * v1_parser, s440_Node * v2_node);
s446_ParseStringResult s418_parse_string(s445_Parser * v1_parser);
s448_Status s419_parse_literal(s445_Parser * v1_parser, s440_Node * v2_node);
s448_Status s420_parse_object(s445_Parser * v1_parser, s440_Node * v2_node);
s448_Status s421_parse_array(s445_Parser * v1_parser, s440_Node * v2_node);
bool s422_match_str(s445_Parser * v1_parser, char * v2_rest);
s448_Status s423_step_unescape(s445_Parser * v1_parser, char * v2_out);
bool s424_is_end(s445_Parser * v1_parser);
void s425_step(s445_Parser * v1_parser);
char s426_curr(s445_Parser * v1_parser);
char s427_peek(s445_Parser * v1_parser, i64 v2_offset);
void s428_whitespace(s445_Parser * v1_parser);
s445_Parser s429_create_parser(char * v1_content, i64 v2_len);
void * s430_allocate_str(s445_Parser * v1_parser, i64 v2_size);
void * s431_head(s445_Parser * v1_parser, i64 v2__size);
void * s432_allocate(s445_Parser * v1_parser, i64 v2_size);
void * s433_push(s445_Parser * v1_parser, i64 v2_size);
void * s434_pop(s445_Parser * v1_parser, i64 v2_size);
i64 s435_with_alignment(i64 v1_size);
i64 s436_estimate_alloca_size(char * v1_content, i64 v2_len, i64 * v3_str_size);
bool s437_is_numeric(char v1_c);
bool s438_is_alpha(char v1_c);
bool s450_has_next(s462_Parser * v1_parser);
bool s451_whitespace(s462_Parser * v1_parser);
s462_Parser s452_new_parser(i64 * v1_log);
void s453_free_parser(s462_Parser * v1_parser);
s461_Request s454_read(s462_Parser * v1_parser);
void s455_free(s461_Request * v1_request);
i64 s456_content_length(s462_Parser * v1_parser);
void s457_clear(s462_Parser * v1_parser, i64 v2_len);
void s458_with_capacity(s462_Parser * v1_parser, i64 v2_capacity);
s463_Method s459_from_str(char * v1_s);
void s460_print(i64 * v1_stream, s461_Request * v2_request);
s466_Context s464_new();
void s465_free(s466_Context * v1_context);
s472_Status s467_handle(s466_Context * v1_context, s461_Request * v2_req);
s472_Status s468_on_initialize(s466_Context * v1__context, s461_Request * v2_req, s824_Builder * v3_res);
s472_Status s469_on_document_open(s466_Context * v1_context, s461_Request * v2_req, s824_Builder * v3__res);
s472_Status s470_on_document_change(s466_Context * v1_context, s461_Request * v2_req, s824_Builder * v3__res);
s472_Status s471_on_document_hover(s466_Context * v1_context, s461_Request * v2_req, s824_Builder * v3_res);
i64 s473_hash(s481_File * v1_file);
bool s474_eq(s481_File * v1_left, s481_File * v2_right);
s482_FileMap s475_new_filemap(i64 * v1_log);
void s476_free_file(s481_File * v1_file);
void s477_free_filemap(s482_FileMap * v1_files);
s481_File s478_temp_file(char * v1_uri, i64 v2_uri_len);
s481_File * s479_find(s482_FileMap * v1_files, char * v2_uri, i64 v3_uri_len);
void s480_update_full(s481_File * v1_file, char * v2_content, i64 v3_length);
void s483_publish(s466_Context * v1_context, s100_BuildResult * v2_result, s824_Builder * v3_res);
void s484_send_error(s466_Context * v1_context, s402_Error * v2_error, s824_Builder * v3_res);
void s485_range(s824_Builder * v1_res, i64 v2_start_line, i64 v3_start_char, i64 v4_end_line, i64 v5_end_char);
s500_HashMap s487_new(i64 v1_key_size, i64 v2_value_size, i64 (* v3_hash_fn)(void *), bool (* v4_eq_fn)(void *, void *));
void * s488_find(s500_HashMap * v1_map, void * v2_key);
void * s489_insert(s500_HashMap * v1_map, void * v2_key, void * v3_value);
void * s490_find_or_insert(s500_HashMap * v1_map, void * v2_key);
void s491_free(s500_HashMap * v1_map);
i64 s492_find_entry_index(s500_HashMap * v1_map, void * v2_key, i64 v3_hash);
void s493_expand(s500_HashMap * v1_map);
i64 s494_find_next_empty_slot_index(s499_EntryMeta * v1_entries, i64 v2_capacity, i64 v3_hash);
s501_HashMapIter s495_iter(s500_HashMap * v1_map);
bool s496_has_next(s501_HashMapIter * v1_iter);
void s497_next(s501_HashMapIter * v1_iter);
i64 s498_with_alignment(i64 v1_size);
s531_TypeIdents s502_new();
void s503_free(s531_TypeIdents * v1_type_idents);
s528_TypeIdent * s504_atomic(s531_TypeIdents * v1_type_idents, s535_AtomicType v2_atomic_ty);
s528_TypeIdent * s505_pointer(s531_TypeIdents * v1_type_idents, s528_TypeIdent * v2_inner);
s528_TypeIdent * s506_compound(s531_TypeIdents * v1_type_idents, s201_UID v2_symbol);
s528_TypeIdent * s507_into_array(s531_TypeIdents * v1_type_idents, s528_TypeIdent * v2_parent, i64 * v3_dimensions, i64 v4_dimension_length);
s527_FlowType s508_typecheck_flowtype(s351_TypecheckContext * v1_context, i64 v2_module, s213_FlowType v3_flow, i64 v4_span);
s528_TypeIdent * s509_typecheck(s351_TypecheckContext * v1_context, i64 v2_module, s214_TypeIdent * v3_type, i64 v4_span);
s528_TypeIdent * s510_typecheck_array(s351_TypecheckContext * v1_context, i64 v2_module, s214_TypeIdent * v3_type, i64 v4_span);
s528_TypeIdent * s511_typecheck_function(s351_TypecheckContext * v1_context, i64 v2_module, s214_TypeIdent * v3_type, i64 v4_span);
s528_TypeIdent * s512_typecheck_compound(s351_TypecheckContext * v1_context, i64 v2_module, s214_TypeIdent * v3_type, i64 v4_span);
s528_TypeIdent * s513_find_or_insert(s531_TypeIdents * v1_type_idents, s528_TypeIdent * v2_type);
bool s514_is_anyptr(s528_TypeIdent * v1_type);
bool s515_is_numeric(s528_TypeIdent * v1_type);
bool s516_is_enum(s528_TypeIdent * v1_type);
bool s517_is_object(s528_TypeIdent * v1_type);
s528_TypeIdent * s518_allocate_typeident(s531_TypeIdents * v1_typeidents, s528_TypeIdent * v2_type);
i64 s519_typeident_hash(s528_TypeIdent * * v1_ident);
bool s520_typeident_eq(s528_TypeIdent * * v1_lhs, s528_TypeIdent * * v2_rhs);
s535_AtomicType s521_ast_atomicty_into_ty(s222_AtomicType v1_from);
bool s522_flowtype_eq(s527_FlowType v1_lhs, s527_FlowType v2_rhs);
void s523_print(s846_Nodes * v1_nodes, s528_TypeIdent * v2_type);
void s524_debug(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, s528_TypeIdent * v3_type, i64 v4_depth);
void s525_debug_flowtype(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, s527_FlowType * v3_flow_type, i64 v4_depth);
void s526_debug_atomic(s299_StringBuilder * v1_sb, s535_AtomicType v2_atomic);
void s536_debug(s540_Symbol * v1_symbol);
void s537_print_ptr(s540_Symbol * v1_symbol);
void s538_debug_ptr(s299_StringBuilder * v1_sb, s540_Symbol * v2_symbol);
void s539_debug_head(s299_StringBuilder * v1_sb, s540_Symbol * v2_symbol);
s554_PathResult s545_path(i64 v1_module_uid, char * * v2_path, i64 v3_path_len);
s554_PathResult s546_path_found(s201_UID v1_symbol);
s554_PathResult s547_path_skipped(s201_UID v1_symbol);
s554_PathResult s548_path_err(s557_PathResultKind v1_kind, i64 v2_not_found_module_index);
s555_FindNextNodeResult s549_path_find_next_node(s377_ModuleMeta * v1_meta, char * v2_alias);
s556_IdentResult s550_identifier(i64 v1_module_uid, char * v2_ident);
s556_IdentResult s551_ident_err(s558_IdentResultKind v1_kind);
s556_IdentResult s552_ident_ok(s201_UID v1_symbol);
s257_Vec s553_collect_identifiers(i64 v1_module_uid, char * v2_ident, i64 v3_count, bool v4_was_public);
s566_Arena s560_new(i64 v1_initial_capacity);
void * s561_allocate(s566_Arena * v1_arena, i64 v2_size);
i64 s562_free(s566_Arena * v1_arena);
s567_ArenaNode * s563_create_node(i64 v1_capacity);
i64 s564_with_alignment(i64 v1_size);
void * s565_debug_allocate(s566_Arena * v1_arena, i64 v2_size);
s576_HashSet s568_new(i64 v1_value_size, i64 (* v2_hash_fn)(void *), bool (* v3_eq_fn)(void *, void *));
void * s569_find(s576_HashSet * v1_set, void * v2_value);
void * s570_find_or_insert(s576_HashSet * v1_set, void * v2_value);
void s571_free(s576_HashSet * v1_set);
i64 s572_find_entry_index(s576_HashSet * v1_set, void * v2_value, i64 v3_hash);
void s573_expand(s576_HashSet * v1_set);
i64 s574_find_next_empty_slot_index(s575_EntryMeta * v1_entries, i64 v2_capacity, i64 v3_hash);
s587_Node * s578_get(s585_Nodes * v1_nodes, i64 v2_index);
i64 s579_push(s585_Nodes * v1_nodes, s589_NodeKind v2_kind);
void * s580_allocate_extra(s585_Nodes * v1_nodes, i64 v2_size);
s585_Nodes s581_new();
void s582_free(s585_Nodes * v1_nodes);
bool s583_is_expression(s585_Nodes * v1_nodes, i64 v2_node);
void s584_debug(s299_StringBuilder * v1_sb, s585_Nodes * v2_nodes, i64 v3_node, i64 v4_depth);
s603_StringView s590_new(char * v1_string, i64 v2_length);
char s591_at(s603_StringView v1_sv, i64 v2_offset);
bool s592_eq_str(s603_StringView v1_sv, char * v2_s);
bool s593_eq(s603_StringView v1_lhs, s603_StringView v2_rhs);
s603_StringView s594_slice(s603_StringView v1_sv, i64 v2_start, i64 v3_end);
s603_StringView s595_drop_left(s603_StringView v1_sv, i64 v2_left);
void s596_print(s603_StringView v1_sv);
void s597_debug(s603_StringView v1_sv);
bool s598_is_empty(s603_StringView v1_sv);
i64 s599_find(s603_StringView v1_sv, char v2_c);
i64 s600_rfind(s603_StringView v1_sv, char v2_c);
s603_StringView s601_from_str(char * v1_string);
char * s602_to_str(s603_StringView v1_sv);
s614_Token s604_new(s616_TokenKind v1_kind);
bool s605_is_eof(s614_Token * v1_token);
s614_Token s606_identifier(char * v1_value);
s614_Token s607_literal_int(i64 v1_value);
s614_Token s608_literal_float(f64 v1_value);
s614_Token s609_literal_string(char * v1_s);
s614_Token s610_literal_char(char v1_c);
void s611_print(s614_Token v1_token);
void s612_fprintf(void * v1_stream, s614_Token v2_token);
void s613_write(s299_StringBuilder * v1_sb, s614_Token v2_token);
s647_Lexer s617_new(char * v1_content, i64 v2_length, s401_Errors * v3_errors, s257_Vec * v4_line_starts);
s648_LexerResult s618_next(s647_Lexer * v1_lexer);
s648_LexerResult s619__next(s647_Lexer * v1_lexer);
s648_LexerResult s620_identifier(s647_Lexer * v1_lexer);
bool s621_consume(s647_Lexer * v1_lexer, char v2_c);
s648_LexerResult s622__char(s647_Lexer * v1_lexer);
s648_LexerResult s623__string(s647_Lexer * v1_lexer);
s649_EscapeResult s624_escape_char_step(s647_Lexer * v1_lexer);
s648_LexerResult s625_number(s647_Lexer * v1_lexer);
i64 s626_number_part(s647_Lexer * v1_lexer);
bool s627_match_str(s647_Lexer * v1_lexer, char * v2_rest);
s616_TokenKind s628_keyword(s647_Lexer * v1_lexer);
s648_LexerResult s629_if_next(s647_Lexer * v1_lexer, char v2_next, s616_TokenKind v3_if_true, s616_TokenKind v4_if_false);
s648_LexerResult s630_simple(s647_Lexer * v1_lexer, s616_TokenKind v2_kind);
bool s631_is_end(s647_Lexer * v1_lexer);
void s632_step(s647_Lexer * v1_lexer);
char s633_curr(s647_Lexer * v1_lexer);
char s634_peek(s647_Lexer * v1_lexer, i64 v2_offset);
void s635_whitespace(s647_Lexer * v1_lexer);
void s636_comment(s647_Lexer * v1_lexer);
void s637_block_comment(s647_Lexer * v1_lexer);
void s638_next_line(s647_Lexer * v1_lexer);
s648_LexerResult s639_ok(s614_Token v1_token);
s648_LexerResult s640_err(s647_Lexer * v1_lexer, s228_ErrorKind v2_kind);
bool s641_is_valid_ident_char(char v1_c);
bool s642_is_alpha(char v1_c);
bool s643_is_numeric(char v1_c);
bool s644_is_hexa(char v1_c);
i64 s645_to_hexa(char v1_c);
void s646_print_status(s647_Lexer * v1_l);
void s650_print_declaration(s662_Declaration * v1_declaration);
void s651_debug_declaration(s299_StringBuilder * v1_sb, s662_Declaration * v2_declaration);
void s652_debug_function(s299_StringBuilder * v1_sb, s334_Module * v2_module, s663_Function * v3_function);
void s653_debug_proto(s299_StringBuilder * v1_sb, s334_Module * v2_module, s665_Prototype * v3_proto);
void s654_debug_import(s299_StringBuilder * v1_sb, s334_Module * v2__module, s669_Import * v3_imp);
void s655_debug_extern_fn(s299_StringBuilder * v1_sb, s334_Module * v2_module, s664_ExternFn * v3_extrn);
void s656_debug_extern_global(s299_StringBuilder * v1_sb, s334_Module * v2_module, s668_ExternGlobal * v3_extrn);
void s657_debug_global(s299_StringBuilder * v1_sb, s334_Module * v2_module, s667_Global * v3_global);
void s658_debug_struct(s299_StringBuilder * v1_sb, s334_Module * v2_module, s670_ObjectDef * v3_obj);
void s659_debug_union(s299_StringBuilder * v1_sb, s334_Module * v2_module, s670_ObjectDef * v3_obj);
void s660_debug_object_def(s299_StringBuilder * v1_sb, s334_Module * v2_module, s670_ObjectDef * v3_obj, char * v4_kind);
void s661_debug_enum(s299_StringBuilder * v1_sb, s334_Module * v2_module, s672_EnumDef * v3_enum_def);
s702_Ast s676_new(s308_Tokens v1_tokens, s334_Module * v2_module, s401_Errors * v3_errors);
void s677_free(s702_Ast * v1_ast);
bool s678_has_next(s702_Ast * v1_ast);
s704_Declaration s679_next(s702_Ast * v1_ast);
i64 s680_declaration(s702_Ast * v1_ast);
bool s681_curr_is_declaration(s702_Ast * v1_ast);
i64 s682_parse_extern(s702_Ast * v1_ast);
i64 s683_parse_import(s702_Ast * v1_ast, bool v2_aliased);
i64 s684_parse_global(s702_Ast * v1_ast, bool v2_mutable);
i64 s685_parse_global_const(s702_Ast * v1_ast);
i64 s686_consume_ident(s702_Ast * v1_ast, char * * v2_result, s226_ErrorKind v3_kind);
i64 s687_error(s702_Ast * v1_ast, s226_ErrorKind v2_kind);
void s688_step(s702_Ast * v1_ast);
s616_TokenKind s689_curr(s702_Ast * v1_ast);
s616_TokenKind s690_peek(s702_Ast * v1_ast, i64 v2_offset);
i64 s691_span_end(s702_Ast * v1_ast, i64 v2_span_start);
i64 s692_curr_span(s702_Ast * v1_ast);
i64 s693_prev_span(s702_Ast * v1_ast);
bool s694_consume(s702_Ast * v1_ast, s616_TokenKind v2_kind);
s614_Token * s695_curr_token(s702_Ast * v1_ast);
i64 s696_node_create(s702_Ast * v1_ast, s589_NodeKind v2_kind);
void * s697_node_data(s702_Ast * v1_ast, i64 v2_node);
i64 s698_node_get_span(s702_Ast * v1_ast, i64 v2_node);
void s699_node_set_span(s702_Ast * v1_ast, i64 v2_node, i64 v3_span);
void s700_work_push(s702_Ast * v1_ast, i64 v2_value);
i64 s701_work_pop(s702_Ast * v1_ast);
void s705_clear(s712_WorkStack * v1_workstack);
void * s706_top(s712_WorkStack * v1_workstack);
void * s707_push(s712_WorkStack * v1_workstack, i64 v2_size);
void * s708_pop(s712_WorkStack * v1_workstack, i64 v2_size);
void * s709_pop_n(s712_WorkStack * v1_workstack, i64 v2_size, i64 v3_count);
void s710_assert_empty(s712_WorkStack * v1_workstack);
void s711_free(s712_WorkStack * v1_workstack);
s729_Module s713_new(s334_Module * v1_source);
void s714_free(s729_Module * v1_module, bool v2_print_usage);
s257_Vec * s715_extern_globals(s729_Module * v1_module);
s257_Vec * s716_extern_fns(s729_Module * v1_module);
s257_Vec * s717_functions(s729_Module * v1_module);
s257_Vec * s718_globals(s729_Module * v1_module);
s257_Vec * s719_structs(s729_Module * v1_module);
s257_Vec * s720_unions(s729_Module * v1_module);
s257_Vec * s721_enums(s729_Module * v1_module);
s201_UID s722_extern_global_symbol(s772_ExternGlobal * v1_extglb);
s201_UID s723_extern_fn_symbol(s740_ExternFn * v1_extfn);
s201_UID s724_function_symbol(s739_Function * v1_func);
s201_UID s725_global_symbol(s771_Global * v1_glb);
s201_UID s726_struct_symbol(s758_ObjectDef * v1_strct);
s201_UID s727_union_symbol(s758_ObjectDef * v1__union);
s201_UID s728_enum_symbol(s766_EnumDef * v1_enums);
s743_FunctionContext s730_create_fn_context(s351_TypecheckContext * v1_parent, i64 v2_module);
void s731_free_fn_context(s743_FunctionContext * v1_context);
void s732_typecheck_function(s351_TypecheckContext * v1_context, s201_UID v2_symbol);
void s733_typecheck_function_head(s351_TypecheckContext * v1_context, s201_UID v2_symbol);
void s734_typecheck_extern(s351_TypecheckContext * v1_context, s201_UID v2_symbol);
s741_Prototype s735_typecheck_prototype(s351_TypecheckContext * v1_context, s201_UID v2__symbol, s665_Prototype * v3_proto, s334_Module * v4_ast_module, s729_Module * v5_module);
void s736_debug(s299_StringBuilder * v1_sb, s729_Module * v2_module, s739_Function * v3_function);
void s737_debug_extern(s299_StringBuilder * v1_sb, s729_Module * v2_module, s740_ExternFn * v3_function);
void s738_debug_proto(s299_StringBuilder * v1_sb, s729_Module * v2_module, s741_Prototype * v3_proto);
s757_ObjectField * s745_get_field(s758_ObjectDef * v1_def, char * v2_field);
i64 s746_get_field_idx(s758_ObjectDef * v1_def, char * v2_field);
void s747_typecheck_struct(s351_TypecheckContext * v1_context, s201_UID v2_symbol);
void s748_struct_alignment(s351_TypecheckContext * v1_context, s758_ObjectDef * v2_def);
void s749_typecheck_union(s351_TypecheckContext * v1_context, s201_UID v2_symbol);
void s750_union_alignment(s351_TypecheckContext * v1_context, s758_ObjectDef * v2_def);
void s751_typecheck_obj_def(s351_TypecheckContext * v1_context, s201_UID v2_symbol, s729_Module * v3_module, s758_ObjectDef * v4_def);
i64 s752_get_aligned_offset(i64 v1_offset, i64 v2_align);
s757_ObjectField * s753_typecheck_fields(s351_TypecheckContext * v1_context, s729_Module * v2_module, s670_ObjectDef * v3_ast_def);
void s754_debug_struct(s299_StringBuilder * v1_sb, s729_Module * v2_module, s758_ObjectDef * v3_obj);
void s755_debug_union(s299_StringBuilder * v1_sb, s729_Module * v2_module, s758_ObjectDef * v3_obj);
void s756_debug_object_def(s299_StringBuilder * v1_sb, s729_Module * v2_module, s758_ObjectDef * v3_obj, char * v4_kind);
i64 s759_field_idx(s766_EnumDef * v1_def, char * v2_key);
void s760_typecheck_def(s351_TypecheckContext * v1_context, s201_UID v2_symbol);
void s761_typecheck_fields(s351_TypecheckContext * v1_context, s201_UID v2_symbol, s729_Module * v3_module, s766_EnumDef * v4_def);
i64 s762_max_value_into_size(i64 v1_max_value);
void s763_eval_enum_value(s743_FunctionContext * v1_context, i64 v2_node, i64 * v3_value);
void s764_debug_enum(s299_StringBuilder * v1_sb, s729_Module * v2__module, s766_EnumDef * v3_enum_def);
void s767_typecheck(s351_TypecheckContext * v1_context, s201_UID v2_symbol);
void s768_typecheck_extern(s351_TypecheckContext * v1_context, s201_UID v2_symbol);
void s769_debug_extern_global(s299_StringBuilder * v1_sb, s729_Module * v2_module, s772_ExternGlobal * v3_extrn);
void s770_debug_global(s299_StringBuilder * v1_sb, s729_Module * v2_module, s771_Global * v3_global);
i64 s773_todo(s351_TypecheckContext * v1_context, i64 v2_span, char * v3_message);
i64 s774_error(s351_TypecheckContext * v1_context, s781_ErrorKind v2_kind, i64 v3_span);
void s775_object_missing_field(s351_TypecheckContext * v1_context, char * v2_field, i64 v3_span);
void s776_cyclic_dependency(s351_TypecheckContext * v1_context, s201_UID v2_symbol);
void s777_warn_unused_variable(s351_TypecheckContext * v1_context, i64 v2_span);
void s778__error(s351_TypecheckContext * v1_context, i64 v2_span);
void s779__warn(s351_TypecheckContext * v1_context, i64 v2_span);
void s780_append_message(s299_StringBuilder * v1_sb, s781_ErrorKind v2_error);
void s782_declaration(s366_CodegenContext * v1_context, s729_Module * v2__module, s201_UID v3_symbol);
void s783_implementation(s366_CodegenContext * v1_context, s729_Module * v2__module, s201_UID v3_symbol);
void s784_implement_field(s366_CodegenContext * v1_context, s757_ObjectField * v2_field);
void s785_declaration(s366_CodegenContext * v1_context, s729_Module * v2__module, s201_UID v3_symbol);
void s786_implementation(s366_CodegenContext * v1_context, s729_Module * v2__module, s201_UID v3_symbol);
void s787_implement_field(s366_CodegenContext * v1_context, s201_UID v2_symbol, s765_EnumField * v3_field);
void s788_variant(s366_CodegenContext * v1_context, s201_UID v2_symbol, s765_EnumField * v3_field);
void s789_declarations(s366_CodegenContext * v1_context);
void s790_codegen_field(s366_CodegenContext * v1_context, s528_TypeIdent * v2_type, char * v3_ident);
void s791_codegen(s366_CodegenContext * v1_context, s528_TypeIdent * v2_type);
void s792__codegen(s366_CodegenContext * v1_context, s528_TypeIdent * v2_type, char * v3_ident);
void s793_atomic(s366_CodegenContext * v1_context, s535_AtomicType v2_atomic);
void s794_func(s366_CodegenContext * v1_context, s530_FunctionType v2_func);
void s795_func_flow_type(s366_CodegenContext * v1_context, s527_FlowType v2_flow);
void s796_declaration(s366_CodegenContext * v1_context, s729_Module * v2_module, s201_UID v3_symbol);
void s797_implementation(s366_CodegenContext * v1_context, s729_Module * v2_module, s201_UID v3_symbol);
void s798_prototype(s366_CodegenContext * v1_context, s729_Module * v2_module, s201_UID v3_symbol, s741_Prototype * v4_proto);
void s799_flow_type(s366_CodegenContext * v1_context, s527_FlowType v2_flow, char * v3_ident);
void s800_declaration(s366_CodegenContext * v1_context, s729_Module * v2__module, s201_UID v3_symbol);
void s801_implementation(s366_CodegenContext * v1_context, s729_Module * v2_module, s201_UID v3_symbol);
s824_Builder s802_new(i64 * v1_log);
void s803_free(s824_Builder * v1_builder);
void s804_send(s824_Builder * v1_builder);
void s805_key(s824_Builder * v1_builder, char * v2_name);
void s806_id(s824_Builder * v1_builder, i64 v2_value);
void s807_begin_result(s824_Builder * v1_builder);
void s808_end_result(s824_Builder * v1_builder);
void s809_method(s824_Builder * v1_builder, char * v2_method);
void s810_begin_params(s824_Builder * v1_builder);
void s811_end_params(s824_Builder * v1_builder);
void s812_begin(s824_Builder * v1_builder);
void s813_end(s824_Builder * v1_builder);
void s814_sep(s824_Builder * v1_builder);
void s815_begin_object(s824_Builder * v1_builder);
void s816_end_object(s824_Builder * v1_builder);
void s817_begin_array(s824_Builder * v1_builder);
void s818_end_array(s824_Builder * v1_builder);
void s819_nil(s824_Builder * v1_builder);
void s820_boolean(s824_Builder * v1_builder, bool v2_value);
void s821_string(s824_Builder * v1_builder, char * v2_s);
void s822_number(s824_Builder * v1_builder, i64 v2_num);
void s823_raw(s824_Builder * v1_builder, char * v2_s);
s845_NodeResult s827_typecheck(s743_FunctionContext * v1_context, i64 v2_node);
s845_NodeResult s828_some(i64 v1_node);
s845_NodeResult s829_result(i64 v1_node, s850_NodeFlow v2_flow);
void s830_assert_nodeflow_sort();
s850_NodeFlow s831_flow_from_typeident(s527_FlowType v1_type);
s850_NodeFlow s832_flow_any(s850_NodeFlow v1_lhs, s850_NodeFlow v2_rhs);
s850_NodeFlow s833_flow_all(s850_NodeFlow v1_lhs, s850_NodeFlow v2_rhs);
s846_Nodes s834_new();
void s835_free(s846_Nodes * v1_nodes);
s844_Node * s836_get(s846_Nodes * v1_nodes, i64 v2_index);
s844_Node * s837_try_get(s846_Nodes * v1_nodes, i64 v2_index);
i64 s838_push_simple(s846_Nodes * v1_nodes, s848_NodeKind v2_kind, i64 v3_span);
i64 s839_push(s846_Nodes * v1_nodes, s848_NodeKind v2_kind, s528_TypeIdent * v3_ty, s847_NodeData v4_data, i64 v5_span);
void * s840_allocate_extra(s846_Nodes * v1_nodes, i64 v2_size);
void s841_print(s846_Nodes * v1_nodes, i64 v2_node);
void s842_debug(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, i64 v3_node, i64 v4_depth);
void s843_debug_simple(s299_StringBuilder * v1_sb, char * v2_label, i64 v3_depth);
i64 s851_typecheck(s743_FunctionContext * v1_context, s895_Literal v2_data, i64 v3_span);
s857_Literal s852_from_ast_literal(s895_Literal v1_data);
s857_Literal s853_from_int(i64 v1_number);
i64 s854_into_int(s857_Literal v1_literal, bool * v2_is_ok);
s528_TypeIdent * s855_into_typeident(s351_TypecheckContext * v1_context, s895_Literal v2_data);
void s856_debug(s299_StringBuilder * v1_sb, s857_Literal * v2_literal, i64 v3_depth);
s864_ConstEvalResult s860_eval(s743_FunctionContext * v1_context, i64 v2_expr);
s864_ConstEvalResult s861_eval_unary(s743_FunctionContext * v1_context, s1051_Unary * v2_unary);
s864_ConstEvalResult s862_some(s865_ConstExpr v1_expr);
s864_ConstEvalResult s863_error();
i64 s866_array_get(s889_Array * v1_array, i64 v2_index);
i64 s867_parse(s702_Ast * v1_ast);
i64 s868_parse_expr_prec(s702_Ast * v1_ast, i64 v2_min_prec);
i64 s869_parse_cast(s702_Ast * v1_ast, i64 v2_lhs);
i64 s870_parse_call(s702_Ast * v1_ast, i64 v2_callee);
i64 s871_binary(s702_Ast * v1_ast, s897_BinaryOp v2_op, i64 v3_lhs, i64 v4_rhs);
i64 s872_unary(s702_Ast * v1_ast, s898_UnaryOp v2_op, i64 v3_expr, i64 v4_span_start);
i64 s873_parse_prefix_op(s702_Ast * v1_ast);
i64 s874_primary(s702_Ast * v1_ast);
i64 s875_parse_array_init(s702_Ast * v1_ast);
i64 s876_parse_sizeof(s702_Ast * v1_ast);
i64 s877_parse_ident(s702_Ast * v1_ast);
i64 s878_literal(s702_Ast * v1_ast, s899_LiteralKind v2_kind);
i64 s879_literal_bool(s702_Ast * v1_ast, bool v2_value);
void s880_debug_call(s299_StringBuilder * v1_sb, s585_Nodes * v2_nodes, s890_Call * v3_call, i64 v4_depth);
void s881_debug_unary(s299_StringBuilder * v1_sb, s585_Nodes * v2_nodes, s894_Unary * v3_unary, i64 v4_depth);
void s882_debug_binary(s299_StringBuilder * v1_sb, s585_Nodes * v2_nodes, s893_Binary * v3_binary, i64 v4_depth);
void s883_debug_literal(s299_StringBuilder * v1_sb, s895_Literal * v2_literal, i64 v3_depth);
void s884_debug_sizeof(s299_StringBuilder * v1_sb, s585_Nodes * v2_nodes, s586_TypeData * v3_size_of, i64 v4_depth);
void s885_debug_object_init(s299_StringBuilder * v1_sb, s585_Nodes * v2_nodes, s891_ObjectInit * v3_obj_init, i64 v4_depth);
void s886_debug_array(s299_StringBuilder * v1_sb, s585_Nodes * v2_nodes, s889_Array * v3_array, i64 v4_depth);
void s887_debug_cast(s299_StringBuilder * v1_sb, s585_Nodes * v2_nodes, s888_Cast * v3_cast, i64 v4_depth);
i64 s900_parse(s702_Ast * v1_ast);
i64 s901_parse_var_dec(s702_Ast * v1_ast, bool v2_mutable);
i64 s902_parse_block(s702_Ast * v1_ast);
i64 s903_parse_return(s702_Ast * v1_ast);
i64 s904_parse_if(s702_Ast * v1_ast);
i64 s905_parse_loop(s702_Ast * v1_ast);
i64 s906_parse_for(s702_Ast * v1_ast);
i64 s907_parse_while(s702_Ast * v1_ast);
i64 s908_parse_match(s702_Ast * v1_ast);
bool s909_parse_match_cond(s702_Ast * v1_ast, s927_MatchCase * v2_case);
bool s910_match_identifier(s702_Ast * v1_ast, char * v2_string);
i64 s911_parse_simple_statement(s702_Ast * v1_ast, s589_NodeKind v2_kind);
i64 s912_block_get(s923_BlockData * v1_block, i64 v2_index);
void s913_debug_var_decl(s299_StringBuilder * v1_sb, s585_Nodes * v2_nodes, bool v3_mutable, s924_VarDeclaration * v4_var_decl, i64 v5_depth);
void s914_debug_block(s299_StringBuilder * v1_sb, s585_Nodes * v2_nodes, s923_BlockData * v3_block, i64 v4_depth);
void s915_debug_if(s299_StringBuilder * v1_sb, s585_Nodes * v2_nodes, s922_IfData * v3_if_data, i64 v4_depth);
void s916_debug_return(s299_StringBuilder * v1_sb, s585_Nodes * v2_nodes, s925_ReturnData * v3_return_data, i64 v4_depth);
void s917_debug_loop(s299_StringBuilder * v1_sb, s585_Nodes * v2_nodes, s921_LoopData * v3_loop_data, i64 v4_depth);
void s918_debug_for(s299_StringBuilder * v1_sb, s585_Nodes * v2_nodes, s920_ForData * * v3_for_data, i64 v4_depth);
void s919_debug_match(s299_StringBuilder * v1_sb, s585_Nodes * v2_nodes, s926_MatchData * v3_match_data, i64 v4_depth);
i64 s928_parse_enum(s702_Ast * v1_ast);
i64 s929_parse_enum_fields(s702_Ast * v1_ast, s672_EnumDef * v2_enum_def);
i64 s930_parse_struct(s702_Ast * v1_ast);
i64 s931_parse_union(s702_Ast * v1_ast);
i64 s932_parse_object_def(s702_Ast * v1_ast, s670_ObjectDef * v2_obj_def);
i64 s933_parse_object_fields(s702_Ast * v1_ast, i64 * v2_count);
i64 s934_parse_object_init(s702_Ast * v1_ast);
i64 s935_parse_object_field_inits(s702_Ast * v1_ast, i64 * v2_field_count);
i64 s936_parse(s702_Ast * v1_ast);
i64 s937_parse_prototype(s702_Ast * v1_ast, s665_Prototype * v2_proto);
i64 s938_parse_prototype_args(s702_Ast * v1_ast, s665_Prototype * v2_proto);
void s939_recover_from_error(s702_Ast * v1_ast, s226_ErrorKind v2_kind);
void s940_skip_until(s702_Ast * v1_ast, s950_RecoveryResult (* v2_pred)(s616_TokenKind));
void s941_skip_until_object_field_end(s702_Ast * v1_ast);
s950_RecoveryResult s942_semicolon_recovery(s616_TokenKind v1_token);
s950_RecoveryResult s943_statement_recovery(s616_TokenKind v1_token);
s950_RecoveryResult s944_next_block_recovery(s616_TokenKind v1_token);
s950_RecoveryResult s945_object_recovery(s616_TokenKind v1_token);
s950_RecoveryResult s946_var_decl_recovery(s616_TokenKind v1_token);
s950_RecoveryResult s947_proto_arg_recovery(s616_TokenKind v1_token);
s950_RecoveryResult s948_proto_flow_recovery(s616_TokenKind v1_token);
s950_RecoveryResult s949_shared_recovery(s616_TokenKind v1_token);
s959_TypeIdentResult s951_parse(s702_Ast * v1_ast);
void s952_parse_fn_typeident(s702_Ast * v1_ast, s959_TypeIdentResult * v2_result);
i64 s953_parse_flowtype(s702_Ast * v1_ast, s213_FlowType * v2_flow_type, i64 * v3_span);
void s954_parse_array_dimensions(s702_Ast * v1_ast, s959_TypeIdentResult * v2_result);
void s955_parse_compound_typeident(s702_Ast * v1_ast, s959_TypeIdentResult * v2_result);
void s956_parse_pointer_typeident(s702_Ast * v1_ast, s959_TypeIdentResult * v2_result);
void s957_parse_str_typeident(s702_Ast * v1_ast, s959_TypeIdentResult * v2_result);
void s958_parse_atomic_typeident(s702_Ast * v1_ast, s959_TypeIdentResult * v2_result);
s969_PrefixPrecedence * s961_get_prefix(s971_PrefixOpMap * v1_map, s616_TokenKind v2_op);
s970_InfixPrecedence * s962_get_infix(s972_InfixOpMap * v1_map, s616_TokenKind v2_op);
void s963_infix_set_disabled(s972_InfixOpMap * v1_map, s616_TokenKind v2_op, bool v3_disabled);
s971_PrefixOpMap s964_default_prefix();
s972_InfixOpMap s965_default_infix();
s969_PrefixPrecedence * s966_add_prefix(s971_PrefixOpMap * v1_map, s616_TokenKind v2_token, i64 v3_prec, s898_UnaryOp v4_op);
s970_InfixPrecedence * s967_add_infix(s972_InfixOpMap * v1_map, s616_TokenKind v2_token, i64 v3_prec, i64 v4_new_prec, s897_BinaryOp v5_op);
s970_InfixPrecedence * s968_add_infix_ex(s972_InfixOpMap * v1_map, s616_TokenKind v2_token, i64 v3_prec, i64 v4_new_prec, s973_RHSKind v5_rhs);
s984_VarBindings s974_new();
void s975_free(s984_VarBindings * v1_binds);
void s976_start(s984_VarBindings * v1_binds);
void s977_end(s984_VarBindings * v1_binds, s351_TypecheckContext * v2_context);
void s978_assert_no_blocks(s984_VarBindings * v1_binds);
i64 s979_insert(s984_VarBindings * v1_binds, char * v2_key, s528_TypeIdent * v3_ty, bool v4_mutable, i64 v5_span);
i64 s980_insert_error(s984_VarBindings * v1_binds, char * v2_key, s528_TypeIdent * v3_ty, bool v4_mutable, i64 v5_span);
s985_VarResult s981_get(s984_VarBindings * v1_binds, char * v2_key);
void s982_print(s984_VarBindings * v1_binds);
s995_SizeAndAlign s987_typeident(s351_TypecheckContext * v1_context, s528_TypeIdent * v2_ty);
s995_SizeAndAlign s988_symbol(s351_TypecheckContext * v1_context, s201_UID v2_symbol);
s995_SizeAndAlign s989_atomic(s535_AtomicType v1_atomic);
s995_SizeAndAlign s990_global(s351_TypecheckContext * v1_context, s201_UID v2_symbol);
s995_SizeAndAlign s991__enum(s766_EnumDef * v1_def);
s995_SizeAndAlign s992_object(s758_ObjectDef * v1_def);
s995_SizeAndAlign s993_new(i64 v1_size, i64 v2_align);
void s994_debug(s299_StringBuilder * v1_sb, i64 v2_size, i64 v3_align);
s845_NodeResult s996_typecheck_block(s743_FunctionContext * v1_context, s923_BlockData v2_data, i64 v3_span);
s845_NodeResult s997_typecheck_vardecl_statement(s743_FunctionContext * v1_context, s924_VarDeclaration v2_data, bool v3_mutable, i64 v4_span);
s1020_VarDeclResult s998_typecheck_vardecl(s743_FunctionContext * v1_context, char * v2__ident, i64 v3_ident_span, s214_TypeIdent * v4_ast_type, i64 v5_type_span, i64 v6_ast_value, bool v7__mutable, i64 v8__span);
i64 s999_insert_binding(s743_FunctionContext * v1_context, char * v2_ident, s528_TypeIdent * v3_type, bool v4_mutable, bool v5_had_error, i64 v6_ident_span);
s845_NodeResult s1000_typecheck_return(s743_FunctionContext * v1_context, s925_ReturnData v2_data, i64 v3_span);
i64 s1001_typecheck_condition(s743_FunctionContext * v1_context, i64 v2_ast_cond, s781_ErrorKind v3_err_kind);
s845_NodeResult s1002_typecheck_if(s743_FunctionContext * v1_context, s922_IfData v2_data, i64 v3_span);
s845_NodeResult s1003_typecheck_loop(s743_FunctionContext * v1_context, s921_LoopData v2_data, i64 v3_span);
s845_NodeResult s1004_typecheck_for(s743_FunctionContext * v1_context, s920_ForData * v2_data, i64 v3_span);
s845_NodeResult s1005_typecheck_break(s743_FunctionContext * v1_context, i64 v2_span);
s845_NodeResult s1006_typecheck_continue(s743_FunctionContext * v1_context, i64 v2_span);
i64 s1007_block_get(s1017_BlockData * v1_block, i64 v2_index);
void s1008_debug_block(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, s1017_BlockData * v3_block, i64 v4_depth);
void s1009_debug_var_decl(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, bool v3_mutable, s1018_VarDeclaration * v4_data, i64 v5_depth);
void s1010_debug_if(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, s1016_IfData * v3_if_data, i64 v4_depth);
void s1011_debug_loop(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, s1015_LoopData * v3_loop_data, i64 v4_depth);
void s1012_debug_return(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, s1019_ReturnData * v3_return_data, i64 v4_depth);
void s1013_debug_for(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, s1014_ForData * * v3_for_data, i64 v4_depth);
s1028_FunctionContext s1021_create_context(s366_CodegenContext * v1_parent, s729_Module * v2_module);
void s1022_free_context(s1028_FunctionContext * v1_context);
s848_NodeKind s1023_nodekind(s1028_FunctionContext * v1_context, i64 v2_node);
void s1024_codegen(s1028_FunctionContext * v1_context, i64 v2_node);
void s1025_indent(s1028_FunctionContext * v1_context);
void s1026_variable(s299_StringBuilder * v1_sb, i64 v2_var_id, char * v3_ident);
bool s1027_is_expr(s1028_FunctionContext * v1_context, i64 v2_node);
i64 s1029_typecheck(s743_FunctionContext * v1_context, s893_Binary v2_data, i64 v3_span);
i64 s1030_assign(s743_FunctionContext * v1_context, s893_Binary v2_data, s1042_AssignOp v3_op, i64 v4_span);
i64 s1031_arith(s743_FunctionContext * v1_context, s893_Binary v2_data, i64 v3_span);
i64 s1032_pred(s743_FunctionContext * v1_context, s893_Binary v2_data, i64 v3_span);
i64 s1033_pred_bool(s743_FunctionContext * v1_context, s893_Binary v2_data, i64 v3_span);
i64 s1034_bit_op(s743_FunctionContext * v1_context, s893_Binary v2_data, i64 v3_span);
i64 s1035_basic(s743_FunctionContext * v1_context, s893_Binary v2_data, i64 v3_span);
s1041_BinaryOp s1036_from_ast_op(s897_BinaryOp v1_op);
void s1037_debug(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, s1039_Binary * v3_binary, i64 v4_depth);
void s1038_debug_assign(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, s1040_Assign * v3_assign, i64 v4_depth);
s845_NodeResult s1043_typecheck(s743_FunctionContext * v1_context, s894_Unary v2_data, i64 v3_span);
s845_NodeResult s1044_into_ref(s743_FunctionContext * v1_context, i64 v2_expr, i64 v3_span);
s845_NodeResult s1045_into_deref(s743_FunctionContext * v1_context, i64 v2_expr, i64 v3_span);
s845_NodeResult s1046_unary_arith(s743_FunctionContext * v1_context, i64 v2_expr, s1052_UnaryOp v3_op, i64 v4_span);
s845_NodeResult s1047_unary_not(s743_FunctionContext * v1_context, i64 v2_expr, i64 v3_span);
void s1048_debug_unary(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, s1051_Unary * v3_unary, i64 v4_depth);
void s1049_debug_deref(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, i64 * v3_expr, i64 v4_depth);
void s1050_debug_ref(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, i64 * v3_expr, i64 v4_depth);
s845_NodeResult s1053_typecheck_call(s743_FunctionContext * v1_context, s890_Call v2_data, i64 v3_span);
i64 s1054_typecheck_ident(s743_FunctionContext * v1_context, char * v2_ident, i64 v3_span);
i64 s1055_typecheck_sizeof(s743_FunctionContext * v1_context, s586_TypeData v2_data, i64 v3_span);
i64 s1056_load_expr(s743_FunctionContext * v1_context, i64 v2_expr);
i64 s1057_autoderef(s743_FunctionContext * v1_context, i64 v2_expr);
void s1058_debug_variable(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, s1065_Variable * v3_var, s528_TypeIdent * v4_ty, i64 v5_depth);
void s1059_debug_symbol(s299_StringBuilder * v1_sb, s846_Nodes * v2__nodes, s201_UID * v3_symbol, i64 v4_depth);
void s1060_debug_call(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, s1064_Call * v3_call, i64 v4_depth);
void s1061_debug_enum_val(s299_StringBuilder * v1_sb, s846_Nodes * v2__nodes, s1066_EnumValue * v3_enum_val, i64 v4_depth);
void s1062_debug_load(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, i64 * v3_expr, i64 v4_depth);
void s1063_debug_object_copy(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, i64 * v3_expr, i64 v4_depth);
s845_NodeResult s1067_typecheck(s743_FunctionContext * v1_context, s926_MatchData v2_data, i64 v3_span);
void s1068_typecheck_arm(s743_FunctionContext * v1_context, s927_MatchCase * v2_case, i64 v3_case_idx, s1072_MatchData * v4_data, s1075_MatchContext * v5_match_context, i64 v6_span);
void s1069_typecheck_arm_condition(s743_FunctionContext * v1_context, i64 v2_node, s1075_MatchContext * v3_match_context);
i64 s1070_typecheck_condition(s743_FunctionContext * v1_context, i64 v2_ast_cond);
void s1071_debug(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, s1072_MatchData * v3_match_data, i64 v4_depth);
i64 s1076_typecheck(s743_FunctionContext * v1_context, s889_Array v2_data, i64 v3_span);
i64 s1077_typecheck_index(s743_FunctionContext * v1_context, s893_Binary v2_data, i64 v3_span);
bool s1078_is_index_type(s528_TypeIdent * v1_type);
s528_TypeIdent * s1079_find_array_type(s743_FunctionContext * v1_context, i64 * v2_elems, i64 v3_count, i64 v4_span);
void s1080_debug_array(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, s1083_Array * v3_array, i64 v4_depth);
i64 s1081_array_get(s1083_Array * v1_array, i64 v2_index);
void s1082_debug_index(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, s1084_Index * v3_index, i64 v4_depth);
i64 s1085_typecheck_objectinit(s743_FunctionContext * v1_context, s891_ObjectInit v2_data, i64 v3_span);
void s1086_typecheck_struct_init(s743_FunctionContext * v1_context, s1096_ObjectInit * v2_init, i64 v3_span);
void s1087_typecheck_union_init(s743_FunctionContext * v1_context, s1096_ObjectInit * v2_init, i64 v3_span);
s1096_ObjectInit s1088_object_init(s743_FunctionContext * v1_context, s891_ObjectInit v2_data, i64 v3_span);
i64 s1089_typecheck_field_lookup(s743_FunctionContext * v1_context, s893_Binary v2_data, i64 v3_span);
void s1090_debug_struct_init(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, s1096_ObjectInit * v3_obj_init, i64 v4_depth);
void s1091_debug_union_init(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, s1096_ObjectInit * v3_obj_init, i64 v4_depth);
void s1092_debug_init(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, s1096_ObjectInit * v3_obj_init, i64 v4_depth, char * v5_key);
void s1093_debug_struct_lookup(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, s1098_FieldLookup * v3_lookup, i64 v4_depth);
void s1094_debug_union_lookup(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, s1098_FieldLookup * v3_lookup, i64 v4_depth);
void s1095_debug_lookup(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, s1098_FieldLookup * v3_lookup, i64 v4_depth, char * v5_key);
i64 s1100_explicit(s743_FunctionContext * v1_context, s888_Cast v2_data, i64 v3_span);
i64 s1101_implicit(s743_FunctionContext * v1_context, i64 v2_expr, s528_TypeIdent * v3_into, bool * v4_res_ok);
s1115_CastMethod s1102_cast_method(s528_TypeIdent * v1_from, s528_TypeIdent * v2_into, bool v3_is_explicit, bool * v4_res_ok);
s1115_CastMethod s1103_try_cast_enum(s528_TypeIdent * v1_from, bool v2_is_from_enum, s528_TypeIdent * v3_into, bool v4_is_into_enum, bool v5_is_explicit, bool * v6_res_ok);
s1115_CastMethod s1104_try_cast_atomic(s535_AtomicType v1_from, s535_AtomicType v2_into, bool v3__is_explicit, bool * v4_res_ok);
s528_TypeIdent * s1105_shared_type(s528_TypeIdent * v1_lhs, s528_TypeIdent * v2_rhs);
s528_TypeIdent * s1106_shared_atomic(s528_TypeIdent * v1_lhs, s528_TypeIdent * v2_rhs);
bool s1107_is_float(s535_AtomicType v1_atomic);
bool s1108_is_int(s535_AtomicType v1_atomic);
bool s1109_is_uint(s535_AtomicType v1_atomic);
bool s1110_is_sint(s535_AtomicType v1_atomic);
i64 s1111_atomic_bits(s535_AtomicType v1_atomic);
void s1112_debug(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, s1113_Cast * v3_cast, i64 v4_depth);
void s1116_semicolon(s1028_FunctionContext * v1_context);
void s1117_block(s1028_FunctionContext * v1_context, s1017_BlockData * v2_data);
void s1118_vardecl(s1028_FunctionContext * v1_context, s1018_VarDeclaration * v2_data);
void s1119__break(s1028_FunctionContext * v1_context);
void s1120__continue(s1028_FunctionContext * v1_context);
void s1121__return(s1028_FunctionContext * v1_context, s1019_ReturnData * v2_data);
void s1122__if(s1028_FunctionContext * v1_context, s1016_IfData * v2_data);
void s1123__match(s1028_FunctionContext * v1_context, s1072_MatchData * v2_data);
void s1124__loop(s1028_FunctionContext * v1_context, s1015_LoopData * v2_data);
void s1125__for(s1028_FunctionContext * v1_context, s1014_ForData * v2_data);
void s1126_top_loop_label(s1028_FunctionContext * v1_context);
void s1127_loop_label(s1028_FunctionContext * v1_context, i64 v2_id);
i64 s1128_push_loop(s1028_FunctionContext * v1_context);
void s1129_pop_loop(s1028_FunctionContext * v1_context, i64 v2_id);
void s1130_binary(s1028_FunctionContext * v1_context, s1039_Binary * v2_data);
void s1131_binary_op(s1028_FunctionContext * v1_context, s1041_BinaryOp v2_op);
void s1132_assign(s1028_FunctionContext * v1_context, s1040_Assign * v2_data);
void s1133_assign_op(s1028_FunctionContext * v1_context, s1042_AssignOp v2_op);
void s1134_unary(s1028_FunctionContext * v1_context, s1051_Unary * v2_data);
void s1135_unary_op(s1028_FunctionContext * v1_context, s1052_UnaryOp v2_op);
void s1136_codegen(s1028_FunctionContext * v1_context, s857_Literal * v2_data);
void s1137_suffix(s1028_FunctionContext * v1_context, s859_LiteralKind v2_kind);
void s1138_variable(s1028_FunctionContext * v1_context, s1065_Variable * v2_data);
void s1139_cast(s1028_FunctionContext * v1_context, s1113_Cast * v2_data);
void s1140_array(s1028_FunctionContext * v1_context, s1083_Array * v2_data);
void s1141_index(s1028_FunctionContext * v1_context, s1084_Index * v2_data);
void s1142_objectinit(s1028_FunctionContext * v1_context, s1096_ObjectInit * v2_data);
void s1143_fieldlookup(s1028_FunctionContext * v1_context, s1098_FieldLookup * v2_data);
void s1144_enumvalue(s1028_FunctionContext * v1_context, s1066_EnumValue * v2_data);
void s1145_call(s1028_FunctionContext * v1_context, s1064_Call * v2_data);
void s1146_ref(s1028_FunctionContext * v1_context, i64 v2_data);
void s1147_deref(s1028_FunctionContext * v1_context, i64 v2_data);
i64 s1148_typecheck(s743_FunctionContext * v1_context, s893_Binary v2_data, i64 v3_span);
i64 s1149_recursive_path(s743_FunctionContext * v1_context, i64 v2_node, i64 v3_span);
s201_UID s1150_resolve_path_symbol(s743_FunctionContext * v1_context, char * v2_ident, i64 v3_span);
i64 s1151_resolve_path_node(s743_FunctionContext * v1_context, char * v2_ident, i64 v3_span);
s1153_PathStackResult s1152_resolve_path_stack(s743_FunctionContext * v1_context, char * v2_ident, i64 v3_span);

/*  Object Definitions */
#line 27 "./lib/stdlib.ib"
enum s41_FileSeek {
	#line 28
	s41_FileSeek_Start = 0,
	#line 29
	s41_FileSeek_Current = 1,
	#line 30
	s41_FileSeek_End = 2,
};

#line 25 "src/args.ib"
enum s83_HelpMode {
	#line 26
	s83_HelpMode_Default = 0,
	#line 27
	s83_HelpMode_Developer = 1,
};

#line 31 "src/args.ib"
enum s84_Mode {
	#line 32
	s84_Mode_Build = 0,
	#line 33
	s84_Mode_Run = 1,
	#line 34
	s84_Mode_Script = 2,
	#line 35
	s84_Mode_Lsp = 3,
	#line 36
	s84_Mode_Help = 4,
};

#line 69 "src/storage/span.ib"
enum s155_Range {
	#line 69
	s155_Range_Full = 0,
	#line 69
	s155_Range_Start = 1,
	#line 69
	s155_Range_End = 2,
};

#line 12 "src/ast/typeident.ib"
enum s220_FlowTypeKind {
	#line 12
	s220_FlowTypeKind_Void = 0,
	#line 12
	s220_FlowTypeKind_Some = 1,
	#line 12
	s220_FlowTypeKind_Never = 2,
};

#line 24 "src/ast/typeident.ib"
enum s221_TypeKind {
	#line 25
	s221_TypeKind_Atomic = 0,
	#line 26
	s221_TypeKind_Pointer = 1,
	#line 27
	s221_TypeKind_Compound = 2,
	#line 28
	s221_TypeKind_Array = 3,
	#line 29
	s221_TypeKind_Function = 4,
};

#line 45 "src/ast/typeident.ib"
enum s222_AtomicType {
	#line 46
	s222_AtomicType_Bool = 0,
	#line 48
	s222_AtomicType_U8 = 1,
	#line 48
	s222_AtomicType_U16 = 2,
	#line 48
	s222_AtomicType_U32 = 3,
	#line 48
	s222_AtomicType_U64 = 4,
	#line 48
	s222_AtomicType_U128 = 5,
	#line 49
	s222_AtomicType_I8 = 6,
	#line 49
	s222_AtomicType_I16 = 7,
	#line 49
	s222_AtomicType_I32 = 8,
	#line 49
	s222_AtomicType_I64 = 9,
	#line 49
	s222_AtomicType_I128 = 10,
	#line 51
	s222_AtomicType_F32 = 11,
	#line 51
	s222_AtomicType_F64 = 12,
};

#line 8 "src/ast/error.ib"
enum s226_ErrorKind {
	#line 9
	s226_ErrorKind_DuplicateSymbol = 0,
	#line 12
	s226_ErrorKind_UnterminatedBlock = 1,
	#line 13
	s226_ErrorKind_UnterminatedParen = 2,
	#line 14
	s226_ErrorKind_UnterminatedBracket = 3,
	#line 17
	s226_ErrorKind_SemicolonExpected = 4,
	#line 18
	s226_ErrorKind_BlockExpected = 5,
	#line 19
	s226_ErrorKind_CommaExpected = 6,
	#line 20
	s226_ErrorKind_InvalidPrimary = 7,
	#line 21
	s226_ErrorKind_IdentifierExpected = 8,
	#line 24
	s226_ErrorKind_VarDeclEqExpected = 9,
	#line 25
	s226_ErrorKind_SizeOfMissingParenL = 10,
	#line 26
	s226_ErrorKind_SizeOfMissingParenR = 11,
	#line 29
	s226_ErrorKind_DuplicatePubForDeclaration = 12,
	#line 30
	s226_ErrorKind_UnknownDeclaration = 13,
	#line 33
	s226_ErrorKind_ImportCannotBePublic = 14,
	#line 34
	s226_ErrorKind_ImportAliasEqExpected = 15,
	#line 35
	s226_ErrorKind_ImportPathExpected = 16,
	#line 36
	s226_ErrorKind_ImportAliasExpected = 17,
	#line 39
	s226_ErrorKind_InvalidExtern = 18,
	#line 40
	s226_ErrorKind_GlobalNameExpected = 19,
	#line 41
	s226_ErrorKind_ExternGlobalNameExpected = 20,
	#line 44
	s226_ErrorKind_PrototypeParenLExpected = 21,
	#line 45
	s226_ErrorKind_PrototypeArgsAfterVarargsNotAllowed = 22,
	#line 46
	s226_ErrorKind_PrototypeNameExpected = 23,
	#line 47
	s226_ErrorKind_PrototypeArgExpected = 24,
	#line 48
	s226_ErrorKind_PrototypeParenRExpected = 25,
	#line 51
	s226_ErrorKind_InvalidTypeIdent = 26,
	#line 52
	s226_ErrorKind_MissingTypeIdent = 27,
	#line 53
	s226_ErrorKind_TypeIdentPathExpected = 28,
	#line 54
	s226_ErrorKind_TypeIdentExpected = 29,
	#line 55
	s226_ErrorKind_TypeIdentArrayBracketRExpected = 30,
	#line 56
	s226_ErrorKind_TypeIdentFnParenExpected = 31,
	#line 57
	s226_ErrorKind_TypeIdentFnFlowTypeRequired = 32,
	#line 60
	s226_ErrorKind_ObjectDefNameExpected = 33,
	#line 61
	s226_ErrorKind_ObjectDefFieldExpected = 34,
	#line 62
	s226_ErrorKind_ObjectDefColonExpected = 35,
	#line 63
	s226_ErrorKind_ObjectDefBraceLExpected = 36,
	#line 64
	s226_ErrorKind_ObjectDefCommaExpected = 37,
	#line 65
	s226_ErrorKind_ObjectInitFieldExpected = 38,
	#line 66
	s226_ErrorKind_ObjectInitCommaExpected = 39,
	#line 67
	s226_ErrorKind_ObjectInitNameExpected = 40,
	#line 70
	s226_ErrorKind_EnumDefNameExpected = 41,
	#line 71
	s226_ErrorKind_EnumDefFieldExpected = 42,
	#line 72
	s226_ErrorKind_EnumDefBraceLExpected = 43,
	#line 73
	s226_ErrorKind_EnumDefCommaExpected = 44,
	#line 76
	s226_ErrorKind_MissingMatchArrow = 45,
	#line 77
	s226_ErrorKind_DuplicateDefaultMatchCase = 46,
};

#line 9 "src/lexer/error.ib"
enum s228_ErrorKind {
	#line 10
	s228_ErrorKind_UnexpectedToken = 0,
	#line 11
	s228_ErrorKind_UnterminatedChar = 1,
	#line 12
	s228_ErrorKind_UnterminatedString = 2,
	#line 13
	s228_ErrorKind_UnknownCharacterEscape = 3,
	#line 14
	s228_ErrorKind_InvalidHexaEscape = 4,
	#line 15
	s228_ErrorKind_EmptyCharLiteral = 5,
	#line 16
	s228_ErrorKind_NumberMultipleFractionPart = 6,
};

#line 8 "src/storage/error.ib"
enum s403_Level {
	#line 9
	s403_Level_Error = 0,
	#line 10
	s403_Level_Warn = 1,
	#line 11
	s403_Level_Info = 2,
};

#line 4 "src/lsp/json.ib"
enum s448_Status {
	#line 5
	s448_Status_Ok = 0,
	#line 6
	s448_Status_UnknownValue = 1,
	#line 7
	s448_Status_UnknownEscape = 2,
	#line 8
	s448_Status_UnterminatedString = 3,
	#line 9
	s448_Status_ExpectedComma = 4,
	#line 10
	s448_Status_ExpectedColon = 5,
};

#line 81 "src/lsp/json.ib"
enum s449_NodeType {
	#line 82
	s449_NodeType_Null = 0,
	#line 83
	s449_NodeType_String = 1,
	#line 84
	s449_NodeType_Bool = 2,
	#line 85
	s449_NodeType_Number = 3,
	#line 86
	s449_NodeType_Object = 4,
	#line 87
	s449_NodeType_Array = 5,
};

#line 12 "src/lsp/request.ib"
enum s463_Method {
	#line 13
	s463_Method_None = 0,
	#line 16
	s463_Method_Initialize = 1,
	#line 17
	s463_Method_Initialized = 2,
	#line 18
	s463_Method_Shutdown = 3,
	#line 19
	s463_Method_Exit = 4,
	#line 22
	s463_Method_TextDocumentDidOpen = 5,
	#line 23
	s463_Method_TextDocumentDidChange = 6,
	#line 24
	s463_Method_TextDocumentDidSave = 7,
	#line 25
	s463_Method_TextDocumentDidClose = 8,
	#line 28
	s463_Method_TextDocumentHover = 9,
	#line 31
	s463_Method_TextDocumentDocumentSymbol = 10,
};

#line 9 "src/lsp/handler.ib"
enum s472_Status {
	#line 10
	s472_Status_Ok = 0,
	#line 11
	s472_Status_Unhandled = 1,
	#line 12
	s472_Status_Skipped = 2,
	#line 13
	s472_Status_Exit = 3,
};

#line 21 "src/typecheck/typeident.ib"
enum s533_FlowTypeKind {
	#line 21
	s533_FlowTypeKind_Void = 0,
	#line 21
	s533_FlowTypeKind_Some = 1,
	#line 21
	s533_FlowTypeKind_Never = 2,
};

#line 34 "src/typecheck/typeident.ib"
enum s534_TypeKind {
	#line 35
	s534_TypeKind_Atomic = 0,
	#line 36
	s534_TypeKind_Pointer = 1,
	#line 37
	s534_TypeKind_Compound = 2,
	#line 38
	s534_TypeKind_Array = 3,
	#line 39
	s534_TypeKind_Function = 4,
};

#line 56 "src/typecheck/typeident.ib"
enum s535_AtomicType {
	#line 57
	s535_AtomicType_Bool = 0,
	#line 59
	s535_AtomicType_U8 = 1,
	#line 59
	s535_AtomicType_U16 = 2,
	#line 59
	s535_AtomicType_U32 = 3,
	#line 59
	s535_AtomicType_U64 = 4,
	#line 59
	s535_AtomicType_U128 = 5,
	#line 60
	s535_AtomicType_I8 = 6,
	#line 60
	s535_AtomicType_I16 = 7,
	#line 60
	s535_AtomicType_I32 = 8,
	#line 60
	s535_AtomicType_I64 = 9,
	#line 60
	s535_AtomicType_I128 = 10,
	#line 62
	s535_AtomicType_F32 = 11,
	#line 62
	s535_AtomicType_F64 = 12,
};

#line 12 "src/symbol/symbol.ib"
enum s543_SymbolStage {
	#line 13
	s543_SymbolStage_Declared = 0,
	#line 14
	s543_SymbolStage_SymbolResolved = 1,
	#line 15
	s543_SymbolStage_TypecheckInProgress = 2,
	#line 16
	s543_SymbolStage_Typechecked = 3,
	#line 17
	s543_SymbolStage_ImplementationEmitted = 4,
};

#line 21 "src/symbol/symbol.ib"
enum s544_SymbolKind {
	#line 22
	s544_SymbolKind_Struct = 0,
	#line 23
	s544_SymbolKind_Union = 1,
	#line 24
	s544_SymbolKind_Enum = 2,
	#line 25
	s544_SymbolKind_Global = 3,
	#line 26
	s544_SymbolKind_Function = 4,
};

#line 8 "src/symbol/resolve.ib"
enum s557_PathResultKind {
	#line 9
	s557_PathResultKind_Found = 0,
	#line 10
	s557_PathResultKind_SkippedName = 1,
	#line 11
	s557_PathResultKind_ErrSymbolWasPrivate = 2,
	#line 12
	s557_PathResultKind_ErrSymbolNotFound = 3,
	#line 13
	s557_PathResultKind_ErrModuleNotFound = 4,
	#line 14
	s557_PathResultKind_ErrModuleWasPrivate = 5,
};

#line 144 "src/symbol/resolve.ib"
enum s558_IdentResultKind {
	#line 145
	s558_IdentResultKind_Found = 0,
	#line 146
	s558_IdentResultKind_ErrFoundMultiple = 1,
	#line 147
	s558_IdentResultKind_ErrSymbolNotFound = 2,
	#line 148
	s558_IdentResultKind_ErrSymbolWasPrivate = 3,
	#line 149
	s558_IdentResultKind_ErrFoundMultiplePrivate = 4,
};

#line 51 "src/ast/node.ib"
enum s589_NodeKind {
	#line 52
	s589_NodeKind_None = 0,
	#line 55
	s589_NodeKind_Literal = 1,
	#line 55
	s589_NodeKind_Ident = 2,
	#line 56
	s589_NodeKind_Binary = 3,
	#line 56
	s589_NodeKind_Unary = 4,
	#line 56
	s589_NodeKind_Cast = 5,
	#line 57
	s589_NodeKind_Array = 6,
	#line 57
	s589_NodeKind_ObjectInit = 7,
	#line 58
	s589_NodeKind_Call = 8,
	#line 59
	s589_NodeKind_SizeOf = 9,
	#line 62
	s589_NodeKind_Block = 10,
	#line 63
	s589_NodeKind_ConstDecl = 11,
	#line 63
	s589_NodeKind_VarDecl = 12,
	#line 64
	s589_NodeKind_Break = 13,
	#line 64
	s589_NodeKind_Continue = 14,
	#line 64
	s589_NodeKind_Return = 15,
	#line 65
	s589_NodeKind_If = 16,
	#line 65
	s589_NodeKind_Match = 17,
	#line 66
	s589_NodeKind_Loop = 18,
	#line 66
	s589_NodeKind_For = 19,
};

#line 5 "src/lexer/token.ib"
enum s616_TokenKind {
	#line 6
	s616_TokenKind_None = 0,
	#line 8
	s616_TokenKind_ParenL = 1,
	#line 8
	s616_TokenKind_ParenR = 2,
	#line 9
	s616_TokenKind_BraceL = 3,
	#line 9
	s616_TokenKind_BraceR = 4,
	#line 10
	s616_TokenKind_BracketL = 5,
	#line 10
	s616_TokenKind_BracketR = 6,
	#line 12
	s616_TokenKind_Comma = 7,
	#line 12
	s616_TokenKind_Colon = 8,
	#line 12
	s616_TokenKind_ColonColon = 9,
	#line 13
	s616_TokenKind_Dot = 10,
	#line 13
	s616_TokenKind_DotDotDot = 11,
	#line 13
	s616_TokenKind_SemiColon = 12,
	#line 15
	s616_TokenKind_Minus = 13,
	#line 15
	s616_TokenKind_Plus = 14,
	#line 15
	s616_TokenKind_Percent = 15,
	#line 15
	s616_TokenKind_Slash = 16,
	#line 15
	s616_TokenKind_Star = 17,
	#line 16
	s616_TokenKind_PlusEq = 18,
	#line 16
	s616_TokenKind_MinusEq = 19,
	#line 16
	s616_TokenKind_SlashEq = 20,
	#line 16
	s616_TokenKind_PercentEq = 21,
	#line 16
	s616_TokenKind_StarEq = 22,
	#line 18
	s616_TokenKind_Pipe = 23,
	#line 18
	s616_TokenKind_Amp = 24,
	#line 18
	s616_TokenKind_And = 25,
	#line 18
	s616_TokenKind_Or = 26,
	#line 19
	s616_TokenKind_Equal = 27,
	#line 19
	s616_TokenKind_EqEq = 28,
	#line 20
	s616_TokenKind_Bang = 29,
	#line 20
	s616_TokenKind_BangEqual = 30,
	#line 21
	s616_TokenKind_GTGT = 31,
	#line 21
	s616_TokenKind_LTLT = 32,
	#line 22
	s616_TokenKind_Caret = 33,
	#line 22
	s616_TokenKind_Tilde = 34,
	#line 24
	s616_TokenKind_LiteralInt = 35,
	#line 25
	s616_TokenKind_LiteralFloat = 36,
	#line 26
	s616_TokenKind_LiteralString = 37,
	#line 27
	s616_TokenKind_LiteralChar = 38,
	#line 28
	s616_TokenKind_Ident = 39,
	#line 30
	s616_TokenKind_LT = 40,
	#line 30
	s616_TokenKind_LE = 41,
	#line 30
	s616_TokenKind_GT = 42,
	#line 30
	s616_TokenKind_GE = 43,
	#line 31
	s616_TokenKind_FatArrow = 44,
	#line 34
	s616_TokenKind_Fn = 45,
	#line 34
	s616_TokenKind_Extern = 46,
	#line 35
	s616_TokenKind_Null = 47,
	#line 35
	s616_TokenKind_True = 48,
	#line 35
	s616_TokenKind_False = 49,
	#line 36
	s616_TokenKind_Let = 50,
	#line 36
	s616_TokenKind_Const = 51,
	#line 37
	s616_TokenKind_If = 52,
	#line 37
	s616_TokenKind_Else = 53,
	#line 38
	s616_TokenKind_While = 54,
	#line 38
	s616_TokenKind_Loop = 55,
	#line 38
	s616_TokenKind_For = 56,
	#line 39
	s616_TokenKind_Break = 57,
	#line 39
	s616_TokenKind_Continue = 58,
	#line 40
	s616_TokenKind_Match = 59,
	#line 41
	s616_TokenKind_Return = 60,
	#line 43
	s616_TokenKind_Import = 61,
	#line 44
	s616_TokenKind_Pub = 62,
	#line 46
	s616_TokenKind_SizeOf = 63,
	#line 47
	s616_TokenKind_As = 64,
	#line 49
	s616_TokenKind_Struct = 65,
	#line 49
	s616_TokenKind_Union = 66,
	#line 49
	s616_TokenKind_Enum = 67,
	#line 51
	s616_TokenKind_Bool = 68,
	#line 51
	s616_TokenKind_Any = 69,
	#line 51
	s616_TokenKind_String = 70,
	#line 52
	s616_TokenKind_Char = 71,
	#line 52
	s616_TokenKind_U8 = 72,
	#line 52
	s616_TokenKind_U16 = 73,
	#line 52
	s616_TokenKind_U32 = 74,
	#line 52
	s616_TokenKind_U64 = 75,
	#line 52
	s616_TokenKind_U128 = 76,
	#line 53
	s616_TokenKind_Int = 77,
	#line 53
	s616_TokenKind_I8 = 78,
	#line 53
	s616_TokenKind_I16 = 79,
	#line 53
	s616_TokenKind_I32 = 80,
	#line 53
	s616_TokenKind_I64 = 81,
	#line 53
	s616_TokenKind_I128 = 82,
	#line 54
	s616_TokenKind_Float = 83,
	#line 54
	s616_TokenKind_F32 = 84,
	#line 54
	s616_TokenKind_F64 = 85,
	#line 55
	s616_TokenKind_Void = 86,
	#line 57
	s616_TokenKind_EOF = 87,
};

#line 50 "src/ast/ast.ib"
enum s703_TypeIdentContext {
	#line 51
	s703_TypeIdentContext_ObjectDef = 0,
	#line 52
	s703_TypeIdentContext_VarDeclaration = 1,
	#line 53
	s703_TypeIdentContext_ProtoArgs = 2,
	#line 54
	s703_TypeIdentContext_ProtoFlowType = 3,
	#line 55
	s703_TypeIdentContext_SizeOf = 4,
	#line 56
	s703_TypeIdentContext_Cast = 5,
};

#line 90 "src/ast/ast.ib"
enum s704_Declaration {
	#line 91
	s704_Declaration_Error = -1,
	#line 92
	s704_Declaration_Function = 0,
	#line 93
	s704_Declaration_ExternFn = 1,
	#line 94
	s704_Declaration_ExternGlobal = 2,
	#line 95
	s704_Declaration_Struct = 3,
	#line 96
	s704_Declaration_Union = 4,
	#line 97
	s704_Declaration_Enum = 5,
	#line 98
	s704_Declaration_Global = 6,
	#line 99
	s704_Declaration_Import = 7,
};

#line 13 "src/typecheck/error.ib"
enum s781_ErrorKind {
	#line 14
	s781_ErrorKind_UnknownError = 0,
	#line 15
	s781_ErrorKind_ConstEvalNotSupported = 1,
	#line 18
	s781_ErrorKind_VariableNotFound = 2,
	#line 19
	s781_ErrorKind_CallNotFunction = 3,
	#line 20
	s781_ErrorKind_CallArgCountIncorrect = 4,
	#line 21
	s781_ErrorKind_CallArgTypeNotMatched = 5,
	#line 22
	s781_ErrorKind_AssignTypeMismatch = 6,
	#line 23
	s781_ErrorKind_BinaryTypeMismatch = 7,
	#line 24
	s781_ErrorKind_InvalidCast = 8,
	#line 25
	s781_ErrorKind_DerefAnyPtr = 9,
	#line 26
	s781_ErrorKind_DerefNonPointer = 10,
	#line 27
	s781_ErrorKind_UnaryNotBoolExpected = 11,
	#line 28
	s781_ErrorKind_UnaryNumericExpected = 12,
	#line 29
	s781_ErrorKind_InvalidPathElement = 13,
	#line 31
	s781_ErrorKind_ArrayTargetTypeWasNotArray = 14,
	#line 32
	s781_ErrorKind_ArrayWasEmptyWithoutTargetType = 15,
	#line 33
	s781_ErrorKind_IndexAnyPtr = 16,
	#line 34
	s781_ErrorKind_ExprCannotBeIndexed = 17,
	#line 35
	s781_ErrorKind_IndexWasNotInteger = 18,
	#line 37
	s781_ErrorKind_PathModuleNotFound = 19,
	#line 38
	s781_ErrorKind_PathModuleWasPrivate = 20,
	#line 39
	s781_ErrorKind_PathSymbolNotFound = 21,
	#line 40
	s781_ErrorKind_PathSymbolWasPrivate = 22,
	#line 41
	s781_ErrorKind_PathEnumExpected = 23,
	#line 43
	s781_ErrorKind_IdentFoundMultiple = 24,
	#line 44
	s781_ErrorKind_IdentSymbolNotFound = 25,
	#line 45
	s781_ErrorKind_IdentSymbolWasPrivate = 26,
	#line 46
	s781_ErrorKind_IdentFoundMultiplePrivate = 27,
	#line 50
	s781_ErrorKind_TypeIdentSkippedName = 28,
	#line 51
	s781_ErrorKind_TypeIdentModuleNotFound = 29,
	#line 52
	s781_ErrorKind_TypeIdentModuleWasPrivate = 30,
	#line 53
	s781_ErrorKind_TypeIdentSymbolNotFound = 31,
	#line 54
	s781_ErrorKind_TypeIdentSymbolWasPrivate = 32,
	#line 56
	s781_ErrorKind_DuplicateObjectField = 33,
	#line 57
	s781_ErrorKind_UndefinedObjectField = 34,
	#line 58
	s781_ErrorKind_SymbolCannotBeConstructed = 35,
	#line 59
	s781_ErrorKind_UnknownSymbolForObjectInit = 36,
	#line 60
	s781_ErrorKind_ObjectInitFieldTypeMismatch = 37,
	#line 61
	s781_ErrorKind_ObjectFieldWasNotIdentifier = 38,
	#line 62
	s781_ErrorKind_ObjectExpected = 39,
	#line 63
	s781_ErrorKind_ObjectFieldNotFound = 40,
	#line 64
	s781_ErrorKind_UnionInitOnlyOneFieldAllowed = 41,
	#line 66
	s781_ErrorKind_EnumDuplicateField = 42,
	#line 67
	s781_ErrorKind_EnumFieldWasNotNumber = 43,
	#line 69
	s781_ErrorKind_GotEnumVariantWhenSymbolWasExpected = 44,
	#line 71
	s781_ErrorKind_MatchInvalidCond = 45,
	#line 72
	s781_ErrorKind_MatchMultipleDefaultCase = 46,
	#line 73
	s781_ErrorKind_MatchMultipleValue = 47,
	#line 74
	s781_ErrorKind_MatchMissingDefaultCase = 48,
	#line 77
	s781_ErrorKind_VarDeclTypeMismatch = 49,
	#line 78
	s781_ErrorKind_VarDeclValueFlowWasNotSome = 50,
	#line 79
	s781_ErrorKind_IfCondNotBool = 51,
	#line 80
	s781_ErrorKind_LoopCondNotBool = 52,
	#line 83
	s781_ErrorKind_ReturnSomeExpected = 53,
	#line 84
	s781_ErrorKind_ReturnVoidExpected = 54,
	#line 85
	s781_ErrorKind_ReturnNeverExpected = 55,
	#line 86
	s781_ErrorKind_ReturnTypeMismatch = 56,
	#line 87
	s781_ErrorKind_BreakOutsideLoop = 57,
	#line 88
	s781_ErrorKind_ContinueOutsideLoop = 58,
	#line 90
	s781_ErrorKind_FunctionInvalidFlow = 59,
};

#line 32 "src/typecheck/node.ib"
enum s848_NodeKind {
	#line 33
	s848_NodeKind_None = 0,
	#line 36
	s848_NodeKind_Literal = 1,
	#line 36
	s848_NodeKind_Variable = 2,
	#line 37
	s848_NodeKind_Binary = 3,
	#line 37
	s848_NodeKind_Unary = 4,
	#line 37
	s848_NodeKind_Cast = 5,
	#line 38
	s848_NodeKind_Assign = 6,
	#line 39
	s848_NodeKind_Array = 7,
	#line 39
	s848_NodeKind_Index = 8,
	#line 40
	s848_NodeKind_StructInit = 9,
	#line 40
	s848_NodeKind_StructFieldLookup = 10,
	#line 41
	s848_NodeKind_UnionInit = 11,
	#line 41
	s848_NodeKind_UnionFieldLookup = 12,
	#line 42
	s848_NodeKind_EnumValue = 13,
	#line 43
	s848_NodeKind_Call = 14,
	#line 46
	s848_NodeKind_Ref = 15,
	#line 46
	s848_NodeKind_Deref = 16,
	#line 47
	s848_NodeKind_Load = 17,
	#line 47
	s848_NodeKind_ObjectCopy = 18,
	#line 50
	s848_NodeKind_Block = 19,
	#line 51
	s848_NodeKind_ConstDecl = 20,
	#line 51
	s848_NodeKind_VarDecl = 21,
	#line 51
	s848_NodeKind_Symbol = 22,
	#line 52
	s848_NodeKind_Break = 23,
	#line 52
	s848_NodeKind_Continue = 24,
	#line 52
	s848_NodeKind_Return = 25,
	#line 53
	s848_NodeKind_If = 26,
	#line 53
	s848_NodeKind_Match = 27,
	#line 54
	s848_NodeKind_Loop = 28,
	#line 54
	s848_NodeKind_For = 29,
};

#line 98 "src/typecheck/node.ib"
enum s849_ValueKind {
	#line 99
	s849_ValueKind_RValue = 0,
	#line 100
	s849_ValueKind_LValue = 1,
};

#line 104 "src/typecheck/node.ib"
enum s850_NodeFlow {
	#line 104
	s850_NodeFlow_Some = 0,
	#line 104
	s850_NodeFlow_Continue = 1,
	#line 104
	s850_NodeFlow_Break = 2,
	#line 104
	s850_NodeFlow_Return = 3,
	#line 104
	s850_NodeFlow_Never = 4,
};

#line 20 "src/typecheck/literal.ib"
enum s859_LiteralKind {
	#line 21
	s859_LiteralKind_Bool = 0,
	#line 21
	s859_LiteralKind_Null = 1,
	#line 23
	s859_LiteralKind_U8 = 2,
	#line 23
	s859_LiteralKind_U16 = 3,
	#line 23
	s859_LiteralKind_U32 = 4,
	#line 23
	s859_LiteralKind_U64 = 5,
	#line 23
	s859_LiteralKind_U128 = 6,
	#line 24
	s859_LiteralKind_I8 = 7,
	#line 24
	s859_LiteralKind_I16 = 8,
	#line 24
	s859_LiteralKind_I32 = 9,
	#line 24
	s859_LiteralKind_I64 = 10,
	#line 24
	s859_LiteralKind_I128 = 11,
	#line 26
	s859_LiteralKind_F32 = 12,
	#line 26
	s859_LiteralKind_F64 = 13,
	#line 28
	s859_LiteralKind_String = 14,
};

#line 53 "src/ast/expr.ib"
enum s897_BinaryOp {
	#line 54
	s897_BinaryOp_None = 0,
	#line 55
	s897_BinaryOp_Add = 1,
	#line 55
	s897_BinaryOp_Sub = 2,
	#line 56
	s897_BinaryOp_Mul = 3,
	#line 56
	s897_BinaryOp_Div = 4,
	#line 56
	s897_BinaryOp_Rem = 5,
	#line 58
	s897_BinaryOp_Assign = 6,
	#line 59
	s897_BinaryOp_AssignAdd = 7,
	#line 59
	s897_BinaryOp_AssignSub = 8,
	#line 60
	s897_BinaryOp_AssignMul = 9,
	#line 60
	s897_BinaryOp_AssignDiv = 10,
	#line 60
	s897_BinaryOp_AssignRem = 11,
	#line 62
	s897_BinaryOp_EQ = 12,
	#line 62
	s897_BinaryOp_NE = 13,
	#line 63
	s897_BinaryOp_GT = 14,
	#line 63
	s897_BinaryOp_GE = 15,
	#line 64
	s897_BinaryOp_LT = 16,
	#line 64
	s897_BinaryOp_LE = 17,
	#line 65
	s897_BinaryOp_And = 18,
	#line 65
	s897_BinaryOp_Or = 19,
	#line 67
	s897_BinaryOp_BitAnd = 20,
	#line 67
	s897_BinaryOp_BitOr = 21,
	#line 67
	s897_BinaryOp_BitXor = 22,
	#line 68
	s897_BinaryOp_BitShiftRight = 23,
	#line 68
	s897_BinaryOp_BitShiftLeft = 24,
	#line 70
	s897_BinaryOp_Index = 25,
	#line 72
	s897_BinaryOp_FieldLookup = 26,
	#line 73
	s897_BinaryOp_Path = 27,
};

#line 83 "src/ast/expr.ib"
enum s898_UnaryOp {
	#line 84
	s898_UnaryOp_Group = 0,
	#line 85
	s898_UnaryOp_Ref = 1,
	#line 86
	s898_UnaryOp_Deref = 2,
	#line 87
	s898_UnaryOp_Pos = 3,
	#line 88
	s898_UnaryOp_Neg = 4,
	#line 89
	s898_UnaryOp_Not = 5,
	#line 90
	s898_UnaryOp_BitNot = 6,
};

#line 105 "src/ast/expr.ib"
enum s899_LiteralKind {
	#line 106
	s899_LiteralKind_Number = 0,
	#line 107
	s899_LiteralKind_Float = 1,
	#line 108
	s899_LiteralKind_String = 2,
	#line 109
	s899_LiteralKind_Char = 3,
	#line 110
	s899_LiteralKind_Bool = 4,
	#line 111
	s899_LiteralKind_Null = 5,
};

#line 117 "src/ast/recovery.ib"
enum s950_RecoveryResult {
	#line 118
	s950_RecoveryResult_Skip = 0,
	#line 119
	s950_RecoveryResult_Recovered = 1,
	#line 120
	s950_RecoveryResult_RecoveredOnNext = 2,
};

#line 6 "src/ast/precedence.ib"
enum s973_RHSKind {
	#line 7
	s973_RHSKind_Expr = 0,
	#line 8
	s973_RHSKind_Call = 1,
	#line 9
	s973_RHSKind_Cast = 2,
};

#line 22 "src/typecheck/binary.ib"
enum s1041_BinaryOp {
	#line 23
	s1041_BinaryOp_Add = 0,
	#line 23
	s1041_BinaryOp_Sub = 1,
	#line 24
	s1041_BinaryOp_Mul = 2,
	#line 24
	s1041_BinaryOp_Div = 3,
	#line 24
	s1041_BinaryOp_Rem = 4,
	#line 26
	s1041_BinaryOp_EQ = 5,
	#line 26
	s1041_BinaryOp_NE = 6,
	#line 27
	s1041_BinaryOp_GT = 7,
	#line 27
	s1041_BinaryOp_GE = 8,
	#line 28
	s1041_BinaryOp_LT = 9,
	#line 28
	s1041_BinaryOp_LE = 10,
	#line 29
	s1041_BinaryOp_And = 11,
	#line 29
	s1041_BinaryOp_Or = 12,
	#line 31
	s1041_BinaryOp_BitAnd = 13,
	#line 31
	s1041_BinaryOp_BitOr = 14,
	#line 31
	s1041_BinaryOp_BitXor = 15,
	#line 32
	s1041_BinaryOp_BitShiftRight = 16,
	#line 32
	s1041_BinaryOp_BitShiftLeft = 17,
};

#line 36 "src/typecheck/binary.ib"
enum s1042_AssignOp {
	#line 37
	s1042_AssignOp_None = 0,
	#line 37
	s1042_AssignOp_Add = 1,
	#line 37
	s1042_AssignOp_Sub = 2,
	#line 37
	s1042_AssignOp_Mul = 3,
	#line 37
	s1042_AssignOp_Div = 4,
	#line 37
	s1042_AssignOp_Rem = 5,
};

#line 18 "src/typecheck/unary.ib"
enum s1052_UnaryOp {
	#line 19
	s1052_UnaryOp_Group = 0,
	#line 20
	s1052_UnaryOp_Pos = 1,
	#line 21
	s1052_UnaryOp_Neg = 2,
	#line 22
	s1052_UnaryOp_Not = 3,
	#line 23
	s1052_UnaryOp_BitNot = 4,
};

#line 20 "src/typecheck/cast.ib"
enum s1115_CastMethod {
	#line 21
	s1115_CastMethod_Keep = 0,
	#line 22
	s1115_CastMethod_Truncate = 1,
	#line 23
	s1115_CastMethod_Extend = 2,
	#line 26
	s1115_CastMethod_FloatToInt = 3,
	#line 27
	s1115_CastMethod_IntToFloat = 4,
	#line 28
	s1115_CastMethod_ArrayDecay = 5,
	#line 29
	s1115_CastMethod_Deref = 6,
};

#line 159 "src/args.ib"
struct s82_Parser {
	#line 160
	i64 argc;
	#line 161
	char * * argv;
	#line 162
	i64 current;
};

#line 4 "src/utils/vec.ib"
struct s257_Vec {
	#line 5
	i64 count;
	#line 6
	i64 capacity;
	#line 7
	i64 item_size;
	#line 8
	char * items;
	#line 9
	bool frozen;
};

#line 4 "src/utils/stringbuilder.ib"
struct s299_StringBuilder {
	#line 5
	s300_Node * head;
	#line 6
	s300_Node * tail;
	#line 7
	i64 length;
	#line 8
	i64 node_count;
};

#line 15 "src/storage/error.ib"
struct s401_Errors {
	#line 16
	s257_Vec errors;
	#line 17
	s299_StringBuilder builder;
	#line 18
	bool had_errors;
	#line 19
	bool had_warnings;
};

#line 9 "src/utils/arena.ib"
struct s566_Arena {
	#line 10
	s567_ArenaNode * head;
	#line 11
	s567_ArenaNode * tail;
	#line 12
	bool debug;
	#line 15
	s257_Vec debug_allocs;
};

#line 8 "src/utils/hashset.ib"
struct s576_HashSet {
	#line 9
	i64 count;
	#line 10
	i64 capacity;
	#line 11
	i64 value_size;
	#line 12
	char * values;
	#line 13
	s575_EntryMeta * entries;
	#line 15
	i64 (* hash_fn)(void *);
	#line 16
	bool (* eq_fn)(void *, void *);
	#line 17
	void (* free_fn)(void *);
};

#line 81 "src/typecheck/typeident.ib"
struct s531_TypeIdents {
	#line 82
	s566_Arena types_arena;
	#line 83
	s576_HashSet types_set;
	#line 86
	s528_TypeIdent * boolean;
};

#line 4 "src/utils/workstack.ib"
struct s712_WorkStack {
	#line 5
	i64 size;
	#line 6
	i64 capacity;
	#line 7
	char * items;
};

#line 22 "src/typecheck/mod.ib"
struct s351_TypecheckContext {
	#line 23
	s257_Vec * ast_modules;
	#line 24
	s257_Vec * modules;
	#line 25
	s531_TypeIdents typeidents;
	#line 27
	s401_Errors * errors;
	#line 28
	s299_StringBuilder err_builder;
	#line 29
	s712_WorkStack workstack;
	#line 31
	s257_Vec typecheck_stack;
};

#line 28 "src/build.ib"
struct s100_BuildResult {
	#line 29
	bool file_read_fail;
	#line 30
	s401_Errors errors;
	#line 31
	s257_Vec ast_modules;
	#line 32
	s257_Vec modules;
	#line 33
	s299_StringBuilder sb;
	#line 35
	s351_TypecheckContext typecheck_context;
};

#line 7 "src/utils/stringview.ib"
struct s603_StringView {
	#line 8
	char * string;
	#line 9
	i64 length;
};

#line 12 "src/utils/path.ib"
struct s275_Path {
	#line 13
	s257_Vec nodes;
	#line 14
	s603_StringView filename;
	#line 15
	bool is_library;
};

#line 97 "src/build.ib"
struct s101_ModuleParserMeta {
	#line 98
	i64 uid;
	#line 99
	char * filename;
	#line 100
	s275_Path path;
};

#line 219 "src/build.ib"
struct s102_FileParseResult {
	#line 220
	bool success;
	#line 221
	s334_Module * module;
};

#line 8 "src/storage/strings.ib"
struct s129_StringArena {
	#line 9
	i64 capacity;
	#line 10
	i64 size;
	#line 11
	s129_StringArena * next;
	#line 12
	char * content;
};

#line 8 "src/storage/identifiers.ib"
struct s141_Entry {
	#line 9
	i64 hash;
	#line 10
	i64 length;
	#line 11
	char * ident;
};

#line 14 "src/storage/identifiers.ib"
struct s142_IdentSet {
	#line 15
	i64 count;
	#line 16
	i64 capacity;
	#line 17
	s141_Entry * entries;
};

#line 12 "src/storage/span.ib"
struct s153_Span {
	#line 13
	char * file;
	#line 14
	i64 start;
	#line 15
	i64 end;
};

#line 63 "src/storage/span.ib"
struct s154_PrintOptions {
	#line 64
	s155_Range range;
	#line 65
	char * pointer_message;
	#line 66
	bool use_colors;
};

#line 7 "src/storage/filemeta.ib"
struct s165_Position {
	#line 8
	i64 line;
	#line 9
	i64 column;
	#line 10
	i64 line_start;
	#line 11
	i64 line_end;
};

#line 14 "src/storage/filemeta.ib"
struct s166_FileMeta {
	#line 15
	char * file;
	#line 16
	i64 length;
	#line 17
	s257_Vec line_starts;
};

#line 20 "src/storage/filemeta.ib"
struct s167_Key {
	#line 20
	char * file;
};

#line 13 "src/symbol/mod.ib"
struct s201_UID {
	#line 14
	i64 module;
	#line 15
	i64 index;
	#line 16
	i64 symbol;
};

#line 13 "src/ast/typeident.ib"
struct s213_FlowType {
	#line 14
	s220_FlowTypeKind kind;
	#line 15
	s214_TypeIdent * type;
};

#line 54 "src/ast/typeident.ib"
struct s215_CompoundType {
	#line 55
	i64 path_length;
	#line 56
	char * * path;
};

#line 60 "src/ast/typeident.ib"
struct s216_ArrayType {
	#line 61
	s214_TypeIdent * parent;
	#line 62
	i64 dimension_length;
	#line 63
	i64 * dimensions;
};

#line 66 "src/ast/typeident.ib"
struct s217_FunctionType {
	#line 67
	s213_FlowType return_ty;
	#line 68
	i64 args_length;
	#line 69
	s214_TypeIdent * * args;
	#line 70
	bool has_varargs;
};

#line 32 "src/ast/typeident.ib"
union s219_TypeData {
	#line 33
	s222_AtomicType atomic;
	#line 34
	s214_TypeIdent * pointer;
	#line 35
	s215_CompoundType compound;
	#line 36
	s216_ArrayType array;
	#line 37
	s217_FunctionType function;
};

#line 19 "src/ast/typeident.ib"
struct s214_TypeIdent {
	#line 20
	s221_TypeKind kind;
	#line 21
	s219_TypeData data;
};

#line 73 "src/ast/typeident.ib"
struct s218_TypeIdents {
	#line 74
	s566_Arena types_arena;
	#line 75
	s576_HashSet types_set;
	#line 76
	i64 module_uid;
};

#line 3 "src/utils/fs.ib"
struct s241_File {
	#line 4
	bool success;
	#line 5
	i64 length;
	#line 6
	char * content;
};

#line 12 "src/utils/stringbuilder.ib"
struct s300_Node {
	#line 13
	i64 capacity;
	#line 14
	i64 length;
	#line 15
	s300_Node * next;
	#line 16
	char * content;
};

#line 22 "src/lexer/mod.ib"
struct s308_Tokens {
	#line 23
	s614_Token * items;
	#line 24
	i64 count;
	#line 25
	i64 capacity;
};

#line 17 "src/lexer/mod.ib"
struct s307_LexerResult {
	#line 18
	bool success;
	#line 19
	s308_Tokens tokens;
};

#line 12 "src/ast/node.ib"
struct s585_Nodes {
	#line 13
	s257_Vec nodes;
	#line 14
	s566_Arena extras;
};

#line 19 "src/ast/mod.ib"
struct s334_Module {
	#line 20
	i64 uid;
	#line 22
	char * file;
	#line 23
	s585_Nodes nodes;
	#line 24
	s257_Vec functions;
	#line 25
	s257_Vec extern_fns;
	#line 26
	s257_Vec extern_globals;
	#line 27
	s257_Vec globals;
	#line 28
	s257_Vec imports;
	#line 29
	s257_Vec args;
	#line 31
	s257_Vec structs;
	#line 32
	s257_Vec unions;
	#line 33
	s257_Vec enums;
	#line 34
	s566_Arena object_data;
	#line 35
	s218_TypeIdents type_idents;
};

#line 39 "src/ast/mod.ib"
struct s335_AstRunResult {
	#line 40
	bool success;
	#line 41
	s334_Module module;
};

#line 226 "src/ast/mod.ib"
struct s336_IdentEntry {
	#line 227
	char * ident;
	#line 228
	i64 span;
};

#line 17 "src/codegen/mod.ib"
struct s366_CodegenContext {
	#line 18
	s257_Vec * modules;
	#line 19
	s299_StringBuilder sb;
	#line 20
	s299_StringBuilder work_sb;
	#line 21
	void * file;
	#line 22
	bool enable_sourcemap;
	#line 23
	bool verbose;
};

#line 9 "src/symbol/table.ib"
struct s376_ModuleImport {
	#line 10
	i64 module;
	#line 11
	char * alias;
	#line 12
	bool is_public;
};

#line 16 "src/symbol/table.ib"
struct s377_ModuleMeta {
	#line 17
	i64 uid;
	#line 18
	char * name;
	#line 20
	i64 import_index;
	#line 21
	i64 import_length;
	#line 22
	s257_Vec symbols;
};

#line 26 "src/symbol/table.ib"
struct s378_SymbolTable {
	#line 27
	s257_Vec modules;
	#line 28
	s257_Vec imports;
	#line 30
	i64 last_symbol_uid;
	#line 31
	i64 next_module_uid;
};

#line 23 "src/storage/error.ib"
struct s402_Error {
	#line 24
	char * header;
	#line 25
	s403_Level level;
	#line 26
	char * message;
	#line 27
	i64 span;
	#line 28
	s154_PrintOptions span_options;
};

#line 13 "src/lsp/json.ib"
struct s439_Result {
	#line 14
	s448_Status status;
	#line 15
	s440_Node * node;
};

#line 100 "src/lsp/json.ib"
struct s441_StringData {
	#line 101
	i64 length;
	#line 102
	char * content;
};

#line 110 "src/lsp/json.ib"
struct s443_ObjectData {
	#line 111
	i64 count;
	#line 112
	s442_ObjectEntry * entries;
};

#line 115 "src/lsp/json.ib"
struct s444_ArrayData {
	#line 116
	i64 count;
	#line 117
	s440_Node * elems;
};

#line 91 "src/lsp/json.ib"
union s447_NodeData {
	#line 93
	i64 number;
	#line 94
	bool boolean;
	#line 95
	s441_StringData string;
	#line 96
	s443_ObjectData object;
	#line 97
	s444_ArrayData array;
};

#line 79 "src/lsp/json.ib"
struct s440_Node {
	#line 79
	s449_NodeType type;
	#line 79
	s447_NodeData data;
};

#line 105 "src/lsp/json.ib"
struct s442_ObjectEntry {
	#line 106
	char * key;
	#line 107
	s440_Node * value;
};

#line 120 "src/lsp/json.ib"
struct s445_Parser {
	#line 121
	char * content;
	#line 122
	i64 length;
	#line 123
	i64 current;
	#line 125
	char * alloca;
	#line 126
	i64 capacity;
	#line 127
	i64 size;
	#line 128
	i64 stack;
	#line 129
	i64 strings;
};

#line 180 "src/lsp/json.ib"
struct s446_ParseStringResult {
	#line 181
	s448_Status status;
	#line 182
	char * string;
	#line 183
	i64 length;
};

#line 4 "src/lsp/request.ib"
struct s461_Request {
	#line 5
	s463_Method method;
	#line 6
	i64 id;
	#line 7
	s440_Node * params;
	#line 8
	s440_Node * json;
};

#line 34 "src/lsp/request.ib"
struct s462_Parser {
	#line 35
	i64 * log;
	#line 36
	i64 * stream;
	#line 37
	char * content;
	#line 38
	i64 capacity;
};

#line 5 "src/lsp/response.ib"
struct s824_Builder {
	#line 6
	i64 * log;
	#line 7
	i64 * stream;
	#line 8
	s299_StringBuilder sb;
};

#line 13 "src/lsp/file.ib"
struct s482_FileMap {
	#line 14
	i64 * log;
	#line 15
	s576_HashSet files;
};

#line 9 "src/lsp/context.ib"
struct s466_Context {
	#line 10
	i64 * log;
	#line 11
	s462_Parser parser;
	#line 12
	s824_Builder response;
	#line 13
	s482_FileMap files;
	#line 15
	char * parse_uri;
	#line 16
	i64 parse_uri_len;
	#line 17
	s100_BuildResult build_result;
};

#line 4 "src/lsp/file.ib"
struct s481_File {
	#line 5
	char * uri;
	#line 6
	i64 uri_len;
	#line 7
	char * content;
	#line 8
	i64 capacity;
	#line 9
	i64 length;
	#line 10
	i64 version;
};

#line 6 "src/utils/hashmap.ib"
struct s499_EntryMeta {
	#line 7
	bool exists;
	#line 8
	i64 hash;
};

#line 12 "src/utils/hashmap.ib"
struct s500_HashMap {
	#line 13
	i64 count;
	#line 13
	i64 capacity;
	#line 14
	i64 key_size;
	#line 14
	i64 value_size;
	#line 15
	char * keys;
	#line 15
	char * values;
	#line 17
	s499_EntryMeta * entries;
	#line 19
	i64 (* hash_fn)(void *);
	#line 20
	bool (* eq_fn)(void *, void *);
	#line 22
	bool debug;
};

#line 221 "src/utils/hashmap.ib"
struct s501_HashMapIter {
	#line 222
	s500_HashMap * map;
	#line 223
	i64 index;
	#line 224
	void * key;
	#line 225
	void * value;
};

#line 22 "src/typecheck/typeident.ib"
struct s527_FlowType {
	#line 23
	s533_FlowTypeKind kind;
	#line 24
	s528_TypeIdent * type;
};

#line 66 "src/typecheck/typeident.ib"
struct s529_ArrayType {
	#line 67
	s528_TypeIdent * parent;
	#line 68
	i64 dimension_length;
	#line 69
	i64 * dimensions;
};

#line 73 "src/typecheck/typeident.ib"
struct s530_FunctionType {
	#line 74
	s527_FlowType return_ty;
	#line 75
	i64 args_length;
	#line 76
	s528_TypeIdent * * args;
	#line 77
	bool has_varargs;
};

#line 43 "src/typecheck/typeident.ib"
union s532_TypeData {
	#line 44
	s535_AtomicType atomic;
	#line 45
	s528_TypeIdent * pointer;
	#line 46
	s201_UID compound;
	#line 47
	s529_ArrayType array;
	#line 48
	s530_FunctionType function;
};

#line 28 "src/typecheck/typeident.ib"
struct s528_TypeIdent {
	#line 29
	s534_TypeKind kind;
	#line 30
	s532_TypeData data;
};

#line 47 "src/symbol/symbol.ib"
union s541_ShallowInfo {
	#line 48
	void * unknown;
	#line 50
	s663_Function * func;
	#line 51
	s667_Global * global;
	#line 52
	s670_ObjectDef * object_def;
	#line 53
	s672_EnumDef * enum_def;
	#line 54
	s664_ExternFn * extern_func;
	#line 55
	s668_ExternGlobal * extern_global;
};

#line 58 "src/symbol/symbol.ib"
union s542_DeepInfo {
	#line 59
	void * unknown;
	#line 61
	s739_Function * func;
	#line 62
	s771_Global * global;
	#line 63
	s758_ObjectDef * object_def;
	#line 64
	s766_EnumDef * enum_def;
	#line 65
	s740_ExternFn * extern_func;
	#line 66
	s772_ExternGlobal * extern_global;
};

#line 30 "src/symbol/symbol.ib"
struct s540_Symbol {
	#line 31
	i64 uid;
	#line 32
	i64 module;
	#line 33
	char * name;
	#line 34
	bool is_public;
	#line 35
	bool is_extern;
	#line 36
	bool preserve_name;
	#line 37
	s544_SymbolKind kind;
	#line 38
	s543_SymbolStage stage;
	#line 39
	s541_ShallowInfo shallow;
	#line 40
	s542_DeepInfo deep;
	#line 41
	s528_TypeIdent * type;
	#line 42
	i64 span;
	#line 43
	bool used;
};

#line 16 "src/symbol/resolve.ib"
struct s554_PathResult {
	#line 17
	s557_PathResultKind kind;
	#line 18
	s201_UID symbol;
	#line 19
	i64 not_found_module_index;
};

#line 118 "src/symbol/resolve.ib"
struct s555_FindNextNodeResult {
	#line 119
	i64 module;
	#line 120
	bool found;
	#line 121
	bool is_public;
};

#line 151 "src/symbol/resolve.ib"
struct s556_IdentResult {
	#line 152
	s558_IdentResultKind kind;
	#line 153
	s201_UID symbol;
};

#line 18 "src/utils/arena.ib"
struct s567_ArenaNode {
	#line 19
	i64 capacity;
	#line 20
	i64 size;
	#line 21
	s567_ArenaNode * next;
	#line 22
	char * content;
};

#line 3 "src/utils/hashset.ib"
struct s575_EntryMeta {
	#line 4
	bool exists;
	#line 5
	i64 hash;
};

#line 69 "src/ast/node.ib"
struct s586_TypeData {
	#line 70
	s214_TypeIdent * type;
	#line 71
	i64 span;
};

#line 115 "src/ast/expr.ib"
union s896_LiteralValue {
	#line 116
	i64 number;
	#line 117
	f64 flt;
	#line 118
	char * string;
	#line 119
	char chr;
	#line 120
	bool boolean;
};

#line 99 "src/ast/expr.ib"
struct s895_Literal {
	#line 100
	s899_LiteralKind kind;
	#line 101
	s896_LiteralValue value;
};

#line 93 "src/ast/expr.ib"
struct s894_Unary {
	#line 94
	s898_UnaryOp op;
	#line 95
	i64 expr;
};

#line 76 "src/ast/expr.ib"
struct s893_Binary {
	#line 77
	s897_BinaryOp op;
	#line 78
	i64 lhs;
	#line 79
	i64 rhs;
};

#line 31 "src/ast/expr.ib"
struct s890_Call {
	#line 32
	i64 callee;
	#line 33
	i64 arg_count;
	#line 34
	i64 * args;
};

#line 25 "src/ast/expr.ib"
struct s889_Array {
	#line 26
	i64 elem_count;
	#line 27
	i64 * elems;
};

#line 39 "src/ast/expr.ib"
struct s891_ObjectInit {
	#line 40
	char * type;
	#line 41
	i64 field_count;
	#line 42
	s892_ObjectFieldInit * fields;
};

#line 18 "src/ast/expr.ib"
struct s888_Cast {
	#line 19
	i64 expr;
	#line 20
	s214_TypeIdent * type;
	#line 21
	i64 type_span;
};

#line 45 "src/ast/statement.ib"
struct s924_VarDeclaration {
	#line 46
	i64 ident;
	#line 47
	i64 value;
	#line 48
	s586_TypeData * type;
};

#line 39 "src/ast/statement.ib"
struct s923_BlockData {
	#line 40
	i64 count;
	#line 41
	i64 * nodes;
};

#line 52 "src/ast/statement.ib"
struct s925_ReturnData {
	#line 53
	bool has_value;
	#line 54
	i64 value;
};

#line 32 "src/ast/statement.ib"
struct s922_IfData {
	#line 33
	i64 cond;
	#line 34
	i64 then;
	#line 35
	i64 otherwise;
};

#line 57 "src/ast/statement.ib"
struct s926_MatchData {
	#line 58
	i64 cond;
	#line 59
	i64 count;
	#line 60
	s927_MatchCase * cases;
};

#line 25 "src/ast/statement.ib"
struct s921_LoopData {
	#line 26
	bool has_cond;
	#line 27
	i64 cond;
	#line 28
	i64 body;
};

#line 83 "src/ast/node.ib"
union s588_NodeData {
	#line 85
	char * ident;
	#line 86
	s895_Literal literal;
	#line 87
	s894_Unary unary;
	#line 88
	s893_Binary binary;
	#line 89
	s890_Call call;
	#line 90
	s889_Array array;
	#line 91
	s891_ObjectInit object;
	#line 92
	s888_Cast cast;
	#line 93
	s586_TypeData size_of;
	#line 97
	i64 expr;
	#line 98
	s924_VarDeclaration var_declaration;
	#line 99
	s923_BlockData block;
	#line 100
	s925_ReturnData retrn;
	#line 101
	s922_IfData if_data;
	#line 102
	s920_ForData * for_data;
	#line 103
	s926_MatchData match_data;
	#line 104
	s921_LoopData loop_data;
};

#line 75 "src/ast/node.ib"
struct s587_Node {
	#line 76
	s589_NodeKind kind;
	#line 77
	i64 span;
	#line 78
	s588_NodeData data;
};

#line 67 "src/lexer/token.ib"
union s615_TokenData {
	#line 68
	i64 number;
	#line 69
	f64 flt;
	#line 70
	char * string;
	#line 71
	char * ident;
	#line 72
	char chr;
};

#line 60 "src/lexer/token.ib"
struct s614_Token {
	#line 61
	s616_TokenKind kind;
	#line 62
	i64 span;
	#line 63
	s615_TokenData data;
};

#line 14 "src/lexer/lexer.ib"
struct s647_Lexer {
	#line 15
	char * content;
	#line 16
	char * file;
	#line 17
	i64 length;
	#line 18
	i64 current;
	#line 19
	i64 line;
	#line 20
	i64 column;
	#line 21
	i64 start;
	#line 22
	i64 line_start;
	#line 23
	s257_Vec * line_starts;
	#line 24
	s401_Errors * errors;
};

#line 28 "src/lexer/lexer.ib"
struct s648_LexerResult {
	#line 29
	bool is_ok;
	#line 30
	s614_Token token;
};

#line 209 "src/lexer/lexer.ib"
struct s649_EscapeResult {
	#line 210
	bool is_ok;
	#line 211
	char c;
};

#line 12 "src/ast/declaration.ib"
struct s662_Declaration {
	#line 13
	char * name;
	#line 14
	bool is_public;
	#line 15
	i64 span;
	#line 16
	s201_UID symbol;
};

#line 33 "src/ast/declaration.ib"
struct s665_Prototype {
	#line 34
	char * identifier;
	#line 35
	i64 arg_index;
	#line 36
	i64 arg_count;
	#line 37
	s213_FlowType return_type;
	#line 38
	i64 return_span;
	#line 39
	bool has_varargs;
	#line 40
	i64 span;
};

#line 20 "src/ast/declaration.ib"
struct s663_Function {
	#line 21
	s662_Declaration declaration;
	#line 22
	s665_Prototype proto;
	#line 23
	i64 body;
};

#line 27 "src/ast/declaration.ib"
struct s664_ExternFn {
	#line 28
	s662_Declaration declaration;
	#line 29
	s665_Prototype proto;
};

#line 44 "src/ast/declaration.ib"
struct s666_Arg {
	#line 45
	char * ident;
	#line 46
	s214_TypeIdent * type;
	#line 47
	i64 span;
	#line 48
	i64 type_span;
};

#line 52 "src/ast/declaration.ib"
struct s667_Global {
	#line 53
	s662_Declaration declaration;
	#line 54
	bool mutable;
	#line 55
	s214_TypeIdent * type;
	#line 56
	i64 type_span;
	#line 57
	i64 value;
};

#line 61 "src/ast/declaration.ib"
struct s668_ExternGlobal {
	#line 62
	s662_Declaration declaration;
	#line 63
	s214_TypeIdent * type;
	#line 64
	i64 type_span;
};

#line 68 "src/ast/declaration.ib"
struct s669_Import {
	#line 69
	s662_Declaration declaration;
	#line 70
	char * path;
	#line 71
	i64 path_span;
	#line 72
	i64 resolved_module;
};

#line 76 "src/ast/declaration.ib"
struct s670_ObjectDef {
	#line 77
	s662_Declaration declaration;
	#line 78
	i64 field_count;
	#line 79
	s671_ObjectField * fields;
};

#line 83 "src/ast/declaration.ib"
struct s671_ObjectField {
	#line 84
	char * field;
	#line 85
	i64 field_span;
	#line 86
	s214_TypeIdent * type;
	#line 87
	i64 type_span;
};

#line 91 "src/ast/declaration.ib"
struct s672_EnumDef {
	#line 92
	s662_Declaration declaration;
	#line 93
	i64 field_count;
	#line 94
	s673_EnumField * fields;
};

#line 97 "src/ast/declaration.ib"
struct s673_EnumField {
	#line 98
	char * field;
	#line 99
	i64 field_span;
	#line 100
	i64 value;
};

#line 22 "src/ast/precedence.ib"
struct s970_InfixPrecedence {
	#line 23
	s616_TokenKind token;
	#line 24
	i64 prec;
	#line 25
	i64 new_prec;
	#line 26
	s897_BinaryOp op;
	#line 27
	s616_TokenKind suffix;
	#line 28
	s226_ErrorKind suffix_err;
	#line 29
	s973_RHSKind rhs_kind;
	#line 30
	bool disabled;
};

#line 41 "src/ast/precedence.ib"
struct s972_InfixOpMap {
	#line 42
	s970_InfixPrecedence ops[64];
	#line 43
	i64 count;
};

#line 13 "src/ast/precedence.ib"
struct s969_PrefixPrecedence {
	#line 14
	s616_TokenKind token;
	#line 15
	i64 new_prec;
	#line 16
	s898_UnaryOp op;
	#line 17
	s616_TokenKind suffix;
	#line 18
	s226_ErrorKind suffix_err;
};

#line 35 "src/ast/precedence.ib"
struct s971_PrefixOpMap {
	#line 36
	s969_PrefixPrecedence ops[64];
	#line 37
	i64 count;
};

#line 30 "src/ast/ast.ib"
struct s702_Ast {
	#line 31
	char * file;
	#line 32
	s308_Tokens tokens;
	#line 33
	i64 current;
	#line 34
	bool in_condition;
	#line 35
	bool is_public;
	#line 36
	s334_Module * module;
	#line 37
	s712_WorkStack workstack;
	#line 38
	s972_InfixOpMap infix;
	#line 39
	s971_PrefixOpMap prefix;
	#line 40
	s401_Errors * errors;
	#line 41
	s703_TypeIdentContext typeident_context;
	#line 42
	bool is_recovering_from_errors;
	#line 47
	bool skip_expr_semicolon;
};

#line 194 "src/typecheck/node.ib"
struct s846_Nodes {
	#line 195
	s257_Vec nodes;
	#line 196
	s566_Arena extras;
};

#line 14 "src/typecheck/module.ib"
struct s729_Module {
	#line 15
	i64 uid;
	#line 16
	char * file;
	#line 18
	s846_Nodes nodes;
	#line 19
	s257_Vec functions;
	#line 20
	s257_Vec extern_fns;
	#line 21
	s257_Vec args;
	#line 23
	s257_Vec globals;
	#line 24
	s257_Vec extern_globals;
	#line 26
	s257_Vec structs;
	#line 27
	s257_Vec unions;
	#line 28
	s257_Vec enums;
	#line 29
	s566_Arena object_data;
};

#line 33 "src/typecheck/function.ib"
struct s741_Prototype {
	#line 34
	char * identifier;
	#line 35
	i64 arg_index;
	#line 36
	i64 arg_count;
	#line 37
	s527_FlowType return_type;
	#line 38
	i64 return_span;
	#line 39
	bool has_varargs;
	#line 40
	s528_TypeIdent * ty;
};

#line 20 "src/typecheck/function.ib"
struct s739_Function {
	#line 21
	s741_Prototype proto;
	#line 22
	i64 body;
	#line 23
	s201_UID symbol;
};

#line 27 "src/typecheck/function.ib"
struct s740_ExternFn {
	#line 28
	s741_Prototype proto;
	#line 29
	s201_UID symbol;
};

#line 44 "src/typecheck/function.ib"
struct s742_Arg {
	#line 45
	char * ident;
	#line 46
	s528_TypeIdent * type;
	#line 47
	i64 span;
	#line 48
	i64 type_span;
};

#line 18 "src/typecheck/var_bindings.ib"
struct s984_VarBindings {
	#line 19
	s257_Vec variables;
	#line 20
	s257_Vec blocks;
	#line 21
	i64 last_id;
};

#line 52 "src/typecheck/function.ib"
struct s743_FunctionContext {
	#line 53
	s351_TypecheckContext * parent;
	#line 54
	s334_Module * module;
	#line 55
	s663_Function * function;
	#line 56
	s846_Nodes * nodes;
	#line 57
	s984_VarBindings bindings;
	#line 59
	s528_TypeIdent * target_ty;
	#line 60
	i64 target_ty_span;
	#line 62
	s527_FlowType return_ty;
	#line 63
	i64 loop_depth;
	#line 64
	s257_Vec path_stack;
	#line 65
	bool has_return;
	#line 66
	s712_WorkStack workstack;
};

#line 15 "src/typecheck/object_def.ib"
struct s757_ObjectField {
	#line 16
	char * field;
	#line 17
	i64 field_span;
	#line 18
	s528_TypeIdent * type;
	#line 19
	i64 type_span;
	#line 20
	i64 offset;
};

#line 24 "src/typecheck/object_def.ib"
struct s758_ObjectDef {
	#line 25
	char * name;
	#line 26
	i64 span;
	#line 27
	i64 field_count;
	#line 28
	s757_ObjectField * fields;
	#line 29
	i64 align;
	#line 30
	i64 size;
	#line 31
	s201_UID symbol;
};

#line 22 "src/typecheck/enums.ib"
struct s765_EnumField {
	#line 23
	char * field;
	#line 24
	i64 field_span;
	#line 25
	i64 value;
};

#line 28 "src/typecheck/enums.ib"
struct s766_EnumDef {
	#line 29
	char * name;
	#line 30
	i64 span;
	#line 31
	s765_EnumField * fields;
	#line 32
	i64 field_count;
	#line 33
	i64 align;
	#line 34
	i64 size;
	#line 35
	s201_UID symbol;
};

#line 18 "src/typecheck/global.ib"
struct s771_Global {
	#line 19
	char * name;
	#line 20
	i64 span;
	#line 21
	bool mutable;
	#line 22
	s528_TypeIdent * type;
	#line 23
	i64 type_span;
	#line 24
	i64 value;
	#line 25
	s201_UID symbol;
};

#line 28 "src/typecheck/global.ib"
struct s772_ExternGlobal {
	#line 29
	char * name;
	#line 30
	i64 span;
	#line 31
	s528_TypeIdent * type;
	#line 32
	i64 type_span;
	#line 33
	s201_UID symbol;
};

#line 30 "src/typecheck/expr.ib"
struct s1065_Variable {
	#line 31
	i64 id;
	#line 32
	char * ident;
};

#line 32 "src/typecheck/literal.ib"
union s858_LiteralValue {
	#line 33
	i64 number;
	#line 34
	f64 flt;
	#line 35
	char * string;
	#line 36
	char chr;
	#line 37
	bool boolean;
};

#line 14 "src/typecheck/literal.ib"
struct s857_Literal {
	#line 15
	s859_LiteralKind kind;
	#line 16
	s858_LiteralValue value;
};

#line 26 "src/typecheck/unary.ib"
struct s1051_Unary {
	#line 27
	s1052_UnaryOp op;
	#line 28
	i64 expr;
};

#line 41 "src/typecheck/binary.ib"
struct s1039_Binary {
	#line 42
	s1041_BinaryOp op;
	#line 43
	i64 lhs;
	#line 44
	i64 rhs;
};

#line 24 "src/typecheck/expr.ib"
struct s1064_Call {
	#line 25
	i64 callee;
	#line 26
	i64 arg_count;
	#line 27
	i64 * args;
};

#line 47 "src/typecheck/binary.ib"
struct s1040_Assign {
	#line 48
	i64 target;
	#line 49
	i64 value;
	#line 50
	s1042_AssignOp op;
};

#line 18 "src/typecheck/array.ib"
struct s1083_Array {
	#line 19
	i64 count;
	#line 20
	i64 * elems;
};

#line 23 "src/typecheck/array.ib"
struct s1084_Index {
	#line 24
	i64 array;
	#line 25
	i64 index;
};

#line 23 "src/typecheck/object_expr.ib"
struct s1096_ObjectInit {
	#line 24
	s201_UID type;
	#line 25
	i64 field_count;
	#line 26
	s1097_ObjectFieldInit * fields;
};

#line 36 "src/typecheck/object_expr.ib"
struct s1098_FieldLookup {
	#line 37
	i64 object;
	#line 38
	char * field;
	#line 39
	i64 field_span;
};

#line 35 "src/typecheck/expr.ib"
struct s1066_EnumValue {
	#line 36
	s201_UID symbol;
	#line 37
	i64 field_idx;
	#line 38
	i64 value;
};

#line 33 "src/typecheck/cast.ib"
struct s1113_Cast {
	#line 34
	i64 expr;
	#line 35
	s528_TypeIdent * into;
	#line 36
	s1115_CastMethod method;
};

#line 48 "src/typecheck/statement.ib"
struct s1018_VarDeclaration {
	#line 49
	char * ident;
	#line 50
	i64 var_id;
	#line 51
	i64 value;
	#line 52
	s528_TypeIdent * type;
};

#line 41 "src/typecheck/statement.ib"
struct s1017_BlockData {
	#line 42
	i64 count;
	#line 43
	i64 * nodes;
};

#line 56 "src/typecheck/statement.ib"
struct s1019_ReturnData {
	#line 57
	bool has_value;
	#line 58
	i64 value;
};

#line 34 "src/typecheck/statement.ib"
struct s1016_IfData {
	#line 35
	i64 cond;
	#line 36
	i64 then;
	#line 37
	i64 otherwise;
};

#line 23 "src/typecheck/statement_match.ib"
struct s1072_MatchData {
	#line 24
	i64 cond;
	#line 25
	i64 count;
	#line 26
	s1073_MatchCase * cases;
};

#line 27 "src/typecheck/statement.ib"
struct s1015_LoopData {
	#line 28
	bool has_cond;
	#line 29
	i64 cond;
	#line 30
	i64 body;
};

#line 57 "src/typecheck/node.ib"
union s847_NodeData {
	#line 59
	s1065_Variable variable;
	#line 60
	s857_Literal literal;
	#line 61
	s1051_Unary unary;
	#line 62
	s1039_Binary binary;
	#line 63
	s1064_Call call;
	#line 64
	s1040_Assign assign;
	#line 65
	s1083_Array array;
	#line 66
	s1084_Index index;
	#line 67
	s1096_ObjectInit object;
	#line 68
	s1098_FieldLookup field_lookup;
	#line 69
	s1066_EnumValue enum_val;
	#line 70
	s1113_Cast cast;
	#line 72
	s201_UID symbol;
	#line 74
	i64 ref;
	#line 75
	i64 deref;
	#line 79
	i64 expr;
	#line 80
	s1018_VarDeclaration var_declaration;
	#line 81
	s1017_BlockData block;
	#line 82
	s1019_ReturnData retrn;
	#line 83
	s1016_IfData if_data;
	#line 84
	s1014_ForData * for_data;
	#line 85
	s1072_MatchData match_data;
	#line 86
	s1015_LoopData loop_data;
};

#line 91 "src/typecheck/node.ib"
struct s844_Node {
	#line 92
	s848_NodeKind kind;
	#line 93
	s847_NodeData data;
	#line 94
	s528_TypeIdent * ty;
	#line 95
	i64 span;
};

#line 105 "src/typecheck/node.ib"
struct s845_NodeResult {
	#line 106
	s850_NodeFlow flow;
	#line 107
	i64 node;
};

#line 16 "src/typecheck/const_eval.ib"
union s865_ConstExpr {
	#line 17
	void * none;
	#line 18
	s857_Literal literal;
};

#line 24 "src/typecheck/const_eval.ib"
struct s864_ConstEvalResult {
	#line 25
	s865_ConstExpr expr;
	#line 26
	bool success;
};

#line 46 "src/ast/expr.ib"
struct s892_ObjectFieldInit {
	#line 47
	char * field;
	#line 48
	i64 field_span;
	#line 49
	i64 value;
};

#line 17 "src/ast/statement.ib"
struct s920_ForData {
	#line 18
	i64 init;
	#line 19
	i64 cond;
	#line 20
	i64 acc;
	#line 21
	i64 body;
};

#line 64 "src/ast/statement.ib"
struct s927_MatchCase {
	#line 65
	bool has_default;
	#line 66
	i64 * conds;
	#line 67
	i64 cond_count;
	#line 68
	i64 arm;
};

#line 12 "src/ast/parse_typeident.ib"
struct s959_TypeIdentResult {
	#line 13
	bool success;
	#line 14
	s214_TypeIdent * type;
	#line 15
	i64 span;
};

#line 9 "src/typecheck/var_bindings.ib"
struct s983_Variable {
	#line 10
	char * key;
	#line 11
	bool is_error;
	#line 12
	s528_TypeIdent * ty;
	#line 13
	bool mutable;
	#line 14
	i64 id;
	#line 15
	bool used;
	#line 16
	i64 span;
};

#line 92 "src/typecheck/var_bindings.ib"
struct s985_VarResult {
	#line 93
	bool found;
	#line 94
	i64 id;
	#line 94
	char * key;
	#line 95
	s528_TypeIdent * ty;
	#line 96
	bool mutable;
	#line 96
	bool is_error;
};

#line 15 "src/typecheck/type_size_align.ib"
struct s995_SizeAndAlign {
	#line 15
	i64 align;
	#line 15
	i64 size;
};

#line 19 "src/typecheck/statement.ib"
struct s1014_ForData {
	#line 20
	i64 init;
	#line 21
	i64 cond;
	#line 22
	i64 acc;
	#line 23
	i64 body;
};

#line 148 "src/typecheck/statement.ib"
struct s1020_VarDeclResult {
	#line 149
	bool had_error;
	#line 150
	s528_TypeIdent * type;
	#line 151
	i64 value;
};

#line 21 "src/codegen/node.ib"
struct s1028_FunctionContext {
	#line 22
	s366_CodegenContext * parent;
	#line 23
	s729_Module * module;
	#line 24
	i64 last_temp;
	#line 25
	i64 depth;
	#line 26
	bool disable_next_indent;
	#line 27
	bool disable_semicolon;
	#line 28
	i64 next_loop_id;
	#line 29
	s257_Vec loop_ids;
};

#line 30 "src/typecheck/statement_match.ib"
struct s1073_MatchCase {
	#line 31
	bool has_default;
	#line 32
	i64 * conds;
	#line 33
	i64 cond_count;
	#line 34
	i64 arm;
};

#line 37 "src/typecheck/statement_match.ib"
struct s1074_CondValue {
	#line 38
	i64 value;
	#line 39
	i64 span;
	#line 40
	bool errored;
};

#line 42 "src/typecheck/statement_match.ib"
struct s1075_MatchContext {
	#line 43
	s201_UID symbol;
	#line 44
	bool is_single_enum;
	#line 45
	s850_NodeFlow flow;
	#line 46
	bool found_default;
	#line 47
	i64 cond_idx;
};

#line 30 "src/typecheck/object_expr.ib"
struct s1097_ObjectFieldInit {
	#line 31
	char * field;
	#line 32
	i64 field_span;
	#line 33
	i64 value;
};

#line 78 "src/typecheck/cast.ib"
struct s1114_ImplicitResult {
	#line 79
	bool is_ok;
	#line 80
	i64 expr;
};

#line 144 "src/typecheck/path.ib"
struct s1153_PathStackResult {
	#line 145
	s201_UID symbol;
	#line 146
	bool skipped_ident;
};

void * s39_log_stream;
char * s44_program;
s84_Mode s45_mode;
s83_HelpMode s46_help_mode;
bool s47_verbose;
bool s48_debug_lexer;
bool s49_debug_ast;
bool s50_debug_typecheck;
bool s51_debug_codegen;
bool s52_usage_stats;
char * s53_cc;
char * s54_cc_flags;
char * s55_out;
char * s56_entry;
i64 s57_forward_argc;
char * * s58_forward_argv;
char * s59_DEFAULT_CC;
char * s60_DEFAULT_ENTRY_SRC;
char * s61_DEFAULT_ENTRY_CURR;
char * s62_DEFAULT_OUT;
s299_StringBuilder s85_sb;
char * s104_RESET;
char * s105_SECTION;
char * s106_CMD;
char * s107_FLAG;
char * s108_KEY;
char * s109_VAL;
bool s118_DEBUG_ENABLED;
s129_StringArena * s119_head;
s129_StringArena * s120_tail;
bool s121_DEBUG_ALLOCATIONS;
s257_Vec s122_debug_allocs;
bool s130_DEBUG_ENABLED;
s142_IdentSet s131_set;
s257_Vec s143_spans;
s500_HashMap s156_filemetas;
s201_UID s168_NONE;
s378_SymbolTable s169_symbol_table;
char * s229_BOLD;
char * s230_RED;
char * s231_GREEN;
char * s232_YELLOW;
char * s233_BLUE;
char * s234_RESET;
i64 s258_ALLOCATED_COUNT;
char * s259_stdlib_path;
char * s260_STDLIB_PATH;
char * s276_EMPTY_STR;
bool s309_MODULE_OWNS_FILENAME;
char * s352_suffix;
char * s379_HEADER_LEXER;
char * s380_HEADER_PARSER;
char * s381_HEADER_TYPE;
char * s382_HEADER_WARN_TYPE;
char * s383_HEADER_ERROR;
char * s384_ENTRY_NOT_FOUND;
i64 s486_MINIMUM_CAPACITY;
bool s559_DEBUG_ALLOCATIONS;
i64 s577_NONE;
i64 s674_ERROR;
i64 s675_SUCCESS;
i64 s744_FIELD_IDX_NONE;
i64 s825_NONE;
i64 s826_ERROR;
i64 s960_MAX_CAPACITY;
s995_SizeAndAlign s986_POINTER_SIZE;
s1115_CastMethod s1099_CAST_INVALID;
#line 58 "./lib/stdlib.ib"
void * s39_log_stream = NULL;
#line 5 "src/args.ib"
char * s44_program = ((char *)NULL);
#line 6 "src/args.ib"
s84_Mode s45_mode = s84_Mode_Build;
#line 7 "src/args.ib"
s83_HelpMode s46_help_mode = s83_HelpMode_Default;
#line 8 "src/args.ib"
bool s47_verbose = false;
#line 10 "src/args.ib"
bool s48_debug_lexer = false;
#line 11 "src/args.ib"
bool s49_debug_ast = false;
#line 12 "src/args.ib"
bool s50_debug_typecheck = false;
#line 13 "src/args.ib"
bool s51_debug_codegen = false;
#line 14 "src/args.ib"
bool s52_usage_stats = false;
#line 16 "src/args.ib"
char * s53_cc = ((char *)NULL);
#line 17 "src/args.ib"
char * s54_cc_flags = ((char *)NULL);
#line 18 "src/args.ib"
char * s55_out = ((char *)NULL);
#line 19 "src/args.ib"
char * s56_entry = ((char *)NULL);
#line 21 "src/args.ib"
i64 s57_forward_argc = 0l;
#line 22 "src/args.ib"
char * * s58_forward_argv = ((char * *)NULL);
#line 143 "src/args.ib"
char * s59_DEFAULT_CC = "gcc";
#line 144 "src/args.ib"
char * s60_DEFAULT_ENTRY_SRC = "./src/main.ib";
#line 145 "src/args.ib"
char * s61_DEFAULT_ENTRY_CURR = "./main.ib";
#line 146 "src/args.ib"
char * s62_DEFAULT_OUT = "./bin/main";
#line 245 "src/build.ib"
s299_StringBuilder s85_sb = ((s299_StringBuilder){

});
#line 83 "src/help.ib"
char * s104_RESET = "\x1B[0m";
#line 84 "src/help.ib"
char * s105_SECTION = "\x1B[1m\x1B[38;5;15m";
#line 85 "src/help.ib"
char * s106_CMD = "\x1B[1m\x1B[38;5;220m";
#line 86 "src/help.ib"
char * s107_FLAG = "\x1B[1m\x1B[38;5;47m";
#line 87 "src/help.ib"
char * s108_KEY = "\x1B[1m\x1B[38;5;47m";
#line 88 "src/help.ib"
char * s109_VAL = "\x1B[1m\x1B[38;5;245m";
#line 6 "src/storage/strings.ib"
bool s118_DEBUG_ENABLED = false;
#line 16 "src/storage/strings.ib"
s129_StringArena * s119_head = ((s129_StringArena *)NULL);
#line 17 "src/storage/strings.ib"
s129_StringArena * s120_tail = ((s129_StringArena *)NULL);
#line 19 "src/storage/strings.ib"
bool s121_DEBUG_ALLOCATIONS = true;
#line 21 "src/storage/strings.ib"
s257_Vec s122_debug_allocs = ((s257_Vec){

});
#line 6 "src/storage/identifiers.ib"
bool s130_DEBUG_ENABLED = false;
#line 20 "src/storage/identifiers.ib"
s142_IdentSet s131_set = ((s142_IdentSet){
	.count = 0l,
	.capacity = 0l,
	.entries = ((s141_Entry *)NULL)
});
#line 9 "src/storage/span.ib"
s257_Vec s143_spans = ((s257_Vec){

});
#line 23 "src/storage/filemeta.ib"
s500_HashMap s156_filemetas = ((s500_HashMap){

});
#line 18 "src/symbol/mod.ib"
s201_UID s168_NONE = ((s201_UID){
	.module = 0l,
	.symbol = 0l,
	.index = 0l
});
#line 19 "src/symbol/mod.ib"
s378_SymbolTable s169_symbol_table = ((s378_SymbolTable){

});
#line 1 "src/utils/color.ib"
char * s229_BOLD = "\x1B[1m";
#line 2 "src/utils/color.ib"
char * s230_RED = "\x1B[1m\x1B[31m";
#line 3 "src/utils/color.ib"
char * s231_GREEN = "\x1B[1m\x1B[32m";
#line 4 "src/utils/color.ib"
char * s232_YELLOW = "\x1B[1m\x1B[33m";
#line 5 "src/utils/color.ib"
char * s233_BLUE = "\x1B[1m\x1B[34m";
#line 7 "src/utils/color.ib"
char * s234_RESET = "\x1B[0m";
#line 9 "src/utils/path.ib"
i64 s258_ALLOCATED_COUNT = 0l;
#line 72 "src/utils/path.ib"
char * s259_stdlib_path = ((char *)NULL);
#line 73 "src/utils/path.ib"
char * s260_STDLIB_PATH = "./lib/stdlib.ib";
#line 217 "src/utils/stringbuilder.ib"
char * s276_EMPTY_STR = "";
#line 107 "src/ast/mod.ib"
bool s309_MODULE_OWNS_FILENAME = true;
#line 27 "src/codegen/mod.ib"
char * s352_suffix = "_generated.c";
#line 77 "src/storage/error.ib"
char * s379_HEADER_LEXER = "Lexer Error";
#line 78 "src/storage/error.ib"
char * s380_HEADER_PARSER = "Parser Error";
#line 79 "src/storage/error.ib"
char * s381_HEADER_TYPE = "Type Error";
#line 80 "src/storage/error.ib"
char * s382_HEADER_WARN_TYPE = "Type Warning";
#line 81 "src/storage/error.ib"
char * s383_HEADER_ERROR = "Error";
#line 96 "src/storage/error.ib"
char * s384_ENTRY_NOT_FOUND = "main not found in entry module";
#line 4 "src/utils/hashmap.ib"
i64 s486_MINIMUM_CAPACITY = 1024l;
#line 29 "src/utils/arena.ib"
bool s559_DEBUG_ALLOCATIONS = true;
#line 10 "src/ast/node.ib"
i64 s577_NONE = 0l;
#line 288 "src/ast/ast.ib"
i64 s674_ERROR = (-1l);
#line 289 "src/ast/ast.ib"
i64 s675_SUCCESS = 1l;
#line 44 "src/typecheck/object_def.ib"
i64 s744_FIELD_IDX_NONE = (-1l);
#line 29 "src/typecheck/node.ib"
i64 s825_NONE = 0l;
#line 30 "src/typecheck/node.ib"
i64 s826_ERROR = (-1l);
#line 34 "src/ast/precedence.ib"
i64 s960_MAX_CAPACITY = 64l;
#line 13 "src/typecheck/type_size_align.ib"
s995_SizeAndAlign s986_POINTER_SIZE = ((s995_SizeAndAlign){
	.align = 8l,
	.size = 8l
});
#line 112 "src/typecheck/cast.ib"
s1115_CastMethod s1099_CAST_INVALID = s1115_CastMethod_Keep;

/*  Functions Implementations */
#line 11 "src/main_other.ib"
int main(int v1_argc, char * * v2_argv) {
	#line 13
	s63_parse(((i64)v1_argc), v2_argv);
	#line 15
	s42_init();
	#line 17
	i64 v3_result = s2_run();
	#line 19
	s43_free();
	#line 21
	fflush(stdout);
	#line 22
	return ((int)v3_result);
}


#line 26 "src/main_other.ib"
i64 s2_run() {
	#line 27
	switch (s45_mode) {
	case s84_Mode_Help: {
	return s110_print();
	break; }
	case s84_Mode_Build: {
	return s86_run();
	break; }
	case s84_Mode_Run: {
	return s103_run();
	break; }
	case s84_Mode_Script: {
	return s103_run();
	break; }
	case s84_Mode_Lsp: {
	return s116_run();
	break; }
	default:
		abort();
}
}


#line 49 "./lib/stdlib.ib"
void s40_assert(bool v1_value, char * v2_message) {
	#line 50
	if ((!v1_value)) {
		#line 51
		if ((s39_log_stream == NULL)) {
			#line 51
			s39_log_stream = stderr;
		}
		#line 52
		fprintf(s39_log_stream, "Assertion Error: %s\n", v2_message);
		#line 53
		fflush(s39_log_stream);
		#line 54
		abort();
	}
}


#line 12 "src/storage/mod.ib"
void s42_init() {
	#line 13
	s144_init();
	#line 14
	s124_init();
	#line 15
	s136_init();
	#line 16
	s157_init();
	#line 18
	s173_init();
}


#line 22 "src/storage/mod.ib"
void s43_free() {
	#line 23
	s174_free();
	#line 25
	s158_free();
	#line 26
	s137_free();
	#line 27
	s127_free();
	#line 28
	s145_free();
}


#line 40 "src/args.ib"
void s63_parse(i64 v1_argc, char * * v2_argv) {
	#line 41
	s44_program = (v2_argv[0l]);
	#line 42
	s82_Parser v3_p = ((s82_Parser){
		.argc = v1_argc,
		.argv = v2_argv,
		.current = 0l
	});
	#line 43
	s75_step((&v3_p));
	#line 44
	s45_mode = s71_parse_mode((&v3_p));
	#line 45
	switch (s45_mode) {
	case s84_Mode_Help: {
		#line 46
		s46_help_mode = s70_parse_help_mode((&v3_p));
	break; }
	case s84_Mode_Build: {
		#line 47
		s64_parse_options((&v3_p), s65_parse_build_arg);
	break; }
	case s84_Mode_Run: {
		#line 48
		s64_parse_options((&v3_p), s65_parse_build_arg);
	break; }
	case s84_Mode_Script: {
	break; }
	case s84_Mode_Lsp: {
	break; }
	default:
		abort();
}
	#line 52
	s72_apply_defaults();
}


#line 56 "src/args.ib"
void s64_parse_options(s82_Parser * v1_parser, bool (* v2_parse_fn)(char *)) {
	#line 57
	while (s73_has_next(v1_parser)) {
		#line 58
		char * v3_arg = s74_curr(v1_parser);
		#line 59
		if ((((i64)strcmp(v3_arg, "--")) == 0l)) {
			#line 60
			s57_forward_argc = ((((*v1_parser).argc) - ((*v1_parser).current)) - 1l);
			#line 61
			s58_forward_argv = (&(((*v1_parser).argv)[(((*v1_parser).current) + 1l)]));
			#line 62
						goto loop_exit_1;
/* break; */
		}
		#line 64
		if ((!v2_parse_fn(v3_arg))) {
			#line 65
			printf("Unknown arg \"%s\".\nSee \"%s%s help%s\" for more info.\n", v3_arg, s233_BLUE, s44_program, s234_RESET);
			#line 66
			exit(((int)1l));
		}
		#line 68
		s75_step(v1_parser);
}
	loop_exit_1:
}


#line 73 "src/args.ib"
bool s65_parse_build_arg(char * v1_arg) {
	#line 74
	char * v2_value = ((char *)NULL);
	#line 75
	if (s66_parse_common_args(v1_arg)) {
		#line 75
		return true;
	}
	#line 76
	if (s68_match_keyval(v1_arg, "--cc", (&v2_value))) {
		#line 76
		s53_cc = v2_value;
	} else if (s68_match_keyval(v1_arg, "--out", (&v2_value))) {
		#line 77
		s55_out = v2_value;
	} else if (s68_match_keyval(v1_arg, "--entry", (&v2_value))) {
		#line 78
		s56_entry = v2_value;
	} else if (s68_match_keyval(v1_arg, "--cc-flags", (&v2_value))) {
		#line 79
		s54_cc_flags = v2_value;
	} else {
#line 80
		return false;
	}
	#line 81
	return true;
}


#line 85 "src/args.ib"
bool s66_parse_common_args(char * v1_arg) {
	#line 86
	if (s67_match_flag(v1_arg, "-v", "--verbose")) {
		#line 86
		s47_verbose = true;
	} else if (s67_match_flag(v1_arg, "-dl", "--debug-lexer")) {
		#line 87
		s48_debug_lexer = true;
	} else if (s67_match_flag(v1_arg, "-da", "--debug-ast")) {
		#line 88
		s49_debug_ast = true;
	} else if (s67_match_flag(v1_arg, "-dt", "--debug-typecheck")) {
		#line 89
		s50_debug_typecheck = true;
	} else if (s67_match_flag(v1_arg, "-dc", "--debug-codegen")) {
		#line 90
		s51_debug_codegen = true;
	} else {
#line 91
		return false;
	}
	#line 92
	return true;
}


#line 96 "src/args.ib"
bool s67_match_flag(char * v1_arg, char * v2_short, char * v3_long) {
	#line 97
	return ((((i64)strcmp(v1_arg, v2_short)) == 0l) || (((i64)strcmp(v1_arg, v3_long)) == 0l));
}


#line 101 "src/args.ib"
bool s68_match_keyval(char * v1_arg, char * v2_key, char * * v3_out) {
	#line 102
	u64 v4_length = strlen(v2_key);
	#line 103
	if ((((i64)strncmp(v1_arg, v2_key, v4_length)) != 0l)) {
		#line 103
		return false;
	}
	#line 104
	if (((v1_arg[v4_length]) != 61u)) {
		#line 104
		return false;
	}
	#line 105
	(*v3_out) = (&(v1_arg[(v4_length + ((u64)1l))]));
	#line 106
	return true;
}


#line 110 "src/args.ib"
void s69_print_raw_args(i64 v1_argc, char * * v2_argv) {
	#line 111
	printf("argc := %d\n", v1_argc);
	#line 112
	for (i64 v3_i = 0l;(v3_i < v1_argc);v3_i += 1l) {
		#line 113
		printf("argv[%d] := \"%s\"\n", v3_i, (v2_argv[v3_i]));
	}
	loop_exit_1:
}


#line 118 "src/args.ib"
s83_HelpMode s70_parse_help_mode(s82_Parser * v1_parser) {
	#line 119
	char * v2_s = s74_curr(v1_parser);
	#line 119
	s75_step(v1_parser);
	#line 120
	s83_HelpMode v3_default = s83_HelpMode_Default;
	#line 122
	if ((v2_s == ((char *)NULL))) {
		#line 122
		return v3_default;
	} else if ((((i64)strcmp(v2_s, "developer")) == 0l)) {
		#line 123
		return s83_HelpMode_Developer;
	} else if ((((i64)strcmp(v2_s, "dev")) == 0l)) {
		#line 124
		return s83_HelpMode_Developer;
	} else {
#line 125
		((*v1_parser).current) -= 1l;
		#line 125
		return v3_default;
	}
}


#line 129 "src/args.ib"
s84_Mode s71_parse_mode(s82_Parser * v1_parser) {
	#line 130
	char * v2_s = s74_curr(v1_parser);
	#line 130
	s75_step(v1_parser);
	#line 131
	s84_Mode v3_default = s84_Mode_Build;
	#line 133
	if ((v2_s == ((char *)NULL))) {
		#line 133
		return v3_default;
	} else if ((((i64)strcmp(v2_s, "run")) == 0l)) {
		#line 134
		return s84_Mode_Run;
	} else if ((((i64)strcmp(v2_s, "build")) == 0l)) {
		#line 135
		return s84_Mode_Build;
	} else if ((((i64)strcmp(v2_s, "help")) == 0l)) {
		#line 136
		return s84_Mode_Help;
	} else if ((((i64)strcmp(v2_s, "script")) == 0l)) {
		#line 137
		return s84_Mode_Script;
	} else if ((((i64)strcmp(v2_s, "lsp")) == 0l)) {
		#line 138
		return s84_Mode_Lsp;
	} else {
#line 139
		((*v1_parser).current) -= 1l;
		#line 139
		return v3_default;
	}
}


#line 147 "src/args.ib"
void s72_apply_defaults() {
	#line 148
	if ((s56_entry == ((char *)NULL))) {
		#line 149
		if (s240_exists(s60_DEFAULT_ENTRY_SRC)) {
			#line 150
			s56_entry = s60_DEFAULT_ENTRY_SRC;
		}
	}
	#line 153
	if ((s56_entry == ((char *)NULL))) {
		#line 153
		s56_entry = s61_DEFAULT_ENTRY_CURR;
	}
	#line 154
	if ((s53_cc == ((char *)NULL))) {
		#line 154
		s53_cc = s59_DEFAULT_CC;
	}
	#line 155
	if ((s55_out == ((char *)NULL))) {
		#line 155
		s55_out = s62_DEFAULT_OUT;
	}
}


#line 165 "src/args.ib"
bool s73_has_next(s82_Parser * v1_parser) {
	#line 166
	return (((*v1_parser).current) < ((*v1_parser).argc));
}


#line 169 "src/args.ib"
char * s74_curr(s82_Parser * v1_parser) {
	#line 170
	if ((((*v1_parser).current) >= ((*v1_parser).argc))) {
		#line 170
		return ((char *)NULL);
	}
	#line 171
	return (((*v1_parser).argv)[((*v1_parser).current)]);
}


#line 174 "src/args.ib"
void s75_step(s82_Parser * v1_parser) {
	#line 175
	((*v1_parser).current) += 1l;
}


#line 179 "src/args.ib"
void s76_print_args() {
	#line 180
	printf("%sArgs:%s\n", s231_GREEN, s234_RESET, s44_program);
	#line 181
	printf("%s   Program:%s %s\n", s231_GREEN, s234_RESET, s44_program);
	#line 182
	s77_print_mode();
	#line 185
	s78_print_debug_flags();
	#line 187
	s80_print_keyval("ENTRY", s56_entry);
	#line 188
	s80_print_keyval("OUT", s55_out);
	#line 189
	s80_print_keyval("CC", s53_cc);
	#line 190
	s80_print_keyval("CCFLAGS", s54_cc_flags);
	#line 192
	s81_print_forward_args();
}


#line 195 "src/args.ib"
void s77_print_mode() {
	#line 196
	printf("%s   Mode:%s ", s231_GREEN, s234_RESET);
	#line 197
	switch (s45_mode) {
	case s84_Mode_Build: {
	printf("Build");
	break; }
	case s84_Mode_Run: {
	printf("Run");
	break; }
	case s84_Mode_Script: {
	printf("Script");
	break; }
	case s84_Mode_Lsp: {
	printf("Lsp");
	break; }
	case s84_Mode_Help: {
		#line 203
		printf("Help");
		#line 204
		switch (s46_help_mode) {
		case s83_HelpMode_Default: {
		break; }
		case s83_HelpMode_Developer: {
		printf(" dev");
		break; }
		default:
			abort();
}
	break; }
	default:
		abort();
}
	#line 211
	printf("\n");
}


#line 214 "src/args.ib"
void s78_print_debug_flags() {
	#line 215
	i64 v1_flag_count = 0l;
	#line 216
	printf("%s   Debug Flags: %s", s231_GREEN, s234_RESET);
	#line 217
	s79_print_flag(s48_debug_lexer, "debug_lexer", (&v1_flag_count));
	#line 218
	s79_print_flag(s49_debug_ast, "debug_ast", (&v1_flag_count));
	#line 219
	s79_print_flag(s50_debug_typecheck, "debug_typecheck", (&v1_flag_count));
	#line 220
	s79_print_flag(s51_debug_codegen, "debug_codegen", (&v1_flag_count));
	#line 221
	s79_print_flag(s52_usage_stats, "usage_stats", (&v1_flag_count));
	#line 223
	if ((v1_flag_count == 0l)) {
		#line 224
		printf("[NONE]");
	}
	#line 226
	printf("\n");
}


#line 229 "src/args.ib"
void s79_print_flag(bool v1_condition, char * v2_label, i64 * v3_enabled_flag_count) {
	#line 230
	if (v1_condition) {
		#line 231
		if (((*v3_enabled_flag_count) > 0l)) {
			#line 231
			printf(", ");
		}
		#line 232
		printf(v2_label);
		#line 233
		(*v3_enabled_flag_count) += 1l;
	}
}


#line 237 "src/args.ib"
void s80_print_keyval(char * v1_label, char * v2_value) {
	#line 238
	printf("%s   %s: %s%s\n", s231_GREEN, v1_label, s234_RESET, v2_value);
}


#line 241 "src/args.ib"
void s81_print_forward_args() {
	#line 242
	printf("%s   FORWARD ARGS%s:\n", s231_GREEN, s234_RESET);
	#line 243
	printf("      %sargc%s = %d\n", s231_GREEN, s234_RESET, s57_forward_argc);
	#line 244
	for (i64 v1_i = 0l;(v1_i < s57_forward_argc);v1_i += 1l) {
		#line 245
		printf("      %sargv%s[%d] = %s\n", s231_GREEN, s234_RESET, v1_i, (s58_forward_argv[v1_i]));
	}
	loop_exit_1:
}


#line 39 "src/build.ib"
i64 s86_run() {
	#line 40
	s100_BuildResult v1_result = s90_build();
	#line 42
	s395_print_errors((&(v1_result.errors)));
	#line 43
	i64 v2_res = 0l;
	#line 44
	if (((v1_result.errors).had_errors)) {
		#line 44
		v2_res = 1l;
	}
	#line 46
	s88_free((&v1_result));
	#line 48
	return 0l;
}


#line 52 "src/build.ib"
s100_BuildResult s87_new() {
	#line 53
	return ((s100_BuildResult){
		.file_read_fail = false,
		.errors = s385_new(),
		.ast_modules = s243_new(((i64)680ul), 1l),
		.modules = ((s257_Vec){

		}),
		.sb = s277_new(),
		.typecheck_context = ((s351_TypecheckContext){

		})
	});
}


#line 65 "src/build.ib"
void s88_free(s100_BuildResult * v1_result) {
	#line 66
	s312_free_modules((&((*v1_result).ast_modules)), true);
	#line 67
	s350_free_modules((&((*v1_result).modules)), false);
	#line 68
	s246_free((&((*v1_result).ast_modules)));
	#line 69
	s278_free((&((*v1_result).sb)));
	#line 70
	s386_free((&((*v1_result).errors)));
	#line 71
	s338_context_free((&((*v1_result).typecheck_context)));
}


#line 75 "src/build.ib"
void s89_clear(s100_BuildResult * v1_result) {
	#line 76
	s387_reset((&((*v1_result).errors)));
}


#line 79 "src/build.ib"
s100_BuildResult s90_build() {
	#line 80
	char * v1_entry = s56_entry;
	#line 81
	s100_BuildResult v2_result = s87_new();
	#line 83
	printf("  %sCompiling%s %s\n", s231_GREEN, s234_RESET, v1_entry);
	#line 85
	s91_parse_all((&v2_result), v1_entry);
	#line 88
	s97_typecheck((&v2_result));
	#line 89
	if (((v2_result.errors).had_errors)) {
		#line 89
		return v2_result;
	}
	#line 91
	if ((v2_result.file_read_fail)) {
		#line 91
		return v2_result;
	}
	#line 93
	s99_codegen((&v2_result));
	#line 94
	return v2_result;
}


#line 102 "src/build.ib"
void s91_parse_all(s100_BuildResult * v1_result, char * v2_entry) {
	#line 103
	s257_Vec v3_modules_to_parse = s243_new(((i64)80ul), 64l);
	#line 105
	s275_Path v4_path = s261_new(v2_entry);
	#line 106
	char * v5_filename = s267_to_str((&v4_path));
	#line 108
	s101_ModuleParserMeta * v6_first = ((s101_ModuleParserMeta *)s249_push((&v3_modules_to_parse)));
	#line 109
	(*v6_first) = ((s101_ModuleParserMeta){
		.uid = s175_insert_module(v5_filename),
		.filename = v5_filename,
		.path = v4_path
	});
	#line 116
	for (i64 v7_module_idx = 0l;(v7_module_idx < (v3_modules_to_parse.count));v7_module_idx += 1l) {
		#line 117
		s101_ModuleParserMeta * v8_module_parse_meta = ((s101_ModuleParserMeta *)s251_get((&v3_modules_to_parse), v7_module_idx));
		#line 122
		char * v9_filename = ((*v8_module_parse_meta).filename);
		#line 123
		i64 v10_uid = ((*v8_module_parse_meta).uid);
		#line 124
		s102_FileParseResult v11_parse_result = s94_parse_file(v9_filename, v10_uid, v1_result);
		#line 126
		if (((v11_parse_result.module) == ((s334_Module *)NULL))) {
			#line 127
			continue;
		}
		#line 129
		s92_insert_module_imports((v11_parse_result.module), v7_module_idx, (&v3_modules_to_parse));
		#line 138
		if (s49_debug_ast) {
			#line 138
			s96_debug_ast((v11_parse_result.module));
		}
		#line 139
		s331_create_symbols((v11_parse_result.module));
	}
	loop_exit_1:
	#line 141
	s264_assert_allocated_count((v3_modules_to_parse.count));
	#line 142
	for (i64 v12_i = 0l;(v12_i < (v3_modules_to_parse.count));v12_i += 1l) {
		#line 143
		s101_ModuleParserMeta * v13_parser = ((s101_ModuleParserMeta *)s251_get((&v3_modules_to_parse), v12_i));
		#line 144
		s262_free((&((*v13_parser).path)));
	}
	loop_exit_2:
	#line 146
	s264_assert_allocated_count(0l);
	#line 148
	s246_free((&v3_modules_to_parse));
}


#line 151 "src/build.ib"
void s92_insert_module_imports(s334_Module * v1_module, i64 v2_base_path_idx, s257_Vec * v3_modules_to_parse) {
	#line 162
	for (i64 v4_i = 0l;(v4_i < (((*v1_module).imports).count));v4_i += 1l) {
		#line 163
		s669_Import * v5_imprt = ((s669_Import *)s251_get((&((*v1_module).imports)), v4_i));
		#line 169
		s101_ModuleParserMeta * v6_base_path_mod = ((s101_ModuleParserMeta *)s251_get(v3_modules_to_parse, v2_base_path_idx));
		#line 170
		s275_Path * v7_base_path = (&((*v6_base_path_mod).path));
		#line 171
		s275_Path v8_canonical_path = s263_join(v7_base_path, ((*v5_imprt).path));
		#line 172
		i64 v9_idx = s93_is_queued((&v8_canonical_path), v3_modules_to_parse);
		#line 173
		if ((v9_idx >= 0l)) {
			#line 174
			s101_ModuleParserMeta * v10_parse = ((s101_ModuleParserMeta *)s251_get(v3_modules_to_parse, v9_idx));
			#line 175
			((*v5_imprt).resolved_module) = ((*v10_parse).uid);
			#line 176
			s262_free((&v8_canonical_path));
			#line 177
			continue;
		}
		#line 180
		char * v11_filename = s267_to_str((&v8_canonical_path));
		#line 181
		i64 v12_uid = s175_insert_module(v11_filename);
		#line 183
		((*v5_imprt).resolved_module) = v12_uid;
		#line 184
		s101_ModuleParserMeta * v13_pushed = ((s101_ModuleParserMeta *)s249_push(v3_modules_to_parse));
		#line 185
		(*v13_pushed) = ((s101_ModuleParserMeta){
			.path = v8_canonical_path,
			.filename = v11_filename,
			.uid = v12_uid
		});
	}
	loop_exit_1:
	#line 191
	s257_Vec v14_module_imports = s243_new(((i64)24ul), (((*v1_module).imports).count));
	#line 192
	for (i64 v15_i = 0l;(v15_i < (((*v1_module).imports).count));v15_i += 1l) {
		#line 193
		s669_Import * v16_ast_import = ((s669_Import *)s251_get((&((*v1_module).imports)), v15_i));
		#line 194
		s376_ModuleImport * v17_imprt = ((s376_ModuleImport *)s249_push((&v14_module_imports)));
		#line 195
		(*v17_imprt) = ((s376_ModuleImport){
			.module = ((*v16_ast_import).resolved_module),
			.alias = (((*v16_ast_import).declaration).name),
			.is_public = (((*v16_ast_import).declaration).is_public)
		});
	}
	loop_exit_2:
	#line 201
	s177_insert_imports(((*v1_module).uid), (&v14_module_imports));
	#line 202
	s246_free((&v14_module_imports));
}


#line 206 "src/build.ib"
i64 s93_is_queued(s275_Path * v1_canonical_path, s257_Vec * v2_modules_to_parse) {
	#line 210
	for (i64 v3_i = 0l;(v3_i < ((*v2_modules_to_parse).count));v3_i += 1l) {
		#line 211
		s101_ModuleParserMeta * v4_parse = ((s101_ModuleParserMeta *)s251_get(v2_modules_to_parse, v3_i));
		#line 212
		s275_Path * v5_path = (&((*v4_parse).path));
		#line 213
		if (s274_eq(v5_path, v1_canonical_path)) {
			#line 213
			return v3_i;
		}
	}
	loop_exit_1:
	#line 215
	return (-1l);
}


#line 225 "src/build.ib"
s102_FileParseResult s94_parse_file(char * v1_filename, i64 v2_module, s100_BuildResult * v3_build_result) {
	#line 226
	s241_File v4_file = s236_read_file(v1_filename);
	#line 227
	if ((!(v4_file.success))) {
		#line 228
		((*v3_build_result).file_read_fail) = true;
		#line 229
		s394_file_not_found((&((*v3_build_result).errors)), v1_filename);
		#line 230
		return ((s102_FileParseResult){

		});
	}
	#line 232
	if (s47_verbose) {
		#line 233
		printf("  %sCompiling%s %s...\n", s231_GREEN, s234_RESET, v1_filename);
	}
	#line 236
	s102_FileParseResult v5_result = s95_parse_file_content(v2_module, v1_filename, (v4_file.content), (v4_file.length), v3_build_result);
	#line 241
	s238_free((&v4_file));
	#line 242
	return v5_result;
}


#line 247 "src/build.ib"
s102_FileParseResult s95_parse_file_content(i64 v1_module, char * v2_filename, char * v3_content, i64 v4_length, s100_BuildResult * v5_build_result) {
	#line 248
	s102_FileParseResult v6_parse_result = ((s102_FileParseResult){
		.success = false,
		.module = ((s334_Module *)NULL)
	});
	#line 250
	s307_LexerResult v7_result = s301_run(v2_filename, v3_content, v4_length, (&((*v5_build_result).errors)));
	#line 251
	if ((!(v7_result.success))) {
		#line 251
		return v6_parse_result;
	}
	#line 253
	if (s48_debug_lexer) {
		#line 253
		s304_print_tokens((&(v7_result.tokens)));
	}
	#line 255
	s335_AstRunResult v8_result = s310_run(v2_filename, v1_module, (v7_result.tokens), (&((*v5_build_result).errors)));
	#line 262
	s40_assert(((((*v5_build_result).ast_modules).count) == v1_module), "parse_file_content module id was incorrect");
	#line 263
	(v6_parse_result.module) = ((s334_Module *)s249_push((&((*v5_build_result).ast_modules))));
	#line 264
	(*(v6_parse_result.module)) = (v8_result.module);
	#line 269
	return v6_parse_result;
}


#line 273 "src/build.ib"
void s96_debug_ast(s334_Module * v1_module) {
	#line 274
	s299_StringBuilder v2_sb = s277_new();
	#line 275
	s315_debug_module((&v2_sb), v1_module);
	#line 276
	printf("%s", s294_merge((&v2_sb)));
	#line 277
	s278_free((&v2_sb));
}


#line 282 "src/build.ib"
void s97_typecheck(s100_BuildResult * v1_result) {
	#line 283
	s201_UID v2_main_fn = s178_find_symbol(0l, s135_find("main"));
	#line 284
	if ((!s170_is_none(v2_main_fn))) {
		#line 285
		s195_preserve_name(v2_main_fn);
	} else {
#line 287
		s393_entry_not_found((&((*v1_result).errors)));
	}
	#line 290
	((*v1_result).modules) = s341_create_modules((&((*v1_result).ast_modules)));
	#line 291
	((*v1_result).typecheck_context) = s337_context((&((*v1_result).errors)), (&((*v1_result).ast_modules)), (&((*v1_result).modules)));
	#line 296
	s339_run((&((*v1_result).typecheck_context)));
	#line 298
	if (s50_debug_typecheck) {
		#line 299
		for (i64 v3_i = 0l;(v3_i < (((*v1_result).modules).count));v3_i += 1l) {
			#line 300
			s98_debug_typecheck(((s729_Module *)s251_get((&((*v1_result).modules)), v3_i)));
		}
		loop_exit_1:
	}
}


#line 306 "src/build.ib"
void s98_debug_typecheck(s729_Module * v1_module) {
	#line 307
	s299_StringBuilder v2_sb = s277_new();
	#line 308
	s349_debug_module((&v2_sb), v1_module);
	#line 309
	printf("%s", s294_merge((&v2_sb)));
	#line 310
	s278_free((&v2_sb));
}


#line 314 "src/build.ib"
void s99_codegen(s100_BuildResult * v1_result) {
	#line 315
	char * v2_generated_file = s353_generated_filename(s55_out);
	#line 316
	s366_CodegenContext v3_context = s354_context((&((*v1_result).modules)), v2_generated_file, s47_verbose);
	#line 317
	s356_run((&v3_context));
	#line 318
	s355_free((&v3_context));
	#line 319
	free(((void *)v2_generated_file));
}


#line 4 "src/run.ib"
i64 s103_run() {
	#line 5
	s406_todo("run not implemented yet");
	#line 7
	return 0l;
}


#line 6 "src/help.ib"
i64 s110_print() {
	#line 7
	printf("%sUsage:%s %s {command} {...option}\n", s105_SECTION, s104_RESET, s44_program);
	#line 8
	s111_section("Commands");
	#line 9
	s112_command("help", "Shows this help menu.");
	#line 10
	s112_command("build", "Compile to an executable.");
	#line 11
	s112_command("run", "Compile and execute.");
	#line 12
	s112_command("script", "Compile and run without creating an executable.");
	#line 13
	s112_command("lsp", "Start LSP server");
	#line 15
	s111_section("Options");
	#line 16
	s113_flag("-v ", "--verbose", "Verbose compilation logging");
	#line 17
	s114_keyval("--cc", "gcc", "C compiler to use when linking.");
	#line 18
	s114_keyval("--cc-flags", "-lraylib", "Flags to pass to compiler when linking");
	#line 19
	s114_keyval("--out", "./bin/main", "Executable file");
	#line 20
	s114_keyval("--entry", "./src/main.ib", "Entry file");
	#line 22
	if ((s46_help_mode == s83_HelpMode_Developer)) {
		#line 23
		s111_section("Developer");
		#line 24
		s113_flag("-dl", "--debug-lexer", "Print tokenizer result to stdout.");
		#line 25
		s113_flag("-da", "--debug-ast", "Print AST modules to stdout.");
		#line 26
		s113_flag("-dt", "--debug-typecheck", "Print Typechecker logs to stdout.");
		#line 27
		s113_flag("-dc", "--debug-codegen", "Print Codegen result to stderr.");
	}
	#line 29
	return 0l;
}


#line 33 "src/help.ib"
void s111_section(char * v1_label) {
	#line 34
	printf("\n%s%s:%s\n", s105_SECTION, v1_label, s104_RESET);
}


#line 38 "src/help.ib"
void s112_command(char * v1_key, char * v2_desc) {
	#line 39
	i64 v3_WIDTH = 8l;
	#line 40
	i64 v4_padding = (v3_WIDTH - ((i64)strlen(v1_key)));
	#line 41
	if ((v4_padding < 0l)) {
		#line 41
		v4_padding = 0l;
	}
	#line 43
	printf("   %s%s%s", s106_CMD, v1_key, s104_RESET);
	#line 44
	printf("%*c\t", v4_padding, 32u);
	#line 45
	printf("%s\n", v2_desc);
}


#line 48 "src/help.ib"
void s113_flag(char * v1_short, char * v2_long, char * v3_desc) {
	#line 49
	i64 v4_WIDTH = 24l;
	#line 50
	i64 v5_padding = ((v4_WIDTH - ((i64)strlen(v1_short))) - ((i64)strlen(v2_long)));
	#line 51
	if ((v5_padding < 0l)) {
		#line 51
		v5_padding = 0l;
	}
	#line 53
	printf("   %s%s%s", s107_FLAG, v1_short, s104_RESET);
	#line 54
	printf(" | ");
	#line 55
	printf("%s%s%s", s107_FLAG, v2_long, s104_RESET);
	#line 56
	printf("%*c\t", v5_padding, 32u);
	#line 57
	printf("%s\n", v3_desc);
}


#line 60 "src/help.ib"
void s114_keyval(char * v1_key, char * v2_val, char * v3_desc) {
	#line 61
	i64 v4_WIDTH = 24l;
	#line 62
	i64 v5_padding = ((v4_WIDTH - ((i64)strlen(v1_key))) - ((i64)strlen(v2_val)));
	#line 63
	if ((v5_padding < 0l)) {
		#line 63
		v5_padding = 0l;
	}
	#line 65
	printf("   %s%s%s=", s108_KEY, v1_key, s104_RESET);
	#line 66
	printf("%s%s%s", s109_VAL, v2_val, s104_RESET);
	#line 67
	printf("%*c\t", v5_padding, 32u);
	#line 68
	printf("%s\n", v3_desc);
}


#line 72 "src/help.ib"
void s115_option(char * v1_key, char * v2_desc) {
	#line 73
	i64 v3_WIDTH = 24l;
	#line 74
	i64 v4_padding = (v3_WIDTH - ((i64)strlen(v1_key)));
	#line 75
	if ((v4_padding < 0l)) {
		#line 75
		v4_padding = 0l;
	}
	#line 77
	printf("   %s%s%s", s106_CMD, v1_key, s104_RESET);
	#line 78
	printf("%*c\t", v4_padding, 32u);
	#line 79
	printf("%s\n", v2_desc);
}


#line 11 "src/lsp/mod.ib"
i64 s116_run() {
	#line 12
	s466_Context v1_context = s464_new();
	#line 13
	fprintf(((void *)(v1_context.log)), "[INFO] Strike the Earth!\n");
	#line 14
	fflush(((void *)(v1_context.log)));
	#line 16
	while (s450_has_next((&(v1_context.parser)))) {
		#line 17
		if (s451_whitespace((&(v1_context.parser)))) {
			#line 17
			continue;
		}
		#line 19
		s461_Request v2_req = s454_read((&(v1_context.parser)));
		#line 20
		fflush(((void *)(v1_context.log)));
		#line 21
		s472_Status v3_status = s467_handle((&v1_context), (&v2_req));
		#line 23
		if ((v3_status == s472_Status_Exit)) {
			#line 23
						goto loop_exit_1;
/* break; */
		}
		#line 25
		s117_parse_file((&v1_context));
		#line 26
		(v1_context.parse_uri) = ((char *)NULL);
		#line 27
		fflush(((void *)(v1_context.log)));
		#line 29
		s455_free((&v2_req));
		#line 30
		s386_free((&((v1_context.build_result).errors)));
		#line 31
		s246_free((&((v1_context.build_result).ast_modules)));
}
	loop_exit_1:
	#line 34
	fprintf(((void *)(v1_context.log)), "[INFO] Losing is fun!\n");
	#line 35
	s465_free((&v1_context));
	#line 36
	return 0l;
}


#line 43 "src/lsp/mod.ib"
void s117_parse_file(s466_Context * v1_context) {
	#line 44
	if ((((*v1_context).parse_uri) == ((char *)NULL))) {
		#line 44
		return;
	}
	#line 46
	s481_File * v2_file = s479_find((&((*v1_context).files)), ((*v1_context).parse_uri), ((*v1_context).parse_uri_len));
	#line 47
	fprintf(((void *)((*v1_context).log)), "[INFO] found file %s (%d) len: %d!\n", ((*v2_file).uri), ((*v2_file).uri_len), ((*v2_file).length));
	#line 48
	if ((((*v2_file).length) == 0l)) {
		#line 48
		return;
	}
	#line 51
	i64 v3_module = 0l;
	#line 52
	s95_parse_file_content(v3_module, ((*v2_file).uri), ((*v2_file).content), ((*v2_file).length), (&((*v1_context).build_result)));
	#line 54
	s483_publish(v1_context, (&((*v1_context).build_result)), (&((*v1_context).response)));
	#line 56
	s89_clear((&((*v1_context).build_result)));
}


#line 23 "src/storage/strings.ib"
s129_StringArena * s123_create_node(i64 v1_capacity) {
	#line 24
	s129_StringArena * v2_node = ((s129_StringArena *)malloc((32ul + (1ul * ((u64)v1_capacity)))));
	#line 25
	((*v2_node).capacity) = v1_capacity;
	#line 26
	((*v2_node).size) = 0l;
	#line 27
	((*v2_node).next) = ((s129_StringArena *)NULL);
	#line 28
	((*v2_node).content) = ((char *)((void *)(((i64)v2_node) + ((i64)32ul))));
	#line 29
	return v2_node;
}


#line 32 "src/storage/strings.ib"
void s124_init() {
	#line 33
	if (s121_DEBUG_ALLOCATIONS) {
		#line 34
		s122_debug_allocs = s243_new(((i64)8ul), 1024l);
		#line 35
		return;
	}
	#line 37
	s119_head = s123_create_node(1024l);
	#line 38
	s120_tail = s119_head;
}


#line 42 "src/storage/strings.ib"
char * s125_reserve(i64 v1_length) {
	#line 43
	if (s121_DEBUG_ALLOCATIONS) {
		#line 43
		return s128_debug_reserve(v1_length);
	}
	#line 44
	i64 v2_required = (v1_length + 1l);
	#line 45
	if (((((*s120_tail).size) + v2_required) > ((*s120_tail).capacity))) {
		#line 46
		if (s118_DEBUG_ENABLED) {
			#line 46
			printf("Not enough space\n");
		}
		#line 47
		i64 v3_new_capacity = (((*s120_tail).capacity) * 2l);
		#line 48
		if ((v3_new_capacity < v2_required)) {
			#line 49
			v3_new_capacity = (v2_required * 2l);
		}
		#line 51
		if (s118_DEBUG_ENABLED) {
			#line 51
			printf("new capacity: %d\n", v3_new_capacity);
		}
		#line 52
		s129_StringArena * v4_new_tail = s123_create_node(v3_new_capacity);
		#line 53
		((*s120_tail).next) = v4_new_tail;
		#line 54
		s120_tail = v4_new_tail;
	}
	#line 56
	(((*s120_tail).content)[(((*s120_tail).size) + v1_length)]) = 0u;
	#line 57
	char * v5_s = (&(((*s120_tail).content)[((*s120_tail).size)]));
	#line 58
	memset(((void *)v5_s), ((int)0l), ((u64)v1_length));
	#line 59
	((*s120_tail).size) += v2_required;
	#line 60
	return v5_s;
}


#line 64 "src/storage/strings.ib"
char * s126_insert(char * v1_s, i64 v2_length) {
	#line 65
	char * v3_target = s125_reserve(v2_length);
	#line 66
	memcpy(((void *)v3_target), ((void *)v1_s), ((u64)(v2_length * ((i64)1ul))));
	#line 67
	return v3_target;
}


#line 71 "src/storage/strings.ib"
void s127_free() {
	#line 72
	if (s121_DEBUG_ALLOCATIONS) {
		#line 73
		for (i64 v1_i = 0l;(v1_i < (s122_debug_allocs.count));v1_i += 1l) {
			#line 74
			void * * v2_ptr = ((void * *)s251_get((&s122_debug_allocs), v1_i));
			#line 75
			free((*v2_ptr));
		}
		loop_exit_1:
		#line 77
		s246_free((&s122_debug_allocs));
	}
	#line 79
	s129_StringArena * v3_current = s119_head;
	#line 80
	i64 v4_capacity = 0l;
	#line 81
	while ((v3_current != ((s129_StringArena *)NULL))) {
		#line 82
		v4_capacity += ((*v3_current).capacity);
		#line 83
		s129_StringArena * v5_next = ((*v3_current).next);
		#line 84
		free(((void *)v3_current));
		#line 85
		v3_current = v5_next;
}
	loop_exit_2:
	#line 87
	if (s52_usage_stats) {
		#line 88
		printf("StringsArena freeing %d\n", v4_capacity);
	}
}


#line 93 "src/storage/strings.ib"
char * s128_debug_reserve(i64 v1_length) {
	#line 94
	char * v2_s = ((char *)malloc((1ul * ((u64)(v1_length + 32l)))));
	#line 95
	memset(((void *)v2_s), ((int)0l), ((u64)v1_length));
	#line 96
	(v2_s[v1_length]) = 0u;
	#line 97
	void * * v3_stored = ((void * *)s249_push((&s122_debug_allocs)));
	#line 98
	(*v3_stored) = ((void *)v2_s);
	#line 99
	return v2_s;
}


#line 27 "src/storage/identifiers.ib"
i64 s132_count() {
	#line 27
	return (s131_set.count);
}


#line 30 "src/storage/identifiers.ib"
i64 s133_hash(char * v1_s, i64 v2_length) {
	#line 31
	i64 v3_hash = 7l;
	#line 32
	for (i64 v4_i = 0l;(v4_i < v2_length);v4_i += 1l) {
		#line 33
		v3_hash = ((v3_hash * 131l) + ((i64)(v1_s[v4_i])));
	}
	loop_exit_1:
	#line 35
	return v3_hash;
}


#line 39 "src/storage/identifiers.ib"
char * s134_insert(char * v1_identifier, i64 v2_length) {
	#line 40
	if ((((f64)((s131_set.count) + 1l)) > (((f64)(s131_set.capacity)) * 0.750000000000))) {
		#line 41
		s139_expand();
	}
	#line 44
	i64 v3_ident_hash = s133_hash(v1_identifier, v2_length);
	#line 45
	s141_Entry * v4_entry = s138_find_identifier_entry(v1_identifier, v2_length, v3_ident_hash);
	#line 47
	if ((((*v4_entry).ident) != ((char *)NULL))) {
		#line 48
		return ((*v4_entry).ident);
	}
	#line 50
	(s131_set.count) += 1l;
	#line 51
	((*v4_entry).ident) = s126_insert(v1_identifier, v2_length);
	#line 52
	((*v4_entry).length) = v2_length;
	#line 53
	((*v4_entry).hash) = v3_ident_hash;
	#line 54
	if (s130_DEBUG_ENABLED) {
		#line 55
		printf("Inserting \"%s\" (%d/%d)\n", ((*v4_entry).ident), (s131_set.count), (s131_set.capacity));
	}
	#line 57
	return ((*v4_entry).ident);
}


#line 60 "src/storage/identifiers.ib"
char * s135_find(char * v1_identifier) {
	#line 61
	return s134_insert(v1_identifier, ((i64)strlen(v1_identifier)));
}


#line 64 "src/storage/identifiers.ib"
void s136_init() {
}


#line 66 "src/storage/identifiers.ib"
void s137_free() {
	#line 67
	if (s52_usage_stats) {
		#line 68
		printf("Identifier Usage: %d\n", (s131_set.count));
	}
	#line 70
	free(((void *)(s131_set.entries)));
}


#line 74 "src/storage/identifiers.ib"
s141_Entry * s138_find_identifier_entry(char * v1_identifier, i64 v2_length, i64 v3_ident_hash) {
	#line 75
	i64 v4_index = (((v3_ident_hash % (s131_set.capacity)) + (s131_set.capacity)) % (s131_set.capacity));
	#line 76
	while (1) {
		#line 77
		s141_Entry * v5_entry = (&((s131_set.entries)[v4_index]));
		#line 78
		if ((((*v5_entry).ident) == ((char *)NULL))) {
			#line 78
			return v5_entry;
		}
		#line 79
		if (((((*v5_entry).length) == v2_length) && (((*v5_entry).hash) == v3_ident_hash))) {
			#line 80
			if ((((i64)memcmp(((void *)((*v5_entry).ident)), ((void *)v1_identifier), ((u64)v2_length))) == 0l)) {
				#line 81
				return v5_entry;
			}
		}
		#line 84
		v4_index = ((v4_index + 1l) % (s131_set.capacity));
}
	loop_exit_1:
	#line 87
	return ((s141_Entry *)NULL);
}


#line 91 "src/storage/identifiers.ib"
void s139_expand() {
	#line 92
	i64 v1_new_capacity = ((s131_set.capacity) * 2l);
	#line 93
	if ((v1_new_capacity < 256l)) {
		#line 93
		v1_new_capacity = 256l;
	}
	#line 94
	void * v2_entries = malloc((24ul * ((u64)v1_new_capacity)));
	#line 95
	memset(v2_entries, ((int)0l), (24ul * ((u64)v1_new_capacity)));
	#line 97
	(s131_set.count) = 0l;
	#line 98
	for (i64 v3_i = 0l;(v3_i < (s131_set.capacity));v3_i += 1l) {
		#line 99
		s141_Entry * v4_entry = (&((s131_set.entries)[v3_i]));
		#line 100
		if ((((*v4_entry).ident) == ((char *)NULL))) {
			#line 100
			continue;
		}
		#line 102
		s141_Entry * v5_dest = s140_find_next_empty_slot(((s141_Entry *)v2_entries), v1_new_capacity, ((*v4_entry).hash));
		#line 103
		((*v5_dest).hash) = ((*v4_entry).hash);
		#line 104
		((*v5_dest).length) = ((*v4_entry).length);
		#line 105
		((*v5_dest).ident) = ((*v4_entry).ident);
		#line 106
		(s131_set.count) += 1l;
	}
	loop_exit_1:
	#line 108
	free(((void *)(s131_set.entries)));
	#line 109
	(s131_set.capacity) = v1_new_capacity;
	#line 110
	(s131_set.entries) = ((s141_Entry *)v2_entries);
}


#line 114 "src/storage/identifiers.ib"
s141_Entry * s140_find_next_empty_slot(s141_Entry * v1_entries, i64 v2_capacity, i64 v3_hash) {
	#line 115
	i64 v4_index = (((v3_hash % v2_capacity) + v2_capacity) % v2_capacity);
	#line 116
	while ((((v1_entries[v4_index]).ident) != ((char *)NULL))) {
		#line 117
		v4_index = ((v4_index + 1l) % v2_capacity);
}
	loop_exit_1:
	#line 119
	return (&(v1_entries[v4_index]));
}


#line 19 "src/storage/span.ib"
void s144_init() {
	#line 20
	s143_spans = s243_new(((i64)24ul), 4096l);
	#line 21
	s249_push((&s143_spans));
}


#line 25 "src/storage/span.ib"
void s145_free() {
	#line 26
	free(((void *)(s143_spans.items)));
	#line 27
	(s143_spans.count) = 0l;
	#line 28
	(s143_spans.capacity) = 0l;
}


#line 32 "src/storage/span.ib"
s153_Span * s146_get(i64 v1_span) {
	#line 32
	return ((s153_Span *)s251_get((&s143_spans), v1_span));
}


#line 33 "src/storage/span.ib"
i64 s147_count() {
	#line 33
	return (s143_spans.count);
}


#line 36 "src/storage/span.ib"
i64 s148_new(char * v1_file, i64 v2_start, i64 v3_end) {
	#line 37
	i64 v4_index = (s143_spans.count);
	#line 38
	s153_Span * v5_span = ((s153_Span *)s249_push((&s143_spans)));
	#line 39
	((*v5_span).file) = v1_file;
	#line 40
	((*v5_span).start) = v2_start;
	#line 41
	((*v5_span).end) = v3_end;
	#line 42
	return v4_index;
}


#line 46 "src/storage/span.ib"
i64 s149_merge(i64 v1_left, i64 v2_right) {
	#line 47
	if ((v1_left == v2_right)) {
		#line 47
		return v1_left;
	}
	#line 49
	s153_Span * v3_left = s146_get(v1_left);
	#line 50
	s153_Span * v4_right = s146_get(v2_right);
	#line 51
	s40_assert((((*v3_left).file) == ((*v4_right).file)), "span::merge::file mismatch");
	#line 52
	char * v5_file = ((*v3_left).file);
	#line 54
	i64 v6_start = ((*v3_left).start);
	#line 55
	i64 v7_end = ((*v3_left).end);
	#line 56
	if ((v6_start > ((*v4_right).start))) {
		#line 56
		v6_start = ((*v4_right).start);
	}
	#line 57
	if ((v7_end < ((*v4_right).end))) {
		#line 57
		v7_end = ((*v4_right).end);
	}
	#line 58
	i64 v8_new_span = s148_new(v5_file, v6_start, v7_end);
	#line 59
	s146_get(v8_new_span);
	#line 60
	return v8_new_span;
}


#line 71 "src/storage/span.ib"
void s150_write(s299_StringBuilder * v1_sb, i64 v2_span) {
	#line 71
	s151_write_ex(v1_sb, v2_span, ((s154_PrintOptions){

	}));
}


#line 73 "src/storage/span.ib"
void s151_write_ex(s299_StringBuilder * v1_sb, i64 v2_span, s154_PrintOptions v3_options) {
	#line 74
	if ((v2_span == 0l)) {
		#line 74
		return;
	}
	#line 75
	s153_Span * v4_span = s146_get(v2_span);
	#line 77
	s241_File v5_file = s236_read_file(((*v4_span).file));
	#line 78
	if ((!(v5_file.success))) {
		#line 79
		printf("Error: Failed to open file \"%s\"", ((*v4_span).file));
		#line 80
		exit(((int)1l));
	}
	#line 82
	s165_Position v6_position = s160_find_position(((*v4_span).file), ((*v4_span).start));
	#line 83
	i64 v7_line_number = ((v6_position.line) + 1l);
	#line 84
	i64 v8_col = (v6_position.column);
	#line 85
	i64 v9_line_start = (v6_position.line_start);
	#line 86
	i64 v10_line_end = (v6_position.line_end);
	#line 87
	bool v11_use_colors = (v3_options.use_colors);
	#line 89
	((v5_file.content)[v10_line_end]) = 0u;
	#line 91
	i64 v12_line_width = s152_number_width(v7_line_number);
	#line 97
	s288_repeat(v1_sb, " ", v12_line_width);
	#line 98
	s283_append(v1_sb, "  ---> ");
	#line 99
	s283_append(v1_sb, ((*v4_span).file));
	#line 100
	s284_append_char(v1_sb, 58u);
	#line 101
	s289_append_number(v1_sb, v7_line_number);
	#line 102
	s284_append_char(v1_sb, 58u);
	#line 103
	s289_append_number(v1_sb, (v8_col + 1l));
	#line 104
	s284_append_char(v1_sb, 10u);
	#line 107
	if (v11_use_colors) {
		#line 107
		s283_append(v1_sb, s233_BLUE);
	}
	#line 108
	s288_repeat(v1_sb, " ", v12_line_width);
	#line 109
	s283_append(v1_sb, "  |");
	#line 110
	if (v11_use_colors) {
		#line 110
		s283_append(v1_sb, s234_RESET);
	}
	#line 111
	s284_append_char(v1_sb, 10u);
	#line 117
	if (v11_use_colors) {
		#line 117
		s283_append(v1_sb, s233_BLUE);
	}
	#line 118
	s284_append_char(v1_sb, 32u);
	#line 119
	s289_append_number(v1_sb, v7_line_number);
	#line 120
	s284_append_char(v1_sb, 32u);
	#line 121
	s283_append(v1_sb, "| ");
	#line 122
	if (v11_use_colors) {
		#line 122
		s283_append(v1_sb, s234_RESET);
	}
	#line 123
	s283_append(v1_sb, (&((v5_file.content)[v9_line_start])));
	#line 124
	s284_append_char(v1_sb, 10u);
	#line 127
	if (v11_use_colors) {
		#line 127
		s283_append(v1_sb, s233_BLUE);
	}
	#line 128
	s288_repeat(v1_sb, " ", v12_line_width);
	#line 129
	s283_append(v1_sb, "  | ");
	#line 130
	if (v11_use_colors) {
		#line 130
		s283_append(v1_sb, s234_RESET);
	}
	#line 132
	for (i64 v13_i = v9_line_start;(v13_i < ((*v4_span).start));v13_i += 1l) {
		#line 133
		switch (((v5_file.content)[v13_i])) {
		case 9u: {
		s284_append_char(v1_sb, 9u);
		break; }
		default:
 {
		s284_append_char(v1_sb, 32u);
		break; }
}
	}
	loop_exit_1:
	#line 138
	i64 v14_span_width = (((*v4_span).end) - ((*v4_span).start));
	#line 139
	switch ((v3_options.range)) {
	case s155_Range_Start: {
		#line 140
		s284_append_char(v1_sb, 94u);
	break; }
	case s155_Range_Full: {
		#line 142
		for (i64 v15_i = 0l;(v15_i < v14_span_width);v15_i += 1l) {
			#line 142
			s284_append_char(v1_sb, 94u);
		}
		loop_exit_2:
	break; }
	case s155_Range_End: {
		#line 145
		for (i64 v16_i = 0l;(v16_i < (v14_span_width - 1l));v16_i += 1l) {
			#line 145
			s284_append_char(v1_sb, 32u);
		}
		loop_exit_3:
		#line 146
		s284_append_char(v1_sb, 94u);
	break; }
	default:
		abort();
}
	#line 149
	if (((v3_options.pointer_message) != ((char *)NULL))) {
		#line 150
		s284_append_char(v1_sb, 32u);
		#line 151
		s283_append(v1_sb, (v3_options.pointer_message));
	}
	#line 153
	s284_append_char(v1_sb, 10u);
	#line 155
	s238_free((&v5_file));
}


#line 159 "src/storage/span.ib"
i64 s152_number_width(i64 v1_n) {
	#line 160
	if ((v1_n == 0l)) {
		#line 160
		return 1l;
	}
	#line 161
	i64 v2_width = 0l;
	#line 162
	if ((v1_n < 0l)) {
		#line 162
		v1_n *= (-1l);
		#line 162
		v2_width += 1l;
	}
	#line 163
	while ((v1_n > 0l)) {
		#line 164
		v2_width += 1l;
		#line 165
		v1_n /= 10l;
}
	loop_exit_1:
	#line 167
	return v2_width;
}


#line 26 "src/storage/filemeta.ib"
void s157_init() {
	#line 27
	s156_filemetas = s487_new(((i64)8ul), ((i64)56ul), ((i64 (*)(void *))s163_file_hash), ((bool (*)(void *, void *))s164_file_eq));
}


#line 35 "src/storage/filemeta.ib"
void s158_free() {
	#line 36
	for (s501_HashMapIter v1_iter = s495_iter((&s156_filemetas));s496_has_next((&v1_iter));s497_next((&v1_iter))) {
		#line 40
		s166_FileMeta * v2_meta = ((s166_FileMeta *)(v1_iter.value));
		#line 41
		s246_free((&((*v2_meta).line_starts)));
	}
	loop_exit_1:
	#line 44
	s491_free((&s156_filemetas));
}


#line 48 "src/storage/filemeta.ib"
s166_FileMeta * s159_create(char * v1_file, i64 v2_length) {
	#line 49
	s40_assert((v1_file != ((char *)NULL)), "filemeta::create");
	#line 50
	s167_Key v3_key = ((s167_Key){
		.file = v1_file
	});
	#line 51
	s166_FileMeta * v4_meta = ((s166_FileMeta *)s490_find_or_insert((&s156_filemetas), ((void *)(&v3_key))));
	#line 52
	((*v4_meta).file) = v1_file;
	#line 53
	((*v4_meta).length) = v2_length;
	#line 54
	if (((((*v4_meta).line_starts).items) == ((char *)NULL))) {
		#line 55
		((*v4_meta).line_starts) = s243_new(((i64)8ul), (v2_length / 30l));
	} else {
#line 57
		s248_clear((&((*v4_meta).line_starts)));
	}
	#line 59
	printf("CREATE FILEMETA: %s %d\n", v1_file, v2_length);
	#line 60
	return v4_meta;
}


#line 64 "src/storage/filemeta.ib"
s165_Position s160_find_position(char * v1_file, i64 v2_offset) {
	#line 65
	s40_assert((v1_file != ((char *)NULL)), "filemeta::find_position null");
	#line 66
	s166_FileMeta * v3_file = s161_get(v1_file);
	#line 67
	if (((v2_offset <= 0l) || (v2_offset >= ((*v3_file).length)))) {
		#line 68
		printf("OUTSIDE FILE: offset: %d filelen: %d %s\n", v2_offset, ((*v3_file).length), ((*v3_file).file));
		#line 69
		return ((s165_Position){
			.line = 0l,
			.column = 0l,
			.line_start = 0l,
			.line_end = (s162_line_start(v3_file, 1l) - 1l)
		});
	}
	#line 77
	i64 v4_min = 0l;
	#line 78
	i64 v5_max = (((*v3_file).line_starts).count);
	#line 79
	while (1) {
		#line 80
		i64 v6_line = (v4_min + ((v5_max - v4_min) / 2l));
		#line 81
		i64 v7_start = s162_line_start(v3_file, v6_line);
		#line 82
		i64 v8_end = s162_line_start(v3_file, (v6_line + 1l));
		#line 83
		if ((v7_start > v2_offset)) {
			#line 84
			v5_max = v6_line;
			#line 85
			continue;
		}
		#line 87
		if ((v8_end <= v2_offset)) {
			#line 88
			v4_min = v6_line;
			#line 89
			continue;
		}
		#line 91
		return ((s165_Position){
			.line = v6_line,
			.column = (v2_offset - v7_start),
			.line_start = v7_start,
			.line_end = (v8_end - 1l)
		});
}
	loop_exit_1:
	#line 98
	abort();
}


#line 102 "src/storage/filemeta.ib"
s166_FileMeta * s161_get(char * v1_file) {
	#line 103
	s40_assert((v1_file != ((char *)NULL)), "filemeta::get");
	#line 104
	s167_Key v2_key = ((s167_Key){
		.file = v1_file
	});
	#line 105
	s166_FileMeta * v3_meta = ((s166_FileMeta *)s488_find((&s156_filemetas), ((void *)(&v2_key))));
	#line 106
	s40_assert((v3_meta != ((s166_FileMeta *)NULL)), "filemeta::get not added");
	#line 107
	s40_assert((((*v3_meta).file) != ((char *)NULL)), "filemeta::get unitialized");
	#line 108
	return v3_meta;
}


#line 112 "src/storage/filemeta.ib"
i64 s162_line_start(s166_FileMeta * v1_meta, i64 v2_line) {
	#line 113
	if ((v2_line >= (((*v1_meta).line_starts).count))) {
		#line 113
		return ((*v1_meta).length);
	}
	#line 114
	return (*((i64 *)s251_get((&((*v1_meta).line_starts)), v2_line)));
}


#line 118 "src/storage/filemeta.ib"
i64 s163_file_hash(s167_Key v1_key) {
	#line 119
	i64 v2_hash = 107l;
	#line 120
	char * v3_file = (v1_key.file);
	#line 121
	for (i64 v4_i = 0l;((v3_file[v4_i]) != 0u);v4_i += 1l) {
		#line 122
		v2_hash += (((i64)(v3_file[v4_i])) * 31l);
	}
	loop_exit_1:
	#line 124
	return v2_hash;
}


#line 128 "src/storage/filemeta.ib"
bool s164_file_eq(s167_Key v1_left, s167_Key v2_right) {
	#line 129
	char * v3_left = (v1_left.file);
	#line 130
	char * v4_right = (v2_right.file);
	#line 131
	return (((i64)strcmp(v3_left, v4_right)) == 0l);
}


#line 21 "src/symbol/mod.ib"
bool s170_is_none(s201_UID v1_uid) {
	#line 21
	return ((v1_uid.symbol) == 0l);
}


#line 22 "src/symbol/mod.ib"
bool s171_eq(s201_UID v1_lhs, s201_UID v2_rhs) {
	#line 23
	if (((v1_lhs.symbol) != (v2_rhs.symbol))) {
		#line 24
		return false;
	}
	#line 26
	s40_assert(((v1_lhs.module) == (v2_rhs.module)), "symbol matched, but module did not!");
	#line 27
	s40_assert(((v1_lhs.index) == (v2_rhs.index)), "symbol matched, but index did not!");
	#line 28
	return true;
}


#line 32 "src/symbol/mod.ib"
void s172_assert_exists(s201_UID v1_symbol) {
	#line 33
	s40_assert((!s170_is_none(v1_symbol)), "symbol was NONE!");
	#line 34
	s540_Symbol * v2_symbol = s370_get_symbol((&s169_symbol_table), v1_symbol);
	#line 35
	s40_assert((v2_symbol != ((s540_Symbol *)NULL)), "symbol was null!");
}


#line 40 "src/symbol/mod.ib"
void s173_init() {
	#line 40
	s169_symbol_table = s367_new();
}


#line 41 "src/symbol/mod.ib"
void s174_free() {
	#line 41
	s368_free((&s169_symbol_table));
}


#line 44 "src/symbol/mod.ib"
i64 s175_insert_module(char * v1_module) {
	#line 45
	i64 v2_uid = s371_insert_module((&s169_symbol_table), v1_module);
	#line 46
	return v2_uid;
}


#line 50 "src/symbol/mod.ib"
s201_UID s176_insert(i64 v1_module, char * v2_name, bool v3_is_public, bool v4_is_extern, s544_SymbolKind v5_kind, i64 v6_span) {
	#line 58
	s201_UID v7_symbol = s369_create_symbol((&s169_symbol_table), v1_module, v2_name, v5_kind, v6_span, v3_is_public, v4_is_extern);
	#line 62
	return v7_symbol;
}


#line 66 "src/symbol/mod.ib"
void s177_insert_imports(i64 v1_module, s257_Vec * v2_imports) {
	#line 70
	s377_ModuleMeta * v3_meta = ((s377_ModuleMeta *)s251_get((&(s169_symbol_table.modules)), v1_module));
	#line 71
	((*v3_meta).import_index) = ((s169_symbol_table.imports).count);
	#line 72
	((*v3_meta).import_length) = ((*v2_imports).count);
	#line 73
	s372_insert_imports((&s169_symbol_table), v2_imports);
}


#line 77 "src/symbol/mod.ib"
s201_UID s178_find_symbol(i64 v1_module_uid, char * v2_name) {
	#line 78
	return s373_find_symbol((&s169_symbol_table), v1_module_uid, v2_name);
}


#line 82 "src/symbol/mod.ib"
s377_ModuleMeta * s179_get_module_meta(i64 v1_module) {
	#line 83
	return ((s377_ModuleMeta *)s251_get((&(s169_symbol_table.modules)), v1_module));
}


#line 86 "src/symbol/mod.ib"
s376_ModuleImport * s180_get_module_import(s377_ModuleMeta * v1_meta, i64 v2_index) {
	#line 87
	return ((s376_ModuleImport *)s251_get((&(s169_symbol_table.imports)), (((*v1_meta).import_index) + v2_index)));
}


#line 91 "src/symbol/mod.ib"
void s181_attach_shallow(s201_UID v1_symbol, s541_ShallowInfo v2_info) {
	#line 92
	s540_Symbol * v3_symbol = s370_get_symbol((&s169_symbol_table), v1_symbol);
	#line 93
	s40_assert((v3_symbol != ((s540_Symbol *)NULL)), "attach_shallow symbol not found");
	#line 94
	((*v3_symbol).shallow) = v2_info;
	#line 95
	((*v3_symbol).stage) = s543_SymbolStage_SymbolResolved;
}


#line 99 "src/symbol/mod.ib"
void s182_attach_deep(s201_UID v1_symbol, s542_DeepInfo v2_info) {
	#line 100
	s540_Symbol * v3_symbol = s370_get_symbol((&s169_symbol_table), v1_symbol);
	#line 101
	s40_assert((v3_symbol != ((s540_Symbol *)NULL)), "attach_deep symbol not found");
	#line 102
	((*v3_symbol).deep) = v2_info;
}


#line 107 "src/symbol/mod.ib"
s542_DeepInfo s183_get_deep(s201_UID v1_symbol) {
	#line 108
	s540_Symbol * v2_symbol = s370_get_symbol((&s169_symbol_table), v1_symbol);
	#line 109
	s40_assert((v2_symbol != ((s540_Symbol *)NULL)), "get_deep symbol not found");
	#line 110
	return ((*v2_symbol).deep);
}


#line 113 "src/symbol/mod.ib"
s541_ShallowInfo s184_get_shallow(s201_UID v1_symbol) {
	#line 114
	s540_Symbol * v2_symbol = s370_get_symbol((&s169_symbol_table), v1_symbol);
	#line 115
	s40_assert((v2_symbol != ((s540_Symbol *)NULL)), "get_deep symbol not found");
	#line 116
	return ((*v2_symbol).shallow);
}


#line 118 "src/symbol/mod.ib"
void s185_set_type(s201_UID v1_symbol, s528_TypeIdent * v2_type) {
	#line 119
	s540_Symbol * v3_symbol = s370_get_symbol((&s169_symbol_table), v1_symbol);
	#line 120
	s40_assert((v3_symbol != ((s540_Symbol *)NULL)), "set_type symbol not found");
	#line 121
	((*v3_symbol).type) = v2_type;
}


#line 123 "src/symbol/mod.ib"
s528_TypeIdent * s186_get_type(s201_UID v1_symbol) {
	#line 124
	s540_Symbol * v2_symbol = s370_get_symbol((&s169_symbol_table), v1_symbol);
	#line 125
	s40_assert((v2_symbol != ((s540_Symbol *)NULL)), "set_type symbol not found");
	#line 126
	return ((*v2_symbol).type);
}


#line 128 "src/symbol/mod.ib"
void s187_set_stage(s201_UID v1_symbol, s543_SymbolStage v2_stage) {
	#line 129
	s540_Symbol * v3_symbol = s370_get_symbol((&s169_symbol_table), v1_symbol);
	#line 130
	s40_assert((v3_symbol != ((s540_Symbol *)NULL)), "set_stage symbol not found");
	#line 131
	((*v3_symbol).stage) = v2_stage;
}


#line 133 "src/symbol/mod.ib"
bool s188_stage_eq(s201_UID v1_symbol, s543_SymbolStage v2_stage) {
	#line 134
	s540_Symbol * v3_symbol = s370_get_symbol((&s169_symbol_table), v1_symbol);
	#line 135
	s40_assert((v3_symbol != ((s540_Symbol *)NULL)), "stage symbol not found");
	#line 136
	return (((*v3_symbol).stage) == v2_stage);
}


#line 139 "src/symbol/mod.ib"
void s189_assert_kind(s201_UID v1_symbol, s544_SymbolKind v2_kind, char * v3_message) {
	#line 140
	s540_Symbol * v4_symbol = s370_get_symbol((&s169_symbol_table), v1_symbol);
	#line 141
	s40_assert((v4_symbol != ((s540_Symbol *)NULL)), "assert_kind symbol not found");
	#line 142
	s40_assert((((*v4_symbol).kind) == v2_kind), v3_message);
}


#line 145 "src/symbol/mod.ib"
s544_SymbolKind s190_kind(s201_UID v1_symbol) {
	#line 146
	s540_Symbol * v2_symbol = s370_get_symbol((&s169_symbol_table), v1_symbol);
	#line 147
	s40_assert((v2_symbol != ((s540_Symbol *)NULL)), "symbol::kind symbol not found");
	#line 148
	return ((*v2_symbol).kind);
}


#line 150 "src/symbol/mod.ib"
bool s191_is_extern(s201_UID v1_symbol) {
	#line 151
	s540_Symbol * v2_symbol = s370_get_symbol((&s169_symbol_table), v1_symbol);
	#line 152
	s40_assert((v2_symbol != ((s540_Symbol *)NULL)), "symbol::is_extern symbol not found");
	#line 153
	return ((*v2_symbol).is_extern);
}


#line 155 "src/symbol/mod.ib"
bool s192_is_public(s201_UID v1_symbol) {
	#line 156
	s540_Symbol * v2_symbol = s370_get_symbol((&s169_symbol_table), v1_symbol);
	#line 157
	s40_assert((v2_symbol != ((s540_Symbol *)NULL)), "symbol::is_public symbol not found");
	#line 158
	return ((*v2_symbol).is_public);
}


#line 160 "src/symbol/mod.ib"
i64 s193_span(s201_UID v1_symbol) {
	#line 161
	s540_Symbol * v2_symbol = s370_get_symbol((&s169_symbol_table), v1_symbol);
	#line 162
	s40_assert((v2_symbol != ((s540_Symbol *)NULL)), "symbol::span symbol not found");
	#line 163
	return ((*v2_symbol).span);
}


#line 165 "src/symbol/mod.ib"
char * s194_name(s201_UID v1_symbol) {
	#line 166
	s540_Symbol * v2_symbol = s370_get_symbol((&s169_symbol_table), v1_symbol);
	#line 167
	s40_assert((v2_symbol != ((s540_Symbol *)NULL)), "symbol::name symbol not found");
	#line 168
	return ((*v2_symbol).name);
}


#line 171 "src/symbol/mod.ib"
void s195_preserve_name(s201_UID v1_symbol) {
	#line 172
	s540_Symbol * v2_symbol = s370_get_symbol((&s169_symbol_table), v1_symbol);
	#line 173
	s40_assert((v2_symbol != ((s540_Symbol *)NULL)), "symbol::name symbol not found");
	#line 174
	((*v2_symbol).preserve_name) = true;
}


#line 176 "src/symbol/mod.ib"
bool s196_is_preserve_name(s201_UID v1_symbol) {
	#line 177
	s540_Symbol * v2_symbol = s370_get_symbol((&s169_symbol_table), v1_symbol);
	#line 178
	s40_assert((v2_symbol != ((s540_Symbol *)NULL)), "symbol::name symbol not found");
	#line 179
	return ((*v2_symbol).preserve_name);
}


#line 183 "src/symbol/mod.ib"
void s197_debug_all() {
	#line 184
	s374_debug((&s169_symbol_table));
}


#line 187 "src/symbol/mod.ib"
void s198_debug_all_head() {
	#line 188
	s375_debug_heads((&s169_symbol_table));
}


#line 192 "src/symbol/mod.ib"
void s199_debug(s201_UID v1_symbol) {
	#line 193
	s540_Symbol * v2_symbol = s370_get_symbol((&s169_symbol_table), v1_symbol);
	#line 194
	s536_debug(v2_symbol);
}


#line 196 "src/symbol/mod.ib"
void s200_debug_head(s299_StringBuilder * v1_sb, s201_UID v2_symbol) {
	#line 197
	s540_Symbol * v3_symbol = s370_get_symbol((&s169_symbol_table), v2_symbol);
	#line 198
	s539_debug_head(v1_sb, v3_symbol);
}


#line 80 "src/ast/typeident.ib"
s218_TypeIdents s202_new(i64 v1_module_uid) {
	#line 81
	s576_HashSet v2_types_set = s568_new(((i64)8ul), ((i64 (*)(void *))s208_typeident_hash), ((bool (*)(void *, void *))s209_typeident_eq));
	#line 82
	s566_Arena v3_types_arena = s560_new(64l);
	#line 83
	return ((s218_TypeIdents){
		.types_arena = v3_types_arena,
		.types_set = v2_types_set,
		.module_uid = v1_module_uid
	});
}


#line 90 "src/ast/typeident.ib"
void s203_free(s218_TypeIdents * v1_type_idents) {
	#line 91
	s571_free((&((*v1_type_idents).types_set)));
	#line 92
	i64 v2_total_freed = s562_free((&((*v1_type_idents).types_arena)));
	#line 93
	if (s52_usage_stats) {
		#line 94
		printf("TypeIdentArena freed %d\n", v2_total_freed);
	}
}


#line 100 "src/ast/typeident.ib"
s214_TypeIdent * s204_atomic(s218_TypeIdents * v1_type_idents, s222_AtomicType v2_atomic_ty) {
	#line 101
	s214_TypeIdent v3_ty = ((s214_TypeIdent){

	});
	#line 102
	(v3_ty.kind) = s221_TypeKind_Atomic;
	#line 103
	((v3_ty.data).atomic) = v2_atomic_ty;
	#line 104
	return s205_find_or_insert(v1_type_idents, (&v3_ty));
}


#line 108 "src/ast/typeident.ib"
s214_TypeIdent * s205_find_or_insert(s218_TypeIdents * v1_type_idents, s214_TypeIdent * v2_type) {
	#line 109
	s214_TypeIdent * * v3_existing = ((s214_TypeIdent * *)s569_find((&((*v1_type_idents).types_set)), ((void *)(&v2_type))));
	#line 110
	if ((v3_existing != ((s214_TypeIdent * *)NULL))) {
		#line 111
		return (*v3_existing);
	}
	#line 113
	s214_TypeIdent * v4_permanent = s207_allocate_typeident(v1_type_idents, v2_type);
	#line 114
	s570_find_or_insert((&((*v1_type_idents).types_set)), ((void *)(&v4_permanent)));
	#line 115
	return v4_permanent;
}


#line 118 "src/ast/typeident.ib"
bool s206_is_anyptr(s214_TypeIdent * v1_type) {
	#line 119
	return ((((*v1_type).kind) == s221_TypeKind_Pointer) && ((((*v1_type).data).pointer) == ((s214_TypeIdent *)NULL)));
}


#line 124 "src/ast/typeident.ib"
s214_TypeIdent * s207_allocate_typeident(s218_TypeIdents * v1_typeidents, s214_TypeIdent * v2_type) {
	#line 125
	s214_TypeIdent * v3_new_type = ((s214_TypeIdent *)s561_allocate((&((*v1_typeidents).types_arena)), ((i64)48ul)));
	#line 126
	((*v3_new_type).kind) = ((*v2_type).kind);
	#line 127
	switch (((*v3_new_type).kind)) {
	case s221_TypeKind_Atomic: {
		#line 129
		(((*v3_new_type).data).atomic) = (((*v2_type).data).atomic);
	break; }
	case s221_TypeKind_Pointer: {
		#line 132
		(((*v3_new_type).data).pointer) = (((*v2_type).data).pointer);
	break; }
	case s221_TypeKind_Compound: {
		#line 135
		s215_CompoundType * v4_src = (&(((*v2_type).data).compound));
		#line 136
		s215_CompoundType * v5_dest = (&(((*v3_new_type).data).compound));
		#line 137
		i64 v6_len = ((*v4_src).path_length);
		#line 138
		u64 v7_size = (8ul * ((u64)v6_len));
		#line 139
		((*v5_dest).path_length) = v6_len;
		#line 140
		((*v5_dest).path) = ((char * *)s561_allocate((&((*v1_typeidents).types_arena)), ((i64)v7_size)));
		#line 141
		memcpy(((void *)((*v5_dest).path)), ((void *)((*v4_src).path)), v7_size);
	break; }
	case s221_TypeKind_Array: {
		#line 144
		s216_ArrayType * v8_src = (&(((*v2_type).data).array));
		#line 145
		s216_ArrayType * v9_dest = (&(((*v3_new_type).data).array));
		#line 146
		i64 v10_len = ((*v8_src).dimension_length);
		#line 147
		u64 v11_size = (8ul * ((u64)v10_len));
		#line 148
		((*v9_dest).parent) = ((*v8_src).parent);
		#line 149
		((*v9_dest).dimension_length) = v10_len;
		#line 150
		((*v9_dest).dimensions) = ((i64 *)s561_allocate((&((*v1_typeidents).types_arena)), ((i64)v11_size)));
		#line 151
		memcpy(((void *)((*v9_dest).dimensions)), ((void *)((*v8_src).dimensions)), v11_size);
	break; }
	case s221_TypeKind_Function: {
		#line 154
		s217_FunctionType * v12_src = (&(((*v2_type).data).function));
		#line 155
		s217_FunctionType * v13_dest = (&(((*v3_new_type).data).function));
		#line 156
		i64 v14_len = ((*v12_src).args_length);
		#line 157
		s214_TypeIdent * * v15_args = ((*v12_src).args);
		#line 158
		u64 v16_size = (8ul * ((u64)v14_len));
		#line 160
		((*v13_dest).return_ty) = ((*v12_src).return_ty);
		#line 161
		((*v13_dest).has_varargs) = ((*v12_src).has_varargs);
		#line 162
		((*v13_dest).args_length) = v14_len;
		#line 163
		((*v13_dest).args) = ((s214_TypeIdent * *)s561_allocate((&((*v1_typeidents).types_arena)), ((i64)v16_size)));
		#line 164
		memcpy(((void *)((*v13_dest).args)), ((void *)v15_args), v16_size);
	break; }
	default:
		abort();
}
	#line 167
	return v3_new_type;
}


#line 170 "src/ast/typeident.ib"
i64 s208_typeident_hash(s214_TypeIdent * * v1_ident) {
	#line 171
	s214_TypeIdent * v2_ident = (*v1_ident);
	#line 172
	i64 v3_h = ((i64)((*v2_ident).kind));
	#line 173
	switch (((*v2_ident).kind)) {
	case s221_TypeKind_Atomic: {
		#line 174
		v3_h = ((v3_h * 31l) + ((i64)(((*v2_ident).data).atomic)));
	break; }
	case s221_TypeKind_Pointer: {
		#line 175
		v3_h = ((v3_h * 31l) + ((i64)(((*v2_ident).data).pointer)));
	break; }
	case s221_TypeKind_Compound: {
		#line 176
		v3_h = ((v3_h * 31l) + ((((*v2_ident).data).compound).path_length));
	break; }
	case s221_TypeKind_Array: {
		#line 178
		v3_h = ((v3_h * 31l) + ((i64)((((*v2_ident).data).array).parent)));
		#line 179
		v3_h = ((v3_h * 31l) + ((i64)((((*v2_ident).data).array).dimension_length)));
	break; }
	case s221_TypeKind_Function: {
		#line 182
		v3_h = ((v3_h * 31l) + ((i64)((((*v2_ident).data).function).args_length)));
		#line 183
		v3_h *= 31l;
		#line 184
		if (((((*v2_ident).data).function).has_varargs)) {
			#line 184
			v3_h += 1l;
		}
		#line 185
		v3_h = ((v3_h * 31l) + ((i64)(((((*v2_ident).data).function).return_ty).kind)));
	break; }
	default:
		abort();
}
	#line 188
	return v3_h;
}


#line 191 "src/ast/typeident.ib"
bool s209_typeident_eq(s214_TypeIdent * * v1_lhs, s214_TypeIdent * * v2_rhs) {
	#line 192
	s214_TypeIdent * v3_lhs = (*v1_lhs);
	#line 193
	s214_TypeIdent * v4_rhs = (*v2_rhs);
	#line 194
	if ((((*v3_lhs).kind) != ((*v4_rhs).kind))) {
		#line 194
		return false;
	}
	#line 195
	switch (((*v3_lhs).kind)) {
	case s221_TypeKind_Atomic: {
		#line 196
		return ((((*v3_lhs).data).atomic) == (((*v4_rhs).data).atomic));
	break; }
	case s221_TypeKind_Pointer: {
		#line 197
		return ((((*v3_lhs).data).pointer) == (((*v4_rhs).data).pointer));
	break; }
	case s221_TypeKind_Compound: {
		#line 199
		i64 v5_len = ((((*v3_lhs).data).compound).path_length);
		#line 200
		if ((v5_len != ((((*v4_rhs).data).compound).path_length))) {
			#line 200
			return false;
		}
		#line 201
		for (i64 v6_i = 0l;(v6_i < v5_len);v6_i += 1l) {
			#line 202
			if (((((((*v3_lhs).data).compound).path)[v6_i]) != (((((*v4_rhs).data).compound).path)[v6_i]))) {
				#line 203
				return false;
			}
		}
		loop_exit_1:
		#line 206
		return true;
	break; }
	case s221_TypeKind_Array: {
		#line 209
		if ((((((*v3_lhs).data).array).parent) != ((((*v4_rhs).data).array).parent))) {
			#line 209
			return false;
		}
		#line 210
		i64 v7_len = ((((*v3_lhs).data).array).dimension_length);
		#line 211
		if ((v7_len != ((((*v4_rhs).data).array).dimension_length))) {
			#line 211
			return false;
		}
		#line 213
		for (i64 v8_i = 0l;(v8_i < v7_len);v8_i += 1l) {
			#line 214
			if (((((((*v3_lhs).data).array).dimensions)[v8_i]) != (((((*v4_rhs).data).array).dimensions)[v8_i]))) {
				#line 215
				return false;
			}
		}
		loop_exit_2:
		#line 218
		return true;
	break; }
	case s221_TypeKind_Function: {
		#line 221
		s217_FunctionType * v9_lhs = (&(((*v3_lhs).data).function));
		#line 222
		s217_FunctionType * v10_rhs = (&(((*v4_rhs).data).function));
		#line 223
		if (((((*v9_lhs).return_ty).kind) != (((*v10_rhs).return_ty).kind))) {
			#line 223
			return false;
		}
		#line 224
		if ((((*v9_lhs).args_length) != ((*v10_rhs).args_length))) {
			#line 224
			return false;
		}
		#line 225
		if ((((*v9_lhs).has_varargs) != ((*v10_rhs).has_varargs))) {
			#line 225
			return false;
		}
		#line 226
		if (((((*v9_lhs).return_ty).kind) == s220_FlowTypeKind_Some)) {
			#line 227
			if ((!s209_typeident_eq((&(((*v9_lhs).return_ty).type)), (&(((*v10_rhs).return_ty).type))))) {
				#line 228
				return false;
			}
		}
		#line 231
		i64 v11_len = ((*v9_lhs).args_length);
		#line 232
		for (i64 v12_i = 0l;(v12_i < v11_len);v12_i += 1l) {
			#line 233
			if ((!s209_typeident_eq((&(((*v9_lhs).args)[v12_i])), (&(((*v10_rhs).args)[v12_i]))))) {
				#line 234
				return false;
			}
		}
		loop_exit_3:
		#line 237
		return true;
	break; }
	default:
		abort();
}
}


#line 244 "src/ast/typeident.ib"
void s210_debug(s299_StringBuilder * v1_sb, s585_Nodes * v2_nodes, s214_TypeIdent * v3_type, i64 v4_depth) {
	#line 245
	s40_assert((v3_type != ((s214_TypeIdent *)NULL)), "null passed!");
	#line 246
	switch (((*v3_type).kind)) {
	case s221_TypeKind_Atomic: {
	s212_debug_atomic(v1_sb, (((*v3_type).data).atomic));
	break; }
	case s221_TypeKind_Pointer: {
		#line 249
		if (s206_is_anyptr(v3_type)) {
			#line 250
			s283_append(v1_sb, "*any");
		} else {
#line 252
			s283_append(v1_sb, "(*");
			#line 253
			s210_debug(v1_sb, v2_nodes, (((*v3_type).data).pointer), v4_depth);
			#line 254
			s283_append(v1_sb, ")");
		}
	break; }
	case s221_TypeKind_Compound: {
		#line 258
		s283_append(v1_sb, "(");
		#line 259
		for (i64 v5_i = 0l;(v5_i < ((((*v3_type).data).compound).path_length));v5_i += 1l) {
			#line 260
			if ((v5_i > 0l)) {
				#line 260
				s283_append(v1_sb, "::");
			}
			#line 261
			s283_append(v1_sb, (((((*v3_type).data).compound).path)[v5_i]));
		}
		loop_exit_1:
		#line 263
		s283_append(v1_sb, ")");
	break; }
	case s221_TypeKind_Array: {
		#line 266
		s283_append(v1_sb, "(");
		#line 267
		s210_debug(v1_sb, v2_nodes, ((((*v3_type).data).array).parent), v4_depth);
		#line 268
		for (i64 v6_i = 0l;(v6_i < ((((*v3_type).data).array).dimension_length));v6_i += 1l) {
			#line 269
			s283_append(v1_sb, "[\n");
			#line 270
			i64 v7_dim_node = (((((*v3_type).data).array).dimensions)[v6_i]);
			#line 271
			if ((v7_dim_node != s577_NONE)) {
				#line 272
				s584_debug(v1_sb, v2_nodes, (((((*v3_type).data).array).dimensions)[v6_i]), (v4_depth + 2l));
			}
			#line 274
			s288_repeat(v1_sb, "  ", v4_depth);
			#line 275
			s283_append(v1_sb, "]");
		}
		loop_exit_2:
		#line 277
		s283_append(v1_sb, ")");
	break; }
	case s221_TypeKind_Function: {
		#line 280
		s217_FunctionType * v8_fn_type = (&(((*v3_type).data).function));
		#line 281
		s283_append(v1_sb, "fn(");
		#line 282
		for (i64 v9_i = 0l;(v9_i < ((*v8_fn_type).args_length));v9_i += 1l) {
			#line 283
			if ((v9_i > 0l)) {
				#line 283
				s283_append(v1_sb, ", ");
			}
			#line 284
			s210_debug(v1_sb, v2_nodes, (((*v8_fn_type).args)[v9_i]), v4_depth);
		}
		loop_exit_3:
		#line 286
		if (((*v8_fn_type).has_varargs)) {
			#line 287
			if ((((*v8_fn_type).args_length) > 0l)) {
				#line 287
				s283_append(v1_sb, ", ");
			}
			#line 288
			s283_append(v1_sb, "...");
		}
		#line 290
		s283_append(v1_sb, "): ");
		#line 291
		s211_debug_flowtype(v1_sb, v2_nodes, (&((*v8_fn_type).return_ty)), v4_depth);
	break; }
	default:
		abort();
}
}


#line 297 "src/ast/typeident.ib"
void s211_debug_flowtype(s299_StringBuilder * v1_sb, s585_Nodes * v2_nodes, s213_FlowType * v3_flow_type, i64 v4_depth) {
	#line 298
	switch (((*v3_flow_type).kind)) {
	case s220_FlowTypeKind_Some: {
	s210_debug(v1_sb, v2_nodes, ((*v3_flow_type).type), v4_depth);
	break; }
	case s220_FlowTypeKind_Void: {
	s283_append(v1_sb, "void");
	break; }
	case s220_FlowTypeKind_Never: {
	s283_append(v1_sb, "!");
	break; }
	default:
		abort();
}
}


#line 306 "src/ast/typeident.ib"
void s212_debug_atomic(s299_StringBuilder * v1_sb, s222_AtomicType v2_atomic) {
	#line 307
	switch (v2_atomic) {
	case s222_AtomicType_Bool: {
	s283_append(v1_sb, "bool");
	break; }
	case s222_AtomicType_U8: {
	s283_append(v1_sb, "u8");
	break; }
	case s222_AtomicType_U16: {
	s283_append(v1_sb, "u16");
	break; }
	case s222_AtomicType_U32: {
	s283_append(v1_sb, "u32");
	break; }
	case s222_AtomicType_U64: {
	s283_append(v1_sb, "u64");
	break; }
	case s222_AtomicType_U128: {
	s283_append(v1_sb, "u128");
	break; }
	case s222_AtomicType_I8: {
	s283_append(v1_sb, "i8");
	break; }
	case s222_AtomicType_I16: {
	s283_append(v1_sb, "i16");
	break; }
	case s222_AtomicType_I32: {
	s283_append(v1_sb, "i32");
	break; }
	case s222_AtomicType_I64: {
	s283_append(v1_sb, "i64");
	break; }
	case s222_AtomicType_I128: {
	s283_append(v1_sb, "i128");
	break; }
	case s222_AtomicType_F32: {
	s283_append(v1_sb, "f32");
	break; }
	case s222_AtomicType_F64: {
	s283_append(v1_sb, "f64");
	break; }
	default:
		abort();
}
}


#line 81 "src/ast/error.ib"
void s223_append_message(s299_StringBuilder * v1_sb, s226_ErrorKind v2_error) {
	#line 82
	switch (v2_error) {
	case s226_ErrorKind_DuplicateSymbol: {
	s283_append(v1_sb, "DuplicateSymbol");
	break; }
	case s226_ErrorKind_UnterminatedBlock: {
	s283_append(v1_sb, "UnterminatedBlock");
	break; }
	case s226_ErrorKind_UnterminatedParen: {
	s283_append(v1_sb, "UnterminatedParen");
	break; }
	case s226_ErrorKind_UnterminatedBracket: {
	s283_append(v1_sb, "UnterminatedBracket");
	break; }
	case s226_ErrorKind_SemicolonExpected: {
	s283_append(v1_sb, "SemicolonExpected");
	break; }
	case s226_ErrorKind_BlockExpected: {
	s283_append(v1_sb, "BlockExpected");
	break; }
	case s226_ErrorKind_CommaExpected: {
	s283_append(v1_sb, "CommaExpected");
	break; }
	case s226_ErrorKind_InvalidPrimary: {
	s283_append(v1_sb, "Expression expected");
	break; }
	case s226_ErrorKind_IdentifierExpected: {
	s283_append(v1_sb, "IdentifierExpected");
	break; }
	case s226_ErrorKind_VarDeclEqExpected: {
	s283_append(v1_sb, "VarDeclEqExpected");
	break; }
	case s226_ErrorKind_SizeOfMissingParenL: {
	s283_append(v1_sb, "SizeOfMissingParenL");
	break; }
	case s226_ErrorKind_SizeOfMissingParenR: {
	s283_append(v1_sb, "SizeOfMissingParenR");
	break; }
	case s226_ErrorKind_DuplicatePubForDeclaration: {
	s283_append(v1_sb, "DuplicatePubForDeclaration");
	break; }
	case s226_ErrorKind_UnknownDeclaration: {
	s283_append(v1_sb, "UnknownDeclaration");
	break; }
	case s226_ErrorKind_ImportCannotBePublic: {
	s283_append(v1_sb, "ImportCannotBePublic");
	break; }
	case s226_ErrorKind_ImportAliasEqExpected: {
	s283_append(v1_sb, "ImportAliasEqExpected");
	break; }
	case s226_ErrorKind_ImportPathExpected: {
	s283_append(v1_sb, "ImportPathExpected");
	break; }
	case s226_ErrorKind_ImportAliasExpected: {
	s283_append(v1_sb, "ImportAliasExpected");
	break; }
	case s226_ErrorKind_InvalidExtern: {
	s283_append(v1_sb, "InvalidExtern");
	break; }
	case s226_ErrorKind_GlobalNameExpected: {
	s283_append(v1_sb, "GlobalNameExpected");
	break; }
	case s226_ErrorKind_ExternGlobalNameExpected: {
	s283_append(v1_sb, "ExternGlobalNameExpected");
	break; }
	case s226_ErrorKind_PrototypeParenLExpected: {
	s283_append(v1_sb, "PrototypeParenLExpected");
	break; }
	case s226_ErrorKind_PrototypeArgsAfterVarargsNotAllowed: {
	s283_append(v1_sb, "PrototypeArgsAfterVarargsNotAllowed");
	break; }
	case s226_ErrorKind_PrototypeNameExpected: {
	s283_append(v1_sb, "PrototypeNameExpected");
	break; }
	case s226_ErrorKind_PrototypeArgExpected: {
	s283_append(v1_sb, "PrototypeArgExpected");
	break; }
	case s226_ErrorKind_PrototypeParenRExpected: {
	s283_append(v1_sb, "PrototypeParenRExpected");
	break; }
	case s226_ErrorKind_InvalidTypeIdent: {
	s283_append(v1_sb, "InvalidTypeIdent");
	break; }
	case s226_ErrorKind_MissingTypeIdent: {
	s283_append(v1_sb, "MissingTypeIdent");
	break; }
	case s226_ErrorKind_TypeIdentPathExpected: {
	s283_append(v1_sb, "TypeIdentPathExpected");
	break; }
	case s226_ErrorKind_TypeIdentExpected: {
	s283_append(v1_sb, "TypeIdentExpected");
	break; }
	case s226_ErrorKind_TypeIdentArrayBracketRExpected: {
	s283_append(v1_sb, "TypeIdentArrayBracketRExpected");
	break; }
	case s226_ErrorKind_TypeIdentFnParenExpected: {
	s283_append(v1_sb, "TypeIdentFnParenExpected");
	break; }
	case s226_ErrorKind_TypeIdentFnFlowTypeRequired: {
	s283_append(v1_sb, "TypeIdentFnFlowTypeRequired");
	break; }
	case s226_ErrorKind_ObjectDefCommaExpected: {
	s283_append(v1_sb, "ObjectDefCommaExpected");
	break; }
	case s226_ErrorKind_ObjectDefNameExpected: {
	s283_append(v1_sb, "ObjectDefNameExpected");
	break; }
	case s226_ErrorKind_ObjectDefBraceLExpected: {
	s283_append(v1_sb, "ObjectDefBraceLExpected");
	break; }
	case s226_ErrorKind_ObjectDefFieldExpected: {
	s283_append(v1_sb, "ObjectDefFieldExpected");
	break; }
	case s226_ErrorKind_ObjectDefColonExpected: {
	s283_append(v1_sb, "ObjectDefColonExpected");
	break; }
	case s226_ErrorKind_ObjectInitFieldExpected: {
	s283_append(v1_sb, "ObjectInitFieldExpected");
	break; }
	case s226_ErrorKind_ObjectInitNameExpected: {
	s283_append(v1_sb, "ObjectInitNameExpected");
	break; }
	case s226_ErrorKind_ObjectInitCommaExpected: {
	s283_append(v1_sb, "ObjectInitCommaExpected");
	break; }
	case s226_ErrorKind_EnumDefNameExpected: {
	s283_append(v1_sb, "EnumDefNameExpected");
	break; }
	case s226_ErrorKind_EnumDefFieldExpected: {
	s283_append(v1_sb, "EnumDefFieldExpected");
	break; }
	case s226_ErrorKind_EnumDefBraceLExpected: {
	s283_append(v1_sb, "EnumDefBraceLExpected");
	break; }
	case s226_ErrorKind_EnumDefCommaExpected: {
	s283_append(v1_sb, "EnumDefCommaExpected");
	break; }
	case s226_ErrorKind_MissingMatchArrow: {
	s283_append(v1_sb, "MissingMatchArrow");
	break; }
	case s226_ErrorKind_DuplicateDefaultMatchCase: {
	s283_append(v1_sb, "DuplicateDefaultMatchCase");
	break; }
	default:
		abort();
}
}


#line 155 "src/ast/error.ib"
i64 s224_token_offset(s226_ErrorKind v1_err) {
	#line 156
	switch (v1_err) {
	case s226_ErrorKind_UnknownDeclaration: {
	return 0l;
	break; }
	case s226_ErrorKind_PrototypeArgsAfterVarargsNotAllowed: {
	return 0l;
	break; }
	case s226_ErrorKind_ImportCannotBePublic:
	case s226_ErrorKind_ImportPathExpected: {
	return (-1l);
	break; }
	case s226_ErrorKind_ImportAliasEqExpected:
	case s226_ErrorKind_ImportAliasExpected: {
	return 0l;
	break; }
	default:
 {
	return (-1l);
	break; }
}
}


#line 174 "src/ast/error.ib"
s155_Range s225_span_range(s226_ErrorKind v1_err) {
	#line 175
	switch (v1_err) {
	case s226_ErrorKind_UnknownDeclaration: {
	return s155_Range_Full;
	break; }
	case s226_ErrorKind_ObjectDefNameExpected:
	case s226_ErrorKind_ObjectDefFieldExpected:
	case s226_ErrorKind_ObjectDefColonExpected:
	case s226_ErrorKind_ObjectDefBraceLExpected:
	case s226_ErrorKind_ObjectDefCommaExpected:
	case s226_ErrorKind_ObjectInitFieldExpected:
	case s226_ErrorKind_ObjectInitCommaExpected:
	case s226_ErrorKind_ObjectInitNameExpected: {
	return s155_Range_End;
	break; }
	case s226_ErrorKind_EnumDefNameExpected:
	case s226_ErrorKind_EnumDefFieldExpected:
	case s226_ErrorKind_EnumDefBraceLExpected:
	case s226_ErrorKind_EnumDefCommaExpected: {
	return s155_Range_End;
	break; }
	case s226_ErrorKind_VarDeclEqExpected: {
	return s155_Range_End;
	break; }
	case s226_ErrorKind_ImportAliasEqExpected:
	case s226_ErrorKind_ImportPathExpected:
	case s226_ErrorKind_ImportAliasExpected: {
	return s155_Range_End;
	break; }
	case s226_ErrorKind_InvalidPrimary:
	case s226_ErrorKind_BlockExpected: {
	return s155_Range_End;
	break; }
	case s226_ErrorKind_PrototypeParenLExpected:
	case s226_ErrorKind_PrototypeNameExpected:
	case s226_ErrorKind_PrototypeArgsAfterVarargsNotAllowed:
	case s226_ErrorKind_PrototypeArgExpected:
	case s226_ErrorKind_PrototypeParenRExpected:
	case s226_ErrorKind_TypeIdentFnFlowTypeRequired:
	case s226_ErrorKind_MissingTypeIdent:
	case s226_ErrorKind_SemicolonExpected: {
	return s155_Range_End;
	break; }
	default:
 {
	return s155_Range_Full;
	break; }
}
}


#line 20 "src/lexer/error.ib"
void s227_append_message(s299_StringBuilder * v1_sb, s228_ErrorKind v2_error, char v3_curr) {
	#line 21
	switch (v2_error) {
	case s228_ErrorKind_UnexpectedToken: {
		#line 23
		s283_append(v1_sb, "UnexpectedToken '");
		#line 24
		s284_append_char(v1_sb, v3_curr);
		#line 25
		s284_append_char(v1_sb, 39u);
	break; }
	case s228_ErrorKind_UnterminatedChar: {
	s283_append(v1_sb, "UnterminatedChar");
	break; }
	case s228_ErrorKind_UnterminatedString: {
	s283_append(v1_sb, "UnterminatedString");
	break; }
	case s228_ErrorKind_UnknownCharacterEscape: {
	s283_append(v1_sb, "UnknownCharacterEscape");
	break; }
	case s228_ErrorKind_EmptyCharLiteral: {
	s283_append(v1_sb, "EmptyCharLiteral");
	break; }
	case s228_ErrorKind_InvalidHexaEscape: {
	s283_append(v1_sb, "InvalidHexaEscape");
	break; }
	case s228_ErrorKind_NumberMultipleFractionPart: {
	s283_append(v1_sb, "NumberMultipleFractionPart");
	break; }
	default:
		abort();
}
}


#line 9 "src/utils/fs.ib"
s241_File s236_read_file(char * v1_file) {
	#line 10
	s241_File v2_result = ((s241_File){
		.success = false,
		.length = 0l,
		.content = ((char *)NULL)
	});
	#line 15
	void * v3_f = fopen(v1_file, "r");
	#line 16
	if ((v3_f == NULL)) {
		#line 17
		return v2_result;
	}
	#line 20
	fseek(v3_f, ((u64)0l), s41_FileSeek_End);
	#line 21
	u64 v4_size = ftell(v3_f);
	#line 22
	fseek(v3_f, ((u64)0l), s41_FileSeek_Start);
	#line 23
	if ((v4_size <= ((u64)0l))) {
		#line 24
		fclose(v3_f);
		#line 25
		return v2_result;
	}
	#line 27
	char * v5_buffer = ((char *)malloc((v4_size + ((u64)1l))));
	#line 28
	if ((v5_buffer == ((char *)NULL))) {
		#line 29
		printf("Failed to malloc?\n");
		#line 30
		return v2_result;
	}
	#line 34
	u64 v6_final_size = (v4_size + ((u64)0l));
	#line 35
	fread(((void *)v5_buffer), v4_size, ((u64)1l), v3_f);
	#line 36
	(v5_buffer[v6_final_size]) = 0u;
	#line 38
	fclose(v3_f);
	#line 40
	(v2_result.content) = v5_buffer;
	#line 41
	(v2_result.length) = ((i64)v4_size);
	#line 42
	(v2_result.success) = true;
	#line 43
	return v2_result;
}


#line 47 "src/utils/fs.ib"
bool s237_write_file(char * v1_file, char * v2_content) {
	#line 48
	void * v3_file = fopen(v1_file, "w");
	#line 49
	if ((v3_file == NULL)) {
		#line 49
		return false;
	}
	#line 52
	fputs(v2_content, v3_file);
	#line 54
	fclose(v3_file);
	#line 55
	return true;
}


#line 59 "src/utils/fs.ib"
void s238_free(s241_File * v1_file) {
	#line 60
	((*v1_file).success) = false;
	#line 61
	((*v1_file).length) = 0l;
	#line 62
	free(((void *)((*v1_file).content)));
}


#line 67 "src/utils/fs.ib"
bool s239_delete_file(char * v1_file) {
	#line 68
	i64 v2_res = remove(v1_file);
	#line 69
	return (v2_res == 0l);
}


#line 73 "src/utils/fs.ib"
bool s240_exists(char * v1_file) {
	#line 74
	void * v2_file = fopen(v1_file, "r");
	#line 75
	if ((v2_file == NULL)) {
		#line 75
		return false;
	}
	#line 76
	fclose(v2_file);
	#line 77
	return true;
}


#line 13 "src/utils/vec.ib"
bool s242_is_initialized(s257_Vec * v1_vec) {
	#line 14
	return (((*v1_vec).item_size) > 0l);
}


#line 18 "src/utils/vec.ib"
s257_Vec s243_new(i64 v1_item_size, i64 v2_capacity) {
	#line 19
	void * v3_items = NULL;
	#line 20
	v1_item_size = s256_with_alignment(v1_item_size);
	#line 21
	if ((v2_capacity > 0l)) {
		#line 22
		v3_items = malloc(((u64)(v1_item_size * v2_capacity)));
	}
	#line 24
	return ((s257_Vec){
		.count = 0l,
		.capacity = v2_capacity,
		.item_size = v1_item_size,
		.items = ((char *)v3_items),
		.frozen = false
	});
}


#line 27 "src/utils/vec.ib"
s257_Vec s244_new_frozen(i64 v1_item_size, i64 v2_capacity) {
	#line 28
	void * v3_items = NULL;
	#line 29
	v1_item_size = s256_with_alignment(v1_item_size);
	#line 30
	if ((v2_capacity > 0l)) {
		#line 31
		v3_items = malloc(((u64)(v1_item_size * v2_capacity)));
	}
	#line 33
	return ((s257_Vec){
		.count = 0l,
		.capacity = v2_capacity,
		.item_size = v1_item_size,
		.items = ((char *)v3_items),
		.frozen = true
	});
}


#line 37 "src/utils/vec.ib"
i64 s245_index(s257_Vec * v1_vec, i64 v2_i) {
	#line 38
	return (((*v1_vec).item_size) * v2_i);
}


#line 42 "src/utils/vec.ib"
i64 s246_free(s257_Vec * v1_vec) {
	#line 43
	i64 v2_size = (((*v1_vec).capacity) * ((*v1_vec).item_size));
	#line 44
	free(((void *)((*v1_vec).items)));
	#line 45
	((*v1_vec).items) = ((char *)NULL);
	#line 46
	((*v1_vec).capacity) = 0l;
	#line 47
	((*v1_vec).count) = 0l;
	#line 48
	return v2_size;
}


#line 52 "src/utils/vec.ib"
s257_Vec s247_clone(s257_Vec * v1_vec) {
	#line 53
	void * v2_items = malloc(((u64)(((*v1_vec).item_size) * ((*v1_vec).capacity))));
	#line 54
	s257_Vec v3_new_vec = ((s257_Vec){
		.count = ((*v1_vec).count),
		.capacity = ((*v1_vec).capacity),
		.item_size = ((*v1_vec).item_size),
		.items = ((char *)v2_items),
		.frozen = ((*v1_vec).frozen)
	});
	#line 60
	if ((((*v1_vec).count) > 0l)) {
		#line 61
		memcpy(((void *)(v3_new_vec.items)), ((void *)((*v1_vec).items)), ((u64)(((*v1_vec).count) * ((*v1_vec).item_size))));
	}
	#line 67
	return v3_new_vec;
}


#line 71 "src/utils/vec.ib"
void s248_clear(s257_Vec * v1_vec) {
	#line 72
	((*v1_vec).count) = 0l;
}


#line 76 "src/utils/vec.ib"
void * s249_push(s257_Vec * v1_vec) {
	#line 78
	s40_assert(s242_is_initialized(v1_vec), "vec::push not initialized!");
	#line 79
	s255_allocate(v1_vec, 1l);
	#line 80
	char * v2_ptr = (&(((*v1_vec).items)[s245_index(v1_vec, ((*v1_vec).count))]));
	#line 81
	memset(((void *)v2_ptr), ((int)0l), ((u64)((*v1_vec).item_size)));
	#line 82
	((*v1_vec).count) += 1l;
	#line 83
	return ((void *)v2_ptr);
}


#line 87 "src/utils/vec.ib"
void * s250_pop(s257_Vec * v1_vec) {
	#line 88
	s40_assert(s242_is_initialized(v1_vec), "vec::pop not initialized!");
	#line 89
	if ((((*v1_vec).count) == 0l)) {
		#line 89
		return NULL;
	}
	#line 90
	void * v2_element = s251_get(v1_vec, (((*v1_vec).count) - 1l));
	#line 91
	((*v1_vec).count) -= 1l;
	#line 92
	return v2_element;
}


#line 96 "src/utils/vec.ib"
void * s251_get(s257_Vec * v1_vec, i64 v2_idx) {
	#line 97
	s40_assert(s242_is_initialized(v1_vec), "vec::get not initialized!");
	#line 98
	if ((v2_idx >= ((*v1_vec).count))) {
		#line 99
		printf("vec::get idx %d < count %d\n", v2_idx, ((*v1_vec).count));
		#line 100
		fflush(stdout);
		#line 101
		abort();
	}
	#line 103
	return ((void *)(&(((*v1_vec).items)[s245_index(v1_vec, v2_idx)])));
}


#line 106 "src/utils/vec.ib"
void * s252_last(s257_Vec * v1_vec) {
	#line 107
	s40_assert(s242_is_initialized(v1_vec), "vec::last not initialized!");
	#line 108
	if ((((*v1_vec).count) == 0l)) {
		#line 108
		return NULL;
	}
	#line 109
	return s251_get(v1_vec, (((*v1_vec).count) - 1l));
}


#line 114 "src/utils/vec.ib"
void * s253_push_many(s257_Vec * v1_vec, i64 v2_count) {
	#line 115
	s255_allocate(v1_vec, v2_count);
	#line 116
	i64 v3_idx = ((*v1_vec).count);
	#line 117
	((*v1_vec).count) += v2_count;
	#line 118
	char * v4_ptr = (&(((*v1_vec).items)[s245_index(v1_vec, v3_idx)]));
	#line 119
	memset(((void *)v4_ptr), ((int)0l), ((u64)((*v1_vec).item_size)));
	#line 120
	return ((void *)v4_ptr);
}


#line 124 "src/utils/vec.ib"
void s254_append(s257_Vec * v1_vec, s257_Vec * v2_other) {
	#line 125
	s40_assert((((*v1_vec).item_size) == ((*v2_other).item_size)), "vec::append item size mismatch!");
	#line 126
	void * v3_ptr = s253_push_many(v1_vec, ((*v2_other).count));
	#line 127
	memcpy(v3_ptr, ((void *)((*v2_other).items)), ((u64)(((*v2_other).count) * ((*v2_other).item_size))));
}


#line 131 "src/utils/vec.ib"
void s255_allocate(s257_Vec * v1_vec, i64 v2_count) {
	#line 132
	i64 v3_min_capacity = (((*v1_vec).count) + v2_count);
	#line 133
	if ((v3_min_capacity <= ((*v1_vec).capacity))) {
		#line 133
		return;
	}
	#line 134
	s40_assert((!((*v1_vec).frozen)), "vec tried to allocate but was frozen!");
	#line 136
	i64 v4_new_capacity = (((*v1_vec).capacity) * 2l);
	#line 137
	if ((v4_new_capacity < v3_min_capacity)) {
		#line 138
		v4_new_capacity = (v3_min_capacity * 2l);
	}
	#line 140
	((*v1_vec).capacity) = v4_new_capacity;
	#line 142
	((*v1_vec).items) = ((char *)realloc(((void *)((*v1_vec).items)), ((u64)(((*v1_vec).capacity) * ((*v1_vec).item_size)))));
}


#line 149 "src/utils/vec.ib"
i64 s256_with_alignment(i64 v1_size) {
	#line 150
	i64 v2_rem = (v1_size % 8l);
	#line 151
	if ((v2_rem == 0l)) {
		#line 151
		return v1_size;
	}
	#line 152
	return (v1_size + (8l - v2_rem));
}


#line 20 "src/utils/path.ib"
s275_Path s261_new(char * v1_path) {
	#line 21
	s275_Path v2_p = ((s275_Path){
		.nodes = s243_new(((i64)16ul), 0l),
		.filename = s590_new(((char *)NULL), 0l),
		.is_library = false
	});
	#line 28
	return s263_join((&v2_p), v1_path);
}


#line 32 "src/utils/path.ib"
void s262_free(s275_Path * v1_path) {
	#line 33
	s246_free((&((*v1_path).nodes)));
	#line 34
	s258_ALLOCATED_COUNT -= 1l;
}


#line 39 "src/utils/path.ib"
s275_Path s263_join(s275_Path * v1_source, char * v2_relative) {
	#line 40
	s258_ALLOCATED_COUNT += 1l;
	#line 41
	switch ((v2_relative[0l])) {
	case 64u: {
	return s269_library_path(v1_source, v2_relative);
	break; }
	case 47u: {
	return s270_root_path(v1_source, v2_relative);
	break; }
	default:
 {
	return s268_relative_path(v1_source, v2_relative);
	break; }
}
}


#line 49 "src/utils/path.ib"
void s264_assert_allocated_count(i64 v1_count) {
	#line 50
	s40_assert((s258_ALLOCATED_COUNT == v1_count), "path::assert_allocated_count");
}


#line 54 "src/utils/path.ib"
void s265_print_debug(s275_Path * v1_path) {
	#line 55
	printf("Path(");
	#line 56
	fflush(stdout);
	#line 57
	if (((*v1_path).is_library)) {
		#line 57
		printf("@");
	}
	#line 58
	fflush(stdout);
	#line 59
	for (i64 v2_i = 0l;(v2_i < (((*v1_path).nodes).count));v2_i += 1l) {
		#line 60
		s603_StringView * v3_node = ((s603_StringView *)s251_get((&((*v1_path).nodes)), v2_i));
		#line 61
		s596_print((*v3_node));
		#line 62
		fflush(stdout);
		#line 63
		printf(" -> ");
		#line 64
		fflush(stdout);
	}
	loop_exit_1:
	#line 66
	s596_print(((*v1_path).filename));
	#line 67
	fflush(stdout);
	#line 68
	printf(")");
	#line 69
	fflush(stdout);
}


#line 74 "src/utils/path.ib"
void s266_build(s275_Path * v1_path, s299_StringBuilder * v2_sb) {
	#line 77
	if (((*v1_path).is_library)) {
		#line 78
		char * v3_s = s126_insert(s260_STDLIB_PATH, ((i64)strlen(s260_STDLIB_PATH)));
		#line 79
		s283_append(v2_sb, v3_s);
		#line 80
		return;
	}
	#line 82
	i64 v4_length = 0l;
	#line 83
	for (i64 v5_i = 0l;(v5_i < (((*v1_path).nodes).count));v5_i += 1l) {
		#line 84
		s603_StringView * v6_node = ((s603_StringView *)s251_get((&((*v1_path).nodes)), v5_i));
		#line 85
		v4_length += (((*v6_node).length) + 1l);
	}
	loop_exit_1:
	#line 87
	v4_length += (((*v1_path).filename).length);
	#line 89
	char * v7_filepath = s292_reserve(v2_sb, (v4_length + 1l));
	#line 92
	i64 v8_offset = 0l;
	#line 93
	for (i64 v9_i = 0l;(v9_i < (((*v1_path).nodes).count));v9_i += 1l) {
		#line 94
		s603_StringView * v10_node = ((s603_StringView *)s251_get((&((*v1_path).nodes)), v9_i));
		#line 95
		memcpy(((void *)(&(v7_filepath[v8_offset]))), ((void *)((*v10_node).string)), (1ul * ((u64)((*v10_node).length))));
		#line 99
		(v7_filepath[(v8_offset + ((*v10_node).length))]) = 47u;
		#line 100
		v8_offset += (((*v10_node).length) + 1l);
	}
	loop_exit_2:
	#line 102
	memcpy(((void *)(&(v7_filepath[v8_offset]))), ((void *)(((*v1_path).filename).string)), (1ul * ((u64)(((*v1_path).filename).length))));
	#line 107
	(v7_filepath[v4_length]) = 0u;
}


#line 110 "src/utils/path.ib"
char * s267_to_str(s275_Path * v1_path) {
	#line 111
	s299_StringBuilder v2_sb = s277_new();
	#line 112
	s266_build(v1_path, (&v2_sb));
	#line 113
	char * v3_file = s293_build((&v2_sb));
	#line 114
	s278_free((&v2_sb));
	#line 115
	return v3_file;
}


#line 119 "src/utils/path.ib"
s275_Path s268_relative_path(s275_Path * v1_source, char * v2_path) {
	#line 121
	s603_StringView v3_path = s601_from_str(v2_path);
	#line 122
	s257_Vec v4_nodes = s247_clone((&((*v1_source).nodes)));
	#line 123
	s275_Path v5_res = s271_build_path(v4_nodes, v3_path);
	#line 135
	return v5_res;
}


#line 139 "src/utils/path.ib"
s275_Path s269_library_path(s275_Path * v1__source, char * v2_path) {
	#line 141
	s603_StringView v3_path = s601_from_str(v2_path);
	#line 142
	s603_StringView v4_path = s595_drop_left(v3_path, 1l);
	#line 143
	s257_Vec v5_nodes = s243_new(((i64)16ul), 32l);
	#line 144
	s275_Path v6_result = s271_build_path(v5_nodes, v4_path);
	#line 145
	(v6_result.is_library) = true;
	#line 146
	return v6_result;
}


#line 150 "src/utils/path.ib"
s275_Path s270_root_path(s275_Path * v1__source, char * v2_path) {
	#line 151
	s603_StringView v3_path = s601_from_str(v2_path);
	#line 152
	s603_StringView v4_path = s595_drop_left(v3_path, 1l);
	#line 153
	s257_Vec v5_nodes = s243_new(((i64)16ul), 32l);
	#line 154
	return s271_build_path(v5_nodes, v4_path);
}


#line 158 "src/utils/path.ib"
s275_Path s271_build_path(s257_Vec v1_nodes, s603_StringView v2_path) {
	#line 159
	i64 v3_node_start = 0l;
	#line 160
	for (i64 v4_i = 0l;(v4_i < (v2_path.length));v4_i += 1l) {
		#line 161
		if ((s591_at(v2_path, v4_i) == 47u)) {
			#line 162
			s272_append((&v1_nodes), s594_slice(v2_path, v3_node_start, v4_i));
			#line 163
			v3_node_start = (v4_i + 1l);
		}
	}
	loop_exit_1:
	#line 166
	s603_StringView v5_filename = s594_slice(v2_path, v3_node_start, (v2_path.length));
	#line 168
	s275_Path v6_result = ((s275_Path){
		.filename = v5_filename,
		.nodes = v1_nodes,
		.is_library = false
	});
	#line 173
	return v6_result;
}


#line 177 "src/utils/path.ib"
void s272_append(s257_Vec * v1_nodes, s603_StringView v2_path) {
	#line 178
	if (s592_eq_str(v2_path, "..")) {
		#line 178
		s250_pop(v1_nodes);
		#line 178
		return;
	}
	#line 179
	if (s592_eq_str(v2_path, ".")) {
		#line 179
		return;
	}
	#line 180
	s603_StringView * v3_node = ((s603_StringView *)s249_push(v1_nodes));
	#line 182
	(*v3_node) = v2_path;
}


#line 187 "src/utils/path.ib"
i64 s273_hash(s275_Path * v1_path) {
	#line 188
	i64 v2_filename = ((i64)(((*v1_path).filename).string));
	#line 189
	return v2_filename;
}


#line 193 "src/utils/path.ib"
bool s274_eq(s275_Path * v1_lhs, s275_Path * v2_rhs) {
	#line 194
	if ((((*v1_lhs).is_library) != ((*v2_rhs).is_library))) {
		#line 194
		return false;
	}
	#line 195
	if (((((*v1_lhs).nodes).count) != (((*v2_rhs).nodes).count))) {
		#line 195
		return false;
	}
	#line 196
	if ((!s593_eq(((*v1_lhs).filename), ((*v2_rhs).filename)))) {
		#line 196
		return false;
	}
	#line 198
	for (i64 v3_i = 0l;(v3_i < (((*v1_lhs).nodes).count));v3_i += 1l) {
		#line 199
		s603_StringView * v4_lhs_node = ((s603_StringView *)s251_get((&((*v1_lhs).nodes)), v3_i));
		#line 200
		s603_StringView * v5_rhs_node = ((s603_StringView *)s251_get((&((*v2_rhs).nodes)), v3_i));
		#line 201
		if ((((*v4_lhs_node).length) != ((*v5_rhs_node).length))) {
			#line 201
			return false;
		}
		#line 202
		if ((!s593_eq((*v4_lhs_node), (*v5_rhs_node)))) {
			#line 202
			return false;
		}
	}
	loop_exit_1:
	#line 204
	return true;
}


#line 20 "src/utils/stringbuilder.ib"
s299_StringBuilder s277_new() {
	#line 21
	return ((s299_StringBuilder){
		.head = ((s300_Node *)NULL),
		.tail = ((s300_Node *)NULL),
		.length = 0l,
		.node_count = 0l
	});
}


#line 30 "src/utils/stringbuilder.ib"
void s278_free(s299_StringBuilder * v1_builder) {
	#line 31
	s300_Node * v2_current = ((*v1_builder).head);
	#line 32
	while ((v2_current != ((s300_Node *)NULL))) {
		#line 33
		s300_Node * v3_next = ((*v2_current).next);
		#line 34
		free(((void *)v2_current));
		#line 35
		v2_current = v3_next;
}
	loop_exit_1:
	#line 37
	((*v1_builder).head) = ((s300_Node *)NULL);
	#line 38
	((*v1_builder).tail) = ((s300_Node *)NULL);
	#line 39
	((*v1_builder).length) = 0l;
	#line 40
	((*v1_builder).node_count) = 0l;
}


#line 44 "src/utils/stringbuilder.ib"
s299_StringBuilder s279_with_capacity(i64 v1_capacity) {
	#line 45
	s40_assert((v1_capacity > 0l), "Capacity was not positive");
	#line 46
	s300_Node * v2_node = s297_allocate_node(v1_capacity);
	#line 47
	return ((s299_StringBuilder){
		.head = v2_node,
		.tail = v2_node,
		.length = 0l,
		.node_count = 1l
	});
}


#line 56 "src/utils/stringbuilder.ib"
bool s280_ends_with_char(s299_StringBuilder * v1_builder, char v2_c) {
	#line 57
	if ((((*v1_builder).tail) == ((s300_Node *)NULL))) {
		#line 57
		return false;
	}
	#line 58
	if ((((*((*v1_builder).tail)).length) == 0l)) {
		#line 58
		return false;
	}
	#line 59
	return ((((*((*v1_builder).tail)).content)[(((*((*v1_builder).tail)).length) - 1l)]) == v2_c);
}


#line 63 "src/utils/stringbuilder.ib"
void s281_append_escaped_str(s299_StringBuilder * v1_builder, char * v2_content) {
	#line 64
	if ((v2_content == ((char *)NULL))) {
		#line 64
		return;
	}
	#line 65
	u64 v3_len = strlen(v2_content);
	#line 66
	for (i64 v4_i = 0l;(v4_i < ((i64)v3_len));v4_i += 1l) {
		#line 67
		switch ((v2_content[v4_i])) {
		case 0u: {
		s283_append(v1_builder, "\\0");
		break; }
		case 10u: {
		s283_append(v1_builder, "\\n");
		break; }
		case 9u: {
		s283_append(v1_builder, "\\t");
		break; }
		case 13u: {
		s283_append(v1_builder, "\\r");
		break; }
		case 92u: {
		s283_append(v1_builder, "\\\\");
		break; }
		case 34u: {
		s283_append(v1_builder, "\\\"");
		break; }
		default:
 {
			#line 75
			char v5_byte = (v2_content[v4_i]);
			#line 76
			if (((((i64)v5_byte) < 32l) || (((i64)v5_byte) >= 127l))) {
				#line 77
				s282_append_hex_escape(v1_builder, v5_byte);
			} else {
#line 79
				s284_append_char(v1_builder, v5_byte);
			}
		break; }
}
	}
	loop_exit_1:
}


#line 87 "src/utils/stringbuilder.ib"
void s282_append_hex_escape(s299_StringBuilder * v1_builder, char v2_byte) {
	#line 88
	char * v3_hex_digits = "0123456789ABCDEF";
	#line 89
	s283_append(v1_builder, "\\x");
	#line 90
	i64 v4_high = (((i64)v2_byte) / 16l);
	#line 91
	i64 v5_low = (((i64)v2_byte) % 16l);
	#line 92
	s284_append_char(v1_builder, (v3_hex_digits[v4_high]));
	#line 93
	s284_append_char(v1_builder, (v3_hex_digits[v5_low]));
}


#line 96 "src/utils/stringbuilder.ib"
void s283_append(s299_StringBuilder * v1_builder, char * v2_content) {
	#line 97
	if ((v2_content == ((char *)NULL))) {
		#line 97
		return;
	}
	#line 98
	s287_append_n(v1_builder, v2_content, ((i64)strlen(v2_content)));
}


#line 102 "src/utils/stringbuilder.ib"
void s284_append_char(s299_StringBuilder * v1_builder, char v2_c) {
	#line 103
	char * v3_start = s292_reserve(v1_builder, 1l);
	#line 104
	(v3_start[0l]) = v2_c;
}


#line 107 "src/utils/stringbuilder.ib"
void s285_append_debug(s299_StringBuilder * v1_builder, char * v2_content) {
	#line 108
	u64 v3_len = strlen(v2_content);
	#line 109
	for (i64 v4_i = 0l;(v4_i < ((i64)v3_len));v4_i += 1l) {
		#line 110
		s286_append_debug_char(v1_builder, (v2_content[v4_i]));
	}
	loop_exit_1:
}


#line 114 "src/utils/stringbuilder.ib"
void s286_append_debug_char(s299_StringBuilder * v1_builder, char v2_c) {
	#line 115
	if ((((i64)v2_c) == 127l)) {
		#line 115
		s283_append(v1_builder, "[DEL]");
		#line 115
		return;
	}
	#line 116
	if ((((i64)v2_c) <= 31l)) {
		#line 116
		s289_append_number(v1_builder, ((i64)v2_c));
		#line 116
		return;
	}
	#line 117
	s284_append_char(v1_builder, v2_c);
}


#line 120 "src/utils/stringbuilder.ib"
void s287_append_n(s299_StringBuilder * v1_builder, char * v2_content, i64 v3_length) {
	#line 121
	char * v4_start = s292_reserve(v1_builder, v3_length);
	#line 122
	memcpy(((void *)v4_start), ((void *)v2_content), (1ul * ((u64)v3_length)));
}


#line 126 "src/utils/stringbuilder.ib"
void s288_repeat(s299_StringBuilder * v1_builder, char * v2_content, i64 v3_count) {
	#line 127
	u64 v4_content_len = strlen(v2_content);
	#line 128
	char * v5_start = s292_reserve(v1_builder, ((i64)(v4_content_len * ((u64)v3_count))));
	#line 129
	for (i64 v6_i = 0l;(v6_i < v3_count);v6_i += 1l) {
		#line 130
		i64 v7_offset = (v6_i * ((i64)v4_content_len));
		#line 131
		memcpy(((void *)(&(v5_start[v7_offset]))), ((void *)v2_content), (1ul * v4_content_len));
	}
	loop_exit_1:
}


#line 136 "src/utils/stringbuilder.ib"
void s289_append_number(s299_StringBuilder * v1_builder, i64 v2_number) {
	#line 137
	i64 v3_width = s298_number_width(v2_number);
	#line 138
	char * v4_head = s292_reserve(v1_builder, v3_width);
	#line 139
	bool v5_is_negative = (v2_number < 0l);
	#line 140
	if (v5_is_negative) {
		#line 140
		v2_number *= (-1l);
	}
	#line 141
	for (i64 v6_i = (v3_width - 1l);(v6_i >= 0l);v6_i -= 1l) {
		#line 142
		(v4_head[v6_i]) = ((char)((v2_number % 10l) + ((i64)48u)));
		#line 143
		v2_number /= 10l;
	}
	loop_exit_1:
	#line 145
	if (v5_is_negative) {
		#line 145
		(v4_head[0l]) = 45u;
	}
}


#line 148 "src/utils/stringbuilder.ib"
f64 s290_absf(f64 v1_number) {
	#line 149
	if ((v1_number < ((f64)0l))) {
		#line 149
		return (-v1_number);
	}
	#line 150
	return v1_number;
}


#line 153 "src/utils/stringbuilder.ib"
void s291_append_float(s299_StringBuilder * v1_builder, f64 v2_number, i64 v3_precision) {
	#line 154
	i64 v4_whole = ((i64)v2_number);
	#line 155
	f64 v5_fract = (s290_absf(v2_number) - ((f64)v4_whole));
	#line 156
	i64 v6_width = s298_number_width(v4_whole);
	#line 157
	char * v7_head = s292_reserve(v1_builder, ((v6_width + v3_precision) + 1l));
	#line 158
	char * v8_whole_head = v7_head;
	#line 159
	char * v9_fract_head = (&(v7_head[(v6_width + 1l)]));
	#line 160
	(v7_head[v6_width]) = 46u;
	#line 161
	bool v10_is_negative = (v2_number < ((f64)0l));
	#line 162
	if (v10_is_negative) {
		#line 163
		v6_width -= 1l;
		#line 164
		(v7_head[0l]) = 45u;
		#line 165
		v8_whole_head = (&(v7_head[1l]));
	}
	#line 167
	for (i64 v11_i = (v6_width - 1l);(v11_i >= 0l);v11_i -= 1l) {
		#line 168
		(v8_whole_head[v11_i]) = ((char)((v4_whole % 10l) + ((i64)48u)));
		#line 169
		v4_whole /= 10l;
	}
	loop_exit_1:
	#line 172
	for (i64 v12_i = 0l;(v12_i < v3_precision);v12_i += 1l) {
		#line 173
		i64 v13_digit = ((i64)(v5_fract * ((f64)10l)));
		#line 174
		(v9_fract_head[v12_i]) = ((char)((v13_digit % 10l) + ((i64)48u)));
		#line 175
		v5_fract *= ((f64)10l);
	}
	loop_exit_2:
}


#line 180 "src/utils/stringbuilder.ib"
char * s292_reserve(s299_StringBuilder * v1_builder, i64 v2_length) {
	#line 182
	if ((((*v1_builder).tail) == ((s300_Node *)NULL))) {
		#line 183
		i64 v3_first_capacity = (v2_length * 2l);
		#line 184
		if ((v3_first_capacity < 1024l)) {
			#line 184
			v3_first_capacity = 1024l;
		}
		#line 185
		((*v1_builder).tail) = s297_allocate_node(v3_first_capacity);
		#line 186
		if ((((*v1_builder).head) == ((s300_Node *)NULL))) {
			#line 186
			((*v1_builder).head) = ((*v1_builder).tail);
		}
		#line 187
		((*v1_builder).node_count) = 1l;
	}
	#line 190
	i64 v4_required_capacity = ((((*((*v1_builder).tail)).length) + v2_length) + 1l);
	#line 191
	if ((v4_required_capacity > ((*((*v1_builder).tail)).capacity))) {
		#line 192
		i64 v5_new_capacity = (((*((*v1_builder).tail)).capacity) * 2l);
		#line 193
		if ((v5_new_capacity < v2_length)) {
			#line 193
			v5_new_capacity = (v2_length * 2l);
		}
		#line 194
		s300_Node * v6_new_tail = s297_allocate_node(v5_new_capacity);
		#line 196
		((*((*v1_builder).tail)).next) = v6_new_tail;
		#line 197
		((*v1_builder).tail) = v6_new_tail;
		#line 198
		((*v1_builder).node_count) += 1l;
	}
	#line 200
	char * v7_ptr = (&(((*((*v1_builder).tail)).content)[((*((*v1_builder).tail)).length)]));
	#line 201
	((*((*v1_builder).tail)).length) += v2_length;
	#line 202
	((*v1_builder).length) += v2_length;
	#line 203
	(((*((*v1_builder).tail)).content)[((*((*v1_builder).tail)).length)]) = 0u;
	#line 204
	return v7_ptr;
}


#line 209 "src/utils/stringbuilder.ib"
char * s293_build(s299_StringBuilder * v1_builder) {
	#line 210
	char * v2_string = ((char *)malloc((1ul * ((u64)(((*v1_builder).length) + 1l)))));
	#line 211
	char * v3_merged = s294_merge(v1_builder);
	#line 212
	memcpy(((void *)v2_string), ((void *)v3_merged), ((1ul * ((u64)((*v1_builder).length))) + ((u64)1l)));
	#line 213
	return v2_string;
}


#line 219 "src/utils/stringbuilder.ib"
char * s294_merge(s299_StringBuilder * v1_builder) {
	#line 220
	if ((((*v1_builder).node_count) == 0l)) {
		#line 220
		return s276_EMPTY_STR;
	}
	#line 221
	if ((((*v1_builder).node_count) == 1l)) {
		#line 221
		return ((*((*v1_builder).tail)).content);
	}
	#line 223
	i64 v2_merged_length = ((*v1_builder).length);
	#line 224
	i64 v3_merged_capacity = (((*v1_builder).length) * 2l);
	#line 225
	s300_Node * v4_new_head = s297_allocate_node(v3_merged_capacity);
	#line 227
	s296_merge_into(v1_builder, ((*v4_new_head).content));
	#line 228
	s278_free(v1_builder);
	#line 230
	((*v1_builder).length) = v2_merged_length;
	#line 231
	((*v1_builder).node_count) = 1l;
	#line 232
	((*v1_builder).tail) = v4_new_head;
	#line 233
	((*v1_builder).head) = v4_new_head;
	#line 234
	return ((*v4_new_head).content);
}


#line 238 "src/utils/stringbuilder.ib"
void s295_reset(s299_StringBuilder * v1_builder) {
	#line 239
	s294_merge(v1_builder);
	#line 240
	((*v1_builder).length) = 0l;
	#line 241
	if ((((*v1_builder).head) != ((s300_Node *)NULL))) {
		#line 242
		((*((*v1_builder).head)).length) = 0l;
		#line 243
		(((*((*v1_builder).head)).content)[0l]) = 0u;
	}
}


#line 248 "src/utils/stringbuilder.ib"
void s296_merge_into(s299_StringBuilder * v1_builder, char * v2_target) {
	#line 249
	s300_Node * v3_current = ((*v1_builder).head);
	#line 250
	i64 v4_offset = 0l;
	#line 251
	while ((v3_current != ((s300_Node *)NULL))) {
		#line 252
		memcpy(((void *)(&(v2_target[v4_offset]))), ((void *)((*v3_current).content)), ((u64)((*v3_current).length)));
		#line 253
		v4_offset += ((*v3_current).length);
		#line 254
		v3_current = ((*v3_current).next);
}
	loop_exit_1:
	#line 256
	(v2_target[((*v1_builder).length)]) = 0u;
}


#line 260 "src/utils/stringbuilder.ib"
s300_Node * s297_allocate_node(i64 v1_capacity) {
	#line 261
	if ((v1_capacity <= 0l)) {
		#line 261
		return ((s300_Node *)NULL);
	}
	#line 262
	s300_Node * v2_node = ((s300_Node *)malloc((32ul + (1ul * ((u64)v1_capacity)))));
	#line 263
	((*v2_node).capacity) = v1_capacity;
	#line 264
	((*v2_node).length) = 0l;
	#line 265
	((*v2_node).next) = ((s300_Node *)NULL);
	#line 266
	((*v2_node).content) = ((char *)((void *)(&(v2_node[1l]))));
	#line 267
	return v2_node;
}


#line 271 "src/utils/stringbuilder.ib"
i64 s298_number_width(i64 v1_n) {
	#line 272
	if ((v1_n == 0l)) {
		#line 272
		return 1l;
	}
	#line 273
	i64 v2_width = 0l;
	#line 274
	if ((v1_n < 0l)) {
		#line 274
		v1_n *= (-1l);
		#line 274
		v2_width += 1l;
	}
	#line 275
	while ((v1_n > 0l)) {
		#line 276
		v2_width += 1l;
		#line 277
		v1_n /= 10l;
}
	loop_exit_1:
	#line 279
	return v2_width;
}


#line 29 "src/lexer/mod.ib"
s307_LexerResult s301_run(char * v1_filename, char * v2_content, i64 v3_length, s401_Errors * v4_errors) {
	#line 30
	s166_FileMeta * v5_meta = s159_create(v1_filename, v3_length);
	#line 31
	s647_Lexer v6_l = s617_new(v2_content, v3_length, v4_errors, (&((*v5_meta).line_starts)));
	#line 32
	(v6_l.file) = v1_filename;
	#line 34
	s308_Tokens v7_tokens = ((s308_Tokens){

	});
	#line 35
	bool v8_success = true;
	#line 37
	while (1) {
		#line 38
		s648_LexerResult v9_res = s618_next((&v6_l));
		#line 39
		if ((v9_res.is_ok)) {
			#line 40
			s303_push((&v7_tokens), (v9_res.token));
			#line 41
			if (s605_is_eof((&(v9_res.token)))) {
				#line 41
								goto loop_exit_1;
/* break; */
			}
		} else {
#line 43
			v8_success = false;
		}
}
	loop_exit_1:
	#line 50
	return ((s307_LexerResult){
		.success = v8_success,
		.tokens = v7_tokens
	});
}


#line 54 "src/lexer/mod.ib"
void s302_free(s308_Tokens * v1_tokens) {
	#line 55
	if ((((*v1_tokens).items) != ((s614_Token *)NULL))) {
		#line 56
		free(((void *)((*v1_tokens).items)));
	}
	#line 58
	memset(((void *)v1_tokens), ((int)0l), 24ul);
}


#line 61 "src/lexer/mod.ib"
void s303_push(s308_Tokens * v1_tokens, s614_Token v2_token) {
	#line 62
	if ((((*v1_tokens).count) >= ((*v1_tokens).capacity))) {
		#line 63
		if ((((*v1_tokens).capacity) == 0l)) {
			#line 64
			((*v1_tokens).capacity) = 256l;
		} else {
#line 66
			((*v1_tokens).capacity) *= 2l;
		}
		#line 68
		((*v1_tokens).items) = ((s614_Token *)realloc(((void *)((*v1_tokens).items)), ((u64)(((*v1_tokens).capacity) * ((i64)24ul)))));
	}
	#line 70
	(((*v1_tokens).items)[((*v1_tokens).count)]) = v2_token;
	#line 71
	((*v1_tokens).count) += 1l;
}


#line 75 "src/lexer/mod.ib"
void s304_print_tokens(s308_Tokens * v1_tokens) {
	#line 76
	s299_StringBuilder v2_sb = s277_new();
	#line 77
	s305_write_tokens((&v2_sb), v1_tokens);
	#line 78
	printf("%s\n", s294_merge((&v2_sb)));
	#line 79
	s278_free((&v2_sb));
}


#line 83 "src/lexer/mod.ib"
void s305_write_tokens(s299_StringBuilder * v1_sb, s308_Tokens * v2_tokens) {
	#line 84
	i64 v3_i = 0l;
	#line 85
	s616_TokenKind v4_eof = s616_TokenKind_EOF;
	#line 86
	while ((((((*v2_tokens).items)[v3_i]).kind) != v4_eof)) {
		#line 87
		s613_write(v1_sb, (((*v2_tokens).items)[v3_i]));
		#line 88
		s283_append(v1_sb, "\n");
		#line 89
		v3_i += 1l;
}
	loop_exit_1:
}


#line 94 "src/lexer/mod.ib"
s307_LexerResult s306_fail() {
	#line 95
	s307_LexerResult v1_result = ((s307_LexerResult){

	});
	#line 96
	(v1_result.success) = false;
	#line 97
	return v1_result;
}


#line 45 "src/ast/mod.ib"
s335_AstRunResult s310_run(char * v1_file, i64 v2_module_uid, s308_Tokens v3_tokens, s401_Errors * v4_errors) {
	#line 46
	for (i64 v5_i = 0l;(v5_i < (v3_tokens.count));v5_i += 1l) {
		#line 47
		s40_assert(((((v3_tokens.items)[v5_i]).span) < s147_count()), "token");
	}
	loop_exit_1:
	#line 50
	s335_AstRunResult v6_result = ((s335_AstRunResult){
		.success = true,
		.module = s311_new_module(v2_module_uid)
	});
	#line 55
	s702_Ast v7_parser = s676_new(v3_tokens, (&(v6_result.module)), v4_errors);
	#line 56
	(v7_parser.file) = v1_file;
	#line 57
	((v6_result.module).file) = v1_file;
	#line 59
	while (s678_has_next((&v7_parser))) {
		#line 60
		switch (s679_next((&v7_parser))) {
		case s704_Declaration_Error: {
			#line 62
			(v6_result.success) = false;
			#line 63
			s705_clear((&(v7_parser.workstack)));
		break; }
		default:
 {
			#line 66
			s40_assert((((v7_parser.workstack).size) == 0l), "ast::next workstack was not cleared!");
		break; }
}
}
	loop_exit_2:
	#line 70
	s302_free((&v3_tokens));
	#line 71
	s677_free((&v7_parser));
	#line 72
	return v6_result;
}


#line 76 "src/ast/mod.ib"
s334_Module s311_new_module(i64 v1_uid) {
	#line 77
	return ((s334_Module){
		.uid = v1_uid,
		.file = ((char *)NULL),
		.functions = s243_new(((i64)120ul), 32l),
		.extern_fns = s243_new(((i64)112ul), 8l),
		.extern_globals = s243_new(((i64)64ul), 8l),
		.args = s243_new(((i64)32ul), 256l),
		.imports = s243_new(((i64)72ul), 16l),
		.globals = s243_new(((i64)80ul), 16l),
		.structs = s243_new(((i64)64ul), 16l),
		.unions = s243_new(((i64)64ul), 16l),
		.enums = s243_new(((i64)64ul), 16l),
		.object_data = s560_new(((i64)(32ul * ((u64)128l)))),
		.nodes = s581_new(),
		.type_idents = s202_new(v1_uid)
	});
}


#line 97 "src/ast/mod.ib"
void s312_free_modules(s257_Vec * v1_modules, bool v2__print_usage) {
	#line 98
	for (i64 v3_i = 0l;(v3_i < ((*v1_modules).count));v3_i += 1l) {
		#line 99
		s334_Module * v4_m = ((s334_Module *)s251_get(v1_modules, v3_i));
		#line 100
		s313_free_module(v4_m, false);
	}
	loop_exit_1:
	#line 102
	s246_free(v1_modules);
}


#line 108 "src/ast/mod.ib"
void s313_free_module(s334_Module * v1_module, bool v2_print_usage) {
	#line 109
	i64 v3_functions_usage = s246_free((&((*v1_module).functions)));
	#line 110
	i64 v4_args_usage = s246_free((&((*v1_module).args)));
	#line 111
	i64 v5_globals_usage = s246_free((&((*v1_module).globals)));
	#line 112
	i64 v6_imports_usage = s246_free((&((*v1_module).imports)));
	#line 113
	i64 v7_structs_usage = s246_free((&((*v1_module).structs)));
	#line 114
	i64 v8_enums_usage = s246_free((&((*v1_module).enums)));
	#line 115
	i64 v9_unions_usage = s246_free((&((*v1_module).unions)));
	#line 116
	i64 v10_object_data_usage = s562_free((&((*v1_module).object_data)));
	#line 117
	i64 v11_extern_fns_usage = s246_free((&((*v1_module).extern_fns)));
	#line 118
	i64 v12_extern_globals_usage = s246_free((&((*v1_module).extern_globals)));
	#line 119
	if (v2_print_usage) {
		#line 120
		printf("Functions Usage: %d\n", v3_functions_usage);
		#line 121
		printf("Args Usage: %d\n", v4_args_usage);
		#line 122
		printf("Globals Usage: %d\n", v5_globals_usage);
		#line 123
		printf("Imports Usage: %d\n", v6_imports_usage);
		#line 124
		printf("Structs Usage: %d\n", v7_structs_usage);
		#line 125
		printf("Enums Usage: %d\n", v8_enums_usage);
		#line 126
		printf("Unions Usage: %d\n", v9_unions_usage);
		#line 127
		printf("ObjectData Usage: %d\n", v10_object_data_usage);
		#line 128
		printf("ExternFunctions Usage: %d\n", v11_extern_fns_usage);
		#line 129
		printf("ExternGlobals Usage: %d\n", v12_extern_globals_usage);
	}
	#line 131
	s582_free((&((*v1_module).nodes)));
	#line 132
	s203_free((&((*v1_module).type_idents)));
	#line 133
	if (s309_MODULE_OWNS_FILENAME) {
		#line 134
		free(((void *)((*v1_module).file)));
	}
}


#line 139 "src/ast/mod.ib"
void s314_debug_declarations(s299_StringBuilder * v1_sb, s334_Module * v2_module, s257_Vec * v3_v, void (* v4_debug_fn)(s299_StringBuilder *, s334_Module *, void *)) {
	#line 140
	for (i64 v5_i = 0l;(v5_i < ((*v3_v).count));v5_i += 1l) {
		#line 141
		v4_debug_fn(v1_sb, v2_module, s251_get(v3_v, v5_i));
		#line 142
		s283_append(v1_sb, "\n");
	}
	loop_exit_1:
}


#line 147 "src/ast/mod.ib"
void s315_debug_module(s299_StringBuilder * v1_sb, s334_Module * v2_module) {
	#line 148
	s314_debug_declarations(v1_sb, v2_module, (&((*v2_module).imports)), ((void (*)(s299_StringBuilder *, s334_Module *, void *))s654_debug_import));
	#line 149
	s314_debug_declarations(v1_sb, v2_module, (&((*v2_module).extern_fns)), ((void (*)(s299_StringBuilder *, s334_Module *, void *))s655_debug_extern_fn));
	#line 150
	s314_debug_declarations(v1_sb, v2_module, (&((*v2_module).extern_globals)), ((void (*)(s299_StringBuilder *, s334_Module *, void *))s656_debug_extern_global));
	#line 151
	s314_debug_declarations(v1_sb, v2_module, (&((*v2_module).structs)), ((void (*)(s299_StringBuilder *, s334_Module *, void *))s658_debug_struct));
	#line 152
	s314_debug_declarations(v1_sb, v2_module, (&((*v2_module).unions)), ((void (*)(s299_StringBuilder *, s334_Module *, void *))s659_debug_union));
	#line 153
	s314_debug_declarations(v1_sb, v2_module, (&((*v2_module).enums)), ((void (*)(s299_StringBuilder *, s334_Module *, void *))s661_debug_enum));
	#line 154
	s314_debug_declarations(v1_sb, v2_module, (&((*v2_module).globals)), ((void (*)(s299_StringBuilder *, s334_Module *, void *))s657_debug_global));
	#line 155
	s314_debug_declarations(v1_sb, v2_module, (&((*v2_module).functions)), ((void (*)(s299_StringBuilder *, s334_Module *, void *))s652_debug_function));
}


#line 159 "src/ast/mod.ib"
void s316_create_symbols_for_kind(i64 v1_module_uid, s257_Vec * v2_v, s662_Declaration * (* v3_decl_fn)(void *), s544_SymbolKind v4_kind, bool v5_is_extern) {
	#line 166
	for (i64 v6_i = 0l;(v6_i < ((*v2_v).count));v6_i += 1l) {
		#line 167
		void * v7_d = s251_get(v2_v, v6_i);
		#line 168
		s662_Declaration * v8_decl = v3_decl_fn(v7_d);
		#line 169
		s201_UID v9_symbol = s176_insert(v1_module_uid, ((*v8_decl).name), ((*v8_decl).is_public), v5_is_extern, v4_kind, ((*v8_decl).span));
		#line 174
		((*v8_decl).symbol) = v9_symbol;
		#line 175
		s541_ShallowInfo v10_shallow = ((s541_ShallowInfo){

		});
		#line 176
		switch (v4_kind) {
		case s544_SymbolKind_Function: {
			#line 178
			if (v5_is_extern) {
				#line 179
				(v10_shallow.extern_func) = ((s664_ExternFn *)v7_d);
			} else {
#line 181
				(v10_shallow.func) = ((s663_Function *)v7_d);
			}
		break; }
		case s544_SymbolKind_Global: {
			#line 185
			if (v5_is_extern) {
				#line 186
				(v10_shallow.extern_global) = ((s668_ExternGlobal *)v7_d);
			} else {
#line 188
				(v10_shallow.global) = ((s667_Global *)v7_d);
			}
		break; }
		case s544_SymbolKind_Struct: {
		(v10_shallow.object_def) = ((s670_ObjectDef *)v7_d);
		break; }
		case s544_SymbolKind_Union: {
		(v10_shallow.object_def) = ((s670_ObjectDef *)v7_d);
		break; }
		case s544_SymbolKind_Enum: {
		(v10_shallow.enum_def) = ((s672_EnumDef *)v7_d);
		break; }
		default:
			abort();
}
		#line 195
		s181_attach_shallow(v9_symbol, v10_shallow);
	}
	loop_exit_1:
}


#line 198 "src/ast/mod.ib"
s662_Declaration * s317_func_decl(s663_Function * v1_f) {
	#line 198
	return (&((*v1_f).declaration));
}


#line 199 "src/ast/mod.ib"
s662_Declaration * s318_global_decl(s667_Global * v1_g) {
	#line 199
	return (&((*v1_g).declaration));
}


#line 200 "src/ast/mod.ib"
s662_Declaration * s319_extfn_decl(s664_ExternFn * v1_e) {
	#line 200
	return (&((*v1_e).declaration));
}


#line 201 "src/ast/mod.ib"
s662_Declaration * s320_extglobal_decl(s668_ExternGlobal * v1_e) {
	#line 201
	return (&((*v1_e).declaration));
}


#line 202 "src/ast/mod.ib"
s662_Declaration * s321_objdef_decl(s670_ObjectDef * v1_o) {
	#line 202
	return (&((*v1_o).declaration));
}


#line 203 "src/ast/mod.ib"
s662_Declaration * s322_enumdef_decl(s672_EnumDef * v1_e) {
	#line 203
	return (&((*v1_e).declaration));
}


#line 204 "src/ast/mod.ib"
s662_Declaration * s323_import_decl(s669_Import * v1_i) {
	#line 204
	return (&((*v1_i).declaration));
}


#line 206 "src/ast/mod.ib"
s257_Vec * s324_functions(s334_Module * v1_m) {
	#line 206
	return (&((*v1_m).functions));
}


#line 207 "src/ast/mod.ib"
s257_Vec * s325_globals(s334_Module * v1_m) {
	#line 207
	return (&((*v1_m).globals));
}


#line 208 "src/ast/mod.ib"
s257_Vec * s326_extern_fns(s334_Module * v1_m) {
	#line 208
	return (&((*v1_m).extern_fns));
}


#line 209 "src/ast/mod.ib"
s257_Vec * s327_extern_globals(s334_Module * v1_m) {
	#line 209
	return (&((*v1_m).extern_globals));
}


#line 210 "src/ast/mod.ib"
s257_Vec * s328_structs(s334_Module * v1_m) {
	#line 210
	return (&((*v1_m).structs));
}


#line 211 "src/ast/mod.ib"
s257_Vec * s329_unions(s334_Module * v1_m) {
	#line 211
	return (&((*v1_m).unions));
}


#line 212 "src/ast/mod.ib"
s257_Vec * s330_enums(s334_Module * v1_m) {
	#line 212
	return (&((*v1_m).enums));
}


#line 214 "src/ast/mod.ib"
void s331_create_symbols(s334_Module * v1_module) {
	#line 215
	s316_create_symbols_for_kind(((*v1_module).uid), (&((*v1_module).extern_fns)), ((s662_Declaration * (*)(void *))s319_extfn_decl), s544_SymbolKind_Function, true);
	#line 216
	s316_create_symbols_for_kind(((*v1_module).uid), (&((*v1_module).extern_globals)), ((s662_Declaration * (*)(void *))s320_extglobal_decl), s544_SymbolKind_Global, true);
	#line 218
	s316_create_symbols_for_kind(((*v1_module).uid), (&((*v1_module).globals)), ((s662_Declaration * (*)(void *))s318_global_decl), s544_SymbolKind_Global, false);
	#line 219
	s316_create_symbols_for_kind(((*v1_module).uid), (&((*v1_module).functions)), ((s662_Declaration * (*)(void *))s317_func_decl), s544_SymbolKind_Function, false);
	#line 220
	s316_create_symbols_for_kind(((*v1_module).uid), (&((*v1_module).structs)), ((s662_Declaration * (*)(void *))s321_objdef_decl), s544_SymbolKind_Struct, false);
	#line 221
	s316_create_symbols_for_kind(((*v1_module).uid), (&((*v1_module).unions)), ((s662_Declaration * (*)(void *))s321_objdef_decl), s544_SymbolKind_Union, false);
	#line 222
	s316_create_symbols_for_kind(((*v1_module).uid), (&((*v1_module).enums)), ((s662_Declaration * (*)(void *))s322_enumdef_decl), s544_SymbolKind_Enum, false);
}


#line 230 "src/ast/mod.ib"
bool s332_check_name_duplicates_for_kind(s401_Errors * v1_errors, s257_Vec * v2_idents, s257_Vec * v3_v, s662_Declaration * (* v4_decl_fn)(void *)) {
	#line 236
	bool v5_had_errors = false;
	#line 237
	for (i64 v6_i = 0l;(v6_i < ((*v3_v).count));v6_i += 1l) {
		#line 238
		void * v7_d = s251_get(v3_v, v6_i);
		#line 239
		s662_Declaration * v8_decl = v4_decl_fn(v7_d);
		#line 240
		char * v9_ident = ((*v8_decl).name);
		#line 241
		i64 v10_span = ((*v8_decl).span);
		#line 242
		if ((v9_ident == ((char *)NULL))) {
			#line 242
			continue;
		}
		#line 243
		bool v11_had_duplicate = false;
		#line 244
		for (i64 v12_j = 0l;(v12_j < ((*v2_idents).count));v12_j += 1l) {
			#line 245
			s336_IdentEntry * v13_existing = ((s336_IdentEntry *)s251_get(v2_idents, v12_j));
			#line 246
			if ((v9_ident == ((*v13_existing).ident))) {
				#line 247
				s402_Error * v14_err = s390_parser_error(v1_errors);
				#line 248
				((*v14_err).span) = v10_span;
				#line 249
				s223_append_message((&((*v1_errors).builder)), s226_ErrorKind_DuplicateSymbol);
				#line 250
				((*v14_err).message) = s293_build((&((*v1_errors).builder)));
				#line 251
				s295_reset((&((*v1_errors).builder)));
				#line 252
				v11_had_duplicate = true;
				#line 253
								goto loop_exit_2;
/* break; */
			}
		}
		loop_exit_2:
		#line 256
		if (v11_had_duplicate) {
			#line 257
			v5_had_errors = true;
		} else {
#line 259
			s336_IdentEntry * v15_entry = ((s336_IdentEntry *)s249_push(v2_idents));
			#line 260
			(*v15_entry) = ((s336_IdentEntry){
				.ident = v9_ident,
				.span = v10_span
			});
		}
	}
	loop_exit_1:
	#line 264
	return v5_had_errors;
}


#line 267 "src/ast/mod.ib"
bool s333_check_name_duplicates(s334_Module * v1_module, s401_Errors * v2_errors) {
	#line 268
	i64 v3_count = ((((((((((*v1_module).functions).count) + (((*v1_module).extern_fns).count)) + (((*v1_module).extern_globals).count)) + (((*v1_module).globals).count)) + (((*v1_module).imports).count)) + (((*v1_module).structs).count)) + (((*v1_module).unions).count)) + (((*v1_module).enums).count));
	#line 276
	s257_Vec v4_idents = s243_new(((i64)16ul), v3_count);
	#line 278
	bool v5_had_errors = false;
	#line 279
	v5_had_errors = (v5_had_errors || s332_check_name_duplicates_for_kind(v2_errors, (&v4_idents), (&((*v1_module).extern_fns)), ((s662_Declaration * (*)(void *))s319_extfn_decl)));
	#line 280
	v5_had_errors = (v5_had_errors || s332_check_name_duplicates_for_kind(v2_errors, (&v4_idents), (&((*v1_module).extern_globals)), ((s662_Declaration * (*)(void *))s320_extglobal_decl)));
	#line 281
	v5_had_errors = (v5_had_errors || s332_check_name_duplicates_for_kind(v2_errors, (&v4_idents), (&((*v1_module).globals)), ((s662_Declaration * (*)(void *))s318_global_decl)));
	#line 282
	v5_had_errors = (v5_had_errors || s332_check_name_duplicates_for_kind(v2_errors, (&v4_idents), (&((*v1_module).functions)), ((s662_Declaration * (*)(void *))s317_func_decl)));
	#line 283
	v5_had_errors = (v5_had_errors || s332_check_name_duplicates_for_kind(v2_errors, (&v4_idents), (&((*v1_module).structs)), ((s662_Declaration * (*)(void *))s321_objdef_decl)));
	#line 284
	v5_had_errors = (v5_had_errors || s332_check_name_duplicates_for_kind(v2_errors, (&v4_idents), (&((*v1_module).unions)), ((s662_Declaration * (*)(void *))s321_objdef_decl)));
	#line 285
	v5_had_errors = (v5_had_errors || s332_check_name_duplicates_for_kind(v2_errors, (&v4_idents), (&((*v1_module).enums)), ((s662_Declaration * (*)(void *))s322_enumdef_decl)));
	#line 287
	s246_free((&v4_idents));
	#line 288
	return v5_had_errors;
}


#line 35 "src/typecheck/mod.ib"
s351_TypecheckContext s337_context(s401_Errors * v1_errors, s257_Vec * v2_ast_modules, s257_Vec * v3_modules) {
	#line 36
	return ((s351_TypecheckContext){
		.ast_modules = v2_ast_modules,
		.modules = v3_modules,
		.errors = v1_errors,
		.typeidents = s502_new(),
		.err_builder = s277_new(),
		.workstack = ((s712_WorkStack){

		}),
		.typecheck_stack = s243_new(((i64)24ul), 64l)
	});
}


#line 46 "src/typecheck/mod.ib"
void s338_context_free(s351_TypecheckContext * v1_context) {
	#line 47
	s278_free((&((*v1_context).err_builder)));
	#line 48
	s711_free((&((*v1_context).workstack)));
	#line 49
	s246_free((&((*v1_context).typecheck_stack)));
	#line 50
	s503_free((&((*v1_context).typeidents)));
}


#line 54 "src/typecheck/mod.ib"
void s339_run(s351_TypecheckContext * v1_context) {
	#line 56
	s340_typecheck_declaration_group(v1_context, s326_extern_fns, ((s662_Declaration * (*)(void *))s319_extfn_decl), s734_typecheck_extern);
	#line 61
	s340_typecheck_declaration_group(v1_context, s327_extern_globals, ((s662_Declaration * (*)(void *))s320_extglobal_decl), s768_typecheck_extern);
	#line 66
	s340_typecheck_declaration_group(v1_context, s330_enums, ((s662_Declaration * (*)(void *))s322_enumdef_decl), s760_typecheck_def);
	#line 71
	s340_typecheck_declaration_group(v1_context, s328_structs, ((s662_Declaration * (*)(void *))s321_objdef_decl), s747_typecheck_struct);
	#line 76
	s340_typecheck_declaration_group(v1_context, s329_unions, ((s662_Declaration * (*)(void *))s321_objdef_decl), s749_typecheck_union);
	#line 81
	s340_typecheck_declaration_group(v1_context, s325_globals, ((s662_Declaration * (*)(void *))s318_global_decl), s767_typecheck);
	#line 86
	s340_typecheck_declaration_group(v1_context, s324_functions, ((s662_Declaration * (*)(void *))s317_func_decl), s733_typecheck_function_head);
	#line 91
	s340_typecheck_declaration_group(v1_context, s324_functions, ((s662_Declaration * (*)(void *))s317_func_decl), s732_typecheck_function);
}


#line 98 "src/typecheck/mod.ib"
void s340_typecheck_declaration_group(s351_TypecheckContext * v1_context, s257_Vec * (* v2_get_decl_vec)(s334_Module *), s662_Declaration * (* v3_decl_fn)(void *), void (* v4_typecheck_fn)(s351_TypecheckContext *, s201_UID)) {
	#line 104
	for (i64 v5_i = 0l;(v5_i < ((*((*v1_context).ast_modules)).count));v5_i += 1l) {
		#line 105
		s334_Module * v6_m = ((s334_Module *)s251_get(((*v1_context).ast_modules), v5_i));
		#line 106
		s257_Vec * v7_decs = v2_get_decl_vec(v6_m);
		#line 107
		if ((((*v7_decs).count) == 0l)) {
			#line 107
			continue;
		}
		#line 108
		s40_assert((((*v6_m).uid) == v5_i), "ast_mod.uid does not match idx");
		#line 109
		for (i64 v8_j = 0l;(v8_j < ((*v7_decs).count));v8_j += 1l) {
			#line 110
			s662_Declaration * v9_declaration = v3_decl_fn(s251_get(v7_decs, v8_j));
			#line 112
			v4_typecheck_fn(v1_context, ((*v9_declaration).symbol));
			#line 113
			s710_assert_empty((&((*v1_context).workstack)));
		}
		loop_exit_2:
	}
	loop_exit_1:
}


#line 119 "src/typecheck/mod.ib"
s257_Vec s341_create_modules(s257_Vec * v1_ast_modules) {
	#line 120
	s257_Vec v2_modules = s243_new(((i64)504ul), ((*v1_ast_modules).count));
	#line 121
	for (i64 v3_i = 0l;(v3_i < ((*v1_ast_modules).count));v3_i += 1l) {
		#line 122
		s334_Module * v4_ast_mod = ((s334_Module *)s251_get(v1_ast_modules, v3_i));
		#line 123
		s729_Module * v5_module = ((s729_Module *)s249_push((&v2_modules)));
		#line 124
		s40_assert((((*v4_ast_mod).uid) == v3_i), "ast_mod.uid does not match idx");
		#line 125
		(*v5_module) = s713_new(v4_ast_mod);
	}
	loop_exit_1:
	#line 127
	return v2_modules;
}


#line 131 "src/typecheck/mod.ib"
void s342_typecheck_symbol(s351_TypecheckContext * v1_context, s201_UID v2_symbol) {
	#line 132
	s172_assert_exists(v2_symbol);
	#line 133
	if (s188_stage_eq(v2_symbol, s543_SymbolStage_Typechecked)) {
		#line 133
		return;
	}
	#line 134
	if (s188_stage_eq(v2_symbol, s543_SymbolStage_TypecheckInProgress)) {
		#line 135
		s776_cyclic_dependency(v1_context, v2_symbol);
		#line 136
		return;
	}
	#line 139
	switch (s190_kind(v2_symbol)) {
	case s544_SymbolKind_Function: {
		#line 141
		s733_typecheck_function_head(v1_context, v2_symbol);
	break; }
	case s544_SymbolKind_Struct: {
		#line 144
		s747_typecheck_struct(v1_context, v2_symbol);
	break; }
	case s544_SymbolKind_Union: {
		#line 147
		s749_typecheck_union(v1_context, v2_symbol);
	break; }
	case s544_SymbolKind_Enum: {
		#line 150
		s760_typecheck_def(v1_context, v2_symbol);
	break; }
	case s544_SymbolKind_Global: {
		#line 153
		s767_typecheck(v1_context, v2_symbol);
	break; }
	default:
		abort();
}
}


#line 159 "src/typecheck/mod.ib"
void s343_typecheck_symbol_body(s351_TypecheckContext * v1_context, s201_UID v2_symbol) {
	#line 160
	switch (s190_kind(v2_symbol)) {
	case s544_SymbolKind_Function: {
		#line 162
		s732_typecheck_function(v1_context, v2_symbol);
	break; }
	case s544_SymbolKind_Struct: {
	break; }
	case s544_SymbolKind_Union: {
	break; }
	case s544_SymbolKind_Enum: {
	break; }
	case s544_SymbolKind_Global: {
	break; }
	default:
		abort();
}
}


#line 171 "src/typecheck/mod.ib"
void s344_start_typechecking(s351_TypecheckContext * v1_context, s201_UID v2_symbol) {
	#line 172
	s201_UID * v3_elem = ((s201_UID *)s249_push((&((*v1_context).typecheck_stack))));
	#line 173
	(*v3_elem) = v2_symbol;
}


#line 176 "src/typecheck/mod.ib"
void s345_finish_typechecking(s351_TypecheckContext * v1_context, s201_UID v2_symbol) {
	#line 177
	s201_UID * v3_elem = ((s201_UID *)s250_pop((&((*v1_context).typecheck_stack))));
	#line 178
	s40_assert(s171_eq((*v3_elem), v2_symbol), "Did not finish typechecking the actual symbol");
}


#line 182 "src/typecheck/mod.ib"
s334_Module * s346_find_ast_module(s351_TypecheckContext * v1_context, i64 v2_uid) {
	#line 183
	for (i64 v3_i = 0l;(v3_i < ((*((*v1_context).ast_modules)).count));v3_i += 1l) {
		#line 184
		s334_Module * v4_module = ((s334_Module *)s251_get(((*v1_context).ast_modules), v3_i));
		#line 185
		if ((((*v4_module).uid) == v2_uid)) {
			#line 185
			return v4_module;
		}
	}
	loop_exit_1:
	#line 187
	return ((s334_Module *)NULL);
}


#line 191 "src/typecheck/mod.ib"
s729_Module * s347_find_module(s351_TypecheckContext * v1_context, i64 v2_uid) {
	#line 192
	for (i64 v3_i = 0l;(v3_i < ((*((*v1_context).modules)).count));v3_i += 1l) {
		#line 193
		s729_Module * v4_module = ((s729_Module *)s251_get(((*v1_context).modules), v3_i));
		#line 194
		if ((((*v4_module).uid) == v2_uid)) {
			#line 194
			return v4_module;
		}
	}
	loop_exit_1:
	#line 196
	return ((s729_Module *)NULL);
}


#line 200 "src/typecheck/mod.ib"
void s348_debug_declarations(s299_StringBuilder * v1_sb, s729_Module * v2_module, s257_Vec * v3_decls, void (* v4_debug_fn)(s299_StringBuilder *, s729_Module *, void *)) {
	#line 204
	for (i64 v5_i = 0l;(v5_i < ((*v3_decls).count));v5_i += 1l) {
		#line 205
		void * v6_d = s251_get(v3_decls, v5_i);
		#line 206
		v4_debug_fn(v1_sb, v2_module, v6_d);
	}
	loop_exit_1:
	#line 208
	if ((((*v3_decls).count) > 0l)) {
		#line 209
		s283_append(v1_sb, "\n");
	}
}


#line 214 "src/typecheck/mod.ib"
void s349_debug_module(s299_StringBuilder * v1_sb, s729_Module * v2_module) {
	#line 215
	s283_append(v1_sb, "# MODULE: ");
	#line 216
	s283_append(v1_sb, ((*v2_module).file));
	#line 217
	s283_append(v1_sb, "\n\n");
	#line 220
	s348_debug_declarations(v1_sb, v2_module, (&((*v2_module).extern_fns)), ((void (*)(s299_StringBuilder *, s729_Module *, void *))s737_debug_extern));
	#line 221
	s348_debug_declarations(v1_sb, v2_module, (&((*v2_module).extern_globals)), ((void (*)(s299_StringBuilder *, s729_Module *, void *))s769_debug_extern_global));
	#line 223
	s348_debug_declarations(v1_sb, v2_module, (&((*v2_module).structs)), ((void (*)(s299_StringBuilder *, s729_Module *, void *))s754_debug_struct));
	#line 224
	s348_debug_declarations(v1_sb, v2_module, (&((*v2_module).unions)), ((void (*)(s299_StringBuilder *, s729_Module *, void *))s755_debug_union));
	#line 225
	s348_debug_declarations(v1_sb, v2_module, (&((*v2_module).enums)), ((void (*)(s299_StringBuilder *, s729_Module *, void *))s764_debug_enum));
	#line 226
	s348_debug_declarations(v1_sb, v2_module, (&((*v2_module).globals)), ((void (*)(s299_StringBuilder *, s729_Module *, void *))s770_debug_global));
	#line 228
	s348_debug_declarations(v1_sb, v2_module, (&((*v2_module).functions)), ((void (*)(s299_StringBuilder *, s729_Module *, void *))s736_debug));
	#line 229
	s283_append(v1_sb, "\n");
}


#line 233 "src/typecheck/mod.ib"
void s350_free_modules(s257_Vec * v1_modules, bool v2_print_usage) {
	#line 234
	for (i64 v3_i = 0l;(v3_i < ((*v1_modules).count));v3_i += 1l) {
		#line 235
		s729_Module * v4_m = ((s729_Module *)s251_get(v1_modules, v3_i));
		#line 236
		s714_free(v4_m, v2_print_usage);
	}
	loop_exit_1:
	#line 238
	s246_free(v1_modules);
}


#line 28 "src/codegen/mod.ib"
char * s353_generated_filename(char * v1_outfile) {
	#line 29
	u64 v2_outfile_len = strlen(v1_outfile);
	#line 30
	u64 v3_suffix_len = strlen(s352_suffix);
	#line 31
	void * v4_file = malloc((((v2_outfile_len + v3_suffix_len) + ((u64)1l)) * 1ul));
	#line 32
	sprintf(((char *)v4_file), "%s%s", v1_outfile, s352_suffix);
	#line 33
	return ((char *)v4_file);
}


#line 37 "src/codegen/mod.ib"
s366_CodegenContext s354_context(s257_Vec * v1_modules, char * v2_outfile, bool v3_verbose) {
	#line 38
	void * v4_file = fopen(v2_outfile, "w");
	#line 39
	return ((s366_CodegenContext){
		.modules = v1_modules,
		.sb = s277_new(),
		.work_sb = s277_new(),
		.file = v4_file,
		.enable_sourcemap = true,
		.verbose = v3_verbose
	});
}


#line 50 "src/codegen/mod.ib"
void s355_free(s366_CodegenContext * v1_context) {
	#line 51
	s278_free((&((*v1_context).sb)));
	#line 52
	s278_free((&((*v1_context).work_sb)));
	#line 53
	if ((((*v1_context).file) == NULL)) {
		#line 54
		fclose(((*v1_context).file));
	}
	#line 56
	((*v1_context).file) = NULL;
}


#line 60 "src/codegen/mod.ib"
void s356_run(s366_CodegenContext * v1_context) {
	#line 61
	s360_define(v1_context, "NULL", "0");
	#line 63
	s362_comment(v1_context, " Common Includes");
	#line 64
	s789_declarations(v1_context);
	#line 65
	s362_comment(v1_context, " Extern Functions");
	#line 68
	s358_codegen_group(v1_context, s721_enums, ((s201_UID (*)(void *))s728_enum_symbol), s785_declaration);
	#line 72
	s358_codegen_group(v1_context, s716_extern_fns, ((s201_UID (*)(void *))s723_extern_fn_symbol), s796_declaration);
	#line 76
	s358_codegen_group(v1_context, s715_extern_globals, ((s201_UID (*)(void *))s722_extern_global_symbol), s800_declaration);
	#line 80
	s358_codegen_group(v1_context, s716_extern_fns, ((s201_UID (*)(void *))s723_extern_fn_symbol), s797_implementation);
	#line 84
	s362_comment(v1_context, " Object Declarations");
	#line 86
	s358_codegen_group(v1_context, s719_structs, ((s201_UID (*)(void *))s726_struct_symbol), s782_declaration);
	#line 91
	s358_codegen_group(v1_context, s720_unions, ((s201_UID (*)(void *))s727_union_symbol), s782_declaration);
	#line 95
	s284_append_char((&((*v1_context).sb)), 10u);
	#line 96
	s362_comment(v1_context, " Functions Declarations");
	#line 98
	s358_codegen_group(v1_context, s716_extern_fns, ((s201_UID (*)(void *))s723_extern_fn_symbol), s796_declaration);
	#line 103
	s358_codegen_group(v1_context, s717_functions, ((s201_UID (*)(void *))s724_function_symbol), s796_declaration);
	#line 107
	s284_append_char((&((*v1_context).sb)), 10u);
	#line 108
	s362_comment(v1_context, " Object Definitions");
	#line 110
	s358_codegen_group(v1_context, s721_enums, ((s201_UID (*)(void *))s728_enum_symbol), s786_implementation);
	#line 115
	s358_codegen_group(v1_context, s719_structs, ((s201_UID (*)(void *))s726_struct_symbol), s783_implementation);
	#line 120
	s358_codegen_group(v1_context, s720_unions, ((s201_UID (*)(void *))s727_union_symbol), s783_implementation);
	#line 124
	s358_codegen_group(v1_context, s718_globals, ((s201_UID (*)(void *))s725_global_symbol), s800_declaration);
	#line 128
	s358_codegen_group(v1_context, s718_globals, ((s201_UID (*)(void *))s725_global_symbol), s801_implementation);
	#line 132
	s284_append_char((&((*v1_context).sb)), 10u);
	#line 133
	s362_comment(v1_context, " Functions Implementations");
	#line 134
	s358_codegen_group(v1_context, s716_extern_fns, ((s201_UID (*)(void *))s723_extern_fn_symbol), s797_implementation);
	#line 138
	s358_codegen_group(v1_context, s717_functions, ((s201_UID (*)(void *))s724_function_symbol), s797_implementation);
}


#line 145 "src/codegen/mod.ib"
void s357_codegen_symbol_implementation(s366_CodegenContext * v1_context, s201_UID v2_symbol) {
	#line 146
	if (s188_stage_eq(v2_symbol, s543_SymbolStage_ImplementationEmitted)) {
		#line 146
		return;
	}
	#line 147
	s729_Module * v3_m = ((s729_Module *)s251_get(((*v1_context).modules), (v2_symbol.module)));
	#line 148
	switch (s190_kind(v2_symbol)) {
	case s544_SymbolKind_Struct: {
	s783_implementation(v1_context, v3_m, v2_symbol);
	break; }
	case s544_SymbolKind_Union: {
	s783_implementation(v1_context, v3_m, v2_symbol);
	break; }
	case s544_SymbolKind_Enum: {
	s786_implementation(v1_context, v3_m, v2_symbol);
	break; }
	case s544_SymbolKind_Global: {
	break; }
	case s544_SymbolKind_Function: {
	break; }
	default:
		abort();
}
}


#line 157 "src/codegen/mod.ib"
void s358_codegen_group(s366_CodegenContext * v1_context, s257_Vec * (* v2_get_decl_vec)(s729_Module *), s201_UID (* v3_symbol_fn)(void *), void (* v4_codegen_fn)(s366_CodegenContext *, s729_Module *, s201_UID)) {
	#line 163
	for (i64 v5_i = 0l;(v5_i < ((*((*v1_context).modules)).count));v5_i += 1l) {
		#line 164
		s729_Module * v6_m = ((s729_Module *)s251_get(((*v1_context).modules), v5_i));
		#line 165
		s257_Vec * v7_decs = v2_get_decl_vec(v6_m);
		#line 166
		if ((((*v7_decs).count) == 0l)) {
			#line 166
			continue;
		}
		#line 167
		s40_assert((((*v6_m).uid) == v5_i), "mod.uid does not match idx");
		#line 168
		for (i64 v8_j = 0l;(v8_j < ((*v7_decs).count));v8_j += 1l) {
			#line 169
			s201_UID v9_symbol = v3_symbol_fn(s251_get(v7_decs, v8_j));
			#line 170
			v4_codegen_fn(v1_context, v6_m, v9_symbol);
			#line 171
			s359_codegen_flush(v1_context);
		}
		loop_exit_2:
	}
	loop_exit_1:
}


#line 177 "src/codegen/mod.ib"
void s359_codegen_flush(s366_CodegenContext * v1_context) {
	#line 178
	char * v2_merged = s294_merge((&((*v1_context).sb)));
	#line 179
	fputs(v2_merged, ((*v1_context).file));
	#line 180
	s295_reset((&((*v1_context).sb)));
}


#line 183 "src/codegen/mod.ib"
void s360_define(s366_CodegenContext * v1_context, char * v2_name, char * v3_value) {
	#line 184
	s283_append((&((*v1_context).sb)), "#define ");
	#line 185
	s283_append((&((*v1_context).sb)), v2_name);
	#line 186
	s283_append((&((*v1_context).sb)), " ");
	#line 187
	s283_append((&((*v1_context).sb)), v3_value);
	#line 188
	s284_append_char((&((*v1_context).sb)), 10u);
}


#line 191 "src/codegen/mod.ib"
void s361_include(s366_CodegenContext * v1_context, char * v2_message) {
	#line 192
	s283_append((&((*v1_context).sb)), "#include ");
	#line 193
	s283_append((&((*v1_context).sb)), v2_message);
	#line 194
	s284_append_char((&((*v1_context).sb)), 10u);
}


#line 198 "src/codegen/mod.ib"
void s362_comment(s366_CodegenContext * v1_context, char * v2_message) {
	#line 199
	s284_append_char((&((*v1_context).sb)), 47u);
	#line 200
	s284_append_char((&((*v1_context).sb)), 42u);
	#line 201
	s284_append_char((&((*v1_context).sb)), 32u);
	#line 202
	s283_append((&((*v1_context).sb)), v2_message);
	#line 203
	s284_append_char((&((*v1_context).sb)), 32u);
	#line 204
	s284_append_char((&((*v1_context).sb)), 42u);
	#line 205
	s284_append_char((&((*v1_context).sb)), 47u);
	#line 206
	s284_append_char((&((*v1_context).sb)), 10u);
}


#line 210 "src/codegen/mod.ib"
void s363_sourcemap(s366_CodegenContext * v1_context, i64 v2_span) {
	#line 211
	if ((!((*v1_context).enable_sourcemap))) {
		#line 211
		return;
	}
	#line 212
	s283_append((&((*v1_context).sb)), "#line ");
	#line 213
	s153_Span * v3_s = s146_get(v2_span);
	#line 214
	s165_Position v4_position = s160_find_position(((*v3_s).file), ((*v3_s).start));
	#line 215
	s289_append_number((&((*v1_context).sb)), ((v4_position.line) + 1l));
	#line 216
	s284_append_char((&((*v1_context).sb)), 32u);
	#line 217
	s284_append_char((&((*v1_context).sb)), 34u);
	#line 218
	s283_append((&((*v1_context).sb)), ((*v3_s).file));
	#line 219
	s284_append_char((&((*v1_context).sb)), 34u);
	#line 220
	s284_append_char((&((*v1_context).sb)), 10u);
}


#line 224 "src/codegen/mod.ib"
void s364_sourcemap_line(s366_CodegenContext * v1_context, i64 v2_span) {
	#line 225
	if ((!((*v1_context).enable_sourcemap))) {
		#line 225
		return;
	}
	#line 226
	s283_append((&((*v1_context).sb)), "#line ");
	#line 227
	s153_Span * v3_s = s146_get(v2_span);
	#line 228
	s165_Position v4_position = s160_find_position(((*v3_s).file), ((*v3_s).start));
	#line 229
	s289_append_number((&((*v1_context).sb)), ((v4_position.line) + 1l));
	#line 230
	s284_append_char((&((*v1_context).sb)), 10u);
}


#line 234 "src/codegen/mod.ib"
void s365_codegen_symbol(s299_StringBuilder * v1_sb, s201_UID v2_symbol) {
	#line 235
	if ((s191_is_extern(v2_symbol) || s196_is_preserve_name(v2_symbol))) {
		#line 236
		s283_append(v1_sb, s194_name(v2_symbol));
		#line 237
		return;
	}
	#line 239
	s284_append_char(v1_sb, 115u);
	#line 241
	s172_assert_exists(v2_symbol);
	#line 242
	s289_append_number(v1_sb, (v2_symbol.symbol));
	#line 243
	s284_append_char(v1_sb, 95u);
	#line 244
	s283_append(v1_sb, s194_name(v2_symbol));
}


#line 35 "src/symbol/table.ib"
s378_SymbolTable s367_new() {
	#line 36
	return ((s378_SymbolTable){
		.modules = s243_new(((i64)72ul), 256l),
		.imports = s243_new(((i64)24ul), 1024l),
		.last_symbol_uid = 0l,
		.next_module_uid = 0l
	});
}


#line 46 "src/symbol/table.ib"
void s368_free(s378_SymbolTable * v1_table) {
	#line 48
	for (i64 v2_i = 0l;(v2_i < (((*v1_table).modules).count));v2_i += 1l) {
		#line 49
		s377_ModuleMeta * v3_module = ((s377_ModuleMeta *)s251_get((&((*v1_table).modules)), v2_i));
		#line 50
		s246_free((&((*v3_module).symbols)));
	}
	loop_exit_1:
	#line 52
	((*v1_table).next_module_uid) = 0l;
	#line 53
	((*v1_table).last_symbol_uid) = 0l;
	#line 55
	s246_free((&((*v1_table).modules)));
	#line 56
	s246_free((&((*v1_table).imports)));
}


#line 60 "src/symbol/table.ib"
s201_UID s369_create_symbol(s378_SymbolTable * v1_table, i64 v2_module, char * v3_name, s544_SymbolKind v4_kind, i64 v5_span, bool v6_is_public, bool v7_is_extern) {
	#line 69
	s377_ModuleMeta * v8_mod = ((s377_ModuleMeta *)s251_get((&((*v1_table).modules)), v2_module));
	#line 70
	i64 v9_index = (((*v8_mod).symbols).count);
	#line 71
	s540_Symbol * v10_symbol = ((s540_Symbol *)s249_push((&((*v8_mod).symbols))));
	#line 73
	((*v1_table).last_symbol_uid) += 1l;
	#line 74
	i64 v11_uid = ((*v1_table).last_symbol_uid);
	#line 75
	(*v10_symbol) = ((s540_Symbol){
		.uid = v11_uid,
		.module = v2_module,
		.name = v3_name,
		.kind = v4_kind,
		.span = v5_span,
		.stage = s543_SymbolStage_Declared,
		.is_public = v6_is_public,
		.is_extern = v7_is_extern,
		.preserve_name = false,
		.shallow = ((s541_ShallowInfo){
			.unknown = NULL
		}),
		.deep = ((s542_DeepInfo){
			.unknown = NULL
		}),
		.type = ((s528_TypeIdent *)NULL),
		.used = false
	});
	#line 86
	return ((s201_UID){
		.module = v2_module,
		.symbol = v11_uid,
		.index = v9_index
	});
}


#line 90 "src/symbol/table.ib"
s540_Symbol * s370_get_symbol(s378_SymbolTable * v1_table, s201_UID v2_uid) {
	#line 92
	s40_assert(((v2_uid.module) < (((*v1_table).modules).count)), "find::symbol uid.module >= table.modules.count");
	#line 93
	s377_ModuleMeta * v3_module = ((s377_ModuleMeta *)s251_get((&((*v1_table).modules)), (v2_uid.module)));
	#line 94
	s40_assert((((*v3_module).uid) == (v2_uid.module)), "find::symbol module uid got corrupted");
	#line 95
	s40_assert(((v2_uid.index) < (((*v3_module).symbols).count)), "find::symbol uid.index >= module.symbols.count");
	#line 96
	s540_Symbol * v4_symbol = ((s540_Symbol *)s251_get((&((*v3_module).symbols)), (v2_uid.index)));
	#line 97
	s40_assert((((*v4_symbol).uid) == (v2_uid.symbol)), "find::symbol symbol uid got corrupted");
	#line 98
	return v4_symbol;
}


#line 102 "src/symbol/table.ib"
i64 s371_insert_module(s378_SymbolTable * v1_table, char * v2_module) {
	#line 103
	s377_ModuleMeta * v3_value = ((s377_ModuleMeta *)s249_push((&((*v1_table).modules))));
	#line 104
	((*v3_value).symbols) = s243_new(((i64)72ul), 64l);
	#line 105
	((*v3_value).name) = v2_module;
	#line 106
	((*v3_value).import_index) = (((*v1_table).imports).count);
	#line 107
	((*v3_value).import_length) = 0l;
	#line 108
	i64 v4_uid = ((*v1_table).next_module_uid);
	#line 109
	((*v3_value).uid) = v4_uid;
	#line 110
	((*v1_table).next_module_uid) = (((*v1_table).next_module_uid) + 1l);
	#line 111
	return v4_uid;
}


#line 115 "src/symbol/table.ib"
void s372_insert_imports(s378_SymbolTable * v1_table, s257_Vec * v2_imports) {
	#line 116
	s376_ModuleImport * v3_stored = ((s376_ModuleImport *)s253_push_many((&((*v1_table).imports)), ((*v2_imports).count)));
	#line 117
	for (i64 v4_i = 0l;(v4_i < ((*v2_imports).count));v4_i += 1l) {
		#line 118
		s376_ModuleImport * v5_imprt = ((s376_ModuleImport *)s251_get(v2_imports, v4_i));
		#line 119
		(v3_stored[v4_i]) = (*v5_imprt);
	}
	loop_exit_1:
}


#line 124 "src/symbol/table.ib"
s201_UID s373_find_symbol(s378_SymbolTable * v1_table, i64 v2_module_id, char * v3_ident) {
	#line 125
	s377_ModuleMeta * v4_module = ((s377_ModuleMeta *)s251_get((&((*v1_table).modules)), v2_module_id));
	#line 126
	s40_assert((((*v4_module).uid) == v2_module_id), "find::symbol module uid got corrupted");
	#line 127
	for (i64 v5_i = 0l;(v5_i < (((*v4_module).symbols).count));v5_i += 1l) {
		#line 128
		s540_Symbol * v6_symbol = ((s540_Symbol *)s251_get((&((*v4_module).symbols)), v5_i));
		#line 129
		s40_assert((((*v6_symbol).module) == v2_module_id), "find::symbol symbol module uid got corrupted");
		#line 130
		if ((((*v6_symbol).name) != v3_ident)) {
			#line 130
			continue;
		}
		#line 131
		return ((s201_UID){
			.module = v2_module_id,
			.symbol = ((*v6_symbol).uid),
			.index = v5_i
		});
	}
	loop_exit_1:
	#line 137
	return s168_NONE;
}


#line 141 "src/symbol/table.ib"
void s374_debug(s378_SymbolTable * v1_table) {
	#line 142
	for (i64 v2_i = 0l;(v2_i < (((*v1_table).modules).count));v2_i += 1l) {
		#line 143
		s377_ModuleMeta * v3_module = ((s377_ModuleMeta *)s251_get((&((*v1_table).modules)), v2_i));
		#line 144
		printf("Module: %d -> %s\n", v2_i, ((*v3_module).name));
		#line 145
		for (i64 v4_i = 0l;(v4_i < (((*v3_module).symbols).count));v4_i += 1l) {
			#line 146
			s540_Symbol * v5_value = ((s540_Symbol *)s251_get((&((*v3_module).symbols)), v4_i));
			#line 147
			s536_debug(v5_value);
		}
		loop_exit_2:
	}
	loop_exit_1:
}


#line 153 "src/symbol/table.ib"
void s375_debug_heads(s378_SymbolTable * v1_table) {
	#line 154
	printf("debug_heads\n");
	#line 155
	for (i64 v2_i = 0l;(v2_i < (((*v1_table).modules).count));v2_i += 1l) {
		#line 156
		s377_ModuleMeta * v3_module = ((s377_ModuleMeta *)s251_get((&((*v1_table).modules)), v2_i));
		#line 157
		for (i64 v4_j = 0l;(v4_j < (((*v3_module).symbols).count));v4_j += 1l) {
			#line 158
			s540_Symbol * v5_value = ((s540_Symbol *)s251_get((&((*v3_module).symbols)), v4_j));
			#line 160
			s537_print_ptr(v5_value);
			#line 161
			printf("\n");
			#line 162
			fflush(stdout);
		}
		loop_exit_2:
	}
	loop_exit_1:
}


#line 31 "src/storage/error.ib"
s401_Errors s385_new() {
	#line 32
	return ((s401_Errors){
		.errors = s243_new(((i64)56ul), 0l),
		.builder = s277_new(),
		.had_errors = false,
		.had_warnings = false
	});
}


#line 41 "src/storage/error.ib"
void s386_free(s401_Errors * v1_errors) {
	#line 42
	for (i64 v2_i = 0l;(v2_i < (((*v1_errors).errors).count));v2_i += 1l) {
		#line 43
		s402_Error * v3_error = ((s402_Error *)s251_get((&((*v1_errors).errors)), v2_i));
		#line 44
		if ((((*v3_error).message) != ((char *)NULL))) {
			#line 45
			free(((void *)((*v3_error).message)));
		}
	}
	loop_exit_1:
	#line 48
	s246_free((&((*v1_errors).errors)));
	#line 49
	s278_free((&((*v1_errors).builder)));
	#line 50
	((*v1_errors).had_errors) = false;
	#line 51
	((*v1_errors).had_warnings) = false;
}


#line 55 "src/storage/error.ib"
void s387_reset(s401_Errors * v1_errors) {
	#line 56
	s248_clear((&((*v1_errors).errors)));
	#line 57
	s295_reset((&((*v1_errors).builder)));
	#line 58
	((*v1_errors).had_errors) = false;
	#line 59
	((*v1_errors).had_warnings) = false;
}


#line 63 "src/storage/error.ib"
s402_Error * s388_push(s401_Errors * v1_errors, char * v2_header, s403_Level v3_level) {
	#line 64
	switch (v3_level) {
	case s403_Level_Error: {
		#line 65
		((*v1_errors).had_errors) = true;
	break; }
	case s403_Level_Warn: {
		#line 66
		((*v1_errors).had_warnings) = true;
	break; }
	case s403_Level_Info: {
	break; }
	default:
		abort();
}
	#line 69
	s402_Error * v4_err = ((s402_Error *)s249_push((&((*v1_errors).errors))));
	#line 70
	memset(((void *)v4_err), ((int)0l), 56ul);
	#line 71
	((*v4_err).header) = v2_header;
	#line 72
	((*v4_err).level) = v3_level;
	#line 73
	((*v4_err).span) = 0l;
	#line 74
	return v4_err;
}


#line 83 "src/storage/error.ib"
s402_Error * s389_lexer_error(s401_Errors * v1_errors) {
	#line 84
	return s388_push(v1_errors, s379_HEADER_LEXER, s403_Level_Error);
}


#line 86 "src/storage/error.ib"
s402_Error * s390_parser_error(s401_Errors * v1_errors) {
	#line 87
	return s388_push(v1_errors, s380_HEADER_PARSER, s403_Level_Error);
}


#line 89 "src/storage/error.ib"
s402_Error * s391_type_error(s401_Errors * v1_errors) {
	#line 90
	return s388_push(v1_errors, s381_HEADER_TYPE, s403_Level_Error);
}


#line 92 "src/storage/error.ib"
s402_Error * s392_type_warn(s401_Errors * v1_errors) {
	#line 93
	return s388_push(v1_errors, s382_HEADER_WARN_TYPE, s403_Level_Warn);
}


#line 97 "src/storage/error.ib"
void s393_entry_not_found(s401_Errors * v1_errors) {
	#line 98
	s402_Error * v2_error = s388_push(v1_errors, s383_HEADER_ERROR, s403_Level_Error);
	#line 99
	u64 v3_len = strlen(s384_ENTRY_NOT_FOUND);
	#line 100
	((*v2_error).message) = ((char *)malloc(((v3_len + ((u64)1l)) * 1ul)));
	#line 101
	(((*v2_error).message)[v3_len]) = 0u;
	#line 102
	memcpy(((void *)((*v2_error).message)), ((void *)s384_ENTRY_NOT_FOUND), v3_len);
}


#line 104 "src/storage/error.ib"
void s394_file_not_found(s401_Errors * v1_errors, char * v2_file) {
	#line 105
	s402_Error * v3_error = s388_push(v1_errors, s383_HEADER_ERROR, s403_Level_Error);
	#line 106
	char * v4_fmt = "Failed to open file \"%s\"";
	#line 107
	u64 v5_len = ((strlen(v4_fmt) + strlen(v2_file)) - ((u64)2l));
	#line 108
	((*v3_error).message) = ((char *)malloc(((v5_len + ((u64)1l)) * 1ul)));
	#line 109
	sprintf(((*v3_error).message), v4_fmt, v2_file);
}


#line 112 "src/storage/error.ib"
void s395_print_errors(s401_Errors * v1_errors) {
	#line 113
	s299_StringBuilder v2_sb = s277_new();
	#line 114
	s398_write_n((&v2_sb), v1_errors, true, 50l);
	#line 115
	fputs(s294_merge((&v2_sb)), stderr);
	#line 116
	s278_free((&v2_sb));
}


#line 120 "src/storage/error.ib"
void s396_write_errors(s299_StringBuilder * v1_sb, s401_Errors * v2_errors, bool v3_use_colors) {
	#line 121
	for (i64 v4_i = 0l;(v4_i < (((*v2_errors).errors).count));v4_i += 1l) {
		#line 122
		s402_Error * v5_error = ((s402_Error *)s251_get((&((*v2_errors).errors)), v4_i));
		#line 123
		if ((((*v5_error).level) != s403_Level_Error)) {
			#line 123
			continue;
		}
		#line 124
		s399_write(v1_sb, v5_error, v3_use_colors);
	}
	loop_exit_1:
}


#line 128 "src/storage/error.ib"
void s397_write_all(s299_StringBuilder * v1_sb, s401_Errors * v2_errors, bool v3_use_colors) {
	#line 129
	bool v4_print_warns = (!((*v2_errors).had_errors));
	#line 130
	bool v5_print_info = ((!((*v2_errors).had_errors)) && (!((*v2_errors).had_warnings)));
	#line 131
	for (i64 v6_i = 0l;(v6_i < (((*v2_errors).errors).count));v6_i += 1l) {
		#line 132
		s402_Error * v7_error = ((s402_Error *)s251_get((&((*v2_errors).errors)), v6_i));
		#line 133
		if (((((*v7_error).level) == s403_Level_Warn) && (!v4_print_warns))) {
			#line 133
			continue;
		}
		#line 134
		if (((((*v7_error).level) == s403_Level_Info) && (!v5_print_info))) {
			#line 134
			continue;
		}
		#line 135
		s399_write(v1_sb, v7_error, v3_use_colors);
	}
	loop_exit_1:
}


#line 139 "src/storage/error.ib"
void s398_write_n(s299_StringBuilder * v1_sb, s401_Errors * v2_errors, bool v3_use_colors, i64 v4_max_errs) {
	#line 140
	bool v5_print_warns = (!((*v2_errors).had_errors));
	#line 141
	bool v6_print_info = ((!((*v2_errors).had_errors)) && (!((*v2_errors).had_warnings)));
	#line 142
	i64 v7_count = (((*v2_errors).errors).count);
	#line 143
	if ((v7_count > v4_max_errs)) {
		#line 143
		v7_count = v4_max_errs;
	}
	#line 144
	for (i64 v8_i = 0l;(v8_i < v7_count);v8_i += 1l) {
		#line 145
		s402_Error * v9_error = ((s402_Error *)s251_get((&((*v2_errors).errors)), v8_i));
		#line 146
		if (((((*v9_error).level) == s403_Level_Warn) && (!v5_print_warns))) {
			#line 146
			continue;
		}
		#line 147
		if (((((*v9_error).level) == s403_Level_Info) && (!v6_print_info))) {
			#line 147
			continue;
		}
		#line 148
		s399_write(v1_sb, v9_error, v3_use_colors);
	}
	loop_exit_1:
}


#line 153 "src/storage/error.ib"
void s399_write(s299_StringBuilder * v1_sb, s402_Error * v2_err, bool v3_use_colors) {
	#line 154
	if (v3_use_colors) {
		#line 155
		s400_level_color(v1_sb, ((*v2_err).level));
	}
	#line 157
	s283_append(v1_sb, ((*v2_err).header));
	#line 158
	if (v3_use_colors) {
		#line 159
		s283_append(v1_sb, s234_RESET);
	}
	#line 161
	s283_append(v1_sb, ": ");
	#line 162
	if ((((*v2_err).message) != ((char *)NULL))) {
		#line 163
		s283_append(v1_sb, ((*v2_err).message));
	}
	#line 165
	s284_append_char(v1_sb, 10u);
	#line 166
	if ((((*v2_err).span) != 0l)) {
		#line 167
		s154_PrintOptions v4_options = ((*v2_err).span_options);
		#line 168
		(v4_options.use_colors) = v3_use_colors;
		#line 169
		s151_write_ex(v1_sb, ((*v2_err).span), v4_options);
	}
	#line 171
	s284_append_char(v1_sb, 10u);
}


#line 175 "src/storage/error.ib"
void s400_level_color(s299_StringBuilder * v1_sb, s403_Level v2_level) {
	#line 176
	switch (v2_level) {
	case s403_Level_Error: {
	s283_append(v1_sb, s230_RED);
	break; }
	case s403_Level_Warn: {
	s283_append(v1_sb, s232_YELLOW);
	break; }
	case s403_Level_Info: {
	s283_append(v1_sb, s233_BLUE);
	break; }
	default:
		abort();
}
}


#line 4 "src/utils/mod.ib"
void s404_debug_str(char * v1_message) {
	#line 5
	putchar(((int)34u));
	#line 6
	for (i64 v2_i = 0l;((v1_message[v2_i]) != 0u);v2_i += 1l) {
		#line 7
		switch ((v1_message[v2_i])) {
		case 0u: {
		printf("\\0");
		break; }
		case 10u: {
		printf("\\n");
		break; }
		case 9u: {
		printf("\\t");
		break; }
		case 13u: {
		printf("\\r");
		break; }
		default:
 {
		putchar(((int)(v1_message[v2_i])));
		break; }
}
	}
	loop_exit_1:
	#line 15
	putchar(((int)34u));
}


#line 19 "src/utils/mod.ib"
void s405_debug_char(char v1_chr) {
	#line 20
	switch (v1_chr) {
	case 0u: {
	printf("'\\0'");
	break; }
	case 10u: {
	printf("'\\n'");
	break; }
	case 9u: {
	printf("'\\t'");
	break; }
	case 13u: {
	printf("'\\r'");
	break; }
	default:
 {
	printf("'%c'", v1_chr);
	break; }
}
}


#line 30 "src/utils/mod.ib"
void s406_todo(char * v1_message) {
	#line 31
	printf("TODO: %s\n", v1_message);
	#line 32
	abort();
}


#line 19 "src/lsp/json.ib"
s439_Result s407_parse(char * v1_content, i64 v2_len) {
	#line 20
	s445_Parser v3_parser = s429_create_parser(v1_content, v2_len);
	#line 23
	s440_Node * v4_node = ((s440_Node *)s432_allocate((&v3_parser), ((i64)24ul)));
	#line 24
	s448_Status v5_status = s415_parse_value((&v3_parser), v4_node);
	#line 25
	if ((v5_status != s448_Status_Ok)) {
		#line 25
		s408_free(v4_node);
	}
	#line 27
	return ((s439_Result){
		.status = v5_status,
		.node = v4_node
	});
}


#line 30 "src/lsp/json.ib"
void s408_free(s440_Node * v1_node) {
	#line 31
	if ((v1_node != ((s440_Node *)NULL))) {
		#line 32
		free(((void *)v1_node));
	}
}


#line 36 "src/lsp/json.ib"
s440_Node * s409_get(s440_Node * v1_node, i64 v2_index) {
	#line 37
	if ((v1_node == ((s440_Node *)NULL))) {
		#line 37
		return ((s440_Node *)NULL);
	}
	#line 38
	if ((((*v1_node).type) != s449_NodeType_Array)) {
		#line 38
		return ((s440_Node *)NULL);
	}
	#line 39
	if (((v2_index < 0l) || (v2_index >= ((((*v1_node).data).array).count)))) {
		#line 39
		return ((s440_Node *)NULL);
	}
	#line 40
	return (&(((((*v1_node).data).array).elems)[v2_index]));
}


#line 43 "src/lsp/json.ib"
s440_Node * s410_lookup(s440_Node * v1_node, char * v2_field) {
	#line 44
	if ((v1_node == ((s440_Node *)NULL))) {
		#line 44
		return ((s440_Node *)NULL);
	}
	#line 45
	if ((((*v1_node).type) != s449_NodeType_Object)) {
		#line 45
		return ((s440_Node *)NULL);
	}
	#line 46
	for (i64 v3_i = 0l;(v3_i < ((((*v1_node).data).object).count));v3_i += 1l) {
		#line 47
		s442_ObjectEntry * v4_entry = (&(((((*v1_node).data).object).entries)[v3_i]));
		#line 48
		if ((((i64)strcmp(v2_field, ((*v4_entry).key))) == 0l)) {
			#line 49
			return ((*v4_entry).value);
		}
	}
	loop_exit_1:
	#line 52
	return ((s440_Node *)NULL);
}


#line 55 "src/lsp/json.ib"
bool s411_as_bool(s440_Node * v1_node) {
	#line 56
	if ((v1_node == ((s440_Node *)NULL))) {
		#line 56
		return false;
	}
	#line 57
	if ((((*v1_node).type) != s449_NodeType_Bool)) {
		#line 57
		return false;
	}
	#line 58
	return (((*v1_node).data).boolean);
}


#line 60 "src/lsp/json.ib"
i64 s412_as_number(s440_Node * v1_node) {
	#line 61
	if ((v1_node == ((s440_Node *)NULL))) {
		#line 61
		return 0l;
	}
	#line 62
	if ((((*v1_node).type) != s449_NodeType_Number)) {
		#line 62
		return 0l;
	}
	#line 63
	return (((*v1_node).data).number);
}


#line 65 "src/lsp/json.ib"
char * s413_as_str(s440_Node * v1_node) {
	#line 66
	if ((v1_node == ((s440_Node *)NULL))) {
		#line 66
		return ((char *)NULL);
	}
	#line 67
	if ((((*v1_node).type) != s449_NodeType_String)) {
		#line 67
		return ((char *)NULL);
	}
	#line 68
	return ((((*v1_node).data).string).content);
}


#line 70 "src/lsp/json.ib"
i64 s414_length(s440_Node * v1_node) {
	#line 71
	if ((v1_node == ((s440_Node *)NULL))) {
		#line 71
		return 0l;
	}
	#line 72
	if ((((*v1_node).type) == s449_NodeType_String)) {
		#line 72
		return ((((*v1_node).data).string).length);
	}
	#line 73
	if ((((*v1_node).type) == s449_NodeType_Array)) {
		#line 73
		return ((((*v1_node).data).array).count);
	}
	#line 74
	if ((((*v1_node).type) == s449_NodeType_Object)) {
		#line 74
		return ((((*v1_node).data).array).count);
	}
	#line 75
	return 0l;
}


#line 132 "src/lsp/json.ib"
s448_Status s415_parse_value(s445_Parser * v1_parser, s440_Node * v2_node) {
	#line 133
	s428_whitespace(v1_parser);
	#line 134
	switch (s426_curr(v1_parser)) {
	case 123u: {
	return s420_parse_object(v1_parser, v2_node);
	break; }
	case 34u: {
	return s417_parse_string_node(v1_parser, v2_node);
	break; }
	case 91u: {
	return s421_parse_array(v1_parser, v2_node);
	break; }
	default:
 {
		#line 139
		if (s437_is_numeric(s426_curr(v1_parser))) {
			#line 140
			return s416_parse_number(v1_parser, v2_node);
		}
		#line 142
		return s419_parse_literal(v1_parser, v2_node);
	break; }
}
}


#line 148 "src/lsp/json.ib"
s448_Status s416_parse_number(s445_Parser * v1_parser, s440_Node * v2_node) {
	#line 149
	bool v3_negated = false;
	#line 150
	if ((s426_curr(v1_parser) == 45u)) {
		#line 151
		v3_negated = true;
		#line 152
		s425_step(v1_parser);
	}
	#line 154
	i64 v4_whole = 0l;
	#line 157
	while (s437_is_numeric(s426_curr(v1_parser))) {
		#line 158
		v4_whole *= 10l;
		#line 159
		v4_whole += ((i64)(s426_curr(v1_parser) - 48u));
		#line 160
		s425_step(v1_parser);
}
	loop_exit_1:
	#line 162
	((*v2_node).type) = s449_NodeType_Number;
	#line 163
	(((*v2_node).data).number) = v4_whole;
	#line 164
	if (v3_negated) {
		#line 165
		(((*v2_node).data).number) *= (-1l);
	}
	#line 167
	return s448_Status_Ok;
}


#line 170 "src/lsp/json.ib"
s448_Status s417_parse_string_node(s445_Parser * v1_parser, s440_Node * v2_node) {
	#line 171
	((*v2_node).type) = s449_NodeType_String;
	#line 172
	s446_ParseStringResult v3_res = s418_parse_string(v1_parser);
	#line 173
	if (((v3_res.status) != s448_Status_Ok)) {
		#line 173
		return (v3_res.status);
	}
	#line 175
	((((*v2_node).data).string).content) = (v3_res.string);
	#line 176
	((((*v2_node).data).string).length) = (v3_res.length);
	#line 177
	return s448_Status_Ok;
}


#line 186 "src/lsp/json.ib"
s446_ParseStringResult s418_parse_string(s445_Parser * v1_parser) {
	#line 187
	s446_ParseStringResult v2_result = ((s446_ParseStringResult){

	});
	#line 189
	s425_step(v1_parser);
	#line 190
	i64 v3_start = ((*v1_parser).current);
	#line 191
	while (((!s424_is_end(v1_parser)) && (s426_curr(v1_parser) != 34u))) {
		#line 192
		if ((s426_curr(v1_parser) == 92u)) {
			#line 192
			s425_step(v1_parser);
		}
		#line 193
		s425_step(v1_parser);
}
	loop_exit_1:
	#line 195
	if (s424_is_end(v1_parser)) {
		#line 196
		(v2_result.status) = s448_Status_UnterminatedString;
		#line 197
		return v2_result;
	}
	#line 200
	i64 v4_len = (((*v1_parser).current) - v3_start);
	#line 201
	char * v5_string = ((char *)s430_allocate_str(v1_parser, ((i64)(1ul * ((u64)(v4_len + 1l))))));
	#line 202
	((*v1_parser).current) = v3_start;
	#line 203
	i64 v6_i = 0l;
	#line 204
	while ((s426_curr(v1_parser) != 34u)) {
		#line 205
		s448_Status v7_res = s423_step_unescape(v1_parser, (&(v5_string[v6_i])));
		#line 206
		if ((v7_res != s448_Status_Ok)) {
			#line 207
			(v2_result.status) = v7_res;
			#line 208
			return v2_result;
		}
		#line 210
		v6_i += 1l;
}
	loop_exit_2:
	#line 212
	(v5_string[v6_i]) = 0u;
	#line 213
	s425_step(v1_parser);
	#line 215
	(v2_result.status) = s448_Status_Ok;
	#line 216
	(v2_result.length) = v6_i;
	#line 217
	(v2_result.string) = v5_string;
	#line 218
	return v2_result;
}


#line 223 "src/lsp/json.ib"
s448_Status s419_parse_literal(s445_Parser * v1_parser, s440_Node * v2_node) {
	#line 224
	if (s422_match_str(v1_parser, "true")) {
		#line 225
		((*v2_node).type) = s449_NodeType_Bool;
		#line 226
		(((*v2_node).data).boolean) = true;
		#line 227
		return s448_Status_Ok;
	}
	#line 229
	if (s422_match_str(v1_parser, "false")) {
		#line 230
		((*v2_node).type) = s449_NodeType_Bool;
		#line 231
		(((*v2_node).data).boolean) = false;
		#line 232
		return s448_Status_Ok;
	}
	#line 234
	if (s422_match_str(v1_parser, "null")) {
		#line 235
		((*v2_node).type) = s449_NodeType_Null;
		#line 236
		(((*v2_node).data).number) = 0l;
		#line 237
		return s448_Status_Ok;
	}
	#line 239
	return s448_Status_UnknownValue;
}


#line 242 "src/lsp/json.ib"
s448_Status s420_parse_object(s445_Parser * v1_parser, s440_Node * v2_node) {
	#line 243
	((*v2_node).type) = s449_NodeType_Object;
	#line 244
	s425_step(v1_parser);
	#line 245
	s428_whitespace(v1_parser);
	#line 246
	if ((s426_curr(v1_parser) == 125u)) {
		#line 247
		s425_step(v1_parser);
		#line 248
		((((*v2_node).data).object).count) = 0l;
		#line 249
		((((*v2_node).data).object).entries) = ((s442_ObjectEntry *)NULL);
		#line 250
		return s448_Status_Ok;
	}
	#line 253
	i64 v3_count = 0l;
	#line 254
	while ((!s424_is_end(v1_parser))) {
		#line 255
		v3_count += 1l;
		#line 257
		s446_ParseStringResult v4_key_res = s418_parse_string(v1_parser);
		#line 258
		if (((v4_key_res.status) != s448_Status_Ok)) {
			#line 258
			return (v4_key_res.status);
		}
		#line 260
		s428_whitespace(v1_parser);
		#line 261
		if ((s426_curr(v1_parser) != 58u)) {
			#line 261
			return s448_Status_ExpectedColon;
		}
		#line 262
		s425_step(v1_parser);
		#line 263
		s428_whitespace(v1_parser);
		#line 265
		s440_Node * v5_value = ((s440_Node *)s432_allocate(v1_parser, ((i64)24ul)));
		#line 266
		s448_Status v6_res = s415_parse_value(v1_parser, v5_value);
		#line 267
		if ((v6_res != s448_Status_Ok)) {
			#line 267
			return v6_res;
		}
		#line 268
		s428_whitespace(v1_parser);
		#line 270
		s442_ObjectEntry * v7_entry = ((s442_ObjectEntry *)s433_push(v1_parser, ((i64)16ul)));
		#line 271
		((*v7_entry).key) = (v4_key_res.string);
		#line 272
		((*v7_entry).value) = v5_value;
		#line 274
		if ((s426_curr(v1_parser) == 125u)) {
			#line 274
						goto loop_exit_1;
/* break; */
		}
		#line 275
		if ((s426_curr(v1_parser) != 44u)) {
			#line 275
			return s448_Status_ExpectedComma;
		}
		#line 276
		s425_step(v1_parser);
		#line 277
		s428_whitespace(v1_parser);
}
	loop_exit_1:
	#line 279
	s425_step(v1_parser);
	#line 281
	((((*v2_node).data).object).entries) = ((s442_ObjectEntry *)s431_head(v1_parser, ((i64)(16ul * ((u64)v3_count)))));
	#line 282
	for (i64 v8_i = 0l;(v8_i < v3_count);v8_i += 1l) {
		#line 284
		s442_ObjectEntry * v9_ptr = ((s442_ObjectEntry *)s434_pop(v1_parser, ((i64)16ul)));
		#line 285
		s442_ObjectEntry v10_entry = (*v9_ptr);
		#line 286
		(((((*v2_node).data).object).entries)[v8_i]) = v10_entry;
	}
	loop_exit_2:
	#line 288
	s432_allocate(v1_parser, ((i64)(16ul * ((u64)v3_count))));
	#line 289
	((((*v2_node).data).object).count) = v3_count;
	#line 290
	return s448_Status_Ok;
}


#line 293 "src/lsp/json.ib"
s448_Status s421_parse_array(s445_Parser * v1_parser, s440_Node * v2_node) {
	#line 294
	((*v2_node).type) = s449_NodeType_Array;
	#line 295
	s425_step(v1_parser);
	#line 296
	s428_whitespace(v1_parser);
	#line 297
	if ((s426_curr(v1_parser) == 93u)) {
		#line 298
		s425_step(v1_parser);
		#line 299
		((((*v2_node).data).array).count) = 0l;
		#line 300
		((((*v2_node).data).array).elems) = ((s440_Node *)NULL);
		#line 301
		return s448_Status_Ok;
	}
	#line 304
	i64 v3_count = 0l;
	#line 305
	while ((!s424_is_end(v1_parser))) {
		#line 306
		s440_Node * v4_element = ((s440_Node *)s433_push(v1_parser, ((i64)24ul)));
		#line 307
		s448_Status v5_res = s415_parse_value(v1_parser, v4_element);
		#line 308
		if ((v5_res != s448_Status_Ok)) {
			#line 308
			return v5_res;
		}
		#line 309
		v3_count += 1l;
		#line 310
		s428_whitespace(v1_parser);
		#line 312
		if ((s426_curr(v1_parser) == 93u)) {
			#line 312
						goto loop_exit_1;
/* break; */
		}
		#line 313
		if ((s426_curr(v1_parser) != 44u)) {
			#line 313
			return s448_Status_ExpectedComma;
		}
		#line 314
		s425_step(v1_parser);
		#line 315
		s428_whitespace(v1_parser);
}
	loop_exit_1:
	#line 317
	s425_step(v1_parser);
	#line 319
	((((*v2_node).data).array).elems) = ((s440_Node *)s431_head(v1_parser, ((i64)(24ul * ((u64)v3_count)))));
	#line 320
	for (i64 v6_i = 0l;(v6_i < v3_count);v6_i += 1l) {
		#line 322
		s440_Node * v7_ptr = ((s440_Node *)s434_pop(v1_parser, ((i64)24ul)));
		#line 323
		s440_Node v8_element = (*v7_ptr);
		#line 324
		(((((*v2_node).data).array).elems)[v6_i]) = v8_element;
	}
	loop_exit_2:
	#line 326
	s432_allocate(v1_parser, ((i64)(24ul * ((u64)v3_count))));
	#line 327
	for (i64 v9_i = 0l;(v9_i < (v3_count / 2l));v9_i += 1l) {
		#line 328
		s440_Node v10_temp = (((((*v2_node).data).array).elems)[((v3_count - v9_i) - 1l)]);
		#line 329
		(((((*v2_node).data).array).elems)[((v3_count - v9_i) - 1l)]) = (((((*v2_node).data).array).elems)[v9_i]);
		#line 330
		(((((*v2_node).data).array).elems)[v9_i]) = v10_temp;
	}
	loop_exit_3:
	#line 332
	((((*v2_node).data).array).count) = v3_count;
	#line 333
	return s448_Status_Ok;
}


#line 337 "src/lsp/json.ib"
bool s422_match_str(s445_Parser * v1_parser, char * v2_rest) {
	#line 338
	i64 v3_i = 0l;
	#line 339
	while (((v2_rest[v3_i]) != 0u)) {
		#line 340
		if (((v2_rest[v3_i]) != s427_peek(v1_parser, v3_i))) {
			#line 340
			return false;
		}
		#line 341
		v3_i += 1l;
}
	loop_exit_1:
	#line 343
	((*v1_parser).current) += v3_i;
	#line 344
	return true;
}


#line 347 "src/lsp/json.ib"
s448_Status s423_step_unescape(s445_Parser * v1_parser, char * v2_out) {
	#line 348
	char v3_c = s426_curr(v1_parser);
	#line 350
	if ((v3_c == 92u)) {
		#line 351
		s425_step(v1_parser);
		#line 352
		v3_c = s426_curr(v1_parser);
		#line 353
		switch (v3_c) {
		case 110u: {
		v3_c = 10u;
		break; }
		case 116u: {
		v3_c = 9u;
		break; }
		case 114u: {
		v3_c = 13u;
		break; }
		case 34u: {
		v3_c = 34u;
		break; }
		case 47u: {
		v3_c = 47u;
		break; }
		case 92u: {
		v3_c = 92u;
		break; }
		default:
 {
		return s448_Status_UnknownEscape;
		break; }
}
	}
	#line 363
	s425_step(v1_parser);
	#line 364
	(*v2_out) = v3_c;
	#line 365
	return s448_Status_Ok;
}


#line 369 "src/lsp/json.ib"
bool s424_is_end(s445_Parser * v1_parser) {
	#line 369
	return (((*v1_parser).current) >= ((*v1_parser).length));
}


#line 370 "src/lsp/json.ib"
void s425_step(s445_Parser * v1_parser) {
	#line 370
	((*v1_parser).current) += 1l;
}


#line 371 "src/lsp/json.ib"
char s426_curr(s445_Parser * v1_parser) {
	#line 372
	if ((((*v1_parser).current) >= ((*v1_parser).length))) {
		#line 372
		return 0u;
	}
	#line 373
	return (((*v1_parser).content)[((*v1_parser).current)]);
}


#line 375 "src/lsp/json.ib"
char s427_peek(s445_Parser * v1_parser, i64 v2_offset) {
	#line 376
	if (((((*v1_parser).current) + v2_offset) >= ((*v1_parser).length))) {
		#line 376
		return 0u;
	}
	#line 377
	return (((*v1_parser).content)[(((*v1_parser).current) + v2_offset)]);
}


#line 379 "src/lsp/json.ib"
void s428_whitespace(s445_Parser * v1_parser) {
	#line 380
	while (1) {
		#line 380
		switch (s426_curr(v1_parser)) {
		case 32u:
		case 9u:
		case 13u:
		case 10u: {
		s425_step(v1_parser);
		break; }
		default:
 {
		return;
		break; }
}
}
	loop_exit_1:
}


#line 386 "src/lsp/json.ib"
s445_Parser s429_create_parser(char * v1_content, i64 v2_len) {
	#line 387
	s445_Parser v3_parser = ((s445_Parser){

	});
	#line 388
	(v3_parser.content) = v1_content;
	#line 389
	(v3_parser.length) = v2_len;
	#line 390
	(v3_parser.current) = 0l;
	#line 392
	i64 v4_string_size = 0l;
	#line 393
	(v3_parser.capacity) = s436_estimate_alloca_size(v1_content, v2_len, (&v4_string_size));
	#line 394
	(v3_parser.alloca) = ((char *)malloc((1ul * ((u64)(v3_parser.capacity)))));
	#line 395
	(v3_parser.stack) = ((v3_parser.capacity) - v4_string_size);
	#line 396
	(v3_parser.strings) = (v3_parser.stack);
	#line 397
	(v3_parser.size) = 0l;
	#line 398
	return v3_parser;
}


#line 401 "src/lsp/json.ib"
void * s430_allocate_str(s445_Parser * v1_parser, i64 v2_size) {
	#line 403
	s40_assert(((((*v1_parser).strings) + v2_size) <= ((*v1_parser).capacity)), "json::allocate_str");
	#line 404
	char * v3_ptr = (&(((*v1_parser).alloca)[((*v1_parser).strings)]));
	#line 405
	((*v1_parser).strings) += v2_size;
	#line 406
	return ((void *)v3_ptr);
}


#line 409 "src/lsp/json.ib"
void * s431_head(s445_Parser * v1_parser, i64 v2__size) {
	#line 410
	return ((void *)(&(((*v1_parser).alloca)[s435_with_alignment(((*v1_parser).size))])));
}


#line 413 "src/lsp/json.ib"
void * s432_allocate(s445_Parser * v1_parser, i64 v2_size) {
	#line 414
	v2_size = s435_with_alignment(v2_size);
	#line 415
	s40_assert(((((*v1_parser).size) + v2_size) < ((*v1_parser).stack)), "json::allocate");
	#line 416
	char * v3_ptr = (&(((*v1_parser).alloca)[((*v1_parser).size)]));
	#line 417
	((*v1_parser).size) += v2_size;
	#line 418
	return ((void *)v3_ptr);
}


#line 421 "src/lsp/json.ib"
void * s433_push(s445_Parser * v1_parser, i64 v2_size) {
	#line 422
	v2_size = s435_with_alignment(v2_size);
	#line 423
	s40_assert((((*v1_parser).size) < (((*v1_parser).stack) - v2_size)), "json::push");
	#line 424
	((*v1_parser).stack) -= v2_size;
	#line 425
	return ((void *)(&(((*v1_parser).alloca)[((*v1_parser).stack)])));
}


#line 428 "src/lsp/json.ib"
void * s434_pop(s445_Parser * v1_parser, i64 v2_size) {
	#line 429
	v2_size = s435_with_alignment(v2_size);
	#line 430
	char * v3_ptr = (&(((*v1_parser).alloca)[((*v1_parser).stack)]));
	#line 431
	((*v1_parser).stack) += v2_size;
	#line 432
	return ((void *)v3_ptr);
}


#line 436 "src/lsp/json.ib"
i64 s435_with_alignment(i64 v1_size) {
	#line 437
	i64 v2_rem = (v1_size % 8l);
	#line 438
	if ((v2_rem == 0l)) {
		#line 438
		return v1_size;
	}
	#line 439
	return (v1_size + (8l - v2_rem));
}


#line 443 "src/lsp/json.ib"
i64 s436_estimate_alloca_size(char * v1_content, i64 v2_len, i64 * v3_str_size) {
	#line 444
	i64 v4_node_count = 0l;
	#line 445
	i64 v5_string_size = 0l;
	#line 447
	for (i64 v6_i = 0l;(v6_i < v2_len);v6_i += 1l) {
		#line 448
		char v7_c = (v1_content[v6_i]);
		#line 449
		switch (v7_c) {
		case 91u:
		case 123u: {
			#line 451
			v4_node_count += 1l;
		break; }
		case 110u: {
			#line 454
			v4_node_count += 1l;
			#line 455
			v6_i += 3l;
		break; }
		case 102u: {
			#line 458
			v4_node_count += 1l;
			#line 459
			v6_i += 4l;
		break; }
		case 116u: {
			#line 462
			v4_node_count += 1l;
			#line 463
			v6_i += 3l;
		break; }
		case 34u: {
			#line 466
			i64 v8_start = v6_i;
			#line 467
			v6_i += 1l;
			#line 468
			while (((v6_i < v2_len) && ((v1_content[v6_i]) != 34u))) {
				#line 469
				if (((v1_content[v6_i]) == 92u)) {
					#line 469
					v6_i += 1l;
				}
				#line 470
				v6_i += 1l;
}
			loop_exit_2:
			#line 472
			v5_string_size += (v6_i - v8_start);
			#line 473
			v4_node_count += 1l;
		break; }
		default:
 {
			#line 476
			if (s437_is_numeric(v7_c)) {
				#line 477
				v4_node_count += 1l;
				#line 478
				v6_i += 1l;
				#line 479
				while (((v6_i < v2_len) && s437_is_numeric((v1_content[v6_i])))) {
					#line 479
					v6_i += 1l;
}
				loop_exit_3:
			}
		break; }
}
	}
	loop_exit_1:
	#line 484
	(*v3_str_size) = v5_string_size;
	#line 485
	i64 v9_total = ((((v4_node_count * ((i64)24ul)) + (v4_node_count * ((i64)16ul))) + (v5_string_size * ((i64)1ul))) + 128l);
	#line 489
	return v9_total;
}


#line 493 "src/lsp/json.ib"
bool s437_is_numeric(char v1_c) {
	#line 494
	return ((v1_c == 45u) || ((v1_c >= 48u) && (v1_c <= 57u)));
}


#line 496 "src/lsp/json.ib"
bool s438_is_alpha(char v1_c) {
	#line 497
	return (((v1_c >= 97u) && (v1_c <= 122u)) || ((v1_c >= 65u) && (v1_c <= 90u)));
}


#line 42 "src/lsp/request.ib"
bool s450_has_next(s462_Parser * v1_parser) {
	#line 43
	return (((i64)feof(((void *)((*v1_parser).stream)))) == 0l);
}


#line 46 "src/lsp/request.ib"
bool s451_whitespace(s462_Parser * v1_parser) {
	#line 47
	int v2_c = fgetc(((void *)((*v1_parser).stream)));
	#line 48
	if ((((v2_c >= ((int)97u)) && (v2_c <= ((int)122u))) || ((v2_c >= ((int)65u)) && (v2_c <= ((int)90u))))) {
		#line 49
		ungetc(v2_c, ((void *)((*v1_parser).stream)));
		#line 50
		return false;
	}
	#line 52
	return true;
}


#line 56 "src/lsp/request.ib"
s462_Parser s452_new_parser(i64 * v1_log) {
	#line 57
	return ((s462_Parser){
		.log = v1_log,
		.stream = ((i64 *)stdin),
		.content = ((char *)NULL),
		.capacity = 0l
	});
}


#line 65 "src/lsp/request.ib"
void s453_free_parser(s462_Parser * v1_parser) {
	#line 66
	free(((void *)((*v1_parser).content)));
	#line 67
	((*v1_parser).capacity) = 0l;
	#line 68
	((*v1_parser).content) = ((char *)NULL);
}


#line 72 "src/lsp/request.ib"
s461_Request s454_read(s462_Parser * v1_parser) {
	#line 73
	i64 v2_len = s456_content_length(v1_parser);
	#line 75
	s461_Request v3_request = ((s461_Request){

	});
	#line 76
	(v3_request.method) = s463_Method_None;
	#line 78
	s458_with_capacity(v1_parser, (v2_len + 1l));
	#line 79
	u64 v4__read_amount = fread(((void *)((*v1_parser).content)), 1ul, ((u64)v2_len), ((void *)((*v1_parser).stream)));
	#line 82
	s457_clear(v1_parser, v2_len);
	#line 84
	fprintf(((void *)((*v1_parser).log)), "%s\n\n", ((*v1_parser).content));
	#line 86
	s439_Result v5_res = s407_parse(((*v1_parser).content), v2_len);
	#line 87
	if (((v5_res.status) != s448_Status_Ok)) {
		#line 88
		fprintf(((void *)((*v1_parser).log)), "[ERROR] Failed to parse json:\n");
		#line 89
		return v3_request;
	}
	#line 92
	(v3_request.json) = (v5_res.node);
	#line 97
	(v3_request.id) = s412_as_number(s410_lookup((v5_res.node), "id"));
	#line 98
	char * v6_method = s413_as_str(s410_lookup((v5_res.node), "method"));
	#line 99
	(v3_request.method) = s459_from_str(v6_method);
	#line 100
	fprintf(((void *)((*v1_parser).log)), "[INFO] Read request method: \"%s\"\n", v6_method);
	#line 102
	(v3_request.params) = s410_lookup((v5_res.node), "params");
	#line 104
	return v3_request;
}


#line 107 "src/lsp/request.ib"
void s455_free(s461_Request * v1_request) {
	#line 108
	s408_free(((*v1_request).json));
	#line 109
	((*v1_request).id) = 0l;
	#line 110
	((*v1_request).params) = ((s440_Node *)NULL);
	#line 111
	((*v1_request).json) = ((s440_Node *)NULL);
	#line 112
	((*v1_request).method) = s463_Method_None;
}


#line 116 "src/lsp/request.ib"
i64 s456_content_length(s462_Parser * v1_parser) {
	#line 117
	i64 v2_len = 0l;
	#line 118
	fscanf(((void *)((*v1_parser).stream)), "Content-Length: %d", (&v2_len));
	#line 119
	fprintf(((void *)((*v1_parser).log)), "[INFO] Got Content-Length: %d\n", v2_len);
	#line 120
	char v3_c = 48u;
	#line 121
	i64 v4_new_lines = 0l;
	#line 122
	while (((v4_new_lines < 2l) && (((i64)v3_c) != (-1l)))) {
		#line 123
		v3_c = ((char)fgetc(((void *)((*v1_parser).stream))));
		#line 124
		if ((v3_c == 10u)) {
			#line 124
			v4_new_lines += 1l;
		}
}
	loop_exit_1:
	#line 126
	return v2_len;
}


#line 130 "src/lsp/request.ib"
void s457_clear(s462_Parser * v1_parser, i64 v2_len) {
	#line 131
	(((*v1_parser).content)[v2_len]) = 0u;
}


#line 135 "src/lsp/request.ib"
void s458_with_capacity(s462_Parser * v1_parser, i64 v2_capacity) {
	#line 136
	if ((((*v1_parser).capacity) >= v2_capacity)) {
		#line 136
		return;
	}
	#line 137
	i64 v3_new_capacity = (v2_capacity * 2l);
	#line 138
	((*v1_parser).content) = ((char *)realloc(((void *)((*v1_parser).content)), (1ul * ((u64)v3_new_capacity))));
	#line 139
	((*v1_parser).capacity) = v3_new_capacity;
}


#line 143 "src/lsp/request.ib"
s463_Method s459_from_str(char * v1_s) {
	#line 144
	if ((((i64)strcmp(v1_s, "initialize")) == 0l)) {
		#line 144
		return s463_Method_Initialize;
	}
	#line 145
	if ((((i64)strcmp(v1_s, "initialized")) == 0l)) {
		#line 145
		return s463_Method_Initialized;
	}
	#line 146
	if ((((i64)strcmp(v1_s, "shutdown")) == 0l)) {
		#line 146
		return s463_Method_Shutdown;
	}
	#line 147
	if ((((i64)strcmp(v1_s, "exit")) == 0l)) {
		#line 147
		return s463_Method_Exit;
	}
	#line 149
	if ((((i64)strcmp(v1_s, "textDocument/didOpen")) == 0l)) {
		#line 149
		return s463_Method_TextDocumentDidOpen;
	}
	#line 150
	if ((((i64)strcmp(v1_s, "textDocument/didChange")) == 0l)) {
		#line 150
		return s463_Method_TextDocumentDidChange;
	}
	#line 151
	if ((((i64)strcmp(v1_s, "textDocument/didSave")) == 0l)) {
		#line 151
		return s463_Method_TextDocumentDidSave;
	}
	#line 152
	if ((((i64)strcmp(v1_s, "textDocument/didClose")) == 0l)) {
		#line 152
		return s463_Method_TextDocumentDidClose;
	}
	#line 154
	if ((((i64)strcmp(v1_s, "textDocument/documentSymbol")) == 0l)) {
		#line 154
		return s463_Method_TextDocumentDocumentSymbol;
	}
	#line 155
	if ((((i64)strcmp(v1_s, "textDocument/hover")) == 0l)) {
		#line 155
		return s463_Method_TextDocumentHover;
	}
	#line 157
	return s463_Method_None;
}


#line 160 "src/lsp/request.ib"
void s460_print(i64 * v1_stream, s461_Request * v2_request) {
	#line 161
	switch (((*v2_request).method)) {
	case s463_Method_None: {
	fprintf(((void *)v1_stream), "NONE");
	break; }
	case s463_Method_Initialize: {
	fprintf(((void *)v1_stream), "initialize");
	break; }
	case s463_Method_Initialized: {
	fprintf(((void *)v1_stream), "initialized");
	break; }
	case s463_Method_Shutdown: {
	fprintf(((void *)v1_stream), "shutdown");
	break; }
	case s463_Method_Exit: {
	fprintf(((void *)v1_stream), "exit");
	break; }
	case s463_Method_TextDocumentDidOpen: {
	fprintf(((void *)v1_stream), "textDocument/didOpen");
	break; }
	case s463_Method_TextDocumentDidChange: {
	fprintf(((void *)v1_stream), "textDocument/didChange");
	break; }
	case s463_Method_TextDocumentDidSave: {
	fprintf(((void *)v1_stream), "textDocument/didSave");
	break; }
	case s463_Method_TextDocumentDidClose: {
	fprintf(((void *)v1_stream), "textDocument/didClose");
	break; }
	case s463_Method_TextDocumentHover: {
	fprintf(((void *)v1_stream), "textDocument/hover");
	break; }
	case s463_Method_TextDocumentDocumentSymbol: {
	fprintf(((void *)v1_stream), "textDocument/documentSymbol");
	break; }
	default:
		abort();
}
}


#line 21 "src/lsp/context.ib"
s466_Context s464_new() {
	#line 22
	void * v1_log = fopen("./lsp.log", "w");
	#line 23
	s39_log_stream = v1_log;
	#line 24
	return ((s466_Context){
		.log = ((i64 *)v1_log),
		.parser = s452_new_parser(((i64 *)v1_log)),
		.response = s802_new(((i64 *)v1_log)),
		.files = s475_new_filemap(((i64 *)v1_log)),
		.parse_uri = ((char *)NULL),
		.parse_uri_len = 0l,
		.build_result = s87_new()
	});
}


#line 36 "src/lsp/context.ib"
void s465_free(s466_Context * v1_context) {
	#line 37
	fclose(((void *)((*v1_context).log)));
	#line 38
	s453_free_parser((&((*v1_context).parser)));
	#line 39
	s803_free((&((*v1_context).response)));
	#line 40
	s88_free((&((*v1_context).build_result)));
}


#line 17 "src/lsp/handler.ib"
s472_Status s467_handle(s466_Context * v1_context, s461_Request * v2_req) {
	#line 18
	fprintf(((void *)((*v1_context).log)), "[INFO] Handling method \"");
	#line 19
	s460_print(((*v1_context).log), v2_req);
	#line 20
	fprintf(((void *)((*v1_context).log)), "\"\n");
	#line 21
	fflush(((void *)((*v1_context).log)));
	#line 23
	s824_Builder * v3_res = (&((*v1_context).response));
	#line 25
	switch (((*v2_req).method)) {
	case s463_Method_Initialize: {
	return s468_on_initialize(v1_context, v2_req, v3_res);
	break; }
	case s463_Method_Exit: {
	return s472_Status_Exit;
	break; }
	case s463_Method_TextDocumentDidOpen: {
	return s469_on_document_open(v1_context, v2_req, v3_res);
	break; }
	case s463_Method_TextDocumentDidChange: {
	return s470_on_document_change(v1_context, v2_req, v3_res);
	break; }
	case s463_Method_TextDocumentHover: {
	return s471_on_document_hover(v1_context, v2_req, v3_res);
	break; }
	default:
 {
	return s472_Status_Unhandled;
	break; }
}
}


#line 39 "src/lsp/handler.ib"
s472_Status s468_on_initialize(s466_Context * v1__context, s461_Request * v2_req, s824_Builder * v3_res) {
	#line 40
	s812_begin(v3_res);
	#line 41
	s806_id(v3_res, ((*v2_req).id));
	#line 41
	s814_sep(v3_res);
	#line 42
	s807_begin_result(v3_res);
	#line 44
	s805_key(v3_res, "capabilities");
	#line 45
	s815_begin_object(v3_res);
	#line 46
	s805_key(v3_res, "textDocumentSync");
	#line 47
	s822_number(v3_res, 1l);
	#line 48
	s814_sep(v3_res);
	#line 50
	s805_key(v3_res, "hoverProvider");
	#line 51
	s820_boolean(v3_res, true);
	#line 61
	s816_end_object(v3_res);
	#line 62
	s814_sep(v3_res);
	#line 64
	s805_key(v3_res, "serverInfo");
	#line 65
	s815_begin_object(v3_res);
	#line 66
	s805_key(v3_res, "name");
	#line 67
	s821_string(v3_res, "ib-lsp");
	#line 68
	s814_sep(v3_res);
	#line 69
	s805_key(v3_res, "version");
	#line 70
	s821_string(v3_res, "0.1");
	#line 71
	s816_end_object(v3_res);
	#line 73
	s808_end_result(v3_res);
	#line 74
	s813_end(v3_res);
	#line 76
	s804_send(v3_res);
	#line 77
	return s472_Status_Ok;
}


#line 81 "src/lsp/handler.ib"
s472_Status s469_on_document_open(s466_Context * v1_context, s461_Request * v2_req, s824_Builder * v3__res) {
	#line 86
	fprintf(((void *)((*v1_context).log)), "[DEBUG] on_document_open\n");
	#line 88
	s440_Node * v4_doc = s410_lookup(((*v2_req).params), "textDocument");
	#line 89
	s440_Node * v5_uri = s410_lookup(v4_doc, "uri");
	#line 90
	i64 v6_uri_len = s414_length(v5_uri);
	#line 91
	char * v7_uri = s413_as_str(v5_uri);
	#line 93
	i64 v8_version = s412_as_number(s410_lookup(v4_doc, "version"));
	#line 95
	s440_Node * v9_content = s410_lookup(v4_doc, "text");
	#line 96
	i64 v10_content_len = s414_length(v9_content);
	#line 97
	char * v11_content = s413_as_str(v9_content);
	#line 99
	((*v1_context).parse_uri) = v7_uri;
	#line 100
	((*v1_context).parse_uri_len) = v6_uri_len;
	#line 101
	s481_File * v12_file = s479_find((&((*v1_context).files)), v7_uri, v6_uri_len);
	#line 103
	((*v12_file).version) = v8_version;
	#line 104
	s480_update_full(v12_file, v11_content, v10_content_len);
	#line 106
	fprintf(((void *)((*v1_context).log)), "[DEBUG] opened file: %s\n", ((*v12_file).uri));
	#line 108
	return s472_Status_Ok;
}


#line 112 "src/lsp/handler.ib"
s472_Status s470_on_document_change(s466_Context * v1_context, s461_Request * v2_req, s824_Builder * v3__res) {
	#line 117
	fprintf(((void *)((*v1_context).log)), "[DEBUG] on_document_change\n");
	#line 119
	s440_Node * v4_doc = s410_lookup(((*v2_req).params), "textDocument");
	#line 120
	s440_Node * v5_uri = s410_lookup(v4_doc, "uri");
	#line 121
	i64 v6_uri_len = s414_length(v5_uri);
	#line 122
	char * v7_uri = s413_as_str(v5_uri);
	#line 124
	i64 v8_version = s412_as_number(s410_lookup(v4_doc, "version"));
	#line 126
	((*v1_context).parse_uri) = v7_uri;
	#line 127
	((*v1_context).parse_uri_len) = v6_uri_len;
	#line 129
	s481_File * v9_file = s479_find((&((*v1_context).files)), v7_uri, v6_uri_len);
	#line 130
	if ((((*v9_file).version) >= v8_version)) {
		#line 131
		return s472_Status_Skipped;
	}
	#line 134
	s440_Node * v10_content_changes = s410_lookup(((*v2_req).params), "contentChanges");
	#line 135
	i64 v11_len = s414_length(v10_content_changes);
	#line 137
	for (i64 v12_i = 0l;(v12_i < v11_len);v12_i += 1l) {
		#line 138
		s440_Node * v13_change = s409_get(v10_content_changes, v12_i);
		#line 139
		s440_Node * v14_text = s410_lookup(v13_change, "text");
		#line 140
		i64 v15_text_len = s414_length(v14_text);
		#line 141
		char * v16_text = s413_as_str(v14_text);
		#line 142
		s480_update_full(v9_file, v16_text, v15_text_len);
	}
	loop_exit_1:
	#line 144
	((*v9_file).version) = v8_version;
	#line 146
	return s472_Status_Ok;
}


#line 157 "src/lsp/handler.ib"
s472_Status s471_on_document_hover(s466_Context * v1_context, s461_Request * v2_req, s824_Builder * v3_res) {
	#line 162
	fprintf(((void *)((*v1_context).log)), "[DEBUG] on_document_hover\n");
	#line 164
	s440_Node * v4_doc = s410_lookup(((*v2_req).params), "textDocument");
	#line 165
	s440_Node * v5_uri = s410_lookup(v4_doc, "uri");
	#line 166
	i64 v6_uri_len = s414_length(v5_uri);
	#line 167
	char * v7_uri = s413_as_str(v5_uri);
	#line 169
	s440_Node * v8_position = s410_lookup(((*v2_req).params), "position");
	#line 170
	i64 v9_line = s412_as_number(s410_lookup(v8_position, "line"));
	#line 171
	i64 v10_col = s412_as_number(s410_lookup(v8_position, "character"));
	#line 173
	s481_File * v11__file = s479_find((&((*v1_context).files)), v7_uri, v6_uri_len);
	#line 175
	char * v12_position = "                                             ";
	#line 176
	sprintf(v12_position, "  Position: %d:%d", v9_line, v10_col);
	#line 178
	s812_begin(v3_res);
	#line 179
	s806_id(v3_res, ((*v2_req).id));
	#line 180
	s814_sep(v3_res);
	#line 182
	s807_begin_result(v3_res);
	#line 183
	s805_key(v3_res, "contents");
	#line 184
	s817_begin_array(v3_res);
	#line 185
	s821_string(v3_res, " Hello from ib! :)  ");
	#line 186
	s814_sep(v3_res);
	#line 187
	s821_string(v3_res, v12_position);
	#line 188
	s818_end_array(v3_res);
	#line 189
	s808_end_result(v3_res);
	#line 190
	s813_end(v3_res);
	#line 192
	s804_send(v3_res);
	#line 193
	return s472_Status_Ok;
}


#line 18 "src/lsp/file.ib"
i64 s473_hash(s481_File * v1_file) {
	#line 19
	i64 v2_hash = 0l;
	#line 20
	for (i64 v3_i = 0l;(v3_i < ((*v1_file).uri_len));v3_i += 1l) {
		#line 21
		v2_hash = ((v2_hash * 31l) + ((i64)(((*v1_file).uri)[v3_i])));
	}
	loop_exit_1:
	#line 23
	return v2_hash;
}


#line 26 "src/lsp/file.ib"
bool s474_eq(s481_File * v1_left, s481_File * v2_right) {
	#line 27
	if ((((*v1_left).uri_len) != ((*v2_right).uri_len))) {
		#line 27
		return false;
	}
	#line 28
	return (((i64)strcmp(((*v1_left).uri), ((*v2_right).uri))) == 0l);
}


#line 31 "src/lsp/file.ib"
s482_FileMap s475_new_filemap(i64 * v1_log) {
	#line 32
	s576_HashSet v2_files = s568_new(((i64)48ul), ((i64 (*)(void *))s473_hash), ((bool (*)(void *, void *))s474_eq));
	#line 33
	(v2_files.free_fn) = ((void (*)(void *))s476_free_file);
	#line 34
	return ((s482_FileMap){
		.log = v1_log,
		.files = v2_files
	});
}


#line 37 "src/lsp/file.ib"
void s476_free_file(s481_File * v1_file) {
	#line 38
	free(((void *)((*v1_file).uri)));
	#line 39
	free(((void *)((*v1_file).content)));
	#line 40
	((*v1_file).uri_len) = 0l;
	#line 41
	((*v1_file).capacity) = 0l;
	#line 42
	((*v1_file).length) = 0l;
}


#line 45 "src/lsp/file.ib"
void s477_free_filemap(s482_FileMap * v1_files) {
	#line 46
	s571_free((&((*v1_files).files)));
}


#line 50 "src/lsp/file.ib"
s481_File s478_temp_file(char * v1_uri, i64 v2_uri_len) {
	#line 51
	return ((s481_File){
		.uri = v1_uri,
		.uri_len = v2_uri_len,
		.content = ((char *)NULL),
		.length = 0l,
		.capacity = 0l,
		.version = 0l
	});
}


#line 54 "src/lsp/file.ib"
s481_File * s479_find(s482_FileMap * v1_files, char * v2_uri, i64 v3_uri_len) {
	#line 55
	s481_File v4_file = s478_temp_file(v2_uri, v3_uri_len);
	#line 56
	void * v5_set_file = s569_find((&((*v1_files).files)), ((void *)(&v4_file)));
	#line 57
	if ((v5_set_file == NULL)) {
		#line 58
		(v4_file.uri) = ((char *)malloc((1ul * ((u64)(v3_uri_len + 1l)))));
		#line 59
		memcpy(((void *)(v4_file.uri)), ((void *)v2_uri), (1ul * ((u64)v3_uri_len)));
		#line 60
		((v4_file.uri)[v3_uri_len]) = 0u;
		#line 61
		return ((s481_File *)s570_find_or_insert((&((*v1_files).files)), ((void *)(&v4_file))));
	} else {
#line 63
		return ((s481_File *)v5_set_file);
	}
}


#line 67 "src/lsp/file.ib"
void s480_update_full(s481_File * v1_file, char * v2_content, i64 v3_length) {
	#line 68
	v3_length += 1l;
	#line 69
	if ((((*v1_file).capacity) < v3_length)) {
		#line 70
		i64 v4_new_capacity = (((*v1_file).capacity) * 2l);
		#line 71
		if ((v4_new_capacity < v3_length)) {
			#line 71
			v4_new_capacity = (v3_length * 2l);
		}
		#line 72
		((*v1_file).content) = ((char *)realloc(((void *)((*v1_file).content)), ((u64)v4_new_capacity)));
	}
	#line 74
	memcpy(((void *)((*v1_file).content)), ((void *)v2_content), (1ul * ((u64)(v3_length - 1l))));
	#line 75
	(((*v1_file).content)[(v3_length - 1l)]) = 0u;
	#line 76
	((*v1_file).length) = v3_length;
}


#line 11 "src/lsp/diagnostics.ib"
void s483_publish(s466_Context * v1_context, s100_BuildResult * v2_result, s824_Builder * v3_res) {
	#line 13
	fprintf(((void *)((*v1_context).log)), "[DEBUG] publish_diagnostics\n");
	#line 14
	s812_begin(v3_res);
	#line 15
	s809_method(v3_res, "textDocument/publishDiagnostics");
	#line 16
	s814_sep(v3_res);
	#line 18
	s810_begin_params(v3_res);
	#line 19
	s805_key(v3_res, "uri");
	#line 20
	s821_string(v3_res, ((*v1_context).parse_uri));
	#line 21
	s814_sep(v3_res);
	#line 22
	s805_key(v3_res, "diagnostics");
	#line 23
	s817_begin_array(v3_res);
	#line 25
	s257_Vec * v4_err_vec = (&(((*v2_result).errors).errors));
	#line 26
	for (i64 v5_i = 0l;(v5_i < ((*v4_err_vec).count));v5_i += 1l) {
		#line 27
		if ((v5_i > 0l)) {
			#line 27
			s814_sep(v3_res);
		}
		#line 28
		void * v6_err = s251_get(v4_err_vec, v5_i);
		#line 29
		s484_send_error(v1_context, ((s402_Error *)v6_err), v3_res);
	}
	loop_exit_1:
	#line 32
	s818_end_array(v3_res);
	#line 33
	s811_end_params(v3_res);
	#line 34
	s813_end(v3_res);
	#line 36
	s804_send(v3_res);
}


#line 39 "src/lsp/diagnostics.ib"
void s484_send_error(s466_Context * v1_context, s402_Error * v2_error, s824_Builder * v3_res) {
	#line 40
	s815_begin_object(v3_res);
	#line 42
	s153_Span * v4_s = s146_get(((*v2_error).span));
	#line 43
	fprintf(((void *)((*v1_context).log)), "[DEBUG] send_error \"%s\" %d->%d\n", ((*v4_s).file), ((*v4_s).start), ((*v4_s).end));
	#line 44
	if ((((*v4_s).file) == ((char *)NULL))) {
		#line 45
		fprintf(((void *)((*v1_context).log)), "[ERROR] Span filename was null when sending error message:\n\t%s\n", ((*v2_error).message));
	}
	#line 48
	s165_Position v5_start = s160_find_position(((*v4_s).file), ((*v4_s).start));
	#line 49
	s165_Position v6_end = s160_find_position(((*v4_s).file), ((*v4_s).end));
	#line 51
	fprintf(((void *)((*v1_context).log)), "[DEBUG]     %d:%d -> %d:%d\n", (v5_start.line), (v5_start.column), (v6_end.line), (v6_end.column));
	#line 53
	s805_key(v3_res, "range");
	#line 54
	s485_range(v3_res, (v5_start.line), (v5_start.column), (v6_end.line), (v6_end.column));
	#line 55
	s814_sep(v3_res);
	#line 57
	s805_key(v3_res, "severity");
	#line 58
	s822_number(v3_res, 1l);
	#line 59
	s814_sep(v3_res);
	#line 61
	s805_key(v3_res, "message");
	#line 62
	s823_raw(v3_res, "\"");
	#line 63
	s823_raw(v3_res, ((*v2_error).header));
	#line 64
	s823_raw(v3_res, ": ");
	#line 65
	s823_raw(v3_res, ((*v2_error).message));
	#line 66
	s823_raw(v3_res, "\"");
	#line 68
	s816_end_object(v3_res);
}


#line 72 "src/lsp/diagnostics.ib"
void s485_range(s824_Builder * v1_res, i64 v2_start_line, i64 v3_start_char, i64 v4_end_line, i64 v5_end_char) {
	#line 73
	s815_begin_object(v1_res);
	#line 75
	s805_key(v1_res, "start");
	#line 76
	s815_begin_object(v1_res);
	#line 77
	s805_key(v1_res, "line");
	#line 78
	s822_number(v1_res, v2_start_line);
	#line 79
	s814_sep(v1_res);
	#line 80
	s805_key(v1_res, "character");
	#line 81
	s822_number(v1_res, v3_start_char);
	#line 82
	s816_end_object(v1_res);
	#line 83
	s814_sep(v1_res);
	#line 85
	s805_key(v1_res, "end");
	#line 86
	s815_begin_object(v1_res);
	#line 87
	s805_key(v1_res, "line");
	#line 88
	s822_number(v1_res, v4_end_line);
	#line 89
	s814_sep(v1_res);
	#line 90
	s805_key(v1_res, "character");
	#line 91
	s822_number(v1_res, v5_end_char);
	#line 92
	s816_end_object(v1_res);
	#line 94
	s816_end_object(v1_res);
}


#line 26 "src/utils/hashmap.ib"
s500_HashMap s487_new(i64 v1_key_size, i64 v2_value_size, i64 (* v3_hash_fn)(void *), bool (* v4_eq_fn)(void *, void *)) {
	#line 27
	v1_key_size = s498_with_alignment(v1_key_size);
	#line 28
	v2_value_size = s498_with_alignment(v2_value_size);
	#line 29
	return ((s500_HashMap){
		.count = 0l,
		.capacity = 0l,
		.entries = ((s499_EntryMeta *)NULL),
		.keys = ((char *)NULL),
		.values = ((char *)NULL),
		.key_size = v1_key_size,
		.value_size = v2_value_size,
		.hash_fn = v3_hash_fn,
		.eq_fn = v4_eq_fn,
		.debug = false
	});
}


#line 39 "src/utils/hashmap.ib"
void * s488_find(s500_HashMap * v1_map, void * v2_key) {
	#line 40
	s40_assert((((*v1_map).hash_fn) != ((i64 (*)(void *))NULL)), "Hashmap::hash_fn uninitialized");
	#line 42
	if ((((*v1_map).count) == 0l)) {
		#line 42
		return NULL;
	}
	#line 43
	i64 (* v3_hash_fn)(void *) = ((*v1_map).hash_fn);
	#line 44
	i64 v4_hash = v3_hash_fn(v2_key);
	#line 45
	i64 v5_index = s492_find_entry_index(v1_map, v2_key, v4_hash);
	#line 46
	if (((*v1_map).debug)) {
		#line 46
		printf("hashmap::hash = %x; index = %d\n", v4_hash, v5_index);
	}
	#line 47
	if (((((*v1_map).entries)[v5_index]).exists)) {
		#line 48
		return ((void *)(&(((*v1_map).values)[(((*v1_map).value_size) * v5_index)])));
	}
	#line 50
	return NULL;
}


#line 54 "src/utils/hashmap.ib"
void * s489_insert(s500_HashMap * v1_map, void * v2_key, void * v3_value) {
	#line 55
	s40_assert((((*v1_map).hash_fn) != ((i64 (*)(void *))NULL)), "Hashmap::hash_fn uninitialized");
	#line 57
	if ((((f64)(((*v1_map).count) + 1l)) > (((f64)((*v1_map).capacity)) * 0.750000000000))) {
		#line 57
		s493_expand(v1_map);
	}
	#line 59
	i64 (* v4_hash_fn)(void *) = ((*v1_map).hash_fn);
	#line 60
	i64 v5_hash = v4_hash_fn(v2_key);
	#line 61
	i64 v6_index = s492_find_entry_index(v1_map, v2_key, v5_hash);
	#line 63
	if (((*v1_map).debug)) {
		#line 63
		printf("hashmap::hash = %x; index = %d\n", v5_hash, v6_index);
	}
	#line 65
	char * v7_map_value = (&(((*v1_map).values)[(((*v1_map).value_size) * v6_index)]));
	#line 66
	char * v8_map_key = (&(((*v1_map).keys)[(((*v1_map).key_size) * v6_index)]));
	#line 68
	if ((!((((*v1_map).entries)[v6_index]).exists))) {
		#line 69
		((*v1_map).count) += 1l;
		#line 70
		((((*v1_map).entries)[v6_index]).exists) = true;
		#line 71
		((((*v1_map).entries)[v6_index]).hash) = v5_hash;
		#line 72
		memcpy(((void *)v8_map_key), v2_key, ((u64)((*v1_map).key_size)));
	}
	#line 79
	memcpy(((void *)v7_map_value), v3_value, ((u64)((*v1_map).value_size)));
	#line 84
	return ((void *)v7_map_value);
}


#line 88 "src/utils/hashmap.ib"
void * s490_find_or_insert(s500_HashMap * v1_map, void * v2_key) {
	#line 89
	s40_assert((((*v1_map).hash_fn) != ((i64 (*)(void *))NULL)), "Hashmap::hash_fn uninitialized");
	#line 91
	if ((((f64)(((*v1_map).count) + 1l)) > (((f64)((*v1_map).capacity)) * 0.750000000000))) {
		#line 91
		s493_expand(v1_map);
	}
	#line 93
	i64 (* v3_hash_fn)(void *) = ((*v1_map).hash_fn);
	#line 94
	i64 v4_hash = v3_hash_fn(v2_key);
	#line 95
	i64 v5_index = s492_find_entry_index(v1_map, v2_key, v4_hash);
	#line 97
	if (((*v1_map).debug)) {
		#line 97
		printf("hashmap::hash = %x; index = %d\n", v4_hash, v5_index);
	}
	#line 98
	if (((((*v1_map).entries)[v5_index]).exists)) {
		#line 99
		return ((void *)(&(((*v1_map).values)[(((*v1_map).value_size) * v5_index)])));
	}
	#line 101
	((*v1_map).count) += 1l;
	#line 103
	char * v6_map_value = (&(((*v1_map).values)[(((*v1_map).value_size) * v5_index)]));
	#line 104
	char * v7_map_key = (&(((*v1_map).keys)[(((*v1_map).key_size) * v5_index)]));
	#line 105
	((((*v1_map).entries)[v5_index]).exists) = true;
	#line 106
	((((*v1_map).entries)[v5_index]).hash) = v4_hash;
	#line 107
	memset(((void *)v6_map_value), ((int)0l), ((u64)((*v1_map).value_size)));
	#line 112
	memcpy(((void *)v7_map_key), v2_key, ((u64)((*v1_map).key_size)));
	#line 117
	return ((void *)v6_map_value);
}


#line 121 "src/utils/hashmap.ib"
void s491_free(s500_HashMap * v1_map) {
	#line 122
	((*v1_map).count) = 0l;
	#line 123
	((*v1_map).capacity) = 0l;
	#line 125
	free(((void *)((*v1_map).keys)));
	#line 126
	free(((void *)((*v1_map).values)));
	#line 127
	free(((void *)((*v1_map).entries)));
	#line 129
	((*v1_map).keys) = ((char *)NULL);
	#line 130
	((*v1_map).values) = ((char *)NULL);
	#line 131
	((*v1_map).entries) = ((s499_EntryMeta *)NULL);
}


#line 135 "src/utils/hashmap.ib"
i64 s492_find_entry_index(s500_HashMap * v1_map, void * v2_key, i64 v3_hash) {
	#line 136
	s40_assert((((*v1_map).capacity) > 0l), "Hashmap::capacity was empty in find_entry_index!");
	#line 137
	i64 v4_index = (((v3_hash % ((*v1_map).capacity)) + ((*v1_map).capacity)) % ((*v1_map).capacity));
	#line 138
	bool (* v5_eq_fn)(void *, void *) = ((*v1_map).eq_fn);
	#line 139
	while (1) {
		#line 140
		if (((*v1_map).debug)) {
			#line 140
			printf("hashmap::find_entry %d\n", v4_index);
		}
		#line 141
		s499_EntryMeta * v6_entry = (&(((*v1_map).entries)[v4_index]));
		#line 142
		if ((!((*v6_entry).exists))) {
			#line 142
			return v4_index;
		}
		#line 143
		if ((((*v6_entry).hash) == v3_hash)) {
			#line 144
			if (v5_eq_fn(v2_key, ((void *)(&(((*v1_map).keys)[(((*v1_map).key_size) * v4_index)]))))) {
				#line 145
				return v4_index;
			}
		}
		#line 148
		v4_index = ((v4_index + 1l) % ((*v1_map).capacity));
}
	loop_exit_1:
	#line 152
	return 0l;
}


#line 156 "src/utils/hashmap.ib"
void s493_expand(s500_HashMap * v1_map) {
	#line 157
	i64 v2_new_capacity = (((*v1_map).capacity) * 2l);
	#line 158
	if ((v2_new_capacity < s486_MINIMUM_CAPACITY)) {
		#line 158
		v2_new_capacity = s486_MINIMUM_CAPACITY;
	}
	#line 159
	if (((*v1_map).debug)) {
		#line 159
		printf("hashmap::expand new capacity: %d\n", v2_new_capacity);
	}
	#line 161
	s499_EntryMeta * v3_entries = ((s499_EntryMeta *)malloc((16ul * ((u64)v2_new_capacity))));
	#line 162
	char * v4_keys = ((char *)malloc(((u64)(((*v1_map).key_size) * v2_new_capacity))));
	#line 163
	char * v5_values = ((char *)malloc(((u64)(((*v1_map).value_size) * v2_new_capacity))));
	#line 164
	memset(((void *)v3_entries), ((int)0l), (16ul * ((u64)v2_new_capacity)));
	#line 165
	memset(((void *)v4_keys), ((int)0l), ((u64)(((*v1_map).key_size) * v2_new_capacity)));
	#line 166
	memset(((void *)v5_values), ((int)0l), ((u64)(((*v1_map).value_size) * v2_new_capacity)));
	#line 168
	s499_EntryMeta * v6_old_entries = ((*v1_map).entries);
	#line 169
	char * v7_old_keys = ((*v1_map).keys);
	#line 170
	char * v8_old_values = ((*v1_map).values);
	#line 171
	i64 v9_old_capacity = ((*v1_map).capacity);
	#line 173
	((*v1_map).capacity) = v2_new_capacity;
	#line 174
	((*v1_map).entries) = v3_entries;
	#line 175
	((*v1_map).keys) = v4_keys;
	#line 176
	((*v1_map).values) = v5_values;
	#line 177
	((*v1_map).count) = 0l;
	#line 179
	for (i64 v10_i = 0l;(v10_i < v9_old_capacity);v10_i += 1l) {
		#line 180
		if ((!((v6_old_entries[v10_i]).exists))) {
			#line 180
			continue;
		}
		#line 182
		char * v11_old_key = (&(v7_old_keys[(((*v1_map).key_size) * v10_i)]));
		#line 183
		char * v12_old_val = (&(v8_old_values[(((*v1_map).value_size) * v10_i)]));
		#line 185
		i64 v13_hash = ((v6_old_entries[v10_i]).hash);
		#line 186
		i64 v14_index = s494_find_next_empty_slot_index(v3_entries, v2_new_capacity, v13_hash);
		#line 188
		((v3_entries[v14_index]).exists) = true;
		#line 189
		((v3_entries[v14_index]).hash) = v13_hash;
		#line 190
		memcpy(((void *)(&(((*v1_map).keys)[(((*v1_map).key_size) * v14_index)]))), ((void *)v11_old_key), ((u64)((*v1_map).key_size)));
		#line 195
		memcpy(((void *)(&(((*v1_map).values)[(((*v1_map).value_size) * v14_index)]))), ((void *)v12_old_val), ((u64)((*v1_map).value_size)));
		#line 200
		((*v1_map).count) += 1l;
	}
	loop_exit_1:
	#line 202
	if ((v6_old_entries != ((s499_EntryMeta *)NULL))) {
		#line 202
		free(((void *)v6_old_entries));
	}
	#line 203
	if ((v7_old_keys != ((char *)NULL))) {
		#line 203
		free(((void *)v7_old_keys));
	}
	#line 204
	if ((v8_old_values != ((char *)NULL))) {
		#line 204
		free(((void *)v8_old_values));
	}
}


#line 212 "src/utils/hashmap.ib"
i64 s494_find_next_empty_slot_index(s499_EntryMeta * v1_entries, i64 v2_capacity, i64 v3_hash) {
	#line 213
	i64 v4_index = (((v3_hash % v2_capacity) + v2_capacity) % v2_capacity);
	#line 214
	while (((v1_entries[v4_index]).exists)) {
		#line 215
		v4_index = ((v4_index + 1l) % v2_capacity);
}
	loop_exit_1:
	#line 217
	return v4_index;
}


#line 229 "src/utils/hashmap.ib"
s501_HashMapIter s495_iter(s500_HashMap * v1_map) {
	#line 230
	s501_HashMapIter v2_iter = ((s501_HashMapIter){
		.map = v1_map,
		.index = (-1l),
		.key = NULL,
		.value = NULL
	});
	#line 234
	s497_next((&v2_iter));
	#line 235
	return v2_iter;
}


#line 239 "src/utils/hashmap.ib"
bool s496_has_next(s501_HashMapIter * v1_iter) {
	#line 240
	return (((*v1_iter).index) < ((*((*v1_iter).map)).capacity));
}


#line 244 "src/utils/hashmap.ib"
void s497_next(s501_HashMapIter * v1_iter) {
	#line 245
	while (1) {
		#line 246
		((*v1_iter).index) += 1l;
		#line 247
		if ((!s496_has_next(v1_iter))) {
			#line 248
			return;
		}
		#line 250
		if (((((*((*v1_iter).map)).entries)[((*v1_iter).index)]).exists)) {
			#line 251
			((*v1_iter).value) = ((void *)(&(((*((*v1_iter).map)).values)[(((*((*v1_iter).map)).value_size) * ((*v1_iter).index))])));
			#line 252
			((*v1_iter).key) = ((void *)(&(((*((*v1_iter).map)).keys)[(((*((*v1_iter).map)).key_size) * ((*v1_iter).index))])));
			#line 253
			return;
		}
}
	loop_exit_1:
}


#line 259 "src/utils/hashmap.ib"
i64 s498_with_alignment(i64 v1_size) {
	#line 260
	i64 v2_rem = (v1_size % 8l);
	#line 261
	if ((v2_rem == 0l)) {
		#line 261
		return v1_size;
	}
	#line 262
	return (v1_size + (8l - v2_rem));
}


#line 90 "src/typecheck/typeident.ib"
s531_TypeIdents s502_new() {
	#line 91
	s576_HashSet v1_types_set = s568_new(((i64)8ul), ((i64 (*)(void *))s519_typeident_hash), ((bool (*)(void *, void *))s520_typeident_eq));
	#line 92
	s566_Arena v2_types_arena = s560_new(64l);
	#line 93
	s531_TypeIdents v3_typeidents = ((s531_TypeIdents){
		.types_arena = v2_types_arena,
		.types_set = v1_types_set,
		.boolean = ((s528_TypeIdent *)NULL)
	});
	#line 97
	(v3_typeidents.boolean) = s504_atomic((&v3_typeidents), s535_AtomicType_Bool);
	#line 98
	return v3_typeidents;
}


#line 102 "src/typecheck/typeident.ib"
void s503_free(s531_TypeIdents * v1_type_idents) {
	#line 103
	s571_free((&((*v1_type_idents).types_set)));
	#line 104
	i64 v2_total_freed = s562_free((&((*v1_type_idents).types_arena)));
	#line 105
	if (s52_usage_stats) {
		#line 106
		printf("typecheck::TypeIdentArena freed %d\n", v2_total_freed);
	}
}


#line 111 "src/typecheck/typeident.ib"
s528_TypeIdent * s504_atomic(s531_TypeIdents * v1_type_idents, s535_AtomicType v2_atomic_ty) {
	#line 112
	s528_TypeIdent v3_ty = ((s528_TypeIdent){

	});
	#line 113
	(v3_ty.kind) = s534_TypeKind_Atomic;
	#line 114
	((v3_ty.data).atomic) = v2_atomic_ty;
	#line 115
	return s513_find_or_insert(v1_type_idents, (&v3_ty));
}


#line 119 "src/typecheck/typeident.ib"
s528_TypeIdent * s505_pointer(s531_TypeIdents * v1_type_idents, s528_TypeIdent * v2_inner) {
	#line 120
	s528_TypeIdent v3_ty = ((s528_TypeIdent){

	});
	#line 121
	(v3_ty.kind) = s534_TypeKind_Pointer;
	#line 122
	((v3_ty.data).pointer) = v2_inner;
	#line 123
	return s513_find_or_insert(v1_type_idents, (&v3_ty));
}


#line 127 "src/typecheck/typeident.ib"
s528_TypeIdent * s506_compound(s531_TypeIdents * v1_type_idents, s201_UID v2_symbol) {
	#line 128
	s528_TypeIdent v3_ty = ((s528_TypeIdent){

	});
	#line 129
	(v3_ty.kind) = s534_TypeKind_Compound;
	#line 130
	((v3_ty.data).compound) = v2_symbol;
	#line 131
	return s513_find_or_insert(v1_type_idents, (&v3_ty));
}


#line 135 "src/typecheck/typeident.ib"
s528_TypeIdent * s507_into_array(s531_TypeIdents * v1_type_idents, s528_TypeIdent * v2_parent, i64 * v3_dimensions, i64 v4_dimension_length) {
	#line 136
	s528_TypeIdent v5_ty = ((s528_TypeIdent){

	});
	#line 137
	(v5_ty.kind) = s534_TypeKind_Array;
	#line 138
	((v5_ty.data).array) = ((s529_ArrayType){
		.parent = v2_parent,
		.dimensions = v3_dimensions,
		.dimension_length = v4_dimension_length
	});
	#line 143
	return s513_find_or_insert(v1_type_idents, (&v5_ty));
}


#line 147 "src/typecheck/typeident.ib"
s527_FlowType s508_typecheck_flowtype(s351_TypecheckContext * v1_context, i64 v2_module, s213_FlowType v3_flow, i64 v4_span) {
	#line 148
	switch ((v3_flow.kind)) {
	case s220_FlowTypeKind_Void: {
		#line 150
		return ((s527_FlowType){
			.kind = s533_FlowTypeKind_Void,
			.type = ((s528_TypeIdent *)NULL)
		});
	break; }
	case s220_FlowTypeKind_Never: {
		#line 153
		return ((s527_FlowType){
			.kind = s533_FlowTypeKind_Never,
			.type = ((s528_TypeIdent *)NULL)
		});
	break; }
	case s220_FlowTypeKind_Some: {
		#line 156
		s528_TypeIdent * v5_type = s509_typecheck(v1_context, v2_module, (v3_flow.type), v4_span);
		#line 157
		return ((s527_FlowType){
			.kind = s533_FlowTypeKind_Some,
			.type = v5_type
		});
	break; }
	default:
		abort();
}
}


#line 163 "src/typecheck/typeident.ib"
s528_TypeIdent * s509_typecheck(s351_TypecheckContext * v1_context, i64 v2_module, s214_TypeIdent * v3_type, i64 v4_span) {
	#line 164
	s40_assert((v3_type != ((s214_TypeIdent *)NULL)), "typeident::typecheck got null");
	#line 165
	switch (((*v3_type).kind)) {
	case s221_TypeKind_Atomic: {
	return s504_atomic((&((*v1_context).typeidents)), s521_ast_atomicty_into_ty((((*v3_type).data).atomic)));
	break; }
	case s221_TypeKind_Pointer: {
		#line 169
		if (((((*v3_type).data).pointer) == ((s214_TypeIdent *)NULL))) {
			#line 169
			return s505_pointer((&((*v1_context).typeidents)), ((s528_TypeIdent *)NULL));
		}
		#line 170
		s528_TypeIdent * v5_ptr = s509_typecheck(v1_context, v2_module, (((*v3_type).data).pointer), v4_span);
		#line 171
		return s505_pointer((&((*v1_context).typeidents)), v5_ptr);
	break; }
	case s221_TypeKind_Compound: {
		#line 174
		return s512_typecheck_compound(v1_context, v2_module, v3_type, v4_span);
	break; }
	case s221_TypeKind_Array: {
		#line 177
		return s510_typecheck_array(v1_context, v2_module, v3_type, v4_span);
	break; }
	case s221_TypeKind_Function: {
		#line 180
		return s511_typecheck_function(v1_context, v2_module, v3_type, v4_span);
	break; }
	default:
		abort();
}
}


#line 185 "src/typecheck/typeident.ib"
s528_TypeIdent * s510_typecheck_array(s351_TypecheckContext * v1_context, i64 v2_module, s214_TypeIdent * v3_type, i64 v4_span) {
	#line 186
	s216_ArrayType * v5_a = (&(((*v3_type).data).array));
	#line 187
	s528_TypeIdent * v6_parent = s509_typecheck(v1_context, v2_module, ((*v5_a).parent), v4_span);
	#line 188
	i64 v7_dimension_length = ((*v5_a).dimension_length);
	#line 190
	s743_FunctionContext v8_fn_context = s730_create_fn_context(v1_context, v2_module);
	#line 191
	for (i64 v9_i = 0l;(v9_i < v7_dimension_length);v9_i += 1l) {
		#line 192
		s845_NodeResult v10_node_res = s827_typecheck((&v8_fn_context), (((*v5_a).dimensions)[v9_i]));
		#line 193
		i64 v11_node = (v10_node_res.node);
		#line 195
		s40_assert((v11_node != s826_ERROR), "Node was error!");
		#line 196
		s864_ConstEvalResult v12_result = s860_eval((&v8_fn_context), v11_node);
		#line 197
		s40_assert((v12_result.success), "ConstEval was not successfull!");
		#line 199
		bool v13_is_ok = true;
		#line 200
		i64 v14_literal_val = s854_into_int(((v12_result.expr).literal), (&v13_is_ok));
		#line 201
		s40_assert(v13_is_ok, "literal::into_int failed");
		#line 202
		i64 * v15_dimension = ((i64 *)s707_push((&((*v1_context).workstack)), ((i64)8ul)));
		#line 203
		(*v15_dimension) = v14_literal_val;
	}
	loop_exit_1:
	#line 205
	s731_free_fn_context((&v8_fn_context));
	#line 206
	i64 * v16_dimensions = ((i64 *)s709_pop_n((&((*v1_context).workstack)), ((i64)8ul), v7_dimension_length));
	#line 207
	s528_TypeIdent v17_ty = ((s528_TypeIdent){

	});
	#line 208
	(v17_ty.kind) = s534_TypeKind_Array;
	#line 209
	((v17_ty.data).array) = ((s529_ArrayType){
		.parent = v6_parent,
		.dimension_length = v7_dimension_length,
		.dimensions = v16_dimensions
	});
	#line 213
	s528_TypeIdent * v18_res = s513_find_or_insert((&((*v1_context).typeidents)), (&v17_ty));
	#line 214
	return v18_res;
}


#line 218 "src/typecheck/typeident.ib"
s528_TypeIdent * s511_typecheck_function(s351_TypecheckContext * v1_context, i64 v2_module, s214_TypeIdent * v3_type, i64 v4_span) {
	#line 219
	s217_FunctionType * v5_f = (&(((*v3_type).data).function));
	#line 220
	s527_FlowType v6_return_ty = s508_typecheck_flowtype(v1_context, v2_module, ((*v5_f).return_ty), v4_span);
	#line 221
	bool v7_has_varargs = ((*v5_f).has_varargs);
	#line 222
	i64 v8_args_length = ((*v5_f).args_length);
	#line 223
	for (i64 v9_i = 0l;(v9_i < v8_args_length);v9_i += 1l) {
		#line 227
		s528_TypeIdent * * v10_arg = ((s528_TypeIdent * *)s707_push((&((*v1_context).workstack)), ((i64)8ul)));
		#line 228
		(*v10_arg) = s509_typecheck(v1_context, v2_module, (((*v5_f).args)[v9_i]), v4_span);
	}
	loop_exit_1:
	#line 230
	s528_TypeIdent v11_ty = ((s528_TypeIdent){

	});
	#line 231
	(v11_ty.kind) = s534_TypeKind_Function;
	#line 232
	s528_TypeIdent * * v12_args = ((s528_TypeIdent * *)s709_pop_n((&((*v1_context).workstack)), ((i64)8ul), v8_args_length));
	#line 233
	((v11_ty.data).function) = ((s530_FunctionType){
		.return_ty = v6_return_ty,
		.args_length = v8_args_length,
		.args = v12_args,
		.has_varargs = v7_has_varargs
	});
	#line 239
	s528_TypeIdent * v13_res = s513_find_or_insert((&((*v1_context).typeidents)), (&v11_ty));
	#line 240
	return v13_res;
}


#line 245 "src/typecheck/typeident.ib"
s528_TypeIdent * s512_typecheck_compound(s351_TypecheckContext * v1_context, i64 v2_module, s214_TypeIdent * v3_type, i64 v4_span) {
	#line 246
	s215_CompoundType * v5_c = (&(((*v3_type).data).compound));
	#line 247
	if ((((*v5_c).path_length) == 1l)) {
		#line 248
		s556_IdentResult v6_res = s550_identifier(v2_module, (((*v5_c).path)[0l]));
		#line 249
		switch ((v6_res.kind)) {
		case s558_IdentResultKind_Found: {
		return s506_compound((&((*v1_context).typeidents)), (v6_res.symbol));
		break; }
		case s558_IdentResultKind_ErrFoundMultiple: {
			#line 253
			s774_error(v1_context, s781_ErrorKind_IdentFoundMultiple, v4_span);
		break; }
		case s558_IdentResultKind_ErrSymbolNotFound: {
			#line 255
			s774_error(v1_context, s781_ErrorKind_IdentSymbolNotFound, v4_span);
		break; }
		case s558_IdentResultKind_ErrSymbolWasPrivate: {
			#line 257
			s774_error(v1_context, s781_ErrorKind_IdentSymbolWasPrivate, v4_span);
		break; }
		case s558_IdentResultKind_ErrFoundMultiplePrivate: {
			#line 259
			s774_error(v1_context, s781_ErrorKind_IdentFoundMultiplePrivate, v4_span);
		break; }
		default:
			abort();
}
		#line 261
		return ((s528_TypeIdent *)NULL);
	}
	#line 263
	s554_PathResult v7_result = s545_path(v2_module, ((*v5_c).path), ((*v5_c).path_length));
	#line 264
	s201_UID v8_symbol = (v7_result.symbol);
	#line 265
	switch ((v7_result.kind)) {
	case s557_PathResultKind_Found: {
		#line 267
		return s506_compound((&((*v1_context).typeidents)), v8_symbol);
	break; }
	case s557_PathResultKind_SkippedName: {
		#line 270
		s774_error(v1_context, s781_ErrorKind_TypeIdentSkippedName, v4_span);
	break; }
	case s557_PathResultKind_ErrSymbolNotFound: {
		#line 273
		s774_error(v1_context, s781_ErrorKind_TypeIdentSymbolNotFound, v4_span);
	break; }
	case s557_PathResultKind_ErrSymbolWasPrivate: {
		#line 276
		s774_error(v1_context, s781_ErrorKind_TypeIdentSymbolWasPrivate, v4_span);
	break; }
	case s557_PathResultKind_ErrModuleNotFound: {
		#line 279
		s774_error(v1_context, s781_ErrorKind_TypeIdentModuleNotFound, v4_span);
	break; }
	case s557_PathResultKind_ErrModuleWasPrivate: {
		#line 282
		s774_error(v1_context, s781_ErrorKind_TypeIdentModuleWasPrivate, v4_span);
	break; }
	default:
		abort();
}
	#line 285
	return ((s528_TypeIdent *)NULL);
}


#line 289 "src/typecheck/typeident.ib"
s528_TypeIdent * s513_find_or_insert(s531_TypeIdents * v1_type_idents, s528_TypeIdent * v2_type) {
	#line 290
	s528_TypeIdent * * v3_existing = ((s528_TypeIdent * *)s569_find((&((*v1_type_idents).types_set)), ((void *)(&v2_type))));
	#line 291
	if ((v3_existing != ((s528_TypeIdent * *)NULL))) {
		#line 292
		return (*v3_existing);
	}
	#line 294
	s528_TypeIdent * v4_permanent = s518_allocate_typeident(v1_type_idents, v2_type);
	#line 295
	s570_find_or_insert((&((*v1_type_idents).types_set)), ((void *)(&v4_permanent)));
	#line 296
	return v4_permanent;
}


#line 300 "src/typecheck/typeident.ib"
bool s514_is_anyptr(s528_TypeIdent * v1_type) {
	#line 301
	return ((((*v1_type).kind) == s534_TypeKind_Pointer) && ((((*v1_type).data).pointer) == ((s528_TypeIdent *)NULL)));
}


#line 305 "src/typecheck/typeident.ib"
bool s515_is_numeric(s528_TypeIdent * v1_type) {
	#line 306
	if ((((*v1_type).kind) != s534_TypeKind_Atomic)) {
		#line 306
		return false;
	}
	#line 307
	if (((((*v1_type).data).atomic) == s535_AtomicType_Bool)) {
		#line 307
		return false;
	}
	#line 308
	return true;
}


#line 311 "src/typecheck/typeident.ib"
bool s516_is_enum(s528_TypeIdent * v1_type) {
	#line 312
	if ((((*v1_type).kind) != s534_TypeKind_Compound)) {
		#line 312
		return false;
	}
	#line 313
	s201_UID v2_s = (((*v1_type).data).compound);
	#line 314
	if ((s190_kind(v2_s) != s544_SymbolKind_Enum)) {
		#line 314
		return false;
	}
	#line 315
	return true;
}


#line 319 "src/typecheck/typeident.ib"
bool s517_is_object(s528_TypeIdent * v1_type) {
	#line 320
	if ((v1_type == ((s528_TypeIdent *)NULL))) {
		#line 320
		return false;
	}
	#line 321
	if ((((*v1_type).kind) != s534_TypeKind_Compound)) {
		#line 321
		return false;
	}
	#line 322
	switch (s190_kind((((*v1_type).data).compound))) {
	case s544_SymbolKind_Struct:
	case s544_SymbolKind_Union: {
	return true;
	break; }
	default:
 {
	break; }
}
	#line 327
	return false;
}


#line 331 "src/typecheck/typeident.ib"
s528_TypeIdent * s518_allocate_typeident(s531_TypeIdents * v1_typeidents, s528_TypeIdent * v2_type) {
	#line 332
	s528_TypeIdent * v3_new_type = ((s528_TypeIdent *)s561_allocate((&((*v1_typeidents).types_arena)), ((i64)48ul)));
	#line 333
	((*v3_new_type).kind) = ((*v2_type).kind);
	#line 334
	switch (((*v3_new_type).kind)) {
	case s534_TypeKind_Atomic: {
		#line 335
		(((*v3_new_type).data).atomic) = (((*v2_type).data).atomic);
	break; }
	case s534_TypeKind_Pointer: {
		#line 336
		(((*v3_new_type).data).pointer) = (((*v2_type).data).pointer);
	break; }
	case s534_TypeKind_Compound: {
		#line 337
		(((*v3_new_type).data).compound) = (((*v2_type).data).compound);
	break; }
	case s534_TypeKind_Array: {
		#line 339
		s529_ArrayType * v4_src = (&(((*v2_type).data).array));
		#line 340
		s529_ArrayType * v5_dest = (&(((*v3_new_type).data).array));
		#line 341
		i64 v6_len = ((*v4_src).dimension_length);
		#line 342
		u64 v7_size = (8ul * ((u64)v6_len));
		#line 343
		((*v5_dest).parent) = ((*v4_src).parent);
		#line 344
		((*v5_dest).dimension_length) = v6_len;
		#line 345
		((*v5_dest).dimensions) = ((i64 *)s561_allocate((&((*v1_typeidents).types_arena)), ((i64)v7_size)));
		#line 346
		memcpy(((void *)((*v5_dest).dimensions)), ((void *)((*v4_src).dimensions)), v7_size);
	break; }
	case s534_TypeKind_Function: {
		#line 349
		s530_FunctionType * v8_src = (&(((*v2_type).data).function));
		#line 350
		s530_FunctionType * v9_dest = (&(((*v3_new_type).data).function));
		#line 351
		i64 v10_len = ((*v8_src).args_length);
		#line 352
		s528_TypeIdent * * v11_args = ((*v8_src).args);
		#line 353
		u64 v12_size = (8ul * ((u64)v10_len));
		#line 355
		((*v9_dest).return_ty) = ((*v8_src).return_ty);
		#line 356
		((*v9_dest).has_varargs) = ((*v8_src).has_varargs);
		#line 357
		((*v9_dest).args_length) = v10_len;
		#line 358
		((*v9_dest).args) = ((s528_TypeIdent * *)s561_allocate((&((*v1_typeidents).types_arena)), ((i64)v12_size)));
		#line 359
		memcpy(((void *)((*v9_dest).args)), ((void *)v11_args), v12_size);
	break; }
	default:
		abort();
}
	#line 362
	return v3_new_type;
}


#line 366 "src/typecheck/typeident.ib"
i64 s519_typeident_hash(s528_TypeIdent * * v1_ident) {
	#line 367
	s528_TypeIdent * v2_ident = (*v1_ident);
	#line 368
	i64 v3_h = ((i64)((*v2_ident).kind));
	#line 369
	switch (((*v2_ident).kind)) {
	case s534_TypeKind_Atomic: {
		#line 370
		v3_h = ((v3_h * 31l) + ((i64)(((*v2_ident).data).atomic)));
	break; }
	case s534_TypeKind_Pointer: {
		#line 371
		v3_h = ((v3_h * 31l) + ((i64)(((*v2_ident).data).pointer)));
	break; }
	case s534_TypeKind_Compound: {
		#line 372
		v3_h = ((v3_h * 31l) + ((((*v2_ident).data).compound).symbol));
	break; }
	case s534_TypeKind_Array: {
		#line 374
		v3_h = ((v3_h * 31l) + ((i64)((((*v2_ident).data).array).parent)));
		#line 375
		v3_h = ((v3_h * 31l) + ((i64)((((*v2_ident).data).array).dimension_length)));
		#line 376
		for (i64 v4_i = 0l;(v4_i < ((((*v2_ident).data).array).dimension_length));v4_i += 1l) {
			#line 377
			v3_h = ((v3_h * 31l) + (((((*v2_ident).data).array).dimensions)[v4_i]));
		}
		loop_exit_1:
	break; }
	case s534_TypeKind_Function: {
		#line 381
		v3_h = ((v3_h * 31l) + ((i64)((((*v2_ident).data).function).args_length)));
		#line 382
		v3_h *= 31l;
		#line 383
		if (((((*v2_ident).data).function).has_varargs)) {
			#line 383
			v3_h += 1l;
		}
		#line 384
		v3_h = ((v3_h * 31l) + ((i64)(((((*v2_ident).data).function).return_ty).kind)));
	break; }
	default:
		abort();
}
	#line 387
	return v3_h;
}


#line 391 "src/typecheck/typeident.ib"
bool s520_typeident_eq(s528_TypeIdent * * v1_lhs, s528_TypeIdent * * v2_rhs) {
	#line 392
	s528_TypeIdent * v3_lhs = (*v1_lhs);
	#line 393
	s528_TypeIdent * v4_rhs = (*v2_rhs);
	#line 395
	if ((((*v3_lhs).kind) != ((*v4_rhs).kind))) {
		#line 395
		return false;
	}
	#line 396
	if (((v3_lhs == ((s528_TypeIdent *)NULL)) || (v4_rhs == ((s528_TypeIdent *)NULL)))) {
		#line 396
		return false;
	}
	#line 398
	switch (((*v3_lhs).kind)) {
	case s534_TypeKind_Atomic: {
		#line 399
		return ((((*v3_lhs).data).atomic) == (((*v4_rhs).data).atomic));
	break; }
	case s534_TypeKind_Pointer: {
		#line 400
		return ((((*v3_lhs).data).pointer) == (((*v4_rhs).data).pointer));
	break; }
	case s534_TypeKind_Compound: {
		#line 401
		return s171_eq((((*v3_lhs).data).compound), (((*v4_rhs).data).compound));
	break; }
	case s534_TypeKind_Array: {
		#line 403
		if ((((((*v3_lhs).data).array).parent) != ((((*v4_rhs).data).array).parent))) {
			#line 403
			return false;
		}
		#line 404
		i64 v5_len = ((((*v3_lhs).data).array).dimension_length);
		#line 405
		if ((v5_len != ((((*v4_rhs).data).array).dimension_length))) {
			#line 405
			return false;
		}
		#line 407
		for (i64 v6_i = 0l;(v6_i < v5_len);v6_i += 1l) {
			#line 408
			if (((((((*v3_lhs).data).array).dimensions)[v6_i]) != (((((*v4_rhs).data).array).dimensions)[v6_i]))) {
				#line 409
				return false;
			}
		}
		loop_exit_1:
		#line 412
		return true;
	break; }
	case s534_TypeKind_Function: {
		#line 415
		s530_FunctionType * v7_lhs = (&(((*v3_lhs).data).function));
		#line 416
		s530_FunctionType * v8_rhs = (&(((*v4_rhs).data).function));
		#line 417
		if (((((*v7_lhs).return_ty).kind) != (((*v8_rhs).return_ty).kind))) {
			#line 417
			return false;
		}
		#line 418
		if ((((*v7_lhs).args_length) != ((*v8_rhs).args_length))) {
			#line 418
			return false;
		}
		#line 419
		if ((((*v7_lhs).has_varargs) != ((*v8_rhs).has_varargs))) {
			#line 419
			return false;
		}
		#line 420
		if (((((*v7_lhs).return_ty).kind) == s533_FlowTypeKind_Some)) {
			#line 421
			if (((((*v7_lhs).return_ty).type) != (((*v8_rhs).return_ty).type))) {
				#line 422
				return false;
			}
		}
		#line 425
		i64 v9_len = ((*v7_lhs).args_length);
		#line 426
		for (i64 v10_i = 0l;(v10_i < v9_len);v10_i += 1l) {
			#line 427
			if (((((*v7_lhs).args)[v10_i]) != (((*v8_rhs).args)[v10_i]))) {
				#line 428
				return false;
			}
		}
		loop_exit_2:
		#line 431
		return true;
	break; }
	default:
		abort();
}
}


#line 437 "src/typecheck/typeident.ib"
s535_AtomicType s521_ast_atomicty_into_ty(s222_AtomicType v1_from) {
	#line 438
	switch (v1_from) {
	case s222_AtomicType_Bool: {
	return s535_AtomicType_Bool;
	break; }
	case s222_AtomicType_U8: {
	return s535_AtomicType_U8;
	break; }
	case s222_AtomicType_U16: {
	return s535_AtomicType_U16;
	break; }
	case s222_AtomicType_U32: {
	return s535_AtomicType_U32;
	break; }
	case s222_AtomicType_U64: {
	return s535_AtomicType_U64;
	break; }
	case s222_AtomicType_U128: {
	return s535_AtomicType_U128;
	break; }
	case s222_AtomicType_I8: {
	return s535_AtomicType_I8;
	break; }
	case s222_AtomicType_I16: {
	return s535_AtomicType_I16;
	break; }
	case s222_AtomicType_I32: {
	return s535_AtomicType_I32;
	break; }
	case s222_AtomicType_I64: {
	return s535_AtomicType_I64;
	break; }
	case s222_AtomicType_I128: {
	return s535_AtomicType_I128;
	break; }
	case s222_AtomicType_F32: {
	return s535_AtomicType_F32;
	break; }
	case s222_AtomicType_F64: {
	return s535_AtomicType_F64;
	break; }
	default:
		abort();
}
}


#line 462 "src/typecheck/typeident.ib"
bool s522_flowtype_eq(s527_FlowType v1_lhs, s527_FlowType v2_rhs) {
	#line 463
	return (((v1_lhs.kind) == (v2_rhs.kind)) && ((v1_lhs.type) == (v2_rhs.type)));
}


#line 465 "src/typecheck/typeident.ib"
void s523_print(s846_Nodes * v1_nodes, s528_TypeIdent * v2_type) {
	#line 466
	s299_StringBuilder v3_sb = s277_new();
	#line 467
	s524_debug((&v3_sb), v1_nodes, v2_type, 0l);
	#line 468
	puts(s294_merge((&v3_sb)));
	#line 469
	s278_free((&v3_sb));
}


#line 474 "src/typecheck/typeident.ib"
void s524_debug(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, s528_TypeIdent * v3_type, i64 v4_depth) {
	#line 480
	if ((v3_type == ((s528_TypeIdent *)NULL))) {
		#line 481
		s283_append(v1_sb, "!UNKNOWN!");
		#line 482
		return;
	}
	#line 484
	switch (((*v3_type).kind)) {
	case s534_TypeKind_Atomic: {
	s526_debug_atomic(v1_sb, (((*v3_type).data).atomic));
	break; }
	case s534_TypeKind_Pointer: {
		#line 487
		if (((((*v3_type).data).pointer) == ((s528_TypeIdent *)NULL))) {
			#line 488
			s283_append(v1_sb, "ANYPTR");
		} else {
#line 490
			s283_append(v1_sb, "PTR(");
			#line 491
			s524_debug(v1_sb, v2_nodes, (((*v3_type).data).pointer), v4_depth);
			#line 492
			s283_append(v1_sb, ")");
		}
	break; }
	case s534_TypeKind_Compound: {
	s200_debug_head(v1_sb, (((*v3_type).data).compound));
	break; }
	case s534_TypeKind_Array: {
		#line 497
		s524_debug(v1_sb, v2_nodes, ((((*v3_type).data).array).parent), v4_depth);
		#line 498
		for (i64 v5_i = 0l;(v5_i < ((((*v3_type).data).array).dimension_length));v5_i += 1l) {
			#line 499
			s284_append_char(v1_sb, 91u);
			#line 500
			s289_append_number(v1_sb, (((((*v3_type).data).array).dimensions)[v5_i]));
			#line 501
			s284_append_char(v1_sb, 93u);
		}
		loop_exit_1:
	break; }
	case s534_TypeKind_Function: {
		#line 505
		s530_FunctionType * v6_fn_type = (&(((*v3_type).data).function));
		#line 506
		s283_append(v1_sb, "fn(");
		#line 507
		for (i64 v7_i = 0l;(v7_i < ((*v6_fn_type).args_length));v7_i += 1l) {
			#line 508
			if ((v7_i > 0l)) {
				#line 508
				s283_append(v1_sb, ", ");
			}
			#line 509
			s524_debug(v1_sb, v2_nodes, (((*v6_fn_type).args)[v7_i]), v4_depth);
		}
		loop_exit_2:
		#line 511
		if (((*v6_fn_type).has_varargs)) {
			#line 512
			if ((((*v6_fn_type).args_length) > 0l)) {
				#line 512
				s283_append(v1_sb, ", ");
			}
			#line 513
			s283_append(v1_sb, "...");
		}
		#line 515
		s283_append(v1_sb, "): ");
		#line 516
		s525_debug_flowtype(v1_sb, v2_nodes, (&((*v6_fn_type).return_ty)), v4_depth);
	break; }
	default:
		abort();
}
}


#line 521 "src/typecheck/typeident.ib"
void s525_debug_flowtype(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, s527_FlowType * v3_flow_type, i64 v4_depth) {
	#line 522
	switch (((*v3_flow_type).kind)) {
	case s533_FlowTypeKind_Some: {
	s524_debug(v1_sb, v2_nodes, ((*v3_flow_type).type), v4_depth);
	break; }
	case s533_FlowTypeKind_Void: {
	s283_append(v1_sb, "void");
	break; }
	case s533_FlowTypeKind_Never: {
	s283_append(v1_sb, "!");
	break; }
	default:
		abort();
}
}


#line 530 "src/typecheck/typeident.ib"
void s526_debug_atomic(s299_StringBuilder * v1_sb, s535_AtomicType v2_atomic) {
	#line 531
	switch (v2_atomic) {
	case s535_AtomicType_Bool: {
	s283_append(v1_sb, "bool");
	break; }
	case s535_AtomicType_U8: {
	s283_append(v1_sb, "u8");
	break; }
	case s535_AtomicType_U16: {
	s283_append(v1_sb, "u16");
	break; }
	case s535_AtomicType_U32: {
	s283_append(v1_sb, "u32");
	break; }
	case s535_AtomicType_U64: {
	s283_append(v1_sb, "u64");
	break; }
	case s535_AtomicType_U128: {
	s283_append(v1_sb, "u128");
	break; }
	case s535_AtomicType_I8: {
	s283_append(v1_sb, "i8");
	break; }
	case s535_AtomicType_I16: {
	s283_append(v1_sb, "i16");
	break; }
	case s535_AtomicType_I32: {
	s283_append(v1_sb, "i32");
	break; }
	case s535_AtomicType_I64: {
	s283_append(v1_sb, "i64");
	break; }
	case s535_AtomicType_I128: {
	s283_append(v1_sb, "i128");
	break; }
	case s535_AtomicType_F32: {
	s283_append(v1_sb, "f32");
	break; }
	case s535_AtomicType_F64: {
	s283_append(v1_sb, "f64");
	break; }
	default:
		abort();
}
}


#line 70 "src/symbol/symbol.ib"
void s536_debug(s540_Symbol * v1_symbol) {
	#line 71
	if ((v1_symbol == ((s540_Symbol *)NULL))) {
		#line 72
		printf("Symbol NONE\n");
		#line 73
		return;
	}
	#line 75
	printf("Symbol #%d:\n", ((*v1_symbol).uid));
	#line 76
	printf("\tmodule: %d\n", ((*v1_symbol).module));
	#line 77
	printf("\tname: %s\n", ((*v1_symbol).name));
	#line 78
	printf("\tkind: ");
	#line 79
	switch (((*v1_symbol).kind)) {
	case s544_SymbolKind_Struct: {
	printf("Struct");
	break; }
	case s544_SymbolKind_Union: {
	printf("Union");
	break; }
	case s544_SymbolKind_Enum: {
	printf("Enum");
	break; }
	case s544_SymbolKind_Global: {
	printf("Global");
	break; }
	case s544_SymbolKind_Function: {
	printf("Function");
	break; }
	default:
		abort();
}
	#line 86
	printf("\n");
	#line 88
	printf("\tstage: ");
	#line 89
	switch (((*v1_symbol).stage)) {
	case s543_SymbolStage_Declared: {
	printf("Declared");
	break; }
	case s543_SymbolStage_SymbolResolved: {
	printf("SymbolResolved");
	break; }
	case s543_SymbolStage_TypecheckInProgress: {
	printf("TypecheckInProgress");
	break; }
	case s543_SymbolStage_Typechecked: {
	printf("Typechecked");
	break; }
	case s543_SymbolStage_ImplementationEmitted: {
	printf("ImplementationEmitted");
	break; }
	default:
		abort();
}
	#line 96
	printf("\n");
	#line 97
	printf("\tshallow: %lu\n", (((*v1_symbol).shallow).unknown));
	#line 98
	printf("\t   deep: %lu\n", (((*v1_symbol).deep).unknown));
	#line 100
	printf("\tattr: ");
	#line 101
	if (((*v1_symbol).is_extern)) {
		#line 101
		printf("extern, ");
	}
	#line 102
	if (((*v1_symbol).is_public)) {
		#line 102
		printf("pub, ");
	}
	#line 103
	printf("\n");
}


#line 106 "src/symbol/symbol.ib"
void s537_print_ptr(s540_Symbol * v1_symbol) {
	#line 107
	printf("SYMBOL@[mod=%d,uid=%d,name=%s]", ((*v1_symbol).module), ((*v1_symbol).uid), ((*v1_symbol).name));
	#line 113
	fflush(stdout);
}


#line 116 "src/symbol/symbol.ib"
void s538_debug_ptr(s299_StringBuilder * v1_sb, s540_Symbol * v2_symbol) {
	#line 117
	s283_append(v1_sb, "SYMBOL@[ptr=");
	#line 118
	s289_append_number(v1_sb, ((i64)v2_symbol));
	#line 119
	s283_append(v1_sb, ",uid=");
	#line 120
	s289_append_number(v1_sb, ((*v2_symbol).uid));
	#line 121
	s283_append(v1_sb, ",module=");
	#line 122
	s289_append_number(v1_sb, ((*v2_symbol).module));
	#line 123
	s283_append(v1_sb, ",name=");
	#line 124
	s283_append(v1_sb, ((*v2_symbol).name));
	#line 125
	s283_append(v1_sb, "]");
}


#line 128 "src/symbol/symbol.ib"
void s539_debug_head(s299_StringBuilder * v1_sb, s540_Symbol * v2_symbol) {
	#line 129
	if ((v2_symbol == ((s540_Symbol *)NULL))) {
		#line 130
		s283_append(v1_sb, "SYMBOL@NONE");
		#line 131
		return;
	}
	#line 133
	s283_append(v1_sb, "SYMBOL@");
	#line 134
	s289_append_number(v1_sb, ((*v2_symbol).uid));
	#line 135
	s283_append(v1_sb, "[name=");
	#line 136
	s283_append(v1_sb, ((*v2_symbol).name));
	#line 137
	s283_append(v1_sb, ",module=");
	#line 138
	s289_append_number(v1_sb, ((*v2_symbol).module));
	#line 139
	s283_append(v1_sb, "]");
}


#line 21 "src/symbol/resolve.ib"
s554_PathResult s545_path(i64 v1_module_uid, char * * v2_path, i64 v3_path_len) {
	#line 22
	v3_path_len -= 1l;
	#line 23
	char * v4_name = (v2_path[v3_path_len]);
	#line 24
	i64 v5_current_module = v1_module_uid;
	#line 26
	for (i64 v6_i = 0l;(v6_i < v3_path_len);v6_i += 1l) {
		#line 27
		s377_ModuleMeta * v7_meta = s179_get_module_meta(v5_current_module);
		#line 28
		char * v8_node = (v2_path[v6_i]);
		#line 29
		bool v9_is_first = (v6_i == 0l);
		#line 30
		bool v10_is_last = ((v6_i + 1l) == v3_path_len);
		#line 32
		s555_FindNextNodeResult v11_res = s549_path_find_next_node(v7_meta, v8_node);
		#line 33
		bool v12_visible = ((v11_res.is_public) || v9_is_first);
		#line 34
		if (((v11_res.found) && v12_visible)) {
			#line 35
			v5_current_module = (v11_res.module);
			#line 36
			continue;
		}
		#line 39
		s201_UID v13_symbol = s178_find_symbol(v5_current_module, v8_node);
		#line 41
		if ((s170_is_none(v13_symbol) && v9_is_first)) {
			#line 42
			s556_IdentResult v14_res = s550_identifier(v5_current_module, v8_node);
			#line 43
			switch ((v14_res.kind)) {
			case s558_IdentResultKind_Found: {
			v13_symbol = (v14_res.symbol);
			break; }
			default:
 {
			break; }
}
		}
		#line 49
		s557_PathResultKind v15_err_kind = s557_PathResultKind_ErrModuleNotFound;
		#line 50
		if (s170_is_none(v13_symbol)) {
			#line 52
			if ((v11_res.found)) {
				#line 53
				v15_err_kind = s557_PathResultKind_ErrModuleWasPrivate;
			}
			#line 55
			return s548_path_err(v15_err_kind, v6_i);
		}
		#line 58
		bool v16_visible = (s192_is_public(v13_symbol) || v9_is_first);
		#line 59
		if ((!v16_visible)) {
			#line 61
			if ((!(v11_res.found))) {
				#line 62
				v15_err_kind = s557_PathResultKind_ErrSymbolWasPrivate;
			}
			#line 64
			return s548_path_err(v15_err_kind, v6_i);
		}
		#line 71
		if (v10_is_last) {
			#line 72
			return s547_path_skipped(v13_symbol);
		}
		#line 74
		return s548_path_err(s557_PathResultKind_ErrModuleNotFound, v6_i);
	}
	loop_exit_1:
	#line 76
	s201_UID v17_symbol = s178_find_symbol(v5_current_module, v4_name);
	#line 77
	if ((s170_is_none(v17_symbol) && (v3_path_len == 0l))) {
		#line 78
		s556_IdentResult v18_res = s550_identifier(v5_current_module, v4_name);
		#line 79
		switch ((v18_res.kind)) {
		case s558_IdentResultKind_Found: {
		v17_symbol = (v18_res.symbol);
		break; }
		default:
 {
		break; }
}
	}
	#line 84
	if (s170_is_none(v17_symbol)) {
		#line 85
		return s548_path_err(s557_PathResultKind_ErrSymbolNotFound, v3_path_len);
	}
	#line 87
	if (((!s192_is_public(v17_symbol)) && (v3_path_len != 0l))) {
		#line 88
		return s548_path_err(s557_PathResultKind_ErrSymbolWasPrivate, v3_path_len);
	}
	#line 90
	return ((s554_PathResult){
		.kind = s557_PathResultKind_Found,
		.symbol = v17_symbol,
		.not_found_module_index = 0l
	});
}


#line 96 "src/symbol/resolve.ib"
s554_PathResult s546_path_found(s201_UID v1_symbol) {
	#line 97
	return ((s554_PathResult){
		.kind = s557_PathResultKind_Found,
		.symbol = v1_symbol,
		.not_found_module_index = 0l
	});
}


#line 104 "src/symbol/resolve.ib"
s554_PathResult s547_path_skipped(s201_UID v1_symbol) {
	#line 105
	return ((s554_PathResult){
		.kind = s557_PathResultKind_SkippedName,
		.symbol = v1_symbol,
		.not_found_module_index = 0l
	});
}


#line 111 "src/symbol/resolve.ib"
s554_PathResult s548_path_err(s557_PathResultKind v1_kind, i64 v2_not_found_module_index) {
	#line 112
	return ((s554_PathResult){
		.kind = v1_kind,
		.symbol = s168_NONE,
		.not_found_module_index = v2_not_found_module_index
	});
}


#line 123 "src/symbol/resolve.ib"
s555_FindNextNodeResult s549_path_find_next_node(s377_ModuleMeta * v1_meta, char * v2_alias) {
	#line 127
	for (i64 v3_i = 0l;(v3_i < ((*v1_meta).import_length));v3_i += 1l) {
		#line 128
		s376_ModuleImport * v4_imprt = s180_get_module_import(v1_meta, v3_i);
		#line 129
		if ((((*v4_imprt).alias) != v2_alias)) {
			#line 129
			continue;
		}
		#line 130
		return ((s555_FindNextNodeResult){
			.found = true,
			.module = ((*v4_imprt).module),
			.is_public = ((*v4_imprt).is_public)
		});
	}
	loop_exit_1:
	#line 136
	return ((s555_FindNextNodeResult){
		.found = false,
		.module = 0l,
		.is_public = true
	});
}


#line 155 "src/symbol/resolve.ib"
s556_IdentResult s550_identifier(i64 v1_module_uid, char * v2_ident) {
	#line 156
	s201_UID v3_symbol = s178_find_symbol(v1_module_uid, v2_ident);
	#line 157
	if ((!s170_is_none(v3_symbol))) {
		#line 157
		return s552_ident_ok(v3_symbol);
	}
	#line 159
	s377_ModuleMeta * v4_meta = s179_get_module_meta(v1_module_uid);
	#line 160
	s201_UID v5_private_symbol = s168_NONE;
	#line 161
	i64 v6_private_count = 0l;
	#line 162
	i64 v7_public_count = 0l;
	#line 163
	for (i64 v8_i = 0l;(v8_i < ((*v4_meta).import_length));v8_i += 1l) {
		#line 164
		s376_ModuleImport * v9_imprt = s180_get_module_import(v4_meta, v8_i);
		#line 165
		if ((((*v9_imprt).alias) != ((char *)NULL))) {
			#line 165
			continue;
		}
		#line 167
		s201_UID v10_mod_symbol = s178_find_symbol(((*v9_imprt).module), v2_ident);
		#line 168
		if (s170_is_none(v10_mod_symbol)) {
			#line 168
			continue;
		}
		#line 169
		if (s192_is_public(v10_mod_symbol)) {
			#line 170
			v3_symbol = v10_mod_symbol;
			#line 171
			v7_public_count += 1l;
		} else {
#line 173
			v5_private_symbol = v10_mod_symbol;
			#line 174
			v6_private_count += 1l;
		}
	}
	loop_exit_1:
	#line 178
	if ((v7_public_count == 1l)) {
		#line 178
		return s552_ident_ok(v3_symbol);
	}
	#line 183
	if ((v7_public_count > 1l)) {
		#line 183
		return s551_ident_err(s558_IdentResultKind_ErrFoundMultiple);
	}
	#line 185
	if ((v6_private_count == 0l)) {
		#line 185
		return s551_ident_err(s558_IdentResultKind_ErrSymbolNotFound);
	}
	#line 186
	if ((v6_private_count == 1l)) {
		#line 186
		return s551_ident_err(s558_IdentResultKind_ErrSymbolWasPrivate);
	}
	#line 187
	return s551_ident_err(s558_IdentResultKind_ErrFoundMultiplePrivate);
}


#line 190 "src/symbol/resolve.ib"
s556_IdentResult s551_ident_err(s558_IdentResultKind v1_kind) {
	#line 191
	return ((s556_IdentResult){
		.kind = v1_kind,
		.symbol = s168_NONE
	});
}


#line 195 "src/symbol/resolve.ib"
s556_IdentResult s552_ident_ok(s201_UID v1_symbol) {
	#line 196
	return ((s556_IdentResult){
		.kind = s558_IdentResultKind_Found,
		.symbol = v1_symbol
	});
}


#line 200 "src/symbol/resolve.ib"
s257_Vec s553_collect_identifiers(i64 v1_module_uid, char * v2_ident, i64 v3_count, bool v4_was_public) {
	#line 201
	s257_Vec v5_symbols = s243_new(((i64)72ul), v3_count);
	#line 202
	s377_ModuleMeta * v6_meta = s179_get_module_meta(v1_module_uid);
	#line 203
	for (i64 v7_i = 0l;(v7_i < ((*v6_meta).import_length));v7_i += 1l) {
		#line 204
		s376_ModuleImport * v8_imprt = s180_get_module_import(v6_meta, v7_i);
		#line 205
		if ((((*v8_imprt).alias) != ((char *)NULL))) {
			#line 205
			continue;
		}
		#line 207
		s201_UID v9_mod_symbol = s178_find_symbol(((*v8_imprt).module), v2_ident);
		#line 208
		if (s170_is_none(v9_mod_symbol)) {
			#line 208
			continue;
		}
		#line 209
		if ((s192_is_public(v9_mod_symbol) == v4_was_public)) {
			#line 210
			s201_UID * v10_s = ((s201_UID *)s249_push((&v5_symbols)));
			#line 211
			(*v10_s) = v9_mod_symbol;
		}
	}
	loop_exit_1:
	#line 214
	return v5_symbols;
}


#line 33 "src/utils/arena.ib"
s566_Arena s560_new(i64 v1_initial_capacity) {
	#line 34
	s40_assert((v1_initial_capacity > 0l), "arena::new capacity was not positive!");
	#line 35
	v1_initial_capacity = s564_with_alignment(v1_initial_capacity);
	#line 36
	s567_ArenaNode * v2_head = s563_create_node(v1_initial_capacity);
	#line 37
	s567_ArenaNode * v3_tail = v2_head;
	#line 38
	s40_assert((v2_head != ((s567_ArenaNode *)NULL)), "Arena head was null!");
	#line 39
	s257_Vec v4_debug_allocs = s243_new(((i64)8ul), 64l);
	#line 40
	return ((s566_Arena){
		.head = v2_head,
		.tail = v3_tail,
		.debug = false,
		.debug_allocs = v4_debug_allocs
	});
}


#line 44 "src/utils/arena.ib"
void * s561_allocate(s566_Arena * v1_arena, i64 v2_size) {
	#line 47
	if ((v2_size == 0l)) {
		#line 47
		return NULL;
	}
	#line 48
	s40_assert((v2_size > 0l), "arena::allocate size less than zero!");
	#line 49
	v2_size = s564_with_alignment(v2_size);
	#line 51
	if (s559_DEBUG_ALLOCATIONS) {
		#line 51
		return s565_debug_allocate(v1_arena, v2_size);
	}
	#line 53
	if ((((*v1_arena).head) == ((s567_ArenaNode *)NULL))) {
		#line 54
		((*v1_arena).head) = s563_create_node((v2_size * 32l));
		#line 55
		((*v1_arena).tail) = ((*v1_arena).head);
	}
	#line 57
	if (((((*((*v1_arena).tail)).size) + v2_size) > ((*((*v1_arena).tail)).capacity))) {
		#line 58
		i64 v3_new_capacity = (((*((*v1_arena).tail)).capacity) * 2l);
		#line 59
		if ((v3_new_capacity < v2_size)) {
			#line 59
			v3_new_capacity = (v2_size * 2l);
		}
		#line 61
		s567_ArenaNode * v4_new_tail = s563_create_node(v3_new_capacity);
		#line 62
		((*((*v1_arena).tail)).next) = v4_new_tail;
		#line 63
		((*v1_arena).tail) = v4_new_tail;
		#line 64
		if (((*v1_arena).debug)) {
			#line 65
			printf("[ARENA] new tail: %lu %lu cap: %d size: %d\n", ((i64)v4_new_tail), ((i64)((*v4_new_tail).content)), ((*v4_new_tail).capacity), ((*v4_new_tail).size));
			#line 72
			fflush(stdout);
		}
	}
	#line 75
	char * v5_s = (&(((*((*v1_arena).tail)).content)[((*((*v1_arena).tail)).size)]));
	#line 76
	memset(((void *)v5_s), ((int)0l), ((u64)v2_size));
	#line 77
	((*((*v1_arena).tail)).size) += v2_size;
	#line 78
	if (((*v1_arena).debug)) {
		#line 79
		printf("[ARENA] Alloc: %lu %lu cap: %d size: %d\n", ((*((*v1_arena).tail)).content), v5_s, ((*((*v1_arena).tail)).capacity), ((*((*v1_arena).tail)).size));
		#line 82
		fflush(stdout);
	}
	#line 84
	return ((void *)v5_s);
}


#line 89 "src/utils/arena.ib"
i64 s562_free(s566_Arena * v1_arena) {
	#line 90
	s40_assert((v1_arena != ((s566_Arena *)NULL)), "Arena was null!");
	#line 91
	i64 v2_free_amount = 0l;
	#line 92
	s567_ArenaNode * v3_current = ((*v1_arena).head);
	#line 93
	while ((v3_current != ((s567_ArenaNode *)NULL))) {
		#line 94
		s567_ArenaNode * v4_next = ((*v3_current).next);
		#line 95
		v2_free_amount += ((*v3_current).capacity);
		#line 96
		free(((void *)v3_current));
		#line 97
		v3_current = v4_next;
}
	loop_exit_1:
	#line 99
	((*v1_arena).head) = ((s567_ArenaNode *)NULL);
	#line 100
	((*v1_arena).tail) = ((s567_ArenaNode *)NULL);
	#line 102
	if (s559_DEBUG_ALLOCATIONS) {
		#line 103
		for (i64 v5_i = 0l;(v5_i < (((*v1_arena).debug_allocs).count));v5_i += 1l) {
			#line 104
			void * * v6_ptr = ((void * *)s251_get((&((*v1_arena).debug_allocs)), v5_i));
			#line 105
			free((*v6_ptr));
		}
		loop_exit_2:
		#line 107
		s246_free((&((*v1_arena).debug_allocs)));
	}
	#line 110
	return v2_free_amount;
}


#line 114 "src/utils/arena.ib"
s567_ArenaNode * s563_create_node(i64 v1_capacity) {
	#line 115
	s40_assert((v1_capacity > 0l), "arena::create_node size less than zero!");
	#line 116
	i64 v2_header_size = s564_with_alignment(((i64)32ul));
	#line 117
	s567_ArenaNode * v3_node = ((s567_ArenaNode *)malloc(((u64)(v2_header_size + v1_capacity))));
	#line 118
	((*v3_node).capacity) = v1_capacity;
	#line 119
	((*v3_node).size) = 0l;
	#line 120
	((*v3_node).next) = ((s567_ArenaNode *)NULL);
	#line 121
	((*v3_node).content) = (&(((char *)v3_node)[v2_header_size]));
	#line 122
	return v3_node;
}


#line 126 "src/utils/arena.ib"
i64 s564_with_alignment(i64 v1_size) {
	#line 127
	i64 v2_rem = (v1_size % 8l);
	#line 128
	if ((v2_rem == 0l)) {
		#line 128
		return v1_size;
	}
	#line 129
	return (v1_size + (8l - v2_rem));
}


#line 133 "src/utils/arena.ib"
void * s565_debug_allocate(s566_Arena * v1_arena, i64 v2_size) {
	#line 134
	if (((*v1_arena).debug)) {
		#line 135
		printf("[ARENA] DEBUG malloc size: %d\n", v2_size);
		#line 139
		fflush(stdout);
	}
	#line 141
	void * v3_ptr = malloc(((u64)v2_size));
	#line 142
	memset(v3_ptr, ((int)0l), ((u64)v2_size));
	#line 143
	void * * v4_stored = ((void * *)s249_push((&((*v1_arena).debug_allocs))));
	#line 144
	(*v4_stored) = v3_ptr;
	#line 145
	return v3_ptr;
}


#line 21 "src/utils/hashset.ib"
s576_HashSet s568_new(i64 v1_value_size, i64 (* v2_hash_fn)(void *), bool (* v3_eq_fn)(void *, void *)) {
	#line 22
	return ((s576_HashSet){
		.count = 0l,
		.capacity = 0l,
		.entries = ((s575_EntryMeta *)NULL),
		.values = ((char *)NULL),
		.value_size = v1_value_size,
		.hash_fn = v2_hash_fn,
		.eq_fn = v3_eq_fn,
		.free_fn = ((void (*)(void *))NULL)
	});
}


#line 32 "src/utils/hashset.ib"
void * s569_find(s576_HashSet * v1_set, void * v2_value) {
	#line 33
	if ((((*v1_set).capacity) == 0l)) {
		#line 33
		s573_expand(v1_set);
	}
	#line 34
	i64 (* v3_hash_fn)(void *) = ((*v1_set).hash_fn);
	#line 35
	i64 v4_hash = v3_hash_fn(v2_value);
	#line 36
	i64 v5_index = s572_find_entry_index(v1_set, v2_value, v4_hash);
	#line 37
	if (((((*v1_set).entries)[v5_index]).exists)) {
		#line 38
		return ((void *)(&(((*v1_set).values)[(((*v1_set).value_size) * v5_index)])));
	}
	#line 40
	return NULL;
}


#line 44 "src/utils/hashset.ib"
void * s570_find_or_insert(s576_HashSet * v1_set, void * v2_value) {
	#line 45
	if ((((f64)(((*v1_set).count) + 1l)) > (((f64)((*v1_set).capacity)) * 0.750000000000))) {
		#line 45
		s573_expand(v1_set);
	}
	#line 47
	i64 (* v3_hash_fn)(void *) = ((*v1_set).hash_fn);
	#line 48
	i64 v4_hash = v3_hash_fn(v2_value);
	#line 49
	i64 v5_index = s572_find_entry_index(v1_set, v2_value, v4_hash);
	#line 51
	if (((((*v1_set).entries)[v5_index]).exists)) {
		#line 52
		return ((void *)(&(((*v1_set).values)[(((*v1_set).value_size) * v5_index)])));
	}
	#line 54
	((*v1_set).count) += 1l;
	#line 56
	char * v6_set_value = (&(((*v1_set).values)[(((*v1_set).value_size) * v5_index)]));
	#line 57
	((((*v1_set).entries)[v5_index]).exists) = true;
	#line 58
	((((*v1_set).entries)[v5_index]).hash) = v4_hash;
	#line 59
	memcpy(((void *)v6_set_value), v2_value, ((u64)((*v1_set).value_size)));
	#line 64
	return ((void *)v6_set_value);
}


#line 68 "src/utils/hashset.ib"
void s571_free(s576_HashSet * v1_set) {
	#line 69
	if ((((*v1_set).free_fn) != ((void (*)(void *))NULL))) {
		#line 70
		void (* v2_free_value)(void *) = ((*v1_set).free_fn);
		#line 71
		for (i64 v3_i = 0l;(v3_i < ((*v1_set).capacity));v3_i += 1l) {
			#line 72
			if ((!((((*v1_set).entries)[v3_i]).exists))) {
				#line 72
				continue;
			}
			#line 73
			v2_free_value(((void *)(&(((*v1_set).values)[(((*v1_set).value_size) * v3_i)]))));
		}
		loop_exit_1:
	}
	#line 78
	((*v1_set).count) = 0l;
	#line 79
	((*v1_set).capacity) = 0l;
	#line 81
	free(((void *)((*v1_set).values)));
	#line 82
	free(((void *)((*v1_set).entries)));
	#line 84
	((*v1_set).values) = ((char *)NULL);
	#line 85
	((*v1_set).entries) = ((s575_EntryMeta *)NULL);
}


#line 89 "src/utils/hashset.ib"
i64 s572_find_entry_index(s576_HashSet * v1_set, void * v2_value, i64 v3_hash) {
	#line 90
	i64 v4_index = (((v3_hash % ((*v1_set).capacity)) + ((*v1_set).capacity)) % ((*v1_set).capacity));
	#line 91
	bool (* v5_eq_fn)(void *, void *) = ((*v1_set).eq_fn);
	#line 92
	while (1) {
		#line 93
		s575_EntryMeta * v6_entry = (&(((*v1_set).entries)[v4_index]));
		#line 94
		if ((!((*v6_entry).exists))) {
			#line 94
			return v4_index;
		}
		#line 95
		if ((((*v6_entry).hash) == v3_hash)) {
			#line 96
			if (v5_eq_fn(v2_value, ((void *)(&(((*v1_set).values)[(((*v1_set).value_size) * v4_index)]))))) {
				#line 97
				return v4_index;
			}
		}
		#line 100
		v4_index = ((v4_index + 1l) % ((*v1_set).capacity));
}
	loop_exit_1:
	#line 103
	return 0l;
}


#line 107 "src/utils/hashset.ib"
void s573_expand(s576_HashSet * v1_set) {
	#line 108
	i64 v2_new_capacity = (((*v1_set).capacity) * 2l);
	#line 109
	if ((v2_new_capacity < 256l)) {
		#line 109
		v2_new_capacity = 256l;
	}
	#line 111
	s575_EntryMeta * v3_entries = ((s575_EntryMeta *)malloc((16ul * ((u64)v2_new_capacity))));
	#line 112
	memset(((void *)v3_entries), ((int)0l), (16ul * ((u64)v2_new_capacity)));
	#line 113
	char * v4_values = ((char *)malloc(((u64)(((*v1_set).value_size) * v2_new_capacity))));
	#line 114
	memset(((void *)v4_values), ((int)0l), ((u64)(((*v1_set).value_size) * v2_new_capacity)));
	#line 116
	((*v1_set).count) = 0l;
	#line 117
	for (i64 v5_i = 0l;(v5_i < ((*v1_set).capacity));v5_i += 1l) {
		#line 118
		if ((!((((*v1_set).entries)[v5_i]).exists))) {
			#line 118
			continue;
		}
		#line 120
		i64 v6_hash = ((((*v1_set).entries)[v5_i]).hash);
		#line 121
		i64 v7_index = s574_find_next_empty_slot_index(v3_entries, v2_new_capacity, v6_hash);
		#line 122
		((v3_entries[v7_index]).exists) = true;
		#line 123
		((v3_entries[v7_index]).hash) = v6_hash;
		#line 124
		memcpy(((void *)(&(v4_values[(((*v1_set).value_size) * v7_index)]))), ((void *)(&(((*v1_set).values)[(((*v1_set).value_size) * v5_i)]))), ((u64)((*v1_set).value_size)));
		#line 129
		((*v1_set).count) += 1l;
	}
	loop_exit_1:
	#line 131
	free(((void *)((*v1_set).entries)));
	#line 132
	free(((void *)((*v1_set).values)));
	#line 133
	((*v1_set).capacity) = v2_new_capacity;
	#line 134
	((*v1_set).entries) = v3_entries;
	#line 135
	((*v1_set).values) = v4_values;
}


#line 139 "src/utils/hashset.ib"
i64 s574_find_next_empty_slot_index(s575_EntryMeta * v1_entries, i64 v2_capacity, i64 v3_hash) {
	#line 140
	i64 v4_index = (((v3_hash % v2_capacity) + v2_capacity) % v2_capacity);
	#line 141
	while (((v1_entries[v4_index]).exists)) {
		#line 142
		v4_index = ((v4_index + 1l) % v2_capacity);
}
	loop_exit_1:
	#line 144
	return v4_index;
}


#line 17 "src/ast/node.ib"
s587_Node * s578_get(s585_Nodes * v1_nodes, i64 v2_index) {
	#line 18
	return ((s587_Node *)s251_get((&((*v1_nodes).nodes)), v2_index));
}


#line 22 "src/ast/node.ib"
i64 s579_push(s585_Nodes * v1_nodes, s589_NodeKind v2_kind) {
	#line 23
	i64 v3_index = (((*v1_nodes).nodes).count);
	#line 24
	s587_Node * v4_node = ((s587_Node *)s249_push((&((*v1_nodes).nodes))));
	#line 25
	((*v4_node).kind) = v2_kind;
	#line 26
	return v3_index;
}


#line 30 "src/ast/node.ib"
void * s580_allocate_extra(s585_Nodes * v1_nodes, i64 v2_size) {
	#line 31
	if ((v2_size == 0l)) {
		#line 31
		return NULL;
	}
	#line 32
	s40_assert((v2_size > 0l), "allocate_extra size less than zero!");
	#line 33
	return s561_allocate((&((*v1_nodes).extras)), v2_size);
}


#line 37 "src/ast/node.ib"
s585_Nodes s581_new() {
	#line 38
	s257_Vec v1_nodes = s243_new(((i64)40ul), 256l);
	#line 39
	s566_Arena v2_extras = s560_new(256l);
	#line 40
	s249_push((&v1_nodes));
	#line 41
	return ((s585_Nodes){
		.nodes = v1_nodes,
		.extras = v2_extras
	});
}


#line 45 "src/ast/node.ib"
void s582_free(s585_Nodes * v1_nodes) {
	#line 46
	s246_free((&((*v1_nodes).nodes)));
	#line 47
	s562_free((&((*v1_nodes).extras)));
}


#line 109 "src/ast/node.ib"
bool s583_is_expression(s585_Nodes * v1_nodes, i64 v2_node) {
	#line 110
	s40_assert((v2_node != s577_NONE), "node::is_expression got NONE");
	#line 111
	s587_Node * v3_n = s578_get(v1_nodes, v2_node);
	#line 112
	switch (((*v3_n).kind)) {
	case s589_NodeKind_Literal:
	case s589_NodeKind_Ident:
	case s589_NodeKind_Binary:
	case s589_NodeKind_Unary:
	case s589_NodeKind_Cast:
	case s589_NodeKind_Array:
	case s589_NodeKind_ObjectInit:
	case s589_NodeKind_Call:
	case s589_NodeKind_SizeOf: {
	return true;
	break; }
	default:
 {
	return false;
	break; }
}
}


#line 127 "src/ast/node.ib"
void s584_debug(s299_StringBuilder * v1_sb, s585_Nodes * v2_nodes, i64 v3_node, i64 v4_depth) {
	#line 128
	s40_assert((v3_node != s577_NONE), "node::print got NONE");
	#line 129
	s587_Node * v5_n = s578_get(v2_nodes, v3_node);
	#line 130
	void * v6_data = ((void *)(&((*v5_n).data)));
	#line 131
	switch (((*v5_n).kind)) {
	case s589_NodeKind_None: {
	break; }
	case s589_NodeKind_Ident: {
		#line 135
		s288_repeat(v1_sb, "  ", v4_depth);
		#line 136
		s283_append(v1_sb, "IDENTIFIER: ");
		#line 137
		s283_append(v1_sb, (*((char * *)v6_data)));
		#line 138
		s283_append(v1_sb, "\n");
	break; }
	case s589_NodeKind_Literal: {
	s883_debug_literal(v1_sb, ((s895_Literal *)v6_data), v4_depth);
	break; }
	case s589_NodeKind_Binary: {
	s882_debug_binary(v1_sb, v2_nodes, ((s893_Binary *)v6_data), v4_depth);
	break; }
	case s589_NodeKind_Unary: {
	s881_debug_unary(v1_sb, v2_nodes, ((s894_Unary *)v6_data), v4_depth);
	break; }
	case s589_NodeKind_Cast: {
	s887_debug_cast(v1_sb, v2_nodes, ((s888_Cast *)v6_data), v4_depth);
	break; }
	case s589_NodeKind_Array: {
	s886_debug_array(v1_sb, v2_nodes, ((s889_Array *)v6_data), v4_depth);
	break; }
	case s589_NodeKind_ObjectInit: {
	s885_debug_object_init(v1_sb, v2_nodes, ((s891_ObjectInit *)v6_data), v4_depth);
	break; }
	case s589_NodeKind_Call: {
	s880_debug_call(v1_sb, v2_nodes, ((s890_Call *)v6_data), v4_depth);
	break; }
	case s589_NodeKind_SizeOf: {
	s884_debug_sizeof(v1_sb, v2_nodes, ((s586_TypeData *)v6_data), v4_depth);
	break; }
	case s589_NodeKind_Block: {
	s914_debug_block(v1_sb, v2_nodes, ((s923_BlockData *)v6_data), v4_depth);
	break; }
	case s589_NodeKind_ConstDecl: {
	s913_debug_var_decl(v1_sb, v2_nodes, false, ((s924_VarDeclaration *)v6_data), v4_depth);
	break; }
	case s589_NodeKind_VarDecl: {
	s913_debug_var_decl(v1_sb, v2_nodes, true, ((s924_VarDeclaration *)v6_data), v4_depth);
	break; }
	case s589_NodeKind_Break: {
		#line 154
		s288_repeat(v1_sb, "  ", v4_depth);
		#line 155
		s283_append(v1_sb, "BREAK;\n");
	break; }
	case s589_NodeKind_Continue: {
		#line 158
		s288_repeat(v1_sb, "  ", v4_depth);
		#line 159
		s283_append(v1_sb, "CONTINUE;\n");
	break; }
	case s589_NodeKind_Return: {
	s916_debug_return(v1_sb, v2_nodes, ((s925_ReturnData *)v6_data), v4_depth);
	break; }
	case s589_NodeKind_If: {
	s915_debug_if(v1_sb, v2_nodes, ((s922_IfData *)v6_data), v4_depth);
	break; }
	case s589_NodeKind_Match: {
	s919_debug_match(v1_sb, v2_nodes, ((s926_MatchData *)v6_data), v4_depth);
	break; }
	case s589_NodeKind_Loop: {
	s917_debug_loop(v1_sb, v2_nodes, ((s921_LoopData *)v6_data), v4_depth);
	break; }
	case s589_NodeKind_For: {
	s918_debug_for(v1_sb, v2_nodes, ((s920_ForData * *)v6_data), v4_depth);
	break; }
	default:
		abort();
}
}


#line 12 "src/utils/stringview.ib"
s603_StringView s590_new(char * v1_string, i64 v2_length) {
	#line 14
	return ((s603_StringView){
		.string = v1_string,
		.length = v2_length
	});
}


#line 18 "src/utils/stringview.ib"
char s591_at(s603_StringView v1_sv, i64 v2_offset) {
	#line 19
	if ((v2_offset >= (v1_sv.length))) {
		#line 19
		return 0u;
	}
	#line 20
	return ((v1_sv.string)[v2_offset]);
}


#line 24 "src/utils/stringview.ib"
bool s592_eq_str(s603_StringView v1_sv, char * v2_s) {
	#line 25
	for (i64 v3_i = 0l;(v3_i < (v1_sv.length));v3_i += 1l) {
		#line 26
		if ((s591_at(v1_sv, v3_i) != (v2_s[v3_i]))) {
			#line 26
			return false;
		}
		#line 27
		if (((v2_s[v3_i]) == 0u)) {
			#line 27
			return false;
		}
	}
	loop_exit_1:
	#line 29
	return ((v2_s[(v1_sv.length)]) == 0u);
}


#line 33 "src/utils/stringview.ib"
bool s593_eq(s603_StringView v1_lhs, s603_StringView v2_rhs) {
	#line 34
	if (((v1_lhs.length) != (v2_rhs.length))) {
		#line 34
		return false;
	}
	#line 36
	for (i64 v3_i = 0l;(v3_i < (v1_lhs.length));v3_i += 1l) {
		#line 37
		if ((s591_at(v1_lhs, v3_i) != s591_at(v2_rhs, v3_i))) {
			#line 37
			return false;
		}
	}
	loop_exit_1:
	#line 39
	return true;
}


#line 43 "src/utils/stringview.ib"
s603_StringView s594_slice(s603_StringView v1_sv, i64 v2_start, i64 v3_end) {
	#line 44
	u64 v4_actual_len = strlen((v1_sv.string));
	#line 45
	s40_assert((v2_start >= 0l), "stringview::slice start was negative");
	#line 46
	s40_assert((v3_end <= ((i64)v4_actual_len)), "stringview::slice end was larger than len");
	#line 47
	s40_assert((v2_start < v3_end), "stringview::slice start was greater than end");
	#line 48
	if ((v3_end > (v1_sv.length))) {
		#line 48
		v3_end = (v1_sv.length);
	}
	#line 50
	return ((s603_StringView){
		.string = (&((v1_sv.string)[v2_start])),
		.length = (v3_end - v2_start)
	});
}


#line 57 "src/utils/stringview.ib"
s603_StringView s595_drop_left(s603_StringView v1_sv, i64 v2_left) {
	#line 58
	if ((v2_left > (v1_sv.length))) {
		#line 58
		v2_left = (v1_sv.length);
	}
	#line 59
	return ((s603_StringView){
		.string = (&((v1_sv.string)[v2_left])),
		.length = ((v1_sv.length) - v2_left)
	});
}


#line 66 "src/utils/stringview.ib"
void s596_print(s603_StringView v1_sv) {
	#line 67
	printf("%.*s", (v1_sv.length), (v1_sv.string));
}


#line 71 "src/utils/stringview.ib"
void s597_debug(s603_StringView v1_sv) {
	#line 73
	printf("SV(%d , \"%.*s\")", (v1_sv.length), (v1_sv.length), (v1_sv.string));
}


#line 77 "src/utils/stringview.ib"
bool s598_is_empty(s603_StringView v1_sv) {
	#line 78
	return ((v1_sv.length) == 0l);
}


#line 83 "src/utils/stringview.ib"
i64 s599_find(s603_StringView v1_sv, char v2_c) {
	#line 84
	for (i64 v3_i = 0l;(v3_i < (v1_sv.length));v3_i += 1l) {
		#line 85
		if ((s591_at(v1_sv, v3_i) == v2_c)) {
			#line 85
			return v3_i;
		}
	}
	loop_exit_1:
	#line 87
	return (-1l);
}


#line 91 "src/utils/stringview.ib"
i64 s600_rfind(s603_StringView v1_sv, char v2_c) {
	#line 92
	for (i64 v3_i = ((v1_sv.length) - 1l);(v3_i >= 0l);v3_i -= 1l) {
		#line 93
		if ((s591_at(v1_sv, v3_i) == v2_c)) {
			#line 93
			return v3_i;
		}
	}
	loop_exit_1:
	#line 95
	return (-1l);
}


#line 99 "src/utils/stringview.ib"
s603_StringView s601_from_str(char * v1_string) {
	#line 101
	return ((s603_StringView){
		.string = v1_string,
		.length = ((i64)strlen(v1_string))
	});
}


#line 106 "src/utils/stringview.ib"
char * s602_to_str(s603_StringView v1_sv) {
	#line 107
	char * v2_string = ((char *)malloc((1ul * ((u64)((v1_sv.length) + 1l)))));
	#line 108
	memcpy(((void *)v2_string), ((void *)(v1_sv.string)), (1ul * ((u64)(v1_sv.length))));
	#line 109
	(v2_string[(v1_sv.length)]) = 0u;
	#line 110
	return v2_string;
}


#line 76 "src/lexer/token.ib"
s614_Token s604_new(s616_TokenKind v1_kind) {
	#line 77
	return ((s614_Token){
		.kind = v1_kind,
		.span = 0l,
		.data = ((s615_TokenData){
			.number = 0l
		})
	});
}


#line 84 "src/lexer/token.ib"
bool s605_is_eof(s614_Token * v1_token) {
	#line 85
	return (((*v1_token).kind) == s616_TokenKind_EOF);
}


#line 88 "src/lexer/token.ib"
s614_Token s606_identifier(char * v1_value) {
	#line 89
	return ((s614_Token){
		.kind = s616_TokenKind_Ident,
		.span = 0l,
		.data = ((s615_TokenData){
			.ident = v1_value
		})
	});
}


#line 96 "src/lexer/token.ib"
s614_Token s607_literal_int(i64 v1_value) {
	#line 97
	return ((s614_Token){
		.kind = s616_TokenKind_LiteralInt,
		.span = 0l,
		.data = ((s615_TokenData){
			.number = v1_value
		})
	});
}


#line 104 "src/lexer/token.ib"
s614_Token s608_literal_float(f64 v1_value) {
	#line 105
	return ((s614_Token){
		.kind = s616_TokenKind_LiteralFloat,
		.span = 0l,
		.data = ((s615_TokenData){
			.flt = v1_value
		})
	});
}


#line 112 "src/lexer/token.ib"
s614_Token s609_literal_string(char * v1_s) {
	#line 113
	return ((s614_Token){
		.kind = s616_TokenKind_LiteralString,
		.span = 0l,
		.data = ((s615_TokenData){
			.string = v1_s
		})
	});
}


#line 120 "src/lexer/token.ib"
s614_Token s610_literal_char(char v1_c) {
	#line 121
	return ((s614_Token){
		.kind = s616_TokenKind_LiteralChar,
		.span = 0l,
		.data = ((s615_TokenData){
			.chr = v1_c
		})
	});
}


#line 128 "src/lexer/token.ib"
void s611_print(s614_Token v1_token) {
	#line 129
	s299_StringBuilder v2_sb = s277_new();
	#line 130
	s613_write((&v2_sb), v1_token);
	#line 131
	printf("TokenKind::%s", s294_merge((&v2_sb)));
	#line 132
	s278_free((&v2_sb));
}


#line 135 "src/lexer/token.ib"
void s612_fprintf(void * v1_stream, s614_Token v2_token) {
	#line 136
	s299_StringBuilder v3_sb = s277_new();
	#line 137
	s613_write((&v3_sb), v2_token);
	#line 138
	fprintf(v1_stream, "TokenKind::%s", s294_merge((&v3_sb)));
	#line 139
	s278_free((&v3_sb));
}


#line 144 "src/lexer/token.ib"
void s613_write(s299_StringBuilder * v1_sb, s614_Token v2_token) {
	#line 145
	switch ((v2_token.kind)) {
	case s616_TokenKind_None: {
	s283_append(v1_sb, "None");
	break; }
	case s616_TokenKind_ParenL: {
	s283_append(v1_sb, "ParenL");
	break; }
	case s616_TokenKind_ParenR: {
	s283_append(v1_sb, "ParenR");
	break; }
	case s616_TokenKind_BraceL: {
	s283_append(v1_sb, "BraceL");
	break; }
	case s616_TokenKind_BraceR: {
	s283_append(v1_sb, "BraceR");
	break; }
	case s616_TokenKind_BracketL: {
	s283_append(v1_sb, "BracketL");
	break; }
	case s616_TokenKind_BracketR: {
	s283_append(v1_sb, "BracketR");
	break; }
	case s616_TokenKind_Comma: {
	s283_append(v1_sb, "Comma");
	break; }
	case s616_TokenKind_Colon: {
	s283_append(v1_sb, "Colon");
	break; }
	case s616_TokenKind_ColonColon: {
	s283_append(v1_sb, "ColonColon");
	break; }
	case s616_TokenKind_Dot: {
	s283_append(v1_sb, "Dot");
	break; }
	case s616_TokenKind_DotDotDot: {
	s283_append(v1_sb, "DotDotDot");
	break; }
	case s616_TokenKind_SemiColon: {
	s283_append(v1_sb, "SemiColon");
	break; }
	case s616_TokenKind_Minus: {
	s283_append(v1_sb, "Minus");
	break; }
	case s616_TokenKind_Plus: {
	s283_append(v1_sb, "Plus");
	break; }
	case s616_TokenKind_Percent: {
	s283_append(v1_sb, "Percent");
	break; }
	case s616_TokenKind_Slash: {
	s283_append(v1_sb, "Slash");
	break; }
	case s616_TokenKind_Star: {
	s283_append(v1_sb, "Star");
	break; }
	case s616_TokenKind_PlusEq: {
	s283_append(v1_sb, "PlusEq");
	break; }
	case s616_TokenKind_MinusEq: {
	s283_append(v1_sb, "MinusEq");
	break; }
	case s616_TokenKind_SlashEq: {
	s283_append(v1_sb, "SlashEq");
	break; }
	case s616_TokenKind_PercentEq: {
	s283_append(v1_sb, "PercentEq");
	break; }
	case s616_TokenKind_StarEq: {
	s283_append(v1_sb, "StarEq");
	break; }
	case s616_TokenKind_Tilde: {
	s283_append(v1_sb, "Tilde");
	break; }
	case s616_TokenKind_Caret: {
	s283_append(v1_sb, "Caret");
	break; }
	case s616_TokenKind_Pipe: {
	s283_append(v1_sb, "Pipe");
	break; }
	case s616_TokenKind_Amp: {
	s283_append(v1_sb, "Amp");
	break; }
	case s616_TokenKind_And: {
	s283_append(v1_sb, "And");
	break; }
	case s616_TokenKind_Or: {
	s283_append(v1_sb, "Or");
	break; }
	case s616_TokenKind_Equal: {
	s283_append(v1_sb, "Equal");
	break; }
	case s616_TokenKind_EqEq: {
	s283_append(v1_sb, "EqEq");
	break; }
	case s616_TokenKind_Bang: {
	s283_append(v1_sb, "Bang");
	break; }
	case s616_TokenKind_BangEqual: {
	s283_append(v1_sb, "BangEqual");
	break; }
	case s616_TokenKind_LiteralInt: {
		#line 184
		s283_append(v1_sb, "LiteralInt(");
		#line 185
		s289_append_number(v1_sb, ((v2_token.data).number));
		#line 186
		s283_append(v1_sb, ")");
	break; }
	case s616_TokenKind_LiteralFloat: {
		#line 189
		s283_append(v1_sb, "LiteralFloat(");
		#line 190
		s291_append_float(v1_sb, ((v2_token.data).flt), 6l);
		#line 191
		s283_append(v1_sb, ")");
	break; }
	case s616_TokenKind_LiteralString: {
		#line 194
		s283_append(v1_sb, "LiteralString(\"");
		#line 195
		s285_append_debug(v1_sb, ((v2_token.data).string));
		#line 196
		s283_append(v1_sb, "\")");
	break; }
	case s616_TokenKind_LiteralChar: {
		#line 199
		s283_append(v1_sb, "LiteralChar(");
		#line 200
		s286_append_debug_char(v1_sb, ((v2_token.data).chr));
		#line 201
		s283_append(v1_sb, ")");
	break; }
	case s616_TokenKind_Ident: {
		#line 204
		s283_append(v1_sb, "Ident(");
		#line 205
		s283_append(v1_sb, ((v2_token.data).ident));
		#line 206
		s283_append(v1_sb, ")");
	break; }
	case s616_TokenKind_LT: {
	s283_append(v1_sb, "LT");
	break; }
	case s616_TokenKind_LTLT: {
	s283_append(v1_sb, "LTLT");
	break; }
	case s616_TokenKind_LE: {
	s283_append(v1_sb, "LE");
	break; }
	case s616_TokenKind_GT: {
	s283_append(v1_sb, "GT");
	break; }
	case s616_TokenKind_GTGT: {
	s283_append(v1_sb, "GTGT");
	break; }
	case s616_TokenKind_GE: {
	s283_append(v1_sb, "GE");
	break; }
	case s616_TokenKind_FatArrow: {
	s283_append(v1_sb, "FatArrow");
	break; }
	case s616_TokenKind_Fn: {
	s283_append(v1_sb, "Fn");
	break; }
	case s616_TokenKind_Extern: {
	s283_append(v1_sb, "Extern");
	break; }
	case s616_TokenKind_Null: {
	s283_append(v1_sb, "Null");
	break; }
	case s616_TokenKind_True: {
	s283_append(v1_sb, "True");
	break; }
	case s616_TokenKind_False: {
	s283_append(v1_sb, "False");
	break; }
	case s616_TokenKind_Let: {
	s283_append(v1_sb, "Let");
	break; }
	case s616_TokenKind_Const: {
	s283_append(v1_sb, "Const");
	break; }
	case s616_TokenKind_If: {
	s283_append(v1_sb, "If");
	break; }
	case s616_TokenKind_Else: {
	s283_append(v1_sb, "Else");
	break; }
	case s616_TokenKind_While: {
	s283_append(v1_sb, "While");
	break; }
	case s616_TokenKind_Loop: {
	s283_append(v1_sb, "Loop");
	break; }
	case s616_TokenKind_For: {
	s283_append(v1_sb, "For");
	break; }
	case s616_TokenKind_Break: {
	s283_append(v1_sb, "Break");
	break; }
	case s616_TokenKind_Continue: {
	s283_append(v1_sb, "Continue");
	break; }
	case s616_TokenKind_Match: {
	s283_append(v1_sb, "Match");
	break; }
	case s616_TokenKind_Return: {
	s283_append(v1_sb, "Return");
	break; }
	case s616_TokenKind_Import: {
	s283_append(v1_sb, "Import");
	break; }
	case s616_TokenKind_Pub: {
	s283_append(v1_sb, "Pub");
	break; }
	case s616_TokenKind_SizeOf: {
	s283_append(v1_sb, "SizeOf");
	break; }
	case s616_TokenKind_As: {
	s283_append(v1_sb, "As");
	break; }
	case s616_TokenKind_Struct: {
	s283_append(v1_sb, "Struct");
	break; }
	case s616_TokenKind_Union: {
	s283_append(v1_sb, "Union");
	break; }
	case s616_TokenKind_Enum: {
	s283_append(v1_sb, "Enum");
	break; }
	case s616_TokenKind_Int: {
	s283_append(v1_sb, "int");
	break; }
	case s616_TokenKind_String: {
	s283_append(v1_sb, "string");
	break; }
	case s616_TokenKind_Char: {
	s283_append(v1_sb, "char");
	break; }
	case s616_TokenKind_Bool: {
	s283_append(v1_sb, "bool");
	break; }
	case s616_TokenKind_Float: {
	s283_append(v1_sb, "float");
	break; }
	case s616_TokenKind_Any: {
	s283_append(v1_sb, "any");
	break; }
	case s616_TokenKind_Void: {
	s283_append(v1_sb, "void");
	break; }
	case s616_TokenKind_U8: {
	s283_append(v1_sb, "u8");
	break; }
	case s616_TokenKind_U16: {
	s283_append(v1_sb, "u16");
	break; }
	case s616_TokenKind_U32: {
	s283_append(v1_sb, "u32");
	break; }
	case s616_TokenKind_U64: {
	s283_append(v1_sb, "u64");
	break; }
	case s616_TokenKind_U128: {
	s283_append(v1_sb, "u128");
	break; }
	case s616_TokenKind_I8: {
	s283_append(v1_sb, "i8");
	break; }
	case s616_TokenKind_I16: {
	s283_append(v1_sb, "i16");
	break; }
	case s616_TokenKind_I32: {
	s283_append(v1_sb, "i32");
	break; }
	case s616_TokenKind_I64: {
	s283_append(v1_sb, "i64");
	break; }
	case s616_TokenKind_I128: {
	s283_append(v1_sb, "i128");
	break; }
	case s616_TokenKind_F32: {
	s283_append(v1_sb, "f32");
	break; }
	case s616_TokenKind_F64: {
	s283_append(v1_sb, "f64");
	break; }
	case s616_TokenKind_EOF: {
	s283_append(v1_sb, "EOF");
	break; }
	default:
		abort();
}
}


#line 33 "src/lexer/lexer.ib"
s647_Lexer s617_new(char * v1_content, i64 v2_length, s401_Errors * v3_errors, s257_Vec * v4_line_starts) {
	#line 34
	return ((s647_Lexer){
		.content = v1_content,
		.length = v2_length,
		.file = ((char *)NULL),
		.current = 0l,
		.line = 0l,
		.column = 1l,
		.start = 0l,
		.line_start = 0l,
		.line_starts = v4_line_starts,
		.errors = v3_errors
	});
}


#line 48 "src/lexer/lexer.ib"
s648_LexerResult s618_next(s647_Lexer * v1_lexer) {
	#line 49
	s648_LexerResult v2_result = s619__next(v1_lexer);
	#line 50
	if ((!(v2_result.is_ok))) {
		#line 50
		return v2_result;
	}
	#line 51
	((v2_result.token).span) = s148_new(((*v1_lexer).file), ((*v1_lexer).start), ((*v1_lexer).current));
	#line 52
	return v2_result;
}


#line 55 "src/lexer/lexer.ib"
s648_LexerResult s619__next(s647_Lexer * v1_lexer) {
	#line 56
	if (s631_is_end(v1_lexer)) {
		#line 56
		return s639_ok(s604_new(s616_TokenKind_EOF));
	}
	#line 57
	s636_comment(v1_lexer);
	#line 58
	s635_whitespace(v1_lexer);
	#line 60
	((*v1_lexer).start) = ((*v1_lexer).current);
	#line 62
	char v2_c = s633_curr(v1_lexer);
	#line 63
	switch (v2_c) {
	case 0u: {
	return s630_simple(v1_lexer, s616_TokenKind_EOF);
	break; }
	case 40u: {
	return s630_simple(v1_lexer, s616_TokenKind_ParenL);
	break; }
	case 41u: {
	return s630_simple(v1_lexer, s616_TokenKind_ParenR);
	break; }
	case 123u: {
	return s630_simple(v1_lexer, s616_TokenKind_BraceL);
	break; }
	case 125u: {
	return s630_simple(v1_lexer, s616_TokenKind_BraceR);
	break; }
	case 91u: {
	return s630_simple(v1_lexer, s616_TokenKind_BracketL);
	break; }
	case 93u: {
	return s630_simple(v1_lexer, s616_TokenKind_BracketR);
	break; }
	case 44u: {
	return s630_simple(v1_lexer, s616_TokenKind_Comma);
	break; }
	case 46u: {
		#line 73
		if (((s634_peek(v1_lexer, 1l) == 46u) && (s634_peek(v1_lexer, 2l) == 46u))) {
			#line 74
			s632_step(v1_lexer);
			#line 74
			s632_step(v1_lexer);
			#line 75
			return s630_simple(v1_lexer, s616_TokenKind_DotDotDot);
		}
		#line 77
		return s630_simple(v1_lexer, s616_TokenKind_Dot);
	break; }
	case 62u: {
		#line 80
		s632_step(v1_lexer);
		#line 81
		switch (s633_curr(v1_lexer)) {
		case 61u: {
		return s630_simple(v1_lexer, s616_TokenKind_GE);
		break; }
		case 62u: {
		return s630_simple(v1_lexer, s616_TokenKind_GTGT);
		break; }
		default:
 {
		return s639_ok(s604_new(s616_TokenKind_GT));
		break; }
}
	break; }
	case 60u: {
		#line 88
		s632_step(v1_lexer);
		#line 89
		switch (s633_curr(v1_lexer)) {
		case 61u: {
		return s630_simple(v1_lexer, s616_TokenKind_LE);
		break; }
		case 60u: {
		return s630_simple(v1_lexer, s616_TokenKind_LTLT);
		break; }
		default:
 {
		return s639_ok(s604_new(s616_TokenKind_LT));
		break; }
}
	break; }
	case 61u: {
		#line 96
		s632_step(v1_lexer);
		#line 97
		switch (s633_curr(v1_lexer)) {
		case 61u: {
		return s630_simple(v1_lexer, s616_TokenKind_EqEq);
		break; }
		case 62u: {
		return s630_simple(v1_lexer, s616_TokenKind_FatArrow);
		break; }
		default:
 {
		return s639_ok(s604_new(s616_TokenKind_Equal));
		break; }
}
	break; }
	case 58u: {
	return s629_if_next(v1_lexer, 58u, s616_TokenKind_ColonColon, s616_TokenKind_Colon);
	break; }
	case 33u: {
	return s629_if_next(v1_lexer, 61u, s616_TokenKind_BangEqual, s616_TokenKind_Bang);
	break; }
	case 43u: {
	return s629_if_next(v1_lexer, 61u, s616_TokenKind_PlusEq, s616_TokenKind_Plus);
	break; }
	case 45u: {
	return s629_if_next(v1_lexer, 61u, s616_TokenKind_MinusEq, s616_TokenKind_Minus);
	break; }
	case 42u: {
	return s629_if_next(v1_lexer, 61u, s616_TokenKind_StarEq, s616_TokenKind_Star);
	break; }
	case 47u: {
	return s629_if_next(v1_lexer, 61u, s616_TokenKind_SlashEq, s616_TokenKind_Slash);
	break; }
	case 37u: {
	return s629_if_next(v1_lexer, 61u, s616_TokenKind_PercentEq, s616_TokenKind_Percent);
	break; }
	case 124u: {
	return s629_if_next(v1_lexer, 124u, s616_TokenKind_Or, s616_TokenKind_Pipe);
	break; }
	case 38u: {
	return s629_if_next(v1_lexer, 38u, s616_TokenKind_And, s616_TokenKind_Amp);
	break; }
	case 59u: {
	return s630_simple(v1_lexer, s616_TokenKind_SemiColon);
	break; }
	case 126u: {
	return s630_simple(v1_lexer, s616_TokenKind_Tilde);
	break; }
	case 94u: {
	return s630_simple(v1_lexer, s616_TokenKind_Caret);
	break; }
	case 39u: {
	return s622__char(v1_lexer);
	break; }
	case 34u: {
	return s623__string(v1_lexer);
	break; }
	default:
 {
		#line 118
		if (s643_is_numeric(v2_c)) {
			#line 118
			return s625_number(v1_lexer);
		}
		#line 119
		if ((s642_is_alpha(v2_c) || (v2_c == 95u))) {
			#line 120
			s616_TokenKind v3_k = s628_keyword(v1_lexer);
			#line 121
			if ((v3_k != s616_TokenKind_None)) {
				#line 122
				return s639_ok(s604_new(v3_k));
			} else {
#line 124
				return s620_identifier(v1_lexer);
			}
		}
		#line 127
		return s640_err(v1_lexer, s228_ErrorKind_UnexpectedToken);
	break; }
}
}


#line 132 "src/lexer/lexer.ib"
s648_LexerResult s620_identifier(s647_Lexer * v1_lexer) {
	#line 133
	i64 v2_len = 0l;
	#line 134
	char * v3_ident = (&(((*v1_lexer).content)[((*v1_lexer).current)]));
	#line 135
	while (s641_is_valid_ident_char(s633_curr(v1_lexer))) {
		#line 136
		s632_step(v1_lexer);
		#line 137
		v2_len += 1l;
}
	loop_exit_1:
	#line 139
	char * v4_ident = s134_insert(v3_ident, v2_len);
	#line 140
	return s639_ok(s606_identifier(v4_ident));
}


#line 143 "src/lexer/lexer.ib"
bool s621_consume(s647_Lexer * v1_lexer, char v2_c) {
	#line 144
	char v3_next = s633_curr(v1_lexer);
	#line 145
	if ((v3_next == v2_c)) {
		#line 146
		s632_step(v1_lexer);
		#line 147
		return true;
	} else {
#line 149
		return false;
	}
}


#line 153 "src/lexer/lexer.ib"
s648_LexerResult s622__char(s647_Lexer * v1_lexer) {
	#line 154
	s632_step(v1_lexer);
	#line 155
	char v2_c = s633_curr(v1_lexer);
	#line 157
	if ((v2_c == 39u)) {
		#line 158
		return s640_err(v1_lexer, s228_ErrorKind_EmptyCharLiteral);
	}
	#line 160
	s649_EscapeResult v3_res = s624_escape_char_step(v1_lexer);
	#line 161
	if ((!(v3_res.is_ok))) {
		#line 162
		return ((s648_LexerResult){
			.is_ok = false,
			.token = s604_new(s616_TokenKind_None)
		});
	}
	#line 168
	if ((!s621_consume(v1_lexer, 39u))) {
		#line 169
		return s640_err(v1_lexer, s228_ErrorKind_UnterminatedChar);
	}
	#line 172
	return s639_ok(s610_literal_char((v3_res.c)));
}


#line 175 "src/lexer/lexer.ib"
s648_LexerResult s623__string(s647_Lexer * v1_lexer) {
	#line 176
	s632_step(v1_lexer);
	#line 177
	i64 v2_len = 0l;
	#line 178
	i64 v3_start = ((*v1_lexer).current);
	#line 179
	while (((!s631_is_end(v1_lexer)) && (s633_curr(v1_lexer) != 34u))) {
		#line 180
		s649_EscapeResult v4_res = s624_escape_char_step(v1_lexer);
		#line 181
		if ((!(v4_res.is_ok))) {
			#line 182
			return ((s648_LexerResult){
				.is_ok = false,
				.token = s604_new(s616_TokenKind_None)
			});
		}
		#line 187
		v2_len += 1l;
}
	loop_exit_1:
	#line 189
	if (s631_is_end(v1_lexer)) {
		#line 190
		((*v1_lexer).current) = v3_start;
		#line 191
		return s640_err(v1_lexer, s228_ErrorKind_UnterminatedString);
	}
	#line 193
	char * v5_s = s125_reserve(v2_len);
	#line 194
	((*v1_lexer).current) = v3_start;
	#line 195
	i64 v6_i = 0l;
	#line 196
	while (((!s631_is_end(v1_lexer)) && (s633_curr(v1_lexer) != 34u))) {
		#line 197
		s649_EscapeResult v7_res = s624_escape_char_step(v1_lexer);
		#line 198
		s40_assert((v7_res.is_ok), "Char should have been validated before!");
		#line 199
		(v5_s[v6_i]) = (v7_res.c);
		#line 200
		v6_i += 1l;
}
	loop_exit_2:
	#line 202
	if ((!s621_consume(v1_lexer, 34u))) {
		#line 203
		return s640_err(v1_lexer, s228_ErrorKind_UnterminatedString);
	}
	#line 205
	return s639_ok(s609_literal_string(v5_s));
}


#line 214 "src/lexer/lexer.ib"
s649_EscapeResult s624_escape_char_step(s647_Lexer * v1_lexer) {
	#line 215
	char v2_c = s633_curr(v1_lexer);
	#line 216
	s649_EscapeResult v3_result = ((s649_EscapeResult){
		.is_ok = true,
		.c = v2_c
	});
	#line 217
	if ((v2_c != 92u)) {
		#line 219
		s632_step(v1_lexer);
		#line 220
		return v3_result;
	}
	#line 222
	s632_step(v1_lexer);
	#line 223
	switch (s633_curr(v1_lexer)) {
	case 110u: {
	(v3_result.c) = 10u;
	break; }
	case 116u: {
	(v3_result.c) = 9u;
	break; }
	case 114u: {
	(v3_result.c) = 13u;
	break; }
	case 48u: {
	(v3_result.c) = 0u;
	break; }
	case 39u: {
	(v3_result.c) = 39u;
	break; }
	case 34u: {
	(v3_result.c) = 34u;
	break; }
	case 92u: {
	(v3_result.c) = 92u;
	break; }
	case 120u: {
		#line 232
		bool v4_is_valid_hexa = (s644_is_hexa(s634_peek(v1_lexer, 1l)) && s644_is_hexa(s634_peek(v1_lexer, 2l)));
		#line 233
		if (v4_is_valid_hexa) {
			#line 234
			i64 v5_hexa_char = ((s645_to_hexa(s634_peek(v1_lexer, 1l)) * 16l) + s645_to_hexa(s634_peek(v1_lexer, 2l)));
			#line 235
			(v3_result.c) = ((char)v5_hexa_char);
			#line 237
			s632_step(v1_lexer);
			#line 238
			s632_step(v1_lexer);
		} else {
#line 240
			s640_err(v1_lexer, s228_ErrorKind_InvalidHexaEscape);
			#line 241
			(v3_result.is_ok) = false;
		}
	break; }
	default:
 {
		#line 245
		s640_err(v1_lexer, s228_ErrorKind_UnknownCharacterEscape);
		#line 246
		(v3_result.is_ok) = false;
	break; }
}
	#line 249
	s632_step(v1_lexer);
	#line 250
	return v3_result;
}


#line 253 "src/lexer/lexer.ib"
s648_LexerResult s625_number(s647_Lexer * v1_lexer) {
	#line 254
	i64 v2_whole = s626_number_part(v1_lexer);
	#line 255
	if ((s633_curr(v1_lexer) != 46u)) {
		#line 256
		return s639_ok(s607_literal_int(v2_whole));
	}
	#line 258
	s632_step(v1_lexer);
	#line 259
	f64 v3_div = ((f64)1l);
	#line 260
	f64 v4_fraction = ((f64)0l);
	#line 261
	while (s643_is_numeric(s633_curr(v1_lexer))) {
		#line 262
		v3_div *= ((f64)10l);
		#line 263
		v4_fraction *= ((f64)10l);
		#line 264
		v4_fraction += ((f64)(s633_curr(v1_lexer) - 48u));
		#line 265
		s632_step(v1_lexer);
}
	loop_exit_1:
	#line 267
	if ((s633_curr(v1_lexer) == 46u)) {
		#line 268
		return s640_err(v1_lexer, s228_ErrorKind_NumberMultipleFractionPart);
	}
	#line 270
	f64 v5_f = (((f64)v2_whole) + (v4_fraction / v3_div));
	#line 271
	return s639_ok(s608_literal_float(v5_f));
}


#line 274 "src/lexer/lexer.ib"
i64 s626_number_part(s647_Lexer * v1_lexer) {
	#line 275
	i64 v2_num = 0l;
	#line 276
	while (s643_is_numeric(s633_curr(v1_lexer))) {
		#line 277
		v2_num *= 10l;
		#line 278
		v2_num += ((i64)(s633_curr(v1_lexer) - 48u));
		#line 279
		s632_step(v1_lexer);
}
	loop_exit_1:
	#line 281
	return v2_num;
}


#line 285 "src/lexer/lexer.ib"
bool s627_match_str(s647_Lexer * v1_lexer, char * v2_rest) {
	#line 286
	i64 v3_i = 0l;
	#line 287
	while (((v2_rest[v3_i]) != 0u)) {
		#line 288
		if (((v2_rest[v3_i]) != s634_peek(v1_lexer, (v3_i + 1l)))) {
			#line 288
			return false;
		}
		#line 289
		v3_i += 1l;
}
	loop_exit_1:
	#line 291
	v3_i += 1l;
	#line 292
	if (s641_is_valid_ident_char(s634_peek(v1_lexer, v3_i))) {
		#line 293
		return false;
	}
	#line 295
	((*v1_lexer).current) += v3_i;
	#line 296
	((*v1_lexer).column) += v3_i;
	#line 297
	return true;
}


#line 300 "src/lexer/lexer.ib"
s616_TokenKind s628_keyword(s647_Lexer * v1_lexer) {
	#line 301
	switch (s633_curr(v1_lexer)) {
	case 108u: {
		#line 303
		if (s627_match_str(v1_lexer, "et")) {
			#line 303
			return s616_TokenKind_Let;
		}
		#line 304
		if (s627_match_str(v1_lexer, "oop")) {
			#line 304
			return s616_TokenKind_Loop;
		}
	break; }
	case 116u: {
		#line 306
		if (s627_match_str(v1_lexer, "rue")) {
			#line 306
			return s616_TokenKind_True;
		}
	break; }
	case 110u: {
		#line 307
		if (s627_match_str(v1_lexer, "ull")) {
			#line 307
			return s616_TokenKind_Null;
		}
	break; }
	case 105u: {
		#line 309
		if (s627_match_str(v1_lexer, "f")) {
			#line 309
			return s616_TokenKind_If;
		}
		#line 310
		if (s627_match_str(v1_lexer, "mport")) {
			#line 310
			return s616_TokenKind_Import;
		}
		#line 311
		if (s627_match_str(v1_lexer, "nt")) {
			#line 311
			return s616_TokenKind_Int;
		}
		#line 312
		if (s627_match_str(v1_lexer, "8")) {
			#line 312
			return s616_TokenKind_I8;
		}
		#line 313
		if (s627_match_str(v1_lexer, "16")) {
			#line 313
			return s616_TokenKind_I16;
		}
		#line 314
		if (s627_match_str(v1_lexer, "32")) {
			#line 314
			return s616_TokenKind_I32;
		}
		#line 315
		if (s627_match_str(v1_lexer, "64")) {
			#line 315
			return s616_TokenKind_I64;
		}
		#line 316
		if (s627_match_str(v1_lexer, "128")) {
			#line 316
			return s616_TokenKind_I128;
		}
	break; }
	case 119u: {
		#line 318
		if (s627_match_str(v1_lexer, "hile")) {
			#line 318
			return s616_TokenKind_While;
		}
	break; }
	case 109u: {
		#line 319
		if (s627_match_str(v1_lexer, "atch")) {
			#line 319
			return s616_TokenKind_Match;
		}
	break; }
	case 97u: {
		#line 321
		if (s627_match_str(v1_lexer, "ny")) {
			#line 321
			return s616_TokenKind_Any;
		}
		#line 322
		if (s627_match_str(v1_lexer, "s")) {
			#line 322
			return s616_TokenKind_As;
		}
	break; }
	case 114u: {
		#line 324
		if (s627_match_str(v1_lexer, "eturn")) {
			#line 324
			return s616_TokenKind_Return;
		}
	break; }
	case 99u: {
		#line 326
		if (s627_match_str(v1_lexer, "ontinue")) {
			#line 326
			return s616_TokenKind_Continue;
		}
		#line 327
		if (s627_match_str(v1_lexer, "har")) {
			#line 327
			return s616_TokenKind_Char;
		}
		#line 328
		if (s627_match_str(v1_lexer, "onst")) {
			#line 328
			return s616_TokenKind_Const;
		}
	break; }
	case 112u: {
		#line 330
		if (s627_match_str(v1_lexer, "ub")) {
			#line 330
			return s616_TokenKind_Pub;
		}
	break; }
	case 101u: {
		#line 332
		if (s627_match_str(v1_lexer, "lse")) {
			#line 332
			return s616_TokenKind_Else;
		}
		#line 333
		if (s627_match_str(v1_lexer, "xtern")) {
			#line 333
			return s616_TokenKind_Extern;
		}
		#line 334
		if (s627_match_str(v1_lexer, "num")) {
			#line 334
			return s616_TokenKind_Enum;
		}
	break; }
	case 117u: {
		#line 337
		if (s627_match_str(v1_lexer, "nion")) {
			#line 337
			return s616_TokenKind_Union;
		}
		#line 338
		if (s627_match_str(v1_lexer, "8")) {
			#line 338
			return s616_TokenKind_U8;
		}
		#line 339
		if (s627_match_str(v1_lexer, "16")) {
			#line 339
			return s616_TokenKind_U16;
		}
		#line 340
		if (s627_match_str(v1_lexer, "32")) {
			#line 340
			return s616_TokenKind_U32;
		}
		#line 341
		if (s627_match_str(v1_lexer, "64")) {
			#line 341
			return s616_TokenKind_U64;
		}
		#line 342
		if (s627_match_str(v1_lexer, "128")) {
			#line 342
			return s616_TokenKind_U128;
		}
	break; }
	case 115u: {
		#line 345
		if (s627_match_str(v1_lexer, "truct")) {
			#line 345
			return s616_TokenKind_Struct;
		}
		#line 346
		if (s627_match_str(v1_lexer, "izeof")) {
			#line 346
			return s616_TokenKind_SizeOf;
		}
		#line 347
		if (s627_match_str(v1_lexer, "tr")) {
			#line 347
			return s616_TokenKind_String;
		}
	break; }
	case 98u: {
		#line 350
		if (s627_match_str(v1_lexer, "reak")) {
			#line 350
			return s616_TokenKind_Break;
		}
		#line 351
		if (s627_match_str(v1_lexer, "ool")) {
			#line 351
			return s616_TokenKind_Bool;
		}
	break; }
	case 102u: {
		#line 354
		if (s627_match_str(v1_lexer, "n")) {
			#line 354
			return s616_TokenKind_Fn;
		}
		#line 355
		if (s627_match_str(v1_lexer, "alse")) {
			#line 355
			return s616_TokenKind_False;
		}
		#line 356
		if (s627_match_str(v1_lexer, "or")) {
			#line 356
			return s616_TokenKind_For;
		}
		#line 357
		if (s627_match_str(v1_lexer, "loat")) {
			#line 357
			return s616_TokenKind_Float;
		}
		#line 358
		if (s627_match_str(v1_lexer, "32")) {
			#line 358
			return s616_TokenKind_F32;
		}
		#line 359
		if (s627_match_str(v1_lexer, "64")) {
			#line 359
			return s616_TokenKind_F64;
		}
	break; }
	case 118u: {
		#line 361
		if (s627_match_str(v1_lexer, "oid")) {
			#line 361
			return s616_TokenKind_Void;
		}
	break; }
	default:
 {
	break; }
}
	#line 364
	return s616_TokenKind_None;
}


#line 367 "src/lexer/lexer.ib"
s648_LexerResult s629_if_next(s647_Lexer * v1_lexer, char v2_next, s616_TokenKind v3_if_true, s616_TokenKind v4_if_false) {
	#line 373
	s632_step(v1_lexer);
	#line 374
	if ((s633_curr(v1_lexer) == v2_next)) {
		#line 375
		s632_step(v1_lexer);
		#line 376
		return s639_ok(s604_new(v3_if_true));
	} else {
#line 378
		return s639_ok(s604_new(v4_if_false));
	}
}


#line 382 "src/lexer/lexer.ib"
s648_LexerResult s630_simple(s647_Lexer * v1_lexer, s616_TokenKind v2_kind) {
	#line 383
	s632_step(v1_lexer);
	#line 384
	return s639_ok(s604_new(v2_kind));
}


#line 387 "src/lexer/lexer.ib"
bool s631_is_end(s647_Lexer * v1_lexer) {
	#line 387
	return (((*v1_lexer).current) >= ((*v1_lexer).length));
}


#line 388 "src/lexer/lexer.ib"
void s632_step(s647_Lexer * v1_lexer) {
	#line 389
	((*v1_lexer).current) += 1l;
	#line 390
	((*v1_lexer).column) += 1l;
}


#line 392 "src/lexer/lexer.ib"
char s633_curr(s647_Lexer * v1_lexer) {
	#line 392
	return s634_peek(v1_lexer, 0l);
}


#line 393 "src/lexer/lexer.ib"
char s634_peek(s647_Lexer * v1_lexer, i64 v2_offset) {
	#line 394
	if (((((*v1_lexer).current) + v2_offset) < ((*v1_lexer).length))) {
		#line 395
		return (((*v1_lexer).content)[(((*v1_lexer).current) + v2_offset)]);
	} else {
#line 397
		return 0u;
	}
}


#line 401 "src/lexer/lexer.ib"
void s635_whitespace(s647_Lexer * v1_lexer) {
	#line 402
	while (1) {
		#line 402
		switch (s633_curr(v1_lexer)) {
		case 32u:
		case 9u:
		case 13u: {
		s632_step(v1_lexer);
		break; }
		case 10u: {
		s638_next_line(v1_lexer);
		break; }
		default:
 {
		return;
		break; }
}
}
	loop_exit_1:
}


#line 409 "src/lexer/lexer.ib"
void s636_comment(s647_Lexer * v1_lexer) {
	#line 410
	while (1) {
		#line 411
		s635_whitespace(v1_lexer);
		#line 412
		if ((s633_curr(v1_lexer) != 47u)) {
			#line 412
			return;
		}
		#line 413
		switch (s634_peek(v1_lexer, 1l)) {
		case 47u: {
			#line 414
			s638_next_line(v1_lexer);
		break; }
		case 42u: {
			#line 415
			s637_block_comment(v1_lexer);
		break; }
		default:
 {
		return;
		break; }
}
}
	loop_exit_1:
}


#line 421 "src/lexer/lexer.ib"
void s637_block_comment(s647_Lexer * v1_lexer) {
	#line 422
	s632_step(v1_lexer);
	#line 423
	s632_step(v1_lexer);
	#line 424
	while (1) {
		#line 425
		if (s631_is_end(v1_lexer)) {
			#line 425
			return;
		}
		#line 426
		if (((s633_curr(v1_lexer) == 42u) && (s634_peek(v1_lexer, 1l) == 47u))) {
			#line 427
			s632_step(v1_lexer);
			#line 428
			s632_step(v1_lexer);
			#line 429
			return;
		}
		#line 431
		s632_step(v1_lexer);
}
	loop_exit_1:
}


#line 435 "src/lexer/lexer.ib"
void s638_next_line(s647_Lexer * v1_lexer) {
	#line 436
	while (1) {
		#line 436
		switch (s633_curr(v1_lexer)) {
		case 0u: {
		return;
		break; }
		case 10u: {
			#line 439
			i64 * v2_start = ((i64 *)s249_push(((*v1_lexer).line_starts)));
			#line 440
			(*v2_start) = ((*v1_lexer).line_start);
			#line 441
			s632_step(v1_lexer);
			#line 442
			((*v1_lexer).line_start) = ((*v1_lexer).current);
			#line 443
			((*v1_lexer).line) += 1l;
			#line 444
			((*v1_lexer).column) = 1l;
			#line 445
			return;
		break; }
		default:
 {
			#line 447
			s632_step(v1_lexer);
		break; }
}
}
	loop_exit_1:
}


#line 451 "src/lexer/lexer.ib"
s648_LexerResult s639_ok(s614_Token v1_token) {
	#line 452
	return ((s648_LexerResult){
		.is_ok = true,
		.token = v1_token
	});
}


#line 458 "src/lexer/lexer.ib"
s648_LexerResult s640_err(s647_Lexer * v1_lexer, s228_ErrorKind v2_kind) {
	#line 459
	s402_Error * v3_err = s389_lexer_error(((*v1_lexer).errors));
	#line 460
	((*v3_err).span) = s148_new(((*v1_lexer).file), ((*v1_lexer).start), (((*v1_lexer).current) + 1l));
	#line 462
	s227_append_message((&((*((*v1_lexer).errors)).builder)), v2_kind, s633_curr(v1_lexer));
	#line 463
	((*v3_err).message) = s293_build((&((*((*v1_lexer).errors)).builder)));
	#line 464
	s295_reset((&((*((*v1_lexer).errors)).builder)));
	#line 466
	s638_next_line(v1_lexer);
	#line 467
	return ((s648_LexerResult){
		.is_ok = false,
		.token = s604_new(s616_TokenKind_None)
	});
}


#line 473 "src/lexer/lexer.ib"
bool s641_is_valid_ident_char(char v1_c) {
	#line 474
	return (((v1_c == 95u) || s642_is_alpha(v1_c)) || s643_is_numeric(v1_c));
}


#line 476 "src/lexer/lexer.ib"
bool s642_is_alpha(char v1_c) {
	#line 477
	return (((v1_c >= 97u) && (v1_c <= 122u)) || ((v1_c >= 65u) && (v1_c <= 90u)));
}


#line 480 "src/lexer/lexer.ib"
bool s643_is_numeric(char v1_c) {
	#line 481
	return ((v1_c >= 48u) && (v1_c <= 57u));
}


#line 484 "src/lexer/lexer.ib"
bool s644_is_hexa(char v1_c) {
	#line 485
	return ((((v1_c >= 48u) && (v1_c <= 57u)) || ((v1_c >= 97u) && (v1_c <= 102u))) || ((v1_c >= 65u) && (v1_c <= 70u)));
}


#line 490 "src/lexer/lexer.ib"
i64 s645_to_hexa(char v1_c) {
	#line 491
	if (((v1_c >= 48u) && (v1_c <= 57u))) {
		#line 491
		return ((i64)(v1_c - 48u));
	}
	#line 492
	if (((v1_c >= 97u) && (v1_c <= 102u))) {
		#line 492
		return (((i64)(v1_c - 97u)) + 10l);
	}
	#line 493
	if (((v1_c >= 65u) && (v1_c <= 70u))) {
		#line 493
		return (((i64)(v1_c - 65u)) + 10l);
	}
	#line 494
	return 0l;
}


#line 499 "src/lexer/lexer.ib"
void s646_print_status(s647_Lexer * v1_l) {
	#line 500
	printf("%s:%d:%d = %d (%d : %d)", ((*v1_l).file), ((*v1_l).line), ((*v1_l).column), s633_curr(v1_l), ((*v1_l).current), ((*v1_l).length));
	#line 505
	printf("\n");
}


#line 103 "src/ast/declaration.ib"
void s650_print_declaration(s662_Declaration * v1_declaration) {
	#line 104
	s299_StringBuilder v2_sb = s277_new();
	#line 105
	s651_debug_declaration((&v2_sb), v1_declaration);
	#line 106
	puts(s294_merge((&v2_sb)));
	#line 107
	s278_free((&v2_sb));
	#line 108
	fflush(stdout);
}


#line 111 "src/ast/declaration.ib"
void s651_debug_declaration(s299_StringBuilder * v1_sb, s662_Declaration * v2_declaration) {
	#line 112
	s283_append(v1_sb, "DECL: [name=");
	#line 113
	s283_append(v1_sb, ((*v2_declaration).name));
	#line 114
	s283_append(v1_sb, ",public=");
	#line 115
	if (((*v2_declaration).is_public)) {
		#line 116
		s283_append(v1_sb, "true");
	} else {
#line 118
		s283_append(v1_sb, "false");
	}
	#line 120
	s283_append(v1_sb, ",span=");
	#line 121
	s289_append_number(v1_sb, ((*v2_declaration).span));
	#line 122
	s283_append(v1_sb, ",symboluid=");
	#line 123
	s289_append_number(v1_sb, (((*v2_declaration).symbol).symbol));
	#line 124
	s283_append(v1_sb, "]");
}


#line 127 "src/ast/declaration.ib"
void s652_debug_function(s299_StringBuilder * v1_sb, s334_Module * v2_module, s663_Function * v3_function) {
	#line 128
	if ((((*v3_function).declaration).is_public)) {
		#line 128
		s283_append(v1_sb, "PUB ");
	}
	#line 129
	s283_append(v1_sb, "FN ");
	#line 130
	s653_debug_proto(v1_sb, v2_module, (&((*v3_function).proto)));
	#line 131
	s584_debug(v1_sb, (&((*v2_module).nodes)), ((*v3_function).body), 1l);
	#line 132
	s284_append_char(v1_sb, 10u);
}


#line 135 "src/ast/declaration.ib"
void s653_debug_proto(s299_StringBuilder * v1_sb, s334_Module * v2_module, s665_Prototype * v3_proto) {
	#line 136
	s283_append(v1_sb, ((*v3_proto).identifier));
	#line 137
	for (i64 v4_i = 0l;(v4_i < ((*v3_proto).arg_count));v4_i += 1l) {
		#line 138
		s283_append(v1_sb, "\n  ");
		#line 140
		s666_Arg * v5_arg = ((s666_Arg *)s251_get((&((*v2_module).args)), (((*v3_proto).arg_index) + v4_i)));
		#line 141
		s283_append(v1_sb, ((*v5_arg).ident));
		#line 142
		s283_append(v1_sb, " : ");
		#line 143
		s210_debug(v1_sb, (&((*v2_module).nodes)), ((*v5_arg).type), 1l);
	}
	loop_exit_1:
	#line 145
	if (((*v3_proto).has_varargs)) {
		#line 146
		s283_append(v1_sb, "\n  ...");
	}
	#line 148
	s283_append(v1_sb, "\nRETURN: ");
	#line 149
	s211_debug_flowtype(v1_sb, (&((*v2_module).nodes)), (&((*v3_proto).return_type)), 1l);
	#line 150
	s284_append_char(v1_sb, 10u);
}


#line 154 "src/ast/declaration.ib"
void s654_debug_import(s299_StringBuilder * v1_sb, s334_Module * v2__module, s669_Import * v3_imp) {
	#line 155
	if ((((*v3_imp).declaration).is_public)) {
		#line 155
		s283_append(v1_sb, "PUB ");
	}
	#line 156
	s283_append(v1_sb, "IMPORT \"");
	#line 157
	s283_append(v1_sb, ((*v3_imp).path));
	#line 158
	s283_append(v1_sb, "\"");
	#line 159
	if (((((*v3_imp).declaration).name) != ((char *)NULL))) {
		#line 160
		s283_append(v1_sb, "  ALIAS:");
		#line 161
		s283_append(v1_sb, (((*v3_imp).declaration).name));
	}
	#line 163
	s283_append(v1_sb, "\n");
}


#line 166 "src/ast/declaration.ib"
void s655_debug_extern_fn(s299_StringBuilder * v1_sb, s334_Module * v2_module, s664_ExternFn * v3_extrn) {
	#line 167
	if ((((*v3_extrn).declaration).is_public)) {
		#line 167
		s283_append(v1_sb, "PUB ");
	}
	#line 168
	s283_append(v1_sb, "EXTERN_FN ");
	#line 169
	s653_debug_proto(v1_sb, v2_module, (&((*v3_extrn).proto)));
}


#line 172 "src/ast/declaration.ib"
void s656_debug_extern_global(s299_StringBuilder * v1_sb, s334_Module * v2_module, s668_ExternGlobal * v3_extrn) {
	#line 173
	if ((((*v3_extrn).declaration).is_public)) {
		#line 173
		s283_append(v1_sb, "PUB ");
	}
	#line 174
	s283_append(v1_sb, "EXTERN_GLOBAL ");
	#line 175
	s283_append(v1_sb, (((*v3_extrn).declaration).name));
	#line 176
	s283_append(v1_sb, " : ");
	#line 177
	s210_debug(v1_sb, (&((*v2_module).nodes)), ((*v3_extrn).type), 1l);
	#line 178
	s283_append(v1_sb, "\n");
}


#line 181 "src/ast/declaration.ib"
void s657_debug_global(s299_StringBuilder * v1_sb, s334_Module * v2_module, s667_Global * v3_global) {
	#line 182
	if ((((*v3_global).declaration).is_public)) {
		#line 182
		s283_append(v1_sb, "PUB ");
	}
	#line 183
	if (((*v3_global).mutable)) {
		#line 184
		s283_append(v1_sb, "VAR_DECL LET\n");
	} else {
#line 186
		s283_append(v1_sb, "VAR_DECL CONST\n");
	}
	#line 188
	s283_append(v1_sb, "  ");
	#line 189
	s283_append(v1_sb, (((*v3_global).declaration).name));
	#line 190
	s283_append(v1_sb, "\n");
	#line 191
	if ((((*v3_global).type) != ((s214_TypeIdent *)NULL))) {
		#line 192
		s283_append(v1_sb, "  TYPE: ");
		#line 193
		s210_debug(v1_sb, (&((*v2_module).nodes)), ((*v3_global).type), 1l);
		#line 194
		s283_append(v1_sb, "\n");
	} else {
#line 196
		s283_append(v1_sb, "  TYPE: NONE\n");
	}
	#line 198
	s584_debug(v1_sb, (&((*v2_module).nodes)), ((*v3_global).value), 1l);
}


#line 201 "src/ast/declaration.ib"
void s658_debug_struct(s299_StringBuilder * v1_sb, s334_Module * v2_module, s670_ObjectDef * v3_obj) {
	#line 202
	s660_debug_object_def(v1_sb, v2_module, v3_obj, "STRUCT");
}


#line 204 "src/ast/declaration.ib"
void s659_debug_union(s299_StringBuilder * v1_sb, s334_Module * v2_module, s670_ObjectDef * v3_obj) {
	#line 205
	s660_debug_object_def(v1_sb, v2_module, v3_obj, "UNION");
}


#line 208 "src/ast/declaration.ib"
void s660_debug_object_def(s299_StringBuilder * v1_sb, s334_Module * v2_module, s670_ObjectDef * v3_obj, char * v4_kind) {
	#line 209
	if ((((*v3_obj).declaration).is_public)) {
		#line 209
		s283_append(v1_sb, "PUB ");
	}
	#line 210
	s283_append(v1_sb, v4_kind);
	#line 211
	s283_append(v1_sb, " : ");
	#line 212
	s283_append(v1_sb, (((*v3_obj).declaration).name));
	#line 213
	s283_append(v1_sb, "\n");
	#line 214
	for (i64 v5_i = 0l;(v5_i < ((*v3_obj).field_count));v5_i += 1l) {
		#line 215
		s283_append(v1_sb, "  ");
		#line 216
		s283_append(v1_sb, ((((*v3_obj).fields)[v5_i]).field));
		#line 217
		s283_append(v1_sb, " : ");
		#line 218
		s210_debug(v1_sb, (&((*v2_module).nodes)), ((((*v3_obj).fields)[v5_i]).type), 2l);
		#line 219
		s283_append(v1_sb, "\n");
	}
	loop_exit_1:
}


#line 223 "src/ast/declaration.ib"
void s661_debug_enum(s299_StringBuilder * v1_sb, s334_Module * v2_module, s672_EnumDef * v3_enum_def) {
	#line 224
	if ((((*v3_enum_def).declaration).is_public)) {
		#line 224
		s283_append(v1_sb, "PUB ");
	}
	#line 225
	s283_append(v1_sb, "ENUM : ");
	#line 226
	s283_append(v1_sb, (((*v3_enum_def).declaration).name));
	#line 227
	s283_append(v1_sb, "\n");
	#line 228
	for (i64 v4_i = 0l;(v4_i < ((*v3_enum_def).field_count));v4_i += 1l) {
		#line 229
		s283_append(v1_sb, "  ");
		#line 230
		s283_append(v1_sb, ((((*v3_enum_def).fields)[v4_i]).field));
		#line 232
		i64 v5_value = ((((*v3_enum_def).fields)[v4_i]).value);
		#line 233
		if ((v5_value != s577_NONE)) {
			#line 234
			s283_append(v1_sb, " = \n");
			#line 235
			s584_debug(v1_sb, (&((*v2_module).nodes)), v5_value, 2l);
		}
		#line 237
		s283_append(v1_sb, "\n");
	}
	loop_exit_1:
}


#line 60 "src/ast/ast.ib"
s702_Ast s676_new(s308_Tokens v1_tokens, s334_Module * v2_module, s401_Errors * v3_errors) {
	#line 61
	return ((s702_Ast){
		.file = ((char *)NULL),
		.tokens = v1_tokens,
		.module = v2_module,
		.current = 0l,
		.in_condition = false,
		.is_public = false,
		.workstack = ((s712_WorkStack){

		}),
		.infix = s965_default_infix(),
		.prefix = s964_default_prefix(),
		.is_recovering_from_errors = false,
		.skip_expr_semicolon = false,
		.typeident_context = s703_TypeIdentContext_ObjectDef,
		.errors = v3_errors
	});
}


#line 77 "src/ast/ast.ib"
void s677_free(s702_Ast * v1_ast) {
	#line 78
	s711_free((&((*v1_ast).workstack)));
}


#line 82 "src/ast/ast.ib"
bool s678_has_next(s702_Ast * v1_ast) {
	#line 83
	return (s689_curr(v1_ast) != s616_TokenKind_EOF);
}


#line 86 "src/ast/ast.ib"
s704_Declaration s679_next(s702_Ast * v1_ast) {
	#line 87
	return ((s704_Declaration)s680_declaration(v1_ast));
}


#line 102 "src/ast/ast.ib"
i64 s680_declaration(s702_Ast * v1_ast) {
	#line 103
	switch (s689_curr(v1_ast)) {
	case s616_TokenKind_EOF: {
	return 0l;
	break; }
	case s616_TokenKind_Pub: {
		#line 106
		if (((*v1_ast).is_public)) {
			#line 107
			((*v1_ast).is_public) = false;
			#line 108
			return s687_error(v1_ast, s226_ErrorKind_DuplicatePubForDeclaration);
		}
		#line 110
		s688_step(v1_ast);
		#line 111
		((*v1_ast).is_public) = true;
		#line 112
		i64 v2_declaration = s680_declaration(v1_ast);
		#line 113
		((*v1_ast).is_public) = false;
		#line 114
		return v2_declaration;
	break; }
	case s616_TokenKind_Fn: {
	return s936_parse(v1_ast);
	break; }
	case s616_TokenKind_Import: {
		#line 118
		if (((*v1_ast).is_public)) {
			#line 118
			return s687_error(v1_ast, s226_ErrorKind_ImportCannotBePublic);
		}
		#line 119
		return s683_parse_import(v1_ast, false);
	break; }
	case s616_TokenKind_Extern: {
	return s682_parse_extern(v1_ast);
	break; }
	case s616_TokenKind_Struct: {
	return s930_parse_struct(v1_ast);
	break; }
	case s616_TokenKind_Union: {
	return s931_parse_union(v1_ast);
	break; }
	case s616_TokenKind_Enum: {
	return s928_parse_enum(v1_ast);
	break; }
	case s616_TokenKind_Let: {
	return s684_parse_global(v1_ast, true);
	break; }
	case s616_TokenKind_Const: {
	return s685_parse_global_const(v1_ast);
	break; }
	default:
 {
		#line 128
		return s687_error(v1_ast, s226_ErrorKind_UnknownDeclaration);
	break; }
}
}


#line 133 "src/ast/ast.ib"
bool s681_curr_is_declaration(s702_Ast * v1_ast) {
	#line 134
	switch (s689_curr(v1_ast)) {
	case s616_TokenKind_EOF:
	case s616_TokenKind_Import:
	case s616_TokenKind_Fn:
	case s616_TokenKind_Extern:
	case s616_TokenKind_Struct:
	case s616_TokenKind_Union:
	case s616_TokenKind_Pub:
	case s616_TokenKind_Enum: {
	return true;
	break; }
	default:
 {
	return false;
	break; }
}
}


#line 148 "src/ast/ast.ib"
i64 s682_parse_extern(s702_Ast * v1_ast) {
	#line 149
	s688_step(v1_ast);
	#line 150
	switch (s690_peek(v1_ast, 1l)) {
	case s616_TokenKind_ParenL: {
		#line 152
		s664_ExternFn * v2_ext = ((s664_ExternFn *)s249_push((&((*((*v1_ast).module)).extern_fns))));
		#line 154
		if ((s937_parse_prototype(v1_ast, (&((*v2_ext).proto))) == s674_ERROR)) {
			#line 154
			return s674_ERROR;
		}
		#line 155
		((*v2_ext).declaration) = ((s662_Declaration){
			.name = (((*v2_ext).proto).identifier),
			.is_public = ((*v1_ast).is_public),
			.span = (((*v2_ext).proto).span),
			.symbol = s168_NONE
		});
		#line 162
		return ((i64)s704_Declaration_ExternFn);
	break; }
	case s616_TokenKind_Colon: {
		#line 165
		s668_ExternGlobal * v3_ext = ((s668_ExternGlobal *)s249_push((&((*((*v1_ast).module)).extern_globals))));
		#line 167
		bool v4_is_public = ((*v1_ast).is_public);
		#line 168
		i64 v5_span = s692_curr_span(v1_ast);
		#line 169
		char * v6_name = ((char *)NULL);
		#line 170
		if ((s686_consume_ident(v1_ast, (&v6_name), s226_ErrorKind_ExternGlobalNameExpected) == s674_ERROR)) {
			#line 170
			return s674_ERROR;
		}
		#line 171
		((*v3_ext).declaration) = ((s662_Declaration){
			.name = v6_name,
			.is_public = v4_is_public,
			.span = v5_span,
			.symbol = s168_NONE
		});
		#line 176
		if ((!s694_consume(v1_ast, s616_TokenKind_Colon))) {
			#line 177
			return s687_error(v1_ast, s226_ErrorKind_TypeIdentExpected);
		}
		#line 179
		((*v1_ast).typeident_context) = s703_TypeIdentContext_VarDeclaration;
		#line 180
		s959_TypeIdentResult v7_ty_res = s951_parse(v1_ast);
		#line 181
		if ((!(v7_ty_res.success))) {
			#line 181
			return s674_ERROR;
		}
		#line 183
		((*v3_ext).type) = (v7_ty_res.type);
		#line 184
		((*v3_ext).type_span) = (v7_ty_res.span);
		#line 186
		if ((!s694_consume(v1_ast, s616_TokenKind_SemiColon))) {
			#line 187
			return s687_error(v1_ast, s226_ErrorKind_SemicolonExpected);
		}
		#line 190
		return ((i64)s704_Declaration_ExternGlobal);
	break; }
	default:
 {
		#line 193
		return s687_error(v1_ast, s226_ErrorKind_InvalidExtern);
	break; }
}
}


#line 199 "src/ast/ast.ib"
i64 s683_parse_import(s702_Ast * v1_ast, bool v2_aliased) {
	#line 200
	s669_Import * v3_imp = ((s669_Import *)s249_push((&((*((*v1_ast).module)).imports))));
	#line 201
	((*v3_imp).declaration) = ((s662_Declaration){
		.name = ((char *)NULL),
		.span = 0l,
		.is_public = ((*v1_ast).is_public),
		.symbol = s168_NONE
	});
	#line 206
	if (v2_aliased) {
		#line 207
		s688_step(v1_ast);
		#line 208
		(((*v3_imp).declaration).span) = s692_curr_span(v1_ast);
		#line 209
		if ((s686_consume_ident(v1_ast, (&(((*v3_imp).declaration).name)), s226_ErrorKind_ImportAliasExpected) == s674_ERROR)) {
			#line 210
			return s674_ERROR;
		}
		#line 212
		if ((!s694_consume(v1_ast, s616_TokenKind_Equal))) {
			#line 213
			return s687_error(v1_ast, s226_ErrorKind_ImportAliasEqExpected);
		}
	}
	#line 216
	s688_step(v1_ast);
	#line 218
	if ((s689_curr(v1_ast) == s616_TokenKind_LiteralString)) {
		#line 219
		s614_Token * v4_token = s695_curr_token(v1_ast);
		#line 220
		((*v3_imp).path) = (((*v4_token).data).string);
		#line 221
		((*v3_imp).path_span) = s692_curr_span(v1_ast);
		#line 222
		s688_step(v1_ast);
	} else {
#line 224
		return s687_error(v1_ast, s226_ErrorKind_ImportPathExpected);
	}
	#line 226
	return ((i64)s704_Declaration_Import);
}


#line 229 "src/ast/ast.ib"
i64 s684_parse_global(s702_Ast * v1_ast, bool v2_mutable) {
	#line 230
	s688_step(v1_ast);
	#line 231
	s667_Global * v3_global = ((s667_Global *)s249_push((&((*((*v1_ast).module)).globals))));
	#line 233
	((*v3_global).mutable) = v2_mutable;
	#line 234
	((*v3_global).type) = ((s214_TypeIdent *)NULL);
	#line 236
	bool v4_is_public = ((*v1_ast).is_public);
	#line 237
	i64 v5_span = s692_curr_span(v1_ast);
	#line 238
	char * v6_name = ((char *)NULL);
	#line 239
	if ((s686_consume_ident(v1_ast, (&v6_name), s226_ErrorKind_GlobalNameExpected) == s674_ERROR)) {
		#line 239
		return s674_ERROR;
	}
	#line 240
	((*v3_global).declaration) = ((s662_Declaration){
		.name = v6_name,
		.is_public = v4_is_public,
		.span = v5_span,
		.symbol = s168_NONE
	});
	#line 245
	if ((s689_curr(v1_ast) == s616_TokenKind_Colon)) {
		#line 246
		s688_step(v1_ast);
		#line 247
		s959_TypeIdentResult v7_res = s951_parse(v1_ast);
		#line 248
		if ((!(v7_res.success))) {
			#line 248
			return s674_ERROR;
		}
		#line 249
		((*v3_global).type) = (v7_res.type);
		#line 250
		((*v3_global).type_span) = (v7_res.span);
	}
	#line 253
	if ((!s694_consume(v1_ast, s616_TokenKind_Equal))) {
		#line 254
		return s687_error(v1_ast, s226_ErrorKind_VarDeclEqExpected);
	}
	#line 257
	((*v3_global).value) = s867_parse(v1_ast);
	#line 258
	if ((((*v3_global).value) == s674_ERROR)) {
		#line 258
		return s674_ERROR;
	}
	#line 260
	if ((!s694_consume(v1_ast, s616_TokenKind_SemiColon))) {
		#line 261
		return s687_error(v1_ast, s226_ErrorKind_SemicolonExpected);
	}
	#line 264
	return ((i64)s704_Declaration_Global);
}


#line 268 "src/ast/ast.ib"
i64 s685_parse_global_const(s702_Ast * v1_ast) {
	#line 269
	if ((s690_peek(v1_ast, 3l) == s616_TokenKind_Import)) {
		#line 270
		return s683_parse_import(v1_ast, true);
	} else {
#line 272
		return s684_parse_global(v1_ast, false);
	}
}


#line 277 "src/ast/ast.ib"
i64 s686_consume_ident(s702_Ast * v1_ast, char * * v2_result, s226_ErrorKind v3_kind) {
	#line 278
	if ((s689_curr(v1_ast) != s616_TokenKind_Ident)) {
		#line 279
		return s687_error(v1_ast, v3_kind);
	}
	#line 281
	s614_Token * v4_token = s695_curr_token(v1_ast);
	#line 282
	(*v2_result) = (((*v4_token).data).ident);
	#line 283
	s688_step(v1_ast);
	#line 284
	return s675_SUCCESS;
}


#line 291 "src/ast/ast.ib"
i64 s687_error(s702_Ast * v1_ast, s226_ErrorKind v2_kind) {
	#line 293
	s402_Error * v3_err = s390_parser_error(((*v1_ast).errors));
	#line 295
	i64 v4_token_offset = s224_token_offset(v2_kind);
	#line 296
	((*v3_err).span) = (((((*v1_ast).tokens).items)[(((*v1_ast).current) + v4_token_offset)]).span);
	#line 297
	(((*v3_err).span_options).range) = s225_span_range(v2_kind);
	#line 299
	s223_append_message((&((*((*v1_ast).errors)).builder)), v2_kind);
	#line 300
	((*v3_err).message) = s293_build((&((*((*v1_ast).errors)).builder)));
	#line 301
	s295_reset((&((*((*v1_ast).errors)).builder)));
	#line 303
	s939_recover_from_error(v1_ast, v2_kind);
	#line 307
	return s674_ERROR;
}


#line 311 "src/ast/ast.ib"
void s688_step(s702_Ast * v1_ast) {
	#line 311
	((*v1_ast).current) += 1l;
}


#line 314 "src/ast/ast.ib"
s616_TokenKind s689_curr(s702_Ast * v1_ast) {
	#line 315
	if ((((*v1_ast).current) >= (((*v1_ast).tokens).count))) {
		#line 315
		return s616_TokenKind_EOF;
	}
	#line 316
	return (((((*v1_ast).tokens).items)[((*v1_ast).current)]).kind);
}


#line 320 "src/ast/ast.ib"
s616_TokenKind s690_peek(s702_Ast * v1_ast, i64 v2_offset) {
	#line 321
	if (((((*v1_ast).current) + v2_offset) >= (((*v1_ast).tokens).count))) {
		#line 322
		return s616_TokenKind_EOF;
	}
	#line 324
	return (((((*v1_ast).tokens).items)[(((*v1_ast).current) + v2_offset)]).kind);
}


#line 328 "src/ast/ast.ib"
i64 s691_span_end(s702_Ast * v1_ast, i64 v2_span_start) {
	#line 329
	return s149_merge(v2_span_start, s693_prev_span(v1_ast));
}


#line 333 "src/ast/ast.ib"
i64 s692_curr_span(s702_Ast * v1_ast) {
	#line 334
	return (((((*v1_ast).tokens).items)[((*v1_ast).current)]).span);
}


#line 338 "src/ast/ast.ib"
i64 s693_prev_span(s702_Ast * v1_ast) {
	#line 339
	return (((((*v1_ast).tokens).items)[(((*v1_ast).current) - 1l)]).span);
}


#line 343 "src/ast/ast.ib"
bool s694_consume(s702_Ast * v1_ast, s616_TokenKind v2_kind) {
	#line 344
	if ((s689_curr(v1_ast) == v2_kind)) {
		#line 345
		s688_step(v1_ast);
		#line 346
		return true;
	} else {
#line 348
		return false;
	}
}


#line 353 "src/ast/ast.ib"
s614_Token * s695_curr_token(s702_Ast * v1_ast) {
	#line 354
	return (&((((*v1_ast).tokens).items)[((*v1_ast).current)]));
}


#line 358 "src/ast/ast.ib"
i64 s696_node_create(s702_Ast * v1_ast, s589_NodeKind v2_kind) {
	#line 359
	return s579_push((&((*((*v1_ast).module)).nodes)), v2_kind);
}


#line 363 "src/ast/ast.ib"
void * s697_node_data(s702_Ast * v1_ast, i64 v2_node) {
	#line 364
	s587_Node * v3_n = s578_get((&((*((*v1_ast).module)).nodes)), v2_node);
	#line 365
	return ((void *)(&((*v3_n).data)));
}


#line 369 "src/ast/ast.ib"
i64 s698_node_get_span(s702_Ast * v1_ast, i64 v2_node) {
	#line 370
	s587_Node * v3_n = s578_get((&((*((*v1_ast).module)).nodes)), v2_node);
	#line 371
	return ((*v3_n).span);
}


#line 375 "src/ast/ast.ib"
void s699_node_set_span(s702_Ast * v1_ast, i64 v2_node, i64 v3_span) {
	#line 376
	s587_Node * v4_n = s578_get((&((*((*v1_ast).module)).nodes)), v2_node);
	#line 377
	((*v4_n).span) = v3_span;
}


#line 381 "src/ast/ast.ib"
void s700_work_push(s702_Ast * v1_ast, i64 v2_value) {
	#line 382
	i64 * v3_v = ((i64 *)s707_push((&((*v1_ast).workstack)), ((i64)8ul)));
	#line 383
	(*v3_v) = v2_value;
}


#line 387 "src/ast/ast.ib"
i64 s701_work_pop(s702_Ast * v1_ast) {
	#line 388
	i64 * v2_v = ((i64 *)s708_pop((&((*v1_ast).workstack)), ((i64)8ul)));
	#line 389
	return (*v2_v);
}


#line 11 "src/utils/workstack.ib"
void s705_clear(s712_WorkStack * v1_workstack) {
	#line 12
	((*v1_workstack).size) = 0l;
}


#line 15 "src/utils/workstack.ib"
void * s706_top(s712_WorkStack * v1_workstack) {
	#line 16
	return ((void *)(&(((*v1_workstack).items)[((*v1_workstack).size)])));
}


#line 20 "src/utils/workstack.ib"
void * s707_push(s712_WorkStack * v1_workstack, i64 v2_size) {
	#line 21
	if (((((*v1_workstack).size) + v2_size) > ((*v1_workstack).capacity))) {
		#line 22
		if ((((*v1_workstack).capacity) == 0l)) {
			#line 22
			((*v1_workstack).capacity) = 1024l;
		} else {
#line 23
			((*v1_workstack).capacity) *= 2l;
		}
		#line 24
		if ((((*v1_workstack).capacity) < v2_size)) {
			#line 24
			((*v1_workstack).capacity) = v2_size;
		}
		#line 26
		((*v1_workstack).items) = ((char *)realloc(((void *)((*v1_workstack).items)), ((u64)(((*v1_workstack).capacity) * ((i64)1ul)))));
	}
	#line 31
	char * v3_ptr = (&(((*v1_workstack).items)[((*v1_workstack).size)]));
	#line 32
	((*v1_workstack).size) += v2_size;
	#line 33
	return ((void *)v3_ptr);
}


#line 37 "src/utils/workstack.ib"
void * s708_pop(s712_WorkStack * v1_workstack, i64 v2_size) {
	#line 38
	((*v1_workstack).size) -= v2_size;
	#line 39
	s40_assert((((*v1_workstack).size) >= 0l), "Tried popping WorkStack, but it was empty!");
	#line 40
	return ((void *)(&(((*v1_workstack).items)[((*v1_workstack).size)])));
}


#line 44 "src/utils/workstack.ib"
void * s709_pop_n(s712_WorkStack * v1_workstack, i64 v2_size, i64 v3_count) {
	#line 45
	((*v1_workstack).size) -= (v2_size * v3_count);
	#line 46
	s40_assert((((*v1_workstack).size) >= 0l), "Tried popping WorkStack N, but it was empty!");
	#line 47
	return ((void *)(&(((*v1_workstack).items)[((*v1_workstack).size)])));
}


#line 50 "src/utils/workstack.ib"
void s710_assert_empty(s712_WorkStack * v1_workstack) {
	#line 51
	s40_assert((((*v1_workstack).size) == 0l), "Workstack was expected to be empty!");
}


#line 55 "src/utils/workstack.ib"
void s711_free(s712_WorkStack * v1_workstack) {
	#line 56
	if ((((*v1_workstack).items) != ((char *)NULL))) {
		#line 57
		free(((void *)((*v1_workstack).items)));
	}
	#line 59
	((*v1_workstack).size) = 0l;
	#line 60
	((*v1_workstack).capacity) = 0l;
	#line 61
	((*v1_workstack).items) = ((char *)NULL);
}


#line 33 "src/typecheck/module.ib"
s729_Module s713_new(s334_Module * v1_source) {
	#line 34
	return ((s729_Module){
		.uid = ((*v1_source).uid),
		.file = ((*v1_source).file),
		.nodes = s834_new(),
		.functions = s244_new_frozen(((i64)96ul), (((*v1_source).functions).count)),
		.extern_fns = s244_new_frozen(((i64)88ul), (((*v1_source).extern_fns).count)),
		.args = s243_new(((i64)32ul), (((*v1_source).args).count)),
		.extern_globals = s244_new_frozen(((i64)56ul), (((*v1_source).extern_globals).count)),
		.globals = s244_new_frozen(((i64)72ul), (((*v1_source).globals).count)),
		.structs = s244_new_frozen(((i64)72ul), (((*v1_source).structs).count)),
		.unions = s244_new_frozen(((i64)72ul), (((*v1_source).unions).count)),
		.enums = s244_new_frozen(((i64)72ul), (((*v1_source).enums).count)),
		.object_data = s560_new(((i64)(40ul * ((u64)128l))))
	});
}


#line 53 "src/typecheck/module.ib"
void s714_free(s729_Module * v1_module, bool v2_print_usage) {
	#line 54
	i64 v3_functions_usage = s246_free((&((*v1_module).functions)));
	#line 55
	i64 v4_args_usage = s246_free((&((*v1_module).args)));
	#line 56
	i64 v5_globals_usage = s246_free((&((*v1_module).globals)));
	#line 57
	i64 v6_structs_usage = s246_free((&((*v1_module).structs)));
	#line 58
	i64 v7_enums_usage = s246_free((&((*v1_module).enums)));
	#line 59
	i64 v8_unions_usage = s246_free((&((*v1_module).unions)));
	#line 60
	i64 v9_object_data_usage = s562_free((&((*v1_module).object_data)));
	#line 61
	i64 v10_extern_fns_usage = s246_free((&((*v1_module).extern_fns)));
	#line 62
	i64 v11_extern_globals_usage = s246_free((&((*v1_module).extern_globals)));
	#line 63
	if (v2_print_usage) {
		#line 64
		printf("Functions Usage: %d\n", v3_functions_usage);
		#line 65
		printf("Args Usage: %d\n", v4_args_usage);
		#line 66
		printf("Globals Usage: %d\n", v5_globals_usage);
		#line 67
		printf("Structs Usage: %d\n", v6_structs_usage);
		#line 68
		printf("Enums Usage: %d\n", v7_enums_usage);
		#line 69
		printf("Unions Usage: %d\n", v8_unions_usage);
		#line 70
		printf("ObjectData Usage: %d\n", v9_object_data_usage);
		#line 71
		printf("ExternFunctions Usage: %d\n", v10_extern_fns_usage);
		#line 72
		printf("ExternGlobals Usage: %d\n", v11_extern_globals_usage);
	}
	#line 74
	s835_free((&((*v1_module).nodes)));
}


#line 78 "src/typecheck/module.ib"
s257_Vec * s715_extern_globals(s729_Module * v1_module) {
	#line 78
	return (&((*v1_module).extern_globals));
}


#line 79 "src/typecheck/module.ib"
s257_Vec * s716_extern_fns(s729_Module * v1_module) {
	#line 79
	return (&((*v1_module).extern_fns));
}


#line 80 "src/typecheck/module.ib"
s257_Vec * s717_functions(s729_Module * v1_module) {
	#line 80
	return (&((*v1_module).functions));
}


#line 81 "src/typecheck/module.ib"
s257_Vec * s718_globals(s729_Module * v1_module) {
	#line 81
	return (&((*v1_module).globals));
}


#line 82 "src/typecheck/module.ib"
s257_Vec * s719_structs(s729_Module * v1_module) {
	#line 82
	return (&((*v1_module).structs));
}


#line 83 "src/typecheck/module.ib"
s257_Vec * s720_unions(s729_Module * v1_module) {
	#line 83
	return (&((*v1_module).unions));
}


#line 84 "src/typecheck/module.ib"
s257_Vec * s721_enums(s729_Module * v1_module) {
	#line 84
	return (&((*v1_module).enums));
}


#line 86 "src/typecheck/module.ib"
s201_UID s722_extern_global_symbol(s772_ExternGlobal * v1_extglb) {
	#line 86
	return ((*v1_extglb).symbol);
}


#line 87 "src/typecheck/module.ib"
s201_UID s723_extern_fn_symbol(s740_ExternFn * v1_extfn) {
	#line 87
	return ((*v1_extfn).symbol);
}


#line 88 "src/typecheck/module.ib"
s201_UID s724_function_symbol(s739_Function * v1_func) {
	#line 88
	return ((*v1_func).symbol);
}


#line 89 "src/typecheck/module.ib"
s201_UID s725_global_symbol(s771_Global * v1_glb) {
	#line 89
	return ((*v1_glb).symbol);
}


#line 90 "src/typecheck/module.ib"
s201_UID s726_struct_symbol(s758_ObjectDef * v1_strct) {
	#line 90
	return ((*v1_strct).symbol);
}


#line 91 "src/typecheck/module.ib"
s201_UID s727_union_symbol(s758_ObjectDef * v1__union) {
	#line 91
	return ((*v1__union).symbol);
}


#line 92 "src/typecheck/module.ib"
s201_UID s728_enum_symbol(s766_EnumDef * v1_enums) {
	#line 92
	return ((*v1_enums).symbol);
}


#line 70 "src/typecheck/function.ib"
s743_FunctionContext s730_create_fn_context(s351_TypecheckContext * v1_parent, i64 v2_module) {
	#line 71
	s334_Module * v3_ast_module = s346_find_ast_module(v1_parent, v2_module);
	#line 72
	s729_Module * v4_module = s347_find_module(v1_parent, v2_module);
	#line 73
	s40_assert((v4_module != ((s729_Module *)NULL)), "typecheck::function module not found!");
	#line 75
	return ((s743_FunctionContext){
		.parent = v1_parent,
		.module = v3_ast_module,
		.function = ((s663_Function *)NULL),
		.nodes = (&((*v4_module).nodes)),
		.bindings = s974_new(),
		.target_ty = ((s528_TypeIdent *)NULL),
		.target_ty_span = 0l,
		.return_ty = ((s527_FlowType){

		}),
		.loop_depth = 0l,
		.path_stack = s243_new(((i64)8ul), 64l),
		.workstack = ((s712_WorkStack){

		}),
		.has_return = false
	});
}


#line 90 "src/typecheck/function.ib"
void s731_free_fn_context(s743_FunctionContext * v1_context) {
	#line 91
	s246_free((&((*v1_context).path_stack)));
	#line 92
	s975_free((&((*v1_context).bindings)));
	#line 93
	s711_free((&((*v1_context).workstack)));
}


#line 97 "src/typecheck/function.ib"
void s732_typecheck_function(s351_TypecheckContext * v1_context, s201_UID v2_symbol) {
	#line 101
	s172_assert_exists(v2_symbol);
	#line 102
	s189_assert_kind(v2_symbol, s544_SymbolKind_Function, "typecheck::run symbols was not function!");
	#line 105
	s743_FunctionContext v3_fn_context = s730_create_fn_context(v1_context, (v2_symbol.module));
	#line 106
	(v3_fn_context.function) = (s184_get_shallow(v2_symbol).func);
	#line 108
	s729_Module * v4_module = s347_find_module(v1_context, (v2_symbol.module));
	#line 110
	s739_Function * v5_func = (s183_get_deep(v2_symbol).func);
	#line 111
	s741_Prototype * v6_proto = (&((*v5_func).proto));
	#line 112
	(v3_fn_context.return_ty) = ((*v6_proto).return_type);
	#line 114
	s976_start((&(v3_fn_context.bindings)));
	#line 115
	for (i64 v7_i = 0l;(v7_i < ((*v6_proto).arg_count));v7_i += 1l) {
		#line 116
		s742_Arg * v8_arg = ((s742_Arg *)s251_get((&((*v4_module).args)), (((*v6_proto).arg_index) + v7_i)));
		#line 117
		s979_insert((&(v3_fn_context.bindings)), ((*v8_arg).ident), ((*v8_arg).type), true, ((*v8_arg).span));
	}
	loop_exit_1:
	#line 120
	s845_NodeResult v9_body_res = s827_typecheck((&v3_fn_context), ((*(v3_fn_context.function)).body));
	#line 121
	i64 v10_body = (v9_body_res.node);
	#line 123
	s977_end((&(v3_fn_context.bindings)), v1_context);
	#line 124
	s978_assert_no_blocks((&(v3_fn_context.bindings)));
	#line 126
	s850_NodeFlow v11_actual_flow = (v9_body_res.flow);
	#line 127
	if (((v11_actual_flow == s850_NodeFlow_Never) && (v3_fn_context.has_return))) {
		#line 128
		v11_actual_flow = s850_NodeFlow_Return;
	}
	#line 130
	bool v12_invalid_flow = false;
	#line 131
	switch ((((*v6_proto).return_type).kind)) {
	case s533_FlowTypeKind_Some: {
	switch ((v9_body_res.flow)) {
	case s850_NodeFlow_Return: {
	break; }
	case s850_NodeFlow_Never: {
	v12_invalid_flow = (!(v3_fn_context.has_return));
	break; }
	default:
 {
	v12_invalid_flow = true;
	break; }
}
	break; }
	case s533_FlowTypeKind_Void: {
	v12_invalid_flow = (v11_actual_flow == s850_NodeFlow_Never);
	break; }
	case s533_FlowTypeKind_Never: {
	v12_invalid_flow = (v11_actual_flow != s850_NodeFlow_Never);
	break; }
	default:
		abort();
}
	#line 142
	if (v12_invalid_flow) {
		#line 143
		s774_error(v1_context, s781_ErrorKind_FunctionInvalidFlow, ((*v6_proto).return_span));
	}
	#line 149
	((*v5_func).body) = v10_body;
	#line 151
	s731_free_fn_context((&v3_fn_context));
}


#line 154 "src/typecheck/function.ib"
void s733_typecheck_function_head(s351_TypecheckContext * v1_context, s201_UID v2_symbol) {
	#line 158
	if (s191_is_extern(v2_symbol)) {
		#line 159
		s734_typecheck_extern(v1_context, v2_symbol);
		#line 160
		return;
	}
	#line 163
	s187_set_stage(v2_symbol, s543_SymbolStage_TypecheckInProgress);
	#line 164
	s334_Module * v3_ast_module = s346_find_ast_module(v1_context, (v2_symbol.module));
	#line 165
	s729_Module * v4_module = s347_find_module(v1_context, (v2_symbol.module));
	#line 167
	s739_Function * v5_func = ((s739_Function *)s249_push((&((*v4_module).functions))));
	#line 168
	s665_Prototype * v6_proto = (&((*(s184_get_shallow(v2_symbol).func)).proto));
	#line 169
	((*v5_func).proto) = s735_typecheck_prototype(v1_context, v2_symbol, v6_proto, v3_ast_module, v4_module);
	#line 174
	((*v5_func).symbol) = v2_symbol;
	#line 175
	s182_attach_deep(v2_symbol, ((s542_DeepInfo){
		.func = v5_func
	}));
	#line 176
	s187_set_stage(v2_symbol, s543_SymbolStage_Typechecked);
	#line 177
	s185_set_type(v2_symbol, (((*v5_func).proto).ty));
}


#line 180 "src/typecheck/function.ib"
void s734_typecheck_extern(s351_TypecheckContext * v1_context, s201_UID v2_symbol) {
	#line 184
	s172_assert_exists(v2_symbol);
	#line 185
	if ((!s191_is_extern(v2_symbol))) {
		#line 186
		s40_assert(false, "Typechecking externfn but symbol was not extern!");
	}
	#line 188
	s187_set_stage(v2_symbol, s543_SymbolStage_TypecheckInProgress);
	#line 189
	s334_Module * v3_ast_module = s346_find_ast_module(v1_context, (v2_symbol.module));
	#line 190
	s729_Module * v4_module = s347_find_module(v1_context, (v2_symbol.module));
	#line 192
	s665_Prototype * v5_proto = (&((*(s184_get_shallow(v2_symbol).extern_func)).proto));
	#line 193
	s740_ExternFn * v6_func = ((s740_ExternFn *)s249_push((&((*v4_module).extern_fns))));
	#line 194
	((*v6_func).proto) = s735_typecheck_prototype(v1_context, v2_symbol, v5_proto, v3_ast_module, v4_module);
	#line 199
	((*v6_func).symbol) = v2_symbol;
	#line 200
	s182_attach_deep(v2_symbol, ((s542_DeepInfo){
		.extern_func = v6_func
	}));
	#line 201
	s187_set_stage(v2_symbol, s543_SymbolStage_Typechecked);
	#line 202
	s185_set_type(v2_symbol, (((*v6_func).proto).ty));
}


#line 206 "src/typecheck/function.ib"
s741_Prototype s735_typecheck_prototype(s351_TypecheckContext * v1_context, s201_UID v2__symbol, s665_Prototype * v3_proto, s334_Module * v4_ast_module, s729_Module * v5_module) {
	#line 213
	char * v6_identifier = ((*v3_proto).identifier);
	#line 215
	i64 v7_arg_index = (((*v5_module).args).count);
	#line 216
	i64 v8_arg_count = ((*v3_proto).arg_count);
	#line 217
	for (i64 v9_i = 0l;(v9_i < ((*v3_proto).arg_count));v9_i += 1l) {
		#line 218
		s666_Arg * v10_ast_arg = ((s666_Arg *)s251_get((&((*v4_ast_module).args)), (((*v3_proto).arg_index) + v9_i)));
		#line 219
		s528_TypeIdent * v11_type = s509_typecheck(v1_context, ((*v5_module).uid), ((*v10_ast_arg).type), ((*v10_ast_arg).type_span));
		#line 221
		s742_Arg * v12_arg = ((s742_Arg *)s249_push((&((*v5_module).args))));
		#line 222
		(*v12_arg) = ((s742_Arg){
			.ident = ((*v10_ast_arg).ident),
			.type = v11_type,
			.span = ((*v10_ast_arg).span),
			.type_span = ((*v10_ast_arg).type_span)
		});
		#line 228
		s528_TypeIdent * * v13_typeident = ((s528_TypeIdent * *)s707_push((&((*v1_context).workstack)), ((i64)8ul)));
		#line 229
		(*v13_typeident) = v11_type;
	}
	loop_exit_1:
	#line 231
	s527_FlowType v14_return_type = s508_typecheck_flowtype(v1_context, ((*v5_module).uid), ((*v3_proto).return_type), ((*v3_proto).return_span));
	#line 232
	i64 v15_return_span = ((*v3_proto).return_span);
	#line 234
	bool v16_has_varargs = ((*v3_proto).has_varargs);
	#line 236
	s528_TypeIdent v17_temp_ty = ((s528_TypeIdent){

	});
	#line 237
	(v17_temp_ty.kind) = s534_TypeKind_Function;
	#line 239
	s530_FunctionType * v18_temp_fn = (&((v17_temp_ty.data).function));
	#line 240
	((*v18_temp_fn).args_length) = v8_arg_count;
	#line 241
	((*v18_temp_fn).has_varargs) = v16_has_varargs;
	#line 242
	((*v18_temp_fn).return_ty) = v14_return_type;
	#line 245
	((*v18_temp_fn).args) = ((s528_TypeIdent * *)s709_pop_n((&((*v1_context).workstack)), ((i64)8ul), v8_arg_count));
	#line 246
	s528_TypeIdent * v19_ty = s513_find_or_insert((&((*v1_context).typeidents)), (&v17_temp_ty));
	#line 247
	return ((s741_Prototype){
		.identifier = v6_identifier,
		.arg_index = v7_arg_index,
		.arg_count = v8_arg_count,
		.has_varargs = v16_has_varargs,
		.return_type = v14_return_type,
		.return_span = v15_return_span,
		.ty = v19_ty
	});
}


#line 260 "src/typecheck/function.ib"
void s736_debug(s299_StringBuilder * v1_sb, s729_Module * v2_module, s739_Function * v3_function) {
	#line 261
	s283_append(v1_sb, "FN ");
	#line 262
	s738_debug_proto(v1_sb, v2_module, (&((*v3_function).proto)));
	#line 263
	if (((((*v3_function).body) != s826_ERROR) && (((*v3_function).body) != s825_NONE))) {
		#line 264
		s842_debug(v1_sb, (&((*v2_module).nodes)), ((*v3_function).body), 1l);
	}
	#line 266
	s284_append_char(v1_sb, 10u);
}


#line 269 "src/typecheck/function.ib"
void s737_debug_extern(s299_StringBuilder * v1_sb, s729_Module * v2_module, s740_ExternFn * v3_function) {
	#line 270
	s283_append(v1_sb, "EXTERN FN ");
	#line 271
	s738_debug_proto(v1_sb, v2_module, (&((*v3_function).proto)));
	#line 272
	s284_append_char(v1_sb, 10u);
}


#line 275 "src/typecheck/function.ib"
void s738_debug_proto(s299_StringBuilder * v1_sb, s729_Module * v2_module, s741_Prototype * v3_proto) {
	#line 276
	s283_append(v1_sb, ((*v3_proto).identifier));
	#line 277
	for (i64 v4_i = 0l;(v4_i < ((*v3_proto).arg_count));v4_i += 1l) {
		#line 278
		s283_append(v1_sb, "\n    ");
		#line 280
		s742_Arg * v5_arg = ((s742_Arg *)s251_get((&((*v2_module).args)), (((*v3_proto).arg_index) + v4_i)));
		#line 281
		s283_append(v1_sb, ((*v5_arg).ident));
		#line 282
		s283_append(v1_sb, " : ");
		#line 283
		s524_debug(v1_sb, (&((*v2_module).nodes)), ((*v5_arg).type), 1l);
	}
	loop_exit_1:
	#line 285
	if (((*v3_proto).has_varargs)) {
		#line 286
		s283_append(v1_sb, "\n  ...");
	}
	#line 288
	s283_append(v1_sb, "\n  return: ");
	#line 289
	s525_debug_flowtype(v1_sb, (&((*v2_module).nodes)), (&((*v3_proto).return_type)), 1l);
	#line 290
	s284_append_char(v1_sb, 10u);
}


#line 35 "src/typecheck/object_def.ib"
s757_ObjectField * s745_get_field(s758_ObjectDef * v1_def, char * v2_field) {
	#line 36
	for (i64 v3_i = 0l;(v3_i < ((*v1_def).field_count));v3_i += 1l) {
		#line 37
		if ((((((*v1_def).fields)[v3_i]).field) == v2_field)) {
			#line 38
			return (&(((*v1_def).fields)[v3_i]));
		}
	}
	loop_exit_1:
	#line 41
	return ((s757_ObjectField *)NULL);
}


#line 45 "src/typecheck/object_def.ib"
i64 s746_get_field_idx(s758_ObjectDef * v1_def, char * v2_field) {
	#line 46
	for (i64 v3_i = 0l;(v3_i < ((*v1_def).field_count));v3_i += 1l) {
		#line 47
		if ((((((*v1_def).fields)[v3_i]).field) == v2_field)) {
			#line 48
			return v3_i;
		}
	}
	loop_exit_1:
	#line 51
	return s744_FIELD_IDX_NONE;
}


#line 54 "src/typecheck/object_def.ib"
void s747_typecheck_struct(s351_TypecheckContext * v1_context, s201_UID v2_symbol) {
	#line 58
	if (s188_stage_eq(v2_symbol, s543_SymbolStage_Typechecked)) {
		#line 58
		return;
	}
	#line 59
	s187_set_stage(v2_symbol, s543_SymbolStage_TypecheckInProgress);
	#line 61
	s528_TypeIdent v3_temp_ty = ((s528_TypeIdent){
		.kind = s534_TypeKind_Compound,
		.data = ((s532_TypeData){
			.compound = v2_symbol
		})
	});
	#line 65
	s185_set_type(v2_symbol, s513_find_or_insert((&((*v1_context).typeidents)), (&v3_temp_ty)));
	#line 67
	s729_Module * v4_module = s347_find_module(v1_context, (v2_symbol.module));
	#line 68
	s758_ObjectDef * v5_def = ((s758_ObjectDef *)s249_push((&((*v4_module).structs))));
	#line 70
	s344_start_typechecking(v1_context, v2_symbol);
	#line 72
	s751_typecheck_obj_def(v1_context, v2_symbol, v4_module, v5_def);
	#line 73
	s748_struct_alignment(v1_context, v5_def);
	#line 74
	s187_set_stage(v2_symbol, s543_SymbolStage_Typechecked);
	#line 76
	s345_finish_typechecking(v1_context, v2_symbol);
}


#line 79 "src/typecheck/object_def.ib"
void s748_struct_alignment(s351_TypecheckContext * v1_context, s758_ObjectDef * v2_def) {
	#line 80
	i64 v3_max_align = 1l;
	#line 81
	i64 v4_offset = 0l;
	#line 82
	for (i64 v5_i = 0l;(v5_i < ((*v2_def).field_count));v5_i += 1l) {
		#line 83
		s995_SizeAndAlign v6_res = s987_typeident(v1_context, ((((*v2_def).fields)[v5_i]).type));
		#line 85
		if (((v6_res.align) > v3_max_align)) {
			#line 85
			v3_max_align = (v6_res.align);
		}
		#line 86
		v4_offset = s752_get_aligned_offset(v4_offset, (v6_res.align));
		#line 87
		((((*v2_def).fields)[v5_i]).offset) = v4_offset;
		#line 88
		v4_offset += (v6_res.size);
	}
	loop_exit_1:
	#line 90
	i64 v7_size = s752_get_aligned_offset(v4_offset, v3_max_align);
	#line 91
	if ((v7_size < 1l)) {
		#line 91
		v7_size = 1l;
	}
	#line 92
	((*v2_def).align) = v3_max_align;
	#line 93
	((*v2_def).size) = v7_size;
}


#line 97 "src/typecheck/object_def.ib"
void s749_typecheck_union(s351_TypecheckContext * v1_context, s201_UID v2_symbol) {
	#line 101
	if (s188_stage_eq(v2_symbol, s543_SymbolStage_Typechecked)) {
		#line 101
		return;
	}
	#line 102
	s187_set_stage(v2_symbol, s543_SymbolStage_TypecheckInProgress);
	#line 104
	s528_TypeIdent v3_temp_ty = ((s528_TypeIdent){
		.kind = s534_TypeKind_Compound,
		.data = ((s532_TypeData){
			.compound = v2_symbol
		})
	});
	#line 108
	s185_set_type(v2_symbol, s513_find_or_insert((&((*v1_context).typeidents)), (&v3_temp_ty)));
	#line 110
	s729_Module * v4_module = s347_find_module(v1_context, (v2_symbol.module));
	#line 111
	s758_ObjectDef * v5_def = ((s758_ObjectDef *)s249_push((&((*v4_module).unions))));
	#line 113
	s344_start_typechecking(v1_context, v2_symbol);
	#line 115
	s751_typecheck_obj_def(v1_context, v2_symbol, v4_module, v5_def);
	#line 116
	s750_union_alignment(v1_context, v5_def);
	#line 117
	s187_set_stage(v2_symbol, s543_SymbolStage_Typechecked);
	#line 119
	s345_finish_typechecking(v1_context, v2_symbol);
}


#line 122 "src/typecheck/object_def.ib"
void s750_union_alignment(s351_TypecheckContext * v1_context, s758_ObjectDef * v2_def) {
	#line 123
	i64 v3_max_align = 1l;
	#line 124
	i64 v4_max_size = 0l;
	#line 125
	for (i64 v5_i = 0l;(v5_i < ((*v2_def).field_count));v5_i += 1l) {
		#line 126
		s995_SizeAndAlign v6_res = s987_typeident(v1_context, ((((*v2_def).fields)[v5_i]).type));
		#line 128
		if (((v6_res.align) > v3_max_align)) {
			#line 128
			v3_max_align = (v6_res.align);
		}
		#line 129
		if (((v6_res.size) > v4_max_size)) {
			#line 129
			v4_max_size = (v6_res.size);
		}
		#line 130
		((((*v2_def).fields)[v5_i]).offset) = 0l;
	}
	loop_exit_1:
	#line 133
	if ((v4_max_size < 1l)) {
		#line 133
		v4_max_size = 1l;
	}
	#line 134
	((*v2_def).align) = v3_max_align;
	#line 135
	((*v2_def).size) = v4_max_size;
}


#line 139 "src/typecheck/object_def.ib"
void s751_typecheck_obj_def(s351_TypecheckContext * v1_context, s201_UID v2_symbol, s729_Module * v3_module, s758_ObjectDef * v4_def) {
	#line 145
	s670_ObjectDef * v5_ast_def = (s184_get_shallow(v2_symbol).object_def);
	#line 147
	char * v6_name = (((*v5_ast_def).declaration).name);
	#line 148
	i64 v7_span = (((*v5_ast_def).declaration).span);
	#line 149
	i64 v8_field_count = ((*v5_ast_def).field_count);
	#line 150
	s757_ObjectField * v9_fields = s753_typecheck_fields(v1_context, v3_module, v5_ast_def);
	#line 152
	(*v4_def) = ((s758_ObjectDef){
		.name = v6_name,
		.span = v7_span,
		.symbol = v2_symbol,
		.field_count = v8_field_count,
		.fields = v9_fields,
		.align = 1l,
		.size = 1l
	});
	#line 157
	s182_attach_deep(v2_symbol, ((s542_DeepInfo){
		.object_def = v4_def
	}));
}


#line 160 "src/typecheck/object_def.ib"
i64 s752_get_aligned_offset(i64 v1_offset, i64 v2_align) {
	#line 161
	i64 v3_padding = (v1_offset % v2_align);
	#line 162
	if ((v3_padding == 0l)) {
		#line 162
		return v1_offset;
	}
	#line 163
	return ((v1_offset + v2_align) - v3_padding);
}


#line 167 "src/typecheck/object_def.ib"
s757_ObjectField * s753_typecheck_fields(s351_TypecheckContext * v1_context, s729_Module * v2_module, s670_ObjectDef * v3_ast_def) {
	#line 172
	s757_ObjectField * v4_fields = ((s757_ObjectField *)s561_allocate((&((*v2_module).object_data)), ((i64)(40ul * ((u64)((*v3_ast_def).field_count))))));
	#line 177
	for (i64 v5_i = 0l;(v5_i < ((*v3_ast_def).field_count));v5_i += 1l) {
		#line 178
		char * v6_field = ((((*v3_ast_def).fields)[v5_i]).field);
		#line 179
		i64 v7_field_span = ((((*v3_ast_def).fields)[v5_i]).field_span);
		#line 180
		i64 v8_type_span = ((((*v3_ast_def).fields)[v5_i]).type_span);
		#line 181
		s528_TypeIdent * v9_type = s509_typecheck(v1_context, ((*v2_module).uid), ((((*v3_ast_def).fields)[v5_i]).type), v8_type_span);
		#line 188
		(v4_fields[v5_i]) = ((s757_ObjectField){
			.field = v6_field,
			.field_span = v7_field_span,
			.type = v9_type,
			.type_span = v8_type_span,
			.offset = 0l
		});
	}
	loop_exit_1:
	#line 194
	return v4_fields;
}


#line 198 "src/typecheck/object_def.ib"
void s754_debug_struct(s299_StringBuilder * v1_sb, s729_Module * v2_module, s758_ObjectDef * v3_obj) {
	#line 199
	s756_debug_object_def(v1_sb, v2_module, v3_obj, "STRUCT");
}


#line 202 "src/typecheck/object_def.ib"
void s755_debug_union(s299_StringBuilder * v1_sb, s729_Module * v2_module, s758_ObjectDef * v3_obj) {
	#line 203
	s756_debug_object_def(v1_sb, v2_module, v3_obj, "UNION");
}


#line 207 "src/typecheck/object_def.ib"
void s756_debug_object_def(s299_StringBuilder * v1_sb, s729_Module * v2_module, s758_ObjectDef * v3_obj, char * v4_kind) {
	#line 209
	s283_append(v1_sb, v4_kind);
	#line 210
	s283_append(v1_sb, " : ");
	#line 211
	s283_append(v1_sb, ((*v3_obj).name));
	#line 212
	s200_debug_head(v1_sb, ((*v3_obj).symbol));
	#line 213
	s283_append(v1_sb, " ");
	#line 214
	s994_debug(v1_sb, ((*v3_obj).size), ((*v3_obj).align));
	#line 215
	s283_append(v1_sb, "\n");
	#line 216
	for (i64 v5_i = 0l;(v5_i < ((*v3_obj).field_count));v5_i += 1l) {
		#line 217
		s283_append(v1_sb, "  .");
		#line 218
		s289_append_number(v1_sb, ((((*v3_obj).fields)[v5_i]).offset));
		#line 219
		s283_append(v1_sb, "\t");
		#line 220
		s283_append(v1_sb, ((((*v3_obj).fields)[v5_i]).field));
		#line 221
		s283_append(v1_sb, "\t: ");
		#line 222
		s524_debug(v1_sb, (&((*v2_module).nodes)), ((((*v3_obj).fields)[v5_i]).type), ((((*v3_obj).fields)[v5_i]).type_span));
		#line 227
		s283_append(v1_sb, "\n");
	}
	loop_exit_1:
	#line 229
	s283_append(v1_sb, "\n");
}


#line 38 "src/typecheck/enums.ib"
i64 s759_field_idx(s766_EnumDef * v1_def, char * v2_key) {
	#line 39
	s40_assert((v1_def != ((s766_EnumDef *)NULL)), "enums::field_idx got null");
	#line 40
	for (i64 v3_i = 0l;(v3_i < ((*v1_def).field_count));v3_i += 1l) {
		#line 41
		if ((((((*v1_def).fields)[v3_i]).field) == v2_key)) {
			#line 42
			return v3_i;
		}
	}
	loop_exit_1:
	#line 45
	return (-1l);
}


#line 48 "src/typecheck/enums.ib"
void s760_typecheck_def(s351_TypecheckContext * v1_context, s201_UID v2_symbol) {
	#line 52
	if (s188_stage_eq(v2_symbol, s543_SymbolStage_Typechecked)) {
		#line 52
		return;
	}
	#line 53
	s187_set_stage(v2_symbol, s543_SymbolStage_TypecheckInProgress);
	#line 55
	s528_TypeIdent v3_temp_ty = ((s528_TypeIdent){
		.kind = s534_TypeKind_Compound,
		.data = ((s532_TypeData){
			.compound = v2_symbol
		})
	});
	#line 59
	s185_set_type(v2_symbol, s513_find_or_insert((&((*v1_context).typeidents)), (&v3_temp_ty)));
	#line 61
	s729_Module * v4_module = s347_find_module(v1_context, (v2_symbol.module));
	#line 62
	s766_EnumDef * v5_enum_def = ((s766_EnumDef *)s249_push((&((*v4_module).enums))));
	#line 64
	s344_start_typechecking(v1_context, v2_symbol);
	#line 66
	s761_typecheck_fields(v1_context, v2_symbol, v4_module, v5_enum_def);
	#line 68
	s182_attach_deep(v2_symbol, ((s542_DeepInfo){
		.enum_def = v5_enum_def
	}));
	#line 69
	s187_set_stage(v2_symbol, s543_SymbolStage_Typechecked);
	#line 71
	s345_finish_typechecking(v1_context, v2_symbol);
}


#line 75 "src/typecheck/enums.ib"
void s761_typecheck_fields(s351_TypecheckContext * v1_context, s201_UID v2_symbol, s729_Module * v3_module, s766_EnumDef * v4_def) {
	#line 81
	s743_FunctionContext v5_fn_context = s730_create_fn_context(v1_context, ((*v3_module).uid));
	#line 82
	s672_EnumDef * v6_ast_def = (s184_get_shallow(v2_symbol).enum_def);
	#line 83
	s765_EnumField * v7_fields = ((s765_EnumField *)s561_allocate((&((*v3_module).object_data)), ((i64)(24ul * ((u64)((*v6_ast_def).field_count))))));
	#line 87
	i64 v8_field_count = ((*v6_ast_def).field_count);
	#line 88
	i64 v9_next_value = 0l;
	#line 89
	i64 v10_max_value = 0l;
	#line 90
	for (i64 v11_i = 0l;(v11_i < v8_field_count);v11_i += 1l) {
		#line 91
		for (i64 v12_j = 0l;(v12_j < v11_i);v12_j += 1l) {
			#line 92
			if ((((((*v6_ast_def).fields)[v11_i]).field) == ((((*v6_ast_def).fields)[v12_j]).field))) {
				#line 93
				s774_error(v1_context, s781_ErrorKind_EnumDuplicateField, ((((*v6_ast_def).fields)[v11_i]).field_span));
			}
		}
		loop_exit_2:
		#line 96
		s673_EnumField * v13_field = (&(((*v6_ast_def).fields)[v11_i]));
		#line 97
		i64 v14_value = v9_next_value;
		#line 98
		if ((((*v13_field).value) != s577_NONE)) {
			#line 99
			s763_eval_enum_value((&v5_fn_context), ((*v13_field).value), (&v14_value));
		}
		#line 105
		if ((v14_value > v10_max_value)) {
			#line 105
			v10_max_value = v14_value;
		}
		#line 106
		(v7_fields[v11_i]) = ((s765_EnumField){
			.value = v14_value,
			.field = ((*v13_field).field),
			.field_span = ((*v13_field).field_span)
		});
		#line 111
		v9_next_value = (v14_value + 1l);
	}
	loop_exit_1:
	#line 113
	char * v15_name = (((*v6_ast_def).declaration).name);
	#line 114
	i64 v16_span = (((*v6_ast_def).declaration).span);
	#line 115
	i64 v17_size = s762_max_value_into_size(v10_max_value);
	#line 116
	(*v4_def) = ((s766_EnumDef){
		.name = v15_name,
		.span = v16_span,
		.symbol = v2_symbol,
		.field_count = v8_field_count,
		.fields = v7_fields,
		.align = v17_size,
		.size = v17_size
	});
	#line 121
	s731_free_fn_context((&v5_fn_context));
}


#line 124 "src/typecheck/enums.ib"
i64 s762_max_value_into_size(i64 v1_max_value) {
	#line 125
	i64 v2_size = 1l;
	#line 126
	while ((v1_max_value > 256l)) {
		#line 127
		v2_size *= 2l;
		#line 128
		v1_max_value /= 256l;
}
	loop_exit_1:
	#line 130
	return v2_size;
}


#line 134 "src/typecheck/enums.ib"
void s763_eval_enum_value(s743_FunctionContext * v1_context, i64 v2_node, i64 * v3_value) {
	#line 139
	s845_NodeResult v4_node_res = s827_typecheck(v1_context, v2_node);
	#line 140
	i64 v5_node = (v4_node_res.node);
	#line 141
	s864_ConstEvalResult v6_result = s860_eval(v1_context, v5_node);
	#line 142
	if ((!(v6_result.success))) {
		#line 142
		return;
	}
	#line 144
	bool v7_is_ok = true;
	#line 145
	i64 v8_literal_val = s854_into_int(((v6_result.expr).literal), (&v7_is_ok));
	#line 146
	if ((!v7_is_ok)) {
		#line 147
		s844_Node * v9_node_data = s836_get(((*v1_context).nodes), v5_node);
		#line 148
		s774_error(((*v1_context).parent), s781_ErrorKind_EnumFieldWasNotNumber, ((*v9_node_data).span));
		#line 149
		return;
	}
	#line 151
	(*v3_value) = v8_literal_val;
}


#line 155 "src/typecheck/enums.ib"
void s764_debug_enum(s299_StringBuilder * v1_sb, s729_Module * v2__module, s766_EnumDef * v3_enum_def) {
	#line 157
	s283_append(v1_sb, "ENUM : ");
	#line 158
	s283_append(v1_sb, ((*v3_enum_def).name));
	#line 159
	s283_append(v1_sb, " ");
	#line 160
	s994_debug(v1_sb, ((*v3_enum_def).size), ((*v3_enum_def).align));
	#line 161
	s283_append(v1_sb, "\n");
	#line 162
	for (i64 v4_i = 0l;(v4_i < ((*v3_enum_def).field_count));v4_i += 1l) {
		#line 163
		s283_append(v1_sb, "  ");
		#line 164
		s283_append(v1_sb, ((((*v3_enum_def).fields)[v4_i]).field));
		#line 166
		s283_append(v1_sb, " = ");
		#line 167
		s289_append_number(v1_sb, ((((*v3_enum_def).fields)[v4_i]).value));
		#line 168
		s283_append(v1_sb, "\n");
	}
	loop_exit_1:
	#line 170
	s283_append(v1_sb, "\n");
}


#line 37 "src/typecheck/global.ib"
void s767_typecheck(s351_TypecheckContext * v1_context, s201_UID v2_symbol) {
	#line 41
	if (s191_is_extern(v2_symbol)) {
		#line 42
		s768_typecheck_extern(v1_context, v2_symbol);
		#line 43
		return;
	}
	#line 45
	if (s188_stage_eq(v2_symbol, s543_SymbolStage_Typechecked)) {
		#line 45
		return;
	}
	#line 46
	s187_set_stage(v2_symbol, s543_SymbolStage_TypecheckInProgress);
	#line 48
	s729_Module * v3_module = s347_find_module(v1_context, (v2_symbol.module));
	#line 49
	s771_Global * v4_global = ((s771_Global *)s249_push((&((*v3_module).globals))));
	#line 50
	s344_start_typechecking(v1_context, v2_symbol);
	#line 52
	s743_FunctionContext v5_fn_context = s730_create_fn_context(v1_context, ((*v3_module).uid));
	#line 53
	s667_Global * v6_ast_def = (s184_get_shallow(v2_symbol).global);
	#line 55
	s1020_VarDeclResult v7_res = s998_typecheck_vardecl((&v5_fn_context), (((*v6_ast_def).declaration).name), (((*v6_ast_def).declaration).span), ((*v6_ast_def).type), ((*v6_ast_def).type_span), ((*v6_ast_def).value), ((*v6_ast_def).mutable), (((*v6_ast_def).declaration).span));
	#line 66
	s185_set_type(v2_symbol, (v7_res.type));
	#line 67
	(*v4_global) = ((s771_Global){
		.name = (((*v6_ast_def).declaration).name),
		.span = (((*v6_ast_def).declaration).span),
		.mutable = ((*v6_ast_def).mutable),
		.type = (v7_res.type),
		.type_span = ((*v6_ast_def).type_span),
		.value = (v7_res.value),
		.symbol = v2_symbol
	});
	#line 76
	s182_attach_deep(v2_symbol, ((s542_DeepInfo){
		.global = v4_global
	}));
	#line 77
	s187_set_stage(v2_symbol, s543_SymbolStage_Typechecked);
	#line 79
	s345_finish_typechecking(v1_context, v2_symbol);
	#line 80
	s731_free_fn_context((&v5_fn_context));
}


#line 83 "src/typecheck/global.ib"
void s768_typecheck_extern(s351_TypecheckContext * v1_context, s201_UID v2_symbol) {
	#line 87
	if (s188_stage_eq(v2_symbol, s543_SymbolStage_Typechecked)) {
		#line 87
		return;
	}
	#line 88
	s187_set_stage(v2_symbol, s543_SymbolStage_TypecheckInProgress);
	#line 90
	s729_Module * v3_module = s347_find_module(v1_context, (v2_symbol.module));
	#line 91
	s772_ExternGlobal * v4_global = ((s772_ExternGlobal *)s249_push((&((*v3_module).extern_globals))));
	#line 92
	s344_start_typechecking(v1_context, v2_symbol);
	#line 94
	s668_ExternGlobal * v5_ast_def = (s184_get_shallow(v2_symbol).extern_global);
	#line 95
	s528_TypeIdent * v6_type = s509_typecheck(v1_context, (v2_symbol.module), ((*v5_ast_def).type), ((*v5_ast_def).type_span));
	#line 101
	s185_set_type(v2_symbol, v6_type);
	#line 102
	(*v4_global) = ((s772_ExternGlobal){
		.name = (((*v5_ast_def).declaration).name),
		.span = (((*v5_ast_def).declaration).span),
		.type = v6_type,
		.type_span = ((*v5_ast_def).type_span),
		.symbol = v2_symbol
	});
	#line 109
	s182_attach_deep(v2_symbol, ((s542_DeepInfo){
		.extern_global = v4_global
	}));
	#line 110
	s187_set_stage(v2_symbol, s543_SymbolStage_Typechecked);
	#line 112
	s345_finish_typechecking(v1_context, v2_symbol);
}


#line 116 "src/typecheck/global.ib"
void s769_debug_extern_global(s299_StringBuilder * v1_sb, s729_Module * v2_module, s772_ExternGlobal * v3_extrn) {
	#line 117
	s283_append(v1_sb, "EXTERN_GLOBAL ");
	#line 118
	s283_append(v1_sb, ((*v3_extrn).name));
	#line 119
	s283_append(v1_sb, " : ");
	#line 120
	s524_debug(v1_sb, (&((*v2_module).nodes)), ((*v3_extrn).type), 1l);
	#line 121
	s283_append(v1_sb, "\n");
}


#line 125 "src/typecheck/global.ib"
void s770_debug_global(s299_StringBuilder * v1_sb, s729_Module * v2_module, s771_Global * v3_global) {
	#line 126
	if (((*v3_global).mutable)) {
		#line 127
		s283_append(v1_sb, "GLOBAL LET\n");
	} else {
#line 129
		s283_append(v1_sb, "GLOBAL CONST\n");
	}
	#line 131
	s283_append(v1_sb, "  ");
	#line 132
	s283_append(v1_sb, ((*v3_global).name));
	#line 133
	s283_append(v1_sb, "\n");
	#line 134
	if ((((*v3_global).type) != ((s528_TypeIdent *)NULL))) {
		#line 135
		s283_append(v1_sb, "  TYPE: ");
		#line 136
		s524_debug(v1_sb, (&((*v2_module).nodes)), ((*v3_global).type), 1l);
		#line 137
		s283_append(v1_sb, "\n");
	} else {
#line 139
		s283_append(v1_sb, "  TYPE: NONE\n");
	}
	#line 141
	s842_debug(v1_sb, (&((*v2_module).nodes)), ((*v3_global).value), 1l);
	#line 142
	s283_append(v1_sb, "\n");
}


#line 94 "src/typecheck/error.ib"
i64 s773_todo(s351_TypecheckContext * v1_context, i64 v2_span, char * v3_message) {
	#line 95
	s283_append((&((*v1_context).err_builder)), "TODO: ");
	#line 96
	s283_append((&((*v1_context).err_builder)), v3_message);
	#line 97
	s778__error(v1_context, v2_span);
	#line 98
	return s826_ERROR;
}


#line 101 "src/typecheck/error.ib"
i64 s774_error(s351_TypecheckContext * v1_context, s781_ErrorKind v2_kind, i64 v3_span) {
	#line 102
	s780_append_message((&((*v1_context).err_builder)), v2_kind);
	#line 103
	s778__error(v1_context, v3_span);
	#line 104
	return s826_ERROR;
}


#line 107 "src/typecheck/error.ib"
void s775_object_missing_field(s351_TypecheckContext * v1_context, char * v2_field, i64 v3_span) {
	#line 108
	s299_StringBuilder * v4_sb = (&((*v1_context).err_builder));
	#line 109
	s283_append(v4_sb, "Missing field: ");
	#line 110
	s283_append(v4_sb, v2_field);
	#line 111
	s778__error(v1_context, v3_span);
}


#line 114 "src/typecheck/error.ib"
void s776_cyclic_dependency(s351_TypecheckContext * v1_context, s201_UID v2_symbol) {
	#line 115
	s299_StringBuilder * v3_sb = (&((*v1_context).err_builder));
	#line 116
	s283_append(v3_sb, "Circular Dependency: ");
	#line 117
	i64 v4_start = 0l;
	#line 118
	for (i64 v5_i = 0l;(v5_i < (((*v1_context).typecheck_stack).count));v5_i += 1l) {
		#line 119
		s201_UID * v6_s = ((s201_UID *)s251_get((&((*v1_context).typecheck_stack)), v5_i));
		#line 120
		if (s171_eq((*v6_s), v2_symbol)) {
			#line 120
			v4_start = v5_i;
			#line 120
						goto loop_exit_1;
/* break; */
		}
	}
	loop_exit_1:
	#line 122
	s283_append(v3_sb, s194_name(v2_symbol));
	#line 123
	for (i64 v7_i = (v4_start + 1l);(v7_i < (((*v1_context).typecheck_stack).count));v7_i += 1l) {
		#line 124
		s201_UID * v8_s = ((s201_UID *)s251_get((&((*v1_context).typecheck_stack)), v7_i));
		#line 125
		s283_append(v3_sb, " -> ");
		#line 126
		s283_append(v3_sb, s194_name((*v8_s)));
	}
	loop_exit_2:
	#line 131
	s778__error(v1_context, s193_span(v2_symbol));
}


#line 134 "src/typecheck/error.ib"
void s777_warn_unused_variable(s351_TypecheckContext * v1_context, i64 v2_span) {
	#line 135
	s283_append((&((*v1_context).err_builder)), "Unused Variable");
	#line 136
	s779__warn(v1_context, v2_span);
}


#line 139 "src/typecheck/error.ib"
void s778__error(s351_TypecheckContext * v1_context, i64 v2_span) {
	#line 140
	s402_Error * v3_err = s391_type_error(((*v1_context).errors));
	#line 141
	((*v3_err).span) = v2_span;
	#line 142
	((*v3_err).message) = s293_build((&((*v1_context).err_builder)));
	#line 143
	s295_reset((&((*v1_context).err_builder)));
}


#line 146 "src/typecheck/error.ib"
void s779__warn(s351_TypecheckContext * v1_context, i64 v2_span) {
	#line 147
	s402_Error * v3_warn = s392_type_warn(((*v1_context).errors));
	#line 148
	((*v3_warn).span) = v2_span;
	#line 149
	((*v3_warn).message) = s293_build((&((*v1_context).err_builder)));
	#line 150
	s295_reset((&((*v1_context).err_builder)));
}


#line 154 "src/typecheck/error.ib"
void s780_append_message(s299_StringBuilder * v1_sb, s781_ErrorKind v2_error) {
	#line 155
	switch (v2_error) {
	case s781_ErrorKind_VariableNotFound: {
	s283_append(v1_sb, "VariableNotFound");
	break; }
	case s781_ErrorKind_VarDeclTypeMismatch: {
	s283_append(v1_sb, "VarDeclTypeMismatch");
	break; }
	case s781_ErrorKind_VarDeclValueFlowWasNotSome: {
	s283_append(v1_sb, "VarDeclValueFlowWasNotSome");
	break; }
	case s781_ErrorKind_IfCondNotBool: {
	s283_append(v1_sb, "IfCondNotBool");
	break; }
	case s781_ErrorKind_LoopCondNotBool: {
	s283_append(v1_sb, "LoopCondNotBool");
	break; }
	case s781_ErrorKind_ReturnSomeExpected: {
	s283_append(v1_sb, "ReturnSomeExpected");
	break; }
	case s781_ErrorKind_ReturnVoidExpected: {
	s283_append(v1_sb, "ReturnVoidExpected");
	break; }
	case s781_ErrorKind_ReturnNeverExpected: {
	s283_append(v1_sb, "ReturnNeverExpected");
	break; }
	case s781_ErrorKind_ReturnTypeMismatch: {
	s283_append(v1_sb, "ReturnTypeMismatch");
	break; }
	case s781_ErrorKind_FunctionInvalidFlow: {
	s283_append(v1_sb, "FunctionInvalidFlow");
	break; }
	case s781_ErrorKind_BreakOutsideLoop: {
	s283_append(v1_sb, "BreakOutsideLoop");
	break; }
	case s781_ErrorKind_ContinueOutsideLoop: {
	s283_append(v1_sb, "ContinueOutsideLoop");
	break; }
	case s781_ErrorKind_CallNotFunction: {
	s283_append(v1_sb, "CallNotFunction");
	break; }
	case s781_ErrorKind_CallArgCountIncorrect: {
	s283_append(v1_sb, "CallArgCountIncorrect");
	break; }
	case s781_ErrorKind_CallArgTypeNotMatched: {
	s283_append(v1_sb, "CallArgTypeNotMatched");
	break; }
	case s781_ErrorKind_AssignTypeMismatch: {
	s283_append(v1_sb, "AssignTypeMismatch");
	break; }
	case s781_ErrorKind_BinaryTypeMismatch: {
	s283_append(v1_sb, "BinaryTypeMismatch");
	break; }
	case s781_ErrorKind_InvalidCast: {
	s283_append(v1_sb, "InvalidCast");
	break; }
	case s781_ErrorKind_DerefAnyPtr: {
	s283_append(v1_sb, "DerefAnyPtr");
	break; }
	case s781_ErrorKind_DerefNonPointer: {
	s283_append(v1_sb, "DerefNonPointer");
	break; }
	case s781_ErrorKind_UnaryNotBoolExpected: {
	s283_append(v1_sb, "UnaryNotBoolExpected");
	break; }
	case s781_ErrorKind_UnaryNumericExpected: {
	s283_append(v1_sb, "UnaryNumericExpected");
	break; }
	case s781_ErrorKind_ArrayTargetTypeWasNotArray: {
	s283_append(v1_sb, "ArrayTargetTypeWasNotArray");
	break; }
	case s781_ErrorKind_ArrayWasEmptyWithoutTargetType: {
	s283_append(v1_sb, "ArrayWasEmptyWithoutTargetType");
	break; }
	case s781_ErrorKind_IndexAnyPtr: {
	s283_append(v1_sb, "IndexAnyPtr");
	break; }
	case s781_ErrorKind_ExprCannotBeIndexed: {
	s283_append(v1_sb, "ExprCannotBeIndexed");
	break; }
	case s781_ErrorKind_IndexWasNotInteger: {
	s283_append(v1_sb, "IndexWasNotInteger");
	break; }
	case s781_ErrorKind_DuplicateObjectField: {
	s283_append(v1_sb, "DuplicateObjectField");
	break; }
	case s781_ErrorKind_UndefinedObjectField: {
	s283_append(v1_sb, "UndefinedObjectField");
	break; }
	case s781_ErrorKind_SymbolCannotBeConstructed: {
	s283_append(v1_sb, "SymbolCannotBeConstructed");
	break; }
	case s781_ErrorKind_UnknownSymbolForObjectInit: {
	s283_append(v1_sb, "UnknownSymbolForObjectInit");
	break; }
	case s781_ErrorKind_ObjectInitFieldTypeMismatch: {
	s283_append(v1_sb, "ObjectInitFieldTypeMismatch");
	break; }
	case s781_ErrorKind_ObjectFieldWasNotIdentifier: {
	s283_append(v1_sb, "ObjectFieldWasNotIdentifier");
	break; }
	case s781_ErrorKind_ObjectExpected: {
	s283_append(v1_sb, "ObjectExpected");
	break; }
	case s781_ErrorKind_ObjectFieldNotFound: {
	s283_append(v1_sb, "ObjectFieldNotFound");
	break; }
	case s781_ErrorKind_UnionInitOnlyOneFieldAllowed: {
	s283_append(v1_sb, "UnionInitOnlyOneFieldAllowed");
	break; }
	case s781_ErrorKind_ConstEvalNotSupported: {
	s283_append(v1_sb, "ConstEvalNotSupported");
	break; }
	case s781_ErrorKind_EnumDuplicateField: {
	s283_append(v1_sb, "EnumDuplicateField");
	break; }
	case s781_ErrorKind_EnumFieldWasNotNumber: {
	s283_append(v1_sb, "EnumFieldWasNotNumber");
	break; }
	case s781_ErrorKind_InvalidPathElement: {
	s283_append(v1_sb, "InvalidPathElement");
	break; }
	case s781_ErrorKind_TypeIdentSkippedName: {
	s283_append(v1_sb, "TypeIdentSkippedName");
	break; }
	case s781_ErrorKind_TypeIdentSymbolWasPrivate: {
	s283_append(v1_sb, "TypeIdentSymbolWasPrivate");
	break; }
	case s781_ErrorKind_TypeIdentModuleNotFound: {
	s283_append(v1_sb, "TypeIdentModuleNotFound");
	break; }
	case s781_ErrorKind_TypeIdentSymbolNotFound: {
	s283_append(v1_sb, "TypeIdentSymbolNotFound");
	break; }
	case s781_ErrorKind_PathEnumExpected: {
	s283_append(v1_sb, "Path resolved as enum variant, but symbol was not an enum.");
	break; }
	case s781_ErrorKind_PathSymbolWasPrivate: {
	s283_append(v1_sb, "PathSymbolWasPrivate");
	break; }
	case s781_ErrorKind_PathModuleNotFound: {
	s283_append(v1_sb, "PathModuleNotFound");
	break; }
	case s781_ErrorKind_PathSymbolNotFound: {
	s283_append(v1_sb, "PathSymbolNotFound");
	break; }
	case s781_ErrorKind_MatchInvalidCond: {
	s283_append(v1_sb, "MatchInvalidCond");
	break; }
	case s781_ErrorKind_MatchMultipleDefaultCase: {
	s283_append(v1_sb, "MatchMultipleDefaultCase");
	break; }
	case s781_ErrorKind_MatchMultipleValue: {
	s283_append(v1_sb, "MatchMultipleValue");
	break; }
	case s781_ErrorKind_MatchMissingDefaultCase: {
	s283_append(v1_sb, "MatchMissingDefaultCase");
	break; }
	case s781_ErrorKind_PathModuleWasPrivate: {
	s283_append(v1_sb, "PathModuleWasPrivate");
	break; }
	case s781_ErrorKind_TypeIdentModuleWasPrivate: {
	s283_append(v1_sb, "TypeIdentModuleWasPrivate");
	break; }
	case s781_ErrorKind_UnknownError: {
	s283_append(v1_sb, "UnknownError");
	break; }
	case s781_ErrorKind_GotEnumVariantWhenSymbolWasExpected: {
	s283_append(v1_sb, "GotEnumVariantWhenSymbolWasExpected");
	break; }
	case s781_ErrorKind_IdentFoundMultiple: {
	s283_append(v1_sb, "IdentFoundMultiple");
	break; }
	case s781_ErrorKind_IdentSymbolNotFound: {
	s283_append(v1_sb, "IdentSymbolNotFound");
	break; }
	case s781_ErrorKind_IdentSymbolWasPrivate: {
	s283_append(v1_sb, "IdentSymbolWasPrivate");
	break; }
	case s781_ErrorKind_IdentFoundMultiplePrivate: {
	s283_append(v1_sb, "IdentFoundMultiplePrivate");
	break; }
	default:
		abort();
}
}


#line 14 "src/codegen/objects.ib"
void s782_declaration(s366_CodegenContext * v1_context, s729_Module * v2__module, s201_UID v3_symbol) {
	#line 15
	s283_append((&((*v1_context).sb)), "typedef ");
	#line 16
	switch (s190_kind(v3_symbol)) {
	case s544_SymbolKind_Struct: {
	s283_append((&((*v1_context).sb)), "struct ");
	break; }
	case s544_SymbolKind_Union: {
	s283_append((&((*v1_context).sb)), "union ");
	break; }
	default:
 {
	s40_assert(false, "objects::declaration expected struct or union");
	break; }
}
	#line 21
	s365_codegen_symbol((&((*v1_context).sb)), v3_symbol);
	#line 22
	s283_append((&((*v1_context).sb)), " ");
	#line 23
	s365_codegen_symbol((&((*v1_context).sb)), v3_symbol);
	#line 24
	s283_append((&((*v1_context).sb)), ";\n");
}


#line 28 "src/codegen/objects.ib"
void s783_implementation(s366_CodegenContext * v1_context, s729_Module * v2__module, s201_UID v3_symbol) {
	#line 29
	if (s188_stage_eq(v3_symbol, s543_SymbolStage_ImplementationEmitted)) {
		#line 29
		return;
	}
	#line 30
	s758_ObjectDef * v4_def = (s183_get_deep(v3_symbol).object_def);
	#line 31
	for (i64 v5_i = 0l;(v5_i < ((*v4_def).field_count));v5_i += 1l) {
		#line 32
		s528_TypeIdent * v6_ty = ((((*v4_def).fields)[v5_i]).type);
		#line 33
		if ((((*v6_ty).kind) == s534_TypeKind_Array)) {
			#line 34
			v6_ty = ((((*v6_ty).data).array).parent);
		}
		#line 36
		if ((((*v6_ty).kind) == s534_TypeKind_Compound)) {
			#line 37
			s201_UID v7_field_symbol = (((*v6_ty).data).compound);
			#line 38
			s357_codegen_symbol_implementation(v1_context, v7_field_symbol);
		}
	}
	loop_exit_1:
	#line 42
	s363_sourcemap(v1_context, s193_span(v3_symbol));
	#line 43
	switch (s190_kind(v3_symbol)) {
	case s544_SymbolKind_Struct: {
	s283_append((&((*v1_context).sb)), "struct ");
	break; }
	case s544_SymbolKind_Union: {
	s283_append((&((*v1_context).sb)), "union ");
	break; }
	default:
 {
	s40_assert(false, "objects::declaration expected struct or union");
	break; }
}
	#line 48
	s365_codegen_symbol((&((*v1_context).sb)), v3_symbol);
	#line 49
	s283_append((&((*v1_context).sb)), " {\n");
	#line 50
	for (i64 v8_i = 0l;(v8_i < ((*v4_def).field_count));v8_i += 1l) {
		#line 51
		s784_implement_field(v1_context, (&(((*v4_def).fields)[v8_i])));
	}
	loop_exit_2:
	#line 54
	s283_append((&((*v1_context).sb)), "};\n\n");
	#line 55
	s187_set_stage(v3_symbol, s543_SymbolStage_ImplementationEmitted);
}


#line 59 "src/codegen/objects.ib"
void s784_implement_field(s366_CodegenContext * v1_context, s757_ObjectField * v2_field) {
	#line 63
	s284_append_char((&((*v1_context).sb)), 9u);
	#line 64
	s364_sourcemap_line(v1_context, ((*v2_field).field_span));
	#line 65
	s284_append_char((&((*v1_context).sb)), 9u);
	#line 66
	s790_codegen_field(v1_context, ((*v2_field).type), ((*v2_field).field));
	#line 67
	s283_append((&((*v1_context).sb)), ";\n");
}


#line 14 "src/codegen/enums.ib"
void s785_declaration(s366_CodegenContext * v1_context, s729_Module * v2__module, s201_UID v3_symbol) {
	#line 15
	s189_assert_kind(v3_symbol, s544_SymbolKind_Enum, "enums::declaration expected struct or union");
	#line 16
	s283_append((&((*v1_context).sb)), "typedef enum ");
	#line 17
	s365_codegen_symbol((&((*v1_context).sb)), v3_symbol);
	#line 18
	s283_append((&((*v1_context).sb)), " ");
	#line 19
	s365_codegen_symbol((&((*v1_context).sb)), v3_symbol);
	#line 20
	s283_append((&((*v1_context).sb)), ";\n");
}


#line 24 "src/codegen/enums.ib"
void s786_implementation(s366_CodegenContext * v1_context, s729_Module * v2__module, s201_UID v3_symbol) {
	#line 25
	if (s188_stage_eq(v3_symbol, s543_SymbolStage_ImplementationEmitted)) {
		#line 25
		return;
	}
	#line 26
	s189_assert_kind(v3_symbol, s544_SymbolKind_Enum, "enums::declaration expected struct or union");
	#line 28
	s363_sourcemap(v1_context, s193_span(v3_symbol));
	#line 29
	s766_EnumDef * v4_def = (s183_get_deep(v3_symbol).enum_def);
	#line 30
	s283_append((&((*v1_context).sb)), "enum ");
	#line 31
	s365_codegen_symbol((&((*v1_context).sb)), v3_symbol);
	#line 32
	s283_append((&((*v1_context).sb)), " {\n");
	#line 33
	for (i64 v5_i = 0l;(v5_i < ((*v4_def).field_count));v5_i += 1l) {
		#line 34
		s787_implement_field(v1_context, v3_symbol, (&(((*v4_def).fields)[v5_i])));
	}
	loop_exit_1:
	#line 37
	s283_append((&((*v1_context).sb)), "};\n\n");
	#line 38
	s187_set_stage(v3_symbol, s543_SymbolStage_ImplementationEmitted);
}


#line 42 "src/codegen/enums.ib"
void s787_implement_field(s366_CodegenContext * v1_context, s201_UID v2_symbol, s765_EnumField * v3_field) {
	#line 47
	s284_append_char((&((*v1_context).sb)), 9u);
	#line 48
	s364_sourcemap_line(v1_context, ((*v3_field).field_span));
	#line 49
	s284_append_char((&((*v1_context).sb)), 9u);
	#line 50
	s788_variant(v1_context, v2_symbol, v3_field);
	#line 51
	s283_append((&((*v1_context).sb)), " = ");
	#line 52
	s289_append_number((&((*v1_context).sb)), ((*v3_field).value));
	#line 53
	s283_append((&((*v1_context).sb)), ",\n");
}


#line 57 "src/codegen/enums.ib"
void s788_variant(s366_CodegenContext * v1_context, s201_UID v2_symbol, s765_EnumField * v3_field) {
	#line 62
	s365_codegen_symbol((&((*v1_context).sb)), v2_symbol);
	#line 63
	s284_append_char((&((*v1_context).sb)), 95u);
	#line 64
	s283_append((&((*v1_context).sb)), ((*v3_field).field));
}


#line 11 "src/codegen/typeident.ib"
void s789_declarations(s366_CodegenContext * v1_context) {
	#line 13
	s283_append((&((*v1_context).sb)), "#include <stdint.h>\n");
	#line 14
	s283_append((&((*v1_context).sb)), "#include <stdbool.h>\n");
	#line 15
	s283_append((&((*v1_context).sb)), "typedef uint8_t  u8;\n");
	#line 16
	s283_append((&((*v1_context).sb)), "typedef uint16_t  u16;\n");
	#line 17
	s283_append((&((*v1_context).sb)), "typedef uint32_t  u32;\n");
	#line 18
	s283_append((&((*v1_context).sb)), "typedef uint64_t  u64;\n");
	#line 21
	s283_append((&((*v1_context).sb)), "typedef int8_t   i8;\n");
	#line 22
	s283_append((&((*v1_context).sb)), "typedef int16_t  i16;\n");
	#line 23
	s283_append((&((*v1_context).sb)), "typedef int32_t  i32;\n");
	#line 24
	s283_append((&((*v1_context).sb)), "typedef int64_t  i64;\n");
	#line 27
	s283_append((&((*v1_context).sb)), "typedef float  f32;\n");
	#line 28
	s283_append((&((*v1_context).sb)), "typedef double f64;\n");
	#line 29
	s283_append((&((*v1_context).sb)), "\n");
}


#line 32 "src/codegen/typeident.ib"
void s790_codegen_field(s366_CodegenContext * v1_context, s528_TypeIdent * v2_type, char * v3_ident) {
	#line 33
	s792__codegen(v1_context, v2_type, v3_ident);
}


#line 36 "src/codegen/typeident.ib"
void s791_codegen(s366_CodegenContext * v1_context, s528_TypeIdent * v2_type) {
	#line 37
	s792__codegen(v1_context, v2_type, ((char *)NULL));
}


#line 40 "src/codegen/typeident.ib"
void s792__codegen(s366_CodegenContext * v1_context, s528_TypeIdent * v2_type, char * v3_ident) {
	#line 43
	switch (((*v2_type).kind)) {
	case s534_TypeKind_Atomic: {
	s793_atomic(v1_context, (((*v2_type).data).atomic));
	break; }
	case s534_TypeKind_Compound: {
	s365_codegen_symbol((&((*v1_context).sb)), (((*v2_type).data).compound));
	break; }
	case s534_TypeKind_Pointer: {
		#line 49
		if (((((*v2_type).data).pointer) != ((s528_TypeIdent *)NULL))) {
			#line 50
			s792__codegen(v1_context, (((*v2_type).data).pointer), ((char *)NULL));
		} else {
#line 52
			s283_append((&((*v1_context).sb)), "void");
		}
		#line 54
		s283_append((&((*v1_context).sb)), " *");
	break; }
	case s534_TypeKind_Array: {
	s792__codegen(v1_context, ((((*v2_type).data).array).parent), ((char *)NULL));
	break; }
	case s534_TypeKind_Function: {
		#line 59
		s795_func_flow_type(v1_context, ((((*v2_type).data).function).return_ty));
		#line 60
		s283_append((&((*v1_context).sb)), " (*");
	break; }
	default:
		abort();
}
	#line 63
	if ((v3_ident != ((char *)NULL))) {
		#line 64
		s284_append_char((&((*v1_context).sb)), 32u);
		#line 65
		s283_append((&((*v1_context).sb)), v3_ident);
	}
	#line 67
	if ((((*v2_type).kind) == s534_TypeKind_Function)) {
		#line 68
		s283_append((&((*v1_context).sb)), ")");
		#line 69
		s794_func(v1_context, (((*v2_type).data).function));
	}
	#line 71
	if ((((*v2_type).kind) == s534_TypeKind_Array)) {
		#line 72
		for (i64 v4_i = 0l;(v4_i < ((((*v2_type).data).array).dimension_length));v4_i += 1l) {
			#line 73
			s284_append_char((&((*v1_context).sb)), 91u);
			#line 74
			s289_append_number((&((*v1_context).sb)), (((((*v2_type).data).array).dimensions)[v4_i]));
			#line 75
			s284_append_char((&((*v1_context).sb)), 93u);
		}
		loop_exit_1:
	}
}


#line 81 "src/codegen/typeident.ib"
void s793_atomic(s366_CodegenContext * v1_context, s535_AtomicType v2_atomic) {
	#line 82
	switch (v2_atomic) {
	case s535_AtomicType_Bool: {
	s283_append((&((*v1_context).sb)), "bool");
	break; }
	case s535_AtomicType_U8: {
	s283_append((&((*v1_context).sb)), "char");
	break; }
	case s535_AtomicType_I8: {
	s283_append((&((*v1_context).sb)), "char");
	break; }
	case s535_AtomicType_U16: {
	s283_append((&((*v1_context).sb)), "u16");
	break; }
	case s535_AtomicType_U32: {
	s283_append((&((*v1_context).sb)), "u32");
	break; }
	case s535_AtomicType_U64: {
	s283_append((&((*v1_context).sb)), "u64");
	break; }
	case s535_AtomicType_U128: {
	s283_append((&((*v1_context).sb)), "u128");
	break; }
	case s535_AtomicType_I16: {
	s283_append((&((*v1_context).sb)), "i16");
	break; }
	case s535_AtomicType_I32: {
	s283_append((&((*v1_context).sb)), "int");
	break; }
	case s535_AtomicType_I64: {
	s283_append((&((*v1_context).sb)), "i64");
	break; }
	case s535_AtomicType_I128: {
	s283_append((&((*v1_context).sb)), "i128");
	break; }
	case s535_AtomicType_F32: {
	s283_append((&((*v1_context).sb)), "f32");
	break; }
	case s535_AtomicType_F64: {
	s283_append((&((*v1_context).sb)), "f64");
	break; }
	default:
		abort();
}
}


#line 103 "src/codegen/typeident.ib"
void s794_func(s366_CodegenContext * v1_context, s530_FunctionType v2_func) {
	#line 104
	s284_append_char((&((*v1_context).sb)), 40u);
	#line 105
	for (i64 v3_i = 0l;(v3_i < (v2_func.args_length));v3_i += 1l) {
		#line 106
		if ((v3_i > 0l)) {
			#line 106
			s283_append((&((*v1_context).sb)), ", ");
		}
		#line 107
		s791_codegen(v1_context, ((v2_func.args)[v3_i]));
	}
	loop_exit_1:
	#line 109
	if ((v2_func.has_varargs)) {
		#line 110
		s283_append((&((*v1_context).sb)), ", ...");
	}
	#line 112
	s284_append_char((&((*v1_context).sb)), 41u);
}


#line 115 "src/codegen/typeident.ib"
void s795_func_flow_type(s366_CodegenContext * v1_context, s527_FlowType v2_flow) {
	#line 116
	switch ((v2_flow.kind)) {
	case s533_FlowTypeKind_Void: {
		#line 118
		s283_append((&((*v1_context).sb)), "void");
	break; }
	case s533_FlowTypeKind_Never: {
		#line 121
		s283_append((&((*v1_context).sb)), "void");
	break; }
	case s533_FlowTypeKind_Some: {
		#line 124
		s790_codegen_field(v1_context, (v2_flow.type), ((char *)NULL));
	break; }
	default:
		abort();
}
}


#line 14 "src/codegen/function.ib"
void s796_declaration(s366_CodegenContext * v1_context, s729_Module * v2_module, s201_UID v3_symbol) {
	#line 15
	s189_assert_kind(v3_symbol, s544_SymbolKind_Function, "codegen::function::decl but was not function");
	#line 16
	s741_Prototype * v4_proto = ((s741_Prototype *)NULL);
	#line 17
	if (s191_is_extern(v3_symbol)) {
		#line 18
		s363_sourcemap(v1_context, s193_span(v3_symbol));
		#line 19
		s283_append((&((*v1_context).sb)), "extern ");
		#line 20
		v4_proto = (&((*(s183_get_deep(v3_symbol).extern_func)).proto));
	} else {
#line 22
		v4_proto = (&((*(s183_get_deep(v3_symbol).func)).proto));
	}
	#line 25
	s798_prototype(v1_context, v2_module, v3_symbol, v4_proto);
	#line 26
	s283_append((&((*v1_context).sb)), ";\n");
}


#line 30 "src/codegen/function.ib"
void s797_implementation(s366_CodegenContext * v1_context, s729_Module * v2_module, s201_UID v3_symbol) {
	#line 31
	if (s188_stage_eq(v3_symbol, s543_SymbolStage_ImplementationEmitted)) {
		#line 31
		return;
	}
	#line 32
	s189_assert_kind(v3_symbol, s544_SymbolKind_Function, "codegen::function::impl but was not function");
	#line 33
	if (s191_is_extern(v3_symbol)) {
		#line 34
		s187_set_stage(v3_symbol, s543_SymbolStage_ImplementationEmitted);
		#line 35
		return;
	}
	#line 37
	s363_sourcemap(v1_context, s193_span(v3_symbol));
	#line 38
	s741_Prototype v4_proto = ((*(s183_get_deep(v3_symbol).func)).proto);
	#line 39
	s798_prototype(v1_context, v2_module, v3_symbol, (&v4_proto));
	#line 41
	s283_append((&((*v1_context).sb)), " {\n");
	#line 42
	s1028_FunctionContext v5_fn_context = s1021_create_context(v1_context, v2_module);
	#line 43
	s739_Function * v6_func = (s183_get_deep(v3_symbol).func);
	#line 44
	s1024_codegen((&v5_fn_context), ((*v6_func).body));
	#line 45
	s283_append((&((*v1_context).sb)), "}\n\n\n");
	#line 46
	s1022_free_context((&v5_fn_context));
	#line 47
	s187_set_stage(v3_symbol, s543_SymbolStage_ImplementationEmitted);
}


#line 51 "src/codegen/function.ib"
void s798_prototype(s366_CodegenContext * v1_context, s729_Module * v2_module, s201_UID v3_symbol, s741_Prototype * v4_proto) {
	#line 52
	s365_codegen_symbol((&((*v1_context).work_sb)), v3_symbol);
	#line 53
	s799_flow_type(v1_context, ((*v4_proto).return_type), s294_merge((&((*v1_context).work_sb))));
	#line 54
	s295_reset((&((*v1_context).work_sb)));
	#line 56
	s284_append_char((&((*v1_context).sb)), 40u);
	#line 57
	for (i64 v5_i = 0l;(v5_i < ((*v4_proto).arg_count));v5_i += 1l) {
		#line 58
		if ((v5_i > 0l)) {
			#line 58
			s283_append((&((*v1_context).sb)), ", ");
		}
		#line 59
		i64 v6_idx = (((*v4_proto).arg_index) + v5_i);
		#line 60
		s742_Arg * v7_arg = ((s742_Arg *)s251_get((&((*v2_module).args)), v6_idx));
		#line 61
		s1026_variable((&((*v1_context).work_sb)), (v5_i + 1l), ((*v7_arg).ident));
		#line 62
		char * v8_ident = s294_merge((&((*v1_context).work_sb)));
		#line 63
		s790_codegen_field(v1_context, ((*v7_arg).type), v8_ident);
		#line 68
		s295_reset((&((*v1_context).work_sb)));
	}
	loop_exit_1:
	#line 70
	if (((*v4_proto).has_varargs)) {
		#line 71
		if ((((*v4_proto).arg_count) > 0l)) {
			#line 72
			s283_append((&((*v1_context).sb)), ", ");
		}
		#line 74
		s283_append((&((*v1_context).sb)), "...");
	}
	#line 76
	s284_append_char((&((*v1_context).sb)), 41u);
}


#line 80 "src/codegen/function.ib"
void s799_flow_type(s366_CodegenContext * v1_context, s527_FlowType v2_flow, char * v3_ident) {
	#line 81
	switch ((v2_flow.kind)) {
	case s533_FlowTypeKind_Void: {
		#line 83
		s283_append((&((*v1_context).sb)), "void");
		#line 84
		if ((v3_ident != ((char *)NULL))) {
			#line 85
			s284_append_char((&((*v1_context).sb)), 32u);
			#line 86
			s283_append((&((*v1_context).sb)), v3_ident);
		}
	break; }
	case s533_FlowTypeKind_Never: {
		#line 90
		s283_append((&((*v1_context).sb)), "void");
		#line 91
		if ((v3_ident != ((char *)NULL))) {
			#line 92
			s284_append_char((&((*v1_context).sb)), 32u);
			#line 93
			s283_append((&((*v1_context).sb)), v3_ident);
		}
	break; }
	case s533_FlowTypeKind_Some: {
		#line 97
		s790_codegen_field(v1_context, (v2_flow.type), v3_ident);
		#line 102
		return;
	break; }
	default:
		abort();
}
}


#line 15 "src/codegen/global.ib"
void s800_declaration(s366_CodegenContext * v1_context, s729_Module * v2__module, s201_UID v3_symbol) {
	#line 16
	s189_assert_kind(v3_symbol, s544_SymbolKind_Global, "codegen::global::decl but was not function");
	#line 17
	if (s191_is_extern(v3_symbol)) {
		#line 18
		s772_ExternGlobal * v4_extern_global = (s183_get_deep(v3_symbol).extern_global);
		#line 19
		s363_sourcemap(v1_context, s193_span(v3_symbol));
		#line 20
		s283_append((&((*v1_context).sb)), "extern ");
		#line 21
		s790_codegen_field(v1_context, ((*v4_extern_global).type), ((*v4_extern_global).name));
		#line 26
		s283_append((&((*v1_context).sb)), ";\n");
		#line 27
		return;
	}
	#line 30
	s771_Global * v5_global = (s183_get_deep(v3_symbol).global);
	#line 32
	s365_codegen_symbol((&((*v1_context).work_sb)), v3_symbol);
	#line 33
	s790_codegen_field(v1_context, ((*v5_global).type), s294_merge((&((*v1_context).work_sb))));
	#line 38
	s295_reset((&((*v1_context).work_sb)));
	#line 39
	s283_append((&((*v1_context).sb)), ";\n");
}


#line 43 "src/codegen/global.ib"
void s801_implementation(s366_CodegenContext * v1_context, s729_Module * v2_module, s201_UID v3_symbol) {
	#line 44
	s189_assert_kind(v3_symbol, s544_SymbolKind_Global, "codegen::global::decl but was not function");
	#line 45
	if (s191_is_extern(v3_symbol)) {
		#line 46
		s187_set_stage(v3_symbol, s543_SymbolStage_ImplementationEmitted);
		#line 47
		return;
	}
	#line 50
	s363_sourcemap(v1_context, s193_span(v3_symbol));
	#line 51
	s771_Global * v4_global = (s183_get_deep(v3_symbol).global);
	#line 52
	s365_codegen_symbol((&((*v1_context).work_sb)), v3_symbol);
	#line 53
	s790_codegen_field(v1_context, ((*v4_global).type), s294_merge((&((*v1_context).work_sb))));
	#line 58
	s295_reset((&((*v1_context).work_sb)));
	#line 59
	s283_append((&((*v1_context).sb)), " = ");
	#line 61
	s1028_FunctionContext v5_fn_context = s1021_create_context(v1_context, v2_module);
	#line 62
	s1024_codegen((&v5_fn_context), ((*v4_global).value));
	#line 63
	s1022_free_context((&v5_fn_context));
	#line 65
	s283_append((&((*v1_context).sb)), ";\n");
}


#line 12 "src/lsp/response.ib"
s824_Builder s802_new(i64 * v1_log) {
	#line 13
	return ((s824_Builder){
		.log = v1_log,
		.stream = ((i64 *)stdout),
		.sb = s279_with_capacity(1024l)
	});
}


#line 20 "src/lsp/response.ib"
void s803_free(s824_Builder * v1_builder) {
	#line 21
	s278_free((&((*v1_builder).sb)));
}


#line 25 "src/lsp/response.ib"
void s804_send(s824_Builder * v1_builder) {
	#line 26
	i64 v2_length = (((*v1_builder).sb).length);
	#line 27
	char * v3_merged = s294_merge((&((*v1_builder).sb)));
	#line 28
	fprintf(((void *)((*v1_builder).stream)), "Content-Length: %d\r\n\r\n%s", v2_length, v3_merged);
	#line 33
	fflush(((void *)((*v1_builder).stream)));
	#line 34
	fprintf(((void *)((*v1_builder).log)), "[LOG] Sending Response: \nContent-Length: %d\n\n%s\n\n", v2_length, v3_merged);
	#line 39
	s295_reset((&((*v1_builder).sb)));
}


#line 43 "src/lsp/response.ib"
void s805_key(s824_Builder * v1_builder, char * v2_name) {
	#line 44
	s823_raw(v1_builder, "\"");
	#line 45
	s823_raw(v1_builder, v2_name);
	#line 46
	s823_raw(v1_builder, "\":");
}


#line 49 "src/lsp/response.ib"
void s806_id(s824_Builder * v1_builder, i64 v2_value) {
	#line 49
	s805_key(v1_builder, "id");
	#line 49
	s822_number(v1_builder, v2_value);
}


#line 50 "src/lsp/response.ib"
void s807_begin_result(s824_Builder * v1_builder) {
	#line 50
	s805_key(v1_builder, "result");
	#line 50
	s815_begin_object(v1_builder);
}


#line 51 "src/lsp/response.ib"
void s808_end_result(s824_Builder * v1_builder) {
	#line 51
	s816_end_object(v1_builder);
}


#line 53 "src/lsp/response.ib"
void s809_method(s824_Builder * v1_builder, char * v2_method) {
	#line 53
	s805_key(v1_builder, "method");
	#line 53
	s821_string(v1_builder, v2_method);
}


#line 54 "src/lsp/response.ib"
void s810_begin_params(s824_Builder * v1_builder) {
	#line 54
	s805_key(v1_builder, "params");
	#line 54
	s815_begin_object(v1_builder);
}


#line 55 "src/lsp/response.ib"
void s811_end_params(s824_Builder * v1_builder) {
	#line 55
	s816_end_object(v1_builder);
}


#line 57 "src/lsp/response.ib"
void s812_begin(s824_Builder * v1_builder) {
	#line 57
	s815_begin_object(v1_builder);
}


#line 58 "src/lsp/response.ib"
void s813_end(s824_Builder * v1_builder) {
	#line 58
	s816_end_object(v1_builder);
}


#line 59 "src/lsp/response.ib"
void s814_sep(s824_Builder * v1_builder) {
	#line 59
	s823_raw(v1_builder, ",");
}


#line 60 "src/lsp/response.ib"
void s815_begin_object(s824_Builder * v1_builder) {
	#line 60
	s823_raw(v1_builder, "{");
}


#line 61 "src/lsp/response.ib"
void s816_end_object(s824_Builder * v1_builder) {
	#line 61
	s823_raw(v1_builder, "}");
}


#line 62 "src/lsp/response.ib"
void s817_begin_array(s824_Builder * v1_builder) {
	#line 62
	s823_raw(v1_builder, "[");
}


#line 63 "src/lsp/response.ib"
void s818_end_array(s824_Builder * v1_builder) {
	#line 63
	s823_raw(v1_builder, "]");
}


#line 64 "src/lsp/response.ib"
void s819_nil(s824_Builder * v1_builder) {
	#line 64
	s823_raw(v1_builder, "null");
}


#line 65 "src/lsp/response.ib"
void s820_boolean(s824_Builder * v1_builder, bool v2_value) {
	#line 66
	if (v2_value) {
		#line 66
		s823_raw(v1_builder, "true");
	} else {
#line 67
		s823_raw(v1_builder, "false");
	}
}


#line 70 "src/lsp/response.ib"
void s821_string(s824_Builder * v1_builder, char * v2_s) {
	#line 71
	s823_raw(v1_builder, "\"");
	#line 72
	s823_raw(v1_builder, v2_s);
	#line 73
	s823_raw(v1_builder, "\"");
}


#line 76 "src/lsp/response.ib"
void s822_number(s824_Builder * v1_builder, i64 v2_num) {
	#line 76
	s289_append_number((&((*v1_builder).sb)), v2_num);
}


#line 77 "src/lsp/response.ib"
void s823_raw(s824_Builder * v1_builder, char * v2_s) {
	#line 77
	s283_append((&((*v1_builder).sb)), v2_s);
}


#line 110 "src/typecheck/node.ib"
s845_NodeResult s827_typecheck(s743_FunctionContext * v1_context, i64 v2_node) {
	#line 111
	s587_Node * v3_node = s578_get((&((*((*v1_context).module)).nodes)), v2_node);
	#line 113
	switch (((*v3_node).kind)) {
	case s589_NodeKind_None: {
		#line 115
		s40_assert(false, "typecheck::node::NodeKind::None");
		#line 116
		return ((s845_NodeResult){

		});
	break; }
	case s589_NodeKind_Literal: {
	return s828_some(s851_typecheck(v1_context, (((*v3_node).data).literal), ((*v3_node).span)));
	break; }
	case s589_NodeKind_Binary: {
	return s828_some(s1029_typecheck(v1_context, (((*v3_node).data).binary), ((*v3_node).span)));
	break; }
	case s589_NodeKind_Unary: {
	return s1043_typecheck(v1_context, (((*v3_node).data).unary), ((*v3_node).span));
	break; }
	case s589_NodeKind_Ident: {
	return s828_some(s1054_typecheck_ident(v1_context, (((*v3_node).data).ident), ((*v3_node).span)));
	break; }
	case s589_NodeKind_Cast: {
	return s828_some(s1100_explicit(v1_context, (((*v3_node).data).cast), ((*v3_node).span)));
	break; }
	case s589_NodeKind_Call: {
	return s1053_typecheck_call(v1_context, (((*v3_node).data).call), ((*v3_node).span));
	break; }
	case s589_NodeKind_SizeOf: {
	return s828_some(s1055_typecheck_sizeof(v1_context, (((*v3_node).data).size_of), ((*v3_node).span)));
	break; }
	case s589_NodeKind_ObjectInit: {
	return s828_some(s1085_typecheck_objectinit(v1_context, (((*v3_node).data).object), ((*v3_node).span)));
	break; }
	case s589_NodeKind_Array: {
	return s828_some(s1076_typecheck(v1_context, (((*v3_node).data).array), ((*v3_node).span)));
	break; }
	case s589_NodeKind_Block: {
	return s996_typecheck_block(v1_context, (((*v3_node).data).block), ((*v3_node).span));
	break; }
	case s589_NodeKind_ConstDecl: {
		#line 133
		return s997_typecheck_vardecl_statement(v1_context, (((*v3_node).data).var_declaration), false, ((*v3_node).span));
	break; }
	case s589_NodeKind_VarDecl: {
		#line 138
		return s997_typecheck_vardecl_statement(v1_context, (((*v3_node).data).var_declaration), true, ((*v3_node).span));
	break; }
	case s589_NodeKind_Break: {
	return s1005_typecheck_break(v1_context, ((*v3_node).span));
	break; }
	case s589_NodeKind_Continue: {
	return s1006_typecheck_continue(v1_context, ((*v3_node).span));
	break; }
	case s589_NodeKind_Return: {
	return s1000_typecheck_return(v1_context, (((*v3_node).data).retrn), ((*v3_node).span));
	break; }
	case s589_NodeKind_If: {
	return s1002_typecheck_if(v1_context, (((*v3_node).data).if_data), ((*v3_node).span));
	break; }
	case s589_NodeKind_Match: {
	return s1067_typecheck(v1_context, (((*v3_node).data).match_data), ((*v3_node).span));
	break; }
	case s589_NodeKind_Loop: {
	return s1003_typecheck_loop(v1_context, (((*v3_node).data).loop_data), ((*v3_node).span));
	break; }
	case s589_NodeKind_For: {
	return s1004_typecheck_for(v1_context, (((*v3_node).data).for_data), ((*v3_node).span));
	break; }
	default:
		abort();
}
}


#line 153 "src/typecheck/node.ib"
s845_NodeResult s828_some(i64 v1_node) {
	#line 153
	return s829_result(v1_node, s850_NodeFlow_Some);
}


#line 154 "src/typecheck/node.ib"
s845_NodeResult s829_result(i64 v1_node, s850_NodeFlow v2_flow) {
	#line 154
	return ((s845_NodeResult){
		.node = v1_node,
		.flow = v2_flow
	});
}


#line 157 "src/typecheck/node.ib"
void s830_assert_nodeflow_sort() {
	#line 158
	s40_assert((s850_NodeFlow_Some < s850_NodeFlow_Never), "NodeFlow invalid sorting");
	#line 159
	s40_assert((s850_NodeFlow_Some < s850_NodeFlow_Return), "NodeFlow invalid sorting");
	#line 160
	s40_assert((s850_NodeFlow_Some < s850_NodeFlow_Break), "NodeFlow invalid sorting");
	#line 161
	s40_assert((s850_NodeFlow_Some < s850_NodeFlow_Continue), "NodeFlow invalid sorting");
	#line 162
	s40_assert((s850_NodeFlow_Continue < s850_NodeFlow_Never), "NodeFlow invalid sorting");
	#line 163
	s40_assert((s850_NodeFlow_Continue < s850_NodeFlow_Return), "NodeFlow invalid sorting");
	#line 164
	s40_assert((s850_NodeFlow_Continue < s850_NodeFlow_Break), "NodeFlow invalid sorting");
	#line 165
	s40_assert((s850_NodeFlow_Break < s850_NodeFlow_Never), "NodeFlow invalid sorting");
	#line 166
	s40_assert((s850_NodeFlow_Break < s850_NodeFlow_Return), "NodeFlow invalid sorting");
	#line 167
	s40_assert((s850_NodeFlow_Return < s850_NodeFlow_Never), "NodeFlow invalid sorting");
}


#line 170 "src/typecheck/node.ib"
s850_NodeFlow s831_flow_from_typeident(s527_FlowType v1_type) {
	#line 171
	switch ((v1_type.kind)) {
	case s533_FlowTypeKind_Never: {
	return s850_NodeFlow_Never;
	break; }
	case s533_FlowTypeKind_Void: {
	return s850_NodeFlow_Some;
	break; }
	case s533_FlowTypeKind_Some: {
	return s850_NodeFlow_Some;
	break; }
	default:
		abort();
}
}


#line 178 "src/typecheck/node.ib"
s850_NodeFlow s832_flow_any(s850_NodeFlow v1_lhs, s850_NodeFlow v2_rhs) {
	#line 179
	s830_assert_nodeflow_sort();
	#line 180
	if ((v1_lhs < v2_rhs)) {
		#line 180
		return v1_lhs;
	}
	#line 181
	return v2_rhs;
}


#line 184 "src/typecheck/node.ib"
s850_NodeFlow s833_flow_all(s850_NodeFlow v1_lhs, s850_NodeFlow v2_rhs) {
	#line 185
	s830_assert_nodeflow_sort();
	#line 186
	if ((v1_lhs > v2_rhs)) {
		#line 186
		return v1_lhs;
	}
	#line 187
	return v2_rhs;
}


#line 199 "src/typecheck/node.ib"
s846_Nodes s834_new() {
	#line 200
	s257_Vec v1_nodes = s243_new(((i64)64ul), 256l);
	#line 201
	s566_Arena v2_extras = s560_new(256l);
	#line 202
	s249_push((&v1_nodes));
	#line 204
	return ((s846_Nodes){
		.nodes = v1_nodes,
		.extras = v2_extras
	});
}


#line 206 "src/typecheck/node.ib"
void s835_free(s846_Nodes * v1_nodes) {
	#line 207
	s246_free((&((*v1_nodes).nodes)));
	#line 208
	s562_free((&((*v1_nodes).extras)));
}


#line 211 "src/typecheck/node.ib"
s844_Node * s836_get(s846_Nodes * v1_nodes, i64 v2_index) {
	#line 212
	s40_assert((v2_index != s826_ERROR), "node::get ERROR was passed!");
	#line 213
	s40_assert((v2_index != s825_NONE), "node::get NONE was passed!");
	#line 214
	return ((s844_Node *)s251_get((&((*v1_nodes).nodes)), v2_index));
}


#line 216 "src/typecheck/node.ib"
s844_Node * s837_try_get(s846_Nodes * v1_nodes, i64 v2_index) {
	#line 217
	if (((v2_index == s826_ERROR) || (v2_index == s825_NONE))) {
		#line 217
		return ((s844_Node *)NULL);
	}
	#line 218
	return ((s844_Node *)s251_get((&((*v1_nodes).nodes)), v2_index));
}


#line 221 "src/typecheck/node.ib"
i64 s838_push_simple(s846_Nodes * v1_nodes, s848_NodeKind v2_kind, i64 v3_span) {
	#line 226
	return s839_push(v1_nodes, v2_kind, ((s528_TypeIdent *)NULL), ((s847_NodeData){
		.expr = s825_NONE
	}), v3_span);
}


#line 228 "src/typecheck/node.ib"
i64 s839_push(s846_Nodes * v1_nodes, s848_NodeKind v2_kind, s528_TypeIdent * v3_ty, s847_NodeData v4_data, i64 v5_span) {
	#line 235
	i64 v6_index = (((*v1_nodes).nodes).count);
	#line 236
	s844_Node * v7_node = ((s844_Node *)s249_push((&((*v1_nodes).nodes))));
	#line 237
	((*v7_node).kind) = v2_kind;
	#line 238
	((*v7_node).ty) = v3_ty;
	#line 239
	((*v7_node).data) = v4_data;
	#line 240
	((*v7_node).span) = v5_span;
	#line 241
	return v6_index;
}


#line 244 "src/typecheck/node.ib"
void * s840_allocate_extra(s846_Nodes * v1_nodes, i64 v2_size) {
	#line 245
	if ((v2_size == 0l)) {
		#line 245
		return NULL;
	}
	#line 246
	s40_assert((v2_size > 0l), "allocate_extra size less than zero!");
	#line 247
	return s561_allocate((&((*v1_nodes).extras)), v2_size);
}


#line 255 "src/typecheck/node.ib"
void s841_print(s846_Nodes * v1_nodes, i64 v2_node) {
	#line 256
	s299_StringBuilder v3_sb = s277_new();
	#line 257
	s842_debug((&v3_sb), v1_nodes, v2_node, 0l);
	#line 258
	puts(s294_merge((&v3_sb)));
	#line 259
	s278_free((&v3_sb));
}


#line 262 "src/typecheck/node.ib"
void s842_debug(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, i64 v3_node, i64 v4_depth) {
	#line 263
	if ((v3_node == s825_NONE)) {
		#line 264
		s843_debug_simple(v1_sb, "NONE", v4_depth);
		#line 265
		return;
	}
	#line 267
	if ((v3_node == s826_ERROR)) {
		#line 268
		s843_debug_simple(v1_sb, "ERROR", v4_depth);
		#line 269
		return;
	}
	#line 272
	s844_Node * v5_n = s836_get(v2_nodes, v3_node);
	#line 273
	void * v6_data = ((void *)(&((*v5_n).data)));
	#line 274
	switch (((*v5_n).kind)) {
	case s848_NodeKind_None: {
	break; }
	case s848_NodeKind_Literal: {
	s856_debug(v1_sb, ((s857_Literal *)v6_data), v4_depth);
	break; }
	case s848_NodeKind_Match: {
	s1071_debug(v1_sb, v2_nodes, ((s1072_MatchData *)v6_data), v4_depth);
	break; }
	case s848_NodeKind_Variable: {
	s1058_debug_variable(v1_sb, v2_nodes, ((s1065_Variable *)v6_data), ((*v5_n).ty), v4_depth);
	break; }
	case s848_NodeKind_Symbol: {
	s1059_debug_symbol(v1_sb, v2_nodes, ((s201_UID *)v6_data), v4_depth);
	break; }
	case s848_NodeKind_Binary: {
	s1037_debug(v1_sb, v2_nodes, ((s1039_Binary *)v6_data), v4_depth);
	break; }
	case s848_NodeKind_Unary: {
	s1048_debug_unary(v1_sb, v2_nodes, ((s1051_Unary *)v6_data), v4_depth);
	break; }
	case s848_NodeKind_Ref: {
	s1050_debug_ref(v1_sb, v2_nodes, ((i64 *)v6_data), v4_depth);
	break; }
	case s848_NodeKind_Deref: {
	s1049_debug_deref(v1_sb, v2_nodes, ((i64 *)v6_data), v4_depth);
	break; }
	case s848_NodeKind_Assign: {
	s1038_debug_assign(v1_sb, v2_nodes, ((s1040_Assign *)v6_data), v4_depth);
	break; }
	case s848_NodeKind_Cast: {
	s1112_debug(v1_sb, v2_nodes, ((s1113_Cast *)v6_data), v4_depth);
	break; }
	case s848_NodeKind_Array: {
	s1080_debug_array(v1_sb, v2_nodes, ((s1083_Array *)v6_data), v4_depth);
	break; }
	case s848_NodeKind_Index: {
	s1082_debug_index(v1_sb, v2_nodes, ((s1084_Index *)v6_data), v4_depth);
	break; }
	case s848_NodeKind_StructInit: {
	s1090_debug_struct_init(v1_sb, v2_nodes, ((s1096_ObjectInit *)v6_data), v4_depth);
	break; }
	case s848_NodeKind_UnionInit: {
	s1091_debug_union_init(v1_sb, v2_nodes, ((s1096_ObjectInit *)v6_data), v4_depth);
	break; }
	case s848_NodeKind_StructFieldLookup: {
	s1093_debug_struct_lookup(v1_sb, v2_nodes, ((s1098_FieldLookup *)v6_data), v4_depth);
	break; }
	case s848_NodeKind_UnionFieldLookup: {
	s1094_debug_union_lookup(v1_sb, v2_nodes, ((s1098_FieldLookup *)v6_data), v4_depth);
	break; }
	case s848_NodeKind_Call: {
	s1060_debug_call(v1_sb, v2_nodes, ((s1064_Call *)v6_data), v4_depth);
	break; }
	case s848_NodeKind_EnumValue: {
	s1061_debug_enum_val(v1_sb, v2_nodes, ((s1066_EnumValue *)v6_data), v4_depth);
	break; }
	case s848_NodeKind_Load: {
	s1062_debug_load(v1_sb, v2_nodes, ((i64 *)v6_data), v4_depth);
	break; }
	case s848_NodeKind_ObjectCopy: {
	s1063_debug_object_copy(v1_sb, v2_nodes, ((i64 *)v6_data), v4_depth);
	break; }
	case s848_NodeKind_Block: {
	s1008_debug_block(v1_sb, v2_nodes, ((s1017_BlockData *)v6_data), v4_depth);
	break; }
	case s848_NodeKind_ConstDecl: {
	s1009_debug_var_decl(v1_sb, v2_nodes, false, ((s1018_VarDeclaration *)v6_data), v4_depth);
	break; }
	case s848_NodeKind_VarDecl: {
	s1009_debug_var_decl(v1_sb, v2_nodes, true, ((s1018_VarDeclaration *)v6_data), v4_depth);
	break; }
	case s848_NodeKind_Break: {
	s843_debug_simple(v1_sb, "BREAK", v4_depth);
	break; }
	case s848_NodeKind_Continue: {
	s843_debug_simple(v1_sb, "CONTINUE", v4_depth);
	break; }
	case s848_NodeKind_Return: {
	s1012_debug_return(v1_sb, v2_nodes, ((s1019_ReturnData *)v6_data), v4_depth);
	break; }
	case s848_NodeKind_If: {
	s1010_debug_if(v1_sb, v2_nodes, ((s1016_IfData *)v6_data), v4_depth);
	break; }
	case s848_NodeKind_Loop: {
	s1011_debug_loop(v1_sb, v2_nodes, ((s1015_LoopData *)v6_data), v4_depth);
	break; }
	case s848_NodeKind_For: {
	s1013_debug_for(v1_sb, v2_nodes, ((s1014_ForData * *)v6_data), v4_depth);
	break; }
	default:
		abort();
}
}


#line 314 "src/typecheck/node.ib"
void s843_debug_simple(s299_StringBuilder * v1_sb, char * v2_label, i64 v3_depth) {
	#line 315
	s288_repeat(v1_sb, "  ", v3_depth);
	#line 316
	s283_append(v1_sb, v2_label);
	#line 317
	s283_append(v1_sb, "\n");
}


#line 43 "src/typecheck/literal.ib"
i64 s851_typecheck(s743_FunctionContext * v1_context, s895_Literal v2_data, i64 v3_span) {
	#line 48
	s528_TypeIdent * v4_type = s855_into_typeident(((*v1_context).parent), v2_data);
	#line 49
	s857_Literal v5_literal = s852_from_ast_literal(v2_data);
	#line 50
	return s839_push(((*v1_context).nodes), s848_NodeKind_Literal, v4_type, ((s847_NodeData){
		.literal = v5_literal
	}), v3_span);
}


#line 57 "src/typecheck/literal.ib"
s857_Literal s852_from_ast_literal(s895_Literal v1_data) {
	#line 58
	switch ((v1_data.kind)) {
	case s899_LiteralKind_Number: {
		#line 60
		s858_LiteralValue v2_value = ((s858_LiteralValue){
			.number = ((v1_data.value).number)
		});
		#line 61
		return ((s857_Literal){
			.value = v2_value,
			.kind = s859_LiteralKind_I64
		});
	break; }
	case s899_LiteralKind_Float: {
		#line 64
		s858_LiteralValue v3_value = ((s858_LiteralValue){
			.flt = ((v1_data.value).flt)
		});
		#line 65
		return ((s857_Literal){
			.value = v3_value,
			.kind = s859_LiteralKind_F64
		});
	break; }
	case s899_LiteralKind_Char: {
		#line 68
		s858_LiteralValue v4_value = ((s858_LiteralValue){
			.chr = ((v1_data.value).chr)
		});
		#line 69
		return ((s857_Literal){
			.value = v4_value,
			.kind = s859_LiteralKind_U8
		});
	break; }
	case s899_LiteralKind_Bool: {
		#line 72
		s858_LiteralValue v5_value = ((s858_LiteralValue){
			.boolean = ((v1_data.value).boolean)
		});
		#line 73
		return ((s857_Literal){
			.value = v5_value,
			.kind = s859_LiteralKind_Bool
		});
	break; }
	case s899_LiteralKind_Null: {
		#line 76
		s858_LiteralValue v6_value = ((s858_LiteralValue){
			.number = 0l
		});
		#line 77
		return ((s857_Literal){
			.value = v6_value,
			.kind = s859_LiteralKind_Null
		});
	break; }
	case s899_LiteralKind_String: {
		#line 80
		s858_LiteralValue v7_value = ((s858_LiteralValue){
			.string = ((v1_data.value).string)
		});
		#line 81
		return ((s857_Literal){
			.value = v7_value,
			.kind = s859_LiteralKind_String
		});
	break; }
	default:
		abort();
}
}


#line 86 "src/typecheck/literal.ib"
s857_Literal s853_from_int(i64 v1_number) {
	#line 87
	s858_LiteralValue v2_value = ((s858_LiteralValue){
		.number = v1_number
	});
	#line 88
	return ((s857_Literal){
		.value = v2_value,
		.kind = s859_LiteralKind_I64
	});
}


#line 91 "src/typecheck/literal.ib"
i64 s854_into_int(s857_Literal v1_literal, bool * v2_is_ok) {
	#line 92
	(*v2_is_ok) = true;
	#line 93
	switch ((v1_literal.kind)) {
	case s859_LiteralKind_U8: {
	return ((i64)((v1_literal.value).chr));
	break; }
	case s859_LiteralKind_I8: {
	return ((i64)((v1_literal.value).chr));
	break; }
	case s859_LiteralKind_U16:
	case s859_LiteralKind_U32:
	case s859_LiteralKind_U64:
	case s859_LiteralKind_U128:
	case s859_LiteralKind_I16:
	case s859_LiteralKind_I32:
	case s859_LiteralKind_I64:
	case s859_LiteralKind_I128: {
	return ((v1_literal.value).number);
	break; }
	case s859_LiteralKind_F32:
	case s859_LiteralKind_F64: {
	return ((i64)((v1_literal.value).flt));
	break; }
	default:
 {
		#line 107
		(*v2_is_ok) = false;
		#line 108
		return 0l;
	break; }
}
	#line 112
	return 0l;
}


#line 115 "src/typecheck/literal.ib"
s528_TypeIdent * s855_into_typeident(s351_TypecheckContext * v1_context, s895_Literal v2_data) {
	#line 116
	switch ((v2_data.kind)) {
	case s899_LiteralKind_Number: {
	return s504_atomic((&((*v1_context).typeidents)), s535_AtomicType_I64);
	break; }
	case s899_LiteralKind_Float: {
	return s504_atomic((&((*v1_context).typeidents)), s535_AtomicType_F64);
	break; }
	case s899_LiteralKind_Char: {
	return s504_atomic((&((*v1_context).typeidents)), s535_AtomicType_U8);
	break; }
	case s899_LiteralKind_Bool: {
	return s504_atomic((&((*v1_context).typeidents)), s535_AtomicType_Bool);
	break; }
	case s899_LiteralKind_Null: {
	return s505_pointer((&((*v1_context).typeidents)), ((s528_TypeIdent *)NULL));
	break; }
	case s899_LiteralKind_String: {
	return s505_pointer((&((*v1_context).typeidents)), s504_atomic((&((*v1_context).typeidents)), s535_AtomicType_U8));
	break; }
	default:
		abort();
}
}


#line 136 "src/typecheck/literal.ib"
void s856_debug(s299_StringBuilder * v1_sb, s857_Literal * v2_literal, i64 v3_depth) {
	#line 137
	s288_repeat(v1_sb, "  ", v3_depth);
	#line 138
	switch (((*v2_literal).kind)) {
	case s859_LiteralKind_Bool: {
		#line 140
		if ((((*v2_literal).value).boolean)) {
			#line 140
			s283_append(v1_sb, "TRUE");
		} else {
#line 141
			s283_append(v1_sb, "FALSE");
		}
	break; }
	case s859_LiteralKind_Null: {
		#line 143
		s283_append(v1_sb, "NULL");
	break; }
	case s859_LiteralKind_U8: {
		#line 145
		s283_append(v1_sb, "U8(");
		#line 146
		s289_append_number(v1_sb, ((i64)(((*v2_literal).value).chr)));
		#line 148
		s283_append(v1_sb, ")");
	break; }
	case s859_LiteralKind_U16: {
		#line 151
		s283_append(v1_sb, "U16(");
		#line 152
		s289_append_number(v1_sb, (((*v2_literal).value).number));
		#line 153
		s283_append(v1_sb, ")");
	break; }
	case s859_LiteralKind_U32: {
		#line 156
		s283_append(v1_sb, "U32(");
		#line 157
		s289_append_number(v1_sb, (((*v2_literal).value).number));
		#line 158
		s283_append(v1_sb, ")");
	break; }
	case s859_LiteralKind_U64: {
		#line 161
		s283_append(v1_sb, "U64(");
		#line 162
		s289_append_number(v1_sb, (((*v2_literal).value).number));
		#line 163
		s283_append(v1_sb, ")");
	break; }
	case s859_LiteralKind_U128: {
		#line 166
		s283_append(v1_sb, "U128(");
		#line 167
		s289_append_number(v1_sb, (((*v2_literal).value).number));
		#line 168
		s283_append(v1_sb, ")");
	break; }
	case s859_LiteralKind_I8: {
		#line 171
		s283_append(v1_sb, "I8(");
		#line 172
		s289_append_number(v1_sb, (((*v2_literal).value).number));
		#line 173
		s283_append(v1_sb, ")");
	break; }
	case s859_LiteralKind_I16: {
		#line 176
		s283_append(v1_sb, "I16(");
		#line 177
		s289_append_number(v1_sb, (((*v2_literal).value).number));
		#line 178
		s283_append(v1_sb, ")");
	break; }
	case s859_LiteralKind_I32: {
		#line 181
		s283_append(v1_sb, "I32(");
		#line 182
		s289_append_number(v1_sb, (((*v2_literal).value).number));
		#line 183
		s283_append(v1_sb, ")");
	break; }
	case s859_LiteralKind_I64: {
		#line 186
		s283_append(v1_sb, "I64(");
		#line 187
		s289_append_number(v1_sb, (((*v2_literal).value).number));
		#line 188
		s283_append(v1_sb, ")");
	break; }
	case s859_LiteralKind_I128: {
		#line 191
		s283_append(v1_sb, "I128(");
		#line 192
		s289_append_number(v1_sb, (((*v2_literal).value).number));
		#line 193
		s283_append(v1_sb, ")");
	break; }
	case s859_LiteralKind_F32: {
		#line 197
		s283_append(v1_sb, "F32(");
		#line 198
		s291_append_float(v1_sb, (((*v2_literal).value).flt), 6l);
		#line 199
		s283_append(v1_sb, ")");
	break; }
	case s859_LiteralKind_F64: {
		#line 202
		s283_append(v1_sb, "F64(");
		#line 203
		s291_append_float(v1_sb, (((*v2_literal).value).flt), 6l);
		#line 204
		s283_append(v1_sb, ")");
	break; }
	case s859_LiteralKind_String: {
		#line 208
		s283_append(v1_sb, "STR(\"");
		#line 209
		s283_append(v1_sb, (((*v2_literal).value).string));
		#line 210
		s283_append(v1_sb, "\")");
	break; }
	default:
		abort();
}
	#line 213
	s283_append(v1_sb, "\n");
}


#line 29 "src/typecheck/const_eval.ib"
s864_ConstEvalResult s860_eval(s743_FunctionContext * v1_context, i64 v2_expr) {
	#line 30
	s844_Node * v3_node = s836_get(((*v1_context).nodes), v2_expr);
	#line 32
	switch (((*v3_node).kind)) {
	case s848_NodeKind_None: {
		#line 34
		s40_assert(false, "typecheck::node::NodeKind::None");
		#line 35
		return s863_error();
	break; }
	case s848_NodeKind_Literal: {
		#line 38
		s857_Literal v4_literal = (((*v3_node).data).literal);
		#line 39
		return s862_some(((s865_ConstExpr){
			.literal = v4_literal
		}));
	break; }
	case s848_NodeKind_Unary: {
		#line 42
		s1051_Unary v5_unary = (((*v3_node).data).unary);
		#line 43
		return s861_eval_unary(v1_context, (&v5_unary));
	break; }
	default:
 {
		#line 46
		s774_error(((*v1_context).parent), s781_ErrorKind_ConstEvalNotSupported, ((*v3_node).span));
		#line 47
		return s863_error();
	break; }
}
}


#line 53 "src/typecheck/const_eval.ib"
s864_ConstEvalResult s861_eval_unary(s743_FunctionContext * v1_context, s1051_Unary * v2_unary) {
	#line 54
	s864_ConstEvalResult v3_res = s860_eval(v1_context, ((*v2_unary).expr));
	#line 55
	if ((!(v3_res.success))) {
		#line 55
		return v3_res;
	}
	#line 56
	switch (((*v2_unary).op)) {
	case s1052_UnaryOp_Group: {
	break; }
	case s1052_UnaryOp_Pos: {
	break; }
	case s1052_UnaryOp_Neg: {
	switch ((((v3_res.expr).literal).kind)) {
	case s859_LiteralKind_U8:
	case s859_LiteralKind_U16:
	case s859_LiteralKind_U32:
	case s859_LiteralKind_U64:
	case s859_LiteralKind_U128:
	case s859_LiteralKind_I8:
	case s859_LiteralKind_I16:
	case s859_LiteralKind_I32:
	case s859_LiteralKind_I64:
	case s859_LiteralKind_I128: {
		#line 70
		((((v3_res.expr).literal).value).number) *= (-1l);
	break; }
	case s859_LiteralKind_F32:
	case s859_LiteralKind_F64: {
		#line 75
		((((v3_res.expr).literal).value).flt) *= ((f64)(-1l));
	break; }
	default:
 {
		#line 77
		s40_assert(false, "Neg was invalid!");
	break; }
}
	break; }
	case s1052_UnaryOp_Not: {
	return v3_res;
	break; }
	case s1052_UnaryOp_BitNot: {
	return v3_res;
	break; }
	default:
		abort();
}
	#line 82
	return v3_res;
}


#line 86 "src/typecheck/const_eval.ib"
s864_ConstEvalResult s862_some(s865_ConstExpr v1_expr) {
	#line 87
	return ((s864_ConstEvalResult){
		.expr = v1_expr,
		.success = true
	});
}


#line 93 "src/typecheck/const_eval.ib"
s864_ConstEvalResult s863_error() {
	#line 94
	s865_ConstExpr v1_expr = ((s865_ConstExpr){
		.none = NULL
	});
	#line 95
	return ((s864_ConstEvalResult){
		.expr = v1_expr,
		.success = true
	});
}


#line 124 "src/ast/expr.ib"
i64 s866_array_get(s889_Array * v1_array, i64 v2_index) {
	#line 125
	if ((v2_index >= ((*v1_array).elem_count))) {
		#line 125
		return s577_NONE;
	}
	#line 126
	return (((*v1_array).elems)[v2_index]);
}


#line 131 "src/ast/expr.ib"
i64 s867_parse(s702_Ast * v1_ast) {
	#line 132
	return s868_parse_expr_prec(v1_ast, 0l);
}


#line 136 "src/ast/expr.ib"
i64 s868_parse_expr_prec(s702_Ast * v1_ast, i64 v2_min_prec) {
	#line 137
	i64 v3_lhs = s874_primary(v1_ast);
	#line 138
	if ((v3_lhs == s674_ERROR)) {
		#line 138
		return s674_ERROR;
	}
	#line 139
	while (1) {
		#line 140
		s616_TokenKind v4_op = s689_curr(v1_ast);
		#line 141
		if (((v4_op == s616_TokenKind_EOF) || (v4_op == s616_TokenKind_SemiColon))) {
			#line 142
						goto loop_exit_1;
/* break; */
		}
		#line 145
		s970_InfixPrecedence * v5_infix = s962_get_infix((&((*v1_ast).infix)), v4_op);
		#line 146
		if ((v5_infix != ((s970_InfixPrecedence *)NULL))) {
			#line 147
			if ((((*v5_infix).prec) < v2_min_prec)) {
				#line 147
								goto loop_exit_1;
/* break; */
			}
			#line 148
			switch (((*v5_infix).rhs_kind)) {
			case s973_RHSKind_Expr: {
				#line 150
				s688_step(v1_ast);
				#line 151
				i64 v6_rhs = s868_parse_expr_prec(v1_ast, ((*v5_infix).new_prec));
				#line 152
				if ((v6_rhs == s674_ERROR)) {
					#line 152
					return s674_ERROR;
				}
				#line 154
				if ((((*v5_infix).suffix) != s616_TokenKind_None)) {
					#line 155
					if ((!s694_consume(v1_ast, ((*v5_infix).suffix)))) {
						#line 155
						return s687_error(v1_ast, ((*v5_infix).suffix_err));
					}
				}
				#line 157
				v3_lhs = s871_binary(v1_ast, ((*v5_infix).op), v3_lhs, v6_rhs);
			break; }
			case s973_RHSKind_Call: {
				#line 160
				v3_lhs = s870_parse_call(v1_ast, v3_lhs);
				#line 161
				if ((v3_lhs == s674_ERROR)) {
					#line 161
					return s674_ERROR;
				}
			break; }
			case s973_RHSKind_Cast: {
				#line 164
				s688_step(v1_ast);
				#line 165
				v3_lhs = s869_parse_cast(v1_ast, v3_lhs);
				#line 166
				if ((v3_lhs == s674_ERROR)) {
					#line 166
					return s674_ERROR;
				}
			break; }
			default:
				abort();
}
		} else {
#line 170
						goto loop_exit_1;
/* break; */
		}
}
	loop_exit_1:
	#line 173
	return v3_lhs;
}


#line 177 "src/ast/expr.ib"
i64 s869_parse_cast(s702_Ast * v1_ast, i64 v2_lhs) {
	#line 180
	((*v1_ast).typeident_context) = s703_TypeIdentContext_Cast;
	#line 181
	s959_TypeIdentResult v3_ty_res = s951_parse(v1_ast);
	#line 182
	if ((!(v3_ty_res.success))) {
		#line 182
		return s674_ERROR;
	}
	#line 184
	i64 v4_lhs_span = s698_node_get_span(v1_ast, v2_lhs);
	#line 185
	i64 v5_rhs_span = (v3_ty_res.span);
	#line 187
	i64 v6_node = s696_node_create(v1_ast, s589_NodeKind_Cast);
	#line 188
	s888_Cast * v7_cast_data = ((s888_Cast *)s697_node_data(v1_ast, v6_node));
	#line 189
	((*v7_cast_data).expr) = v2_lhs;
	#line 190
	((*v7_cast_data).type) = (v3_ty_res.type);
	#line 191
	((*v7_cast_data).type_span) = (v3_ty_res.span);
	#line 192
	s699_node_set_span(v1_ast, v6_node, s149_merge(v4_lhs_span, v5_rhs_span));
	#line 193
	return v6_node;
}


#line 197 "src/ast/expr.ib"
i64 s870_parse_call(s702_Ast * v1_ast, i64 v2_callee) {
	#line 198
	i64 v3_span_start = s692_curr_span(v1_ast);
	#line 200
	s688_step(v1_ast);
	#line 201
	i64 v4_arg_count = 0l;
	#line 202
	while (1) {
		#line 202
		switch (s689_curr(v1_ast)) {
		case s616_TokenKind_EOF: {
		return s687_error(v1_ast, s226_ErrorKind_UnterminatedParen);
		break; }
		case s616_TokenKind_ParenR: {
			#line 206
			s688_step(v1_ast);
			#line 207
						goto loop_exit_1;
/* break; */
		break; }
		default:
 {
			#line 210
			i64 v5_arg = s867_parse(v1_ast);
			#line 211
			if ((v5_arg == s674_ERROR)) {
				#line 211
				return s674_ERROR;
			}
			#line 212
			v4_arg_count += 1l;
			#line 213
			s700_work_push(v1_ast, v5_arg);
			#line 215
			if ((s689_curr(v1_ast) == s616_TokenKind_Comma)) {
				#line 216
				s688_step(v1_ast);
			} else if (s694_consume(v1_ast, s616_TokenKind_ParenR)) {
				#line 218
								goto loop_exit_1;
/* break; */
			} else {
#line 220
				return s687_error(v1_ast, s226_ErrorKind_CommaExpected);
			}
		break; }
}
}
	loop_exit_1:
	#line 225
	i64 v6_node = s696_node_create(v1_ast, s589_NodeKind_Call);
	#line 226
	s890_Call * v7_call_data = ((s890_Call *)s697_node_data(v1_ast, v6_node));
	#line 227
	((*v7_call_data).callee) = v2_callee;
	#line 229
	((*v7_call_data).args) = ((i64 *)s580_allocate_extra((&((*((*v1_ast).module)).nodes)), ((i64)(8ul * ((u64)v4_arg_count)))));
	#line 230
	((*v7_call_data).arg_count) = v4_arg_count;
	#line 231
	for (i64 v8_i = (v4_arg_count - 1l);(v8_i >= 0l);v8_i -= 1l) {
		#line 232
		(((*v7_call_data).args)[v8_i]) = s701_work_pop(v1_ast);
	}
	loop_exit_2:
	#line 235
	s699_node_set_span(v1_ast, v6_node, s691_span_end(v1_ast, v3_span_start));
	#line 236
	return v6_node;
}


#line 240 "src/ast/expr.ib"
i64 s871_binary(s702_Ast * v1_ast, s897_BinaryOp v2_op, i64 v3_lhs, i64 v4_rhs) {
	#line 241
	i64 v5_node = s696_node_create(v1_ast, s589_NodeKind_Binary);
	#line 242
	s893_Binary * v6_binary = ((s893_Binary *)s697_node_data(v1_ast, v5_node));
	#line 243
	((*v6_binary).op) = v2_op;
	#line 244
	((*v6_binary).lhs) = v3_lhs;
	#line 245
	((*v6_binary).rhs) = v4_rhs;
	#line 246
	i64 v7_lhs_span = s698_node_get_span(v1_ast, v3_lhs);
	#line 247
	i64 v8_rhs_span = s698_node_get_span(v1_ast, v4_rhs);
	#line 248
	s699_node_set_span(v1_ast, v5_node, s149_merge(v7_lhs_span, v8_rhs_span));
	#line 249
	return v5_node;
}


#line 253 "src/ast/expr.ib"
i64 s872_unary(s702_Ast * v1_ast, s898_UnaryOp v2_op, i64 v3_expr, i64 v4_span_start) {
	#line 254
	i64 v5_node = s696_node_create(v1_ast, s589_NodeKind_Unary);
	#line 255
	s894_Unary * v6_unary = ((s894_Unary *)s697_node_data(v1_ast, v5_node));
	#line 256
	((*v6_unary).op) = v2_op;
	#line 257
	((*v6_unary).expr) = v3_expr;
	#line 258
	s699_node_set_span(v1_ast, v5_node, s691_span_end(v1_ast, v4_span_start));
	#line 259
	return v5_node;
}


#line 263 "src/ast/expr.ib"
i64 s873_parse_prefix_op(s702_Ast * v1_ast) {
	#line 264
	s616_TokenKind v2_op = s689_curr(v1_ast);
	#line 265
	s969_PrefixPrecedence * v3_pref = s961_get_prefix((&((*v1_ast).prefix)), v2_op);
	#line 266
	if ((v3_pref == ((s969_PrefixPrecedence *)NULL))) {
		#line 266
		return s674_ERROR;
	}
	#line 268
	i64 v4_span_start = s692_curr_span(v1_ast);
	#line 269
	s688_step(v1_ast);
	#line 271
	i64 v5_expr = s868_parse_expr_prec(v1_ast, ((*v3_pref).new_prec));
	#line 272
	if ((v5_expr == s674_ERROR)) {
		#line 272
		return s674_ERROR;
	}
	#line 274
	if ((((*v3_pref).suffix) != s616_TokenKind_None)) {
		#line 275
		if ((!s694_consume(v1_ast, ((*v3_pref).suffix)))) {
			#line 276
			return s687_error(v1_ast, ((*v3_pref).suffix_err));
		}
	}
	#line 279
	return s872_unary(v1_ast, ((*v3_pref).op), v5_expr, v4_span_start);
}


#line 283 "src/ast/expr.ib"
i64 s874_primary(s702_Ast * v1_ast) {
	#line 284
	switch (s689_curr(v1_ast)) {
	case s616_TokenKind_LiteralInt: {
	return s878_literal(v1_ast, s899_LiteralKind_Number);
	break; }
	case s616_TokenKind_LiteralFloat: {
	return s878_literal(v1_ast, s899_LiteralKind_Float);
	break; }
	case s616_TokenKind_LiteralString: {
	return s878_literal(v1_ast, s899_LiteralKind_String);
	break; }
	case s616_TokenKind_LiteralChar: {
	return s878_literal(v1_ast, s899_LiteralKind_Char);
	break; }
	case s616_TokenKind_True: {
	return s879_literal_bool(v1_ast, true);
	break; }
	case s616_TokenKind_False: {
	return s879_literal_bool(v1_ast, false);
	break; }
	case s616_TokenKind_Null: {
	return s878_literal(v1_ast, s899_LiteralKind_Null);
	break; }
	case s616_TokenKind_Ident: {
		#line 293
		bool v2_is_struct_allowed = (!((*v1_ast).in_condition));
		#line 294
		if ((v2_is_struct_allowed && (s690_peek(v1_ast, 1l) == s616_TokenKind_BraceL))) {
			#line 295
			return s934_parse_object_init(v1_ast);
		} else {
#line 297
			return s877_parse_ident(v1_ast);
		}
	break; }
	case s616_TokenKind_SizeOf: {
	return s876_parse_sizeof(v1_ast);
	break; }
	case s616_TokenKind_BracketL: {
		#line 303
		return s875_parse_array_init(v1_ast);
	break; }
	default:
 {
		#line 306
		i64 v3_expr = s873_parse_prefix_op(v1_ast);
		#line 307
		if ((v3_expr == s674_ERROR)) {
			#line 307
			return s687_error(v1_ast, s226_ErrorKind_InvalidPrimary);
		}
		#line 308
		return v3_expr;
	break; }
}
}


#line 313 "src/ast/expr.ib"
i64 s875_parse_array_init(s702_Ast * v1_ast) {
	#line 314
	i64 v2_span_start = s692_curr_span(v1_ast);
	#line 315
	s688_step(v1_ast);
	#line 317
	i64 v3_elem_count = 0l;
	#line 318
	while (1) {
		#line 319
		if ((s689_curr(v1_ast) == s616_TokenKind_EOF)) {
			#line 320
			return s687_error(v1_ast, s226_ErrorKind_UnterminatedBracket);
		}
		#line 322
		if ((s689_curr(v1_ast) == s616_TokenKind_BracketR)) {
			#line 323
			s688_step(v1_ast);
			#line 324
						goto loop_exit_1;
/* break; */
		}
		#line 326
		i64 v4_elem = s867_parse(v1_ast);
		#line 327
		if ((v4_elem == s674_ERROR)) {
			#line 327
			return s674_ERROR;
		}
		#line 328
		s700_work_push(v1_ast, v4_elem);
		#line 329
		v3_elem_count += 1l;
		#line 331
		if ((s689_curr(v1_ast) == s616_TokenKind_Comma)) {
			#line 332
			s688_step(v1_ast);
			#line 333
			continue;
		}
		#line 336
		if ((!s694_consume(v1_ast, s616_TokenKind_BracketR))) {
			#line 337
			return s687_error(v1_ast, s226_ErrorKind_CommaExpected);
		}
		#line 339
				goto loop_exit_1;
/* break; */
}
	loop_exit_1:
	#line 342
	i64 v5_node = s696_node_create(v1_ast, s589_NodeKind_Array);
	#line 343
	s889_Array * v6_array = ((s889_Array *)s697_node_data(v1_ast, v5_node));
	#line 344
	((*v6_array).elem_count) = v3_elem_count;
	#line 345
	((*v6_array).elems) = ((i64 *)s580_allocate_extra((&((*((*v1_ast).module)).nodes)), ((i64)(8ul * ((u64)((*v6_array).elem_count))))));
	#line 349
	for (i64 v7_i = (((*v6_array).elem_count) - 1l);(v7_i >= 0l);v7_i -= 1l) {
		#line 350
		(((*v6_array).elems)[v7_i]) = s701_work_pop(v1_ast);
	}
	loop_exit_2:
	#line 353
	s699_node_set_span(v1_ast, v5_node, s691_span_end(v1_ast, v2_span_start));
	#line 354
	return v5_node;
}


#line 358 "src/ast/expr.ib"
i64 s876_parse_sizeof(s702_Ast * v1_ast) {
	#line 359
	i64 v2_span_start = s692_curr_span(v1_ast);
	#line 360
	s688_step(v1_ast);
	#line 361
	if ((!s694_consume(v1_ast, s616_TokenKind_ParenL))) {
		#line 362
		return s687_error(v1_ast, s226_ErrorKind_SizeOfMissingParenL);
	}
	#line 364
	((*v1_ast).typeident_context) = s703_TypeIdentContext_SizeOf;
	#line 365
	s959_TypeIdentResult v3_type_res = s951_parse(v1_ast);
	#line 366
	if ((!(v3_type_res.success))) {
		#line 366
		return s674_ERROR;
	}
	#line 368
	if ((!s694_consume(v1_ast, s616_TokenKind_ParenR))) {
		#line 369
		return s687_error(v1_ast, s226_ErrorKind_SizeOfMissingParenR);
	}
	#line 372
	i64 v4_node = s696_node_create(v1_ast, s589_NodeKind_SizeOf);
	#line 373
	s586_TypeData * v5_size_of = ((s586_TypeData *)s697_node_data(v1_ast, v4_node));
	#line 374
	((*v5_size_of).type) = (v3_type_res.type);
	#line 375
	((*v5_size_of).span) = (v3_type_res.span);
	#line 377
	s699_node_set_span(v1_ast, v4_node, s691_span_end(v1_ast, v2_span_start));
	#line 378
	return v4_node;
}


#line 382 "src/ast/expr.ib"
i64 s877_parse_ident(s702_Ast * v1_ast) {
	#line 383
	i64 v2_node = s696_node_create(v1_ast, s589_NodeKind_Ident);
	#line 384
	char * * v3_ident = ((char * *)s697_node_data(v1_ast, v2_node));
	#line 386
	s699_node_set_span(v1_ast, v2_node, s692_curr_span(v1_ast));
	#line 387
	if ((s686_consume_ident(v1_ast, v3_ident, s226_ErrorKind_IdentifierExpected) == s674_ERROR)) {
		#line 387
		return s674_ERROR;
	}
	#line 389
	return v2_node;
}


#line 393 "src/ast/expr.ib"
i64 s878_literal(s702_Ast * v1_ast, s899_LiteralKind v2_kind) {
	#line 394
	i64 v3_node = s696_node_create(v1_ast, s589_NodeKind_Literal);
	#line 395
	s895_Literal * v4_literal = ((s895_Literal *)s697_node_data(v1_ast, v3_node));
	#line 396
	s614_Token * v5_token = s695_curr_token(v1_ast);
	#line 397
	((*v4_literal).kind) = v2_kind;
	#line 398
	((*v4_literal).value) = (*((s896_LiteralValue *)((void *)(&((*v5_token).data)))));
	#line 399
	s699_node_set_span(v1_ast, v3_node, s692_curr_span(v1_ast));
	#line 400
	s688_step(v1_ast);
	#line 401
	return v3_node;
}


#line 405 "src/ast/expr.ib"
i64 s879_literal_bool(s702_Ast * v1_ast, bool v2_value) {
	#line 406
	i64 v3_node = s696_node_create(v1_ast, s589_NodeKind_Literal);
	#line 407
	s895_Literal * v4_literal = ((s895_Literal *)s697_node_data(v1_ast, v3_node));
	#line 408
	((*v4_literal).kind) = s899_LiteralKind_Bool;
	#line 409
	(((*v4_literal).value).boolean) = v2_value;
	#line 411
	s699_node_set_span(v1_ast, v3_node, s692_curr_span(v1_ast));
	#line 412
	s688_step(v1_ast);
	#line 413
	return v3_node;
}


#line 422 "src/ast/expr.ib"
void s880_debug_call(s299_StringBuilder * v1_sb, s585_Nodes * v2_nodes, s890_Call * v3_call, i64 v4_depth) {
	#line 423
	s288_repeat(v1_sb, "  ", v4_depth);
	#line 424
	s283_append(v1_sb, "[CALL] CALLEE:\n");
	#line 425
	s584_debug(v1_sb, v2_nodes, ((*v3_call).callee), (v4_depth + 1l));
	#line 426
	for (i64 v5_i = 0l;(v5_i < ((*v3_call).arg_count));v5_i += 1l) {
		#line 427
		s288_repeat(v1_sb, "  ", (v4_depth + 1l));
		#line 428
		s283_append(v1_sb, "ARG[");
		#line 429
		s289_append_number(v1_sb, v5_i);
		#line 430
		s283_append(v1_sb, "]\n");
		#line 431
		s584_debug(v1_sb, v2_nodes, (((*v3_call).args)[v5_i]), (v4_depth + 1l));
	}
	loop_exit_1:
}


#line 436 "src/ast/expr.ib"
void s881_debug_unary(s299_StringBuilder * v1_sb, s585_Nodes * v2_nodes, s894_Unary * v3_unary, i64 v4_depth) {
	#line 437
	s288_repeat(v1_sb, "  ", v4_depth);
	#line 438
	switch (((*v3_unary).op)) {
	case s898_UnaryOp_Group: {
	s283_append(v1_sb, "GROUP\n");
	break; }
	case s898_UnaryOp_Ref: {
	s283_append(v1_sb, "REF\n");
	break; }
	case s898_UnaryOp_Deref: {
	s283_append(v1_sb, "DEREF\n");
	break; }
	case s898_UnaryOp_Pos: {
	s283_append(v1_sb, "POS\n");
	break; }
	case s898_UnaryOp_Neg: {
	s283_append(v1_sb, "NEG\n");
	break; }
	case s898_UnaryOp_Not: {
	s283_append(v1_sb, "NOT\n");
	break; }
	case s898_UnaryOp_BitNot: {
	s283_append(v1_sb, "BITNOT\n");
	break; }
	default:
		abort();
}
	#line 447
	s584_debug(v1_sb, v2_nodes, ((*v3_unary).expr), (v4_depth + 1l));
}


#line 451 "src/ast/expr.ib"
void s882_debug_binary(s299_StringBuilder * v1_sb, s585_Nodes * v2_nodes, s893_Binary * v3_binary, i64 v4_depth) {
	#line 452
	s288_repeat(v1_sb, "  ", v4_depth);
	#line 453
	switch (((*v3_binary).op)) {
	case s897_BinaryOp_None: {
	s283_append(v1_sb, "NONE\n");
	break; }
	case s897_BinaryOp_Add: {
	s283_append(v1_sb, "ADD\n");
	break; }
	case s897_BinaryOp_Sub: {
	s283_append(v1_sb, "SUB\n");
	break; }
	case s897_BinaryOp_Mul: {
	s283_append(v1_sb, "MUL\n");
	break; }
	case s897_BinaryOp_Div: {
	s283_append(v1_sb, "DIV\n");
	break; }
	case s897_BinaryOp_Rem: {
	s283_append(v1_sb, "REM\n");
	break; }
	case s897_BinaryOp_Assign: {
	s283_append(v1_sb, "ASSIGN\n");
	break; }
	case s897_BinaryOp_AssignAdd: {
	s283_append(v1_sb, "ASSIGN_ADD\n");
	break; }
	case s897_BinaryOp_AssignSub: {
	s283_append(v1_sb, "ASSIGN_SUB\n");
	break; }
	case s897_BinaryOp_AssignMul: {
	s283_append(v1_sb, "ASSIGN_MUL\n");
	break; }
	case s897_BinaryOp_AssignDiv: {
	s283_append(v1_sb, "ASSIGN_DIV\n");
	break; }
	case s897_BinaryOp_AssignRem: {
	s283_append(v1_sb, "ASSIGN_REM\n");
	break; }
	case s897_BinaryOp_EQ: {
	s283_append(v1_sb, "EQ\n");
	break; }
	case s897_BinaryOp_NE: {
	s283_append(v1_sb, "NE\n");
	break; }
	case s897_BinaryOp_GT: {
	s283_append(v1_sb, "GT\n");
	break; }
	case s897_BinaryOp_GE: {
	s283_append(v1_sb, "GE\n");
	break; }
	case s897_BinaryOp_LT: {
	s283_append(v1_sb, "LT\n");
	break; }
	case s897_BinaryOp_LE: {
	s283_append(v1_sb, "LE\n");
	break; }
	case s897_BinaryOp_And: {
	s283_append(v1_sb, "AND\n");
	break; }
	case s897_BinaryOp_Or: {
	s283_append(v1_sb, "OR\n");
	break; }
	case s897_BinaryOp_Index: {
	s283_append(v1_sb, "INDEX\n");
	break; }
	case s897_BinaryOp_FieldLookup: {
	s283_append(v1_sb, "FIELD_LOOKUP\n");
	break; }
	case s897_BinaryOp_Path: {
	s283_append(v1_sb, "PATH\n");
	break; }
	case s897_BinaryOp_BitOr: {
	s283_append(v1_sb, "BIT_OR\n");
	break; }
	case s897_BinaryOp_BitXor: {
	s283_append(v1_sb, "BIT_XOR\n");
	break; }
	case s897_BinaryOp_BitAnd: {
	s283_append(v1_sb, "BIT_AND\n");
	break; }
	case s897_BinaryOp_BitShiftRight: {
	s283_append(v1_sb, "BIT_SHIFT_RIGHT\n");
	break; }
	case s897_BinaryOp_BitShiftLeft: {
	s283_append(v1_sb, "BIT_SHIFT_LEFT\n");
	break; }
	default:
		abort();
}
	#line 483
	s584_debug(v1_sb, v2_nodes, ((*v3_binary).lhs), (v4_depth + 1l));
	#line 484
	s584_debug(v1_sb, v2_nodes, ((*v3_binary).rhs), (v4_depth + 1l));
}


#line 488 "src/ast/expr.ib"
void s883_debug_literal(s299_StringBuilder * v1_sb, s895_Literal * v2_literal, i64 v3_depth) {
	#line 489
	s288_repeat(v1_sb, "  ", v3_depth);
	#line 490
	switch (((*v2_literal).kind)) {
	case s899_LiteralKind_Number: {
		#line 492
		s283_append(v1_sb, "[LITERAL] NUMBER = ");
		#line 493
		s289_append_number(v1_sb, (((*v2_literal).value).number));
	break; }
	case s899_LiteralKind_Float: {
		#line 496
		s283_append(v1_sb, "[LITERAL] FLOAT = ");
		#line 497
		s291_append_float(v1_sb, (((*v2_literal).value).flt), 6l);
	break; }
	case s899_LiteralKind_String: {
		#line 502
		s283_append(v1_sb, "[LITERAL] STRING = ");
		#line 503
		s283_append(v1_sb, (((*v2_literal).value).string));
	break; }
	case s899_LiteralKind_Char: {
		#line 506
		s283_append(v1_sb, "[LITERAL]  CHAR = ");
		#line 507
		s286_append_debug_char(v1_sb, (((*v2_literal).value).chr));
	break; }
	case s899_LiteralKind_Bool: {
		#line 510
		if ((((*v2_literal).value).boolean)) {
			#line 511
			s283_append(v1_sb, "[LITERAL] TRUE");
		} else {
#line 513
			s283_append(v1_sb, "[LITERAL] FALSE");
		}
	break; }
	case s899_LiteralKind_Null: {
	s283_append(v1_sb, "[LITERAL] NULL");
	break; }
	default:
		abort();
}
	#line 518
	s284_append_char(v1_sb, 10u);
}


#line 522 "src/ast/expr.ib"
void s884_debug_sizeof(s299_StringBuilder * v1_sb, s585_Nodes * v2_nodes, s586_TypeData * v3_size_of, i64 v4_depth) {
	#line 523
	s288_repeat(v1_sb, "  ", v4_depth);
	#line 524
	s283_append(v1_sb, "SIZEOF\n");
	#line 526
	s288_repeat(v1_sb, "  ", v4_depth);
	#line 527
	s210_debug(v1_sb, v2_nodes, ((*v3_size_of).type), v4_depth);
	#line 528
	s283_append(v1_sb, "\n");
}


#line 532 "src/ast/expr.ib"
void s885_debug_object_init(s299_StringBuilder * v1_sb, s585_Nodes * v2_nodes, s891_ObjectInit * v3_obj_init, i64 v4_depth) {
	#line 533
	s288_repeat(v1_sb, "  ", v4_depth);
	#line 534
	s283_append(v1_sb, "OBJECT_INIT ");
	#line 535
	s283_append(v1_sb, ((*v3_obj_init).type));
	#line 536
	s283_append(v1_sb, "\n");
	#line 537
	for (i64 v5_i = 0l;(v5_i < ((*v3_obj_init).field_count));v5_i += 1l) {
		#line 538
		s288_repeat(v1_sb, "  ", (v4_depth + 1l));
		#line 539
		s283_append(v1_sb, ((((*v3_obj_init).fields)[v5_i]).field));
		#line 540
		s283_append(v1_sb, "\n");
		#line 541
		i64 v6_value = ((((*v3_obj_init).fields)[v5_i]).value);
		#line 542
		if ((v6_value != s577_NONE)) {
			#line 543
			s584_debug(v1_sb, v2_nodes, v6_value, (v4_depth + 2l));
		}
	}
	loop_exit_1:
}


#line 549 "src/ast/expr.ib"
void s886_debug_array(s299_StringBuilder * v1_sb, s585_Nodes * v2_nodes, s889_Array * v3_array, i64 v4_depth) {
	#line 550
	s288_repeat(v1_sb, "  ", v4_depth);
	#line 551
	s283_append(v1_sb, "ARRAY\n");
	#line 552
	for (i64 v5_i = 0l;(v5_i < ((*v3_array).elem_count));v5_i += 1l) {
		#line 553
		i64 v6_n = s866_array_get(v3_array, v5_i);
		#line 554
		s584_debug(v1_sb, v2_nodes, v6_n, (v4_depth + 1l));
	}
	loop_exit_1:
}


#line 559 "src/ast/expr.ib"
void s887_debug_cast(s299_StringBuilder * v1_sb, s585_Nodes * v2_nodes, s888_Cast * v3_cast, i64 v4_depth) {
	#line 560
	s288_repeat(v1_sb, "  ", v4_depth);
	#line 561
	s283_append(v1_sb, "CAST\n");
	#line 562
	s584_debug(v1_sb, v2_nodes, ((*v3_cast).expr), (v4_depth + 1l));
	#line 563
	s288_repeat(v1_sb, "  ", v4_depth);
	#line 564
	s210_debug(v1_sb, v2_nodes, ((*v3_cast).type), v4_depth);
	#line 565
	s283_append(v1_sb, "\n");
}


#line 72 "src/ast/statement.ib"
i64 s900_parse(s702_Ast * v1_ast) {
	#line 73
	bool v2_skip_expr_semicolon = ((*v1_ast).skip_expr_semicolon);
	#line 74
	((*v1_ast).skip_expr_semicolon) = false;
	#line 75
	switch (s689_curr(v1_ast)) {
	case s616_TokenKind_Let: {
	return s901_parse_var_dec(v1_ast, true);
	break; }
	case s616_TokenKind_Const: {
	return s901_parse_var_dec(v1_ast, false);
	break; }
	case s616_TokenKind_BraceL: {
	return s902_parse_block(v1_ast);
	break; }
	case s616_TokenKind_Return: {
	return s903_parse_return(v1_ast);
	break; }
	case s616_TokenKind_If: {
	return s904_parse_if(v1_ast);
	break; }
	case s616_TokenKind_Loop: {
	return s905_parse_loop(v1_ast);
	break; }
	case s616_TokenKind_For: {
	return s906_parse_for(v1_ast);
	break; }
	case s616_TokenKind_While: {
	return s907_parse_while(v1_ast);
	break; }
	case s616_TokenKind_Match: {
	return s908_parse_match(v1_ast);
	break; }
	case s616_TokenKind_Break: {
	return s911_parse_simple_statement(v1_ast, s589_NodeKind_Break);
	break; }
	case s616_TokenKind_Continue: {
	return s911_parse_simple_statement(v1_ast, s589_NodeKind_Continue);
	break; }
	default:
 {
		#line 88
		i64 v3_expr = s867_parse(v1_ast);
		#line 89
		if (v2_skip_expr_semicolon) {
			#line 89
			return v3_expr;
		}
		#line 90
		if ((!s694_consume(v1_ast, s616_TokenKind_SemiColon))) {
			#line 91
			return s687_error(v1_ast, s226_ErrorKind_SemicolonExpected);
		}
		#line 93
		return v3_expr;
	break; }
}
}


#line 99 "src/ast/statement.ib"
i64 s901_parse_var_dec(s702_Ast * v1_ast, bool v2_mutable) {
	#line 100
	i64 v3_span_start = s692_curr_span(v1_ast);
	#line 102
	s589_NodeKind v4_kind = s589_NodeKind_VarDecl;
	#line 103
	if ((!v2_mutable)) {
		#line 103
		v4_kind = s589_NodeKind_ConstDecl;
	}
	#line 105
	s688_step(v1_ast);
	#line 106
	i64 v5_ident = s877_parse_ident(v1_ast);
	#line 107
	if ((v5_ident == s674_ERROR)) {
		#line 107
		return s674_ERROR;
	}
	#line 109
	s586_TypeData * v6_type = ((s586_TypeData *)NULL);
	#line 110
	if ((s689_curr(v1_ast) == s616_TokenKind_Colon)) {
		#line 111
		s688_step(v1_ast);
		#line 112
		((*v1_ast).typeident_context) = s703_TypeIdentContext_VarDeclaration;
		#line 113
		s959_TypeIdentResult v7_res = s951_parse(v1_ast);
		#line 114
		if ((!(v7_res.success))) {
			#line 114
			return s674_ERROR;
		}
		#line 115
		v6_type = ((s586_TypeData *)s580_allocate_extra((&((*((*v1_ast).module)).nodes)), ((i64)16ul)));
		#line 119
		((*v6_type).span) = (v7_res.span);
		#line 120
		((*v6_type).type) = (v7_res.type);
	}
	#line 122
	if ((!s694_consume(v1_ast, s616_TokenKind_Equal))) {
		#line 123
		return s687_error(v1_ast, s226_ErrorKind_VarDeclEqExpected);
	}
	#line 125
	i64 v8_value = s867_parse(v1_ast);
	#line 126
	if ((v8_value == s674_ERROR)) {
		#line 126
		return s674_ERROR;
	}
	#line 127
	if ((!s694_consume(v1_ast, s616_TokenKind_SemiColon))) {
		#line 128
		return s687_error(v1_ast, s226_ErrorKind_SemicolonExpected);
	}
	#line 131
	i64 v9_node = s696_node_create(v1_ast, v4_kind);
	#line 132
	s924_VarDeclaration * v10_var_decl = ((s924_VarDeclaration *)s697_node_data(v1_ast, v9_node));
	#line 133
	((*v10_var_decl).ident) = v5_ident;
	#line 134
	((*v10_var_decl).type) = v6_type;
	#line 135
	((*v10_var_decl).value) = v8_value;
	#line 137
	s699_node_set_span(v1_ast, v9_node, s691_span_end(v1_ast, v3_span_start));
	#line 138
	return v9_node;
}


#line 142 "src/ast/statement.ib"
i64 s902_parse_block(s702_Ast * v1_ast) {
	#line 143
	i64 v2_span_start = s692_curr_span(v1_ast);
	#line 145
	if ((!s694_consume(v1_ast, s616_TokenKind_BraceL))) {
		#line 146
		return s687_error(v1_ast, s226_ErrorKind_BlockExpected);
	}
	#line 148
	i64 v3_count = 0l;
	#line 150
	bool v4_had_error = false;
	#line 151
	while (1) {
		#line 156
		if (s681_curr_is_declaration(v1_ast)) {
			#line 157
			return s687_error(v1_ast, s226_ErrorKind_UnterminatedBlock);
		}
		#line 159
		switch (s689_curr(v1_ast)) {
		case s616_TokenKind_EOF: {
		return s687_error(v1_ast, s226_ErrorKind_UnterminatedBlock);
		break; }
		case s616_TokenKind_BraceR: {
			#line 163
			s688_step(v1_ast);
			#line 164
						goto loop_exit_1;
/* break; */
		break; }
		case s616_TokenKind_SemiColon: {
			#line 167
			s688_step(v1_ast);
		break; }
		default:
 {
			#line 170
			i64 v5_s = s900_parse(v1_ast);
			#line 171
			if ((v5_s == s674_ERROR)) {
				#line 172
				v4_had_error = true;
			} else {
#line 174
				s700_work_push(v1_ast, v5_s);
				#line 175
				v3_count += 1l;
			}
		break; }
}
}
	loop_exit_1:
	#line 179
	if (v4_had_error) {
		#line 179
		return s674_ERROR;
	}
	#line 181
	i64 v6_node = s696_node_create(v1_ast, s589_NodeKind_Block);
	#line 182
	s923_BlockData * v7_block = ((s923_BlockData *)s697_node_data(v1_ast, v6_node));
	#line 183
	s699_node_set_span(v1_ast, v6_node, s691_span_end(v1_ast, v2_span_start));
	#line 184
	((*v7_block).nodes) = ((i64 *)s580_allocate_extra((&((*((*v1_ast).module)).nodes)), ((i64)(8ul * ((u64)v3_count)))));
	#line 185
	((*v7_block).count) = v3_count;
	#line 186
	for (i64 v8_i = (v3_count - 1l);(v8_i >= 0l);v8_i -= 1l) {
		#line 187
		i64 v9_node = s701_work_pop(v1_ast);
		#line 188
		(((*v7_block).nodes)[v8_i]) = v9_node;
	}
	loop_exit_2:
	#line 190
	return v6_node;
}


#line 194 "src/ast/statement.ib"
i64 s903_parse_return(s702_Ast * v1_ast) {
	#line 195
	i64 v2_value = 0l;
	#line 196
	bool v3_has_value = false;
	#line 198
	i64 v4_span_start = s692_curr_span(v1_ast);
	#line 199
	s688_step(v1_ast);
	#line 200
	if ((s689_curr(v1_ast) != s616_TokenKind_SemiColon)) {
		#line 201
		v2_value = s867_parse(v1_ast);
		#line 202
		v3_has_value = true;
	}
	#line 204
	if ((!s694_consume(v1_ast, s616_TokenKind_SemiColon))) {
		#line 205
		return s687_error(v1_ast, s226_ErrorKind_SemicolonExpected);
	}
	#line 208
	i64 v5_node = s696_node_create(v1_ast, s589_NodeKind_Return);
	#line 209
	s925_ReturnData * v6_return_data = ((s925_ReturnData *)s697_node_data(v1_ast, v5_node));
	#line 210
	((*v6_return_data).value) = v2_value;
	#line 211
	((*v6_return_data).has_value) = v3_has_value;
	#line 213
	s699_node_set_span(v1_ast, v5_node, s691_span_end(v1_ast, v4_span_start));
	#line 214
	return v5_node;
}


#line 218 "src/ast/statement.ib"
i64 s904_parse_if(s702_Ast * v1_ast) {
	#line 219
	i64 v2_span_start = s692_curr_span(v1_ast);
	#line 220
	s688_step(v1_ast);
	#line 222
	((*v1_ast).in_condition) = true;
	#line 223
	i64 v3_cond = s867_parse(v1_ast);
	#line 224
	if ((v3_cond == s674_ERROR)) {
		#line 224
		return s674_ERROR;
	}
	#line 225
	((*v1_ast).in_condition) = false;
	#line 227
	i64 v4_then = s902_parse_block(v1_ast);
	#line 228
	if ((v4_then == s674_ERROR)) {
		#line 228
		return s674_ERROR;
	}
	#line 229
	i64 v5_otherwise = 0l;
	#line 230
	if ((s689_curr(v1_ast) == s616_TokenKind_Else)) {
		#line 231
		s688_step(v1_ast);
		#line 232
		if ((s689_curr(v1_ast) == s616_TokenKind_If)) {
			#line 233
			v5_otherwise = s904_parse_if(v1_ast);
		} else {
#line 235
			v5_otherwise = s902_parse_block(v1_ast);
		}
		#line 237
		if ((v5_otherwise == s674_ERROR)) {
			#line 237
			return s674_ERROR;
		}
	}
	#line 240
	i64 v6_node = s696_node_create(v1_ast, s589_NodeKind_If);
	#line 241
	s922_IfData * v7_if_data = ((s922_IfData *)s697_node_data(v1_ast, v6_node));
	#line 242
	((*v7_if_data).cond) = v3_cond;
	#line 243
	((*v7_if_data).then) = v4_then;
	#line 244
	((*v7_if_data).otherwise) = v5_otherwise;
	#line 246
	s699_node_set_span(v1_ast, v6_node, s691_span_end(v1_ast, v2_span_start));
	#line 247
	return v6_node;
}


#line 251 "src/ast/statement.ib"
i64 s905_parse_loop(s702_Ast * v1_ast) {
	#line 252
	i64 v2_span_start = s692_curr_span(v1_ast);
	#line 254
	s688_step(v1_ast);
	#line 255
	i64 v3_body = s902_parse_block(v1_ast);
	#line 256
	if ((v3_body == s674_ERROR)) {
		#line 256
		return s674_ERROR;
	}
	#line 258
	i64 v4_node = s696_node_create(v1_ast, s589_NodeKind_Loop);
	#line 259
	s921_LoopData * v5_loop_data = ((s921_LoopData *)s697_node_data(v1_ast, v4_node));
	#line 260
	((*v5_loop_data).body) = v3_body;
	#line 261
	((*v5_loop_data).has_cond) = false;
	#line 262
	((*v5_loop_data).cond) = 0l;
	#line 264
	s699_node_set_span(v1_ast, v4_node, s691_span_end(v1_ast, v2_span_start));
	#line 265
	return v4_node;
}


#line 269 "src/ast/statement.ib"
i64 s906_parse_for(s702_Ast * v1_ast) {
	#line 270
	i64 v2_span_start = s692_curr_span(v1_ast);
	#line 271
	s688_step(v1_ast);
	#line 273
	i64 v3_init = 0l;
	#line 274
	if ((s689_curr(v1_ast) == s616_TokenKind_Let)) {
		#line 275
		v3_init = s901_parse_var_dec(v1_ast, true);
	} else {
#line 277
		v3_init = s867_parse(v1_ast);
		#line 278
		if ((!s694_consume(v1_ast, s616_TokenKind_SemiColon))) {
			#line 279
			return s687_error(v1_ast, s226_ErrorKind_SemicolonExpected);
		}
	}
	#line 283
	((*v1_ast).in_condition) = true;
	#line 284
	i64 v4_cond = s867_parse(v1_ast);
	#line 285
	if ((v4_cond == s674_ERROR)) {
		#line 285
		return s674_ERROR;
	}
	#line 286
	if ((!s694_consume(v1_ast, s616_TokenKind_SemiColon))) {
		#line 287
		return s687_error(v1_ast, s226_ErrorKind_SemicolonExpected);
	}
	#line 290
	i64 v5_acc = s867_parse(v1_ast);
	#line 291
	if ((v5_acc == s674_ERROR)) {
		#line 291
		return s674_ERROR;
	}
	#line 292
	((*v1_ast).in_condition) = false;
	#line 294
	i64 v6_body = s902_parse_block(v1_ast);
	#line 295
	if ((v6_body == s674_ERROR)) {
		#line 295
		return s674_ERROR;
	}
	#line 298
	s920_ForData * v7_for_data = ((s920_ForData *)s580_allocate_extra((&((*((*v1_ast).module)).nodes)), ((i64)32ul)));
	#line 299
	((*v7_for_data).init) = v3_init;
	#line 300
	((*v7_for_data).cond) = v4_cond;
	#line 301
	((*v7_for_data).acc) = v5_acc;
	#line 302
	((*v7_for_data).body) = v6_body;
	#line 304
	i64 v8_node = s696_node_create(v1_ast, s589_NodeKind_For);
	#line 305
	s920_ForData * * v9_node_for_data = ((s920_ForData * *)s697_node_data(v1_ast, v8_node));
	#line 306
	(*v9_node_for_data) = v7_for_data;
	#line 308
	s699_node_set_span(v1_ast, v8_node, s691_span_end(v1_ast, v2_span_start));
	#line 309
	return v8_node;
}


#line 313 "src/ast/statement.ib"
i64 s907_parse_while(s702_Ast * v1_ast) {
	#line 314
	i64 v2_span_start = s692_curr_span(v1_ast);
	#line 315
	s688_step(v1_ast);
	#line 317
	((*v1_ast).in_condition) = true;
	#line 318
	i64 v3_cond = s867_parse(v1_ast);
	#line 319
	((*v1_ast).in_condition) = false;
	#line 320
	if ((v3_cond == s674_ERROR)) {
		#line 320
		return s674_ERROR;
	}
	#line 322
	i64 v4_body = s902_parse_block(v1_ast);
	#line 323
	if ((v4_body == s674_ERROR)) {
		#line 323
		return s674_ERROR;
	}
	#line 325
	i64 v5_node = s696_node_create(v1_ast, s589_NodeKind_Loop);
	#line 326
	s921_LoopData * v6_loop_data = ((s921_LoopData *)s697_node_data(v1_ast, v5_node));
	#line 327
	((*v6_loop_data).has_cond) = true;
	#line 328
	((*v6_loop_data).cond) = v3_cond;
	#line 329
	((*v6_loop_data).body) = v4_body;
	#line 331
	s699_node_set_span(v1_ast, v5_node, s691_span_end(v1_ast, v2_span_start));
	#line 332
	return v5_node;
}


#line 335 "src/ast/statement.ib"
i64 s908_parse_match(s702_Ast * v1_ast) {
	#line 336
	s688_step(v1_ast);
	#line 337
	((*v1_ast).in_condition) = true;
	#line 338
	i64 v2_span_start = s692_curr_span(v1_ast);
	#line 339
	i64 v3_cond = s867_parse(v1_ast);
	#line 340
	i64 v4_span = s691_span_end(v1_ast, v2_span_start);
	#line 341
	((*v1_ast).in_condition) = false;
	#line 342
	if ((v3_cond == s674_ERROR)) {
		#line 342
		return s674_ERROR;
	}
	#line 343
	if ((!s694_consume(v1_ast, s616_TokenKind_BraceL))) {
		#line 344
		return s687_error(v1_ast, s226_ErrorKind_BlockExpected);
	}
	#line 346
	i64 v5_case_count = 0l;
	#line 347
	bool v6_had_errors = false;
	#line 348
	while (1) {
		#line 349
		if ((s689_curr(v1_ast) == s616_TokenKind_BraceR)) {
			#line 349
						goto loop_exit_1;
/* break; */
		}
		#line 351
		s927_MatchCase v7_temp_match_case = ((s927_MatchCase){

		});
		#line 353
		if ((!s909_parse_match_cond(v1_ast, (&v7_temp_match_case)))) {
			#line 353
			return s674_ERROR;
		}
		#line 354
		if ((!s694_consume(v1_ast, s616_TokenKind_FatArrow))) {
			#line 355
			return s687_error(v1_ast, s226_ErrorKind_MissingMatchArrow);
		}
		#line 359
		((*v1_ast).skip_expr_semicolon) = true;
		#line 360
		i64 v8_arm = s900_parse(v1_ast);
		#line 361
		if ((v8_arm == s674_ERROR)) {
			#line 361
			v6_had_errors = true;
		}
		#line 362
		if (s583_is_expression((&((*((*v1_ast).module)).nodes)), v8_arm)) {
			#line 363
			switch (s689_curr(v1_ast)) {
			case s616_TokenKind_SemiColon:
			case s616_TokenKind_Comma: {
			s688_step(v1_ast);
			break; }
			default:
 {
			return s687_error(v1_ast, s226_ErrorKind_SemicolonExpected);
			break; }
}
		}
		#line 369
		(v7_temp_match_case.arm) = v8_arm;
		#line 371
		s927_MatchCase * v9_match_case = ((s927_MatchCase *)s707_push((&((*v1_ast).workstack)), ((i64)32ul)));
		#line 374
		(*v9_match_case) = v7_temp_match_case;
		#line 375
		v5_case_count += 1l;
}
	loop_exit_1:
	#line 377
	s688_step(v1_ast);
	#line 378
	if (v6_had_errors) {
		#line 378
		return s674_ERROR;
	}
	#line 380
	i64 v10_node = s696_node_create(v1_ast, s589_NodeKind_Match);
	#line 381
	s926_MatchData * v11_match_data = ((s926_MatchData *)s697_node_data(v1_ast, v10_node));
	#line 382
	s699_node_set_span(v1_ast, v10_node, v4_span);
	#line 383
	((*v11_match_data).cond) = v3_cond;
	#line 384
	((*v11_match_data).count) = v5_case_count;
	#line 385
	((*v11_match_data).cases) = ((s927_MatchCase *)s580_allocate_extra((&((*((*v1_ast).module)).nodes)), ((i64)(32ul * ((u64)v5_case_count)))));
	#line 389
	for (i64 v12_i = (v5_case_count - 1l);(v12_i >= 0l);v12_i -= 1l) {
		#line 390
		s927_MatchCase * v13_case = ((s927_MatchCase *)s708_pop((&((*v1_ast).workstack)), ((i64)32ul)));
		#line 391
		(((*v11_match_data).cases)[v12_i]) = (*v13_case);
	}
	loop_exit_2:
	#line 394
	return v10_node;
}


#line 397 "src/ast/statement.ib"
bool s909_parse_match_cond(s702_Ast * v1_ast, s927_MatchCase * v2_case) {
	#line 398
	i64 v3_cond_count = 0l;
	#line 399
	bool v4_had_default = false;
	#line 400
	bool v5_had_error = false;
	#line 401
	s963_infix_set_disabled((&((*v1_ast).infix)), s616_TokenKind_Pipe, true);
	#line 404
	while (1) {
		#line 405
		if (s910_match_identifier(v1_ast, "_")) {
			#line 406
			if (v4_had_default) {
				#line 407
				v5_had_error = true;
				#line 408
				s687_error(v1_ast, s226_ErrorKind_DuplicateDefaultMatchCase);
			}
			#line 410
			v4_had_default = true;
			#line 411
			((*v2_case).has_default) = true;
			#line 412
			s688_step(v1_ast);
		} else {
#line 414
			i64 v6_expr = s867_parse(v1_ast);
			#line 415
			if ((v6_expr == s674_ERROR)) {
				#line 415
				v5_had_error = true;
			}
			#line 416
			s700_work_push(v1_ast, v6_expr);
			#line 417
			v3_cond_count += 1l;
		}
		#line 419
		if ((s689_curr(v1_ast) == s616_TokenKind_Pipe)) {
			#line 420
			s688_step(v1_ast);
			#line 421
			continue;
		}
		#line 423
				goto loop_exit_1;
/* break; */
}
	loop_exit_1:
	#line 425
	s963_infix_set_disabled((&((*v1_ast).infix)), s616_TokenKind_Pipe, false);
	#line 428
	((*v2_case).cond_count) = v3_cond_count;
	#line 429
	((*v2_case).conds) = ((i64 *)s580_allocate_extra((&((*((*v1_ast).module)).nodes)), ((i64)(8ul * ((u64)v3_cond_count)))));
	#line 433
	for (i64 v7_i = (v3_cond_count - 1l);(v7_i >= 0l);v7_i -= 1l) {
		#line 434
		(((*v2_case).conds)[v7_i]) = s701_work_pop(v1_ast);
	}
	loop_exit_2:
	#line 436
	return (!v5_had_error);
}


#line 439 "src/ast/statement.ib"
bool s910_match_identifier(s702_Ast * v1_ast, char * v2_string) {
	#line 440
	if ((s689_curr(v1_ast) != s616_TokenKind_Ident)) {
		#line 440
		return false;
	}
	#line 441
	s614_Token * v3_token = s695_curr_token(v1_ast);
	#line 442
	return (((i64)strcmp(v2_string, (((*v3_token).data).ident))) == 0l);
}


#line 446 "src/ast/statement.ib"
i64 s911_parse_simple_statement(s702_Ast * v1_ast, s589_NodeKind v2_kind) {
	#line 447
	i64 v3_node = s696_node_create(v1_ast, v2_kind);
	#line 449
	i64 v4_span_start = s692_curr_span(v1_ast);
	#line 450
	s688_step(v1_ast);
	#line 451
	s699_node_set_span(v1_ast, v3_node, s691_span_end(v1_ast, v4_span_start));
	#line 453
	if ((!s694_consume(v1_ast, s616_TokenKind_SemiColon))) {
		#line 454
		return s687_error(v1_ast, s226_ErrorKind_SemicolonExpected);
	}
	#line 457
	return v3_node;
}


#line 466 "src/ast/statement.ib"
i64 s912_block_get(s923_BlockData * v1_block, i64 v2_index) {
	#line 467
	if ((v2_index >= ((*v1_block).count))) {
		#line 467
		return s577_NONE;
	}
	#line 468
	return (((*v1_block).nodes)[v2_index]);
}


#line 472 "src/ast/statement.ib"
void s913_debug_var_decl(s299_StringBuilder * v1_sb, s585_Nodes * v2_nodes, bool v3_mutable, s924_VarDeclaration * v4_var_decl, i64 v5_depth) {
	#line 473
	s288_repeat(v1_sb, "  ", v5_depth);
	#line 474
	s283_append(v1_sb, "VAR_DECL ");
	#line 475
	if (v3_mutable) {
		#line 476
		s283_append(v1_sb, "LET\n");
	} else {
#line 478
		s283_append(v1_sb, "CONST\n");
	}
	#line 480
	s584_debug(v1_sb, v2_nodes, ((*v4_var_decl).ident), (v5_depth + 1l));
	#line 481
	s288_repeat(v1_sb, "  ", (v5_depth + 1l));
	#line 482
	if ((((*v4_var_decl).type) != ((s586_TypeData *)NULL))) {
		#line 483
		s283_append(v1_sb, "TYPE: ");
		#line 484
		s210_debug(v1_sb, v2_nodes, ((*((*v4_var_decl).type)).type), v5_depth);
		#line 485
		s283_append(v1_sb, "\n");
	} else {
#line 487
		s283_append(v1_sb, "TYPE: NONE\n");
	}
	#line 489
	s584_debug(v1_sb, v2_nodes, ((*v4_var_decl).value), (v5_depth + 2l));
}


#line 493 "src/ast/statement.ib"
void s914_debug_block(s299_StringBuilder * v1_sb, s585_Nodes * v2_nodes, s923_BlockData * v3_block, i64 v4_depth) {
	#line 494
	s288_repeat(v1_sb, "  ", v4_depth);
	#line 495
	s283_append(v1_sb, "BLOCK\n");
	#line 496
	for (i64 v5_i = 0l;(v5_i < ((*v3_block).count));v5_i += 1l) {
		#line 497
		i64 v6_n = s912_block_get(v3_block, v5_i);
		#line 498
		s40_assert((v6_n != s577_NONE), "statement::debug_block");
		#line 499
		s584_debug(v1_sb, v2_nodes, v6_n, (v4_depth + 1l));
	}
	loop_exit_1:
}


#line 504 "src/ast/statement.ib"
void s915_debug_if(s299_StringBuilder * v1_sb, s585_Nodes * v2_nodes, s922_IfData * v3_if_data, i64 v4_depth) {
	#line 505
	s288_repeat(v1_sb, "  ", v4_depth);
	#line 506
	s283_append(v1_sb, "IF\n");
	#line 507
	s584_debug(v1_sb, v2_nodes, ((*v3_if_data).cond), (v4_depth + 1l));
	#line 508
	s288_repeat(v1_sb, "  ", (v4_depth + 1l));
	#line 509
	s283_append(v1_sb, "THEN\n");
	#line 510
	s584_debug(v1_sb, v2_nodes, ((*v3_if_data).then), (v4_depth + 2l));
	#line 511
	if ((((*v3_if_data).otherwise) != s577_NONE)) {
		#line 512
		s288_repeat(v1_sb, "  ", (v4_depth + 1l));
		#line 513
		s283_append(v1_sb, "ELSE\n");
		#line 514
		s584_debug(v1_sb, v2_nodes, ((*v3_if_data).otherwise), (v4_depth + 2l));
	}
}


#line 519 "src/ast/statement.ib"
void s916_debug_return(s299_StringBuilder * v1_sb, s585_Nodes * v2_nodes, s925_ReturnData * v3_return_data, i64 v4_depth) {
	#line 520
	s288_repeat(v1_sb, "  ", v4_depth);
	#line 521
	s283_append(v1_sb, "RETURN\n");
	#line 522
	if (((*v3_return_data).has_value)) {
		#line 523
		s584_debug(v1_sb, v2_nodes, ((*v3_return_data).value), (v4_depth + 1l));
	}
}


#line 528 "src/ast/statement.ib"
void s917_debug_loop(s299_StringBuilder * v1_sb, s585_Nodes * v2_nodes, s921_LoopData * v3_loop_data, i64 v4_depth) {
	#line 529
	s288_repeat(v1_sb, "  ", v4_depth);
	#line 530
	if (((*v3_loop_data).has_cond)) {
		#line 531
		s283_append(v1_sb, "WHILE\n");
		#line 532
		s584_debug(v1_sb, v2_nodes, ((*v3_loop_data).cond), (v4_depth + 1l));
	} else {
#line 534
		s283_append(v1_sb, "LOOP\n");
	}
	#line 536
	s584_debug(v1_sb, v2_nodes, ((*v3_loop_data).body), (v4_depth + 1l));
}


#line 540 "src/ast/statement.ib"
void s918_debug_for(s299_StringBuilder * v1_sb, s585_Nodes * v2_nodes, s920_ForData * * v3_for_data, i64 v4_depth) {
	#line 541
	s288_repeat(v1_sb, "  ", v4_depth);
	#line 542
	s283_append(v1_sb, "FOR\n");
	#line 543
	s920_ForData * v5_for_data = (*v3_for_data);
	#line 544
	s584_debug(v1_sb, v2_nodes, ((*v5_for_data).init), (v4_depth + 2l));
	#line 545
	s288_repeat(v1_sb, "  ", (v4_depth + 1l));
	#line 546
	s283_append(v1_sb, "COND\n");
	#line 547
	s584_debug(v1_sb, v2_nodes, ((*v5_for_data).cond), (v4_depth + 2l));
	#line 548
	s288_repeat(v1_sb, "  ", (v4_depth + 1l));
	#line 549
	s283_append(v1_sb, "ACC\n");
	#line 550
	s584_debug(v1_sb, v2_nodes, ((*v5_for_data).acc), (v4_depth + 2l));
	#line 551
	s288_repeat(v1_sb, "  ", (v4_depth + 1l));
	#line 552
	s283_append(v1_sb, "BODY\n");
	#line 553
	s584_debug(v1_sb, v2_nodes, ((*v5_for_data).body), (v4_depth + 2l));
}


#line 557 "src/ast/statement.ib"
void s919_debug_match(s299_StringBuilder * v1_sb, s585_Nodes * v2_nodes, s926_MatchData * v3_match_data, i64 v4_depth) {
	#line 558
	s288_repeat(v1_sb, "  ", v4_depth);
	#line 559
	s283_append(v1_sb, "MATCH\n");
	#line 560
	s584_debug(v1_sb, v2_nodes, ((*v3_match_data).cond), (v4_depth + 1l));
	#line 561
	for (i64 v5_i = 0l;(v5_i < ((*v3_match_data).count));v5_i += 1l) {
		#line 562
		s288_repeat(v1_sb, "  ", (v4_depth + 1l));
		#line 563
		s283_append(v1_sb, "CASE[");
		#line 564
		s289_append_number(v1_sb, v5_i);
		#line 565
		s283_append(v1_sb, "]\n");
		#line 566
		s927_MatchCase v6_case = (((*v3_match_data).cases)[v5_i]);
		#line 568
		if ((v6_case.has_default)) {
			#line 569
			s288_repeat(v1_sb, "  ", (v4_depth + 2l));
			#line 570
			s283_append(v1_sb, "[DEFAULT]\n");
		}
		#line 572
		for (i64 v7_i = 0l;(v7_i < (v6_case.cond_count));v7_i += 1l) {
			#line 573
			s584_debug(v1_sb, v2_nodes, ((v6_case.conds)[v7_i]), (v4_depth + 2l));
		}
		loop_exit_2:
		#line 575
		s288_repeat(v1_sb, "  ", (v4_depth + 1l));
		#line 576
		s283_append(v1_sb, "THEN\n");
		#line 577
		s584_debug(v1_sb, v2_nodes, (v6_case.arm), (v4_depth + 2l));
	}
	loop_exit_1:
}


#line 17 "src/ast/enums.ib"
i64 s928_parse_enum(s702_Ast * v1_ast) {
	#line 18
	s688_step(v1_ast);
	#line 19
	s672_EnumDef * v2_enum_def = ((s672_EnumDef *)s249_push((&((*((*v1_ast).module)).enums))));
	#line 21
	bool v3_is_public = ((*v1_ast).is_public);
	#line 22
	i64 v4_span = s692_curr_span(v1_ast);
	#line 23
	char * v5_name = ((char *)NULL);
	#line 24
	if ((s686_consume_ident(v1_ast, (&v5_name), s226_ErrorKind_EnumDefNameExpected) == s674_ERROR)) {
		#line 25
		return s674_ERROR;
	}
	#line 27
	((*v2_enum_def).declaration) = ((s662_Declaration){
		.name = v5_name,
		.is_public = v3_is_public,
		.span = v4_span,
		.symbol = s168_NONE
	});
	#line 32
	if ((s929_parse_enum_fields(v1_ast, v2_enum_def) == s674_ERROR)) {
		#line 32
		return s674_ERROR;
	}
	#line 34
	((*v2_enum_def).fields) = ((s673_EnumField *)s561_allocate((&((*((*v1_ast).module)).object_data)), ((i64)(24ul * ((u64)((*v2_enum_def).field_count))))));
	#line 39
	for (i64 v6_i = (((*v2_enum_def).field_count) - 1l);(v6_i >= 0l);v6_i -= 1l) {
		#line 40
		s673_EnumField * v7_enum_field = ((s673_EnumField *)s708_pop((&((*v1_ast).workstack)), ((i64)24ul)));
		#line 41
		(((*v2_enum_def).fields)[v6_i]) = (*v7_enum_field);
	}
	loop_exit_1:
	#line 43
	return ((i64)s704_Declaration_Enum);
}


#line 47 "src/ast/enums.ib"
i64 s929_parse_enum_fields(s702_Ast * v1_ast, s672_EnumDef * v2_enum_def) {
	#line 48
	((*v2_enum_def).field_count) = 0l;
	#line 49
	if ((!s694_consume(v1_ast, s616_TokenKind_BraceL))) {
		#line 50
		return s687_error(v1_ast, s226_ErrorKind_EnumDefBraceLExpected);
	}
	#line 52
	bool v3_had_errors = false;
	#line 53
	while (1) {
		#line 54
		if (s681_curr_is_declaration(v1_ast)) {
			#line 55
			if ((!v3_had_errors)) {
				#line 55
				s687_error(v1_ast, s226_ErrorKind_EnumDefFieldExpected);
			}
			#line 56
			return s674_ERROR;
		}
		#line 58
		if ((s689_curr(v1_ast) == s616_TokenKind_BraceR)) {
			#line 59
			s688_step(v1_ast);
			#line 60
						goto loop_exit_1;
/* break; */
		}
		#line 62
		((*v2_enum_def).field_count) += 1l;
		#line 63
		s673_EnumField * v4_enum_field = ((s673_EnumField *)s707_push((&((*v1_ast).workstack)), ((i64)24ul)));
		#line 65
		i64 v5_span_start = s692_curr_span(v1_ast);
		#line 66
		if ((s686_consume_ident(v1_ast, (&((*v4_enum_field).field)), s226_ErrorKind_EnumDefFieldExpected) == s674_ERROR)) {
			#line 67
			v3_had_errors = true;
			#line 68
			continue;
		}
		#line 70
		((*v4_enum_field).field_span) = s691_span_end(v1_ast, v5_span_start);
		#line 71
		((*v4_enum_field).value) = 0l;
		#line 73
		if ((s689_curr(v1_ast) == s616_TokenKind_Equal)) {
			#line 74
			s688_step(v1_ast);
			#line 75
			((*v4_enum_field).value) = s867_parse(v1_ast);
			#line 76
			if ((((*v4_enum_field).value) == s674_ERROR)) {
				#line 77
				v3_had_errors = true;
				#line 78
				continue;
			}
		}
		#line 82
		if ((s689_curr(v1_ast) == s616_TokenKind_Comma)) {
			#line 83
			s688_step(v1_ast);
			#line 84
			continue;
		}
		#line 87
		if ((!s694_consume(v1_ast, s616_TokenKind_BraceR))) {
			#line 88
			return s687_error(v1_ast, s226_ErrorKind_EnumDefCommaExpected);
		}
		#line 90
				goto loop_exit_1;
/* break; */
}
	loop_exit_1:
	#line 92
	if (v3_had_errors) {
		#line 92
		return s674_ERROR;
	}
	#line 93
	return s675_SUCCESS;
}


#line 17 "src/ast/object.ib"
i64 s930_parse_struct(s702_Ast * v1_ast) {
	#line 18
	s688_step(v1_ast);
	#line 19
	s670_ObjectDef * v2_strct = ((s670_ObjectDef *)s249_push((&((*((*v1_ast).module)).structs))));
	#line 20
	if ((s932_parse_object_def(v1_ast, v2_strct) == s674_ERROR)) {
		#line 20
		return s674_ERROR;
	}
	#line 21
	return ((i64)s704_Declaration_Struct);
}


#line 25 "src/ast/object.ib"
i64 s931_parse_union(s702_Ast * v1_ast) {
	#line 26
	s688_step(v1_ast);
	#line 27
	s670_ObjectDef * v2__union = ((s670_ObjectDef *)s249_push((&((*((*v1_ast).module)).unions))));
	#line 28
	if ((s932_parse_object_def(v1_ast, v2__union) == s674_ERROR)) {
		#line 28
		return s674_ERROR;
	}
	#line 29
	return ((i64)s704_Declaration_Union);
}


#line 33 "src/ast/object.ib"
i64 s932_parse_object_def(s702_Ast * v1_ast, s670_ObjectDef * v2_obj_def) {
	#line 34
	char * v3_name = ((char *)NULL);
	#line 35
	bool v4_is_public = ((*v1_ast).is_public);
	#line 37
	i64 v5_span = s692_curr_span(v1_ast);
	#line 38
	if ((s686_consume_ident(v1_ast, (&v3_name), s226_ErrorKind_ObjectDefNameExpected) == s674_ERROR)) {
		#line 39
		return s674_ERROR;
	}
	#line 41
	i64 v6_field_count = 0l;
	#line 42
	if ((s933_parse_object_fields(v1_ast, (&v6_field_count)) == s674_ERROR)) {
		#line 42
		return s674_ERROR;
	}
	#line 44
	((*v2_obj_def).fields) = ((s671_ObjectField *)s561_allocate((&((*((*v1_ast).module)).object_data)), ((i64)(32ul * ((u64)v6_field_count)))));
	#line 48
	((*v2_obj_def).field_count) = v6_field_count;
	#line 49
	((*v2_obj_def).declaration) = ((s662_Declaration){
		.is_public = v4_is_public,
		.name = v3_name,
		.span = v5_span,
		.symbol = s168_NONE
	});
	#line 54
	for (i64 v7_i = (v6_field_count - 1l);(v7_i >= 0l);v7_i -= 1l) {
		#line 55
		s671_ObjectField * v8_object_field = ((s671_ObjectField *)s708_pop((&((*v1_ast).workstack)), ((i64)32ul)));
		#line 56
		(((*v2_obj_def).fields)[v7_i]) = (*v8_object_field);
	}
	loop_exit_1:
	#line 59
	return s675_SUCCESS;
}


#line 64 "src/ast/object.ib"
i64 s933_parse_object_fields(s702_Ast * v1_ast, i64 * v2_count) {
	#line 65
	if ((!s694_consume(v1_ast, s616_TokenKind_BraceL))) {
		#line 66
		return s687_error(v1_ast, s226_ErrorKind_ObjectDefBraceLExpected);
	}
	#line 68
	bool v3_had_errors = false;
	#line 69
	while (1) {
		#line 70
		if (s681_curr_is_declaration(v1_ast)) {
			#line 71
			if ((!v3_had_errors)) {
				#line 71
				s687_error(v1_ast, s226_ErrorKind_ObjectDefFieldExpected);
			}
			#line 72
			return s674_ERROR;
		}
		#line 74
		if ((s689_curr(v1_ast) == s616_TokenKind_BraceR)) {
			#line 75
			s688_step(v1_ast);
			#line 76
						goto loop_exit_1;
/* break; */
		}
		#line 78
		(*v2_count) = ((*v2_count) + 1l);
		#line 79
		s671_ObjectField * v4_object_field = ((s671_ObjectField *)s707_push((&((*v1_ast).workstack)), ((i64)32ul)));
		#line 81
		i64 v5_span_start = s692_curr_span(v1_ast);
		#line 82
		if ((s686_consume_ident(v1_ast, (&((*v4_object_field).field)), s226_ErrorKind_ObjectDefFieldExpected) == s674_ERROR)) {
			#line 86
			v3_had_errors = true;
			#line 87
			continue;
		}
		#line 89
		((*v4_object_field).field_span) = s691_span_end(v1_ast, v5_span_start);
		#line 91
		if ((!s694_consume(v1_ast, s616_TokenKind_Colon))) {
			#line 92
			s687_error(v1_ast, s226_ErrorKind_ObjectDefColonExpected);
			#line 93
			v3_had_errors = true;
			#line 94
			continue;
		}
		#line 96
		((*v1_ast).typeident_context) = s703_TypeIdentContext_ObjectDef;
		#line 97
		s959_TypeIdentResult v6_type_res = s951_parse(v1_ast);
		#line 98
		if ((!(v6_type_res.success))) {
			#line 99
			v3_had_errors = true;
			#line 100
			continue;
		}
		#line 103
		((*v4_object_field).type) = (v6_type_res.type);
		#line 104
		((*v4_object_field).type_span) = (v6_type_res.span);
		#line 106
		if ((s689_curr(v1_ast) == s616_TokenKind_Comma)) {
			#line 107
			s688_step(v1_ast);
			#line 108
			continue;
		}
		#line 110
		if ((!s694_consume(v1_ast, s616_TokenKind_BraceR))) {
			#line 111
			return s687_error(v1_ast, s226_ErrorKind_ObjectDefCommaExpected);
		}
		#line 113
				goto loop_exit_1;
/* break; */
}
	loop_exit_1:
	#line 115
	if (v3_had_errors) {
		#line 115
		return s674_ERROR;
	}
	#line 116
	return s675_SUCCESS;
}


#line 120 "src/ast/object.ib"
i64 s934_parse_object_init(s702_Ast * v1_ast) {
	#line 121
	i64 v2_span_start = s692_curr_span(v1_ast);
	#line 122
	char * v3_type = ((char *)NULL);
	#line 123
	if ((s686_consume_ident(v1_ast, (&v3_type), s226_ErrorKind_ObjectInitNameExpected) == s674_ERROR)) {
		#line 123
		return s674_ERROR;
	}
	#line 124
	s688_step(v1_ast);
	#line 126
	i64 v4_field_count = 0l;
	#line 127
	if ((s935_parse_object_field_inits(v1_ast, (&v4_field_count)) == s674_ERROR)) {
		#line 127
		return s674_ERROR;
	}
	#line 129
	i64 v5_node = s696_node_create(v1_ast, s589_NodeKind_ObjectInit);
	#line 130
	s891_ObjectInit * v6_init = ((s891_ObjectInit *)s697_node_data(v1_ast, v5_node));
	#line 131
	((*v6_init).type) = v3_type;
	#line 132
	((*v6_init).field_count) = v4_field_count;
	#line 133
	((*v6_init).fields) = ((s892_ObjectFieldInit *)s580_allocate_extra((&((*((*v1_ast).module)).nodes)), ((i64)(24ul * ((u64)((*v6_init).field_count))))));
	#line 137
	for (i64 v7_i = (((*v6_init).field_count) - 1l);(v7_i >= 0l);v7_i -= 1l) {
		#line 138
		s892_ObjectFieldInit * v8_field_init = ((s892_ObjectFieldInit *)s708_pop((&((*v1_ast).workstack)), ((i64)24ul)));
		#line 139
		(((*v6_init).fields)[v7_i]) = (*v8_field_init);
	}
	loop_exit_1:
	#line 141
	s699_node_set_span(v1_ast, v5_node, v2_span_start);
	#line 142
	return v5_node;
}


#line 145 "src/ast/object.ib"
i64 s935_parse_object_field_inits(s702_Ast * v1_ast, i64 * v2_field_count) {
	#line 146
	(*v2_field_count) = 0l;
	#line 147
	while (1) {
		#line 148
		if ((s689_curr(v1_ast) == s616_TokenKind_BraceR)) {
			#line 149
			s688_step(v1_ast);
			#line 150
						goto loop_exit_1;
/* break; */
		}
		#line 152
		(*v2_field_count) += 1l;
		#line 153
		s892_ObjectFieldInit * v3_field_init = ((s892_ObjectFieldInit *)s707_push((&((*v1_ast).workstack)), ((i64)24ul)));
		#line 155
		i64 v4_span_start = s692_curr_span(v1_ast);
		#line 156
		if ((s686_consume_ident(v1_ast, (&((*v3_field_init).field)), s226_ErrorKind_ObjectInitFieldExpected) == s674_ERROR)) {
			#line 157
			return s674_ERROR;
		}
		#line 159
		((*v3_field_init).field_span) = s691_span_end(v1_ast, v4_span_start);
		#line 160
		((*v3_field_init).value) = s577_NONE;
		#line 161
		if ((s689_curr(v1_ast) == s616_TokenKind_Colon)) {
			#line 162
			s688_step(v1_ast);
			#line 163
			((*v3_field_init).value) = s867_parse(v1_ast);
			#line 164
			if ((((*v3_field_init).value) == s674_ERROR)) {
				#line 165
				return s674_ERROR;
			}
		} else {
#line 168
			i64 v5_node = s696_node_create(v1_ast, s589_NodeKind_Ident);
			#line 169
			char * * v6_ident = ((char * *)s697_node_data(v1_ast, v5_node));
			#line 170
			(*v6_ident) = ((*v3_field_init).field);
			#line 171
			s699_node_set_span(v1_ast, v5_node, ((*v3_field_init).field_span));
			#line 172
			((*v3_field_init).value) = v5_node;
		}
		#line 175
		if ((s689_curr(v1_ast) == s616_TokenKind_Comma)) {
			#line 176
			s688_step(v1_ast);
			#line 177
			continue;
		}
		#line 179
		if ((!s694_consume(v1_ast, s616_TokenKind_BraceR))) {
			#line 180
			return s687_error(v1_ast, s226_ErrorKind_ObjectInitCommaExpected);
		}
		#line 182
				goto loop_exit_1;
/* break; */
}
	loop_exit_1:
	#line 184
	return s675_SUCCESS;
}


#line 15 "src/ast/function.ib"
i64 s936_parse(s702_Ast * v1_ast) {
	#line 16
	s688_step(v1_ast);
	#line 18
	s665_Prototype v2_proto = ((s665_Prototype){

	});
	#line 19
	bool v3_had_errors = false;
	#line 20
	if ((s937_parse_prototype(v1_ast, (&v2_proto)) == s674_ERROR)) {
		#line 20
		v3_had_errors = true;
	}
	#line 22
	if ((v3_had_errors && s681_curr_is_declaration(v1_ast))) {
		#line 22
		return s674_ERROR;
	}
	#line 24
	i64 v4_body = s902_parse_block(v1_ast);
	#line 25
	if ((v4_body == s674_ERROR)) {
		#line 25
		v3_had_errors = true;
	}
	#line 27
	if (v3_had_errors) {
		#line 27
		return s674_ERROR;
	}
	#line 29
	s663_Function * v5_function = ((s663_Function *)s249_push((&((*((*v1_ast).module)).functions))));
	#line 30
	bool v6_is_public = ((*v1_ast).is_public);
	#line 31
	i64 v7_span = (v2_proto.span);
	#line 32
	char * v8_name = (v2_proto.identifier);
	#line 33
	(*v5_function) = ((s663_Function){
		.proto = v2_proto,
		.body = v4_body,
		.declaration = ((s662_Declaration){
			.name = v8_name,
			.is_public = v6_is_public,
			.span = v7_span,
			.symbol = s168_NONE
		})
	});
	#line 41
	return ((i64)s704_Declaration_Function);
}


#line 44 "src/ast/function.ib"
i64 s937_parse_prototype(s702_Ast * v1_ast, s665_Prototype * v2_proto) {
	#line 45
	((*v2_proto).span) = s692_curr_span(v1_ast);
	#line 46
	if ((s686_consume_ident(v1_ast, (&((*v2_proto).identifier)), s226_ErrorKind_PrototypeNameExpected) == s674_ERROR)) {
		#line 46
		return s674_ERROR;
	}
	#line 48
	i64 v3_args = s938_parse_prototype_args(v1_ast, v2_proto);
	#line 49
	if ((v3_args == s674_ERROR)) {
		#line 49
		return s674_ERROR;
	}
	#line 50
	if ((s689_curr(v1_ast) == s616_TokenKind_Colon)) {
		#line 51
		s688_step(v1_ast);
		#line 52
		((*v1_ast).typeident_context) = s703_TypeIdentContext_ProtoFlowType;
		#line 53
		if ((s953_parse_flowtype(v1_ast, (&((*v2_proto).return_type)), (&((*v2_proto).return_span))) == s674_ERROR)) {
			#line 54
			return s674_ERROR;
		}
	} else {
#line 57
		(((*v2_proto).return_type).kind) = s220_FlowTypeKind_Void;
		#line 58
		((*v2_proto).return_span) = s693_prev_span(v1_ast);
	}
	#line 61
	return s675_SUCCESS;
}


#line 65 "src/ast/function.ib"
i64 s938_parse_prototype_args(s702_Ast * v1_ast, s665_Prototype * v2_proto) {
	#line 66
	if ((!s694_consume(v1_ast, s616_TokenKind_ParenL))) {
		#line 67
		return s687_error(v1_ast, s226_ErrorKind_PrototypeParenLExpected);
	}
	#line 69
	bool v3_has_varargs = false;
	#line 70
	((*v2_proto).arg_index) = (((*((*v1_ast).module)).args).count);
	#line 71
	((*v2_proto).arg_count) = 0l;
	#line 72
	((*v2_proto).has_varargs) = false;
	#line 73
	while (1) {
		#line 74
		switch (s689_curr(v1_ast)) {
		case s616_TokenKind_ParenR: {
			#line 76
			s688_step(v1_ast);
			#line 76
						goto loop_exit_1;
/* break; */
		break; }
		case s616_TokenKind_DotDotDot: {
			#line 79
			s688_step(v1_ast);
			#line 80
			if ((!s694_consume(v1_ast, s616_TokenKind_ParenR))) {
				#line 81
				return s687_error(v1_ast, s226_ErrorKind_PrototypeArgsAfterVarargsNotAllowed);
			}
			#line 83
			v3_has_varargs = true;
			#line 84
			((*v2_proto).has_varargs) = true;
			#line 85
						goto loop_exit_1;
/* break; */
		break; }
		case s616_TokenKind_Ident: {
			#line 88
			s614_Token * v4_token = s695_curr_token(v1_ast);
			#line 89
			i64 v5_span = s692_curr_span(v1_ast);
			#line 90
			char * v6_ident = (((*v4_token).data).ident);
			#line 91
			s688_step(v1_ast);
			#line 92
			if ((!s694_consume(v1_ast, s616_TokenKind_Colon))) {
				#line 93
				return s687_error(v1_ast, s226_ErrorKind_TypeIdentExpected);
			}
			#line 95
			((*v1_ast).typeident_context) = s703_TypeIdentContext_ProtoArgs;
			#line 96
			s959_TypeIdentResult v7_typeident_result = s951_parse(v1_ast);
			#line 97
			if ((!(v7_typeident_result.success))) {
				#line 97
				return s674_ERROR;
			}
			#line 99
			s666_Arg * v8_arg = ((s666_Arg *)s249_push((&((*((*v1_ast).module)).args))));
			#line 100
			i64 v9_type_span = (v7_typeident_result.span);
			#line 101
			s214_TypeIdent * v10_type = (v7_typeident_result.type);
			#line 102
			(*v8_arg) = ((s666_Arg){
				.ident = v6_ident,
				.span = v5_span,
				.type_span = v9_type_span,
				.type = v10_type
			});
			#line 105
			((*v2_proto).arg_count) += 1l;
		break; }
		default:
 {
		return s687_error(v1_ast, s226_ErrorKind_PrototypeArgExpected);
		break; }
}
		#line 109
		if ((s689_curr(v1_ast) == s616_TokenKind_Comma)) {
			#line 110
			s688_step(v1_ast);
		} else if (s694_consume(v1_ast, s616_TokenKind_ParenR)) {
			#line 112
						goto loop_exit_1;
/* break; */
		} else {
#line 114
			return s687_error(v1_ast, s226_ErrorKind_PrototypeParenRExpected);
		}
}
	loop_exit_1:
	#line 117
	return 0l;
}


#line 5 "src/ast/recovery.ib"
void s939_recover_from_error(s702_Ast * v1_ast, s226_ErrorKind v2_kind) {
	#line 6
	switch (v2_kind) {
	case s226_ErrorKind_DuplicateSymbol: {
	break; }
	case s226_ErrorKind_UnterminatedBlock:
	case s226_ErrorKind_UnterminatedParen:
	case s226_ErrorKind_UnterminatedBracket: {
	s940_skip_until(v1_ast, s949_shared_recovery);
	break; }
	case s226_ErrorKind_MissingMatchArrow:
	case s226_ErrorKind_DuplicateDefaultMatchCase: {
	s940_skip_until(v1_ast, s942_semicolon_recovery);
	break; }
	case s226_ErrorKind_ObjectInitNameExpected:
	case s226_ErrorKind_SemicolonExpected:
	case s226_ErrorKind_BlockExpected:
	case s226_ErrorKind_CommaExpected:
	case s226_ErrorKind_InvalidPrimary:
	case s226_ErrorKind_VarDeclEqExpected:
	case s226_ErrorKind_SizeOfMissingParenL:
	case s226_ErrorKind_SizeOfMissingParenR:
	case s226_ErrorKind_IdentifierExpected:
	case s226_ErrorKind_ObjectInitFieldExpected:
	case s226_ErrorKind_ObjectInitCommaExpected: {
	s940_skip_until(v1_ast, s943_statement_recovery);
	break; }
	case s226_ErrorKind_DuplicatePubForDeclaration:
	case s226_ErrorKind_ImportCannotBePublic:
	case s226_ErrorKind_ImportAliasEqExpected:
	case s226_ErrorKind_ImportPathExpected:
	case s226_ErrorKind_ImportAliasExpected:
	case s226_ErrorKind_ObjectDefBraceLExpected:
	case s226_ErrorKind_ObjectDefCommaExpected:
	case s226_ErrorKind_InvalidExtern:
	case s226_ErrorKind_GlobalNameExpected:
	case s226_ErrorKind_ExternGlobalNameExpected:
	case s226_ErrorKind_UnknownDeclaration: {
	s940_skip_until(v1_ast, s949_shared_recovery);
	break; }
	case s226_ErrorKind_PrototypeParenLExpected:
	case s226_ErrorKind_PrototypeArgsAfterVarargsNotAllowed:
	case s226_ErrorKind_PrototypeArgExpected:
	case s226_ErrorKind_PrototypeParenRExpected:
	case s226_ErrorKind_PrototypeNameExpected: {
	s940_skip_until(v1_ast, s944_next_block_recovery);
	break; }
	case s226_ErrorKind_InvalidTypeIdent:
	case s226_ErrorKind_TypeIdentPathExpected:
	case s226_ErrorKind_TypeIdentFnParenExpected:
	case s226_ErrorKind_TypeIdentExpected:
	case s226_ErrorKind_MissingTypeIdent:
	case s226_ErrorKind_TypeIdentFnFlowTypeRequired:
	case s226_ErrorKind_TypeIdentArrayBracketRExpected: {
		#line 63
		switch (((*v1_ast).typeident_context)) {
		case s703_TypeIdentContext_ObjectDef: {
		s940_skip_until(v1_ast, s945_object_recovery);
		break; }
		case s703_TypeIdentContext_VarDeclaration: {
		s940_skip_until(v1_ast, s946_var_decl_recovery);
		break; }
		case s703_TypeIdentContext_ProtoArgs: {
		s940_skip_until(v1_ast, s947_proto_arg_recovery);
		break; }
		case s703_TypeIdentContext_ProtoFlowType: {
		s940_skip_until(v1_ast, s948_proto_flow_recovery);
		break; }
		case s703_TypeIdentContext_SizeOf: {
		s940_skip_until(v1_ast, s942_semicolon_recovery);
		break; }
		case s703_TypeIdentContext_Cast: {
		s940_skip_until(v1_ast, s942_semicolon_recovery);
		break; }
		default:
			abort();
}
	break; }
	case s226_ErrorKind_ObjectDefNameExpected:
	case s226_ErrorKind_EnumDefNameExpected: {
	s940_skip_until(v1_ast, s949_shared_recovery);
	break; }
	case s226_ErrorKind_ObjectDefFieldExpected:
	case s226_ErrorKind_EnumDefFieldExpected:
	case s226_ErrorKind_EnumDefBraceLExpected:
	case s226_ErrorKind_EnumDefCommaExpected:
	case s226_ErrorKind_ObjectDefColonExpected: {
	s940_skip_until(v1_ast, s945_object_recovery);
	break; }
	default:
		abort();
}
}


#line 87 "src/ast/recovery.ib"
void s940_skip_until(s702_Ast * v1_ast, s950_RecoveryResult (* v2_pred)(s616_TokenKind)) {
	#line 88
	while (1) {
		#line 89
		s616_TokenKind v3_t = s689_curr(v1_ast);
		#line 90
		if ((v3_t == s616_TokenKind_EOF)) {
			#line 90
			return;
		}
		#line 91
		switch (v2_pred(v3_t)) {
		case s950_RecoveryResult_Recovered: {
		return;
		break; }
		case s950_RecoveryResult_RecoveredOnNext: {
			#line 94
			s688_step(v1_ast);
			#line 95
			return;
		break; }
		case s950_RecoveryResult_Skip: {
		break; }
		default:
			abort();
}
		#line 100
		s688_step(v1_ast);
}
	loop_exit_1:
}


#line 105 "src/ast/recovery.ib"
void s941_skip_until_object_field_end(s702_Ast * v1_ast) {
	#line 106
	while (1) {
		#line 106
		switch (s689_curr(v1_ast)) {
		case s616_TokenKind_EOF: {
		return;
		break; }
		case s616_TokenKind_Comma:
		case s616_TokenKind_BraceR: {
			#line 110
			s688_step(v1_ast);
			#line 111
			return;
		break; }
		default:
 {
		s688_step(v1_ast);
		break; }
}
}
	loop_exit_1:
}


#line 122 "src/ast/recovery.ib"
s950_RecoveryResult s942_semicolon_recovery(s616_TokenKind v1_token) {
	#line 123
	switch (v1_token) {
	case s616_TokenKind_SemiColon:
	case s616_TokenKind_BraceR: {
	return s950_RecoveryResult_Recovered;
	break; }
	default:
 {
	return s949_shared_recovery(v1_token);
	break; }
}
}


#line 131 "src/ast/recovery.ib"
s950_RecoveryResult s943_statement_recovery(s616_TokenKind v1_token) {
	#line 132
	switch (v1_token) {
	case s616_TokenKind_Let:
	case s616_TokenKind_Const:
	case s616_TokenKind_If:
	case s616_TokenKind_While:
	case s616_TokenKind_Loop:
	case s616_TokenKind_For:
	case s616_TokenKind_Break:
	case s616_TokenKind_Continue:
	case s616_TokenKind_Match:
	case s616_TokenKind_Return: {
	return s950_RecoveryResult_Recovered;
	break; }
	case s616_TokenKind_SemiColon: {
	return s950_RecoveryResult_RecoveredOnNext;
	break; }
	case s616_TokenKind_BraceL: {
	return s950_RecoveryResult_Recovered;
	break; }
	default:
 {
	return s949_shared_recovery(v1_token);
	break; }
}
}


#line 154 "src/ast/recovery.ib"
s950_RecoveryResult s944_next_block_recovery(s616_TokenKind v1_token) {
	#line 155
	switch (v1_token) {
	case s616_TokenKind_BraceL: {
	return s950_RecoveryResult_Recovered;
	break; }
	default:
 {
	return s949_shared_recovery(v1_token);
	break; }
}
}


#line 161 "src/ast/recovery.ib"
s950_RecoveryResult s945_object_recovery(s616_TokenKind v1_token) {
	#line 162
	switch (v1_token) {
	case s616_TokenKind_BraceR:
	case s616_TokenKind_Comma: {
	return s950_RecoveryResult_RecoveredOnNext;
	break; }
	default:
 {
	return s949_shared_recovery(v1_token);
	break; }
}
}


#line 169 "src/ast/recovery.ib"
s950_RecoveryResult s946_var_decl_recovery(s616_TokenKind v1_token) {
	#line 170
	switch (v1_token) {
	case s616_TokenKind_Equal: {
	return s950_RecoveryResult_Recovered;
	break; }
	default:
 {
	return s942_semicolon_recovery(v1_token);
	break; }
}
}


#line 176 "src/ast/recovery.ib"
s950_RecoveryResult s947_proto_arg_recovery(s616_TokenKind v1_token) {
	#line 177
	switch (v1_token) {
	case s616_TokenKind_ParenR:
	case s616_TokenKind_Comma: {
	return s950_RecoveryResult_RecoveredOnNext;
	break; }
	default:
 {
	return s949_shared_recovery(v1_token);
	break; }
}
}


#line 183 "src/ast/recovery.ib"
s950_RecoveryResult s948_proto_flow_recovery(s616_TokenKind v1_token) {
	#line 184
	switch (v1_token) {
	case s616_TokenKind_BraceL: {
	return s950_RecoveryResult_Recovered;
	break; }
	default:
 {
	return s949_shared_recovery(v1_token);
	break; }
}
}


#line 190 "src/ast/recovery.ib"
s950_RecoveryResult s949_shared_recovery(s616_TokenKind v1_token) {
	#line 191
	switch (v1_token) {
	case s616_TokenKind_EOF:
	case s616_TokenKind_Import:
	case s616_TokenKind_Fn:
	case s616_TokenKind_Extern:
	case s616_TokenKind_Struct:
	case s616_TokenKind_Union:
	case s616_TokenKind_Pub:
	case s616_TokenKind_Enum: {
	return s950_RecoveryResult_Recovered;
	break; }
	default:
 {
	return s950_RecoveryResult_Skip;
	break; }
}
}


#line 18 "src/ast/parse_typeident.ib"
s959_TypeIdentResult s951_parse(s702_Ast * v1_ast) {
	#line 19
	i64 v2_span_start = s692_curr_span(v1_ast);
	#line 20
	s959_TypeIdentResult v3_result = ((s959_TypeIdentResult){

	});
	#line 21
	(v3_result.span) = 0l;
	#line 22
	switch (s689_curr(v1_ast)) {
	case s616_TokenKind_Fn: {
	s952_parse_fn_typeident(v1_ast, (&v3_result));
	break; }
	case s616_TokenKind_Ident: {
	s955_parse_compound_typeident(v1_ast, (&v3_result));
	break; }
	case s616_TokenKind_Star: {
	s956_parse_pointer_typeident(v1_ast, (&v3_result));
	break; }
	case s616_TokenKind_String: {
	s957_parse_str_typeident(v1_ast, (&v3_result));
	break; }
	default:
 {
	s958_parse_atomic_typeident(v1_ast, (&v3_result));
	break; }
}
	#line 29
	if ((!(v3_result.success))) {
		#line 29
		return v3_result;
	}
	#line 31
	s954_parse_array_dimensions(v1_ast, (&v3_result));
	#line 32
	(v3_result.span) = s691_span_end(v1_ast, v2_span_start);
	#line 33
	return v3_result;
}


#line 37 "src/ast/parse_typeident.ib"
void s952_parse_fn_typeident(s702_Ast * v1_ast, s959_TypeIdentResult * v2_result) {
	#line 38
	s688_step(v1_ast);
	#line 39
	if ((!s694_consume(v1_ast, s616_TokenKind_ParenL))) {
		#line 40
		s687_error(v1_ast, s226_ErrorKind_TypeIdentFnParenExpected);
		#line 41
		return;
	}
	#line 43
	i64 v3_args_length = 0l;
	#line 44
	bool v4_has_varargs = false;
	#line 45
	while (1) {
		#line 45
		switch (s689_curr(v1_ast)) {
		case s616_TokenKind_ParenR: {
			#line 46
			s688_step(v1_ast);
			#line 46
						goto loop_exit_1;
/* break; */
		break; }
		case s616_TokenKind_DotDotDot: {
			#line 48
			s688_step(v1_ast);
			#line 49
			if ((!s694_consume(v1_ast, s616_TokenKind_ParenR))) {
				#line 50
				s687_error(v1_ast, s226_ErrorKind_TypeIdentFnParenExpected);
				#line 51
				return;
			}
			#line 53
			v4_has_varargs = true;
			#line 54
						goto loop_exit_1;
/* break; */
		break; }
		default:
 {
			#line 57
			s959_TypeIdentResult v5_res = s951_parse(v1_ast);
			#line 58
			if ((!(v5_res.success))) {
				#line 59
				return;
			}
			#line 61
			v3_args_length += 1l;
			#line 62
			s214_TypeIdent * * v6_typeident = ((s214_TypeIdent * *)s707_push((&((*v1_ast).workstack)), ((i64)8ul)));
			#line 63
			(*v6_typeident) = (v5_res.type);
			#line 64
			if ((s689_curr(v1_ast) == s616_TokenKind_Comma)) {
				#line 65
				s688_step(v1_ast);
			} else if (s694_consume(v1_ast, s616_TokenKind_ParenR)) {
				#line 67
								goto loop_exit_1;
/* break; */
			} else {
#line 69
				s687_error(v1_ast, s226_ErrorKind_PrototypeParenRExpected);
				#line 70
				return;
			}
		break; }
}
}
	loop_exit_1:
	#line 74
	if ((!s694_consume(v1_ast, s616_TokenKind_Colon))) {
		#line 75
		s687_error(v1_ast, s226_ErrorKind_TypeIdentFnFlowTypeRequired);
		#line 76
		return;
	}
	#line 78
	s214_TypeIdent v7_temp_ty = ((s214_TypeIdent){

	});
	#line 79
	(v7_temp_ty.kind) = s221_TypeKind_Function;
	#line 80
	s217_FunctionType * v8_temp_fn = (&((v7_temp_ty.data).function));
	#line 81
	((*v8_temp_fn).args_length) = v3_args_length;
	#line 82
	((*v8_temp_fn).has_varargs) = v4_has_varargs;
	#line 84
	i64 v9_span = 0l;
	#line 85
	if ((s953_parse_flowtype(v1_ast, (&((*v8_temp_fn).return_ty)), (&v9_span)) == s674_ERROR)) {
		#line 86
		return;
	}
	#line 91
	((*v8_temp_fn).args) = ((s214_TypeIdent * *)s709_pop_n((&((*v1_ast).workstack)), ((i64)8ul), v3_args_length));
	#line 93
	((*v2_result).type) = s205_find_or_insert((&((*((*v1_ast).module)).type_idents)), (&v7_temp_ty));
	#line 94
	((*v2_result).success) = true;
}


#line 98 "src/ast/parse_typeident.ib"
i64 s953_parse_flowtype(s702_Ast * v1_ast, s213_FlowType * v2_flow_type, i64 * v3_span) {
	#line 99
	switch (s689_curr(v1_ast)) {
	case s616_TokenKind_Void: {
		#line 101
		(*v3_span) = s692_curr_span(v1_ast);
		#line 102
		s688_step(v1_ast);
		#line 103
		((*v2_flow_type).kind) = s220_FlowTypeKind_Void;
		#line 104
		((*v2_flow_type).type) = ((s214_TypeIdent *)NULL);
	break; }
	case s616_TokenKind_Bang: {
		#line 107
		(*v3_span) = s692_curr_span(v1_ast);
		#line 108
		s688_step(v1_ast);
		#line 109
		((*v2_flow_type).kind) = s220_FlowTypeKind_Never;
		#line 110
		((*v2_flow_type).type) = ((s214_TypeIdent *)NULL);
	break; }
	default:
 {
		#line 113
		((*v2_flow_type).kind) = s220_FlowTypeKind_Some;
		#line 114
		s959_TypeIdentResult v4_res = s951_parse(v1_ast);
		#line 115
		if ((!(v4_res.success))) {
			#line 115
			return s674_ERROR;
		}
		#line 116
		((*v2_flow_type).type) = (v4_res.type);
		#line 117
		(*v3_span) = (v4_res.span);
	break; }
}
	#line 120
	return s675_SUCCESS;
}


#line 124 "src/ast/parse_typeident.ib"
void s954_parse_array_dimensions(s702_Ast * v1_ast, s959_TypeIdentResult * v2_result) {
	#line 125
	i64 v3_dimension_count = 0l;
	#line 126
	while ((s689_curr(v1_ast) == s616_TokenKind_BracketL)) {
		#line 127
		v3_dimension_count += 1l;
		#line 128
		s688_step(v1_ast);
		#line 129
		i64 v4_len = s577_NONE;
		#line 130
		if ((s689_curr(v1_ast) != s616_TokenKind_BracketR)) {
			#line 131
			v4_len = s867_parse(v1_ast);
			#line 132
			if ((v4_len == s674_ERROR)) {
				#line 133
				((*v2_result).success) = false;
				#line 134
				return;
			}
		}
		#line 137
		s700_work_push(v1_ast, v4_len);
		#line 138
		if ((!s694_consume(v1_ast, s616_TokenKind_BracketR))) {
			#line 139
			s687_error(v1_ast, s226_ErrorKind_TypeIdentArrayBracketRExpected);
			#line 140
			((*v2_result).success) = false;
			#line 141
			return;
		}
}
	loop_exit_1:
	#line 144
	if ((v3_dimension_count == 0l)) {
		#line 144
		return;
	}
	#line 146
	s214_TypeIdent v5_temp_ty = ((s214_TypeIdent){

	});
	#line 147
	(v5_temp_ty.kind) = s221_TypeKind_Array;
	#line 148
	(((v5_temp_ty.data).array).parent) = ((*v2_result).type);
	#line 149
	(((v5_temp_ty.data).array).dimension_length) = v3_dimension_count;
	#line 151
	for (i64 v6_i = 0l;(v6_i < v3_dimension_count);v6_i += 1l) {
		#line 151
		s701_work_pop(v1_ast);
	}
	loop_exit_2:
	#line 152
	void * v7_dimensions = s706_top((&((*v1_ast).workstack)));
	#line 153
	(((v5_temp_ty.data).array).dimensions) = ((i64 *)v7_dimensions);
	#line 155
	((*v2_result).type) = s205_find_or_insert((&((*((*v1_ast).module)).type_idents)), (&v5_temp_ty));
}


#line 159 "src/ast/parse_typeident.ib"
void s955_parse_compound_typeident(s702_Ast * v1_ast, s959_TypeIdentResult * v2_result) {
	#line 160
	i64 v3_span_start = s692_curr_span(v1_ast);
	#line 161
	((*v2_result).success) = false;
	#line 162
	s214_TypeIdent v4_temp_ty = ((s214_TypeIdent){

	});
	#line 163
	(v4_temp_ty.kind) = s221_TypeKind_Compound;
	#line 165
	i64 v5_length = 1l;
	#line 167
	char * * v6_idents = ((char * *)s707_push((&((*v1_ast).workstack)), ((i64)8ul)));
	#line 168
	s686_consume_ident(v1_ast, v6_idents, s226_ErrorKind_TypeIdentPathExpected);
	#line 170
	while ((s689_curr(v1_ast) == s616_TokenKind_ColonColon)) {
		#line 171
		s688_step(v1_ast);
		#line 172
		char * * v7_ident = ((char * *)s707_push((&((*v1_ast).workstack)), ((i64)8ul)));
		#line 173
		if ((s686_consume_ident(v1_ast, v7_ident, s226_ErrorKind_TypeIdentPathExpected) == s674_ERROR)) {
			#line 174
			return;
		}
		#line 176
		v5_length += 1l;
}
	loop_exit_1:
	#line 178
	(((v4_temp_ty.data).compound).path_length) = v5_length;
	#line 179
	(((v4_temp_ty.data).compound).path) = v6_idents;
	#line 181
	((*v2_result).type) = s205_find_or_insert((&((*((*v1_ast).module)).type_idents)), (&v4_temp_ty));
	#line 182
	((*v2_result).span) = s691_span_end(v1_ast, v3_span_start);
	#line 184
	for (i64 v8_i = 0l;(v8_i < v5_length);v8_i += 1l) {
		#line 185
		s708_pop((&((*v1_ast).workstack)), ((i64)8ul));
	}
	loop_exit_2:
	#line 188
	((*v2_result).success) = true;
}


#line 192 "src/ast/parse_typeident.ib"
void s956_parse_pointer_typeident(s702_Ast * v1_ast, s959_TypeIdentResult * v2_result) {
	#line 193
	i64 v3_span_start = s692_curr_span(v1_ast);
	#line 194
	s688_step(v1_ast);
	#line 196
	s214_TypeIdent v4_temp_ty = ((s214_TypeIdent){

	});
	#line 197
	(v4_temp_ty.kind) = s221_TypeKind_Pointer;
	#line 198
	((*v2_result).success) = true;
	#line 199
	if ((s689_curr(v1_ast) == s616_TokenKind_Any)) {
		#line 200
		s688_step(v1_ast);
		#line 201
		((v4_temp_ty.data).pointer) = ((s214_TypeIdent *)NULL);
		#line 202
		((*v2_result).success) = true;
	} else {
#line 204
		s959_TypeIdentResult v5_inner_result = s951_parse(v1_ast);
		#line 205
		if ((v5_inner_result.success)) {
			#line 206
			((v4_temp_ty.data).pointer) = (v5_inner_result.type);
		} else {
#line 208
			((*v2_result).success) = false;
		}
	}
	#line 212
	((*v2_result).span) = s691_span_end(v1_ast, v3_span_start);
	#line 213
	((*v2_result).type) = s205_find_or_insert((&((*((*v1_ast).module)).type_idents)), (&v4_temp_ty));
}


#line 217 "src/ast/parse_typeident.ib"
void s957_parse_str_typeident(s702_Ast * v1_ast, s959_TypeIdentResult * v2_result) {
	#line 218
	s214_TypeIdent v3_temp_ty = ((s214_TypeIdent){

	});
	#line 219
	(v3_temp_ty.kind) = s221_TypeKind_Pointer;
	#line 220
	((v3_temp_ty.data).pointer) = s204_atomic((&((*((*v1_ast).module)).type_idents)), s222_AtomicType_U8);
	#line 221
	((*v2_result).type) = s205_find_or_insert((&((*((*v1_ast).module)).type_idents)), (&v3_temp_ty));
	#line 223
	((*v2_result).span) = s692_curr_span(v1_ast);
	#line 224
	((*v2_result).success) = true;
	#line 226
	s688_step(v1_ast);
}


#line 230 "src/ast/parse_typeident.ib"
void s958_parse_atomic_typeident(s702_Ast * v1_ast, s959_TypeIdentResult * v2_result) {
	#line 231
	((*v2_result).success) = true;
	#line 232
	((*v2_result).span) = s692_curr_span(v1_ast);
	#line 233
	s218_TypeIdents * v3_types = (&((*((*v1_ast).module)).type_idents));
	#line 234
	switch (s689_curr(v1_ast)) {
	case s616_TokenKind_Bool: {
		#line 235
		((*v2_result).type) = s204_atomic(v3_types, s222_AtomicType_Bool);
	break; }
	case s616_TokenKind_Char: {
		#line 236
		((*v2_result).type) = s204_atomic(v3_types, s222_AtomicType_U8);
	break; }
	case s616_TokenKind_Int: {
		#line 237
		((*v2_result).type) = s204_atomic(v3_types, s222_AtomicType_I64);
	break; }
	case s616_TokenKind_Float: {
		#line 238
		((*v2_result).type) = s204_atomic(v3_types, s222_AtomicType_F64);
	break; }
	case s616_TokenKind_U8: {
		#line 240
		((*v2_result).type) = s204_atomic(v3_types, s222_AtomicType_U8);
	break; }
	case s616_TokenKind_U16: {
		#line 241
		((*v2_result).type) = s204_atomic(v3_types, s222_AtomicType_U16);
	break; }
	case s616_TokenKind_U32: {
		#line 242
		((*v2_result).type) = s204_atomic(v3_types, s222_AtomicType_U32);
	break; }
	case s616_TokenKind_U64: {
		#line 243
		((*v2_result).type) = s204_atomic(v3_types, s222_AtomicType_U64);
	break; }
	case s616_TokenKind_U128: {
		#line 244
		((*v2_result).type) = s204_atomic(v3_types, s222_AtomicType_U128);
	break; }
	case s616_TokenKind_I8: {
		#line 246
		((*v2_result).type) = s204_atomic(v3_types, s222_AtomicType_I8);
	break; }
	case s616_TokenKind_I16: {
		#line 247
		((*v2_result).type) = s204_atomic(v3_types, s222_AtomicType_I16);
	break; }
	case s616_TokenKind_I32: {
		#line 248
		((*v2_result).type) = s204_atomic(v3_types, s222_AtomicType_I32);
	break; }
	case s616_TokenKind_I64: {
		#line 249
		((*v2_result).type) = s204_atomic(v3_types, s222_AtomicType_I64);
	break; }
	case s616_TokenKind_I128: {
		#line 250
		((*v2_result).type) = s204_atomic(v3_types, s222_AtomicType_I128);
	break; }
	case s616_TokenKind_F32: {
		#line 252
		((*v2_result).type) = s204_atomic(v3_types, s222_AtomicType_F32);
	break; }
	case s616_TokenKind_F64: {
		#line 253
		((*v2_result).type) = s204_atomic(v3_types, s222_AtomicType_F64);
	break; }
	case s616_TokenKind_EOF: {
		#line 255
		s687_error(v1_ast, s226_ErrorKind_MissingTypeIdent);
		#line 256
		((*v2_result).success) = false;
		#line 257
		return;
	break; }
	default:
 {
		#line 260
		s687_error(v1_ast, s226_ErrorKind_InvalidTypeIdent);
		#line 261
		((*v2_result).success) = false;
		#line 262
		return;
	break; }
}
	#line 264
	s688_step(v1_ast);
}


#line 47 "src/ast/precedence.ib"
s969_PrefixPrecedence * s961_get_prefix(s971_PrefixOpMap * v1_map, s616_TokenKind v2_op) {
	#line 48
	for (i64 v3_i = 0l;(v3_i < ((*v1_map).count));v3_i += 1l) {
		#line 49
		if ((((((*v1_map).ops)[v3_i]).token) == v2_op)) {
			#line 49
			return (&(((*v1_map).ops)[v3_i]));
		}
	}
	loop_exit_1:
	#line 51
	return ((s969_PrefixPrecedence *)NULL);
}


#line 55 "src/ast/precedence.ib"
s970_InfixPrecedence * s962_get_infix(s972_InfixOpMap * v1_map, s616_TokenKind v2_op) {
	#line 56
	for (i64 v3_i = 0l;(v3_i < ((*v1_map).count));v3_i += 1l) {
		#line 57
		if (((((((*v1_map).ops)[v3_i]).token) == v2_op) && (!((((*v1_map).ops)[v3_i]).disabled)))) {
			#line 57
			return (&(((*v1_map).ops)[v3_i]));
		}
	}
	loop_exit_1:
	#line 59
	return ((s970_InfixPrecedence *)NULL);
}


#line 62 "src/ast/precedence.ib"
void s963_infix_set_disabled(s972_InfixOpMap * v1_map, s616_TokenKind v2_op, bool v3_disabled) {
	#line 63
	for (i64 v4_i = 0l;(v4_i < ((*v1_map).count));v4_i += 1l) {
		#line 64
		if ((((((*v1_map).ops)[v4_i]).token) == v2_op)) {
			#line 65
			((((*v1_map).ops)[v4_i]).disabled) = v3_disabled;
		}
	}
	loop_exit_1:
}


#line 71 "src/ast/precedence.ib"
s971_PrefixOpMap s964_default_prefix() {
	#line 72
	s971_PrefixOpMap v1_map = ((s971_PrefixOpMap){

	});
	#line 74
	s966_add_prefix((&v1_map), s616_TokenKind_Star, 90l, s898_UnaryOp_Deref);
	#line 75
	s966_add_prefix((&v1_map), s616_TokenKind_Amp, 90l, s898_UnaryOp_Ref);
	#line 76
	s966_add_prefix((&v1_map), s616_TokenKind_Minus, 80l, s898_UnaryOp_Neg);
	#line 77
	s966_add_prefix((&v1_map), s616_TokenKind_Bang, 80l, s898_UnaryOp_Not);
	#line 78
	s966_add_prefix((&v1_map), s616_TokenKind_Plus, 80l, s898_UnaryOp_Pos);
	#line 79
	s966_add_prefix((&v1_map), s616_TokenKind_Tilde, 80l, s898_UnaryOp_BitNot);
	#line 80
	s969_PrefixPrecedence * v2_group = s966_add_prefix((&v1_map), s616_TokenKind_ParenL, 0l, s898_UnaryOp_Group);
	#line 81
	((*v2_group).suffix) = s616_TokenKind_ParenR;
	#line 82
	((*v2_group).suffix_err) = s226_ErrorKind_UnterminatedParen;
	#line 84
	return v1_map;
}


#line 88 "src/ast/precedence.ib"
s972_InfixOpMap s965_default_infix() {
	#line 89
	s972_InfixOpMap v1_map = ((s972_InfixOpMap){

	});
	#line 91
	s967_add_infix((&v1_map), s616_TokenKind_Equal, 2l, 0l, s897_BinaryOp_Assign);
	#line 92
	s967_add_infix((&v1_map), s616_TokenKind_PlusEq, 2l, 0l, s897_BinaryOp_AssignAdd);
	#line 93
	s967_add_infix((&v1_map), s616_TokenKind_MinusEq, 2l, 0l, s897_BinaryOp_AssignSub);
	#line 94
	s967_add_infix((&v1_map), s616_TokenKind_SlashEq, 2l, 0l, s897_BinaryOp_AssignDiv);
	#line 95
	s967_add_infix((&v1_map), s616_TokenKind_StarEq, 2l, 0l, s897_BinaryOp_AssignMul);
	#line 96
	s967_add_infix((&v1_map), s616_TokenKind_PercentEq, 2l, 0l, s897_BinaryOp_AssignRem);
	#line 98
	s967_add_infix((&v1_map), s616_TokenKind_Or, 10l, 11l, s897_BinaryOp_Or);
	#line 99
	s967_add_infix((&v1_map), s616_TokenKind_And, 12l, 13l, s897_BinaryOp_And);
	#line 101
	s967_add_infix((&v1_map), s616_TokenKind_EqEq, 20l, 21l, s897_BinaryOp_EQ);
	#line 102
	s967_add_infix((&v1_map), s616_TokenKind_BangEqual, 20l, 21l, s897_BinaryOp_NE);
	#line 104
	s967_add_infix((&v1_map), s616_TokenKind_GT, 22l, 23l, s897_BinaryOp_GT);
	#line 105
	s967_add_infix((&v1_map), s616_TokenKind_GE, 22l, 23l, s897_BinaryOp_GE);
	#line 106
	s967_add_infix((&v1_map), s616_TokenKind_LT, 22l, 23l, s897_BinaryOp_LT);
	#line 107
	s967_add_infix((&v1_map), s616_TokenKind_LE, 22l, 23l, s897_BinaryOp_LE);
	#line 109
	s967_add_infix((&v1_map), s616_TokenKind_Pipe, 30l, 31l, s897_BinaryOp_BitOr);
	#line 110
	s967_add_infix((&v1_map), s616_TokenKind_Caret, 32l, 33l, s897_BinaryOp_BitXor);
	#line 111
	s967_add_infix((&v1_map), s616_TokenKind_Amp, 35l, 36l, s897_BinaryOp_BitAnd);
	#line 113
	s967_add_infix((&v1_map), s616_TokenKind_Plus, 40l, 41l, s897_BinaryOp_Add);
	#line 114
	s967_add_infix((&v1_map), s616_TokenKind_Minus, 40l, 41l, s897_BinaryOp_Sub);
	#line 116
	s967_add_infix((&v1_map), s616_TokenKind_GTGT, 50l, 51l, s897_BinaryOp_BitShiftRight);
	#line 117
	s967_add_infix((&v1_map), s616_TokenKind_LTLT, 50l, 51l, s897_BinaryOp_BitShiftLeft);
	#line 119
	s967_add_infix((&v1_map), s616_TokenKind_Star, 60l, 61l, s897_BinaryOp_Mul);
	#line 120
	s967_add_infix((&v1_map), s616_TokenKind_Slash, 60l, 61l, s897_BinaryOp_Div);
	#line 121
	s967_add_infix((&v1_map), s616_TokenKind_Percent, 64l, 65l, s897_BinaryOp_Rem);
	#line 123
	s968_add_infix_ex((&v1_map), s616_TokenKind_As, 70l, 71l, s973_RHSKind_Cast);
	#line 124
	s968_add_infix_ex((&v1_map), s616_TokenKind_ParenL, 100l, 101l, s973_RHSKind_Call);
	#line 126
	s967_add_infix((&v1_map), s616_TokenKind_Dot, 120l, 121l, s897_BinaryOp_FieldLookup);
	#line 128
	s967_add_infix((&v1_map), s616_TokenKind_ColonColon, 130l, 131l, s897_BinaryOp_Path);
	#line 130
	s970_InfixPrecedence * v2_index = s967_add_infix((&v1_map), s616_TokenKind_BracketL, 100l, 0l, s897_BinaryOp_Index);
	#line 131
	((*v2_index).suffix) = s616_TokenKind_BracketR;
	#line 131
	((*v2_index).suffix_err) = s226_ErrorKind_UnterminatedBracket;
	#line 133
	return v1_map;
}


#line 137 "src/ast/precedence.ib"
s969_PrefixPrecedence * s966_add_prefix(s971_PrefixOpMap * v1_map, s616_TokenKind v2_token, i64 v3_prec, s898_UnaryOp v4_op) {
	#line 138
	s40_assert((((*v1_map).count) < s960_MAX_CAPACITY), "Prefix Capacity exceeded max!");
	#line 139
	((((*v1_map).ops)[((*v1_map).count)]).token) = v2_token;
	#line 140
	((((*v1_map).ops)[((*v1_map).count)]).new_prec) = v3_prec;
	#line 141
	((((*v1_map).ops)[((*v1_map).count)]).op) = v4_op;
	#line 142
	((((*v1_map).ops)[((*v1_map).count)]).suffix) = s616_TokenKind_None;
	#line 143
	((*v1_map).count) += 1l;
	#line 144
	return (&(((*v1_map).ops)[(((*v1_map).count) - 1l)]));
}


#line 148 "src/ast/precedence.ib"
s970_InfixPrecedence * s967_add_infix(s972_InfixOpMap * v1_map, s616_TokenKind v2_token, i64 v3_prec, i64 v4_new_prec, s897_BinaryOp v5_op) {
	#line 149
	s40_assert((((*v1_map).count) < s960_MAX_CAPACITY), "Infix Capacity exceeded max!");
	#line 150
	((((*v1_map).ops)[((*v1_map).count)]).token) = v2_token;
	#line 151
	((((*v1_map).ops)[((*v1_map).count)]).prec) = v3_prec;
	#line 152
	((((*v1_map).ops)[((*v1_map).count)]).new_prec) = v4_new_prec;
	#line 153
	((((*v1_map).ops)[((*v1_map).count)]).op) = v5_op;
	#line 154
	((((*v1_map).ops)[((*v1_map).count)]).suffix) = s616_TokenKind_None;
	#line 155
	((((*v1_map).ops)[((*v1_map).count)]).rhs_kind) = s973_RHSKind_Expr;
	#line 156
	((((*v1_map).ops)[((*v1_map).count)]).disabled) = false;
	#line 157
	((*v1_map).count) += 1l;
	#line 158
	return (&(((*v1_map).ops)[(((*v1_map).count) - 1l)]));
}


#line 161 "src/ast/precedence.ib"
s970_InfixPrecedence * s968_add_infix_ex(s972_InfixOpMap * v1_map, s616_TokenKind v2_token, i64 v3_prec, i64 v4_new_prec, s973_RHSKind v5_rhs) {
	#line 162
	s40_assert((((*v1_map).count) < s960_MAX_CAPACITY), "Infix Capacity exceeded max!");
	#line 163
	((((*v1_map).ops)[((*v1_map).count)]).token) = v2_token;
	#line 164
	((((*v1_map).ops)[((*v1_map).count)]).prec) = v3_prec;
	#line 165
	((((*v1_map).ops)[((*v1_map).count)]).new_prec) = v4_new_prec;
	#line 166
	((((*v1_map).ops)[((*v1_map).count)]).op) = s897_BinaryOp_None;
	#line 167
	((((*v1_map).ops)[((*v1_map).count)]).suffix) = s616_TokenKind_None;
	#line 168
	((((*v1_map).ops)[((*v1_map).count)]).rhs_kind) = v5_rhs;
	#line 169
	((*v1_map).count) += 1l;
	#line 170
	return (&(((*v1_map).ops)[(((*v1_map).count) - 1l)]));
}


#line 24 "src/typecheck/var_bindings.ib"
s984_VarBindings s974_new() {
	#line 25
	return ((s984_VarBindings){
		.variables = s243_new(((i64)56ul), 64l),
		.blocks = s243_new(((i64)8ul), 64l),
		.last_id = 0l
	});
}


#line 32 "src/typecheck/var_bindings.ib"
void s975_free(s984_VarBindings * v1_binds) {
	#line 33
	s246_free((&((*v1_binds).variables)));
	#line 34
	s246_free((&((*v1_binds).blocks)));
}


#line 38 "src/typecheck/var_bindings.ib"
void s976_start(s984_VarBindings * v1_binds) {
	#line 39
	i64 * v2_value = ((i64 *)s249_push((&((*v1_binds).blocks))));
	#line 40
	(*v2_value) = (((*v1_binds).variables).count);
}


#line 44 "src/typecheck/var_bindings.ib"
void s977_end(s984_VarBindings * v1_binds, s351_TypecheckContext * v2_context) {
	#line 45
	s40_assert(((((*v1_binds).blocks).count) > 0l), "var_bindings::end without blocks!");
	#line 46
	i64 v3_block_start = (*((i64 *)s250_pop((&((*v1_binds).blocks)))));
	#line 48
	for (i64 v4_i = v3_block_start;(v4_i < (((*v1_binds).variables).count));v4_i += 1l) {
		#line 49
		s983_Variable * v5_var = ((s983_Variable *)s251_get((&((*v1_binds).variables)), v4_i));
		#line 50
		if (((*v5_var).used)) {
			#line 50
			continue;
		}
		#line 51
		if (((((*v5_var).key)[0l]) == 95u)) {
			#line 51
			continue;
		}
		#line 52
		s777_warn_unused_variable(v2_context, ((*v5_var).span));
	}
	loop_exit_1:
	#line 54
	(((*v1_binds).variables).count) = v3_block_start;
}


#line 57 "src/typecheck/var_bindings.ib"
void s978_assert_no_blocks(s984_VarBindings * v1_binds) {
	#line 58
	s40_assert(((((*v1_binds).variables).count) == 0l), "No variables are expected");
	#line 59
	s40_assert(((((*v1_binds).blocks).count) == 0l), "No blocks are expected");
}


#line 63 "src/typecheck/var_bindings.ib"
i64 s979_insert(s984_VarBindings * v1_binds, char * v2_key, s528_TypeIdent * v3_ty, bool v4_mutable, i64 v5_span) {
	#line 64
	s983_Variable * v6_var = ((s983_Variable *)s249_push((&((*v1_binds).variables))));
	#line 65
	((*v1_binds).last_id) += 1l;
	#line 66
	(*v6_var) = ((s983_Variable){
		.key = v2_key,
		.ty = v3_ty,
		.mutable = v4_mutable,
		.id = ((*v1_binds).last_id),
		.is_error = false,
		.used = false,
		.span = v5_span
	});
	#line 73
	return ((*v6_var).id);
}


#line 77 "src/typecheck/var_bindings.ib"
i64 s980_insert_error(s984_VarBindings * v1_binds, char * v2_key, s528_TypeIdent * v3_ty, bool v4_mutable, i64 v5_span) {
	#line 78
	s983_Variable * v6_var = ((s983_Variable *)s249_push((&((*v1_binds).variables))));
	#line 79
	((*v1_binds).last_id) += 1l;
	#line 80
	(*v6_var) = ((s983_Variable){
		.key = v2_key,
		.ty = v3_ty,
		.mutable = v4_mutable,
		.id = ((*v1_binds).last_id),
		.is_error = true,
		.used = true,
		.span = v5_span
	});
	#line 88
	return ((*v6_var).id);
}


#line 98 "src/typecheck/var_bindings.ib"
s985_VarResult s981_get(s984_VarBindings * v1_binds, char * v2_key) {
	#line 99
	s985_VarResult v3_res = ((s985_VarResult){

	});
	#line 100
	for (i64 v4_i = ((((*v1_binds).variables).count) - 1l);(v4_i >= 0l);v4_i -= 1l) {
		#line 101
		s983_Variable * v5_var = ((s983_Variable *)s251_get((&((*v1_binds).variables)), v4_i));
		#line 102
		if ((((*v5_var).key) == v2_key)) {
			#line 103
			(v3_res.found) = true;
			#line 104
			(v3_res.ty) = ((*v5_var).ty);
			#line 105
			(v3_res.mutable) = ((*v5_var).mutable);
			#line 106
			(v3_res.id) = ((*v5_var).id);
			#line 107
			(v3_res.key) = ((*v5_var).key);
			#line 108
			(v3_res.is_error) = ((*v5_var).is_error);
			#line 109
			((*v5_var).used) = true;
			#line 110
			return v3_res;
		}
	}
	loop_exit_1:
	#line 113
	return v3_res;
}


#line 117 "src/typecheck/var_bindings.ib"
void s982_print(s984_VarBindings * v1_binds) {
	#line 118
	printf("VarBindings: ");
	#line 119
	i64 v2_next_block = 0l;
	#line 120
	i64 v3_block_idx = 0l;
	#line 121
	for (i64 v4_i = 0l;(v4_i < (((*v1_binds).variables).count));v4_i += 1l) {
		#line 122
		if ((v2_next_block == v4_i)) {
			#line 123
			printf("[BLOCK] ");
		}
		#line 125
		s983_Variable * v5_var = ((s983_Variable *)s251_get((&((*v1_binds).variables)), v4_i));
		#line 126
		printf("[%s@%d] ", ((*v5_var).key), ((*v5_var).id));
		#line 128
		if ((v3_block_idx < (((*v1_binds).blocks).count))) {
			#line 129
			v2_next_block = (*((i64 *)s251_get((&((*v1_binds).blocks)), v3_block_idx)));
			#line 130
			v3_block_idx += 1l;
		}
	}
	loop_exit_1:
	#line 133
	printf("\n");
}


#line 16 "src/typecheck/type_size_align.ib"
s995_SizeAndAlign s987_typeident(s351_TypecheckContext * v1_context, s528_TypeIdent * v2_ty) {
	#line 17
	if ((v2_ty == ((s528_TypeIdent *)NULL))) {
		#line 17
		return s993_new(1l, 1l);
	}
	#line 18
	switch (((*v2_ty).kind)) {
	case s534_TypeKind_Atomic: {
	return s989_atomic((((*v2_ty).data).atomic));
	break; }
	case s534_TypeKind_Pointer: {
	return s986_POINTER_SIZE;
	break; }
	case s534_TypeKind_Function: {
	return s986_POINTER_SIZE;
	break; }
	case s534_TypeKind_Compound: {
	return s988_symbol(v1_context, (((*v2_ty).data).compound));
	break; }
	case s534_TypeKind_Array: {
		#line 25
		s529_ArrayType * v3_array = (&(((*v2_ty).data).array));
		#line 26
		s995_SizeAndAlign v4_align = s987_typeident(v1_context, ((*v3_array).parent));
		#line 27
		for (i64 v5_i = 0l;(v5_i < ((*v3_array).dimension_length));v5_i += 1l) {
			#line 28
			(v4_align.size) *= (((*v3_array).dimensions)[v5_i]);
		}
		loop_exit_1:
		#line 30
		return v4_align;
	break; }
	default:
		abort();
}
}


#line 37 "src/typecheck/type_size_align.ib"
s995_SizeAndAlign s988_symbol(s351_TypecheckContext * v1_context, s201_UID v2_symbol) {
	#line 38
	s40_assert((!s170_is_none(v2_symbol)), "type_size_align::symbol symbol was null");
	#line 39
	s342_typecheck_symbol(v1_context, v2_symbol);
	#line 41
	switch (s190_kind(v2_symbol)) {
	case s544_SymbolKind_Struct: {
	return s992_object((s183_get_deep(v2_symbol).object_def));
	break; }
	case s544_SymbolKind_Union: {
	return s992_object((s183_get_deep(v2_symbol).object_def));
	break; }
	case s544_SymbolKind_Enum: {
	return s991__enum((s183_get_deep(v2_symbol).enum_def));
	break; }
	case s544_SymbolKind_Global: {
	return s990_global(v1_context, v2_symbol);
	break; }
	case s544_SymbolKind_Function: {
	return s986_POINTER_SIZE;
	break; }
	default:
		abort();
}
	#line 49
	return s993_new(0l, 0l);
}


#line 53 "src/typecheck/type_size_align.ib"
s995_SizeAndAlign s989_atomic(s535_AtomicType v1_atomic) {
	#line 54
	switch (v1_atomic) {
	case s535_AtomicType_Bool: {
	return s993_new(1l, 1l);
	break; }
	case s535_AtomicType_U8: {
	return s993_new(1l, 1l);
	break; }
	case s535_AtomicType_U16: {
	return s993_new(2l, 2l);
	break; }
	case s535_AtomicType_U32: {
	return s993_new(4l, 4l);
	break; }
	case s535_AtomicType_U64: {
	return s993_new(8l, 8l);
	break; }
	case s535_AtomicType_U128: {
	return s993_new(16l, 16l);
	break; }
	case s535_AtomicType_I8: {
	return s993_new(1l, 1l);
	break; }
	case s535_AtomicType_I16: {
	return s993_new(2l, 2l);
	break; }
	case s535_AtomicType_I32: {
	return s993_new(4l, 4l);
	break; }
	case s535_AtomicType_I64: {
	return s993_new(8l, 8l);
	break; }
	case s535_AtomicType_I128: {
	return s993_new(16l, 16l);
	break; }
	case s535_AtomicType_F32: {
	return s993_new(4l, 4l);
	break; }
	case s535_AtomicType_F64: {
	return s993_new(8l, 8l);
	break; }
	default:
		abort();
}
}


#line 74 "src/typecheck/type_size_align.ib"
s995_SizeAndAlign s990_global(s351_TypecheckContext * v1_context, s201_UID v2_symbol) {
	#line 75
	if (s191_is_extern(v2_symbol)) {
		#line 76
		s772_ExternGlobal * v3_ext_global = (s183_get_deep(v2_symbol).extern_global);
		#line 77
		return s987_typeident(v1_context, ((*v3_ext_global).type));
	}
	#line 79
	s771_Global * v4_global = (s183_get_deep(v2_symbol).global);
	#line 80
	return s987_typeident(v1_context, ((*v4_global).type));
}


#line 84 "src/typecheck/type_size_align.ib"
s995_SizeAndAlign s991__enum(s766_EnumDef * v1_def) {
	#line 85
	return s993_new(((*v1_def).size), ((*v1_def).align));
}


#line 88 "src/typecheck/type_size_align.ib"
s995_SizeAndAlign s992_object(s758_ObjectDef * v1_def) {
	#line 89
	return s993_new(((*v1_def).size), ((*v1_def).align));
}


#line 92 "src/typecheck/type_size_align.ib"
s995_SizeAndAlign s993_new(i64 v1_size, i64 v2_align) {
	#line 93
	return ((s995_SizeAndAlign){
		.size = v1_size,
		.align = v2_align
	});
}


#line 97 "src/typecheck/type_size_align.ib"
void s994_debug(s299_StringBuilder * v1_sb, i64 v2_size, i64 v3_align) {
	#line 98
	s283_append(v1_sb, "[SIZE=");
	#line 99
	s289_append_number(v1_sb, v2_size);
	#line 100
	s283_append(v1_sb, ",ALIGN=");
	#line 101
	s289_append_number(v1_sb, v3_align);
	#line 102
	s283_append(v1_sb, "]");
}


#line 62 "src/typecheck/statement.ib"
s845_NodeResult s996_typecheck_block(s743_FunctionContext * v1_context, s923_BlockData v2_data, i64 v3_span) {
	#line 67
	s1017_BlockData v4_block = ((s1017_BlockData){
		.count = (v2_data.count),
		.nodes = ((i64 *)s840_allocate_extra(((*v1_context).nodes), ((i64)(8ul * ((u64)(v2_data.count))))))
	});
	#line 71
	s850_NodeFlow v5_flow = s850_NodeFlow_Some;
	#line 73
	s976_start((&((*v1_context).bindings)));
	#line 75
	for (i64 v6_i = 0l;(v6_i < (v2_data.count));v6_i += 1l) {
		#line 76
		s845_NodeResult v7_res = s827_typecheck(v1_context, ((v2_data.nodes)[v6_i]));
		#line 77
		((v4_block.nodes)[v6_i]) = (v7_res.node);
		#line 79
		v5_flow = s833_flow_all(v5_flow, (v7_res.flow));
	}
	loop_exit_1:
	#line 82
	s977_end((&((*v1_context).bindings)), ((*v1_context).parent));
	#line 85
	return s829_result(s839_push(((*v1_context).nodes), s848_NodeKind_Block, ((s528_TypeIdent *)NULL), ((s847_NodeData){
		.block = v4_block
	}), v3_span), v5_flow);
}


#line 96 "src/typecheck/statement.ib"
s845_NodeResult s997_typecheck_vardecl_statement(s743_FunctionContext * v1_context, s924_VarDeclaration v2_data, bool v3_mutable, i64 v4_span) {
	#line 102
	s848_NodeKind v5_kind = s848_NodeKind_VarDecl;
	#line 103
	if ((!v3_mutable)) {
		#line 103
		v5_kind = s848_NodeKind_ConstDecl;
	}
	#line 105
	s587_Node * v6_ident = s578_get((&((*((*v1_context).module)).nodes)), (v2_data.ident));
	#line 106
	s40_assert((((*v6_ident).kind) == s589_NodeKind_Ident), "VarDecl expected identifier.");
	#line 107
	i64 v7_ident_span = ((*v6_ident).span);
	#line 108
	char * v8_ident = (((*v6_ident).data).ident);
	#line 110
	void * v9_ast_ty = NULL;
	#line 111
	i64 v10_ast_ty_span = 0l;
	#line 112
	if (((v2_data.type) != ((s586_TypeData *)NULL))) {
		#line 113
		v9_ast_ty = ((void *)((*(v2_data.type)).type));
		#line 114
		v10_ast_ty_span = ((*(v2_data.type)).span);
	}
	#line 117
	s1020_VarDeclResult v11_res = s998_typecheck_vardecl(v1_context, v8_ident, v7_ident_span, ((s214_TypeIdent *)v9_ast_ty), v10_ast_ty_span, (v2_data.value), v3_mutable, v4_span);
	#line 128
	i64 v12_var_id = s999_insert_binding(v1_context, v8_ident, (v11_res.type), v3_mutable, (v11_res.had_error), v7_ident_span);
	#line 134
	s1018_VarDeclaration v13_var_declaration = ((s1018_VarDeclaration){
		.ident = v8_ident,
		.var_id = v12_var_id,
		.value = (v11_res.value),
		.type = (v11_res.type)
	});
	#line 141
	return s828_some(s839_push(((*v1_context).nodes), v5_kind, (v11_res.type), ((s847_NodeData){
		.var_declaration = v13_var_declaration
	}), v4_span));
}


#line 153 "src/typecheck/statement.ib"
s1020_VarDeclResult s998_typecheck_vardecl(s743_FunctionContext * v1_context, char * v2__ident, i64 v3_ident_span, s214_TypeIdent * v4_ast_type, i64 v5_type_span, i64 v6_ast_value, bool v7__mutable, i64 v8__span) {
	#line 163
	bool v9_had_error = false;
	#line 165
	s528_TypeIdent * v10_type = ((s528_TypeIdent *)NULL);
	#line 166
	bool v11_had_typehint = (v4_ast_type != ((s214_TypeIdent *)NULL));
	#line 167
	if (v11_had_typehint) {
		#line 168
		v10_type = s509_typecheck(((*v1_context).parent), ((*((*v1_context).module)).uid), v4_ast_type, v5_type_span);
		#line 174
		((*v1_context).target_ty) = v10_type;
		#line 175
		((*v1_context).target_ty_span) = v5_type_span;
	}
	#line 177
	s845_NodeResult v12_value_res = s827_typecheck(v1_context, v6_ast_value);
	#line 179
	i64 v13_value = (v12_value_res.node);
	#line 182
	s528_TypeIdent * v14_value_ty = ((s528_TypeIdent *)NULL);
	#line 183
	if ((v13_value != s826_ERROR)) {
		#line 184
		s844_Node * v15_value_data = s836_get(((*v1_context).nodes), v13_value);
		#line 185
		v14_value_ty = ((*v15_value_data).ty);
	}
	#line 187
	if ((v10_type == ((s528_TypeIdent *)NULL))) {
		#line 188
		v10_type = v14_value_ty;
	}
	#line 190
	((*v1_context).target_ty) = ((s528_TypeIdent *)NULL);
	#line 191
	((*v1_context).target_ty_span) = 0l;
	#line 193
	bool v16_typehint_errored = (v11_had_typehint && (v10_type == ((s528_TypeIdent *)NULL)));
	#line 194
	v9_had_error = (v9_had_error || v16_typehint_errored);
	#line 196
	bool v17_value_not_some = (((v12_value_res.flow) != s850_NodeFlow_Some) || ((v13_value != s826_ERROR) && (v14_value_ty == ((s528_TypeIdent *)NULL))));
	#line 199
	if ((v17_value_not_some && (!v9_had_error))) {
		#line 200
		v9_had_error = true;
		#line 201
		s774_error(((*v1_context).parent), s781_ErrorKind_VarDeclValueFlowWasNotSome, v3_ident_span);
	}
	#line 208
	if ((v11_had_typehint && (!v9_had_error))) {
		#line 209
		bool v18_cast_res = true;
		#line 210
		v13_value = s1101_implicit(v1_context, v13_value, v10_type, (&v18_cast_res));
		#line 211
		if ((!v18_cast_res)) {
			#line 212
			v9_had_error = true;
			#line 213
			s774_error(((*v1_context).parent), s781_ErrorKind_VarDeclTypeMismatch, v5_type_span);
		}
	}
	#line 220
	return ((s1020_VarDeclResult){
		.had_error = v9_had_error,
		.type = v10_type,
		.value = v13_value
	});
}


#line 228 "src/typecheck/statement.ib"
i64 s999_insert_binding(s743_FunctionContext * v1_context, char * v2_ident, s528_TypeIdent * v3_type, bool v4_mutable, bool v5_had_error, i64 v6_ident_span) {
	#line 233
	if (v5_had_error) {
		#line 234
		return s980_insert_error((&((*v1_context).bindings)), v2_ident, v3_type, v4_mutable, v6_ident_span);
	}
	#line 240
	return s979_insert((&((*v1_context).bindings)), v2_ident, v3_type, v4_mutable, v6_ident_span);
}


#line 247 "src/typecheck/statement.ib"
s845_NodeResult s1000_typecheck_return(s743_FunctionContext * v1_context, s925_ReturnData v2_data, i64 v3_span) {
	#line 252
	bool v4_has_value = (v2_data.has_value);
	#line 253
	i64 v5_value = s825_NONE;
	#line 254
	if (v4_has_value) {
		#line 255
		s845_NodeResult v6_value_res = s827_typecheck(v1_context, (v2_data.value));
		#line 256
		v5_value = (v6_value_res.node);
	}
	#line 258
	((*v1_context).has_return) = true;
	#line 259
	switch ((((*v1_context).return_ty).kind)) {
	case s533_FlowTypeKind_Some: {
		#line 261
		if ((!v4_has_value)) {
			#line 262
			s774_error(((*v1_context).parent), s781_ErrorKind_ReturnSomeExpected, v3_span);
		} else if ((v5_value != s826_ERROR)) {
			#line 268
			s844_Node * v7_value_data = s836_get(((*v1_context).nodes), v5_value);
			#line 269
			bool v8_cast_res = true;
			#line 270
			v5_value = s1101_implicit(v1_context, v5_value, (((*v1_context).return_ty).type), (&v8_cast_res));
			#line 271
			if ((!v8_cast_res)) {
				#line 272
				s774_error(((*v1_context).parent), s781_ErrorKind_ReturnTypeMismatch, ((*v7_value_data).span));
			}
		}
	break; }
	case s533_FlowTypeKind_Void: {
		#line 281
		if (v4_has_value) {
			#line 282
			s774_error(((*v1_context).parent), s781_ErrorKind_ReturnVoidExpected, v3_span);
		}
	break; }
	case s533_FlowTypeKind_Never: {
		#line 290
		s774_error(((*v1_context).parent), s781_ErrorKind_ReturnNeverExpected, v3_span);
	break; }
	default:
		abort();
}
	#line 297
	s1019_ReturnData v9_retrn = ((s1019_ReturnData){
		.has_value = v4_has_value,
		.value = v5_value
	});
	#line 300
	return s829_result(s839_push(((*v1_context).nodes), s848_NodeKind_Return, ((s528_TypeIdent *)NULL), ((s847_NodeData){
		.retrn = v9_retrn
	}), v3_span), s850_NodeFlow_Return);
}


#line 311 "src/typecheck/statement.ib"
i64 s1001_typecheck_condition(s743_FunctionContext * v1_context, i64 v2_ast_cond, s781_ErrorKind v3_err_kind) {
	#line 316
	s845_NodeResult v4_cond_res = s827_typecheck(v1_context, v2_ast_cond);
	#line 317
	i64 v5_cond = (v4_cond_res.node);
	#line 319
	if ((v5_cond == s826_ERROR)) {
		#line 320
		return s826_ERROR;
	}
	#line 323
	s844_Node * v6_cond_data = s836_get(((*v1_context).nodes), v5_cond);
	#line 324
	if ((((*v6_cond_data).ty) != (((*((*v1_context).parent)).typeidents).boolean))) {
		#line 325
		s523_print(((*v1_context).nodes), ((*v6_cond_data).ty));
		#line 326
		s774_error(((*v1_context).parent), v3_err_kind, ((*v6_cond_data).span));
	}
	#line 328
	return v5_cond;
}


#line 331 "src/typecheck/statement.ib"
s845_NodeResult s1002_typecheck_if(s743_FunctionContext * v1_context, s922_IfData v2_data, i64 v3_span) {
	#line 336
	s850_NodeFlow v4_flow = s850_NodeFlow_Some;
	#line 338
	i64 v5_cond = s1001_typecheck_condition(v1_context, (v2_data.cond), s781_ErrorKind_IfCondNotBool);
	#line 340
	s845_NodeResult v6_then_res = s827_typecheck(v1_context, (v2_data.then));
	#line 341
	i64 v7_then = (v6_then_res.node);
	#line 343
	i64 v8_otherwise = s825_NONE;
	#line 344
	if (((v2_data.otherwise) != s577_NONE)) {
		#line 345
		s845_NodeResult v9_otherwise_res = s827_typecheck(v1_context, (v2_data.otherwise));
		#line 346
		v8_otherwise = (v9_otherwise_res.node);
		#line 347
		v4_flow = s832_flow_any((v6_then_res.flow), (v9_otherwise_res.flow));
	}
	#line 350
	s1016_IfData v10_if_data = ((s1016_IfData){
		.cond = v5_cond,
		.then = v7_then,
		.otherwise = v8_otherwise
	});
	#line 352
	return s829_result(s839_push(((*v1_context).nodes), s848_NodeKind_If, ((s528_TypeIdent *)NULL), ((s847_NodeData){
		.if_data = v10_if_data
	}), v3_span), v4_flow);
}


#line 363 "src/typecheck/statement.ib"
s845_NodeResult s1003_typecheck_loop(s743_FunctionContext * v1_context, s921_LoopData v2_data, i64 v3_span) {
	#line 368
	bool v4_has_cond = (v2_data.has_cond);
	#line 369
	i64 v5_cond = s825_NONE;
	#line 370
	s850_NodeFlow v6_base_flow = s850_NodeFlow_Never;
	#line 371
	if (v4_has_cond) {
		#line 372
		v6_base_flow = s850_NodeFlow_Some;
		#line 373
		v5_cond = s1001_typecheck_condition(v1_context, (v2_data.cond), s781_ErrorKind_LoopCondNotBool);
	}
	#line 378
	s850_NodeFlow v7_flow = v6_base_flow;
	#line 380
	((*v1_context).loop_depth) += 1l;
	#line 381
	s845_NodeResult v8_body_res = s827_typecheck(v1_context, (v2_data.body));
	#line 382
	i64 v9_body = (v8_body_res.node);
	#line 383
	((*v1_context).loop_depth) -= 1l;
	#line 385
	switch ((v8_body_res.flow)) {
	case s850_NodeFlow_Some:
	case s850_NodeFlow_Continue:
	case s850_NodeFlow_Return:
	case s850_NodeFlow_Never: {
	break; }
	case s850_NodeFlow_Break: {
		#line 392
		v7_flow = s850_NodeFlow_Some;
	break; }
	default:
		abort();
}
	#line 396
	s1015_LoopData v10_loop_data = ((s1015_LoopData){
		.has_cond = v4_has_cond,
		.cond = v5_cond,
		.body = v9_body
	});
	#line 399
	return s829_result(s839_push(((*v1_context).nodes), s848_NodeKind_Loop, ((s528_TypeIdent *)NULL), ((s847_NodeData){
		.loop_data = v10_loop_data
	}), v3_span), v7_flow);
}


#line 407 "src/typecheck/statement.ib"
s845_NodeResult s1004_typecheck_for(s743_FunctionContext * v1_context, s920_ForData * v2_data, i64 v3_span) {
	#line 412
	s976_start((&((*v1_context).bindings)));
	#line 413
	s845_NodeResult v4_init_res = s827_typecheck(v1_context, ((*v2_data).init));
	#line 414
	i64 v5_init = (v4_init_res.node);
	#line 416
	i64 v6_cond = s1001_typecheck_condition(v1_context, ((*v2_data).cond), s781_ErrorKind_LoopCondNotBool);
	#line 421
	s845_NodeResult v7_acc_res = s827_typecheck(v1_context, ((*v2_data).acc));
	#line 422
	i64 v8_acc = (v7_acc_res.node);
	#line 424
	((*v1_context).loop_depth) += 1l;
	#line 425
	s845_NodeResult v9_body_res = s827_typecheck(v1_context, ((*v2_data).body));
	#line 426
	i64 v10_body = (v9_body_res.node);
	#line 427
	((*v1_context).loop_depth) -= 1l;
	#line 428
	s977_end((&((*v1_context).bindings)), ((*v1_context).parent));
	#line 430
	s1014_ForData * v11_for_data = ((s1014_ForData *)s840_allocate_extra(((*v1_context).nodes), ((i64)32ul)));
	#line 431
	(*v11_for_data) = ((s1014_ForData){
		.init = v5_init,
		.cond = v6_cond,
		.acc = v8_acc,
		.body = v10_body
	});
	#line 432
	return s828_some(s839_push(((*v1_context).nodes), s848_NodeKind_For, ((s528_TypeIdent *)NULL), ((s847_NodeData){
		.for_data = v11_for_data
	}), v3_span));
}


#line 439 "src/typecheck/statement.ib"
s845_NodeResult s1005_typecheck_break(s743_FunctionContext * v1_context, i64 v2_span) {
	#line 440
	if ((((*v1_context).loop_depth) == 0l)) {
		#line 441
		s774_error(((*v1_context).parent), s781_ErrorKind_BreakOutsideLoop, v2_span);
	}
	#line 443
	return s829_result(s838_push_simple(((*v1_context).nodes), s848_NodeKind_Break, v2_span), s850_NodeFlow_Break);
}


#line 450 "src/typecheck/statement.ib"
s845_NodeResult s1006_typecheck_continue(s743_FunctionContext * v1_context, i64 v2_span) {
	#line 451
	if ((((*v1_context).loop_depth) == 0l)) {
		#line 452
		s774_error(((*v1_context).parent), s781_ErrorKind_ContinueOutsideLoop, v2_span);
	}
	#line 454
	return s829_result(s838_push_simple(((*v1_context).nodes), s848_NodeKind_Continue, v2_span), s850_NodeFlow_Continue);
}


#line 465 "src/typecheck/statement.ib"
i64 s1007_block_get(s1017_BlockData * v1_block, i64 v2_index) {
	#line 466
	if ((v2_index >= ((*v1_block).count))) {
		#line 466
		return s825_NONE;
	}
	#line 467
	return (((*v1_block).nodes)[v2_index]);
}


#line 471 "src/typecheck/statement.ib"
void s1008_debug_block(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, s1017_BlockData * v3_block, i64 v4_depth) {
	#line 472
	s288_repeat(v1_sb, "  ", v4_depth);
	#line 473
	s283_append(v1_sb, "BLOCK\n");
	#line 474
	for (i64 v5_i = 0l;(v5_i < ((*v3_block).count));v5_i += 1l) {
		#line 475
		i64 v6_n = s1007_block_get(v3_block, v5_i);
		#line 476
		s40_assert((v6_n != s825_NONE), "statement::debug_block");
		#line 477
		s842_debug(v1_sb, v2_nodes, v6_n, (v4_depth + 1l));
	}
	loop_exit_1:
}


#line 483 "src/typecheck/statement.ib"
void s1009_debug_var_decl(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, bool v3_mutable, s1018_VarDeclaration * v4_data, i64 v5_depth) {
	#line 484
	s288_repeat(v1_sb, "  ", v5_depth);
	#line 485
	s283_append(v1_sb, "VAR_DECL ");
	#line 486
	if (v3_mutable) {
		#line 486
		s283_append(v1_sb, "LET ");
	} else {
#line 487
		s283_append(v1_sb, "CONST ");
	}
	#line 488
	s283_append(v1_sb, ((*v4_data).ident));
	#line 489
	s283_append(v1_sb, "@");
	#line 490
	s289_append_number(v1_sb, ((*v4_data).var_id));
	#line 491
	s283_append(v1_sb, "\n");
	#line 493
	s288_repeat(v1_sb, "  ", (v5_depth + 1l));
	#line 494
	s283_append(v1_sb, "TYPE: ");
	#line 495
	s524_debug(v1_sb, v2_nodes, ((*v4_data).type), v5_depth);
	#line 496
	s283_append(v1_sb, "\n");
	#line 497
	s842_debug(v1_sb, v2_nodes, ((*v4_data).value), (v5_depth + 1l));
}


#line 501 "src/typecheck/statement.ib"
void s1010_debug_if(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, s1016_IfData * v3_if_data, i64 v4_depth) {
	#line 502
	s288_repeat(v1_sb, "  ", v4_depth);
	#line 503
	s283_append(v1_sb, "IF\n");
	#line 504
	s842_debug(v1_sb, v2_nodes, ((*v3_if_data).cond), (v4_depth + 1l));
	#line 505
	s288_repeat(v1_sb, "  ", (v4_depth + 1l));
	#line 506
	s283_append(v1_sb, "THEN\n");
	#line 507
	s842_debug(v1_sb, v2_nodes, ((*v3_if_data).then), (v4_depth + 2l));
	#line 508
	if ((((*v3_if_data).otherwise) != s825_NONE)) {
		#line 509
		s288_repeat(v1_sb, "  ", (v4_depth + 1l));
		#line 510
		s283_append(v1_sb, "ELSE\n");
		#line 511
		s842_debug(v1_sb, v2_nodes, ((*v3_if_data).otherwise), (v4_depth + 2l));
	}
}


#line 516 "src/typecheck/statement.ib"
void s1011_debug_loop(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, s1015_LoopData * v3_loop_data, i64 v4_depth) {
	#line 517
	s288_repeat(v1_sb, "  ", v4_depth);
	#line 518
	if (((*v3_loop_data).has_cond)) {
		#line 519
		s283_append(v1_sb, "WHILE\n");
		#line 520
		s842_debug(v1_sb, v2_nodes, ((*v3_loop_data).cond), (v4_depth + 1l));
	} else {
#line 522
		s283_append(v1_sb, "LOOP\n");
	}
	#line 524
	s842_debug(v1_sb, v2_nodes, ((*v3_loop_data).body), (v4_depth + 1l));
}


#line 528 "src/typecheck/statement.ib"
void s1012_debug_return(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, s1019_ReturnData * v3_return_data, i64 v4_depth) {
	#line 529
	s288_repeat(v1_sb, "  ", v4_depth);
	#line 530
	s283_append(v1_sb, "RETURN\n");
	#line 531
	if (((*v3_return_data).has_value)) {
		#line 532
		s842_debug(v1_sb, v2_nodes, ((*v3_return_data).value), (v4_depth + 1l));
	}
}


#line 537 "src/typecheck/statement.ib"
void s1013_debug_for(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, s1014_ForData * * v3_for_data, i64 v4_depth) {
	#line 538
	s288_repeat(v1_sb, "  ", v4_depth);
	#line 539
	s283_append(v1_sb, "FOR\n");
	#line 540
	s1014_ForData * v5_for_data = (*v3_for_data);
	#line 541
	s288_repeat(v1_sb, "  ", (v4_depth + 1l));
	#line 542
	s283_append(v1_sb, "INIT\n");
	#line 543
	s842_debug(v1_sb, v2_nodes, ((*v5_for_data).init), (v4_depth + 2l));
	#line 544
	s288_repeat(v1_sb, "  ", (v4_depth + 1l));
	#line 545
	s283_append(v1_sb, "COND\n");
	#line 546
	s842_debug(v1_sb, v2_nodes, ((*v5_for_data).cond), (v4_depth + 2l));
	#line 547
	s288_repeat(v1_sb, "  ", (v4_depth + 1l));
	#line 548
	s283_append(v1_sb, "ACC\n");
	#line 549
	s842_debug(v1_sb, v2_nodes, ((*v5_for_data).acc), (v4_depth + 2l));
	#line 550
	s288_repeat(v1_sb, "  ", (v4_depth + 1l));
	#line 551
	s283_append(v1_sb, "BODY\n");
	#line 552
	s842_debug(v1_sb, v2_nodes, ((*v5_for_data).body), (v4_depth + 2l));
}


#line 32 "src/codegen/node.ib"
s1028_FunctionContext s1021_create_context(s366_CodegenContext * v1_parent, s729_Module * v2_module) {
	#line 33
	return ((s1028_FunctionContext){
		.parent = v1_parent,
		.module = v2_module,
		.last_temp = 0l,
		.depth = 0l,
		.disable_next_indent = false,
		.disable_semicolon = false,
		.next_loop_id = 1l,
		.loop_ids = s243_new(((i64)8ul), 64l)
	});
}


#line 44 "src/codegen/node.ib"
void s1022_free_context(s1028_FunctionContext * v1_context) {
	#line 45
	s246_free((&((*v1_context).loop_ids)));
}


#line 49 "src/codegen/node.ib"
s848_NodeKind s1023_nodekind(s1028_FunctionContext * v1_context, i64 v2_node) {
	#line 50
	s844_Node * v3_n = s836_get((&((*((*v1_context).module)).nodes)), v2_node);
	#line 51
	return ((*v3_n).kind);
}


#line 55 "src/codegen/node.ib"
void s1024_codegen(s1028_FunctionContext * v1_context, i64 v2_node) {
	#line 56
	s844_Node * v3_n = s836_get((&((*((*v1_context).module)).nodes)), v2_node);
	#line 57
	switch (((*v3_n).kind)) {
	case s848_NodeKind_None: {
	break; }
	case s848_NodeKind_Literal: {
	s1136_codegen(v1_context, (&(((*v3_n).data).literal)));
	break; }
	case s848_NodeKind_Variable: {
	s1138_variable(v1_context, (&(((*v3_n).data).variable)));
	break; }
	case s848_NodeKind_Binary: {
	s1130_binary(v1_context, (&(((*v3_n).data).binary)));
	break; }
	case s848_NodeKind_Assign: {
	s1132_assign(v1_context, (&(((*v3_n).data).assign)));
	break; }
	case s848_NodeKind_Unary: {
	s1134_unary(v1_context, (&(((*v3_n).data).unary)));
	break; }
	case s848_NodeKind_Cast: {
	s1139_cast(v1_context, (&(((*v3_n).data).cast)));
	break; }
	case s848_NodeKind_Array: {
	s1140_array(v1_context, (&(((*v3_n).data).array)));
	break; }
	case s848_NodeKind_Index: {
	s1141_index(v1_context, (&(((*v3_n).data).index)));
	break; }
	case s848_NodeKind_StructInit:
	case s848_NodeKind_UnionInit: {
	s1142_objectinit(v1_context, (&(((*v3_n).data).object)));
	break; }
	case s848_NodeKind_StructFieldLookup:
	case s848_NodeKind_UnionFieldLookup: {
	s1143_fieldlookup(v1_context, (&(((*v3_n).data).field_lookup)));
	break; }
	case s848_NodeKind_EnumValue: {
	s1144_enumvalue(v1_context, (&(((*v3_n).data).enum_val)));
	break; }
	case s848_NodeKind_Call: {
	s1145_call(v1_context, (&(((*v3_n).data).call)));
	break; }
	case s848_NodeKind_Ref: {
	s1146_ref(v1_context, (((*v3_n).data).expr));
	break; }
	case s848_NodeKind_Deref: {
	s1147_deref(v1_context, (((*v3_n).data).expr));
	break; }
	case s848_NodeKind_Symbol: {
	s365_codegen_symbol((&((*((*v1_context).parent)).sb)), (((*v3_n).data).symbol));
	break; }
	case s848_NodeKind_Load:
	case s848_NodeKind_ObjectCopy: {
	s406_todo("codegen::nodekind::Load|Objectcopy");
	break; }
	case s848_NodeKind_Block: {
	s1117_block(v1_context, (&(((*v3_n).data).block)));
	break; }
	case s848_NodeKind_ConstDecl: {
	s1118_vardecl(v1_context, (&(((*v3_n).data).var_declaration)));
	break; }
	case s848_NodeKind_VarDecl: {
	s1118_vardecl(v1_context, (&(((*v3_n).data).var_declaration)));
	break; }
	case s848_NodeKind_Break: {
	s1119__break(v1_context);
	break; }
	case s848_NodeKind_Continue: {
	s1120__continue(v1_context);
	break; }
	case s848_NodeKind_Return: {
	s1121__return(v1_context, (&(((*v3_n).data).retrn)));
	break; }
	case s848_NodeKind_If: {
	s1122__if(v1_context, (&(((*v3_n).data).if_data)));
	break; }
	case s848_NodeKind_Match: {
	s1123__match(v1_context, (&(((*v3_n).data).match_data)));
	break; }
	case s848_NodeKind_Loop: {
	s1124__loop(v1_context, (&(((*v3_n).data).loop_data)));
	break; }
	case s848_NodeKind_For: {
	s1125__for(v1_context, (((*v3_n).data).for_data));
	break; }
	default:
		abort();
}
}


#line 104 "src/codegen/node.ib"
void s1025_indent(s1028_FunctionContext * v1_context) {
	#line 105
	if (((*v1_context).disable_next_indent)) {
		#line 106
		((*v1_context).disable_next_indent) = false;
		#line 107
		return;
	}
	#line 109
	for (i64 v2_i = 0l;(v2_i < ((*v1_context).depth));v2_i += 1l) {
		#line 110
		s284_append_char((&((*((*v1_context).parent)).sb)), 9u);
	}
	loop_exit_1:
}


#line 115 "src/codegen/node.ib"
void s1026_variable(s299_StringBuilder * v1_sb, i64 v2_var_id, char * v3_ident) {
	#line 116
	s284_append_char(v1_sb, 118u);
	#line 117
	s289_append_number(v1_sb, v2_var_id);
	#line 118
	s284_append_char(v1_sb, 95u);
	#line 119
	s283_append(v1_sb, v3_ident);
}


#line 123 "src/codegen/node.ib"
bool s1027_is_expr(s1028_FunctionContext * v1_context, i64 v2_node) {
	#line 124
	s844_Node * v3_n = s836_get((&((*((*v1_context).module)).nodes)), v2_node);
	#line 125
	switch (((*v3_n).kind)) {
	case s848_NodeKind_None: {
	break; }
	case s848_NodeKind_Literal:
	case s848_NodeKind_Variable:
	case s848_NodeKind_Binary:
	case s848_NodeKind_Assign:
	case s848_NodeKind_Unary:
	case s848_NodeKind_Cast:
	case s848_NodeKind_Array:
	case s848_NodeKind_Index:
	case s848_NodeKind_StructInit:
	case s848_NodeKind_UnionInit:
	case s848_NodeKind_StructFieldLookup:
	case s848_NodeKind_UnionFieldLookup:
	case s848_NodeKind_EnumValue:
	case s848_NodeKind_Call:
	case s848_NodeKind_Ref:
	case s848_NodeKind_Deref:
	case s848_NodeKind_Symbol:
	case s848_NodeKind_Load:
	case s848_NodeKind_ObjectCopy: {
	return true;
	break; }
	case s848_NodeKind_Block:
	case s848_NodeKind_ConstDecl:
	case s848_NodeKind_VarDecl:
	case s848_NodeKind_Break:
	case s848_NodeKind_Continue:
	case s848_NodeKind_Return:
	case s848_NodeKind_If:
	case s848_NodeKind_Match:
	case s848_NodeKind_Loop:
	case s848_NodeKind_For: {
	return false;
	break; }
	default:
		abort();
}
	#line 161
	return false;
}


#line 54 "src/typecheck/binary.ib"
i64 s1029_typecheck(s743_FunctionContext * v1_context, s893_Binary v2_data, i64 v3_span) {
	#line 59
	switch ((v2_data.op)) {
	case s897_BinaryOp_None: {
	s40_assert(false, "BinaryOp::None");
	break; }
	case s897_BinaryOp_Add:
	case s897_BinaryOp_Sub:
	case s897_BinaryOp_Mul:
	case s897_BinaryOp_Div:
	case s897_BinaryOp_Rem: {
	return s1031_arith(v1_context, v2_data, v3_span);
	break; }
	case s897_BinaryOp_Assign: {
	return s1030_assign(v1_context, v2_data, s1042_AssignOp_None, v3_span);
	break; }
	case s897_BinaryOp_AssignAdd: {
	return s1030_assign(v1_context, v2_data, s1042_AssignOp_Add, v3_span);
	break; }
	case s897_BinaryOp_AssignSub: {
	return s1030_assign(v1_context, v2_data, s1042_AssignOp_Sub, v3_span);
	break; }
	case s897_BinaryOp_AssignMul: {
	return s1030_assign(v1_context, v2_data, s1042_AssignOp_Mul, v3_span);
	break; }
	case s897_BinaryOp_AssignDiv: {
	return s1030_assign(v1_context, v2_data, s1042_AssignOp_Div, v3_span);
	break; }
	case s897_BinaryOp_AssignRem: {
	return s1030_assign(v1_context, v2_data, s1042_AssignOp_Rem, v3_span);
	break; }
	case s897_BinaryOp_EQ:
	case s897_BinaryOp_NE:
	case s897_BinaryOp_GT:
	case s897_BinaryOp_GE:
	case s897_BinaryOp_LT:
	case s897_BinaryOp_LE: {
	return s1032_pred(v1_context, v2_data, v3_span);
	break; }
	case s897_BinaryOp_And:
	case s897_BinaryOp_Or: {
	return s1033_pred_bool(v1_context, v2_data, v3_span);
	break; }
	case s897_BinaryOp_BitOr:
	case s897_BinaryOp_BitXor:
	case s897_BinaryOp_BitAnd:
	case s897_BinaryOp_BitShiftRight:
	case s897_BinaryOp_BitShiftLeft: {
	return s1034_bit_op(v1_context, v2_data, v3_span);
	break; }
	case s897_BinaryOp_Index: {
	return s1077_typecheck_index(v1_context, v2_data, v3_span);
	break; }
	case s897_BinaryOp_FieldLookup: {
	return s1089_typecheck_field_lookup(v1_context, v2_data, v3_span);
	break; }
	case s897_BinaryOp_Path: {
	return s1148_typecheck(v1_context, v2_data, v3_span);
	break; }
	default:
		abort();
}
	#line 104
	return 0l;
}


#line 108 "src/typecheck/binary.ib"
i64 s1030_assign(s743_FunctionContext * v1_context, s893_Binary v2_data, s1042_AssignOp v3_op, i64 v4_span) {
	#line 114
	s845_NodeResult v5_target_res = s827_typecheck(v1_context, (v2_data.lhs));
	#line 115
	s845_NodeResult v6_value_res = s827_typecheck(v1_context, (v2_data.rhs));
	#line 116
	i64 v7_target = (v5_target_res.node);
	#line 117
	i64 v8_value = (v6_value_res.node);
	#line 119
	if (((v7_target == s826_ERROR) || (v8_value == s826_ERROR))) {
		#line 119
		return s826_ERROR;
	}
	#line 120
	s844_Node * v9_target_data = s836_get(((*v1_context).nodes), v7_target);
	#line 122
	bool v10_cast_res = true;
	#line 123
	i64 v11_value = s1101_implicit(v1_context, v8_value, ((*v9_target_data).ty), (&v10_cast_res));
	#line 124
	if ((!v10_cast_res)) {
		#line 125
		s774_error(((*v1_context).parent), s781_ErrorKind_AssignTypeMismatch, v4_span);
	}
	#line 132
	s1040_Assign v12_assign = ((s1040_Assign){
		.op = v3_op,
		.target = v7_target,
		.value = v11_value
	});
	#line 135
	return s839_push(((*v1_context).nodes), s848_NodeKind_Assign, ((*v9_target_data).ty), ((s847_NodeData){
		.assign = v12_assign
	}), v4_span);
}


#line 143 "src/typecheck/binary.ib"
i64 s1031_arith(s743_FunctionContext * v1_context, s893_Binary v2_data, i64 v3_span) {
	#line 148
	return s1035_basic(v1_context, v2_data, v3_span);
}


#line 152 "src/typecheck/binary.ib"
i64 s1032_pred(s743_FunctionContext * v1_context, s893_Binary v2_data, i64 v3_span) {
	#line 157
	i64 v4_node = s1035_basic(v1_context, v2_data, v3_span);
	#line 158
	if ((v4_node == s826_ERROR)) {
		#line 158
		return v4_node;
	}
	#line 159
	s844_Node * v5_node_data = s836_get(((*v1_context).nodes), v4_node);
	#line 160
	((*v5_node_data).ty) = (((*((*v1_context).parent)).typeidents).boolean);
	#line 161
	return v4_node;
}


#line 165 "src/typecheck/binary.ib"
i64 s1033_pred_bool(s743_FunctionContext * v1_context, s893_Binary v2_data, i64 v3_span) {
	#line 170
	return s1035_basic(v1_context, v2_data, v3_span);
}


#line 174 "src/typecheck/binary.ib"
i64 s1034_bit_op(s743_FunctionContext * v1_context, s893_Binary v2_data, i64 v3_span) {
	#line 179
	return s1035_basic(v1_context, v2_data, v3_span);
}


#line 183 "src/typecheck/binary.ib"
i64 s1035_basic(s743_FunctionContext * v1_context, s893_Binary v2_data, i64 v3_span) {
	#line 188
	s845_NodeResult v4_lhs_res = s827_typecheck(v1_context, (v2_data.lhs));
	#line 189
	s845_NodeResult v5_rhs_res = s827_typecheck(v1_context, (v2_data.rhs));
	#line 190
	i64 v6_lhs = (v4_lhs_res.node);
	#line 191
	i64 v7_rhs = (v5_rhs_res.node);
	#line 193
	if (((v6_lhs == s826_ERROR) || (v7_rhs == s826_ERROR))) {
		#line 193
		return s826_ERROR;
	}
	#line 195
	s844_Node * v8_lhs_data = s836_get(((*v1_context).nodes), v6_lhs);
	#line 196
	s844_Node * v9_rhs_data = s836_get(((*v1_context).nodes), v7_rhs);
	#line 199
	s528_TypeIdent * v10_shared_ty = s1105_shared_type(((*v8_lhs_data).ty), ((*v9_rhs_data).ty));
	#line 200
	if ((v10_shared_ty == ((s528_TypeIdent *)NULL))) {
		#line 201
		s774_error(((*v1_context).parent), s781_ErrorKind_BinaryTypeMismatch, v3_span);
		#line 207
		v10_shared_ty = ((*v8_lhs_data).ty);
	} else {
#line 209
		bool v11_lhs_res = false;
		#line 210
		bool v12_rhs_res = false;
		#line 211
		v6_lhs = s1101_implicit(v1_context, v6_lhs, v10_shared_ty, (&v11_lhs_res));
		#line 212
		v7_rhs = s1101_implicit(v1_context, v7_rhs, v10_shared_ty, (&v12_rhs_res));
		#line 213
		if (((!v11_lhs_res) || (!v12_rhs_res))) {
			#line 214
			s523_print(((*v1_context).nodes), v10_shared_ty);
			#line 215
			s523_print(((*v1_context).nodes), ((*v8_lhs_data).ty));
			#line 216
			s523_print(((*v1_context).nodes), ((*v9_rhs_data).ty));
			#line 217
			printf("LHS %lu == %lu\n", ((*v8_lhs_data).ty), ((*v9_rhs_data).ty));
		}
		#line 219
		s40_assert(v11_lhs_res, "typecheck::cast LHS found shared_ty, but failed to implicitly cast LHS.");
		#line 220
		s40_assert(v12_rhs_res, "typecheck::cast found shared_ty, but failed to implicitly cast RHS.");
	}
	#line 223
	s1039_Binary v13_binary = ((s1039_Binary){
		.op = s1036_from_ast_op((v2_data.op)),
		.lhs = v6_lhs,
		.rhs = v7_rhs
	});
	#line 227
	return s839_push(((*v1_context).nodes), s848_NodeKind_Binary, v10_shared_ty, ((s847_NodeData){
		.binary = v13_binary
	}), v3_span);
}


#line 235 "src/typecheck/binary.ib"
s1041_BinaryOp s1036_from_ast_op(s897_BinaryOp v1_op) {
	#line 236
	switch (v1_op) {
	case s897_BinaryOp_None: {
		#line 238
		s40_assert(false, "None op is not Binaryop during typechecking.");
		#line 239
		return s1041_BinaryOp_Add;
	break; }
	case s897_BinaryOp_Add: {
	return s1041_BinaryOp_Add;
	break; }
	case s897_BinaryOp_Sub: {
	return s1041_BinaryOp_Sub;
	break; }
	case s897_BinaryOp_Mul: {
	return s1041_BinaryOp_Mul;
	break; }
	case s897_BinaryOp_Div: {
	return s1041_BinaryOp_Div;
	break; }
	case s897_BinaryOp_Rem: {
	return s1041_BinaryOp_Rem;
	break; }
	case s897_BinaryOp_Assign:
	case s897_BinaryOp_AssignAdd:
	case s897_BinaryOp_AssignSub:
	case s897_BinaryOp_AssignMul:
	case s897_BinaryOp_AssignDiv:
	case s897_BinaryOp_AssignRem: {
		#line 252
		s40_assert(false, "Assign op is not Binaryop during typechecking.");
		#line 253
		return s1041_BinaryOp_Add;
	break; }
	case s897_BinaryOp_EQ: {
	return s1041_BinaryOp_EQ;
	break; }
	case s897_BinaryOp_NE: {
	return s1041_BinaryOp_NE;
	break; }
	case s897_BinaryOp_GT: {
	return s1041_BinaryOp_GT;
	break; }
	case s897_BinaryOp_GE: {
	return s1041_BinaryOp_GE;
	break; }
	case s897_BinaryOp_LT: {
	return s1041_BinaryOp_LT;
	break; }
	case s897_BinaryOp_LE: {
	return s1041_BinaryOp_LE;
	break; }
	case s897_BinaryOp_And: {
	return s1041_BinaryOp_And;
	break; }
	case s897_BinaryOp_Or: {
	return s1041_BinaryOp_Or;
	break; }
	case s897_BinaryOp_BitAnd: {
	return s1041_BinaryOp_BitAnd;
	break; }
	case s897_BinaryOp_BitOr: {
	return s1041_BinaryOp_BitOr;
	break; }
	case s897_BinaryOp_BitXor: {
	return s1041_BinaryOp_BitXor;
	break; }
	case s897_BinaryOp_BitShiftRight: {
	return s1041_BinaryOp_BitShiftRight;
	break; }
	case s897_BinaryOp_BitShiftLeft: {
	return s1041_BinaryOp_BitShiftLeft;
	break; }
	case s897_BinaryOp_Index: {
		#line 269
		s40_assert(false, "Index is not Binaryop during typechecking.");
		#line 270
		return s1041_BinaryOp_Add;
	break; }
	case s897_BinaryOp_FieldLookup: {
		#line 273
		s40_assert(false, "FieldLookup is not Binaryop during typechecking.");
		#line 274
		return s1041_BinaryOp_Add;
	break; }
	case s897_BinaryOp_Path: {
		#line 277
		s40_assert(false, "Path is not Binaryop during typechecking.");
		#line 278
		return s1041_BinaryOp_Add;
	break; }
	default:
		abort();
}
}


#line 288 "src/typecheck/binary.ib"
void s1037_debug(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, s1039_Binary * v3_binary, i64 v4_depth) {
	#line 289
	s288_repeat(v1_sb, "  ", v4_depth);
	#line 290
	switch (((*v3_binary).op)) {
	case s1041_BinaryOp_Add: {
	s283_append(v1_sb, "ADD\n");
	break; }
	case s1041_BinaryOp_Sub: {
	s283_append(v1_sb, "SUB\n");
	break; }
	case s1041_BinaryOp_Mul: {
	s283_append(v1_sb, "MUL\n");
	break; }
	case s1041_BinaryOp_Div: {
	s283_append(v1_sb, "DIV\n");
	break; }
	case s1041_BinaryOp_Rem: {
	s283_append(v1_sb, "REM\n");
	break; }
	case s1041_BinaryOp_EQ: {
	s283_append(v1_sb, "EQ\n");
	break; }
	case s1041_BinaryOp_NE: {
	s283_append(v1_sb, "NE\n");
	break; }
	case s1041_BinaryOp_GT: {
	s283_append(v1_sb, "GT\n");
	break; }
	case s1041_BinaryOp_GE: {
	s283_append(v1_sb, "GE\n");
	break; }
	case s1041_BinaryOp_LT: {
	s283_append(v1_sb, "LT\n");
	break; }
	case s1041_BinaryOp_LE: {
	s283_append(v1_sb, "LE\n");
	break; }
	case s1041_BinaryOp_And: {
	s283_append(v1_sb, "AND\n");
	break; }
	case s1041_BinaryOp_Or: {
	s283_append(v1_sb, "OR\n");
	break; }
	case s1041_BinaryOp_BitOr: {
	s283_append(v1_sb, "BIT_OR\n");
	break; }
	case s1041_BinaryOp_BitXor: {
	s283_append(v1_sb, "BIT_XOR\n");
	break; }
	case s1041_BinaryOp_BitAnd: {
	s283_append(v1_sb, "BIT_AND\n");
	break; }
	case s1041_BinaryOp_BitShiftRight: {
	s283_append(v1_sb, "BIT_SHIFT_RIGHT\n");
	break; }
	case s1041_BinaryOp_BitShiftLeft: {
	s283_append(v1_sb, "BIT_SHIFT_LEFT\n");
	break; }
	default:
		abort();
}
	#line 314
	s842_debug(v1_sb, v2_nodes, ((*v3_binary).lhs), (v4_depth + 1l));
	#line 315
	s842_debug(v1_sb, v2_nodes, ((*v3_binary).rhs), (v4_depth + 1l));
}


#line 319 "src/typecheck/binary.ib"
void s1038_debug_assign(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, s1040_Assign * v3_assign, i64 v4_depth) {
	#line 320
	s288_repeat(v1_sb, "  ", v4_depth);
	#line 321
	switch (((*v3_assign).op)) {
	case s1042_AssignOp_None: {
	s283_append(v1_sb, "ASSIGN\n");
	break; }
	case s1042_AssignOp_Add: {
	s283_append(v1_sb, "ASSIGN_ADD\n");
	break; }
	case s1042_AssignOp_Sub: {
	s283_append(v1_sb, "ASSIGN_SUB\n");
	break; }
	case s1042_AssignOp_Mul: {
	s283_append(v1_sb, "ASSIGN_MUL\n");
	break; }
	case s1042_AssignOp_Div: {
	s283_append(v1_sb, "ASSIGN_DIV\n");
	break; }
	case s1042_AssignOp_Rem: {
	s283_append(v1_sb, "ASSIGN_REM\n");
	break; }
	default:
		abort();
}
	#line 329
	s842_debug(v1_sb, v2_nodes, ((*v3_assign).target), (v4_depth + 1l));
	#line 330
	s842_debug(v1_sb, v2_nodes, ((*v3_assign).value), (v4_depth + 1l));
}


#line 32 "src/typecheck/unary.ib"
s845_NodeResult s1043_typecheck(s743_FunctionContext * v1_context, s894_Unary v2_data, i64 v3_span) {
	#line 37
	switch ((v2_data.op)) {
	case s898_UnaryOp_Group: {
	return s827_typecheck(v1_context, (v2_data.expr));
	break; }
	case s898_UnaryOp_Ref: {
	return s1044_into_ref(v1_context, (v2_data.expr), v3_span);
	break; }
	case s898_UnaryOp_Deref: {
	return s1045_into_deref(v1_context, (v2_data.expr), v3_span);
	break; }
	case s898_UnaryOp_Pos: {
	return s1046_unary_arith(v1_context, (v2_data.expr), s1052_UnaryOp_Pos, v3_span);
	break; }
	case s898_UnaryOp_Neg: {
	return s1046_unary_arith(v1_context, (v2_data.expr), s1052_UnaryOp_Neg, v3_span);
	break; }
	case s898_UnaryOp_BitNot: {
	return s1046_unary_arith(v1_context, (v2_data.expr), s1052_UnaryOp_BitNot, v3_span);
	break; }
	case s898_UnaryOp_Not: {
	return s1047_unary_not(v1_context, (v2_data.expr), v3_span);
	break; }
	default:
		abort();
}
}


#line 49 "src/typecheck/unary.ib"
s845_NodeResult s1044_into_ref(s743_FunctionContext * v1_context, i64 v2_expr, i64 v3_span) {
	#line 54
	s845_NodeResult v4_expr_res = s827_typecheck(v1_context, v2_expr);
	#line 55
	i64 v5_expr = (v4_expr_res.node);
	#line 57
	if ((v5_expr == s826_ERROR)) {
		#line 57
		return v4_expr_res;
	}
	#line 58
	s844_Node * v6_expr_data = s836_get(((*v1_context).nodes), v5_expr);
	#line 59
	s528_TypeIdent * v7_expr_ty = s505_pointer((&((*((*v1_context).parent)).typeidents)), ((*v6_expr_data).ty));
	#line 61
	return s829_result(s839_push(((*v1_context).nodes), s848_NodeKind_Ref, v7_expr_ty, ((s847_NodeData){
		.ref = v5_expr
	}), v3_span), (v4_expr_res.flow));
}


#line 72 "src/typecheck/unary.ib"
s845_NodeResult s1045_into_deref(s743_FunctionContext * v1_context, i64 v2_expr, i64 v3_span) {
	#line 77
	s845_NodeResult v4_expr_res = s827_typecheck(v1_context, v2_expr);
	#line 78
	i64 v5_expr = (v4_expr_res.node);
	#line 80
	if ((v5_expr == s826_ERROR)) {
		#line 80
		return v4_expr_res;
	}
	#line 81
	s844_Node * v6_expr_data = s836_get(((*v1_context).nodes), v5_expr);
	#line 83
	s528_TypeIdent * v7_ty = ((*v6_expr_data).ty);
	#line 84
	if ((((*v7_ty).kind) == s534_TypeKind_Pointer)) {
		#line 85
		if (((((*v7_ty).data).pointer) == ((s528_TypeIdent *)NULL))) {
			#line 86
			return s828_some(s774_error(((*v1_context).parent), s781_ErrorKind_DerefAnyPtr, v3_span));
		}
		#line 93
		return s828_some(s839_push(((*v1_context).nodes), s848_NodeKind_Deref, (((*v7_ty).data).pointer), ((s847_NodeData){
			.deref = v5_expr
		}), v3_span));
	}
	#line 102
	return s828_some(s774_error(((*v1_context).parent), s781_ErrorKind_DerefNonPointer, v3_span));
}


#line 110 "src/typecheck/unary.ib"
s845_NodeResult s1046_unary_arith(s743_FunctionContext * v1_context, i64 v2_expr, s1052_UnaryOp v3_op, i64 v4_span) {
	#line 116
	s845_NodeResult v5_expr_res = s827_typecheck(v1_context, v2_expr);
	#line 117
	i64 v6_expr = (v5_expr_res.node);
	#line 121
	if ((v6_expr == s826_ERROR)) {
		#line 121
		return v5_expr_res;
	}
	#line 122
	s844_Node * v7_expr_data = s836_get(((*v1_context).nodes), v6_expr);
	#line 123
	if ((!s515_is_numeric(((*v7_expr_data).ty)))) {
		#line 124
		s774_error(((*v1_context).parent), s781_ErrorKind_UnaryNumericExpected, v4_span);
	}
	#line 131
	s1051_Unary v8_unary = ((s1051_Unary){
		.op = v3_op,
		.expr = v6_expr
	});
	#line 132
	return s829_result(s839_push(((*v1_context).nodes), s848_NodeKind_Unary, ((*v7_expr_data).ty), ((s847_NodeData){
		.unary = v8_unary
	}), v4_span), (v5_expr_res.flow));
}


#line 143 "src/typecheck/unary.ib"
s845_NodeResult s1047_unary_not(s743_FunctionContext * v1_context, i64 v2_expr, i64 v3_span) {
	#line 148
	s845_NodeResult v4_expr_res = s827_typecheck(v1_context, v2_expr);
	#line 149
	i64 v5_expr = (v4_expr_res.node);
	#line 154
	if ((v5_expr == s826_ERROR)) {
		#line 154
		return v4_expr_res;
	}
	#line 155
	s844_Node * v6_expr_data = s836_get(((*v1_context).nodes), v5_expr);
	#line 156
	if ((((*v6_expr_data).ty) != (((*((*v1_context).parent)).typeidents).boolean))) {
		#line 157
		s774_error(((*v1_context).parent), s781_ErrorKind_UnaryNotBoolExpected, v3_span);
	}
	#line 163
	s528_TypeIdent * v7_ty = (((*((*v1_context).parent)).typeidents).boolean);
	#line 164
	s1051_Unary v8_unary = ((s1051_Unary){
		.op = s1052_UnaryOp_Not,
		.expr = v5_expr
	});
	#line 165
	return s828_some(s839_push(((*v1_context).nodes), s848_NodeKind_Unary, v7_ty, ((s847_NodeData){
		.unary = v8_unary
	}), v3_span));
}


#line 173 "src/typecheck/unary.ib"
void s1048_debug_unary(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, s1051_Unary * v3_unary, i64 v4_depth) {
	#line 174
	s288_repeat(v1_sb, "  ", v4_depth);
	#line 175
	switch (((*v3_unary).op)) {
	case s1052_UnaryOp_Group: {
	s283_append(v1_sb, "GROUP\n");
	break; }
	case s1052_UnaryOp_Pos: {
	s283_append(v1_sb, "POS\n");
	break; }
	case s1052_UnaryOp_Neg: {
	s283_append(v1_sb, "NEG\n");
	break; }
	case s1052_UnaryOp_Not: {
	s283_append(v1_sb, "NOT\n");
	break; }
	case s1052_UnaryOp_BitNot: {
	s283_append(v1_sb, "BITNOT\n");
	break; }
	default:
		abort();
}
	#line 182
	s842_debug(v1_sb, v2_nodes, ((*v3_unary).expr), (v4_depth + 1l));
}


#line 186 "src/typecheck/unary.ib"
void s1049_debug_deref(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, i64 * v3_expr, i64 v4_depth) {
	#line 187
	s288_repeat(v1_sb, "  ", v4_depth);
	#line 188
	s283_append(v1_sb, "DEREF\n");
	#line 189
	s842_debug(v1_sb, v2_nodes, (*v3_expr), (v4_depth + 1l));
}


#line 193 "src/typecheck/unary.ib"
void s1050_debug_ref(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, i64 * v3_expr, i64 v4_depth) {
	#line 194
	s288_repeat(v1_sb, "  ", v4_depth);
	#line 195
	s283_append(v1_sb, "REF\n");
	#line 196
	s842_debug(v1_sb, v2_nodes, (*v3_expr), (v4_depth + 1l));
}


#line 42 "src/typecheck/expr.ib"
s845_NodeResult s1053_typecheck_call(s743_FunctionContext * v1_context, s890_Call v2_data, i64 v3_span) {
	#line 47
	s845_NodeResult v4_callee_res = s827_typecheck(v1_context, (v2_data.callee));
	#line 48
	i64 v5_callee = (v4_callee_res.node);
	#line 49
	if ((v5_callee == s826_ERROR)) {
		#line 49
		return s828_some(s826_ERROR);
	}
	#line 51
	s844_Node * v6_callee_data = s836_get(((*v1_context).nodes), v5_callee);
	#line 52
	if ((((*v6_callee_data).ty) == ((s528_TypeIdent *)NULL))) {
		#line 52
		return s828_some(s826_ERROR);
	}
	#line 54
	if ((((*((*v6_callee_data).ty)).kind) != s534_TypeKind_Function)) {
		#line 55
		return s828_some(s774_error(((*v1_context).parent), s781_ErrorKind_CallNotFunction, ((*v6_callee_data).span)));
	}
	#line 61
	s530_FunctionType v7_fn_type = (((*((*v6_callee_data).ty)).data).function);
	#line 63
	s1064_Call v8_call = ((s1064_Call){
		.callee = v5_callee,
		.arg_count = (v2_data.arg_count),
		.args = ((i64 *)s840_allocate_extra(((*v1_context).nodes), ((i64)(8ul * ((u64)(v2_data.arg_count))))))
	});
	#line 68
	if (((v2_data.arg_count) < (v7_fn_type.args_length))) {
		#line 69
		s774_error(((*v1_context).parent), s781_ErrorKind_CallArgCountIncorrect, ((*v6_callee_data).span));
	}
	#line 75
	if ((((v2_data.arg_count) > (v7_fn_type.args_length)) && (!(v7_fn_type.has_varargs)))) {
		#line 76
		s774_error(((*v1_context).parent), s781_ErrorKind_CallArgCountIncorrect, ((*v6_callee_data).span));
	}
	#line 82
	for (i64 v9_i = 0l;(v9_i < (v2_data.arg_count));v9_i += 1l) {
		#line 83
		s845_NodeResult v10_arg_res = s827_typecheck(v1_context, ((v2_data.args)[v9_i]));
		#line 84
		i64 v11_arg = (v10_arg_res.node);
		#line 85
		((v8_call.args)[v9_i]) = v11_arg;
		#line 86
		if ((v11_arg == s826_ERROR)) {
			#line 86
			continue;
		}
		#line 87
		s844_Node * v12_arg_data = s836_get(((*v1_context).nodes), v11_arg);
		#line 90
		if ((v9_i >= (v7_fn_type.args_length))) {
			#line 91
			continue;
		}
		#line 93
		bool v13_cast_res = true;
		#line 94
		((v8_call.args)[v9_i]) = s1101_implicit(v1_context, ((v8_call.args)[v9_i]), ((v7_fn_type.args)[v9_i]), (&v13_cast_res));
		#line 95
		if ((!v13_cast_res)) {
			#line 96
			s774_error(((*v1_context).parent), s781_ErrorKind_CallArgTypeNotMatched, ((*v12_arg_data).span));
		}
	}
	loop_exit_1:
	#line 104
	return s829_result(s839_push(((*v1_context).nodes), s848_NodeKind_Call, ((v7_fn_type.return_ty).type), ((s847_NodeData){
		.call = v8_call
	}), v3_span), s831_flow_from_typeident((v7_fn_type.return_ty)));
}


#line 114 "src/typecheck/expr.ib"
i64 s1054_typecheck_ident(s743_FunctionContext * v1_context, char * v2_ident, i64 v3_span) {
	#line 119
	if (((((*v1_context).path_stack).count) == 0l)) {
		#line 120
		s985_VarResult v4_binding = s981_get((&((*v1_context).bindings)), v2_ident);
		#line 121
		if ((v4_binding.found)) {
			#line 122
			if (((v4_binding.is_error) && ((v4_binding.ty) == ((s528_TypeIdent *)NULL)))) {
				#line 125
				return s826_ERROR;
			}
			#line 127
			s1065_Variable v5_variable = ((s1065_Variable){
				.id = (v4_binding.id),
				.ident = (v4_binding.key)
			});
			#line 131
			return s839_push(((*v1_context).nodes), s848_NodeKind_Variable, (v4_binding.ty), ((s847_NodeData){
				.variable = v5_variable
			}), v3_span);
		}
	}
	#line 138
	i64 v6_res_node = s1151_resolve_path_node(v1_context, v2_ident, v3_span);
	#line 139
	if ((v6_res_node == s826_ERROR)) {
		#line 139
		return s826_ERROR;
	}
	#line 140
	if ((v6_res_node != s825_NONE)) {
		#line 140
		return v6_res_node;
	}
	#line 143
	return s774_error(((*v1_context).parent), s781_ErrorKind_VariableNotFound, v3_span);
}


#line 148 "src/typecheck/expr.ib"
i64 s1055_typecheck_sizeof(s743_FunctionContext * v1_context, s586_TypeData v2_data, i64 v3_span) {
	#line 153
	s528_TypeIdent * v4_type = s509_typecheck(((*v1_context).parent), ((*((*v1_context).module)).uid), (v2_data.type), v3_span);
	#line 154
	i64 v5_size = 0l;
	#line 155
	if ((v4_type != ((s528_TypeIdent *)NULL))) {
		#line 156
		s995_SizeAndAlign v6_res = s987_typeident(((*v1_context).parent), v4_type);
		#line 157
		v5_size = (v6_res.size);
	}
	#line 160
	s858_LiteralValue v7_value = ((s858_LiteralValue){
		.number = v5_size
	});
	#line 161
	s857_Literal v8_literal = ((s857_Literal){
		.value = v7_value,
		.kind = s859_LiteralKind_U64
	});
	#line 162
	return s839_push(((*v1_context).nodes), s848_NodeKind_Literal, s504_atomic((&((*((*v1_context).parent)).typeidents)), s535_AtomicType_U64), ((s847_NodeData){
		.literal = v8_literal
	}), v3_span);
}


#line 170 "src/typecheck/expr.ib"
i64 s1056_load_expr(s743_FunctionContext * v1_context, i64 v2_expr) {
	#line 171
	if ((v2_expr == s826_ERROR)) {
		#line 171
		return s826_ERROR;
	}
	#line 173
	s844_Node * v3_expr_data = s836_get(((*v1_context).nodes), v2_expr);
	#line 174
	if ((((*((*v3_expr_data).ty)).kind) == s534_TypeKind_Compound)) {
		#line 175
		s201_UID v4_symbol = (((*((*v3_expr_data).ty)).data).compound);
		#line 176
		switch (s190_kind(v4_symbol)) {
		case s544_SymbolKind_Struct:
		case s544_SymbolKind_Union: {
		return s839_push(((*v1_context).nodes), s848_NodeKind_ObjectCopy, ((*v3_expr_data).ty), ((s847_NodeData){
			.expr = v2_expr
		}), ((*v3_expr_data).span));
		break; }
		default:
 {
		break; }
}
	}
	#line 188
	return s839_push(((*v1_context).nodes), s848_NodeKind_Load, ((*v3_expr_data).ty), ((s847_NodeData){
		.expr = v2_expr
	}), ((*v3_expr_data).span));
}


#line 196 "src/typecheck/expr.ib"
i64 s1057_autoderef(s743_FunctionContext * v1_context, i64 v2_expr) {
	#line 197
	s40_assert((v2_expr != s826_ERROR), "node::ERROR passed to autoderef");
	#line 198
	s844_Node * v3_expr_data = s836_get(((*v1_context).nodes), v2_expr);
	#line 199
	s40_assert((((*((*v3_expr_data).ty)).kind) == s534_TypeKind_Pointer), "autoderef was not pointer!");
	#line 203
	s528_TypeIdent * v4_inner_ty = (((*((*v3_expr_data).ty)).data).pointer);
	#line 204
	return s839_push(((*v1_context).nodes), s848_NodeKind_Deref, v4_inner_ty, ((s847_NodeData){
		.deref = v2_expr
	}), ((*v3_expr_data).span));
}


#line 216 "src/typecheck/expr.ib"
void s1058_debug_variable(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, s1065_Variable * v3_var, s528_TypeIdent * v4_ty, i64 v5_depth) {
	#line 217
	s288_repeat(v1_sb, "  ", v5_depth);
	#line 218
	s283_append(v1_sb, "VAR@");
	#line 219
	s289_append_number(v1_sb, ((*v3_var).id));
	#line 220
	s283_append(v1_sb, " [ident=");
	#line 221
	s283_append(v1_sb, ((*v3_var).ident));
	#line 222
	s283_append(v1_sb, ",ty=");
	#line 223
	s524_debug(v1_sb, v2_nodes, v4_ty, v5_depth);
	#line 224
	s283_append(v1_sb, "]");
	#line 225
	s283_append(v1_sb, "\n");
}


#line 228 "src/typecheck/expr.ib"
void s1059_debug_symbol(s299_StringBuilder * v1_sb, s846_Nodes * v2__nodes, s201_UID * v3_symbol, i64 v4_depth) {
	#line 229
	s288_repeat(v1_sb, "  ", v4_depth);
	#line 230
	s200_debug_head(v1_sb, (*v3_symbol));
	#line 231
	s283_append(v1_sb, "\n");
}


#line 235 "src/typecheck/expr.ib"
void s1060_debug_call(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, s1064_Call * v3_call, i64 v4_depth) {
	#line 236
	s288_repeat(v1_sb, "  ", v4_depth);
	#line 237
	s283_append(v1_sb, "[CALL] CALLEE:\n");
	#line 238
	s842_debug(v1_sb, v2_nodes, ((*v3_call).callee), (v4_depth + 2l));
	#line 239
	for (i64 v5_i = 0l;(v5_i < ((*v3_call).arg_count));v5_i += 1l) {
		#line 240
		s288_repeat(v1_sb, "  ", (v4_depth + 1l));
		#line 241
		s283_append(v1_sb, "ARG[");
		#line 242
		s289_append_number(v1_sb, v5_i);
		#line 243
		s283_append(v1_sb, "]\n");
		#line 244
		s842_debug(v1_sb, v2_nodes, (((*v3_call).args)[v5_i]), (v4_depth + 2l));
	}
	loop_exit_1:
}


#line 248 "src/typecheck/expr.ib"
void s1061_debug_enum_val(s299_StringBuilder * v1_sb, s846_Nodes * v2__nodes, s1066_EnumValue * v3_enum_val, i64 v4_depth) {
	#line 249
	s288_repeat(v1_sb, "  ", v4_depth);
	#line 250
	s283_append(v1_sb, "ENUM_VALUE\n");
	#line 251
	s288_repeat(v1_sb, "  ", (v4_depth + 1l));
	#line 252
	s200_debug_head(v1_sb, ((*v3_enum_val).symbol));
	#line 253
	s283_append(v1_sb, "\n");
	#line 255
	s766_EnumDef * v5_enum_def = (s183_get_deep(((*v3_enum_val).symbol)).enum_def);
	#line 256
	s765_EnumField * v6_field = (&(((*v5_enum_def).fields)[((*v3_enum_val).field_idx)]));
	#line 257
	s288_repeat(v1_sb, "  ", (v4_depth + 2l));
	#line 258
	s283_append(v1_sb, ((*v6_field).field));
	#line 259
	s283_append(v1_sb, "\t:= ");
	#line 260
	s289_append_number(v1_sb, ((*v6_field).value));
	#line 261
	s283_append(v1_sb, "\n");
}


#line 265 "src/typecheck/expr.ib"
void s1062_debug_load(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, i64 * v3_expr, i64 v4_depth) {
	#line 266
	s288_repeat(v1_sb, "  ", v4_depth);
	#line 267
	s283_append(v1_sb, "LOAD\n");
	#line 268
	s842_debug(v1_sb, v2_nodes, (*v3_expr), (v4_depth + 1l));
}


#line 271 "src/typecheck/expr.ib"
void s1063_debug_object_copy(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, i64 * v3_expr, i64 v4_depth) {
	#line 272
	s288_repeat(v1_sb, "  ", v4_depth);
	#line 273
	s283_append(v1_sb, "OBJECT_COPY\n");
	#line 274
	s842_debug(v1_sb, v2_nodes, (*v3_expr), (v4_depth + 1l));
}


#line 49 "src/typecheck/statement_match.ib"
s845_NodeResult s1067_typecheck(s743_FunctionContext * v1_context, s926_MatchData v2_data, i64 v3_span) {
	#line 54
	i64 v4_all_cond_count = 0l;
	#line 55
	for (i64 v5_i = 0l;(v5_i < (v2_data.count));v5_i += 1l) {
		#line 56
		v4_all_cond_count += (((v2_data.cases)[v5_i]).cond_count);
	}
	loop_exit_1:
	#line 63
	i64 v6_cond = s1070_typecheck_condition(v1_context, (v2_data.cond));
	#line 65
	s1075_MatchContext v7_match_context = ((s1075_MatchContext){
		.symbol = s168_NONE,
		.is_single_enum = true,
		.flow = s850_NodeFlow_Never,
		.found_default = false,
		.cond_idx = 0l
	});
	#line 73
	s1072_MatchData v8_match_data = ((s1072_MatchData){
		.cond = v6_cond,
		.count = (v2_data.count),
		.cases = ((s1073_MatchCase *)s840_allocate_extra(((*v1_context).nodes), ((i64)(32ul * ((u64)(v2_data.count))))))
	});
	#line 83
	for (i64 v9_i = 0l;(v9_i < (v2_data.count));v9_i += 1l) {
		#line 84
		s1068_typecheck_arm(v1_context, (&((v2_data.cases)[v9_i])), v9_i, (&v8_match_data), (&v7_match_context), v3_span);
	}
	loop_exit_2:
	#line 93
	s1074_CondValue * v10_cond_values = ((s1074_CondValue *)s709_pop_n((&((*v1_context).workstack)), ((i64)24ul), v4_all_cond_count));
	#line 97
	bool v11_had_cond_error = false;
	#line 98
	for (i64 v12_i = 0l;(v12_i < v4_all_cond_count);v12_i += 1l) {
		#line 99
		if (((v10_cond_values[v12_i]).errored)) {
			#line 100
			v11_had_cond_error = true;
			#line 101
			continue;
		}
		#line 103
		for (i64 v13_j = 0l;(v13_j < v12_i);v13_j += 1l) {
			#line 104
			if (((v10_cond_values[v13_j]).errored)) {
				#line 104
				continue;
			}
			#line 105
			if ((((v10_cond_values[v12_i]).value) != ((v10_cond_values[v13_j]).value))) {
				#line 105
				continue;
			}
			#line 106
			s774_error(((*v1_context).parent), s781_ErrorKind_MatchMultipleValue, ((v10_cond_values[v13_j]).span));
		}
		loop_exit_4:
	}
	loop_exit_3:
	#line 114
	bool v14_covered_all_enum_cases = true;
	#line 115
	if ((!s170_is_none((v7_match_context.symbol)))) {
		#line 116
		s766_EnumDef * v15_enum_def = (s183_get_deep((v7_match_context.symbol)).enum_def);
		#line 117
		v14_covered_all_enum_cases = (((*v15_enum_def).field_count) == v4_all_cond_count);
	}
	#line 120
	bool v16_requires_default_case = (((v7_match_context.is_single_enum) && (!v14_covered_all_enum_cases)) || (!(v7_match_context.is_single_enum)));
	#line 124
	if (((v16_requires_default_case && (!(v7_match_context.found_default))) && (!v11_had_cond_error))) {
		#line 125
		s774_error(((*v1_context).parent), s781_ErrorKind_MatchMissingDefaultCase, v3_span);
	}
	#line 128
	return s829_result(s839_push(((*v1_context).nodes), s848_NodeKind_Match, ((s528_TypeIdent *)NULL), ((s847_NodeData){
		.match_data = v8_match_data
	}), v3_span), (v7_match_context.flow));
}


#line 138 "src/typecheck/statement_match.ib"
void s1068_typecheck_arm(s743_FunctionContext * v1_context, s927_MatchCase * v2_case, i64 v3_case_idx, s1072_MatchData * v4_data, s1075_MatchContext * v5_match_context, i64 v6_span) {
	#line 146
	bool v7_has_default = ((*v2_case).has_default);
	#line 147
	i64 v8_cond_count = ((*v2_case).cond_count);
	#line 148
	i64 * v9_conds = ((i64 *)s840_allocate_extra(((*v1_context).nodes), ((i64)(8ul * ((u64)v8_cond_count)))));
	#line 151
	for (i64 v10_i = 0l;(v10_i < v8_cond_count);v10_i += 1l) {
		#line 152
		s845_NodeResult v11_node_res = s827_typecheck(v1_context, (((*v2_case).conds)[v10_i]));
		#line 153
		(v9_conds[v10_i]) = (v11_node_res.node);
		#line 154
		s1069_typecheck_arm_condition(v1_context, (v11_node_res.node), v5_match_context);
		#line 155
		((*v5_match_context).cond_idx) += 1l;
	}
	loop_exit_1:
	#line 157
	s845_NodeResult v12_arm_res = s827_typecheck(v1_context, ((*v2_case).arm));
	#line 158
	((*v5_match_context).flow) = s832_flow_any(((*v5_match_context).flow), (v12_arm_res.flow));
	#line 159
	i64 v13_arm = (v12_arm_res.node);
	#line 160
	(((*v4_data).cases)[v3_case_idx]) = ((s1073_MatchCase){
		.has_default = v7_has_default,
		.conds = v9_conds,
		.cond_count = v8_cond_count,
		.arm = v13_arm
	});
	#line 165
	if ((v7_has_default && ((*v5_match_context).found_default))) {
		#line 167
		s774_error(((*v1_context).parent), s781_ErrorKind_MatchMultipleDefaultCase, v6_span);
	}
	#line 173
	((*v5_match_context).found_default) = (((*v5_match_context).found_default) || v7_has_default);
}


#line 177 "src/typecheck/statement_match.ib"
void s1069_typecheck_arm_condition(s743_FunctionContext * v1_context, i64 v2_node, s1075_MatchContext * v3_match_context) {
	#line 182
	s1074_CondValue * v4_cond_value = ((s1074_CondValue *)s707_push((&((*v1_context).workstack)), ((i64)24ul)));
	#line 183
	if ((v2_node == s826_ERROR)) {
		#line 184
		(*v4_cond_value) = ((s1074_CondValue){
			.value = 0l,
			.span = 0l,
			.errored = true
		});
		#line 187
		return;
	}
	#line 189
	s844_Node * v5_node_data = s836_get(((*v1_context).nodes), v2_node);
	#line 190
	i64 v6_span = ((*v5_node_data).span);
	#line 191
	switch (((*v5_node_data).kind)) {
	case s848_NodeKind_EnumValue: {
		#line 193
		i64 v7_value = ((((*v5_node_data).data).enum_val).value);
		#line 194
		s201_UID v8_symbol = ((((*v5_node_data).data).enum_val).symbol);
		#line 195
		if (((*v3_match_context).is_single_enum)) {
			#line 196
			if (s170_is_none(((*v3_match_context).symbol))) {
				#line 197
				((*v3_match_context).symbol) = v8_symbol;
			} else if ((!s171_eq(((*v3_match_context).symbol), v8_symbol))) {
				#line 199
				((*v3_match_context).symbol) = s168_NONE;
				#line 200
				((*v3_match_context).is_single_enum) = false;
			}
		}
		#line 203
		(*v4_cond_value) = ((s1074_CondValue){
			.value = v7_value,
			.span = v6_span,
			.errored = false
		});
	break; }
	case s848_NodeKind_Literal: {
		#line 208
		bool v9_is_ok = true;
		#line 209
		i64 v10_value = s854_into_int((((*v5_node_data).data).literal), (&v9_is_ok));
		#line 210
		(*v4_cond_value) = ((s1074_CondValue){
			.value = v10_value,
			.span = v6_span,
			.errored = (!v9_is_ok)
		});
	break; }
	default:
 {
		#line 215
		s773_todo(((*v1_context).parent), v6_span, "statement_match:: constant cond eval");
		#line 216
		(*v4_cond_value) = ((s1074_CondValue){
			.value = 0l,
			.span = v6_span,
			.errored = true
		});
	break; }
}
}


#line 224 "src/typecheck/statement_match.ib"
i64 s1070_typecheck_condition(s743_FunctionContext * v1_context, i64 v2_ast_cond) {
	#line 228
	s845_NodeResult v3_cond_res = s827_typecheck(v1_context, v2_ast_cond);
	#line 229
	i64 v4_cond = (v3_cond_res.node);
	#line 231
	if ((v4_cond == s826_ERROR)) {
		#line 231
		return s826_ERROR;
	}
	#line 232
	s844_Node * v5_cond_data = s836_get(((*v1_context).nodes), v4_cond);
	#line 233
	if ((((*v5_cond_data).ty) == ((s528_TypeIdent *)NULL))) {
		#line 233
		return v4_cond;
	}
	#line 235
	bool v6_cond_type_valid = false;
	#line 236
	switch (((*((*v5_cond_data).ty)).kind)) {
	case s534_TypeKind_Atomic: {
	v6_cond_type_valid = s1108_is_int((((*((*v5_cond_data).ty)).data).atomic));
	break; }
	case s534_TypeKind_Compound: {
		#line 240
		s201_UID v7_s = (((*((*v5_cond_data).ty)).data).compound);
		#line 241
		v6_cond_type_valid = (s190_kind(v7_s) == s544_SymbolKind_Enum);
	break; }
	default:
 {
	v6_cond_type_valid = false;
	break; }
}
	#line 246
	if ((!v6_cond_type_valid)) {
		#line 247
		s774_error(((*v1_context).parent), s781_ErrorKind_MatchInvalidCond, ((*v5_cond_data).span));
	}
	#line 253
	return v4_cond;
}


#line 258 "src/typecheck/statement_match.ib"
void s1071_debug(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, s1072_MatchData * v3_match_data, i64 v4_depth) {
	#line 259
	s288_repeat(v1_sb, "  ", v4_depth);
	#line 260
	s283_append(v1_sb, "MATCH\n");
	#line 261
	s842_debug(v1_sb, v2_nodes, ((*v3_match_data).cond), (v4_depth + 1l));
	#line 262
	for (i64 v5_i = 0l;(v5_i < ((*v3_match_data).count));v5_i += 1l) {
		#line 263
		s288_repeat(v1_sb, "  ", (v4_depth + 1l));
		#line 264
		s283_append(v1_sb, "CASE[");
		#line 265
		s289_append_number(v1_sb, v5_i);
		#line 266
		s283_append(v1_sb, "]\n");
		#line 267
		s1073_MatchCase v6_case = (((*v3_match_data).cases)[v5_i]);
		#line 269
		if ((v6_case.has_default)) {
			#line 270
			s288_repeat(v1_sb, "  ", (v4_depth + 2l));
			#line 271
			s283_append(v1_sb, "[DEFAULT]\n");
		}
		#line 273
		for (i64 v7_i = 0l;(v7_i < (v6_case.cond_count));v7_i += 1l) {
			#line 274
			s842_debug(v1_sb, v2_nodes, ((v6_case.conds)[v7_i]), (v4_depth + 2l));
		}
		loop_exit_2:
		#line 276
		s288_repeat(v1_sb, "  ", (v4_depth + 1l));
		#line 277
		s283_append(v1_sb, "THEN\n");
		#line 278
		s842_debug(v1_sb, v2_nodes, (v6_case.arm), (v4_depth + 2l));
	}
	loop_exit_1:
}


#line 29 "src/typecheck/array.ib"
i64 s1076_typecheck(s743_FunctionContext * v1_context, s889_Array v2_data, i64 v3_span) {
	#line 34
	s1083_Array v4_array = ((s1083_Array){
		.count = (v2_data.elem_count),
		.elems = ((i64 *)s840_allocate_extra(((*v1_context).nodes), ((i64)(8ul * ((u64)(v2_data.elem_count))))))
	});
	#line 41
	for (i64 v5_i = 0l;(v5_i < (v2_data.elem_count));v5_i += 1l) {
		#line 42
		s845_NodeResult v6_res = s827_typecheck(v1_context, ((v2_data.elems)[v5_i]));
		#line 43
		((v4_array.elems)[v5_i]) = (v6_res.node);
	}
	loop_exit_1:
	#line 45
	s528_TypeIdent * v7_shared = s1079_find_array_type(v1_context, (v4_array.elems), (v4_array.count), v3_span);
	#line 47
	if ((v7_shared != ((s528_TypeIdent *)NULL))) {
		#line 48
		for (i64 v8_i = 0l;(v8_i < (v2_data.elem_count));v8_i += 1l) {
			#line 49
			bool v9_is_ok = true;
			#line 50
			((v4_array.elems)[v8_i]) = s1101_implicit(v1_context, ((v4_array.elems)[v8_i]), v7_shared, (&v9_is_ok));
		}
		loop_exit_2:
	}
	#line 60
	i64 * v10_dimensions = (&(v4_array.count));
	#line 61
	i64 v11_dim_len = 1l;
	#line 62
	s528_TypeIdent * v12_type = s507_into_array((&((*((*v1_context).parent)).typeidents)), v7_shared, v10_dimensions, v11_dim_len);
	#line 66
	return s839_push(((*v1_context).nodes), s848_NodeKind_Array, v12_type, ((s847_NodeData){
		.array = v4_array
	}), v3_span);
}


#line 73 "src/typecheck/array.ib"
i64 s1077_typecheck_index(s743_FunctionContext * v1_context, s893_Binary v2_data, i64 v3_span) {
	#line 78
	s845_NodeResult v4_array_res = s827_typecheck(v1_context, (v2_data.lhs));
	#line 79
	s845_NodeResult v5_idx_res = s827_typecheck(v1_context, (v2_data.rhs));
	#line 80
	i64 v6_array = (v4_array_res.node);
	#line 81
	i64 v7_idx = (v5_idx_res.node);
	#line 83
	s1084_Index v8_index = ((s1084_Index){
		.array = v6_array,
		.index = v7_idx
	});
	#line 84
	if ((v6_array == s826_ERROR)) {
		#line 85
		return s839_push(((*v1_context).nodes), s848_NodeKind_Index, ((s528_TypeIdent *)NULL), ((s847_NodeData){
			.index = v8_index
		}), v3_span);
	}
	#line 90
	s844_Node * v9_array_data = s836_get(((*v1_context).nodes), v6_array);
	#line 91
	if ((((*v9_array_data).ty) == ((s528_TypeIdent *)NULL))) {
		#line 91
		return s826_ERROR;
	}
	#line 93
	s528_TypeIdent * v10_elem_ty = ((s528_TypeIdent *)NULL);
	#line 94
	switch (((*((*v9_array_data).ty)).kind)) {
	case s534_TypeKind_Array: {
	v10_elem_ty = ((((*((*v9_array_data).ty)).data).array).parent);
	break; }
	case s534_TypeKind_Pointer: {
		#line 97
		if (((((*((*v9_array_data).ty)).data).pointer) == ((s528_TypeIdent *)NULL))) {
			#line 98
			s774_error(((*v1_context).parent), s781_ErrorKind_IndexAnyPtr, ((*v9_array_data).span));
		} else {
#line 104
			v10_elem_ty = (((*((*v9_array_data).ty)).data).pointer);
		}
	break; }
	default:
 {
		#line 108
		s774_error(((*v1_context).parent), s781_ErrorKind_ExprCannotBeIndexed, ((*v9_array_data).span));
	break; }
}
	#line 118
	if (((v10_elem_ty == ((s528_TypeIdent *)NULL)) || (v7_idx == s826_ERROR))) {
		#line 119
		return s839_push(((*v1_context).nodes), s848_NodeKind_Index, v10_elem_ty, ((s847_NodeData){
			.index = v8_index
		}), v3_span);
	}
	#line 124
	s844_Node * v11_idx_data = s836_get(((*v1_context).nodes), v7_idx);
	#line 125
	if (((((*v11_idx_data).ty) != ((s528_TypeIdent *)NULL)) && (!s1078_is_index_type(((*v11_idx_data).ty))))) {
		#line 126
		s774_error(((*v1_context).parent), s781_ErrorKind_IndexWasNotInteger, ((*v11_idx_data).span));
	}
	#line 139
	return s839_push(((*v1_context).nodes), s848_NodeKind_Index, v10_elem_ty, ((s847_NodeData){
		.index = v8_index
	}), v3_span);
}


#line 147 "src/typecheck/array.ib"
bool s1078_is_index_type(s528_TypeIdent * v1_type) {
	#line 148
	if ((v1_type == ((s528_TypeIdent *)NULL))) {
		#line 148
		return false;
	}
	#line 149
	if ((((*v1_type).kind) != s534_TypeKind_Atomic)) {
		#line 149
		return false;
	}
	#line 150
	return s1108_is_int((((*v1_type).data).atomic));
}


#line 178 "src/typecheck/array.ib"
s528_TypeIdent * s1079_find_array_type(s743_FunctionContext * v1_context, i64 * v2_elems, i64 v3_count, i64 v4_span) {
	#line 184
	if ((((*v1_context).target_ty) != ((s528_TypeIdent *)NULL))) {
		#line 185
		if ((((*((*v1_context).target_ty)).kind) != s534_TypeKind_Array)) {
			#line 186
			s774_error(((*v1_context).parent), s781_ErrorKind_ArrayTargetTypeWasNotArray, ((*v1_context).target_ty_span));
			#line 191
			return ((s528_TypeIdent *)NULL);
		}
		#line 193
		return ((*v1_context).target_ty);
	}
	#line 195
	if ((v3_count == 0l)) {
		#line 196
		s774_error(((*v1_context).parent), s781_ErrorKind_ArrayWasEmptyWithoutTargetType, v4_span);
		#line 201
		return ((s528_TypeIdent *)NULL);
	}
	#line 203
	s528_TypeIdent * v5_shared = ((s528_TypeIdent *)NULL);
	#line 204
	for (i64 v6_i = 0l;(v6_i < v3_count);v6_i += 1l) {
		#line 205
		if (((v2_elems[v6_i]) == s826_ERROR)) {
			#line 205
			continue;
		}
		#line 206
		s844_Node * v7_node_data = s836_get(((*v1_context).nodes), (v2_elems[v6_i]));
		#line 207
		s528_TypeIdent * v8_ty = ((*v7_node_data).ty);
		#line 208
		if ((v8_ty == ((s528_TypeIdent *)NULL))) {
			#line 208
			continue;
		}
		#line 209
		if ((v5_shared == ((s528_TypeIdent *)NULL))) {
			#line 210
			v5_shared = v8_ty;
			#line 211
			continue;
		}
		#line 214
		s528_TypeIdent * v9_new_shared = s1105_shared_type(v5_shared, v8_ty);
		#line 215
		if ((v9_new_shared == ((s528_TypeIdent *)NULL))) {
			#line 217
			continue;
		}
		#line 219
		v5_shared = v9_new_shared;
	}
	loop_exit_1:
	#line 221
	return v5_shared;
}


#line 230 "src/typecheck/array.ib"
void s1080_debug_array(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, s1083_Array * v3_array, i64 v4_depth) {
	#line 231
	s288_repeat(v1_sb, "  ", v4_depth);
	#line 232
	s283_append(v1_sb, "ARRAY\n");
	#line 233
	for (i64 v5_i = 0l;(v5_i < ((*v3_array).count));v5_i += 1l) {
		#line 234
		i64 v6_n = s1081_array_get(v3_array, v5_i);
		#line 235
		s842_debug(v1_sb, v2_nodes, v6_n, (v4_depth + 1l));
	}
	loop_exit_1:
}


#line 239 "src/typecheck/array.ib"
i64 s1081_array_get(s1083_Array * v1_array, i64 v2_index) {
	#line 240
	if ((v2_index >= ((*v1_array).count))) {
		#line 240
		return s825_NONE;
	}
	#line 241
	return (((*v1_array).elems)[v2_index]);
}


#line 244 "src/typecheck/array.ib"
void s1082_debug_index(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, s1084_Index * v3_index, i64 v4_depth) {
	#line 245
	s288_repeat(v1_sb, "  ", v4_depth);
	#line 246
	s283_append(v1_sb, "INDEX\n");
	#line 247
	s842_debug(v1_sb, v2_nodes, ((*v3_index).array), (v4_depth + 2l));
	#line 248
	s288_repeat(v1_sb, "  ", v4_depth);
	#line 249
	s283_append(v1_sb, "  [IDX]\n");
	#line 250
	s842_debug(v1_sb, v2_nodes, ((*v3_index).index), (v4_depth + 2l));
}


#line 44 "src/typecheck/object_expr.ib"
i64 s1085_typecheck_objectinit(s743_FunctionContext * v1_context, s891_ObjectInit v2_data, i64 v3_span) {
	#line 49
	s1096_ObjectInit v4_object = s1088_object_init(v1_context, v2_data, v3_span);
	#line 51
	if (s170_is_none((v4_object.type))) {
		#line 52
		return s826_ERROR;
	}
	#line 55
	s848_NodeKind v5_node_kind = s848_NodeKind_StructInit;
	#line 56
	s201_UID v6_ty = (v4_object.type);
	#line 57
	switch (s190_kind(v6_ty)) {
	case s544_SymbolKind_Struct: {
		#line 59
		v5_node_kind = s848_NodeKind_StructInit;
		#line 60
		s1086_typecheck_struct_init(v1_context, (&v4_object), v3_span);
	break; }
	case s544_SymbolKind_Union: {
		#line 63
		v5_node_kind = s848_NodeKind_UnionInit;
		#line 64
		s1087_typecheck_union_init(v1_context, (&v4_object), v3_span);
	break; }
	default:
 {
		#line 67
		return s774_error(((*v1_context).parent), s781_ErrorKind_SymbolCannotBeConstructed, v3_span);
	break; }
}
	#line 75
	return s839_push(((*v1_context).nodes), v5_node_kind, s186_get_type((v4_object.type)), ((s847_NodeData){
		.object = v4_object
	}), v3_span);
}


#line 82 "src/typecheck/object_expr.ib"
void s1086_typecheck_struct_init(s743_FunctionContext * v1_context, s1096_ObjectInit * v2_init, i64 v3_span) {
	#line 84
	if ((((*v2_init).field_count) == 0l)) {
		#line 84
		return;
	}
	#line 85
	s758_ObjectDef * v4_object_def = (s183_get_deep(((*v2_init).type)).object_def);
	#line 86
	for (i64 v5_i = 0l;(v5_i < ((*v4_object_def).field_count));v5_i += 1l) {
		#line 87
		bool v6_found = false;
		#line 88
		i64 v7_init_index = 0l;
		#line 89
		for (v7_init_index;((v7_init_index < ((*v2_init).field_count)) && (!v6_found));v7_init_index += 1l) {
#line 90
			v6_found = (((((*v4_object_def).fields)[v5_i]).field) == ((((*v2_init).fields)[v7_init_index]).field));
		}
		loop_exit_2:
		#line 92
		if (v6_found) {
			#line 92
			continue;
		}
		#line 93
		s775_object_missing_field(((*v1_context).parent), ((((*v4_object_def).fields)[v5_i]).field), v3_span);
	}
	loop_exit_1:
	#line 100
	for (i64 v8_i = 0l;(v8_i < ((*v2_init).field_count));v8_i += 1l) {
		#line 101
		bool v9_found = false;
		#line 102
		i64 v10_obj_def_idx = 0l;
		#line 103
		for (v10_obj_def_idx = 0l;(v10_obj_def_idx < ((*v4_object_def).field_count));v10_obj_def_idx += 1l) {
#line 104
			if ((((((*v2_init).fields)[v8_i]).field) == ((((*v4_object_def).fields)[v10_obj_def_idx]).field))) {
				#line 105
				v9_found = true;
				#line 106
								goto loop_exit_4;
/* break; */
			}
		}
		loop_exit_4:
		#line 109
		if ((!v9_found)) {
			#line 111
			s774_error(((*v1_context).parent), s781_ErrorKind_UndefinedObjectField, ((((*v2_init).fields)[v8_i]).field_span));
			#line 116
			continue;
		}
		#line 119
		if ((((((*v2_init).fields)[v8_i]).value) < 0l)) {
			#line 120
			s774_error(((*v1_context).parent), s781_ErrorKind_UnknownError, ((((*v2_init).fields)[v8_i]).field_span));
			#line 121
			return;
		}
		#line 124
		bool v11_is_ok = true;
		#line 125
		((((*v2_init).fields)[v8_i]).value) = s1101_implicit(v1_context, ((((*v2_init).fields)[v8_i]).value), ((((*v4_object_def).fields)[v10_obj_def_idx]).type), (&v11_is_ok));
		#line 131
		if ((!v11_is_ok)) {
			#line 132
			s774_error(((*v1_context).parent), s781_ErrorKind_ObjectInitFieldTypeMismatch, ((((*v2_init).fields)[v8_i]).field_span));
		}
	}
	loop_exit_3:
}


#line 142 "src/typecheck/object_expr.ib"
void s1087_typecheck_union_init(s743_FunctionContext * v1_context, s1096_ObjectInit * v2_init, i64 v3_span) {
	#line 144
	if ((((*v2_init).field_count) == 0l)) {
		#line 144
		return;
	}
	#line 145
	if ((((*v2_init).field_count) > 1l)) {
		#line 146
		s774_error(((*v1_context).parent), s781_ErrorKind_UnionInitOnlyOneFieldAllowed, v3_span);
		#line 151
		return;
	}
	#line 153
	s758_ObjectDef * v4_object_def = (s183_get_deep(((*v2_init).type)).object_def);
	#line 155
	s1097_ObjectFieldInit v5_field = (((*v2_init).fields)[0l]);
	#line 156
	s757_ObjectField * v6_field_def = s745_get_field(v4_object_def, (v5_field.field));
	#line 157
	if ((v6_field_def == ((s757_ObjectField *)NULL))) {
		#line 159
		s774_error(((*v1_context).parent), s781_ErrorKind_UndefinedObjectField, (v5_field.field_span));
		#line 164
		return;
	}
	#line 167
	bool v7_is_ok = true;
	#line 168
	(v5_field.value) = s1101_implicit(v1_context, (v5_field.value), ((*v6_field_def).type), (&v7_is_ok));
	#line 174
	if ((!v7_is_ok)) {
		#line 175
		s774_error(((*v1_context).parent), s781_ErrorKind_ObjectInitFieldTypeMismatch, (v5_field.field_span));
	}
}


#line 185 "src/typecheck/object_expr.ib"
s1096_ObjectInit s1088_object_init(s743_FunctionContext * v1_context, s891_ObjectInit v2_data, i64 v3_span) {
	#line 186
	s201_UID v4_type = s1150_resolve_path_symbol(v1_context, (v2_data.type), v3_span);
	#line 188
	i64 v5_field_count = (v2_data.field_count);
	#line 189
	s1096_ObjectInit v6_init = ((s1096_ObjectInit){
		.type = v4_type,
		.field_count = v5_field_count,
		.fields = ((s1097_ObjectFieldInit *)s840_allocate_extra(((*v1_context).nodes), ((i64)(24ul * ((u64)v5_field_count)))))
	});
	#line 196
	for (i64 v7_i = 0l;(v7_i < v5_field_count);v7_i += 1l) {
		#line 197
		s892_ObjectFieldInit * v8_field = (&((v2_data.fields)[v7_i]));
		#line 198
		s845_NodeResult v9_value_res = s827_typecheck(v1_context, ((*v8_field).value));
		#line 199
		i64 v10_value = (v9_value_res.node);
		#line 201
		((v6_init.fields)[v7_i]) = ((s1097_ObjectFieldInit){
			.field = ((*v8_field).field),
			.field_span = ((*v8_field).field_span),
			.value = v10_value
		});
		#line 207
		for (i64 v11_j = 0l;(v11_j < v7_i);v11_j += 1l) {
			#line 208
			if (((((v6_init.fields)[v7_i]).field) == (((v6_init.fields)[v11_j]).field))) {
				#line 209
				s774_error(((*v1_context).parent), s781_ErrorKind_DuplicateObjectField, ((*v8_field).field_span));
			}
		}
		loop_exit_2:
	}
	loop_exit_1:
	#line 218
	return v6_init;
}


#line 222 "src/typecheck/object_expr.ib"
i64 s1089_typecheck_field_lookup(s743_FunctionContext * v1_context, s893_Binary v2_data, i64 v3_span) {
	#line 227
	s845_NodeResult v4_object_res = s827_typecheck(v1_context, (v2_data.lhs));
	#line 228
	i64 v5_object = (v4_object_res.node);
	#line 229
	if ((v5_object == s826_ERROR)) {
		#line 229
		return s826_ERROR;
	}
	#line 231
	s587_Node * v6_field = s578_get((&((*((*v1_context).module)).nodes)), (v2_data.rhs));
	#line 232
	if ((((*v6_field).kind) != s589_NodeKind_Ident)) {
		#line 233
		return s774_error(((*v1_context).parent), s781_ErrorKind_ObjectFieldWasNotIdentifier, ((*v6_field).span));
	}
	#line 239
	i64 v7_field_span = ((*v6_field).span);
	#line 240
	char * v8_field = (((*v6_field).data).ident);
	#line 242
	s848_NodeKind v9_node_kind = s848_NodeKind_StructFieldLookup;
	#line 243
	s844_Node * v10_object_data = s836_get(((*v1_context).nodes), v5_object);
	#line 244
	s528_TypeIdent * v11_object_ty = ((*v10_object_data).ty);
	#line 245
	s758_ObjectDef * v12_def = ((s758_ObjectDef *)NULL);
	#line 246
	if ((v11_object_ty == ((s528_TypeIdent *)NULL))) {
		#line 246
		return s826_ERROR;
	}
	#line 249
	if ((((*v11_object_ty).kind) == s534_TypeKind_Pointer)) {
		#line 250
		s528_TypeIdent * v13_inner_ty = (((*v11_object_ty).data).pointer);
		#line 251
		if (s517_is_object(v13_inner_ty)) {
			#line 252
			v5_object = s1057_autoderef(v1_context, v5_object);
			#line 253
			v10_object_data = s836_get(((*v1_context).nodes), v5_object);
			#line 254
			v11_object_ty = ((*v10_object_data).ty);
		}
	}
	#line 258
	switch (((*v11_object_ty).kind)) {
	case s534_TypeKind_Compound: {
		#line 260
		s201_UID v14_s = (((*v11_object_ty).data).compound);
		#line 261
		switch (s190_kind(v14_s)) {
		case s544_SymbolKind_Struct: {
			#line 263
			v9_node_kind = s848_NodeKind_StructFieldLookup;
			#line 264
			v12_def = (s183_get_deep(v14_s).object_def);
		break; }
		case s544_SymbolKind_Union: {
			#line 267
			v9_node_kind = s848_NodeKind_UnionFieldLookup;
			#line 268
			v12_def = (s183_get_deep(v14_s).object_def);
		break; }
		default:
 {
		break; }
}
	break; }
	default:
 {
	break; }
}
	#line 275
	if ((v12_def == ((s758_ObjectDef *)NULL))) {
		#line 276
		return s774_error(((*v1_context).parent), s781_ErrorKind_ObjectExpected, ((*v10_object_data).span));
	}
	#line 282
	i64 v15_obj_idx = s746_get_field_idx(v12_def, v8_field);
	#line 283
	if ((v15_obj_idx == s744_FIELD_IDX_NONE)) {
		#line 284
		s774_error(((*v1_context).parent), s781_ErrorKind_ObjectFieldNotFound, v7_field_span);
	}
	#line 290
	s528_TypeIdent * v16_type = ((((*v12_def).fields)[v15_obj_idx]).type);
	#line 292
	s1098_FieldLookup v17_field_lookup = ((s1098_FieldLookup){
		.object = v5_object,
		.field = v8_field,
		.field_span = v7_field_span
	});
	#line 297
	return s839_push(((*v1_context).nodes), v9_node_kind, v16_type, ((s847_NodeData){
		.field_lookup = v17_field_lookup
	}), v3_span);
}


#line 304 "src/typecheck/object_expr.ib"
void s1090_debug_struct_init(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, s1096_ObjectInit * v3_obj_init, i64 v4_depth) {
	#line 305
	s1092_debug_init(v1_sb, v2_nodes, v3_obj_init, v4_depth, "STRUCT_INIT ");
}


#line 308 "src/typecheck/object_expr.ib"
void s1091_debug_union_init(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, s1096_ObjectInit * v3_obj_init, i64 v4_depth) {
	#line 309
	s1092_debug_init(v1_sb, v2_nodes, v3_obj_init, v4_depth, "UNION_INIT ");
}


#line 312 "src/typecheck/object_expr.ib"
void s1092_debug_init(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, s1096_ObjectInit * v3_obj_init, i64 v4_depth, char * v5_key) {
	#line 313
	s288_repeat(v1_sb, "  ", v4_depth);
	#line 314
	s283_append(v1_sb, v5_key);
	#line 315
	s200_debug_head(v1_sb, ((*v3_obj_init).type));
	#line 316
	s283_append(v1_sb, "\n");
	#line 317
	if ((((*v3_obj_init).field_count) == 0l)) {
		#line 318
		s288_repeat(v1_sb, "  ", (v4_depth + 1l));
		#line 319
		s283_append(v1_sb, "[ZERO_INIT]\n");
	}
	#line 321
	for (i64 v6_i = 0l;(v6_i < ((*v3_obj_init).field_count));v6_i += 1l) {
		#line 322
		s288_repeat(v1_sb, "  ", (v4_depth + 1l));
		#line 323
		s283_append(v1_sb, ((((*v3_obj_init).fields)[v6_i]).field));
		#line 324
		s283_append(v1_sb, "\n");
		#line 325
		i64 v7_value = ((((*v3_obj_init).fields)[v6_i]).value);
		#line 326
		if ((v7_value != s825_NONE)) {
			#line 327
			s842_debug(v1_sb, v2_nodes, v7_value, (v4_depth + 2l));
		}
	}
	loop_exit_1:
}


#line 332 "src/typecheck/object_expr.ib"
void s1093_debug_struct_lookup(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, s1098_FieldLookup * v3_lookup, i64 v4_depth) {
	#line 333
	s1095_debug_lookup(v1_sb, v2_nodes, v3_lookup, v4_depth, "STRUCT_FIELD_LOOKUP\n");
}


#line 336 "src/typecheck/object_expr.ib"
void s1094_debug_union_lookup(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, s1098_FieldLookup * v3_lookup, i64 v4_depth) {
	#line 337
	s1095_debug_lookup(v1_sb, v2_nodes, v3_lookup, v4_depth, "UNION_FIELD_LOOKUP\n");
}


#line 340 "src/typecheck/object_expr.ib"
void s1095_debug_lookup(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, s1098_FieldLookup * v3_lookup, i64 v4_depth, char * v5_key) {
	#line 341
	s288_repeat(v1_sb, "  ", v4_depth);
	#line 342
	s283_append(v1_sb, v5_key);
	#line 343
	s842_debug(v1_sb, v2_nodes, ((*v3_lookup).object), (v4_depth + 1l));
	#line 344
	s288_repeat(v1_sb, "  ", (v4_depth + 1l));
	#line 345
	s283_append(v1_sb, "[FIELD] ");
	#line 346
	s283_append(v1_sb, ((*v3_lookup).field));
	#line 347
	s283_append(v1_sb, "\n");
}


#line 40 "src/typecheck/cast.ib"
i64 s1100_explicit(s743_FunctionContext * v1_context, s888_Cast v2_data, i64 v3_span) {
	#line 45
	s845_NodeResult v4_expr_res = s827_typecheck(v1_context, (v2_data.expr));
	#line 46
	i64 v5_expr = (v4_expr_res.node);
	#line 47
	if ((v5_expr == s826_ERROR)) {
		#line 47
		return s826_ERROR;
	}
	#line 48
	s844_Node * v6_expr_data = s836_get(((*v1_context).nodes), v5_expr);
	#line 50
	s528_TypeIdent * v7_from = ((*v6_expr_data).ty);
	#line 51
	s528_TypeIdent * v8_into = s509_typecheck(((*v1_context).parent), ((*((*v1_context).module)).uid), (v2_data.type), (v2_data.type_span));
	#line 52
	if ((v8_into == ((s528_TypeIdent *)NULL))) {
		#line 52
		return s826_ERROR;
	}
	#line 54
	s1113_Cast v9_cast = ((s1113_Cast){
		.expr = v5_expr,
		.into = v8_into,
		.method = s1115_CastMethod_Keep
	});
	#line 57
	if ((v5_expr == s826_ERROR)) {
		#line 58
		return s839_push(((*v1_context).nodes), s848_NodeKind_Cast, v8_into, ((s847_NodeData){
			.cast = v9_cast
		}), v3_span);
	}
	#line 65
	bool v10_is_ok = true;
	#line 66
	(v9_cast.method) = s1102_cast_method(v7_from, v8_into, true, (&v10_is_ok));
	#line 67
	if ((!v10_is_ok)) {
		#line 68
		s774_error(((*v1_context).parent), s781_ErrorKind_InvalidCast, v3_span);
	}
	#line 71
	return s839_push(((*v1_context).nodes), s848_NodeKind_Cast, v8_into, ((s847_NodeData){
		.cast = v9_cast
	}), v3_span);
}


#line 82 "src/typecheck/cast.ib"
i64 s1101_implicit(s743_FunctionContext * v1_context, i64 v2_expr, s528_TypeIdent * v3_into, bool * v4_res_ok) {
	#line 88
	if ((v2_expr == s826_ERROR)) {
		#line 88
		return s826_ERROR;
	}
	#line 89
	if ((v2_expr == s825_NONE)) {
		#line 89
		return s825_NONE;
	}
	#line 91
	s844_Node * v5_expr_data = s836_get(((*v1_context).nodes), v2_expr);
	#line 92
	i64 v6_span = ((*v5_expr_data).span);
	#line 93
	s528_TypeIdent * v7_from = ((*v5_expr_data).ty);
	#line 95
	if ((((v7_from == v3_into) || (v3_into == ((s528_TypeIdent *)NULL))) || (v7_from == ((s528_TypeIdent *)NULL)))) {
		#line 96
		(*v4_res_ok) = true;
		#line 97
		return v2_expr;
	}
	#line 99
	s1115_CastMethod v8_method = s1102_cast_method(v7_from, v3_into, false, v4_res_ok);
	#line 100
	s1113_Cast v9_cast = ((s1113_Cast){
		.expr = v2_expr,
		.into = v3_into,
		.method = v8_method
	});
	#line 103
	return s839_push(((*v1_context).nodes), s848_NodeKind_Cast, v3_into, ((s847_NodeData){
		.cast = v9_cast
	}), v6_span);
}


#line 113 "src/typecheck/cast.ib"
s1115_CastMethod s1102_cast_method(s528_TypeIdent * v1_from, s528_TypeIdent * v2_into, bool v3_is_explicit, bool * v4_res_ok) {
	#line 119
	(*v4_res_ok) = true;
	#line 120
	if ((v1_from == v2_into)) {
		#line 120
		return s1115_CastMethod_Keep;
	}
	#line 121
	if (((v1_from == ((s528_TypeIdent *)NULL)) || (v2_into == ((s528_TypeIdent *)NULL)))) {
		#line 121
		return s1115_CastMethod_Keep;
	}
	#line 123
	if (((((*v1_from).kind) == s534_TypeKind_Atomic) && (((*v2_into).kind) == s534_TypeKind_Atomic))) {
		#line 124
		return s1104_try_cast_atomic((((*v1_from).data).atomic), (((*v2_into).data).atomic), v3_is_explicit, v4_res_ok);
	}
	#line 127
	if (((((*v1_from).kind) == s534_TypeKind_Pointer) && (((*v2_into).kind) == s534_TypeKind_Pointer))) {
		#line 128
		bool v5_has_anyptr = (((((*v1_from).data).pointer) == ((s528_TypeIdent *)NULL)) || ((((*v2_into).data).pointer) == ((s528_TypeIdent *)NULL)));
		#line 129
		if ((v5_has_anyptr || v3_is_explicit)) {
			#line 129
			return s1115_CastMethod_Keep;
		}
		#line 131
		s528_TypeIdent * v6__into_inner = (((*v2_into).data).pointer);
		#line 133
		(*v4_res_ok) = false;
		#line 134
		return s1099_CAST_INVALID;
	}
	#line 137
	if ((((((*v1_from).kind) == s534_TypeKind_Pointer) && (((*v2_into).kind) == s534_TypeKind_Atomic)) && v3_is_explicit)) {
		#line 138
		if (s1108_is_int((((*v2_into).data).atomic))) {
			#line 139
			return s1104_try_cast_atomic(s535_AtomicType_U64, (((*v2_into).data).atomic), v3_is_explicit, v4_res_ok);
		}
	}
	#line 142
	if ((((((*v1_from).kind) == s534_TypeKind_Atomic) && (((*v2_into).kind) == s534_TypeKind_Pointer)) && v3_is_explicit)) {
		#line 143
		if (s1108_is_int((((*v1_from).data).atomic))) {
			#line 144
			return s1104_try_cast_atomic((((*v1_from).data).atomic), s535_AtomicType_U64, v3_is_explicit, v4_res_ok);
		}
	}
	#line 148
	if (((((*v1_from).kind) == s534_TypeKind_Function) && (((*v2_into).kind) == s534_TypeKind_Function))) {
		#line 151
		return s1115_CastMethod_Keep;
	}
	#line 154
	bool v7_has_fn = ((((*v1_from).kind) == s534_TypeKind_Function) || (((*v2_into).kind) == s534_TypeKind_Function));
	#line 155
	bool v8_has_ptr = ((((*v1_from).kind) == s534_TypeKind_Pointer) || (((*v2_into).kind) == s534_TypeKind_Pointer));
	#line 156
	if ((v7_has_fn && v8_has_ptr)) {
		#line 161
		return s1115_CastMethod_Keep;
	}
	#line 164
	bool v9_is_from_enum = s516_is_enum(v1_from);
	#line 165
	bool v10_is_into_enum = s516_is_enum(v2_into);
	#line 166
	if ((v9_is_from_enum || v10_is_into_enum)) {
		#line 167
		return s1103_try_cast_enum(v1_from, v9_is_from_enum, v2_into, v10_is_into_enum, v3_is_explicit, v4_res_ok);
	}
	#line 174
	(*v4_res_ok) = false;
	#line 175
	return s1099_CAST_INVALID;
}


#line 178 "src/typecheck/cast.ib"
s1115_CastMethod s1103_try_cast_enum(s528_TypeIdent * v1_from, bool v2_is_from_enum, s528_TypeIdent * v3_into, bool v4_is_into_enum, bool v5_is_explicit, bool * v6_res_ok) {
	#line 179
	i64 v7_from_bits = 0l;
	#line 180
	if (v2_is_from_enum) {
		#line 181
		s766_EnumDef * v8_enum_def = (s183_get_deep((((*v1_from).data).compound)).enum_def);
		#line 182
		v7_from_bits = (((*v8_enum_def).size) * 8l);
	} else if (((((*v1_from).kind) == s534_TypeKind_Atomic) && v5_is_explicit)) {
		#line 185
		v7_from_bits = s1111_atomic_bits((((*v1_from).data).atomic));
	} else {
#line 188
		(*v6_res_ok) = false;
		#line 189
		return s1099_CAST_INVALID;
	}
	#line 191
	i64 v9_into_bits = 0l;
	#line 192
	if (v4_is_into_enum) {
		#line 193
		s766_EnumDef * v10_enum_def = (s183_get_deep((((*v3_into).data).compound)).enum_def);
		#line 194
		v9_into_bits = (((*v10_enum_def).size) * 8l);
	} else if ((((*v3_into).kind) == s534_TypeKind_Atomic)) {
		#line 196
		v9_into_bits = s1111_atomic_bits((((*v3_into).data).atomic));
	} else {
#line 199
		(*v6_res_ok) = false;
		#line 200
		return s1099_CAST_INVALID;
	}
	#line 204
	if (((v4_is_into_enum && v2_is_from_enum) && (!v5_is_explicit))) {
		#line 205
		(*v6_res_ok) = false;
		#line 206
		return s1099_CAST_INVALID;
	}
	#line 209
	if ((v7_from_bits < v9_into_bits)) {
		#line 210
		return s1115_CastMethod_Extend;
	} else if ((v7_from_bits > v9_into_bits)) {
		#line 212
		return s1115_CastMethod_Truncate;
	} else {
#line 215
		return s1115_CastMethod_Keep;
	}
}


#line 219 "src/typecheck/cast.ib"
s1115_CastMethod s1104_try_cast_atomic(s535_AtomicType v1_from, s535_AtomicType v2_into, bool v3__is_explicit, bool * v4_res_ok) {
	#line 220
	if ((v1_from == v2_into)) {
		#line 220
		return s1115_CastMethod_Keep;
	}
	#line 222
	if (((v1_from == s535_AtomicType_Bool) || (v2_into == s535_AtomicType_Bool))) {
		#line 223
		(*v4_res_ok) = false;
		#line 224
		return s1099_CAST_INVALID;
	}
	#line 226
	if ((s1107_is_float(v1_from) && s1108_is_int(v2_into))) {
		#line 226
		return s1115_CastMethod_FloatToInt;
	}
	#line 227
	if ((s1108_is_int(v1_from) && s1107_is_float(v2_into))) {
		#line 227
		return s1115_CastMethod_IntToFloat;
	}
	#line 230
	i64 v5_from_bits = s1111_atomic_bits(v1_from);
	#line 231
	i64 v6_into_bits = s1111_atomic_bits(v2_into);
	#line 233
	if ((v5_from_bits < v6_into_bits)) {
		#line 234
		return s1115_CastMethod_Extend;
	} else if ((v5_from_bits > v6_into_bits)) {
		#line 237
		return s1115_CastMethod_Truncate;
	} else {
#line 240
		return s1115_CastMethod_Keep;
	}
}


#line 245 "src/typecheck/cast.ib"
s528_TypeIdent * s1105_shared_type(s528_TypeIdent * v1_lhs, s528_TypeIdent * v2_rhs) {
	#line 246
	if ((v1_lhs == v2_rhs)) {
		#line 246
		return v1_lhs;
	}
	#line 247
	if (((v1_lhs == ((s528_TypeIdent *)NULL)) || (v2_rhs == ((s528_TypeIdent *)NULL)))) {
		#line 247
		return ((s528_TypeIdent *)NULL);
	}
	#line 248
	if (((((*v1_lhs).kind) == s534_TypeKind_Atomic) && (((*v2_rhs).kind) == s534_TypeKind_Atomic))) {
		#line 248
		return s1106_shared_atomic(v1_lhs, v2_rhs);
	}
	#line 249
	if (((((*v1_lhs).kind) == s534_TypeKind_Pointer) && (((*v2_rhs).kind) == s534_TypeKind_Pointer))) {
		#line 249
		return v1_lhs;
	}
	#line 250
	if (((((*v1_lhs).kind) == s534_TypeKind_Pointer) && (((*v2_rhs).kind) == s534_TypeKind_Function))) {
		#line 250
		return v1_lhs;
	}
	#line 251
	if (((((*v1_lhs).kind) == s534_TypeKind_Function) && (((*v2_rhs).kind) == s534_TypeKind_Pointer))) {
		#line 251
		return v1_lhs;
	}
	#line 253
	return ((s528_TypeIdent *)NULL);
}


#line 257 "src/typecheck/cast.ib"
s528_TypeIdent * s1106_shared_atomic(s528_TypeIdent * v1_lhs, s528_TypeIdent * v2_rhs) {
	#line 258
	s535_AtomicType v3_lhsa = (((*v1_lhs).data).atomic);
	#line 259
	s535_AtomicType v4_rhsa = (((*v2_rhs).data).atomic);
	#line 260
	if ((v3_lhsa == v4_rhsa)) {
		#line 260
		return v1_lhs;
	}
	#line 262
	if (((v3_lhsa == s535_AtomicType_Bool) || (v4_rhsa == s535_AtomicType_Bool))) {
		#line 263
		return ((s528_TypeIdent *)NULL);
	}
	#line 266
	s528_TypeIdent * v5_larger_ty = v1_lhs;
	#line 267
	if ((s1111_atomic_bits(v4_rhsa) > s1111_atomic_bits(v3_lhsa))) {
		#line 267
		v5_larger_ty = v2_rhs;
	}
	#line 270
	if ((s1108_is_int(v3_lhsa) && s1108_is_int(v4_rhsa))) {
		#line 270
		return v5_larger_ty;
	}
	#line 271
	if ((s1107_is_float(v3_lhsa) && s1107_is_float(v4_rhsa))) {
		#line 271
		return v5_larger_ty;
	}
	#line 273
	if ((s1107_is_float(v3_lhsa) || s1108_is_int(v4_rhsa))) {
		#line 273
		return v1_lhs;
	}
	#line 274
	if ((s1108_is_int(v3_lhsa) || s1107_is_float(v4_rhsa))) {
		#line 274
		return v2_rhs;
	}
	#line 276
	return ((s528_TypeIdent *)NULL);
}


#line 280 "src/typecheck/cast.ib"
bool s1107_is_float(s535_AtomicType v1_atomic) {
	#line 281
	switch (v1_atomic) {
	case s535_AtomicType_F32:
	case s535_AtomicType_F64: {
	return true;
	break; }
	default:
 {
	return false;
	break; }
}
}


#line 290 "src/typecheck/cast.ib"
bool s1108_is_int(s535_AtomicType v1_atomic) {
	#line 291
	return (s1109_is_uint(v1_atomic) || s1110_is_sint(v1_atomic));
}


#line 294 "src/typecheck/cast.ib"
bool s1109_is_uint(s535_AtomicType v1_atomic) {
	#line 295
	switch (v1_atomic) {
	case s535_AtomicType_U8:
	case s535_AtomicType_U16:
	case s535_AtomicType_U32:
	case s535_AtomicType_U64:
	case s535_AtomicType_U128: {
	return true;
	break; }
	default:
 {
	return false;
	break; }
}
}


#line 307 "src/typecheck/cast.ib"
bool s1110_is_sint(s535_AtomicType v1_atomic) {
	#line 308
	switch (v1_atomic) {
	case s535_AtomicType_I8:
	case s535_AtomicType_I16:
	case s535_AtomicType_I32:
	case s535_AtomicType_I64:
	case s535_AtomicType_I128: {
	return true;
	break; }
	default:
 {
	return false;
	break; }
}
}


#line 320 "src/typecheck/cast.ib"
i64 s1111_atomic_bits(s535_AtomicType v1_atomic) {
	#line 321
	switch (v1_atomic) {
	case s535_AtomicType_Bool: {
	return 1l;
	break; }
	case s535_AtomicType_U8: {
	return 8l;
	break; }
	case s535_AtomicType_U16: {
	return 16l;
	break; }
	case s535_AtomicType_U32: {
	return 32l;
	break; }
	case s535_AtomicType_U64: {
	return 64l;
	break; }
	case s535_AtomicType_U128: {
	return 128l;
	break; }
	case s535_AtomicType_I8: {
	return 8l;
	break; }
	case s535_AtomicType_I16: {
	return 16l;
	break; }
	case s535_AtomicType_I32: {
	return 32l;
	break; }
	case s535_AtomicType_I64: {
	return 64l;
	break; }
	case s535_AtomicType_I128: {
	return 128l;
	break; }
	case s535_AtomicType_F32: {
	return 32l;
	break; }
	case s535_AtomicType_F64: {
	return 64l;
	break; }
	default:
		abort();
}
}


#line 342 "src/typecheck/cast.ib"
void s1112_debug(s299_StringBuilder * v1_sb, s846_Nodes * v2_nodes, s1113_Cast * v3_cast, i64 v4_depth) {
	#line 343
	s288_repeat(v1_sb, "  ", v4_depth);
	#line 344
	s283_append(v1_sb, "CAST Method: ");
	#line 345
	switch (((*v3_cast).method)) {
	case s1115_CastMethod_Keep: {
	s283_append(v1_sb, "Keep");
	break; }
	case s1115_CastMethod_Truncate: {
	s283_append(v1_sb, "Truncate");
	break; }
	case s1115_CastMethod_Extend: {
	s283_append(v1_sb, "Extend");
	break; }
	case s1115_CastMethod_FloatToInt: {
	s283_append(v1_sb, "FloatToInt");
	break; }
	case s1115_CastMethod_IntToFloat: {
	s283_append(v1_sb, "IntToFloat");
	break; }
	case s1115_CastMethod_ArrayDecay: {
	s283_append(v1_sb, "ArrayDecay");
	break; }
	case s1115_CastMethod_Deref: {
	s283_append(v1_sb, "Deref");
	break; }
	default:
		abort();
}
	#line 354
	s283_append(v1_sb, "\n");
	#line 355
	s842_debug(v1_sb, v2_nodes, ((*v3_cast).expr), (v4_depth + 1l));
	#line 356
	s288_repeat(v1_sb, "  ", (v4_depth + 1l));
	#line 357
	s283_append(v1_sb, "CAST_INTO ");
	#line 358
	s524_debug(v1_sb, v2_nodes, ((*v3_cast).into), (v4_depth + 1l));
	#line 359
	s283_append(v1_sb, "\n");
}


#line 14 "src/codegen/statement.ib"
void s1116_semicolon(s1028_FunctionContext * v1_context) {
	#line 15
	if (((*v1_context).disable_semicolon)) {
		#line 15
		return;
	}
	#line 16
	if (s280_ends_with_char((&((*((*v1_context).parent)).sb)), 59u)) {
		#line 16
		return;
	}
	#line 17
	if (s280_ends_with_char((&((*((*v1_context).parent)).sb)), 32u)) {
		#line 17
		return;
	}
	#line 18
	s283_append((&((*((*v1_context).parent)).sb)), ";\n");
}


#line 21 "src/codegen/statement.ib"
void s1117_block(s1028_FunctionContext * v1_context, s1017_BlockData * v2_data) {
	#line 23
	((*v1_context).depth) += 1l;
	#line 24
	for (i64 v3_i = 0l;(v3_i < ((*v2_data).count));v3_i += 1l) {
		#line 25
		i64 v4_n = (((*v2_data).nodes)[v3_i]);
		#line 26
		s844_Node * v5_node_data = s836_get((&((*((*v1_context).module)).nodes)), v4_n);
		#line 27
		s1025_indent(v1_context);
		#line 28
		s364_sourcemap_line(((*v1_context).parent), ((*v5_node_data).span));
		#line 29
		bool v6_was_expr = s1027_is_expr(v1_context, v4_n);
		#line 30
		if (v6_was_expr) {
			#line 30
			s1025_indent(v1_context);
		}
		#line 31
		s1024_codegen(v1_context, (((*v2_data).nodes)[v3_i]));
		#line 32
		if (v6_was_expr) {
			#line 32
			s1116_semicolon(v1_context);
		}
	}
	loop_exit_1:
	#line 34
	((*v1_context).depth) -= 1l;
}


#line 37 "src/codegen/statement.ib"
void s1118_vardecl(s1028_FunctionContext * v1_context, s1018_VarDeclaration * v2_data) {
	#line 38
	s1025_indent(v1_context);
	#line 39
	s1026_variable((&((*((*v1_context).parent)).work_sb)), ((*v2_data).var_id), ((*v2_data).ident));
	#line 40
	char * v3_ident = s294_merge((&((*((*v1_context).parent)).work_sb)));
	#line 41
	s790_codegen_field(((*v1_context).parent), ((*v2_data).type), v3_ident);
	#line 42
	s295_reset((&((*((*v1_context).parent)).work_sb)));
	#line 43
	s283_append((&((*((*v1_context).parent)).sb)), " = ");
	#line 44
	s1024_codegen(v1_context, ((*v2_data).value));
	#line 45
	s1116_semicolon(v1_context);
}


#line 48 "src/codegen/statement.ib"
void s1119__break(s1028_FunctionContext * v1_context) {
	#line 49
	s1025_indent(v1_context);
	#line 51
	s1025_indent(v1_context);
	#line 52
	s283_append((&((*((*v1_context).parent)).sb)), "goto ");
	#line 53
	s1126_top_loop_label(v1_context);
	#line 54
	s1116_semicolon(v1_context);
	#line 55
	s362_comment(((*v1_context).parent), "break;");
}


#line 59 "src/codegen/statement.ib"
void s1120__continue(s1028_FunctionContext * v1_context) {
	#line 61
	s1025_indent(v1_context);
	#line 62
	s283_append((&((*((*v1_context).parent)).sb)), "continue");
	#line 63
	s1116_semicolon(v1_context);
}


#line 67 "src/codegen/statement.ib"
void s1121__return(s1028_FunctionContext * v1_context, s1019_ReturnData * v2_data) {
	#line 68
	s1025_indent(v1_context);
	#line 69
	if ((!((*v2_data).has_value))) {
		#line 70
		s283_append((&((*((*v1_context).parent)).sb)), "return");
		#line 71
		s1116_semicolon(v1_context);
		#line 72
		return;
	}
	#line 74
	s283_append((&((*((*v1_context).parent)).sb)), "return ");
	#line 75
	s1024_codegen(v1_context, ((*v2_data).value));
	#line 76
	s1116_semicolon(v1_context);
}


#line 80 "src/codegen/statement.ib"
void s1122__if(s1028_FunctionContext * v1_context, s1016_IfData * v2_data) {
	#line 81
	s1025_indent(v1_context);
	#line 82
	s283_append((&((*((*v1_context).parent)).sb)), "if (");
	#line 83
	s1024_codegen(v1_context, ((*v2_data).cond));
	#line 84
	s283_append((&((*((*v1_context).parent)).sb)), ") {\n");
	#line 85
	s1024_codegen(v1_context, ((*v2_data).then));
	#line 86
	if ((((*v2_data).otherwise) != s825_NONE)) {
		#line 87
		s1025_indent(v1_context);
		#line 88
		s284_append_char((&((*((*v1_context).parent)).sb)), 125u);
		#line 89
		s283_append((&((*((*v1_context).parent)).sb)), " else ");
		#line 90
		((*v1_context).disable_next_indent) = true;
		#line 91
		if ((s1023_nodekind(v1_context, ((*v2_data).otherwise)) == s848_NodeKind_If)) {
			#line 92
			s1024_codegen(v1_context, ((*v2_data).otherwise));
		} else {
#line 94
			s283_append((&((*((*v1_context).parent)).sb)), "{\n");
			#line 95
			s1024_codegen(v1_context, ((*v2_data).otherwise));
			#line 96
			s1025_indent(v1_context);
			#line 97
			s283_append((&((*((*v1_context).parent)).sb)), "}\n");
		}
		#line 99
		((*v1_context).disable_next_indent) = false;
	} else {
#line 101
		s1025_indent(v1_context);
		#line 102
		s284_append_char((&((*((*v1_context).parent)).sb)), 125u);
		#line 103
		s284_append_char((&((*((*v1_context).parent)).sb)), 10u);
	}
}


#line 108 "src/codegen/statement.ib"
void s1123__match(s1028_FunctionContext * v1_context, s1072_MatchData * v2_data) {
	#line 109
	s1025_indent(v1_context);
	#line 110
	s283_append((&((*((*v1_context).parent)).sb)), "switch (");
	#line 111
	s1024_codegen(v1_context, ((*v2_data).cond));
	#line 112
	s283_append((&((*((*v1_context).parent)).sb)), ") {\n");
	#line 113
	bool v3_had_default = false;
	#line 114
	for (i64 v4_i = 0l;(v4_i < ((*v2_data).count));v4_i += 1l) {
		#line 115
		if (((((*v2_data).cases)[v4_i]).has_default)) {
			#line 116
			v3_had_default = true;
			#line 117
			s1025_indent(v1_context);
			#line 118
			s283_append((&((*((*v1_context).parent)).sb)), "default:\n");
		}
		#line 120
		for (i64 v5_j = 0l;(v5_j < ((((*v2_data).cases)[v4_i]).cond_count));v5_j += 1l) {
			#line 121
			if ((v5_j > 0l)) {
				#line 121
				s284_append_char((&((*((*v1_context).parent)).sb)), 10u);
			}
			#line 122
			s1025_indent(v1_context);
			#line 123
			s283_append((&((*((*v1_context).parent)).sb)), "case ");
			#line 124
			s1024_codegen(v1_context, (((((*v2_data).cases)[v4_i]).conds)[v5_j]));
			#line 125
			s284_append_char((&((*((*v1_context).parent)).sb)), 58u);
		}
		loop_exit_2:
		#line 127
		s283_append((&((*((*v1_context).parent)).sb)), " {\n");
		#line 129
		if (s1027_is_expr(v1_context, ((((*v2_data).cases)[v4_i]).arm))) {
			#line 131
			s1025_indent(v1_context);
			#line 132
			((*v1_context).disable_next_indent) = true;
		}
		#line 134
		s1024_codegen(v1_context, ((((*v2_data).cases)[v4_i]).arm));
		#line 135
		if (s1027_is_expr(v1_context, ((((*v2_data).cases)[v4_i]).arm))) {
			#line 136
			s1116_semicolon(v1_context);
		}
		#line 138
		((*v1_context).disable_next_indent) = false;
		#line 139
		s1025_indent(v1_context);
		#line 140
		s283_append((&((*((*v1_context).parent)).sb)), "break; }\n");
		#line 141
		if (s1027_is_expr(v1_context, ((((*v2_data).cases)[v4_i]).arm))) {
		}
	}
	loop_exit_1:
	#line 145
	if ((!v3_had_default)) {
		#line 146
		s1025_indent(v1_context);
		#line 147
		s283_append((&((*((*v1_context).parent)).sb)), "default:\n");
		#line 148
		s1025_indent(v1_context);
		#line 150
		s283_append((&((*((*v1_context).parent)).sb)), "\tabort();\n");
	}
	#line 152
	s283_append((&((*((*v1_context).parent)).sb)), "}\n");
}


#line 156 "src/codegen/statement.ib"
void s1124__loop(s1028_FunctionContext * v1_context, s1015_LoopData * v2_data) {
	#line 157
	s1025_indent(v1_context);
	#line 158
	s283_append((&((*((*v1_context).parent)).sb)), "while (");
	#line 159
	if (((*v2_data).has_cond)) {
		#line 160
		s1024_codegen(v1_context, ((*v2_data).cond));
	} else {
#line 162
		s284_append_char((&((*((*v1_context).parent)).sb)), 49u);
	}
	#line 164
	i64 v3_loop_id = s1128_push_loop(v1_context);
	#line 166
	s283_append((&((*((*v1_context).parent)).sb)), ") {\n");
	#line 167
	s1024_codegen(v1_context, ((*v2_data).body));
	#line 168
	s283_append((&((*((*v1_context).parent)).sb)), "}\n");
	#line 170
	s1129_pop_loop(v1_context, v3_loop_id);
	#line 171
	s1025_indent(v1_context);
	#line 172
	s1127_loop_label(v1_context, v3_loop_id);
	#line 173
	s283_append((&((*((*v1_context).parent)).sb)), ":\n");
}


#line 177 "src/codegen/statement.ib"
void s1125__for(s1028_FunctionContext * v1_context, s1014_ForData * v2_data) {
	#line 178
	s1025_indent(v1_context);
	#line 179
	s283_append((&((*((*v1_context).parent)).sb)), "for (");
	#line 180
	((*v1_context).disable_semicolon) = true;
	#line 181
	((*v1_context).disable_next_indent) = true;
	#line 183
	s1024_codegen(v1_context, ((*v2_data).init));
	#line 184
	s284_append_char((&((*((*v1_context).parent)).sb)), 59u);
	#line 185
	s1024_codegen(v1_context, ((*v2_data).cond));
	#line 186
	s284_append_char((&((*((*v1_context).parent)).sb)), 59u);
	#line 187
	s1024_codegen(v1_context, ((*v2_data).acc));
	#line 189
	i64 v3_loop_id = s1128_push_loop(v1_context);
	#line 190
	((*v1_context).disable_semicolon) = false;
	#line 191
	s283_append((&((*((*v1_context).parent)).sb)), ") {\n");
	#line 192
	s1024_codegen(v1_context, ((*v2_data).body));
	#line 193
	s1025_indent(v1_context);
	#line 194
	s283_append((&((*((*v1_context).parent)).sb)), "}\n");
	#line 196
	s1129_pop_loop(v1_context, v3_loop_id);
	#line 197
	s1025_indent(v1_context);
	#line 198
	s1127_loop_label(v1_context, v3_loop_id);
	#line 199
	s283_append((&((*((*v1_context).parent)).sb)), ":\n");
}


#line 202 "src/codegen/statement.ib"
void s1126_top_loop_label(s1028_FunctionContext * v1_context) {
	#line 203
	i64 * v2_last = ((i64 *)s252_last((&((*v1_context).loop_ids))));
	#line 204
	s1127_loop_label(v1_context, (*v2_last));
}


#line 207 "src/codegen/statement.ib"
void s1127_loop_label(s1028_FunctionContext * v1_context, i64 v2_id) {
	#line 208
	s283_append((&((*((*v1_context).parent)).sb)), "loop_exit_");
	#line 209
	s289_append_number((&((*((*v1_context).parent)).sb)), v2_id);
}


#line 213 "src/codegen/statement.ib"
i64 s1128_push_loop(s1028_FunctionContext * v1_context) {
	#line 214
	i64 v2_id = ((*v1_context).next_loop_id);
	#line 215
	((*v1_context).next_loop_id) += 1l;
	#line 216
	i64 * v3_stored = ((i64 *)s249_push((&((*v1_context).loop_ids))));
	#line 217
	(*v3_stored) = v2_id;
	#line 218
	return v2_id;
}


#line 222 "src/codegen/statement.ib"
void s1129_pop_loop(s1028_FunctionContext * v1_context, i64 v2_id) {
	#line 223
	i64 * v3_last = ((i64 *)s250_pop((&((*v1_context).loop_ids))));
	#line 224
	s40_assert(((*v3_last) == v2_id), "Did not pop expected loop id");
}


#line 10 "src/codegen/binary.ib"
void s1130_binary(s1028_FunctionContext * v1_context, s1039_Binary * v2_data) {
	#line 11
	s284_append_char((&((*((*v1_context).parent)).sb)), 40u);
	#line 12
	s1024_codegen(v1_context, ((*v2_data).lhs));
	#line 13
	s1131_binary_op(v1_context, ((*v2_data).op));
	#line 14
	s1024_codegen(v1_context, ((*v2_data).rhs));
	#line 15
	s284_append_char((&((*((*v1_context).parent)).sb)), 41u);
}


#line 19 "src/codegen/binary.ib"
void s1131_binary_op(s1028_FunctionContext * v1_context, s1041_BinaryOp v2_op) {
	#line 20
	switch (v2_op) {
	case s1041_BinaryOp_Add: {
	s283_append((&((*((*v1_context).parent)).sb)), " + ");
	break; }
	case s1041_BinaryOp_Sub: {
	s283_append((&((*((*v1_context).parent)).sb)), " - ");
	break; }
	case s1041_BinaryOp_Mul: {
	s283_append((&((*((*v1_context).parent)).sb)), " * ");
	break; }
	case s1041_BinaryOp_Div: {
	s283_append((&((*((*v1_context).parent)).sb)), " / ");
	break; }
	case s1041_BinaryOp_Rem: {
	s283_append((&((*((*v1_context).parent)).sb)), " % ");
	break; }
	case s1041_BinaryOp_EQ: {
	s283_append((&((*((*v1_context).parent)).sb)), " == ");
	break; }
	case s1041_BinaryOp_NE: {
	s283_append((&((*((*v1_context).parent)).sb)), " != ");
	break; }
	case s1041_BinaryOp_GT: {
	s283_append((&((*((*v1_context).parent)).sb)), " > ");
	break; }
	case s1041_BinaryOp_GE: {
	s283_append((&((*((*v1_context).parent)).sb)), " >= ");
	break; }
	case s1041_BinaryOp_LT: {
	s283_append((&((*((*v1_context).parent)).sb)), " < ");
	break; }
	case s1041_BinaryOp_LE: {
	s283_append((&((*((*v1_context).parent)).sb)), " <= ");
	break; }
	case s1041_BinaryOp_And: {
	s283_append((&((*((*v1_context).parent)).sb)), " && ");
	break; }
	case s1041_BinaryOp_Or: {
	s283_append((&((*((*v1_context).parent)).sb)), " || ");
	break; }
	case s1041_BinaryOp_BitAnd: {
	s283_append((&((*((*v1_context).parent)).sb)), " & ");
	break; }
	case s1041_BinaryOp_BitOr: {
	s283_append((&((*((*v1_context).parent)).sb)), " | ");
	break; }
	case s1041_BinaryOp_BitXor: {
	s283_append((&((*((*v1_context).parent)).sb)), " ^ ");
	break; }
	case s1041_BinaryOp_BitShiftRight: {
	s283_append((&((*((*v1_context).parent)).sb)), " >> ");
	break; }
	case s1041_BinaryOp_BitShiftLeft: {
	s283_append((&((*((*v1_context).parent)).sb)), " << ");
	break; }
	default:
		abort();
}
}


#line 43 "src/codegen/binary.ib"
void s1132_assign(s1028_FunctionContext * v1_context, s1040_Assign * v2_data) {
	#line 44
	s1024_codegen(v1_context, ((*v2_data).target));
	#line 45
	s1133_assign_op(v1_context, ((*v2_data).op));
	#line 46
	s1024_codegen(v1_context, ((*v2_data).value));
}


#line 50 "src/codegen/binary.ib"
void s1133_assign_op(s1028_FunctionContext * v1_context, s1042_AssignOp v2_op) {
	#line 51
	switch (v2_op) {
	case s1042_AssignOp_None: {
	s283_append((&((*((*v1_context).parent)).sb)), " = ");
	break; }
	case s1042_AssignOp_Add: {
	s283_append((&((*((*v1_context).parent)).sb)), " += ");
	break; }
	case s1042_AssignOp_Sub: {
	s283_append((&((*((*v1_context).parent)).sb)), " -= ");
	break; }
	case s1042_AssignOp_Mul: {
	s283_append((&((*((*v1_context).parent)).sb)), " *= ");
	break; }
	case s1042_AssignOp_Div: {
	s283_append((&((*((*v1_context).parent)).sb)), " /= ");
	break; }
	case s1042_AssignOp_Rem: {
	s283_append((&((*((*v1_context).parent)).sb)), " %= ");
	break; }
	default:
		abort();
}
}


#line 11 "src/codegen/unary.ib"
void s1134_unary(s1028_FunctionContext * v1_context, s1051_Unary * v2_data) {
	#line 12
	s284_append_char((&((*((*v1_context).parent)).sb)), 40u);
	#line 13
	s1135_unary_op(v1_context, ((*v2_data).op));
	#line 14
	s1024_codegen(v1_context, ((*v2_data).expr));
	#line 15
	s284_append_char((&((*((*v1_context).parent)).sb)), 41u);
}


#line 19 "src/codegen/unary.ib"
void s1135_unary_op(s1028_FunctionContext * v1_context, s1052_UnaryOp v2_op) {
	#line 20
	switch (v2_op) {
	case s1052_UnaryOp_Group: {
	break; }
	case s1052_UnaryOp_Pos: {
	s284_append_char((&((*((*v1_context).parent)).sb)), 43u);
	break; }
	case s1052_UnaryOp_Neg: {
	s284_append_char((&((*((*v1_context).parent)).sb)), 45u);
	break; }
	case s1052_UnaryOp_Not: {
	s284_append_char((&((*((*v1_context).parent)).sb)), 33u);
	break; }
	case s1052_UnaryOp_BitNot: {
	s284_append_char((&((*((*v1_context).parent)).sb)), 126u);
	break; }
	default:
		abort();
}
}


#line 10 "src/codegen/literal.ib"
void s1136_codegen(s1028_FunctionContext * v1_context, s857_Literal * v2_data) {
	#line 11
	switch (((*v2_data).kind)) {
	case s859_LiteralKind_Bool: {
		#line 13
		if ((((*v2_data).value).boolean)) {
			#line 14
			s283_append((&((*((*v1_context).parent)).sb)), "true");
		} else {
#line 16
			s283_append((&((*((*v1_context).parent)).sb)), "false");
		}
	break; }
	case s859_LiteralKind_Null: {
		#line 20
		s283_append((&((*((*v1_context).parent)).sb)), "NULL");
	break; }
	case s859_LiteralKind_U8:
	case s859_LiteralKind_I8: {
	s289_append_number((&((*((*v1_context).parent)).sb)), ((i64)(((*v2_data).value).chr)));
	break; }
	case s859_LiteralKind_U16:
	case s859_LiteralKind_U32:
	case s859_LiteralKind_U64:
	case s859_LiteralKind_U128:
	case s859_LiteralKind_I16:
	case s859_LiteralKind_I32:
	case s859_LiteralKind_I64:
	case s859_LiteralKind_I128: {
		#line 34
		s289_append_number((&((*((*v1_context).parent)).sb)), (((*v2_data).value).number));
	break; }
	case s859_LiteralKind_F32:
	case s859_LiteralKind_F64: {
		#line 39
		s291_append_float((&((*((*v1_context).parent)).sb)), (((*v2_data).value).flt), 12l);
	break; }
	case s859_LiteralKind_String: {
		#line 43
		s284_append_char((&((*((*v1_context).parent)).sb)), 34u);
		#line 45
		s281_append_escaped_str((&((*((*v1_context).parent)).sb)), (((*v2_data).value).string));
		#line 46
		s284_append_char((&((*((*v1_context).parent)).sb)), 34u);
	break; }
	default:
		abort();
}
	#line 49
	s1137_suffix(v1_context, ((*v2_data).kind));
}


#line 53 "src/codegen/literal.ib"
void s1137_suffix(s1028_FunctionContext * v1_context, s859_LiteralKind v2_kind) {
	#line 54
	switch (v2_kind) {
	case s859_LiteralKind_F32:
	case s859_LiteralKind_F64:
	case s859_LiteralKind_Bool:
	case s859_LiteralKind_String:
	case s859_LiteralKind_I8:
	case s859_LiteralKind_I16:
	case s859_LiteralKind_I32:
	case s859_LiteralKind_Null: {
	break; }
	case s859_LiteralKind_U8: {
	s283_append((&((*((*v1_context).parent)).sb)), "u");
	break; }
	case s859_LiteralKind_U16: {
	s283_append((&((*((*v1_context).parent)).sb)), "u");
	break; }
	case s859_LiteralKind_U32: {
	s283_append((&((*((*v1_context).parent)).sb)), "u");
	break; }
	case s859_LiteralKind_U64: {
	s283_append((&((*((*v1_context).parent)).sb)), "ul");
	break; }
	case s859_LiteralKind_U128: {
	s283_append((&((*((*v1_context).parent)).sb)), "ull");
	break; }
	case s859_LiteralKind_I64: {
	s283_append((&((*((*v1_context).parent)).sb)), "l");
	break; }
	case s859_LiteralKind_I128: {
	s283_append((&((*((*v1_context).parent)).sb)), "ll");
	break; }
	default:
		abort();
}
}


#line 16 "src/codegen/expr.ib"
void s1138_variable(s1028_FunctionContext * v1_context, s1065_Variable * v2_data) {
	#line 17
	s1026_variable((&((*((*v1_context).parent)).sb)), ((*v2_data).id), ((*v2_data).ident));
}


#line 21 "src/codegen/expr.ib"
void s1139_cast(s1028_FunctionContext * v1_context, s1113_Cast * v2_data) {
	#line 22
	s284_append_char((&((*((*v1_context).parent)).sb)), 40u);
	#line 23
	s284_append_char((&((*((*v1_context).parent)).sb)), 40u);
	#line 24
	s791_codegen(((*v1_context).parent), ((*v2_data).into));
	#line 25
	s284_append_char((&((*((*v1_context).parent)).sb)), 41u);
	#line 26
	s1024_codegen(v1_context, ((*v2_data).expr));
	#line 27
	s284_append_char((&((*((*v1_context).parent)).sb)), 41u);
}


#line 31 "src/codegen/expr.ib"
void s1140_array(s1028_FunctionContext * v1_context, s1083_Array * v2_data) {
	#line 32
	s284_append_char((&((*((*v1_context).parent)).sb)), 123u);
	#line 33
	for (i64 v3_i = 0l;(v3_i < ((*v2_data).count));v3_i += 1l) {
		#line 34
		if ((v3_i > 0l)) {
			#line 34
			s283_append((&((*((*v1_context).parent)).sb)), ", ");
		}
		#line 35
		s1024_codegen(v1_context, (((*v2_data).elems)[v3_i]));
	}
	loop_exit_1:
	#line 37
	s284_append_char((&((*((*v1_context).parent)).sb)), 125u);
}


#line 41 "src/codegen/expr.ib"
void s1141_index(s1028_FunctionContext * v1_context, s1084_Index * v2_data) {
	#line 42
	s284_append_char((&((*((*v1_context).parent)).sb)), 40u);
	#line 43
	s1024_codegen(v1_context, ((*v2_data).array));
	#line 44
	s284_append_char((&((*((*v1_context).parent)).sb)), 91u);
	#line 45
	s1024_codegen(v1_context, ((*v2_data).index));
	#line 46
	s284_append_char((&((*((*v1_context).parent)).sb)), 93u);
	#line 47
	s284_append_char((&((*((*v1_context).parent)).sb)), 41u);
}


#line 51 "src/codegen/expr.ib"
void s1142_objectinit(s1028_FunctionContext * v1_context, s1096_ObjectInit * v2_data) {
	#line 52
	s283_append((&((*((*v1_context).parent)).sb)), "((");
	#line 53
	s365_codegen_symbol((&((*((*v1_context).parent)).sb)), ((*v2_data).type));
	#line 54
	s283_append((&((*((*v1_context).parent)).sb)), "){\n");
	#line 55
	((*v1_context).depth) += 1l;
	#line 56
	for (i64 v3_i = 0l;(v3_i < ((*v2_data).field_count));v3_i += 1l) {
		#line 57
		if ((v3_i > 0l)) {
			#line 57
			s283_append((&((*((*v1_context).parent)).sb)), ",\n");
		}
		#line 58
		s1025_indent(v1_context);
		#line 59
		s284_append_char((&((*((*v1_context).parent)).sb)), 46u);
		#line 60
		s283_append((&((*((*v1_context).parent)).sb)), ((((*v2_data).fields)[v3_i]).field));
		#line 61
		s283_append((&((*((*v1_context).parent)).sb)), " = ");
		#line 62
		s1024_codegen(v1_context, ((((*v2_data).fields)[v3_i]).value));
	}
	loop_exit_1:
	#line 64
	((*v1_context).depth) -= 1l;
	#line 65
	s284_append_char((&((*((*v1_context).parent)).sb)), 10u);
	#line 66
	s1025_indent(v1_context);
	#line 67
	s284_append_char((&((*((*v1_context).parent)).sb)), 125u);
	#line 68
	s284_append_char((&((*((*v1_context).parent)).sb)), 41u);
}


#line 72 "src/codegen/expr.ib"
void s1143_fieldlookup(s1028_FunctionContext * v1_context, s1098_FieldLookup * v2_data) {
	#line 73
	s284_append_char((&((*((*v1_context).parent)).sb)), 40u);
	#line 74
	s1024_codegen(v1_context, ((*v2_data).object));
	#line 75
	s284_append_char((&((*((*v1_context).parent)).sb)), 46u);
	#line 76
	s283_append((&((*((*v1_context).parent)).sb)), ((*v2_data).field));
	#line 77
	s284_append_char((&((*((*v1_context).parent)).sb)), 41u);
}


#line 81 "src/codegen/expr.ib"
void s1144_enumvalue(s1028_FunctionContext * v1_context, s1066_EnumValue * v2_data) {
	#line 82
	s189_assert_kind(((*v2_data).symbol), s544_SymbolKind_Enum, "EnumValue was not enum!");
	#line 83
	s766_EnumDef * v3_enum_def = (s183_get_deep(((*v2_data).symbol)).enum_def);
	#line 84
	s788_variant(((*v1_context).parent), ((*v2_data).symbol), (&(((*v3_enum_def).fields)[((*v2_data).field_idx)])));
}


#line 91 "src/codegen/expr.ib"
void s1145_call(s1028_FunctionContext * v1_context, s1064_Call * v2_data) {
	#line 93
	s1024_codegen(v1_context, ((*v2_data).callee));
	#line 94
	s284_append_char((&((*((*v1_context).parent)).sb)), 40u);
	#line 95
	for (i64 v3_i = 0l;(v3_i < ((*v2_data).arg_count));v3_i += 1l) {
		#line 96
		if ((v3_i > 0l)) {
			#line 96
			s283_append((&((*((*v1_context).parent)).sb)), ", ");
		}
		#line 97
		s1024_codegen(v1_context, (((*v2_data).args)[v3_i]));
	}
	loop_exit_1:
	#line 99
	s284_append_char((&((*((*v1_context).parent)).sb)), 41u);
}


#line 103 "src/codegen/expr.ib"
void s1146_ref(s1028_FunctionContext * v1_context, i64 v2_data) {
	#line 104
	s284_append_char((&((*((*v1_context).parent)).sb)), 40u);
	#line 105
	s284_append_char((&((*((*v1_context).parent)).sb)), 38u);
	#line 106
	s1024_codegen(v1_context, v2_data);
	#line 107
	s284_append_char((&((*((*v1_context).parent)).sb)), 41u);
}


#line 111 "src/codegen/expr.ib"
void s1147_deref(s1028_FunctionContext * v1_context, i64 v2_data) {
	#line 112
	s284_append_char((&((*((*v1_context).parent)).sb)), 40u);
	#line 113
	s284_append_char((&((*((*v1_context).parent)).sb)), 42u);
	#line 114
	s1024_codegen(v1_context, v2_data);
	#line 115
	s284_append_char((&((*((*v1_context).parent)).sb)), 41u);
}


#line 19 "src/typecheck/path.ib"
i64 s1148_typecheck(s743_FunctionContext * v1_context, s893_Binary v2_data, i64 v3_span) {
	#line 24
	if ((((v2_data.lhs) == s674_ERROR) || ((v2_data.rhs) == s674_ERROR))) {
		#line 24
		return s826_ERROR;
	}
	#line 25
	i64 v4_lhs = s1149_recursive_path(v1_context, (v2_data.lhs), v3_span);
	#line 26
	if ((v4_lhs == s826_ERROR)) {
		#line 26
		return s826_ERROR;
	}
	#line 28
	s845_NodeResult v5_node_res = s827_typecheck(v1_context, (v2_data.rhs));
	#line 29
	return (v5_node_res.node);
}


#line 33 "src/typecheck/path.ib"
i64 s1149_recursive_path(s743_FunctionContext * v1_context, i64 v2_node, i64 v3_span) {
	#line 38
	s587_Node * v4_node = s578_get((&((*((*v1_context).module)).nodes)), v2_node);
	#line 39
	switch (((*v4_node).kind)) {
	case s589_NodeKind_Ident: {
		#line 41
		char * * v5_path = ((char * *)s249_push((&((*v1_context).path_stack))));
		#line 42
		(*v5_path) = (((*v4_node).data).ident);
	break; }
	case s589_NodeKind_Binary: {
		#line 45
		s893_Binary * v6_binary = (&(((*v4_node).data).binary));
		#line 46
		if ((((*v6_binary).op) != s897_BinaryOp_Path)) {
			#line 47
			return s774_error(((*v1_context).parent), s781_ErrorKind_InvalidPathElement, v3_span);
		}
		#line 49
		s587_Node * v7_rhs_data = s578_get((&((*((*v1_context).module)).nodes)), ((*v6_binary).rhs));
		#line 50
		if ((((*v7_rhs_data).kind) != s589_NodeKind_Ident)) {
			#line 51
			return s774_error(((*v1_context).parent), s781_ErrorKind_InvalidPathElement, ((*v7_rhs_data).span));
		}
		#line 53
		s587_Node * v8_lhs_data = s578_get((&((*((*v1_context).module)).nodes)), ((*v6_binary).lhs));
		#line 54
		i64 v9_lhs = s1149_recursive_path(v1_context, ((*v6_binary).lhs), ((*v8_lhs_data).span));
		#line 55
		if ((v9_lhs == s826_ERROR)) {
			#line 55
			return s826_ERROR;
		}
		#line 57
		char * * v10_node = ((char * *)s249_push((&((*v1_context).path_stack))));
		#line 58
		(*v10_node) = (((*v7_rhs_data).data).ident);
	break; }
	default:
 {
		#line 60
		return s774_error(((*v1_context).parent), s781_ErrorKind_InvalidPathElement, v3_span);
	break; }
}
	#line 62
	return s825_NONE;
}


#line 66 "src/typecheck/path.ib"
s201_UID s1150_resolve_path_symbol(s743_FunctionContext * v1_context, char * v2_ident, i64 v3_span) {
	#line 67
	if (((((*v1_context).path_stack).count) > 0l)) {
		#line 68
		s1153_PathStackResult v4_res = s1152_resolve_path_stack(v1_context, v2_ident, v3_span);
		#line 69
		if ((v4_res.skipped_ident)) {
			#line 70
			s774_error(((*v1_context).parent), s781_ErrorKind_GotEnumVariantWhenSymbolWasExpected, v3_span);
			#line 75
			return s168_NONE;
		}
		#line 77
		return (v4_res.symbol);
	}
	#line 79
	s556_IdentResult v5_res = s550_identifier(((*((*v1_context).module)).uid), v2_ident);
	#line 81
	switch ((v5_res.kind)) {
	case s558_IdentResultKind_Found: {
	break; }
	case s558_IdentResultKind_ErrFoundMultiple: {
	s774_error(((*v1_context).parent), s781_ErrorKind_IdentFoundMultiple, v3_span);
	break; }
	case s558_IdentResultKind_ErrSymbolNotFound: {
	s774_error(((*v1_context).parent), s781_ErrorKind_IdentSymbolNotFound, v3_span);
	break; }
	case s558_IdentResultKind_ErrSymbolWasPrivate: {
	s774_error(((*v1_context).parent), s781_ErrorKind_IdentSymbolWasPrivate, v3_span);
	break; }
	case s558_IdentResultKind_ErrFoundMultiplePrivate: {
	s774_error(((*v1_context).parent), s781_ErrorKind_IdentFoundMultiplePrivate, v3_span);
	break; }
	default:
		abort();
}
	#line 92
	return (v5_res.symbol);
}


#line 96 "src/typecheck/path.ib"
i64 s1151_resolve_path_node(s743_FunctionContext * v1_context, char * v2_ident, i64 v3_span) {
	#line 97
	if (((((*v1_context).path_stack).count) > 0l)) {
		#line 98
		s1153_PathStackResult v4_res = s1152_resolve_path_stack(v1_context, v2_ident, v3_span);
		#line 99
		if (s170_is_none((v4_res.symbol))) {
			#line 99
			return s826_ERROR;
		}
		#line 100
		s201_UID v5_symbol = (v4_res.symbol);
		#line 101
		if ((v4_res.skipped_ident)) {
			#line 102
			s544_SymbolKind v6_kind = s190_kind(v5_symbol);
			#line 103
			if ((v6_kind != s544_SymbolKind_Enum)) {
				#line 104
				return s774_error(((*v1_context).parent), s781_ErrorKind_PathEnumExpected, v3_span);
			}
			#line 106
			s542_DeepInfo v7_deep = s183_get_deep(v5_symbol);
			#line 107
			s766_EnumDef * v8_enum_def = (v7_deep.enum_def);
			#line 108
			i64 v9_field_idx = s759_field_idx(v8_enum_def, v2_ident);
			#line 109
			i64 v10_value = ((((*v8_enum_def).fields)[v9_field_idx]).value);
			#line 110
			s40_assert((v9_field_idx >= 0l), "field_idx not found!");
			#line 111
			s1066_EnumValue v11_enum_val = ((s1066_EnumValue){
				.symbol = v5_symbol,
				.field_idx = v9_field_idx,
				.value = v10_value
			});
			#line 112
			return s839_push(((*v1_context).nodes), s848_NodeKind_EnumValue, s186_get_type(v5_symbol), ((s847_NodeData){
				.enum_val = v11_enum_val
			}), v3_span);
		} else {
#line 117
			return s839_push(((*v1_context).nodes), s848_NodeKind_Symbol, s186_get_type(v5_symbol), ((s847_NodeData){
				.symbol = v5_symbol
			}), v3_span);
		}
	}
	#line 123
	s556_IdentResult v12_res = s550_identifier(((*((*v1_context).module)).uid), v2_ident);
	#line 124
	s201_UID v13_symbol = (v12_res.symbol);
	#line 126
	switch ((v12_res.kind)) {
	case s558_IdentResultKind_Found: {
	return s839_push(((*v1_context).nodes), s848_NodeKind_Symbol, s186_get_type(v13_symbol), ((s847_NodeData){
		.symbol = v13_symbol
	}), v3_span);
	break; }
	case s558_IdentResultKind_ErrSymbolNotFound: {
	return s825_NONE;
	break; }
	case s558_IdentResultKind_ErrFoundMultiple: {
	return s774_error(((*v1_context).parent), s781_ErrorKind_IdentFoundMultiple, v3_span);
	break; }
	case s558_IdentResultKind_ErrSymbolWasPrivate: {
	return s774_error(((*v1_context).parent), s781_ErrorKind_IdentSymbolWasPrivate, v3_span);
	break; }
	case s558_IdentResultKind_ErrFoundMultiplePrivate: {
	return s774_error(((*v1_context).parent), s781_ErrorKind_IdentFoundMultiplePrivate, v3_span);
	break; }
	default:
		abort();
}
	#line 141
	return s825_NONE;
}


#line 148 "src/typecheck/path.ib"
s1153_PathStackResult s1152_resolve_path_stack(s743_FunctionContext * v1_context, char * v2_ident, i64 v3_span) {
	#line 153
	char * * v4_node = ((char * *)s249_push((&((*v1_context).path_stack))));
	#line 154
	(*v4_node) = v2_ident;
	#line 155
	s554_PathResult v5_result = s545_path(((*((*v1_context).module)).uid), ((char * *)s251_get((&((*v1_context).path_stack)), 0l)), (((*v1_context).path_stack).count));
	#line 160
	s201_UID v6_symbol = (v5_result.symbol);
	#line 162
	s248_clear((&((*v1_context).path_stack)));
	#line 163
	switch ((v5_result.kind)) {
	case s557_PathResultKind_Found: {
	return ((s1153_PathStackResult){
		.symbol = v6_symbol,
		.skipped_ident = false
	});
	break; }
	case s557_PathResultKind_SkippedName: {
	return ((s1153_PathStackResult){
		.symbol = v6_symbol,
		.skipped_ident = true
	});
	break; }
	case s557_PathResultKind_ErrModuleNotFound: {
		#line 169
		s774_error(((*v1_context).parent), s781_ErrorKind_PathModuleNotFound, v3_span);
	break; }
	case s557_PathResultKind_ErrModuleWasPrivate: {
		#line 172
		s774_error(((*v1_context).parent), s781_ErrorKind_PathModuleWasPrivate, v3_span);
	break; }
	case s557_PathResultKind_ErrSymbolNotFound: {
		#line 175
		s774_error(((*v1_context).parent), s781_ErrorKind_PathSymbolNotFound, v3_span);
	break; }
	case s557_PathResultKind_ErrSymbolWasPrivate: {
		#line 178
		s774_error(((*v1_context).parent), s781_ErrorKind_PathSymbolWasPrivate, v3_span);
	break; }
	default:
		abort();
}
	#line 181
	return ((s1153_PathStackResult){
		.symbol = s168_NONE,
		.skipped_ident = false
	});
}


