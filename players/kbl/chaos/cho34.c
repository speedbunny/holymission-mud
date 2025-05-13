/* Cave Entrance way into Dark crystal cliff */

inherit "room/room";
int gate_open;
int panel_found;

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    panel_found = 0;
    gate_open = 0;
    set_light(1);
    short_desc = "Cave entrance in dark crystal cliff";
    long_desc = "You stand on a narrow ledge overlooking the vortex.\n"+
                "Spectacular view of the material disappearing into the\n"+
                "vortex. From this close the energy releases can be felt.\n"+
                "To the north is a cave entrance. The amount of dust on\n"+
                "this ledge indicates that not too many adventures have\n"+
                "traveled this way.\n";
    dest_dir = ({"players/kbl/chaos/cho33","up"});
    smell = "The air is fresh here";
  }
}

init()
{
  ::init();
  add_action("look_it","look");
  add_action("north","north");
  add_action("search","search");
  add_action("press","press");
  add_action("press","push");
  add_action("look_it","scan");
}

north()
{
  if(gate_open)
  {
    write("You enter cave heading north.\n");
    this_player()->move_player("into cave#players/kbl/chaos/cho35");
  }
  else
  {
    write("You bump into energy bars, OUCH! That hurt!\n");
    this_player()->hit_player(5);
    say(this_player()->query_name()+" takes flash damage from bars!!\n");
   }
   return 1;
}


look_it(str)
{
  if(!str)
   return;
  if(str == "at vortex" || str == "vortex")
  {
    say(this_player()->query_name()+" looks at vortexs' center.\n");
    write("You see a close up view of the Voidal Vortex. Theres a black\n");
    write("hole in the center of the vortex, maybe it leads somewhere?\n");
    return 1;
  }
  if(str == "at cave" || str == "cave")
  {
     say(this_player()->query_name()+" looks at cave.\n");
    write("Looking at cave you see its been blasted out of the cliff.\n");
    write("This may be some sort of secret entrance, back door maybe.\n");
    return 1;
  }
  if(str == "at panel" || str == "panel")
  {
    if(panel_found)
    {
      say(this_player()->query_name()+" looks at panel.\n");
      write("The panel has three colored push buttons, black, red and\n");
      write("purple. Maybe you should push one?\n");
      if(gate_open)
        write("The purple button is glowing faintly.\n");
      else
        write("The red button is glowing faintly.\n");
      return 1;
    }
    else
    {
      write("You see no panel!\n");
      return 1;
    }
  }
  if(str == "at bars" || str == "bars")
  {
    if(gate_open)
    {
      write("You see no bars presently.\n");
      return 1;
    }
    else
    {
      say(this_player()->query_name()+" looks closer at bars.\n");
      write("The bars are made of a multicolored energy similar to that\n");
      write("emitted from the vortex. They are unbreakable, maybe thats\n");
      write("why there's no guard here.\n");
      return 1;
    }
  }
  if(str == "at ledge" || str == "ledge")
  {
    say(this_player()->query_name()+" looks at ledge under foot.\n");
    write("This ledge was formed when the entrance was created. Small\n");
    write("crystals are loose on the ledge, but they decay to your\n");
    write("touch.\n");
    return 1;
  }
  if(str == "at entrance" || str == "entrance")
  {
    say(this_player()->query_name()+" looks at cave entrance.\n");
    write("The dark crystal around the entrance has been pealed back, by\n");
    write("a power that you can't imagine. The entrance way looks\n");
    write("strange.\n");
    return 1;
  }
  if(str == "at cliff" || str == "cliff")
  {
    say(this_player()->query_name()+" looks at the dark crystal cliff\n");
    write("You look up at the cliff. Its very steep and unclimbable.\n");
    write("BUT, as you look closer a pathway leading up is noticeable.\n");
    write("The many hand and foot holds actually make for easy climbing.\n");
    return 1;
  }
  if(str == "at screen" || str == "screen")
  {
    if(panel_found)
    {
      say(this_player()->query_name()+" looks closely at screen, on panel.\n");
      write("The screen is a Demon Of Chaos report menu, but the title is\n");
      write("is the only thing you can read on it. The rest is cryptic\n");
      write("and is unreadable.\n");
      return 1;
    }
    else
    {
      write("What screen??\n");
      return 1;
    }
  }
}

search(str)
{
  if(!str)
   return;
  if(str == "entrance" || str == "cave entrance")
  {
    if(panel_found)
    {
      write("You see the panel, embedded into the dark crystal.\n");
      return 1;
    }
    else
    {
      say(this_player()->query_name()+" finds a hidden panel.\n");
      write("You find a hidden panel embedded into the dark crystal.\n");
      write("Sliding the rough crystal cover reveals some sort of\n");
      write("control device. It has a row of buttons and a screen with\n");
      write("unfamiliar symbology on it.\n");
      panel_found = 1;
      return 1;
    }
  }
  if(str == "cave" || str == "cave entrance")
  {
    if(gate_open)
    {
      write("You find nothing special about the cave.\n");
      return 1;
    }
    else
    {
     if(this_player()->query_dex() < 25)
     {
      say(this_player()->query_name()+" bumps into energy bars.\n");
      write("You bump into the energy bars. You smell burning flesh!\n");
      this_player()->hit_player(5);
      return 1;
     }
     say(this_player()->query_name()+" moves away from energy bars.\n");
     write("You move away from energy bars.\n");
     return 1;
    }
  }
}

press(str)
{
  object doc;
  if(!str)
   return;
  if(str == "purple" || str == "purple button")
  {
    if(panel_found)
    {
      if(gate_open)
      {
        write("Bars have already been removed.\n");
        return 1;
      }
      say(this_player()->query_name()+" presses purple button.\n");
      say("The energy bars vanish.\n");
      write("You press purple button and bars disappear!\n");
      gate_open = 1;
      return 1;
    }
    else
    {
      write("What button??\n");
      return 1;
    }
  }
  if(str == "black" || str == "black button")
  {
    if(panel_found)
    {
      say(this_player()->query_name()+" presses black button.\n");
      write("You press black button...\n");
      if(gate_open)
      {
        write("Energy bars reappear with a energy SNAP!\n");
        say("Energy bars reappear with a energy SNAP!\n");
        gate_open = 0;
      }
      panel_found = 0;
      say("Panel cover slides shut.\n");
      write("Panel cover slides shut!\n");
      write("A Demon Of Chaos apprears and attacks!\n");
      doc = clone_object("obj/monster");
      fix_up(doc);
      transfer(doc,this_object());
      return 1;
    }
    else
    {
      write("Press what??\n");
      return 1;
    }
  }
  if(str == "red" || str == "red button")
  {
    if(panel_found)
    {
      say(this_player()->query_name()+" presses red button.\n");
      if(gate_open)
      {
        say("The energy bars reappear with a SNAP!\n");
        write("You see energy bars reappear with a SNAP!\n");
        gate_open = 0;
      }
      say("Panel cover slides shut.\n");
      write("Panel cover slides shut.\n");
      panel_found = 0;
      return 1;
    }
  }
}

fix_up(doc)
{
  doc->set_name("Demon of Chaos");
  doc->set_alias("doc");
  doc->set_alt_name("demon");
  doc->set_level(random(5)+28);
  doc->set_hp(random(500)+320);
  doc->set_sp(random(250)+120);
  doc->set_al(random(200)-2000);
  doc->set_gender(1);
  doc->set_race("krajar");
  doc->set_aggressive(1);
  doc->set_str(random(5)+27);
  doc->set_dex(random(5)+27);
  doc->set_wis(random(5)+27);
  doc->set_int(random(5)+27);
  doc->set_con(random(5)+27);
  doc->set_chr(2);
  doc->set_wc(25);
  doc->set_ac(20);
  doc->set_short("Guard Demon Of Chaos");
  doc->set_long("This Demon Of Chaos guard has been trained by the Defense\n"+
                "Institute of Zesranotae. Has naturally armoured skin.\n");
  doc->set_chance(random(35)+15);
  doc->set_spell_mess1("DOC throws many dark crystal shards at you!\n");
  doc->set_spell_mess2("DOC throws hail of dark crystal shards at you!\n");
  doc->set_spell_dam(50);
}

query_bars()
{
  return gate_open;
}
