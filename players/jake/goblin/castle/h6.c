#define TP this_player()
#define TPN TP->query_name()
inherit "room/room";
object gob,hat;
reset (arg) {
gob=move_object(clone_object("obj/monster"),this_object());
gob->set_name("goblin chef");
gob->set_short("goblin cook");
gob->set_long("The cook peers back at you.\nHe has food stains all over him, and he doesn't look very happy.\n");
gob->set_level(10);
gob->set_al(100);
gob->set_race("goblin");
gob->set_size(3);
gob->add_money(400);
hat=move_object(clone_object("obj/armour"),gob);
hat->set_name("chef hat");
hat->set_short("chef hat");
hat->set_ac(1);
hat->set_type("helmet");
hat->set_weight(2);
hat->set_size(3);  
hat->set_long("An old looking chef hat.\nIt has numerous food stains on it.\n");
hat->set_value(500);
if (arg) return;
 set_light(2);
 short_desc = "kitchen";
 long_desc =  
              "You are standing in what appears to be the castle kitchen.\n"
           +  "There is a large fireplace against the west wall.\n"
           +  "A large table sets in the middle of the floor.\n" 
           +  "A counter runs across the southern wall.\n"
           +  "A large black iron kettle sits in the fireplace.  It appears empty.\n";
items = ({
  "floor","You are looking at a red stone floor.\nIt has numerous food stains onit", 
  "counter","You see a long counter mounted against the wall.\nIt appears empthy at the moment",
  "fireplace","You see a huge brick fireplace.At the moment there is no fire in it, but a small pile of ash sits is in it",
  "table","You see a large old-looking wooden table",
  "kettle","You see a large black iron kettle.\It looks real old and heavy",
  });
dest_dir = ({
  "players/jake/goblin/castle/h5","north",
});
}
init() {
  ::init() ;
         add_action("search","search");
}
  search(str) {
    switch(str) {
  case "ashes":
   write ("You search through the ashes.\n");
   write ("You feel something..OH!...ahh it's just a piece of wood.\n");
   say (TPN + " searches through a pile of ashes.\n");return 1;
 default:
   write ("Do what?\n");
return 1;
}
}
