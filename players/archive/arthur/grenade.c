/* The Holy hand Grenade by ARTHUR */

inherit "obj/treasure";

reset(arg) 
{
  if (arg) return;
     set_alias("grenade");
     set_short("The Holy hand Grenade");
     set_long("This is a Holy hand Grenade, it has been blessed by the church \n"+        
      "judging its weight, you think that you could throw it fairly well.\n");
     set_value(4000);
     set_weight(1);
}
init() {
   add_action("tp_throw", "throw");
   ::init();
}
tp_throw(str) {
  if (!str)
     return 0;

  if (str!="grenade")
     return 0;
	/* if (file_name(enviroment(this_player()))=="players/arthur/area/entrance") */
  if(str)

     { write("You pull the pin out of the grenade, count up to three, not to one,\n"+ 
     "not to two, but three, you heave the grenade into the rabbit hole.\n"+
     "You here the grenade blow up, the ground trembles, and you fall into\n"+
     "the hole!\n"); 
   destruct(this_object());
     return 1;}

  else {
      write("You go to throw it, but realize that there is no place to throw it to.\n"); 
      return 1;}
   }
