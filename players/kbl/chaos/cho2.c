/* Distant view of Voidal Vortex */

inherit "room/room";
object doc,doc2;
int num_c;

reset(arg)
{
 ::reset(arg);
 if(!arg)
 {
  set_light(1);
  short_desc = "Sharp Ridge";
  long_desc = "Off to your left and down looking east is a swirling vortex.\n"+
              "Chunks of material disappear into the vortex. Each time a\n"+
              "chunk goes into the vortex a light beam shoots upward and out\n"+
              "of sight. Illumination provided by these periodic bursts cast\n"+
              "dancing shadows off of the sharp ridge of dark crystal on\n"+
              "your right.\n";
  dest_dir = ({"players/kbl/chaos/cho3","east",
               "players/kbl/chaos/cho1","west"});
  items = ({"dancing shadows","These are just light dancing off a mirrored\n"+
                              "face on some naturally polished crystals",
            "polished crystals","Looks like a crystal has been broken off\n"+
                                "of this place on the ridge, search the ridge?",
            "chunk","To far away to get any detail.",
            "chunks","To far away to get any detail."});
  property = "no_steal";
  smell = "There's a very slight chemical odor here";
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
    fix_up(doc2);
    transfer(doc2,this_object());
  }
 }
}

init()
{
  ::init();
  add_action("look_it","look");
  add_action("break_it","break");
  add_action("look_it","scan");
}

break_it(str)
{
  int val;
  object tal;


  if(!str)
   return;
  if(str == "crystal off ridge" || str == "off crystal from ridge")
  {
   if(num_c == 1)
   {
    if((!doc || !living(doc)) && (!doc2 || !living(doc2)))
    {
     write("You break crystal off ridge\n");
      say(this_player()->query_name()+" breaks crystal off ridge\n");
     tal = clone_object("players/kbl/objs/ridge_cr");
      tal->set_tim(random(5)+1);
      transfer(tal,this_player());
      num_c+=1;
      return 1;
    }
    else
    {
      write("Demon Of Chaos blocks you from the ridge.\n");
      val = random(3);
      if(val == 1)
      {
        write("DOC gurgles in common: Get out of here fleshling!\n");
        say("DOC gurgles in common: Get out of here fleshling!\n");
        return 1;
      }
      if(val == 2)
      {
        write("DOC snarls: I love you dead! MUHAHAHAHAHA!!!!\n");
        say("DOC snarls: I love you dead! MUHAHAHAHAHA!!!!\n");
        return 1;
      }
      return 1;
    }
   }
   else
   {
     write("No more loose crystal on ridge to break off.\n");
     say(this_player()->query_name()+" fails to find any loose crystal.\n");
     return 1;
   }
 }
}

look_it(str)
{
  if(!str)
   return;
  if(str == "at beam" || str == "beam")
  {
    say(this_player()->query_name()+" looks at light beam pulse.\n");
    write("The light beam looks like a beacon in the darkness. Its light\n");
    write("blinds you briefly. You are too far away to see any detail.\n");
    return 1;
  }
  if(str == "at vortex" || str == "vortex")
  {
   say(this_player()->query_name()+" looks down and left at vortex.\n");
   write("The view of the vortex is very distant. The light emitted from\n");
   write("the vortex in energy quanta in the form of Red, Green and Blue\n");
   write("light beams.\n");
   return 1;
  }
  if(str == "at ridge" || str == "ridge")
  {
    say(this_player()->query_name()+" scans sharp ridge for loose crystal.\n");
   write("The ridge is made of a dark crystaline material that glows with\n");
   write("some internal power. Maybe you can break off a piece, hmmmm.\n");
   if(num_c == 1)
    write("Looks as if you might be able to break off some crystal.\n");
   return 1;
  }
}

fix_up(doc)
{
  doc->set_name("Demon Of Chaos");
  doc->set_alt_name("demon");
  doc->set_alias("doc");
  doc->set_level(random(5)+18);
  doc->set_hp(random(200)+200);
  doc->set_sp(random(250)+250);
  doc->set_gender(random(2)+1);
  doc->set_al(-1);
  doc->set_race("krajar");
  doc->set_aggressive(0);
  doc->set_str(random(2)+19);
  doc->set_dex(random(2)+19);
  doc->set_wis(random(5)+14);
  doc->set_int(random(5)+14);
  doc->set_con(random(2)+19);
  doc->set_chr(random(2)+4);
  doc->set_ac(15);
  doc->set_wc(random(3)+17);
  doc->set_short("Lower Demon of Chaos");
  doc->set_long("This Demon of Chaos creature has sharp claws and\n"+
                "yellowish teeth. This is a Krajar class being.\n");
  doc->set_chance(random(25)+5);
  doc->set_spell_mess1("DOC casts a hail of sharp crystal shards at you!\n");
  doc->set_spell_mess2("DOC cuts you to shreads!\n");
  doc->set_spell_dam(25);
}
