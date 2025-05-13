inherit "/obj/monster";
 reset(arg)
 {
 ::reset(arg);
 load_chat(45,({"Wasp buzzes around your head.\n",
                "Wasp dances around you.\n"}));
 load_a_chat(60,({"Bzzzzzzzz\n",
  		  "Bzzzzzzz\n"}));
if (arg) return;
set_name("wasp");
set_race("animal");
set_short("Yellow wasp");
set_long("You see small wasp flying around you.\n");
set_wc(7);
set_ac(1);
set_hp(90);
set_aggressive(0);
set_level(1);
set_size(1);
move_object(clone_object("/players/goldsun/sherwood/obj/sting"),
             this_object());
}
