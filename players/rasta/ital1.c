#include "std.h"

int lamp_is_lit, reboot_time, time_from_reset, last_reset_cycle;
int list_length;

reset(arg)
{
    set_light(1);
}

init()
{
    add_action("close", "close");
    add_action("pray", "pray");
    add_action("pray", "regenerate");
    add_action("south", "south");
}

short() {
    return "Rasta Chapel";
}

long(str)
{
    write("Light in the stained-glass windows flickers from the dozens of\n" +
	 "long candles and topers burn silenty\n");
    write("Blown-up sepia portraits of Marcus Garvey and Haile Selassie\n");
    write("are propped up against the ground and red-green-gold bunting\n");
    write("drapes the floor.\n");
    write("Dead rastamen come here to pray.\n");
    write("There is an exit to the south.\n");
}

pray() {
    return call_other(this_player(), "remove_ghost", 0);
}

prevent_look_at_inv(str)
{
    return str != 0;
}

south() {
 call_other(this_player(), "move_player", "south#players/rasta/room/yard1");
    return 1;
}

