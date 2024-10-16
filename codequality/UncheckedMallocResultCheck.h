//===--- UncheckedMallocResultCheck.h - clang-tidy --------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_CODEQUALITY_UNCHECKEDMALLOCRESULTCHECK_H
#define LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_CODEQUALITY_UNCHECKEDMALLOCRESULTCHECK_H

#include "clang-tidy/ClangTidyCheck.h"

namespace clang {
namespace tidy {
namespace codequality {

/// FIXME: Write a short description.
///
/// For the user-facing documentation see:
/// http://clang.llvm.org/extra/clang-tidy/checks/codequality/unchecked-malloc-result.html
class UncheckedMallocResultCheck : public ClangTidyCheck {
public:
    UncheckedMallocResultCheck(StringRef Name, ClangTidyContext *Context)
        : ClangTidyCheck(Name, Context) {}
    void registerMatchers(ast_matchers::MatchFinder *Finder) override;
    void check(const ast_matchers::MatchFinder::MatchResult &Result) override;

private:
    void        reportBug();
    bool        hasUsedVar(const clang::Stmt *stmt, const VarDecl *var);
    const Stmt *FindPaNodes(ASTContext *const context, DynTypedNodeList Parents);
};

}  // namespace codequality
}  // namespace tidy
}  // namespace clang

#endif  // LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_CODEQUALITY_UNCHECKEDMALLOCRESULTCHECK_H
