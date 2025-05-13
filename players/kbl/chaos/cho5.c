/* Natural dark crystal bridge over brownish crystal flow */

inherit "room/room";
object doc;
int gone;

reset(arg)
{
 ::reset(arg);
 if(!arg)
 {
   set_light(0);
   short_desc = "Natural bridge near Stronghold";
   long_desc = "A natural dark crystal bridge allows crossing of a `flow'\n"+
               "of brownish crystal, that flows through a canyon here.\n"+
               "Across the bridge lies a short stout structure called the\n"+
               "Stronghold. The Arch DOC may be in. Maybe you should visit.\n";
   dest_dir = ({"players/kbl/chaos/cho6","north",
                "players/kbl/chaos/cho4","south"});
   property = "no_steal";
   smell = "Nasty rotten egg odor";
  if(!doc || !living(doc))
  {
    doc = clone_object("obj/monster");
    fix_up(doc);
    transfer(doc,this_object());
    gone = 0;
  }
 }
}

init()
{
  ::init();
  add_action("look_it","look");
  add_action("look_it","scan");
  add_action("bribe","bribe");
  add_action("block","north");
}


block()
{
  int val;
  if(!doc || !living(doc) || gone)
  {
    write("You leave across natural bridge to...\n");
    ::move(query_verb());
    return 1;
  }
  else
  {
    say("Troll DOC blocks "+this_player()->query_name()+"'s path north.\n");
    write("Troll DOC blocks your path!\n");
    val = random(5);
    if(val == 1)
     write("Troll grumbles, U tink U go somplace?\n");
    if(val == 2)
     command("kick "+this_player()->query_name(),doc);
    if(val == 3)
     write("Troll says: Hey, U got some business here!?\n");
    if(val == 4)
    command("slap "+this_player()->query_name(),doc);
    write("DOC grunts: U gotem somding fer me?\n");
    return 1;
  }
}

bribe(str)
{

  object doc2;

  if(!str)
   return;
  if(str == "with crystal" || str == "with dark crystal")
  {
    if(cry())
    {
      if(doc && !gone)
      {
        write("Troll smiles widely. Ummm! Good crystal!\n");
        say("Troll smiles widely. Ummm! Good crystal!\n");
        command("hug "+this_player()->query_name(),doc);
        doc->set_aggressive(1);
        transfer(doc,"/players/kbl/chaos/cho71");
        write("Troll leaves north chewing on the crystal.\n");
        say("Troll leaves north chewing on the crystal.\n");
        write("You hear a door close.\n");
        say("You hear a door close.\n");
        gone = 1;
        return 1;
      }
      else
      {
        write("Nobody present to bribe.\n");
        return 1;
      }
    }
    else
    {
      if(doc && !gone)
      {
        write("Troll screams: Fleshling tries to bribe a ROYAL member with nothing!!!\n");
        say("Troll screams: Fleshling tries to bribe a ROYAL member with nothing!!!\n");
        write("Troll is laughing... and then gestures with its hand...\n");
        say("Troll is laughing... and then gestures with its hand...\n");
        doc2 = clone_object("obj/monster");
        fix_up2(doc2);
        transfer(doc2,this_object());
        write("A High DOC appears and attacks!\n");
        say("A High DOC appears and attacks!\n");
        return 1;
      }
      else
      {
        write("You have nothing to bribe with anyway!\n");
        return 1;
      }
    }
  }
}

look_it(str)
{
  if(!str)
   return;
  if(str == "at natural bridge" || str == "natural bridge")
  {
    say(this_player()->query_name()+" looks at natural bridge.\n");
    write("Natural bridge is made from some high density dark crystal and\n");
    write("looks very strong. You can feel the `flow' of brownish\n");
    write("crystal as it batters against the sides of the canyon in its\n");
    write("slow but steady journey towards a unknown destination.\n");
    return 1;
  }
  if(str == "at stronghold" || str == "stronghold")
  {
    say(this_player()->query_name()+" looks at the Stronghold.\n");
    write("A short stout structure with no real outstanding features.\n");
    write("The doorway is only slightly visible from here, but no\n");
    write("features are observable.\n");
    return 1;
  }
  if(str == "at flow" || str == "flow")
  {
    say(this_player()->query_name()+" looks at flow in canyon.\n");
    write("The `flow' is made up of molten brownish crystal laced with\n");
    write("small islands of darker crystal. A nasty smell greets your\n");
    write("nose. You look around...\n");
    if(doc && !gone)
     write("You wonder if its the Troll or the flow.\n");
    else
     write("You can tell the smell is coming from the crystal flow.\n");
    return 1;
  }
}

cry()
{
  int no_obj;
  object ob,gobj;

  if(!gone)
  {
    no_obj = 0;
    ob = first_inventory(this_player());
    gobj = clone_object("players/kbl/objs/ridge_cr");
   if(ob && gobj)
    {
      while(ob)
      {
        if(ob->query_name() == gobj->query_name())
        {
          write("The Troll takes the Dark Crystal...\n");
          say("The Troll takes the Dark Crystal from "+this_player()->query_name()+".\n");
          destruct(ob);
          destruct(gobj);
          return 1;
        }
        else
          ob = next_inventory(ob);
      }
    }
    else
    {
      write("You do not have ANY inventory!!!\n");
      destruct(gobj);
      return;
    }
    if(no_obj == 0)
    {
      destruct(gobj);
      return;
    }
  }
  return;
}

fix_up2(doc)
{
  doc->set_name("Demon Of Chaos");
  doc->set_alt_name("demon");
  doc->set_alias("doc");
  doc->set_level(35);
  doc->set_gender(1);
  doc->set_al(-2000);
  doc->set_race("krajar");
  doc->set_aggressive(1);
  doc->set_chr(5);
  doc->set_ac(25);
  doc->set_wc(25);
  doc->set_short("High Demon Of Chaos");
  doc->set_long("Trained in power fighting! Sharp pearl black teeth\n"+
                "are accented by his highly polished natural armour.\n");
  doc->set_chance(30);
  doc->set_spell_mess1("DOC slaps you silly!\n");
  doc->set_spell_mess2("DOC casts many sharp shards at you!\n");
  doc->set_spell_dam(40);
}

fix_up(doc)
{
  doc->set_name("Demon Of Chaos");
  doc->set_alias("doc");
  doc->set_alt_name("demon");
  doc->set_level(25);
  doc->set_al(-7000);
  doc->set_race("krajar");
  doc->set_aggressive(0);
  doc->set_chr(8);
  doc->set_short("Troll Demon Of Chaos");
  doc->set_long("Trained in the art of Trollandria, looks too powerful\n"+
                "for you! His yellow eyes and high profile body are\n"+
                "in sharp contrast to the long slender crystal claws\n"+
                "that point at you.\n");
  doc->set_chance(70);
  doc->set_spell_mess1("DOC slices to in fine bits!\n");
  doc->set_spell_mess2("DOC does INSANE damage to you!\n");
  doc->set_spell_dam(70);
}
