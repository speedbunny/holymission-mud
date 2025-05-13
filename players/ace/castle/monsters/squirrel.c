inherit "obj/monster.c";

reset(arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("Squirrel");
   set_alt_name("squirrel");
   set_level(7);
   set_al(-100);
   set_ac(4);
   set_wc(7);
   set_short("A rabid squirrel");
   set_long("This is one ugly squirrel!\n" +
            "It has foam coming from it's mouth, you'd better watch out!\n");
   set_race("squirrel");
}
