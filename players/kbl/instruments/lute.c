inherit "players/kbl/inherit/music";

string feelings;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("lute");
    set_short("A primitive lute");
    set_long("This is a primitive, but functional lute.\n");
    set_write_snd("You play on the lute.\n");
    set_say_snd("plays a nice accompaning melody on a lute.\n");
    set_2nd_com("strum");
    set_value(75);
    set_weight(2);
    set_spell(10,2);
    feelings=({"dance","french","kiss","hug","love","thank"});
  }
}

spell_target(who) {
  if(who->query_gender()==this_player()->query_gender()) return;
  tell_object(who,
    "You love this luteplayer! You decide to give your thanks!\n");
  command(feelings[random(sizeof(feelings))]+" "
        + this_player()->query_real_name(),who);
}
