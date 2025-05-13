/*
    Generic forest room. Special function hear gives new dimension to
your average room. Eventually it will trap says in this room and respond if
set up in this object

*/

inherit "room/room";
#define TCL(file) transfer(clone_object(file),this_object())
#define TP this_player()
#define TO this_object()
#define CP(x) capitalize(x)
#define TPRN  TP->query_real_name()

string *search_items;
string *hear_items;
string *room_sound;
string DEST;
string TREE;
string TREDWN;
int    attach;
int    tied;
int    level;
int    HDEX;
int    DIFF;
int    spice_here;
object ropedown,ropehere;


reset(arg)
{
  if(!arg)
  {
    set_light(1);
    set_level(1);
    set_attach(0);
    set_tied(0);
    set_spice_here(2);
    set_hard_dex(10);
    set_diff_fac(10);
    set_sound_dest("none");
    set_tree_exit("none");
    set_tree_down("none");
    short_desc = "Pathway in a dense forest";
    long_desc = "Deep dark forest that is very dense. The pathway slowly\n"+
                "twists through the forest here. Barely enought light\n"+
                "filters through the branches overhead.\n";
    search_items = ({
                     "spice",
                     "stick",
                    });
    room_sound = ({
                   "There's some crackling noises under the brush here.\n",
                   "You hear the howling on the wind.\n",
                   "You can hear a slight breeze in the branches above.\n",
                  });
    items = ({
              "pathway","Very worn dirt pathway",
              "forest","Dense forest. Too dense to enter",
              "branches","Too dark to get detail up there",
              "brush","Thick underbrush hides just about anything",
             });
    hear_items = ({
                   "sounds","Very muddled sounds",
                   "branches","They creek in the slight breeze",
                   "forest","The forest sounds give you an errie feeling",
                   "howling","A dog or some other creature in pain",
                   "wind","You hear a dog crying somewhere",
                   "breeze","It moves with grace through the branches",
                   "crackling","Sounds coming from birds or animals",
                  });
  }
  event();
}

init()
{
  if(room_sound)
   gen_sound();
  ::init();
  add_action("srch_it","search");
  add_action("hear","hear");
  add_action("hear","listen");
  add_action("climb","climb");
   add_action("attach","attach");
   add_action("remove","remove");
   add_action("toss","throw");
}

toss(str)
{
  string IN1,IN2;

  if(TREE == "none")
  {
    write("There is no limbs low enough here to toss a rope over.\n");
    return 1;
  }
  if(!str)
  {
    write("Toss what over the where??\n");
    return 1;
  }
  if((sscanf(str,"%s over the %s",IN1, IN2) == 2) ||
     (sscanf(str,"%s over %s",IN1, IN2) == 2))
  {
    if(tied)
    {
      write("There's a rope hanging down from above already.\n");
      return 1;
    }
    if((ropehere = present(IN1,TP)) && IN2 == "limb")
    {
     if(TP->query_dex()-random(DIFF) > HDEX+TP->query_intoxination())
     {
      transfer(ropehere,TO);
      ropehere->auto_tie("a limb above you",TO);
      tied = 1;
      say(CP(TPRN)+" throws a rope over the limb of a large tree.\n");
      write("You toss the rope over the limb. You catch the end and tie\n"+
            "a slip nott and draw it back up to the limb. You could now\n"+
            "climb the rope up to that tree limb.\n");
      TREE->set_rope_down(ropehere);
      TREE->set_attach(1);
      TO->set_tied(1);
      return 1;
     }
     write("Your vision blurs and you fail to throw the rope correctly.\n");
     return 1;
    }
    write("You "+query_verb()+" the "+IN1+" but it just falls back to you.\n");
    return 1;
  }
  write(CP(query_verb())+" what over the where??\n");
  return 1;
}

attach(str)
{
  string IN1,IN2;

  if(TREDWN == "none")
   return;
  if(!str)
  {
    write("Attach what to the where??\n");
    return 1;
  }
  if((sscanf(str,"%s to the %s",IN1,IN2) == 2) ||
     (sscanf(str,"%s to %s",IN1,IN2) == 2))
  {
    if(attach)
    {
      write("You see there's a rope already attached to the limb.\n");
      return 1;
    }
    if((ropedown = present(IN1,TP)) && IN2 == "limb")
    {
     if(TP->query_dex()-random(DIFF) > TP->query_intoxination()+HDEX)
     {
      transfer(ropedown,TREDWN);
      TREDWN->set_rope_here(ropedown);
      ropedown->auto_tie("a limb above you",TREDWN);
      attach = 1;
      say(CP(TPRN)+" attaches a rope to the limb and lowers the rope down.\n");
      write("You attach the rope to the limb and lower the rope down.\n");
      TREDWN->set_tied(1);
      TO->set_attach(1);
      return 1;
     }
     write("Your vision blurs and you fail to attach the rope to the limb.\n");
     return 1;
    }
    write("You try to attach the "+IN1+" to the "+IN2+" but fail.\n");
    return 1;
  }
  write("Attach what to the where??\n");
  return 1;
}

remove(str)
{
  if(!str)
  {
    write("Remove what from where??\n");
    return 1;
  }
  if(TREDWN == "none")
   return;
  if(attach)
  {
   if(str == "rope from the limb" || str == "rope from limb")
   {
    if(TP->query_dex()-random(DIFF) > TP->query_intoxination()+HDEX)
    {
      write("You remove the rope from the limb.\n");
      say(CP(TPRN)+" removes a rope tied to the limb.\n");
      ropedown->auto_tie(0,0);
      transfer(ropedown,TP);
      ropedown = 0;
      TREDWN->set_rope_here(0);
      set_attach(0);
      TREDWN->set_tied(0);
      tell_room(TREDWN,"Someone just pulled up the rope!\n");
      return 1;
    }
    write("Your hands fail as you try to remove the rope from the limb.\n");
    return 1;
   }
   write("Remove what from where??\n");
   return 1;
  }
  write("There's no rope attached to the limb to remove.\n");
  return 1;
}


climb(str)
{
  switch(str)
  {
    case "up":
    case "rope":
           if(tied)
           {
              if(TP->query_dex()-random(DIFF) < TP->query_intoxination()+HDEX)
                set_spice_here(random(DIFF)+5);
              TP->move_player("by climbing up a rope#"+TREE);
              return 1;
           }
           write("There is no rope hanging down here.\n");
           return 1;
    case "tree":
           if(TREE == "none")
           {
             write("Nothing climbable here.\n");
             return 1;
           }
           if(tied)
           {
             write("There's a rope hanging down from above here.\n");
             return 1;
           }
           write("You would need a rope to throw over that large limb so\n"+
                 "that you could climb the tree using the rope.\n");
           return 1;
    case "down":
           if(TREDWN == "none")
           {
             write("Climb down?? You are on the ground!\n");
             return 1;
           }
           if(attach)
           {
             TP->move_player("climbing down a rope#"+TREDWN);
             return 1;
           }
           write("You would have to attach a rope to the limb here before\n"+
                 "trying to climb down.\n");
           return 1;
  }
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
   return;
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
                spice_here = 2;
                write("You found it hard going searching under all the\n"+
                      "tightly growing brush and tall grass.\n");
                return 1;
              }
              write("It seems you cannot find anything.\n");
              return 1;
            }
            write("You search for but cannot locate any bits of spice.\n");
            return 1;
            break;
    case "stick":
            if(TP->query_dex()-random(DIFF) > HDEX+TP->query_intoxination())
            {
             if(!present("stick",TP) && !present("torch",TP))
             {
               if(transfer(clone_object("/obj/torch"),TP))
               {
                 write("You cannot carry the torch you just found!\n");
                 return 1;
               }
               write("You find a torch here!\n");
               return 1;
             }
             write("You cannot locate a stick here for yourself.\n");
            }
            write("You have a hard time searching this tangled area.\n");
            return 1;
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
           this_player()->move_player("suddenly in a puff of smoke#"+DEST);
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

  idx = random(sizeof(room_sound)+random(4));
  if(idx < sizeof(room_sound))
   tell_room(TO,room_sound[idx]);
}

set_sound_dest(str)
{
   DEST = str;
}

set_tree_down(str)
{
  TREDWN = str;
}

set_tree_exit(str)
{
   TREE = str;
}

untie()
{
  return 0;
}

query_tied()
{
  return tied;
}

set_tied(n)
{
  tied = n;
}

set_level(n)
{
  level = n;
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

event()
{
  int i;

  for(i=0;i<random(random(random(100)))+1;i++)
  {
    switch(random(100))
    {
      case 0: TCL("/players/kbl/objs/bird");
              tell_room(TO,"A bird flies into the area.\n");
              break;
      case 2: TCL("/players/kbl/objs/coon");
              tell_room(TO,"A plump racoon moves into view here.\n");
              break;
      case 4: TCL("/players/kbl/objs/pigeon");
              tell_room(TO,"A pigeon flutters into the area.\n");
              break;
      case 16: TCL("/players/kbl/objs/frog");
               tell_room(TO,"A aqua-green frog hops into the area.\n");
               break;
      case 55: TCL("/players/kbl/objs/fox");
               tell_room(TO,"A fox walks softly into the area.\n");
               break;
      case 99: TCL("/players/kbl/objs/bear");
               tell_room(TO,"A HUGE bear walks out from the bushes.\n");
               break;
      default:
               tell_room(TO,"You hear something moving in the underbrush.\n");
               break;
    }
  }
}
