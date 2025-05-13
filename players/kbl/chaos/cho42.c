/* Funnel hole down into the blackness */

inherit "room/room";
object doc,doc2;
int seed,seed2;

reset(arg)
{
 ::reset(arg);
 if(!arg)
 {
  set_light(1);
  short_desc = "Funnel shaped hole in the brownish crystal";
  long_desc = "The crystal here has been fused together by some type of\n"+
              "intense heat. A slim pathway leads down along the side of\n"+
              "the hole and looks extremely slippery. Beyond the hole lies\n"+
              "this edge of the parallel plane of chaos. The blackness of\n"+
              "the void beyond this point and above, is in sharp contrast\n"+
              "to the light pulse that casts errie shadows over this\n"+
              "broken landscape.\n";
   dest_dir = ({"players/kbl/chaos/cho41","west",
                "players/kbl/chaos/cho43","down"});
   smell = "Pungent dead body odor";
   property = "no_steal";
  seed = 32;
  seed2 = 30;
  if((!doc || !living(doc)) && (random(seed) < seed/4))
  {
    doc = clone_object("obj/monster");
    fix_up(doc);
    transfer(doc,this_object());
  }
  if((!doc2 || !living(doc2)) && (random(seed2) < seed2))
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
  add_action("look_it","l");
  add_action("look_it","exa");
  add_action("slip","down");
}


slip()
{
int val;
  if(this_player()->query_dex() > 21)
  {
    write("You use grooves on the wall to slide yourself down to...\n");
    ::move(query_verb());
    say(this_player()->query_name()+" comes sliding down!\n");
    return 1;
  }
  if(this_player()->query_dex() > 14)
  {
    write("You grab for the grooves on the wall but slip on the smooth\n");
    write("crystal ground! You try and reach for the grooves...\n");
    val = random(30);
    if(val < (this_player()->query_dex()-(this_player()->query_weigh()/10)))
    {
      write("again and you grab one, just before you fell over the edge.\n");
      write("Good grab! *lucky*\n");
      say(this_player()->query_name()+" almost feel into the hole!\n");
      ::move(query_verb());
      say(this_player()->query_name()+" arrives stumbling...\n");
      return 1;
    }
    write("Oooooops! You missed! You are falling!\n");
  }
    this_player()->move_player("falling into hole!#players/kbl/chaos/cho43");
    write("You keep falling, but the pull of gravity is getting weaker...\n");
   say(this_player()->query_name()+" arrives falling downward!\n");
    this_player()->move_player("falling downward#players/kbl/chaos/cvoid");
    return 1;
}


look_it(str)
{
  if(!str)
   return;
  if(str == "at grooves" || str == "grooves")
  {
    say(this_player()->query_name()+" looks at grooved handholds.\n");
    write("This fused crystal has ripples, which look like grooves. These\n");
    write("natural ripples provide hand holds to make your way down this\n");
    write("steep pathway going down the west wall of the hole.\n");
    return 1;
  }
  if(str == "at pathway" || str == "pathway")
  {
    say(this_player()->query_name()+" looks at pathway going down into hole.\n");
    write("The pathway looks real slick, better have a good dexterity!\n");
    write("The claw marks here seems to fade and you figure it must be\n");
    write("from the intense heat that seems to have been used in this area.\n");
    return 1;
  }
  if(str == "at void" || str == "void")
  {
    say(this_player()->query_name()+" looks at the void.\n");
    write("The void looks black as black can get. The void towards the \n");
    write("west looks more granular, for lack of a better explaination.\n");
    return 1;
  }
  if(str == "at hole" || str == "hole")
  {
    say(this_player()->query_name()+" looks down into hole.\n");
    write("Looking down into the hole into the blackness, you see a \n");
    write("faint greenish brown glow at the bottom... Bottom?\n");
    return 1;
  }
}

fix_up(doc)
{
  doc->set_name("Demon Of Chaos");
  doc->set_alias("doc");
  doc->set_level(16);
  doc->set_hp(200);
  doc->set_sp(125);
  doc->set_al(1000);
  doc->set_race("krajar");
  doc->set_aggressive(1);
  doc->set_str(17);
  doc->set_dex(18);
  doc->set_int(18);
  doc->set_wis(15);
  doc->set_con(19);
  doc->set_chr(9);
  doc->set_ac(19);
  doc->set_wc(19);
  doc->set_short("Lower Demon of Chaos");
  doc->set_long("Tho a lower DOC, this one belongs to the elite guard.\n"+
                "Claw blades and foot blades are needle sharp!\n");
  doc->add_money(random(750)+600);
  doc->set_chance(40);
  doc->set_spell_mess1("DOC slices your tongue out!\n");
  doc->set_spell_mess2("DOC shreads you bad!\n");
  doc->set_spell_dam(40);
}

fix_up2(doc)
{
  doc->set_name("Demon Of Chaos");
  doc->set_alias("doc");
  doc->set_level(21);
  doc->set_hp(280);
  doc->set_sp(50);
  doc->set_al(5000);
  doc->set_race("krajar");
  doc->set_aggressive(1);
  doc->set_str(22);
  doc->set_dex(17);
  doc->set_int(5);
  doc->set_con(22);
  doc->set_wis(7);
  doc->add_money(random(500)+350);
  doc->set_chr(1);
  doc->set_ac(25);
  doc->set_wc(29);
  doc->set_short("Worker Demon Of Chaos");
  doc->set_long("Tired looking DOC but very powerful. Thick claw blades\n");
  doc->set_chance(5);
  doc->set_spell_mess1("DOC kicks you hard!\n");
  doc->set_spell_mess2("DOC knocks the daylights out of you!\n");
  doc->set_spell_dam(50);
}
