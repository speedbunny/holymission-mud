inherit "obj/std_trans";
#include "/players/sylvyn/defines/amazon.h"

void reset(int arg) {

    if(arg) return;
    set_short("A Small Boat");
    set_alias("boat");
    set_long("A small boat pulls up to the banks. A ghoul whispers in a bone chilling\n" +
            "voice, "Climb aboard for passage down the river.\n");
    set_inside_long("You climb into the rickety boat, and it squeaks under your wieght\n" +
                  "You wonder if this boad could actually hold you. The ghoul whispers\n" +
                   "agian in his bone chilling voice, "Stay inside the boat, to leave\n" +
                   "would spell certain DEATH!" The ghoul cackles loudly and you feel\n" +
                   "the hair on the back of your neck stand up.\n");
    set_inside_enter("carefully climed into the small boat and quickly took a seat.\n");
 set_outside_enter("paused, looked at the ghoul, shivered and quickly got in the boat.\n");
    set_outside_leave("hastely left the boat, almost falling into the deadly water.\n");
    set_inside_leave("on shakey legs, quickly gets up and heads for the shore.\n");
    set_water(1);
    stop_time(20);
    trans_time(30);
    set_rooms(2,({
                  "PATH+NORTH+"a041.c",
                  "PATH+NORTH+"a058.c",
                }));
    ::reset(arg);
}
