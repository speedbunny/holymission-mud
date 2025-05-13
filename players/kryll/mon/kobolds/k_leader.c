inherit "/obj/monster";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("Kobold Leader");
  set_race("kobold");
  set_alias_list(({ "leader", "kobold leader", "Kobold leader" }));
  set_size(2);
  set_level(18);
  set_short("Kobold Leader");
  set_long("This is a cowardly, sadistic humanoid that is\n" +
    "3 feet tall with scaly dark brown hide. With\n" +
    "their rat-like tail and raggedy garb, they\n" +
    "don't look like much of a threat. This little one "+
    "is someone of importance however.\n");
  load_a_chat(10, ({
    "The kobold leader shouts: Let's gangbang this fool!",
    "The kobold leader gives you an evil eye.",
    "The kobold leader says: You'll make good eatin' for our master!" })
  );
  if(!random(4))
    set_gender(2);
  else
    set_gender(1);
  set_move_at_reset();
  set_aggressive(1);
  set_al(-150);
  add_money(200 + random(100));
}
