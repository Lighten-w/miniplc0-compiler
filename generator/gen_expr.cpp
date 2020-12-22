#include "ast/ast.h"
#include "generator.h"

namespace miniplc0 {

void Generator::generateStat(StatNodePtr stat) {
  switch (stat->_ntype) {
    case NodeType::ExprStatNode:
      /* code */
      break;
    case NodeType::BlockStatNode: {
      auto node = std::dynamic_pointer_cast<BlockStatNode>(stat);
      generateBlockStat(node);
      break;
    }
    case NodeType::DeclStatNode: {
      auto node = std::dynamic_pointer_cast<DeclStatNode>(stat);
      generateDeclStat(node);
      break;
    }
    case NodeType::IfStatNode: {
      auto node = std::dynamic_pointer_cast<IfStatNode>(stat);
      generateIfStat(node);
      break;
    }
    case NodeType::WhileStatNode: {
      auto node = std::dynamic_pointer_cast<WhileStatNode>(stat);
      generateWhileStat(node);
      break;
    }
    case NodeType::BreakStatNode: {
      auto node = std::dynamic_pointer_cast<BreakStatNode>(stat);
      generateBreakStat(node);
      break;
    }
    case NodeType::ContinueStatNode: {
      auto node = std::dynamic_pointer_cast<ContinueStatNode>(stat);
      generateContinueStat(node);
      break;
    }
    case NodeType::ReturnStatNode: {
      auto node = std::dynamic_pointer_cast<ReturnStatNode>(stat);
      generateReturnStat(node);
      break;
    }
    default: {
      printf("error!");
      break;
    }
  }
  return;
}

void Generator::generateBlockStat(BlockStatNodePtr block_node) {
  for (auto &stat_node : block_node->_stats) {
    generateStat(stat_node);
  }
}

void Generator::generateDeclStat(DeclStatNodePtr) {

}
void Generator::generateIfStat(IfStatNodePtr) {

}
void Generator::generateWhileStat(WhileStatNodePtr) {

}
void Generator::generateBreakStat(BreakStatNodePtr) {

}
void Generator::generateContinueStat(ContinueStatNodePtr) {

}
void Generator::generateReturnStat(ReturnStatNodePtr) {

}
void Generator::generateWhileStat(BlockStatNodePtr) {

}
}  // namespace miniplc0
