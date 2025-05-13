inherit "room/room";
#define me capitalize(this_player()->query_name())
 
    object ghost, axe;
    int g;
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
init()
{
    ::init();
    add_action("search","search");
    add_action("_get","get");
	add_action("_get","take");
}
 
reset(arg)
{
     if(!arg) {
 
     ::reset(arg);
/*  set_outdoors(0);  */
     set_light(1);
     long_desc = "The dead end\n" +
         "\n" +
         "    The caves come to an abrupt end here. You notice the\n" +
         "    walls here do not emit the same kind of light as the\n" +
         "    other cave walls. This light is much more intense.\n\n";
    short_desc = "The dead end";
    dest_dir = ({
        "players/animal/cave/22","south",
     });
     items = ({
   "walls","The walls here are illuminated with an eery light",
     });
     }
     g=0;
     extra_reset();
     return;
}
 
query_long() { 
    return long_desc; 
} 
 
query_light() {
    return 1;
}
 
 
extra_reset()
{
 
     if (!axe) {
         axe = clone_object("players/animal/obj/axe");
         move_object(axe, this_object());
     }
}
 
search(str) {
    if (!str) str = "room";
    if (str == "room") {
          write("You find nothing unusual.\n");
          say(me + " searches the room.\n");
            return 1;
        }
     return 0;
}
 
_get(str) {
     if(present("axe", this_object())) {
     if(str == "all" || str == "axe" || str == "rusty axe" || str == "pick axe")  {
        if(ghost) {
     write("The ghost stops you from taking the axe.\n");
     return 1;
     }
     if (g==1) return;
     write("As you attempt to get the axe, you hear a high pitched voice screaming this: \n\n");
     tell_room(this_object(),"  NO ONE may touch the axe unless they deal with me first!\n");
     tell_room(this_object(), "  You thought I was DEAD, you were wrong,\n" +
     "  DEAD wrong!!!!! MUHAHAHAHAHAHA!!!!!\n\n");
     g=g+1;
     call_out("monster",2);
     return 1;
    }
        }
     return;
}
 
monster() {
           if (!ghost || !living(ghost)) {
     tell_room(this_object(),"The ghost of the mystic appears and starts to take his revenge.\n\n\n");
         ghost = clone_object("obj/monster");
         call_other(ghost, "set_name", "ghost of mystic");
         call_other(ghost, "set_alias", "mystic");
         call_other(ghost, "set_race", "ghost");
         call_other(ghost, "set_level", 16);
         call_other(ghost, "set_hp", 450);
         call_other(ghost, "set_al", 700);
         call_other(ghost, "set_short", "The ghost of the mystic");
         call_other(ghost, "set_long", "This ghost is the ghost of the" +
          " mystic that was killed by you.\n");
         call_other(ghost, "set_ac", 9);
         call_other(ghost, "set_wc", 19);
         call_other(ghost, "set_aggressive", 1);
         move_object(ghost, this_object());
         call_other(ghost,"attack_object",this_player());
     }
}
realm () { return "NT"; }
