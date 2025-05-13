/* 12.11.93 Airborne: Changed to room/room */

inherit "room/room";
object bat;

reset(arg){
 if(!arg){
  set_light(1);
  short_desc = "Bottom of the staircase";
  long_desc = 
    "You are at the bottom of the staircase. Nobody has been here for\n"
    "a long time. Still the place is lit up by torches. The atmosphere\n"
    "does not feel very good. You can easily imagine evil creatures\n"
    "lurking behind every corner.\n";
  dest_dir = ({ "players/topaz/angmar/midstairs", "up",
           "players/topaz/angmar/corridor", "east",
           "players/topaz/angmar/torture", "south" });
  items = ({ "staircase", "A staircase filled with stairs",
	"stairs", "Ordinary stairs",
	"torch", "Firey torches",
	"torches", "Firey torches" });
   }

  if(!present("bat", this_object())){
	bat=clone_object("obj/monster");
	/* Macbeth: changed "obj/monster.old" -> "obj/monster" */
	bat->set_name("bat");
	bat->set_level(1);
	bat->set_hp(30);
	bat->set_al(-10);
	bat->set_short("a bat");
	bat->set_wc(2);
	bat->set_ac(0);
	bat->set_aggressive(1);
	bat->set_dead_ob(this_object());
	move_object(bat, this_object());
    }
}

monster_died(dum) {
    write("The bat gives off a high pitched shriek as you\n"+
        "give it a killing blow.\n");
    say("The bat gives off a shriek as "+
    this_player()->query_name()+" kills it.\n");
    return 0;
}

