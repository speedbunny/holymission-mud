inherit "room/room";
reset (arg) {
   if (arg) return;
   clone_list=({
        1, 3, "peasant","players/bobo/monsters/peasant", 0,
   });
   ::reset(arg);
   set_light (1);
   short_desc="In the stands.";
   long_desc=
"As you enter this area the crowd scatters.  Though they all came to\n"+
"see people and animals kill eachother having a combatant in the\n"+
"stands was more than they bargained for, and now they are running\n"+
"for their lives.\n";
   dest_dir=({
        "players/bobo/arena/s5.c","northwest",
        "players/bobo/arena/s3.c","southwest",
        "players/bobo/arena/a9.c","down",
   });
   items=({
        "crowd","Once bold and brash, these people are fleeing for their lives",
        "people","The The people in the arena don't seem to notice this way into the stands",
        "animals","The animals in the arena are fighting with each other",
   });
   replace_program("room/room");
}
