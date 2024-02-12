
#include <vector>
#include "Program.h"
#include "Declarations.h"
#include "Statements.h"
#include "Exprs.h"
#include "Terms.h"


// Generated from /home/hasti2c/Documents/csc488/assignments/code/grammars/MiniC.g4 by ANTLR 4.11.1


#include "MiniCLexer.h"


using namespace antlr4;

using namespace minicc;


using namespace antlr4;

namespace {

struct MiniCLexerStaticData final {
  MiniCLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  MiniCLexerStaticData(const MiniCLexerStaticData&) = delete;
  MiniCLexerStaticData(MiniCLexerStaticData&&) = delete;
  MiniCLexerStaticData& operator=(const MiniCLexerStaticData&) = delete;
  MiniCLexerStaticData& operator=(MiniCLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag miniclexerLexerOnceFlag;
MiniCLexerStaticData *miniclexerLexerStaticData = nullptr;

void miniclexerLexerInitialize() {
  assert(miniclexerLexerStaticData == nullptr);
  auto staticData = std::make_unique<MiniCLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
      "T__9", "T__10", "T__11", "T__12", "T__13", "T__14", "T__15", "T__16", 
      "T__17", "T__18", "T__19", "T__20", "T__21", "T__22", "T__23", "T__24", 
      "T__25", "T__26", "T__27", "T__28", "T__29", "T__30", "T__31", "T__32", 
      "T__33", "T__34", "T__35", "ID", "INT", "CHAR", "WS", "COMMENT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,41,258,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,1,0,1,0,1,0,1,
  	0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,2,1,2,1,3,1,3,1,4,1,4,1,5,1,5,1,6,1,6,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,
  	8,1,9,1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,
  	11,1,11,1,11,1,11,1,11,1,11,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,13,1,
  	13,1,14,1,14,1,15,1,15,1,16,1,16,1,16,1,16,1,17,1,17,1,17,1,17,1,17,1,
  	18,1,18,1,18,1,18,1,18,1,19,1,19,1,19,1,19,1,19,1,20,1,20,1,20,1,20,1,
  	20,1,21,1,21,1,21,1,21,1,21,1,21,1,22,1,22,1,23,1,23,1,24,1,24,1,25,1,
  	25,1,26,1,26,1,27,1,27,1,27,1,28,1,28,1,28,1,29,1,29,1,30,1,30,1,30,1,
  	31,1,31,1,32,1,32,1,32,1,33,1,33,1,33,1,34,1,34,1,34,1,35,1,35,1,36,1,
  	36,5,36,222,8,36,10,36,12,36,225,9,36,1,37,1,37,1,37,5,37,230,8,37,10,
  	37,12,37,233,9,37,3,37,235,8,37,1,38,1,38,1,38,1,38,1,39,4,39,242,8,39,
  	11,39,12,39,243,1,39,1,39,1,40,1,40,1,40,1,40,5,40,252,8,40,10,40,12,
  	40,255,9,40,1,40,1,40,0,0,41,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,
  	19,10,21,11,23,12,25,13,27,14,29,15,31,16,33,17,35,18,37,19,39,20,41,
  	21,43,22,45,23,47,24,49,25,51,26,53,27,55,28,57,29,59,30,61,31,63,32,
  	65,33,67,34,69,35,71,36,73,37,75,38,77,39,79,40,81,41,1,0,7,2,0,65,90,
  	97,122,4,0,48,57,65,90,95,95,97,122,1,0,48,48,1,0,49,57,1,0,48,57,3,0,
  	9,10,13,13,32,32,2,0,10,10,13,13,262,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,
  	0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,
  	17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,
  	0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,
  	0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,
  	49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,0,57,1,0,0,0,0,59,1,
  	0,0,0,0,61,1,0,0,0,0,63,1,0,0,0,0,65,1,0,0,0,0,67,1,0,0,0,0,69,1,0,0,
  	0,0,71,1,0,0,0,0,73,1,0,0,0,0,75,1,0,0,0,0,77,1,0,0,0,0,79,1,0,0,0,0,
  	81,1,0,0,0,1,83,1,0,0,0,3,92,1,0,0,0,5,104,1,0,0,0,7,106,1,0,0,0,9,108,
  	1,0,0,0,11,110,1,0,0,0,13,112,1,0,0,0,15,114,1,0,0,0,17,117,1,0,0,0,19,
  	122,1,0,0,0,21,126,1,0,0,0,23,136,1,0,0,0,25,142,1,0,0,0,27,149,1,0,0,
  	0,29,151,1,0,0,0,31,153,1,0,0,0,33,155,1,0,0,0,35,159,1,0,0,0,37,164,
  	1,0,0,0,39,169,1,0,0,0,41,174,1,0,0,0,43,179,1,0,0,0,45,185,1,0,0,0,47,
  	187,1,0,0,0,49,189,1,0,0,0,51,191,1,0,0,0,53,193,1,0,0,0,55,195,1,0,0,
  	0,57,198,1,0,0,0,59,201,1,0,0,0,61,203,1,0,0,0,63,206,1,0,0,0,65,208,
  	1,0,0,0,67,211,1,0,0,0,69,214,1,0,0,0,71,217,1,0,0,0,73,219,1,0,0,0,75,
  	234,1,0,0,0,77,236,1,0,0,0,79,241,1,0,0,0,81,247,1,0,0,0,83,84,5,35,0,
  	0,84,85,5,105,0,0,85,86,5,110,0,0,86,87,5,99,0,0,87,88,5,108,0,0,88,89,
  	5,117,0,0,89,90,5,100,0,0,90,91,5,101,0,0,91,2,1,0,0,0,92,93,5,34,0,0,
  	93,94,5,109,0,0,94,95,5,105,0,0,95,96,5,110,0,0,96,97,5,105,0,0,97,98,
  	5,99,0,0,98,99,5,105,0,0,99,100,5,111,0,0,100,101,5,46,0,0,101,102,5,
  	104,0,0,102,103,5,34,0,0,103,4,1,0,0,0,104,105,5,40,0,0,105,6,1,0,0,0,
  	106,107,5,41,0,0,107,8,1,0,0,0,108,109,5,59,0,0,109,10,1,0,0,0,110,111,
  	5,123,0,0,111,12,1,0,0,0,112,113,5,125,0,0,113,14,1,0,0,0,114,115,5,105,
  	0,0,115,116,5,102,0,0,116,16,1,0,0,0,117,118,5,101,0,0,118,119,5,108,
  	0,0,119,120,5,115,0,0,120,121,5,101,0,0,121,18,1,0,0,0,122,123,5,102,
  	0,0,123,124,5,111,0,0,124,125,5,114,0,0,125,20,1,0,0,0,126,127,5,99,0,
  	0,127,128,5,111,0,0,128,129,5,110,0,0,129,130,5,116,0,0,130,131,5,105,
  	0,0,131,132,5,110,0,0,132,133,5,117,0,0,133,134,5,101,0,0,134,135,5,59,
  	0,0,135,22,1,0,0,0,136,137,5,98,0,0,137,138,5,114,0,0,138,139,5,101,0,
  	0,139,140,5,97,0,0,140,141,5,107,0,0,141,24,1,0,0,0,142,143,5,114,0,0,
  	143,144,5,101,0,0,144,145,5,116,0,0,145,146,5,117,0,0,146,147,5,114,0,
  	0,147,148,5,110,0,0,148,26,1,0,0,0,149,150,5,91,0,0,150,28,1,0,0,0,151,
  	152,5,93,0,0,152,30,1,0,0,0,153,154,5,44,0,0,154,32,1,0,0,0,155,156,5,
  	105,0,0,156,157,5,110,0,0,157,158,5,116,0,0,158,34,1,0,0,0,159,160,5,
  	98,0,0,160,161,5,111,0,0,161,162,5,111,0,0,162,163,5,108,0,0,163,36,1,
  	0,0,0,164,165,5,99,0,0,165,166,5,104,0,0,166,167,5,97,0,0,167,168,5,114,
  	0,0,168,38,1,0,0,0,169,170,5,118,0,0,170,171,5,111,0,0,171,172,5,105,
  	0,0,172,173,5,100,0,0,173,40,1,0,0,0,174,175,5,116,0,0,175,176,5,114,
  	0,0,176,177,5,117,0,0,177,178,5,101,0,0,178,42,1,0,0,0,179,180,5,102,
  	0,0,180,181,5,97,0,0,181,182,5,108,0,0,182,183,5,115,0,0,183,184,5,101,
  	0,0,184,44,1,0,0,0,185,186,5,45,0,0,186,46,1,0,0,0,187,188,5,33,0,0,188,
  	48,1,0,0,0,189,190,5,42,0,0,190,50,1,0,0,0,191,192,5,47,0,0,192,52,1,
  	0,0,0,193,194,5,43,0,0,194,54,1,0,0,0,195,196,5,61,0,0,196,197,5,61,0,
  	0,197,56,1,0,0,0,198,199,5,33,0,0,199,200,5,61,0,0,200,58,1,0,0,0,201,
  	202,5,60,0,0,202,60,1,0,0,0,203,204,5,60,0,0,204,205,5,61,0,0,205,62,
  	1,0,0,0,206,207,5,62,0,0,207,64,1,0,0,0,208,209,5,62,0,0,209,210,5,61,
  	0,0,210,66,1,0,0,0,211,212,5,38,0,0,212,213,5,38,0,0,213,68,1,0,0,0,214,
  	215,5,124,0,0,215,216,5,124,0,0,216,70,1,0,0,0,217,218,5,61,0,0,218,72,
  	1,0,0,0,219,223,7,0,0,0,220,222,7,1,0,0,221,220,1,0,0,0,222,225,1,0,0,
  	0,223,221,1,0,0,0,223,224,1,0,0,0,224,74,1,0,0,0,225,223,1,0,0,0,226,
  	235,7,2,0,0,227,231,7,3,0,0,228,230,7,4,0,0,229,228,1,0,0,0,230,233,1,
  	0,0,0,231,229,1,0,0,0,231,232,1,0,0,0,232,235,1,0,0,0,233,231,1,0,0,0,
  	234,226,1,0,0,0,234,227,1,0,0,0,235,76,1,0,0,0,236,237,5,39,0,0,237,238,
  	9,0,0,0,238,239,5,39,0,0,239,78,1,0,0,0,240,242,7,5,0,0,241,240,1,0,0,
  	0,242,243,1,0,0,0,243,241,1,0,0,0,243,244,1,0,0,0,244,245,1,0,0,0,245,
  	246,6,39,0,0,246,80,1,0,0,0,247,248,5,47,0,0,248,249,5,47,0,0,249,253,
  	1,0,0,0,250,252,8,6,0,0,251,250,1,0,0,0,252,255,1,0,0,0,253,251,1,0,0,
  	0,253,254,1,0,0,0,254,256,1,0,0,0,255,253,1,0,0,0,256,257,6,40,0,0,257,
  	82,1,0,0,0,6,0,223,231,234,243,253,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  miniclexerLexerStaticData = staticData.release();
}

}

MiniCLexer::MiniCLexer(CharStream *input) : Lexer(input) {
  MiniCLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *miniclexerLexerStaticData->atn, miniclexerLexerStaticData->decisionToDFA, miniclexerLexerStaticData->sharedContextCache);
}

MiniCLexer::~MiniCLexer() {
  delete _interpreter;
}

std::string MiniCLexer::getGrammarFileName() const {
  return "MiniC.g4";
}

const std::vector<std::string>& MiniCLexer::getRuleNames() const {
  return miniclexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& MiniCLexer::getChannelNames() const {
  return miniclexerLexerStaticData->channelNames;
}

const std::vector<std::string>& MiniCLexer::getModeNames() const {
  return miniclexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& MiniCLexer::getVocabulary() const {
  return miniclexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView MiniCLexer::getSerializedATN() const {
  return miniclexerLexerStaticData->serializedATN;
}

const atn::ATN& MiniCLexer::getATN() const {
  return *miniclexerLexerStaticData->atn;
}




void MiniCLexer::initialize() {
  ::antlr4::internal::call_once(miniclexerLexerOnceFlag, miniclexerLexerInitialize);
}
