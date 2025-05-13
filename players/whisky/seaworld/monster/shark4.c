
/* shark4 */

inherit "/obj/monster";
#include "bad_fish.h"

void reset(int arg) 
{
    ::reset(arg);
    if (arg) return;

    set_name("shark");
    set_alias("black shark");
    set_level(35);
    set_aggressive(1);
    set_has_gills();
    set_size(5);
    set_race("fish");
    set_aggressive(1);
    set_short("A black Shark");
    set_long("You see a big teeth snapping after your feet.\n");
    load_a_chat(80, ({
	"You see big teeth snapping at your feet!\n",
	"A mad shark gets mad and tries to tear off your head!\n",
      }) );
    move_object(clone_object("players/whisky/seaworld/obj/teeth"),this_object());
    init_command("wield teeth");
}

run_away() { return 0; }
stop_fight() { return 0; }
