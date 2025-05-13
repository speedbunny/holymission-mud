/* Ledge along hole in Chaos */

inherit "room/room";
object doc,doc2,tal;

reset(arg)
{
 ::reset(arg);
 if(!arg)
 {
   set_light(0);
   short_desc = "Inside hole in the brown crystal";
   long_desc = "DOC work here mainly throwing `trash' down into the void.\n"+
               "You stand on a naturally formed ledge that surrounds the\n"+
               "the hole here. A slim passageway lead west into a reddish\n"+
               "the hole here. A small cave entrance can be seen to the\n"+
               "west. The walls and the ledge have a fused look to them.\n"+
               "You notice a large crack running down the north side of\n"+
               "this hole.\n";
   dest_dir = ({"players/kbl/chaos/cho44","west",
                "players/kbl/chaos/cho42","up"});
   property = "no_steal","no_hide";
   smell = "The stench of death";
  if(!tal)
  {
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
      tal = clone_object("players/kbl/objs/chaoskey");
      transfer(tal,doc2);
    }
  }
 }
}

init()
{
  ::init();
  add_action("look_it","look");
  add_action("look_it","scan");
add_action("up_s","up");
add_action("west_b","west");
  add_action("jump","jump");
  add_action("climb","climb");
}

up_s()
{
  if(this_player()->query_dex() > 10)
  {
    write("You use grooves to pull yourself up to...\n");
    ::move(query_verb());
    return 1;
  }
  write("You are TOO scared to even TRY to go up!\n");
  say(this_player()->query_name()+" is too scared to go up smooth pathway!\n");
  command("shiver",this_player());
  return 1;
}

west_b()
{
int val;
  if(present("captain",this_object()))
  {
    write("Captain Demon Of Chaos blocks your path west.\n");
    val = random(30);
    if(doc2->query_dex() >= this_player()->query_dex()+this_player()->query_int()/5)
    {
      write("DOC Captain kicks you into hole!\n");
      say(this_player()->query_name()+" gets kicked into hole by DOC Captain!\n");
      this_player()->move_player("by getting kicked in hole!#players/kbl/chaos/cvoid");
      return 1;
    }
   if(this_player()->query_dex() > doc2->query_dex()+doc2->query_int()/5)
      {
        write("DOC Captain tries to kick you into hole, BUT you side step\n");
           write("and kick DOC Captain into hole!\n");
        transfer(doc2,"/players/kbl/chaos/cvoid");
        say(doc2->query_name()+" gets kicked into hole by "+this_player()->query_name()+"!\n");
        doc2 = 0;
        return 1;
      }
      write("DOC Captain tried to kick you into hole, but you moved!\n");
      write("DOC looks at you with respect!\n");
      say("DOC Captain tried to kick "+this_player()->query_name()+" into hole but fails.\n");
      return 1;
    }
    if(doc)
    {
      write("Worker DOC blocks your path west!\n");
      write("Worker throws cloud of sharpe crystal shards at you!\n");
      say("Worker DOC blocks "+this_player()->query_name()+" from going west!\n");
      say("DOC throws many dark crystal shards at "+this_player()->query_name()+"!\n");
      this_player()->hit_player(10);
    }
     write("You go west towards a thumping noise to...\n");
     ::move(query_verb());
     return 1;
}

jump()
{
  write("You just jump into the hole going down....\n");
  this_player()->move_player("by jumping into hole!#players/kbl/chaos/cvoid");
  return 1;
}


climb(str)
{
  if(!str)
   return;
  if(str == "down hole")
  {
    if((this_player()->query_dex()-this_player()->query_intoxination()/10) < 20)
    {
      say(this_player()->query_name()+" slips off handholds in hole!\n");
      write("You loose your grip on the handholds!\n");
      write("You fall down hole...\n");
      this_player()->move_player("falling downward#players/kbl/chaos/cvoid");
      return 1;
    }
    say(this_player()->query_name()+" climbs down into hole.\n");
    write("You climb down hole to...\n");
    this_player()->move_player("climbing down#players/kbl/chaos/cho45");
    return 1;
  }
}
look_it(str)
{
  if(!str)
   return;
  if(str == "at walls" || str == "walls")
  {
    say(this_player()->query_name()+" looks at the walls.\n");
    write("The walls a smooth and are unclimbable. On the north wall, a\n");
    write("crack lets in a bit of heat. You feel the heat as you run you\n");
    write("hand over the crack.\n");
    return 1;
  }
  if(str == "at hole" || str == "hole")
  {
    say(this_player()->query_name()+" looks down the hole.\n");
    write("Hole looks as if its been carved out. This is not a natural\n");
    write("thing. You think you see grooves to climb down, but its only\n");
    write("the way the hole was made.\n");
    return 1;
  }
  if(str == "at crack" || str == "crack")
  {
    say(this_player()->query_name()+" looks at the crack on north wall.\n");
    write("A crack running down the north wall of this hole. Looking\n");
    write("closer, you see heat waves coming from the top portion of\n");
    write("the crack nearest the very top of the hole. This is a\n");
    write("stress crack, probably caused by something pushing against\n");
    write("the wall you think.\n");
    return 1;
  }
  if(str == "at ledge" || str == "ledge")
  {
    say(this_player()->query_name()+" looks at ledge.\n");
    write("The ledge is very smooth. Its made of fused brown crystal and\n");
    write("is very hard. Claw marks can be seen all over showing that this\n");
    write("is used very much by the DOC. Some of the claw marks lead right\n");
    write("to the edge of the hole.\n");
    return 1;
  }
  if(str == "up")
  {
    say(this_player()->query_name()+" looks up.\n");
    write("You look up to see a faint outline of the funnel shaped hole\n");
    write("laid against the blackness of the void.\n");
    return 1;
  }
  if(str = "down")
  {
    say(this_player()->query_name()+" looks down...\n");
    write("You move very close to the edge of the hole and look down.\n");
    if(this_player()->query_dex() < 20)
    {
      say(this_player()->query_name()+" slips into hole!\n");
      write("You loose your footing and slip into hole!\n");
      this_player()->move_player("down into hole#players/kbl/chaos/cvoid");
      return 1;
    }
    write("You see that the hole has many handholds going down, maybe you\n");
    write("climb down them!\n");
    return 1;
  }
}

fix_up(doc)
{
  doc->set_name("Demon of Chaos");
  doc->set_alias("doc");
  doc->set_level(23);
  doc->set_hp(295);
  doc->set_sp(95);
  doc->set_al(-2000);
  doc->set_gender(2);
  doc->set_race("krajar");
  doc->set_aggressive(1);
  doc->set_str(24);
  doc->set_dex(23);
  doc->set_wis(13);
  doc->set_int(13);
  doc->set_con(23);
  doc->set_chr(2);
  doc->set_short("Worker Demon Of Chaos");
  doc->set_long("Worse looking DOC you've seen! Must be constantly moving\n"+
                "garbage around and smells that way to! Looks very mean.\n");
  doc->set_chance(5);
  doc->add_money(random(500)+400);
  doc->set_spell_mess1("DOC licks your face clean!\n");
  doc->set_spell_mess2("DOC throws a mean roundhouse punch at you!\n");
  doc->set_spell_dam(20);
}

fix_up2(doc)
{
  doc->set_name("Demon Of Chaos");
  doc->set_alias("doc");
  doc->set_level(35);
  doc->set_alias("captain");
  doc->set_hp(700);
  doc->set_sp(300);
  doc->set_al(-3000);
  doc->set_gender(1);
  doc->set_race("krajar");
  doc->set_aggressive(1);
  doc->set_str(30);
  doc->set_dex(30);
  doc->set_int(30);
  doc->set_wis(30);
  doc->add_money(random(1500)+800);
  doc->set_chr(30);
  doc->set_con(30);
  doc->set_short("Captain Demon Of Chaos");
  doc->set_long("Captain Demon Of Chaos has a highly polished look. Seems"+
              "\nthis DOC has been trained as a manager AND fighter. Looks\n"+
               "very powerful and wise.\n");
  doc->set_chance(25);
  doc->set_spell_mess1("DOC slams you hard!\n");
  doc->set_spell_mess2("DOC throws hail of crystal shards at you!\n");
  doc->set_spell_dam(40);
}
