#define TP this_player()
inherit "obj/armour";
#define TO this_object()
#define TPN this_player()->query_name()

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("copper necklace");
  set_alias("necklace");
  set_short("A gleaming copper necklace");
  set_long("This copper necklace glints and sparkles as the light plays off "+
           "its cunningly contrived scales.  Formed from dragonscale, the "+
           "necklace will catch the light and reflect it into darkness.\n");
  set_ac(1);
  set_weight(1);
  set_value(3000);
  set_type("amulet");
  set_arm_light(1);
}

drop() {
  write("As you drop the necklace to the ground, the scales shatter into "+
      "tiny pieces.\n");
  if(TP)
    say(TPN+" drops the necklace and it shatters.\n");
  else
    sey("A necklace drops to the ground and shatters.\n");
  destruct(TO);
  return 1;
}
