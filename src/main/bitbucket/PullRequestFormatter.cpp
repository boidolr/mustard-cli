#include <sstream>
#include "PullRequestFormatter.h"

string PullRequestFormatter::format ( const PullRequest &pullRequest )
{
    stringstream ss;
    ss << " *** " << formatBold << pullRequest.title << formatNormal << " *** " << endl;
    ss << pullRequest.description << endl << endl;
    ss << "author:        " << formatUser ( pullRequest.author ) << endl;
    ss << "reviewers: ";
    bool hasReviewers = false;
    for ( const auto &reviewer : pullRequest.reviewers ) {
        if ( !hasReviewers ) {
            hasReviewers = true;
        } else {
            ss << "           ";
        }
        ss  << symbol ( reviewer.status ) << " " << formatUser ( reviewer.user ) << endl;
    }
    if ( !hasReviewers ) {
        ss << "    <none>";
    }
    ss << endl << endl;
    ss << "View in BitBucket: " << pullRequest.url << endl << endl;
    return ss.str();
}

std::ostream &PullRequestFormatter::formatBold ( std::ostream &stream )
{
    return stream << "\e[1m";
}

std::ostream &PullRequestFormatter::formatNormal ( std::ostream &stream )
{
    return stream << "\e[0m";
}

string PullRequestFormatter::symbol ( ReviewStatus status )
{
    switch ( status ) {
    case UNAPPROVED:
        return "[ ]";
    case APPROVED:
        return "[\033[0;32m✓\033[0m]";
    case NEEDS_WORK:
        return "[\033[0;31m✗\033[0m]";
    }
}

string PullRequestFormatter::formatUser ( const User &user )
{
    stringstream ss;
    ss << formatBold << user.displayName << formatNormal << " <" <<  user.eMail << ">";
    return ss.str();
}
