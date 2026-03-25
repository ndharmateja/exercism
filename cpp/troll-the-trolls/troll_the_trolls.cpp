namespace hellmath
{

    // Task 1 - Define an `AccountStatus` enumeration to represent the four
    // account types: `troll`, `guest`, `user`, and `mod`.
    enum class AccountStatus
    {
        troll,
        guest,
        user,
        mod
    };

    // Task 1 - Define an `Action` enumeration to represent the three
    // permission types: `read`, `write`, and `remove`.
    enum class Action
    {
        read,
        write,
        remove
    };

    // Task 2 - Implement the `display_post` function, that gets two arguments
    // of `AccountStatus` and returns a `bool`. The first argument is the status of
    // the poster, the second one is the status of the viewer.
    bool display_post(AccountStatus poster, AccountStatus viewer)
    {
        // If the poster isn't a troll, we can directly return true
        // as anyone can see the posts by non-trolls
        // But if the poster is a troll, only trolls can see the posts
        return (poster != AccountStatus::troll) || (viewer == AccountStatus::troll);
    }

    // Task 3 - Implement the `permission_check` function, that takes an
    // `Action` as a first argument and an `AccountStatus` to check against. It
    // should return a `bool`.
    bool permission_check(Action action, AccountStatus account)
    {
        switch (account)
        {
        // Guests can only read
        case AccountStatus::guest:
            return action == Action::read;

        // Users and trolls can read and write
        case AccountStatus::user:
        case AccountStatus::troll:
            return action == Action::read || action == Action::write;

        // Mods can do everything
        case AccountStatus::mod:
            return true;
        }

        // this is redundant, only for the compiler as we will never reach here
        return false;
    }

    // Task 4 - Implement the `valid_player_combination` function that
    // checks if two players can join the same game. The function has two parameters
    // of type `AccountStatus` and returns a `bool`.
    bool valid_player_combination(AccountStatus p1, AccountStatus p2)
    {
        // If either player is guest we return false
        if (p1 == AccountStatus::guest || p2 == AccountStatus::guest)
            return false;

        // At this point there are no guests
        // If both are trolls, we return true
        if (p1 == AccountStatus::troll && p2 == AccountStatus::troll)
            return true;

        // If either player is true we return false, true otherwise
        return p1 != AccountStatus::troll && p2 != AccountStatus::troll;
    }

    // Task 5 - Implement the `has_priority` function that takes two
    // `AccountStatus` arguments and returns `true`, if and only if the first
    // account has a strictly higher priority than the second.
    bool has_priority(AccountStatus a1, AccountStatus a2)
    {
        // If both accounts are same, we return false as account1 doesn't have
        // strictly higher priority over account2
        // if (a1 == a2)
        // return false;

        // At this point, both accounts are different
        // If first account is a moderator or if second account is a troll, then a1 > a2
        // if (a1 == AccountStatus::mod || a2 == AccountStatus::troll)
        // return true;

        // If first account is user and second account is guest, then a1 > a2
        // if (a1 == AccountStatus::user && a2 == AccountStatus::guest)
        // return true;

        // In all other cases, a1 < a2
        // return false;

        // Easier solution would be to order the enum values in
        // increasing order of priorities
        // troll, guest, user, mod => mod will always be top priority and troll the bottom
        // and user is greater than guest
        return a1 > a2;
    }

} // namespace hellmath
