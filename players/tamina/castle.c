#define NAME "ted"
#define DEST "/players/blade/area/forest1/forest3"

object coach;

reset(arg) 
{
  if (arg)   return 0;
//  move_object(this_object(), DEST);

/*
    coach = clone_object("/players/tamina/teds/carriage");
    move_object(coach, "/room/vill_road1");
*/
}

string short() 
{ 
  return "A cobblestone path leading north to King Arthurs Castle"; 
}

void long(string str) 
{
  if (str == "path" || str == "north" || str == "arthur" || 
                    str == "cobblestone") 
  {
    write("Far to the north lies king Arthurs castle. There the\n"+
          "knights of the round table gather to rest and relax\n"+
          "after there adventures. Also north lie the dread woods\n"+
          "and the hot and cold lands.\n");
  }
}

int id(string str) 
{
 return str == "path" || str == "north" || str == "cobblestone"
        || str == "arthurs" || str == "arthur" || str == "sign";
}

void init() 
{ 
  add_action("north", "north"); 
}

int north() 
{
  this_player()->move_player("north#/players/tamina/teds/path/path1");
  return 1;
}

int no_clean_up()
{
  return 1;
}

/*  Removed by Matt 08-10-94
void make_quest() 
{
   object ob;

   ob = clone_object("obj/quest_obj");

   ob->set_name("dragon_slayer");
   ob->set_weight(20);
   ob->set_killing(8);
   ob->set_hint("Have the smith make a Dragon Slayer for you.\n");
   ob->set_short_hint("The Quest Perilous");
   ob->add_quest();
}
*/
