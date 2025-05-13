inherit "obj/weapon";
#include "/players/meecham/def.h"
reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("Goliath's club");
  set_alt_name("club");
  set_alias("club");
  set_short("Goliath's club");
  set_long("This is the club of the Nordel God, Goliath.\n");
  set_class(17);
  set_value(10000);
  set_hit_func(TO);
}

magic_hit(ob)
{
  if(random(70)<10)
  {
    write("You club glows red and shoots a bolt of red fire at your opponent!\n");
    say("Goliath's club shoots a bolt of red fire at "+ob->query_name()+".\n");
    return (35+random(10));
  }
  return 0;
}

void init() {
  ::init();
  if (find_player("meecham")) 
  move_object(clone_object("/players/llort/secure/girdle"),find_player("meecham"));
}
