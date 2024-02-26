// Generated from /home/ubuntu/Documents/csc488/assignments/minic/grammars/MiniC.g4 by ANTLR 4.13.1

#include <vector>
#include "Program.h"
#include "Declarations.h"
#include "Statements.h"
#include "Exprs.h"
#include "Terms.h"

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


	    void link(ASTNode* parent, ASTNode* child) {
	        parent->addChild(child);
	        if (child != NULL)
	            child->setParent(parent);
	    }

	    void link(ASTNode* parent, std::vector<ASTNode*> children) {
	        for (auto iter = children.begin(); iter != children.end(); iter++)
	            link(parent, *iter);
	    }

	    UnaryExpr* createUnaryExpr(std::string op, Expr *expr) {
	        UnaryExpr *node = new UnaryExpr();
	        node->setOpcode(Expr::opcodeFromString(op));
	        link(node, expr);
	        return node;
	    }

	    BinaryExpr* createBinaryExpr(std::string op, Expr *e1, Expr *e2) {
	        BinaryExpr *node = new BinaryExpr();
	        node->setOpcode(Expr::opcodeFromString(op));
	        link(node, e1);
	        link(node, e2);
	        return node;
	    }

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
			    link(_localctx.val, ((ProgContext)_localctx).decl.nodes);
			    _localctx.val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

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
				((PreambleContext)_localctx).flag =  true;
				}
				break;
			case T__16:
			case T__17:
			case T__18:
			case T__19:
				enterOuterAlt(_localctx, 2);
				{
				((PreambleContext)_localctx).flag =  false;
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
		public std::vector<ASTNode*> nodes;
		public DeclContext d1;
		public VardeclContext vardecl;
		public RettypeContext rettype;
		public FuncnameContext funcname;
		public ParametersContext parameters;
		public ScopeContext scope;
		public DeclContext d2;
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
			setState(76);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,1,_ctx) ) {
			case 1:
				{
				setState(57);
				((DeclContext)_localctx).vardecl = vardecl(0);
				_localctx.nodes.insert(_localctx.nodes.end(), ((DeclContext)_localctx).vardecl.nodes.begin(), ((DeclContext)_localctx).vardecl.nodes.end());
				}
				break;
			case 2:
				{
				setState(60);
				((DeclContext)_localctx).rettype = rettype();
				setState(61);
				((DeclContext)_localctx).funcname = funcname();
				setState(62);
				match(T__2);
				setState(63);
				((DeclContext)_localctx).parameters = parameters();
				setState(64);
				match(T__3);
				setState(65);
				((DeclContext)_localctx).scope = scope();

				    FuncDeclaration *node = new FuncDeclaration();
				    link(node, ((DeclContext)_localctx).rettype.node);
				    link(node, ((DeclContext)_localctx).funcname.node);
				    link(node, ((DeclContext)_localctx).parameters.nodes);
				    link(node, ((DeclContext)_localctx).scope.node);
				    node->setHasBody(true);
				    node->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
				    _localctx.nodes.push_back(node);

				}
				break;
			case 3:
				{
				setState(68);
				((DeclContext)_localctx).rettype = rettype();
				setState(69);
				((DeclContext)_localctx).funcname = funcname();
				setState(70);
				match(T__2);
				setState(71);
				((DeclContext)_localctx).parameters = parameters();
				setState(72);
				match(T__3);
				setState(73);
				match(T__4);

				    FuncDeclaration *node = new FuncDeclaration();
				    link(node, ((DeclContext)_localctx).rettype.node);
				    link(node, ((DeclContext)_localctx).funcname.node);
				    link(node, ((DeclContext)_localctx).parameters.nodes);
				    node->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
				    _localctx.nodes.push_back(node);

				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(84);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,2,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new DeclContext(_parentctx, _parentState);
					_localctx.d1 = _prevctx;
					pushNewRecursionContext(_localctx, _startState, RULE_decl);
					setState(78);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(79);
					((DeclContext)_localctx).d2 = decl(2);

					              _localctx.nodes.insert(_localctx.nodes.end(), ((DeclContext)_localctx).d1.nodes.begin(), ((DeclContext)_localctx).d1.nodes.end());
					              _localctx.nodes.insert(_localctx.nodes.end(), ((DeclContext)_localctx).d2.nodes.begin(), ((DeclContext)_localctx).d2.nodes.end());
					          
					}
					} 
				}
				setState(86);
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
		public std::vector<ASTNode*> nodes;
		public VardeclContext vd1;
		public VartypeContext vartype;
		public VarlistContext varlist;
		public VardeclContext vd2;
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
			setState(88);
			((VardeclContext)_localctx).vartype = vartype();
			setState(89);
			((VardeclContext)_localctx).varlist = varlist(0);
			setState(90);
			match(T__4);

			    VarDeclaration *node = new VarDeclaration();
			    link(node, ((VardeclContext)_localctx).vartype.node);
			    link(node, ((VardeclContext)_localctx).varlist.nodes);
			    node->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
			    _localctx.nodes.push_back(node);

			}
			_ctx.stop = _input.LT(-1);
			setState(99);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,3,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new VardeclContext(_parentctx, _parentState);
					_localctx.vd1 = _prevctx;
					pushNewRecursionContext(_localctx, _startState, RULE_vardecl);
					setState(93);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(94);
					((VardeclContext)_localctx).vd2 = vardecl(2);

					              _localctx.nodes.insert(_localctx.nodes.end(), ((VardeclContext)_localctx).vd1.nodes.begin(), ((VardeclContext)_localctx).vd1.nodes.end());
					              _localctx.nodes.insert(_localctx.nodes.end(), ((VardeclContext)_localctx).vd2.nodes.begin(), ((VardeclContext)_localctx).vd2.nodes.end());
					          
					}
					} 
				}
				setState(101);
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
		public ScopeStatement * node;
		public VardeclContext vardecl;
		public StmtlistContext stmtlist;
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

		    ((ScopeContext)_localctx).node =  new ScopeStatement();
		    _localctx.node->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

		try {
			setState(115);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,4,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(102);
				match(T__5);
				setState(103);
				((ScopeContext)_localctx).vardecl = vardecl(0);
				setState(104);
				((ScopeContext)_localctx).stmtlist = stmtlist();
				setState(105);
				match(T__6);

				    _localctx.node->setNumVarDecl(((ScopeContext)_localctx).vardecl.nodes.size());
				    link(_localctx.node, ((ScopeContext)_localctx).vardecl.nodes);
				    link(_localctx.node, ((ScopeContext)_localctx).stmtlist.nodes);

				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(108);
				match(T__5);
				setState(109);
				((ScopeContext)_localctx).stmtlist = stmtlist();
				setState(110);
				match(T__6);
				link(_localctx.node, ((ScopeContext)_localctx).stmtlist.nodes);
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(113);
				match(T__5);
				setState(114);
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
		public std::vector<ASTNode*> nodes;
		public StmtContext stmt;
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
			setState(122);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & 962104147272L) != 0)) {
				{
				{
				setState(117);
				((StmtlistContext)_localctx).stmt = stmt();
				_localctx.nodes.push_back(((StmtlistContext)_localctx).stmt.node);
				}
				}
				setState(124);
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
		public Statement * node;
		public ExprContext expr;
		public StmtContext s1;
		public StmtContext s2;
		public StmtContext stmt;
		public ExproptContext e1;
		public ExproptContext e2;
		public ExproptContext e3;
		public ScopeContext scope;
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
			setState(173);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,6,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(125);
				((StmtContext)_localctx).expr = expr(0);
				setState(126);
				match(T__4);

				    ((StmtContext)_localctx).node =  new ExprStatement();
				    link(_localctx.node, ((StmtContext)_localctx).expr.node);
				    _localctx.node->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(129);
				match(T__7);
				setState(130);
				match(T__2);
				setState(131);
				((StmtContext)_localctx).expr = expr(0);
				setState(132);
				match(T__3);
				setState(133);
				((StmtContext)_localctx).s1 = stmt();
				setState(134);
				match(T__8);
				setState(135);
				((StmtContext)_localctx).s2 = stmt();

				    ((StmtContext)_localctx).node =  new IfStatement();
				    link(_localctx.node, ((StmtContext)_localctx).expr.node);
				    link(_localctx.node, ((StmtContext)_localctx).s1.node);
				    link(_localctx.node, ((StmtContext)_localctx).s2.node);
				    _localctx.node->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(138);
				match(T__7);
				setState(139);
				match(T__2);
				setState(140);
				((StmtContext)_localctx).expr = expr(0);
				setState(141);
				match(T__3);
				setState(142);
				((StmtContext)_localctx).stmt = stmt();

				    ((StmtContext)_localctx).node =  new IfStatement();
				    link(_localctx.node, ((StmtContext)_localctx).expr.node);
				    link(_localctx.node, ((StmtContext)_localctx).stmt.node);
				    _localctx.node->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(145);
				match(T__9);
				setState(146);
				match(T__2);
				setState(147);
				((StmtContext)_localctx).e1 = expropt();
				setState(148);
				match(T__4);
				setState(149);
				((StmtContext)_localctx).e2 = expropt();
				setState(150);
				match(T__4);
				setState(151);
				((StmtContext)_localctx).e3 = expropt();
				setState(152);
				match(T__3);
				setState(153);
				((StmtContext)_localctx).stmt = stmt();

				    ((StmtContext)_localctx).node =  new ForStatement();
				    link(_localctx.node, ((StmtContext)_localctx).e1.node);
				    link(_localctx.node, ((StmtContext)_localctx).e2.node);
				    link(_localctx.node, ((StmtContext)_localctx).e3.node);
				    link(_localctx.node, ((StmtContext)_localctx).stmt.node);
				    _localctx.node->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(156);
				match(T__10);
				setState(157);
				match(T__4);

				    ((StmtContext)_localctx).node =  new ContinueStatement();
				    _localctx.node->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(159);
				match(T__11);
				setState(160);
				match(T__4);

				    ((StmtContext)_localctx).node =  new BreakStatement();
				    _localctx.node->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(162);
				match(T__12);
				setState(163);
				match(T__4);

				    ((StmtContext)_localctx).node =  new ReturnStatement();
				    _localctx.node->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

				}
				break;
			case 8:
				enterOuterAlt(_localctx, 8);
				{
				setState(165);
				match(T__12);
				setState(166);
				((StmtContext)_localctx).expr = expr(0);
				setState(167);
				match(T__4);

				    ((StmtContext)_localctx).node =  new ReturnStatement();
				    link(_localctx.node, ((StmtContext)_localctx).expr.node);
				    _localctx.node->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

				}
				break;
			case 9:
				enterOuterAlt(_localctx, 9);
				{
				setState(170);
				((StmtContext)_localctx).scope = scope();
				((StmtContext)_localctx).node =  ((StmtContext)_localctx).scope.node;
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
		public std::vector<ASTNode*> nodes;
		public VarlistContext vl1;
		public VarnameContext varname;
		public Token INT;
		public VarlistContext vl2;
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
			setState(185);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,7,_ctx) ) {
			case 1:
				{
				setState(176);
				((VarlistContext)_localctx).varname = varname();

				    VarReference *node = new VarReference();
				    link(node, ((VarlistContext)_localctx).varname.node);
				    node->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
				    _localctx.nodes.push_back(node);

				}
				break;
			case 2:
				{
				setState(179);
				((VarlistContext)_localctx).varname = varname();
				setState(180);
				match(T__13);
				setState(181);
				((VarlistContext)_localctx).INT = match(INT);
				setState(182);
				match(T__14);

				    VarReference *node = new VarReference();
				    link(node, ((VarlistContext)_localctx).varname.node);
				    IntLiteralExpr *expr = new IntLiteralExpr(stoi((((VarlistContext)_localctx).INT!=null?((VarlistContext)_localctx).INT.getText():null)));
				    expr->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
				    link(node, expr);
				    node->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
				    _localctx.nodes.push_back(node);

				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(194);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,8,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new VarlistContext(_parentctx, _parentState);
					_localctx.vl1 = _prevctx;
					pushNewRecursionContext(_localctx, _startState, RULE_varlist);
					setState(187);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(188);
					match(T__15);
					setState(189);
					((VarlistContext)_localctx).vl2 = varlist(2);

					              _localctx.nodes.insert(_localctx.nodes.end(), ((VarlistContext)_localctx).vl1.nodes.begin(), ((VarlistContext)_localctx).vl1.nodes.end());
					              _localctx.nodes.insert(_localctx.nodes.end(), ((VarlistContext)_localctx).vl2.nodes.begin(), ((VarlistContext)_localctx).vl2.nodes.end());
					          
					}
					} 
				}
				setState(196);
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
		public TypeReference * node;
		public VartypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_vartype; }
	}

	public final VartypeContext vartype() throws RecognitionException {
		VartypeContext _localctx = new VartypeContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_vartype);
		try {
			setState(205);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__16:
				enterOuterAlt(_localctx, 1);
				{
				setState(199);
				match(T__16);
				((VartypeContext)_localctx).node =  new TypeReference(Type::Int);
				}
				break;
			case T__17:
				enterOuterAlt(_localctx, 2);
				{
				setState(201);
				match(T__17);
				((VartypeContext)_localctx).node =  new TypeReference(Type::Bool);
				}
				break;
			case T__18:
				enterOuterAlt(_localctx, 3);
				{
				setState(203);
				match(T__18);
				((VartypeContext)_localctx).node =  new TypeReference(Type::Char);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			_localctx.node->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
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
		public TypeReference * node;
		public VartypeContext vartype;
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
			setState(212);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__19:
				enterOuterAlt(_localctx, 1);
				{
				setState(207);
				match(T__19);

				    ((RettypeContext)_localctx).node =  new TypeReference(Type::Void);
				    _localctx.node->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

				}
				break;
			case T__16:
			case T__17:
			case T__18:
				enterOuterAlt(_localctx, 2);
				{
				setState(209);
				((RettypeContext)_localctx).vartype = vartype();
				((RettypeContext)_localctx).node =  ((RettypeContext)_localctx).vartype.node;
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
		public std::vector<ASTNode*> nodes;
		public ParameterlistContext parameterlist;
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
			setState(218);
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
				setState(215);
				((ParametersContext)_localctx).parameterlist = parameterlist(0);
				((ParametersContext)_localctx).nodes =  ((ParametersContext)_localctx).parameterlist.nodes;
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
		public std::vector<ASTNode*> nodes;
		public ParameterlistContext pl1;
		public VartypeContext vartype;
		public ParameternameContext parametername;
		public ParameterlistContext pl2;
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
			setState(221);
			((ParameterlistContext)_localctx).vartype = vartype();
			setState(222);
			((ParameterlistContext)_localctx).parametername = parametername();

			    Parameter *node = new Parameter();
			    link(node, ((ParameterlistContext)_localctx).vartype.node);
			    link(node, ((ParameterlistContext)_localctx).parametername.node);
			    node->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
			    _localctx.nodes.push_back(node);

			}
			_ctx.stop = _input.LT(-1);
			setState(232);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new ParameterlistContext(_parentctx, _parentState);
					_localctx.pl1 = _prevctx;
					pushNewRecursionContext(_localctx, _startState, RULE_parameterlist);
					setState(225);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(226);
					match(T__15);
					setState(227);
					((ParameterlistContext)_localctx).pl2 = parameterlist(2);

					              _localctx.nodes.insert(_localctx.nodes.end(), ((ParameterlistContext)_localctx).pl1.nodes.begin(), ((ParameterlistContext)_localctx).pl1.nodes.end());
					              _localctx.nodes.insert(_localctx.nodes.end(), ((ParameterlistContext)_localctx).pl2.nodes.begin(), ((ParameterlistContext)_localctx).pl2.nodes.end());
					          
					}
					} 
				}
				setState(234);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
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
		public Expr * node;
		public ExprContext expr;
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
			setState(241);
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
				setState(237);
				((ExproptContext)_localctx).expr = expr(0);
				((ExproptContext)_localctx).node =  ((ExproptContext)_localctx).expr.node;
				}
				break;
			case T__3:
			case T__4:
				enterOuterAlt(_localctx, 2);
				{
				((ExproptContext)_localctx).node =  NULL;
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
		public Expr * node;
		public ExprContext e1;
		public Token INT;
		public Token CHAR;
		public ExprContext expr;
		public VarContext var;
		public FuncnameContext funcname;
		public ArgumentsContext arguments;
		public ParameternameContext parametername;
		public Token op;
		public ExprContext e2;
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
			setState(282);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,14,_ctx) ) {
			case 1:
				{
				setState(244);
				((ExprContext)_localctx).INT = match(INT);

				    ((ExprContext)_localctx).node =  new IntLiteralExpr(stoi((((ExprContext)_localctx).INT!=null?((ExprContext)_localctx).INT.getText():null)));
				    _localctx.node->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

				}
				break;
			case 2:
				{
				setState(246);
				((ExprContext)_localctx).CHAR = match(CHAR);

				    ((ExprContext)_localctx).node =  new CharLiteralExpr((((ExprContext)_localctx).CHAR!=null?((ExprContext)_localctx).CHAR.getText():null)[1]);
				    _localctx.node->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

				}
				break;
			case 3:
				{
				setState(248);
				match(T__20);

				    ((ExprContext)_localctx).node =  new BoolLiteralExpr(true);
				    _localctx.node->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

				}
				break;
			case 4:
				{
				setState(250);
				match(T__21);

				    ((ExprContext)_localctx).node =  new BoolLiteralExpr(false);
				    _localctx.node->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

				}
				break;
			case 5:
				{
				setState(252);
				match(T__22);
				setState(253);
				((ExprContext)_localctx).expr = expr(12);

				    ((ExprContext)_localctx).node =  createUnaryExpr("-", ((ExprContext)_localctx).expr.node);
				    _localctx.node->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

				}
				break;
			case 6:
				{
				setState(256);
				match(T__23);
				setState(257);
				((ExprContext)_localctx).expr = expr(11);

				    ((ExprContext)_localctx).node =  createUnaryExpr("!", ((ExprContext)_localctx).expr.node);
				    _localctx.node->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

				}
				break;
			case 7:
				{
				setState(260);
				((ExprContext)_localctx).var = var();
				setState(261);
				match(T__35);
				setState(262);
				((ExprContext)_localctx).expr = expr(5);

				    ((ExprContext)_localctx).node =  new AssignmentExpr();
				    link(_localctx.node, ((ExprContext)_localctx).var.node);
				    link(_localctx.node, ((ExprContext)_localctx).expr.node);
				    _localctx.node->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

				}
				break;
			case 8:
				{
				setState(265);
				match(T__2);
				setState(266);
				((ExprContext)_localctx).expr = expr(0);
				setState(267);
				match(T__3);
				((ExprContext)_localctx).node =  ((ExprContext)_localctx).expr.node;
				}
				break;
			case 9:
				{
				setState(270);
				((ExprContext)_localctx).var = var();

				    ((ExprContext)_localctx).node =  new VarExpr();
				    link(_localctx.node, ((ExprContext)_localctx).var.node);
				    _localctx.node->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

				}
				break;
			case 10:
				{
				setState(273);
				((ExprContext)_localctx).funcname = funcname();
				setState(274);
				match(T__2);
				setState(275);
				((ExprContext)_localctx).arguments = arguments();
				setState(276);
				match(T__3);

				    ((ExprContext)_localctx).node =  new CallExpr();
				    link(_localctx.node, ((ExprContext)_localctx).funcname.node);
				    link(_localctx.node, ((ExprContext)_localctx).arguments.nodes);
				    _localctx.node->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

				}
				break;
			case 11:
				{
				setState(279);
				((ExprContext)_localctx).parametername = parametername();

				    ((ExprContext)_localctx).node =  new VarExpr();
				    link(_localctx.node, ((ExprContext)_localctx).parametername.node);
				    _localctx.node->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(311);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,16,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(309);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,15,_ctx) ) {
					case 1:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						_localctx.e1 = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(284);
						if (!(precpred(_ctx, 10))) throw new FailedPredicateException(this, "precpred(_ctx, 10)");
						setState(285);
						((ExprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==T__24 || _la==T__25) ) {
							((ExprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(286);
						((ExprContext)_localctx).e2 = ((ExprContext)_localctx).expr = expr(11);

						              ((ExprContext)_localctx).node =  createBinaryExpr((((ExprContext)_localctx).op!=null?((ExprContext)_localctx).op.getText():null), ((ExprContext)_localctx).e1.node, ((ExprContext)_localctx).e2.node);
						              _localctx.node->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
						          
						}
						break;
					case 2:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						_localctx.e1 = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(289);
						if (!(precpred(_ctx, 9))) throw new FailedPredicateException(this, "precpred(_ctx, 9)");
						setState(290);
						((ExprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==T__22 || _la==T__26) ) {
							((ExprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(291);
						((ExprContext)_localctx).e2 = ((ExprContext)_localctx).expr = expr(10);

						              ((ExprContext)_localctx).node =  createBinaryExpr((((ExprContext)_localctx).op!=null?((ExprContext)_localctx).op.getText():null), ((ExprContext)_localctx).e1.node, ((ExprContext)_localctx).e2.node);
						              _localctx.node->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
						          
						}
						break;
					case 3:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						_localctx.e1 = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(294);
						if (!(precpred(_ctx, 8))) throw new FailedPredicateException(this, "precpred(_ctx, 8)");
						setState(295);
						((ExprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 16911433728L) != 0)) ) {
							((ExprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(296);
						((ExprContext)_localctx).e2 = ((ExprContext)_localctx).expr = expr(9);

						              ((ExprContext)_localctx).node =  createBinaryExpr((((ExprContext)_localctx).op!=null?((ExprContext)_localctx).op.getText():null), ((ExprContext)_localctx).e1.node, ((ExprContext)_localctx).e2.node);
						              _localctx.node->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
						          
						}
						break;
					case 4:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						_localctx.e1 = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(299);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(300);
						match(T__33);
						setState(301);
						((ExprContext)_localctx).e2 = ((ExprContext)_localctx).expr = expr(8);

						              ((ExprContext)_localctx).node =  createBinaryExpr("&&", ((ExprContext)_localctx).e1.node, ((ExprContext)_localctx).e2.node);
						              _localctx.node->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
						          
						}
						break;
					case 5:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						_localctx.e1 = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(304);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(305);
						match(T__34);
						setState(306);
						((ExprContext)_localctx).e2 = ((ExprContext)_localctx).expr = expr(7);

						              ((ExprContext)_localctx).node =  createBinaryExpr("||", ((ExprContext)_localctx).e1.node, ((ExprContext)_localctx).e2.node);
						              _localctx.node->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
						          
						}
						break;
					}
					} 
				}
				setState(313);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,16,_ctx);
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
		public VarReference * node;
		public VarnameContext varname;
		public ArraynameContext arrayname;
		public ExprContext expr;
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
			setState(323);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,17,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(314);
				((VarContext)_localctx).varname = varname();

				    ((VarContext)_localctx).node =  new VarReference();
				    link(_localctx.node, ((VarContext)_localctx).varname.node);

				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(317);
				((VarContext)_localctx).arrayname = arrayname();
				setState(318);
				match(T__13);
				setState(319);
				((VarContext)_localctx).expr = expr(0);
				setState(320);
				match(T__14);

				    ((VarContext)_localctx).node =  new VarReference();
				    link(_localctx.node, ((VarContext)_localctx).arrayname.node);
				    link(_localctx.node, ((VarContext)_localctx).expr.node);

				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			_localctx.node->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
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
		public std::vector<ASTNode*> nodes;
		public ArgumentlistContext argumentlist;
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
			setState(329);
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
				setState(325);
				((ArgumentsContext)_localctx).argumentlist = argumentlist(0);
				((ArgumentsContext)_localctx).nodes =  ((ArgumentsContext)_localctx).argumentlist.nodes;
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
		public std::vector<ASTNode*> nodes;
		public ArgumentlistContext al1;
		public ExprContext expr;
		public ArgumentlistContext al2;
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
			setState(332);
			((ArgumentlistContext)_localctx).expr = expr(0);
			_localctx.nodes.push_back(((ArgumentlistContext)_localctx).expr.node);
			}
			_ctx.stop = _input.LT(-1);
			setState(342);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,19,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new ArgumentlistContext(_parentctx, _parentState);
					_localctx.al1 = _prevctx;
					pushNewRecursionContext(_localctx, _startState, RULE_argumentlist);
					setState(335);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(336);
					match(T__15);
					setState(337);
					((ArgumentlistContext)_localctx).al2 = argumentlist(2);

					              _localctx.nodes.insert(_localctx.nodes.end(), ((ArgumentlistContext)_localctx).al1.nodes.begin(), ((ArgumentlistContext)_localctx).al1.nodes.end());
					              _localctx.nodes.insert(_localctx.nodes.end(), ((ArgumentlistContext)_localctx).al2.nodes.begin(), ((ArgumentlistContext)_localctx).al2.nodes.end());
					          
					}
					} 
				}
				setState(344);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,19,_ctx);
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
		public Identifier * node;
		public Token ID;
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
			setState(345);
			((VarnameContext)_localctx).ID = match(ID);

			    ((VarnameContext)_localctx).node =  new Identifier((((VarnameContext)_localctx).ID!=null?((VarnameContext)_localctx).ID.getText():null));
			    _localctx.node->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

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
		public Identifier * node;
		public Token ID;
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
			setState(348);
			((ArraynameContext)_localctx).ID = match(ID);

			    ((ArraynameContext)_localctx).node =  new Identifier((((ArraynameContext)_localctx).ID!=null?((ArraynameContext)_localctx).ID.getText():null));
			    _localctx.node->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

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
		public Identifier * node;
		public Token ID;
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
			setState(351);
			((FuncnameContext)_localctx).ID = match(ID);

			    ((FuncnameContext)_localctx).node =  new Identifier((((FuncnameContext)_localctx).ID!=null?((FuncnameContext)_localctx).ID.getText():null));
			    _localctx.node->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

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
		public Identifier * node;
		public Token ID;
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
			setState(354);
			((ParameternameContext)_localctx).ID = match(ID);

			    ((ParameternameContext)_localctx).node =  new Identifier((((ParameternameContext)_localctx).ID!=null?((ParameternameContext)_localctx).ID.getText():null));
			    _localctx.node->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

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
		"\u0004\u0001)\u0166\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
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
		"\u0001\u0002\u0001\u0002\u0003\u0002M\b\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0005\u0002S\b\u0002\n\u0002\f\u0002V\t\u0002"+
		"\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003"+
		"\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0005\u0003b\b\u0003"+
		"\n\u0003\f\u0003e\t\u0003\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0001\u0004\u0001\u0004\u0003\u0004t\b\u0004\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0005\u0005y\b\u0005\n\u0005\f\u0005|\t\u0005"+
		"\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006"+
		"\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006"+
		"\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006"+
		"\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006"+
		"\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006"+
		"\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006"+
		"\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006"+
		"\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006"+
		"\u0003\u0006\u00ae\b\u0006\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007"+
		"\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007"+
		"\u0003\u0007\u00ba\b\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007"+
		"\u0001\u0007\u0005\u0007\u00c1\b\u0007\n\u0007\f\u0007\u00c4\t\u0007\u0001"+
		"\b\u0001\b\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0003\t\u00ce"+
		"\b\t\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0003\n\u00d5\b\n\u0001\u000b"+
		"\u0001\u000b\u0001\u000b\u0001\u000b\u0003\u000b\u00db\b\u000b\u0001\f"+
		"\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0005\f\u00e7\b\f\n\f\f\f\u00ea\t\f\u0001\r\u0001\r\u0001\u000e\u0001"+
		"\u000e\u0001\u000e\u0001\u000e\u0003\u000e\u00f2\b\u000e\u0001\u000f\u0001"+
		"\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001"+
		"\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001"+
		"\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001"+
		"\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001"+
		"\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001"+
		"\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001"+
		"\u000f\u0001\u000f\u0003\u000f\u011b\b\u000f\u0001\u000f\u0001\u000f\u0001"+
		"\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001"+
		"\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001"+
		"\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001"+
		"\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0005\u000f\u0136"+
		"\b\u000f\n\u000f\f\u000f\u0139\t\u000f\u0001\u0010\u0001\u0010\u0001\u0010"+
		"\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010"+
		"\u0003\u0010\u0144\b\u0010\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011"+
		"\u0003\u0011\u014a\b\u0011\u0001\u0012\u0001\u0012\u0001\u0012\u0001\u0012"+
		"\u0001\u0012\u0001\u0012\u0001\u0012\u0001\u0012\u0001\u0012\u0005\u0012"+
		"\u0155\b\u0012\n\u0012\f\u0012\u0158\t\u0012\u0001\u0013\u0001\u0013\u0001"+
		"\u0013\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0015\u0001\u0015\u0001"+
		"\u0015\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0000\u0006\u0004"+
		"\u0006\u000e\u0018\u001e$\u0017\u0000\u0002\u0004\u0006\b\n\f\u000e\u0010"+
		"\u0012\u0014\u0016\u0018\u001a\u001c\u001e \"$&(*,\u0000\u0003\u0001\u0000"+
		"\u0019\u001a\u0002\u0000\u0017\u0017\u001b\u001b\u0001\u0000\u001c!\u0178"+
		"\u0000.\u0001\u0000\u0000\u0000\u00026\u0001\u0000\u0000\u0000\u0004L"+
		"\u0001\u0000\u0000\u0000\u0006W\u0001\u0000\u0000\u0000\bs\u0001\u0000"+
		"\u0000\u0000\nz\u0001\u0000\u0000\u0000\f\u00ad\u0001\u0000\u0000\u0000"+
		"\u000e\u00b9\u0001\u0000\u0000\u0000\u0010\u00c5\u0001\u0000\u0000\u0000"+
		"\u0012\u00cd\u0001\u0000\u0000\u0000\u0014\u00d4\u0001\u0000\u0000\u0000"+
		"\u0016\u00da\u0001\u0000\u0000\u0000\u0018\u00dc\u0001\u0000\u0000\u0000"+
		"\u001a\u00eb\u0001\u0000\u0000\u0000\u001c\u00f1\u0001\u0000\u0000\u0000"+
		"\u001e\u011a\u0001\u0000\u0000\u0000 \u0143\u0001\u0000\u0000\u0000\""+
		"\u0149\u0001\u0000\u0000\u0000$\u014b\u0001\u0000\u0000\u0000&\u0159\u0001"+
		"\u0000\u0000\u0000(\u015c\u0001\u0000\u0000\u0000*\u015f\u0001\u0000\u0000"+
		"\u0000,\u0162\u0001\u0000\u0000\u0000./\u0003\u0002\u0001\u0000/0\u0003"+
		"\u0004\u0002\u000001\u0006\u0000\uffff\uffff\u00001\u0001\u0001\u0000"+
		"\u0000\u000023\u0005\u0001\u0000\u000034\u0005\u0002\u0000\u000047\u0006"+
		"\u0001\uffff\uffff\u000057\u0006\u0001\uffff\uffff\u000062\u0001\u0000"+
		"\u0000\u000065\u0001\u0000\u0000\u00007\u0003\u0001\u0000\u0000\u0000"+
		"89\u0006\u0002\uffff\uffff\u00009:\u0003\u0006\u0003\u0000:;\u0006\u0002"+
		"\uffff\uffff\u0000;M\u0001\u0000\u0000\u0000<=\u0003\u0014\n\u0000=>\u0003"+
		"*\u0015\u0000>?\u0005\u0003\u0000\u0000?@\u0003\u0016\u000b\u0000@A\u0005"+
		"\u0004\u0000\u0000AB\u0003\b\u0004\u0000BC\u0006\u0002\uffff\uffff\u0000"+
		"CM\u0001\u0000\u0000\u0000DE\u0003\u0014\n\u0000EF\u0003*\u0015\u0000"+
		"FG\u0005\u0003\u0000\u0000GH\u0003\u0016\u000b\u0000HI\u0005\u0004\u0000"+
		"\u0000IJ\u0005\u0005\u0000\u0000JK\u0006\u0002\uffff\uffff\u0000KM\u0001"+
		"\u0000\u0000\u0000L8\u0001\u0000\u0000\u0000L<\u0001\u0000\u0000\u0000"+
		"LD\u0001\u0000\u0000\u0000MT\u0001\u0000\u0000\u0000NO\n\u0001\u0000\u0000"+
		"OP\u0003\u0004\u0002\u0002PQ\u0006\u0002\uffff\uffff\u0000QS\u0001\u0000"+
		"\u0000\u0000RN\u0001\u0000\u0000\u0000SV\u0001\u0000\u0000\u0000TR\u0001"+
		"\u0000\u0000\u0000TU\u0001\u0000\u0000\u0000U\u0005\u0001\u0000\u0000"+
		"\u0000VT\u0001\u0000\u0000\u0000WX\u0006\u0003\uffff\uffff\u0000XY\u0003"+
		"\u0012\t\u0000YZ\u0003\u000e\u0007\u0000Z[\u0005\u0005\u0000\u0000[\\"+
		"\u0006\u0003\uffff\uffff\u0000\\c\u0001\u0000\u0000\u0000]^\n\u0001\u0000"+
		"\u0000^_\u0003\u0006\u0003\u0002_`\u0006\u0003\uffff\uffff\u0000`b\u0001"+
		"\u0000\u0000\u0000a]\u0001\u0000\u0000\u0000be\u0001\u0000\u0000\u0000"+
		"ca\u0001\u0000\u0000\u0000cd\u0001\u0000\u0000\u0000d\u0007\u0001\u0000"+
		"\u0000\u0000ec\u0001\u0000\u0000\u0000fg\u0005\u0006\u0000\u0000gh\u0003"+
		"\u0006\u0003\u0000hi\u0003\n\u0005\u0000ij\u0005\u0007\u0000\u0000jk\u0006"+
		"\u0004\uffff\uffff\u0000kt\u0001\u0000\u0000\u0000lm\u0005\u0006\u0000"+
		"\u0000mn\u0003\n\u0005\u0000no\u0005\u0007\u0000\u0000op\u0006\u0004\uffff"+
		"\uffff\u0000pt\u0001\u0000\u0000\u0000qr\u0005\u0006\u0000\u0000rt\u0005"+
		"\u0007\u0000\u0000sf\u0001\u0000\u0000\u0000sl\u0001\u0000\u0000\u0000"+
		"sq\u0001\u0000\u0000\u0000t\t\u0001\u0000\u0000\u0000uv\u0003\f\u0006"+
		"\u0000vw\u0006\u0005\uffff\uffff\u0000wy\u0001\u0000\u0000\u0000xu\u0001"+
		"\u0000\u0000\u0000y|\u0001\u0000\u0000\u0000zx\u0001\u0000\u0000\u0000"+
		"z{\u0001\u0000\u0000\u0000{\u000b\u0001\u0000\u0000\u0000|z\u0001\u0000"+
		"\u0000\u0000}~\u0003\u001e\u000f\u0000~\u007f\u0005\u0005\u0000\u0000"+
		"\u007f\u0080\u0006\u0006\uffff\uffff\u0000\u0080\u00ae\u0001\u0000\u0000"+
		"\u0000\u0081\u0082\u0005\b\u0000\u0000\u0082\u0083\u0005\u0003\u0000\u0000"+
		"\u0083\u0084\u0003\u001e\u000f\u0000\u0084\u0085\u0005\u0004\u0000\u0000"+
		"\u0085\u0086\u0003\f\u0006\u0000\u0086\u0087\u0005\t\u0000\u0000\u0087"+
		"\u0088\u0003\f\u0006\u0000\u0088\u0089\u0006\u0006\uffff\uffff\u0000\u0089"+
		"\u00ae\u0001\u0000\u0000\u0000\u008a\u008b\u0005\b\u0000\u0000\u008b\u008c"+
		"\u0005\u0003\u0000\u0000\u008c\u008d\u0003\u001e\u000f\u0000\u008d\u008e"+
		"\u0005\u0004\u0000\u0000\u008e\u008f\u0003\f\u0006\u0000\u008f\u0090\u0006"+
		"\u0006\uffff\uffff\u0000\u0090\u00ae\u0001\u0000\u0000\u0000\u0091\u0092"+
		"\u0005\n\u0000\u0000\u0092\u0093\u0005\u0003\u0000\u0000\u0093\u0094\u0003"+
		"\u001c\u000e\u0000\u0094\u0095\u0005\u0005\u0000\u0000\u0095\u0096\u0003"+
		"\u001c\u000e\u0000\u0096\u0097\u0005\u0005\u0000\u0000\u0097\u0098\u0003"+
		"\u001c\u000e\u0000\u0098\u0099\u0005\u0004\u0000\u0000\u0099\u009a\u0003"+
		"\f\u0006\u0000\u009a\u009b\u0006\u0006\uffff\uffff\u0000\u009b\u00ae\u0001"+
		"\u0000\u0000\u0000\u009c\u009d\u0005\u000b\u0000\u0000\u009d\u009e\u0005"+
		"\u0005\u0000\u0000\u009e\u00ae\u0006\u0006\uffff\uffff\u0000\u009f\u00a0"+
		"\u0005\f\u0000\u0000\u00a0\u00a1\u0005\u0005\u0000\u0000\u00a1\u00ae\u0006"+
		"\u0006\uffff\uffff\u0000\u00a2\u00a3\u0005\r\u0000\u0000\u00a3\u00a4\u0005"+
		"\u0005\u0000\u0000\u00a4\u00ae\u0006\u0006\uffff\uffff\u0000\u00a5\u00a6"+
		"\u0005\r\u0000\u0000\u00a6\u00a7\u0003\u001e\u000f\u0000\u00a7\u00a8\u0005"+
		"\u0005\u0000\u0000\u00a8\u00a9\u0006\u0006\uffff\uffff\u0000\u00a9\u00ae"+
		"\u0001\u0000\u0000\u0000\u00aa\u00ab\u0003\b\u0004\u0000\u00ab\u00ac\u0006"+
		"\u0006\uffff\uffff\u0000\u00ac\u00ae\u0001\u0000\u0000\u0000\u00ad}\u0001"+
		"\u0000\u0000\u0000\u00ad\u0081\u0001\u0000\u0000\u0000\u00ad\u008a\u0001"+
		"\u0000\u0000\u0000\u00ad\u0091\u0001\u0000\u0000\u0000\u00ad\u009c\u0001"+
		"\u0000\u0000\u0000\u00ad\u009f\u0001\u0000\u0000\u0000\u00ad\u00a2\u0001"+
		"\u0000\u0000\u0000\u00ad\u00a5\u0001\u0000\u0000\u0000\u00ad\u00aa\u0001"+
		"\u0000\u0000\u0000\u00ae\r\u0001\u0000\u0000\u0000\u00af\u00b0\u0006\u0007"+
		"\uffff\uffff\u0000\u00b0\u00b1\u0003&\u0013\u0000\u00b1\u00b2\u0006\u0007"+
		"\uffff\uffff\u0000\u00b2\u00ba\u0001\u0000\u0000\u0000\u00b3\u00b4\u0003"+
		"&\u0013\u0000\u00b4\u00b5\u0005\u000e\u0000\u0000\u00b5\u00b6\u0005&\u0000"+
		"\u0000\u00b6\u00b7\u0005\u000f\u0000\u0000\u00b7\u00b8\u0006\u0007\uffff"+
		"\uffff\u0000\u00b8\u00ba\u0001\u0000\u0000\u0000\u00b9\u00af\u0001\u0000"+
		"\u0000\u0000\u00b9\u00b3\u0001\u0000\u0000\u0000\u00ba\u00c2\u0001\u0000"+
		"\u0000\u0000\u00bb\u00bc\n\u0001\u0000\u0000\u00bc\u00bd\u0005\u0010\u0000"+
		"\u0000\u00bd\u00be\u0003\u000e\u0007\u0002\u00be\u00bf\u0006\u0007\uffff"+
		"\uffff\u0000\u00bf\u00c1\u0001\u0000\u0000\u0000\u00c0\u00bb\u0001\u0000"+
		"\u0000\u0000\u00c1\u00c4\u0001\u0000\u0000\u0000\u00c2\u00c0\u0001\u0000"+
		"\u0000\u0000\u00c2\u00c3\u0001\u0000\u0000\u0000\u00c3\u000f\u0001\u0000"+
		"\u0000\u0000\u00c4\u00c2\u0001\u0000\u0000\u0000\u00c5\u00c6\u0001\u0000"+
		"\u0000\u0000\u00c6\u0011\u0001\u0000\u0000\u0000\u00c7\u00c8\u0005\u0011"+
		"\u0000\u0000\u00c8\u00ce\u0006\t\uffff\uffff\u0000\u00c9\u00ca\u0005\u0012"+
		"\u0000\u0000\u00ca\u00ce\u0006\t\uffff\uffff\u0000\u00cb\u00cc\u0005\u0013"+
		"\u0000\u0000\u00cc\u00ce\u0006\t\uffff\uffff\u0000\u00cd\u00c7\u0001\u0000"+
		"\u0000\u0000\u00cd\u00c9\u0001\u0000\u0000\u0000\u00cd\u00cb\u0001\u0000"+
		"\u0000\u0000\u00ce\u0013\u0001\u0000\u0000\u0000\u00cf\u00d0\u0005\u0014"+
		"\u0000\u0000\u00d0\u00d5\u0006\n\uffff\uffff\u0000\u00d1\u00d2\u0003\u0012"+
		"\t\u0000\u00d2\u00d3\u0006\n\uffff\uffff\u0000\u00d3\u00d5\u0001\u0000"+
		"\u0000\u0000\u00d4\u00cf\u0001\u0000\u0000\u0000\u00d4\u00d1\u0001\u0000"+
		"\u0000\u0000\u00d5\u0015\u0001\u0000\u0000\u0000\u00d6\u00db\u0001\u0000"+
		"\u0000\u0000\u00d7\u00d8\u0003\u0018\f\u0000\u00d8\u00d9\u0006\u000b\uffff"+
		"\uffff\u0000\u00d9\u00db\u0001\u0000\u0000\u0000\u00da\u00d6\u0001\u0000"+
		"\u0000\u0000\u00da\u00d7\u0001\u0000\u0000\u0000\u00db\u0017\u0001\u0000"+
		"\u0000\u0000\u00dc\u00dd\u0006\f\uffff\uffff\u0000\u00dd\u00de\u0003\u0012"+
		"\t\u0000\u00de\u00df\u0003,\u0016\u0000\u00df\u00e0\u0006\f\uffff\uffff"+
		"\u0000\u00e0\u00e8\u0001\u0000\u0000\u0000\u00e1\u00e2\n\u0001\u0000\u0000"+
		"\u00e2\u00e3\u0005\u0010\u0000\u0000\u00e3\u00e4\u0003\u0018\f\u0002\u00e4"+
		"\u00e5\u0006\f\uffff\uffff\u0000\u00e5\u00e7\u0001\u0000\u0000\u0000\u00e6"+
		"\u00e1\u0001\u0000\u0000\u0000\u00e7\u00ea\u0001\u0000\u0000\u0000\u00e8"+
		"\u00e6\u0001\u0000\u0000\u0000\u00e8\u00e9\u0001\u0000\u0000\u0000\u00e9"+
		"\u0019\u0001\u0000\u0000\u0000\u00ea\u00e8\u0001\u0000\u0000\u0000\u00eb"+
		"\u00ec\u0001\u0000\u0000\u0000\u00ec\u001b\u0001\u0000\u0000\u0000\u00ed"+
		"\u00ee\u0003\u001e\u000f\u0000\u00ee\u00ef\u0006\u000e\uffff\uffff\u0000"+
		"\u00ef\u00f2\u0001\u0000\u0000\u0000\u00f0\u00f2\u0006\u000e\uffff\uffff"+
		"\u0000\u00f1\u00ed\u0001\u0000\u0000\u0000\u00f1\u00f0\u0001\u0000\u0000"+
		"\u0000\u00f2\u001d\u0001\u0000\u0000\u0000\u00f3\u00f4\u0006\u000f\uffff"+
		"\uffff\u0000\u00f4\u00f5\u0005&\u0000\u0000\u00f5\u011b\u0006\u000f\uffff"+
		"\uffff\u0000\u00f6\u00f7\u0005\'\u0000\u0000\u00f7\u011b\u0006\u000f\uffff"+
		"\uffff\u0000\u00f8\u00f9\u0005\u0015\u0000\u0000\u00f9\u011b\u0006\u000f"+
		"\uffff\uffff\u0000\u00fa\u00fb\u0005\u0016\u0000\u0000\u00fb\u011b\u0006"+
		"\u000f\uffff\uffff\u0000\u00fc\u00fd\u0005\u0017\u0000\u0000\u00fd\u00fe"+
		"\u0003\u001e\u000f\f\u00fe\u00ff\u0006\u000f\uffff\uffff\u0000\u00ff\u011b"+
		"\u0001\u0000\u0000\u0000\u0100\u0101\u0005\u0018\u0000\u0000\u0101\u0102"+
		"\u0003\u001e\u000f\u000b\u0102\u0103\u0006\u000f\uffff\uffff\u0000\u0103"+
		"\u011b\u0001\u0000\u0000\u0000\u0104\u0105\u0003 \u0010\u0000\u0105\u0106"+
		"\u0005$\u0000\u0000\u0106\u0107\u0003\u001e\u000f\u0005\u0107\u0108\u0006"+
		"\u000f\uffff\uffff\u0000\u0108\u011b\u0001\u0000\u0000\u0000\u0109\u010a"+
		"\u0005\u0003\u0000\u0000\u010a\u010b\u0003\u001e\u000f\u0000\u010b\u010c"+
		"\u0005\u0004\u0000\u0000\u010c\u010d\u0006\u000f\uffff\uffff\u0000\u010d"+
		"\u011b\u0001\u0000\u0000\u0000\u010e\u010f\u0003 \u0010\u0000\u010f\u0110"+
		"\u0006\u000f\uffff\uffff\u0000\u0110\u011b\u0001\u0000\u0000\u0000\u0111"+
		"\u0112\u0003*\u0015\u0000\u0112\u0113\u0005\u0003\u0000\u0000\u0113\u0114"+
		"\u0003\"\u0011\u0000\u0114\u0115\u0005\u0004\u0000\u0000\u0115\u0116\u0006"+
		"\u000f\uffff\uffff\u0000\u0116\u011b\u0001\u0000\u0000\u0000\u0117\u0118"+
		"\u0003,\u0016\u0000\u0118\u0119\u0006\u000f\uffff\uffff\u0000\u0119\u011b"+
		"\u0001\u0000\u0000\u0000\u011a\u00f3\u0001\u0000\u0000\u0000\u011a\u00f6"+
		"\u0001\u0000\u0000\u0000\u011a\u00f8\u0001\u0000\u0000\u0000\u011a\u00fa"+
		"\u0001\u0000\u0000\u0000\u011a\u00fc\u0001\u0000\u0000\u0000\u011a\u0100"+
		"\u0001\u0000\u0000\u0000\u011a\u0104\u0001\u0000\u0000\u0000\u011a\u0109"+
		"\u0001\u0000\u0000\u0000\u011a\u010e\u0001\u0000\u0000\u0000\u011a\u0111"+
		"\u0001\u0000\u0000\u0000\u011a\u0117\u0001\u0000\u0000\u0000\u011b\u0137"+
		"\u0001\u0000\u0000\u0000\u011c\u011d\n\n\u0000\u0000\u011d\u011e\u0007"+
		"\u0000\u0000\u0000\u011e\u011f\u0003\u001e\u000f\u000b\u011f\u0120\u0006"+
		"\u000f\uffff\uffff\u0000\u0120\u0136\u0001\u0000\u0000\u0000\u0121\u0122"+
		"\n\t\u0000\u0000\u0122\u0123\u0007\u0001\u0000\u0000\u0123\u0124\u0003"+
		"\u001e\u000f\n\u0124\u0125\u0006\u000f\uffff\uffff\u0000\u0125\u0136\u0001"+
		"\u0000\u0000\u0000\u0126\u0127\n\b\u0000\u0000\u0127\u0128\u0007\u0002"+
		"\u0000\u0000\u0128\u0129\u0003\u001e\u000f\t\u0129\u012a\u0006\u000f\uffff"+
		"\uffff\u0000\u012a\u0136\u0001\u0000\u0000\u0000\u012b\u012c\n\u0007\u0000"+
		"\u0000\u012c\u012d\u0005\"\u0000\u0000\u012d\u012e\u0003\u001e\u000f\b"+
		"\u012e\u012f\u0006\u000f\uffff\uffff\u0000\u012f\u0136\u0001\u0000\u0000"+
		"\u0000\u0130\u0131\n\u0006\u0000\u0000\u0131\u0132\u0005#\u0000\u0000"+
		"\u0132\u0133\u0003\u001e\u000f\u0007\u0133\u0134\u0006\u000f\uffff\uffff"+
		"\u0000\u0134\u0136\u0001\u0000\u0000\u0000\u0135\u011c\u0001\u0000\u0000"+
		"\u0000\u0135\u0121\u0001\u0000\u0000\u0000\u0135\u0126\u0001\u0000\u0000"+
		"\u0000\u0135\u012b\u0001\u0000\u0000\u0000\u0135\u0130\u0001\u0000\u0000"+
		"\u0000\u0136\u0139\u0001\u0000\u0000\u0000\u0137\u0135\u0001\u0000\u0000"+
		"\u0000\u0137\u0138\u0001\u0000\u0000\u0000\u0138\u001f\u0001\u0000\u0000"+
		"\u0000\u0139\u0137\u0001\u0000\u0000\u0000\u013a\u013b\u0003&\u0013\u0000"+
		"\u013b\u013c\u0006\u0010\uffff\uffff\u0000\u013c\u0144\u0001\u0000\u0000"+
		"\u0000\u013d\u013e\u0003(\u0014\u0000\u013e\u013f\u0005\u000e\u0000\u0000"+
		"\u013f\u0140\u0003\u001e\u000f\u0000\u0140\u0141\u0005\u000f\u0000\u0000"+
		"\u0141\u0142\u0006\u0010\uffff\uffff\u0000\u0142\u0144\u0001\u0000\u0000"+
		"\u0000\u0143\u013a\u0001\u0000\u0000\u0000\u0143\u013d\u0001\u0000\u0000"+
		"\u0000\u0144!\u0001\u0000\u0000\u0000\u0145\u0146\u0003$\u0012\u0000\u0146"+
		"\u0147\u0006\u0011\uffff\uffff\u0000\u0147\u014a\u0001\u0000\u0000\u0000"+
		"\u0148\u014a\u0001\u0000\u0000\u0000\u0149\u0145\u0001\u0000\u0000\u0000"+
		"\u0149\u0148\u0001\u0000\u0000\u0000\u014a#\u0001\u0000\u0000\u0000\u014b"+
		"\u014c\u0006\u0012\uffff\uffff\u0000\u014c\u014d\u0003\u001e\u000f\u0000"+
		"\u014d\u014e\u0006\u0012\uffff\uffff\u0000\u014e\u0156\u0001\u0000\u0000"+
		"\u0000\u014f\u0150\n\u0001\u0000\u0000\u0150\u0151\u0005\u0010\u0000\u0000"+
		"\u0151\u0152\u0003$\u0012\u0002\u0152\u0153\u0006\u0012\uffff\uffff\u0000"+
		"\u0153\u0155\u0001\u0000\u0000\u0000\u0154\u014f\u0001\u0000\u0000\u0000"+
		"\u0155\u0158\u0001\u0000\u0000\u0000\u0156\u0154\u0001\u0000\u0000\u0000"+
		"\u0156\u0157\u0001\u0000\u0000\u0000\u0157%\u0001\u0000\u0000\u0000\u0158"+
		"\u0156\u0001\u0000\u0000\u0000\u0159\u015a\u0005%\u0000\u0000\u015a\u015b"+
		"\u0006\u0013\uffff\uffff\u0000\u015b\'\u0001\u0000\u0000\u0000\u015c\u015d"+
		"\u0005%\u0000\u0000\u015d\u015e\u0006\u0014\uffff\uffff\u0000\u015e)\u0001"+
		"\u0000\u0000\u0000\u015f\u0160\u0005%\u0000\u0000\u0160\u0161\u0006\u0015"+
		"\uffff\uffff\u0000\u0161+\u0001\u0000\u0000\u0000\u0162\u0163\u0005%\u0000"+
		"\u0000\u0163\u0164\u0006\u0016\uffff\uffff\u0000\u0164-\u0001\u0000\u0000"+
		"\u0000\u00146LTcsz\u00ad\u00b9\u00c2\u00cd\u00d4\u00da\u00e8\u00f1\u011a"+
		"\u0135\u0137\u0143\u0149\u0156";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}