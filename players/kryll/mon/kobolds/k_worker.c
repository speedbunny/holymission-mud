inherit "/obj/monster";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("Kobold Worker");
  set_level(12);
  set_alias_list(({ "worker", "kobold worker", "Kobold worker" }));
  set_short("Kobold Worker");
  set_race("kobold");
  set_size(2);
  set_al(-110);
  if(!random(2))
    set_gender(2);
  else
    set_gender(1);
  set_long("This is a cowardly, sadistic humanoid that is " +
    "3 feet tall with scaly dark brown hide. With " +
    "their rat-like tail and raggedy garb, they " +
    "don't look like much of a threat. This laborer "+
    "looks slightly tired anyway.\n");
  add_money(10 + random(30));
}
