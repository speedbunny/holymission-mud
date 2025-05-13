inherit "players/kbl/inherit/music";
int spell_done;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("piano");
    set_short("An ordinary black piano");
    set_long("It's really nothing more than a box with a couple of keys.\n");
    set_write_snd("You enjoy banging on the piano.\n");
    set_say_snd("plays a nice ragtime melody on a piano.\n");
    set_value(0);
    set_weight(0);
    set_can_get(0);
    set_spell(15,6);
  }
  spell_done=0;
}

do_spell() {
string filenaam;
int inpub;
object drinken;

  if(spell_done) return;
  spell_done=1;
  say("The Bard continues and the next piece is played very, very well.\n");
  filenaam=file_name(environment(this_object()));
  inpub=0;
  switch(filenaam) {
    case "room/pub2" : inpub=1; break;
    case "room/inn" : inpub=1; break;
  }
  if(inpub) {
    say("The bartender thanks the Bard for the music and sets a drink on\n"
      + "the piano. The drink looks appetizing.\n");
    write("The bartender thanks you and sets a drink on the piano. It\n"
      + "looks appetizing.\n");
    drinken=clone_object("obj/soft_drink");
    drinken->set_strength(48);
    drinken->set_empty_container("glass");
    drinken->set_drinker_mess("It tastes delicious!\n");
    drinken->set_drinking_mess(" drinks an interesting liquid.\n");
    switch(random(7)) {
      case 0 : drinken->set_name("mineral water"); break;
      case 1 : drinken->set_name("apple juice"); break;
      case 2 : drinken->set_name("peach juice"); break;
      case 3 : drinken->set_name("coca cola"); break;
      case 4 : drinken->set_name("buttermilk"); break;
      case 5 : drinken->set_name("cow milk"); break;
      case 6 : drinken->set_name("hot chocolate"); break;
    }  
    transfer(drinken,environment(this_object()));
    return;
  }
}
