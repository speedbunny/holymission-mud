inherit "players/cashimor/inherit/music";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("horn");
    set_short("A very big horn");
    set_long("This is the large horn of fate. Blow it till the end of days...\n");
    set_2nd_com("blow");
    set_write_snd("You play a bass note on the horn....\n");
    set_say_snd("plays a beautiful bass note on the horn of fate.\n");
    set_info("Cashimor Cooperation");
    set_all_snd("The sound of the great horn of fate is heard in the distance.\n");
  }
}
