/* Inside Stronghole, entrance hall */

inherit "room/room";
object doc,doc2,doc3;
int num_c;

reset(arg)
{
 ::reset(arg);
 if(!arg)
 {
   set_light(0);
   short_desc = "Stronghold entrance hall";
   long_desc = "Immediately catching your attention is a dark crystal spire\n"+
               "coming through the floor and its peak ends just below the\n"+
               "ceiling. Around the base of the spire is a bench. The walls\n"+
               "are made of a black material unknown to you. A stairwell\n"+
               "goes down in west wall and east there is some sort of\n"+
               "chamber.\n";
   dest_dir = ({"players/kbl/chaos/cho71","east",
                "players/kbl/chaos/cho6","south",
                "players/kbl/chaos/cho8","down"});
   property = "no_steal";
   smell = "Air has a musty odor";
   items = ({"bench","Is around the base of the spire"});
  num_c = 1;
  if(!doc || !living(doc))
  {
    doc = clone_object("obj/monster");
    fix_up(doc);
    transfer(doc,this_object());
  }
  if(!doc2 || !living(doc2))
  {
    doc2 = clone_object("obj/monster");
    fix_up2(doc2);
    transfer(doc2,this_object());
  }
  if(!doc3 || !living(doc3))
  {
   doc3 = clone_object("obj/monster");
   fix_up2(doc3);
   transfer(doc3,this_object());
  }
 }
}

init()
{
  ::init();
  add_action("look_it","look");
  add_action("look_it","scan");
  add_action("east_b","east");
  add_action("down_b","down");
  add_action("get_it","get");
  add_action("sit","sit");
  add_action("climb","climb");
}


east_b()
{
  if(!doc && !doc2 && !doc3)
  {
    write("You leave east into chamber.\n");
   ::move(query_verb());
    return 1;
  }
  else
  {
    if(doc)
    {
      blocker(doc);
      return 1;
    }
    if(doc2)
    {
      blocker(doc2);
      return 1;
    }
    if(doc3)
    {
      blocker(doc3);
      return 1;
    }
  }
}

blocker(doc)
{
  int val;
  write(doc->query_name()+" blocks you from going east!\n");
   say(doc->query_name()+" blocks "+this_player()->query_name()+" from going east.\n");
  val = random(8);
  if(val == 2)
  {
   write("DOC gurgles: You can't visit de Arch! Go Away fleshling!\n");
   say("DOC gurgles: You can't visit de Arch! Go Away fleshling!\n");
  }
  if(val == 4)
  {
   write("DOC snaps: You stink, boss don't like stinky fleshlings!\n");
   say("DOC snaps: You stink, boss don't like stinky fleshlings!\n");
  }
  if(val == 6)
  {
   write("DOC licks his slender claws: I can taste your blood already!\n");
   say("DOC licks his slender claws: I can taste your blood already!\n");
  }
  return 1;
}


down_b()
{
  if(!doc && !doc2 && !doc3)
  {
    write("You leave down stairs to...\n");
    ::move(query_verb());
    return 1;
  }
  else
  {
    if(doc)
    {
      blocker2(doc);
      return 1;
    }
    if(doc2)
    {
      blocker2(doc2);
      return 1;
    }
    if(doc3)
    {
      blocker2(doc3);
      return 1;
    }
  }
}

blocker2(doc)
{
  int val;
  object cdoc;

  write(doc->query_name()+" blocks you path down!\n");
   say(doc->query_name()+" blocks "+this_player()->query_name()+"'s path down.\n");
  val = random(8);
  if(val == 2)
  {
    write("DOC says: Hey! My beds down there! Go find your own.\n");
    say("DOC says: Hey! My beds down there! Go find your own.\n");
  }
  if(val == 4)
  {
    write("DOC screems: Help! we need HELP!\n");
    cdoc = clone_object("obj/monster");
   fix_up(cdoc);
    transfer(cdoc,this_object());
    write("Lower DOC arrives to assist!\n");
    say("Lower DOC arrives to assist!\n");
  }
  if(val == 6)
  {
    command("kick "+this_player()->query_name(),doc);
  }
}

get_it(str)
{

  int val;
  object tal;

  if(!str)
   return;
  if(str == "crystal from bench" || str == "crystal on bench")
  {
    if(num_c > 0)
    {
     if(!doc && !doc2 && !doc3)
      {
        write("You pick up a Darknife\n");
        say(this_player()->query_name()+" picks up a Darknife from bench.\n");
        tal = clone_object("players/kbl/objs/darknife");
        transfer(tal,this_player());
        num_c -=1;
        return 1;
      }
      else
      {
        if(doc)
        {
          blocker3(doc);
          return 1;
        }
        if(doc2)
        {
          blocker3(doc2);
          return 1;
        }
        if(doc3)
        {
          blocker3(doc3);
          return 1;
        }
      }
    }
    else
    {
      write("You don't see anymore crystals, so why bother.\n");
      return 1;
    }
  }
}

blocker3(doc)
{
  int val;

  write("DOC blocks your way to the Darknife.\n");
  say(doc->query_name()+" blocks "+this_player()->query_name()+"'s way to the Darknife on the bench.\n");
  val = random(8);
  if(val == 2)
  {
     write("DOC laughs: So, you like nice weapons, eh??\n");
     say("DOC laughs: So "+this_player()->query_name()+", you like nice weapons, eh?\n");
  }
  if(val == 4)
  {
    command("spit "+this_player()->query_name(),doc);
  }
  if(val == 6)
  {
    command("grin "+this_player()->query_name(),doc);
  }
  return 1;
}

look_it(str)
{
  if(!str)
   return;
  if(str == "at bench" || str == "bench")
  {
    say(this_player()->query_name()+" looks at bench.\n");
    if(num_c > 0)
    {
     write("The maybe be a crystal shard or more on the bench. There\n");
     write("is "+num_c+" remaining. Maybe you should grab one soon!\n");
    }
    write("The bench is formed out of brown crystal of very high density.\n");
    write("The surface of the bench is very smooth, maybe you should sit\n");
    write("on it.\n");
    return 1;
  }
  if (str == "at spire" || str == "spire")
  {
    say(this_player()->query_name()+" looks at the spire.\n");
    write("This dark crystal spire testifies to the forces at work, shaping\n");
    write("the Chaos. Looks like DOC have tried to climb the spire by all\n");
    write("the claws marks on it.\n");
    return 1;
  }
  if(str == "at walls" || str == "wall")
  {
    say(this_player()->query_name()+" looks at the walls.\n");
    write("The walls look very tough. You wonder at the thickness of them.\n");
    write("What are the DOC trying to hide from??\n");
    return 1;
  }
}

sit(str)
{
  if(!str)
   return;
  if(str == "on bench")
  {
    say(this_player()->query_name()+" sits on the bench.\n");
    write("You sit on bench, DOC don't care about that!\n");
    return 1;
  }
}

climb(str)
{

  int val;

  if(!str)
   return;
  if(str == "spire")
  {
    say(this_player()->query_name()+" climbs spire and disappears!\n");
    write("You start to climb and feel a power magic envelope you!!\n");
    write("*poof* You end up somewhere else!!\n");
    val = random(5);
    if(val == 0)
     transfer(this_player(),"/players/kbl/chaos/cvoid");
    if(val == 1)
     transfer(this_player(),"/players/kbl/chaos/cho34");
    if(val == 2)
     transfer(this_player(),"/players/kbl/chaos/cho45");
    if(val == 3)
     transfer(this_player(),"/players/kbl/chaos/cho44");
    if(val > 3)
     transfer(this_player(),"/players/kbl/chaos/cho2");
    return 1;
  }
}

fix_up(doc)
{
  doc->set_name("Demon Of Chaos");
  doc->set_alias("doc");
  doc->set_alt_name("demon");
  doc->set_level(15);
  doc->set_hp(200);
  doc->set_sp(175);
  doc->set_al(-1000);
  doc->set_race("krajar");
  doc->set_gender(1);
  doc->set_aggressive(1);
  doc->set_str(18);
  doc->set_dex(18);
  doc->set_wis(15);
  doc->set_int(15);
  doc->set_con(17);
  doc->set_chr(7);
  doc->set_ac(25);
  doc->set_wc(20);
  doc->set_short("Lower Demon Of Chaos");
  doc->set_long("Has large scar running down chest. Has very powerful arms.\n");
  doc->set_chance(10);
  doc->set_spell_mess1("DOC slams you!\n");
  doc->set_spell_mess2("DOC hits you hard!\n");
  doc->set_spell_dam(25);
}

fix_up2(doc)
{
  doc->set_name("Demon Of Chaos");
  doc->set_alias("doc");
  doc->set_alt_name("demon");
  doc->set_level(random(5)+23);
  doc->set_hp(random(100)+300);
   doc->set_sp(random(50)+150);
  doc->set_al(-2500);
  doc->set_race("krajar");
  doc->set_gender(2);
  doc->set_aggressive(0);
  doc->set_str(random(3)+27);
  doc->set_dex(random(3)+27);
  doc->set_wis(random(5)+17);
  doc->set_int(random(5)+17);
  doc->set_con(random(5)+27);
  doc->set_chr(random(5)+2);
  doc->set_ac(random(5)+20);
  doc->set_wc(random(15)+30);
  doc->set_str(28);
  doc->set_dex(28);
  doc->set_wis(18);
  doc->set_int(18);
  doc->set_con(26);
  doc->set_chr(16);
  doc->set_ac(26);
  doc->set_wc(40);
  doc->set_short("Guard Demon Of Chaos");
  doc->set_long("This female guard is tougher than most of the males!\n");
  doc->set_chance(5);
  doc->set_spell_mess1("DOC kicks your ass!\n");
  doc->set_spell_mess2("DOC pounds you silly!\n");
  doc->set_spell_dam(55);
}

