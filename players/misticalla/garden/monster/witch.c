inherit "obj/monster";

#define TP this_player()
reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("witch");
    set_alias("evil witch");
    set_short("The evil Witch");
    set_long("This is Xenia the witch. She looks extremly sexy.\n"+
   "She has green eyes and black hairs and seems like she\n"+
   "is only waiting to rape you in her hot witchbed !\n");
    set_level(20);
    set_race("whiskywitch");
    set_heart_beat(20);
    set_al(-1000);
    set_hp(9000);
    set_gender(2);
    set_wc(8);
    set_spell_mess1("The Witch casts a red ball of fire in your direction");
    set_spell_mess2("The Witch casts a red ball of fire in your direction");
    set_chance(80);
    set_spell_dam(8+random(15));
    set_dead_ob(this_object());
    set_aggressive(1);
    move_object(clone_object("/players/misticalla/garden/obj/whip"),
      this_object());
    command("wield whip");
    command("wear straps");
  }
}
init() {
add_action("steal","steal");
::init();
}
steal() {
write("You are much to busy to steal from the witch.\n");
return 1;
}
/* Matt 7-30-93: Removed this pointless function *growl*
   point: this function should warn cheating wizes ** grin **
zap() {
write("Next time the witch will destroy you!\n");
destruct(this_player());
return 1;
}
hold() {
  write("\n\nUiiiiiiiiiihhhhhhhhhhhhhhhhhhhhhh\n\n"+
        "\n\nThe witch laughs about your stupid attempt !!!!\n"+
        "and casts a fireball in your direction !!!!\n\n");
  return 1;
  } 
  */

hold(ob, time)
{
   if (time > 4)
       return ::hold(ob,random(7));
   return ::hold(ob,time);
}
 monster_died(ob) {
    object broom;
    object hank;

    hank = present("hank",this_player()); /* garlic */

    if (hank)
    {
       destruct(hank);
       write("\n\n** Your garlic hank bursts into small pieces hitting the nose of the witch !**\n\n");
    }
   broom=clone_object("players/misticalla/garden/obj/broom");
   write("As you have killed the witch you feel suddenly\n"+
         "the strong force to pick up all her items as fast\n"+
         "as you can\n\n");
    
move_object(clone_object("players/misticalla/garden/obj/key2"),this_player());
/* Matt 7-30-03: Removed crystal ball */
    
move_object(clone_object("players/misticalla/garden/obj/robe2"),this_player());
   if(transfer(broom,this_player())) {
     write("Ok.\nYou are carrying too much.\nOk.\n");
     move_object(broom,environment(this_object()));
   } else {
     write("Ok.\nOk.\nOk.\nOk.\n");
   say(this_player()->query_name()+" gets all from the witchcorpse.\n");
    return 0;
  }
 } 

hit_player(dam,kind)
{
   if (dam > query_hp())
   {
/* Matt 8-4-94: Checked for no quest string, otherwise bad arg to explode */
    if (TP->query_quests() &&
	member_array("witchquest",explode(TP->query_quests(),"#"))!=-1)
       set_ep(0);
   }
    return ::hit_player(dam,kind);
}
