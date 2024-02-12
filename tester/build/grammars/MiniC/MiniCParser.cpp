
#include <vector>
#include "Program.h"
#include "Declarations.h"
#include "Statements.h"
#include "Exprs.h"
#include "Terms.h"


// Generated from /home/hasti2c/Documents/csc488/assignments/code/grammars/MiniC.g4 by ANTLR 4.11.1


#include "MiniCListener.h"
#include "MiniCVisitor.h"

#include "MiniCParser.h"


using namespace antlrcpp;
using namespace minicc;

using namespace antlr4;

namespace {

struct MiniCParserStaticData final {
  MiniCParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  MiniCParserStaticData(const MiniCParserStaticData&) = delete;
  MiniCParserStaticData(MiniCParserStaticData&&) = delete;
  MiniCParserStaticData& operator=(const MiniCParserStaticData&) = delete;
  MiniCParserStaticData& operator=(MiniCParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag minicParserOnceFlag;
MiniCParserStaticData *minicParserStaticData = nullptr;

void minicParserInitialize() {
  assert(minicParserStaticData == nullptr);
  auto staticData = std::make_unique<MiniCParserStaticData>(
    std::vector<std::string>{
      "prog", "preamble", "decl", "vardecl", "scope", "stmtlist", "stmt", 
      "varlist", "varlistentry", "vartype", "rettype", "parameters", "parameterlist", 
      "parameterentry", "expropt", "expr", "var", "arguments", "argumentlist", 
      "varname", "arrayname", "funcname", "parametername"
    },
    std::vector<std::string>{
      "", "'#include'", "'\"minicio.h\"'", "'('", "')'", "';'", "'{'", "'}'", 
      "'if'", "'else'", "'for'", "'continue;'", "'break'", "'return'", "'['", 
      "']'", "','", "'int'", "'bool'", "'char'", "'void'", "'true'", "'false'", 
      "'-'", "'!'", "'*'", "'/'", "'+'", "'=='", "'!='", "'<'", "'<='", 
      "'>'", "'>='", "'&&'", "'||'", "'='"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "ID", "INT", "CHAR", "WS", "COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,41,274,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,1,0,1,0,1,0,1,1,1,1,1,1,3,1,53,8,1,1,2,1,2,1,2,1,2,1,2,1,
  	2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,71,8,2,1,2,1,2,5,2,75,8,
  	2,10,2,12,2,78,9,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,5,3,87,8,3,10,3,12,3,90,
  	9,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,3,4,103,8,4,1,5,5,5,106,
  	8,5,10,5,12,5,109,9,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,
  	1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,
  	6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,3,6,148,8,6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,
  	3,7,157,8,7,1,7,1,7,1,7,5,7,162,8,7,10,7,12,7,165,9,7,1,8,1,8,1,9,1,9,
  	1,10,1,10,3,10,173,8,10,1,11,1,11,3,11,177,8,11,1,12,1,12,1,12,1,12,1,
  	12,1,12,1,12,5,12,186,8,12,10,12,12,12,189,9,12,1,13,1,13,1,14,1,14,3,
  	14,195,8,14,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,
  	15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,3,15,221,
  	8,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,
  	1,15,1,15,5,15,238,8,15,10,15,12,15,241,9,15,1,16,1,16,1,16,1,16,1,16,
  	1,16,3,16,249,8,16,1,17,1,17,3,17,253,8,17,1,18,1,18,1,18,1,18,1,18,1,
  	18,5,18,261,8,18,10,18,12,18,264,9,18,1,19,1,19,1,20,1,20,1,21,1,21,1,
  	22,1,22,1,22,0,6,4,6,14,24,30,36,23,0,2,4,6,8,10,12,14,16,18,20,22,24,
  	26,28,30,32,34,36,38,40,42,44,0,4,1,0,17,19,1,0,25,26,2,0,23,23,27,27,
  	1,0,28,33,290,0,46,1,0,0,0,2,52,1,0,0,0,4,70,1,0,0,0,6,79,1,0,0,0,8,102,
  	1,0,0,0,10,107,1,0,0,0,12,147,1,0,0,0,14,156,1,0,0,0,16,166,1,0,0,0,18,
  	168,1,0,0,0,20,172,1,0,0,0,22,176,1,0,0,0,24,178,1,0,0,0,26,190,1,0,0,
  	0,28,194,1,0,0,0,30,220,1,0,0,0,32,248,1,0,0,0,34,252,1,0,0,0,36,254,
  	1,0,0,0,38,265,1,0,0,0,40,267,1,0,0,0,42,269,1,0,0,0,44,271,1,0,0,0,46,
  	47,3,2,1,0,47,48,3,4,2,0,48,1,1,0,0,0,49,50,5,1,0,0,50,53,5,2,0,0,51,
  	53,1,0,0,0,52,49,1,0,0,0,52,51,1,0,0,0,53,3,1,0,0,0,54,55,6,2,-1,0,55,
  	71,3,6,3,0,56,57,3,20,10,0,57,58,3,42,21,0,58,59,5,3,0,0,59,60,3,22,11,
  	0,60,61,5,4,0,0,61,62,3,8,4,0,62,71,1,0,0,0,63,64,3,20,10,0,64,65,3,42,
  	21,0,65,66,5,3,0,0,66,67,3,22,11,0,67,68,5,4,0,0,68,69,5,5,0,0,69,71,
  	1,0,0,0,70,54,1,0,0,0,70,56,1,0,0,0,70,63,1,0,0,0,71,76,1,0,0,0,72,73,
  	10,1,0,0,73,75,3,4,2,2,74,72,1,0,0,0,75,78,1,0,0,0,76,74,1,0,0,0,76,77,
  	1,0,0,0,77,5,1,0,0,0,78,76,1,0,0,0,79,80,6,3,-1,0,80,81,3,18,9,0,81,82,
  	3,14,7,0,82,83,5,5,0,0,83,88,1,0,0,0,84,85,10,1,0,0,85,87,3,6,3,2,86,
  	84,1,0,0,0,87,90,1,0,0,0,88,86,1,0,0,0,88,89,1,0,0,0,89,7,1,0,0,0,90,
  	88,1,0,0,0,91,92,5,6,0,0,92,93,3,6,3,0,93,94,3,10,5,0,94,95,5,7,0,0,95,
  	103,1,0,0,0,96,97,5,6,0,0,97,98,3,10,5,0,98,99,5,7,0,0,99,103,1,0,0,0,
  	100,101,5,6,0,0,101,103,5,7,0,0,102,91,1,0,0,0,102,96,1,0,0,0,102,100,
  	1,0,0,0,103,9,1,0,0,0,104,106,3,12,6,0,105,104,1,0,0,0,106,109,1,0,0,
  	0,107,105,1,0,0,0,107,108,1,0,0,0,108,11,1,0,0,0,109,107,1,0,0,0,110,
  	111,3,30,15,0,111,112,5,5,0,0,112,148,1,0,0,0,113,114,5,8,0,0,114,115,
  	5,3,0,0,115,116,3,30,15,0,116,117,5,4,0,0,117,118,3,12,6,0,118,119,5,
  	9,0,0,119,120,3,12,6,0,120,148,1,0,0,0,121,122,5,8,0,0,122,123,5,3,0,
  	0,123,124,3,30,15,0,124,125,5,4,0,0,125,126,3,12,6,0,126,148,1,0,0,0,
  	127,128,5,10,0,0,128,129,5,3,0,0,129,130,3,28,14,0,130,131,5,5,0,0,131,
  	132,3,28,14,0,132,133,5,5,0,0,133,134,3,28,14,0,134,135,5,4,0,0,135,136,
  	3,12,6,0,136,148,1,0,0,0,137,148,5,11,0,0,138,139,5,12,0,0,139,148,5,
  	5,0,0,140,141,5,13,0,0,141,148,5,5,0,0,142,143,5,13,0,0,143,144,3,30,
  	15,0,144,145,5,5,0,0,145,148,1,0,0,0,146,148,3,8,4,0,147,110,1,0,0,0,
  	147,113,1,0,0,0,147,121,1,0,0,0,147,127,1,0,0,0,147,137,1,0,0,0,147,138,
  	1,0,0,0,147,140,1,0,0,0,147,142,1,0,0,0,147,146,1,0,0,0,148,13,1,0,0,
  	0,149,150,6,7,-1,0,150,157,3,38,19,0,151,152,3,38,19,0,152,153,5,14,0,
  	0,153,154,5,38,0,0,154,155,5,15,0,0,155,157,1,0,0,0,156,149,1,0,0,0,156,
  	151,1,0,0,0,157,163,1,0,0,0,158,159,10,1,0,0,159,160,5,16,0,0,160,162,
  	3,14,7,2,161,158,1,0,0,0,162,165,1,0,0,0,163,161,1,0,0,0,163,164,1,0,
  	0,0,164,15,1,0,0,0,165,163,1,0,0,0,166,167,1,0,0,0,167,17,1,0,0,0,168,
  	169,7,0,0,0,169,19,1,0,0,0,170,173,5,20,0,0,171,173,3,18,9,0,172,170,
  	1,0,0,0,172,171,1,0,0,0,173,21,1,0,0,0,174,177,1,0,0,0,175,177,3,24,12,
  	0,176,174,1,0,0,0,176,175,1,0,0,0,177,23,1,0,0,0,178,179,6,12,-1,0,179,
  	180,3,18,9,0,180,181,3,44,22,0,181,187,1,0,0,0,182,183,10,1,0,0,183,184,
  	5,16,0,0,184,186,3,24,12,2,185,182,1,0,0,0,186,189,1,0,0,0,187,185,1,
  	0,0,0,187,188,1,0,0,0,188,25,1,0,0,0,189,187,1,0,0,0,190,191,1,0,0,0,
  	191,27,1,0,0,0,192,195,3,30,15,0,193,195,1,0,0,0,194,192,1,0,0,0,194,
  	193,1,0,0,0,195,29,1,0,0,0,196,197,6,15,-1,0,197,221,5,38,0,0,198,221,
  	5,39,0,0,199,221,5,21,0,0,200,221,5,22,0,0,201,202,5,23,0,0,202,221,3,
  	30,15,12,203,204,5,24,0,0,204,221,3,30,15,11,205,206,3,32,16,0,206,207,
  	5,36,0,0,207,208,3,30,15,5,208,221,1,0,0,0,209,210,5,3,0,0,210,211,3,
  	30,15,0,211,212,5,4,0,0,212,221,1,0,0,0,213,221,3,32,16,0,214,215,3,42,
  	21,0,215,216,5,3,0,0,216,217,3,34,17,0,217,218,5,4,0,0,218,221,1,0,0,
  	0,219,221,3,44,22,0,220,196,1,0,0,0,220,198,1,0,0,0,220,199,1,0,0,0,220,
  	200,1,0,0,0,220,201,1,0,0,0,220,203,1,0,0,0,220,205,1,0,0,0,220,209,1,
  	0,0,0,220,213,1,0,0,0,220,214,1,0,0,0,220,219,1,0,0,0,221,239,1,0,0,0,
  	222,223,10,10,0,0,223,224,7,1,0,0,224,238,3,30,15,11,225,226,10,9,0,0,
  	226,227,7,2,0,0,227,238,3,30,15,10,228,229,10,8,0,0,229,230,7,3,0,0,230,
  	238,3,30,15,9,231,232,10,7,0,0,232,233,5,34,0,0,233,238,3,30,15,8,234,
  	235,10,6,0,0,235,236,5,35,0,0,236,238,3,30,15,7,237,222,1,0,0,0,237,225,
  	1,0,0,0,237,228,1,0,0,0,237,231,1,0,0,0,237,234,1,0,0,0,238,241,1,0,0,
  	0,239,237,1,0,0,0,239,240,1,0,0,0,240,31,1,0,0,0,241,239,1,0,0,0,242,
  	249,3,38,19,0,243,244,3,40,20,0,244,245,5,14,0,0,245,246,3,30,15,0,246,
  	247,5,15,0,0,247,249,1,0,0,0,248,242,1,0,0,0,248,243,1,0,0,0,249,33,1,
  	0,0,0,250,253,3,36,18,0,251,253,1,0,0,0,252,250,1,0,0,0,252,251,1,0,0,
  	0,253,35,1,0,0,0,254,255,6,18,-1,0,255,256,3,30,15,0,256,262,1,0,0,0,
  	257,258,10,1,0,0,258,259,5,16,0,0,259,261,3,36,18,2,260,257,1,0,0,0,261,
  	264,1,0,0,0,262,260,1,0,0,0,262,263,1,0,0,0,263,37,1,0,0,0,264,262,1,
  	0,0,0,265,266,5,37,0,0,266,39,1,0,0,0,267,268,5,37,0,0,268,41,1,0,0,0,
  	269,270,5,37,0,0,270,43,1,0,0,0,271,272,5,37,0,0,272,45,1,0,0,0,19,52,
  	70,76,88,102,107,147,156,163,172,176,187,194,220,237,239,248,252,262
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  minicParserStaticData = staticData.release();
}

}

MiniCParser::MiniCParser(TokenStream *input) : MiniCParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

MiniCParser::MiniCParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  MiniCParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *minicParserStaticData->atn, minicParserStaticData->decisionToDFA, minicParserStaticData->sharedContextCache, options);
}

MiniCParser::~MiniCParser() {
  delete _interpreter;
}

const atn::ATN& MiniCParser::getATN() const {
  return *minicParserStaticData->atn;
}

std::string MiniCParser::getGrammarFileName() const {
  return "MiniC.g4";
}

const std::vector<std::string>& MiniCParser::getRuleNames() const {
  return minicParserStaticData->ruleNames;
}

const dfa::Vocabulary& MiniCParser::getVocabulary() const {
  return minicParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView MiniCParser::getSerializedATN() const {
  return minicParserStaticData->serializedATN;
}


//----------------- ProgContext ------------------------------------------------------------------

MiniCParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::PreambleContext* MiniCParser::ProgContext::preamble() {
  return getRuleContext<MiniCParser::PreambleContext>(0);
}

MiniCParser::DeclContext* MiniCParser::ProgContext::decl() {
  return getRuleContext<MiniCParser::DeclContext>(0);
}


size_t MiniCParser::ProgContext::getRuleIndex() const {
  return MiniCParser::RuleProg;
}

void MiniCParser::ProgContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProg(this);
}

void MiniCParser::ProgContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProg(this);
}


std::any MiniCParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::ProgContext* MiniCParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, MiniCParser::RuleProg);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(46);
    preamble();
    setState(47);
    decl(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PreambleContext ------------------------------------------------------------------

MiniCParser::PreambleContext::PreambleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MiniCParser::PreambleContext::getRuleIndex() const {
  return MiniCParser::RulePreamble;
}

void MiniCParser::PreambleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPreamble(this);
}

void MiniCParser::PreambleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPreamble(this);
}


std::any MiniCParser::PreambleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitPreamble(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::PreambleContext* MiniCParser::preamble() {
  PreambleContext *_localctx = _tracker.createInstance<PreambleContext>(_ctx, getState());
  enterRule(_localctx, 2, MiniCParser::RulePreamble);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(52);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MiniCParser::T__0: {
        enterOuterAlt(_localctx, 1);
        setState(49);
        match(MiniCParser::T__0);
        setState(50);
        match(MiniCParser::T__1);
        break;
      }

      case MiniCParser::T__16:
      case MiniCParser::T__17:
      case MiniCParser::T__18:
      case MiniCParser::T__19: {
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclContext ------------------------------------------------------------------

MiniCParser::DeclContext::DeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::VardeclContext* MiniCParser::DeclContext::vardecl() {
  return getRuleContext<MiniCParser::VardeclContext>(0);
}

MiniCParser::RettypeContext* MiniCParser::DeclContext::rettype() {
  return getRuleContext<MiniCParser::RettypeContext>(0);
}

MiniCParser::FuncnameContext* MiniCParser::DeclContext::funcname() {
  return getRuleContext<MiniCParser::FuncnameContext>(0);
}

MiniCParser::ParametersContext* MiniCParser::DeclContext::parameters() {
  return getRuleContext<MiniCParser::ParametersContext>(0);
}

MiniCParser::ScopeContext* MiniCParser::DeclContext::scope() {
  return getRuleContext<MiniCParser::ScopeContext>(0);
}

std::vector<MiniCParser::DeclContext *> MiniCParser::DeclContext::decl() {
  return getRuleContexts<MiniCParser::DeclContext>();
}

MiniCParser::DeclContext* MiniCParser::DeclContext::decl(size_t i) {
  return getRuleContext<MiniCParser::DeclContext>(i);
}


size_t MiniCParser::DeclContext::getRuleIndex() const {
  return MiniCParser::RuleDecl;
}

void MiniCParser::DeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDecl(this);
}

void MiniCParser::DeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDecl(this);
}


std::any MiniCParser::DeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitDecl(this);
  else
    return visitor->visitChildren(this);
}


MiniCParser::DeclContext* MiniCParser::decl() {
   return decl(0);
}

MiniCParser::DeclContext* MiniCParser::decl(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniCParser::DeclContext *_localctx = _tracker.createInstance<DeclContext>(_ctx, parentState);
  MiniCParser::DeclContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 4;
  enterRecursionRule(_localctx, 4, MiniCParser::RuleDecl, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(70);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      setState(55);
      vardecl(0);
      break;
    }

    case 2: {
      setState(56);
      rettype();
      setState(57);
      funcname();
      setState(58);
      match(MiniCParser::T__2);
      setState(59);
      parameters();
      setState(60);
      match(MiniCParser::T__3);
      setState(61);
      scope();
      break;
    }

    case 3: {
      setState(63);
      rettype();
      setState(64);
      funcname();
      setState(65);
      match(MiniCParser::T__2);
      setState(66);
      parameters();
      setState(67);
      match(MiniCParser::T__3);
      setState(68);
      match(MiniCParser::T__4);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(76);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<DeclContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleDecl);
        setState(72);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(73);
        decl(2); 
      }
      setState(78);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- VardeclContext ------------------------------------------------------------------

MiniCParser::VardeclContext::VardeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::VartypeContext* MiniCParser::VardeclContext::vartype() {
  return getRuleContext<MiniCParser::VartypeContext>(0);
}

MiniCParser::VarlistContext* MiniCParser::VardeclContext::varlist() {
  return getRuleContext<MiniCParser::VarlistContext>(0);
}

std::vector<MiniCParser::VardeclContext *> MiniCParser::VardeclContext::vardecl() {
  return getRuleContexts<MiniCParser::VardeclContext>();
}

MiniCParser::VardeclContext* MiniCParser::VardeclContext::vardecl(size_t i) {
  return getRuleContext<MiniCParser::VardeclContext>(i);
}


size_t MiniCParser::VardeclContext::getRuleIndex() const {
  return MiniCParser::RuleVardecl;
}

void MiniCParser::VardeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVardecl(this);
}

void MiniCParser::VardeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVardecl(this);
}


std::any MiniCParser::VardeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitVardecl(this);
  else
    return visitor->visitChildren(this);
}


MiniCParser::VardeclContext* MiniCParser::vardecl() {
   return vardecl(0);
}

MiniCParser::VardeclContext* MiniCParser::vardecl(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniCParser::VardeclContext *_localctx = _tracker.createInstance<VardeclContext>(_ctx, parentState);
  MiniCParser::VardeclContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 6;
  enterRecursionRule(_localctx, 6, MiniCParser::RuleVardecl, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(80);
    vartype();
    setState(81);
    varlist(0);
    setState(82);
    match(MiniCParser::T__4);
    _ctx->stop = _input->LT(-1);
    setState(88);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<VardeclContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleVardecl);
        setState(84);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(85);
        vardecl(2); 
      }
      setState(90);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ScopeContext ------------------------------------------------------------------

MiniCParser::ScopeContext::ScopeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::VardeclContext* MiniCParser::ScopeContext::vardecl() {
  return getRuleContext<MiniCParser::VardeclContext>(0);
}

MiniCParser::StmtlistContext* MiniCParser::ScopeContext::stmtlist() {
  return getRuleContext<MiniCParser::StmtlistContext>(0);
}


size_t MiniCParser::ScopeContext::getRuleIndex() const {
  return MiniCParser::RuleScope;
}

void MiniCParser::ScopeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterScope(this);
}

void MiniCParser::ScopeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitScope(this);
}


std::any MiniCParser::ScopeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitScope(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::ScopeContext* MiniCParser::scope() {
  ScopeContext *_localctx = _tracker.createInstance<ScopeContext>(_ctx, getState());
  enterRule(_localctx, 8, MiniCParser::RuleScope);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(102);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(91);
      match(MiniCParser::T__5);
      setState(92);
      vardecl(0);
      setState(93);
      stmtlist();
      setState(94);
      match(MiniCParser::T__6);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(96);
      match(MiniCParser::T__5);
      setState(97);
      stmtlist();
      setState(98);
      match(MiniCParser::T__6);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(100);
      match(MiniCParser::T__5);
      setState(101);
      match(MiniCParser::T__6);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtlistContext ------------------------------------------------------------------

MiniCParser::StmtlistContext::StmtlistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MiniCParser::StmtContext *> MiniCParser::StmtlistContext::stmt() {
  return getRuleContexts<MiniCParser::StmtContext>();
}

MiniCParser::StmtContext* MiniCParser::StmtlistContext::stmt(size_t i) {
  return getRuleContext<MiniCParser::StmtContext>(i);
}


size_t MiniCParser::StmtlistContext::getRuleIndex() const {
  return MiniCParser::RuleStmtlist;
}

void MiniCParser::StmtlistContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmtlist(this);
}

void MiniCParser::StmtlistContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmtlist(this);
}


std::any MiniCParser::StmtlistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitStmtlist(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::StmtlistContext* MiniCParser::stmtlist() {
  StmtlistContext *_localctx = _tracker.createInstance<StmtlistContext>(_ctx, getState());
  enterRule(_localctx, 10, MiniCParser::RuleStmtlist);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(107);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 962104147272) != 0) {
      setState(104);
      stmt();
      setState(109);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

MiniCParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::ExprContext* MiniCParser::StmtContext::expr() {
  return getRuleContext<MiniCParser::ExprContext>(0);
}

std::vector<MiniCParser::StmtContext *> MiniCParser::StmtContext::stmt() {
  return getRuleContexts<MiniCParser::StmtContext>();
}

MiniCParser::StmtContext* MiniCParser::StmtContext::stmt(size_t i) {
  return getRuleContext<MiniCParser::StmtContext>(i);
}

std::vector<MiniCParser::ExproptContext *> MiniCParser::StmtContext::expropt() {
  return getRuleContexts<MiniCParser::ExproptContext>();
}

MiniCParser::ExproptContext* MiniCParser::StmtContext::expropt(size_t i) {
  return getRuleContext<MiniCParser::ExproptContext>(i);
}

MiniCParser::ScopeContext* MiniCParser::StmtContext::scope() {
  return getRuleContext<MiniCParser::ScopeContext>(0);
}


size_t MiniCParser::StmtContext::getRuleIndex() const {
  return MiniCParser::RuleStmt;
}

void MiniCParser::StmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmt(this);
}

void MiniCParser::StmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmt(this);
}


std::any MiniCParser::StmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitStmt(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::StmtContext* MiniCParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 12, MiniCParser::RuleStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(147);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(110);
      expr(0);
      setState(111);
      match(MiniCParser::T__4);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(113);
      match(MiniCParser::T__7);
      setState(114);
      match(MiniCParser::T__2);
      setState(115);
      expr(0);
      setState(116);
      match(MiniCParser::T__3);
      setState(117);
      stmt();
      setState(118);
      match(MiniCParser::T__8);
      setState(119);
      stmt();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(121);
      match(MiniCParser::T__7);
      setState(122);
      match(MiniCParser::T__2);
      setState(123);
      expr(0);
      setState(124);
      match(MiniCParser::T__3);
      setState(125);
      stmt();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(127);
      match(MiniCParser::T__9);
      setState(128);
      match(MiniCParser::T__2);
      setState(129);
      expropt();
      setState(130);
      match(MiniCParser::T__4);
      setState(131);
      expropt();
      setState(132);
      match(MiniCParser::T__4);
      setState(133);
      expropt();
      setState(134);
      match(MiniCParser::T__3);
      setState(135);
      stmt();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(137);
      match(MiniCParser::T__10);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(138);
      match(MiniCParser::T__11);
      setState(139);
      match(MiniCParser::T__4);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(140);
      match(MiniCParser::T__12);
      setState(141);
      match(MiniCParser::T__4);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(142);
      match(MiniCParser::T__12);
      setState(143);
      expr(0);
      setState(144);
      match(MiniCParser::T__4);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(146);
      scope();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarlistContext ------------------------------------------------------------------

MiniCParser::VarlistContext::VarlistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::VarnameContext* MiniCParser::VarlistContext::varname() {
  return getRuleContext<MiniCParser::VarnameContext>(0);
}

tree::TerminalNode* MiniCParser::VarlistContext::INT() {
  return getToken(MiniCParser::INT, 0);
}

std::vector<MiniCParser::VarlistContext *> MiniCParser::VarlistContext::varlist() {
  return getRuleContexts<MiniCParser::VarlistContext>();
}

MiniCParser::VarlistContext* MiniCParser::VarlistContext::varlist(size_t i) {
  return getRuleContext<MiniCParser::VarlistContext>(i);
}


size_t MiniCParser::VarlistContext::getRuleIndex() const {
  return MiniCParser::RuleVarlist;
}

void MiniCParser::VarlistContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarlist(this);
}

void MiniCParser::VarlistContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarlist(this);
}


std::any MiniCParser::VarlistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitVarlist(this);
  else
    return visitor->visitChildren(this);
}


MiniCParser::VarlistContext* MiniCParser::varlist() {
   return varlist(0);
}

MiniCParser::VarlistContext* MiniCParser::varlist(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniCParser::VarlistContext *_localctx = _tracker.createInstance<VarlistContext>(_ctx, parentState);
  MiniCParser::VarlistContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 14;
  enterRecursionRule(_localctx, 14, MiniCParser::RuleVarlist, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(156);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      setState(150);
      varname();
      break;
    }

    case 2: {
      setState(151);
      varname();
      setState(152);
      match(MiniCParser::T__13);
      setState(153);
      match(MiniCParser::INT);
      setState(154);
      match(MiniCParser::T__14);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(163);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<VarlistContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleVarlist);
        setState(158);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(159);
        match(MiniCParser::T__15);
        setState(160);
        varlist(2); 
      }
      setState(165);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- VarlistentryContext ------------------------------------------------------------------

MiniCParser::VarlistentryContext::VarlistentryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MiniCParser::VarlistentryContext::getRuleIndex() const {
  return MiniCParser::RuleVarlistentry;
}

void MiniCParser::VarlistentryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarlistentry(this);
}

void MiniCParser::VarlistentryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarlistentry(this);
}


std::any MiniCParser::VarlistentryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitVarlistentry(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::VarlistentryContext* MiniCParser::varlistentry() {
  VarlistentryContext *_localctx = _tracker.createInstance<VarlistentryContext>(_ctx, getState());
  enterRule(_localctx, 16, MiniCParser::RuleVarlistentry);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);

   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VartypeContext ------------------------------------------------------------------

MiniCParser::VartypeContext::VartypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MiniCParser::VartypeContext::getRuleIndex() const {
  return MiniCParser::RuleVartype;
}

void MiniCParser::VartypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVartype(this);
}

void MiniCParser::VartypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVartype(this);
}


std::any MiniCParser::VartypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitVartype(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::VartypeContext* MiniCParser::vartype() {
  VartypeContext *_localctx = _tracker.createInstance<VartypeContext>(_ctx, getState());
  enterRule(_localctx, 18, MiniCParser::RuleVartype);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(168);
    _la = _input->LA(1);
    if (!(((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 917504) != 0)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RettypeContext ------------------------------------------------------------------

MiniCParser::RettypeContext::RettypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::VartypeContext* MiniCParser::RettypeContext::vartype() {
  return getRuleContext<MiniCParser::VartypeContext>(0);
}


size_t MiniCParser::RettypeContext::getRuleIndex() const {
  return MiniCParser::RuleRettype;
}

void MiniCParser::RettypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRettype(this);
}

void MiniCParser::RettypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRettype(this);
}


std::any MiniCParser::RettypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitRettype(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::RettypeContext* MiniCParser::rettype() {
  RettypeContext *_localctx = _tracker.createInstance<RettypeContext>(_ctx, getState());
  enterRule(_localctx, 20, MiniCParser::RuleRettype);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(172);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MiniCParser::T__19: {
        enterOuterAlt(_localctx, 1);
        setState(170);
        match(MiniCParser::T__19);
        break;
      }

      case MiniCParser::T__16:
      case MiniCParser::T__17:
      case MiniCParser::T__18: {
        enterOuterAlt(_localctx, 2);
        setState(171);
        vartype();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParametersContext ------------------------------------------------------------------

MiniCParser::ParametersContext::ParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::ParameterlistContext* MiniCParser::ParametersContext::parameterlist() {
  return getRuleContext<MiniCParser::ParameterlistContext>(0);
}


size_t MiniCParser::ParametersContext::getRuleIndex() const {
  return MiniCParser::RuleParameters;
}

void MiniCParser::ParametersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameters(this);
}

void MiniCParser::ParametersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameters(this);
}


std::any MiniCParser::ParametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitParameters(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::ParametersContext* MiniCParser::parameters() {
  ParametersContext *_localctx = _tracker.createInstance<ParametersContext>(_ctx, getState());
  enterRule(_localctx, 22, MiniCParser::RuleParameters);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(176);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MiniCParser::T__3: {
        enterOuterAlt(_localctx, 1);

        break;
      }

      case MiniCParser::T__16:
      case MiniCParser::T__17:
      case MiniCParser::T__18: {
        enterOuterAlt(_localctx, 2);
        setState(175);
        parameterlist(0);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterlistContext ------------------------------------------------------------------

MiniCParser::ParameterlistContext::ParameterlistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::VartypeContext* MiniCParser::ParameterlistContext::vartype() {
  return getRuleContext<MiniCParser::VartypeContext>(0);
}

MiniCParser::ParameternameContext* MiniCParser::ParameterlistContext::parametername() {
  return getRuleContext<MiniCParser::ParameternameContext>(0);
}

std::vector<MiniCParser::ParameterlistContext *> MiniCParser::ParameterlistContext::parameterlist() {
  return getRuleContexts<MiniCParser::ParameterlistContext>();
}

MiniCParser::ParameterlistContext* MiniCParser::ParameterlistContext::parameterlist(size_t i) {
  return getRuleContext<MiniCParser::ParameterlistContext>(i);
}


size_t MiniCParser::ParameterlistContext::getRuleIndex() const {
  return MiniCParser::RuleParameterlist;
}

void MiniCParser::ParameterlistContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterlist(this);
}

void MiniCParser::ParameterlistContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterlist(this);
}


std::any MiniCParser::ParameterlistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitParameterlist(this);
  else
    return visitor->visitChildren(this);
}


MiniCParser::ParameterlistContext* MiniCParser::parameterlist() {
   return parameterlist(0);
}

MiniCParser::ParameterlistContext* MiniCParser::parameterlist(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniCParser::ParameterlistContext *_localctx = _tracker.createInstance<ParameterlistContext>(_ctx, parentState);
  MiniCParser::ParameterlistContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 24;
  enterRecursionRule(_localctx, 24, MiniCParser::RuleParameterlist, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(179);
    vartype();
    setState(180);
    parametername();
    _ctx->stop = _input->LT(-1);
    setState(187);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ParameterlistContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleParameterlist);
        setState(182);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(183);
        match(MiniCParser::T__15);
        setState(184);
        parameterlist(2); 
      }
      setState(189);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ParameterentryContext ------------------------------------------------------------------

MiniCParser::ParameterentryContext::ParameterentryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MiniCParser::ParameterentryContext::getRuleIndex() const {
  return MiniCParser::RuleParameterentry;
}

void MiniCParser::ParameterentryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterentry(this);
}

void MiniCParser::ParameterentryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterentry(this);
}


std::any MiniCParser::ParameterentryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitParameterentry(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::ParameterentryContext* MiniCParser::parameterentry() {
  ParameterentryContext *_localctx = _tracker.createInstance<ParameterentryContext>(_ctx, getState());
  enterRule(_localctx, 26, MiniCParser::RuleParameterentry);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);

   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExproptContext ------------------------------------------------------------------

MiniCParser::ExproptContext::ExproptContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::ExprContext* MiniCParser::ExproptContext::expr() {
  return getRuleContext<MiniCParser::ExprContext>(0);
}


size_t MiniCParser::ExproptContext::getRuleIndex() const {
  return MiniCParser::RuleExpropt;
}

void MiniCParser::ExproptContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpropt(this);
}

void MiniCParser::ExproptContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpropt(this);
}


std::any MiniCParser::ExproptContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitExpropt(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::ExproptContext* MiniCParser::expropt() {
  ExproptContext *_localctx = _tracker.createInstance<ExproptContext>(_ctx, getState());
  enterRule(_localctx, 28, MiniCParser::RuleExpropt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(194);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MiniCParser::T__2:
      case MiniCParser::T__20:
      case MiniCParser::T__21:
      case MiniCParser::T__22:
      case MiniCParser::T__23:
      case MiniCParser::ID:
      case MiniCParser::INT:
      case MiniCParser::CHAR: {
        enterOuterAlt(_localctx, 1);
        setState(192);
        expr(0);
        break;
      }

      case MiniCParser::T__3:
      case MiniCParser::T__4: {
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

MiniCParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniCParser::ExprContext::INT() {
  return getToken(MiniCParser::INT, 0);
}

tree::TerminalNode* MiniCParser::ExprContext::CHAR() {
  return getToken(MiniCParser::CHAR, 0);
}

std::vector<MiniCParser::ExprContext *> MiniCParser::ExprContext::expr() {
  return getRuleContexts<MiniCParser::ExprContext>();
}

MiniCParser::ExprContext* MiniCParser::ExprContext::expr(size_t i) {
  return getRuleContext<MiniCParser::ExprContext>(i);
}

MiniCParser::VarContext* MiniCParser::ExprContext::var() {
  return getRuleContext<MiniCParser::VarContext>(0);
}

MiniCParser::FuncnameContext* MiniCParser::ExprContext::funcname() {
  return getRuleContext<MiniCParser::FuncnameContext>(0);
}

MiniCParser::ArgumentsContext* MiniCParser::ExprContext::arguments() {
  return getRuleContext<MiniCParser::ArgumentsContext>(0);
}

MiniCParser::ParameternameContext* MiniCParser::ExprContext::parametername() {
  return getRuleContext<MiniCParser::ParameternameContext>(0);
}


size_t MiniCParser::ExprContext::getRuleIndex() const {
  return MiniCParser::RuleExpr;
}

void MiniCParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void MiniCParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


std::any MiniCParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}


MiniCParser::ExprContext* MiniCParser::expr() {
   return expr(0);
}

MiniCParser::ExprContext* MiniCParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniCParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  MiniCParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 30;
  enterRecursionRule(_localctx, 30, MiniCParser::RuleExpr, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(220);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      setState(197);
      match(MiniCParser::INT);
      break;
    }

    case 2: {
      setState(198);
      match(MiniCParser::CHAR);
      break;
    }

    case 3: {
      setState(199);
      match(MiniCParser::T__20);
      break;
    }

    case 4: {
      setState(200);
      match(MiniCParser::T__21);
      break;
    }

    case 5: {
      setState(201);
      match(MiniCParser::T__22);
      setState(202);
      expr(12);
      break;
    }

    case 6: {
      setState(203);
      match(MiniCParser::T__23);
      setState(204);
      expr(11);
      break;
    }

    case 7: {
      setState(205);
      var();
      setState(206);
      match(MiniCParser::T__35);
      setState(207);
      expr(5);
      break;
    }

    case 8: {
      setState(209);
      match(MiniCParser::T__2);
      setState(210);
      expr(0);
      setState(211);
      match(MiniCParser::T__3);
      break;
    }

    case 9: {
      setState(213);
      var();
      break;
    }

    case 10: {
      setState(214);
      funcname();
      setState(215);
      match(MiniCParser::T__2);
      setState(216);
      arguments();
      setState(217);
      match(MiniCParser::T__3);
      break;
    }

    case 11: {
      setState(219);
      parametername();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(239);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(237);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(222);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(223);
          _la = _input->LA(1);
          if (!(_la == MiniCParser::T__24

          || _la == MiniCParser::T__25)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(224);
          expr(11);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(225);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(226);
          _la = _input->LA(1);
          if (!(_la == MiniCParser::T__22

          || _la == MiniCParser::T__26)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(227);
          expr(10);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(228);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(229);
          _la = _input->LA(1);
          if (!(((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 16911433728) != 0)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(230);
          expr(9);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(231);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(232);
          match(MiniCParser::T__33);
          setState(233);
          expr(8);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(234);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(235);
          match(MiniCParser::T__34);
          setState(236);
          expr(7);
          break;
        }

        default:
          break;
        } 
      }
      setState(241);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- VarContext ------------------------------------------------------------------

MiniCParser::VarContext::VarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::VarnameContext* MiniCParser::VarContext::varname() {
  return getRuleContext<MiniCParser::VarnameContext>(0);
}

MiniCParser::ArraynameContext* MiniCParser::VarContext::arrayname() {
  return getRuleContext<MiniCParser::ArraynameContext>(0);
}

MiniCParser::ExprContext* MiniCParser::VarContext::expr() {
  return getRuleContext<MiniCParser::ExprContext>(0);
}


size_t MiniCParser::VarContext::getRuleIndex() const {
  return MiniCParser::RuleVar;
}

void MiniCParser::VarContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar(this);
}

void MiniCParser::VarContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar(this);
}


std::any MiniCParser::VarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitVar(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::VarContext* MiniCParser::var() {
  VarContext *_localctx = _tracker.createInstance<VarContext>(_ctx, getState());
  enterRule(_localctx, 32, MiniCParser::RuleVar);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(248);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(242);
      varname();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(243);
      arrayname();
      setState(244);
      match(MiniCParser::T__13);
      setState(245);
      expr(0);
      setState(246);
      match(MiniCParser::T__14);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentsContext ------------------------------------------------------------------

MiniCParser::ArgumentsContext::ArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::ArgumentlistContext* MiniCParser::ArgumentsContext::argumentlist() {
  return getRuleContext<MiniCParser::ArgumentlistContext>(0);
}


size_t MiniCParser::ArgumentsContext::getRuleIndex() const {
  return MiniCParser::RuleArguments;
}

void MiniCParser::ArgumentsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArguments(this);
}

void MiniCParser::ArgumentsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArguments(this);
}


std::any MiniCParser::ArgumentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitArguments(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::ArgumentsContext* MiniCParser::arguments() {
  ArgumentsContext *_localctx = _tracker.createInstance<ArgumentsContext>(_ctx, getState());
  enterRule(_localctx, 34, MiniCParser::RuleArguments);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(252);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MiniCParser::T__2:
      case MiniCParser::T__20:
      case MiniCParser::T__21:
      case MiniCParser::T__22:
      case MiniCParser::T__23:
      case MiniCParser::ID:
      case MiniCParser::INT:
      case MiniCParser::CHAR: {
        enterOuterAlt(_localctx, 1);
        setState(250);
        argumentlist(0);
        break;
      }

      case MiniCParser::T__3: {
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentlistContext ------------------------------------------------------------------

MiniCParser::ArgumentlistContext::ArgumentlistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::ExprContext* MiniCParser::ArgumentlistContext::expr() {
  return getRuleContext<MiniCParser::ExprContext>(0);
}

std::vector<MiniCParser::ArgumentlistContext *> MiniCParser::ArgumentlistContext::argumentlist() {
  return getRuleContexts<MiniCParser::ArgumentlistContext>();
}

MiniCParser::ArgumentlistContext* MiniCParser::ArgumentlistContext::argumentlist(size_t i) {
  return getRuleContext<MiniCParser::ArgumentlistContext>(i);
}


size_t MiniCParser::ArgumentlistContext::getRuleIndex() const {
  return MiniCParser::RuleArgumentlist;
}

void MiniCParser::ArgumentlistContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgumentlist(this);
}

void MiniCParser::ArgumentlistContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgumentlist(this);
}


std::any MiniCParser::ArgumentlistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitArgumentlist(this);
  else
    return visitor->visitChildren(this);
}


MiniCParser::ArgumentlistContext* MiniCParser::argumentlist() {
   return argumentlist(0);
}

MiniCParser::ArgumentlistContext* MiniCParser::argumentlist(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniCParser::ArgumentlistContext *_localctx = _tracker.createInstance<ArgumentlistContext>(_ctx, parentState);
  MiniCParser::ArgumentlistContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 36;
  enterRecursionRule(_localctx, 36, MiniCParser::RuleArgumentlist, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(255);
    expr(0);
    _ctx->stop = _input->LT(-1);
    setState(262);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ArgumentlistContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleArgumentlist);
        setState(257);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(258);
        match(MiniCParser::T__15);
        setState(259);
        argumentlist(2); 
      }
      setState(264);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- VarnameContext ------------------------------------------------------------------

MiniCParser::VarnameContext::VarnameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniCParser::VarnameContext::ID() {
  return getToken(MiniCParser::ID, 0);
}


size_t MiniCParser::VarnameContext::getRuleIndex() const {
  return MiniCParser::RuleVarname;
}

void MiniCParser::VarnameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarname(this);
}

void MiniCParser::VarnameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarname(this);
}


std::any MiniCParser::VarnameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitVarname(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::VarnameContext* MiniCParser::varname() {
  VarnameContext *_localctx = _tracker.createInstance<VarnameContext>(_ctx, getState());
  enterRule(_localctx, 38, MiniCParser::RuleVarname);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(265);
    match(MiniCParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArraynameContext ------------------------------------------------------------------

MiniCParser::ArraynameContext::ArraynameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniCParser::ArraynameContext::ID() {
  return getToken(MiniCParser::ID, 0);
}


size_t MiniCParser::ArraynameContext::getRuleIndex() const {
  return MiniCParser::RuleArrayname;
}

void MiniCParser::ArraynameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayname(this);
}

void MiniCParser::ArraynameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayname(this);
}


std::any MiniCParser::ArraynameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitArrayname(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::ArraynameContext* MiniCParser::arrayname() {
  ArraynameContext *_localctx = _tracker.createInstance<ArraynameContext>(_ctx, getState());
  enterRule(_localctx, 40, MiniCParser::RuleArrayname);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(267);
    match(MiniCParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncnameContext ------------------------------------------------------------------

MiniCParser::FuncnameContext::FuncnameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniCParser::FuncnameContext::ID() {
  return getToken(MiniCParser::ID, 0);
}


size_t MiniCParser::FuncnameContext::getRuleIndex() const {
  return MiniCParser::RuleFuncname;
}

void MiniCParser::FuncnameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncname(this);
}

void MiniCParser::FuncnameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncname(this);
}


std::any MiniCParser::FuncnameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitFuncname(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::FuncnameContext* MiniCParser::funcname() {
  FuncnameContext *_localctx = _tracker.createInstance<FuncnameContext>(_ctx, getState());
  enterRule(_localctx, 42, MiniCParser::RuleFuncname);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(269);
    match(MiniCParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameternameContext ------------------------------------------------------------------

MiniCParser::ParameternameContext::ParameternameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniCParser::ParameternameContext::ID() {
  return getToken(MiniCParser::ID, 0);
}


size_t MiniCParser::ParameternameContext::getRuleIndex() const {
  return MiniCParser::RuleParametername;
}

void MiniCParser::ParameternameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParametername(this);
}

void MiniCParser::ParameternameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParametername(this);
}


std::any MiniCParser::ParameternameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitParametername(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::ParameternameContext* MiniCParser::parametername() {
  ParameternameContext *_localctx = _tracker.createInstance<ParameternameContext>(_ctx, getState());
  enterRule(_localctx, 44, MiniCParser::RuleParametername);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(271);
    match(MiniCParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool MiniCParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 2: return declSempred(antlrcpp::downCast<DeclContext *>(context), predicateIndex);
    case 3: return vardeclSempred(antlrcpp::downCast<VardeclContext *>(context), predicateIndex);
    case 7: return varlistSempred(antlrcpp::downCast<VarlistContext *>(context), predicateIndex);
    case 12: return parameterlistSempred(antlrcpp::downCast<ParameterlistContext *>(context), predicateIndex);
    case 15: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);
    case 18: return argumentlistSempred(antlrcpp::downCast<ArgumentlistContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool MiniCParser::declSempred(DeclContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool MiniCParser::vardeclSempred(VardeclContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool MiniCParser::varlistSempred(VarlistContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool MiniCParser::parameterlistSempred(ParameterlistContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool MiniCParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 10);
    case 5: return precpred(_ctx, 9);
    case 6: return precpred(_ctx, 8);
    case 7: return precpred(_ctx, 7);
    case 8: return precpred(_ctx, 6);

  default:
    break;
  }
  return true;
}

bool MiniCParser::argumentlistSempred(ArgumentlistContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 9: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

void MiniCParser::initialize() {
  ::antlr4::internal::call_once(minicParserOnceFlag, minicParserInitialize);
}
