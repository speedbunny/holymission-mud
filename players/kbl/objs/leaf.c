/* KBL's Star Leaf */

#include "/players/kbl/header/T.h"
int fly;
int max_hp;
int stuck;
object attach;
string buff;
string memor;

reset(arg)
{
  if(arg)
   return;
   max_hp = random(50)+20;
   if (!buff)
    buff = allocate(4);
}

short()
{
  return "Star Leaf";
}

id(str)
{
  return str == "star leaf" || str == "Star Leaf";
}

long()
{
  if(!attach)
  {
    write(short() + " that seems to shine with a light of its own.\n");
    write("You notice that the edges of this leaf are fairly sharp. The\n");
    write("stem looks like it could double as a light weight handle made\n");
    write("out of wood.\n");
  }
  else
  {
    write(query_long() + ".\n");
    write("The Leaf smiles up at you and says: Great day, eh?\n");
  }
}

init()
{
  add_action("toss","toss");
  add_action("absorb","absorb");
  add_action("ask","ask");
  add_action("remove","remove");
  add_action("program","rmem");
  if(stuck)
   add_action("nodrop","drop");
}

remove(str)
{
   if(!str)
    return;
   if (str == "star leaf" || str == "Star Leaf")
   {
     if(stuck)
     {
       if(this_player()->query_str() > 7)
       {
         write("You remove the Star Leaf stuck in your " + buff[1] + ".\n");
         attach = 0;
         set_stuck(0);
         return 1;
        }
      }
      else
       {
       write("The Leaf is not stuck in you.\n");
       return 1;
       }
   }
}

nodrop(str)
{
 if ((id(str) || str == "all") && attach)
  {
    say("Leaf say: Ya got to remove me first! *laugh*\n");
    write("Leaf looks at you and smiles.\n");
    return 1;
  }
}


absorb(num)
{
 if(max_hp > 0)
 {
  if (num == "all")
  {
    write("You drain remaining healing energy from Leaf\n");
    write("Leaf looks at you and says: Hope it was worth it!\n");
    this_player()->heal_self(max_hp);
    max_hp = 0;
    return 1;
  }
  if (num == "half")
  {
    write("Leaf looks and says: Well thats conservative!\n");
    write("Leaf says: I now have " + max_hp/2 + " energy points remaining.\n");
    this_player()->heal_self(max_hp/2);
    max_hp = max_hp / 2;
    return 1;
  }
 }
 else
 {
   write("No more energy to absorb from in this Leaf.\n");
   return 1;
  }
}

ask(str)
{
  if (str == "leaf about energy" || str == "leaf about units")
  {
    write("Leaf turns and says: I have " + max_hp + " energy units remaining.\n");
    return 1;
  }
 if (str == "leaf to dump memory")
  {
    if (memor)
    {
   if (memor[0] != "")
    write("Leaf says memory 0 is: " + memor[0] + "\n");
   if (memor[1] != "")
    write("Leaf says memory 1 is: " + memor[1] + "\n");
   if (memor[2] != "")
    write("Leaf says memory 2 is: " + memor[2] + "\n");
   if (memor[3] != "")
    write("Leaf says memory 3 is: " + memor[3] + "\n");
   return 1;
   }
   else
      write("Leaf says: No memory to dump.\n");
      return 1;
    }
  if (str == "leaf about recharge")
  {
    write("Leaf grins: Only White crystal can recharge me.\n");
     return 1;
   }
    if (str == "leaf about origin")
    {
      write("Leaf laughs: Hey go climb a Giant Oak, if you can!\n");
      return 1;
    }
}

program(str)
{
  /* Make sure we have a string to remember! */

  if (!str)
  {
    tell_object(this_player(), "Leaf says: Remember what?\n");
    return 1;
  }
  if (!memor)
  {
   memor = allocate(4);
   memor[0] = "";
   memor[1] = "";
   memor[2] = "";
   memor[3] = "";
  }
  if (str == "erase all")
  {
   memor[0] = "";
   memor[1] = "";
   memor[2] = "";
   memor[3] = "";
   return 1;
  }
  if (str == "erase 0")
  {
    memor[0] = "";
    return 1;
  }

  if (str == "erase 1")
  {
    memor[1] = "";
    return 1;
  }
  if (str == "erase 2")
  {
    memor[2] = "";
    return 1;
  }
  if (str == "erase 3")
  {
    memor[3] = "";
    return 1;
  }
  if (memor[0] == "")
  {
    memor[0] = str;
    return 1;
  }
  if (memor[1] == "")
  {
    memor[1] = str;
    return 1;
  }
  if (memor[2] == "")
  {
    memor[2] = str;
    return 1;
  }
  if (memor[3] == "")
  {
    memor[3] = str;
    return 1;
  }
  write("Memory is full, you have to erase something.\n");
  return 1;
}

toss(str)
{
  int to_hit,wher_hit;

  if(str == "at castle")
  {
     write("You want to toss a star leaf at a castle!?\n");
     write("Star Leaf says: You stupid! I'm leaving!\n");
     write("The Star Leaf flies out of your hands and leaves flying away.\n");
     say("The star leaf jumps out of "+this_player()->query_name()+"'s hands and flies away.\n");
     transfer(this_object(),"/players/kbl/big_forest1");
     return 1;
  }
  /* Make sure attacker and attackee are in same room */
 if(!str)
 {
   write("Toss what??\n");
   return 1;
 }
 if(present(str,ETP))
 {
  if(E(present(str,ETP)) == ETP)
  {
   if(present(str,ETP) == TP && fly == 0)
     write("You cannot toss Leaf at yourself!\n");
   else
   {
    say("Leaf says: Bonziiiiii!!\n");
    write("Leaf says: Bonziiiiiii!!\n");
    to_hit = random(30)+1;
    to_hit += ((this_player()->query_dex()/10 + this_player()->query_str()/10) -this_player()->query_intoxination()/5);
    if (to_hit < 0)
      to_hit = 0;
    wher_hit = random(6);
    fly = 1;
   buff[0] = "The Leaf is stuck ";
   buff[1] = "";
  buff[2] = "in ";
    if (to_hit > 10 && to_hit < 28)
    {
      switch(wher_hit)
      {
        case 0: buff[1] = "head";
           break;
       case 1: buff[1] = "chest";
           break;
        case 2: buff[1] = "right arm";
           break;
       case 3: buff[1] = "left arm";
           break;
        case 4: buff[1] = "right leg";
           break;
       case 5: buff[1] = "left leg";
           break;
      }
      write("You toss a wobbly leaf throw\n");
      present(str,ETP)->hit_player(20);
    }
      if (to_hit > 27)
      {
        switch(wher_hit)
        {
          case 0: buff[1] = "head, right between the eyes";
             break;
          case 1: buff[1] = "chest dead center";
             break;
          case 2: buff[1] = "right arm bicep area";
             break;
          case 3: buff[1] = "left arm bicep area";
             break;
          case 4: buff[1] = "right leg thigh area";
             break;
          case 5: buff[1] = "left leg thigh area";
             break;
        }
        write("You toss a beautiful arc Leaf throw!\n");
       present(str,ETP)->hit_player(35);
      }
      if (to_hit > 29)
      {
       buff[2] = "very deeply into ";
        if(present(str,ETP))
         present(str,ETP)->hit_player(15);
      }
      if (to_hit < 11)
      {
        set_long("");
        say("Leaf lands on the ground next to " + capitalize(str) + ".\n");
        say(this_player()->query_name() + " missed " +capitalize(str)+".\n");
        write("You missed " + capitalize(str) + " and the Leaf hits the ground.\n");
        transfer(TO,ETP);
        fly = 0;
        return 1;
      }
    set_long(buff[0] + buff[2] + capitalize(str) + "'s " + buff[1] + "!\n");
    say(this_player()->query_name()+" threw Leaf at " +capitalize(str)+"!\n");
    write("You threw the Leaf at " + capitalize(str) + "\n");
    write(query_long());
    attach = present(str,ETP);
    transfer(TO,present(str,ETP));
    fly = 0;
    if (!attach->query_npc())
    {
    attach = 0;
    set_stuck(1);
    }
    return 1;
   }
  }
  else
    write("Cannot throw Leaf at " + capitalize(str) + ".\n");
 }
 else
   write("No player on with name " + capitalize(str) + ".\n");
 return 1;
}

missed()
{
  toss(this_player()->query_real_name());
  return 1;
}

query_long()
{
 return buff[3];
}

set_long(str)
{
  buff[3] = str;
}

set_stuck(h)
{
  stuck = h;
}


get()
{
  return 1;
}

set_charge(h)
{
  max_hp+=h;
}

query_name()
{
 return "leaf";
}

query_alias()
{
  return "leaf";
}

query_weight()
{
 return 1;
}

query_value()
{
 return 200;
}

query_wc()
{
return 1;
}
