int main() {
    object mage,soul;

    mage=this_player();
    if(!mage)
        return 0;
    else
        soul=present("magesoul",mage);
    if(!soul)
        return 0;
    else
        return soul->reveal_me();
}
