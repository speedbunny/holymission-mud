inherit "obj/monster";
#define env environment
object who;

reset(arg) {
    ::reset(arg);
    if(!arg) {
      set_name("Smorlok's Schnuddlwuddl");
      set_alias("schnuddi");
      set_short("Smorlok's Schnuddlwuddl");
      set_long("Smorlok's Schnuddlwuddl is watching you.\n");
      set_race("schnuddlwuddl");
      set_hp(1000000);
      set_level(100);
      set_wc(1);
      set_ac(1);
      set_aggressive(0);
    who=find_player("smorlok");
    set_heart_beat(1);
add_action("order","order");
    }
}

void heart_beat() {
    if (who && env(who)) {
      if (env(who) != env(this_object())) {
          say("Smorlok's Schnuddlwuddl looks lost and leaves.\n");
          move_object(this_object(),env(who));
          say("Smorlok's Schnuddlwuddl arrives near Smorlok.\n");
}
      }
::heart_beat();

}
detect_invis()
{
   return 1;
}
int order(string arg)
{
command(arg);
write("oki.");
return 1;
}
