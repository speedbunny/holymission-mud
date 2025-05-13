/* Ledge over the Vortex */

inherit "room/room";
object doc;

reset(arg)
{
 ::reset(arg);
 if(!arg)
 {
  set_light(1);
  short_desc = "Ledge of Vortex";
  long_desc = "You stand at the tip of a great ledge that extends out over\n"+
              "the vortex. Not far away is a pulsing light beam. The ledge\n"+
              "extends so far out, you could probably just jump into the\n"+
              "center of the vortex itself. The light beam crackles with a\n"+
              "powerful intensity that scares you half to death. But death\n"+
              "is just a transference of energy anyway so who cares?\n";
  dest_dir = ({
               "/players/kbl/chaos/cho31","up",
               "/players/kbl/chaos/cho33","down",
               });
  items = ({"down","Below the tip of the ledge you see the vortex framed\n"+
                   "by the blackness of the void showing a picture of\n"+
                   "its swirling decaying matter falling into its blackhole\n"+
                   "center. But in the very center, theres a speck of light.",
            "up","Your eyes go to the light beam traveling upwards as far\n"+
                 "as you can see. It never fans out. Stays traveling in a\n"+
                 "tight beam.",
            "blackness","The blackness of the void is almost deafing. Your\n"+
                        "minds own thoughts seem to be completely absorbed\n"+
                        "when looking into the voidal blackness.",
            "matter","Brown chunk of material spinning and falling towards\n"+
                     "the blackhole center of the vortex.",
            "blackhole","The center of the vortex has a speck of light way\n"+
                        "down inside. You stop yourself from being pulled\n"+
                        "by the very sight of it.\n",
            "speck of light","Something familiar about that light."});
  smell = "Rotten egg odor lingers in the air here.";
  property = "no_steal";
  if(!doc || !living(doc))
  {
    doc = clone_object("obj/monster");
    fix_up(doc);
    transfer(doc,this_object());
  }
 }
}

init()
{
  ::init();
  add_action("jump","jump");
  add_action("enter","enter");
  add_action("climb","climb");
  add_action("look_it","look");
  add_action("look_it","scan");
}


jump()
{
  write("You jump into the Vortex!\n");
  this_player()->move_player("by jumping into the Vortex!#room/void");
  return 1;
}


climb(str)
{
  if(!str)
   return;
  if(str == "to right and down" || str == "right and down")
  {
    this_player()->add_exp(10);
    write("You climb right and down to...\n");
    this_player()->move_player("climbing to the right and down#players/kbl/chaos/cho33");
    return 1;
  }
}

enter(str)
{
  int val;

  if(!str)
   return;
  if(str == "light beam" || str == "beam")
  {
    if(gift())
    {
      if(doc)
      {
        write("High Demon Of Chaos blocks your path to the beam.\n");
        val = random(4);
        if(val == 3)
          write("Get the out of my sight fleshling, or I kill you *snarl*\n");
        if(val == 2)
          write("SO, you want out eh? Maybe I kick you into the vortex!\n");
        if(val == 1)
          write("Piss on you, stinky fleshling!\n");
        return 1;
      }
      else
      {
        write(this_player()->query_name()+" enters light beam!\n");
        for(val=0;val<6;val++)
         write("       YOU are traveling up the light beam!!!\n\n\n\n\n");
       this_player()->move_player("into the light beam!#players/kbl/light/light1");
        return 1;
      }
    }
    else
    {
      write("You DO NOT possess the proper protection!!!\n");
      write("A flash of light fries you!\n");
      write("You fall into the vortex....\n");
      say("A flash of light fries "+this_player()->query_name()+"!\n");
      for(val=0;val<3;val++)
      {
        say(this_player()->query_name()+" is falling away fast!\n");
        write("You are falling away into vortex fast!\n");
      }
      write("You break the plane of the vortex and see the matter swirling!\n");
      write("You are heading towards the light at a tremendous rate!\n");
      write("The light is upon you!!!\n");
      this_player()->hit_player(50);
      this_player()->move_player("falling into the vortex!#room/void");
      return 1;
    }
  }
}

look_it(str)
{
  int val;

  if(!str)
   return;
  if(str == "at vortex" || str == "vortex")
  {
    say(this_player()->query_name()+" looks at the vortex.\n");
    write("The Vortex is liken to a drain where chunks of matter flow into\n");
    write("it continuously. The bursts of light energy almost blind you and\n");
    write("you find yourself shielding your eyes. The brownish material\n");
    write("breaks away from your left.\n");
    val=random(50);
    if (val > 10 && val < 25)
    {
     say("A lage piece breaks off and falls away towards the vortex.\n");
      write("A large piece breaks off and falls away towards the vortex.\n");
    }
    if (val == 5)
    {
      write("You feel a slight tremor run throughout this place.\n");
      say("A slight tremor runs throughtout this place.\n");
    }
    if (val > 24 && val < 45)
    {
      write("A small piece breaks away. You feel the ledge vibrate.\n");
      say("A small piece breaks away and you feel the ledge vibrate.\n");
    }
    if (val == 48)
    {
      write("Crackling can be heard under your feet!\n");
      say("Crackling can be heard coming from the ledge!\n");
    }
    return 1;
  }
  if(str == "at ledge" || str == "ledge")
  {
    say(this_player()->query_name()+" looks down at the ledge.\n");
    write("Looking at the "+short()+", you see its made of high\n");
    write("density dark crystal. The dark crystal here is unbreakable.\n");
    write("As the pieces break away, the ledge vibrates slightly. You\n");
    write("don't feel like staying here to long.\n");
    return 1;
  }
  if(str == "at light beam" || str == "at beam")
  {
    say(this_player()->query_name()+" looks that the light beam.\n");
    write("Looking at the RGB beam you see its made of rainbow colors.\n");
    write("You can see pieces of light material, possibly white crystal\n");
    write("flowing up the light beam.\n");
    write("They look VERY sharp!\n");
    return 1;
  }
  if(str == "at cliff" || str == "cliff")
  {
    say(this_player()->query_name()+" looks at the cliffs, left and right.\n");
    write("The `cliffs' are made of a crystaline material. Left side of\n");
    write("ledge the brownish crystal seems more unstable than the right\n");
    write("side of ledge which is made of dark crystal. The right side\n");
    write("looks more climbable than the left.\n");
    return 1;
  }
  if(str == "left")
  {
    say(this_player()->query_name()+" looks left.\n");
    write("Looking left you see that this ledge comes from a cliff like\n");
    write("structure similar to the abrupt ending of a continent next to\n");
    write("the ocean. The 'cliff' goes down and curves back under, beyond\n");
    write("you sight. Thye voidal blackness is offset by the faintly\n");
    write("glowing material you have been traveling across.\n");
    return 1;
  }
  if(str == "right")
  {
    say(this_player()->query_name()+" looks right.\n");
    write("Looking right you see a narrow path carved into the 'cliff'\n");
    write("here. Its very accessible, but it goes right and downward\n");
    write("along the 'cliff' of dark crystal.\n");
    return 1;
  }
}

gift()
{
  int no_obj;
  object ob,gobj;

  no_obj = 0;
  ob = first_inventory(this_player());
  gobj = clone_object("players/kbl/objs/litesuit");
  if(ob && gobj)
  {
    while(ob)
    {
      if(ob->query_name() == gobj->query_name())
      {
        if(ob->query_worn() == 1)
        {
          write("You have the litesuit turned on, GOOD!\n");
          destruct(gobj);
          return 1;
        }
        else
        {
          write("You DO NOT have the litesuit turned on! Thats BAD!\n");
          destruct(gobj);
          write("The litesuit dematerializes on contact with the BEAM!\n");
          say("Litesuit dematerializes on contact with the BEAM!\n");
          destruct(ob);
          return 0;
        }
      }
      else
        ob = next_inventory(ob);
    }
  }
  else
  {
    write("You do not have any inventory!\n");
    destruct(gobj);
   return 0;
  }
  if(no_obj == 0)
  {
    destruct(gobj);
    return 0;
  }
}

fix_up(doc)
{
  doc->set_name("High Demon Of Chaos");
  doc->set_alias("doc");
  doc->set_alt_name("demon");
  doc->set_level(55);
  doc->set_al(-500);
  doc->set_race("krajar");
  doc->set_gender(1);
  doc->set_aggressive(0);
  doc->set_chr(3);
  doc->set_wc(20);
  doc->set_ac(30);
  doc->set_short("High Demon Of Chaos");
  doc->set_long("This DOC is a trained fighting machine, deadly!!\n");
  doc->set_chance(50);
  doc->set_spell_mess1("DOC cast a few shard crystals at you.\n");
  doc->set_spell_mess2("DOC casts a seemingly endless hail of shards at you!\n");
  doc->set_spell_dam(80);
}
