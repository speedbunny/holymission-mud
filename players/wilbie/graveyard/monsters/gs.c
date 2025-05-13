  inherit "obj/weapon";
reset(arg) {
  ::reset(arg);
if(arg) return;
   set_name("blade");
   set_alias("black");
   set_value(5000);
    set_class(16);
   set_weight(2);
   set_hit_func(this_object());
   set_short("The black blade of Sheankala");
   set_alt_name("Sheankala");
  set_long("This blade of the Goddess Sheankala.  It is said to have "+
  "the power to heal anyone who wields it, if that persons has the "+
  "power to awaken it!!\n");
   }

int weapon_hit(object mob)
{
int thp, hll;

    thp = this_player()->query_level();

   if (thp > 50)
{
thp = 50;
}
    if (random(90) < (thp))
{

   hll = (random(thp));  /* Heal MAX is level of player */
write("\n");
write(mob->query_name()+"'s life force is drawn into your blade!!\n"+
"You feel your wounds mending!!\n");


       /*  debug  
-



write("\n");
write("THP : "+thp);
write("\n");
write("HLL : "+hll);
write("\n");


       */


tell_object(mob,
"You feel your life force being drawn away...\n");

this_player()->heal_self(hll);
this_player()->set_al(-9999);
}
return (10 + random(thp/2));
}
