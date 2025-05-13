/* outside gates */

#define TP this_player()
#define TO this_object()
#define TPN TP->query_name()

inherit "/room/room";

int is_broken;

int query_is_broken()
{ 
    return is_broken; 
}

int fall_stone()
{
  object *all;
  int i;

// query_hp is better because then its a monster or a player for sure
// the filter_object filters all object called by a call_other fun

  all = filter_objects(all_inventory(TO),"query_hp");

  if (sizeof(all))
  {
      i=random(sizeof(all));
     /*
      write("INFO"+to_string(i)+"\n");
      write(to_string(sizeof(all))+"\n"+all[0]->query_name()+"\n");
     */
      all[i]->hit_player(5+random(10));
      tell_object(all[i],"A big boulder smashes you to the head.\n");
      say("A big boulder smashes "+all[i]->query_name()+" to the head.\n",
          all[i]);
  }
  move_object(clone_object("/players/goldsun/green_island/obj/boulder"),TO);
  return 1;
}


void reset(int arg)
{

 is_broken=0;

 ::reset(arg);

 if (!arg)
 {

 set_light(1);
 short_desc=("In front of gates");
 long_desc=
   "You are standing on the high cliff in front of a large gates to\n"+
   "the Rockland Castle. To the east you can see a nice green plain,\n"+
   "but there is a deep abyss between you and it. From the abyss you\n"+
   "can hear a crackle of sea waves.\n";

    smell="The air is fresh.";

    dest_dir=({ "/players/goldsun/green_island/room/hill2","east"});

    items=({"gates","@@query_gates@@"});
  }
}

string query_gates()
{
 if (is_broken) 
     return "The gates are broken";
 return "The gates are closed and looks very sturdy";
}

void init()
{
 ::init();
 add_action("enter","enter");
 add_action("open","open");
 add_action("d_break","break");
 add_action("d_break","smash");
}

int d_break(string str){
 notify_fail("Break or Smash what?\n");
 if (str=="gates"){
   if (is_broken){
     write("But the gates are already broken.\n");
     return 1;
   }
   if (present("ebony goldsun tree",TP)){
       write("BANG\nCRACK\n\nShhhhhhhh\n\nBeng\nYou break the gates.\n");
       say(TPN+" breaks the gates.\n");
       is_broken=1;
       return 1;
   }
   write("You take your head and foolishly bang to the gates.\n\nOUCH\n\n"+
	 "That hurts.\n");
   say(TPN+" takes his head and foolishly bangs to the gates.\n");
   TP->hit_player(2);
   return 1;
 }
 return 0;
}

int open(string str){
 notify_fail("Open what ?\n");
 if (!str) return 0;
 if (str=="gates"){
   if (is_broken){
       write("The gates are broken, you can pass.\n");
       return 1;
   } 
   write("You try to open it. But how ?\n");
   say(TPN+" tries to open the gates.\n");
   return 1;
 }
 return 0;
}  

int enter(string str){
 if (str=="gates" || str=="castle"){
   if (is_broken) TP->move_player("into the castle#/players/goldsun/green_island/room/gates");
    else write("You bang your head against the gates.\n");
    return 1;
 }
 notify_fail("Enter what ?\n");
 return 0;
}
