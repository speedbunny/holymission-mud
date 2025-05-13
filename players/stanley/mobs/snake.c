inherit "obj/monster";
reset(arg) {
    ::reset(arg);
    set_alt_name("snake");
    set_name("water snake");
    set_alias("snake");
    set_level(5);
    set_wc(7);
    set_ac(3);
    set_short("A water snake");
    set_long( 
    "The water snake is long and brown, and is slithering directly towards you!\n");
    set_al(50);
    set_aggressive(0);

load_chat(7,({
   "The water snake rears back it's head at you!\n",
   "\n  \"Hiiisssss!\"\n",
   "The water snake curls into a defensive position.\n",
   }));
}
