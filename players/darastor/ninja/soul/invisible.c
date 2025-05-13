#define COST	40

int main() {
    object mage,soul;

    mage=this_player();
    if(!mage)
        return 0;
    else
        soul=present("magesoul",mage);
    if(!soul)
        return 0;
    else if(mage->query_invis()) {
        write("You are already as invisible as you can get.\n");
        return 1;
    }
    else if(mage->query_sp()<COST && !mage->query_immortal()) {
        write("You do not have enough energy.\n");
        return 1;
    }
    else {
        if(!mage->query_immortal())
            mage->restore_spell_points(-COST);
        write("You vanish from sight.\n");
        say(mage->query_name()+" vanishes from sight.\n");
        mage->set_invis();
        soul->reveal_me(mage->query_level()*20,0);
        return 1;
    }
}
