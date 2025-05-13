inherit "room/room";

#include "/players/blade/area/blade_defs.h"

int get(string str_arg);

reset(arg) {
  int mon_numbers;

    if(!arg) {
        set_light(1);
        short_desc="The ore refining area",
        long_desc=
  "This is a large room filled with blackish smoke.  Prisoners dump\n"+
  "the cleaned ore into bowl shaped furnaces, which are built of stone and\n"+
  "lined with clay.  The furnaces are set on the edge of depressions carved\n"+
  "out of the ground.  Wolfen craftsmen man the ovens, draining the slag\n"+
  "from the furnaces.  Ingots are cooling near each of the furnaces.\n";
   dest_dir=({
	    CAMPPATH+"ore_refining_area.c", "north", 
                 });
   items=({ 
  "ore","The silver ore is the consistency of gravel",
  "furnace","Very hot furnaces with small front openings",
  "opening","An opening in the front of a furnace used to drain the slag"
  "slag","Very hot slag being drained out of the furnaces",
  "ingot","A large silver ingot left to cool",
  "ingots","Large silver ingots left to cool.",
  "depressions","Fires rage in these shallow depressions",  
  "clay","Very hot clay that lines the furnaces.",
  "ovens","Very hot furnaces with small front openings",
  "stone","Large stones which make up the furnaces",
  "ground","It is covered with black soot and silver ore",
});

        smell = "You smell smoke.";
	enable_commands();
    }
/*****  Mangla removed since something buggy  *****
    mon_numbers=(7-(filter_live(this_object(),"wolfen worker")));
   clone_x_of_y(mon_numbers,"/players/blade/area/monsters/wolfen_worker");
******  end of comment out  ******/

}

int get (string str_arg){
  if(str_arg=="ingot" ||str_arg=="ingots"){
    write("You try to pick up a cooling ingot and burn your hand!\n");
    say(PNAME+" tries to pick up an ingot and burns his hand!\n");
    command("shout OUCH!!!",TP);
    TP->hit_player(10);
    return 1;
  }
  return 0;
}

init(){
  ::init();
    add_action("get","get");
  }

