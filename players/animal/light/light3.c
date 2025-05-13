inherit "room/room";
 
#define me capitalize(this_player()->query_name())
 
    int class,value,weight;
    object dog, stone;
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
init()
{
    ::init();
    add_action("search","search");
}
 
reset(arg)
{
	if(!arg) {
#if 0 
     ::reset(arg);
     set_outdoors(4);
#endif
     set_light(1);
     long_desc = "The peaceful valley.\n" +
         "\n" +
         "    You have entered a peaceful and serene valley.\n" +
         "    The valley stretches out in all directions far\n" +
	 "    into the distance. The valley is a narrow one.\n"+
         "\n";
    short_desc = "The peaceful valley";
    dest_dir = ({
        "players/animal/light/light2","south",
        "players/animal/light/light10","west",
        "players/animal/light/light11","north",
        "players/animal/light/light9","east"
     });
     items = ({
   "fields","The fields are beautiful, they stretch out far into the distance",
     });
	}
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
 
     if (!dog || !living(dog)) {
         dog = clone_object("obj/monster");
         call_other(dog, "set_name", "lab");
         call_other(dog, "set_alias", "black lab");
         call_other(dog, "set_race", "dog");
         call_other(dog, "set_level", 5);
         call_other(dog, "set_hp", 140);
         call_other(dog, "set_al", 310);
         call_other(dog, "set_short", "A playful black lab");
         call_other(dog, "set_ac", 3);
         call_other(dog, "set_wc", 10);
         call_other(dog, "set_aggressive", 0);
         move_object(dog, this_object());
         stone = clone_object("obj/treasure");
         call_other(stone, "set_id", "ruby");
         call_other(stone, "set_alias", "gem");
         call_other(stone, "set_short", "A small ruby");
         call_other(stone, "set_weight", 2);
         call_other(stone, "set_value", 400);
         move_object(stone, dog);
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
 
 
