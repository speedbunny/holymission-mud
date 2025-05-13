/* Inside dark crystal cave */

inherit "room/room";
object doc,doc2;


init()
{
  ::init();
  add_action("bars","south");
  add_action("look_it","look");
  add_action("look_it","scan");
}

reset(arg)
{
 ::reset(arg);
 if(!arg)
 {
  set_light(0);
  short_desc = "Inside dark crystal cave";
  long_desc = "The walls of this cave are smooth like they have been carved\n"+
              "out with a fine blade. North you see pitch blackness while\n"+
              "while south you see a faint wavering glow. You feel periodic\n"+
              "tremors running thought this area.\n";
  dest_dir = ({"players/kbl/chaos/cho36","north",
               "players/kbl/chaos/cho34","south"});
  smell = "Air is filled with the odor of unwashed feet";
  property = "no_steal";
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


bars()
{
  if(call_other("/players/kbl/chaos/cho34","query_bars"))
  {
    return ::move(query_verb());
  }
  else
  {
    write("The bars of the cave entrance are closed, you cannot go south!\n");
    return 1;
  }
}

fix_up(doc)
{
  doc->set_name("Demon Of Chaos");
  doc->set_alias("doc");
  doc->set_level(15);
  doc->set_hp(225);
  doc->set_sp(80);
  doc->set_al(1000);
  doc->set_race("krajar");
  doc->set_gen(1);
  doc->set_aggressive(1);
  doc->set_str(15);
  doc->set_dex(15);
  doc->set_wis(13);
  doc->set_int(13);
  doc->set_con(15);
  doc->set_chr(5);
  doc->set_ac(15);
  doc->set_wc(15);
  doc->set_short("Lower Demon Of Chaos");
  doc->set_long("DOC has sharp yellowish teeth that glow faintly.\n"+
                 "The natural shine of the Krajar scales make these\n"+
                 "DOC seem reptilian.\n");
   doc->set_chance(10);
   doc->set_spell_mess1("DOC slams you good!\n");
   doc->set_spell_mess2("DOC throws many sharp shards at you!\n");
   doc->set_spell_dam(20);
}

look_it(str)
{
  if(!str)
   return;
  if(str == "at walls" || str == "wall" || str == "at wall")
  {
    say(this_player()->query_name()+" looks at the walls.\n");
    write("The walls seem smooth to the touch, like they were fused\n");
    write("by some very intense heat. Very very fine pressure cracks\n");
    write("can be found all over the walls fanning out from the ceiling\n");
    write("directly overhead.\n");
    return 1;
  }
  if(str == "at cracks" || str == "cracks")
  {
    say(this_player()->query_name()+" looks at cracks in ceiling.\n");
    write("These cracks are caused by some weakness in the surrounding\n");
    write("dark crystal. There is stress everywhere here, you can feel\n");
    write("it. You touch the cracks and find they are sharp. Like razors.\n");
    return 1;
  }
  if(str == "at bars" || str == "bars")
  {
    if(call_other("/players/kbl/chaos/cho34","query_bars"))
    {
      say(this_player()->query_name()+" looks at the bars blocking the way south.\n");
      write("You see multicolored energy bars blocking the way south.\n");
      write("The bars hum with some type of power.\n");
      return 1;
    }
  }
  if(str == "at cave" || str == "cave")
  {
    say(this_player()->query_name()+" looks around.\n");
    long();
    return 1;
  }
}
