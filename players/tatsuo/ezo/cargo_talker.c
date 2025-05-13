inherit "obj/monster";
reset(arg){
   ::reset(arg);
   load_chat(40,({
         "The wind blows a water drops into your face.\n",
         "You see birds fling around the ship.\n",
         "The waves are rolling around the ship.\n"}));
   if (arg) return;
   set_level(1);
   set_name("invisible talker");
   set_short(0);
   set_long("Invisible talker.\n");
   is_invis=30;
   set_ac(1000000);
   set_hp(1000000);
}
