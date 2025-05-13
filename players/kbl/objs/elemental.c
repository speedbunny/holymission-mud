/* Light Elemental */

inherit "obj/monster";
#define STARL "/players/kbl/objs/leaf"
#define NOTE "/players/kbl/objs/kblnote"
object ob;
    
reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_name("light elemental");
    set_level(25);
    set_al(1000);
    set_alias("elemental");
    set_race("elemental");
    set_short("Light elemental");
    set_long("A flowing light pulse with no real form.\n");
    set_wc(19);
    set_ac(15);
    set_aggressive(0);
    set_spell_mess1("Light elemental burns your face!");
    set_spell_mess2("\nLight elemental sprays you with a fire jet!\n");
    set_chance(40);
    set_spell_dam(35);
  }
}

init()
{
  ::init();
  add_action("give_it","give");
  add_action("give_it","hand");
}

give_it(str)
{
  if(!str)
  {
    write("Give or hand what to elemental?\n");
    return 1;
  }
  switch(str)
  {
    case "slayer to elemental":
    case "slayer to light elemental":
    case "slayer to light":
          if(ob = present("slayer",this_player()))
          {
            write("Elemental smiles happily at you and takes the AnySlayer.\n");
            transfer(ob,this_object());
            write("You feel greatly experienced!\n");
            this_player()->add_exp(25000);
            write("Light Elemental gives you a gift.\n");
            transfer(clone_object(STARL),this_player());
            transfer(clone_object(NOTE),this_player());
            write("Elemental gives you a Star Leaf and a note.\n");
            write("Elemental tells you: in a private place, the command\n"+
                  "\"tree house\" means alot... I thank you for bringing\n"+
                  "me this Slayer and I hope to see you again.\n");
            return 1;
          }
          write("You do not have the AnySlayer, go find it.\n");
          return 1;
  }
}
