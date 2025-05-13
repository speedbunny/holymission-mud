inherit "players/kbl/inherit/music";

int hoeveel;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("bagpipe");
    set_short("A big bagpipe");
    set_weight(2);
    set_value(75);
    set_long("This is a scottish bagpipe from the highlands.\n");
    set_write_snd("You make some scottish noises.\n");
    set_say_snd("makes some scottish noises.\n");
    set_2nd_com("blow");
    set_spell(15,3);
    set_cpag(1);
  }
}

spell_target(who) {
  if(who==this_player()) return;
  if(who->query_alignment()<0) return;
  hoeveel=this_player()->query_level()*who->query_level();
  if(who->query_money()<hoeveel) return;
  who->add_money(-hoeveel);
  this_player()->add_money(hoeveel);
  tell_object(who,"You decide to give "
            + this_player()->query_name()+" "+hoeveel+" gold coins.\n");
  write(who->query_name()+" gives you some money.\n");
  say(this_player()->query_name()+" thanks "
    + this_player()->query_possessive()+" audience.\n");
}
