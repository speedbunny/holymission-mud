inherit "obj/monster";

reset(arg) {

  ::reset(arg);
  if(!arg) {

    set_name("kenny");
    set_race("human");
    set_short("Kenny");
    set_long(
  "This is Kenny McKormik dressed in his red parka. He mumbles something \
that you don't understand though you're sure it's disgusting! In one \
hand he holds Cartman's Cheesy Poofs.\n");
    set_gender(1);
    set_level(20);
    set_hp(1500);
    set_wc(30);
    set_ac(11);
    set_al(500);
    set_dead_ob(this_object());
    add_money(1000);
 }
}

monster_died(ob)
{
  shout("Stan shouts: Oh my God! "
+capitalize(this_player()->query_real_name())+
" killed Kenny!\n");
  shout("Kyle shouts: You bastard!\n");
  write("Oh my God! You killed Kenny! You bastard!\n");
}
