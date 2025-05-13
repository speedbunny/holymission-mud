/* KBL's workroom */

inherit "room/room";
#include "/players/kbl/header/T.h"
int locked;

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(2);
    short_desc = "Kbl's humble workroom";
    long_desc = "Ancient cave with lighting provided by moss that grows on\n"+
                "the cave walls. You see many devices of unknown origin\n"+
                "The atmosphere is quiet but you can feel the power of\n"+
                "creation here. A cool breeze coming up from the caverns\n"+
                "below, circulates around you. There's a round table in the\n"+
               "middle of this cave.\n"+
                "There is a sign stuck in the dirt.\n";
    dest_dir = ({"players/kbl/chaos/cho1","chaos",
                 "players/kbl/dungeon/dun5","dung",
                  "players/acdc/office/wiz_office","rules",
                 "players/kbl/boards/player_bug","pbug",
                 "players/kbl/boards/wiz_bug","wbug",
                 "room/church","church",
                 "obj/tick","tick",
                 "room/post","post",
                 "players/kbl/kblroom","entra",
                 "players/kbl/lib/lib1","lib",
                 "players/kbl/pine/toplimb3","pine"});
    items = ({"floor","Natural floor beaten smooth from centuries of\n"+
                       "usage. You see glittering tiny shards of crystal\n"+
                       "scattered about on the floor",
              "ceiling","You see many cracks where the cool breeze flows\n"+
                         "into. Tiny green eyes stare back at you from some\n"+
                         "of the cracks",
              "shards","Tiny white crystal shards",
              "crystal","Tiny white crystal shards",
	      "sign","A sign for Kbl's eyes only!!",
              "eyes","The eyes of cavern mole mites, Kbls' mind helpers"});
    smell = "The air is amazingly fresh here";
    property = "no_hide","no_steal","no_fight";
  }
}


init()
{
  if(locked)
   if(!ck_allow())
   {
    transfer(this_player(),"/players/kbl/kblroom");
    command("look at table",this_player());
    return;
   }
  ::init();
  add_action("lock","lock");
  add_action("find","fnd");
  add_action("look_it","look");
  add_action("em","emo");
  add_action("look_it","scan");
  add_action("touch","touch");
  add_action("get_it","get");
  add_action("block","chaos");
  add_action("block","tick");
  add_action("block","entra");
  add_action("block","lib");
  add_action("block","pine");
  add_action("read","read");
}

lock(str)
{
  if(!str)
   return;
  if(this_player()->query_real_name() != "kbl")
   return;
  switch(str)
  {
    case "room": locked = 0;
            tell_object(this_player(),"You just unlocked the room.\n");
            return 1;
            break;
    case "work": locked = 1;
            tell_object(this_player(),"You just locked the room.\n");
            return 1;
            break;
  }
}

ck_allow()
{
  switch(this_player()->query_real_name())
  {
    case "herp":
    case "moonchild":
    case "warlord":
    case "acdc":
    case "airborne":
    case "helenette":
    case "patience":
         return 1;
         break;
  }
  return 0;
}

block()
{
  string ver;
  string str;
   ver = query_verb();
   switch(ver)
   {
     case "pine":
     case "tick":
     case "entra":
     case "lib":
     case "chaos":
         str = query_verb();
         if(this_player()->query_level() < 29)
         {
           write("You are not allowed access to the "+str+".\n");
            log_file("kbl.work","This person "+this_player()->query_name()+" tryed to leave a illegal way.\n");
           return 1;
         }
     case "church":
     case "post":
         str = query_verb();
         say(this_player()->query_real_name()+" leaves to the "+str+".\n");
         log_file("kbl.work",this_player()->query_real_name()+" went "+str+
                             " at the date: "+
                             ctime(time())+ " *** \n");
         break;
   }
}

em(str)
{
   object tp;

  if(!str)
   return;
  tp = this_player();
  say(capitalize(tp->query_real_name())+" "+str+".\n");
  tell_object(tp,"You say "+capitalize(tp->query_real_name())+" "+str+".\n");
  return 1;
}

look_it(str)
{
  if(!str)
   return;
  if(str == "at table" || str == "table")
  {
    say(this_player()->query_name()+" looks at Kbls work table.\n");
    write("You see various tools that Kbl uses to create the wonderous\n");
    write("worlds you have seen, or will see in the future. Many crystal\n");
    write("ornaments and devices can be seen on the table. They are Kbl's\n");
    write("tho! Do NOT touch!\n");
    return 1;
  }
  if(str == "at moss" || str == "moss")
  {
    say(this_player()->query_name()+" looks at moss on cave walls.\n");
    write("The moss is lime green colored and looks nasty. The moss\n");
    write("seems to move as you look at it. Its definitely alive.\n");
    return 1;
  }
  if(str == "at cave" || str == "cave")
  {
    say(this_player()->query_name()+" looks around the cave here.\n");
    write("Frosty outcroppings of crystal can be seen here and there\n");
    write("around this cave. They seem to give off a power flow of\n");
    write("energy that gives you a lift here!\n");
    this_player()->heal_self(5);
    return 1;
  }
}

get_it(str)
{
  if(!str)
   return;
  if(str == "tools from table" || str == "devices from table")
  {
    say(this_player()->query_name()+" tries to remove things from the table!\n");
    write("You can't take those things, they are Kbl's!\n");
    return 1;
  }
}

touch(str)
{
int val;
  if(!str)
   return;
  if(str == "moss")
  {
    say(this_player()->query_name()+" touches the moss on the cave walls.\n");
    write("The moss feels soft and warm to the touch.\n");
    val = random(8);
    if(val == 1)
     write("Moss thinks to you: Stroke me again! Ahhhhhhh...\n");
    if(val == 3)
     write("Moss says to you: I like you, you like me?\n");
    if(val == 5)
     write("Moss snickers: Love is a most slendid thing!\n");
    if(val == 7)
     write("Moss thinks to you: This is the funny farm, hope you like it!\n");
    return 1;
  }
  if(str == "table")
  {
    say(this_player()->query_name()+" touches the table.\n");
    write("The table is made out of oak and is very smooth.\n");
    return 1;
  }
}

query_matrix()
{
  return "/players/kbl/cry_home";
}
/* From the schmoo herself! SUNSHINE */

read(str)
{
   if(str != "sign")
      return;
        write("The sign sez:\n"+
              "To Kbl, My REAL ONE AND ONLY, FOREVER HUBBY!:\n"+
              "Just a note to tell you that I love you.\n"+
	"And remind you everytime you log on how much I wish I was there.\n"+
              "Jag vill kyssa dig.\n"+
              "Forever yours....\n"+
              "                                 -The real-now Mrs. Kbl.\n"+
              " P.S. If you are not Kbl, WHY are you reading this????\n"+
              " P.S.2 Never forget 14 August 1994!\n"+
              "                                 -Sunshine\n");
	return 1;
}

find(str)
{
  object ob;

  if(!str)
  {
    write("Find who?? [Kbl's workroom]\n");
    return 1;
  }
  if(find_living(str))
  {
    ob = first_inventory(E(find_living(str)));
    write(CP(str)+"is found! Environment dump follows:\n\n");
    while(ob)
    {
      if(ob->QRN)
       write(CP(ob->QRN)+"\n");
      else
        if(ob->short())
         write(ob->short()+".\n");
        else
         write("A invisible of non described object.\n");
      ob = next_inventory();
    }
    write("\nThe above objects are in this following object:\n");
    E(find_living(str))->long();
    return 1;
  }
  write("No such living object called "+CP(str)+".\n");
  return 1;
}
