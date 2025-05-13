inherit "obj/monster";
void reset(){
{
 ::reset();
 set_name("rabbit");
 set_short("A White rabbit");
 set_race("rabbit");
 set_alias("rabbit");
 set_long("The little white rabbit looks at you then begins hopping around.\n");
 set_level(2);
 set_hp(60);
 set_gender(2);
 load_chat(5,({"The rabbit hops around.\n",
               "The rabbit nibbles on some grass.\n",
               "The rabbit twitches its nose at you and hops happily around.\n"}));
 
}
