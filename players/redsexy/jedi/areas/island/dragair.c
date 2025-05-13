inherit "obj/std_trans";

reset(int arg) {

    if(arg) return;
    set_short("Dragon airways");
    set_alias("dragon");
    set_long("A very large dragon looms up before you. There " +
             "appears to be several saddles resting atop the " +
             "top of the dragon. You can feel that this is a " +
             "tame beast and you have nothing to fear.\n");
    set_inside_long("You are sitting on the back of a large dragon\n" +
                    "used for transportation around Holy Mission.\n");
    set_inside_enter("climbs aboard and takes a place on a saddle.\n");
    set_outside_enter("climbs up onto the dragon and takes a seat.\n");
    set_outside_leave("drops from the top of the dragon.\n");
    set_inside_leave("climbs down looking for adventure.\n");
    set_flying(1);
    stop_time(15);
    trans_time(10);
    set_rooms(5,({
                  "players/warlord/trans/port3",
                  "players/warlord/trans/port4",
                  "players/warlord/trans/port5",
                  "players/warlord/trans/port6",
                  "players/warlord/trans/port1",
                }));
    move_object(this_object(),"/players/warlord/trans/port1");
    ::reset(arg);
}
