inherit "players/kbl/inherit/music";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("harp");
    set_short("A beautiful, nicely crafted harp");
    set_long("This is a fine harp, especially for a master harper.\n");
    set_write_snd("You play on the harp.\n");
    set_say_snd("is making a very complicated movement on a harp.\n"
              + "You feel it's just for you.\n");
    set_2nd_com("strum");
    set_value(75);
    set_weight(2);
  }
}
