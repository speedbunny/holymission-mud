inherit "room/room";

reset(arg) {
    ::reset(arg);
    if(arg) {
	return;
    }
    short_desc="Jungle Entrance";
    long_desc=
    "As you come over the rise, the mist thins, and a massive jungle\n"+
    "sprawls before you.  Its greenness seems otherworldly as sounds\n"+
    "from a time long-forgotten assault your ears.  Amongst the\n"+
    "vegetation, you notice a small, somewhat beaten path.  It does\n"+
    "not look well travelled.  Suddenly, the chilling bellow of something\n"+
    "hungry stops you in your tracks...\n";
    set_light(1);
    items=({"jungle","It is huge and looks impenetrable, except\n"+
      "for the meager path in front of you.",
      "path","A small path, almost like a deer trail, although\n"+
      "not as faint.  Even though it might be against your\n"+
      "best interests, you could navigate it easily."});
    dest_dir=({
      "players/helmut/rooms/jungle2","north",
      "players/helmut/workroom","south"});
    /* Airborne - 930512 */
    replace_program("room/room");
}
