#define TP this_player()
#define TPN TP->query_name()
#define SAY(x) tell_room(environment(), x)

inherit "room/room";
reset (arg){

	set_light(1);
	
	dest_dir = ({"players/airborne/temple/levela/room2", "west", });
	short_desc = "Fountain room";

long_desc =

"Torches line the walls of the small cavern, giving off a bright light.\n"+
"The light reflects off of the water inside a small stone fountain housed\n"+
"in the center of the cavern.\n";
	
	items = 
({"torches", "Torches line the walls separated about every 6 feet",
  "walls", "The walls are rough and dirty",
  "fountain", "As you examine the fountain, you get a strange feeling that\n"+
	      "it is some how different than all the others you have seen.\n"+
	      "The ice blue waters lay dormant inside the basin of stone",
  "water", "The water looks like liquid ice",
}); }
init(){
	::init();
        add_action("push", "press");    add_action("water", "drink");
	add_action("water", "taste");   add_action("water", "touch");
	add_action("quench", "quench"); add_action("swim", "swim");
	add_action("enter", "enter");   add_action("search", "search");
      }

water(str){
	if(str != "water"){
		write("What do you want to do?\n");
			}
	else {
   write("Great pain surges through your body as you touch tremendously\n");
   write("cold water. It is colder than you ever thought water could get.\n");
              TP->misc_hit(10, 3, 0);
              return 1;
       }
}
	
swim(str){
        if ((str=="in water") || (str=="in fountain")) {
             write("As you start to swim in the fountain you feel your blood start\n"+
                    "to freeze up and your body turns blue. You immediately stop swimming\n"+
                    "around.\n");
                     TP->misc_hit(20, 3, 0);
                 return 1;
                 }
                         else {
           write("Where do you want to swim?\n");
                   return 1;
           }
}
search(){
	write("You find nothing important.\n");
	}
quench(str) {
object ob,ob2;
  if (!str) {
             write("Quench what?\n");
     return 1;
     }
   if ((str=="hellfire axe")||(str=="hellfire")) {
    if (present("hellfire",TP)) {
             write("You put the Hellfire Axe into the fountain. As you do you see a \n"+
           "blinding flash of light and then it dims. The axe looks quenched.\n");
	this_player()->set_quest("hellfire");
  ob=present("hellfire",TP);
  destruct(ob);
  ob2=clone_object("players/airborne/weapons/quest_axe");
  transfer(ob2,TP);
     return 1;
             }
else {
                    write("You don't have the axe on you.\n");
            return 1;
            }
    }
  else {
            write("You can't quench that.\n");
    return 1;
            }
}
