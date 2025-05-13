
inherit"obj/monster";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("purple worm");
set_short("Purple worm");
set_long(
"A purple worm which has made this maze its home. It sustains itself\n"
+ "by eating the decaying bodies of those unfortunate enough not to have\n"
+ "found their way out of the maze of Argannos. Slime drips from its body\n"
+ "as it creeps along the floor in search of another corpse to munch on.\n");
set_level(11);
set_wc(10);
set_race("worm");
set_random_pick(100);
}
