#include "Member.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("testing of follow and unfollow function") {
	Member Dor, Sergey;
    Dor.follow(Sergey);
    CHECK(Sergey.numFollowers() == 1);
    Sergey.follow(Dor);
    CHECK(Dor.numFollowers() == 1);
    CHECK(Dor.numFollowing() == 1);
    CHECK(Sergey.numFollowing() == 1);

    Member Aviad, Yarden;

    Aviad.follow(Dor);
    Aviad.follow(Sergey);

    CHECK(Sergey.numFollowers() == 2);
    CHECK(Dor.numFollowers() == 2);

    Aviad.unfollow(Dor);

    CHECK(Sergey.numFollowers() == 1);
    CHECK(Dor.numFollowers() == 2);
}

TEST_CASE("testing the count function") {
	Member Erel;
    CHECK(Member::count() == 1);
    Member Herot;
    CHECK(Member::count() == 2);
}

void test(Member& m){
    Member bar;
    bar.follow(m);
}

   TEST_CASE("Destructor :"){
    Member Noya, Aviv;
    Noya.follow(Aviv);
    CHECK(Aviv.numFollowers()==1);
    test(Aviv);
    CHECK(Aviv.numFollowers()==1);
}