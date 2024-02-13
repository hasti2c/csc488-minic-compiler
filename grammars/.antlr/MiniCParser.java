// Generated from /Users/hasti/Documents/UofT/csc488/assignments/code/grammars/MiniC.g4 by ANTLR 4.13.1

#include <vector>
#include "Program.h"
#include "Declarations.h"
#include "Statements.h"
#include "Exprs.h"
#include "Terms.h"
#include "A3Helper.h" // TODO: okay?

import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class MiniCParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, T__8=9, 
		T__9=10, T__10=11, T__11=12, T__12=13, T__13=14, T__14=15, T__15=16, T__16=17, 
		T__17=18, T__18=19, T__19=20, T__20=21, T__21=22, T__22=23, T__23=24, 
		T__24=25, T__25=26, T__26=27, T__27=28, T__28=29, T__29=30, T__30=31, 
		T__31=32, T__32=33, T__33=34, T__34=35, T__35=36, ID=37, INT=38, CHAR=39, 
		WS=40, COMMENT=41;
	public static final int
		RULE_prog = 0, RULE_preamble = 1, RULE_decl = 2, RULE_vardecl = 3, RULE_scope = 4, 
		RULE_stmtlist = 5, RULE_stmt = 6, RULE_varlist = 7, RULE_varlistentry = 8, 
		RULE_vartype = 9, RULE_rettype = 10, RULE_parameters = 11, RULE_parameterlist = 12, 
		RULE_parameterentry = 13, RULE_expropt = 14, RULE_expr = 15, RULE_var = 16, 
		RULE_arguments = 17, RULE_argumentlist = 18, RULE_varname = 19, RULE_arrayname = 20, 
		RULE_funcname = 21, RULE_parametername = 22;
	private static String[] makeRuleNames() {
		return new String[] {
			"prog", "preamble", "decl", "vardecl", "scope", "stmtlist", "stmt", "varlist", 
			"varlistentry", "vartype", "rettype", "parameters", "parameterlist", 
			"parameterentry", "expropt", "expr", "var", "arguments", "argumentlist", 
			"varname", "arrayname", "funcname", "parametername"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'#include'", "'\"minicio.h\"'", "'('", "')'", "';'", "'{'", "'}'", 
			"'if'", "'else'", "'for'", "'continue'", "'break'", "'return'", "'['", 
			"']'", "','", "'int'", "'bool'", "'char'", "'void'", "'true'", "'false'", 
			"'-'", "'!'", "'*'", "'/'", "'+'", "'=='", "'!='", "'<'", "'<='", "'>'", 
			"'>='", "'&&'", "'||'", "'='"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, "ID", "INT", "CHAR", "WS", "COMMENT"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "MiniC.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public MiniCParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ProgContext extends ParserRuleContext {
		public minicc::Program * val;
		public PreambleContext preamble;
		public DeclContext decl;
		public PreambleContext preamble() {
			return getRuleContext(PreambleContext.class,0);
		}
		public DeclContext decl() {
			return getRuleContext(DeclContext.class,0);
		}
		public ProgContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_prog; }
	}

	public final ProgContext prog() throws RecognitionException {
		ProgContext _localctx = new ProgContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_prog);
		((ProgContext)_localctx).val =  new Program();
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(46);
			((ProgContext)_localctx).preamble = preamble();
			setState(47);
			((ProgContext)_localctx).decl = decl(0);

			    _localctx.val->setSyslibFlag(((ProgContext)_localctx).preamble.flag);
			    link(_localctx.val, ((ProgContext)_localctx).decl.nodes.begin(), ((ProgContext)_localctx).decl.nodes.end());

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class PreambleContext extends ParserRuleContext {
		public bool flag;
		public PreambleContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_preamble; }
	}

	public final PreambleContext preamble() throws RecognitionException {
		PreambleContext _localctx = new PreambleContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_preamble);
		try {
			setState(54);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__0:
				enterOuterAlt(_localctx, 1);
				{
				setState(50);
				match(T__0);
				setState(51);
				match(T__1);
				_localctx.flag = true
				}
				break;
			case T__16:
			case T__17:
			case T__18:
			case T__19:
				enterOuterAlt(_localctx, 2);
				{
				_localctx.flag = false
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class DeclContext extends ParserRuleContext {
		public std::vector<Declaration*> nodes;
		public VardeclContext vardecl() {
			return getRuleContext(VardeclContext.class,0);
		}
		public RettypeContext rettype() {
			return getRuleContext(RettypeContext.class,0);
		}
		public FuncnameContext funcname() {
			return getRuleContext(FuncnameContext.class,0);
		}
		public ParametersContext parameters() {
			return getRuleContext(ParametersContext.class,0);
		}
		public ScopeContext scope() {
			return getRuleContext(ScopeContext.class,0);
		}
		public List<DeclContext> decl() {
			return getRuleContexts(DeclContext.class);
		}
		public DeclContext decl(int i) {
			return getRuleContext(DeclContext.class,i);
		}
		public DeclContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_decl; }
	}

	public final DeclContext decl() throws RecognitionException {
		return decl(0);
	}

	private DeclContext decl(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		DeclContext _localctx = new DeclContext(_ctx, _parentState);
		DeclContext _prevctx = _localctx;
		int _startState = 4;
		enterRecursionRule(_localctx, 4, RULE_decl, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(74);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,1,_ctx) ) {
			case 1:
				{
				setState(57);
				vardecl(0);
				nodes.push_back();
				}
				break;
			case 2:
				{
				setState(60);
				rettype();
				setState(61);
				funcname();
				setState(62);
				match(T__2);
				setState(63);
				parameters();
				setState(64);
				match(T__3);
				setState(65);
				scope();
				}
				break;
			case 3:
				{
				setState(67);
				rettype();
				setState(68);
				funcname();
				setState(69);
				match(T__2);
				setState(70);
				parameters();
				setState(71);
				match(T__3);
				setState(72);
				match(T__4);
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(80);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,2,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new DeclContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_decl);
					setState(76);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(77);
					decl(2);
					}
					} 
				}
				setState(82);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,2,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class VardeclContext extends ParserRuleContext {
		public VartypeContext vartype() {
			return getRuleContext(VartypeContext.class,0);
		}
		public VarlistContext varlist() {
			return getRuleContext(VarlistContext.class,0);
		}
		public List<VardeclContext> vardecl() {
			return getRuleContexts(VardeclContext.class);
		}
		public VardeclContext vardecl(int i) {
			return getRuleContext(VardeclContext.class,i);
		}
		public VardeclContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_vardecl; }
	}

	public final VardeclContext vardecl() throws RecognitionException {
		return vardecl(0);
	}

	private VardeclContext vardecl(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		VardeclContext _localctx = new VardeclContext(_ctx, _parentState);
		VardeclContext _prevctx = _localctx;
		int _startState = 6;
		enterRecursionRule(_localctx, 6, RULE_vardecl, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(84);
			vartype();
			setState(85);
			varlist(0);
			setState(86);
			match(T__4);
			}
			_ctx.stop = _input.LT(-1);
			setState(92);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,3,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new VardeclContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_vardecl);
					setState(88);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(89);
					vardecl(2);
					}
					} 
				}
				setState(94);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,3,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ScopeContext extends ParserRuleContext {
		public VardeclContext vardecl() {
			return getRuleContext(VardeclContext.class,0);
		}
		public StmtlistContext stmtlist() {
			return getRuleContext(StmtlistContext.class,0);
		}
		public ScopeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_scope; }
	}

	public final ScopeContext scope() throws RecognitionException {
		ScopeContext _localctx = new ScopeContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_scope);
		try {
			setState(106);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,4,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(95);
				match(T__5);
				setState(96);
				vardecl(0);
				setState(97);
				stmtlist();
				setState(98);
				match(T__6);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(100);
				match(T__5);
				setState(101);
				stmtlist();
				setState(102);
				match(T__6);
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(104);
				match(T__5);
				setState(105);
				match(T__6);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class StmtlistContext extends ParserRuleContext {
		public List<StmtContext> stmt() {
			return getRuleContexts(StmtContext.class);
		}
		public StmtContext stmt(int i) {
			return getRuleContext(StmtContext.class,i);
		}
		public StmtlistContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_stmtlist; }
	}

	public final StmtlistContext stmtlist() throws RecognitionException {
		StmtlistContext _localctx = new StmtlistContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_stmtlist);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(111);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & 962104147272L) != 0)) {
				{
				{
				setState(108);
				stmt();
				}
				}
				setState(113);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class StmtContext extends ParserRuleContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public List<StmtContext> stmt() {
			return getRuleContexts(StmtContext.class);
		}
		public StmtContext stmt(int i) {
			return getRuleContext(StmtContext.class,i);
		}
		public List<ExproptContext> expropt() {
			return getRuleContexts(ExproptContext.class);
		}
		public ExproptContext expropt(int i) {
			return getRuleContext(ExproptContext.class,i);
		}
		public ScopeContext scope() {
			return getRuleContext(ScopeContext.class,0);
		}
		public StmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_stmt; }
	}

	public final StmtContext stmt() throws RecognitionException {
		StmtContext _localctx = new StmtContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_stmt);
		try {
			setState(152);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,6,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(114);
				expr(0);
				setState(115);
				match(T__4);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(117);
				match(T__7);
				setState(118);
				match(T__2);
				setState(119);
				expr(0);
				setState(120);
				match(T__3);
				setState(121);
				stmt();
				setState(122);
				match(T__8);
				setState(123);
				stmt();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(125);
				match(T__7);
				setState(126);
				match(T__2);
				setState(127);
				expr(0);
				setState(128);
				match(T__3);
				setState(129);
				stmt();
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(131);
				match(T__9);
				setState(132);
				match(T__2);
				setState(133);
				expropt();
				setState(134);
				match(T__4);
				setState(135);
				expropt();
				setState(136);
				match(T__4);
				setState(137);
				expropt();
				setState(138);
				match(T__3);
				setState(139);
				stmt();
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(141);
				match(T__10);
				setState(142);
				match(T__4);
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(143);
				match(T__11);
				setState(144);
				match(T__4);
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(145);
				match(T__12);
				setState(146);
				match(T__4);
				}
				break;
			case 8:
				enterOuterAlt(_localctx, 8);
				{
				setState(147);
				match(T__12);
				setState(148);
				expr(0);
				setState(149);
				match(T__4);
				}
				break;
			case 9:
				enterOuterAlt(_localctx, 9);
				{
				setState(151);
				scope();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class VarlistContext extends ParserRuleContext {
		public VarnameContext varname() {
			return getRuleContext(VarnameContext.class,0);
		}
		public TerminalNode INT() { return getToken(MiniCParser.INT, 0); }
		public List<VarlistContext> varlist() {
			return getRuleContexts(VarlistContext.class);
		}
		public VarlistContext varlist(int i) {
			return getRuleContext(VarlistContext.class,i);
		}
		public VarlistContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_varlist; }
	}

	public final VarlistContext varlist() throws RecognitionException {
		return varlist(0);
	}

	private VarlistContext varlist(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		VarlistContext _localctx = new VarlistContext(_ctx, _parentState);
		VarlistContext _prevctx = _localctx;
		int _startState = 14;
		enterRecursionRule(_localctx, 14, RULE_varlist, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(161);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,7,_ctx) ) {
			case 1:
				{
				setState(155);
				varname();
				}
				break;
			case 2:
				{
				setState(156);
				varname();
				setState(157);
				match(T__13);
				setState(158);
				match(INT);
				setState(159);
				match(T__14);
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(168);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,8,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new VarlistContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_varlist);
					setState(163);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(164);
					match(T__15);
					setState(165);
					varlist(2);
					}
					} 
				}
				setState(170);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,8,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class VarlistentryContext extends ParserRuleContext {
		public VarlistentryContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_varlistentry; }
	}

	public final VarlistentryContext varlistentry() throws RecognitionException {
		VarlistentryContext _localctx = new VarlistentryContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_varlistentry);
		try {
			enterOuterAlt(_localctx, 1);
			{
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class VartypeContext extends ParserRuleContext {
		public VartypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_vartype; }
	}

	public final VartypeContext vartype() throws RecognitionException {
		VartypeContext _localctx = new VartypeContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_vartype);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(173);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 917504L) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class RettypeContext extends ParserRuleContext {
		public VartypeContext vartype() {
			return getRuleContext(VartypeContext.class,0);
		}
		public RettypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_rettype; }
	}

	public final RettypeContext rettype() throws RecognitionException {
		RettypeContext _localctx = new RettypeContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_rettype);
		try {
			setState(177);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__19:
				enterOuterAlt(_localctx, 1);
				{
				setState(175);
				match(T__19);
				}
				break;
			case T__16:
			case T__17:
			case T__18:
				enterOuterAlt(_localctx, 2);
				{
				setState(176);
				vartype();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ParametersContext extends ParserRuleContext {
		public ParameterlistContext parameterlist() {
			return getRuleContext(ParameterlistContext.class,0);
		}
		public ParametersContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameters; }
	}

	public final ParametersContext parameters() throws RecognitionException {
		ParametersContext _localctx = new ParametersContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_parameters);
		try {
			setState(181);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__3:
				enterOuterAlt(_localctx, 1);
				{
				}
				break;
			case T__16:
			case T__17:
			case T__18:
				enterOuterAlt(_localctx, 2);
				{
				setState(180);
				parameterlist(0);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ParameterlistContext extends ParserRuleContext {
		public VartypeContext vartype() {
			return getRuleContext(VartypeContext.class,0);
		}
		public ParameternameContext parametername() {
			return getRuleContext(ParameternameContext.class,0);
		}
		public List<ParameterlistContext> parameterlist() {
			return getRuleContexts(ParameterlistContext.class);
		}
		public ParameterlistContext parameterlist(int i) {
			return getRuleContext(ParameterlistContext.class,i);
		}
		public ParameterlistContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameterlist; }
	}

	public final ParameterlistContext parameterlist() throws RecognitionException {
		return parameterlist(0);
	}

	private ParameterlistContext parameterlist(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ParameterlistContext _localctx = new ParameterlistContext(_ctx, _parentState);
		ParameterlistContext _prevctx = _localctx;
		int _startState = 24;
		enterRecursionRule(_localctx, 24, RULE_parameterlist, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(184);
			vartype();
			setState(185);
			parametername();
			}
			_ctx.stop = _input.LT(-1);
			setState(192);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,11,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new ParameterlistContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_parameterlist);
					setState(187);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(188);
					match(T__15);
					setState(189);
					parameterlist(2);
					}
					} 
				}
				setState(194);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,11,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ParameterentryContext extends ParserRuleContext {
		public ParameterentryContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameterentry; }
	}

	public final ParameterentryContext parameterentry() throws RecognitionException {
		ParameterentryContext _localctx = new ParameterentryContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_parameterentry);
		try {
			enterOuterAlt(_localctx, 1);
			{
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ExproptContext extends ParserRuleContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public ExproptContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expropt; }
	}

	public final ExproptContext expropt() throws RecognitionException {
		ExproptContext _localctx = new ExproptContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_expropt);
		try {
			setState(199);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__2:
			case T__20:
			case T__21:
			case T__22:
			case T__23:
			case ID:
			case INT:
			case CHAR:
				enterOuterAlt(_localctx, 1);
				{
				setState(197);
				expr(0);
				}
				break;
			case T__3:
			case T__4:
				enterOuterAlt(_localctx, 2);
				{
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ExprContext extends ParserRuleContext {
		public TerminalNode INT() { return getToken(MiniCParser.INT, 0); }
		public TerminalNode CHAR() { return getToken(MiniCParser.CHAR, 0); }
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public VarContext var() {
			return getRuleContext(VarContext.class,0);
		}
		public FuncnameContext funcname() {
			return getRuleContext(FuncnameContext.class,0);
		}
		public ArgumentsContext arguments() {
			return getRuleContext(ArgumentsContext.class,0);
		}
		public ParameternameContext parametername() {
			return getRuleContext(ParameternameContext.class,0);
		}
		public ExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expr; }
	}

	public final ExprContext expr() throws RecognitionException {
		return expr(0);
	}

	private ExprContext expr(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ExprContext _localctx = new ExprContext(_ctx, _parentState);
		ExprContext _prevctx = _localctx;
		int _startState = 30;
		enterRecursionRule(_localctx, 30, RULE_expr, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(225);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,13,_ctx) ) {
			case 1:
				{
				setState(202);
				match(INT);
				}
				break;
			case 2:
				{
				setState(203);
				match(CHAR);
				}
				break;
			case 3:
				{
				setState(204);
				match(T__20);
				}
				break;
			case 4:
				{
				setState(205);
				match(T__21);
				}
				break;
			case 5:
				{
				setState(206);
				match(T__22);
				setState(207);
				expr(12);
				}
				break;
			case 6:
				{
				setState(208);
				match(T__23);
				setState(209);
				expr(11);
				}
				break;
			case 7:
				{
				setState(210);
				var();
				setState(211);
				match(T__35);
				setState(212);
				expr(5);
				}
				break;
			case 8:
				{
				setState(214);
				match(T__2);
				setState(215);
				expr(0);
				setState(216);
				match(T__3);
				}
				break;
			case 9:
				{
				setState(218);
				var();
				}
				break;
			case 10:
				{
				setState(219);
				funcname();
				setState(220);
				match(T__2);
				setState(221);
				arguments();
				setState(222);
				match(T__3);
				}
				break;
			case 11:
				{
				setState(224);
				parametername();
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(244);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,15,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(242);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,14,_ctx) ) {
					case 1:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(227);
						if (!(precpred(_ctx, 10))) throw new FailedPredicateException(this, "precpred(_ctx, 10)");
						setState(228);
						_la = _input.LA(1);
						if ( !(_la==T__24 || _la==T__25) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(229);
						expr(11);
						}
						break;
					case 2:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(230);
						if (!(precpred(_ctx, 9))) throw new FailedPredicateException(this, "precpred(_ctx, 9)");
						setState(231);
						_la = _input.LA(1);
						if ( !(_la==T__22 || _la==T__26) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(232);
						expr(10);
						}
						break;
					case 3:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(233);
						if (!(precpred(_ctx, 8))) throw new FailedPredicateException(this, "precpred(_ctx, 8)");
						setState(234);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 16911433728L) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(235);
						expr(9);
						}
						break;
					case 4:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(236);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(237);
						match(T__33);
						setState(238);
						expr(8);
						}
						break;
					case 5:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(239);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(240);
						match(T__34);
						setState(241);
						expr(7);
						}
						break;
					}
					} 
				}
				setState(246);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,15,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class VarContext extends ParserRuleContext {
		public VarnameContext varname() {
			return getRuleContext(VarnameContext.class,0);
		}
		public ArraynameContext arrayname() {
			return getRuleContext(ArraynameContext.class,0);
		}
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public VarContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_var; }
	}

	public final VarContext var() throws RecognitionException {
		VarContext _localctx = new VarContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_var);
		try {
			setState(253);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,16,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(247);
				varname();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(248);
				arrayname();
				setState(249);
				match(T__13);
				setState(250);
				expr(0);
				setState(251);
				match(T__14);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ArgumentsContext extends ParserRuleContext {
		public ArgumentlistContext argumentlist() {
			return getRuleContext(ArgumentlistContext.class,0);
		}
		public ArgumentsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_arguments; }
	}

	public final ArgumentsContext arguments() throws RecognitionException {
		ArgumentsContext _localctx = new ArgumentsContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_arguments);
		try {
			setState(257);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__2:
			case T__20:
			case T__21:
			case T__22:
			case T__23:
			case ID:
			case INT:
			case CHAR:
				enterOuterAlt(_localctx, 1);
				{
				setState(255);
				argumentlist(0);
				}
				break;
			case T__3:
				enterOuterAlt(_localctx, 2);
				{
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ArgumentlistContext extends ParserRuleContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public List<ArgumentlistContext> argumentlist() {
			return getRuleContexts(ArgumentlistContext.class);
		}
		public ArgumentlistContext argumentlist(int i) {
			return getRuleContext(ArgumentlistContext.class,i);
		}
		public ArgumentlistContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_argumentlist; }
	}

	public final ArgumentlistContext argumentlist() throws RecognitionException {
		return argumentlist(0);
	}

	private ArgumentlistContext argumentlist(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ArgumentlistContext _localctx = new ArgumentlistContext(_ctx, _parentState);
		ArgumentlistContext _prevctx = _localctx;
		int _startState = 36;
		enterRecursionRule(_localctx, 36, RULE_argumentlist, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(260);
			expr(0);
			}
			_ctx.stop = _input.LT(-1);
			setState(267);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,18,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new ArgumentlistContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_argumentlist);
					setState(262);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(263);
					match(T__15);
					setState(264);
					argumentlist(2);
					}
					} 
				}
				setState(269);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,18,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class VarnameContext extends ParserRuleContext {
		public TerminalNode ID() { return getToken(MiniCParser.ID, 0); }
		public VarnameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_varname; }
	}

	public final VarnameContext varname() throws RecognitionException {
		VarnameContext _localctx = new VarnameContext(_ctx, getState());
		enterRule(_localctx, 38, RULE_varname);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(270);
			match(ID);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ArraynameContext extends ParserRuleContext {
		public TerminalNode ID() { return getToken(MiniCParser.ID, 0); }
		public ArraynameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_arrayname; }
	}

	public final ArraynameContext arrayname() throws RecognitionException {
		ArraynameContext _localctx = new ArraynameContext(_ctx, getState());
		enterRule(_localctx, 40, RULE_arrayname);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(272);
			match(ID);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class FuncnameContext extends ParserRuleContext {
		public TerminalNode ID() { return getToken(MiniCParser.ID, 0); }
		public FuncnameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_funcname; }
	}

	public final FuncnameContext funcname() throws RecognitionException {
		FuncnameContext _localctx = new FuncnameContext(_ctx, getState());
		enterRule(_localctx, 42, RULE_funcname);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(274);
			match(ID);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ParameternameContext extends ParserRuleContext {
		public TerminalNode ID() { return getToken(MiniCParser.ID, 0); }
		public ParameternameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parametername; }
	}

	public final ParameternameContext parametername() throws RecognitionException {
		ParameternameContext _localctx = new ParameternameContext(_ctx, getState());
		enterRule(_localctx, 44, RULE_parametername);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(276);
			match(ID);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 2:
			return decl_sempred((DeclContext)_localctx, predIndex);
		case 3:
			return vardecl_sempred((VardeclContext)_localctx, predIndex);
		case 7:
			return varlist_sempred((VarlistContext)_localctx, predIndex);
		case 12:
			return parameterlist_sempred((ParameterlistContext)_localctx, predIndex);
		case 15:
			return expr_sempred((ExprContext)_localctx, predIndex);
		case 18:
			return argumentlist_sempred((ArgumentlistContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean decl_sempred(DeclContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean vardecl_sempred(VardeclContext _localctx, int predIndex) {
		switch (predIndex) {
		case 1:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean varlist_sempred(VarlistContext _localctx, int predIndex) {
		switch (predIndex) {
		case 2:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean parameterlist_sempred(ParameterlistContext _localctx, int predIndex) {
		switch (predIndex) {
		case 3:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean expr_sempred(ExprContext _localctx, int predIndex) {
		switch (predIndex) {
		case 4:
			return precpred(_ctx, 10);
		case 5:
			return precpred(_ctx, 9);
		case 6:
			return precpred(_ctx, 8);
		case 7:
			return precpred(_ctx, 7);
		case 8:
			return precpred(_ctx, 6);
		}
		return true;
	}
	private boolean argumentlist_sempred(ArgumentlistContext _localctx, int predIndex) {
		switch (predIndex) {
		case 9:
			return precpred(_ctx, 1);
		}
		return true;
	}

	public static final String _serializedATN =
		"\u0004\u0001)\u0117\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
		"\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004\u0002"+
		"\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007\u0002"+
		"\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b\u0007\u000b\u0002"+
		"\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e\u0002\u000f\u0007\u000f"+
		"\u0002\u0010\u0007\u0010\u0002\u0011\u0007\u0011\u0002\u0012\u0007\u0012"+
		"\u0002\u0013\u0007\u0013\u0002\u0014\u0007\u0014\u0002\u0015\u0007\u0015"+
		"\u0002\u0016\u0007\u0016\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0003\u00017\b\u0001"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0003\u0002K\b\u0002\u0001\u0002\u0001\u0002\u0005\u0002O\b\u0002\n\u0002"+
		"\f\u0002R\t\u0002\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001"+
		"\u0003\u0001\u0003\u0001\u0003\u0005\u0003[\b\u0003\n\u0003\f\u0003^\t"+
		"\u0003\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001"+
		"\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0003"+
		"\u0004k\b\u0004\u0001\u0005\u0005\u0005n\b\u0005\n\u0005\f\u0005q\t\u0005"+
		"\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006"+
		"\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006"+
		"\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006"+
		"\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006"+
		"\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006"+
		"\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006"+
		"\u0001\u0006\u0001\u0006\u0003\u0006\u0099\b\u0006\u0001\u0007\u0001\u0007"+
		"\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0003\u0007"+
		"\u00a2\b\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0005\u0007\u00a7\b"+
		"\u0007\n\u0007\f\u0007\u00aa\t\u0007\u0001\b\u0001\b\u0001\t\u0001\t\u0001"+
		"\n\u0001\n\u0003\n\u00b2\b\n\u0001\u000b\u0001\u000b\u0003\u000b\u00b6"+
		"\b\u000b\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0005"+
		"\f\u00bf\b\f\n\f\f\f\u00c2\t\f\u0001\r\u0001\r\u0001\u000e\u0001\u000e"+
		"\u0003\u000e\u00c8\b\u000e\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f"+
		"\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f"+
		"\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f"+
		"\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f"+
		"\u0001\u000f\u0001\u000f\u0003\u000f\u00e2\b\u000f\u0001\u000f\u0001\u000f"+
		"\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f"+
		"\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f"+
		"\u0001\u000f\u0005\u000f\u00f3\b\u000f\n\u000f\f\u000f\u00f6\t\u000f\u0001"+
		"\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0003"+
		"\u0010\u00fe\b\u0010\u0001\u0011\u0001\u0011\u0003\u0011\u0102\b\u0011"+
		"\u0001\u0012\u0001\u0012\u0001\u0012\u0001\u0012\u0001\u0012\u0001\u0012"+
		"\u0005\u0012\u010a\b\u0012\n\u0012\f\u0012\u010d\t\u0012\u0001\u0013\u0001"+
		"\u0013\u0001\u0014\u0001\u0014\u0001\u0015\u0001\u0015\u0001\u0016\u0001"+
		"\u0016\u0001\u0016\u0000\u0006\u0004\u0006\u000e\u0018\u001e$\u0017\u0000"+
		"\u0002\u0004\u0006\b\n\f\u000e\u0010\u0012\u0014\u0016\u0018\u001a\u001c"+
		"\u001e \"$&(*,\u0000\u0004\u0001\u0000\u0011\u0013\u0001\u0000\u0019\u001a"+
		"\u0002\u0000\u0017\u0017\u001b\u001b\u0001\u0000\u001c!\u0127\u0000.\u0001"+
		"\u0000\u0000\u0000\u00026\u0001\u0000\u0000\u0000\u0004J\u0001\u0000\u0000"+
		"\u0000\u0006S\u0001\u0000\u0000\u0000\bj\u0001\u0000\u0000\u0000\no\u0001"+
		"\u0000\u0000\u0000\f\u0098\u0001\u0000\u0000\u0000\u000e\u00a1\u0001\u0000"+
		"\u0000\u0000\u0010\u00ab\u0001\u0000\u0000\u0000\u0012\u00ad\u0001\u0000"+
		"\u0000\u0000\u0014\u00b1\u0001\u0000\u0000\u0000\u0016\u00b5\u0001\u0000"+
		"\u0000\u0000\u0018\u00b7\u0001\u0000\u0000\u0000\u001a\u00c3\u0001\u0000"+
		"\u0000\u0000\u001c\u00c7\u0001\u0000\u0000\u0000\u001e\u00e1\u0001\u0000"+
		"\u0000\u0000 \u00fd\u0001\u0000\u0000\u0000\"\u0101\u0001\u0000\u0000"+
		"\u0000$\u0103\u0001\u0000\u0000\u0000&\u010e\u0001\u0000\u0000\u0000("+
		"\u0110\u0001\u0000\u0000\u0000*\u0112\u0001\u0000\u0000\u0000,\u0114\u0001"+
		"\u0000\u0000\u0000./\u0003\u0002\u0001\u0000/0\u0003\u0004\u0002\u0000"+
		"01\u0006\u0000\uffff\uffff\u00001\u0001\u0001\u0000\u0000\u000023\u0005"+
		"\u0001\u0000\u000034\u0005\u0002\u0000\u000047\u0006\u0001\uffff\uffff"+
		"\u000057\u0006\u0001\uffff\uffff\u000062\u0001\u0000\u0000\u000065\u0001"+
		"\u0000\u0000\u00007\u0003\u0001\u0000\u0000\u000089\u0006\u0002\uffff"+
		"\uffff\u00009:\u0003\u0006\u0003\u0000:;\u0006\u0002\uffff\uffff\u0000"+
		";K\u0001\u0000\u0000\u0000<=\u0003\u0014\n\u0000=>\u0003*\u0015\u0000"+
		">?\u0005\u0003\u0000\u0000?@\u0003\u0016\u000b\u0000@A\u0005\u0004\u0000"+
		"\u0000AB\u0003\b\u0004\u0000BK\u0001\u0000\u0000\u0000CD\u0003\u0014\n"+
		"\u0000DE\u0003*\u0015\u0000EF\u0005\u0003\u0000\u0000FG\u0003\u0016\u000b"+
		"\u0000GH\u0005\u0004\u0000\u0000HI\u0005\u0005\u0000\u0000IK\u0001\u0000"+
		"\u0000\u0000J8\u0001\u0000\u0000\u0000J<\u0001\u0000\u0000\u0000JC\u0001"+
		"\u0000\u0000\u0000KP\u0001\u0000\u0000\u0000LM\n\u0001\u0000\u0000MO\u0003"+
		"\u0004\u0002\u0002NL\u0001\u0000\u0000\u0000OR\u0001\u0000\u0000\u0000"+
		"PN\u0001\u0000\u0000\u0000PQ\u0001\u0000\u0000\u0000Q\u0005\u0001\u0000"+
		"\u0000\u0000RP\u0001\u0000\u0000\u0000ST\u0006\u0003\uffff\uffff\u0000"+
		"TU\u0003\u0012\t\u0000UV\u0003\u000e\u0007\u0000VW\u0005\u0005\u0000\u0000"+
		"W\\\u0001\u0000\u0000\u0000XY\n\u0001\u0000\u0000Y[\u0003\u0006\u0003"+
		"\u0002ZX\u0001\u0000\u0000\u0000[^\u0001\u0000\u0000\u0000\\Z\u0001\u0000"+
		"\u0000\u0000\\]\u0001\u0000\u0000\u0000]\u0007\u0001\u0000\u0000\u0000"+
		"^\\\u0001\u0000\u0000\u0000_`\u0005\u0006\u0000\u0000`a\u0003\u0006\u0003"+
		"\u0000ab\u0003\n\u0005\u0000bc\u0005\u0007\u0000\u0000ck\u0001\u0000\u0000"+
		"\u0000de\u0005\u0006\u0000\u0000ef\u0003\n\u0005\u0000fg\u0005\u0007\u0000"+
		"\u0000gk\u0001\u0000\u0000\u0000hi\u0005\u0006\u0000\u0000ik\u0005\u0007"+
		"\u0000\u0000j_\u0001\u0000\u0000\u0000jd\u0001\u0000\u0000\u0000jh\u0001"+
		"\u0000\u0000\u0000k\t\u0001\u0000\u0000\u0000ln\u0003\f\u0006\u0000ml"+
		"\u0001\u0000\u0000\u0000nq\u0001\u0000\u0000\u0000om\u0001\u0000\u0000"+
		"\u0000op\u0001\u0000\u0000\u0000p\u000b\u0001\u0000\u0000\u0000qo\u0001"+
		"\u0000\u0000\u0000rs\u0003\u001e\u000f\u0000st\u0005\u0005\u0000\u0000"+
		"t\u0099\u0001\u0000\u0000\u0000uv\u0005\b\u0000\u0000vw\u0005\u0003\u0000"+
		"\u0000wx\u0003\u001e\u000f\u0000xy\u0005\u0004\u0000\u0000yz\u0003\f\u0006"+
		"\u0000z{\u0005\t\u0000\u0000{|\u0003\f\u0006\u0000|\u0099\u0001\u0000"+
		"\u0000\u0000}~\u0005\b\u0000\u0000~\u007f\u0005\u0003\u0000\u0000\u007f"+
		"\u0080\u0003\u001e\u000f\u0000\u0080\u0081\u0005\u0004\u0000\u0000\u0081"+
		"\u0082\u0003\f\u0006\u0000\u0082\u0099\u0001\u0000\u0000\u0000\u0083\u0084"+
		"\u0005\n\u0000\u0000\u0084\u0085\u0005\u0003\u0000\u0000\u0085\u0086\u0003"+
		"\u001c\u000e\u0000\u0086\u0087\u0005\u0005\u0000\u0000\u0087\u0088\u0003"+
		"\u001c\u000e\u0000\u0088\u0089\u0005\u0005\u0000\u0000\u0089\u008a\u0003"+
		"\u001c\u000e\u0000\u008a\u008b\u0005\u0004\u0000\u0000\u008b\u008c\u0003"+
		"\f\u0006\u0000\u008c\u0099\u0001\u0000\u0000\u0000\u008d\u008e\u0005\u000b"+
		"\u0000\u0000\u008e\u0099\u0005\u0005\u0000\u0000\u008f\u0090\u0005\f\u0000"+
		"\u0000\u0090\u0099\u0005\u0005\u0000\u0000\u0091\u0092\u0005\r\u0000\u0000"+
		"\u0092\u0099\u0005\u0005\u0000\u0000\u0093\u0094\u0005\r\u0000\u0000\u0094"+
		"\u0095\u0003\u001e\u000f\u0000\u0095\u0096\u0005\u0005\u0000\u0000\u0096"+
		"\u0099\u0001\u0000\u0000\u0000\u0097\u0099\u0003\b\u0004\u0000\u0098r"+
		"\u0001\u0000\u0000\u0000\u0098u\u0001\u0000\u0000\u0000\u0098}\u0001\u0000"+
		"\u0000\u0000\u0098\u0083\u0001\u0000\u0000\u0000\u0098\u008d\u0001\u0000"+
		"\u0000\u0000\u0098\u008f\u0001\u0000\u0000\u0000\u0098\u0091\u0001\u0000"+
		"\u0000\u0000\u0098\u0093\u0001\u0000\u0000\u0000\u0098\u0097\u0001\u0000"+
		"\u0000\u0000\u0099\r\u0001\u0000\u0000\u0000\u009a\u009b\u0006\u0007\uffff"+
		"\uffff\u0000\u009b\u00a2\u0003&\u0013\u0000\u009c\u009d\u0003&\u0013\u0000"+
		"\u009d\u009e\u0005\u000e\u0000\u0000\u009e\u009f\u0005&\u0000\u0000\u009f"+
		"\u00a0\u0005\u000f\u0000\u0000\u00a0\u00a2\u0001\u0000\u0000\u0000\u00a1"+
		"\u009a\u0001\u0000\u0000\u0000\u00a1\u009c\u0001\u0000\u0000\u0000\u00a2"+
		"\u00a8\u0001\u0000\u0000\u0000\u00a3\u00a4\n\u0001\u0000\u0000\u00a4\u00a5"+
		"\u0005\u0010\u0000\u0000\u00a5\u00a7\u0003\u000e\u0007\u0002\u00a6\u00a3"+
		"\u0001\u0000\u0000\u0000\u00a7\u00aa\u0001\u0000\u0000\u0000\u00a8\u00a6"+
		"\u0001\u0000\u0000\u0000\u00a8\u00a9\u0001\u0000\u0000\u0000\u00a9\u000f"+
		"\u0001\u0000\u0000\u0000\u00aa\u00a8\u0001\u0000\u0000\u0000\u00ab\u00ac"+
		"\u0001\u0000\u0000\u0000\u00ac\u0011\u0001\u0000\u0000\u0000\u00ad\u00ae"+
		"\u0007\u0000\u0000\u0000\u00ae\u0013\u0001\u0000\u0000\u0000\u00af\u00b2"+
		"\u0005\u0014\u0000\u0000\u00b0\u00b2\u0003\u0012\t\u0000\u00b1\u00af\u0001"+
		"\u0000\u0000\u0000\u00b1\u00b0\u0001\u0000\u0000\u0000\u00b2\u0015\u0001"+
		"\u0000\u0000\u0000\u00b3\u00b6\u0001\u0000\u0000\u0000\u00b4\u00b6\u0003"+
		"\u0018\f\u0000\u00b5\u00b3\u0001\u0000\u0000\u0000\u00b5\u00b4\u0001\u0000"+
		"\u0000\u0000\u00b6\u0017\u0001\u0000\u0000\u0000\u00b7\u00b8\u0006\f\uffff"+
		"\uffff\u0000\u00b8\u00b9\u0003\u0012\t\u0000\u00b9\u00ba\u0003,\u0016"+
		"\u0000\u00ba\u00c0\u0001\u0000\u0000\u0000\u00bb\u00bc\n\u0001\u0000\u0000"+
		"\u00bc\u00bd\u0005\u0010\u0000\u0000\u00bd\u00bf\u0003\u0018\f\u0002\u00be"+
		"\u00bb\u0001\u0000\u0000\u0000\u00bf\u00c2\u0001\u0000\u0000\u0000\u00c0"+
		"\u00be\u0001\u0000\u0000\u0000\u00c0\u00c1\u0001\u0000\u0000\u0000\u00c1"+
		"\u0019\u0001\u0000\u0000\u0000\u00c2\u00c0\u0001\u0000\u0000\u0000\u00c3"+
		"\u00c4\u0001\u0000\u0000\u0000\u00c4\u001b\u0001\u0000\u0000\u0000\u00c5"+
		"\u00c8\u0003\u001e\u000f\u0000\u00c6\u00c8\u0001\u0000\u0000\u0000\u00c7"+
		"\u00c5\u0001\u0000\u0000\u0000\u00c7\u00c6\u0001\u0000\u0000\u0000\u00c8"+
		"\u001d\u0001\u0000\u0000\u0000\u00c9\u00ca\u0006\u000f\uffff\uffff\u0000"+
		"\u00ca\u00e2\u0005&\u0000\u0000\u00cb\u00e2\u0005\'\u0000\u0000\u00cc"+
		"\u00e2\u0005\u0015\u0000\u0000\u00cd\u00e2\u0005\u0016\u0000\u0000\u00ce"+
		"\u00cf\u0005\u0017\u0000\u0000\u00cf\u00e2\u0003\u001e\u000f\f\u00d0\u00d1"+
		"\u0005\u0018\u0000\u0000\u00d1\u00e2\u0003\u001e\u000f\u000b\u00d2\u00d3"+
		"\u0003 \u0010\u0000\u00d3\u00d4\u0005$\u0000\u0000\u00d4\u00d5\u0003\u001e"+
		"\u000f\u0005\u00d5\u00e2\u0001\u0000\u0000\u0000\u00d6\u00d7\u0005\u0003"+
		"\u0000\u0000\u00d7\u00d8\u0003\u001e\u000f\u0000\u00d8\u00d9\u0005\u0004"+
		"\u0000\u0000\u00d9\u00e2\u0001\u0000\u0000\u0000\u00da\u00e2\u0003 \u0010"+
		"\u0000\u00db\u00dc\u0003*\u0015\u0000\u00dc\u00dd\u0005\u0003\u0000\u0000"+
		"\u00dd\u00de\u0003\"\u0011\u0000\u00de\u00df\u0005\u0004\u0000\u0000\u00df"+
		"\u00e2\u0001\u0000\u0000\u0000\u00e0\u00e2\u0003,\u0016\u0000\u00e1\u00c9"+
		"\u0001\u0000\u0000\u0000\u00e1\u00cb\u0001\u0000\u0000\u0000\u00e1\u00cc"+
		"\u0001\u0000\u0000\u0000\u00e1\u00cd\u0001\u0000\u0000\u0000\u00e1\u00ce"+
		"\u0001\u0000\u0000\u0000\u00e1\u00d0\u0001\u0000\u0000\u0000\u00e1\u00d2"+
		"\u0001\u0000\u0000\u0000\u00e1\u00d6\u0001\u0000\u0000\u0000\u00e1\u00da"+
		"\u0001\u0000\u0000\u0000\u00e1\u00db\u0001\u0000\u0000\u0000\u00e1\u00e0"+
		"\u0001\u0000\u0000\u0000\u00e2\u00f4\u0001\u0000\u0000\u0000\u00e3\u00e4"+
		"\n\n\u0000\u0000\u00e4\u00e5\u0007\u0001\u0000\u0000\u00e5\u00f3\u0003"+
		"\u001e\u000f\u000b\u00e6\u00e7\n\t\u0000\u0000\u00e7\u00e8\u0007\u0002"+
		"\u0000\u0000\u00e8\u00f3\u0003\u001e\u000f\n\u00e9\u00ea\n\b\u0000\u0000"+
		"\u00ea\u00eb\u0007\u0003\u0000\u0000\u00eb\u00f3\u0003\u001e\u000f\t\u00ec"+
		"\u00ed\n\u0007\u0000\u0000\u00ed\u00ee\u0005\"\u0000\u0000\u00ee\u00f3"+
		"\u0003\u001e\u000f\b\u00ef\u00f0\n\u0006\u0000\u0000\u00f0\u00f1\u0005"+
		"#\u0000\u0000\u00f1\u00f3\u0003\u001e\u000f\u0007\u00f2\u00e3\u0001\u0000"+
		"\u0000\u0000\u00f2\u00e6\u0001\u0000\u0000\u0000\u00f2\u00e9\u0001\u0000"+
		"\u0000\u0000\u00f2\u00ec\u0001\u0000\u0000\u0000\u00f2\u00ef\u0001\u0000"+
		"\u0000\u0000\u00f3\u00f6\u0001\u0000\u0000\u0000\u00f4\u00f2\u0001\u0000"+
		"\u0000\u0000\u00f4\u00f5\u0001\u0000\u0000\u0000\u00f5\u001f\u0001\u0000"+
		"\u0000\u0000\u00f6\u00f4\u0001\u0000\u0000\u0000\u00f7\u00fe\u0003&\u0013"+
		"\u0000\u00f8\u00f9\u0003(\u0014\u0000\u00f9\u00fa\u0005\u000e\u0000\u0000"+
		"\u00fa\u00fb\u0003\u001e\u000f\u0000\u00fb\u00fc\u0005\u000f\u0000\u0000"+
		"\u00fc\u00fe\u0001\u0000\u0000\u0000\u00fd\u00f7\u0001\u0000\u0000\u0000"+
		"\u00fd\u00f8\u0001\u0000\u0000\u0000\u00fe!\u0001\u0000\u0000\u0000\u00ff"+
		"\u0102\u0003$\u0012\u0000\u0100\u0102\u0001\u0000\u0000\u0000\u0101\u00ff"+
		"\u0001\u0000\u0000\u0000\u0101\u0100\u0001\u0000\u0000\u0000\u0102#\u0001"+
		"\u0000\u0000\u0000\u0103\u0104\u0006\u0012\uffff\uffff\u0000\u0104\u0105"+
		"\u0003\u001e\u000f\u0000\u0105\u010b\u0001\u0000\u0000\u0000\u0106\u0107"+
		"\n\u0001\u0000\u0000\u0107\u0108\u0005\u0010\u0000\u0000\u0108\u010a\u0003"+
		"$\u0012\u0002\u0109\u0106\u0001\u0000\u0000\u0000\u010a\u010d\u0001\u0000"+
		"\u0000\u0000\u010b\u0109\u0001\u0000\u0000\u0000\u010b\u010c\u0001\u0000"+
		"\u0000\u0000\u010c%\u0001\u0000\u0000\u0000\u010d\u010b\u0001\u0000\u0000"+
		"\u0000\u010e\u010f\u0005%\u0000\u0000\u010f\'\u0001\u0000\u0000\u0000"+
		"\u0110\u0111\u0005%\u0000\u0000\u0111)\u0001\u0000\u0000\u0000\u0112\u0113"+
		"\u0005%\u0000\u0000\u0113+\u0001\u0000\u0000\u0000\u0114\u0115\u0005%"+
		"\u0000\u0000\u0115-\u0001\u0000\u0000\u0000\u00136JP\\jo\u0098\u00a1\u00a8"+
		"\u00b1\u00b5\u00c0\u00c7\u00e1\u00f2\u00f4\u00fd\u0101\u010b";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}