#include "tune.h"

#define TP	this_player()

inherit "room/room";

reset(arg) {
    object ob;

    ::reset(arg);
    if (!arg) {
        set_light( 1 );
        transfer(clone_object("/boards/testp_wanted"),this_object());
        short_desc="Testplayers wanted";
        long_desc=
            "This is the room, where you can register as testplayer for the\n"+ 
            "new Holy Mission. As the new mud is still in a gamma-version,\n"+
            "please note that we can only accept experienced players and we\n"+
            "need to limit the test-players. However, it is a good opportunity\n"+
            "to get used to the new lib, and it's always funny testing.\n"+
            "Please note, that all the testplayers will be removed or\n"+
            "lose levels when we open the mud.\n"+
            "The time when testing can start is September 30, 1995.\n"+
            "Anyway, if you want to test the mud, just leave a note at the "+
            "board.\n";
        dest_dir=({
            "room/adv_guild","east",
                 });
        property=({ "no_fight", "no_sneak","no_steal","has_fire" });
    }
}
