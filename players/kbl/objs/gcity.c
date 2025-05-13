/*
    Generic city.

    Special actions:

    listen/hear <sound> on the <direction>
    climb <direction>
    toss/throw <rope,kevlon,wire> over <pole,protrusion>
    remove <rope,kevlon,wire> from <pole,protrusion>
    attach <rope,kevlon,wire> to <pole,protrusion>
    smell *no argument needed*

*/

inherit "room/room";
#define TP this_player()
#define TO this_object()
#define CP(x) capitalize(x)
#define TPRN  TP->query_real_name()

string *search_items;
string *hear_items;
string *room_sound;
string *tie_array;
string *tie_type_array;
string *smells;
string DEST;
string TREE;
string TREDWN;
string TOP;
string BOTTOM;
string climb_top;
string climb_down;
string climb_up;

int    sm_idx;
int    attach;
int    tied;
int    level;
int    top_level;
int    HDEX;
int    DIFF;
int    spice_here;

object ropedown,
       ropehere;


reset(arg)
{
  if(!arg)
  {
    sm_idx = 0;
    set_light(1);
    set_level(1);
    set_top_level(0);
    set_attach(0);
    set_tied(0);
    set_cdesc("none","none","none");
    set_spice_here(2);
    set_hard_dex(10);
    set_diff_fac(10);
    set_sound_dest("none");
    set_tree_up("none");
    set_tree_down("none");
    set_tree_top("none");
    set_tree_bottom("none");
    long_desc = "Buildings line the street. Gray and black buildings that\n"+
                "seem to be lifeless. The building tops are shrouded in\n"+
                "a thick chemical fog. Walls of the buildings are rough\n"+
                "as if their creators did not care about looks.\n";
    tie_type_array = ({
                "wall",
                "building top",
               });
    tie_array = ({
                "rope",
                "wire",
                "kevlon",
               });
    smells = ({
                "Nasty sulfur and other chemicals drift by your nose",
                "The scent of a dog greets you senses",
                "A welcomed wisp of fresh air moves past your nose",
                "A garbage smell dominates you senses for a second",
                "A fishy smell drifts through",
               });
    search_items = ({
                "spice",
               });
    room_sound = ({
                "The wind whips through bringing faraway sounds.\n",
                "You hear the howling on the wind.\n",
                "You can hear a slight breeze above you.\n",
                "The city sounds make you shiver.\n",
                "You all of a sudden hear a chirping noise.\n",
                "You hear liquid dripping somewhere.\n",
               });
    items = ({
                "street","Very clean street",
                "buildings","Completely sealed. No entrances",
                "building tops","Too far up to get a clean view of",
                "city","Its all around you",
                "walls","SteelCrete walls. Very dense and unbreakable",
                "steelcrete","Unknown how the Ixians make the stuff",
               });
    hear_items = ({
                "noise","There's always noise in a city",
                "sounds","Very muddled and distant",
                "city","The city sounds give you an errie feeling",
                "howling","A dog or some other creature in pain",
                "wind","You hear a dog crying somewhere",
                "breeze","It moves fearfully through the buildings",
                "chirping","Sounds coming from birds or animals",
                "dripping","The sound of dripping liquid echos here",
               });
  }
}

init()
{
  if(room_sound)
   gen_sound();
  if(smells)
   gen_smell();
  ::init();
  add_action("srch_it","search");
  add_action("hear","hear");
  add_action("hear","listen");
  add_action("smell","smell");
  add_action("climb","climb");
  add_action("attach","attach");
  add_action("remove","remove");
  add_action("toss","throw");
  add_action("toss","toss");
}

toss(str)
{
  string IN1,IN2;

  if(TREE == "none")
  {
    write("There is nothing low enough here to toss anything over.\n");
    return 1;
  }
  if(!str)
  {
    write("Toss what over where??\n");
    return 1;
  }
  if((sscanf(str,"%s over the %s",IN1, IN2) == 2) ||
     (sscanf(str,"%s over %s",IN1, IN2) == 2))
  {
    if(tied)
    {
      write("There's a "+IN1+" hanging down from above already.\n");
      return 1;
    }
    if((ropehere = present(IN1,TP)) &&
       (member_array(IN1,tie_array)+1) &&
       (member_array(IN2,tie_type_array)+1))
    {
     if(TP->query_dex()-random(DIFF) > HDEX+TP->query_intoxination())
     {
      transfer(ropehere,TO);
      ropehere->auto_tie("a "+IN2+" above you",TO);
      tied = 1;
      say(CP(TPRN)+" throws a "+IN1+" over a "+IN2+" on the building.\n");
      write("You toss the "+IN1+" over a "+IN2+". You catch the end and tie\n"+
            "a slip nott and draw it back up tight.\n");
      TREE->set_rope_down(ropehere);
      TREE->set_attach(1);
      TO->set_tied(1);
      return 1;
     }
     write("Your vision blurs and you fail to throw the "+IN1+" correctly.\n");
     return 1;
    }
    if(!ropehere)
    {
      write("You do not have a "+IN1+" to throw or toss.\n");
      return 1;
    }
    write("You "+query_verb()+" the "+IN1+" but it just falls back to you.\n");
    return 1;
  }
  write(CP(query_verb())+" what over where??\n");
  return 1;
}

smell(str)
{
  write(smells[sm_idx]+".\n");
  return 1;
}

gen_smell()
{
  int idx;

  idx = random(sizeof(smells)+random(15));
  if(idx < sizeof(smells))
  {
   tell_room(TO,smells[idx]+"\n");
   sm_idx = idx;
  }
}

attach(str)
{
  string IN1,IN2;

  if(TREDWN == "none")
   return;
  if(!str)
  {
    write("Attach what to where??\n");
    return 1;
  }
  if((sscanf(str,"%s to the %s",IN1,IN2) == 2) ||
     (sscanf(str,"%s to %s",IN1,IN2) == 2))
  {
    if(attach)
    {
      write("You see there's a "+IN1+" already attached here.\n");
      return 1;
    }
    if((ropedown = present(IN1,TP)) &&
       (member_array(IN1,tie_array)+1) &&
       (member_array(IN2,tie_type_array)+1))
    {
     if(TP->query_dex()-random(DIFF) > TP->query_intoxination()+HDEX)
     {
      transfer(ropedown,TREDWN);
      TREDWN->set_rope_here(ropedown);
      ropedown->auto_tie("a "+IN2+" above you",TREDWN);
      attach = 1;
      say(CP(TPRN)+" attaches a "+IN1+" to a "+IN2+" and lowers the "+IN1+" down.\n");
      write("You attach the "+IN1+" to the "+IN2+" and lower the "+IN1+" down.\n");
      TREDWN->set_tied(1);
      TO->set_attach(1);
      return 1;
     }
     write("Your vision blurs and you fail to attach the "+IN1+".\n");
     return 1;
    }
    write("You try to attach the "+IN1+" to the "+IN2+" but fail.\n");
    return 1;
  }
  write("Attach what to where??\n");
  return 1;
}

remove(str)
{
  string IN1,IN2;

  if(!str)
  {
    write("Remove what from where??\n");
    return 1;
  }
  if(TREDWN == "none")
   return;
  if(attach)
  {
   if(sscanf(str,"%s from %s",IN1,IN2) != 2)
   {
     write("Remove what from where??\n");
     return 1;
   }
   if((member_array(IN1,tie_array)+1) &&
      (member_array(IN2,tie_type_array)+1))
   {
    if(TP->query_dex()-random(DIFF) > TP->query_intoxination()+HDEX)
    {
      write("You remove the "+IN1+".\n");
      say(CP(TPRN)+" removes a "+IN1+".\n");
      ropedown->auto_tie(0,0);
      transfer(ropedown,TP);
      ropedown = 0;
      TREDWN->set_rope_here(0);
      set_attach(0);
      TREDWN->set_tied(0);
      tell_room(TREDWN,"Someone just pulled up the "+IN1+"!\n");
      return 1;
    }
    write("Your hands fail as you try to remove the "+IN1+".\n");
    return 1;
   }
   write("Remove what from where??\n");
   return 1;
  }
  write("There's no "+IN1+" attached here.\n");
  return 1;
}

climb(str)
{
  switch(str)
  {
    case "building":
        if(present("hy_gear",TP) && TOP != "none")
        {
          DHG(present("hy_gear",TP),"up",TOP,top_level,0);
          return 1;
        }
        write("You do not possess the proper gear to climb this building.\n");
        return 1;
    case "up":
        if(present("hy_gear",TP) && TREE != "none")
        {
          DHG(present("hy_gear",TP),"up",TREE,1,2);
          return 1;
        }
    case "rope":
    case "wire":
    case "kevlon":
        if(tied)
        {
           if(TP->query_dex()-random(DIFF) < TP->query_intoxination()+HDEX)
             set_spice_here(random(DIFF)+5);
           TP->move_player("by climbing up a "+str+"#"+TREE);
           return 1;
        }
        write("Nothing to climb with here.\n");
        return 1;
    case "down":
        if(level == 1 && BOTTOM == "none" && TREDWN == "none")
        {
          write("Climb down?? You are on the ground!\n");
          return 1;
        }
        if(attach)
        {
          TP->move_player("climbing down#"+TREDWN);
          return 1;
        }
        if(present("hy_gear",TP) && BOTTOM != "none")
        {
          DHG(present("hy_gear",TP),"down",BOTTOM,level,1);
          return 1;
        }
        write("You have to attach something here before trying to climb down.\n");
        return 1;
  }
}

DHG(gear,str,dest,lvl,ty)
{
  write("You start climbing "+str+" at a rapid rate!\n");
  say(CP(TPRN)+" starts climbing "+str+" at a rapid rate!\n");
  gear->set_bdesc(query_cdesc(ty));
  gear->set_dest(dest);
  gear->set_levels(lvl);
  gear->set_start();
  return 1;
}

srch_it(str)
{
  string item;
  object ob;

  if(!str)
  {
    write("Search for what??\n");
    return 1;
  }
  if(sscanf(str,"for %s",item) != 1)
   return;
  if(member_array(item,search_items) == -1)
  {
    write("You cannot locate a "+item+" here.\n");
    return 1;
  }
  switch(item)
  {
    case "spice":
        if(TREE == "none")
        {
          write("You search but cannot locate any spice here.\n");
          return 1;
        }
        if(spice_here > 5)
        {
          if(TP->query_dex() > HDEX)
          {
            TP->add_money(spice_here);
            write("You find "+spice_here+" bits of spice here!\n");
            say(CP(TPRN)+ "searched and found some bits of spice.\n");
            spice_here = 2;
            return 1;
          }
          write("It seems you cannot find anything.\n");
          return 1;
        }
        write("You search for but cannot locate any bits of spice.\n");
        return 1;
        break;
    case "dog":
         break;
    case "lotus":
         break;
    case "clover":
         break;
  }
}


hear(str)
{
  string IN1,IN2;
  int    flag;

  flag = 0;
  if(str)
  {
   if(hear_items)
   {
    if(sscanf(str,"the %s in the %s",IN1,IN2) == 2)
      flag = 1;
    if(sscanf(str,"the %s of the %s",IN1,IN2) == 2)
     flag = 1;
    if(sscanf(str,"to the %s of the %s",IN1,IN2) == 2)
     flag = 2;
    if(sscanf(str,"to the %s in the %s",IN1,IN2) == 2)
      flag = 2;
    if(sscanf(str,"to the %s on the %s",IN1,IN2) == 2)
      flag = 2;
    if(!flag)
    {
      write("You do not hear anything special around here.\n");
      return 1;
    }
    process(flag,IN1,IN2);
    return 1;
   }
  }
  write("You wanting to hear or listen to something?\n");
  return 1;
}

process(flag,str1,str2)
{
  int idx;

  switch(flag)
  {
    case 1:
       if((idx = member_array(str1,hear_items)) != -1)
        write(hear_items[idx+1]+".\n");
       else
        write("Hear the or listen to the "+str1+"??\n"); 
       break;
    case 2:
       if((idx = member_array(str1,hear_items)) != -1)
       {
         if(str1 != "sounds" && DEST != "none")
         {
           TP->move_player("suddenly in a flash of energy light#"+DEST);
           return 1;
         }
         write(hear_items[idx+1]+".\n");
         return 1;
       }
       break;
  }
}

gen_sound()
{
  int idx;

  idx = random(sizeof(room_sound)+random(8));
  if(idx < sizeof(room_sound))
   tell_room(TO,room_sound[idx]+"\n");
}

set_sound_dest(str)
{
   DEST = str;
  if(str == "none")
   return;
  if(!find_object(DEST))
    call_other(DEST,"???");
}

set_tree_down(str)
{
  TREDWN = str;
  if(str == "none")
   return;
  if(!find_object(TREDWN))
    call_other(TREDWN,"???");
}

set_tree_up(str)
{
   TREE = str;
  if(str == "none")
   return;
  if(!find_object(TREE))
    call_other(TREE,"???");
}

set_tree_top(str)
{
   TOP = str;
  if(str == "none")
   return;
   if(!find_object(TOP))
    call_other(TOP,"???");
}

set_tree_bottom(str)
{
  BOTTOM = str;
  if(str == "none")
   return;
   if(!find_object(BOTTOM))
    call_other(BOTTOM,"???");
}


set_city_name(str,str2)
{
  if(str == "none" && str2 == "none")
  {
   short_desc = "A City street";
   return;
  }
  if(str == "none")
  {
   short_desc = str2;
   return;
  }
  if(str2 == "none")
  {
   short_desc = str+" city street";
   return;
  }
  short_desc = str+" "+str2;
}

untie()
{
  return 0;
}

query_cdesc(n)
{
  switch(n)
  {
    case 0:
      return climb_top;
    case 1:
      return climb_down;
    case 2:
      return climb_up;
  }
}


query_tied()
{
  return tied;
}

set_cdesc(str1,str2,str3)
{
  if(str1 != "none")
   climb_top = str1;
  if(str2 != "none")
   climb_down = str2;
  if(str3 != "none")
   climb_up = str3;
}

set_tied(n)
{
  tied = n;
}

set_level(n)
{
  level = n;
}

set_top_level(n)
{
  top_level = n;
}


query_attach()
{
  return attach;
}

set_attach(n)
{
  attach = n;
}

set_rope_down(ob)
{
  ropedown = ob;
}

set_rope_here(ob)
{
  ropehere = ob;
}

set_hard_dex(n)
{
  HDEX = n;
}

set_diff_fac(n)
{
  DIFF = n;
}

set_spice_here(n)
{
  spice_here += n;
}
