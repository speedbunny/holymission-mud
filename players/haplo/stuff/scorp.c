inherit "/obj/monster";
object tail;
reset (arg)
{
::reset (arg);
if(arg) return 1;
{
       set_name("scorpion");
      set_alt_name("deadly scorpion");
      set_short("A Deadly Scorpion");
      set_long("This is the most dangerous of all the desert creatures.\n" +
               "BEWARE of his poisonous tail. It will kill you!!\n");
       set_level(15);
       set_wc(35);
       set_hp(2500);
	set_aggressive(0);
      tail =clone_object("players/haplo/fun/stail");
      move_object(tail,this_object());
      init_command("wield tail");

  return 1;
}
return 0;
}
