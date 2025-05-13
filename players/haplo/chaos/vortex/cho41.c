/* Brownish pressure ridge */

inherit "room/room";
object doc, doc2;
int seed, seed2;

reset(arg)
{
 ::reset(arg);
 if(!arg)
 {
  short_desc = "Brown crystal pressure ridge";
  long_desc = "DOC travel by here alot. The path is very worn with claw\n"+
              "marks deliberately into the ridge here because of the\n"+
              "smoothness of the surface here. To the east the ridge drops\n"+
              "off into a funnel shaped hole. A steady vibration can be\n"+
              "felt under your feet.\n";
  dest_dir = ({"players/kbl/chaos/cho42","east",
               "players/kbl/chaos/cho4","down"});
  smell = "Burnt paper";
  property = "no_steal","no_hide";
  seed = 27;
  seed2 = 30;
  if((!doc || !living(doc)) && (random(seed) < seed/3))
  {
    doc = clone_object("obj/monster");
    fix_up(doc);
    transfer(doc,this_object());
  }
  if((!doc2 || !living(doc2)) && (random(seed2) < seed/5))
  {
    doc2 = clone_object("obj/monster");
    fix_up2(doc2);
    transfer(doc2,this_object());
  }
 }
}

init()
{
  ::init();
  add_action("look_it","look");
  add_action("look_it","scan");
}


look_it(str)
{
  if(!str)
   return;
  if(str == "at claw marks" || str == "claw marks")
  {
    say(this_player()->query_name()+" looks at claw marks.\n");
    write("Must have been easy to claw this crystal up. The brownish\n");
    write("flakes up as you run your hand over it. The flakes bounce\n");
    write("around and decay as you watch.\n");
    return 1;
  }
  if(str == "at ridge" || str == "ridge")
  {
    say(this_player()->query_name()+" looks a brownish ridge of crystal.\n");
    write("This ridge looks as if its pushing upward slowly. Loose\n");
    write("crystal falls down as the ridge rises slowly from pressure\n");
    write("underneath it.\n");
    return 1;
  }
  if(str == "brownish crystal" || str == "crystal")
  {
   say(this_player()->query_name()+" looks at the brownish crystal here.\n");
    write("Looking closely at the brownish crystal it looks as if it has\n");
    write("been somewhere before this. You feel the living power of this\n");
    write("crystal and sense a feeling of knowning inside the crystal!!\n");
    return 1;
  }
}

fix_up(doc)
{

  doc->set_name("Demon Of Chaos");
  doc->set_alias("doc");
  doc->set_level(15);
  doc->set_hp(300);
  doc->set_sp(100);
  doc->set_al(1000);
  doc->set_race("krajar");
  doc->set_aggressive(1);
  doc->set_str(15);
  doc->set_dex(15);
  doc->set_int(15);
  doc->set_wis(15);
  doc->set_con(18);
  doc->set_chr(9);
  doc->set_wc(19);
  doc->set_ac(19);
  doc->set_short("Lower Demon Of Chaos");
  doc->set_long("DOC with powerful claws and naturally formed armour.\n");
  doc->add_money(random(400)+200);
  doc->set_chance(20);
  doc->set_spell_mess1("DOC slams you with a backhand claw!\n");
  doc->set_spell_mess2("DOC throws crystal shards at you!\n");
  doc->set_spell_dam(30);
}

fix_up2(doc)
{

  doc->set_name("Demon Of Chaos");
  doc->set_alias("doc");
  doc->set_level(20);
  doc->set_hp(250);
  doc->set_sp(50);
  doc->set_al(5000);
  doc->set_race("krajar");
  doc->set_aggressive(1);
  doc->set_str(20);
  doc->set_dex(20);
  doc->set_int(5);
  doc->set_con(15);
  doc->add_money(random(450)+250);
  doc->set_wis(5);
  doc->set_chr(5);
  doc->set_ac(18);
  doc->set_wc(20);
  doc->set_short("Worker Demon Of Chaos");
  doc->set_long("This DOC looks very worn, but tough. Has alot of scars!\n");
  doc->set_chance(5);
  doc->set_spell_mess1("DOC slaps you around!\n");
  doc->set_spell_mess2("DOC kicks you silly!\n");
  doc->set_spell_dam(35);
}
