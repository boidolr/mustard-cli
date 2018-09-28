#ifndef MUSTARD_GITCLIENTFORTEST_H
#define MUSTARD_GITCLIENTFORTEST_H


#include "../../main/git/GitClient.h"

class GitClientForTest : public GitClient
{
public:
    MOCK_METHOD0 (  getHeadCommit, Commitish() );
    MOCK_METHOD0 ( workingDirectoryIsClean, bool() );
    MOCK_METHOD0 ( getFeatureBranchOnOrigin, Commitish() );
    MOCK_METHOD2 ( getMergeBase, Commitish ( const Commitish &, const Commitish & ) );
    MOCK_METHOD1 ( reset, void ( const Commitish & ) );
    MOCK_METHOD1 ( getConfigValue, string ( const string & ) );
    MOCK_METHOD0 ( getDiff, string() );
    virtual ~GitClientForTest() {}

};


#endif //MUSTARD_GITCLIENTFORTEST_H
