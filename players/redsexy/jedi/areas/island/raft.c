inherit "obj/std_trans";

reset(int arg) {

    if(arg) return;
    set_short("The Jedi Islands Raft");
    set_alias("raft");
    set_long("A rickety sailing raft, bound for the Jedi islands.\n");
    set_inside_long(      "One of Jabba's sail barges which run between The \n" +
          "Island of Carkoon and the Mos Eisley Desert ports.  The craft\n" +
          "is very rickety, and you begin to wonder if it is at all \n" +
          "sea worthy! Porcilius, the captain of the barge, stands at \n"+
          "the helm, guiding you across the Dune Sea. \n");
    set_inside_enter("climbs aboard the raft.\n");
    set_outside_enter("climbs aboard the raft.\n");
    set_outside_leave("leaves the raft.\n");
    set_inside_leave("leaves the raft.\n");
    set_water(1);
    stop_time(30);
    trans_time(20);
    set_rooms(3,({
                 "/players/redsexy/jedi/areas/desert/d5",
                 "/players/redsexy/jedi/areas/island/5",
                 "/players/redsexy/jedi/areas/start/port1",
                }));
    move_object(this_object(),"/players/redsexy/jedi/areas/start/port1");
    ::reset(arg);
}
